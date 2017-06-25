//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы функций и других объектов.

typedef unsigned char BYTE;
typedef signed char SCHAR;
typedef short int SHRT;
typedef unsigned short int USHRT;
typedef unsigned long U_LONG;

typedef unsigned long PNT_DATA; // Тип для передачи указателей.
typedef char *typPntChar; // Тип - указатель на строку.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы.

#define strL_Txt 256 // Длина вспомогательной строки.
#define strL_Path 512 // Длина строки пути файла.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы, задающие различные малые или большие параметры.

#define SmCnst4 1.e-4F
#define SmCnst10_d 1.e-10
#define SmCnst24_d 1.e-24
#define SmCnst32_d 1.e-32

#define LrgCnst32_d 1.e+32

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Макросы.

#define SAFE_DELETE(Obj) { if(Obj!=NULL) { delete Obj; Obj=NULL;}} // Безопасное удаление.
#define SAFE_DELETE_ARR(Arr) { if(Arr!=NULL) { delete[] Arr; Arr=NULL;}} // Безопасное удаление массива.
#define SAFE_DELETE_OBJECT(Obj) { if(Obj!=NULL) { DeleteObject(Obj); Obj=NULL;}} // Безопасное удаление объекта.
#define SET_ZERO(Obj) { if(Obj!=NULL) ZeroMemory((PVOID)Obj,sizeof(*Obj));} // Обнуление памяти.
#define COPY(Dst,Src) { if(Dst!=NULL&&Src!=NULL) memcpy((void *)Dst,(void *)Src,sizeof(*Src));} // Копирование объектов.
#define SAFE_FREE_LIB(hLib) { if(hLib!=NULL) { FreeLibrary(hLib); hLib=NULL;}} // Безопасное закрытие библиотеки.
#define SAFE_CLOSE_FILE(Handle) { if(Handle!=INVALID_HANDLE_VALUE) { CloseHandle(Handle); Handle=INVALID_HANDLE_VALUE;}} // Закрытие файла.
#define SQRT(v) (v<SmCnst32_d?0.:sqrt(v)) // Нахождение квадратного корня.
#define POW2D(x) ((double)(x)*(double)(x)) // Квадрат.
#define LOG2(x) (float)(log((double)(x))/log(2.)) // Логарифм по основанию 2.
#define MIN(x,y) (x<y?x:y) // Нахождение минимума.
#define MAX(x,y) (x>y?x:y) // Нахождение максимума.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы.

#define M_PI 3.1415926535897932384626433832795 // Число "Пи".

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Коды сообщений.

#define messRet   255 // Возврат.
#define messNoMem 254 // Недостаточно памяти.
#define messLrgAr 253 // Большой размер массива.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы сообщений в окне 'MessageBox'.

#define MB_ST (MB_OK|MB_ICONSTOP|MB_APPLMODAL|MB_TOPMOST)        // Стоп.
#define MB_IN (MB_OK|MB_ICONINFORMATION|MB_APPLMODAL|MB_TOPMOST) // Информация.
#define MB_EX (MB_OK|MB_ICONEXCLAMATION|MB_APPLMODAL|MB_TOPMOST) // Восклицание.
#define MB_QU (MB_YESNO|MB_ICONQUESTION|MB_APPLMODAL|MB_TOPMOST) // Вопрос (да/нет).
#define MB_QU_YNC (MB_YESNOCANCEL|MB_ICONQUESTION|MB_APPLMODAL|MB_TOPMOST) // Вопрос (да/нет/отмена).

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Состояния пунктов меню.

#define MF_GR (MF_BYCOMMAND|MF_GRAYED)
#define MF_EN (MF_BYCOMMAND|MF_ENABLED)
#define MF_CH (MF_BYCOMMAND|MF_CHECKED)
#define MF_UNCH (MF_BYCOMMAND|MF_UNCHECKED)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Стандартные цвета.

