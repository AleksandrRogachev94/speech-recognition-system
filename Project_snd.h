/*...........................................................................................................

clWavData,strSndBuf,clSndCapArr,clSndCapData,clDLLObjSoundCap,clLoadDLLSndCap,clDlgSndCap

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс звукового сигнала, прочитанного из файла *.wav.

class clWavData {

void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
void ZeroSnd(void); // Обнуление указателей и инициализация параметров для массивов звука.
BYTE IsOK_Header(void); // Проверки структуры заголовка.
BYTE Read_(HANDLE File); // Чтение из файла.
BYTE ReadData(HANDLE File); // Чтение данных из файла.
BYTE Write_(HANDLE File); // Запись в файл.
BYTE WriteData(HANDLE File); // Запись данных в файл.

public:

BYTE ch,nBS; UINT ln; BYTE *bSnd[2]; SHRT *sSnd[2]; PCMWAVEFORMAT WF; WAVEFORMAT *pwf;

clWavData(void);
~clWavData(void);
void FreeSnd(void); // Освобождение памяти для массивов звука.
BYTE AllocSnd(UINT ln_,BYTE chan_,BYTE nBS_); // Выделение памяти для массивов звука.
BYTE IsOKSnd(void); // Проверки массивов звука.
void Init_Header(BYTE ch_,BYTE nBS_,DWORD sps); // Инициализация структуры заголовка.
BYTE Read(char *fName); // Чтение из файла.
BYTE Write(char *fName); // Запись в файл.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура отрезка звукового сигнала.

struct strSndBuf {

UINT ln; SHRT *Snd;

strSndBuf(void);
~strSndBuf(void);
void Zero(void); // Обнуление указателей.
void Free(void); // Освобождение памяти.
BYTE Create(UINT ln_); // Создание.
BYTE IsOK(void); // Проверки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Тип - указатель на класс отрезка звукового сигнала.

typedef strSndBuf *typPntSndBuf;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы для класса 'clSndCapArr'.

#define nSA_Step 50 // Размер дополнительно выделяемого массива.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Набор отрезков звука, полученных при записи.

class clSndCapArr {

UINT nM; typPntSndBuf *Arr;

void Zero(void); // Обнуление указателей и инициализация параметров.
void Clear(void); // Удаление структур 'strSndBuf'.
BYTE ReAlloc(UINT nM_); // Перераспределение памяти.

public:

UINT nI;

clSndCapArr(void); // Конструктор.
~clSndCapArr(void); // Деструктор.
void Free(void); // Освобождение памяти.
BYTE Alloc(UINT nM_); // Выделение памяти.
BYTE CheckSize(UINT nM_); // Проверка размера массива и при необходимости выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE Create(UINT num); // Создание объекта отрезка звукового сигнала.
strSndBuf *Get(UINT num); // Получение отрезка звукового сигнала.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Стандартный размер буфера захвата звука.

#define szSndCapDataCycle 128 // Число элементов циклического буфера для захвата звука при распознавании.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс звука, полученного при записи в виде отдельных отрезков.

class clSndCapData {

void Zero(void); // Обнуление указателей.
void FreeSCA(void); // Освобождение памяти.
BYTE CreateSCA(void); // Создание класса набора отрезков звука.

public:

UINT nSPS,nCnt; clSndCapArr *SCA;

clSndCapData(void);
~clSndCapData(void);
void Free(void); // Удаление массивов звука.
BYTE Add(UINT szSnd,SHRT *pSnd); // Добавление отрезка звукового сигнала.
BYTE IsOK(void); // Проверки набора отрезков звука.
strSndBuf *Get(UINT num); // Получение отрезка звукового сигнала.
BYTE CreateCycle(UINT nM_); // Создание циклического буфера.
BYTE AddCycle(UINT szSnd,SHRT *pSnd); // Добавление отрезка звукового сигнала в цикл.
BYTE GetCycle(UINT szSnd,SHRT *pSnd,UINT Shift); // Получение отрезка звукового сигнала из цикла.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Стандартный размер буфера захвата звука.

#define szNotifySndCap 2048

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Число и нумерация форматов звука.

#define nSndForm 5 // Число форматов по выборкам в секунду.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы функций для класса 'clDLLObjSoundCap'.

typedef void (*funSndCap_CallBack)(PNT_DATA Pnt,DWORD szBuf,void *Buf); // Тип функции обратного вызова для передачи данных.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс объекта для захвата звука (контейнер).

class clDLLObjSoundCap {

void Zero_(void); // Инициализация параметров.
void ZeroPntFunc(void); // Обнуление указателя на класс и указателя на функцию обратного вызова.

protected:

BYTE *pFlStop; // Указатель на флаг остановки захвата звука.
PNT_DATA Pnt; // Указатель на вызывающий класс.
funSndCap_CallBack funCB; // Функция обратного вызова для передачи данных.

public:

BYTE numDevice; // Номер устройства для вывода звука.
BYTE numFormat; // Номер формата звука.

clDLLObjSoundCap(void);
~clDLLObjSoundCap(void);
void SetPntFunc(PNT_DATA Pnt_,funSndCap_CallBack funCB_,BYTE *pFlStop_); // Установка указателей.
virtual BYTE _stdcall FillInfDevices(void); // Загрузка информации об имеющихся устройствах ввода звука.
virtual BYTE _stdcall InitDirectSound(void); // Инициализация 'Direct Sound'.
virtual void _stdcall UnInitDirectSound(void); // Деинициализация 'Direct Sound'.
virtual BYTE _stdcall Open(void); // Открытие интерфейса.
virtual void _stdcall Close(void); // Закрытие интерфейса.
virtual BYTE _stdcall StartCapture(void); // Запуск захвата звука.
virtual void _stdcall StopCapture(void); // Остановка захвата звука.
virtual BYTE _stdcall CheckMessage(void); // Опрос сообщений при захвате звука.
virtual void _stdcall GetParSnd(UINT *nSPS,BYTE *nChan,BYTE *nbPS); // Получение параметров формата звука.
virtual BYTE _stdcall FillCB_Devices(HWND hDlg,UINT id); // Заполнение списка имеющимися устройствами записи звука.
virtual BYTE _stdcall FillCB_Formats(HWND hDlg,UINT id); // Заполнение списка имеющимися для выбранного устройства форматами звука.
virtual void _stdcall SetNotifySize(UINT szNotify_); // Установка размера буфера сообщений.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы функций, используемых в классе для работы с библиотекой захвата звука.

typedef BYTE (_stdcall *pDll_SndCap_CreateObj)(clDLLObjSoundCap **Obj); // Создание объекта.
typedef void (_stdcall *pDll_SndCap_DeleteObj)(clDLLObjSoundCap **Obj); // Удаление объекта.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс для работы с библиотекой захвата звука.

class clLoadDLLSndCap {

HMODULE hLib; // Библиотека.

pDll_SndCap_CreateObj funCreateObj; // Создание объекта.
pDll_SndCap_DeleteObj funDeleteObj; // Удаление объекта.

void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
void FreeLibr(void); // Освобождение памяти для библиотеки.
BYTE LoadLibr(char *nameDir,char *nameDLL); // Загрузка библиотеки.
void ZeroFunLib(void); // Обнуление указателей на функции библиотеки.
BYTE LoadFunLib(void); // Загрузка функций библиотеки.
void ZeroDLLObj(void); // Обнуление указателей на объект библиотеки.
BYTE FreeDLLObj(void); // Удаление объекта библиотеки.
BYTE LoadDLLObj(void); // Создание объекта библиотеки.

public:

clDLLObjSoundCap *Obj; // Класс объекта для захвата звука.

clLoadDLLSndCap(void);
~clLoadDLLSndCap(void);
BYTE Load(char *nameDir,char *nameDLL); // Загрузка библиотеки и функций.
BYTE StartCapture(void); // Запуск захвата звука.
void StopCapture(void); // Остановка захвата звука.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс диалогового окна настройки захвата звука.

class clDlgSndCap {

BYTE numDev,numForm,flCh; HWND hDlg; clDLLObjSoundCap *ObjSC;

void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
BYTE SelDevice(BYTE num); // Выбор устройства для захвата звука.
BYTE SelFormat(BYTE num); // Выбор формата звука.
void ChBntSave(void); // Установка состояния кнопки сохранения результатов выбора устройства и формата звука.
BYTE Command(WPARAM wParam); // Команды от окон и органов управления.

public:

clDlgSndCap(void);
~clDlgSndCap(void);
BYTE Dialog(HWND hWndOwner,clDLLObjSoundCap *ObjSC_,BYTE *flRet); // Открытие диалогового окна.
BYTE Create(HWND hDlg_); // Создание всех компонент объекта.
LRESULT MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка очереди сообщений окна.
};
