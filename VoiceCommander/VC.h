/*...........................................................................................................

clWinText,clMain

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Идентификаторы дочерних окон.

#define id_Win_Edit 1 // Окно редактора текста.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс для окна текста распознавания.

class clWinText {

HWND hwndEdt; // Идентификатор окна редактирования.
HWND hwndOwner; // Идентификатор родительского окна.
RECT *rcWin; // Прямоугольник окна.
RECT rcEdt; // Прямоугольник окна редактора текста.
USHRT dxMin,dyMin; // Минимальные размеры окна.
HBRUSH hBrushBkg,hBrushDial; // Кисти для закрашивания окон.
HFONT hFontText; // Шрифт для вывода текста.

void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
void ZeroBrushes(void); // Обнуление кистей для закрашивания окон.
void FreeBrushes(void); // Создание кистей для закрашивания окон.
BYTE CreateBrushes(void); // Создание кистей для закрашивания окон.
void ZeroFont(void); // Обнуление указателя для шрифта.
void FreeFont(void); // Удаление шрифта.
BYTE LoadFont(void); // Загрузка шрифта.
void OnCloseWin(void); // Действия при закрытии окна.
void GetMinSizeWin(void); // Получение минимального размера окна.
void SetMinSize(LPMINMAXINFO lpMinMax); // Установка минимального размера окна.
BYTE CreateEdt(void); // Создание окна редактирования.
void CloseEdt(void); // Закрытие окна редактирования.
void ChPosSizeChWin(void); // Изменение расположения дочерних окон.
BYTE SetPosSizeChWin(void); // Установка расположения дочерних окон.

public:

HWND hwnd; // Идентификатор окна.

clWinText(void);
~clWinText(void);
void SetParPnt(HWND hwndOwner_,RECT *rcWin_); // Установка параметров и указателей.
BYTE CreateWin(void); // Создание окна.
void CloseWin(void); // Закрытие окна.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка сообщений окна.
BYTE SetText(char *Text); // Установка текста в окне.
void ClearWin(void); // Очистка окна.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс главного окна.

class clMain {

BYTE flCaptSound,flStopCaptSound,flDoCommands,flOutWords,cntShutDown; USHRT dxMin,dyMin;
UINT TimeRecBuf,TimeRecProc,nRecChar,nRecText,cntPause; HWND hwnd,hDlg,hwndProgr; RECT rc,rcText;
HBRUSH hBrushBkg,hBrushDial; HMENU hMenu,hMenu_; clHelpEx *Help;

struct strParSpProc ParSpectr; // Параметры спектральной обработки.
clLoadDLLSndCap *SndCap; // Класс для работы с библиотекой по захвату звука.
clSndCapData *SndCapData; // Класс звука, полученного при записи в виде отдельных отрезков.
struct strNNW NNW_Spectr; // Класс нейронной сети.
clString RecNNW; // Символы звуков, распознаваемых в потоке в реальном времени.
clString RecText; // Символы распознанного текста.
struct strAnalyseSound AnSound; // Структура для анализа потока символов.
struct strAnalyseData AnStream; // Структура для анализа потока данных.
struct strDictionary Dict; // Структура словаря.
struct strRecognAllWords RecWords; // Структура для распознавания слов.
clWinText WinText; // Класс окна текста - результата распознавания.

void Zero(void); // Обнуление идентификаторов и указателей.
void Free(void); // Освобождение памяти.
void ZeroBrushes(void); // Обнуление кистей для закрашивания окон.
void FreeBrushes(void); // Создание кистей для закрашивания окон.
BYTE CreateBrushes(void); // Создание кистей для закрашивания окон.
void ZeroMenu(void); // Обнуление указателей для меню.
void FreeMenu(void); // Освобождение памяти от меню.
BYTE CreateMenu(void); // Создание и загрузка меню.
BYTE ShowMenu(LPARAM lParam); // Отображает меню на экране.
void ZeroHelp(void); // Обнуление указателя для класса для вывода файла справки.
void FreeHelp(void); // Уничтожение класса для вывода файла справки.
BYTE CreateHelp(void); // Создание класса для вывода файла справки.
void ChMenuHelp(void); // Изменение состояния пункта меню справки.
BYTE CreateDlgCntrl(void); // Создание диалогового управляющего окна.
BYTE GetMinSizeWin(void); // Получение минимального размера окна.
void SetMinSize(LPMINMAXINFO lpMinMax); // Установка минимального размера окна.
BYTE MoveWinCorner(void); // Перемещение окна в нижний правый угол.
BYTE Command(WPARAM wParam); // Команды.
BYTE CommandCntrl(WPARAM wParam); // Обработка команд окна управления.
void OnPaint(HDC hdc); // Рисование в окне.
void ZeroSndCapData(void); // Класс хранения данных при записи звука: обнуление указателя.
void FreeSndCapData(void); // Класс хранения данных при записи звука: оcвобождение памяти.
BYTE CreateSndCapData(void); // Класс хранения данных при записи звука: создание.
void ZeroSndCap(void); // Обнуление указателя на объект класса библиотеки захвата звука.
void FreeSndCap(void); // Удаление объекта класса библиотеки захвата звука.
BYTE CreateSndCap(void); // Создание объекта класса библиотеки захвата звука.
BYTE StartCaptureSound(void); // Включение записи звука.
void StopCaptureSound(void); // Остановка записи звука.
void StopCaptureSound_(void); // Остановка записи звука.
void ChBtnMenuCaptureSound(void); // Выделение пункта меню захвата звука и изменение кнопки.
void SetTxtBtnRecSound(void); // Установка текста в кнопку распознавания звука.
BYTE DlgAdjSound(void); // Настройка захвата звука.
BYTE ProcRecRealTime(void); // Обработка и распознавание в реальном времени.
BYTE AddSymbTextWin(char Symb); // Добавление распознанного символа в окно.
BYTE AddWordTextWin(char *Str); // Добавление распознанного слова в окно.
void ShowProgr(double v,double vMax); // Полоса прогресса.
BYTE LoadNNW(void); // Загрузка нейронной сети.
BYTE LoadDict(void); // Загрузка словаря.
void SetPntWinText(void); // Установка параметров и указателей для окна текста.
BYTE GetSizeWinText(void); // Установка размеров окна текста.
void OpenWinText(void); // Открытие окна тескта.
void ClearWinText(void); // Очистка окна текста.
void SetWinText(char *Text); // Изображение текста в окне.
void RecognTxtCommand(BYTE numSnd,char Symb); // Распознавание текста и команд.
void DoCommand(BYTE comm); // Выполнение команд.
BYTE OpenSysProg(char *NameProg); // Открытие системной программы.
BYTE OpenProgFiles(char *PathProg,char *NameProg); // Открытие программы из директории "Program Files".
BYTE ShowCommand(BYTE comm); // Отображение команд в окне.
void SetText(char *txt); // Установка текста в окне.
void SetWord(char *txt); // Установка слова в окне.
BYTE SetString(int idS); // Установка строки в окне.
void ChMenuDoCommands(void); // Изменение выделения пункта меню принятия команд.
void ChMenuOutWords(void); // Изменение выделения пункта меню вывода в окно распознанных слов.
void OnCloseWin(void); // Действия при закрытии окна.

public:

clMain(void); // Конструктор.
~clMain(void); // Деструктор.
BYTE OnCreate(HWND hwnd_); // Действия в начале работы программы.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка очереди сообщений окна.
LRESULT MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка очереди сообщений окна управления.
BYTE SaveBufSound(DWORD szBuf,void *pBuf); // Сохранение при записи звука.
BYTE GetNumSndRecogn(strLay *pLay,BYTE *numSnd); // Получение номера звука при распознавании потока речи.
void ChMenuWinText(void); // Изменение состояния кнопки и пункта меню открытия окна текста.
};
