/*...........................................................................................................

clSpDiag,
strParSpProc,
strNeurVect,strEtalVal,strNeuron,strLay,strInpLay,clInpLayArr,strParFreqCorrPeaks,strParFreqCorrSpectr,
strPropNNW,strNNW,
strInfTrSerRand,strParTrainNNWSearch,strArrTrSearch,strParLay,strParNNW,
clDlgParNNW,
strSpectrLine,strSpLines,clSpLinesArr,
strParGetPeaks,strParInpSpectr,strParTrainNNW,
strParIncHighSynth

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы функций.

typedef void (*pFunShowProgr)(PNT_DATA Pnt,UINT i,UINT n); // Полоса прогресса.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс спектральной диаграммы.

class clSpDiag: public clArr2Float {

void Zero_St(void); // Обнуление шагов.

public:

double stArr,stLn;

clSpDiag(void);
void Free_St(void); // Освобождение памяти с обнулением шагов.
BYTE IsOK_St(void); // Проверки включая проверки шагов.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Окна для спектрального преобразования в движущемся окне.

#define nTypMovWinSpectr 14 // Число типов окон.

#define methSpFour_Cos        0 // Косинусоидальное сглаживание (окно Тьюки) с параметром 0.5.
#define methSpFour_Hann       1 // Косинусоидальное сглаживание с параметром 0. (функция Ханна).
#define methSpFour_Hamming    2 // Окно Хэмминга.
#define methSpFour_Blackman   3 // Окно Блэкмена.
#define methSpFour_BlHarr     4 // Окно Блэкмена-Харриса.
#define methSpFour_KaisBess   5 // Окно Кайзера-Бесселя.
#define methSpFour_Natall     6 // Окно Наталла.
#define methSpFour_BlNatall   7 // Окно Блэкмена-Наталла.
#define methSpFour_FlatTop    8 // Окно с плоской вершиной.
#define methSpFour_Barlett    9 // Окно Барлетта.
#define methSpFour_BarHann   10 // Окно Барлетта-Ханна.
#define methSpFour_Lanczos   11 // Окно Ланкзоса.
#define methSpFour_Gauss     12 // Функция Гаусса.
#define methSpFour_NoWin     13 // Без сглаживания.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Коэффициенты оконных функций.

#define coeWinCos 0.5F // Коэффициент окна с косинусоидальным сглаживанием.
#define coeWinKaisBess 4.54F // Коэффициент окна Кайзера-Бесселя.
#define coeWinGauss 0.3F // Коэффициент окна Гаусса.
#define coeWinDolphCheb 30.0F // Коэффициент окна Дольфа-Чебышева (ослабление лепестков дБ).

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы обработки.

#define Time_Width_Spectr_Stand 0.085F // Длительность временного окна (с) (cтандартное значение).
#define Time_Width_Spectr_Min 1.e-2F // Длительность временного окна (с) (минимальное значение).
#define Time_Width_Spectr_Max 2.0F // Длительность временного окна (с) (максимальное значение).
#define Time_Step_Spectr_Stand 0.02F // Шаг перемещения временного окна (с) (cтандартное значение).
#define Time_Step_Spectr_Min 1.e-2F // Шаг перемещения временного окна (с) (минимальное значение).
#define Time_Step_Spectr_Max 1.0F // Шаг перемещения временного окна (с) (максимальное значение).
#define nWinWid_Min 64 // Минимальная ширина временного окна в точках.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров спектральной обработки.

struct strParSpProc {

float Time_Width; // Ширина временного окна.
float Time_Step; // Шаг перемещения временного окна.
BYTE methSpFour; // Метод сглаживания временным окном.

strParSpProc(void); // Конструктор.
BYTE IsOK(void); // Проверки.
BYTE Check(void); // Проверки и исправления.
BYTE Read_(FILE *file); // Чтение из файла.
BYTE Write_(FILE *file); // Запись в файл.
BYTE Read(char *Path,char *fName); // Чтение из файла.
BYTE Write(char *Path,char *fName); // Запись в файл.
BYTE SetDlg(HWND hDlg); // Установка в диалоговое окно.
BYTE GetDlg(HWND hDlg); // Получение из диалогового окна.
void OnCreateDlg(HWND hDlg); // Действия при открытии диалогового окна.
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структуры и классы для обработки методом нейронных сетей.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Определение типов функций.

typedef double (*pFunAct)(double S); // Функция активации нейрона.
typedef double (*pFunDerAct)(double y); // Производная функции активации нейрона.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы функции активации.

#define nTypFunAct 5 // Число типов функций.

#define TypFunAct_Sigm   0 // Сигмоидная функция.
#define TypFunAct_BiSigm 1 // Биполярная cигмоидная функция.
#define TypFunAct_HypTan 2 // Гиперболический тангенс.
#define TypFunAct_Log    3 // Логарифмическая.
#define TypFunAct_Lin    4 // Линейная.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура векторов и параметров для тренировки нейронной сети.

struct strNeurVect {

BYTE flTUse,flSmart; USHRT nWeights; double T,*Weights,*Shifts;

strNeurVect(void); // Конструктор.
~strNeurVect(void); // Деструктор.
void Zero(void); // Обнуление идентификаторов и указателей.
void ZeroPar(void); // Обнуление идентификаторов для векторов.
void Free(void); // Удаление массива из памяти.
BYTE Alloc(USHRT nWeights_); // Выделение памяти.
BYTE IsOK(void); // Проверки массива.
BYTE SetZero(void); // Установка нулей в массив векторов.
BYTE GetSetWeightsShifts(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet); // Получение или установка массива весов и смещений.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура эталонных значений слоя нейрона.

struct strEtalVal {

UINT nVal; double *pVal;

strEtalVal(void); // Конструктор.
~strEtalVal(void); // Деструктор.
void Zero(void); // Обнуление идентификаторов и указателей.
void Free(void); // Удаление массива из памяти.
BYTE Alloc(UINT nVal_); // Выделение памяти.
BYTE IsOK(void); // Проверки массива.
BYTE GetMinMax(double *pMin,double *pMax); // Нахождение минимального и максимального значений.
BYTE Correct(double coe,double shift); // Корректировка.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура нейрона.

struct strNeuron {

BYTE flTUse,flSmart; USHRT nWeights; double Val,T,*Weights,*Shifts,Err;

struct strNeurVect Vect; // Структура векторов и параметров для тренировки нейронной сети.
struct strEtalVal Etal; // Структура эталонных значений слоя нейрона.

strNeuron(void); // Конструктор.
~strNeuron(void); // Деструктор.
void Zero(void); // Обнуление идентификаторов и указателей.
void ZeroPar(void); // Обнуление идентификаторов.
void Free(void); // Удаление массива весов из памяти.
BYTE Alloc(USHRT nWeights_); // Выделение памяти для массива весов.
BYTE IsOK(void); // Проверки массива весов.
BYTE IsOK_Vect(void); // Проверки массива векторов.
BYTE GetSetArrSearch(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet,BYTE flArr); // Получение или установка массива весов и смещений или векторов весов и смещений.
BYTE GetSetWeightsShifts(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet); // Получение или установка массива весов и смещений.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
void ZeroInit(void); // Обнуление весовых коэффициентов и порогового уровня.
BYTE RandInit(float CoeWei,float CoeTe); // Нахождение начального приближения весовых коэффициентов и пороговых уровней.
BYTE RandChange(float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA); // Случайное изменение весовых коэффициентов и пороговых уровней.
BYTE AddWeightsShiftsGroup(double Alpha); // Добавление вектора приращения к коэффициентам и смещениям при групповом обучении.
BYTE SetValEqualEtal(UINT numSample); // Установка значения, равного эталонному значению в послойном обучении.
BYTE SetEtalEqualVal(UINT numSample); // Установка эталонного значения, равного текущему значению нейрона в послойном обучении.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура слоя нейронов.

struct strLay {

BYTE TypFunAct,flTUse,flSmart; // Число нейронов, функция активации и флаг использования порогов и смещений.
USHRT n; // Число нейронов.
double Alpha; // Адаптивный шаг.
double Numer,Denom; // Переменные для нахождения адаптивного шага.
struct strNeuron *Neurons; // Массив структур нейронов.

strLay(void); // Конструктор.
~strLay(void); // Деструктор.
void Zero(void); // Обнуление идентификаторов и указателей.
void InitPar(void); // Инициализация или обнуление идентификаторов.
void Free(void); // Удаление объектов из памяти.
BYTE Alloc(USHRT n_); // Выделение памяти для массива структур нейронов.
BYTE IsOK(void); // Проверки.
strNeuron *Get(USHRT num); // Получение указателя на структуру нейрона.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
BYTE AllocWeights(USHRT nNeurPrev); // Выделение памяти для массивов весовых коэффициэнтов для каждого нейрона. 
void FreeVect(void); // Удаление массивов векторов из памяти.
BYTE AllocVect(void); // Выделение памяти для массивов векторов.
BYTE IsOK_Vect(void); // Проверки массивов векторов.
BYTE SetZeroVect(void); // Установка нулей в массивы векторов.
BYTE GetSetArrSearch(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet,BYTE flArr); // Получение или установка массива весов и смещений или векторов весов и смещений.
BYTE SetFlagTShUse(void); // Установка флагов использования порогов и смещений во все нейроны.
void ZeroInit(void); // Обнуление весовых коэффициентов и пороговых уровней всех нейронов.
BYTE RandInit(float CoeWei,float CoeTe); // Нахождение начального приближения весовых коэффициентов и пороговых уровней.
BYTE RandChange(float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA); // Случайное изменение весовых коэффициентов и пороговых уровней.
BYTE AddWeightsShiftsGroup(void); // Добавление вектора приращения к коэффициентам и смещениям при групповом обучении.
BYTE FreeEtal(void); // Удаление из памяти массивов эталонных значений нейронов.
BYTE AllocEtal(UINT nSamples); // Выделение памяти для массивов эталонных значений нейронов.
BYTE SetValEqualEtal(UINT numSample); // Установка значений нейронов, равных эталонным значениям в послойном обучении.
BYTE SetEtalEqualVal(UINT numSample); // Установка эталонных значений нейронов, равных текущим значениям нейронов в послойном обучении.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура входного слоя нейронов.

struct strInpLay {

USHRT n; double *Values;

strInpLay(void); // Конструктор.
~strInpLay(void); // Деструктор.
void Zero(void); // Обнуление идентификаторов и указателей.
void Free(void); // Удаление объектов из памяти.
BYTE Alloc(USHRT n_); // Выделение памяти для массива значений нейронов.
BYTE IsOK(void); // Проверки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс массива структур входного или выходного слоя нейронов.

struct clInpLayArr {

struct strInpLay *Data; // Массив структур входного или выходного слоя нейронов.

public:

UINT nData; // Число элементов массива.
USHRT n; // Число значений в каждом массиве.

clInpLayArr(void); // Конструктор.
~clInpLayArr(void); // Деструктор.
void Zero(void); // Обнуление идентификаторов и указателей.
void Free(void); // Удаление из памяти.
BYTE Alloc(UINT nData_,USHRT n_); // Выделение памяти.
BYTE IsOK(void); // Проверки.
strInpLay *Get(UINT num); // Получение указателя на структуру данных.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы.

#define CorrDBFrCorr_Stand 20.0F // Усиление частотной коррекции (дБ).

#define numIniFrCorr_Stand 5 // Начальный номер входных нейронов, где начинается частотная коррекця - стандартное значение.
#define numIniFrCorr_Max  15 // Начальный номер входных нейронов, где начинается частотная коррекця - максимальное значение.
#define numFinFrCorr_Stand 10 // Конечный номер входных нейронов, после чего усиление постоянно - стандартное значение.

#define FreqIniFrCorr_Stand 1500.0F // Частота (Гц), где начинается частотная коррекция - стандартное значение.
#define FreqFinFrCorr_Stand 2500.0F // Частота (Гц), где кончается частотная коррекция - стандартное значение.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Параметры частотной коррекции спектральных линий.

struct strParFreqCorrPeaks {

USHRT numIni,numFin; // Начало и конец интервала коррекции в номерах гармоник.
float CorrDB; // Величина частотной коррекции в дБ.

strParFreqCorrPeaks(void); // Конструктор.
void Init(void); // Инициализация параметров.
BYTE IsOK(void); // Проверки.
USHRT Check(void); // Проверки и коррекция.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
void SetDlg(HWND hDlg); // Установка в диалоговое окно.
BYTE GetDlg(HWND hDlg); // Получение из диалогового окна.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Параметры частотной коррекции спектра.

struct strParFreqCorrSpectr {

float FrIni,FrFin; // Начало и конец интервала коррекции (Гц).
float CorrDB; // Величина частотной коррекции в дБ.

strParFreqCorrSpectr(void); // Конструктор.
void Init(void); // Инициализация параметров.
BYTE IsOK(void); // Проверки.
USHRT Check(void); // Проверки и коррекция.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
void SetDlg(HWND hDlg); // Установка в диалоговое окно.
BYTE GetDlg(HWND hDlg); // Получение из диалогового окна.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы.

#define ColBkgWinNet COL_GRAY // Цвет фона окна изображения нейронной сети.
#define ColNeur COL_RED // Цвет нейронов без показа амплитуды.
#define ColAxons COL_GREEN // Цвет аксонов без показа амплитуды.
#define ColAxonsSmartNeur COL_BLUE // Цвет аксонов для 'умных' нейронов (со смещениями) без показа амплитуды.
#define ColCircleNeur COL_WHITE // Цвет окружности нейронов.
#define ColTxtNumNeur COL_WHITE // Цвет номеров нейронов.
#define ColRectNeurThr COL_WHITE // Цвет рамки прямоугольника порогов.
#define szImgNeurMax 15 // Максимальный радиус изображения нейрона.
#define szImgNeurThrMax 6 // Максимальная высота изображения порогов.
#define coeSzNeur 0.7F // Относительный размер нейрона.
#define coeSzNeurThr 0.2F // Относительная высота прямоугольника порогов.
#define ColRectInpLay COL_WHITE // Цвет прямоугольника изображения входного слоя.
#define ColInpLay COL_BLUE // Цвет изображения входного слоя без показа амплитуды.
#define ColTxtNumInpLay COL_WHITE // Цвет номеров входного слоя.
#define szImgLetter 10 // Размер изображения буквы.
#define ColRectLetter COL_WHITE // Цвет прямоугольника изображения символа звука.
#define ColImgLetterLt COL_WHITE // Цвет символа звука (светлый).
#define ColImgLetterDk COL_BLACK // Цвет символа звука (тёмный).
#define szImgLettFunAct 10 // Высота текста названий функций активации.
#define ColBkgTextFunAct COL_WHITE // Цвет фона названий функций активации.
#define ColFrameTextFunAct COL_RED // Цвет рамки.
#define ColTextFunAct COL_BLUE // Цвет названий функций активации.
#define LevNoDrawAxons 0.025F // Относительный уровень амплитуды, ниже которого не рисуются аксоны.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы нейронных сетей.

#define nTypesNNW 3 // Число типов нейронных сетей.
#define typNNW_Vowel  0 // Гласные и сонорные звуки.
#define typNNW_Cons   1 // Согласные импульсные и шипящие звуки.
#define typNNW_Spectr 2 // Применение нейронных сетей сразу для всего спектра.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы подстановки данных.

#define nDiffDataNNW 4 // Число типов подстановки данных для нейронных сетей.
#define typDataNNW_Peaks        0 // По пикам.
#define typDataNNW_SpectrTri    1 // По спектру с разложением по треугольным функциям.
#define typDataNNW_SpectrTriEnv 2 // По спектру с разложением огибающей по треугольным функциям.
#define typDataNNW_SpectrRow    3 // Непосредственно спектр.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы используемых нейронных сетей.

#define nTypesRecNNW 3 // Число типов распознавания.
#define typNNR_VC 0 // Две раздельные сети для гласных и согласных.
#define typNNR_Sp 1 // Одну многослойную сеть прямого распространения для всего спектра.
#define typNNR_Co 2 // Сеть Кохонена.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура свойств и параметров нейронной сети.

struct strPropNNW {

BYTE flType; // Тип нейронной сети: (гласные, согласные, сразу всё - спектр).
BYTE flTypInpData; // Тип подачи данных на вход нейронной сети.
BYTE flFrCorr,typFrCorr; // Флаг и тип частотной коррекции.
BYTE flFrCompr,typFrCompr; // Флаг и тип частотного сжатия.
BYTE nPCons; // Число нейронов для спектральных линий согласных звуков.
float dFr; // Дискрет спектрального разложения (Гц).
float dFrTri; // Дискрет спектрального разложения по треугольным функциям (Гц).
float FreqMin; // Минимальная частота учитываемого спектрального интервала (Гц).
float FreqMax; // Максимальная частота учитываемого спектрального интервала (Гц).
struct strParFreqCorrPeaks FreqCorrPeaks; // Параметры частотной коррекции спектральных линий.
struct strParFreqCorrSpectr FreqCorrSpectr; // Параметры частотной коррекции спектра.

strPropNNW(void); // Конструктор.
void Init(void); // Инициализация параметров.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы изображаемых величин для аксонов.

#define nTypesShowAxons 4 // Число типов изображаемых величин для аксонов.

#define flAxons_Axons  0 // Весовые коэффициенты 'Wij'.
#define flAxons_Trans  1 // Передающиеся величины: 'Yi*Wij'.
#define flAxons_Shifts 2 // Смещения 'Sij' для "умных" нейронов.
#define flAxons_Excit  3 // Возбуждения - передающиеся величины минус смещения: '(Yi-Sij)*Wij'.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура всей нейронной сети.

struct strNNW {

BYTE typ; // Тип нейронной сети - для гласных или согласных.
BYTE nLay; // Число слоёв нейронов.
struct strInpLay InpLay; // Входной слой нейронной сети.
struct strLay *Layers; // Массив структур слоёв нейронов.
struct strPropNNW Par; // Структура свойств и параметров нейронной сети.
BYTE flOK; // Флаг наличия правильных весовых коэффициентов и порогов.
BYTE flChange; // Флаг изменения весовых коэффициентов и порогов нейронной сети.
char *PathDir; // Директория, где хранятся файлы базы данных.
char *NameFile; // Имя файла базы данных.

strNNW(void); // Конструктор.
~strNNW(void); // Деструктор.
void Zero(void); // Обнуление идентификаторов и указателей.
void FreeInit(void); // Освобождение памяти и инициализация параметров.
void Free(void); // Удаление объектов из памяти.
BYTE Alloc(BYTE nLay_); // Выделение памяти для массива структур слоёв нейронов.
BYTE IsOK(void); // Проверки.
BYTE IsOK_Lay(void); // Проверки включая слои.
strLay *Get(BYTE num); // Получение указателя на структуру слоя.
strLay *GetOutLay(void); // Получение указателя на структуру выходного слоя.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
BYTE Read_(char *fName); // Чтение из файла.
BYTE Write_(char *fName); // Запись в файл.
BYTE Read(char *Path,char *fName,char *ext); // Чтение из файла.
BYTE Write(char *Path,char *fName,char *ext,BYTE flSetChange); // Сохранение в файл.
BYTE Write(void); // Сохранение в файле.
BYTE Compute(strInpLay *InpLay_); // Установка входного слоя и расчёт.
BYTE ComputeFrom(BYTE layIni); // Расчёт начиная со слоя 'layIni'.
BYTE FreqCorrect(void); // Частотная коррекция входного массива.
void ZeroInit(void); // Обнуление весовых коэффициентов и пороговых уровней всех нейронов.
BYTE RandInit(UINT RandSeq,float CoeWei,float CoeTe); // Нахождение начального приближения весовых коэффициентов и пороговых уровней.
BYTE RandInit_(float CoeWei,float CoeTe); // Нахождение начального приближения весовых коэффициентов и пороговых уровней.
BYTE RandChange(UINT RandSeq,float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA); // Случайное изменение весовых коэффициентов и пороговых уровней.
BYTE RandChange_(float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA); // Случайное изменение весовых коэффициентов и пороговых уровней.
BYTE ComputeErrBackProp(strInpLay *True); // Нахождение ошибки методом обратного распространения ошибки.
BYTE TrainStepSequent(strInpLay *True,float AlphaConst,float AlphaMin,float AlphaMax,BYTE flAdaptSt,BYTE flEqualAdaptSt,float coeAlpha); // Шаг цикла обучения методом обратного распространения ошибки.
BYTE TrainStepSequentRep(strInpLay *True,float AlphaConst,float AlphaMin,float AlphaMax,BYTE flAdaptSt,float coeAlpha); // Шаг цикла обучения методом повторного обратного распространения ошибки.
BYTE TrainStepSequentLayWeights(UINT numSample,strInpLay *InpLay_,BYTE numLay,float AlphaConst,
  float AlphaMin,float AlphaMax,BYTE flAdaptSt,float coeAlpha); // Шаг цикла метода последовательного послойного обучения - корректировка весов и порогов для слоя 'numLay'.
BYTE TrainStepSequentLayEtal(UINT numSample,BYTE numLay,float AlphaConst,float AlphaMin,float AlphaMax,BYTE flAdaptSt,float coeAlpha); // Шаг цикла метода последовательного послойного обучения - корректировка эталонных значений для слоя 'numLay'.
BYTE TrainStepSequentLayCorr(BYTE numLay); // Корректировка эталонных значений и весовых коэффициентов.
BYTE ComputeAdaptStepAll(float AlphaMin,float AlphaMax,float coeAlpha); // Расчёт адаптивного шага для всех слоёв сети.
BYTE ComputeAdaptStepLay(BYTE numLay,float AlphaMin,float AlphaMax,float coeAlpha); // Расчёт адаптивного шага для слоя с номером 'numLay'.
void FreeVect(void); // Удаление массивов векторов из памяти.
BYTE AllocVect(void); // Выделение памяти для массивов векторов.
BYTE IsOK_Vect(void); // Проверки массивов векторов.
BYTE SetZeroVect(void); // Установка нулей в массивы векторов.
BYTE TrainGroupErrSumVect(strInpLay *True,double Wei); // Нахождение ошибки и суммирование векторов при обучении групповым методом.
BYTE TrainGroupAdaptStep(strInpLay *True,double Wei); // Добавление слагаемых к вспомогательным переменным для нахождения адаптивного шага при предъявлении образца данных при групповом обучении.
BYTE ZeroNumDenomAdaptStepGroup(void); // Обнуление вспомогательных переменных для суммирования при нахождении адаптивного шага при предъявлении образца данных при групповом обучении.
BYTE FindAlphaGroup(void); // Нахождение адаптивного шага при групповом обучении.
BYTE CorrectAlpha(float AlphaMin,float AlphaMax); // Корректировка адаптивного шага для каждого слоя.
BYTE MultCoeAlpha(float CoeAlpha); // Умножение адаптивного шага на замедляющий коэффициент.
BYTE SetAlphaConst(double Alpha); // Установка одинакового шага во все слои.
BYTE GetEqualAdaptStep(double *pAlpha); // Нахождение одного адаптивного шага для всех слоёв.
BYTE AddWeightsShiftsGroup(void); // Добавление вектора приращения к коэффициентам и смещениям при групповом обучении.
BYTE GetSetArrSearch(double *Arr,USHRT szArr,BYTE flSet,BYTE flArr); // Получение или установка массива весов и смещений или векторов весов и смещений.
BYTE PaintNNW(HDC hdc,RECT *rc,float AmpNormNeur,float AmpNormAxons,float AmpNormInp,strPal *PalPos,
  strPal *PalPosNeg,BYTE flWork,BYTE flAxons); // Визуализация работы нейронной сети.
BYTE FreeEtal(void); // Удаление из памяти массивов эталонных значений нейронов.
BYTE AllocEtal(UINT nSamples); // Выделение памяти для массивов эталонных значений нейронов.
void ZeroNames(void); // Обнуление указателей на строки директории и имени файла.
void FreeNames(void); // Удаление из памяти строк директории и имени файла.
BYTE SetNames(char *Path,char *fName); // Установка строк директории и имени файла.
BYTE IsOK_Name(void); // Проверка строки имени файла.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров тренировки нейронной сети групповым методом поиска.

struct strParTrainNNWSearch {

BYTE nStRepM; float coeStI,coeSt,coeChSt;

BYTE IsOK(void); // Проверки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура вспомогательных массивов для тренировки сети методом поиска.

struct strArrTrSearch {

USHRT nV; double *Coe,*CoeN,*CoeS,*Vect,*VectN;

strArrTrSearch(void); // Конструктор.
~strArrTrSearch(void); // Деструктор.
void Zero(void); // Обнуление указателей.
void Free(void); // Освобождение памяти.
BYTE Create(USHRT nV_); // Создание массивов.
BYTE IsOK(void); // Проверки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров слоя.

struct strParLay { 

BYTE TypFunAct,flTUse,flSmart; USHRT nNeurons;

strParLay(void); // Конструктор.
void Init(void); // Инициализация.
BYTE IsOK(void); // Проверки.
void Print(void); // Печать в строку.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров нейронной сети.

struct strParNNW {

struct strPropNNW Par; // Структура свойств и параметров нейронной сети.
BYTE nLay; // Число слоёв нейронной сети.
struct strParLay *ParLay; // Структуры слоёв нейронной сети.
BYTE flChange; // Флаг изменения параметров нейронной сети.
char *PathDir; // Директория, где хранятся файлы базы данных.
char *NameFile; // Имя файла базы данных.

strParNNW(void); // Конструктор.
~strParNNW(void); // Деструктор.
void Zero(void); // Обнуление идентификаторов и указателей.
void Free(void); // Удаление объектов из памяти.
BYTE Alloc(BYTE nLay_); // Выделение памяти для массива структур параметров слоёв нейронов.
BYTE ReAlloc(BYTE nLay_); // Перераспределение памяти для массива структур параметров слоёв нейронов.
BYTE IsOK(void); // Проверки.
BYTE IsOK_(void); // Проверки включая структуры параметров слоёв нейронов.
strParLay *Get(BYTE num); // Получение указателя на параметры слоя.
BYTE Init(BYTE typNNW); // Инициализация структуры параметров нейронной сети.
BYTE InsItem(BYTE num); // Вставка слоя.
BYTE DelItem(BYTE num); // Удаление слоя.
BYTE Read_(FILE *file); // Чтение из файла.
BYTE Write_(FILE *file); // Запись в файл.
BYTE Read(char *Path,char *fName,char *ext); // Чтение из файла.
BYTE Write(char *Path,char *fName,char *ext); // Сохранение в файле.
BYTE Write(void); // Сохранение в файле.
void ZeroNames(void); // Обнуление указателей на строки директории и имени файла.
void FreeNames(void); // Удаление из памяти строк директории и имени файла.
BYTE SetNames(char *Path,char *fName); // Установка строк директории и имени файла.
BYTE IsOK_Name(void); // Проверка строки имени файла.
BYTE EdtParFreqCorrPeaks(HWND hDlg); // Настройка параметров частотной коррекции спектральных линий.
BYTE EdtParFreqCorrSpectr(HWND hDlg); // Настройка параметров частотной коррекции спектра.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Нумерация параметров слоя нейронной сети.

#define numParLay_Neurons 0 // Число нейронов.
#define numParLay_FunAct  1 // Функция активации.
#define numParLay_TUse    2 // Использование порогов.
#define numParLay_Shifts  3 // Использование смещений ('умные' нейроны).

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс диалогового окна настройки параметров нейронной сети.

struct clDlgParNNW {

struct strParNNW *pPar; // Указатель на структуру параметров нейронной сети.
struct strParLay *selLay; // Структура выбранного слоя нейронной сети.
HWND hDlg; // Идентификатор диалогового окна.
BYTE numSel; // Номер выбранного слоя.
BYTE flChLay; // Флаг изменения параметров слоя нейронной сети.
BYTE flLastLay; // Флаг того, что выбран последний слой нейронной сети.
BYTE blkChType; // Флаг блокировки изменения типа нейронной сети.

void Zero(void); // Обнуление идентификаторов и указателей.
BYTE IsOK(void); // Проверки.
void SetDlgWinEdt(void); // Установка параметров в окнах редактирования.
BYTE FillLBLayers(void); // Заполнение списка слоёв нейронной сети.
void UnSelLayer(void); // Отмена выбора слоя.
BYTE OnChangeLayer(void); // Изменение выбранного слоя.
void SelectLayer_(BYTE num); // Выбор слоя с отображением параметров в окнах.
BYTE SelectLayer(BYTE num); // Выбор слоя.
void SetWinParLay_(void); // Установка параметров слоя нейронной сети в окнах.
BYTE SetWinParLay(void); // Установка параметров слоя нейронной сети в окнах.
void UnSetWinParLay(void); // Очистка окон параметров слоя нейронной сети.
BYTE AcceptChanges(void); // Принятие изменений параметров слоя.
BYTE SetParLaySel(void); // Установка параметров выбранного слоя.
BYTE AddInsItem(BYTE flAdd); // Вставка слоя.
BYTE DelItem(void); // Удаление слоя.
void SelectTypNNW(int id); // Выбор типа нейронной сети.
BYTE ReadParNNW(void); // Чтение структуры параметров из файла.
BYTE WriteParNNW(void); // Запись структуры параметров в файл.
void ChBtnAccept(void); // Изменение состояния кнопки принятия изменений.
void ChBtnDelAdd(void); // Блокировка и разблокирование кнопок удаления и добавления.
BYTE OnChangeFlags(int id); // Действия при изменении флагов параметров.
void EnableRadioTypNet(void); // Установка состояния кнопок задания типа сети.
void EnableBtnTypInpData(void); // Установка состояния кнопок в зависимости от типа входных данных для сети.
void SelectTypInpData(int id); // Выбор типа входных данных для сети.
BYTE Command(WPARAM wParam); // Обработка команд диалогового окна.

public:

clDlgParNNW(void); // Конструктор.
~clDlgParNNW(void); // Деструктор.
BYTE OnOpenDlg(HWND hDlg_); // Действия при открытии диалогового окна.
BYTE MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag); // Обработка сообщений диалогового окна.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура спектральной линии.

struct strSpectrLine {

float Amp,AmpRel,Freq;

strSpectrLine(void); // Конструктор.
void Zero(void); // Обнуление идентификаторов.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура массива спектральных линий.

struct strSpLines {

BYTE nSpL; struct strSpectrLine *pSpL;

strSpLines(void); // Конструктор.
~strSpLines(void); // Деструктор.
void Zero(void); // Обнуление указателей и параметров.
void Free(void); // Освобождение памяти.
BYTE Create(BYTE nSpL_); // Создание массива.
BYTE IsOK(void); // Проверки.
strSpectrLine *Get(BYTE num); // Получение указателя на структуру спектральной линии.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Тип - указатель на структуру массива спектральных линий.

typedef strSpLines *typPntSpLines;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс двумерного массива спектральных линий.

class clSpLinesArr {

UINT nArr; typPntSpLines *pArr;

public:

clSpLinesArr(void); // Конструктор.
~clSpLinesArr(void); // Деструктор.
void Zero(void); // Обнуление указателей и параметров.
void Free(void); // Освобождение памяти.
void Clear(void); // Удаление структур массивов.
BYTE Create(UINT nArr_); // Создание массива.
BYTE IsOK(void); // Проверки.
strSpLines *Get(UINT num); // Получение указателя на структуру массива спектральных линии.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы для параметров задания входных данных сети.

#define AmpThr_Stand 2.0F // Амплитуда для пороговой фильтрации шума.
#define FreqMin_Stand 80.0F // Минимальная частота рассматриваемого спектра (Гц).
#define FreqMax_Stand 8200.0F // Максимальная частота рассматриваемого спектра (Гц).
#define FreqDiscrTri_Stand 200.0F // Шаг сетки при разложении спектра по треугольным функциям.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы для параметров выделения спектральных линий в спектре гласных звуков.

#define nPeaksMax 50 // Максимальное число спектральных линий при выделении гласных звуков и полное число входов нейронов.
#define nPeaksCons 10 // Число спектральных линий при выделении гласных звуков.
#define ampSmPeaksAbs_Stand 0.1F // Уровень малых пиков по абсолютному значению, которые отбрасываются при нахождении первого пика.
#define ampSmPeaksMS_Stand 0.2F // Уровень малых пиков по среднеквадратичному отклонению, которые отбрасываются при нахождении первого пика.
#define ampSmPeaksMS_Min 0.05F // Уровень малых пиков по среднеквадратичному отклонению, которые отбрасываются при нахождении первого пика (минимальное значение).
#define ampPeaksBad_Stand 0.05F // Уровень по среднеквадратичному отклонению плохих (мало выделяющихся) пиков, которые отбрасываются.
#define FreqMinPeaks_Stand 100.0F // Минимальная частота рассматриваемого спектра (Гц).
#define FreqMinPeaks_Min 80.0F // Минимальная частота рассматриваемого спектра (Гц) (минимальное значение).
#define FreqMinPeaks_Max 200.0F // Минимальная частота рассматриваемого спектра (Гц) (максимальное значение).
#define FreqBaseMax_Stand 400.0F // Максимальная частота основной гармоники (Гц).
#define ErrFreq_Stand 0.35F // Максимальная ошибка при отбраковке пиков по частоте.
#define coeWidPeaks_Stand 0.165F // Полуширина пиков (относительная).
#define CoeRecPeaksSpectr_Stand 0.35F // Коэффициент распознавания пиков при анализе всего спектра.
#define CoeRecPeaksVowel_Stand 0.1F // Коэффициент распознавания пиков при занесении в массив для гласных звуков.
#define CoeRecPeaksCons_Stand 0.35F // Коэффициент распознавания пиков при занесении в массив для согласных звуков.
#define CoeRecPeaks_Min 0.0F // Коэффициент распознавания пиков (минимальное значение).
#define CoeRecPeaks_Max 10.0F // Коэффициент распознавания пиков (максимальное значение).
#define LevPowPeak_Stand 0.3F // Минимальный уровень мощности, который должен содержаться в пиках.
#define ampPeaksCorrFreq_Stand 0.3F // Амплитуда линий, по которым проводится коррекция частоты.
#define coeShPeaks_Stand 0.5F // Коэффициент, дающий максимально возможный сдвиг частоты пиков при расстановке пиков.
#define FreqDiscrCons_Stand 150.0F // Дискрет по частоте для разложения по треугольным функциям для шипящих и глухих согласных звуков.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров нахождения спектральных линий гласных звуков и предварительного распознавания гласных и согласных звуков.

struct strParGetPeaks {

float AmpThr; // Амплитуда для пороговой фильтрации шума.
BYTE flCorrFreq; // Флаг коррекции частоты по максимальной выявленной гармонике.
float ampSmPeaksAbs; // Уровень малых пиков по абсолютному значению, которые отбрасываются при нахождении начального пика при нахождении первого пика.
float ampSmPeaksMS; // Уровень малых пиков по среднеквадратичному отклонению, которые отбрасываются при нахождении начального пика при нахождении первого пика.
float ampPeaksBad; // Уровень по среднеквадратичному отклонению плохих (мало выделяющихся) пиков, которые отбрасываются.
float FreqMin; // Минимальная частота рассматриваемого интервала спектра (Гц).
float FreqMax; // Максимальная частота, до которой проводится анализ (Гц).
float FreqBaseMax; // Максимальная частота основной гармоники (Гц).
float ErrFreq; // Максимальная ошибка при отбраковке пиков по частоте.
float coeWidPeaks; // Полуширина пиков относительно основной частоты.
float coeRecPeaksSpectr; // Коэффициент распознавания пиков при анализе всего спектра.
float coeRecPeaksVowel; // Коэффициент распознавания пиков при занесении в массив для гласных звуков.
float coeRecPeaksCons; // Коэффициент распознавания пиков при занесении в массив для согласных звуков.
float LevPowPeak; // Минимальный уровень мощности, который должен содержаться в пиках.
float ampPeaksCorrFreq; // Амплитуда линий, по которым проводится коррекция частоты.
float coeShPeaks; // Коэффициент, дающий максимально возможный сдвиг частоты пиков при расстановке пиков.
float FreqDiscrCons; // Дискрет по частоте для разложения по треугольным функциям для шипящих и глухих согласных звуков.

strParGetPeaks(void); // Конструктор.
void Init(void); // Инициализация.
BYTE IsOK(void); // Проверки.
UINT Check(void); // Проверки и коррекция.
BYTE Read_(FILE *file); // Чтение из файла.
BYTE Read(char *Path,char *fName); // Чтение из файла.
BYTE Write_(FILE *file); // Запись в файл.
BYTE Write(char *Path,char *fName); // Запись в файл.
BYTE SetDlg(HWND hDlg); // Установка в диалоговое окно.
BYTE GetDlg(HWND hDlg); // Получение из диалогового окна.
void OnCreateDlg(HWND hDlg); // Действия при открытии диалогового окна.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров нахождения спектральных линий гласных звуков и предварительного распознавания гласных и согласных звуков.

struct strParInpSpectr {

float AmpThr; // Амплитуда для пороговой фильтрации шума.
float FreqMin; // Минимальная частота (Гц).
float FreqMax; // Максимальная частота, до которой проводится анализ (Гц).
float FreqDiscrTri; // Дискрет по частоте для разложения по треугольным функциям.

strParInpSpectr(void); // Конструктор.
void Init(void); // Инициализация.
BYTE IsOK(void); // Проверки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Методы тренировки нейронной сети.

#define nMethTrain 5 // Число методов тренировки нейронной сети.

#define methTrain_Sequent     0 // Последовательный метод тренировки.
#define methTrain_SequentRep  1 // Последовательный метод многократного распространения ошибки.
#define methTrain_SequentLay  2 // Последовательный послойный метод тренировки.
#define methTrain_Group       3 // Групповой метод, в том числе с адаптивным шагом.
#define methTrain_GroupSearch 4 // Групповой метод поиска.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы для параметров тренировки сети.

#define nStRand_Stand 300 // Число шагов случайного подбора коэффициентов - стандартное значение.
#define nStTrain_Stand 100 // Число шагов тренировки в цикле - стандартное значение.
#define RandSeq_Stand 2011 // Число, задающее случайную последовательность - стандартное значение.
#define AlphaTrain_Stand 0.01F // Шаг тренировки сети - стандартное значение.
#define AlphaMinTrain_Stand 1.e-4F // Ограничение адаптивного шага снизу - начальное значение.
#define AlphaMaxTrain_Stand 0.4F // Ограничение адаптивного шага сверху - начальное значение.
#define coeWei_Stand 0.5F // Коэффициент для весов при случайном подборе коэффициентов - стандартное значение.
#define coeTe_Stand 0.5F // Коэффициент для смещений при случайном подборе коэффициентов - стандартное значение.
#define coeVect_Stand 1.0F // Коэффициент изменения весов и порогов при случайном подборе - стандартное значение.
#define nCycleRandSamples 3 // Число циклов случайной перетасовки порядка предъявления образцов.
#define flCorrAdaptStep 1 // Тип корректировки адаптивного шага (0 - простой, 1 - со сглаживанием).
#define CoeAdaptStep_Stand 0.8F // Замедляющий коэффициент для адаптивного шага.
#define CoeAdaptStep_Min 0.1F // Замедляющий коэффициент для адаптивного шага - минимальное значение.
#define nStSeqLay_Stand 20 // Число шагов в цикле тренировки последовательным послойным методом - стандартное значение.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров тренировки сети.

struct strParTrainNNW {

BYTE methTrain; // Метод тренировки нейронной сети.
BYTE flAdaptSt; // Флаг использоания адаптивного шага при тренировке.
USHRT nStRand; // Число шагов случайного подбора коэффициентов.
USHRT nStTrain; // Число шагов тренировки в цикле.
USHRT nStSeqLay; // Число шагов в цикле тренировки последовательным послойным методом.
UINT RandSeq; // Число, задающее случайную последовательность.
BYTE flRandSampl; // Флаг случайного выбора образцов при тренировке.
float Alpha; // Постоянный шаг тренировки сети.
float AlphaMin; // Ограничение адаптивного шага сверху.
float AlphaMax; // Ограничение адаптивного шага снизу.
BYTE flEqualAdaptSt; // Флаг одинакового адаптивного шага для всех слоёв.
float CoeAdaptStep; // Замедляющий коэффициент для адаптивного шага. 
float coeWei; // Коэффициент для весов при случайном подборе коэффициентов.
float coeTe; // Коэффициент для смещений при случайном подборе коэффициентов.
float coeVect; // Коэффициент изменения весов и порогов при случайном подборе.

strParTrainNNW(void); // Конструктор.
void Init(void); // Инициализация.
BYTE IsOK(void); // Проверки.
USHRT Check(void); // Проверки и коррекция.
BYTE Read_(FILE *file); // Чтение из файла.
BYTE Read(char *Path,char *fName); // Чтение из файла.
BYTE Write_(FILE *file); // Запись в файл.
BYTE Write(char *Path,char *fName); // Запись в файл.
void SetDlg(HWND hDlg); // Установка в диалоговое окно.
BYTE GetDlg(HWND hDlg); // Получение из диалогового окна.
void OnCreateDlg(HWND hDlg); // Действия при открытии диалогового окна.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Определение типов функций для алгоритма распознавания.

typedef BYTE (*pFunDecSnd)(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // Функция принятия решения при распознавании звука.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров увеличения амплитуд высоких гармоник при синтезе звука.

struct strParIncHighSynth { BYTE nc; float coeCorr,CorrMax;};
