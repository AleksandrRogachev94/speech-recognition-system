/*...........................................................................................................

strResRec,strDBS,strDBSArr,strDBF,strDBFArr,strDataTrain,strDataTrainArr,strStatSnd,strStatSndAll,
clDlgDBF_NNW,clWinViewNNW,strParAnSnd,strAnSnd,strAnSndArr,strAnalyseSound,clWinText,clMain

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Cтруктура результата распознавания.

struct strResRec {

UINT nSamp; // Число образцов, по которым проводился подсчёт.
float prcTrue,prcFalse,prcNo; // Проценты распознавания - правильного, другой звук, нераспознано.
float Err; // Среднеквадратичная ошибка.

strResRec(void); // Конструктор.
void Zero(void); // Обнуление и инициализация параметров.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Cтруктура параметров события (звука) внутри файла.

struct strDBS {

BYTE flUse; // Флаг использования.
BYTE flTrain; // Флаг тренировки.
BYTE nRep; // Число повторений.
char cSnd; // Обозначение звука.
BYTE typSnd; // Тип звука.
BYTE numSnd; // Номер звука в списке.
float tI,tF; // Начальное и конечное время интервала звука.
struct strResRec Res; // Результат распознавания звука.
clSpDiag Diag; // Результат спектральной обработки.
clInpLayArr Peaks; // Спектральные линии.
clInpLayArr InpData; // Входные данные для сети.
BYTE typInpData; // Тип входных данных для сети.

strDBS(void); // Конструктор.
void Zero(void); // Обнуление указателей и инициализация параметров.
void ZeroRes(void); // Обнуление результатов распознавания.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
void Print(void); // Печать в строку.
BYTE ProcSpectr(strSndArr *Snd,strParSpProc *Param,BYTE *flStop); // Разложение в спектр.
BYTE GetPeaks(BYTE *flStop); // Нахождение спектральных линий.
BYTE GetInpData(BYTE typNet,BYTE typID,BYTE *flStop); // Нахождение входных данных.
BYTE GetInpDataVC(BYTE typID,BYTE *flStop); // Нахождение входных данных для раздельной сети для гласных или согласных.
BYTE GetInpDataSp(BYTE *flStop); // Нахождение входных данных для одной сети для всего спектра.
BYTE GetResult(strNNW *pNNW); // Получение результата распознавания.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Cтруктура базы данных по звукам внутри файла.

struct strDBSArr {

BYTE nDBS; // Число событий (звуков) в файле.
struct strDBS *DBS; // Массив структур событий (звуков).
struct strSndArr Snd; // Массив звукового файла.
BYTE flChange; // Флаг изменения базы данных.

strDBSArr(void); // Конструктор.
~strDBSArr(void); // Деструктор.
void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
BYTE Alloc(BYTE nDBS_); // Выделение памяти.
BYTE IsOK(void); // Проверки массива структур.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
BYTE Read_(char *fName); // Чтение из файла.
BYTE Write_(char *fName); // Запись в файл.
BYTE ReadSound(char *fName); // Чтение звукового файла.
BYTE FillLBParam(HWND hDlg); // Заполнение списка элементов базы данных.
strDBS *Get(BYTE num); // Даёт указатель на структуру события (звука) внутри файла.
BYTE ProcSpectr(strParSpProc *Param,BYTE *flStop); // Разложение в спектр.
BYTE SoundSel(void); // Озвучивание выбранного интервала.
BYTE GetPeaks(BYTE *flStop); // Нахождение спектральных линий.
BYTE GetInpData(BYTE typNet,BYTE typInpData,BYTE *flStop); // Нахождение входных данных.
void SetResZero(void); // Обнуление результатов распознавания.
BYTE GetResult(strNNW *pNNW,BYTE flAll); // Получение результата распознавания.
BYTE CalcResult(strResRec *pRes); // Подсчёт результатов по распознаванию для всех звуков списка.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Cтруктура описания параметров файла, используемого при тренировке сетей.

struct strDBF {

char *FName; // Имя файла.
char *NamePeople; // Имя человека, произносящего звук.
BYTE Gender; // Пол человека, произносящего звук.
BYTE flUse; // Флаг использования.
BYTE flTrain; // Флаг тренировки.
struct strDBSArr DBS; // База данных по звукам внутри файла.
struct strResRec Res; // Результат распознавания для всех звуков базы данных.

strDBF(void); // Конструктор.
~strDBF(void); // Деструктор.
void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
BYTE ReadDBS(char *Path,char *Dir); // Чтение баз данных по звукам внутри файла.
BYTE WriteDBS(char *Path,char *Dir); // Запись баз данных по звукам внутри файла.
void Print(void); // Печать в строку.
BYTE ProcSpectr(strParSpProc *Param,BYTE *flStop); // Разложение в спектр.
BYTE GetPeaks(BYTE *flStop); // Нахождение спектральных линий.
BYTE GetInpData(BYTE typNet,BYTE typInpData,BYTE *flStop); // Нахождение входных данных.
void SetResZero(void); // Обнуление результатов распознавания.
BYTE GetResult(strNNW *pNNW,BYTE flAll); // Получение результата распознавания.
BYTE CalcResult(void); // Подсчёт результатов по распознаванию для всего файла.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Cтруктура базы данных по всем файлам для тренировки нейронной сети.

struct strDBFArr {

BYTE n; // Число файлов.
struct strDBF *DBF; // Массив структур.
char *PathDir; // Директория, где хранятся файлы базы данных.
char *NameFile; // Имя файла базы данных.
BYTE flChange; // Флаг изменения базы данных.

strDBFArr(void); // Конструктор.
~strDBFArr(void); // Деструктор.
void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
void FreeDBF(void); // Освобождение памяти от массива структур.
BYTE AllocDBF(BYTE n_); // Выделение памяти.
BYTE IsOK_DBF(void); // Проверки массива структур.
strDBF *Get(BYTE num); // Даёт указатель на структуру базы данных файла.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
BYTE Read_(char *Path,char *Name); // Чтение из файла.
BYTE Write_(char *Path,char *Name); // Запись в файл.
BYTE Write_(void); // Запись в файл.
BYTE ReadDBS(char *Path); // Чтение баз данных по звукам внутри файла.
BYTE WriteDBS(char *Path); // Запись баз данных по звукам внутри файла.
BYTE SetFlagChange(BYTE num,BYTE flag); // Установка флага изменения.
void SetResZero(void); // Обнуление результатов распознавания.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Cтруктура пункта данных для тренировки нейронной сети.

struct strDataTrain {

BYTE *pFlUseFile; // Указатель на флаг использования для файла.
BYTE *pFlTrainFile; // Указатель на флаг тренировки для файла.
BYTE *pFlUseSnd; // Указатель на флаг использования для звука в отдельности.
BYTE *pFlTrainSnd; // Указатель на флаг тренировки для звука в отдельности.
BYTE flUse; // Флаг использования.
BYTE flTrain; // Флаг тренировки.
struct strInpLay *InpLay; // Указатель на массив входного слоя сети.
struct strInpLay *TrueOut; // Указатель на массив правильного выходного слоя.
BYTE nRep; // Число повторов (вес тренировочного набора).

strDataTrain(void); // Конструктор.
void Zero(void); // Обнуление указателей и инициализация параметров.
BYTE IsOK(void); // Проверки массива структур.
void SetFlags(void); // Установка флагов использования и тренировки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Cтруктура массива данных для тренировки нейронной сети.

struct strDataTrainArr {

UINT nDT; // Число элементов данных.
struct strDataTrain *DT; // Массив структур данных для тренировки нейронной сети.

strDataTrainArr(void); // Конструктор.
~strDataTrainArr(void); // Деструктор.
void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
BYTE Alloc(UINT nDT_); // Выделение памяти.
BYTE IsOK(void); // Проверки массива структур.
strDataTrain *Get(UINT num); // Получение указателя на структуру данных.
BYTE SetFlags(void); // Установка флагов использования и тренировки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Cтруктура статистики для звука.

struct strStatSnd {

char c; // Обозначение звука.
USHRT nIntTrain,nIntCntrl; // Число интервалов для тренировки и контроля.
UINT nSampTrain,nSampCntrl; // Число образцов (по временным дискретам спектра с учётом повторов) для тренировки и контроля.

strStatSnd(void); // Конструктор.
void Zero(void); // Обнуление параметров.
void Print(void); // Печать в строку.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Cтруктура статистики для набора звуков.

struct strStatSndAll {

BYTE nSnd; // Число звуков.
struct strStatSnd *StatSnd; // Массив структур статистики для звуков.

strStatSndAll(void); // Конструктор.
~strStatSndAll(void); // Деструктор.
void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
BYTE Alloc(BYTE nSnd_); // Выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE FillLB(HWND hDlg,int id); // Заполнение списка.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Нумерация битов флага блокировки выхода из диалогового окна базы данных.

#define numBlkDBF_PreProc 0 // Предобработка (Фурье, спектральные линии).
#define numBlkDBF_InpData 1 // Заполнение массивов входных данных сети.
#define numBlkDBF_Train   2 // Тренировка нейронной сети.
#define numBlkDBF_Sound   3 // Прослушивание звука.
#define numBlkDBF_TestDBS 4 // Тест нейронной сети на базе данных.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс для редактирования базы данных и тренировки нейронной сети.

class clDlgDBF_NNW {

HWND hDlg; // Идентификатор диалогового окна.
HWND hwndProgr; // Идентификатор полосы прогресса.
HWND hDlgAdjNNW; // Идентификатор диалогового окна задания параметров нейронной сети.
struct strDBFArr *pDataBase; // Указатель на структуру базы данных по файлпм.
struct strNNW *pNNW; // Указатель на структуру нейронной сети.
struct strNNW *pNNW_Vowel; // Указатель на структуру нейронной сети для гласных.
struct strNNW *pNNW_Cons; // Указатель на структуру нейронной сети для согласных.
struct strNNW *pNNW_Spectr; // Указатель на структуру нейронной сети для всего спектра.
struct strDBF *selDBF; // Указатель на структуру выбранного файла.
BYTE numSel; // Номер выбранной строки.
BYTE numFileLoad; // Номер загруженного файла.
BYTE numSelSound; // Номер выбранной строки в списке звуков.
BYTE flPlaySound; // Флаг вывода звука.
BYTE flStopSound; // Флаг остановки вывода звука.
BYTE typPlaySound; // Тип вывода звука - 0 - исходный звук, !=0 - синтезированный.
BYTE flPreProc; // Флаг выполнения предварительной обработки (преобразование Фурье, выделение спектральных линий, заполнение тренировочного массива).
BYTE flStopPreProc; // Флаг остановки предварительной обработки.
BYTE flPreProcDone; // Флаг, показывающий, что предварительная обработка выполнена.
BYTE flSetData; // Флаг выполнения заполнения массива входных данных.
BYTE flStopSetData; // Флаг остановки установки входных данных.
BYTE flSetDataDone; // Флаг, показывающий, что установка входных данных сети проведена.
BYTE flTypInpData; // Тип установленных входных данных.
BYTE flTrain; // Флаг тренировки.
BYTE flStopTrain; // Флаг остановки тренировки.
BYTE flBlk; // Флаг блокировки выхода.
BYTE typNet; // Тип сети - гласные/согласные/спектр.
HWAVEOUT hwo; // Структура для вывода звука.
clDlgParNNW DlgParNNW; // Объект класса диалогового окна для редактирования параметров нейронной сети.
struct strParNNW *pParNNW; // Указатель но структуру параметров нейронной сети.
struct strParNNW ParNNW_Vowel; // Структура параметров нейронной сети для гласных звуков.
struct strParNNW ParNNW_Cons; // Структура параметров нейронной сети для согласных звуков.
struct strParNNW ParNNW_Spectr; // Структура параметров нейронной сети для применения ко всему спектру.
struct strParTrainNNW ParTrain; // Структура параметров тренировки сети.
struct strDataTrainArr DataTrain; // Cтруктура массива данных для тренировки нейронной сети.
clInpLayArr TrueOutSnd; // Массив правильных выходов нейронной сети для всех звуков.
HBRUSH hBrushBkg,hBrushDial; // Кисти для закрашивания окон.
float *pWaveSynth; // Указатель на массив для вывода синтезированного звука.

void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
void ZeroBrushes(void); // Обнуление кистей для закрашивания окон.
void FreeBrushes(void); // Создание кистей для закрашивания окон.
BYTE CreateBrushes(void); // Создание кистей для закрашивания окон.
void ZeroWaveSynth(void); // Обнуление указателя на массив для вывода синтезированного звука.
void FreeWaveSynth(void); // Удаление массива для вывода синтезированного звука.
BYTE CreateWaveSynth(UINT nWaveSynth); // Выделение памяти для массива для вывода синтезированного звука.
BYTE SaveFileDBF(void); // Сохранение изменений в файл базы данных.
void UnSelFile(void); // Действия при выборе другого файла.
BYTE OnSelChangeFile(void); // Действия при выборе другой строки в списке файлов.
BYTE SetWinParFile(void); // Установка параметров файла базы данных в окнах.
void ClearWinParFile(void); // Очистка окон параметров файла базы данных в окнах.
void UnSelSound(void); // Действия при выборе другого звука.
BYTE OnSelChangeSound(void); // Действия при выборе другой строки в списке звуков.
BYTE FindSoundDiag(void); // Нахождение изображения звука на диаграмме.
BYTE SetWinParSound(void); // Установка параметров отрезка звука базы данных в окнах.
void ClearWinParSound(void); // Очистка окон параметров отрезка звука базы данных в окнах.
BYTE LoadFile(void); // Загрузка файла и построение диаграммы.
BYTE OnChangeStrFile(void); // Действия при изменении выбранной строки файла.
BYTE OnChangeStrSound(void); // Действия при изменении выбранной строки звука.
void SetHeaderWinAlpha(void); // Установка заголовка окна шага.
void SetFlagChange(BYTE num,BYTE flag); // Установка флага изменения.
BYTE ReadNNW(BYTE typ); // Чтение файла нейронной сети.
BYTE SaveNNW(BYTE typ); // Сохранение файла нейронной сети.
BYTE SaveAsNNW(BYTE typ); // Сохранение файла нейронной сети под другим именем.
BYTE ReadParNNW(void); // Чтение файла параметров нейронной сети.
BYTE SaveParNNW(void); // Сохранение файла параметров нейронной сети.
BYTE SaveAsParNNW(void); // Сохранение файла параметров нейронной сети под другим именем.
BYTE AdjustParNNW(void); // Настройка параметров нейронной сети.
BYTE InitNNW(void); // Инициализация новой нейронной сети по заданным параметрам.
BYTE GetParFromNNW(void); // Заполнение структуры параметров сети из выбранной сети.
BYTE AdjParTrain(void); // Редактирование параметров тренировки сети.
BYTE ProcSpectr(BYTE *flStop,BYTE flAll); // Разложение в спектр.
BYTE GetPeaks(BYTE *flStop); // Нахождение спектральных линий.
BYTE GetInpData(BYTE typInpData,BYTE *flStop); // Нахождение входных данных.
BYTE ProcSpectrPeaks(void); // Предобработка: преобразование Фурье, нахождение спектральных линий.
BYTE ProcSetInpData(void); // Предобработка: заполнение входных массивов сети.
BYTE FillTrainData(void); // Заполнение тренировочного массива.
BYTE FillTrueOut(void); // Заполнение массивов правильных значений выходного слоя сети.
void CmndTrainNNW(void); // Команда на тренировку сети.
BYTE TrainNNW(void); // Тренировка нейронной сети.
BYTE TrainNNW_Seq(void); // Тренировка нейронной сети последовательным методом.
BYTE TrainNNW_SeqRep(void); // Тренировка нейронной сети последовательным методом с многократным распространением ошибки.
BYTE TrainNNW_SeqLay(void); // Тренировка нейронной сети последовательным послойным методом.
BYTE TrainNNW_Group(void); // Тренировка нейронной сети групповым методом, в том числе с адаптивным шагом.
BYTE TrainNNW_GroupSearch(void); // Тренировка нейронной сети групповым методом поиска.
BYTE TrainNNW_MonteCarlo(void); // Тренировка нейронной сети методом случайного поиска (Монте-Карло).
BYTE TrainSearchIniRandom(void); // Шаги поиска начального приближения при тренировке нейронной сети.
BYTE StepTrainErr(double *pErr,double *pErrCntrl); // Шаг предъявления образцов с нахождением ошибки.
BYTE StepTrainSequent(double *pErr,double *pErrCntrl); // Шаг предъявления образцов при последовательной тренировке сети методом обратного распространения ошибки.
BYTE StepTrainSequentRep(double *pErr,double *pErrCntrl); // Шаг предъявления образцов при последовательной тренировке сети методом повторного обратного распространения ошибки.
BYTE StepTrainSequentLay(void); // Шаг тренировки нейронной сети последовательным послойным методом.
BYTE InitSequentLay(UINT nNumSampl,UINT *pNumSampl); // Инициализация эталонных значений и истинных значений выходного слоя при тренировке нейронной сети последовательным послойным методом.
BYTE StepSequentLay(BYTE numLay,UINT nNumSampl,UINT *pNumSampl); // Шаг предъявления образцов при тренировке нейронной сети последовательным послойным методом.
BYTE FindVectGroup(double *pErr,double *pWei,double *pErrCntrl,double *pWeiCntrl); // Шаг предъявления образцов при тренировке сети групповым методом обратного распространения ошибки.
BYTE StepFindAdaptStepGroup(void); // Шаг предъявления образцов при нахождении адаптивного шага при тренировке сети групповым методом обратного распространения ошибки.
void SetErrWin(double Err,double ErrCntrl); // Установка ошибок в окнах.
void ClearErrWin(void); // Установка ошибок в окнах.
void GetStepTrain(void); // Получение шага тренировки.
void SetStepTrain(void); // Установка шага тренировки.
void ShowHideWinStepTrain(void); // Визуализация и скрытие окон, относящихся к установке шага или адаптивного шага.
void SetNameTrainMeth(void); // Установка названия метода тренировки.
void ShowProgr(UINT i,UINT n); // Полоса прогресса.
BYTE Command(WPARAM wParam); // Команды.
void OnSelectTypNet(int id); // Выбор типа сети.
void SetPntNNW(void); // Установка указателей на структуры нейронной сети и параметров нейронной сети.
void DrawNet(void); // Перерисовка изображения сети.
void SetFocusWin(void); // Установка фокуса ввода.
BYTE FillLBFiles(void); // Заполнение списка файлов базы данных.
BYTE StartPlaySound(void); // Вывод звука.
BYTE StartPlaySoundPeaks(void); // Вывод синтезированного звука.
void OnStopSound(void); // Действия при остановке проигрывания звука.
void OnChFlagPreProc(void); // Действия при изменении флага выполнения предварительной обработки.
void OnChFlagSetInpData(void); // Действия при изменении флага выполнения заполнения массива входных данных.
void OnChFlagTrain(void); // Действия при изменении флага тренировки сети.
void SetStateRadioTypNet(BYTE En); // Блокировка и разблокирование переключателей выбора типа нейронной сети.
void InitParNNW(void); // Инициализация структур параметров нейронных сетей.
void SetTxtBtnPreProc(void); // Установка текста в кнопку предварительной обработки.
void SetTxtBtnSetData(void); // Установка текста в кнопку заполнения входных данных.
void SetTxtBtnTrain(void); // Установка текста в кнопку тренировки сети.
void SetTxtBtnPlaySound(BYTE typ); // Установка текста в кнопки воспроизведения звука.
void SetTxtBtnBlockSetTime(void); // Установка текста в кнопку блокировки изменения времени в базе данных.
BYTE ShowStatistics(void); // Показ статистики по данным для звуков.
void FindShowResults(void); // Расчёт и изображение показателей по качеству распознавания звуков для базы данных.
BYTE DoTest(BYTE flAll); // Расчёт показателей по качеству распознавания звуков для базы данных.
BYTE AcceptDBF(void); // Принятие изменений параметров файла базы данных.
BYTE DelDBF(void); // Удаление из списка файла базы данных.
BYTE InsDBF(void); // Вставка файла базы данных.
BYTE AddDBF(void); // Добавление файла базы данных.
BYTE AcceptDBS(void); // Принятие изменений параметров отрезка звука базы данных.
BYTE DelDBS(void); // Удаление из списка отрезка звука базы данных.
BYTE InsDBS(void); // Вставка отрезка звука в список.
BYTE AddDBS(void); // Добавление отрезка звука в список.
BYTE BrowseFileDBF(void); // Пролистать в поисках файла базы данных.
void OnChangeGendDBF(BYTE Gender); // Действия при изменении информации о поле человека.

public:

BYTE flBlkTime; // Флаг блокировки установки времени из окна диаграммы.
BYTE flLoadFile; // Флаг загрузки в главной программе файла, выбранного в базе данных.
struct strDBS *selDBS; // Указатель на структуру выбранного звука в выбранном файле.

clDlgDBF_NNW(void); // Конструктор.
~clDlgDBF_NNW(void); // Деструктор.
void SetPntDataBase(strDBFArr *pDataBase_); // Установка указателя на структуру базы данных по файлам.
void SetPntNeurNet(strNNW *pNNW_Vowel_,strNNW *pNNW_Cons_,strNNW *pNNW_Spectr_); // Установка указателей на структуры нейронных сетей для гласных и согласных и всего спектра.
BYTE IsOK_DBF(void); // Проверки массива структур базы данных.
BYTE OnOpenDlg(HWND hDlg_); // Действия при открытии диалогового окна.
void OnCloseDlg(void); // Действия при закрытии диалогового окна.
void OnChDataBase(void); // Действия при загрузке или закрытии базы данных.
void SetTimeSound(float time,BYTE fl); // Установка значения времени в структуре базы данных по звуку.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка сообщений диалогового окна просмтора и редактирования базы данных.
BYTE SetNameNNW(BYTE typ); // Установка имени файла нейронной сети.
BYTE SetFlagLoadFile(void); // Установка флага загрузки файла.
BYTE IsTrain(BYTE typ); // Проверка тренировки сети для заданного типа сети.
BYTE IsDoTrain(void); // Проверка, идёт ли тренировка сети.
BYTE IsDoPreProc(void); // Проверка, идёт ли предварительная обработка.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс для окна визуализации нейронной сети.

class clWinViewNNW {

HWND hDlg; // Идентификатор диалогового окна.
HWND hwndOwner; // Идентификатор родительского окна.
RECT *rcWin; // Прямоугольник окна.
USHRT dxMin,dyMin; // Минимальные размеры окна.
USHRT dxCntrl,dyCntrl; // Размеры окна управления.
RECT rcFrame; // Прямоугольник окна с изображением сети.
float AmpNormNeur; // Амплитуда нормировки изображения нейронов.
float AmpNormInp; // Амплитуда нормировки изображения амплитуд входного слоя нейронов.
float AmpNormSynops; // Амплитуда нормировки изображения синапсов.
BYTE typNet; // Тип сети - гласные/согласные.
BYTE flWork; // Флаг изображения сети в работе.
BYTE flAxons; // Тип выводимой величины для аксонов.
struct strNNW *pNNW; // Указатель на структуру нейронной сети.
struct strNNW *pNNW_Vowel; // Указатель на структуру нейронной сети для гласных.
struct strNNW *pNNW_Cons; // Указатель на структуру нейронной сети для согласных.
struct strNNW *pNNW_Spectr; // Указатель на структуру нейронной сети для всего спектра.
clImgMem *BmpNet; // Изображение нейронной сети.
RECT rc; // Вспомогательная структура прямоугольника.

void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
void CloseFree(void); // Закрытие окон и освобождение памяти.
void OnCloseWin(void); // Действия при закрытии окна.
void GetMinSizeWin(void); // Получение минимального размера окна.
void SetMinSize(LPMINMAXINFO lpMinMax); // Установка минимального размера окна.
BYTE CreateDlgCntrl(void); // Создание диалогового управляющего окна.
void CloseDlgCntrl(void); // Закрытие диалогового управляющего окна.
BYTE OnPaint(HDC hdc); // Рисование в окне.
void UpdateWin(void); // Перерисовка окна.
void ZeroImgMem(void); // Обнуление указателя для битового образа окна изображения сети.
void FreeImgMem(void); // Освобождение памяти от битового образа окна изображения сети.
BYTE CreateImgMem(void); // Создание битового образа окна изображения сети.
BYTE IsOKImgMem(void); // Проверка битового образа окна изображения сети.
BYTE DrawNetMem(void); // Рисование изображения сети в памяти.
void ChPosSizeChWin(void); // Изменение расположения дочерних окон.
BYTE SetPosSizeChWin(void); // Установка расположения дочерних окон.
void OnSelectTypNet(int id); // Выбор типа сети.
void SetNet_(BYTE typ); // Установка типа нейронной сети.
void SetTxtBtnWork(void); // Установка текста в кнопке изображения сети в работе.
void clWinViewNNW::OnSelectTypShowAxons(int id); // Установка типа изображения для аксонов.
BYTE Command(WPARAM wParam); // Команды.

public:

HWND hwnd; // Идентификатор окна.

clWinViewNNW(void);
~clWinViewNNW(void);
void SetParPnt(HWND hwndOwner_,RECT *rcWin_); // Установка параметров и указателей.
void SetPntNeurNet(strNNW *pNNW_Vowel_,strNNW *pNNW_Cons_,strNNW *pNNW_Spectr_); // Установка указателей на структуры нейронных сетей для гласных и согласных.
BYTE CreateWin(void); // Создание окна.
void CloseWin(void); // Закрытие окна.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка сообщений окна.
LRESULT MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка очереди сообщений окна управления.
void DrawNet(void); // Перерисовка изображения сети.
void SetNet(BYTE typ); // Установка типа нейронной сети.
void SetFlagWork(BYTE flWork_); // Установка флага изображения сети в работе.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров для анализа потока данных для звука.

struct strParAnSnd {

float tStore; // Время накопления сигнала.
float weiStore; // Коэффициент учёта накопленного сигнала.
float weiInst; // Коэффициент учёта текущего сигнала.

BYTE IsOK(void); // Проверки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура для анализа потока данных для звука.

struct strAnSnd {

USHRT nBuf,cnt; float *Buf,weiStore,weiInst; double sum;

strAnSnd(void); // Конструктор.
~strAnSnd(void); // Деструктор.
void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
BYTE Init(strParAnSnd *PAS,float tStep); // Инициализация.
BYTE IsOK(void); // Проверки.
BYTE Start(void); // Начало работы.
BYTE Step(float Val,float *pRes); // Шаг работы.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура для анализа потока данных для нескольких звуков.

struct strAnSndArr {

BYTE nArr; struct strAnSnd *pArr;

strAnSndArr(void); // Конструктор.
~strAnSndArr(void); // Деструктор.
void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
void Clear(void); // Освобождение памяти в структурах.
BYTE Create(BYTE nArr_); // Создание массива.
BYTE IsOK(void); // Проверки массива структур.
BYTE Init(strParAnSnd *PAS,BYTE nPAS,float tStep,BYTE flNew); // Инициализация.
BYTE Start(void); // Начало работы.
BYTE Step(float *pVal,float *pRes,BYTE nVal); // Шаг работы.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура для анализа потока данных.

struct strAnalyseSound {

float ResVowel[nVoicesVowel],ResCons[nVoicesCons]; // Массивы для хранения результатов распознавания.
struct strAnSndArr AnSndVowel,AnSndCons; // Структуры для анализа потока данных.

BYTE Init(float tStep,BYTE flNew); // Инициализация.
BYTE Start(void); // Начало работы.
BYTE Step(float *pVal,BYTE nVal,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // Шаг работы.
};

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
// Идентификаторы дочерних окон.

#define idMain_SpDiag   1 // Идентификатор дочернего окна спектральной диаграммы.
#define idMain_GrSig    2 // Идентификатор дочернего окна графика сигнала.
#define idMain_GrSpectr 3 // Идентификатор дочернего окна графика спектра.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Нумерация битов флага блокировки выхода из программы.

#define numBlkMain_Proc   0 // Обработка.
#define numBlkMain_Sound  1 // Вывод звука.
#define numBlkMain_SndCap 2 // Захват звука.
#define numBlkMain_DlgDBS 3 // Открыто диалоговое окно базы данных и тренировки сети.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс главного окна.

class clMain {

BYTE flTi,flFr,flAm,flStopSound,flPlaySound,flEnCaptSound,flCaptSound,flStopCaptSound,flRegCapt,
flProc,flStopProc,flDBS,flDlgDBS,flBlk,methDecSound,flCurGrSig,typShowLineDiag,typUseNNWRec;
int pScDiagH,pMScDiagH,pScDiagV,pMScDiagV,pScGrSp,pMScGrSp,pScGrSig,pMScGrSig,CoordTimeDiag,CoordTimeSig;
UINT PosCurSnd,TimeRecBuf,TimeRecProc,nRecChar; float AmpSig,AmpNorm,AmpSpect,TimeCur,FreqCur;
RECT rc,rcDiag,rcSig,rcSpect,rcCntrl,rcViewNNW,rcText; HWND hwndProgr,hwndPerc; HBRUSH hBrushBkg,hBrushDial;
HMENU hMenu; HWAVEOUT hwo;

clHelpEx *Help; // Класс справки.
clLoadDLLSndCap *SndCap; // Класс для работы с библиотекой по захвату звука.
struct strSndArr Snd; // Класс сигнала.
clSndCapData *SndCapData; // Класс звука, полученного при записи в виде отдельных отрезков.
clBmpPict *BmpDiag; // Битовое изображение диаграммы.
clSpDiag SpectrAmp; // Двумерный массив диаграммы.
clSpLinesArr SpLines; // Класс массива спектральных линий.
clArrBYTE ResNNW; // Массив номеров символов.
clString RecNNW; // Массив номеров символов, распознаваемых в реальном времени.
struct strDBFArr DataBase; // Класс базы данных.
struct strNNW NNW_Vowel,NNW_Cons,NNW_Spectr; // Классы нейронных сетей.
struct strPal PalDiag; // Структура палитры для изображения диаграммы.
struct strAnalyseSound AnSound; // Структура для анализа потока символов.
clDlgDBF_NNW DlgDBFNNW; // Класс диалогового окна базы данных и тренировки нейронной сети.
clWinViewNNW WinViewNNW; // Класс окна просмотра работы нейронной сети.
clWinText WinText; // Класс окна текста - результата распознавания.

void Zero(void); // Обнуление идентификаторов и указателей.
void Free(void); // Удаление объектов из памяти.
void ZeroBrushes(void); // Обнуление кистей для закрашивания окон.
void FreeBrushes(void); // Создание кистей для закрашивания окон.
BYTE CreateBrushes(void); // Создание кистей для закрашивания окон.
void ZeroHelp(void); // Обнуление указателя для класса для вывода файла справки.
void FreeHelp(void); // Уничтожение класса для вывода файла справки.
BYTE CreateHelp(void); // Создание класса для вывода файла справки.
void ChMenuHelp(void); // Изменение состояния пункта меню справки.
void ZeroBmpDiag(void); // Обнуление указателя на класс для вывода изображения диаграммы.
void FreeBmpDiag(void); // Удаление класса для вывода изображения диаграммы.
BYTE CreateBmpDiag(void); // Создание класса для вывода изображения диаграммы.
void OnBegin(void); // Действия при создании объекта класса главного окна.
BYTE CreateDlgCntrl(void); // Создание диалогового управляющего окна.
BYTE CreateWinDiag(void); // Создание дочернего окна диаграммы.
void OnChSizeWinDiag(void); // Действия при изменении размеров окна диаграммы.
BYTE SetScrollDiagH(void); // Установка параметров прокрутки окна диаграммы по горизонтали.
BYTE SetScrollDiagV(void); // Установка параметров прокрутки окна диаграммы по вертикали.
BYTE HScrollDiag(WPARAM wParam); // Пролистывание окна диаграммы по горизонтали.
BYTE VScrollDiag(WPARAM wParam); // Пролистывание окна диаграммы по вертикали.
BYTE OnMouseMoveDiag(LPARAM lParam); // Действия при перемещении курсора мыши в окне диаграммы.
BYTE CreateWinGraph(void); // Создание дочернего окна графика сигнала.
BYTE OnMouseMoveGraphSig(LPARAM lParam); // Действия при перемещении курсора мыши в окне графика сигнала.
void OnChSizeWinGraphSig(void); // Действия при изменении размеров окна графика сигнала.
BYTE SetScrollGrSig(void); // Установка параметров прокрутки окна графика сигнала.
BYTE HScrollGrSig(WPARAM wParam); // Пролистывание окна графика сигнала.
BYTE CreateWinGraphSpectr(void); // Создание дочернего окна графика спектра.
BYTE OnMouseMoveGraphSpectr(LPARAM lParam); // Действия при перемещении курсора мыши в окне графика спектра.
void OnChSizeWinGraphSpectr(void); // Действия при изменении размеров окна графика спектра.
BYTE SetScrollGrSpectr(void); // Установка параметров прокрутки окна графика спектра.
BYTE HScrollGrSpectr(WPARAM wParam); // Пролистывание окна графика спектра.
BYTE Command(WPARAM wParam); // Команды.
void FreeDiagRes(void); // Освобождение памяти для диаграммы и других результатов.
BYTE ComputeDiag(void); // Расчёт диаграммы.
BYTE ComputeSpLines(void); // Нахождение спектральных линий для всего файла.
BYTE RecognNNW_All(void); // Распознавание методом нейронных сетей для всего файла.
BYTE OutTextRecogn_All(void); // Вывод текста распознавания после обработки в окно текста.
BYTE DrawDiag(void); // Построение спектральной диаграммы.
BYTE OnPaintDiag(HDC hdc); // Рисование в окне спектральной диаграммы.
BYTE DrawCursorsDiag(HDC hdc); // Рисование курсоров в окне спектральной диаграммы.
BYTE OnPaintDiagDef(HDC hdc); // Закрашивание окна спектральной диаграммы.
BYTE OnPaintGraphSig(HDC hdc); // Рисование в окне графика сигнала.
BYTE DrawCursorGraphSig(HDC hdc); // Рисование курсора в окне сигнала.
BYTE OnPaintGraphSigDef(HDC hdc); // Закрашивание окна графика сигнала.
BYTE OnPaintGraphSpectr(HDC hdc); // Рисование в окне графика спектра.
BYTE OnPaintGraphSpectrDef(HDC hdc); // Закрашивание окна графика спектра.
BYTE DrawPeaksGraphSpectr(HDC hdc); // Рисование спектральных линий в окне графика спектра.
BYTE RecognNNW(void); // Распознавание звуков методом нейронных сетей.
BYTE ProcRecRealTime(void); // Обработка и распознавание в реальном времени.
void FindCoordChildWin(void); // Нахождение координат дочених окон.
void MoveChWin(void); // Перемещение окон сигнала и диаграммы.
void OnChSizeWin(void); // Перемещение дочерних окон сигнала, диаграммы и графика спектра.
void CloseFileSound(void); // Закрытие звукового файла.
BYTE OpenFileSound(void); // Открытие звукового файла.
BYTE SaveFileSound(void); // Сохранение звукового файла.
void ZeroSndCap(void); // Обнуление указателя на объект класса библиотеки захвата звука.
void FreeSndCap(void); // Удаление объекта класса библиотеки захвата звука.
BYTE CreateSndCap(void); // Создание объекта класса библиотеки захвата звука.
BYTE StartCaptureSound(BYTE flag); // Включение записи звука.
void StopCaptureSound(BYTE flag); // Остановка записи звука.
void StopCaptureSound_(void); // Остановка записи звука.
void SetTxtBtnCaptSound(void); // Установка текста в кнопку записи звука.
void SetTxtBtnRecSound(void); // Установка текста в кнопку распознавания звука.
BYTE SaveSndCapData(void); // Сохранение результатов захвата звука.
BYTE DlgAdjSound(void); // Настройка захвата звука.
void ZeroSndCapData(void); // Класс хранения данных при записи звука: обнуление указателя.
void FreeSndCapData(void); // Класс хранения данных при записи звука: оcвобождение памяти.
BYTE CreateSndCapData(void); // Класс хранения данных при записи звука: создание.
void AdjParSpectr(void); // Редактирование параметров спектрального разложения.
void AdjParPeaks(void); // Редактирование параметров выделения спектральных пиков.
void CloseDataBase(void); // Закрытие базы данных.
BYTE OpenDataBase(void); // Открытие файла базы данных.
void OpenDlgDBS_NNW(void); // Открытие диалогового окна базы данных и тренировки сети.
void ChBtnMenuOpenDlgDBS_NNW(void); // Изменение состояния кнопки и пункта меню открытия диалогового окна базы данных и тренировки сети.
void ChBtnCaptSound(void); // Установка состояния кнопки захвата звука.
void SetPntWinViewNNW(void); // Установка параметров и указателей для окна визуализации нейронной сети.
BYTE GetSizeWinViewNNW(void); // Установка размеров окна визуализации нейронной сети.
void OpenWinViewNNW(void); // Открытие окна визуализации нейронной сети.
void SetPntWinText(void); // Установка параметров и указателей для окна текста.
BYTE GetSizeWinText(void); // Установка размеров окна текста.
void OpenWinText(void); // Открытие окна тескта.
void ClearWinText(void); // Очистка окна текста.
void SetWinText(char *Text); // Изображение текста в окне.
BYTE StartPlaySound(void); // Вывод звука.
void OnStopSound(void); // Действия при остановке проигрывания звука.
void SetTxtBtnPlaySound(void); // Установка текста в кнопку воспроизведения звука.
BYTE DrawCurSound(void); // Перерисовка курсора при проигрывании звука.
void OnChCurTime(void); // Действия при изменении положения курсора по времени.
void OnChCurTimeGraphSig(void); // Действия при изменении положения курсора по времени в окне графика сигнала.
void OnSetCurTimeDiag(int x,BYTE fl); // Установка курсора по времени в окне диаграммы.
void OnSetCurTimeGraphSig(int x); // Установка курсора по времени в окне графика сигнала.
void SetTimeDBF(BYTE fl); // Передача значения времени в базу данных.
void ChMenuProcOutput(void); // Изменение состояния пункта меню обработки выходного потока символов.
BYTE CommandCntrl(WPARAM wParam); // Обработка команд окна управления.
void SetFocusWin(void); // Установка фокуса ввода.
void CheckCurPos(void); //Проверка местоположения курсора.
BYTE LoadFile(char *Path,char *Dir,char *FileName); // Загрузка файла, построение графика сигнала.
BYTE SaveFile(char *Path,char *Dir,char *FileName); // Сохранение файла в формате "WAV".
void ComputeDrawDiag(void); // Расчёт и построение диаграммы.
void SetBtnMenuProc(void); // Установка текста в кнопку обработки и выделение пункта меню.
void OnDrawDiag(void); // Действия после изменения диаграммы.
BYTE LoadNNW(BYTE typ); // Загрузка нейронных сетей.
BYTE SaveNNW(BYTE typ); // Сохранение нейронных сетей.
BYTE SaveAsNNW(BYTE typ); // Сохранение нейронных сетей под другим именем.
BYTE CheckSaveNNW(void); // Проверка несохранённых сетей и сохранение при необходимости.
void OnSelTypViewSndLineDiag(int id); // Действия при выборе типа изображаемых звуков в линии символов на диаграмме.
void SetTypRecNNW(int id); // Установка типа сетей при распознавании.
void SetMenuTypNNWRec(void); // Установка меню для типа сетей при распознавании.
void OnCloseWin(void); // Действия при закрытии окна.

public:

HWND hwnd,hDlg,hwndDiag,hwndGraphSig,hwndGraphSpectr,hDlgDB;

char *FileNameWAV; // Имя открытого звукового файла.
struct strParSpProc ParSpectr; // Параметры спектральной обработки.
struct strPal PalPos,PalSign; // Структуры палитр для изображения только положительных значений и разного знака.

clMain(HWND hwnd_); // Конструктор.
~clMain(void); // Деструктор.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка очереди сообщений окна.
LRESULT MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка очереди сообщений окна управления.
LRESULT MsgCommandDiag(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка очереди окна спектральной диаграммы.
LRESULT MsgCommandGraphSig(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка очереди окна графика сигнала.
LRESULT MsgCommandGraphSpectr(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка очереди окна графика спектра.
BYTE SaveBufSound(DWORD szBuf,void *pBuf); // Сохранение при записи звука.
BYTE LoadProcFile(char *Path,char *Dir,char *FileName); // Загрузка файла, построение диаграммы, построение графика сигнала.
void OnCloseDlgDBS_NNW(void); // Действия при закрытии диалогового окна базы данных и тренировки сети.
void UpdateWinDiag(void); // Перерисовка окна диаграммы.
BYTE SetTimeDiag(float Time); // Установка пролистывания диаграммы на заданное время.
void DrawNet(void); // Перерисовка изображения сети.
void ChBtnMenuWinViewNNW(void); // Изменение состояния кнопки и пункта меню открытия окна визуализации нейронной сети.
void ChBtnMenuWinText(void); // Изменение состояния кнопки и пункта меню открытия окна текста.
BYTE IsCaptSound(); // Проверка, идёт ли захват звука.
BYTE GetNumSndRecogn(strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // Получение номера звука при распознавании потока речи.
void ShowProgr(UINT i,UINT n); // Полоса прогресса.
};
