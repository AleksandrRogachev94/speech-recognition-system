/*...........................................................................................................

clString,clArrBYTE,clArrFloat,clArrDouble,clArr2Float,
clBmpPict,clImgMem,clFileT,clOFN,strSndArr,strPal,clListString,clHelpEx

...........................................................................................................*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс строки.

class clString {

void Zero(void); // Обнуление указателя и инициализация параметров.

public:

UINT sz; char *String;

clString(void);
~clString(void);
void Free(void); // Освобождение памяти.
BYTE Alloc(UINT sz_); // Выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE SetZero(void); // Обнуление строки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс массива 'BYTE'.

class clArrBYTE {

void Zero(void); // Обнуление указателя и инициализация параметров.

public:

UINT ln; BYTE *Arr;

clArrBYTE(void);
~clArrBYTE(void);
void Free(void); // Освобождение памяти.
BYTE Alloc(UINT ln_); // Выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE SetZero(void); // Обнуление массива.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс массива 'float'.

class clArrFloat {

void Zero(void); // Обнуление указателя и инициализация параметров.

public:

UINT ln; float *Arr;

clArrFloat(void);
~clArrFloat(void);
void Free(void); // Освобождение памяти.
BYTE Alloc(UINT ln_); // Выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE SetZero(void); // Обнуление массива.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Тип - указатель на класс массива 'float'.

typedef clArrFloat *typPntArrFloat;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс массива 'double'.

class clArrDouble {

void Zero(void); // Обнуление указателя и инициализация параметров.
void Free(void); // Освобождение памяти.

public:

UINT ln; double *Arr;

clArrDouble(void);
~clArrDouble(void);
BYTE Alloc(UINT ln_); // Выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE SetZero(void); // Обнуление массива.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс двумерного массива чисел 'float'.

class clArr2Float {

typPntArrFloat *Arr;

void Zero(void); // Обнуление указателя и инициализация параметров.
void Clear(void); // Удаление классов массивов 'float'.

public:

UINT nArr,ln;

clArr2Float(void);
~clArr2Float(void);
void Free(void); // Освобождение памяти.
BYTE Alloc(UINT nArr_,UINT ln_); // Выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE IsOK_(void); // Проверки включая массивы 'float'.
clArrFloat *Get(UINT num); // Получение указателя на класс массива.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс для вывода изображения типа DIB и считывания изображения с экрана.

class clBmpPict {

HDC hdc; HBITMAP hBitmap,hBitmapOld; HFONT hFont;

void Zero(void); // Обнуление указателей и инициализация параметров.
void ZeroDC(void); // Обнуление указателей на старый битовый образ и DC.
void ZeroBmp(void); // Обнуление указателей и инициализация параметров для битового изображения.
void FreeBmp(void); // Освобождение памяти от битового изображения.
BYTE SetPix(int cx,int cy,BYTE *CC); // Рисование пиксела.

public:

BYTE typBmp,*pvBits; SHRT nCol; int dx,dy; UINT dxB;

clBmpPict(void);
~clBmpPict(void);
BYTE IsOK(void); // Проверки битового изображения и параметров.
BYTE IsOKB(void); // Проверки битового изображения и параметров.
BYTE Clear(void); // Заполнение битового изображения нулевым цветом.
BYTE Clear(COLORREF Col); // Заполнение битового изображения заданным цветом.
HDC GetDC(HDC hdc_); // Создание DC и выбор битового изображения в этом DC.
void FreeDC(void); // Выбор старого битового изображения и уничтожение DC.
void Free(void); // Освобождение памяти.
BYTE Init(int dx_,int dy_,BYTE typBmp_,DWORD *NCol,SHRT nCol_,HFONT hFont_); // Задание параметров.
BYTE Image(HDC hdcD,int xiD,int yiD,int dxD,int dyD,int xiS,int yiS,int dxS,int dyS,BYTE stretch); // Вывод изображения.
BYTE GetImg(HDC hdc_,int xi_,int yi_,int dx_,int dy_); // Получение изображения.
BYTE Save(HANDLE File,DWORD *NCol,SHRT nCol); // Сохранение изображения в файле '*.bmp'.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Изображение в памяти.

class clImgMem {

HBITMAP hBitmap,hBitmapOld;

void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Освобождение памяти.
void FreeDC(void); // Удаление 'hdc' из памяти.
void ZeroBmp(void); // Обнуление указателей и инициализация параметров.
void FreeBmp(void); // Удаление битового изображения 'hBitmap' из 'hdc' и из памяти.
BYTE CreateBmp(int dx_,int dy_); // Создание битового изображения 'hBitmap'.
BYTE SelectBmp(void); // Выбор битового образа 'hBitmap' в 'hdc'.
void UnSelectBmp(void); // Удаление битового образа 'hBitmap' из 'hdc'.
BYTE IsOK(void); // Проверка параметров.

public:

HDC hdc; int dx,dy; UINT dxB;

clImgMem(void);
~clImgMem(void);
BYTE Create(HDC hdc_,int dx_,int dy_,HFONT hFont,BYTE mess); // Создание 'hdc' и выбор битового изображения 'hBitmap' в 'hdc'.
BYTE SetPar(HFONT hFont); // Установка параметров в 'hdc' и закрашивание цветом по умолчанию.
BYTE IsOKImg(void); // Проверка параметров и того, что битовое изображение выбрано в 'hdc'.
BYTE SetBitsTrCol(int dx_,int dy_,BYTE *Bits); // Установка бит в формате 'True color'.
BYTE SetBitsGrayCol(int dx_,int dy_,BYTE *Bits); // Установка бит в формате чёрно-серо-белого изображения с 1 байтом на пиксел.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Открытие и закрытие файлов.

class clFileT {

int File;

public:

FILE *file;

clFileT(void);
~clFileT(void);
void Close(void); // Закрытие файла.
BYTE Open(char *name,BYTE wr); // Открытие файла.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс для работы с файлами.

class clOFN {

void Zero(void); // Обнуление структуры.
void Free(void); // Освобождение памяти от строк.

public:

OPENFILENAME ofn; 

clOFN(void);
~clOFN(void);
BYTE Init(USHRT szFile,USHRT szFileTitle); // Выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE Open(BYTE flSave,char *Filter,char *ExtIni,char *ExtDef,char *PathToDir,char *FileNameIni,
  HWND hwndOwner,UINT IDS_Header,BYTE flExtDiff,BYTE flCase); // Получение имени файла для открытия или сохранения.
BYTE GetFilePath(char *FileName,USHRT szFileName,char *PathToDir,USHRT szPathToDir,char *Exten,
  USHRT szExten,BYTE cutExt,USHRT *nFiltInd); // Получение имени файла и пути к файлу.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура массива звукового сигнала.

struct strSndArr {

UINT ln; float *Snd; double dt;

strSndArr(void);
~strSndArr(void);
void Zero(void); // Обнуление указателей.
void Free(void); // Освобождение памяти.
BYTE Create(UINT ln_); // Создание.
BYTE IsOK(void); // Проверки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура палитры.

struct strPal {

BYTE MasRGB[nColSmoothPal][3];

strPal(void); // Конструктор.
void Zero(void); // Обнуление массива.
BYTE FillColor(DWORD *ColBase); // Нахождение цветов сглаженной палитры.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Набор строк.

class clListString {

void Zero(void); // Обнуление указателя и инициализация параметров.
void Clear(void); // Удаление строк.

char **List;

public:

USHRT nList;

clListString(void);
~clListString(void);
void Free(void); // Освобождение памяти.
BYTE Alloc(USHRT nList_); // Выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE Set(USHRT num,char *txt); // Установка строки в массив.
char *Get(USHRT num); // Получение строки.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Вывод справки "*.htm" через 'Explorer'.

class clHelpEx {

char *Name,*CurrDir; clListString *LS;

void Zero(void); // Обнуление указателей и инициализация параметров.
void Free(void); // Закрытие справки.
void ZeroLS(void); // Обнуление указателя на класс списка строк.
void FreeLS(void); // Удаление класса списка строк.
BYTE CreateLS(void); // Создание списка строк.
BYTE ReadLS(void); // Чтение списка строк.
BYTE Show(char *Topic); // Показ справки.

public:

clHelpEx(void);
~clHelpEx(void);
BYTE Set(char *Path,char *Dir,char *DirFile,char *Name_); // Установка параметров и проверка наличия файла.
void ShowContent(void); // Показ содержания файла справки.
BYTE ShowTopic(DWORD Topic); // Показ справки по заданной теме.
};