#define COL_BLACK    RGB(0,0,0)
#define COL_WHITE    RGB(255,255,255)
#define COL_GRAY     RGB(128,128,128)
#define COL_DK_GRAY  RGB(64,64,64)
#define COL_LT_GRAY  RGB(192,192,192)

#define COL_RED      RGB(255,0,0)
#define COL_GREEN    RGB(0,255,0)
#define COL_BLUE     RGB(0,0,255)

#define COL_YELLOW   RGB(255,255,0)
#define COL_SKY_BLUE RGB(0,255,255)
#define COL_VIOLET   RGB(255,0,255)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Звуки.

#define nVoicesVowel 15 // Число гласных и сонорных звуков.
#define nVoicesCons 16 // Число взрывных и шипящих согласных звуков.
#define nVoices (nVoicesVowel+nVoicesCons) // Полное число звуков.

// Типы звуков.
#define nTypesSnd 7 // Число типов звуков.
#define typSnd_Vowel     0 // Гласный звук.
#define typSnd_Sonor     1 // Сонорный звук.
#define typSnd_ConsPulse 2 // Импульсный согласный звук.
#define typSnd_ConsTurb  3 // Турбулентный согласный звук.
#define typSnd_ConsHiss  4 // Шипящий согласный звук.
#define typSnd_ConsTone  5 // Шипяще-тоновой согласный звук.
#define typSnd_Silence   6 // Молчание.

// Нумерация гласных и сонорных звуков.
#define numSymbA  0
#define numSymbE  1
#define numSymbO  2
#define numSymbU  3
#define numSymbYI 4
#define numSymbYA 5
#define numSymbYE 6
#define numSymbYO 7
#define numSymbYU 8
#define numSymbI  9
#define numSymbL  10
#define numSymbM  11
#define numSymbN  12
#define numSymbR  13
#define numSymbV  14

// Нумерация согласных импульсных и шипящих звуков.
#define numSymbB  (0+nVoicesVowel)
#define numSymbP  (1+nVoicesVowel)
#define numSymbG  (2+nVoicesVowel)
#define numSymbK  (3+nVoicesVowel)
#define numSymbD  (4+nVoicesVowel)
#define numSymbT  (5+nVoicesVowel)
#define numSymbCH (6+nVoicesVowel)
#define numSymbC  (7+nVoicesVowel)
#define numSymbJ  (8+nVoicesVowel)
#define numSymbZ  (9+nVoicesVowel)
#define numSymbII (10+nVoicesVowel)
#define numSymbS  (11+nVoicesVowel)
#define numSymbF  (12+nVoicesVowel)
#define numSymbH  (13+nVoicesVowel)
#define numSymbSH (14+nVoicesVowel)
#define numSymbSCH (15+nVoicesVowel)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Различные пределы.

#define szMemMax 0xFFFFFFFF // Максимальный размер массива.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы программы.

#define nRecCharMax 512 // Число выводимых символов при распознавании в реальном времени.
#define nSzRecTextMax 100 // Число символов распознанного текста.
#define MaxSizeEdt SHRT_MAX // Максимальный размер текста редактора с информацией (байт).
#define AmpNormSound 5.0F // Амплитуда нормировки амплитуды звука при индикации.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Размеры окон.

// Окно текста.
#define dxWinText_Min 300
#define dyWinText_Min 300
#define dxWinText_Stand 450
#define dyWinText_Stand 300

// Константы окон.
#define HeiFontText 20 // Размер шрифта в окне текста.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Команды.

#define nCommands 9 // Число команд.

#define commShutDownQ   0 // Выключение компьютера - вопрос.
#define commShutDown    1 // Выключение компьютера - подтверждение.
#define commCloseWin    2 // Закрытие окна программы.
#define commStopRec     3 // Остановка работы.
#define commShowHelp    4 // Показать справку по программе.
#define commOpenNotepad 5 // Открыть блокнот.
#define commOpenPaint   6 // Открыть редактор изображений.
#define commOpenWord    7 // Открыть 'WinWord'.
#define commOpenIE      8 // Открыть 'Internet Explorer'.
