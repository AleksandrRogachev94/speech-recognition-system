/*...........................................................................................................

clFileT,clString,clListString,clHelpEx

...........................................................................................................*/

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
