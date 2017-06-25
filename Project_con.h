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
#define strL_FileName 128 // Длина строки имени файла.
#define strL_Path 512 // Длина строки пути файла.
#define szExt 6 // Длина строки расширения файла.

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
#define SAFE_FREE(Obj) { if(Obj!=NULL) { free((void *)Obj); Obj=NULL;}} // Безопасное освобождение памяти.
#define SET_ZERO(Obj) { if(Obj!=NULL) ZeroMemory((PVOID)Obj,sizeof(*Obj));} // Обнуление памяти.
#define SAFE_CLOSE_FILE(Handle) { if(Handle!=INVALID_HANDLE_VALUE) { CloseHandle(Handle); Handle=INVALID_HANDLE_VALUE;}} // Закрытие файла.
#define COPY(Dst,Src) { if(Dst!=NULL&&Src!=NULL) memcpy((void *)Dst,(void *)Src,sizeof(*Src));} // Копирование объектов.
#define SAFE_FREE_LIB(hLib) { if(hLib!=NULL) { FreeLibrary(hLib); hLib=NULL;}} // Безопасное закрытие библиотеки.
#define MIN(x,y) (x<y?x:y) // Нахождение минимума.
#define MAX(x,y) (x>y?x:y) // Нахождение максимума.
#define ABS(x) (x>=0.?x:-x) // Нахождение модуля.
#define CHECK_LIM(x,xMin,xMax) (x<xMin?xMin:(x>xMax?xMax:x)) // Проверка и коррекция по допустимым минимуму и максимуму.
#define SQRT(v) (v<SmCnst32_d?0.:sqrt(v)) // Нахождение квадратного корня.
#define POW2D(x) ((double)(x)*(double)(x)) // Квадрат.
#define LOG2(x) (float)(log((double)(x))/log(2.)) // Логарифм по основанию 2.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы.

#define M_PI 3.1415926535897932384626433832795 // Число "Пи".

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Коды сообщений.

#define messRet   255 // Возврат.
#define messNoMem 254 // Недостаточно памяти.
#define messLrgAr 253 // Большой размер массива.
#define messStop  252 // Остановка.

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

#define COL_DK_RED   RGB(128,0,0)
#define COL_DK_GREEN RGB(0,128,0)
#define COL_DK_BLUE  RGB(0,0,128)

#define COL_VDK_RED   RGB(64,0,0)
#define COL_VDK_GREEN RGB(0,64,0)
#define COL_VDK_BLUE  RGB(0,0,64)

#define COL_YELLOW   RGB(255,255,0)
#define COL_SKY_BLUE RGB(0,255,255)
#define COL_VIOLET   RGB(255,0,255)
#define COL_BRICK    RGB(255,128,0)

#define COL_DK_YELLOW   RGB(128,128,0)
#define COL_DK_SKY_BLUE RGB(0,128,128)
#define COL_DK_VIOLET   RGB(128,0,128)
#define COL_DK_BRICK    RGB(128,64,0)

#define COL_VDK_YELLOW   RGB(64,64,0)
#define COL_VDK_SKY_BLUE RGB(0,64,64)
#define COL_VDK_VIOLET   RGB(64,0,64)

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
// Типы изображений DIB.

#define typBmp_24 0 // True Color.
#define typBmp_16 1 // 16 bits.
#define typBmp_8  2 // 8 bits (256 colors).
#define typBmp_4  3 // 4 bits (16 colors).
#define typBmp_1  4 // 1 bits (monochrome image).
#define typBmp_32 5 // 32 bits.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы построения битового изображения.

#define typDrawBMP_Stretch 0 // Масштабирование изображения проводится точно по размерам прямоугольника.
#define typDrawBMP_Size    1 // Масштабирование изображения проводится так, чтобы сохранялись пропорции, а изображение помещалось в прямоугольник.
#define typDrawBMP_Exact   2 // Размеры изображения остаются неизменными.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Расположение точки привязки относительно прямоугольника (по горизонтали и вертикали).

#define posH_Left 0
#define posH_Center 1
#define posH_Right 2

#define posV_Top 0
#define posV_Center 1
#define posV_Bottom 2

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Различные константы.

#define szMemMax 0xFFFFFFFF // Максимальный размер массива.

#define CH_FILT '|' // Символ-разделитель в строке фильтра.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Флаги соответствия строки расширения файла списку расширений в фильтре.

#define flFiltStr_Error    0 // Ошибка в строке или фильтре.
#define flFiltStr_Exact    1 // Точное соотвествие расширения индексу.
#define flFiltStr_List     2 // Соответствие списку, но не данному индексу.
#define flFiltStr_NotFound 3 // Не нейдено в списке.
#define flFiltStr_Any      4 // Случай, когда можно выбирать все файлы.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Постоянные для палитры цветов.

#define nColB 9 // Число основных цветов.
#define nPalStep 10 // Число цветов между основными цветами.
#define nColSmoothPal ((nColB-1)*nPalStep+1) // Число цветов сглаженной палитры.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Различные константы.

#define VelScrlPos 5 // Коэффициент обычного пролистывания.
#define AccScrlPos 100 // Коэффициент ускоренного пролистывания.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Различные пределы.

#define IPE_MAX log(DBL_MAX) // Максимальный показатель, больше которого не ищем экспоненту.
#define MaxSizeEdt SHRT_MAX // Максимальный размер текста редактора с информацией (байт).
#define nRecCharMax 1024 // Число выводимых символов при распознавании в реальном времени.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Константы программы.

#define AmpNormSpectr_Stand 300.0F // Амплитуда нормировки спектра по умолчанию.
#define AmpNormSig_Stand 10000.0F // Амплитуда нормировки сигнала по умолчанию.

#define szWinResDiag 18 // Размер окна полосы отображения результатов на диаграмме спектра.

#define AmpNormNeur_Stand 1.0F // Амплитуда нормировки изображения нейронов.
#define AmpNormInp_Stand 0.7F // Амплитуда нормировки изображения входов нейронов.
#define AmpNormSynops_Stand 100.0F // Амплитуда нормировки изображения синапсов.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Параметры синтезатора речи.

#define FreqSynthesis_Stand 150.0F // Частота синтезатора речи по умолчанию.
#define FreqSynthesis_Min 50.0F // Частота синтезатора речи минимальная.
#define FreqSynthesis_Max 400.0F // Частота синтезатора речи максимальная.
#define AmpSynthesis_Stand 500.0F // Амплитуда синтезатора речи по умолчанию.
#define AmpSynthesis_Min 50.0F // Амплитуда синтезатора речи минимальная.
#define AmpSynthesis_Max 3000.0F // Амплитуда синтезатора речи максимальная.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Цвета.

// Окно диаграммы спектра.
#define ColBkgDiag COL_WHITE // Цвет фона в окне диаграммы.
#define ColCursorDiag COL_BLACK // Цвет курсора в окне диаграммы.
#define ColDiagLineSep COL_WHITE // Цвет линии-разделителя в окне диаграммы.
#define ColDiagLineSymbBkg COL_BLACK // Цвет фона в линии вывода символов в окне диаграммы.
#define ColDiagLineSndNoShow COL_WHITE // Цвет для типа звука, который не должен изображаться в линии вывода символов диаграммы.
#define ColCursorDiagLimDB_Ini COL_GREEN // Цвет курсора начальной линии интервала звука в базе данных.
#define ColCursorDiagLimDB_Fin COL_RED // Цвет курсора конечной линии интервала звука в базе данных.

// Окно графика сигнала.
#define ColBkgWinGraphSign COL_WHITE // Цвет фона в окне графика сигнала.
#define ColGraphSign COL_BLACK // Цвет графика сигнала.
#define ColCursorGraphSign COL_BLUE // Цвет курсора в окне графика сигнала.

// Окно графика спектра.
#define ColBkgWinGraphSpectr COL_WHITE // Цвет фона в окне графика спектра.
#define ColGraphSpectr COL_BLACK // Цвет графика спектра.
#define ColPeaksGrSpectr COL_DK_RED // Цвет пиков в окне графика спектра.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Звуки.

#define nVoicesVowel 15 // Число гласных и сонорных звуков.
#define nVoicesCons 16 // Число взрывных и шипящих согласных звуков.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы для параметров анализа потока звуков.

#define errSoundResNNW 0.3F // Допустимая ошибка при распознавании звука в простом методе принятия решения.
#define LevSoundDecStore 0.6F // Уровень принятия решения при распознавании звука в методе с учётом накопленного результата.

#define tStVowel 1.0F // Время накопления (c) для гласных звуков.
#define tStSonor 0.3F // Время накопления (c) для сонорных звуков.
#define tStPulse 0.1F // Время накопления (c) для импульсных согласных звуков.
#define tStTurb  0.3F // Время накопления (c) для турбулентных согласных звуков.
#define tStHiss  0.3F // Время накопления (c) для шипящих согласных звуков.
#define tStHTone 0.3F // Время накопления (c) для шипяще-тоновых согласных звуков.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Способы анализа потока звуков.

#define methDecSnd_Inst  0 // Простейший способ, основанный на мгновенном значении.
#define methDecSnd_Store 1 // Метод с накоплением результата.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Задание параметров нейронных сетей.

#define nNeurons_Stand 10 // Число нейронов в скрытом слое по умолчанию.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Размеры окон.

#define coeSzWinDiag 0.7F // Относительная ширина окна диаграммы спектра.
#define coeSzWinSig 0.3F // Относительная высота окна сигнала.

// Окно просмотра нейронной сети.
#define dxViewNNW_Min 200
#define dyViewNNW_Min 200
#define dxViewNNW_Stand 800
#define dyViewNNW_Stand 600

// Окно текста.
#define dxWinText_Min 600
#define dyWinText_Min 600
#define dxWinText_Stand 900
#define dyWinText_Stand 600

// Константы окон.
#define HeiFontText 20 // Размер шрифта в окне текста.
