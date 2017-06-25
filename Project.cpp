/*...........................................................................................................

WinMain,InitCommonControls_,
RegisterClassAll,RegisterClassMain,RegisterClassSpectrDiag,RegisterClassGraphSig,RegisterClassGraphSpectr,
RegisterClassViewNNW,RegisterClassText,

ZeroMain,FreeMain,InitMain,
SetPathFilesSound,SetPathFilesDBS,SetPathParNNW,SetPathNNW,
GetPath,

// Класс главного окна.
class clMain {
clMain,~clMain,Zero,Free,
ZeroBrushes,FreeBrushes,CreateBrushes,
ZeroHelp,FreeHelp,CreateHelp,ChMenuHelp,
ZeroBmpDiag,FreeBmpDiag,CreateBmpDiag,
OnBegin,CreateDlgCntrl,
CreateWinDiag,OnChSizeWinDiag,SetScrollDiagH,SetScrollDiagV,HScrollDiag,VScrollDiag,OnMouseMoveDiag,
CreateWinGraph,OnMouseMoveGraphSig,OnChSizeWinGraphSig,SetScrollGrSig,HScrollGrSig,
CreateWinGraphSpectr,OnMouseMoveGraphSpectr,OnChSizeWinGraphSpectr,SetScrollGrSpectr,HScrollGrSpectr,
FreeDiagRes,ComputeDiag,DrawDiag,OnPaintDiag,DrawCursorsDiag,OnPaintDiagDef,UpdateWinDiag,
ComputeDrawDiag,SetBtnMenuProc,ComputeSpLines,RecognNNW_All,OnDrawDiag,
OnPaintGraphSig,DrawCursorGraphSig,OnPaintGraphSigDef,
OnPaintGraphSpectr,OnPaintGraphSpectrDef,DrawPeaksGraphSpectr,
RecognNNW,ProcRecRealTime,GetNumSndRecogn,FindCoordChildWin,MoveChWin,OnChSizeWin,
CloseFileSound,OpenFileSound,SaveFileSound,
ZeroSndCap,FreeSndCap,CreateSndCap,SaveBufSound,StartCaptureSound,StopCaptureSound,StopCaptureSound_,
SetTxtBtnCaptSound,SetTxtBtnRecSound,
ZeroSndCapData,FreeSndCapData,CreateSndCapData,
SaveSndCapData,DlgAdjSound,IsCaptSound,
AdjParSpectr,AdjParPeaks,CloseDataBase,OpenDataBase,
OpenDlgDBS_NNW,OnCloseDlgDBS_NNW,ChBtnMenuOpenDlgDBS_NNW,ChBtnCaptSound,
SetPntWinViewNNW,GetSizeWinViewNNW,OpenWinViewNNW,ChBtnMenuWinViewNNW,
SetPntWinText,GetSizeWinText,OpenWinText,ChBtnMenuWinText,ClearWinText,SetWinText,
StartPlaySound,OnStopSound,SetTxtBtnPlaySound,DrawCurSound,OnChCurTime,OnChCurTimeGraphSig,OnSetCurTimeDiag,
OnSetCurTimeGraphSig,SetTimeDBF,SetTimeDiag,ChMenuProcOutput,
MsgCommand,Command,MsgCommandCntrl,CommandCntrl,MsgCommandDiag,MsgCommandGraphSig,MsgCommandGraphSpectr,
SetFocusWin,DrawNet,CheckCurPos,LoadFile,SaveFile,LoadProcFile,
LoadNNW,SaveNNW,SaveAsNNW,CheckSaveNNW,
OnSelTypViewSndLineDiag,SetTypRecNNW,SetMenuTypNNWRec,ShowProgr,OnCloseWin},
WndProcMain,DlgProcCntrlMain,WndSpectrDiag,WndGraphSig,WndGraphSpectr,
FunSndCap_CallBack,DecSnd_Store,ShowProgrMain,

DlgAbout,DlgParSpectr,

// Cтруктура результата распознавания.
struct strResRec { strResRec,Zero},

// Cтруктура параметров события (звука) внутри файла.
struct strDBS { strDBS,Zero,ZeroRes,Read,Write,Print,ProcSpectr,GetPeaks,GetInpData,GetInpDataVC,
GetInpDataSp,GetResult},

// Cтруктура базы данных по звукам внутри файла.
struct strDBSArr {
strDBSArr,~strDBSArr,Zero,Free,Alloc,IsOK,Read,Write,Read_,Write_,ReadSound,FillLBParam,Get,
ProcSpectr,GetPeaks,GetInpData,SetResZero,GetResult,CalcResult},

// Cтруктура описания параметров файла, используемого при тренировке сетей.
struct strDBF {
strDBF,~strDBF,Zero,Free,Read,Write,ReadDBS,WriteDBS,Print,ProcSpectr,GetPeaks,GetInpData,SetResZero,GetResult},

// Cтруктура базы данных по всем файлам для тренировки нейронной сети.
struct strDBFArr {
strDBFArr,~strDBFArr,Zero,Free,
FreeDBF,AllocDBF,IsOK_DBF,Get,
Read,Write,Read_,Write_,Write_,ReadDBS,WriteDBS,
SetFlagChange,SetResZero},

// Cтруктура пункта данных для тренировки нейронной сети.
struct strDataTrain { strDataTrain,Zero,IsOK,SetFlags},

// Cтруктура массива данных для тренировки нейронной сети.
struct strDataTrainArr {
strDataTrainArr,~strDataTrainArr,Zero,Free,Alloc,IsOK,Get,SetFlags},

// Cтруктура статистики для звука.
struct strStatSnd { strStatSnd,Zero,Print},

// Cтруктура статистики для набора звуков.
struct strStatSndAll {
strStatSndAll,~strStatSndAll,Zero,Free,Alloc,IsOK,FillLB},
FindStatSound,DlgShowStatSound,

// Класс для редактирования базы данных и тренировки нейронной сети.
class clDlgDBF_NNW {
clDlgDBF_NNW,~clDlgDBF_NNW,Zero,Free,SetPntDataBase,SetPntNeurNet,
ZeroBrushes,FreeBrushes,CreateBrushes,
ZeroWaveSynth,FreeWaveSynth,CreateWaveSynth,
IsOK_DBF,SaveFileDBF,UnSelFile,OnSelChangeFile,SetWinParFile,ClearWinParFile,UnSelSound,OnSelChangeSound,
FindSoundDiag,SetWinParSound,ClearWinParSound,LoadFile,SetFlagLoadFile,OnChangeStrFile,OnChangeStrSound,
OnOpenDlg,OnCloseDlg,OnChDataBase,
SetHeaderWinAlpha,SetTimeSound,SetFlagChange,
ReadNNW,SaveNNW,SaveAsNNW,SetNameNNW,
ReadParNNW,SaveParNNW,SaveAsParNNW,AdjustParNNW,InitNNW,GetParFromNNW,
AdjParTrain,ProcSpectr,GetPeaks,GetInpData,ProcSpectrPeaks,ProcSetInpData,FillTrainData,FillTrueOut,
CmndTrainNNW,TrainNNW,TrainNNW_Seq,TrainNNW_SeqRep,TrainNNW_SeqLay,TrainNNW_Group,TrainNNW_GroupSearch,
TrainSearchIniRandom,
StepTrainErr,StepTrainSequent,StepTrainSequentRep,StepTrainSequentLay,InitSequentLay,StepSequentLay,
FindVectGroup,StepFindAdaptStepGroup,SetErrWin,ClearErrWin,GetStepTrain,SetStepTrain,ShowHideWinStepTrain,
SetNameTrainMeth,ShowProgr,
MsgCommand,Command,OnSelectTypNet,
SetPntNNW,DrawNet,SetFocusWin,FillLBFiles,
StartPlaySound,StartPlaySoundPeaks,OnStopSound,SetTxtBtnPreProc,SetTxtBtnSetData,SetTxtBtnTrain,
SetTxtBtnPlaySound,SetTxtBtnBlockSetTime,OnChFlagPreProc,OnChFlagSetInpData,OnChFlagTrain,SetStateRadioTypNet,
InitParNNW,IsTrain,IsDoTrain,
IsDoPreProc,ShowStatistics,FindShowResults,DoTest,
AcceptDBF,DelDBF,InsDBF,AddDBF,
AcceptDBS,DelDBS,InsDBS,AddDBS,
BrowseFileDBF,OnChangeGendDBF},
DlgProcDB,

// Вспомогательные программы.
GetNumSndChar,GetTypNumSndChar,GetOutArr,GetNumSound,GetSymbSound,

// Класс для окна визуализации нейронной сети.
class clWinViewNNW {
clWinViewNNW,~clWinViewNNW,Zero,Free,CloseFree,SetParPnt,SetPntNeurNet,CreateWindow,CloseWindow,OnCloseWin,
GetMinSizeWin,SetMinSize,
CreateDlgCntrl,CloseDlgCntrl,
ChPosSizeChWin,SetPosSizeChWin,
ZeroImgMem,FreeImgMem,CreateImgMem,IsOKImgMem,DrawNetMem,
OnPaint,DrawNet,UpdateWin,SetNet_,SetNet,OnSelectTypNet,SetFlagWork,SetTxtBtnWork,OnSelectTypShowAxons,
MsgCommand,MsgCommandCntrl,Command},
WndViewNNW,DlgProcCntrlViewNNW,

// Класс для окна текста распознавания.
class clWinText {
clWinText,~clWinText,Zero,SetParPnt,
ZeroBrushes,FreeBrushes,CreateBrushes,
CreateWindow,CloseWindow,OnCloseWin,GetMinSizeWin,SetMinSize,
CreateEdt,CloseEdt,ChPosSizeChWin,SetPosSizeChWin,SetText,ClearWin,MsgCommand},
WndViewText,

// Структура параметров для анализа потока данных для звука.
struct strParAnSnd { IsOK},

// Структура для анализа потока данных для звука.
struct strAnSnd {
strAnSnd,~strAnSnd,Zero,Free,Init,IsOK,Start,Step},

// Структура для анализа потока данных для нескольких звуков.
struct strAnSndArr {
strAnSndArr,~strAnSndArr,Zero,Free,Clear,Create,IsOK,Init,Start,Step},

// Структура для анализа потока данных.
struct strAnalyseSound { Init,Start,Step}

...........................................................................................................*/

#include "stdafx.h"

#include "Project_con.h"
#include "cmplx.h"
#include "Project_cls.h"
#include "Project_snd.h"
#include "Project_pro.h"
#include "Project.h"
#include "resource.h"

#pragma comment(lib,"comctl32.lib")

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Программы.

BYTE AllocString(char **Str,size_t ln); // Выделение памяти для строки.
void FreeString(char **Str); // Освобождение памяти для строки.
BYTE AllocSHRT(SHRT **shipp,size_t ln); // Выделение памяти для массива 'SHRT'.
void FreeSHRT(SHRT **shipp); // Освобождение памяти для массива 'SHRT'.
BYTE AllocFloat(float **fpp,size_t ln); // Выделение памяти для массива 'float'.
void FreeFloat(float **fpp); // Освобождение памяти для массива 'float'.
BYTE AllocComplex(complex **cpp,size_t ln); // Выделение памяти для массива 'complex'.
void FreeComplex(complex **cpp); // Освобождение памяти для массива 'complex'.
BYTE IsFileExist_(char *PathName); // Проверка существования файла.
BYTE CrSelPen(HDC hdc,HPEN *hPen,HPEN *hPenP,BYTE Wid,DWORD Col); // Создание и выбор пера.
void UnSelDelPen(HDC hdc,HPEN *hPen,HPEN *hPenP); // Освобождение и удаление пера.
void ImgRectC(HDC hdc,RECT *rc,DWORD ColP,DWORD ColB,BYTE Wid); // Закрашивание прямоугольника.
void ImgWinC(HWND hwnd,DWORD ColP,DWORD ColB); // Закрашивание окна.
void ShowWin(HWND hwnd,BYTE flVis); // Отображение или скрытие окна.
void UpdateWindow_(HWND hwnd); // Обновление окна.
void CloseWin_(HWND *hwnd); // Закрытие окна.
void DestroyWin_(HWND *hwnd); // Уничтожение окна с обнулением 'hwnd'.
void ShowChWin(HWND hDlg,int id,BYTE flVis); // Показ или скрытие дочернего окна.
void EnableChWin(HWND hDlg,int id,BYTE flag); // Ввод и снятие блокировки дочернего окна.
void SetPosWindowCenter(HWND hDlg); // Помещение окна в центр другого окна или экрана.
BYTE SetPosWindow(HWND hwnd,RECT *rc); // Установка расположения окна.
BYTE GetDlgWinRect(HWND hDlg,int id,RECT *rc); // Получение прямоугольника дочернего окна диалога в координатах диалога.
void CloseChWin(HWND hDlg,int id); // Закрытие дочернего окна.
HFONT GetFont(char *nameFont,SHRT Wid,SHRT Hei); // Загрузка шрифта.
BYTE SetFont(HWND hwnd,HFONT hFont); // Программа для установки шрифта в окне.
void SetStMenuItem_(HMENU hMenu,UINT id,SCHAR En,SCHAR Ch); // Установка состояния пункта меню.
BYTE ClearList(HWND hDlg,int id); // Очистка списка.
BYTE SelItemList(HWND hDlg,int id,USHRT num); // Установка выделенного элемента в списке.
BYTE IsOKStr(char *str); // Проверка строки.
BYTE StrCopy(char *Dst,size_t lnDst,char *Src); // Копирование строк.
BYTE LoadString_(UINT StrID,char *String,USHRT szString); // Загрузка строки из ресурсов.
BYTE DupString(char **Str,char *Src); // Выделение памяти для строки и копирование.
BYTE LoadDupString(char **Str,UINT StrID,char *Def); // Загрузка строки из ресурсов.
BYTE ReadString(FILE *file,char *str,size_t strLen); // Чтение строки из текстового файла.
BYTE CompareStr(char *strA,char *strB); // Сравнение строк (с учётом длины строк и типа букв).
BYTE CompareStrCase(char *strA,char *strB); // Сравнение строк (с учётом длины строк и типа букв) без различения прописных и строчных букв.
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // Получение имени файла включая путь.
BYTE SetByteEdt(HWND hDlg,int id,BYTE bV); // Установка значения 'BYTE' в окно редактирования.
BYTE SetUSHRT_Edt(HWND hDlg,int id,USHRT Val); // Установка значения 'USHRT' в окно редактирования.
BYTE SetFlEdt(HWND hDlg,int id,float Val,char *Form); // Установка значения с плавающей точкой в окно редактирования.
BYTE GetFlEdt(HWND hDlg,int id,float *Val); // Получение значения с плавающей точкой из окна редактирования.
BYTE SetChBox(HWND hDlg,int id,BYTE flag); // Установка флага в окне.
BYTE GetChBox(HWND hDlg,int id,BYTE *flag); // Получение флага из окна.
BYTE SizeMovWin(HWND hwnd,int shX,int shY,int dX,int dY,BYTE flChild); // Перемещение и изменение размеров окна.
BYTE SetRangePageScrollBar(HWND hwnd,BYTE Dir,BYTE Cntrl,int nMin,int nMax,UINT nPage,BYTE Update); // Установка пределов и размера страницы в полосе прокрутки с пропорциональной шириной ползунка.
BYTE ScrollFunS(WPARAM wParam,int *p,int pMin,int pMax,SHRT nScrl,SHRT nScrlP); // Обработка сообщений от полосы прокрутки.
BYTE ScrollFun32(HWND hwnd,int nScroll,BYTE Dir,BYTE Cntrl,int *p,int nScrl,int nScrlP); // Обработка сообщений от полосы прокрутки.
HWND InitProgress(HWND hDlg,int id); // Инициализация окна показа процента выполнения работы.
void SetColProgr(HWND hwnd,DWORD BkgCol,DWORD BarCol); // Установка цветов индикаторной полосы показа процента выполнения работы.
void ShowProgress(HWND hwndProgr,HWND hwndPerc,UINT p,UINT pMax); // Изображение процента выполнения работы.
BYTE FileNameQuest(HWND hwnd,BYTE flWrite,UINT idSFilt,char *PathToDir,char *extFile,UINT IDS_Header,
  char *FileNameN,USHRT szFileNameN,char *PathToDirN,USHRT szPathToDirN,char *ExtN,USHRT szExtN,BYTE flChExt); // Выводит стандартный диалог для запроса имени файла и получает имя файла и директории.
BYTE InitBmpMem_(HWND hwnd,clImgMem **Bmp,int dx,int dy,BYTE mess); // Создание объекта класса 'clImgMem'.
void DeleteBmpMem_(clImgMem **Bmp); // Удаление объекта класса 'clImgMem'.
BYTE IsOKRect(RECT *rc); // Проверка прямоугольника.
BYTE GetBYTE(float v); // Получение числа 'BYTE' из числа 'float' с проверкой выхода за пределы 'BYTE'.
USHRT GetUSHRT_Test(int iv); // Получение числа 'USHRT' из числа 'int' с проверкой выхода за пределы 'USHRT'.
USHRT GetUSHRT_Test(float v); // Получение числа 'USHRT' из числа 'float' с проверкой выхода за пределы 'USHRT'.
USHRT GetUSHRT_Test(double d); // Получение числа 'USHRT' из числа 'double' с проверкой выхода за пределы 'USHRT'.
int GetIntTest(float v); // Получение числа 'int' из числа 'float' с проверкой выхода за пределы 'int'.
int GetIntTest(double v); // Получение числа 'int' из числа 'double' с проверкой выхода за пределы 'int'.
UINT GetUINT_Test(double d); // Получение числа 'UINT' из числа 'double' с проверкой выхода за пределы 'UINT'.
void ErrMessage(void); // Выдача сообщения об ошибке.
void Message_(HWND hwnd,UINT StrID,char *txt,UINT typ); // Вывод сообщения.
void Message(UINT StrID,UINT typ); // Вывод сообщения.
void ProcMess(void); // Опрос очереди сообщений и обработка сообщений.
void SoundBlock(void); // Звук при заблокированном действии.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные переменные.

HINSTANCE hInst; // Идентификатор приложения.
LRESULT LRes; // Вспомогательная переменная.

// Курсоры общего назначения.
HCURSOR cur_wait;

// Шрифты.
HFONT hFontA;

DWORD ColDial; // Цвет фона или диалогового окна.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Массив основных цветов палитры для изображения диаграммы (положительные значения).

DWORD ColBaseDiag[nColB]={COL_WHITE,COL_DK_BLUE,COL_BLUE,COL_DK_SKY_BLUE,COL_DK_GREEN,COL_GREEN,COL_YELLOW,COL_DK_RED,COL_RED};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Массив основных цветов палитры для положительных значений.

DWORD ColBasePos[nColB]={COL_BLACK,COL_VDK_YELLOW,COL_DK_YELLOW,COL_DK_BRICK,COL_DK_RED,COL_RED,COL_BRICK,COL_YELLOW,COL_WHITE};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Массив основных цветов палитры для знакопеременных значений.

DWORD ColBaseSign[nColB]={COL_SKY_BLUE,COL_BLUE,COL_GREEN,COL_DK_GREEN,COL_BLACK,COL_DK_RED,COL_RED,COL_YELLOW,COL_WHITE};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Строки.

char const NameClassMainWin[]="ClassMainWinSpeachRecogn"; // Имя класса главного окна.
char const ClassNameSpDiag[]="ClassNameSpectrDiag"; // Имя класса для дочернего окна спектральной диаграммы.
char const ClassNameGraphSnd[]="ClassNameGraphSnd"; // Имя класса для дочернего окна графика сигнала.
char const ClassNameGraphSpectr[]="ClassNameGraphSpectr"; // Имя класса для дочернего окна графика спектра.
char const ClassNameViewNNW[]="ClassNameViewNNW"; // Имя класса для окна визуализации нейронной сети.
char const ClassNameText[]="ClassNameText"; // Имя класса для окна текста.

char const szTitleProg[]="Распознавание речи методом нейронных сетей"; // Название программы.
char const NameWinSpectrDiag[]="Диаграмма спектра"; // Заголовок дочернего окна спектральной диаграммы.
char const NameWinGraphSnd[]="График сигнала";      // Заголовок дочернего окна графика сигнала.
char const NameWinGraphSpectr[]="График спектра";   // Заголовок дочернего окна графика спектра.
char const NameWinViewNNW[]="Визуализация нейронной сети"; // Заголовок окна визуализации нейронной сети.
char const NameWinText[]="Результат распознавания"; // Заголовок окна текста.

char TxtStr[strL_Txt],TxtMem[strL_Txt]; // Вспомогательные строки.

char PathToProgDir[strL_Path]; // Директория программы.
char PathToDir[strL_Path]; // Директория файла.
char PathToDirDBS[strL_Path]; // Директория с файлами баз данных.
char PathToDirParNNW[strL_Path]; // Директория с файлами параметров нейронной сети.
char PathToDirNNW[strL_Path]; // Директория с файлами нейронных сетей.
char PathToDirN[strL_Path]; // Директория выбранного файла.
char FileNameN[strL_FileName]; // Имя выбранного файла.
char ExtN[szExt]; // Расширение выбранного файла.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Директории.

char *dirHelp="Help\\"; // Директория с файлами справки.
char *dirSounds="Sounds\\"; // Директория со звуковыми файлами.
char *dirDBS="DataBase\\"; // Директория с базами данных.
char *dirParNNW="ParNNW\\"; // Директория с файлами параметров нейронных сетей.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Расширения файлов.

char *extHTM=".htm"; // Расширение файлов справки в формате '*.htm'.
char *extWAV=".wav"; // Расширение звукового файла.
char *extDBF=".dbf"; // Расширение файла базы данных с именами файлов.
char *extDBS=".dbs"; // Расширение файла базы данных по звукам внутри файла.
char *extParNNW_Vowel=".pnwv"; // Расширение файла параметров нейронной сети для гласных звуков.
char *extParNNW_Cons=".pnwc"; // Расширения файлов параметров нейронных сетей для согласных звуков.
char *extParNNW_Spectr=".pnws"; // Расширения файлов параметров нейронных сетей для всего спектра.
char *extNNW_Vowel=".nnwv"; // Расширение файла нейронной сети для гласных звуков.
char *extNNW_Cons=".nnwc"; // Расширение файла нейронной сети для согласных звуков.
char *extNNW_Spectr=".nnws"; // Расширения файла нейронной сети для всего спектра.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Имена файлов.

char *NameDLLSoundCap="SoundCap.dll"; // Имя библиотеки *.dll для захвата звука.
char *NameParSpectr="ParSpectr.cnf"; // Параметры спектральной обработки.
char *NameParGetPeaks="ParGetPeaks.cnf"; // Параметры нахождения спектральных линий для гласных звуков.
char *NameParTrain="ParTrain.cnf"; // Параметры тренировки.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Имена файлов справки.

char *nameHlpProg="Project"; // Имя справки по программе.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Шрифты.

char *NameFontWinTest="Times New Roman"; // Шрифт для окна вывода текста.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Форматы.

char *FormTimeDur="%10.5f"; // Короткий промежуток времени (с).
char *FormTime="%10.3f"; // Время (с).
char *FormFreq="%10.3f"; // Частота (Гц).
char *FormAmpNormSpectr="%6.3f"; // Амплитуда нормировки спектра.
char *FormAmpNormSig="%6.3f"; // Амплитуда нормировки сигнала.
char *FormAmp="%6.3f"; // Амплитуда сигнала.
char *FormCoeff="%12.5e"; // Коэффициент.
char *FormErr="%12.5e"; // Ошибка при тренировке сети.
char *FormNeur="%7.4f"; // Амплитуда на нейроне.
char *FormSynops="%12.5e"; // Амплитуда на синапсе.
char *FormStepTrain="%9.6e"; // Шаг тренировки.
char *FormDB="%10.3f"; // Значение в дБ.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные классы и структуры.

clMain *MW;
struct strParGetPeaks ParGetPeaks; // Структура параметров нахождения спектральных линий.
struct strParInpSpectr ParInpSp; // Структура параметров нахождения спектральных линий гласных звуков и предварительного распознавания гласных и согласных звуков.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Массив обозначений гласных и сонорных звуков.
char SignVoicesVowel[nVoicesVowel]={'а','э','о','у','ы', 'я','е','ё','ю','и', 'л','м','н','р','в'};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Цвета обозначения гласных и сонорных звуков.
DWORD ColVoicesVowel[nVoicesVowel]={
COL_RED,COL_DK_GREEN,COL_BLUE,COL_YELLOW,COL_DK_VIOLET,
COL_DK_RED,COL_GREEN,COL_DK_BLUE,COL_DK_YELLOW,COL_VIOLET,
COL_VDK_RED,COL_VDK_YELLOW,COL_VDK_VIOLET,COL_VDK_GREEN,COL_VDK_BLUE};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Массив обозначений согласных импульсных и шипящих звуков.
char SignVoicesCons[nVoicesCons]={'б','п','г','к','д','т','ч','ц', 'ж','з', 'й', 'с','ф','х','ш','щ'};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Цвета обозначения согласных импульсных и шипящих звуков.
DWORD ColVoicesCons[nVoicesCons]={COL_RED,COL_DK_RED,COL_LT_GRAY,COL_GRAY,COL_YELLOW,COL_DK_YELLOW,
COL_VIOLET,COL_DK_VIOLET,  COL_BLUE,COL_GREEN, COL_BRICK,
COL_SKY_BLUE,COL_DK_BLUE,COL_DK_GREEN,COL_VDK_RED,COL_VDK_YELLOW};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров для анализа потока данных для звука.
//struct strParAnSnd { float tStore,weiStore,weiInst;};

// Для гласных и сонорных звуков.
struct strParAnSnd ParAnSndVowel[nVoicesVowel]={
{tStVowel,1.0F,1.0F},{tStVowel,1.0F,1.0F},{tStVowel,1.0F,1.0F},{tStVowel,1.0F,1.0F},{tStVowel,1.0F,1.0F},
{tStVowel,1.0F,1.0F},{tStVowel,1.0F,1.0F},{tStVowel,1.0F,1.0F},{tStVowel,1.0F,1.0F},{tStVowel,1.0F,1.0F},
{tStSonor,1.0F,1.0F},{tStSonor,1.0F,1.0F},{tStSonor,1.0F,1.0F},{tStSonor,1.0F,1.0F},{tStSonor,1.0F,1.0F}};

// Для согласных импульсных и шипящих звуков.
struct strParAnSnd ParAnSndCons[nVoicesCons]={
{tStPulse,1.0F,1.0F},{tStPulse,1.0F,1.0F},{tStPulse,1.0F,1.0F},{tStPulse,1.0F,1.0F},
{tStPulse,1.0F,1.0F},{tStPulse,1.0F,1.0F},{tStPulse,1.0F,1.0F},{tStPulse,1.0F,1.0F},
{tStHTone,1.0F,1.0F},{tStHTone,1.0F,1.0F},{tStHTone,1.0F,1.0F},
{tStTurb,1.0F,1.0F},{tStTurb,1.0F,1.0F},{tStTurb,1.0F,1.0F},{tStHiss,1.0F,1.0F},{tStHiss,1.0F,1.0F}};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Идентификаторы строк названий методов тренировки сети.

UINT IDSArrMethTrain[nMethTrain]={IDS_MethTrain_Sequent,IDS_MethTrain_SeqRep,IDS_MethTrain_SeqLay,
IDS_MethTrain_GroupAdapt,IDS_MethTrain_GroupSearch};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров увеличения амплитуд высоких гармоник при синтезе звука.
//struct strParIncHighSynth { BYTE nc; float coeCorr,CorrMax;};
struct strParIncHighSynth ParIHS={6,0.25F,2.0F};

//-----------------------------------------------------------------------------------------------------------

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
BYTE InitCommonControls_(void); // Загрузка классов для кнопок и окон управления 'Windows'.
BYTE RegisterClassAll(void); // Регистрация всех классов.
BYTE GetPath(BYTE typ); // Получение имени директории с программой.

UNREFERENCED_PARAMETER(hPrevInstance);
UNREFERENCED_PARAMETER(lpCmdLine);

MSG msg; HACCEL hAccelTable; HWND MainHwnd;  

hInst=hInstance;

if(InitCommonControls_()!=0) return FALSE; // Загрузка классов для кнопок и окон управления 'Windows'.
if(RegisterClassAll()!=0) return FALSE; // Регистрация всех классов.
if(GetPath(0)!=0) return FALSE; // Получение имени директории с программой.
ColDial=GetSysColor(COLOR_BTNFACE); // Получение цвета фона или диалогового окна.

// Создание главного окна.
MainHwnd=CreateWindow(NameClassMainWin,szTitleProg,WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN,
-4,-4,GetSystemMetrics(SM_CXSCREEN)+8,GetSystemMetrics(SM_CYSCREEN)-21,NULL,NULL,hInst,NULL);
if(MainHwnd==NULL) { ErrMessage(); return FALSE;}
ShowWindow(MainHwnd,nCmdShow); UpdateWindow(MainHwnd);

hAccelTable=LoadAccelerators(hInst,MAKEINTRESOURCE(IDA_MAIN));

// Цикл опроса очереди сообщений.
while(GetMessage(&msg,NULL,0,0)) {
if(!TranslateAccelerator(msg.hwnd,hAccelTable,&msg)) { TranslateMessage(&msg); DispatchMessage(&msg);}
}
return (int) msg.wParam;
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка классов для кнопок и окон управления 'Windows'.

BYTE InitCommonControls_(void)
{
BYTE ber; INITCOMMONCONTROLSEX *ICC;

ber=0; ICC=new INITCOMMONCONTROLSEX; if(ICC==NULL) { ber=1; goto end;} SET_ZERO(ICC);
ICC->dwSize=sizeof(INITCOMMONCONTROLSEX);
ICC->dwICC=ICC_PROGRESS_CLASS;
if(InitCommonControlsEx((LPINITCOMMONCONTROLSEX)ICC)==FALSE) { ber=2; goto end;}
end: SAFE_DELETE(ICC); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Регистрация всех классов.

BYTE RegisterClassAll(void)
{
ATOM RegisterClassMain(void); // Регистрация класса главного окна.
ATOM RegisterClassSpectrDiag(void); // Регистрация класса окна диаграммы спектра.
ATOM RegisterClassGraphSig(void); // Регистрация класса окна графика сигнала.
ATOM RegisterClassGraphSpectr(void); // Регистрация класса окна графика спектра.
ATOM RegisterClassViewNNW(void); // Регистрация класса окна визуализации нейронной сети.
ATOM RegisterClassText(void); // Регистрация класса окна текста.

if(!RegisterClassMain()) return 1; // Регистрация класса главного окна.
if(!RegisterClassSpectrDiag()) return 2; // Регистрация класса окна диаграммы спектра.
if(!RegisterClassGraphSig()) return 3; // Регистрация класса окна графика сигнала.
if(!RegisterClassGraphSpectr()) return 4; // Регистрация класса окна графика спектра.
if(!RegisterClassViewNNW()) return 5; // Регистрация класса окна визуализации нейронной сети.
if(!RegisterClassText()) return 6; // Регистрация класса окна текста.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Регистрация класса главного окна.

ATOM RegisterClassMain(void)
{
LRESULT CALLBACK WndProcMain(HWND,UINT,WPARAM,LPARAM); // Функция главного окна.

WNDCLASSEX wcex;

wcex.cbSize=sizeof(WNDCLASSEX);
wcex.style			= CS_HREDRAW|CS_VREDRAW;
wcex.lpfnWndProc	= WndProcMain;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInst;
wcex.hIcon			= LoadIcon(hInst,MAKEINTRESOURCE(IDI_PROG));
wcex.hCursor		= LoadCursor(NULL,IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= MAKEINTRESOURCE(ID_MENU_MAIN);
wcex.lpszClassName	= NameClassMainWin;
wcex.hIconSm		= LoadIcon(hInst,MAKEINTRESOURCE(IDI_PROG));
return RegisterClassEx(&wcex);
}

//-----------------------------------------------------------------------------------------------------------
// Регистрация класса окна диаграммы спектра.

ATOM RegisterClassSpectrDiag(void)
{
LRESULT CALLBACK WndSpectrDiag(HWND,UINT,WPARAM,LPARAM); // Функция обработки сообщений окна спектральной диаграммы.

WNDCLASSEX wcex;

wcex.cbSize=sizeof(WNDCLASSEX);
wcex.style			=CS_HREDRAW|CS_VREDRAW;
wcex.lpfnWndProc	= WndSpectrDiag;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInst;
wcex.hIcon			= NULL;
wcex.hCursor		= LoadCursor(NULL,IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= NULL;
wcex.lpszClassName	= ClassNameSpDiag;
wcex.hIconSm		= NULL;
return RegisterClassEx(&wcex);
}

//-----------------------------------------------------------------------------------------------------------
// Регистрация класса окна графика сигнала.

ATOM RegisterClassGraphSig(void)
{
LRESULT CALLBACK WndGraphSig(HWND,UINT,WPARAM,LPARAM); // Функция обработки сообщений окна графика сигнала.

WNDCLASSEX wcex;

wcex.cbSize=sizeof(WNDCLASSEX);
wcex.style			=CS_HREDRAW|CS_VREDRAW;
wcex.lpfnWndProc	= WndGraphSig;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInst;
wcex.hIcon			= NULL;
wcex.hCursor		= LoadCursor(NULL,IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= NULL;
wcex.lpszClassName	= ClassNameGraphSnd;
wcex.hIconSm		= NULL;
return RegisterClassEx(&wcex);
}

//-----------------------------------------------------------------------------------------------------------
// Регистрация класса окна графика спектра.

ATOM RegisterClassGraphSpectr(void)
{
LRESULT CALLBACK WndGraphSpectr(HWND,UINT,WPARAM,LPARAM); // Функция обработки сообщений окна графика спекрта.

WNDCLASSEX wcex;

wcex.cbSize=sizeof(WNDCLASSEX);
wcex.style			=CS_HREDRAW|CS_VREDRAW;
wcex.lpfnWndProc	= WndGraphSpectr;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInst;
wcex.hIcon			= NULL;
wcex.hCursor		= LoadCursor(NULL,IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= NULL;
wcex.lpszClassName	= ClassNameGraphSpectr;
wcex.hIconSm		= NULL;
return RegisterClassEx(&wcex);
}

//-----------------------------------------------------------------------------------------------------------
// Регистрация класса окна визуализации нейронной сети.

ATOM RegisterClassViewNNW(void)
{
LRESULT CALLBACK WndViewNNW(HWND,UINT,WPARAM,LPARAM); // Функция обработки сообщений окна визуализации нейронной сети.

WNDCLASSEX wcex;

wcex.cbSize=sizeof(WNDCLASSEX);
wcex.style			=CS_HREDRAW|CS_VREDRAW;
wcex.lpfnWndProc	= WndViewNNW;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInst;
wcex.hIcon			= LoadIcon(hInst,MAKEINTRESOURCE(IDI_NNW));
wcex.hCursor		= LoadCursor(NULL,IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= NULL;
wcex.lpszClassName	= ClassNameViewNNW;
wcex.hIconSm		= LoadIcon(hInst,MAKEINTRESOURCE(IDI_NNW));
return RegisterClassEx(&wcex);
}

//-----------------------------------------------------------------------------------------------------------
// Регистрация класса окна текста.

ATOM RegisterClassText(void)
{
LRESULT CALLBACK WndViewText(HWND,UINT,WPARAM,LPARAM); // Функция обработки сообщений окна текста.

WNDCLASSEX wcex;

wcex.cbSize=sizeof(WNDCLASSEX);
wcex.style			=CS_HREDRAW|CS_VREDRAW;
wcex.lpfnWndProc	= WndViewText;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInst;
wcex.hIcon			= LoadIcon(hInst,MAKEINTRESOURCE(IDI_TEXT));
wcex.hCursor		= LoadCursor(NULL,IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= NULL;
wcex.lpszClassName	= ClassNameText;
wcex.hIconSm		= LoadIcon(hInst,MAKEINTRESOURCE(IDI_TEXT));
return RegisterClassEx(&wcex);
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей.

void ZeroMain(void)
{
cur_wait=NULL; hFontA=NULL; MW=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти и удаление классов в программе.

void FreeMain(void)
{
SAFE_DELETE(MW); hFontA=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация - создание класса главного окна.

BYTE InitMain(HWND hwnd)
{
BYTE CheckCreateDir(char *Path,char *dir,BYTE flCreate); // Проверка наличия директории и создание при необходимости.
BYTE SetPathFilesSound(void); // Установка имени директории для звуковых файлов.
BYTE SetPathFilesDBS(void); // Установка имени директории для файлов баз данных.
BYTE SetPathParNNW(void); // Установка имени директории для файлов параметров нейронных сетей.
BYTE SetPathNNW(void); // Установка имени директории для файлов нейронных сетей.

if(hwnd==NULL) return 1;
cur_wait=LoadCursor(NULL,IDC_WAIT);
hFontA=(HFONT)GetStockObject(ANSI_VAR_FONT); if(hFontA==NULL) return 2;
if(CheckCreateDir(PathToProgDir,dirSounds,1)!=0) return 3; // Проверка наличия директории для звуковых файлов.
if(CheckCreateDir(PathToProgDir,dirDBS,1)!=0) return 4; //  Проверка наличия директории для баз данных.
if(CheckCreateDir(PathToProgDir,dirParNNW,1)!=0) return 5; //  Проверка наличия директории для файлов с параметрами нейронных сетей.
if(SetPathFilesSound()!=0) return 6; // Установка имени директории для звуковых файлов.
if(SetPathFilesDBS()!=0) return 7; // Установка имени директории для файлов баз данных.
if(SetPathParNNW()!=0) return 8; // Установка имени директории для файлов параметров нейронных сетей.
if(SetPathNNW()!=0) return 9; // Установка имени директории для файлов нейронных сетей.

MW=new clMain(hwnd); if(MW==NULL) return 10; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка имени директории для звуковых файлов.

BYTE SetPathFilesSound(void)
{
if(strlen(PathToProgDir)+strlen(dirSounds)>strL_Path) return 1;
strcpy(PathToDir,PathToProgDir); strcat(PathToDir,dirSounds); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка имени директории для файлов баз данных.

BYTE SetPathFilesDBS(void)
{
if(strlen(PathToProgDir)+strlen(dirDBS)>strL_Path) return 1;
strcpy(PathToDirDBS,PathToProgDir); strcat(PathToDirDBS,dirDBS); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка имени директории для файлов параметров нейронных сетей.

BYTE SetPathParNNW(void)
{
if(strlen(PathToProgDir)+strlen(dirParNNW)>strL_Path) return 1;
strcpy(PathToDirParNNW,PathToProgDir); strcat(PathToDirParNNW,dirParNNW); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка имени директории для файлов нейронных сетей.

BYTE SetPathNNW(void)
{
if(strlen(PathToProgDir)+strlen(dirDBS)>strL_Path) return 1;
strcpy(PathToDirNNW,PathToProgDir); strcat(PathToDirNNW,dirDBS); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение имени директории.

BYTE GetPath(BYTE typ)
{
BYTE StrSybmConv(char *StrI,char *StrC,size_t szStrC,BYTE flag); // Преобразование символов строки в большие или малые символы.

BYTE ber; size_t ln; char *cp,*str,*ext;

if(hInst==NULL) return 1;
if(GetModuleFileName(hInst,PathToProgDir,strL_Path)==0) { ErrMessage(); return 2;}
ln=strlen(PathToProgDir); if(ln==0) return 3;
str=NULL; ber=0;
if(AllocString(&str,ln)!=0) { ber=5; goto end;}
if(StrSybmConv(PathToProgDir,str,ln+1,1)!=0) { ber=6; goto end;}
if(typ==0) ext=".EXE"; else ext=".DLL";
cp=strstr(str,ext); if(cp==NULL) { ber=7; goto end;} *cp='\0';
cp=strrchr(str,'\\'); if(cp==NULL) { ber=8; goto end;} cp++; *cp='\0';
ln=strlen(str); PathToProgDir[ln]='\0';
end: FreeString(&str); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс главного окна.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Идентификаторы таймеров.

#define idT_Main_CheckCurPos 1 // Таймер проверки положения курсора.
#define uT_Main_CheckCurPos 500 // Время таймера проверки положения курсора.

#define idT_Main_Snd 2 // Таймер перемещения курсора при проигрывании звука.
#define uT_Main_Snd 20 // Время таймера перемещения курсора при проигрывании звука.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

clMain::clMain(HWND hwnd_)
{
Zero(); hwnd=hwnd_; OnBegin(); 
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

clMain::~clMain(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void clMain::Zero(void)
{
hwnd=hDlg=hwndDiag=hwndGraphSig=hwndGraphSpectr=NULL; hwndProgr=hwndPerc=NULL; hDlgDB=NULL; hMenu=NULL;
ZeroBrushes(); ZeroHelp(); ZeroBmpDiag(); ZeroSndCap(); ZeroSndCapData();
DlgDBFNNW.SetPntDataBase(&DataBase); // Установка указателя на структуру базы данных в классе диалогового окна тренировки сети.
NNW_Vowel.typ=typNNW_Vowel;
NNW_Cons.typ=typNNW_Cons;
NNW_Spectr.typ=typNNW_Spectr;
DlgDBFNNW.SetPntNeurNet(&NNW_Vowel,&NNW_Cons,&NNW_Spectr); // Установка указателей на структуры нейронных сетей в классе диалогового окна тренировки сети.
SET_ZERO(&rcSig); SET_ZERO(&rcDiag); SET_ZERO(&rcSpect); SET_ZERO(&rcViewNNW); SET_ZERO(&rcText);
FileNameWAV=NULL;
AmpNorm=AmpSpect=AmpNormSpectr_Stand; AmpSig=AmpNormSig_Stand;
pScDiagH=pMScDiagH=0;
pScDiagV=pMScDiagV=0;
pScGrSp=pMScGrSp=0;
pScGrSig=pMScGrSig=0;
CoordTimeDiag=CoordTimeSig=0; flCurGrSig=0; TimeCur=FreqCur=0.0F;
flStopSound=1; flPlaySound=0; flStopCaptSound=1; flCaptSound=flEnCaptSound=0; flRegCapt=0;
flProc=flDlgDBS=flDBS=0; flStopProc=1; flBlk=0; methDecSound=methDecSnd_Inst; typShowLineDiag=typNNW_Vowel;
typUseNNWRec=typNNR_VC;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление объектов из памяти.

void clMain::Free(void)
{
CloseWin_(&hDlg); CloseWin_(&hDlgDB); FreeBrushes(); FreeHelp(); FreeBmpDiag(); FreeSndCap();
FreeSndCapData(); FreeDiagRes(); FreeString(&FileNameWAV);
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление кистей для закрашивания окон.

void clMain::ZeroBrushes(void)
{
hBrushBkg=hBrushDial=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Создание кистей для закрашивания окон.

void clMain::FreeBrushes(void)
{
SAFE_DELETE_OBJECT(hBrushBkg);
SAFE_DELETE_OBJECT(hBrushDial);
}

//-----------------------------------------------------------------------------------------------------------
// Создание кистей для закрашивания окон.

BYTE clMain::CreateBrushes(void)
{
FreeBrushes();
hBrushBkg=CreateSolidBrush(COL_WHITE); if(hBrushBkg==NULL) return 1;
hBrushDial=CreateSolidBrush(ColDial); if(hBrushDial==NULL) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя для класса для вывода файла справки.

void clMain::ZeroHelp(void)
{
Help=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Уничтожение класса для вывода файла справки.

void clMain::FreeHelp(void)
{
SAFE_DELETE(Help); ChMenuHelp();
}

//-----------------------------------------------------------------------------------------------------------
// Создание класса для вывода файла справки.

BYTE clMain::CreateHelp(void)
{
BYTE ber;

FreeHelp(); if(IsOKStr(nameHlpProg)!=0) return 1; ber=0;
Help=new clHelpEx(); if(Help==NULL) { ber=2; goto end;}
if(Help->Set(PathToProgDir,dirHelp,nameHlpProg,nameHlpProg)!=0) { ber=3; goto end;}
end: if(ber!=0) FreeHelp(); else ChMenuHelp(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Изменение состояния пункта меню справки.

void clMain::ChMenuHelp(void)
{
BYTE b;

if(Help==NULL) b=0; else b=1; SetStMenuItem_(hMenu,IDM_HELP,(SCHAR)b,0);
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя на класс для вывода изображения диаграммы.

void clMain::ZeroBmpDiag(void)
{
BmpDiag=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление класса для вывода изображения диаграммы.

void clMain::FreeBmpDiag(void)
{
SAFE_DELETE(BmpDiag);
}

//-----------------------------------------------------------------------------------------------------------
// Создание класса для вывода изображения диаграммы.

BYTE clMain::CreateBmpDiag(void)
{
FreeBmpDiag(); BmpDiag=new clBmpPict(); if(BmpDiag==NULL) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при создании объекта класса главного окна.

void clMain::OnBegin(void)
{
if(hwnd==NULL) return; hMenu=GetMenu(hwnd); // Получение идентификатора меню.
CreateHelp(); // Создание класса для вывода файла справки.
CreateDlgCntrl(); // Создание диалогового окна управления.
CreateWinDiag(); // Создание дочернего окна диаграммы.
CreateWinGraph(); // Создание дочернего окна графика сигнала.
CreateWinGraphSpectr(); // Создание дочернего окна графика спектра.
SetPntWinViewNNW(); // Установка параметров и указателей для окна визуализации нейронной сети.
GetSizeWinViewNNW(); // Установка размеров окна визуализации нейронной сети.
SetPntWinText(); // Установка параметров и указателей для окна текста.
GetSizeWinText(); // Установка размеров окна текста.
OnChSizeWin(); // Перемещение дочерних окон сигнала, диаграммы и графика спектра.
ParSpectr.Read(PathToProgDir,NameParSpectr); // Чтение параметров спектральной обработки.
ParGetPeaks.Read(PathToProgDir,NameParGetPeaks); // Чтение параметров нахождения спектральных линий для гласных звуков.
CreateBmpDiag(); // Создание класса для вывода изображения диаграммы.
CreateSndCap(); // Создание объекта класса библиотеки захвата звука.
CreateSndCapData(); // Класс хранения данных при записи звука: создание.
SetTimer(hDlg,idT_Main_CheckCurPos,uT_Main_CheckCurPos,NULL);

PalDiag.FillColor(ColBaseDiag);
PalPos.FillColor(ColBasePos);
PalSign.FillColor(ColBaseSign);
flAm=0; flFr=0; flTi=0;
} 

//-----------------------------------------------------------------------------------------------------------
// Создание диалогового управляющего окна.

BYTE clMain::CreateDlgCntrl(void)
{
LRESULT CALLBACK DlgProcCntrlMain(HWND,UINT,WPARAM,LPARAM); // Управляющее окно главного окна.

if(hwnd==NULL) return 1; if(hInst==NULL) return 2; CloseWin_(&hDlg);
if(CreateBrushes()!=0) return 3; // Создание кистей для закрашивания окон.
hDlg=CreateDialogParam(hInst,(LPCTSTR)IDD_CNTRL_MAIN,hwnd,(DLGPROC)DlgProcCntrlMain,(LPARAM)this);
if(hDlg==NULL) return 4;
hwndProgr=InitProgress(hDlg,IDC_PROGR); // Инициализация окна показа процента выполнения работы.
SetColProgr(hwndProgr,COL_WHITE,COL_BLUE); // Установка цветов полосы прогресса.
hwndPerc=GetDlgItem(hDlg,IDC_PERC); // Идентфикатор окна процента выполненной работы.

// Установка состояния окон и элементов управления.
SetFlEdt(hDlg,IDC_AMPL_DIAG,AmpNorm,FormAmpNormSpectr);
SetFlEdt(hDlg,IDC_AMPL_SIG,AmpSig,FormAmpNormSig);
SetFlEdt(hDlg,IDC_AMPL_GRSP,AmpSpect,FormAmpNormSpectr);
ChBtnMenuOpenDlgDBS_NNW(); // Изменение состояния кнопки и пункта меню открытия диалогового окна базы данных и тренировки сети.
ChBtnCaptSound(); // Установка состояния кнопки захвата звука.
SetTxtBtnPlaySound(); // Установка текста в кнопку воспроизведения звука.
SetTxtBtnCaptSound(); // Установка текста в кнопку записи звука.
SetTxtBtnRecSound(); // Установка текста в кнопку распознавания звука.
ChBtnMenuWinText(); // Изменение состояния кнопки и пункта меню открытия окна текста.
ChBtnMenuWinViewNNW(); // Изменение состояния кнопки и пункта меню открытия окна визуализации нейронной сети.
ChMenuProcOutput(); // Изменение состояния пункта меню обработки выходного потока символов.
CheckRadioButton(hDlg,IDC_RADIO_SHOW_VOWEL,IDC_RADIO_SHOW_CONS,IDC_RADIO_SHOW_VOWEL+(int)typShowLineDiag); // Установка типа изображаемых звуков в полосе интерпретации на диаграмме.
SetMenuTypNNWRec(); // Установка меню для типа сетей при распознавании.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание дочернего окна диаграммы.

BYTE clMain::CreateWinDiag(void)
{
int dx,dy; DWORD Style;

if(hwnd==NULL) return 1; if(hInst==NULL) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3;
dx=(int)(rc.right-rc.left);
dy=(int)(rc.bottom-rc.top);
Style=WS_CHILDWINDOW|WS_CAPTION|WS_VISIBLE|WS_CLIPSIBLINGS|WS_HSCROLL|WS_VSCROLL;
hwndDiag=CreateWindow(ClassNameSpDiag,NameWinSpectrDiag,Style,(int)rc.left,(int)rc.top,dx,dy,hwnd,
(HMENU)idMain_SpDiag,hInst,NULL); if(hwndDiag==NULL) { ErrMessage(); return 4;}
SetScrollDiagH(); // Установка параметров прокрутки окна диаграммы по горизонтали.
SetScrollDiagV(); // Установка параметров прокрутки окна диаграммы по вертикали.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении размеров окна диаграммы.

void clMain::OnChSizeWinDiag(void)
{
SetScrollDiagH(); // Установка параметров прокрутки окна диаграммы по горизонтали.
SetScrollDiagV(); // Установка параметров прокрутки окна диаграммы по вертикали.
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров прокрутки окна диаграммы по горизонтали.

BYTE clMain::SetScrollDiagH(void)
{
BYTE err; USHRT nPage; int dx,d;

if(hwndDiag==NULL) return 1; err=0;
if(BmpDiag==NULL) { err=2; goto end;} if(BmpDiag->IsOK()!=0) { err=3; goto end;}
if(GetClientRect(hwndDiag,&rc)==FALSE) { err=4; goto end;}
dx=(int)(rc.right-rc.left); if(dx<=0) { err=5; goto end;}
d=BmpDiag->dx-dx; if(d>SHRT_MAX) { err=6; goto end;}
if(d<=0) pMScDiagH=0; else pMScDiagH=d;
if(pMScDiagH!=0) nPage=GetUSHRT_Test((float)dx/(float)(pMScDiagH+(int)dx)*(float)pMScDiagH); else nPage=0;
if(SetRangePageScrollBar(hwndDiag,0,0,0,pMScDiagH,(UINT)nPage,1)!=0) { err=7; goto end;}
pScDiagH=0; SetScrollPos(hwndDiag,SB_HORZ,pScDiagH,TRUE); return 0;
end: SetRangePageScrollBar(hwndDiag,0,0,0,0,0,1); pScDiagH=0; SetScrollPos(hwndDiag,SB_HORZ,pScDiagH,TRUE); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров прокрутки окна диаграммы по вертикали.

BYTE clMain::SetScrollDiagV(void)
{
BYTE err; USHRT nPage; int dy,d;

if(hwndDiag==NULL) return 1; err=0;
if(BmpDiag==NULL) { err=2; goto end;} if(BmpDiag->IsOK()!=0) { err=3; goto end;}
if(GetClientRect(hwndDiag,&rc)==FALSE) { err=4; goto end;}
dy=(int)(rc.bottom-rc.top); if(dy<=0) { err=6; goto end;}
d=BmpDiag->dy-dy; if(d>SHRT_MAX) { err=6; goto end;}
if(d<=0) pMScDiagV=0; else pMScDiagV=d;
if(pMScDiagV!=0) nPage=GetUSHRT_Test((float)dy/(float)(pMScDiagV+(int)dy)*(float)pMScDiagV); else nPage=0;
if(SetRangePageScrollBar(hwndDiag,1,0,0,pMScDiagV,(UINT)nPage,1)!=0) { err=7; goto end;}
pScDiagV=pMScDiagV; SetScrollPos(hwndDiag,SB_VERT,pScDiagV,TRUE); return 0;
end: SetRangePageScrollBar(hwndDiag,1,0,0,0,0,1); pScDiagV=0; SetScrollPos(hwndDiag,SB_VERT,pScDiagV,TRUE); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Пролистывание окна диаграммы по горизонтали.

BYTE clMain::HScrollDiag(WPARAM wParam)
{
int p;

if(hwndDiag==NULL) return 1;

p=pScDiagH; if(ScrollFunS(wParam,&p,0,pMScDiagH,VelScrlPos,AccScrlPos)!=0) return 2; if(p==pScDiagH) return 3;
pScDiagH=p; SetScrollPos(hwndDiag,SB_HORZ,pScDiagH,TRUE); ProcMess(); UpdateWinDiag(); ProcMess(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Пролистывание окна диаграммы по вертикали.

BYTE clMain::VScrollDiag(WPARAM wParam)
{
int p;

if(hwndDiag==NULL) return 1;
p=pScDiagV; if(ScrollFunS(wParam,&p,0,pMScDiagV,VelScrlPos,AccScrlPos)!=0) return 2; if(p==pScDiagV) return 3;
pScDiagV=p; SetScrollPos(hwndDiag,SB_VERT,pScDiagV,TRUE); ProcMess(); UpdateWinDiag(); ProcMess(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при перемещении курсора мыши в окне диаграммы.

BYTE clMain::OnMouseMoveDiag(LPARAM lParam)
{
BYTE err; int dy,xPos,yPos,cf,sz; double st_Time;

if(hwndDiag==NULL) return 1; if(GetClientRect(hwndDiag,&rc)==FALSE) return 2;
dy=(int)(rc.bottom-rc.top); if(dy<=1) return 3;
xPos=LOWORD(lParam);
yPos=HIWORD(lParam);
err=0;

st_Time=SpectrAmp.stArr; if(st_Time<=0.) { err=4; goto err;}
if(Snd.IsOK()!=0) { err=5; goto err;}
if(BmpDiag==NULL) { err=6; goto err;} if(BmpDiag->IsOKB()!=0) { err=7; goto err;}

TimeCur=(float)st_Time*(float)(xPos+(int)pScDiagH); 
SetFlEdt(hDlg,IDC_COORDTIME,TimeCur,FormTime);
flTi=1;

sz=BmpDiag->dy-szWinResDiag; if(sz<=0) { err=8; goto err;}
cf=dy-1-yPos+pMScDiagV-pScDiagV-szWinResDiag;
if(cf<0) { if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDFREQ,""); flFr=0;}
else { FreqCur=(float)cf/((float)sz*(float)Snd.dt)*0.5F;
SetFlEdt(hDlg,IDC_COORDFREQ,FreqCur,FormFreq);
flFr=1;}

return 0;

err:
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDTIME,""); flTi=0;
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDFREQ,""); flFr=0;
return err;
}

//-----------------------------------------------------------------------------------------------------------
// Создание дочернего окна графика сигнала.

BYTE clMain::CreateWinGraph(void)
{
int dx,dy; DWORD Style;

if(hwnd==NULL) return 1; if(hInst==NULL) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3;
dx=(int)(rc.right-rc.left);
dy=(int)(rc.bottom-rc.top);
Style=WS_CHILDWINDOW|WS_CAPTION|WS_VISIBLE|WS_CLIPSIBLINGS;
hwndGraphSig=CreateWindow(ClassNameGraphSnd,NameWinGraphSnd,Style,(int)rc.left,(int)rc.top,dx,dy,hwnd,
(HMENU)idMain_GrSig,hInst,NULL); if(hwndGraphSig==NULL) { ErrMessage(); return 3;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при перемещении курсора мыши в окне графика сигнала.

BYTE clMain::OnMouseMoveGraphSig(LPARAM lParam)
{
BYTE err; int xPos,yPos,dy; float amp;

if(hwndGraphSig==NULL) return 1; if(GetClientRect(hwndGraphSig,&rc)==FALSE) return 2;
dy=(int)(rc.bottom-rc.top); if(dy<=0) return 3;
xPos=LOWORD(lParam);
yPos=dy/2-(int)HIWORD(lParam);

err=0;
if(Snd.IsOK()!=0) { err=4; goto err;}
if(AmpSig<=0.0F) { err=5; goto err;}

TimeCur=(float)Snd.dt*(float)(xPos+(int)pScGrSig);
SetFlEdt(hDlg,IDC_COORDTIME,TimeCur,FormTime); flTi=1;

amp=AmpSig*(float)yPos/(float)dy*2.0F;
SetFlEdt(hDlg,IDC_COORDAMPL,amp,FormAmpNormSig); flAm=1;

return 0;

err:
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDTIME,""); flTi=0;
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDAMPL,""); flAm=0;
return err;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении размеров окна графика сигнала.

void clMain::OnChSizeWinGraphSig(void)
{
SetScrollGrSig(); // Установка параметров прокрутки окна графика сигнала.
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров прокрутки окна графика сигнала.

BYTE clMain::SetScrollGrSig(void)
{
BYTE err; USHRT nPage; int dx,d;

if(hwndGraphSig==NULL) return 1; err=0;
if(Snd.ln==0) { err=2; goto end;}
if(GetClientRect(hwndGraphSig,&rc)==FALSE) { err=3; goto end;}
dx=(int)(rc.right-rc.left); if(dx<=0) { err=4; goto end;}
d=(int)Snd.ln-dx;
if(d<=0) pMScGrSig=0; else pMScGrSig=d;
if(pMScGrSig!=0) nPage=GetUSHRT_Test((float)dx/(float)(pMScGrSig+(int)dx)*(float)pMScGrSig); else nPage=0;
if(SetRangePageScrollBar(hwndGraphSig,0,0,0,pMScGrSig,(UINT)nPage,1)!=0) { err=5; goto end;}
pScGrSig=0; SetScrollPos(hwndGraphSig,SB_HORZ,pScGrSig,TRUE); return 0;
end: SetRangePageScrollBar(hwndGraphSig,0,0,0,0,0,1); SetScrollPos(hwndGraphSig,SB_HORZ,pScGrSig,TRUE); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Пролистывание окна графика сигнала.

BYTE clMain::HScrollGrSig(WPARAM wParam)
{
int p;

if(hwndGraphSig==NULL) return 1;
p=pScGrSig; if(ScrollFun32(hwndGraphSig,(int)LOWORD(wParam),0,0,&p,(int)VelScrlPos,(int)AccScrlPos)!=0) return 2;
if(p==pScGrSig) return 3; pScGrSig=p; SetScrollPos(hwndGraphSig,SB_HORZ,pScGrSig,TRUE);
UpdateWindow_(hwndGraphSig); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание дочернего окна графика спектра.

BYTE clMain::CreateWinGraphSpectr(void)
{
int dx,dy; DWORD Style;

if(hwnd==NULL) return 1; if(hInst==NULL) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3;
dx=(int)(rc.right-rc.left);
dy=(int)(rc.bottom-rc.top);
Style=WS_CHILDWINDOW|WS_CAPTION|WS_VISIBLE|WS_CLIPSIBLINGS|WS_HSCROLL;
hwndGraphSpectr=CreateWindow(ClassNameGraphSpectr,NameWinGraphSpectr,Style,(int)rc.left,(int)rc.top,dx,dy,
hwnd,(HMENU)idMain_GrSpectr,hInst,NULL); if(hwndGraphSpectr==NULL) { ErrMessage(); return 4;}
SetScrollGrSpectr(); // Установка параметров прокрутки окна графика спектра.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при перемещении курсора мыши в окне графика спектра.

BYTE clMain::OnMouseMoveGraphSpectr(LPARAM lParam)
{
BYTE err; int xPos,yPos,dy; float v;

if(hwndGraphSpectr==NULL) return 1; if(GetClientRect(hwndGraphSpectr,&rc)==FALSE) return 2;
dy=(int)(rc.bottom-rc.top); if(dy<=0) return 3;
xPos=LOWORD(lParam);
yPos=HIWORD(lParam);

err=0;
if(Snd.IsOK()!=0) { err=4; goto err;}
if(AmpSpect<=0.0F) { err=5; goto err;}
if(SpectrAmp.ln==0) { err=6; goto err;}

v=(float)(xPos+(int)pScGrSp)/((float)SpectrAmp.ln*(float)Snd.dt)*0.5F;
SetFlEdt(hDlg,IDC_COORDFREQ,v,FormFreq); flFr=1;

v=AmpSpect*(float)(dy-yPos)/(float)dy;
SetFlEdt(hDlg,IDC_COORDAMPL,v,FormAmpNormSig); flAm=1;

return 0;

err: 
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDFREQ,"");  flFr=0;
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDAMPL,"");  flAm=0;
return err; 
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении размеров окна графика спектра.

void clMain::OnChSizeWinGraphSpectr(void)
{
SetScrollGrSpectr(); // Установка параметров прокрутки окна графика спектра.
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров прокрутки окна графика спектра.

BYTE clMain::SetScrollGrSpectr(void)
{
BYTE err; USHRT nPage; int dx,d;

if(hwndGraphSpectr==NULL) return 1; err=0;
if(SpectrAmp.ln==0) { err=2; goto end;}
if(GetClientRect(hwndGraphSpectr,&rc)==FALSE) { err=3; goto end;}
dx=(int)(rc.right-rc.left); if(dx<=0) { err=4; goto end;}
d=(int)SpectrAmp.ln-dx; if(d>SHRT_MAX) { err=5; goto end;}
if(d<=0) pMScGrSp=0; else pMScGrSp=d;
if(pMScGrSp!=0) nPage=GetUSHRT_Test((float)dx/(float)(pMScGrSp+(int)dx)*(float)pMScGrSp); else nPage=0;
if(SetRangePageScrollBar(hwndGraphSpectr,0,0,0,pMScGrSp,(UINT)nPage,1)!=0) { err=6; goto end;}
pScGrSp=0; SetScrollPos(hwndGraphSpectr,SB_HORZ,pScGrSp,TRUE); return 0;
end: SetRangePageScrollBar(hwndGraphSpectr,0,0,0,0,0,1);
pScDiagV=0; SetScrollPos(hwndGraphSpectr,SB_HORZ,pScGrSp,TRUE); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Пролистывание окна графика спектра.

BYTE clMain::HScrollGrSpectr(WPARAM wParam)
{
int p;

if(hwndGraphSpectr==NULL) return 1;
p=pScGrSp; if(ScrollFunS(wParam,&p,0,pMScGrSp,VelScrlPos,AccScrlPos)!=0) return 2; if(p==pScGrSp) return 3;
pScGrSp=p; SetScrollPos(hwndGraphSpectr,SB_HORZ,pScGrSp,TRUE); UpdateWindow_(hwndGraphSpectr); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для диаграммы и других результатов.

void clMain::FreeDiagRes(void)
{
SpectrAmp.Free_St(); ResNNW.Free();
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт диаграммы.

BYTE clMain::ComputeDiag(void)
{
BYTE ComputeSpDiag(float *Snd,UINT nSnd,double dt,clSpDiag *Diag,strParSpProc *Param,PNT_DATA Pnt,
  pFunShowProgr FSP,BYTE *flStop); // Расчёт спектральной диаграммы.
void ShowProgrMain(PNT_DATA Pnt,UINT i,UINT n); // Полоса прогресса в главном окне.

BYTE be;

SpectrAmp.Free_St(); // Освобождение памяти для диаграммы.
if(Snd.IsOK()!=0) { Message(IDS_Mess_FileNotOpen,MB_ST); return 1;}
if(ParSpectr.IsOK()!=0) return 2;
be=ComputeSpDiag(Snd.Snd,Snd.ln,Snd.dt,&SpectrAmp,&ParSpectr,(PNT_DATA)this,ShowProgrMain,&flStopProc); // Расчёт спектральной диаграммы.
if(be==messRet) return messRet; if(be!=0) return 3;
ShowProgr(0,0); // Изображение процента выполнения работы.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Построение спектральной диаграммы.

BYTE clMain::DrawDiag(void)
{
BYTE *pvBits,R,G,B,nC,Res,k,flRes; USHRT i,j; int dy; UINT dxB,l0,l; DWORD Col; float v; struct strPal *pPal;
clArrFloat *pArrFr;

if(BmpDiag==NULL) return 1; BmpDiag->Free(); if(SpectrAmp.IsOK_St()!=0) return 2;
if(SpectrAmp.ln+szWinResDiag>USHRT_MAX) return 3; if(SpectrAmp.nArr>USHRT_MAX) return 4;
GetFlEdt(hDlg,IDC_AMPL_DIAG,&(MW->AmpNorm)); if(AmpNorm<=0.0F) return 5;
flRes=0; if(ResNNW.IsOK()==0) { if(ResNNW.ln!=SpectrAmp.nArr) return 6; flRes=1;}
if(BmpDiag->Init((int)SpectrAmp.nArr,(int)(SpectrAmp.ln+szWinResDiag),typBmp_24,NULL,0,NULL)!=0) return 6;
if(BmpDiag->IsOKB()!=0) return 7;
pvBits=BmpDiag->pvBits; if(pvBits==NULL) return 8;

dy=BmpDiag->dy; dxB=BmpDiag->dxB;

// Рисование линии - разделителя между диаграммой и полосой результата распознавания.
Col=ColDiagLineSep; R=GetRValue(Col); G=GetGValue(Col); B=GetBValue(Col);
j=szWinResDiag-1; l0=(UINT)j*(UINT)dxB;
for(i=0;i<(USHRT)SpectrAmp.nArr;i++) { l=l0+(UINT)i*3; *(pvBits+l)=B; *(pvBits+l+1)=G; *(pvBits+l+2)=R;}

pPal=&PalDiag; // Выбор палитры.

// Цикл рисования по времени.
for(i=0;i<(USHRT)SpectrAmp.nArr;i++) { l0=(UINT)i*3;
// Рисование спектральной диаграммы.
pArrFr=SpectrAmp.Get(i); if(pArrFr==NULL) return 9; if(pArrFr->IsOK()!=0) return 10;
if(pArrFr->ln!=SpectrAmp.ln) return 11;
for(j=0;j<(USHRT)SpectrAmp.ln;j++) { v=pArrFr->Arr[j]/AmpNorm;
if(v>=1.0F) nC=nColSmoothPal-1; else if(v<=0.0F) nC=0; else nC=(BYTE)((float)(nColSmoothPal-1)*v);
l=(UINT)(j+szWinResDiag)*(UINT)dxB+l0; for(k=0;k<3;k++) *(pvBits+l+(UINT)k)=pPal->MasRGB[nC][2-k];}
// Рисование результата распознавания.
Col=ColDiagLineSymbBkg; if(flRes==0) goto drRes; Res=ResNNW.Arr[i]; if(Res==UCHAR_MAX) goto drRes;
if(Res<nVoicesVowel) { if(typShowLineDiag==typNNW_Vowel) Col=ColVoicesVowel[Res]; else Col=ColDiagLineSndNoShow;}
else { Res-=nVoicesVowel;
if(Res<nVoicesCons) { if(typShowLineDiag==typNNW_Cons) Col=ColVoicesCons[Res]; else Col=ColDiagLineSndNoShow;}}
drRes: R=GetRValue(Col); G=GetGValue(Col); B=GetBValue(Col);
for(j=0;j<szWinResDiag-1;j++) { l=(UINT)j*(UINT)dxB+l0; *(pvBits+l)=B; *(pvBits+l+1)=G; *(pvBits+l+2)=R;}
ShowProgr((UINT)i+1,SpectrAmp.nArr);}
ShowProgr(0,0); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование в окне спектральной диаграммы.

BYTE clMain::OnPaintDiag(HDC hdc)
{
int dxW,dyW,dx,dy,p,pD;

if(hdc==NULL) return 1; if(hwndDiag==NULL) return 2;
if(GetClientRect(hwndDiag,&rc)==FALSE) return 3;
dxW=(int)(rc.right-rc.left); if(dxW<=0) return 4;
dyW=(int)(rc.bottom-rc.top); if(dyW<=0) return 5;
if(BmpDiag==NULL) return 6; if(BmpDiag->IsOKB()!=0) return 7;
if(pMScDiagH==0) dx=BmpDiag->dx; else dx=dxW;
if(pMScDiagV==0) { dy=BmpDiag->dy; p=0; pD=dyW-dy;} else { dy=dyW; p=pMScDiagV-pScDiagV; p=BmpDiag->dy-dy-p; pD=0;}
if(BmpDiag->Image(hdc,0,pD,dxW,dyW,pScDiagH,p,dx,dy,0)!=0) return 8; // Вывод изображения.

// Закрашивание фона сверху в случае, если вся область не закрашивается диаграммой.
if(dy<dyW) {
rc.left=0; rc.right=dxW; rc.top=0; rc.bottom=dyW-dy;
ImgRectC(hdc,&rc,ColBkgDiag,ColBkgDiag,1);}

// Закрашивание фона справа в случае, если вся область не закрашивается диаграммой.
if(dx<dxW) {
rc.left=dx; rc.right=dxW; rc.top=0; rc.bottom=dyW;
ImgRectC(hdc,&rc,ColBkgDiag,ColBkgDiag,1);}

// Рисование курсоров в окне спектральной диаграммы.
DrawCursorsDiag(hdc);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование курсоров в окне спектральной диаграммы.

BYTE clMain::DrawCursorsDiag(HDC hdc)
{
int dxW,dyW,x; HPEN hPen,hPenP; double st_Time;

if(hdc==NULL) return 1; st_Time=SpectrAmp.stArr; if(st_Time<=0.) return 2;
if(hwndDiag==NULL) return 3; if(GetClientRect(hwndDiag,&rc)==FALSE) return 4;
dxW=(int)(rc.right-rc.left); if(dxW<=0) return 5;
dyW=(int)(rc.bottom-rc.top); if(dyW<=0) return 6;

// Рисование курсора на выбранном времени.
x=CoordTimeDiag-pScDiagH;
if(x>=0&&x<dxW) { hPen=hPenP=NULL;
CrSelPen(hdc,&hPen,&hPenP,1,ColCursorDiag);
MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dyW);
UnSelDelPen(hdc,&hPen,&hPenP);}

// Рисование маркеров звука в базе данных.
if(DlgDBFNNW.selDBS!=NULL&&DlgDBFNNW.flLoadFile!=0) {
hPen=hPenP=NULL;
x=GetIntTest((double)DlgDBFNNW.selDBS->tI/st_Time)-pScDiagH;
if(x>=0&&x<dxW) {
CrSelPen(hdc,&hPen,&hPenP,1,ColCursorDiagLimDB_Ini);
MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dyW);
UnSelDelPen(hdc,&hPen,&hPenP);}
x=GetIntTest((double)DlgDBFNNW.selDBS->tF/st_Time)-pScDiagH;
if(x>=0&&x<dxW) {
CrSelPen(hdc,&hPen,&hPenP,1,ColCursorDiagLimDB_Fin);
MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dyW);
UnSelDelPen(hdc,&hPen,&hPenP);}
}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Закрашивание окна спектральной диаграммы.

BYTE clMain::OnPaintDiagDef(HDC hdc)
{
if(hdc==NULL) return 1; if(hwndDiag==NULL) return 2;
if(GetClientRect(hwndDiag,&rc)==FALSE) return 3;
ImgRectC(hdc,&rc,ColBkgDiag,ColBkgDiag,1); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Перерисовка окна спектральной диаграммы.

void clMain::UpdateWinDiag(void)
{
UpdateWindow_(hwndDiag);
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт и построение диаграммы.

void clMain::ComputeDrawDiag(void)
{
if(flProc!=0) { SoundBlock(); return;} if(flCaptSound!=0||flPlaySound!=0) { SoundBlock(); return;}
FreeDiagRes();  // Освобождение памяти для диаграммы и других результатов.
CoordTimeDiag=CoordTimeSig=0; flCurGrSig=0; flBlk|=1<<numBlkMain_Proc; flProc=1; flStopProc=0; SetBtnMenuProc();
ComputeDiag(); // Расчёт диаграммы.
ComputeSpLines(); // Нахождение спектральных линий для всего файла.
RecognNNW_All(); // Распознавание методом нейронных сетей для всего файла.
DrawDiag(); // Построение спектральной диаграммы.
OutTextRecogn_All(); // Вывод текста распознавания после обработки в окно текста.
OnDrawDiag(); // Действия после изменения диаграммы.
UpdateWindow_(hwndGraphSpectr); // Перерисовка графика спектра.
flBlk&=~(1<<numBlkMain_Proc); flProc=0; flStopProc=1; SetBtnMenuProc();
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку обработки и выделение пункта меню.

void clMain::SetBtnMenuProc(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flProc==0) id=IDS_Btn_Processing; else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_PROCESSING,cp);
SetStMenuItem_(hMenu,IDM_COMPUTE,1,flProc);
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение спектральных линий для всего файла.

BYTE clMain::ComputeSpLines(void)
{
BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nPCons,BYTE nSpLines,strSpectrLine *SpLines,
  strParGetPeaks *PGP,BYTE *typNet,BYTE *flErr); // Нахождение относительных амплитуд и частот спектральных линий.

BYTE nPeaks,k,typNet,be,ber; UINT i; float dFr; clArrFloat *pArrFr; struct strSpLines *pLines;
struct strSpectrLine *pSpL;

SpLines.Free(); if(SpectrAmp.IsOK_St()!=0) return 1; ber=0;
if(SpLines.Create(SpectrAmp.nArr)!=0) { ber=2; goto end;}
dFr=(float)SpectrAmp.stLn;

for(i=0;i<SpectrAmp.nArr;i++) {
pArrFr=SpectrAmp.Get(i); if(pArrFr==NULL) { ber=3; goto end;} if(pArrFr->IsOK()!=0) { ber=4; goto end;}
if(pArrFr->ln!=SpectrAmp.ln) { ber=5; goto end;} if(pArrFr->ln>USHRT_MAX) { ber=6; goto end;}
pLines=SpLines.Get(i); if(pLines==NULL) { ber=7; goto end;}
if(pLines->Create(nPeaksMax)!=0) { ber=8; goto end;}
pSpL=pLines->pSpL; if(pSpL==NULL) { ber=9; goto end;}
typNet=UCHAR_MAX;
be=FindPeaks(pArrFr->ln,pArrFr->Arr,dFr,nPeaksCons,nPeaksMax,pSpL,&ParGetPeaks,&typNet,NULL); // Нахождение спектральных линий.
if(be!=0||typNet==typNNW_Cons) { if(be!=0) nPeaks=0; else nPeaks=nPeaksCons;
for(k=nPeaks;k<nPeaksMax;k++) (pSpL+k)->Zero();}
ShowProgr(i+1,SpectrAmp.nArr); // Изображение процента выполнения работы.
if(flStopProc!=0) { ber=messRet; goto end;}}

end: ShowProgr(0,0); if(ber!=0) SpLines.Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Распознавание методом нейронных сетей для всего файла.

BYTE clMain::RecognNNW_All(void)
{
BYTE RecognSoundNNW_VC(float *Spectr,USHRT nSpectr,float dFr,strNNW *NNW_Vowel,strNNW *NNW_Cons,pFunDecSnd DecSnd,
  PNT_DATA Pnt,BYTE *numSnd,BYTE *typSnd,BYTE flOut); // Распознавание звуков методом нейронных сетей.
BYTE RecognSoundNNW_Sp(float *Spectr,USHRT nSpectr,float dFr,strNNW *NNW_Sp,pFunDecSnd DecSnd,PNT_DATA Pnt,
  BYTE *numSnd,BYTE *typSnd); // Распознавание звуков методом нейронных сетей.
BYTE CopyNNW(strNNW *Dst,strNNW *Src); // Копирование структуры нейронной сети.
BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // Функция принятия решения при распознавании звука - простейший пороговый классификатор, основанный на текущих значениях.
BYTE DecSnd_Store(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // Функция принятия решения при распознавании звука - метод с накоплением результата распознавания.

BYTE typSnd,numSnd,num,ber; UINT i; float dFr; clArrFloat *pArrFr;
struct strNNW *NNW_V,*NNW_C,*NNW_S,*pNNW_V,*pNNW_C,*pNNW_S; pFunDecSnd pFunDecSnd;

ResNNW.Free(); if(SpectrAmp.IsOK_St()!=0) return 1;
if(methDecSound==methDecSnd_Store) { if(AnSound.Init(ParSpectr.Time_Step,1)!=0) return 2;} // Инициализация класса для обработки потока символов звуков.

NNW_V=NNW_C=NNW_S=NULL; pNNW_V=pNNW_C=pNNW_S=NULL; ber=0;
if(ResNNW.Alloc(SpectrAmp.nArr)!=0) { ber=3; goto end;}
dFr=(float)SpectrAmp.stLn;

switch(typUseNNWRec) { default: ber=4; goto end;
// Две раздельные сети для гласных и согласных.
case typNNR_VC:
NNW_V=new strNNW; if(NNW_V==NULL) { ber=5; goto end;}
NNW_C=new strNNW; if(NNW_C==NULL) { ber=6; goto end;}
if(CopyNNW(NNW_V,&NNW_Vowel)==0) pNNW_V=NNW_V;
if(CopyNNW(NNW_C,&NNW_Cons)==0) pNNW_C=NNW_C;
if(pNNW_V==NULL&&pNNW_C==NULL) { ber=messRet; goto end;}
break;

// Одну многослойную сеть прямого распространения для всего спектра.
case typNNR_Sp:
NNW_S=new strNNW; if(NNW_S==NULL) { ber=7; goto end;}
if(CopyNNW(NNW_S,&NNW_Spectr)==0) pNNW_S=NNW_S; if(pNNW_S==NULL) { ber=messRet; goto end;}
break;

// Сеть Кохонена.
case typNNR_Co: //xxx aaa
i=0; if(i==0) { ber=messRet; goto end;}
break;
}

for(i=0;i<SpectrAmp.nArr;i++) {
pArrFr=SpectrAmp.Get(i); if(pArrFr==NULL) { ber=6; goto end;} if(pArrFr->IsOK()!=0) { ber=7; goto end;}
if(pArrFr->ln!=SpectrAmp.ln) { ber=8; goto end;} if(pArrFr->ln>USHRT_MAX) { ber=9; goto end;}
typSnd=numSnd=UCHAR_MAX;
if(methDecSound==methDecSnd_Store) pFunDecSnd=DecSnd_Store; else pFunDecSnd=DecSnd_Instant; // Установка способа принятия решения по звуку.

if(typUseNNWRec==typNNR_VC) {
// Две раздельные сети для гласных и согласных.
RecognSoundNNW_VC(pArrFr->Arr,(USHRT)pArrFr->ln,dFr,pNNW_V,pNNW_C,pFunDecSnd,NULL,&numSnd,&typSnd,0);}
else if(typUseNNWRec==typNNR_Sp) {
// Одну многослойную сеть прямого распространения для всего спектра.
RecognSoundNNW_Sp(pArrFr->Arr,(USHRT)pArrFr->ln,dFr,pNNW_S,pFunDecSnd,NULL,&numSnd,&typSnd);}
else { ber=messRet; goto end;}

if(numSnd==UCHAR_MAX||typSnd>=nTypesNNW) num=UCHAR_MAX;
else { if(typSnd==typNNW_Vowel) { if(numSnd>=nVoicesVowel) { ber=10; goto end;} num=numSnd;} // Для гласных и сонорных звуков.
else { if(numSnd>=nVoicesCons) { ber=11; goto end;} num=nVoicesVowel+numSnd;} // Для согласных взрывных и шипящих звуков.
}
ResNNW.Arr[i]=num;
ShowProgr(i+1,SpectrAmp.nArr); // Изображение процента выполнения работы.
if(flStopProc!=0) { ber=messRet; goto end;}}

end: SAFE_DELETE(NNW_V); SAFE_DELETE(NNW_C); SAFE_DELETE(NNW_S);
ShowProgr(0,0); if(ber!=0) ResNNW.Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Вывод текста распознавания после обработки в окно текста.

BYTE clMain::OutTextRecogn_All(void)
{
BYTE GetSymbSound(BYTE num,BYTE typ,char *pSymb); // Получение символа звука.

BYTE numSnd,typSnd,Res,ber; UINT i; char Symb,*Text;

if(ResNNW.IsOK()!=0) return 1;
Text=NULL; ber=0;
if(AllocString(&Text,(size_t)ResNNW.ln)!=0) { ber=2; goto end;}
for(i=0;i<ResNNW.ln;i++) {
Res=ResNNW.Arr[i]; if(Res==UCHAR_MAX) { Symb=' '; goto outRes;}
numSnd=typSnd=UCHAR_MAX;
if(Res<nVoicesVowel) { typSnd=typNNW_Vowel; numSnd=Res;}
else { Res-=nVoicesVowel; if(Res<nVoicesCons) { typSnd=typNNW_Cons; numSnd=Res;}}
if(GetSymbSound(numSnd,typSnd,&Symb)!=0) Symb=' ';
outRes: Text[i]=Symb;}
Text[ResNNW.ln]='\0'; SetWinText(Text); // Изображение текста в окне.
end: FreeString(&Text); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Действия после изменения диаграммы.

void clMain::OnDrawDiag(void)
{
SetScrollDiagH(); // Установка параметров прокрутки окна диаграммы по горизонтали.
SetScrollDiagV(); // Установка параметров прокрутки окна диаграммы по вертикали.
SetScrollGrSpectr(); // Установка параметров прокрутки окна графика спектра.
UpdateWinDiag(); // Перерисовка окна диаграммы.
}

//-----------------------------------------------------------------------------------------------------------
// Рисование в окне графика сигнала.

BYTE clMain::OnPaintGraphSig(HDC hdc)
{
BYTE fl; int dx,dy,i,y,j,y0; DWORD Col; float coe; HPEN hPen,hPenP;

GetFlEdt(hDlg,IDC_AMPL_SIG,&(MW->AmpSig));

if(hdc==NULL) return 1; if(hwndGraphSig==NULL) return 2; 
if(GetClientRect(hwndGraphSig,&rc)==FALSE) return 3;
dx=(int)(rc.right-rc.left); if(dx<=0) return 4;
dy=(int)(rc.bottom-rc.top); if(dy<=0) return 5;
hPen=hPenP=NULL; fl=0; if(AmpSig<=0.) return 6; 
if(Snd.IsOK()!=0) return 7;
// Рисование фона окна.
Col=ColBkgWinGraphSign; ImgRectC(hdc,&rc,Col,Col,1);

// Рисование графика сигнала.
CrSelPen(hdc,&hPen,&hPenP,1,ColGraphSign);
y0=dy/2;
MoveToEx(hdc,0,y0,NULL); LineTo(hdc,dx,y0);
coe=(float)dy*0.5F/AmpSig;
for(i=0;i<dx;i++) { j=i+pScGrSig; if(j<0) continue; if(j>=(int)Snd.ln) break;
y=dy-GetIntTest(Snd.Snd[j]*coe+(float)y0);
if(fl==0) { MoveToEx(hdc,i,y,NULL); fl=1;} else LineTo(hdc,i,y);} 
UnSelDelPen(hdc,&hPen,&hPenP);

// Рисование курсора в окне сигнала.
DrawCursorGraphSig(hdc);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование курсора в окне сигнала.

BYTE clMain::DrawCursorGraphSig(HDC hdc)
{
int dx,dy,x; HPEN hPen,hPenP;

if(hdc==NULL) return 1; if(hwndGraphSig==NULL) return 2; if(GetClientRect(hwndGraphSig,&rc)==FALSE) return 3;
dx=(int)(rc.right-rc.left); if(dx<=0) return 4;
dy=(int)(rc.bottom-rc.top); if(dy<=0) return 5;

// Рисование курсора на выбранном времени.
x=CoordTimeSig-pScGrSig;
if(x>=0&&x<dx) { hPen=hPenP=NULL;
CrSelPen(hdc,&hPen,&hPenP,1,ColCursorGraphSign);
MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dy);
UnSelDelPen(hdc,&hPen,&hPenP);
flCurGrSig=1;} else flCurGrSig=0;

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Закрашивание окна графика сигнала.

BYTE clMain::OnPaintGraphSigDef(HDC hdc)
{
DWORD Col;

if(hdc==NULL) return 1; if(hwndGraphSig==NULL) return 2;
if(GetClientRect(hwndGraphSig,&rc)==FALSE) return 3;
Col=ColBkgWinGraphSign; ImgRectC(hdc,&rc,Col,Col,1); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование в окне графика спектра.

BYTE clMain::OnPaintGraphSpectr(HDC hdc)
{
BYTE fl; int dx,dy,i,j,y; DWORD Col; float coe,v; HPEN hPen,hPenP; clArrFloat *pArrFr;

if(hdc==NULL) return 1; if(hwndGraphSpectr==NULL) return 2; 
if(GetClientRect(hwndGraphSpectr,&rc)==FALSE) return 3;
dx=(int)(rc.right-rc.left); if(dx<=1) return 4;
dy=(int)(rc.bottom-rc.top); if(dy<=1) return 5;
hPen=hPenP=NULL;
Col=ColBkgWinGraphSpectr; ImgRectC(hdc,&rc,Col,Col,1);

// Рисование линии Y=0;
CrSelPen(hdc,&hPen,&hPenP,1,COL_RED);
y=dy-1; MoveToEx(hdc,0,y,NULL); LineTo(hdc,dx,y);
UnSelDelPen(hdc,&hPen,&hPenP);

// Рисование графика и пиков.
if(AmpSpect<=0.) return 6; coe=(float)dy/AmpSpect;

// Выбор выводимого графика.
if(SpectrAmp.IsOK_St()!=0) return 7;
if(CoordTimeDiag<0||CoordTimeDiag>=(int)SpectrAmp.nArr) return 8;
pArrFr=SpectrAmp.Get((UINT)CoordTimeDiag); if(pArrFr==NULL) return 9; if(pArrFr->IsOK()!=0) return 10;
if(pArrFr->ln!=SpectrAmp.ln) return 11;

// Рисование графика.
CrSelPen(hdc,&hPen,&hPenP,1,ColGraphSpectr);
fl=0;
for(i=0;i<dx;i++) { j=pScGrSp+i; if(j<0) continue; if(j>=(int)SpectrAmp.ln) break; v=pArrFr->Arr[j];
y=dy-1-GetIntTest(v*coe);
if(fl==0) { MoveToEx(hdc,i,y,NULL); fl=1;} else LineTo(hdc,i,y);}
UnSelDelPen(hdc,&hPen,&hPenP);

// Рисование спектральных линий в окне графика спектра.
DrawPeaksGraphSpectr(hdc);

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Закрашивание окна графика спектра.

BYTE clMain::OnPaintGraphSpectrDef(HDC hdc)
{
DWORD Col;

if(hdc==NULL) return 1; if(hwndGraphSpectr==NULL) return 2;
if(GetClientRect(hwndGraphSpectr,&rc)==FALSE) return 3;
Col=ColBkgWinGraphSpectr; ImgRectC(hdc,&rc,Col,Col,1); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование спектральных линий в окне графика спектра.

BYTE clMain::DrawPeaksGraphSpectr(HDC hdc)
{
BYTE k; int dx,dy,i,y; float coe,v; HPEN hPen,hPenP; struct strSpLines *pLines; struct strSpectrLine *pSpL;

if(hdc==NULL) return 1; if(SpLines.IsOK()!=0) return 2; if(CoordTimeDiag<0) return 3;
pLines=SpLines.Get((UINT)CoordTimeDiag); if(pLines==NULL) return 4; if(pLines->IsOK()!=0) return 5;
if(hwndGraphSpectr==NULL) return 6; if(GetClientRect(hwndGraphSpectr,&rc)==FALSE) return 7;
dx=(int)(rc.right-rc.left); if(dx<=1) return 8;
dy=(int)(rc.bottom-rc.top); if(dy<=1) return 9;
if(AmpSpect<=0.) return 10; coe=(float)dy/AmpSpect;

hPen=hPenP=NULL;
CrSelPen(hdc,&hPen,&hPenP,1,ColPeaksGrSpectr);
for(k=0;k<pLines->nSpL;k++) { pSpL=pLines->Get(k); if(pSpL==NULL) continue;
v=pSpL->AmpRel; if(v<(float)SmCnst10_d) continue;
v=pSpL->Amp; y=dy-1-GetIntTest(v*coe);
v=pSpL->Freq; i=GetIntTest(v); i-=pScGrSp; if(i<0||i>=dx) continue;
MoveToEx(hdc,i,dy-1,NULL); LineTo(hdc,i,y);}

UnSelDelPen(hdc,&hPen,&hPenP); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Распознавание звуков методом нейронных сетей.

BYTE clMain::RecognNNW(void)
{
BYTE RecognSoundNNW_VC(float *Spectr,USHRT nSpectr,float dFr,strNNW *NNW_Vowel,strNNW *NNW_Cons,pFunDecSnd DecSnd,
  PNT_DATA Pnt,BYTE *numSnd,BYTE *typSnd,BYTE flOut); // Распознавание звуков методом нейронных сетей.
BYTE RecognSoundNNW_Sp(float *Spectr,USHRT nSpectr,float dFr,strNNW *NNW_Sp,pFunDecSnd DecSnd,PNT_DATA Pnt,
  BYTE *numSnd,BYTE *typSnd); // Распознавание звуков методом нейронных сетей.
BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // Функция принятия решения при распознавании звука - простейший пороговый классификатор, основанный на текущих значениях.
BYTE DecSnd_Store(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // Функция принятия решения при распознавании звука - метод с накоплением результата распознавания.
BYTE GetSymbSound(BYTE num,BYTE typ,char *pSymb); // Получение символа звука.

BYTE numSnd,typSnd; float dFr; char Txt[2]; clArrFloat *pArrFr;

if(DlgDBFNNW.IsDoTrain()!=0) { SoundBlock(); return messRet;}
if(SpectrAmp.IsOK_St()!=0) return 1; if(CoordTimeDiag<0||CoordTimeDiag>=(int)SpectrAmp.nArr) return 2;
pArrFr=SpectrAmp.Get((UINT)CoordTimeDiag); if(pArrFr==NULL) return 3; if(pArrFr->IsOK()!=0) return 4;
if(pArrFr->ln!=SpectrAmp.ln) return 5; if(pArrFr->ln>USHRT_MAX) return 6;
typSnd=numSnd=UCHAR_MAX;
dFr=(float)SpectrAmp.stLn;

if(typUseNNWRec==typNNR_VC) {
// Две раздельные сети для гласных и согласных.
if(RecognSoundNNW_VC(pArrFr->Arr,(USHRT)pArrFr->ln,dFr,&NNW_Vowel,&NNW_Cons,DecSnd_Instant,NULL,
&numSnd,&typSnd,1)!=0) return 7;}
else if(typUseNNWRec==typNNR_Sp) {
// Одну многослойную сеть прямого распространения для всего спектра.
if(RecognSoundNNW_Sp(pArrFr->Arr,(USHRT)pArrFr->ln,dFr,&NNW_Spectr,DecSnd_Instant,NULL,&numSnd,&typSnd)!=0) return 8;}
else return messRet;

if(WinViewNNW.hwnd!=NULL) WinViewNNW.DrawNet(); // Перерисовка изображения сети.
Txt[1]='\0'; if(GetSymbSound(numSnd,typSnd,Txt)!=0) Txt[0]='-'; // Получение символа звука.
if(WinText.hwnd!=NULL) WinText.SetText(Txt); // Вывод символа звука в окно текста.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка и распознавание в реальном времени.

BYTE clMain::ProcRecRealTime(void)
{
BYTE GetN_(USHRT nPoints,USHRT *Np,USHRT NpM,BYTE *Mp); // Даёт минимальное число 'Np', являющееся 2 в целой степени, которое превышает 'nPoints'.
BYTE GetWeightWinSTFT(BYTE meth,float *Weight,USHRT nP,float Wid); // Нахождение весовой функции окна при спектральном разложении.
BYTE FastFT(complex *A,complex *B,BYTE M,SCHAR dir,BYTE prcMess); // Быстрое преобразование Фурье.
BYTE RecognSoundNNW_VC(float *Spectr,USHRT nSpectr,float dFr,strNNW *NNW_Vowel,strNNW *NNW_Cons,pFunDecSnd DecSnd,
  PNT_DATA Pnt,BYTE *numSnd,BYTE *typSnd,BYTE flOut); // Распознавание звуков методом нейронных сетей.
BYTE RecognSoundNNW_Sp(float *Spectr,USHRT nSpectr,float dFr,strNNW *NNW_Sp,pFunDecSnd DecSnd,PNT_DATA Pnt,
  BYTE *numSnd,BYTE *typSnd); // Распознавание звуков методом нейронных сетей.
BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // Функция принятия решения при распознавании звука - простейший пороговый классификатор, основанный на текущих значениях.
BYTE DecSnd_Store(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd); // Функция принятия решения при распознавании звука - метод с накоплением результата распознавания.
BYTE GetSymbSound(BYTE num,BYTE typ,char *pSymb); // Получение символа звука.

BYTE M,numSnd,typSnd,flStart,ber; SHRT iv,*Sound; USHRT i,n,nWinWid,nPoints,nPh,nStep,nTI; UINT k,nTime,ui;
float v,*Weight,*Spectr,dFr; double dt; complex *A,*B; char Symb; pFunDecSnd pFunDecSnd;

if(SndCapData==NULL) return 1; if(SndCapData->IsOK()!=0) return 2; dt=1./(double)SndCapData->nSPS;
if(RecNNW.IsOK()!=0) return 3; if(ParSpectr.IsOK()!=0) return 4;
nWinWid=GetUSHRT_Test((double)ParSpectr.Time_Width/dt); if(nWinWid<nWinWid_Min) nWinWid=nWinWid_Min;
if(GetN_(nWinWid,&nPoints,0,&M)!=0) return 5; nPh=nPoints/2;
if(TimeRecBuf<(UINT)nPoints) return messRet;
flStart=0; if(TimeRecProc<nPh) { TimeRecProc=nPh; flStart=1;}
if(TimeRecBuf-nPh<TimeRecProc) return messRet;
nStep=GetUSHRT_Test((double)ParSpectr.Time_Step/dt); if(nStep==0) nStep=1;
ui=TimeRecBuf-nPh-TimeRecProc; nTime=(UINT)(ui/nStep);
if(flStart==0) { nTI=1; nTime++;} else nTI=0;
dFr=(float)(1./(dt*(double)nPoints));

A=B=NULL; Sound=NULL; Weight=Spectr=NULL; ber=0;
if(AllocSHRT(&Sound,(size_t)nPoints)!=0) { ber=6; goto end;}
if(AllocFloat(&Spectr,(size_t)nPh)!=0) { ber=7; goto end;}
if(AllocComplex(&A,(size_t)nPoints)!=0) { ber=8; goto end;}
if(AllocComplex(&B,(size_t)nPoints)!=0) { ber=9; goto end;}
if(AllocFloat(&Weight,(size_t)nPh)!=0) { ber=10; goto end;}

// Нахождение весовой функции окна.
if(ParSpectr.methSpFour!=methSpFour_NoWin) { v=ParSpectr.Time_Width*0.5F/(float)dt;
if(GetWeightWinSTFT(ParSpectr.methSpFour,Weight,nPh,v)!=0) { ber=11; goto end;}}

// Цикл по временным точкам.
for(i=nTI;i<nTime;i++) { k=TimeRecProc+(UINT)i*(UINT)nStep-nPh; if(k>TimeRecBuf) { ber=12; goto end;}
k=TimeRecBuf-k; if(SndCapData->GetCycle((UINT)nPoints,Sound,k)!=0) { ber=13; goto end;}
for(n=0;n<nPoints;n++) { iv=(SHRT)((int)n-(int)nPh); if(iv<0) iv=-iv;
v=(float)Sound[n]; if(ParSpectr.methSpFour!=methSpFour_NoWin) { if(iv<nPh) v*=Weight[iv]; else v=0.0F;}
A[n]=complex((double)v,0.);}

if(FastFT(A,B,M,1,1)!=0) { ber=14; goto end;}

for(n=0;n<nPh;n++) Spectr[n]=(float)abs(B[n]);

// Распознавание методом нейронных сетей.
if(methDecSound==methDecSnd_Store) pFunDecSnd=DecSnd_Store; else pFunDecSnd=DecSnd_Instant; // Установка способа принятия решения по звуку.
typSnd=numSnd=UCHAR_MAX;

if(typUseNNWRec==typNNR_VC) {
// Две раздельные сети для гласных и согласных.
if(RecognSoundNNW_VC(Spectr,nPh,dFr,&NNW_Vowel,&NNW_Cons,pFunDecSnd,(PNT_DATA)this,
&numSnd,&typSnd,0)!=0) { ber=15; goto end;}}
else if(typUseNNWRec==typNNR_Sp) {
// Одну многослойную сеть прямого распространения для всего спектра.
if(RecognSoundNNW_Sp(Spectr,nPh,dFr,&NNW_Spectr,pFunDecSnd,(PNT_DATA)this,&numSnd,&typSnd)!=0) { ber=16; goto end;}}
else return messRet;

if(numSnd==UCHAR_MAX||typSnd>=nTypesNNW) Symb='-';
else { if(GetSymbSound(numSnd,typSnd,&Symb)!=0) Symb='-';} // Получение символа звука.

if(nRecChar>=RecNNW.sz) { ber=17; goto end;}
RecNNW.String[nRecChar]=Symb; nRecChar++;
if(nRecChar==RecNNW.sz) { RecNNW.String[nRecChar]='\0'; nRecChar=0;
if(WinText.hwnd!=NULL) WinText.SetText(RecNNW.String);}
}
TimeRecProc+=(UINT)(nTime-1)*(UINT)nStep;

end: FreeComplex(&A); FreeComplex(&B); FreeSHRT(&Sound); FreeFloat(&Spectr); FreeFloat(&Weight); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Получение номера звука при распознавании потока речи.

BYTE clMain::GetNumSndRecogn(strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd)
{
BYTE GetOutArr(strLay *pLay,float *pArr,BYTE nArr); // Нахождение массива выходов нейронных элементов.

BYTE nArr,ber; float *pArr;

if(pLay==NULL) return 1; if(pLay->IsOK()!=0) return 2; if(typSnd==NULL) return 3; if(numSnd==NULL) return 4;
switch(typNet) { default: return 5;
case typNNW_Vowel: nArr=nVoicesVowel; break; // Для гласных и сонорных звуков.
case typNNW_Cons: nArr=nVoicesCons; break; // Для согласных взрывных и шипящих звуков.
case typNNW_Spectr: nArr=nVoicesVowel+nVoicesCons; break; // Применение нейронных сетей сразу для всего спектра.
}
if((USHRT)nArr!=pLay->n) return 6;
pArr=NULL; ber=0;
pArr=new float[nArr]; if(pArr==NULL) { ber=7; goto end;}
if(GetOutArr(pLay,pArr,nArr)!=0) { ber=8; goto end;}
if(AnSound.Step(pArr,nArr,typNet,typSnd,numSnd)!=0) { ber=9; goto end;}
end: SAFE_DELETE_ARR(pArr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение координат дочерних окон.

void clMain::FindCoordChildWin(void) 
{
USHRT dy,dySig;

GetClientRect(hDlg,&rcCntrl); GetClientRect(hwnd,&rc);
dy=(USHRT)(rc.bottom-rcCntrl.bottom); dySig=(USHRT)((float)dy*coeSzWinSig);
rcSig.left=rc.left; rcSig.right=rc.right; rcSig.top=rcCntrl.bottom; rcSig.bottom=rcSig.top+dySig;
rcDiag.left=rc.left; rcDiag.right=(long)(coeSzWinDiag*(float)rc.right); rcDiag.top=rcSig.bottom; rcDiag.bottom=rc.bottom;
rcSpect.left=rc.right-(int)((float)rc.right*(1.0F-coeSzWinDiag)); rcSpect.right=rc.right; rcSpect.top=rcDiag.top; rcSpect.bottom=rc.bottom;
}

//-----------------------------------------------------------------------------------------------------------
// Перемещение окон сигнала и диаграммы.

void clMain::MoveChWin(void)
{
BYTE i; int dx,dy; HWND hw; RECT *prc;

for(i=0;i<3;i++) {
switch(i) { default: continue;
case 0: hw=hwndDiag; prc=&rcDiag; break;
case 1: hw=hwndGraphSig; prc=&rcSig; break;
case 2: hw=hwndGraphSpectr; prc=&rcSpect; break;
}
dx=prc->right-prc->left; dy=prc->bottom-prc->top; MoveWindow(hw,prc->left,prc->top,dx,dy,TRUE);}
}

//-----------------------------------------------------------------------------------------------------------
// Перемещение дочерних окон сигнала, диаграммы и графика спектра.

void clMain::OnChSizeWin(void)
{
FindCoordChildWin(); MoveChWin();
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие звукового файла.

void clMain::CloseFileSound(void)
{
Snd.Free(); FreeString(&FileNameWAV); if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_FILE_NAME,"");
SetScrollGrSig(); // Установка параметров прокрутки окна графика сигнала.
UpdateWindow_(hwndGraphSig); // Перерисовка графика сигнала.
FreeDiagRes(); if(BmpDiag!=NULL) BmpDiag->Free(); // Удаление диаграммы.
OnDrawDiag(); // Действия после изменения диаграммы.
UpdateWindow_(hwndGraphSpectr); // Перерисовка графика спектра.
ClearWinText(); // Очистка окна текста.
if(hDlgDB!=NULL) DlgDBFNNW.SetFlagLoadFile(); // Установка флага загрузки файла.
}

//-----------------------------------------------------------------------------------------------------------
// Открытие звукового файла.

BYTE clMain::OpenFileSound(void)
{
BYTE err;

if(hDlg==NULL) return 1; strcpy(FileNameN,"");
err=FileNameQuest(hDlg,0,IDS_Filt_Sound,PathToDir,extWAV,IDS_HeaderDlg_OpenWav,FileNameN,
strL_FileName,PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 2;
CloseFileSound();
if(CompareStrCase(ExtN,extWAV)!=0) return 3; strcpy(PathToDir,PathToDirN);
if(LoadFile(PathToDirN,NULL,FileNameN)!=0) return 4; // Загрузка файла, построение графика сигнала.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение звукового файла.

BYTE clMain::SaveFileSound(void)
{
BYTE err; char *cp;

if(Snd.IsOK()!=0) return 1; if(hDlg==NULL) return 2; if(hInst==NULL) return 3;
cp="Record"; if(LoadString(hInst,IDS_NameRecord,TxtStr,strL_Txt)!=0) cp=TxtStr; strcpy(FileNameN,cp);
err=FileNameQuest(hDlg,1,IDS_Filt_Sound,PathToDir,extWAV,IDS_HeaderDlg_SaveWav,FileNameN,
strL_FileName,PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 4;
if(CompareStrCase(ExtN,extWAV)!=0) return 5; strcpy(PathToDir,PathToDirN);
if(SaveFile(PathToDirN,NULL,FileNameN)!=0) return 4; // Сохранение файла в формате "WAV".
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя на объект класса библиотеки захвата звука.

void clMain::ZeroSndCap(void)
{
SndCap=NULL; TimeRecBuf=TimeRecProc=nRecChar=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление объекта класса библиотеки захвата звука.

void clMain::FreeSndCap(void)
{
SAFE_DELETE(SndCap); flEnCaptSound=0; ChBtnCaptSound();
}

//-----------------------------------------------------------------------------------------------------------
// Создание объекта класса библиотеки захвата звука.

BYTE clMain::CreateSndCap(void)
{
void FunSndCap_CallBack(PNT_DATA Pnt,DWORD szBuf,void *pBuf); // Функции обратного вызова для записи звука.

BYTE ber;

FreeSndCap(); ber=0;
SndCap=new clLoadDLLSndCap(); if(SndCap==NULL) { ber=1; goto end;}
if(SndCap->Load(NULL,NameDLLSoundCap)!=0) { ber=2; goto end;} // Загрузка библиотеки, функций и создание объекта.
if(SndCap->Obj==NULL) { ber=3; goto end;}
SndCap->Obj->SetPntFunc((PNT_DATA)this,FunSndCap_CallBack,&flStopCaptSound); // Установка указателей.
SndCap->Obj->SetNotifySize(szNotifySndCap); // Установка размера буфера сообщений.
flEnCaptSound=1; ChBtnCaptSound(); // Установка состояния кнопки захвата звука.
end: if(ber!=0) FreeSndCap(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение при записи звука.

BYTE clMain::SaveBufSound(DWORD szBuf,void *pBuf)
{
UINT sz;

if(szBuf==0) return 1; if(pBuf==NULL) return 2; if(SndCapData==NULL) return 3; sz=szBuf/sizeof(SHRT);
// Запись звука.
if(flRegCapt==0) { if(SndCapData->Add(sz,(SHRT *)pBuf)!=0) return 4;}
// Обработка и распознавание в реальном времени без записи.
else { if(SndCapData->AddCycle(sz,(SHRT *)pBuf)!=0) return 5;
TimeRecBuf+=sz; if(ProcRecRealTime()!=0) return 6;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Включение записи звука.

BYTE clMain::StartCaptureSound(BYTE flag)
{
BYTE nChan,nbPS,ber;

if(flPlaySound!=0||flProc!=0) { SoundBlock(); return messRet;}
if(DlgDBFNNW.IsDoTrain()!=0) { SoundBlock(); return messRet;}
if(SndCap==NULL) return 1; if(SndCap->Obj==NULL) return 2;
if(SndCapData==NULL) return 3; SndCapData->Free();
flRegCapt=flag;

if(flRegCapt!=0) { TimeRecBuf=TimeRecProc=nRecChar=0;
if(SndCapData->CreateCycle(szSndCapDataCycle)!=0) return 4; // Выделение памяти для цикла хранения данных при распознавании звука.
if(WinText.hwnd!=NULL) WinText.ClearWin();
if(AnSound.Init(ParSpectr.Time_Step,1)!=0) return 5; // Инициализация класса для обработки потока символов звуков.
if(RecNNW.Alloc(nRecCharMax)!=0) return 6;}

if(SndCap->StartCapture()!=0) return 7; // Запуск захвата звука.
ber=0;
SndCap->Obj->GetParSnd(&SndCapData->nSPS,&nChan,&nbPS);
if(nChan!=1) { ber=8; goto end;} if(nbPS!=16) { ber=9; goto end;}
if(flRegCapt!=0) { if(szSndCapDataCycle*szNotifySndCap<SndCapData->nSPS*ParSpectr.Time_Width) { ber=10; goto end;}}

flCaptSound=1; flStopCaptSound=0; flBlk|=1<<numBlkMain_SndCap;
if(flRegCapt==0) SetTxtBtnCaptSound(); else SetTxtBtnRecSound();
while(1) { if(SndCap->Obj->CheckMessage()!=0) break;}

end: StopCaptureSound_(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Остановка записи звука.

void clMain::StopCaptureSound(BYTE flag)
{
if(flRegCapt==flag) flStopCaptSound=1; else SoundBlock();
}

//-----------------------------------------------------------------------------------------------------------
// Остановка записи звука.

void clMain::StopCaptureSound_(void)
{
flStopCaptSound=1; if(SndCap==NULL) return;
SndCap->StopCapture(); // Остановка захвата звука.
if(flRegCapt==0) SaveSndCapData(); // Сохранение результатов захвата звука.
else { if(SndCapData!=NULL) SndCapData->Free();} // В режиме реального времени - освобождение памяти.
flCaptSound=0; flBlk&=~(1<<numBlkMain_SndCap);
if(flRegCapt==0) SetTxtBtnCaptSound(); else SetTxtBtnRecSound();
flRegCapt=0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку записи звука.

void clMain::SetTxtBtnCaptSound(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flCaptSound==0) id=IDS_Btn_Record; else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_CAPT_SND,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку распознавания звука.

void clMain::SetTxtBtnRecSound(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flCaptSound==0) id=IDS_Btn_Recogn; else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_CAPT_REC,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Класс хранения данных при записи звука: обнуление указателя.

void clMain::ZeroSndCapData(void)
{
SndCapData=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Класс хранения данных при записи звука: оcвобождение памяти.

void clMain::FreeSndCapData(void)
{
SAFE_DELETE(SndCapData);
}

//-----------------------------------------------------------------------------------------------------------
// Класс хранения данных при записи звука: создание.

BYTE clMain::CreateSndCapData(void)
{
FreeSndCapData(); SndCapData=new clSndCapData(); if(SndCapData==NULL) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение результатов захвата звука.

BYTE clMain::SaveSndCapData(void)
{
BYTE FillSndArr(clSndCapData *SndCapData,strSndArr *Snd); // Заполнение структуры звука.

char *cp;

if(SndCapData==NULL) return 1; if(SndCapData->IsOK()!=0) return 2;
CloseFileSound();
if(FillSndArr(SndCapData,&Snd)!=0) return 3; // Заполнение структуры звука.
SndCapData->Free();
cp="Record"; if(hInst!=NULL) { if(LoadString(hInst,IDS_NameRecord,TxtStr,strL_Txt)!=0) cp=TxtStr;}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_FILE_NAME,cp); // Установка имени звукового файла.
SetScrollGrSig(); // Установка параметров прокрутки окна графика сигнала.
UpdateWindow_(hwndGraphSig);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Настройка захвата звука.

BYTE clMain::DlgAdjSound(void)
{
BYTE flRet,ber; clDlgSndCap *DSC;

if(flCaptSound!=0) { SoundBlock(); return messRet;}
if(hDlg==NULL) return 1; if(SndCap==NULL) return 2; if(SndCap->Obj==NULL) return 3;
DSC=NULL; ber=0;
DSC=new clDlgSndCap(); if(DSC==NULL) { ber=4; goto end;}
if(DSC->Dialog(hDlg,SndCap->Obj,&flRet)!=0) { ber=5; goto end;}
end: SAFE_DELETE(DSC); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка, идёт ли захват звука.

BYTE clMain::IsCaptSound(void)
{
return flCaptSound;
}

//-----------------------------------------------------------------------------------------------------------
// Редактирование параметров спектрального разложения.

void clMain::AdjParSpectr(void)
{
INT_PTR CALLBACK DlgParSpectr(HWND,UINT,WPARAM,LPARAM); // Функция диалогового окна задание параметров спектрального разложения.

BYTE fl;

if(hInst==NULL) return; if(hwnd==NULL) return;
if(flProc!=0) { SoundBlock(); return;} if(DlgDBFNNW.IsDoPreProc()!=0) { SoundBlock(); return;}
fl=(BYTE)DialogBox(hInst,MAKEINTRESOURCE(IDD_PAR_PROC_SPECTR),hwnd,(DLGPROC)DlgParSpectr); if(fl==0) return;
ParSpectr.Write(PathToProgDir,NameParSpectr);
}

//-----------------------------------------------------------------------------------------------------------
// Редактирование параметров выделения спектральных пиков.

void clMain::AdjParPeaks(void)
{
INT_PTR CALLBACK DlgParPeaks(HWND,UINT,WPARAM,LPARAM); // Функция диалогового окна настройки параметров выделения спектральных линий.

BYTE fl;

if(hInst==NULL) return; if(hwnd==NULL) return;
if(flProc!=0) { SoundBlock(); return;} if(DlgDBFNNW.IsDoPreProc()!=0) { SoundBlock(); return;}
fl=(BYTE)DialogBoxParam(hInst,MAKEINTRESOURCE(IDD_PAR_PEAKS),hwnd,(DLGPROC)DlgParPeaks,(LPARAM)&ParGetPeaks);
if(fl==0) return; ParGetPeaks.Write(PathToProgDir,NameParGetPeaks);
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие базы данных.

void clMain::CloseDataBase(void)
{
DataBase.Free(); flDBS=0; ChBtnMenuOpenDlgDBS_NNW(); if(hDlgDB!=NULL) DlgDBFNNW.OnChDataBase();
}

//-----------------------------------------------------------------------------------------------------------
// Открытие файла базы данных.

BYTE clMain::OpenDataBase(void)
{
BYTE err;

CloseDataBase(); if(hDlg==NULL) return 1; strcpy(FileNameN,"");
err=FileNameQuest(hDlg,0,IDS_Filt_DBS_Files,PathToDirDBS,extDBF,IDS_HeaderDlg_OpenDBF,FileNameN,
strL_FileName,PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 2;
if(CompareStrCase(ExtN,extDBF)!=0) return 3; strcpy(PathToDirDBS,PathToDirN);
if(DataBase.Read_(PathToDirN,FileNameN)!=0) return 4; // Чтение файла базы данных.
flDBS=1; ChBtnMenuOpenDlgDBS_NNW(); if(hDlgDB!=NULL) DlgDBFNNW.OnChDataBase(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Открытие диалогового окна базы данных и тренировки сети.

void clMain::OpenDlgDBS_NNW(void)
{
INT_PTR CALLBACK DlgProcDB(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam); // Функция диалогового окна базы данных.

if(hDlgDB!=NULL||flDlgDBS!=0) { SoundBlock(); return;} if(flDBS==0) { SoundBlock(); return;}
if(hInst==NULL) return;
hDlgDB=CreateDialogParam(hInst,MAKEINTRESOURCE(IDD_DATABASE),hwnd,(DLGPROC)DlgProcDB,(LPARAM)&DlgDBFNNW);
if(hDlgDB==NULL) return; flBlk|=1<<numBlkMain_DlgDBS; flDlgDBS=1; ChBtnMenuOpenDlgDBS_NNW();
}

//-----------------------------------------------------------------------------------------------------------
// Действия при закрытии диалогового окна базы данных и тренировки сети.

void clMain::OnCloseDlgDBS_NNW(void)
{
UpdateWinDiag(); flBlk&=~(1<<numBlkMain_DlgDBS); hDlgDB=NULL; flDlgDBS=0; ChBtnMenuOpenDlgDBS_NNW();
}

//-----------------------------------------------------------------------------------------------------------
// Изменение состояния кнопки и пункта меню открытия диалогового окна базы данных и тренировки сети.

void clMain::ChBtnMenuOpenDlgDBS_NNW(void)
{
SCHAR En,Ch;

if(flDBS==0) En=0; else En=1; if(flDlgDBS==0) Ch=0; else Ch=1;
SetStMenuItem_(hMenu,IDM_DLG_DB,En,Ch);
EnableChWin(hDlg,IDC_DBS_NNW,En);
}

//-----------------------------------------------------------------------------------------------------------
// Установка состояния кнопки захвата звука.

void clMain::ChBtnCaptSound(void)
{
EnableChWin(hDlg,IDC_CAPT_SND,flEnCaptSound);
EnableChWin(hDlg,IDC_CAPT_REC,flEnCaptSound);
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров и указателей для окна визуализации нейронной сети.

void clMain::SetPntWinViewNNW(void)
{
WinViewNNW.SetParPnt(hwnd,&rcViewNNW); // Установка параметров и указателей.
WinViewNNW.SetPntNeurNet(&NNW_Vowel,&NNW_Cons,&NNW_Spectr); // Установка указателей на структуры нейронных сетей для гласных и согласных и для всего спектра.
}

//-----------------------------------------------------------------------------------------------------------
// Установка размеров окна визуализации нейронной сети.

BYTE clMain::GetSizeWinViewNNW(void)
{
BYTE GetSizeDlg(HWND hwndOwner,int idD,USHRT *dx,USHRT *dy); // Даёт размер диалогового окна.

USHRT dx,dy,dW; long *lp,d;

if(hwnd==NULL) return 1; if(GetSizeDlg(hwnd,IDD_CNTRL_VIEW_NNW,&dx,&dy)!=0) return 2;
dx=MAX(dx,dxViewNNW_Stand); if(dy>USHRT_MAX-dyViewNNW_Stand) return 3; dy+=dyViewNNW_Stand;
if(GetWindowRect(hwnd,&rc)==FALSE) return 4;
lp=&rcViewNNW.left; dW=dx; d=rc.right-rc.left; *lp=(d-(long)dW)/2; *lp+=rc.left; rcViewNNW.right=*lp+(long)dW;
lp=&rcViewNNW.top; dW=dy; d=rc.bottom-rc.top; *lp=(d-(long)dW)/2; *lp+=rc.top; rcViewNNW.bottom=*lp+(long)dW;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Открытие окна визуализации нейронной сети.

void clMain::OpenWinViewNNW(void)
{
if(WinViewNNW.hwnd==NULL) WinViewNNW.CreateWin(); else WinViewNNW.CloseWin(); ChBtnMenuWinViewNNW();
}

//-----------------------------------------------------------------------------------------------------------
// Изменение состояния кнопки и пункта меню открытия окна визуализации нейронной сети.

void clMain::ChBtnMenuWinViewNNW(void)
{
BYTE Ch; int id; char *cp;

if(WinViewNNW.hwnd==NULL) Ch=0; else Ch=1;
SetStMenuItem_(hMenu,IDM_WIN_VISUAL_NNW,1,Ch);
if(Ch==0) id=IDS_Btn_WinViewNet; else id=IDS_Btn_WinClose;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_WIN_VIEW_NNW,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров и указателей для окна текста.

void clMain::SetPntWinText(void)
{
WinText.SetParPnt(hwnd,&rcText); // Установка параметров и указателей.
}

//-----------------------------------------------------------------------------------------------------------
// Установка размеров окна текста.

BYTE clMain::GetSizeWinText(void)
{
USHRT dW; long *lp,d;

if(hwnd==NULL) return 1; if(GetWindowRect(hwnd,&rc)==FALSE) return 2;
lp=&rcText.left; dW=dxWinText_Stand; d=rc.right-rc.left; *lp=(d-(long)dW)/2; *lp+=rc.left; rcText.right=*lp+(long)dW;
lp=&rcText.top; dW=dyWinText_Stand; d=rc.bottom-rc.top; *lp=(d-(long)dW)/2; *lp+=rc.top; rcText.bottom=*lp+(long)dW;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Открытие окна тескта.

void clMain::OpenWinText(void)
{
if(WinText.hwnd==NULL) WinText.CreateWin(); else WinText.CloseWin(); ChBtnMenuWinText();
}

//-----------------------------------------------------------------------------------------------------------
// Изменение состояния кнопки и пункта меню открытия окна текста.

void clMain::ChBtnMenuWinText(void)
{
BYTE Ch; int id; char *cp;

if(WinText.hwnd==NULL) Ch=0; else Ch=1;
SetStMenuItem_(hMenu,IDM_WIN_TEXT,1,Ch);
if(Ch==0) id=IDS_Btn_WinText; else id=IDS_Btn_WinClose;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_WIN_TEXT,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Очистка окна текста.

void clMain::ClearWinText(void)
{
if(WinText.hwnd!=NULL) WinText.SetText("");
}

//-----------------------------------------------------------------------------------------------------------
// Изображение текста в окне.

void clMain::SetWinText(char *Text)
{
if(WinText.hwnd!=NULL) WinText.SetText(Text);
}

//-----------------------------------------------------------------------------------------------------------
// Вывод звука.

BYTE clMain::StartPlaySound(void)
{
BYTE PlayWave_(float *Wave,UINT nPoints,DWORD sps,BYTE *flStop,DWORD WOP,DWORD Pnt,HWAVEOUT *hwo_); // Вывод звука из массива.

BYTE be; DWORD sps;

if(hDlg==NULL) return 1; if(Snd.IsOK()!=0) return 2; if(Snd.ln<=1) return 3;
if(flCaptSound!=0||flProc!=0) { SoundBlock(); return messRet;}
SetTimer(hDlg,idT_Main_Snd,uT_Main_Snd,NULL);
sps=(DWORD)GetIntTest(1.0F/(float)Snd.dt);
flStopSound=0; flPlaySound=1; flBlk|=1<<numBlkMain_Sound; SetTxtBtnPlaySound();
be=PlayWave_(Snd.Snd,Snd.ln,sps,&flStopSound,0L,0L,&hwo);
OnStopSound();
if(be!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при остановке проигрывания звука.

void clMain::OnStopSound(void)
{
BYTE fl;

if(hDlg!=NULL) KillTimer(hDlg,idT_Main_Snd); flBlk&=~(1<<numBlkMain_Sound);
PlaySound(NULL,NULL,SND_PURGE);
flStopSound=1; flPlaySound=0; SetTxtBtnPlaySound();
fl=1; if(BmpDiag==NULL) fl=0; else if(BmpDiag->IsOKB()!=0) fl=0; if(fl!=0) UpdateWinDiag();
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку воспроизведения звука.

void clMain::SetTxtBtnPlaySound(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flPlaySound==0) id=IDS_Btn_Sound; else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_PLAY_SND,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Перерисовка курсора при проигрывании звука.

BYTE clMain::DrawCurSound(void)
{
BYTE ber; UINT PosCurSnd; MMTIME *mmt;

if(hwo==NULL) return 1; if(flStopSound!=0||flPlaySound==0) return 2; if(SpectrAmp.IsOK_St()!=0) return 3;
ber=0; mmt=NULL;
mmt=new MMTIME; if(mmt==NULL) { ber=4; goto end;}
mmt->wType=TIME_BYTES;
if(waveOutGetPosition(hwo,(LPMMTIME)mmt,(UINT)sizeof(MMTIME))!=MMSYSERR_NOERROR) { ber=5; goto end;}
if(mmt->wType!=TIME_BYTES) { ber=6; goto end;}
PosCurSnd=(UINT)(mmt->u.cb/(int)sizeof(SHRT));
CoordTimeDiag=GetIntTest((double)Snd.dt/SpectrAmp.stArr*(double)PosCurSnd); CoordTimeSig=PosCurSnd;
OnChCurTime();
end: SAFE_DELETE(mmt); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении положения курсора по времени.

void clMain::OnChCurTime(void)
{
BYTE fl;

fl=1; if(BmpDiag==NULL) fl=0; else if(BmpDiag->IsOKB()!=0) fl=0; if(fl==0) return;
UpdateWinDiag(); UpdateWindow_(hwndGraphSpectr); OnChCurTimeGraphSig();
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении положения курсора по времени в окне графика сигнала.

void clMain::OnChCurTimeGraphSig(void)
{
int x,dx;

if(hwndGraphSig==NULL) return; if(GetClientRect(hwndGraphSig,&rc)==FALSE) return;
dx=(int)(rc.right-rc.left); if(dx<=0) return;
x=CoordTimeSig-pScGrSig; if(x<0||x>=dx) { if(flCurGrSig==0) return; flCurGrSig=0;}
UpdateWindow_(hwndGraphSig);
}

//-----------------------------------------------------------------------------------------------------------
// Установка курсора по времени в окне диаграммы.

void clMain::OnSetCurTimeDiag(int x,BYTE fl)
{
float time;

CoordTimeDiag=x+pScDiagH; SetTimeDBF(fl);
if(SpectrAmp.stArr<=0.||Snd.dt<=0.) CoordTimeSig=0;
else { time=(float)(SpectrAmp.stArr*(double)CoordTimeDiag); CoordTimeSig=GetIntTest(time/(float)Snd.dt);}
OnChCurTime(); RecognNNW();
}

//-----------------------------------------------------------------------------------------------------------
// Установка курсора по времени в окне графика сигнала.

void clMain::OnSetCurTimeGraphSig(int x)
{
float time;

CoordTimeSig=x+pScGrSig;
if(SpectrAmp.stArr<=0.||Snd.dt<=0.) CoordTimeDiag=0;
else { time=(float)(Snd.dt*(double)CoordTimeSig); CoordTimeDiag=GetIntTest(time/(float)SpectrAmp.stArr);}
OnChCurTime();
}

//-----------------------------------------------------------------------------------------------------------
// Передача значения времени в базу данных.

void clMain::SetTimeDBF(BYTE fl)
{
float time;

if(SpectrAmp.stArr<=0.) return; time=(float)(SpectrAmp.stArr*(double)CoordTimeDiag);
DlgDBFNNW.SetTimeSound(time,fl);
}

//-----------------------------------------------------------------------------------------------------------
// Установка пролистывания диаграммы на заданное время.

BYTE clMain::SetTimeDiag(float Time)
{
if(SpectrAmp.stArr<=0.) return 1; CoordTimeDiag=pScDiagH=MIN(GetIntTest(Time/(float)SpectrAmp.stArr),pMScDiagH);
if(Snd.dt>0.) CoordTimeSig=GetIntTest(Time/(float)Snd.dt);
if(hwndDiag!=NULL) SetScrollPos(hwndDiag,SB_HORZ,pScDiagH,TRUE);
OnChCurTime(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Изменение состояния пункта меню обработки выходного потока символов.

void clMain::ChMenuProcOutput(void)
{
SetStMenuItem_(hMenu,IDM_SET_OUTPUT,1,methDecSound);
}

//-----------------------------------------------------------------------------------------------------------
// Обработка очереди сообщений главного окна.

LRESULT clMain::MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
if(flag==NULL) return 0L; *flag=0; if(hwnd==NULL) return 0L; if(msg==WM_CREATE) return 0L;

switch(msg) { default: break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1; break;

// WM_SIZE ..................................................................................................
case WM_SIZE: *flag=1; if(wParam==SIZE_MINIMIZED) break; OnChSizeWin(); break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: if(Command(wParam)==0) *flag=1; break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; ImgWinC(hwnd,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: *flag=1; OnCloseWin(); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Команды.

BYTE clMain::Command(WPARAM wParam)
{
INT_PTR CALLBACK DlgAbout(HWND,UINT,WPARAM,LPARAM); // Функция диалогового окна о программе.

BYTE flag,fl,be; int wmId;

if(hwnd==NULL) return 1; flag=0; wmId=LOWORD(wParam);

switch(wmId) { default: flag=2; break; 

// IDM_OPEN_WAV .............................................................................................
case IDM_OPEN_WAV: be=OpenFileSound(); if(be!=0&&be!=messRet) SoundBlock(); break;

// IDM_SAVE_WAV .............................................................................................
case IDM_SAVE_WAV: be=SaveFileSound(); if(be!=0&&be!=messRet) SoundBlock(); break;

// IDM_ADJUST_PAR_SPECTR ....................................................................................
case IDM_ADJUST_PAR_SPECTR: AdjParSpectr(); break;

// IDM_ADJUST_PAR_PEAKS .....................................................................................
case IDM_ADJUST_PAR_PEAKS: AdjParPeaks(); break;

// IDM_ADJ_SOUND_CAPTURE ....................................................................................
case IDM_ADJ_SOUND_CAPTURE: DlgAdjSound(); break;

// IDM_COMPUTE ..............................................................................................
case IDM_COMPUTE: if(flStopProc==0) { flStopProc=1; break;} ComputeDrawDiag(); break;

// IDM_OPEN_DB ..............................................................................................
case IDM_OPEN_DB: OpenDataBase(); break;

// IDM_DLG_DB ...............................................................................................
case IDM_DLG_DB: OpenDlgDBS_NNW(); break;

// IDM_WIN_VISUAL_NNW .......................................................................................
case IDM_WIN_VISUAL_NNW: OpenWinViewNNW(); break;

// IDM_WIN_TEXT .............................................................................................
case IDM_WIN_TEXT: OpenWinText(); break;

// IDM_NEUR_LOAD_VOWEL IDM_NEUR_LOAD_CONSONANT IDM_NEUR_LOAD_SPECTR .........................................
case IDM_NEUR_LOAD_VOWEL: case IDM_NEUR_LOAD_CONSONANT: case IDM_NEUR_LOAD_SPECTR:
switch(wmId) { default: break;
case IDM_NEUR_LOAD_VOWEL: fl=typNNW_Vowel; break;
case IDM_NEUR_LOAD_CONSONANT: fl=typNNW_Cons; break;
case IDM_NEUR_LOAD_SPECTR: fl=typNNW_Spectr; break;
}
be=LoadNNW(fl); if(be!=0&&be!=messRet) Message(IDS_Mess_ErrLoadNNW,MB_ST); break;

// IDM_NEUR_SAVE_VOWEL IDM_NEUR_SAVE_CONSONANT IDM_NEUR_SAVE_SPECTR .........................................
case IDM_NEUR_SAVE_VOWEL: case IDM_NEUR_SAVE_CONSONANT: case IDM_NEUR_SAVE_SPECTR:
switch(wmId) { default: break;
case IDM_NEUR_SAVE_VOWEL: fl=typNNW_Vowel; break;
case IDM_NEUR_SAVE_CONSONANT: fl=typNNW_Cons; break;
case IDM_NEUR_SAVE_SPECTR: fl=typNNW_Spectr; break;
}
SaveNNW(fl); break;

// IDM_NEUR_SAVEAS_VOWEL IDM_NEUR_SAVEAS_CONSONANT IDM_NEUR_SAVEAS_SPECTR ...................................
case IDM_NEUR_SAVEAS_VOWEL: case IDM_NEUR_SAVEAS_CONSONANT: case IDM_NEUR_SAVEAS_SPECTR:
switch(wmId) { default: break;
case IDM_NEUR_SAVEAS_VOWEL: fl=typNNW_Vowel; break;
case IDM_NEUR_SAVEAS_CONSONANT: fl=typNNW_Cons; break;
case IDM_NEUR_SAVEAS_SPECTR: fl=typNNW_Spectr; break;
}
SaveAsNNW(fl); break;

// IDM_USE_NNW_TWO_SEP IDM_USE_NNW_SINGLE_SPECTR IDM_USE_NNW_COHONEN ........................................
case IDM_USE_NNW_TWO_SEP: case IDM_USE_NNW_SINGLE_SPECTR: case IDM_USE_NNW_COHONEN: SetTypRecNNW(wmId); break;

// IDM_SET_OUTPUT ...........................................................................................
case IDM_SET_OUTPUT: methDecSound=1-methDecSound; ChMenuProcOutput(); break;

// IDM_HELP .................................................................................................
case IDM_HELP: if(Help!=NULL) Help->ShowContent(); break;

// IDM_ABOUT ................................................................................................
case IDM_ABOUT: if(hInst==NULL) break; DialogBox(hInst,MAKEINTRESOURCE(IDD_ABOUTBOX),hwnd,(DLGPROC)DlgAbout); break;

// IDM_EXIT .................................................................................................
case IDM_EXIT: OnCloseWin(); break;
}
return flag;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка очереди сообщений окна управления.

LRESULT clMain::MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
int id; HDC hdc;

if(flag==NULL) return 0L; *flag=0; if(hDlg==NULL) return 0L; if(msg==WM_INITDIALOG) return 0L;

switch(msg) { default: break;

// WM_CTLCOLORSTATIC ........................................................................................
case WM_CTLCOLORSTATIC: hdc=(HDC)wParam; id=GetDlgCtrlID((HWND)lParam); if(id<=0) break; *flag=1;
SetBkColor(hdc,GetSysColor(COLOR_WINDOW)); SetTextColor(hdc,GetSysColor(COLOR_BTNTEXT));
SetBkMode(hdc,TRANSPARENT);
if(id==IDC_FILE_NAME||id==IDC_PERC||id==IDC_COORDTIME||id==IDC_COORDFREQ||id==IDC_COORDAMPL) return (LRESULT)hBrushBkg;
return (LRESULT)hBrushDial;

// WM_TIMER .................................................................................................
case WM_TIMER: *flag=1;
if(wParam==idT_Main_Snd) { DrawCurSound(); break;}
if(wParam==idT_Main_CheckCurPos) { CheckCurPos(); break;}
break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: if(CommandCntrl(wParam)==0) *flag=1; break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка команд окна управления.

BYTE clMain::CommandCntrl(WPARAM wParam)
{
BYTE fl,be; int id; float coe;

if(hDlg==NULL) return 1; id=LOWORD(wParam);

switch(id) { default: return 2;

// Изменение амплитуды нормировки диаграммы.
// IDC_AMPLM_DIAG IDC_AMPLP_DIAG ............................................................................
case IDC_AMPLM_DIAG: case IDC_AMPLP_DIAG: coe=(float)sqrt(2.);
if(id==IDC_AMPLM_DIAG) AmpNorm*=coe; else AmpNorm/=coe;
SetFlEdt(hDlg,IDC_AMPL_DIAG,AmpNorm,FormAmpNormSpectr); DrawDiag(); UpdateWinDiag(); break;

// IDC_AMPLOK_DIAG ..........................................................................................
case IDC_AMPLOK_DIAG: GetFlEdt(hDlg,IDC_AMPL_DIAG,&AmpNorm); DrawDiag(); UpdateWinDiag(); break;

// Изменение амплитуды нормировки сигнала.
// IDC_AMPLM_SIG IDC_AMPLP_SIG ..............................................................................
case IDC_AMPLM_SIG: case IDC_AMPLP_SIG: coe=(float)sqrt(2.);
if(id==IDC_AMPLM_SIG) AmpSig*=coe; else AmpSig/=coe;
SetFlEdt(hDlg,IDC_AMPL_SIG,AmpSig,FormAmpNormSig); UpdateWindow_(hwndGraphSig); break;

// IDC_AMPLOK_SIG ...........................................................................................
case IDC_AMPLOK_SIG: GetFlEdt(hDlg,IDC_AMPL_SIG,&AmpSig); UpdateWindow_(hwndGraphSig); break;

// Изменение амплитуды нормировки спектра.
// IDC_AMPLM_GRSP IDC_AMPLP_GRSP ............................................................................
case IDC_AMPLM_GRSP: case IDC_AMPLP_GRSP: coe=(float)sqrt(2.);
if(id==IDC_AMPLM_GRSP) AmpSpect*=coe; else AmpSpect/=coe;
SetFlEdt(hDlg,IDC_AMPL_GRSP,AmpSpect,FormAmpNormSpectr); UpdateWindow_(hwndGraphSpectr); break;

// IDC_AMPLOK_GRSP ..........................................................................................
case IDC_AMPLOK_GRSP: GetFlEdt(hDlg,IDC_AMPL_GRSP,&AmpSpect); UpdateWindow_(hwndGraphSpectr); break;

// IDC_PLAY_SND .............................................................................................
case IDC_PLAY_SND: if(flPlaySound==0) StartPlaySound(); else flStopSound=1; break;

// IDC_CAPT_SND IDC_CAPT_REC ................................................................................
case IDC_CAPT_SND: case IDC_CAPT_REC: if(id==IDC_CAPT_SND) fl=0; else fl=1;
if(flCaptSound==0) StartCaptureSound(fl); else StopCaptureSound(fl); break;

// IDC_OPEN_FILE ............................................................................................
case IDC_OPEN_FILE: be=OpenFileSound(); if(be!=0&&be!=messRet) SoundBlock(); break;

// IDC_PROCESSING ...........................................................................................
case IDC_PROCESSING: if(flStopProc==0) { flStopProc=1; break;} ComputeDrawDiag(); break;

// IDC_ADJ_SPECTR ...........................................................................................
case IDC_ADJ_SPECTR: AdjParSpectr(); break;

// IDC_OPEN_DBS .............................................................................................
case IDC_OPEN_DBS: OpenDataBase(); break;

// IDC_DBS_NNW ..............................................................................................
case IDC_DBS_NNW: OpenDlgDBS_NNW(); break;

// IDC_WIN_TEXT .............................................................................................
case IDC_WIN_TEXT: OpenWinText(); break;

// IDC_WIN_VIEW_NNW .........................................................................................
case IDC_WIN_VIEW_NNW: OpenWinViewNNW(); break;

// IDC_RADIO_SHOW_VOWEL IDC_RADIO_SHOW_CONS .................................................................
case IDC_RADIO_SHOW_VOWEL: case IDC_RADIO_SHOW_CONS: OnSelTypViewSndLineDiag(id); break;

// IDC_FILE_NAME IDC_PERC IDC_COORDFREQ IDC_COORDAMPL .......................................................
case IDC_FILE_NAME: case IDC_PERC: case IDC_COORDFREQ: case IDC_COORDAMPL:
if(HIWORD(wParam)==EN_SETFOCUS) SetFocusWin(); break;
}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка очереди окна спектральной диаграммы.

LRESULT clMain::MsgCommandDiag(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
BYTE fl; PAINTSTRUCT ps; HDC hdc;

if(flag==NULL) return 0L; *flag=0; if(hwndDiag==NULL) return 0L; if(msg==WM_CREATE) return 0L;

switch(msg) { default: break; 

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1;  break;

// WM_MOUSEMOVE .............................................................................................
case WM_MOUSEMOVE: *flag=1; SetFocus(hwnd); OnMouseMoveDiag(lParam); break;

// WM_LBUTTONDOWN WM_RBUTTONDOWN ............................................................................
case WM_LBUTTONDOWN: case WM_RBUTTONDOWN: if(msg==WM_LBUTTONDOWN) fl=0; else fl=1;
OnSetCurTimeDiag((int)LOWORD(lParam),fl); break;

// WM_HSCROLL WM_VSCROLL ....................................................................................
case WM_HSCROLL: *flag=1; HScrollDiag(wParam); break;
case WM_VSCROLL: *flag=1; VScrollDiag(wParam); break;

// WM_SIZE ..................................................................................................
case WM_SIZE: *flag=1; if(wParam==SIZE_MINIMIZED) break; OnChSizeWinDiag(); break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; hdc=BeginPaint(hwndDiag,&ps);
if(OnPaintDiag(hdc)!=0) OnPaintDiagDef(hdc); EndPaint(hwndDiag,&ps); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка очереди окна графика сигнала.

LRESULT clMain::MsgCommandGraphSig(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
PAINTSTRUCT ps; HDC hdc;

if(flag==NULL) return 0L; *flag=0; if(hwndGraphSig==NULL) return 0L; if(msg==WM_CREATE) return 0L;

switch(msg) { default: break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1; break;

// WM_MOUSEMOVE .............................................................................................
case WM_MOUSEMOVE: *flag=1; SetFocus(hwnd); OnMouseMoveGraphSig(lParam); break;

// WM_LBUTTONDOWN WM_RBUTTONDOWN ............................................................................
case WM_LBUTTONDOWN: case WM_RBUTTONDOWN: OnSetCurTimeGraphSig((int)LOWORD(lParam)); break;

// WM_HSCROLL ...............................................................................................
case WM_HSCROLL: *flag=1; HScrollGrSig(wParam); break;

// WM_SIZE ..................................................................................................
case WM_SIZE: *flag=1; if(wParam==SIZE_MINIMIZED) break; OnChSizeWinGraphSig(); break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; hdc=BeginPaint(hwndGraphSig,&ps);
if(OnPaintGraphSig(hdc)!=0) OnPaintGraphSigDef(hdc); EndPaint(hwndGraphSig,&ps); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка очереди окна графика спектра.

LRESULT clMain::MsgCommandGraphSpectr(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
PAINTSTRUCT ps; HDC hdc;

if(flag==NULL) return 0L; *flag=0; if(hwndGraphSpectr==NULL) return 0L; if(msg==WM_CREATE) return 0L;

switch(msg) { default: break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1; break;

// WM_MOUSEMOVE .............................................................................................
case WM_MOUSEMOVE: *flag=1; SetFocus(hwnd); OnMouseMoveGraphSpectr(lParam); break;

// WM_HSCROLL ...............................................................................................
case WM_HSCROLL: *flag=1; HScrollGrSpectr(wParam); break;

// WM_SIZE ..................................................................................................
case WM_SIZE: *flag=1; if(wParam==SIZE_MINIMIZED) break; OnChSizeWinGraphSpectr(); break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; hdc=BeginPaint(hwndGraphSpectr,&ps); 
if(OnPaintGraphSpectr(hdc)!=0) OnPaintGraphSpectrDef(hdc); EndPaint(hwndGraphSpectr,&ps); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Установка фокуса ввода.

void clMain::SetFocusWin(void)
{
HWND hwnd_;

if(hDlg==NULL) return; hwnd_=GetDlgItem(hDlg,IDC_OPEN_FILE); if(hwnd_==NULL) return; SetFocus(hwnd_);
}

//-----------------------------------------------------------------------------------------------------------
// Перерисовка изображения сети.

void clMain::DrawNet(void)
{
WinViewNNW.DrawNet(); // Перерисовка изображения сети.
}

//-----------------------------------------------------------------------------------------------------------
//Проверка местоположения курсора.

void clMain::CheckCurPos(void)
{
BYTE i,flT,flF,flA; POINT ptt,pt; HWND hwnd_;

GetCursorPos(&pt);

flT=flF=flA=0;
for(i=0;i<3;i++) {
ptt=pt;
switch(i) { default:
case 0: hwnd_=hwndDiag; break;
case 1: hwnd_=hwndGraphSpectr; break;
case 2: hwnd_=hwndGraphSig; break;}

if(hwnd_==NULL) continue;
if(ScreenToClient(hwnd_,&ptt)==FALSE) continue;
if(GetClientRect(hwnd_,&rc)==FALSE) continue;
if(PtInRect(&rc,ptt)==FALSE) continue;

switch(i) { default:
case 0: if(flT==0) flT=1; if(flF==0) flF=1; break;
case 1: if(flA==0) flA=1; if(flF==0) flF=1; break;
case 2: if(flA==0) flA=1; if(flT==0) flT=1; break;
}

}

if(flTi!=0&&flT==0) { if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDTIME,""); flTi=0;}
if(flAm!=0&&flA==0) { if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDAMPL,""); flAm=0;}
if(flFr!=0&&flF==0) { if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_COORDFREQ,""); flFr=0;}
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка файла, построение графика сигнала.

BYTE clMain::LoadFile(char *Path,char *Dir,char *FileName)
{
BYTE FillSndArr(clWavData *WAV,strSndArr *Snd); // Заполнение структуры звука.

BYTE err; char *fName; clWavData *SoundWAV;

CloseFileSound(); if(IsOKStr(FileName)!=0) return 1;
fName=NULL; SoundWAV=NULL; err=0;
SoundWAV=new clWavData(); if(SoundWAV==NULL) { err=2; goto end;}
if(GetName(&fName,Path,Dir,FileName,extWAV)!=0) { err=3; goto end;}
if(SoundWAV->Read(fName)!=0) { err=4; goto end;} // Чтение звукового файла.
if(FillSndArr(SoundWAV,&Snd)!=0) { err=5; goto end;} // Заполнение структуры звука.
if(DupString(&FileNameWAV,fName)!=0) { err=6; goto end;} // Установка имени загруженного файла.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_FILE_NAME,FileName); // Установка имени звукового файла.
SetScrollGrSig(); // Установка параметров прокрутки окна графика сигнала.
UpdateWindow_(hwndGraphSig);
if(hDlgDB!=NULL) DlgDBFNNW.SetFlagLoadFile(); // Установка флага загрузки файла.
end: FreeString(&fName); SAFE_DELETE(SoundWAV); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение файла в формате "WAV".

BYTE clMain::SaveFile(char *Path,char *Dir,char *FileName)
{
BYTE FillWavData(strSndArr *Snd,clWavData *WAV); // Заполнение массива в формате "WAV".

BYTE err; char *fName; clWavData *SoundWAV;

if(IsOKStr(FileName)!=0) return 1; if(Snd.IsOK()!=0) return 2;
fName=NULL; SoundWAV=NULL; err=0;
SoundWAV=new clWavData(); if(SoundWAV==NULL) { err=3; goto end;}
if(GetName(&fName,Path,Dir,FileName,extWAV)!=0) { err=4; goto end;}
if(FillWavData(&Snd,SoundWAV)!=0) { err=5; goto end;} // Заполнение массива в формате "WAV".
if(SoundWAV->Write(fName)!=0) { err=6; goto end;} // Запись в файл.
if(DupString(&FileNameWAV,fName)!=0) { err=7; goto end;} // Установка имени загруженного файла.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_FILE_NAME,FileName); // Установка имени звукового файла.
if(hDlgDB!=NULL) DlgDBFNNW.SetFlagLoadFile(); // Установка флага загрузки файла.
end: FreeString(&fName); SAFE_DELETE(SoundWAV); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка файла, построение диаграммы, построение графика сигнала.

BYTE clMain::LoadProcFile(char *Path,char *Dir,char *FileName)
{
if(flProc!=0) { SoundBlock(); return messRet;} if(IsOKStr(FileName)!=0) return 1;
if(LoadFile(Path,Dir,FileName)!=0) return 2; // Загрузка файла, построение графика сигнала.
ComputeDrawDiag(); // Расчёт и построение диаграммы.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка нейронных сетей.

BYTE clMain::LoadNNW(BYTE typ)
{
BYTE err; int idSFilt; char *ext; struct strNNW *pNNW_;

if(DlgDBFNNW.IsTrain(typ)!=0) { SoundBlock(); return messRet;} if(hDlg==NULL) return 1;
switch(typ) { default: return 2;
case typNNW_Vowel:  pNNW_=&NNW_Vowel;  idSFilt=IDS_Filt_NNW_Vowel;  ext=extNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   pNNW_=&NNW_Cons;   idSFilt=IDS_Filt_NNW_Cons;   ext=extNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: pNNW_=&NNW_Spectr; idSFilt=IDS_Filt_NNW_Spectr; ext=extNNW_Spectr; break; // Для всего спектра.
}
if(pNNW_->typ!=typ) return 3;
strcpy(FileNameN,"");
err=FileNameQuest(hDlg,0,idSFilt,PathToDirNNW,ext,IDS_HeaderDlg_OpenNNW,FileNameN,strL_FileName,
PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 4;
if(CompareStrCase(ExtN,ext)!=0) return 5; strcpy(PathToDirNNW,PathToDirN);
if(pNNW_->Read(PathToDirN,FileNameN,ext)!=0) return 6; DlgDBFNNW.SetNameNNW(typ); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение нейронных сетей.

BYTE clMain::SaveNNW(BYTE typ)
{
struct strNNW *pNNW_;

switch(typ) { default: return 1;
case typNNW_Vowel:  pNNW_=&NNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   pNNW_=&NNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: pNNW_=&NNW_Spectr; break; // Для всего спектра.
}
if(pNNW_->typ!=typ) return 2;
if(pNNW_->IsOK_Name()!=0) { if(SaveAsNNW(typ)!=0) return 3; return 0;}
if(pNNW_->Write()!=0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение нейронных сетей под другим именем.

BYTE clMain::SaveAsNNW(BYTE typ)
{
BYTE fl,err; int idSFilt; char *ext; struct strNNW *pNNW_;

if(hDlg==NULL) return 1;
switch(typ) { default: return 2;
case typNNW_Vowel:  pNNW_=&NNW_Vowel;  idSFilt=IDS_Filt_NNW_Vowel;  ext=extNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   pNNW_=&NNW_Cons;   idSFilt=IDS_Filt_NNW_Cons;   ext=extNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: pNNW_=&NNW_Spectr; idSFilt=IDS_Filt_NNW_Spectr; ext=extNNW_Spectr; break; // Для всего спектра.
}
if(pNNW_->typ!=typ) return 3;
fl=0; if(pNNW_->IsOK_Name()==0) { if(StrCopy(FileNameN,strL_FileName,pNNW_->NameFile)==0) fl=1;}
if(fl==0) strcpy(FileNameN,"NNW");
err=FileNameQuest(hDlg,1,idSFilt,PathToDirNNW,ext,IDS_HeaderDlg_SaveNNW,FileNameN,strL_FileName,
PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 4;
if(CompareStrCase(ExtN,ext)!=0) return 5; strcpy(PathToDirNNW,PathToDirN);
if(pNNW_->IsOK_Name()!=0) { if(pNNW_->SetNames(PathToDirN,FileNameN)!=0) return 6; fl=1;} else fl=0;
if(pNNW_->Write(PathToDirN,FileNameN,ext,fl)!=0) return 7; DlgDBFNNW.SetNameNNW(typ); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка несохранённых сетей и сохранение при необходимости.

BYTE clMain::CheckSaveNNW(void)
{
BYTE typ,fl,flName,ber; int idS; char *NameNNW,*NameSound,*cp,*Def; struct strNNW *pNNW_;

if(LoadString(hInst,IDS_Quest_NoSavedNNW,TxtMem,strL_Txt)==0) strcpy(TxtMem,"Not saved NNW:\n'%s' for sounds: '%s' !\nSave ?");
NameSound=NameNNW=NULL; ber=0;
for(typ=0;typ<nTypesNNW;typ++) {
switch(typ) { default: continue;
case typNNW_Vowel:  pNNW_=&NNW_Vowel;  idS=IDS_SoundsVowel;     Def="Vowel"; break; // Для гласных звуков.
case typNNW_Cons:   pNNW_=&NNW_Cons;   idS=IDS_SoundsConsonant; Def="Consonant"; break; // Для согласных звуков.
case typNNW_Spectr: pNNW_=&NNW_Spectr; idS=IDS_SoundsSpectr;    Def="Spectr"; break; // Для всего спектра.
}
if(pNNW_->flChange==0||pNNW_->flOK==0) continue; if(pNNW_->IsOK_Name()!=0) flName=0; else flName=1;
if(LoadDupString(&NameSound,idS,Def)!=0) continue;
if(flName==0) { cp="New Network"; if(LoadDupString(&NameNNW,IDS_NewNNW,cp)==0) cp=NameNNW;} else cp=pNNW_->NameFile;
sprintf(TxtStr,TxtMem,cp,NameSound); fl=MessageBox(NULL,TxtStr,"",MB_QU); if(fl!=IDYES) continue;
if(flName==0) SaveAsNNW(typ); else SaveNNW(typ);
}
FreeString(&NameSound); FreeString(&NameNNW); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при выборе типа изображаемых звуков в линии символов на диаграмме.

void clMain::OnSelTypViewSndLineDiag(int id)
{
BYTE typ;

switch(id) { default: typ=UCHAR_MAX; break;
case IDC_RADIO_SHOW_VOWEL: typ=typNNW_Vowel; break; // Для гласных и сонорных звуков.
case IDC_RADIO_SHOW_CONS: typ=typNNW_Cons; break; // Для согласных взрывных и шипящих звуков.
}
if(typShowLineDiag==typ) return; typShowLineDiag=typ; if(SpectrAmp.IsOK_St()!=0) return;
DrawDiag(); // Построение спектральной диаграммы.
UpdateWinDiag(); // Перерисовка окна диаграммы.
}

//-----------------------------------------------------------------------------------------------------------
// Установка типа сетей при распознавании.

void clMain::SetTypRecNNW(int id)
{
BYTE typ;

switch(id) { default: return;
case IDM_USE_NNW_TWO_SEP:       typ=typNNR_VC; break; // Две раздельные сети для гласных и согласных.
case IDM_USE_NNW_SINGLE_SPECTR: typ=typNNR_Sp; break; // Одну многослойную сеть прямого распространения для всего спектра.
case IDM_USE_NNW_COHONEN:       typ=typNNR_Co; break; // Сеть Кохонена.
}
if(typ==typUseNNWRec) return; typUseNNWRec=typ; SetMenuTypNNWRec();
DrawDiag(); // Построение спектральной диаграммы.
UpdateWinDiag(); // Перерисовка окна диаграммы.
}

//-----------------------------------------------------------------------------------------------------------
// Установка меню для типа сетей при распознавании.

void clMain::SetMenuTypNNWRec(void)
{
BYTE i,Ch; int id;

for(i=0;i<nTypesRecNNW;i++) {
switch(i) { default: continue;
case typNNR_VC: id=IDM_USE_NNW_TWO_SEP; break; // Две раздельные сети для гласных и согласных.
case typNNR_Sp: id=IDM_USE_NNW_SINGLE_SPECTR; break; // Одну многослойную сеть прямого распространения для всего спектра.
case typNNR_Co: id=IDM_USE_NNW_COHONEN; break; // Сеть Кохонена.
}
if(i==typUseNNWRec) Ch=1; else Ch=0; SetStMenuItem_(hMenu,id,1,Ch);}
}

//-----------------------------------------------------------------------------------------------------------
// Полоса прогресса.

void clMain::ShowProgr(UINT i,UINT n)
{
ShowProgress(hwndProgr,hwndPerc,i,n); ProcMess();
}

//-----------------------------------------------------------------------------------------------------------
// Действия при закрытии окна.

void clMain::OnCloseWin(void)
{
if(flBlk!=0) { Message(IDS_Mess_CanNotExit,MB_ST); return;} CheckSaveNNW(); DestroyWindow(hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// Функция главного окна.

LRESULT CALLBACK WndProcMain(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
void ZeroMain(void); // Обнуление указателей.
void FreeMain(void); // Освобождение памяти и удаление классов в программе.
BYTE InitMain(HWND hwnd); // Инициализация - создание класса главного окна.

BYTE flag;

if(msg!=WM_CREATE) { if(MW!=NULL) { LRes=MW->MsgCommand(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) {

default: return DefWindowProc(hwnd,msg,wParam,lParam);

// WM_CREATE ................................................................................................
case WM_CREATE: ZeroMain(); if(InitMain(hwnd)!=0) { PostMessage(hwnd,WM_CLOSE,0,0L); return 0L;} break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: break;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hwnd,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hwnd); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: FreeMain(); PostQuitMessage(0); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Управляющее окно главного окна.

LRESULT CALLBACK DlgProcCntrlMain(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{   
BYTE flag; clMain *MW_;

if(msg!=WM_INITDIALOG) { MW_=(clMain *)GetWindowLong(hDlg,DWL_USER);
if(MW_!=NULL) { LRes=MW_->MsgCommandCntrl(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetWindowLong(hDlg,DWL_USER,(long)lParam); return (LRESULT)TRUE;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hDlg,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hDlg); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: SetWindowLong(hDlg,DWL_USER,0L); break;
}

return FALSE;
}

//-----------------------------------------------------------------------------------------------------------
// Функция обработки сообщений окна спектральной диаграммы.

LRESULT CALLBACK WndSpectrDiag(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE flag;

if(msg!=WM_CREATE) { if(MW!=NULL) { LRes=MW->MsgCommandDiag(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) {

default: return DefWindowProc(hwnd,msg,wParam,lParam);

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: break;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hwnd,COL_WHITE,COL_WHITE); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hwnd); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: FreeMain(); PostQuitMessage(0); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Функция обработки сообщений окна графика сигнала.

LRESULT CALLBACK WndGraphSig(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE flag;

if(msg!=WM_CREATE) { if(MW!=NULL) { LRes=MW->MsgCommandGraphSig(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) {

default: return DefWindowProc(hwnd,msg,wParam,lParam);

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: break;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hwnd,COL_WHITE,COL_WHITE); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hwnd); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: FreeMain(); PostQuitMessage(0); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Функция обработки сообщений окна графика спектра.

LRESULT CALLBACK WndGraphSpectr(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE flag;

if(msg!=WM_CREATE) { if(MW!=NULL) { LRes=MW->MsgCommandGraphSpectr(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) {

default: return DefWindowProc(hwnd,msg,wParam,lParam);

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: break;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hwnd,COL_WHITE,COL_WHITE); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hwnd); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: FreeMain(); PostQuitMessage(0); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Функции обратного вызова для записи звука.

void FunSndCap_CallBack(PNT_DATA Pnt,DWORD szBuf,void *pBuf)
{
clMain *MW_;

MW_=(clMain *)Pnt; if(MW_==NULL) return; MW_->SaveBufSound(szBuf,pBuf);
}

//-----------------------------------------------------------------------------------------------------------
// Функция принятия решения при распознавании звука - метод с накоплением результата распознавания.

BYTE DecSnd_Store(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd)
{
clMain *MW_;

MW_=(clMain *)Pnt; if(MW_==NULL) return 1; if(MW_->GetNumSndRecogn(pLay,typNet,typSnd,numSnd)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Полоса прогресса в главном окне.

void ShowProgrMain(PNT_DATA Pnt,UINT i,UINT n)
{
clMain *MW_;

MW_=(clMain *)Pnt; if(MW_==NULL) return; MW_->ShowProgr(i,n);
}

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна о программе.

INT_PTR CALLBACK DlgAbout(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
switch (message)
{
// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG:	return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND:
if(LOWORD(wParam)==IDOK||LOWORD(wParam)==IDCANCEL) { EndDialog(hDlg,LOWORD(wParam)); return (INT_PTR)TRUE;}
break;
}
return (INT_PTR)FALSE;
}

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна задание параметров спектрального разложения.

INT_PTR CALLBACK DlgParSpectr(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam)
{
int id;

if(hDlg==NULL||MW==NULL) return (INT_PTR)FALSE;

switch(message) {

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: MW->ParSpectr.OnCreateDlg(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK .....................................................................................................
case IDOK: MW->ParSpectr.GetDlg(hDlg); EndDialog(hDlg,1); return (INT_PTR)TRUE;

// IDCANCEL .................................................................................................
case IDCANCEL: EndDialog(hDlg,0); return (INT_PTR)TRUE;
}
break;
}

return (INT_PTR)FALSE;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Cтруктура результата распознавания.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strResRec::strResRec(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление и инициализация параметров.

void strResRec::Zero(void)
{
nSamp=0; prcTrue=prcFalse=prcNo=0.0F; Err=0.0F;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Cтруктура параметров события (звука) внутри файла.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strDBS::strDBS(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strDBS::Zero(void)
{
flUse=flTrain=0; nRep=1; cSnd=0; typSnd=numSnd=UCHAR_MAX; tI=tF=0.0F; typInpData=UCHAR_MAX;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление результатов распознавания.

void strDBS::ZeroRes(void)
{
Res.Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strDBS::Read(FILE *file)
{
int iv; float v;

if(file==NULL) return 1;
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv==0) flUse=0; else flUse=1;
if(fscanf(file,"%d",&iv)==EOF) return 3; if(iv==0) flTrain=0; else flTrain=1;
if(fscanf(file,"%d",&iv)==EOF) return 4; if(iv<=0||iv>UCHAR_MAX) nRep=1; else nRep=(BYTE)iv;
if(fscanf(file,"%s%f%f",TxtStr,&tI,&tF)==EOF) return 5; cSnd=TxtStr[0]; if(tI>tF) { v=tI; tI=tF; tF=v;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strDBS::Write(FILE *file)
{
float v;

if(file==NULL) return 1; if(tI>tF) { v=tI; tI=tF; tF=v;}
if(fprintf(file,"%d %d %d %c %f %f\n",(int)flUse,(int)flTrain,(int)nRep,cSnd,tI,tF)<0) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Печать в строку.

void strDBS::Print(void)
{
char *cpUse,*cpTrain;

if(flUse==0) cpUse="-"; else cpUse="+";
if(flTrain==0) cpTrain="-"; else cpTrain="+";
if(Res.nSamp==0) sprintf(TxtStr,"%s %s %c %d %f %f",cpUse,cpTrain,cSnd,(int)nRep,tI,tF);
else sprintf(TxtStr,"%s %s %c %d %f %f - %f %f %f %f",cpUse,cpTrain,cSnd,(int)nRep,tI,tF,Res.prcTrue,Res.prcFalse,Res.prcNo,Res.Err);
}

//-----------------------------------------------------------------------------------------------------------
// Разложение в спектр.

BYTE strDBS::ProcSpectr(strSndArr *Snd,strParSpProc *Param,BYTE *flStop)
{
BYTE ComputeSpDiag(float *Snd,UINT nSnd,double dt,clSpDiag *Diag,strParSpProc *Param,PNT_DATA Pnt,
  pFunShowProgr FSP,BYTE *flStop); // Расчёт спектральной диаграммы.

BYTE be; UINT nI,nF; float v,tI_,tF_;

Diag.Free_St(); if(Snd==NULL) return 1; if(Snd->IsOK()!=0) return 2;
if(Param==NULL) return 3; if(Param->IsOK()!=0) return 4;
if(tI>tF) { v=tI; tI=tF; tF=v;}
v=Param->Time_Step; tI_=tI-v*0.5F; tF_=tF+v*0.5F; if(tF_<=tI_) return 5;
nI=GetUINT_Test((double)tI_/Snd->dt); if(nI>=Snd->ln) return 6;
nF=GetUINT_Test((double)tF_/Snd->dt); if(nF>=Snd->ln) nF=Snd->ln-1;
if(nI>=nF) return messRet;
be=ComputeSpDiag(Snd->Snd+nI,nF-nI,Snd->dt,&Diag,Param,0UL,NULL,flStop); // Расчёт спектральной диаграммы.
if(be==messRet) return messRet; if(be!=0) return 7;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение спектральных линий.

BYTE strDBS::GetPeaks(BYTE *flStop)
{
BYTE GetTypNumSndChar(char cSnd,BYTE *pTyp,BYTE *pNum); // Нахождение типа звука и номера звука в списке по букве.
BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nPCons,BYTE nSpLines,strSpectrLine *SpLines,
  strParGetPeaks *PGP,BYTE *typNet,BYTE *flErr); // Нахождение относительных амплитуд и частот спектральных линий.

BYTE k,typNet,nPeaks,be,ber; USHRT j; UINT i; clArrFloat *pFlArr; struct strSpectrLine *SpL;
struct strInpLay *pIL; struct strParGetPeaks *PGP;

Peaks.Free(); if(Diag.IsOK_St()!=0) return 1; PGP=&ParGetPeaks; if(PGP->IsOK()!=0) return 2;
nPeaks=nPeaksMax;

SpL=NULL; ber=0;
SpL=new strSpectrLine[nPeaks]; if(SpL==NULL) { ber=3; goto end;}
if(Peaks.Alloc(Diag.nArr,(UINT)nPeaks)!=0) { ber=4; goto end;}

// Нахождение типа звука и номера звука в списке по букве.
if(cSnd=='-') typSnd=numSnd=UCHAR_MAX;
else { if(GetTypNumSndChar(cSnd,&typSnd,&numSnd)!=0) { ber=5; goto end;}}

// Шаги по интервалам спектрального преобразования.
for(i=0;i<Diag.nArr;i++) { if(flStop!=NULL) { if(*flStop!=0) { ber=messRet; goto end;}}
pFlArr=Diag.Get(i); if(pFlArr==NULL) { ber=6; goto end;} if(pFlArr->IsOK()!=0) { ber=7; goto end;}
if(pFlArr->ln>USHRT_MAX) { ber=8; goto end;}
if(typSnd==UCHAR_MAX||numSnd==UCHAR_MAX) typNet=UCHAR_MAX; else typNet=typSnd;
be=FindPeaks((USHRT)pFlArr->ln,pFlArr->Arr,(float)Diag.stLn,nPeaksCons,nPeaks,SpL,PGP,&typNet,NULL);
if(be!=0&&be!=messRet) { ber=9; goto end;}
pIL=Peaks.Get(i); if(pIL==NULL) { ber=10; goto end;} if(pIL->IsOK()!=0) { ber=11; goto end;}
if(pIL->n!=nPeaks) { ber=12; goto end;}
if(be==messRet||typNet!=UCHAR_MAX&&typNet!=typSnd) for(j=0;j<nPeaks;j++) pIL->Values[j]=0.;
else for(k=0;k<nPeaks;k++) pIL->Values[k]=(double)SpL[k].AmpRel;
}

end: SAFE_DELETE_ARR(SpL); if(ber!=0) Peaks.Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение входных данных.

BYTE strDBS::GetInpData(BYTE typNet,BYTE typID,BYTE *flStop)
{
BYTE be;

InpData.Free(); typInpData=UCHAR_MAX;
if(typNet==typNNW_Vowel||typNet==typNNW_Cons) {
be=GetInpDataVC(typID,flStop); if(be!=0&&be!=messRet!=0) return 1; return 0;}
if(typNet==typNNW_Spectr) {
be=GetInpDataSp(flStop);
//mmm xxx aaa
if(be!=0) {
//mmm
sprintf(TxtStr,"GetInpDataSp be: %d",be); MessageBox(NULL,TxtStr,"strDBS::GetInpData",MB_EX);

}

 if(be!=0&&be!=messRet) return 2; return 0;}
return 3;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение входных данных для раздельной сети для гласных или согласных.

BYTE strDBS::GetInpDataVC(BYTE typID,BYTE *flStop)
{
BYTE GetTypNumSndChar(char cSnd,BYTE *pTyp,BYTE *pNum); // Нахождение типа звука и номера звука в списке по букве.
BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nPCons,BYTE nSpLines,strSpectrLine *SpLines,
  strParGetPeaks *PGP,BYTE *typNet,BYTE *flErr); // Нахождение относительных амплитуд и частот спектральных линий.
BYTE GetNInpDataNetVC(BYTE typInp,BYTE typNet,float FreqMax,float dFr,float dFrTri,BYTE nPCons,USHRT *nInp); // Получение числа входных нейронов сети.
BYTE InputDataNetVC(BYTE typInp,BYTE typNet,float FreqMin,float FreqMax,float dFr,float dFrTri,float AmpThr,
  BYTE nPCons,float *Spectr,USHRT nSpectr,strSpectrLine *pSpL,BYTE nSpL,strInpLay *InpLay); // Нахождение входных данных для нейронной сети.

BYTE typNet,nPeaks,be,ber; USHRT nInp,j; UINT i; float dFr,FreqMin,FreqMax,dFrTri,AmpThr; clArrFloat *pFlArr;
struct strSpectrLine *SpL; struct strInpLay *pIL; struct strParGetPeaks *PGP;

InpData.Free(); typInpData=UCHAR_MAX; if(Diag.IsOK_St()!=0) return 1;
PGP=&ParGetPeaks; if(PGP->IsOK()!=0) return 2; nPeaks=nPeaksMax;

FreqMin=ParInpSp.FreqMin;
FreqMax=ParInpSp.FreqMax;
dFrTri=ParInpSp.FreqDiscrTri; if(typID==typDataNNW_Peaks&&typSnd==typNNW_Cons) dFrTri=PGP->FreqDiscrCons;
AmpThr=ParInpSp.AmpThr;
dFr=(float)Diag.stLn;

// Нахождение типа звука и номера звука в списке по букве.
if(cSnd=='-') typSnd=numSnd=UCHAR_MAX; else { if(GetTypNumSndChar(cSnd,&typSnd,&numSnd)!=0) return 3;}

// Получение числа входных нейронов сети.
if(GetNInpDataNetVC(typID,typSnd,FreqMax,dFr,dFrTri,nPeaksCons,&nInp)!=0) return 4;
if(typID==typDataNNW_Peaks) nInp=MIN(nInp,(USHRT)nPeaks);
if(typID==typDataNNW_SpectrRow) { if(Diag.ln>USHRT_MAX) return 5; nInp=MIN(nInp,(USHRT)Diag.ln);}

SpL=NULL; ber=0;
SpL=new strSpectrLine[nPeaks]; if(SpL==NULL) { ber=6; goto end;}
if(InpData.Alloc(Diag.nArr,(UINT)nInp)!=0) { ber=7; goto end;}

// Шаги по интервалам спектрального преобразования.
for(i=0;i<Diag.nArr;i++) { if(flStop!=NULL) { if(*flStop!=0) { ber=messRet; goto end;}}
pFlArr=Diag.Get(i); if(pFlArr==NULL) { ber=8; goto end;} if(pFlArr->IsOK()!=0) { ber=9; goto end;}
if(pFlArr->ln>USHRT_MAX) { ber=10; goto end;} if(pFlArr->ln!=Diag.ln) { ber=11; goto end;}
pIL=InpData.Get(i); if(pIL==NULL) { ber=12; goto end;} if(pIL->IsOK()!=0) { ber=13; goto end;}
if(pIL->n!=nInp) { ber=14; goto end;}

// Нахождение спектральных линий.
if(typID!=typDataNNW_SpectrRow) {
if(typSnd==UCHAR_MAX||numSnd==UCHAR_MAX) typNet=UCHAR_MAX; else typNet=typSnd;
be=FindPeaks((USHRT)pFlArr->ln,pFlArr->Arr,(float)Diag.stLn,nPeaksCons,nPeaks,SpL,PGP,&typNet,NULL);
if(be!=0&&be!=messRet) { ber=15; goto end;}
if(be==messRet||typNet!=UCHAR_MAX&&typNet!=typSnd) { for(j=0;j<nInp;j++) pIL->Values[j]=0.; continue;}}

// Ввод данных в нейронную сеть.
be=InputDataNetVC(typID,typSnd,FreqMin,FreqMax,dFr,dFrTri,AmpThr,nPeaksCons,pFlArr->Arr,
(USHRT)pFlArr->ln,SpL,nPeaks,pIL);
if(be==messRet) for(j=0;j<nInp;j++) pIL->Values[j]=0.;
if(be!=messRet&&be!=0) { ber=16; goto end;}
}

typInpData=typID;

end: SAFE_DELETE_ARR(SpL); if(ber!=0) { InpData.Free(); typInpData=UCHAR_MAX;} return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение входных данных для одной сети для всего спектра.

BYTE strDBS::GetInpDataSp(BYTE *flStop)
{
BYTE InputDataNetSp(float FreqMin,float FreqMax,float dFr,float AmpThr,float *Spectr,USHRT nSpectr,strInpLay *InpLay); // Нахождение входных данных для нейронной сети.

BYTE be,ber; USHRT nInp,j; UINT i; float dFr,FreqMin,FreqMax,AmpThr; clArrFloat *pFlArr;
struct strInpLay *pIL;

InpData.Free(); typInpData=UCHAR_MAX; if(Diag.IsOK_St()!=0) return 1;
FreqMin=ParInpSp.FreqMin;
FreqMax=ParInpSp.FreqMax; if(FreqMax<=0.0F) return 2;
AmpThr=ParInpSp.AmpThr;
dFr=(float)Diag.stLn; nInp=GetUSHRT_Test(FreqMax/dFr);
if(Diag.ln>USHRT_MAX) return 3; nInp=MIN(nInp,(USHRT)Diag.ln);

ber=0;
if(InpData.Alloc(Diag.nArr,(UINT)nInp)!=0) { ber=4; goto end;}

// Шаги по интервалам спектрального преобразования.
for(i=0;i<Diag.nArr;i++) { if(flStop!=NULL) { if(*flStop!=0) { ber=messRet; goto end;}}
pFlArr=Diag.Get(i); if(pFlArr==NULL) { ber=5; goto end;} if(pFlArr->IsOK()!=0) { ber=6; goto end;}
if(pFlArr->ln>USHRT_MAX) { ber=7; goto end;} if(pFlArr->ln!=Diag.ln) { ber=8; goto end;}
pIL=InpData.Get(i); if(pIL==NULL) { ber=9; goto end;} if(pIL->IsOK()!=0) { ber=10; goto end;}
if(pIL->n!=nInp) { ber=11; goto end;}

// Ввод данных в нейронную сеть.
be=InputDataNetSp(FreqMin,FreqMax,dFr,AmpThr,pFlArr->Arr,(USHRT)pFlArr->ln,pIL);
if(be==messRet) for(j=0;j<nInp;j++) pIL->Values[j]=0.;
if(be!=messRet&&be!=0) { ber=12; goto end;}
}

typInpData=typDataNNW_SpectrRow;

end: if(ber!=0) { InpData.Free(); typInpData=UCHAR_MAX;} return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Получение результата распознавания.

BYTE strDBS::GetResult(strNNW *pNNW)
{
BYTE FindErrOutLay(strInpLay *True,strLay *Lay,double *pErr); // Нахождение ошибки выходного слоя нейронов.
BYTE GetNumSound(strLay *pLay,float Err,BYTE *numSnd); // Нахождение номера звука, которому соответствует максимальное значение в выходном массиве нейронов.

BYTE num,typS,flSndSp,be; USHRT n,l; UINT k,nSamp,nTrue,nFalse,nNoRec; float v; double s,sum;
struct strInpLay *pIL,TrueOut; struct strLay *pLay;

ZeroRes(); if(typSnd==UCHAR_MAX||numSnd==UCHAR_MAX) return messRet; if(pNNW==NULL) return 1;
if(pNNW->typ==typNNW_Vowel||pNNW->typ==typNNW_Cons) flSndSp=1; else flSndSp=0;
if(typSnd!=UCHAR_MAX) { if(flSndSp!=0&&typSnd!=pNNW->typ) return messRet;}
if(pNNW->Par.flTypInpData!=typInpData) return 2;
if(pNNW->IsOK_Lay()!=0) return 3; if(InpData.IsOK()!=0) return 4;

// Нахождение размера массива истинного результата распознавания.
switch(pNNW->typ) { default: return 5;
case typNNW_Vowel: n=nVoicesVowel; break; // Гласные звуки.
case typNNW_Cons: n=nVoicesCons; break; // Согласные звуки.
case typNNW_Spectr: n=nVoicesVowel+nVoicesCons; break; // Для всего спектра.
}
if(TrueOut.Alloc(n)!=0) return 6; // Выделение памяти для истинного результата распознавания.
for(l=0;l<TrueOut.n;l++) TrueOut.Values[l]=0.;
num=numSnd; if(pNNW->typ==typNNW_Spectr) num+=nVoicesCons;
if(num<TrueOut.n) TrueOut.Values[num]=1.; // Задание истинного результата распознавания.

nSamp=nTrue=nFalse=nNoRec=0; sum=0.;
// Шаги по интервалам спектрального преобразования.
for(k=0;k<InpData.nData;k++) { pIL=InpData.Get(k); if(pIL==NULL) continue; if(pIL->IsOK()!=0) continue;
if(pNNW->Compute(pIL)!=0) return 7; // Предъявление нейронной сети.
pLay=pNNW->GetOutLay(); if(pLay==NULL) return 8;
if(FindErrOutLay(&TrueOut,pLay,&s)!=0) return 9; // Нахождение ошибки выходного слоя.
be=GetNumSound(pLay,errSoundResNNW,&num); if(be!=messRet&&be!=0) return 10; // Нахождение результата распознавания (номера) звука.
if(be==messRet) num=UCHAR_MAX; else {
if(pNNW->typ==typNNW_Spectr) { if(num<nVoicesVowel) typS=typNNW_Vowel; else { typS=typNNW_Cons; num-=nVoicesVowel;}}}
if(num==numSnd) nTrue++; // Распознанный звук совпал с заданным (или помеха распознана как помеха).
if(num!=UCHAR_MAX&&num!=numSnd) nFalse++; // Заданный звук не помеха, распознался другой звук.
if(num==UCHAR_MAX) nNoRec++; // Заданный звук не помеха, звук не распознан.
sum+=s; nSamp++;}

if(nSamp!=0) { v=1.0F/(float)nSamp; Res.Err=(float)sum*v; v*=100.0F;
Res.prcTrue=(float)nTrue*v; Res.prcFalse=(float)nFalse*v; Res.prcNo=(float)nNoRec*v; Res.nSamp=nSamp;}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Cтруктура базы данных по звукам внутри файла.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strDBSArr::strDBSArr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strDBSArr::~strDBSArr(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strDBSArr::Zero(void)
{
nDBS=0; DBS=NULL; Snd.Zero(); flChange=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strDBSArr::Free(void)
{
SAFE_DELETE_ARR(DBS); nDBS=0; Snd.Free();
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strDBSArr::Alloc(BYTE nDBS_)
{
if(nDBS_==0) return 1; nDBS=nDBS_; DBS=new strDBS[nDBS]; if(DBS==NULL) { nDBS=0; return 2;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива структур.

BYTE strDBSArr::IsOK(void)
{
if(nDBS==0) return 1; if(DBS==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strDBSArr::Read(FILE *file)
{
BYTE i,ber; int iv;

if(file==NULL) return 1;
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<=0) return 3; if(iv>UCHAR_MAX) return 4;
ber=0;
if(Alloc((BYTE)iv)!=0) { ber=5; goto end;}
if(IsOK()!=0) { ber=6; goto end;}
for(i=0;i<nDBS;i++) { if(DBS[i].Read(file)!=0) { ber=7; goto end;}
}
flChange=0;
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strDBSArr::Write(FILE *file)
{
BYTE i;

if(file==NULL) return 1; if(IsOK()!=0) return 2;
if(fprintf(file,"%d\n",(int)nDBS)<0) return 3;
for(i=0;i<nDBS;i++) if(DBS[i].Write(file)!=0) return 4;
flChange=0; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strDBSArr::Read_(char *fName)
{ 
BYTE err; clFileT *FT;

if(IsOKStr(fName)!=0) return 1;
if(IsFileExist_(fName)!=0) return messRet; // Проверка существования файла.
FT=NULL; err=0;
FT=new clFileT(); if(FT==NULL) { err=2; goto end;}
if(FT->Open(fName,0)!=0) { err=3; goto end;} 
if(Read(FT->file)!=0) { err=4; goto end;}
end: SAFE_DELETE(FT); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strDBSArr::Write_(char *fName)
{
BYTE err; clFileT *FT;

if(IsOKStr(fName)!=0) return 1;
FT=NULL; err=0;
FT=new clFileT(); if(FT==NULL) { err=2; goto end;}
if(FT->Open(fName,1)!=0) { err=3; goto end;} 
if(Write(FT->file)!=0) { err=4; goto end;}
end: SAFE_DELETE(FT); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение звукового файла.

BYTE strDBSArr::ReadSound(char *fName)
{
BYTE FillSndArr(clWavData *WAV,strSndArr *Snd); // Заполнение структуры звука.

BYTE err; clWavData *SoundWAV;

if(IsOKStr(fName)!=0) return 1; Snd.Free();
if(IsFileExist_(fName)!=0) return messRet; // Проверка существования файла.
SoundWAV=NULL; err=0;
SoundWAV=new clWavData(); if(SoundWAV==NULL) { err=2; goto end;}
if(SoundWAV->Read(fName)!=0) { err=3; goto end;} // Чтение звукового файла.
if(FillSndArr(SoundWAV,&Snd)!=0) { err=4; goto end;} // Заполнение структуры звука.
end: SAFE_DELETE(SoundWAV); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение списка элементов базы данных.

BYTE strDBSArr::FillLBParam(HWND hDlg)
{
BYTE i; HWND hwnd;

if(hDlg==NULL) return 1; if(IsOK()!=0) return 2; hwnd=GetDlgItem(hDlg,IDC_DBS); if(hwnd==NULL) return 3;
SendMessage(hwnd,LB_RESETCONTENT,0,0);
for(i=0;i<nDBS;i++) { DBS[i].Print(); SendMessage(hwnd,LB_ADDSTRING,0,(LPARAM)(LPSTR)TxtStr);} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Даёт указатель на структуру события (звука) внутри файла.

strDBS *strDBSArr::Get(BYTE num)
{
if(IsOK()!=0) return NULL; if(num>=nDBS) return NULL; return DBS+num;
}

//-----------------------------------------------------------------------------------------------------------
// Разложение в спектр.

BYTE strDBSArr::ProcSpectr(strParSpProc *Param,BYTE *flStop)
{
BYTE i,be;

if(IsOK()!=0) return 1; if(Param==NULL) return 2; if(Param->IsOK()!=0) return 3; if(Snd.IsOK()!=0) return 4;
for(i=0;i<nDBS;i++) { be=DBS[i].ProcSpectr(&Snd,Param,flStop); if(be==messRet) return messRet;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение спектральных линий.

BYTE strDBSArr::GetPeaks(BYTE *flStop)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nDBS;i++) { if(DBS[i].GetPeaks(flStop)!=0) return 2;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение входных данных.

BYTE strDBSArr::GetInpData(BYTE typNet,BYTE typInpData,BYTE *flStop)
{
BYTE i,be,fl;

if(IsOK()!=0) return 1; fl=0;
for(i=0;i<nDBS;i++) { be=DBS[i].GetInpData(typNet,typInpData,flStop);
if(be==messRet) { fl=1; continue;} if(be!=0) return 2;}
if(fl!=0) return messRet; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление результатов распознавания.

void strDBSArr::SetResZero(void)
{
BYTE i;

if(IsOK()!=0) return; for(i=0;i<nDBS;i++) DBS[i].ZeroRes();
}

//-----------------------------------------------------------------------------------------------------------
// Получение результата распознавания.

BYTE strDBSArr::GetResult(strNNW *pNNW,BYTE flAll)
{
BYTE i;

if(IsOK()!=0) return 1; if(pNNW==NULL) return 2; if(pNNW->IsOK_Lay()!=0) return 3;
for(i=0;i<nDBS;i++) { if(flAll==0&&DBS[i].flUse==0) continue; DBS[i].GetResult(pNNW);} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Подсчёт результатов по распознаванию для всех звуков списка.

BYTE strDBSArr::CalcResult(strResRec *pRes)
{
BYTE i; UINT nSamp; float v; struct strResRec *pRS;

if(pRes==NULL) return 1; pRes->Zero(); if(IsOK()!=0) return 2;
nSamp=0; for(i=0;i<nDBS;i++) { pRS=&DBS[i].Res; if(pRS->nSamp==0) continue; v=(float)pRS->nSamp;
pRes->prcTrue+=pRS->prcTrue*v;
pRes->prcFalse+=pRS->prcFalse*v;
pRes->prcNo+=pRS->prcNo*v;
pRes->Err+=pRS->Err*v;
nSamp+=pRS->nSamp;}
if(nSamp==0) return messRet; v=1.0F/(float)nSamp;
pRes->prcTrue*=v; pRes->prcFalse*=v; pRes->prcNo*=v; pRes->Err*=v; pRes->nSamp=nSamp; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Cтруктура описания параметров файла, используемого при тренировке сетей.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strDBF::strDBF(void)
{
Zero();
} 

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strDBF::~strDBF(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей.

void strDBF::Zero(void)
{
FName=NamePeople=NULL; Gender=0; flUse=flTrain=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strDBF::Free(void)
{
FreeString(&FName); FreeString(&NamePeople);
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strDBF::Read(FILE *file)
{
int iv;

if(file==NULL) return 1; DBS.Free();
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv==0) flUse=0; else flUse=1;
if(fscanf(file,"%d",&iv)==EOF) return 3; if(iv==0) flTrain=0; else flTrain=1;
if(fscanf(file,"%d",&iv)==EOF) return 4; if(iv==0) Gender=0; else Gender=1;
if(fscanf(file,"\n")==EOF) return 5;
if(ReadString(file,TxtStr,strL_Txt)!=0) return 6;
if(DupString(&FName,TxtStr)!=0) return 8;
if(ReadString(file,TxtStr,strL_Txt)!=0) return 9;
if(DupString(&NamePeople,TxtStr)!=0) return 11;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strDBF::Write(FILE *file)
{
char *cp;

if(file==NULL) return 1;
if(fprintf(file,"%d %d %d\n",(int)flUse,(int)flTrain,(int)Gender)<0) return 2;
if(IsOKStr(FName)!=0) cp="-"; else cp=FName; if(fprintf(file,"%s\n",cp)<0) return 3;
if(IsOKStr(NamePeople)!=0) cp="-"; else cp=NamePeople; if(fprintf(file,"%s\n",cp)<0) return 4;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение баз данных по звукам внутри файла.

BYTE strDBF::ReadDBS(char *Path,char *Dir)
{
BYTE be,err; char *name;

if(IsOKStr(FName)!=0) return 1;
name=NULL; err=0;
if(GetName(&name,Path,Dir,FName,extDBS)!=0) { err=2; goto end;}
be=DBS.Read_(name); // Чтение базы данных по звукам из файла.
if(be==messRet) { Message_(NULL,IDS_Err_NoFileDBS,FName,MB_IN); err=3; goto end;}
if(be!=0) { Message_(NULL,IDS_Err_CanNotReadDBS,FName,MB_IN); err=4; goto end;}
if(GetName(&name,Path,Dir,FName,extWAV)!=0) { err=5; goto end;}
be=DBS.ReadSound(name); // Чтение звукового файла.
if(be==messRet) { Message_(NULL,IDS_Err_NoFileWAV,FName,MB_IN); err=6; goto end;}
if(be!=0) { Message_(NULL,IDS_Err_CanNotReadWAV,FName,MB_IN); err=7; goto end;}
end: FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Запись баз данных по звукам внутри файла.

BYTE strDBF::WriteDBS(char *Path,char *Dir)
{
BYTE err; char *name;

if(IsOKStr(FName)!=0) return 1;
name=NULL; err=0;
if(GetName(&name,Path,Dir,FName,extDBS)!=0) { err=2; goto end;}
if(DBS.Write_(name)!=0) { err=3; goto end;}
end: FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Печать в строку.

void strDBF::Print(void)
{
char *cpGend,*cpUse,*cpTrain;

if(flUse==0) cpUse="-"; else cpUse="+";
if(flTrain==0) cpTrain="-"; else cpTrain="+";
if(Gender==0) cpGend="муж."; else cpGend="жен.";
if(Res.nSamp==0) sprintf(TxtStr,"%s %s %s %s  (%s)" ,cpUse,cpTrain,cpGend,FName,NamePeople);
else sprintf(TxtStr,"%s %s %s %s  (%s) - %f %f %f %f" ,cpUse,cpTrain,cpGend,FName,NamePeople,Res.prcTrue,Res.prcFalse,Res.prcNo,Res.Err);
}

//-----------------------------------------------------------------------------------------------------------
// Разложение в спектр.

BYTE strDBF::ProcSpectr(strParSpProc *Param,BYTE *flStop)
{
return DBS.ProcSpectr(Param,flStop);
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение спектральных линий.

BYTE strDBF::GetPeaks(BYTE *flStop)
{
return DBS.GetPeaks(flStop);
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение входных данных.

BYTE strDBF::GetInpData(BYTE typNet,BYTE typInpData,BYTE *flStop)
{
return DBS.GetInpData(typNet,typInpData,flStop);
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление результатов распознавания.

void strDBF::SetResZero(void)
{
Res.Zero(); DBS.SetResZero();
}

//-----------------------------------------------------------------------------------------------------------
// Получение результата распознавания.

BYTE strDBF::GetResult(strNNW *pNNW,BYTE flAll)
{
SetResZero(); if(DBS.GetResult(pNNW,flAll)!=0) return 1; if(DBS.CalcResult(&Res)!=0) return 2; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Cтруктура базы данных по всем файлам для тренировки нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strDBFArr::strDBFArr(void)
{
Zero();
} 

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strDBFArr::~strDBFArr(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.


void strDBFArr::Zero(void)
{
n=0; DBF=NULL; PathDir=NameFile=NULL; flChange=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strDBFArr::Free(void)
{
FreeDBF(); FreeString(&PathDir); FreeString(&NameFile);
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти от массива структур.

void strDBFArr::FreeDBF(void)
{
SAFE_DELETE_ARR(DBF); n=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strDBFArr::AllocDBF(BYTE n_)
{
FreeDBF(); if(n_==0) return 1; n=n_; DBF=new strDBF[n]; if(DBF==NULL) { n=0; return 2;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива структур.

BYTE strDBFArr::IsOK_DBF(void)
{
if(n==0) return 1; if(DBF==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Даёт указатель на структуру базы данных файла;

strDBF *strDBFArr::Get(BYTE num)
{
if(IsOK_DBF()!=0) return NULL; if(num>=n) return NULL; return DBF+num;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strDBFArr::Read(FILE *file)
{
BYTE i,ber; int iv;

FreeDBF(); if(file==NULL) return 1;
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<=0) return 3; if(iv>UCHAR_MAX) return 4;
ber=0;
if(AllocDBF((BYTE)iv)!=0) { ber=5; goto end;}
if(IsOK_DBF()!=0) { ber=6; goto end;}
for(i=0;i<n;i++) if(DBF[i].Read(file)!=0) { ber=7; goto end;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strDBFArr::Write(FILE *file)
{
BYTE i;

if(file==NULL) return 1; if(IsOK_DBF()!=0) return 2;
if(fprintf(file,"%d\n",(int)n)<0) return 3;
for(i=0;i<n;i++) if(DBF[i].Write(file)!=0) return 4;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strDBFArr::Read_(char *Path,char *Name)
{ 
BYTE err; char *fName; clFileT *FT;

flChange=0; if(IsOKStr(Name)!=0) return 1;
FreeString(&PathDir); if(IsOKStr(Path)==0) DupString(&PathDir,Path);
FreeString(&NameFile); DupString(&NameFile,Name);
fName=NULL; FT=NULL; err=0;
if(GetName(&fName,Path,NULL,Name,extDBF)!=0) { err=2; goto end;}
FT=new clFileT(); if(FT==NULL) { err=3; goto end;}
if(FT->Open(fName,0)!=0) { err=4; goto end;} 
if(Read(FT->file)!=0) { err=5; goto end;}
if(ReadDBS(Path)!=0) { err=6; goto end;}
end: SAFE_DELETE(FT); FreeString(&fName); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strDBFArr::Write_(char *Path,char *Name)
{
BYTE err; char *fName; clFileT *FT;

if(IsOKStr(Name)!=0) return 1;
fName=NULL; FT=NULL; err=0;
if(GetName(&fName,Path,NULL,Name,extDBF)!=0) { err=2; goto end;}
FT=new clFileT(); if(FT==NULL) { err=2; goto end;}
if(FT->Open(fName,1)!=0) { err=3; goto end;} 
if(Write(FT->file)!=0) { err=4; goto end;}
if(WriteDBS(Path)!=0) { err=5; goto end;}
flChange=0;
end: SAFE_DELETE(FT); FreeString(&fName); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strDBFArr::Write_(void)
{
return Write_(PathDir,NameFile);
}

//-----------------------------------------------------------------------------------------------------------
// Чтение баз данных по звукам внутри файла.

BYTE strDBFArr::ReadDBS(char *Path)
{
BYTE i;

if(IsOK_DBF()!=0) return 1; for(i=0;i<n;i++) DBF[i].ReadDBS(Path,NULL); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись баз данных по звукам внутри файла.

BYTE strDBFArr::WriteDBS(char *Path)
{
BYTE i;

if(IsOK_DBF()!=0) return 1; for(i=0;i<n;i++) if(DBF[i].DBS.flChange!=0) DBF[i].WriteDBS(Path,NULL); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка флага изменения.

BYTE strDBFArr::SetFlagChange(BYTE num,BYTE flag)
{
BYTE fl;

fl=flChange; if(flag==0) fl&=~(1<<num); else fl|=1<<num; if(flChange==fl) return 0; flChange=fl; return 1;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление результатов распознавания.

void strDBFArr::SetResZero(void)
{
BYTE i;

if(IsOK_DBF()!=0) return; for(i=0;i<n;i++) DBF[i].SetResZero();
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Cтруктура пункта данных для тренировки нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strDataTrain::strDataTrain(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strDataTrain::Zero(void)
{
pFlUseFile=pFlUseSnd=pFlTrainFile=pFlTrainSnd=NULL; flUse=flTrain=0; InpLay=NULL; TrueOut=NULL; nRep=1;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива структур.

BYTE strDataTrain::IsOK(void)
{
if(InpLay==NULL) return 1; if(TrueOut==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка флагов использования и тренировки.

void strDataTrain::SetFlags(void)
{
flUse=1;
if(pFlUseFile!=NULL) { if(*pFlUseFile==0) flUse=0;}
if(flUse!=0&&pFlUseSnd!=NULL) { if(*pFlUseSnd==0) flUse=0;}
flTrain=1;
if(pFlTrainFile!=NULL) { if(*pFlTrainFile==0) flTrain=0;}
if(flTrain!=0&&pFlTrainSnd!=NULL) { if(*pFlTrainSnd==0) flTrain=0;}
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Cтруктура массива данных для тренировки нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strDataTrainArr::strDataTrainArr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strDataTrainArr::~strDataTrainArr(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strDataTrainArr::Zero(void)
{
nDT=0; DT=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strDataTrainArr::Free(void)
{
SAFE_DELETE_ARR(DT); nDT=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strDataTrainArr::Alloc(UINT nDT_)
{
Free(); if(nDT_==0) return 1; DT=new strDataTrain[nDT_]; if(DT==NULL) return 2; nDT=nDT_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива структур.

BYTE strDataTrainArr::IsOK(void)
{
if(DT==NULL) return 1; if(nDT==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение указателя на структуру данных.

strDataTrain *strDataTrainArr::Get(UINT num)
{
if(IsOK()!=0) return NULL; if(num>=nDT) return NULL; return DT+num;
}

//-----------------------------------------------------------------------------------------------------------
// Установка флагов использования и тренировки.

BYTE strDataTrainArr::SetFlags(void)
{
UINT i;

if(IsOK()!=0) return 1; for(i=0;i<nDT;i++) DT[i].SetFlags(); return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Cтруктура статистики для звука.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strStatSnd::strStatSnd(void)
{
Zero(); c=0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление параметров.

void strStatSnd::Zero(void)
{
nIntTrain=nIntCntrl=0; nSampTrain=nSampCntrl=0;
}

//-----------------------------------------------------------------------------------------------------------
// Печать в строку.

void strStatSnd::Print(void)
{
sprintf(TxtStr,"%c     -     %d %d     -     %u %u",c,(int)nIntTrain,(int)nIntCntrl,nSampTrain,nSampCntrl);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Cтруктура статистики для набора звуков.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strStatSndAll::strStatSndAll(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strStatSndAll::~strStatSndAll(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strStatSndAll::Zero(void)
{
nSnd=0; StatSnd=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strStatSndAll::Free(void)
{
SAFE_DELETE_ARR(StatSnd); nSnd=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strStatSndAll::Alloc(BYTE nSnd_)
{
if(nSnd_==0) return 1; Free(); StatSnd=new strStatSnd[nSnd_]; if(StatSnd==NULL) return 2; nSnd=nSnd_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strStatSndAll::IsOK(void)
{
if(nSnd==0) return 1; if(StatSnd==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение списка.

BYTE strStatSndAll::FillLB(HWND hDlg,int id)
{
BYTE i; HWND hwnd;

if(hDlg==NULL) return 1; if(id<=0) return 2; if(IsOK()!=0) return 3;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 4;
SendMessage(hwnd,LB_RESETCONTENT,0,0);
for(i=0;i<nSnd;i++) { StatSnd[i].Print(); SendMessage(hwnd,LB_ADDSTRING,0,(LPARAM)(LPSTR)TxtStr);}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение статистики для звуков.

BYTE FindStatSound(strStatSndAll *pStatAll,strDBFArr *pDBFA,float dTime)
{
BYTE i,j,k,nSnd,num; USHRT *pUS; UINT *pU,nSamp,u; float v,coe; char c; struct strStatSnd *pStat;
struct strDBF *pDBF; struct strDBS *pDBS; struct strStatSnd *pSt;

if(pStatAll==NULL) return 1; if(pStatAll->IsOK()!=0) return 2; nSnd=pStatAll->nSnd; pStat=pStatAll->StatSnd;
if(pDBFA==NULL) return 3; if(pDBFA->IsOK_DBF()!=0) return 4; if(dTime<=0.0F) return 5; coe=1.0F/dTime;
for(k=0;k<nSnd;k++) (pStat+k)->Zero();
for(i=0;i<pDBFA->n;i++) { pDBF=pDBFA->Get(i); if(pDBF==NULL) continue; if(pDBF->DBS.IsOK()!=0) continue;
for(j=0;j<pDBF->DBS.nDBS;j++) { pDBS=pDBF->DBS.Get(j); if(pDBS==NULL) continue; if(pDBS->flUse==0) continue;
c=pDBS->cSnd; num=UCHAR_MAX; for(k=0;k<nSnd;k++) { pSt=pStat+k; if(pSt->c==c) { num=k; break;}}
if(num==UCHAR_MAX) continue; pSt=pStat+num;
if(pDBS->flTrain==0) { pUS=&pSt->nIntCntrl; pU=&pSt->nSampCntrl;}
else { pUS=&pSt->nIntTrain; pU=&pSt->nSampTrain;}
(*pUS)++;
v=pDBS->tF-pDBS->tI; if(v<0.0F) v=-v; nSamp=GetUINT_Test(v*coe); if(nSamp==0) continue;
if(UINT_MAX/nSamp<pDBS->nRep) return 6; u=nSamp*(UINT)pDBS->nRep; if(*pU>UINT_MAX-u) return 7; *pU+=u;}}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна показа статистики для звуков.

INT_PTR CALLBACK DlgShowStatSound(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{
int id; struct strStatSndAll *pStatAll;

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetPosWindowCenter(hDlg);
pStatAll=(strStatSndAll *)lParam; if(pStatAll!=NULL) pStatAll->FillLB(hDlg,IDC_LIST); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK IDCANCEL ............................................................................................
case IDOK: case IDCANCEL: EndDialog(hDlg,0); return (INT_PTR)TRUE;
}
break;
}

return (INT_PTR)FALSE;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс для редактирования базы данных и тренировки нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

clDlgDBF_NNW::clDlgDBF_NNW(void)
{
Zero();
} 

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

clDlgDBF_NNW::~clDlgDBF_NNW(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void clDlgDBF_NNW::Zero(void)
{
hDlg=NULL; ZeroBrushes(); ZeroWaveSynth(); pDataBase=NULL;
pNNW=pNNW_Vowel=pNNW_Cons=pNNW_Spectr=NULL; pParNNW=NULL;
numSel=numFileLoad=numSelSound=UCHAR_MAX; selDBF=NULL; selDBS=NULL;
flPlaySound=0; typPlaySound=0; flStopSound=1;
flTrain=0; flStopTrain=1; flPreProc=flSetData=0; flStopPreProc=flStopSetData=1; flPreProcDone=flSetDataDone=0;
flTypInpData=UCHAR_MAX; flLoadFile=0; flBlk=0; flBlkTime=1; typNet=typNNW_Vowel;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clDlgDBF_NNW::Free(void)
{
UnSelFile(); FreeBrushes(); FreeWaveSynth();
}

//-----------------------------------------------------------------------------------------------------------
// Установка указателя на структуру базы данных по файлам.

void clDlgDBF_NNW::SetPntDataBase(strDBFArr *pDataBase_)
{
pDataBase=pDataBase_;
}

//-----------------------------------------------------------------------------------------------------------
// Установка указателей на структуры нейронных сетей для гласных и согласных.

void clDlgDBF_NNW::SetPntNeurNet(strNNW *pNNW_Vowel_,strNNW *pNNW_Cons_,strNNW *pNNW_Spectr_)
{
pNNW_Vowel=pNNW_Vowel_; pNNW_Cons=pNNW_Cons_; pNNW_Spectr=pNNW_Spectr_;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление кистей для закрашивания окон.

void clDlgDBF_NNW::ZeroBrushes(void)
{
hBrushBkg=hBrushDial=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Создание кистей для закрашивания окон.

void clDlgDBF_NNW::FreeBrushes(void)
{
SAFE_DELETE_OBJECT(hBrushBkg);
SAFE_DELETE_OBJECT(hBrushDial);
}

//-----------------------------------------------------------------------------------------------------------
// Создание кистей для закрашивания окон.

BYTE clDlgDBF_NNW::CreateBrushes(void)
{
FreeBrushes();
hBrushBkg=CreateSolidBrush(COL_WHITE); if(hBrushBkg==NULL) return 1;
hBrushDial=CreateSolidBrush(ColDial); if(hBrushDial==NULL) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя на массив для вывода синтезированного звука.

void clDlgDBF_NNW::ZeroWaveSynth(void)
{
pWaveSynth=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массива для вывода синтезированного звука.

void clDlgDBF_NNW::FreeWaveSynth(void)
{
SAFE_DELETE_ARR(pWaveSynth);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива для вывода синтезированного звука.

BYTE clDlgDBF_NNW::CreateWaveSynth(UINT nWaveSynth)
{
FreeWaveSynth(); if(nWaveSynth==0) return 1;
pWaveSynth=new float[nWaveSynth]; if(pWaveSynth==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива структур базы данных.

BYTE clDlgDBF_NNW::IsOK_DBF(void)
{
if(pDataBase==NULL) return 1; if(pDataBase->IsOK_DBF()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение изменений в файл базы данных.

BYTE clDlgDBF_NNW::SaveFileDBF(void)
{
if(pDataBase==NULL) return 1; if(pDataBase->Write_()!=0) return 2;
EnableChWin(hDlg,IDC_SAVE,pDataBase->flChange); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при выборе другого файла.

void clDlgDBF_NNW::UnSelFile(void)
{
numSel=UCHAR_MAX; selDBF=NULL; UnSelSound(); ClearList(hDlg,IDC_DBS); flLoadFile=0;
SetChBox(hDlg,IDC_FILE_USE,0); ShowChWin(hDlg,IDC_FILE_USE,0);
SetChBox(hDlg,IDC_FILE_TRAIN,0); ShowChWin(hDlg,IDC_FILE_TRAIN,0);
}

//-----------------------------------------------------------------------------------------------------------
// Действия при выборе другой строки в списке файлов.

BYTE clDlgDBF_NNW::OnSelChangeFile(void)
{
long msg; HWND hwnd;

if(hDlg==NULL) return 1; hwnd=GetDlgItem(hDlg,IDC_DBF); if(hwnd==NULL) return 2;
msg=SendMessage(hwnd,LB_GETCURSEL,0,0); if(msg==LB_ERR) return 3; if(msg>=UCHAR_MAX) return 4;
if(numSel==(BYTE)msg) return 0; UnSelFile(); numSel=(BYTE)msg; ClearList(hDlg,IDC_DBS);
if(IsOK_DBF()!=0) return 5; selDBF=pDataBase->Get(numSel); if(selDBF==NULL) return 6;
selDBF->DBS.FillLBParam(hDlg);
SetChBox(hDlg,IDC_FILE_USE,selDBF->flUse); ShowChWin(hDlg,IDC_FILE_USE,1);
SetChBox(hDlg,IDC_FILE_TRAIN,selDBF->flTrain); ShowChWin(hDlg,IDC_FILE_TRAIN,1);
if(SetWinParFile()!=0) ClearWinParFile(); // Установка параметров файла базы данных в окнах.
SetFlagLoadFile(); // Установка флага загрузки файла.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров файла базы данных в окнах.

BYTE clDlgDBF_NNW::SetWinParFile(void)
{
char *cp;

if(hDlg==NULL) return 1; if(selDBF==NULL) return 2;
cp=selDBF->FName; if(IsOKStr(cp)!=0) cp="-"; SetDlgItemText(hDlg,IDC_NAME_FILE_DBF,cp);
cp=selDBF->NamePeople; if(IsOKStr(cp)!=0) cp="-"; SetDlgItemText(hDlg,IDC_NAME_PERSON,cp);
CheckRadioButton(hDlg,IDC_RADIO_GEND_M,IDC_RADIO_GEND_W,IDC_RADIO_GEND_M+(int)selDBF->Gender);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Очистка окон параметров файла базы данных в окнах.

void clDlgDBF_NNW::ClearWinParFile(void)
{
if(hDlg==NULL) return;
SetDlgItemText(hDlg,IDC_NAME_FILE_DBF,"-");
SetDlgItemText(hDlg,IDC_NAME_PERSON,"-");
CheckRadioButton(hDlg,IDC_RADIO_GEND_M,IDC_RADIO_GEND_W,IDC_RADIO_GEND_M);
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка файла и построение диаграммы.

BYTE clDlgDBF_NNW::LoadFile(void)
{
BYTE num; long msg; HWND hwnd; struct strDBF *pDBF;

numFileLoad=UCHAR_MAX; if(MW==NULL) return 1; if(IsOK_DBF()!=0) return 2;
if(hDlg==NULL) return 3; hwnd=GetDlgItem(hDlg,IDC_DBF); if(hwnd==NULL) return 4;
msg=SendMessage(hwnd,LB_GETCURSEL,0,0); if(msg==LB_ERR) return 5; if(msg>=UCHAR_MAX) return 6; num=(BYTE)msg;
pDBF=pDataBase->Get(num); if(pDBF==NULL) return 7; if(IsOKStr(pDBF->FName)!=0) return 8;
if(MW->LoadProcFile(pDataBase->PathDir,NULL,pDBF->FName)!=0) return 9; numFileLoad=num; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка флага загрузки файла.

BYTE clDlgDBF_NNW::SetFlagLoadFile(void)
{
BYTE ber; char *name;

flLoadFile=0; if(MW==NULL) return 1; if(IsOKStr(MW->FileNameWAV)!=0) return 2;
if(pDataBase==NULL) return 3; if(selDBF==NULL) return 4; if(IsOKStr(selDBF->FName)!=0) return 5;
name=NULL; ber=0;
if(GetName(&name,pDataBase->PathDir,NULL,selDBF->FName,extWAV)!=0) { ber=6; goto end;}
if(CompareStr(name,MW->FileNameWAV)==0) flLoadFile=1;
end: FreeString(&name); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при выборе другого звука.

void clDlgDBF_NNW::UnSelSound(void)
{
numSelSound=UCHAR_MAX; selDBS=NULL;
SetChBox(hDlg,IDC_SOUND_USE,0); ShowChWin(hDlg,IDC_SOUND_USE,0);
SetChBox(hDlg,IDC_SOUND_TRAIN,0); ShowChWin(hDlg,IDC_SOUND_TRAIN,0);
EnableChWin(hDlg,IDC_PLAY_SND,0);
EnableChWin(hDlg,IDC_PLAY_SND_PEAKS,0);
if(MW!=NULL) MW->UpdateWinDiag(); // Перерисовка окна диаграммы в главном окне.
}

//-----------------------------------------------------------------------------------------------------------
// Действия при выборе другой строки в списке звуков.

BYTE clDlgDBF_NNW::OnSelChangeSound(void)
{
long msg; HWND hwnd;

UnSelSound(); if(hDlg==NULL) return 1; hwnd=GetDlgItem(hDlg,IDC_DBS); if(hwnd==NULL) return 2;
msg=SendMessage(hwnd,LB_GETCURSEL,0,0); if(msg==LB_ERR) return 3; if(msg>=UCHAR_MAX) return 4;
numSelSound=(BYTE)msg; if(selDBF==NULL) return 5; selDBS=selDBF->DBS.Get(numSelSound);
if(selDBS!=NULL) {
SetChBox(hDlg,IDC_SOUND_USE,selDBS->flUse); ShowChWin(hDlg,IDC_SOUND_USE,1);
SetChBox(hDlg,IDC_SOUND_TRAIN,selDBS->flTrain); ShowChWin(hDlg,IDC_SOUND_TRAIN,1);
EnableChWin(hDlg,IDC_PLAY_SND,1);
EnableChWin(hDlg,IDC_PLAY_SND_PEAKS,1);
}
else {
EnableChWin(hDlg,IDC_PLAY_SND,0);
EnableChWin(hDlg,IDC_PLAY_SND_PEAKS,0);}

if(SetWinParSound()!=0) ClearWinParSound(); // Установка параметров отрезка звука базы данных в окнах.
if(MW!=NULL) MW->UpdateWinDiag(); // Перерисовка окна диаграммы в главном окне.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение изображения звука на диаграмме.

BYTE clDlgDBF_NNW::FindSoundDiag(void)
{
if(MW==NULL) return 1; if(selDBS==NULL) return 2; if(flLoadFile==0) return 3;
if(MW->SetTimeDiag(MIN(selDBS->tI,selDBS->tF))!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров отрезка звука базы данных в окнах.

BYTE clDlgDBF_NNW::SetWinParSound(void)
{
if(hDlg==NULL) return 1; if(selDBS==NULL) return 2;
SetByteEdt(hDlg,IDC_REPEATS,selDBS->nRep);
sprintf(TxtStr,"%c",selDBS->cSnd); SetDlgItemText(hDlg,IDC_NAME_SOUND,TxtStr);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Очистка окон параметров отрезка звука базы данных в окнах.

void clDlgDBF_NNW::ClearWinParSound(void)
{
if(hDlg==NULL) return; SetByteEdt(hDlg,IDC_REPEATS,1); SetDlgItemText(hDlg,IDC_NAME_SOUND,"-");
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении выбранной строки файла.

BYTE clDlgDBF_NNW::OnChangeStrFile(void)
{
long msg; HWND hwnd;

SetFlagChange(0,1); if(hDlg==NULL) return 1; hwnd=GetDlgItem(hDlg,IDC_DBF); if(hwnd==NULL) return 2;
if(numSel==UCHAR_MAX) return 3; if(selDBF==NULL) return 4;
SendMessage(hwnd,LB_DELETESTRING,(WPARAM)numSel,0); selDBF->Print();
msg=SendMessage(hwnd,LB_INSERTSTRING,(WPARAM)numSel,(LPARAM)(LPCTSTR)TxtStr);
if(msg==LB_ERR||msg==LB_ERRSPACE) return 5;
SendMessage(hwnd,LB_SETCURSEL,(WPARAM)numSel,0); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении выбранной строки звука.

BYTE clDlgDBF_NNW::OnChangeStrSound(void)
{
long msg; HWND hwnd;

SetFlagChange(1,1); if(hDlg==NULL) return 1; hwnd=GetDlgItem(hDlg,IDC_DBS); if(hwnd==NULL) return 2;
if(numSelSound==UCHAR_MAX) return 3; if(selDBS==NULL) return 4;
if(selDBF==NULL) return 5; selDBF->DBS.flChange=1;
SendMessage(hwnd,LB_DELETESTRING,(WPARAM)numSelSound,0); selDBS->Print();
msg=SendMessage(hwnd,LB_INSERTSTRING,(WPARAM)numSelSound,(LPARAM)(LPCTSTR)TxtStr);
if(msg==LB_ERR||msg==LB_ERRSPACE) return 6;
SendMessage(hwnd,LB_SETCURSEL,(WPARAM)numSelSound,0); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при открытии диалогового окна.

BYTE clDlgDBF_NNW::OnOpenDlg(HWND hDlg_)
{
if(hDlg_==NULL) return 1; hDlg=hDlg_;
if(CreateBrushes()!=0) return 2; // Создание кистей для закрашивания окон.
SetPosWindowCenter(hDlg); // Помещение окна в центр другого окна или экрана.

hwndProgr=InitProgress(hDlg,IDC_PROGR); // Инициализация окна показа процента выполнения работы.
SetColProgr(hwndProgr,COL_WHITE,COL_BLUE); // Установка цветов полосы прогресса.

SetTxtBtnPreProc(); // Установка текста в кнопку предварительной обработки.
SetTxtBtnTrain(); // Установка текста в кнопку тренировки сети.
SetTxtBtnPlaySound(0); // Установка текста в кнопку воспроизведения звука.
SetTxtBtnPlaySound(1); // Установка текста в кнопку синтеза звука.
SetTxtBtnBlockSetTime(); // Установка текста в кнопку блокировки изменения времени в базе данных.

ParTrain.Read(PathToProgDir,NameParTrain); // Чтение параметров тренировки сети.
SetHeaderWinAlpha(); // Установка заголовка окна шага.

InitParNNW(); // Инициализация структур параметров нейронных сетей.
SetPntNNW(); // Установка указателей на структуры нейронной сети и параметров нейронной сети.

// Установка окон редактирования.
CheckRadioButton(hDlg,IDC_RADIO_VOWEL,IDC_RADIO_SPECTR,IDC_RADIO_VOWEL+(int)typNet); // Установка типа сети.
SetNameNNW(typNNW_Vowel); SetNameNNW(typNNW_Cons); SetNameNNW(typNNW_Spectr); // Установка имён файлов нейронных сетей.
ShowHideWinStepTrain(); // Визуализация и скрытие окон, относящихся к установке шага или адаптивного шага.
SetNameTrainMeth(); // Установка названия метода тренировки.
SetFlEdt(hDlg,IDC_FREQ_SYNTHESIS,FreqSynthesis_Stand,FormFreq); // Частота синтезатора речи.
SetFlEdt(hDlg,IDC_AMP_SYNTHESIS,AmpSynthesis_Stand,FormAmpNormSig); // Амплитуда синтезатора речи.
SetChBox(hDlg,IDC_CHECK_SYNTH_CORR,1); // Флаг коррекции высоких гармоник.

OnChDataBase(); // Действия при загрузке или закрытии базы данных.

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при закрытии диалогового окна.

void clDlgDBF_NNW::OnCloseDlg(void)
{
UnSelSound(); if(MW!=NULL) MW->OnCloseDlgDBS_NNW(); hwndProgr=NULL; Free();
}

//-----------------------------------------------------------------------------------------------------------
// Действия при загрузке или закрытии базы данных.

void clDlgDBF_NNW::OnChDataBase(void)
{
BYTE fl;

ClearList(hDlg,IDC_DBF); // Очистка списка файлов базы данных.
FillLBFiles(); // Заполнение списка файлов базы данных.
UnSelFile(); // Действия при выборе другого файла.
if(pDataBase==NULL) fl=0; else fl=pDataBase->flChange; EnableChWin(hDlg,IDC_SAVE,fl);
ClearWinParFile(); // Очистка окон параметров файла базы данных в окнах.
ClearWinParSound(); // Очистка окон параметров отрезка звука базы данных в окнах.
flPreProcDone=flSetDataDone=0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка заголовка окна шага.

void clDlgDBF_NNW::SetHeaderWinAlpha(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(hInst==NULL) { cp="Step"; goto end;}
id=IDS_HeaderAlphaConst;
if(ParTrain.flAdaptSt!=0&&ParTrain.methTrain==methTrain_Group) id=IDS_HeaderAlphaAdapt;
if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr; else cp="Step";
end: SetDlgItemText(hDlg,IDC_HEADER_ALPHA,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Установка значения времени в структуре базы данных по звуку.

void clDlgDBF_NNW::SetTimeSound(float time,BYTE fl)
{
if(flLoadFile==0) return; if(numSelSound==UCHAR_MAX) return; if(selDBS==NULL) return; if(flBlkTime!=0) return;
if(fl==0) selDBS->tI=time; else selDBS->tF=time; OnChangeStrSound(); if(MW!=NULL) MW->UpdateWinDiag();
}

//-----------------------------------------------------------------------------------------------------------
// Установка флага изменения.

void clDlgDBF_NNW::SetFlagChange(BYTE num,BYTE flag)
{
if(pDataBase==NULL) return; if(pDataBase->SetFlagChange(num,flag)==0) return;
EnableChWin(hDlg,IDC_SAVE,pDataBase->flChange);
}

//-----------------------------------------------------------------------------------------------------------
// Чтение файла нейронной сети.

BYTE clDlgDBF_NNW::ReadNNW(BYTE typ)
{
BYTE err; int idSFilt; char *ext; struct strNNW *pNNW_;

if(flTrain!=0&&typ==typNet) { SoundBlock(); return messRet;} if(hDlg==NULL) return 1;
switch(typ) { default: return 2;
case typNNW_Vowel:  pNNW_=pNNW_Vowel;  idSFilt=IDS_Filt_NNW_Vowel;  ext=extNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   pNNW_=pNNW_Cons;   idSFilt=IDS_Filt_NNW_Cons;   ext=extNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: pNNW_=pNNW_Spectr; idSFilt=IDS_Filt_NNW_Spectr; ext=extNNW_Spectr; break; // Для всего спектра.
}
if(pNNW_==NULL) return 3; if(pNNW_->typ!=typ) return 4;
strcpy(FileNameN,"");
err=FileNameQuest(hDlg,0,idSFilt,PathToDirNNW,ext,IDS_HeaderDlg_OpenNNW,FileNameN,strL_FileName,
PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 5;
if(CompareStrCase(ExtN,ext)!=0) return 6; strcpy(PathToDirNNW,PathToDirN);
if(pNNW_->Read(PathToDirN,FileNameN,ext)!=0) return 7; SetNameNNW(typ); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение файла нейронной сети.

BYTE clDlgDBF_NNW::SaveNNW(BYTE typ)
{
struct strNNW *pNNW_;

switch(typ) { default: return 1;
case typNNW_Vowel: pNNW_=pNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons: pNNW_=pNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: pNNW_=pNNW_Spectr; break; // Для всего спектра.
}
if(pNNW_==NULL) return 2; if(pNNW_->typ!=typNet) return 3;
if(pNNW_->IsOK_Name()!=0) { SaveAsNNW(typ); return 0;} if(pNNW_->Write()!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение файла нейронной сети под другим именем.

BYTE clDlgDBF_NNW::SaveAsNNW(BYTE typ)
{
BYTE fl,err; int idSFilt; char *ext; struct strNNW *pNNW_;

if(hDlg==NULL) return 1;
switch(typ) { default: return 2;
case typNNW_Vowel:  pNNW_=pNNW_Vowel;  idSFilt=IDS_Filt_NNW_Vowel;  ext=extNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   pNNW_=pNNW_Cons;   idSFilt=IDS_Filt_NNW_Cons;   ext=extNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: pNNW_=pNNW_Spectr; idSFilt=IDS_Filt_NNW_Spectr; ext=extNNW_Spectr; break; // Для всего спектра.
}
if(pNNW_==NULL) return 3; if(pNNW_->typ!=typ) return 4;
fl=0; if(pNNW_->IsOK_Name()==0) { if(StrCopy(FileNameN,strL_FileName,pNNW_->NameFile)==0) fl=1;}
if(fl==0) strcpy(FileNameN,"NNW");
err=FileNameQuest(hDlg,1,idSFilt,PathToDirNNW,ext,IDS_HeaderDlg_SaveNNW,FileNameN,strL_FileName,
PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 5;
if(CompareStrCase(ExtN,ext)!=0) return 6; strcpy(PathToDirNNW,PathToDirN);
if(pNNW_->IsOK_Name()!=0) { if(pNNW_->SetNames(PathToDirN,FileNameN)!=0) return 7; fl=1;} else fl=0;
if(pNNW_->Write(PathToDirN,FileNameN,ext,fl)!=0) return 8; SetNameNNW(typ); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка имени файла нейронной сети.

BYTE clDlgDBF_NNW::SetNameNNW(BYTE typ)
{
int id; char *cp; struct strNNW *pNNW_;

if(hInst==NULL) return 1; if(hDlg==NULL) return 2;
switch(typ) { default: return 3;
case typNNW_Vowel: pNNW_=pNNW_Vowel; id=IDC_NAME_NNW_VOWEL; break; // Для гласных звуков.
case typNNW_Cons: pNNW_=pNNW_Cons; id=IDC_NAME_NNW_CONSONANT; break; // Для согласных звуков.
case typNNW_Spectr: pNNW_=pNNW_Spectr; id=IDC_NAME_NNW_SPECTR; break; // Для всего спектра.
}
cp=NULL; if(pNNW_!=NULL) { if(pNNW_->IsOK_Name()==0) cp=pNNW_->NameFile;}
if(IsOKStr(cp)!=0) { if(LoadString(hInst,IDS_NewNNW,TxtStr,strL_Txt)!=0) cp=TxtStr; else cp="New Neural Network";}
SetDlgItemText(hDlg,id,cp); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение файла параметров нейронной сети.

BYTE clDlgDBF_NNW::ReadParNNW(void)
{
BYTE err; int idSFilt; char *ext;

if(pParNNW==NULL) return 1; if(pParNNW->Par.flType!=typNet) return 2; if(hDlg==NULL) return 3;
switch(pParNNW->Par.flType) { default: return 4;
case typNNW_Vowel:  idSFilt=IDS_Filt_ParNNW_Vowel;  ext=extParNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   idSFilt=IDS_Filt_ParNNW_Cons;   ext=extParNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: idSFilt=IDS_Filt_ParNNW_Spectr; ext=extParNNW_Spectr; break; // Для всего спектра.
}
strcpy(FileNameN,"");
err=FileNameQuest(hDlg,0,idSFilt,PathToDirParNNW,ext,IDS_HeaderDlg_OpenParNNW,FileNameN,
strL_FileName,PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 5;
if(CompareStrCase(ExtN,ext)!=0) return 6; strcpy(PathToDirParNNW,PathToDirN);
if(pParNNW->Read(PathToDirN,FileNameN,ext)!=0) return 7; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение файла параметров нейронной сети.

BYTE clDlgDBF_NNW::SaveParNNW(void)
{
if(pParNNW==NULL) return 1; if(pParNNW->Par.flType!=typNet) return 2;
if(pParNNW->IsOK_Name()!=0) { SaveAsParNNW(); return 0;} if(pParNNW->Write()!=0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение файла параметров нейронной сети под другим именем.

BYTE clDlgDBF_NNW::SaveAsParNNW(void)
{
BYTE fl,err; int idSFilt; char *ext;

if(pParNNW==NULL) return 1; if(pParNNW->Par.flType!=typNet) return 2; if(hDlg==NULL) return 3;
switch(pParNNW->Par.flType) { default: return 4;
case typNNW_Vowel:  idSFilt=IDS_Filt_ParNNW_Vowel;  ext=extParNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   idSFilt=IDS_Filt_ParNNW_Cons;   ext=extParNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: idSFilt=IDS_Filt_ParNNW_Spectr; ext=extParNNW_Spectr; break; // Для всего спектра.
}
fl=0; if(pParNNW->IsOK_Name()==0) { if(StrCopy(FileNameN,strL_FileName,pParNNW->NameFile)==0) fl=1;}
if(fl==0) strcpy(FileNameN,"ParNNW");
err=FileNameQuest(hDlg,1,idSFilt,PathToDirParNNW,ext,IDS_HeaderDlg_SaveParNNW,FileNameN,
strL_FileName,PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 5;
if(CompareStrCase(ExtN,ext)!=0) return 6; strcpy(PathToDirParNNW,PathToDirN);
if(pParNNW->Write(PathToDirN,FileNameN,ext)!=0) return 7;
if(pParNNW->IsOK_Name()!=0) { if(pParNNW->SetNames(PathToDirN,FileNameN)!=0) return 8;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Настройка параметров нейронной сети.

BYTE clDlgDBF_NNW::AdjustParNNW(void)
{
INT_PTR CALLBACK DlgProcParNNW(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam); // Функция диалогового окна задания параметров нейронной сети.

if(hDlg==NULL) return 1; if(hInst==NULL) return 2;
if(pParNNW==NULL) return 3; if(pParNNW->Par.flType!=typNet) return 4; DlgParNNW.pPar=pParNNW;
DialogBoxParam(hInst,MAKEINTRESOURCE(IDD_PAR_NNW),hDlg,(DLGPROC)DlgProcParNNW,(LPARAM)&DlgParNNW);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация новой нейронной сети по заданным параметрам.

BYTE clDlgDBF_NNW::InitNNW(void)
{
BYTE CreateNNW(strNNW *pNNW,strParNNW *pParNNW,USHRT nNeurInp); // Создание структуры нейронной сети по структуре параметров.
BYTE GetN_(USHRT nPoints,USHRT *Np,USHRT NpM,BYTE *Mp); // Даёт минимальное число 'Np', являющееся 2 в целой степени, которое превышает 'nPoints'.

BYTE nNeur,i,M,typ,typInp; USHRT nInp,nWinWid,nPoints,nFrTri; float dFr,dFrTri; double dt,*dp;
struct strParLay *pParLay; struct strDBF *pDBF;

if(flTrain!=0) { SoundBlock(); return 1;}
if(pNNW==NULL) return 2; pNNW->FreeInit(); SetNameNNW(typNet);
if(pParNNW==NULL) return 3; if(pParNNW->Par.flType!=typNet) return 4; if(pParNNW->IsOK_()!=0) return 5;
typ=pParNNW->Par.flType; typInp=pParNNW->Par.flTypInpData;
if(typ==typNNW_Spectr&&typInp!=typDataNNW_SpectrRow) return 6;

// Определение частоты дискретизации спектра, числа необходимых входов сети и других параметров.
pParNNW->Par.FreqMin=ParInpSp.FreqMin;
pParNNW->Par.FreqMax=ParInpSp.FreqMax;
pParNNW->Par.nPCons=0;
pParNNW->Par.dFr=0.0F;

switch(typInp) { default: return 7;
// По пикам.
case typDataNNW_Peaks:
dFrTri=ParGetPeaks.FreqDiscrCons; pParNNW->Par.dFrTri=dFrTri;
switch(typ) { default: return 8;
case typNNW_Vowel: nInp=nPeaksMax; break;
case typNNW_Cons: nFrTri=GetUSHRT_Test(ParInpSp.FreqMax/dFrTri); pParNNW->Par.nPCons=nPeaksCons;
if(nFrTri>USHRT_MAX-(USHRT)nPeaksCons) return 9; nInp=nFrTri+(USHRT)nPeaksCons;
nInp=MIN(nInp,nPeaksMax); break;
}
break;

// По спектру с разложением по треугольным функциям.
case typDataNNW_SpectrTri: if(typ==typNNW_Spectr) return 10;
dFr=ParInpSp.FreqDiscrTri; pParNNW->Par.dFrTri=dFr;
nInp=GetUSHRT_Test(ParInpSp.FreqMax/dFr); break;

// По спектру с разложением огибающей по треугольным функциям.
case typDataNNW_SpectrTriEnv: if(typ!=typNNW_Vowel) return 11;
dFr=ParInpSp.FreqDiscrTri; pParNNW->Par.dFrTri=dFr;
nInp=GetUSHRT_Test(ParInpSp.FreqMax/dFr); break;

// Непосредственно спектр.
case typDataNNW_SpectrRow:
if(pDataBase==NULL) return 12; if(MW==NULL) return 13;
dt=0.;
for(i=0;i<pDataBase->n;i++) { pDBF=pDataBase->Get(i); if(pDBF==NULL) return 14;
dp=&pDBF->DBS.Snd.dt; if(*dp<=0.) return 15;
if(i==0) dt=*dp; else if(dt!=*dp) {
if(LoadString(hInst,IDS_MessDiff_SPS,TxtMem,strL_Txt)!=0) return 16;
sprintf(TxtStr,TxtMem,pDBF->FName); MessageBox(NULL,TxtStr,NULL,MB_EX); return messRet;}}

nWinWid=GetUSHRT_Test((double)MW->ParSpectr.Time_Width/dt);
if(GetN_(nWinWid,&nPoints,0,&M)!=0) return 17;
dFr=(float)(1./(dt*(double)nPoints)); pParNNW->Par.dFr=dFr; pParNNW->Par.dFrTri=0.0F;
nInp=GetUSHRT_Test(ParInpSp.FreqMax/dFr); nInp=MIN(nInp,nPoints/2);
break;
}

// Задание числа выходов нейронной сети.
switch(typ) { default: return 18;
case typNNW_Vowel: nNeur=nVoicesVowel; break;
case typNNW_Cons: nNeur=nVoicesCons; break;
case typNNW_Spectr: nNeur=nVoicesVowel+nVoicesCons; break;
}
pParLay=pParNNW->Get(pParNNW->nLay-1); if(pParLay==NULL) return 19; pParLay->nNeurons=(USHRT)nNeur;

if(CreateNNW(pNNW,pParNNW,nInp)!=0) return 20; // Инициализации нейронной сети.
DrawNet(); // Перерисовка изображения сети.
ClearErrWin(); // Установка ошибок в окнах.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение структуры параметров сети из выбранной сети.

BYTE clDlgDBF_NNW::GetParFromNNW(void)
{
BYTE GetParNNW(strNNW *pNNW,strParNNW *pParNNW); // Получение параметров из структуры нейронной сети.

if(pParNNW==NULL) return 1; if(pParNNW->Par.flType!=typNet) return 2;
if(pNNW==NULL) return 3; if(pNNW->IsOK_Lay()!=0) { Message(IDS_Mess_ErrConfNNW,MB_ST); return 4;}
if(GetParNNW(pNNW,pParNNW)!=0) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Редактирование параметров тренировки сети.

BYTE clDlgDBF_NNW::AdjParTrain(void)
{
INT_PTR CALLBACK DlgParTrainNNW(HWND,UINT,WPARAM,LPARAM); // Функция диалогового окна настройки тренировки сети.

BYTE fl;

if(hDlg==NULL) return 1; if(hInst==NULL) return 2; if(flTrain!=0) { SoundBlock(); return 3;}
fl=(BYTE)DialogBoxParam(hInst,MAKEINTRESOURCE(IDD_PAR_TRAIN_NNW),hDlg,(DLGPROC)DlgParTrainNNW,(LPARAM)&ParTrain);
if(fl==0) return 0;
SetHeaderWinAlpha(); // Установка заголовка окна шага.
SetStepTrain(); // Установка шага тренировки.
ShowHideWinStepTrain(); // Визуализация и скрытие окон, относящихся к установке шага или адаптивного шага.
SetNameTrainMeth(); // Установка названия метода тренировки.
if(ParTrain.Write(PathToProgDir,NameParTrain)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Разложение в спектр.

BYTE clDlgDBF_NNW::ProcSpectr(BYTE *flStop,BYTE flAll)
{
BYTE i,n,be; struct strDBF *pDBF;

if(MW==NULL) return 1; if(IsOK_DBF()!=0) return 2; n=pDataBase->n;
for(i=0;i<n;i++) { pDBF=pDataBase->Get(i); if(pDBF==NULL) return 3; if(flAll==0&&pDBF->flUse==0) goto cont;
be=pDBF->ProcSpectr(&MW->ParSpectr,flStop); if(be==messRet) return messRet;
cont: ShowProgr((UINT)i+1,(UINT)n); // Изображение процента выполнения работы.
if(flStop!=NULL) { if(*flStop!=0) return messRet;}}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение спектральных линий.

BYTE clDlgDBF_NNW::GetPeaks(BYTE *flStop)
{
BYTE i,n,be; struct strDBF *pDBF;

if(IsOK_DBF()!=0) return 1; n=pDataBase->n;
for(i=0;i<n;i++) { pDBF=pDataBase->Get(i); if(pDBF==NULL) return 2; if(pDBF->flUse==0) goto cont;
be=pDBF->GetPeaks(flStop); if(be==messRet) return messRet;
cont: ShowProgr((UINT)i+1,(UINT)n); // Изображение процента выполнения работы.
if(flStop!=NULL) { if(*flStop!=0) return messRet;}}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение входных данных.

BYTE clDlgDBF_NNW::GetInpData(BYTE typInpData,BYTE *flStop)
{
BYTE i,n,fl,be; struct strDBF *pDBF;

if(IsOK_DBF()!=0) return 1; n=pDataBase->n; fl=0;
for(i=0;i<n;i++) { pDBF=pDataBase->Get(i); if(pDBF==NULL) return 3; if(pDBF->flUse==0) goto cont;
be=pDBF->GetInpData(typNet,typInpData,flStop); if(be==messRet) fl=1;
cont: ShowProgr((UINT)i+1,(UINT)n); // Изображение процента выполнения работы.
if(flStop!=NULL) { if(*flStop!=0) return messRet;}}
if(fl!=0) Message(IDS_WrongIntervalsData,MB_IN); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Предобработка: преобразование Фурье, нахождение спектральных линий.

BYTE clDlgDBF_NNW::ProcSpectrPeaks(void)
{
BYTE fl,be,ber;

if(flSetData!=0) { SoundBlock(); return messRet;}
if(IsOK_DBF()!=0) return 1;
flBlk|=1<<numBlkDBF_PreProc; flPreProc=1; flStopPreProc=0; OnChFlagPreProc(); ber=0;

// Разложение в спектр.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Fourier");
if(GetChBox(hDlg,IDC_CHECK_ALL_DATA,&fl)!=0) { ber=2; goto end;}
be=ProcSpectr(&flStopPreProc,fl); if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=3; goto end;}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgr(0,0); // Изображение процента выполнения работы.

// Нахождение спектральных линий.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"SpLines");
be=GetPeaks(&flStopPreProc); if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=4; goto end;}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgr(0,0); // Изображение процента выполнения работы.

end: flBlk&=~(1<<numBlkDBF_PreProc); flPreProc=0; flStopPreProc=1; OnChFlagPreProc();
ShowProgr(0,0); // Изображение процента выполнения работы.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");

flPreProcDone=1; return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Предобработка: заполнение входных массивов сети.

BYTE clDlgDBF_NNW::ProcSetInpData(void)
{
BYTE typInpData,be,ber;

if(flPreProc!=0) { SoundBlock(); return messRet;}
if(flPreProcDone==0) ProcSpectrPeaks(); // Предобработка: преобразование Фурье, нахождение спектральных линий.
if(IsOK_DBF()!=0) return 1;
if(pNNW!=NULL) { if(pNNW->typ!=typNet) return 2; typInpData=pNNW->Par.flTypInpData;}
else { if(pParNNW==NULL) return 3; typInpData=pParNNW->Par.flTypInpData;}
flBlk|=1<<numBlkDBF_InpData; flSetData=1; flStopSetData=0; OnChFlagSetInpData(); ber=0;

// Нахождение входных данных.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"InpData");
be=GetInpData(typInpData,&flStopSetData); if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=4; goto end;}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgr(0,0); // Изображение процента выполнения работы.

end: flBlk&=~(1<<numBlkDBF_InpData); flSetData=0; flStopSetData=1; OnChFlagSetInpData();
ShowProgr(0,0); // Изображение процента выполнения работы.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");

flSetDataDone=1; flTypInpData=typInpData; return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение тренировочного массива.

BYTE clDlgDBF_NNW::FillTrainData(void)
{
BYTE i,j,nSnd,num,flSndSp,typInpData,fl,ber; UINT nD,k; struct strDBF *pDBF; struct strDBSArr *pDBSA;
struct strDBS *pDBS; clInpLayArr *pInpDat; struct strInpLay *pIL,*pTrue; struct strDataTrain *pDT;

DataTrain.Free(); if(IsOK_DBF()!=0) return 1; if(pNNW==NULL) return 2; if(pNNW->typ!=typNet) return 3;
typInpData=pNNW->Par.flTypInpData; if(flSetDataDone==0||flTypInpData!=typInpData) return 4;

// Проверки соответствия параметров нейронной сети праметрам данных.
fl=0;
if(pNNW->Par.FreqMin!=ParInpSp.FreqMin) fl+=1<<0;
if(pNNW->Par.FreqMax!=ParInpSp.FreqMax) fl+=1<<1;
if(typNet==typNNW_Cons&&typInpData==typDataNNW_Peaks) { if(pNNW->Par.nPCons!=nPeaksMax) fl+=1<<2;}
if(fl!=0) { Message(IDS_Err_DiffParNNW,MB_ST); return messRet;}

switch(typNet) { default: return 5;
case typNNW_Vowel: nSnd=nVoicesVowel; break; // Гласные звуки.
case typNNW_Cons: nSnd=nVoicesCons; break; // Согласные звуки.
case typNNW_Spectr: nSnd=nVoicesVowel+nVoicesCons; break; // Применение нейронных сетей сразу для всего спектра.
}

// Заполнение массивов правильных значений выходного слоя сети.
if(FillTrueOut()!=0) return 6;

if(TrueOutSnd.IsOK()!=0) return 7; if(TrueOutSnd.nData!=(UINT)nSnd+1) return 8;
if(typNet==typNNW_Vowel||typNet==typNNW_Cons) flSndSp=1; else flSndSp=0;

ber=0;

// Определение требуемого размера массива данных.
nD=0;

// Шаги по файлам.
for(i=0;i<pDataBase->n;i++) { pDBF=pDataBase->Get(i); if(pDBF==NULL) continue;
pDBSA=&pDBF->DBS; if(pDBSA->IsOK()!=0) continue;

// Шаги по звукам.
for(j=0;j<pDBSA->nDBS;j++) { pDBS=pDBF->DBS.Get(j); if(pDBS==NULL) continue; if(pDBS->nRep==0) continue;
if(flSndSp!=0&&pDBS->typSnd!=typNet&&pDBS->typSnd!=UCHAR_MAX) continue;
if(pDBS->typInpData!=typInpData) continue;
pInpDat=&pDBS->InpData; if(pInpDat->IsOK()!=0) continue;

// Шаги по интервалам спектрального преобразования.
for(k=0;k<pInpDat->nData;k++) { pIL=pInpDat->Get(k); if(pIL==NULL) continue; if(pIL->IsOK()!=0) continue; nD++;}
}}

if(nD==0) { Message(IDS_Err_NoTrainData,MB_ST); ber=messRet; goto end;}

// Выделение памяти.
if(DataTrain.Alloc(nD)!=0) { ber=9; goto end;}

// Заполнение тренировочного массива.
nD=0;

// Шаги по файлам.
for(i=0;i<pDataBase->n;i++) { pDBF=pDataBase->Get(i); if(pDBF==NULL) continue;
pDBSA=&pDBF->DBS; if(pDBSA->IsOK()!=0) continue;

// Шаги по звукам.
for(j=0;j<pDBSA->nDBS;j++) { pDBS=pDBF->DBS.Get(j); if(pDBS==NULL) continue; if(pDBS->nRep==0) continue;
if(flSndSp!=0&&pDBS->typSnd!=typNet&&pDBS->typSnd!=UCHAR_MAX) continue;
if(pDBS->typInpData!=typInpData) continue;
if(pDBS->typSnd==UCHAR_MAX) num=nSnd; else {
num=pDBS->numSnd; if(flSndSp==0&&pDBS->typSnd==typNNW_Cons) num+=nVoicesVowel; if(num>nSnd) num=nSnd;}
pTrue=TrueOutSnd.Get(num); if(pTrue==NULL) { ber=10; goto end;}
pInpDat=&pDBS->InpData; if(pInpDat->IsOK()!=0) continue;

// Шаги по интервалам спектрального преобразования.
for(k=0;k<pInpDat->nData;k++) { pIL=pInpDat->Get(k); if(pIL==NULL) continue; if(pIL->IsOK()!=0) continue;
if(nD>=DataTrain.nDT) { ber=11; goto end;}
pDT=DataTrain.Get(nD); if(pDT==NULL) { ber=12; goto end;}
pDT->pFlUseFile=&pDBF->flUse; pDT->pFlTrainFile=&pDBF->flTrain;
pDT->pFlUseSnd=&pDBS->flUse; pDT->pFlTrainSnd=&pDBS->flTrain;
pDT->nRep=pDBS->nRep; pDT->InpLay=pIL; pDT->TrueOut=pTrue; nD++;
ShowProgr(nD,DataTrain.nDT); // Изображение процента выполнения работы.
}}}

if(nD!=DataTrain.nDT) { ber=13; goto end;}

end: if(ber!=0) DataTrain.Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение массивов правильных значений выходного слоя сети.

BYTE clDlgDBF_NNW::FillTrueOut(void)
{
BYTE nSnd,i,k,ber; struct strInpLay *pTrue;

TrueOutSnd.Free(); if(pNNW==NULL) return 1; if(pNNW->typ!=typNet) return 2;

switch(typNet) { default: return 3;
case typNNW_Vowel: nSnd=nVoicesVowel; break; // Гласные звуки.
case typNNW_Cons: nSnd=nVoicesCons; break; // Согласные звуки.
case typNNW_Spectr: nSnd=nVoicesVowel+nVoicesCons; break; // Применение нейронных сетей сразу для всего спектра.
}

ber=0;
if(TrueOutSnd.Alloc((UINT)nSnd+1,nSnd)!=0) { ber=4; goto end;}
for(i=0;i<nSnd+1;i++) { pTrue=TrueOutSnd.Get(i); if(pTrue==NULL) { ber=5; goto end;}
if(pTrue->Alloc(nSnd)!=0) { ber=6; goto end;}
for(k=0;k<nSnd;k++) pTrue->Values[k]=0.; if(i<nSnd) pTrue->Values[i]=1.;}

end: if(ber!=0) TrueOutSnd.Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Команда на тренировку сети.

void clDlgDBF_NNW::CmndTrainNNW(void)
{
if(flPreProc!=0||flSetData!=0) { SoundBlock(); return;} if(flTrain!=0) { flStopTrain=1; return;}
if(MW!=NULL) { if(MW->IsCaptSound()!=0) { SoundBlock(); return;}}
if(pNNW==NULL) return; if(pNNW->typ!=typNet) return;
if(flPreProcDone==0) ProcSpectrPeaks(); // Предобработка: преобразование Фурье, нахождение спектральных линий.
if(flSetDataDone==0||flTypInpData!=pNNW->Par.flTypInpData) ProcSetInpData(); // Предобработка: заполнение входных массивов сети.
TrainNNW(); // Тренировка нейронной сети.
}

//-----------------------------------------------------------------------------------------------------------
// Тренировка нейронной сети.

BYTE clDlgDBF_NNW::TrainNNW(void)
{
BYTE be,ber;

if(pNNW==NULL) return 1; if(pNNW->typ!=typNet) return 2;
if(pNNW->IsOK_Lay()!=0) { Message(IDS_Mess_ErrConfNNW,MB_ST); return 3;}
flBlk|=1<<numBlkDBF_Train; flTrain=1; flStopTrain=0; OnChFlagTrain();

SetStepTrain(); // Установка шага тренировки.
ClearErrWin(); // Установка ошибок в окнах.

ber=0;

// Заполнение тренировочного массива.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"FillData");
be=FillTrainData(); if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=5; goto end;}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgr(0,0); // Изображение процента выполнения работы.

// Цикл поиска наилучшего начального приближения при случайной инициализации коэффициентов нейронной сети.
if(pNNW->flOK==0) {
be=TrainSearchIniRandom(); if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=6; goto end;}
ShowProgr(0,0); // Изображение процента выполнения работы.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");}

// Тренировка нейронной сети различными методами.
switch(ParTrain.methTrain) { default: break;
case methTrain_Sequent:     be=TrainNNW_Seq(); break; // Последовательный метод тренировки.
case methTrain_SequentRep:  be=TrainNNW_SeqRep(); break; // Последовательный метод многократного распространения ошибки.
case methTrain_SequentLay:  be=TrainNNW_SeqLay(); break; // Последовательный послойный метод тренировки.
case methTrain_Group:       be=TrainNNW_Group(); break; // Групповой метод, в том числе с адаптивным шагом.
case methTrain_GroupSearch: be=TrainNNW_GroupSearch(); break; // Групповой метод поиска.
}
if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=7; goto end;}

end: DataTrain.Free(); TrueOutSnd.Free();
flBlk&=~(1<<numBlkDBF_Train); flTrain=0; flStopTrain=1; OnChFlagTrain();
ShowProgr(0,0); // Изображение процента выполнения работы.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Тренировка нейронной сети последовательным методом.

BYTE clDlgDBF_NNW::TrainNNW_Seq(void)
{
BYTE be; USHRT i,nCycle; double Err,ErrCntrl;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2;
nCycle=0;
repCycle: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(i=0;i<ParTrain.nStTrain;i++) { if(flStopTrain!=0) return messRet;
be=StepTrainSequent(&Err,&ErrCntrl); if(be!=0&&be!=messRet) return 3;
if(be==messRet&&ParTrain.flRandSampl==0) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); return messRet;}
SetErrWin(Err,ErrCntrl); // Установка ошибок в окнах.
pNNW->flOK=1;
ShowProgr((UINT)i+1,(UINT)ParTrain.nStTrain); // Изображение процента выполнения работы.
}
if(nCycle==USHRT_MAX) return 0; nCycle++; goto repCycle; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Тренировка нейронной сети последовательным методом с многократным распространением ошибки.

BYTE clDlgDBF_NNW::TrainNNW_SeqRep(void)
{
BYTE be; USHRT i,nCycle; double Err,ErrCntrl;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2;
nCycle=0;
repCycle: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(i=0;i<ParTrain.nStTrain;i++) { if(flStopTrain!=0) return messRet;
be=StepTrainSequentRep(&Err,&ErrCntrl); if(be!=0&&be!=messRet) return 3;
if(be==messRet&&ParTrain.flRandSampl==0) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); return messRet;}
SetErrWin(Err,ErrCntrl); // Установка ошибок в окнах.
pNNW->flOK=1;
ShowProgr((UINT)i+1,(UINT)ParTrain.nStTrain); // Изображение процента выполнения работы.
}
if(nCycle==USHRT_MAX) return 0; nCycle++; goto repCycle; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Тренировка нейронной сети последовательным послойным методом.

BYTE clDlgDBF_NNW::TrainNNW_SeqLay(void)
{
BYTE be; USHRT i,nCycle; double Err,ErrCntrl;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2;
nCycle=0;
repCycle: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(i=0;i<ParTrain.nStTrain;i++) { if(flStopTrain!=0) return messRet;
be=StepTrainSequentLay(); if(be!=0&&be!=messRet) return 3;
if(be==messRet&&ParTrain.flRandSampl==0) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); return messRet;}
be=StepTrainErr(&Err,&ErrCntrl); // Шаг предъявления образцов с нахождением ошибки.
if(be==messRet&&ParTrain.flRandSampl==0) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); return messRet;}
SetErrWin(Err,ErrCntrl); // Установка ошибок в окнах.
pNNW->flOK=1;
ShowProgr((UINT)i+1,(UINT)ParTrain.nStTrain); // Изображение процента выполнения работы.
}
if(nCycle==USHRT_MAX) return 0; nCycle++; goto repCycle; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Тренировка нейронной сети групповым методом, в том числе с адаптивным шагом.

BYTE clDlgDBF_NNW::TrainNNW_Group(void)
{
BYTE flAdaptSt,be,ber; USHRT k,nCycle; double erN,weiN,erC,weiC,Err,ErrCntrl;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2; flAdaptSt=ParTrain.flAdaptSt;
ber=0;
if(pNNW->AllocVect()!=0) { ber=3; goto end;} // Выделение памяти для векторов.

nCycle=0;
repCycle: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(k=0;k<ParTrain.nStTrain;k++) {
if(flStopTrain!=0) { ber=messRet; goto end;}

// Шаг предъявления образцов при тренировке сети групповым методом обратного распространения ошибки.
if(DataTrain.SetFlags()!=0) { ber=4; goto end;} // Установка флагов использования и тренировки.
be=FindVectGroup(&erN,&weiN,&erC,&weiC); if(be!=0&&be!=messRet) { ber=5; goto end;}
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}

// Шаг предъявления образцов при нахождении адаптивного шага при тренировке сети групповым методом обратного распространения ошибки.
if(flAdaptSt!=0) {
be=StepFindAdaptStepGroup(); if(be!=0&&be!=messRet) { ber=6; goto end;}
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(be==messStop) { Message(IDS_Mess_ZeroAdaptStep,MB_ST); ber=messStop; goto end;}
}
else {
// Установка одинакового шага во все слои.
if(pNNW->SetAlphaConst((double)ParTrain.Alpha)!=0) { ber=7; goto end;}}

// Добавление вектора приращения к коэффициентам и смещениям при групповом обучении.
if(pNNW->AddWeightsShiftsGroup()!=0) { ber=8; goto end;}
pNNW->flChange=1;

// Вывод информации о ходе тренировки.
if(weiN<SmCnst24_d) { ber=9; goto end;} Err=erN/weiN; Err=SQRT(Err);
if(weiC<SmCnst24_d) ErrCntrl=0.; else ErrCntrl=erC/weiC; ErrCntrl=SQRT(ErrCntrl);
SetErrWin(Err,ErrCntrl); // Установка ошибок в окнах.
pNNW->flOK=1;
ShowProgr((UINT)k+1,(UINT)ParTrain.nStTrain); // Изображение процента выполнения работы.
}
if(nCycle==USHRT_MAX) goto end; nCycle++; goto repCycle;

end: pNNW->FreeVect(); return ber;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров тренировки нейронной сети групповым методом поиска.
//struct strParTrainNNWSearch { BYTE nStRepM; float coeStI,coeSt,coeChSt;};
struct strParTrainNNWSearch ParTrNNWSearch={ 60, 0.03F,0.07F,0.15F};

//-----------------------------------------------------------------------------------------------------------
// Тренировка нейронной сети групповым методом поиска.

BYTE clDlgDBF_NNW::TrainNNW_GroupSearch(void)
{
BYTE GetNumInput(strNNW *pNNW,USHRT *nInp); // Получение числа нейронов первого распределительного слоя.
BYTE GetParNNW(strNNW *pNNW,strParNNW *pParNNW); // Получение параметров из структуры нейронной сети.
BYTE GetNumVectParNNW(strParNNW *pParNNW,USHRT nNeurInp,USHRT *nVect);// Получение полного числа коэффициентов и смещений из структуры нейронной сети.
BYTE AbsValue(double *V,USHRT N,double *av); // Норма вектора.

BYTE ind,flStop,be,ber; USHRT i,k,nCycle,nV,nStRep,nPeaksInp;
double stN,stNw,stPr,er,erN,erC,a,c,av,avN,ac,acN,acS,d,wei,weiN,weiC,coeSt,v,Err,ErrCntrl;
struct strArrTrSearch ATS; struct strParNNW Par;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2; if(ParTrNNWSearch.IsOK()!=0) return 3;
if(GetNumInput(pNNW,&nPeaksInp)!=0) return 4; if(nPeaksInp==0) return 5;
if(GetParNNW(pNNW,&Par)!=0) return 6; // Получение параметров из структуры нейронной сети.
if(GetNumVectParNNW(&Par,nPeaksInp,&nV)!=0) return 7; // Получение полного числа коэффициентов и смещений из структуры нейронной сети.
if(ATS.Create(nV)!=0) return 8; // Создание массивов.

ber=0;
if(pNNW->AllocVect()!=0) { ber=9; goto end;} // Выделение памяти для векторов.
if(DataTrain.SetFlags()!=0) { ber=10; goto end;} // Установка флагов использования и тренировки.
be=FindVectGroup(&er,&wei,NULL,NULL); if(be!=0&&be!=messRet) { ber=11; goto end;} // Шаг предъявления образцов.
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(pNNW->GetSetArrSearch(ATS.Vect,nV,0,1)!=0) { ber=12; goto end;} // Получение векторов.
if(AbsValue(ATS.Vect,nV,&av)!=0) { ber=13; goto end;}
if(pNNW->GetSetArrSearch(ATS.Coe,nV,0,0)!=0) { ber=14; goto end;} // Получение коэффициентов.
if(AbsValue(ATS.Coe,nV,&ac)!=0) { ber=15; goto end;}

ind=0; stN=ac; flStop=0;

// Циклы тренировки групповым методом поиска.
nCycle=0;
repCycle: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(k=0;k<ParTrain.nStTrain;k++) { nStRep=0;
if(DataTrain.SetFlags()!=0) { ber=16; goto end;} // Установка флагов использования и тренировки.
repSt: if(av<SmCnst24_d) goto end; if(flStopTrain!=0&&flStop==0) flStop=1;
if(ind==0) coeSt=ParTrNNWSearch.coeStI; else coeSt=ParTrNNWSearch.coeSt;
stPr=stN*coeSt; v=stPr/av; for(i=0;i<nV;i++) ATS.CoeN[i]=ATS.Coe[i]+ATS.Vect[i]*v;

if(pNNW->GetSetArrSearch(ATS.CoeN,nV,1,0)!=0) { ber=17; goto end;} // Установка коэффициентов.
pNNW->flChange=1;
if(FindVectGroup(&erN,&weiN,&erC,&weiC)!=0) { ber=18; goto end;} // Шаг предъявления образцов.
if(pNNW->GetSetArrSearch(ATS.VectN,nV,0,1)!=0) { ber=19; goto end;} // Получение векторов.
if(AbsValue(ATS.VectN,nV,&avN)!=0) { ber=20; goto end;}
if(erN>er) { stN*=ParTrNNWSearch.coeChSt; if(nStRep>ParTrNNWSearch.nStRepM) goto end; nStRep++;
ProcMess(); goto repSt;}

if(AbsValue(ATS.CoeN,nV,&acN)!=0) { ber=21; goto end;}
v=er-erN; if(v<SmCnst24_d) goto end; stN=erN/v*stPr; for(i=0;i<nV;i++) ATS.CoeS[i]=ATS.Coe[i]+ATS.CoeN[i];
if(AbsValue(ATS.CoeS,nV,&acS)!=0) { ber=22; goto end;}
v=stPr*acS; if(v<SmCnst24_d) goto end; a=(er-erN)/v; c=((er+erN)-a*(ac*ac+acN*acN))*0.5; if(c<0.) c=0.;
if(a<SmCnst24_d) goto end; d=(erN-c)/a; stNw=SQRT(d);
stN=MIN(stN,stNw); er=erN; ac=acN; av=avN;
for(i=0;i<nV;i++) { ATS.Coe[i]=ATS.CoeN[i]; ATS.Vect[i]=ATS.VectN[i];}

// Вывод информации о ходе тренировки.
if(weiN<SmCnst24_d) { ber=23; goto end;} Err=erN/weiN; Err=SQRT(Err);
if(weiC<SmCnst24_d) ErrCntrl=0.; else ErrCntrl=erC/weiC; ErrCntrl=SQRT(ErrCntrl);
SetErrWin(Err,ErrCntrl); // Установка ошибок в окнах.
ind=1; pNNW->flOK=1;
ShowProgr((UINT)k+1,(UINT)ParTrain.nStTrain); // Изображение процента выполнения работы.
if(flStop!=0) { ber=messRet; goto end;}}
if(nCycle==USHRT_MAX) goto end; nCycle++; goto repCycle;

end: pNNW->FreeVect(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Шаги поиска начального приближения при тренировке нейронной сети.

BYTE clDlgDBF_NNW::TrainSearchIniRandom(void)
{
BYTE be,ber; USHRT i,j,nStepsRand; UINT *NumRandArr; double Err,ErrMin;

if(pNNW==NULL) return 1; if(pNNW->flOK!=0) return 0; if(pNNW->IsOK_Lay()!=0) return 2;
nStepsRand=ParTrain.nStRand; if(nStepsRand==0) return 0;

NumRandArr=NULL; ber=0;

// Цикл поиска наилучшего начального приближения при случайной инициализации коэффициентов нейронной сети.
pNNW->ZeroInit(); ErrMin=LrgCnst32_d; j=USHRT_MAX;
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Random");

// Заполнение массива случайных чисел.
NumRandArr=new UINT[nStepsRand]; if(NumRandArr==NULL) { ber=3; goto end;}
srand(ParTrain.RandSeq); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();

// Цикл случайного поиска.
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) goto end;
pNNW->ZeroInit(); if(pNNW->RandInit(NumRandArr[i],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=4; goto end;}
pNNW->flChange=1;
be=StepTrainErr(&Err,NULL); if(be!=0&&be!=messRet) { ber=5; goto end;} // Шаг предъявления образцов с нахождением ошибки.
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(Err<ErrMin) { ErrMin=Err; j=i; SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)ErrMin,FormErr);}
ShowProgr((UINT)i+1,(UINT)nStepsRand); // Изображение процента выполнения работы.
if(flStopTrain!=0) { ber=messRet; goto end;}
}
if(j>=nStepsRand) { ber=6; goto end;}
pNNW->ZeroInit(); if(pNNW->RandInit(NumRandArr[j],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=7; goto end;}
pNNW->flChange=1;

end: SAFE_DELETE_ARR(NumRandArr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг предъявления образцов с нахождением ошибки.

BYTE clDlgDBF_NNW::StepTrainErr(double *pErr,double *pErrCntrl)
{
BYTE FindErrOutLay(strInpLay *True,strLay *Lay,double *pErr); // Нахождение ошибки выходного слоя нейронов.

BYTE flCntrl; UINT i,nSamp,nSampCntrl; double sum,sumCntrl,s; struct strDataTrain *pDT; struct strLay *pLay;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2; if(DataTrain.IsOK()!=0) return 3;
if(DataTrain.SetFlags()!=0) return 4; // Установка флагов использования и тренировки.
if(pErr!=NULL) *pErr=0.; if(pErrCntrl!=NULL) *pErrCntrl=0.;

nSamp=nSampCntrl=0; sum=sumCntrl=0.; // Обнуление числа предъявляемых образцов данных и ошибки.

// Шаги по тренировочным образцам.
for(i=0;i<DataTrain.nDT;i++) {
pDT=DataTrain.Get(i); if(pDT==NULL) return 5; if(pDT->IsOK()!=0) return 6;
if(pDT->flUse==0) continue; if(pDT->nRep==0) continue;
if(pDT->flTrain==0) flCntrl=1; else flCntrl=0;
if(pNNW->Compute(pDT->InpLay)!=0) return 7; // Расчёт.

// Нахождение ошибки выходного слоя.
pLay=pNNW->GetOutLay(); if(pLay==NULL) return 8;
if(FindErrOutLay(pDT->TrueOut,pLay,&s)!=0) return 9;
s*=(double)pDT->nRep;
if(flCntrl!=0) { sumCntrl+=s; nSampCntrl+=(UINT)pDT->nRep;} else { sum+=s; nSamp+=(UINT)pDT->nRep;}
ProcMess();
}

if(pErr!=NULL) { if(nSamp==0) *pErr=0.; else *pErr=SQRT(sum/(double)nSamp);}
if(pErrCntrl!=NULL) { if(nSampCntrl==0) *pErrCntrl=0.; else *pErrCntrl=SQRT(sumCntrl/(double)nSampCntrl);}
if(nSamp==0) return messRet;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг предъявления образцов при последовательной тренировке сети методом обратного распространения ошибки.

BYTE clDlgDBF_NNW::StepTrainSequent(double *pErr,double *pErrCntrl)
{
BYTE RandomizeArr(UINT *NumArr,UINT nNumArr,BYTE nCycles); // Случайная перетасовка порядка номеров в массиве.
BYTE FindErrOutLay(strInpLay *True,strLay *Lay,double *pErr); // Нахождение ошибки выходного слоя нейронов.

BYTE flRand,flCntrl,m,be,ber; UINT i,iv,nSamp,nSampCntrl,*NumArr; double sum,sumCntrl,s;
struct strDataTrain *pDT; struct strLay *pLay;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2; if(DataTrain.IsOK()!=0) return 3;
if(DataTrain.SetFlags()!=0) return 4; // Установка флагов использования и тренировки.
flRand=ParTrain.flRandSampl;
if(pErr!=NULL) *pErr=0.; if(pErrCntrl!=NULL) *pErrCntrl=0.;

NumArr=NULL; ber=0;
// Нахождение массива перестановок при случайной перестановке порядка образцов во время обучения.
if(flRand!=0) {
NumArr=new UINT[DataTrain.nDT]; if(NumArr==NULL) { ber=5; goto end;}
for(i=0;i<DataTrain.nDT;i++) NumArr[i]=i;
if(RandomizeArr(NumArr,DataTrain.nDT,nCycleRandSamples)!=0) { ber=6; goto end;}}

nSamp=nSampCntrl=0; sum=sumCntrl=0.; // Обнуление числа предъявляемых образцов данных и ошибки.

// Шаги по тренировочным и контрольным образцам.
for(iv=0;iv<DataTrain.nDT;iv++) { if(flRand==0) i=iv; else i=NumArr[iv];
pDT=DataTrain.Get(i); if(pDT==NULL) { ber=7; goto end;} if(pDT->IsOK()!=0) { ber=8; goto end;}
if(pDT->flUse==0) continue; if(pDT->nRep==0) continue;
if(pDT->flTrain==0) flCntrl=1; else flCntrl=0;

// Шаги повторов.
for(m=0;m<pDT->nRep;m++) {

// Простой расчёт, если это контрольный образец.
if(flCntrl!=0) { if(pNNW->Compute(pDT->InpLay)!=0) { ber=9; goto end;}}
// Шаг обратного распространения ошибки.
else {
if(pNNW->Compute(pDT->InpLay)!=0) { ber=10; goto end;}
be=pNNW->TrainStepSequent(pDT->TrueOut,ParTrain.Alpha,ParTrain.AlphaMin,ParTrain.AlphaMax,ParTrain.flAdaptSt,
ParTrain.flEqualAdaptSt,ParTrain.CoeAdaptStep); if(be!=0&&be!=messStop) { ber=11; goto end;}
if(be==messStop) { Message(IDS_Mess_ZeroAdaptStep,MB_ST); ber=messStop; goto end;}
pNNW->flChange=1;
}

// Нахождение ошибки выходного слоя.
pLay=pNNW->GetOutLay(); if(pLay==NULL) { ber=12; goto end;}
if(FindErrOutLay(pDT->TrueOut,pLay,&s)!=0) { ber=13; goto end;}

if(flCntrl!=0) { sumCntrl+=s; nSampCntrl++;} else { sum+=s; nSamp++;}
ProcMess();
}}

if(pErr!=NULL) { if(nSamp==0) *pErr=0.; else *pErr=SQRT(sum/(double)nSamp);}
if(pErrCntrl!=NULL) { if(nSampCntrl==0) *pErrCntrl=0.; else *pErrCntrl=SQRT(sumCntrl/(double)nSampCntrl);}
if(nSamp==0) { ber=messRet; goto end;}

end: SAFE_DELETE_ARR(NumArr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг предъявления образцов при последовательной тренировке сети методом повторного обратного распространения ошибки.

BYTE clDlgDBF_NNW::StepTrainSequentRep(double *pErr,double *pErrCntrl)
{
BYTE RandomizeArr(UINT *NumArr,UINT nNumArr,BYTE nCycles); // Случайная перетасовка порядка номеров в массиве.
BYTE FindErrOutLay(strInpLay *True,strLay *Lay,double *pErr); // Нахождение ошибки выходного слоя нейронов.

BYTE flRand,flCntrl,m,ber; UINT i,iv,nSamp,nSampCntrl,*NumArr; double sum,sumCntrl,s;
struct strDataTrain *pDT; struct strLay *pLay;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2; if(DataTrain.IsOK()!=0) return 3;
if(DataTrain.SetFlags()!=0) return 4; // Установка флагов использования и тренировки.
flRand=ParTrain.flRandSampl;
if(pErr!=NULL) *pErr=0.; if(pErrCntrl!=NULL) *pErrCntrl=0.;

NumArr=NULL; ber=0;
// Нахождение массива перестановок при случайной перестановке порядка образцов во время обучения.
if(flRand!=0) {
NumArr=new UINT[DataTrain.nDT]; if(NumArr==NULL) { ber=5; goto end;}
for(i=0;i<DataTrain.nDT;i++) NumArr[i]=i;
if(RandomizeArr(NumArr,DataTrain.nDT,nCycleRandSamples)!=0) { ber=6; goto end;}}

nSamp=nSampCntrl=0; sum=sumCntrl=0.; // Обнуление числа предъявляемых образцов данных и ошибки.

// Шаги по тренировочным и контрольным образцам.
for(iv=0;iv<DataTrain.nDT;iv++) { if(flRand==0) i=iv; else i=NumArr[iv];
pDT=DataTrain.Get(i); if(pDT==NULL) { ber=7; goto end;} if(pDT->IsOK()!=0) { ber=8; goto end;}
if(pDT->flUse==0) continue; if(pDT->nRep==0) continue;
if(pDT->flTrain==0) flCntrl=1; else flCntrl=0;

// Шаги повторов.
for(m=0;m<pDT->nRep;m++) {

// Простой расчёт, если это контрольный образец.
if(flCntrl!=0) { if(pNNW->Compute(pDT->InpLay)!=0) { ber=9; goto end;}}
// Шаг обратного распространения ошибки.
else {
if(pNNW->Compute(pDT->InpLay)!=0) { ber=10; goto end;}
if(pNNW->TrainStepSequentRep(pDT->TrueOut,ParTrain.Alpha,ParTrain.AlphaMin,ParTrain.AlphaMax,
ParTrain.flAdaptSt,ParTrain.CoeAdaptStep)!=0) { ber=11; goto end;}
pNNW->flChange=1;
}

// Нахождение ошибки выходного слоя.
pLay=pNNW->GetOutLay(); if(pLay==NULL) { ber=12; goto end;}
if(FindErrOutLay(pDT->TrueOut,pLay,&s)!=0) { ber=13; goto end;}

if(flCntrl!=0) { sumCntrl+=s; nSampCntrl++;} else { sum+=s; nSamp++;}
ProcMess();
}}

if(pErr!=NULL) { if(nSamp==0) *pErr=0.; else *pErr=SQRT(sum/(double)nSamp);}
if(pErrCntrl!=NULL) { if(nSampCntrl==0) *pErrCntrl=0.; else *pErrCntrl=SQRT(sumCntrl/(double)nSampCntrl);}
if(nSamp==0) { ber=messRet; goto end;}

end: SAFE_DELETE_ARR(NumArr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг тренировки нейронной сети последовательным послойным методом.

BYTE clDlgDBF_NNW::StepTrainSequentLay(void)
{
BYTE k,numLay,ber; USHRT n,nSt; UINT i,j,*NumSampl,nNumSampl; struct strDataTrain *pDT;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2;
if(DataTrain.IsOK()!=0) return 3;
if(DataTrain.SetFlags()!=0) return 4; // Установка флагов использования и тренировки.
nSt=ParTrain.nStSeqLay; if(nSt==0) nSt=1;

// Шаги по тренировочным образцам. Нахождение числа образцов, участвующих в тренировке.
nNumSampl=0;
for(i=0;i<DataTrain.nDT;i++) {
pDT=DataTrain.Get(i); if(pDT==NULL) return 5; if(pDT->IsOK()!=0) return 6;
if(pDT->flUse==0||pDT->nRep==0||pDT->flTrain==0) continue; nNumSampl++;}
if(nNumSampl==0) return messRet;

NumSampl=NULL; ber=0;
// Выделение памяти для массива номеров образцов.
NumSampl=new UINT[nNumSampl]; if(NumSampl==NULL) { ber=7; goto end;}

// Шаги по тренировочным образцам. Заполнение массива номеров образцов, участвующих в тренировке.
j=0;
for(i=0;i<DataTrain.nDT;i++) {
pDT=DataTrain.Get(i); if(pDT==NULL) { ber=8; goto end;} if(pDT->IsOK()!=0) { ber=9; goto end;}
if(pDT->flUse==0||pDT->nRep==0||pDT->flTrain==0) continue;
if(j>=nNumSampl) { ber=10; goto end;} NumSampl[j]=i; j++;}
if(j!=nNumSampl) { ber=11; goto end;}

// Выделение памяти для массивов эталонных значений нейронов.
if(pNNW->AllocEtal(nNumSampl)!=0) { ber=12; goto end;}

// Инициализация эталонных значений и истинных значений выходного слоя при тренировке нейронной сети последовательным послойным методом.
if(InitSequentLay(nNumSampl,NumSampl)!=0) { ber=13; goto end;}

// Цикл по слоям нейронной сети.
for(k=0;k<pNNW->nLay;k++) { numLay=pNNW->nLay-1-k;
for(n=0;n<nSt;n++) {
if(StepSequentLay(numLay,nNumSampl,NumSampl)!=0) { ber=14; goto end;}
pNNW->flChange=1;}}

end: pNNW->FreeEtal(); SAFE_DELETE_ARR(NumSampl); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация эталонных значений и истинных значений выходного слоя при тренировке нейронной сети последовательным послойным методом.

BYTE clDlgDBF_NNW::InitSequentLay(UINT nNumSampl,UINT *pNumSampl)
{
BYTE SetValEtalOutLay(UINT numSample,strInpLay *True,strLay *Lay); // Установка эталонных значений для выходного слоя нейронной сети.

BYTE k; UINT i,num; struct strDataTrain *pDT; struct strLay *pLay;

if(nNumSampl==0) return 1; if(pNumSampl==NULL) return 2;
if(pNNW==NULL) return 3; if(pNNW->IsOK_Lay()!=0) return 4;
if(DataTrain.IsOK()!=0) return 5;

// Шаги по тренировочным образцам. Предъявление образцов, расчёт и установка начальных значений для эталонных значений.
for(i=0;i<nNumSampl;i++) { num=pNumSampl[i]; if(num>=DataTrain.nDT) return 6;
pDT=DataTrain.Get(num); if(pDT==NULL) return 7; if(pDT->IsOK()!=0) return 8;
if(pDT->flUse==0||pDT->nRep==0||pDT->flTrain==0) return 9;
if(pNNW->Compute(pDT->InpLay)!=0) return 10;
pLay=pNNW->Get(pNNW->nLay-1); if(pLay==NULL) return 11;
if(SetValEtalOutLay(i,pDT->TrueOut,pLay)!=0) return 12; // Установка эталонных значений для выходного слоя нейронной сети.
// Установка эталонных значений нейронов, равных текущим значениям нейронов в послойном обучении.
if(pNNW->nLay>1) for(k=0;k<pNNW->nLay-1;k++) { pLay=pNNW->Get(k); if(pLay==NULL) return 13;
if(pLay->SetEtalEqualVal(i)!=0) return 14;}
ProcMess();}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг предъявления образцов при тренировке нейронной сети последовательным послойным методом.

BYTE clDlgDBF_NNW::StepSequentLay(BYTE numLay,UINT nNumSampl,UINT *pNumSampl)
{
BYTE RandomizeArr(UINT *NumArr,UINT nNumArr,BYTE nCycles); // Случайная перетасовка порядка номеров в массиве.

BYTE flRand,m,ber; UINT i,iv,num,*NumArr; struct strDataTrain *pDT;

if(nNumSampl==0) return 1; if(pNumSampl==NULL) return 2;
if(pNNW==NULL) return 3; if(pNNW->IsOK_Lay()!=0) return 4; if(numLay>=pNNW->nLay) return 5;
if(DataTrain.IsOK()!=0) return 6;
flRand=ParTrain.flRandSampl;

NumArr=NULL; ber=0;
// Нахождение массива перестановок при случайной перестановке порядка образцов во время обучения.
if(flRand!=0) {
NumArr=new UINT[nNumSampl]; if(NumArr==NULL) { ber=7; goto end;}
for(i=0;i<nNumSampl;i++) NumArr[i]=i;
if(RandomizeArr(NumArr,nNumSampl,nCycleRandSamples)!=0) { ber=8; goto end;}}

// Шаги по тренировочным образцам. Корректировка весов и порогов для слоя 'numLay'.
for(iv=0;iv<nNumSampl;iv++) { if(flRand==0) i=iv; else i=NumArr[iv]; if(i>=nNumSampl) { ber=9; goto end;}
num=pNumSampl[i]; if(num>=DataTrain.nDT) { ber=10; goto end;}
pDT=DataTrain.Get(num); if(pDT==NULL) { ber=11; goto end;} if(pDT->IsOK()!=0) { ber=12; goto end;}
if(pDT->flUse==0||pDT->nRep==0||pDT->flTrain==0) { ber=13; goto end;}

// Шаги повторов.
for(m=0;m<pDT->nRep;m++) {
// Шаг цикла метода последовательного послойного обучения - корректировка весов и порогов для слоя 'numLay'.
if(pNNW->TrainStepSequentLayWeights(i,pDT->InpLay,numLay,ParTrain.Alpha,ParTrain.AlphaMin,ParTrain.AlphaMax,
ParTrain.flAdaptSt,ParTrain.CoeAdaptStep)!=0) { ber=14; goto end;}
ProcMess();}}
if(numLay==0) goto end;

// Шаги по тренировочным образцам. Корректировка эталонных значений для слоя 'numLay-1'.
for(iv=0;iv<nNumSampl;iv++) { if(flRand==0) i=iv; else i=NumArr[iv]; if(i>=nNumSampl) { ber=15; goto end;}
num=pNumSampl[i]; if(num>=DataTrain.nDT) { ber=16; goto end;}
pDT=DataTrain.Get(num); if(pDT==NULL) { ber=17; goto end;} if(pDT->IsOK()!=0) { ber=18; goto end;}
if(pDT->flUse==0||pDT->nRep==0||pDT->flTrain==0) { ber=19; goto end;}

// Шаги повторов.
for(m=0;m<pDT->nRep;m++) {
// Цикл метода последовательного послойного обучения - корректировка эталонных значений для слоя 'numLay-1'.
if(pNNW->TrainStepSequentLayEtal(i,numLay,ParTrain.Alpha,ParTrain.AlphaMin,ParTrain.AlphaMax,
ParTrain.flAdaptSt,ParTrain.CoeAdaptStep)!=0) { ber=20; goto end;}
ProcMess();}}

// Корректировка эталонных значений и весовых коэффициентов.
if(pNNW->TrainStepSequentLayCorr(numLay)!=0) { ber=21; goto end;}

end: SAFE_DELETE_ARR(NumArr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг предъявления образцов при тренировке сети групповым методом обратного распространения ошибки.

BYTE clDlgDBF_NNW::FindVectGroup(double *pErr,double *pWei,double *pErrCntrl,double *pWeiCntrl)
{
BYTE FindErrOutLay(strInpLay *True,strLay *Lay,double *pErr); // Нахождение ошибки выходного слоя нейронов.

BYTE flCntrl,flNeedCntrl,nRep; UINT i,nSamp,nSampCntrl; double sum,sumCntrl,s; struct strDataTrain *pDT;
struct strLay *pLay;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2; if(pNNW->IsOK_Vect()!=0) return 3;
if(DataTrain.IsOK()!=0) return 4;
if(pErrCntrl==NULL&&pWeiCntrl==NULL) flNeedCntrl=0; else flNeedCntrl=1;
if(pErr!=NULL) *pErr=0.; if(pErrCntrl!=NULL) *pErrCntrl=0.;
if(pWei!=NULL) *pWei=0.; if(pWeiCntrl!=NULL) *pWeiCntrl=0.;

nSamp=nSampCntrl=0; sum=sumCntrl=0.; // Обнуление числа предъявляемых образцов данных и ошибки.
if(pNNW->SetZeroVect()!=0) return 5; // Установка нулей в массивы векторов.

// Шаги по тренировочным и контрольным образцам.
for(i=0;i<DataTrain.nDT;i++) {
pDT=DataTrain.Get(i); if(pDT==NULL) return 6; if(pDT->IsOK()!=0) return 7;
if(pDT->flUse==0) continue; nRep=pDT->nRep; if(nRep==0) continue;
if(pDT->flTrain==0) flCntrl=1; else flCntrl=0; if(flNeedCntrl==0&&flCntrl!=0) continue;

// Расчёт.
if(pNNW->Compute(pDT->InpLay)!=0) return 8;
// Шаг обратного распространения ошибки и суммирование векторов.
if(flCntrl==0) { if(pNNW->TrainGroupErrSumVect(pDT->TrueOut,(double)nRep)!=0) return 9;}

// Нахождение ошибки выходного слоя.
pLay=pNNW->GetOutLay(); if(pLay==NULL) return 10;
if(FindErrOutLay(pDT->TrueOut,pLay,&s)!=0) return 11;
s*=(double)nRep;
if(flCntrl!=0) { sumCntrl+=s; nSampCntrl+=(UINT)nRep;} else { sum+=s; nSamp+=(UINT)nRep;}
ProcMess();
}

if(pErr!=NULL) *pErr=sum; if(pErrCntrl!=NULL) *pErrCntrl=sumCntrl;
if(pWei!=NULL) *pWei=(double)nSamp; if(pWeiCntrl!=NULL) *pWeiCntrl=(double)nSampCntrl;
if(nSamp==0) return messRet;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг предъявления образцов при нахождении адаптивного шага при тренировке сети групповым методом обратного распространения ошибки.

BYTE clDlgDBF_NNW::StepFindAdaptStepGroup(void)
{
BYTE FindErrOutLay(strInpLay *True,strLay *Lay,double *pErr); // Нахождение ошибки выходного слоя нейронов.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

BYTE nRep; UINT i,nSamp; float coe; double Alpha; struct strDataTrain *pDT;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2; if(pNNW->IsOK_Vect()!=0) return 3;
if(DataTrain.IsOK()!=0) return 4;
if(pNNW->ZeroNumDenomAdaptStepGroup()!=0) return 5; // Обнуление вспомогательных переменных для суммирования при нахождении адаптивного шага при предъявлении образца данных при групповом обучении.

// Шаги по тренировочным образцам.
nSamp=0;
for(i=0;i<DataTrain.nDT;i++) {
pDT=DataTrain.Get(i); if(pDT==NULL) return 6; if(pDT->IsOK()!=0) return 7;
if(pDT->flUse==0) continue; if(pDT->flTrain==0) continue; nRep=pDT->nRep; if(nRep==0) continue;
if(pNNW->Compute(pDT->InpLay)!=0) return 8; // Расчёт.
if(pNNW->TrainGroupAdaptStep(pDT->TrueOut,(double)nRep)!=0) return 9; // Шаг нахождения адаптивного шага.
nSamp+=(UINT)nRep; ProcMess();}
if(nSamp==0) return messRet;

// Нахождение адаптивного шага при групповом обучении.
if(pNNW->FindAlphaGroup()!=0) return 10;

coe=ParTrain.CoeAdaptStep;

// Корректировка адаптивного шага для каждого слоя.
if(ParTrain.flEqualAdaptSt==0) {
if(pNNW->MultCoeAlpha(coe)!=0) return 11; // Умножение адаптивного шага на замедляющий коэффициент.
if(pNNW->CorrectAlpha(ParTrain.AlphaMin,ParTrain.AlphaMax)!=0) return 12; // Корректировка адаптивного шага для каждого слоя.
}

// Использование одного адаптивного шага для всех слоёв.
if(ParTrain.flEqualAdaptSt!=0) {
if(pNNW->GetEqualAdaptStep(&Alpha)!=0) return 13; // Нахождение одного адаптивного шага для всех слоёв.
if(coe>0.&&coe<1.0F) Alpha*=(double)coe; // Замедляющий множитель для адаптивного шага.
if(CorrectAdaptStep(&Alpha,ParTrain.AlphaMin,ParTrain.AlphaMax)!=0) return 14; // Корректировка адаптивного шага.
if(Alpha<=0.) return messStop;
if(pNNW->SetAlphaConst(Alpha)!=0) return 15; // Установка одинакового шага во все слои.
SetFlEdt(hDlg,IDC_STEP_TRAIN,(float)Alpha,FormStepTrain); // Установка найденного значения адаптивного шага в окне.
}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка ошибок в окнах.

void clDlgDBF_NNW::SetErrWin(double Err,double ErrCntrl)
{
if(hDlg==NULL) return;
SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)Err,FormErr);
SetFlEdt(hDlg,IDC_ERR_CONTR,(float)ErrCntrl,FormErr);
}

//-----------------------------------------------------------------------------------------------------------
// Установка ошибок в окнах.

void clDlgDBF_NNW::ClearErrWin(void)
{
if(hDlg==NULL) return;
SetDlgItemText(hDlg,IDC_ERR_TRAIN,"");
SetDlgItemText(hDlg,IDC_ERR_CONTR,"");
}

//-----------------------------------------------------------------------------------------------------------
// Получение шага тренировки.

void clDlgDBF_NNW::GetStepTrain(void)
{
float *fp,v;

if(hDlg==NULL) return;
if(ParTrain.flAdaptSt==0) { fp=&ParTrain.Alpha; v=AlphaTrain_Stand;
GetFlEdt(hDlg,IDC_STEP_TRAIN,fp); if(*fp<=0.0F) *fp=v;}
else {
fp=&ParTrain.AlphaMin; GetFlEdt(hDlg,IDC_ADAPT_STEP_MIN,fp); if(*fp<0.0F) *fp=0.0F;
fp=&ParTrain.AlphaMax; v=ParTrain.AlphaMin; GetFlEdt(hDlg,IDC_ADAPT_STEP_MAX,fp); if(*fp<v) *fp=v;}
}

//-----------------------------------------------------------------------------------------------------------
// Установка шага тренировки.

void clDlgDBF_NNW::SetStepTrain(void)
{
float *fp,v;

if(hDlg==NULL) return;
if(ParTrain.flAdaptSt==0) { fp=&ParTrain.Alpha; v=AlphaTrain_Stand; if(*fp<=0.0F) *fp=v;
SetFlEdt(hDlg,IDC_STEP_TRAIN,*fp,FormStepTrain);}
else {
fp=&ParTrain.AlphaMin; if(*fp<0.0F) *fp=0.0F;
SetFlEdt(hDlg,IDC_ADAPT_STEP_MIN,*fp,FormStepTrain);
fp=&ParTrain.AlphaMax; v=ParTrain.AlphaMin; if(*fp<v) *fp=v;
SetFlEdt(hDlg,IDC_ADAPT_STEP_MAX,*fp,FormStepTrain);}
}

//-----------------------------------------------------------------------------------------------------------
// Визуализация и скрытие окон, относящихся к установке шага или адаптивного шага.

void clDlgDBF_NNW::ShowHideWinStepTrain(void)
{
BYTE fl,flS;

if(hDlg==NULL) return;
switch(ParTrain.methTrain) { default: fl=1; break;
case methTrain_GroupSearch: // Групповой метод поиска.
fl=0; break;}

ShowChWin(hDlg,IDC_APPLY,fl);
if(fl!=0) flS=ParTrain.flAdaptSt; else flS=0;
ShowChWin(hDlg,IDC_ADAPT_STEP_MIN,flS);
ShowChWin(hDlg,IDC_ADAPT_STEP_MAX,flS);
ShowChWin(hDlg,IDC_HEADER_ALPHA_LIM,flS);
if(fl!=0&&(ParTrain.flAdaptSt==0||ParTrain.flAdaptSt!=0&&ParTrain.flEqualAdaptSt!=0&&ParTrain.methTrain==methTrain_Group)) flS=1; else flS=0;
ShowChWin(hDlg,IDC_STEP_TRAIN,flS);
ShowChWin(hDlg,IDC_HEADER_ALPHA,flS);
}

//-----------------------------------------------------------------------------------------------------------
// Установка названия метода тренировки.

void clDlgDBF_NNW::SetNameTrainMeth(void)
{
char *cp;

if(hDlg==NULL) return; if(ParTrain.methTrain>=nMethTrain) return; cp=""; if(hInst==NULL) goto end;
if(LoadString(hInst,IDSArrMethTrain[ParTrain.methTrain],TxtStr,strL_Txt)==0) goto end; cp=TxtStr;
end: SetDlgItemText(hDlg,IDC_METH_TRAIN,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Полоса прогресса.

void clDlgDBF_NNW::ShowProgr(UINT i,UINT n)
{
ShowProgress(hwndProgr,NULL,i,n); ProcMess();
}

//-----------------------------------------------------------------------------------------------------------
// Обработка сообщений диалогового окна просмтора и редактирования базы данных.

LRESULT clDlgDBF_NNW::MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
int id; HDC hdc;

if(flag==NULL) return 0L; *flag=0; if(hDlg==NULL) return 0L; if(msg==WM_INITDIALOG) return 0L;

switch(msg) { default: break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1; break;

// WM_CTLCOLORSTATIC ........................................................................................
case WM_CTLCOLORSTATIC: hdc=(HDC)wParam; id=GetDlgCtrlID((HWND)lParam); if(id<=0) break; *flag=1;
SetBkColor(hdc,GetSysColor(COLOR_WINDOW)); SetTextColor(hdc,GetSysColor(COLOR_BTNTEXT)); SetBkMode(hdc,TRANSPARENT);
if(id==IDC_NUM_CYCLE||id==IDC_ERR_TRAIN||id==IDC_ERR_CONTR||id==IDC_NAME_NNW_VOWEL||id==IDC_NAME_NNW_CONSONANT||
id==IDC_NAME_NNW_SPECTR||id==IDC_METH_TRAIN) return (LRESULT)hBrushBkg; return (LRESULT)hBrushDial;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: if(Command(wParam)==0) *flag=1; break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; ImgWinC(hDlg,ColDial,ColDial); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Команды.

BYTE clDlgDBF_NNW::Command(WPARAM wParam)
{
INT_PTR CALLBACK DlgAbout(HWND,UINT,WPARAM,LPARAM); // Функция диалогового окна о программе.

BYTE flag,fl,be; int id;

if(hDlg==NULL) return 1; flag=0; id=LOWORD(wParam);

switch(id) { default: flag=2; break;

// IDC_DBF ..................................................................................................
case IDC_DBF:
if(HIWORD(wParam)==LBN_SELCHANGE) { OnSelChangeFile(); break;}
if(HIWORD(wParam)==LBN_DBLCLK) { LoadFile(); break;}
break;

// IDC_DBS ..................................................................................................
case IDC_DBS:
if(HIWORD(wParam)==LBN_SELCHANGE) { OnSelChangeSound(); break;} 
if(HIWORD(wParam)==LBN_DBLCLK) { FindSoundDiag(); break;}
break;

// IDC_FILE_USE .............................................................................................
case IDC_FILE_USE: if(selDBF==NULL) break; GetChBox(hDlg,IDC_FILE_USE,&selDBF->flUse); OnChangeStrFile(); break;

// IDC_FILE_TRAIN ...........................................................................................
case IDC_FILE_TRAIN: if(selDBF==NULL) break; GetChBox(hDlg,IDC_FILE_TRAIN,&selDBF->flTrain); OnChangeStrFile(); break;

// IDC_SOUND_USE ............................................................................................
case IDC_SOUND_USE: if(selDBS==NULL) break; GetChBox(hDlg,IDC_SOUND_USE,&selDBS->flUse); OnChangeStrSound(); break;

// IDC_SOUND_TRAIN ..........................................................................................
case IDC_SOUND_TRAIN: if(selDBS==NULL) break; GetChBox(hDlg,IDC_SOUND_TRAIN,&selDBS->flTrain); OnChangeStrSound(); break;

// IDC_ACCEPT_DBF ...........................................................................................
case IDC_ACCEPT_DBF: if(flTrain!=0) { SoundBlock(); break;} AcceptDBF(); break;

// IDC_DEL_DBF ..............................................................................................
case IDC_DEL_DBF: if(flTrain!=0) { SoundBlock(); break;} DelDBF(); break;

// IDC_INS_DBF ..............................................................................................
case IDC_INS_DBF: if(flTrain!=0) { SoundBlock(); break;} InsDBF(); break;

// IDC_ADD_DBF ..............................................................................................
case IDC_ADD_DBF: if(flTrain!=0) { SoundBlock(); break;} AddDBF(); break;

// IDC_ACCEPT_DBS ...........................................................................................
case IDC_ACCEPT_DBS: if(flTrain!=0) { SoundBlock(); break;} AcceptDBS(); break;

// IDC_DEL_DBS ..............................................................................................
case IDC_DEL_DBS: if(flTrain!=0) { SoundBlock(); break;} DelDBS(); break;

// IDC_INS_DBS ..............................................................................................
case IDC_INS_DBS: if(flTrain!=0) { SoundBlock(); break;} InsDBS(); break;

// IDC_ADD_DBS ..............................................................................................
case IDC_ADD_DBS: if(flTrain!=0) { SoundBlock(); break;} AddDBS(); break;

// IDC_BROWSE ...............................................................................................
case IDC_BROWSE: BrowseFileDBF(); break;

//xxx IDC_NAME_FILE_DBF IDC_NAME_PERSON IDC_REPEATS IDC_NAME_SOUND

// IDC_RADIO_GEND_M IDC_RADIO_GEND_W ........................................................................
case IDC_RADIO_GEND_M: case IDC_RADIO_GEND_W: if(id==IDC_RADIO_GEND_M) fl=0; else fl=1; OnChangeGendDBF(fl); break;

// IDC_BLOCK_TIME ...........................................................................................
case IDC_BLOCK_TIME: flBlkTime=1-flBlkTime; SetTxtBtnBlockSetTime(); break;

// IDC_PLAY_SND .............................................................................................
case IDC_PLAY_SND: if(flPlaySound==0) StartPlaySound(); else flStopSound=1; break;

// IDC_PLAY_SND_PEAKS .......................................................................................
case IDC_PLAY_SND_PEAKS: if(flPlaySound==0) StartPlaySoundPeaks(); else flStopSound=1; break;

// IDC_STATISTICS ...........................................................................................
case IDC_STATISTICS: ShowStatistics(); break;

// IDC_RESULTS ..............................................................................................
case IDC_RESULTS: FindShowResults(); break;

// IDC_RADIO_VOWEL IDC_RADIO_CONS IDC_RADIO_SPECTR ..........................................................
case IDC_RADIO_VOWEL: case IDC_RADIO_CONS: case IDC_RADIO_SPECTR:
if(flTrain!=0) { SoundBlock(); break;} OnSelectTypNet(id); break;

// IDC_OPEN_NNW_VOWEL IDC_OPEN_NNW_CONSONANT IDC_OPEN_NNW_SPECTR ............................................
case IDC_OPEN_NNW_VOWEL: case IDC_OPEN_NNW_CONSONANT: case IDC_OPEN_NNW_SPECTR:
switch(id) { default: break;
case IDC_OPEN_NNW_VOWEL: fl=typNNW_Vowel; break;
case IDC_OPEN_NNW_CONSONANT: fl=typNNW_Cons; break;
case IDC_OPEN_NNW_SPECTR: fl=typNNW_Spectr; break;
}
be=ReadNNW(fl); if(be!=0&&be!=messRet) Message(IDS_Mess_ErrLoadNNW,MB_ST); break;

// IDC_SAVE_NNW_VOWEL IDC_SAVE_NNW_CONSONANT IDC_SAVE_NNW_SPECTR ............................................
case IDC_SAVE_NNW_VOWEL: case IDC_SAVE_NNW_CONSONANT: case IDC_SAVE_NNW_SPECTR:
switch(id) { default: break;
case IDC_SAVE_NNW_VOWEL: fl=typNNW_Vowel; break;
case IDC_SAVE_NNW_CONSONANT: fl=typNNW_Cons; break;
case IDC_SAVE_NNW_SPECTR: fl=typNNW_Spectr; break;
}
SaveNNW(fl); break;

// IDC_SAVE_AS_NNW_VOWEL IDC_SAVE_AS_NNW_CONSONANT IDC_SAVE_AS_NNW_SPECTR ...................................
case IDC_SAVE_AS_NNW_VOWEL: case IDC_SAVE_AS_NNW_CONSONANT: case IDC_SAVE_AS_NNW_SPECTR:
switch(id) { default: break;
case IDC_SAVE_AS_NNW_VOWEL: fl=typNNW_Vowel; break;
case IDC_SAVE_AS_NNW_CONSONANT: fl=typNNW_Cons; break;
case IDC_SAVE_AS_NNW_SPECTR: fl=typNNW_Spectr; break;
}
SaveAsNNW(fl); break;

// IDC_OPEN_PAR_NNW .........................................................................................
case IDC_OPEN_PAR_NNW: ReadParNNW(); break;

// IDC_SAVE_PAR_NNW .........................................................................................
case IDC_SAVE_PAR_NNW: if(SaveParNNW()!=0) SoundBlock(); break;

// IDC_SAVE_AS_PAR_NNW ......................................................................................
case IDC_SAVE_AS_PAR_NNW: SaveAsParNNW(); break;

// IDC_ADJUST_NNW ...........................................................................................
case IDC_ADJUST_NNW: AdjustParNNW(); break;

// IDC_GET_PAR_FROM_NNW .....................................................................................
case IDC_GET_PAR_FROM_NNW: GetParFromNNW(); break;

// IDC_INIT_NNW .............................................................................................
case IDC_INIT_NNW: InitNNW(); break;

// IDC_ADJUST_TRAIN .........................................................................................
case IDC_ADJUST_TRAIN: AdjParTrain(); break;

// IDC_PROC_SPECTR_PEAKS ....................................................................................
case IDC_PROC_SPECTR_PEAKS: if(flTrain!=0) { SoundBlock(); break;} ProcSpectrPeaks(); break;

// IDC_SET_INP_DATA .........................................................................................
case IDC_SET_INP_DATA: if(flTrain!=0) { SoundBlock(); break;} ProcSetInpData(); break;

// IDC_TRAINING .............................................................................................
case IDC_TRAINING: CmndTrainNNW(); break;

// IDC_APPLY ................................................................................................
case IDC_APPLY: GetStepTrain(); break;

// IDC_ERR_TRAIN IDC_ERR_CONTR IDC_NUM_CYCLE ................................................................
case IDC_ERR_TRAIN: case IDC_ERR_CONTR: case IDC_NUM_CYCLE: if(HIWORD(wParam)==EN_SETFOCUS) SetFocusWin(); break;

// IDC_SAVE .................................................................................................
case IDC_SAVE: SaveFileDBF(); break;

// IDOK IDCANCEL ............................................................................................
case IDOK: case IDCANCEL: if(flBlk!=0) { Message(IDS_Mess_CanNotExit,MB_ST); break;}
if(id==IDOK) fl=1; else fl=0; EndDialog(hDlg,fl); OnCloseDlg(); return (INT_PTR)TRUE;
}

return flag;
}

//-----------------------------------------------------------------------------------------------------------
// Выбор типа сети.

void clDlgDBF_NNW::OnSelectTypNet(int id)
{
BYTE typ;

if(flTrain!=0) return;
switch(id) { default: return;
case IDC_RADIO_VOWEL:  typ=typNNW_Vowel; break; // Гласные звуки.
case IDC_RADIO_CONS:   typ=typNNW_Cons; break; // Согласные звуки.
case IDC_RADIO_SPECTR: typ=typNNW_Spectr; break; // Применение нейронных сетей сразу для всего спектра.
}
if(typ==typNet) return; typNet=typ; SetPntNNW();
}

//-----------------------------------------------------------------------------------------------------------
// Установка указателей на структуры нейронной сети и параметров нейронной сети.

void clDlgDBF_NNW::SetPntNNW(void)
{
switch(typNet) { default: pNNW=NULL; break;
case typNNW_Vowel:  pNNW=pNNW_Vowel;  pParNNW=&ParNNW_Vowel; break; // Гласные звуки.
case typNNW_Cons:   pNNW=pNNW_Cons;   pParNNW=&ParNNW_Cons; break; // Согласные звуки.
case typNNW_Spectr: pNNW=pNNW_Spectr; pParNNW=&ParNNW_Spectr; break; // Применение нейронных сетей сразу для всего спектра.
}
}

//-----------------------------------------------------------------------------------------------------------
// Перерисовка изображения сети.

void clDlgDBF_NNW::DrawNet(void)
{
if(MW!=NULL) MW->DrawNet(); // Перерисовка изображения сети.
}

//-----------------------------------------------------------------------------------------------------------
// Установка фокуса ввода.

void clDlgDBF_NNW::SetFocusWin(void)
{
HWND hwnd;

if(hDlg==NULL) return; hwnd=GetDlgItem(hDlg,IDOK); if(hwnd==NULL) return; SetFocus(hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение списка файлов базы данных.

BYTE clDlgDBF_NNW::FillLBFiles(void) 
{
BYTE i; HWND hwnd; struct strDBF *pDBF;

if(hDlg==0) return 1; if(IsOK_DBF()!=0) return 2; hwnd=GetDlgItem(hDlg,IDC_DBF); if(hwnd==NULL) return 3;
SendMessage(hwnd,LB_RESETCONTENT,0,0);
for(i=0;i<pDataBase->n;i++) { pDBF=pDataBase->Get(i); pDBF->Print();
SendMessage(hwnd,LB_ADDSTRING,0,(LPARAM)(LPSTR)TxtStr);}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Вывод звука.

BYTE clDlgDBF_NNW::StartPlaySound(void)
{
BYTE PlayWave_(float *Wave,UINT nPoints,DWORD sps,BYTE *flStop,DWORD WOP,DWORD Pnt,HWAVEOUT *hwo_); // Вывод звука из массива.

BYTE be; UINT nI,nF,sz; DWORD sps; float tI,tF,v; struct strSndArr *pSnd;

if(hDlg==NULL) return 1; if(selDBF==NULL) return 2; if(selDBS==NULL) return 3;
pSnd=&selDBF->DBS.Snd; if(pSnd->IsOK()!=0) return 4; if(pSnd->ln<=1) return 5;
sps=(DWORD)GetIntTest(1.0F/(float)pSnd->dt);

tI=selDBS->tI; tF=selDBS->tF;
if(tI>tF) { v=tI; tI=tF; tF=v;}
nI=GetUINT_Test((double)tI/pSnd->dt); if(nI>=pSnd->ln) return 6;
nF=GetUINT_Test((double)tF/pSnd->dt); if(nF>=pSnd->ln) nF=pSnd->ln-1;
if(nI>=nF) return 7; sz=nF-nI;

flStopSound=0; flPlaySound=1; flBlk|=1<<numBlkDBF_Sound; typPlaySound=0;
SetTxtBtnPlaySound(typPlaySound); // Установка текста в кнопку воспроизведения звука.
EnableChWin(hDlg,IDC_DBF,0);
EnableChWin(hDlg,IDC_DBS,0);
be=PlayWave_(pSnd->Snd+nI,sz,sps,&flStopSound,0L,0L,&hwo);
OnStopSound();
if(be!=0) return 8; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Вывод синтезированного звука.

BYTE clDlgDBF_NNW::StartPlaySoundPeaks(void)
{
BYTE Synthesis(float *Wave,UINT nPoints,float Amp,USHRT nStep,clInpLayArr *pPeaks,USHRT nPM,double dt,
  float Freq,BYTE flIncHigh); // Синтез звука.
BYTE PlayWave_(float *Wave,UINT nPoints,DWORD sps,BYTE *flStop,DWORD WOP,DWORD Pnt,HWAVEOUT *hwo_); // Вывод звука из массива.

BYTE fl,be,ber; USHRT nStep; UINT nPoints; DWORD sps; float Freq,Amp; double dt,st; struct strSndArr *pSnd;

if(hDlg==NULL) return 1; if(selDBS==NULL) return 2;
if(selDBS->typSnd!=typNNW_Vowel) { SoundBlock(); return messRet;}
st=selDBS->Diag.stArr; if(st<=0.) { Message(IDS_Mess_NoPreProc,MB_IN); return 3;}
if(selDBS->Peaks.IsOK()!=0) { Message(IDS_Mess_NoPreProc,MB_IN); return 4;}
if(selDBF==NULL) return 5; pSnd=&selDBF->DBS.Snd; dt=pSnd->dt; if(dt<=0.) return 6;
sps=(DWORD)GetIntTest(1./(double)dt);
nStep=GetUSHRT_Test(st/dt); if(nStep==0) return 7;
if(selDBS->Peaks.nData>UINT_MAX-2) return 8; if(selDBS->Peaks.nData+2>UINT_MAX/nStep) return 9;
nPoints=(selDBS->Peaks.nData-1)*nStep;

GetFlEdt(hDlg,IDC_FREQ_SYNTHESIS,&Freq); // Частота синтезатора речи.
Freq=CHECK_LIM(Freq,FreqSynthesis_Min,FreqSynthesis_Max);
GetFlEdt(hDlg,IDC_AMP_SYNTHESIS,&Amp); // Амплитуда синтезатора речи.
Amp=CHECK_LIM(Amp,AmpSynthesis_Min,AmpSynthesis_Max);
if(GetChBox(hDlg,IDC_CHECK_SYNTH_CORR,&fl)!=0) fl=1; // Флаг коррекции высоких гармоник.

ber=0;
if(CreateWaveSynth(nPoints)!=0) { ber=10; goto end;}
if(Synthesis(pWaveSynth,nPoints,Amp,nStep,&selDBS->Peaks,0,dt,Freq,fl)!=0) { ber=11; goto end;} // Cинтез звука.

flStopSound=0; flPlaySound=1; flBlk|=1<<numBlkDBF_Sound; typPlaySound=1;
SetTxtBtnPlaySound(typPlaySound); // Установка текста в кнопку воспроизведения звука.
EnableChWin(hDlg,IDC_DBF,0);
EnableChWin(hDlg,IDC_DBS,0);
be=PlayWave_(pWaveSynth,nPoints,sps,&flStopSound,0L,0L,&hwo);
OnStopSound();
if(be!=0) { ber=12; goto end;}

end: if(ber!=0) FreeWaveSynth(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при остановке проигрывания звука.

void clDlgDBF_NNW::OnStopSound(void)
{
flBlk&=~(1<<numBlkDBF_Sound);
PlaySound(NULL,NULL,SND_PURGE);
if(hDlg!=NULL) {
EnableChWin(hDlg,IDC_DBF,1);
EnableChWin(hDlg,IDC_DBS,1);}
flStopSound=1; flPlaySound=0;
SetTxtBtnPlaySound(typPlaySound); // Установка текста в кнопку воспроизведения звука.
FreeWaveSynth();
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку предварительной обработки.

void clDlgDBF_NNW::SetTxtBtnPreProc(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flPreProc==0) id=IDS_Btn_PreProc; else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_PROC_SPECTR_PEAKS,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку заполнения входных данных.

void clDlgDBF_NNW::SetTxtBtnSetData(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flSetData==0) id=IDS_Btn_SetData; else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_SET_INP_DATA,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку тренировки сети.

void clDlgDBF_NNW::SetTxtBtnTrain(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flTrain==0) id=IDS_Btn_Train; else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_TRAINING,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку воспроизведения звука.

void clDlgDBF_NNW::SetTxtBtnPlaySound(BYTE typ)
{
int id; char *cp;

if(hDlg==NULL) return;
if(flPlaySound==0) { if(typ==0) id=IDS_Btn_Sound; else id=IDS_Btn_SynthSound;} else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
if(typ==0) id=IDC_PLAY_SND; else id=IDC_PLAY_SND_PEAKS; SetDlgItemText(hDlg,id,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку блокировки изменения времени в базе данных.

void clDlgDBF_NNW::SetTxtBtnBlockSetTime(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flBlkTime==0) id=IDS_Btn_Block; else id=IDS_Btn_Enable;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_BLOCK_TIME,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении флага выполнения предварительной обработки.

void clDlgDBF_NNW::OnChFlagPreProc(void)
{
BYTE En;

if(flPreProc!=0) En=0; else En=1; SetTxtBtnPreProc(); EnableChWin(hDlg,IDC_TRAINING,En);
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении флага выполнения заполнения массива входных данных.

void clDlgDBF_NNW::OnChFlagSetInpData(void)
{
BYTE En;

if(flSetData!=0) En=0; else En=1; SetTxtBtnSetData(); EnableChWin(hDlg,IDC_TRAINING,En);
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении флага тренировки сети.

void clDlgDBF_NNW::OnChFlagTrain(void)
{
BYTE En;

if(flTrain!=0) En=0; else En=1; SetStateRadioTypNet(En); SetTxtBtnTrain();
EnableChWin(hDlg,IDC_PROC_SPECTR_PEAKS,En);
EnableChWin(hDlg,IDC_SET_INP_DATA,En);
}

//-----------------------------------------------------------------------------------------------------------
// Блокировка и разблокирование переключателей выбора типа нейронной сети.

void clDlgDBF_NNW::SetStateRadioTypNet(BYTE En)
{
EnableChWin(hDlg,IDC_RADIO_VOWEL,En);
EnableChWin(hDlg,IDC_RADIO_CONS,En);
EnableChWin(hDlg,IDC_RADIO_SPECTR,En);
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация структур параметров нейронных сетей.

void clDlgDBF_NNW::InitParNNW(void)
{
ParNNW_Vowel.Init(typNNW_Vowel); // Гласные звуки.
ParNNW_Cons.Init(typNNW_Cons); // Согласные звуки.
ParNNW_Spectr.Init(typNNW_Spectr); // Все (для спектра).
}

//-----------------------------------------------------------------------------------------------------------
// Проверка тренировки сети для заданного типа сети.

BYTE clDlgDBF_NNW::IsTrain(BYTE typ)
{
if(flTrain==0) return 0; if(typ==typNet) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка, идёт ли тренировка сети.

BYTE clDlgDBF_NNW::IsDoTrain(void)
{
return flTrain;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка, идёт ли предварительная обработка.

BYTE clDlgDBF_NNW::IsDoPreProc(void)
{
return flPreProc;
}

//-----------------------------------------------------------------------------------------------------------
// Показ статистики по данным для звуков.

BYTE clDlgDBF_NNW::ShowStatistics(void)
{
BYTE FindStatSound(strStatSndAll *pStatAll,strDBFArr *pDBFA,float dTime); // Нахождение статистики для звуков.
INT_PTR CALLBACK DlgShowStatSound(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam); // Функция диалогового окна показа статистики для звуков.

BYTE k,nV; float dt; char *pSign; struct strStatSndAll StatAll; struct strStatSnd *pSt;

if(hInst==NULL) return 1; if(hDlg==NULL) return 2;
if(pDataBase==NULL) return 3; if(pDataBase->IsOK_DBF()!=0) return 4;
if(MW==NULL) return 5; dt=MW->ParSpectr.Time_Step; if(dt<=0.0F) return 6;

switch(typNet) { default: return 7;
case typNNW_Vowel: pSign=SignVoicesVowel; nV=nVoicesVowel; break; // Для гласных звуков.
case typNNW_Cons: pSign=SignVoicesCons; nV=nVoicesCons; break; // Для согласных звуков.
}

if(StatAll.Alloc(nV)!=0) return 8;
for(k=0;k<nV;k++) { pSt=StatAll.StatSnd+k; pSt->Zero(); pSt->c=pSign[k];}
if(FindStatSound(&StatAll,pDataBase,dt)!=0) return 9; // Нахождение статистики для звуков.
DialogBoxParam(hInst,MAKEINTRESOURCE(IDD_STAT_SOUNDS),hDlg,(DLGPROC)DlgShowStatSound,(LPARAM)&StatAll);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт и изображение показателей по качеству распознавания звуков для базы данных.

void clDlgDBF_NNW::FindShowResults(void)
{
BYTE fl;

if(IsOK_DBF()!=0) return; if(pNNW==NULL) return;
if(flPreProcDone==0) { Message(IDS_Mess_NoPreProc,MB_EX); return;}
if(flSetDataDone==0||flTypInpData!=pNNW->Par.flTypInpData) { Message(IDS_Mess_NoInpData,MB_EX); return;}
flBlk|=1<<numBlkDBF_TestDBS;
pDataBase->SetResZero(); // Обнуление результатов распознавания.
if(GetChBox(hDlg,IDC_CHECK_ALL_RES,&fl)!=0) fl=1;
DoTest(fl); // Расчёт показателей по качеству распознавания звуков для базы данных.
FillLBFiles(); // Перерисовка списка файлов базы данных.
if(numSel!=UCHAR_MAX) SelItemList(hDlg,IDC_DBF,(USHRT)numSel); // Выделение строки в списке файлов.
if(selDBF!=NULL) selDBF->DBS.FillLBParam(hDlg); // Перерисовка списка звуков.
if(numSelSound!=UCHAR_MAX) SelItemList(hDlg,IDC_DBS,(USHRT)numSelSound); // Выделение строки в списке звуков.
flBlk&=~(1<<numBlkDBF_TestDBS);
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт показателей по качеству распознавания звуков для базы данных.

BYTE clDlgDBF_NNW::DoTest(BYTE flAll)
{
BYTE CopyNNW(strNNW *Dst,strNNW *Src); // Копирование структуры нейронной сети.

BYTE i,ber; struct strDBF *pDBF; struct strNNW *NNW_Test;

if(IsOK_DBF()!=0) return 1; if(pNNW==NULL) return 2; if(pNNW->IsOK_Lay()!=0) return 3;
NNW_Test=NULL; ber=0;
NNW_Test=new strNNW; if(NNW_Test==NULL) { ber=4; goto end;}
if(CopyNNW(NNW_Test,pNNW)!=0) { ber=5; goto end;}
for(i=0;i<pDataBase->n;i++) { pDBF=pDataBase->Get(i); if(pDBF==NULL) continue; if(flAll==0&&pDBF->flUse==0) continue;
pDBF->GetResult(NNW_Test,flAll);}
end: SAFE_DELETE(NNW_Test); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Принятие изменений параметров файла базы данных.

BYTE clDlgDBF_NNW::AcceptDBF(void)
{
//xxx
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление из списка файла базы данных.

BYTE clDlgDBF_NNW::DelDBF(void)
{
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Вставка файла базы данных.

BYTE clDlgDBF_NNW::InsDBF(void)
{
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Добавление файла базы данных.

BYTE clDlgDBF_NNW::AddDBF(void)
{
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Принятие изменений параметров отрезка звука базы данных.

BYTE clDlgDBF_NNW::AcceptDBS(void)
{
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление из списка отрезка звука базы данных.

BYTE clDlgDBF_NNW::DelDBS(void)
{
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Вставка отрезка звука в список.

BYTE clDlgDBF_NNW::InsDBS(void)
{
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Добавление отрезка звука в список.

BYTE clDlgDBF_NNW::AddDBS(void)
{
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Пролистать в поисках файла базы данных.

BYTE clDlgDBF_NNW::BrowseFileDBF(void)
{
//xxx
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении информации о поле человека.

void clDlgDBF_NNW::OnChangeGendDBF(BYTE Gender)
{
//xxx
}

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна базы данных файлов.

INT_PTR CALLBACK DlgProcDB(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE flag; int id; clDlgDBF_NNW *DBFNNW;

if(msg!=WM_INITDIALOG) { DBFNNW=(clDlgDBF_NNW *)GetWindowLong(hDlg,DWL_USER);
if(DBFNNW!=NULL) { LRes=DBFNNW->MsgCommand(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetWindowLong(hDlg,DWL_USER,(long)lParam); DBFNNW=(clDlgDBF_NNW *)lParam;
if(DBFNNW!=NULL) DBFNNW->OnOpenDlg(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK IDCANCEL ............................................................................................
case IDOK: case IDCANCEL: if(id==IDOK) flag=1; else flag=0; EndDialog(hDlg,(int)flag);
if(DBFNNW!=NULL) DBFNNW->OnCloseDlg(); return (INT_PTR)TRUE;
}
break;
}

return (INT_PTR)FALSE;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Вспомогательные программы.

//-----------------------------------------------------------------------------------------------------------
// Нахождение номера звука по букве.

BYTE GetNumSndChar(char cSnd,BYTE typ)
{
BYTE i,j,n; char *Sign;

switch(typ) { default:
case typNNW_Vowel: Sign=SignVoicesVowel; n=nVoicesVowel; break; // Гласные звуки.
case typNNW_Cons: Sign=SignVoicesCons; n=nVoicesCons; break; // Согласные звуки.
}
j=UCHAR_MAX; for(i=0;i<n;i++) if(cSnd==Sign[i]) { j=i; break;} return j;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение типа звука и номера звука в списке по букве.

BYTE GetTypNumSndChar(char cSnd,BYTE *pTyp,BYTE *pNum)
{
BYTE GetNumSndChar(char cSnd,BYTE typ); // Нахождение номера звука по букве.

BYTE i,typ,num;

typ=UCHAR_MAX; for(i=0;i<nTypesNNW;i++) { num=GetNumSndChar(cSnd,i); if(num!=UCHAR_MAX) { typ=i; break;}}
if(typ>=nTypesNNW) return 1; if(pTyp!=NULL) *pTyp=typ; if(pNum!=NULL) *pNum=num; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение массива выходов нейронных элементов.

BYTE GetOutArr(strLay *pLay,float *pArr,BYTE nArr)
{
USHRT i; struct strNeuron *pNeur;

if(pLay==NULL) return 1; if(pLay->IsOK()!=0) return 2; if(pArr==NULL) return 3; if(nArr==0) return 4;
if((USHRT)nArr!=pLay->n) return 5;
for(i=0;i<pLay->n;i++) { pNeur=pLay->Get(i); if(pNeur==NULL) return 6; pArr[i]=(float)pNeur->Val;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение номера звука, которому соответствует максимальное значение в выходном массиве нейронов.

BYTE GetNumSound(strLay *pLay,float Err,BYTE *numSnd)
{
USHRT i,j; double v,vm; struct strNeuron *pNeur;

if(pLay==0) return 1; if(pLay->IsOK()!=0) return 2; if(numSnd==NULL) return 3; *numSnd=UCHAR_MAX;
if(Err<=0.0F||Err>=1.0F) return 4;
j=USHRT_MAX; vm=(float)LrgCnst32_d;
for(i=0;i<pLay->n;i++) { pNeur=pLay->Get(i); if(pNeur==NULL) return 5;
v=1.-pNeur->Val; if(v<0.) v=-v; if(v<vm) { vm=v; j=i;}}
if(j>UCHAR_MAX) j=UCHAR_MAX; if(vm>Err) return messRet; *numSnd=(BYTE)j; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение символа звука.

BYTE GetSymbSound(BYTE num,BYTE typ,char *pSymb)
{
BYTE n; char *Sign;

if(pSymb==NULL) return 1;
switch(typ) { default: return 2;
case typNNW_Vowel: Sign=SignVoicesVowel; n=nVoicesVowel; break; // Гласные звуки.
case typNNW_Cons: Sign=SignVoicesCons; n=nVoicesCons; break; // Согласные звуки.
}
if(num>=n) return 3; *pSymb=Sign[num]; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс для окна визуализации нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

clWinViewNNW::clWinViewNNW(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

clWinViewNNW::~clWinViewNNW(void)
{
CloseFree();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void clWinViewNNW::Zero(void)
{
hwnd=hDlg=hwndOwner=NULL; rcWin=NULL; dxMin=dyMin=0; dxCntrl=dyCntrl=0; SET_ZERO(&rcFrame);
ZeroImgMem(); pNNW=pNNW_Vowel=pNNW_Cons=NULL; typNet=typNNW_Vowel;
AmpNormNeur=AmpNormNeur_Stand; AmpNormInp=AmpNormInp_Stand; AmpNormSynops=AmpNormSynops_Stand;
flWork=1; flAxons=flAxons_Trans;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clWinViewNNW::Free(void)
{
FreeImgMem();
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие окон и освобождение памяти.

void clWinViewNNW::CloseFree(void)
{
CloseDlgCntrl(); CloseWin(); Free();
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров и указателей.

void clWinViewNNW::SetParPnt(HWND hwndOwner_,RECT *rcWin_)
{
hwndOwner=hwndOwner_; rcWin=rcWin_;
}

//-----------------------------------------------------------------------------------------------------------
// Установка указателей на структуры нейронных сетей для гласных и согласных.

void clWinViewNNW::SetPntNeurNet(strNNW *pNNW_Vowel_,strNNW *pNNW_Cons_,strNNW *pNNW_Spectr_)
{
pNNW_Vowel=pNNW_Vowel_; pNNW_Cons=pNNW_Cons_; pNNW_Spectr=pNNW_Spectr_;
}

//-----------------------------------------------------------------------------------------------------------
// Создание окна.

BYTE clWinViewNNW::CreateWin(void)
{
BYTE CheckWindowSize(HWND hwnd,int dxm,int dym); // Установка минимального размера окна.

int dx,dy; DWORD Style;

CloseWin(); if(hInst==NULL) return 1; if(hwndOwner==NULL) return 2; if(IsOKRect(rcWin)!=0) return 3;
dx=(rcWin->right-rcWin->left);
dy=(rcWin->bottom-rcWin->top);
if(dx<=0||dy<=0) return 4;

Style=WS_POPUP|WS_CAPTION|WS_THICKFRAME|WS_MAXIMIZEBOX|WS_MINIMIZEBOX|WS_SYSMENU|WS_CLIPCHILDREN;
hwnd=CreateWindow(ClassNameViewNNW,NameWinViewNNW,Style,(int)rcWin->left,(int)rcWin->top,dx,dy,hwndOwner,NULL,
hInst,NULL); if(hwnd==NULL) { ErrMessage(); return 5;}
SetWindowLong(hwnd,GWL_USERDATA,(LONG)this); ShowWin(hwnd,1);

if(CreateDlgCntrl()!=0) return 6; // Создание диалогового управляющего окна.
GetMinSizeWin(); // Получение минимального размера окна.
CheckWindowSize(hwnd,(int)dxMin,(int)dyMin); // Установка минимального размера окна.
if(SetPosSizeChWin()!=0) return 7; // Установка расположения дочерних окон.

SetNet(typNet); // Установка типа нейронной сети.

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие окна.

void clWinViewNNW::CloseWin(void)
{
CloseWin_(&hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// Действия при закрытии окна.

void clWinViewNNW::OnCloseWin(void)
{
CloseFree(); if(MW!=NULL) MW->ChBtnMenuWinViewNNW();
}

//-----------------------------------------------------------------------------------------------------------
// Получение минимального размера окна.

void clWinViewNNW::GetMinSizeWin(void)
{
dxMin=GetUSHRT_Test((int)MAX(dxViewNNW_Min,dxCntrl)+GetSystemMetrics(SM_CXFRAME)*2);
dyMin=GetUSHRT_Test((int)dyViewNNW_Min+(int)dyCntrl+GetSystemMetrics(SM_CYFRAME)*2+GetSystemMetrics(SM_CYCAPTION));
}

//-----------------------------------------------------------------------------------------------------------
// Установка минимального размера окна.

void clWinViewNNW::SetMinSize(LPMINMAXINFO lpMinMax)
{
BYTE SetMinSizeWin(HWND hwnd,LPMINMAXINFO lpMinMax,int dxm,int dym); // Установка минимального размера окна.

SetMinSizeWin(hwnd,lpMinMax,(int)dxMin,(int)dyMin);
}

//-----------------------------------------------------------------------------------------------------------
// Создание диалогового управляющего окна.

BYTE clWinViewNNW::CreateDlgCntrl(void)
{
LRESULT CALLBACK DlgProcCntrlViewNNW(HWND,UINT,WPARAM,LPARAM); // Управляющее окно окна визуализации нейронной сети.

if(hwnd==NULL) return 1; if(hInst==NULL) return 2; CloseDlgCntrl();
hDlg=CreateDialogParam(hInst,(LPCTSTR)IDD_CNTRL_VIEW_NNW,hwnd,(DLGPROC)DlgProcCntrlViewNNW,(LPARAM)this);
if(hDlg==NULL) return 3;
if(GetClientRect(hDlg,&rc)==FALSE) return 4;
dxCntrl=GetUSHRT_Test((int)(rc.right-rc.left));
dyCntrl=GetUSHRT_Test((int)(rc.bottom-rc.top));
if(dxCntrl==0||dyCntrl==0) return 5;

// Установка состояния окон и элементов управления.
SetFlEdt(hDlg,IDC_AMPL_NEUR,AmpNormNeur,FormNeur);
SetFlEdt(hDlg,IDC_AMPL_SYN,AmpNormSynops,FormSynops);
SetFlEdt(hDlg,IDC_AMPL_INP,AmpNormInp,FormNeur);
SetTxtBtnWork(); // Установка текста в кнопке изображения сети в работе.
CheckRadioButton(hDlg,IDC_RADIO_AXONS,IDC_RADIO_EXCITATION,IDC_RADIO_AXONS+(int)flAxons); // Тип изображения аксонов.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие диалогового управляющего окна.

void clWinViewNNW::CloseDlgCntrl(void)
{
CloseWin_(&hDlg);
}

//-----------------------------------------------------------------------------------------------------------
// Изменение расположения дочерних окон.

void clWinViewNNW::ChPosSizeChWin(void)
{
SetPosSizeChWin(); DrawNetMem(); UpdateWin();
}

//-----------------------------------------------------------------------------------------------------------
// Установка расположения дочерних окон.

BYTE clWinViewNNW::SetPosSizeChWin(void)
{
if(hwnd==NULL) return 1; if(GetClientRect(hwnd,&rc)==FALSE) return 2;
rcFrame.left=rc.left; rcFrame.right=rc.right;
rcFrame.top=rc.top+(long)dyCntrl; rcFrame.bottom=rc.bottom;
if(CreateImgMem()!=0) return 3; // Создание битового образа окна изображения сети.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя для битового образа окна изображения сети.

void clWinViewNNW::ZeroImgMem(void)
{
BmpNet=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти от битового образа окна изображения сети.

void clWinViewNNW::FreeImgMem(void)
{
DeleteBmpMem_(&BmpNet);
}

//-----------------------------------------------------------------------------------------------------------
// Создание битового образа окна изображения сети.

BYTE clWinViewNNW::CreateImgMem(void)
{
BYTE ber; int dx,dy;

ber=0; if(hwnd==NULL) { ber=1; goto end;}
dx=(int)(rcFrame.right-rcFrame.left);
dy=(int)(rcFrame.bottom-rcFrame.top);
if(dx<=0||dy<=0) { ber=2; goto end;}
if(IsOKImgMem()==0) { if(dx==BmpNet->dx&&dy==BmpNet->dy) return 0;}
FreeImgMem();
if(InitBmpMem_(hwnd,&BmpNet,dx,dy,0)!=0) { ber=3; goto end;}
end: if(ber!=0) FreeImgMem(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка битового образа окна изображения сети.

BYTE clWinViewNNW::IsOKImgMem(void)
{
if(BmpNet==NULL) return 1; if(BmpNet->IsOKImg()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование изображения сети в памяти.

BYTE clWinViewNNW::DrawNetMem(void)
{
RECT rc;

if(IsOKImgMem()!=0) return 1; if(MW==NULL) return 2; if(pNNW==NULL) return 3;
rc.left=0; rc.right=(long)BmpNet->dx; rc.top=0; rc.bottom=(long)BmpNet->dy;
if(pNNW->PaintNNW(BmpNet->hdc,&rc,AmpNormNeur,AmpNormSynops,AmpNormInp,&MW->PalPos,&MW->PalSign,flWork,
flAxons)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование в окне.

BYTE clWinViewNNW::OnPaint(HDC hdc)
{
BYTE ber; int iv; RECT rc; HRGN hRgn;

if(hdc==NULL) return 1; if(hwnd==NULL) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3;
hRgn=NULL; ber=0;
hRgn=CreateRectRgnIndirect(&rc); if(hRgn==NULL) { ber=4; goto end;} SelectClipRgn(hdc,hRgn);
if(IsOKImgMem()==0) {
iv=(int)(rcFrame.right-rcFrame.left); if(iv!=BmpNet->dx) { ber=5; goto end;}
iv=(int)(rcFrame.bottom-rcFrame.top); if(iv!=BmpNet->dy) { ber=6; goto end;}
BitBlt(hdc,(int)rcFrame.left,(int)rcFrame.top,BmpNet->dx,BmpNet->dy,BmpNet->hdc,0,0,SRCCOPY);}
ExcludeClipRect(hdc,(int)rcFrame.left,(int)rcFrame.top,(int)rcFrame.right,(int)rcFrame.bottom);
ImgRectC(hdc,&rc,ColDial,ColDial,1);
end: SAFE_DELETE_OBJECT(hRgn); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Перерисовка изображения сети.

void clWinViewNNW::DrawNet(void)
{
if(hwnd==NULL) return;
DrawNetMem(); // Рисование изображения сети в памяти.
UpdateWin(); // Перерисовка окна.
}

//-----------------------------------------------------------------------------------------------------------
// Перерисовка окна.

void clWinViewNNW::UpdateWin(void)
{
UpdateWindow_(hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// Установка типа нейронной сети.

void clWinViewNNW::SetNet_(BYTE typ)
{
switch(typ) { default:
case typNNW_Vowel:  typNet=typNNW_Vowel;  pNNW=pNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   typNet=typNNW_Cons;   pNNW=pNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: typNet=typNNW_Spectr; pNNW=pNNW_Spectr; break; // Для всего спектра.
}
}

//-----------------------------------------------------------------------------------------------------------
// Установка типа нейронной сети.

void clWinViewNNW::SetNet(BYTE typ)
{
SetNet_(typ); CheckRadioButton(hDlg,IDC_RADIO_VOWEL,IDC_RADIO_SPECTR,IDC_RADIO_VOWEL+(int)typNet); DrawNet();
}

//-----------------------------------------------------------------------------------------------------------
// Выбор типа сети.

void clWinViewNNW::OnSelectTypNet(int id)
{
BYTE typ;

switch(id) { default: return;
case IDC_RADIO_VOWEL:  typ=typNNW_Vowel; break; // Гласные звуки.
case IDC_RADIO_CONS:   typ=typNNW_Cons; break; // Согласные звуки.
case IDC_RADIO_SPECTR: typ=typNNW_Spectr; break; // Все (для спектра).
}
if(typ==typNet) return; SetNet_(typ); DrawNet();
}

//-----------------------------------------------------------------------------------------------------------
// Установка флага изображения сети в работе.

void clWinViewNNW::SetFlagWork(BYTE flWork_)
{
if(flWork==flWork_) return; flWork=flWork_; SetTxtBtnWork(); DrawNet();
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопке изображения сети в работе.

void clWinViewNNW::SetTxtBtnWork(void)
{
int idS; char *cp;

if(hDlg==NULL) return; if(hInst==NULL) return;
if(flWork==0) idS=IDS_BtnNNWWork_Work; else idS=IDS_BtnNNWWork_Net;
if(LoadString(hInst,idS,TxtStr,strL_Txt)!=0) cp=TxtStr; else cp="-";
SetDlgItemText(hDlg,IDC_WORK,TxtStr);
}

//-----------------------------------------------------------------------------------------------------------
// Установка типа изображения для аксонов.

void clWinViewNNW::OnSelectTypShowAxons(int id)
{
BYTE fl;

switch(id) { default: return;
case IDC_RADIO_AXONS:      fl=flAxons_Axons; break; // Весовые коэффициенты 'Wij'.
case IDC_RADIO_TRANSFER:   fl=flAxons_Trans; break; // Передающиеся величины: 'Yi*Wij'.
case IDC_RADIO_SHIFTS:     fl=flAxons_Shifts; break; // Смещения 'Sij' для "умных" нейронов.
case IDC_RADIO_EXCITATION: fl=flAxons_Excit; break; // Возбуждения - передающиеся величины минус смещения: '(Yi-Sij)*Wij'.
}
if(fl==flAxons) return; flAxons=fl; DrawNet();
}

//-----------------------------------------------------------------------------------------------------------
// Обработка сообщений окна.

LRESULT clWinViewNNW::MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
HDC hdc; PAINTSTRUCT ps;

if(flag==NULL) return 0L; *flag=0; if(hwnd==NULL) return 0L; if(msg==WM_CREATE) return 0L;

switch(msg) { default: break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1; break;

// WM_GETMINMAXINFO .........................................................................................
case WM_GETMINMAXINFO: *flag=1; SetMinSize((LPMINMAXINFO)lParam); break;

// WM_SIZE ..................................................................................................
case WM_SIZE: *flag=1; if(wParam==SIZE_MINIMIZED) break; ChPosSizeChWin(); break;

// WM_SYSCOMMAND ............................................................................................
case WM_SYSCOMMAND: if(wParam==SC_CLOSE) OnCloseWin(); break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; hdc=BeginPaint(hwnd,&ps); OnPaint(hdc); EndPaint(hwnd,&ps); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWin_(&hwnd); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка очереди сообщений окна управления.

LRESULT clWinViewNNW::MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
if(flag==NULL) return 0L; *flag=0; if(hDlg==NULL) return 0L; if(msg==WM_INITDIALOG) return 0L;

switch(msg) { default: break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: if(Command(wParam)==0) *flag=1; break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Команды.

BYTE clWinViewNNW::Command(WPARAM wParam)
{
BYTE flag; int id; float coe;

if(hDlg==NULL) return 1; flag=0; id=LOWORD(wParam);

switch(id) { default: flag=2; break;

// IDC_AMPLM_NEUR IDC_AMPLP_NEUR ............................................................................
case IDC_AMPLM_NEUR: case IDC_AMPLP_NEUR: coe=(float)pow(2.,0.25);
if(id==IDC_AMPLM_NEUR) AmpNormNeur*=coe; else AmpNormNeur/=coe;
SetFlEdt(hDlg,IDC_AMPL_NEUR,AmpNormNeur,FormNeur); DrawNet(); break;

// IDC_AMPLOK_NEUR ..........................................................................................
case IDC_AMPLOK_NEUR: GetFlEdt(hDlg,IDC_AMPL_NEUR,&AmpNormNeur); DrawNet(); break;

// IDC_AMPLM_SYN IDC_AMPLP_SYN ..............................................................................
case IDC_AMPLM_SYN: case IDC_AMPLP_SYN: coe=(float)pow(2.,0.25);
if(id==IDC_AMPLM_SYN) AmpNormSynops*=coe; else AmpNormSynops/=coe;
SetFlEdt(hDlg,IDC_AMPL_SYN,AmpNormSynops,FormSynops); DrawNet(); break;

// IDC_AMPLOK_SYN ...........................................................................................
case IDC_AMPLOK_SYN: GetFlEdt(hDlg,IDC_AMPL_SYN,&AmpNormSynops); DrawNet(); break;

// IDC_AMPLM_INP IDC_AMPLP_INP ..............................................................................
case IDC_AMPLM_INP: case IDC_AMPLP_INP: coe=(float)pow(2.,0.25);
if(id==IDC_AMPLM_INP) AmpNormInp*=coe; else AmpNormInp/=coe;
SetFlEdt(hDlg,IDC_AMPL_INP,AmpNormInp,FormNeur); DrawNet(); break;

// IDC_AMPLOK_INP ...........................................................................................
case IDC_AMPLOK_INP: GetFlEdt(hDlg,IDC_AMPL_INP,&AmpNormInp); DrawNet(); break;

// IDC_RADIO_VOWEL IDC_RADIO_CONS IDC_RADIO_SPECTR ..........................................................
case IDC_RADIO_VOWEL: case IDC_RADIO_CONS: case IDC_RADIO_SPECTR: OnSelectTypNet(id); break;

// IDC_WORK .................................................................................................
case IDC_WORK: SetFlagWork(1-flWork); break;

// IDC_RADIO_AXONS IDC_RADIO_TRANSFER IDC_RADIO_SHIFTS IDC_RADIO_EXCITATION .................................
case IDC_RADIO_AXONS: case IDC_RADIO_TRANSFER: case IDC_RADIO_SHIFTS: case IDC_RADIO_EXCITATION:
OnSelectTypShowAxons(id); break;
}

return flag;
}

//-----------------------------------------------------------------------------------------------------------
// Функция обработки сообщений окна визуализации нейронной сети.

LRESULT CALLBACK WndViewNNW(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE flag; clWinViewNNW *WinViewNNW_;

if(msg!=WM_CREATE) { WinViewNNW_=(clWinViewNNW *)GetWindowLong(hwnd,GWL_USERDATA);
if(WinViewNNW_!=NULL) { LRes=WinViewNNW_->MsgCommand(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) {

default: return DefWindowProc(hwnd,msg,wParam,lParam);

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: break;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hwnd,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hwnd); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: SetWindowLong(hwnd,GWL_USERDATA,0L); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Управляющее окно окна визуализации нейронной сети.

LRESULT CALLBACK DlgProcCntrlViewNNW(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{   
BYTE flag; clWinViewNNW *WinViewNNW_;

if(msg!=WM_INITDIALOG) { WinViewNNW_=(clWinViewNNW *)GetWindowLong(hDlg,DWL_USER);
if(WinViewNNW_!=NULL) { LRes=WinViewNNW_->MsgCommandCntrl(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetWindowLong(hDlg,DWL_USER,(long)lParam); return (LRESULT)TRUE;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hDlg,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hDlg); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: SetWindowLong(hDlg,DWL_USER,0L); break;
}

return FALSE;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс для окна текста распознавания.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

clWinText::clWinText(void)
{
Zero(); CreateBrushes();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

clWinText::~clWinText(void)
{
CloseEdt(); CloseWin(); Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void clWinText::Zero(void)
{
hwnd=hwndEdt=hwndOwner=NULL; rcWin=NULL; ZeroBrushes(); ZeroFont(); dxMin=dyMin=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clWinText::Free(void)
{
FreeBrushes(); FreeFont();
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров и указателей.

void clWinText::SetParPnt(HWND hwndOwner_,RECT *rcWin_)
{
hwndOwner=hwndOwner_; rcWin=rcWin_;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление кистей для закрашивания окон.

void clWinText::ZeroBrushes(void)
{
hBrushBkg=hBrushDial=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Создание кистей для закрашивания окон.

void clWinText::FreeBrushes(void)
{
SAFE_DELETE_OBJECT(hBrushBkg);
SAFE_DELETE_OBJECT(hBrushDial);
}

//-----------------------------------------------------------------------------------------------------------
// Создание кистей для закрашивания окон.

BYTE clWinText::CreateBrushes(void)
{
FreeBrushes();
hBrushBkg=CreateSolidBrush(COL_WHITE); if(hBrushBkg==NULL) return 1;
hBrushDial=CreateSolidBrush(ColDial); if(hBrushDial==NULL) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя для шрифта.

void clWinText::ZeroFont(void)
{
hFontText=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление шрифта.

void clWinText::FreeFont(void)
{
SAFE_DELETE_OBJECT(hFontText);
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка шрифта.

BYTE clWinText::LoadFont(void)
{
FreeFont(); if(IsOKStr(NameFontWinTest)!=0) return 1;
hFontText=GetFont(NameFontWinTest,0,-HeiFontText); if(hFontText==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание окна.

BYTE clWinText::CreateWin(void)
{
BYTE CheckWindowSize(HWND hwnd,int dxm,int dym); // Установка минимального размера окна.

int dx,dy; DWORD Style;

CloseWin(); if(hInst==NULL) return 1; if(hwndOwner==NULL) return 2; if(IsOKRect(rcWin)!=0) return 3;
dx=(rcWin->right-rcWin->left);
dy=(rcWin->bottom-rcWin->top);
if(dx<=0||dy<=0) return 4;
if(LoadFont()!=0) return 5; // Загрузка шрифта.

Style=WS_POPUP|WS_CAPTION|WS_THICKFRAME|WS_MAXIMIZEBOX|WS_MINIMIZEBOX|WS_SYSMENU|WS_CLIPCHILDREN;
hwnd=CreateWindow(ClassNameText,NameWinText,Style,(int)rcWin->left,(int)rcWin->top,dx,dy,hwndOwner,NULL,
hInst,NULL); if(hwnd==NULL) { ErrMessage(); return 6;}
SetWindowLong(hwnd,GWL_USERDATA,(LONG)this); ShowWin(hwnd,1);

GetMinSizeWin(); // Получение минимального размера окна.
CheckWindowSize(hwnd,(int)dxMin,(int)dyMin); // Установка минимального размера окна.
if(SetPosSizeChWin()!=0) return 7; // Установка расположения дочерних окон.
if(CreateEdt()!=0) return 8; // Создание окна редактирования.

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие окна.

void clWinText::CloseWin(void)
{
CloseWin_(&hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// Действия при закрытии окна.

void clWinText::OnCloseWin(void)
{
CloseEdt(); CloseWin(); if(MW!=NULL) MW->ChBtnMenuWinText();
}

//-----------------------------------------------------------------------------------------------------------
// Получение минимального размера окна.

void clWinText::GetMinSizeWin(void)
{
dxMin=GetUSHRT_Test((int)dxWinText_Min+GetSystemMetrics(SM_CXFRAME)*2);
dyMin=GetUSHRT_Test((int)dyWinText_Min+GetSystemMetrics(SM_CYFRAME)*2+GetSystemMetrics(SM_CYCAPTION));
}

//-----------------------------------------------------------------------------------------------------------
// Установка минимального размера окна.

void clWinText::SetMinSize(LPMINMAXINFO lpMinMax)
{
BYTE SetMinSizeWin(HWND hwnd,LPMINMAXINFO lpMinMax,int dxm,int dym); // Установка минимального размера окна.

SetMinSizeWin(hwnd,lpMinMax,(int)dxMin,(int)dyMin);
}

//-----------------------------------------------------------------------------------------------------------
// Создание окна редактирования.

BYTE clWinText::CreateEdt(void)
{
int dx,dy; DWORD Style;

if(hwnd==NULL) return 1; if(hInst==NULL) return 2; CloseEdt();
dx=(int)(rcEdt.right-rcEdt.left);
dy=(int)(rcEdt.bottom-rcEdt.top);
if(dx<=0||dy<=0) return 3;
Style=WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT|ES_MULTILINE|ES_AUTOVSCROLL|ES_READONLY;
hwndEdt=CreateWindow("edit","",Style,0,0,dx,dy,hwnd,(HMENU)id_Win_Edit,hInst,NULL);
if(hwndEdt==NULL) return 4;
if(SetFont(hwndEdt,hFontText)!=0) return 5;
SendMessage(hwndEdt,EM_LIMITTEXT,(WPARAM)MaxSizeEdt,0L); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие окна редактирования.

void clWinText::CloseEdt(void)
{
CloseWin_(&hwndEdt);
}

//-----------------------------------------------------------------------------------------------------------
// Изменение расположения дочерних окон.

void clWinText::ChPosSizeChWin(void)
{
SetPosSizeChWin(); SetPosWindow(hwndEdt,&rcEdt);
}

//-----------------------------------------------------------------------------------------------------------
// Установка расположения дочерних окон.

BYTE clWinText::SetPosSizeChWin(void)
{
if(hwnd==NULL) return 1; if(GetClientRect(hwnd,&rcEdt)==FALSE) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в окне.

BYTE clWinText::SetText(char *Text)
{
if(hwndEdt==NULL) return 1; if(IsOKStr(Text)!=0) SetWindowText(hwndEdt,"");
SetWindowText(hwndEdt,Text); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Очистка окна.

void clWinText::ClearWin(void)
{
if(hwndEdt==NULL) return; SetWindowText(hwndEdt,"");
}

//-----------------------------------------------------------------------------------------------------------
// Обработка сообщений окна.

LRESULT clWinText::MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
int id; HDC hdc;

if(flag==NULL) return 0L; *flag=0; if(hwnd==NULL) return 0L; if(msg==WM_CREATE) return 0L;

switch(msg) { default: break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1; break;

// WM_GETMINMAXINFO .........................................................................................
case WM_GETMINMAXINFO: *flag=1; SetMinSize((LPMINMAXINFO)lParam); break;

// WM_CTLCOLORSTATIC ........................................................................................
case WM_CTLCOLORSTATIC: hdc=(HDC)wParam; id=GetDlgCtrlID((HWND)lParam); if(id<=0) break; *flag=1;
SetBkColor(hdc,GetSysColor(COLOR_WINDOW)); SetTextColor(hdc,GetSysColor(COLOR_BTNTEXT));
SetBkMode(hdc,TRANSPARENT); if(id==id_Win_Edit) return (LRESULT)hBrushBkg; return (LRESULT)hBrushDial;

// WM_SIZE ..................................................................................................
case WM_SIZE: *flag=1; if(wParam==SIZE_MINIMIZED) break; ChPosSizeChWin(); break;

// WM_SYSCOMMAND ............................................................................................
case WM_SYSCOMMAND: if(wParam==SC_CLOSE) OnCloseWin(); break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; ImgWinC(hwnd,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWin_(&hwnd); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Функция обработки сообщений окна текста.

LRESULT CALLBACK WndViewText(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE flag; clWinText *WinText_;

if(msg!=WM_CREATE) { WinText_=(clWinText *)GetWindowLong(hwnd,GWL_USERDATA);
if(WinText_!=NULL) { LRes=WinText_->MsgCommand(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) {

default: return DefWindowProc(hwnd,msg,wParam,lParam);

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: break;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hwnd,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hwnd); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: SetWindowLong(hwnd,GWL_USERDATA,0L); break;
}

return 0L;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров для анализа потока данных для звука.

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParAnSnd::IsOK(void)
{
if(tStore<=0.0F) return 1; if(weiStore<=0.0F) return 2; if(weiInst<=0.0F) return 3; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура для анализа потока данных для звука.

//-----------------------------------------------------------------------------------------------------------

strAnSnd::strAnSnd(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

strAnSnd::~strAnSnd(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strAnSnd::Zero(void)
{
nBuf=0; Buf=NULL; weiStore=weiInst=0.0F; cnt=0; sum=0.;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strAnSnd::Free(void)
{
SAFE_DELETE_ARR(Buf); nBuf=0;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

BYTE strAnSnd::Init(strParAnSnd *PAS,float tStep)
{
if(PAS==NULL) return 1; if(PAS->IsOK()!=0) return 2; if(tStep<=0.0F) return 3; Free();
weiStore=PAS->weiStore; weiInst=PAS->weiInst;
nBuf=GetUSHRT_Test(PAS->tStore/tStep); if(nBuf<=1) nBuf=2;
Buf=new float[nBuf]; if(Buf==NULL) { nBuf=0; return 4;}
if(Start()!=0) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strAnSnd::IsOK(void)
{
if(Buf==NULL) return 1; if(nBuf==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Начало работы.

BYTE strAnSnd::Start(void)
{
USHRT i;

cnt=0; sum=0.; if(IsOK()!=0) return 1; for(i=0;i<nBuf;i++) Buf[i]=0.0F; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг работы.

BYTE strAnSnd::Step(float Val,float *pRes)
{
float v,*fp;

if(IsOK()!=0) return 1; if(cnt>=nBuf) return 2;
fp=Buf+cnt; sum-=(double)*fp; *fp=Val; sum+=(double)*fp; cnt++; if(cnt>=nBuf) cnt=0; 
if(pRes==NULL) return 0; v=(float)(sum/(double)nBuf); *pRes=v*weiStore+Val*weiInst; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура для анализа потока данных для нескольких звуков.

//-----------------------------------------------------------------------------------------------------------

strAnSndArr::strAnSndArr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

strAnSndArr::~strAnSndArr(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strAnSndArr::Zero(void)
{
pArr=NULL; nArr=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strAnSndArr::Free(void)
{
Clear(); SAFE_DELETE_ARR(pArr); nArr=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти в структурах.

void strAnSndArr::Clear(void)
{
BYTE i;

if(IsOK()!=0) return; for(i=0;i<nArr;i++) pArr[i].Free();
}

//-----------------------------------------------------------------------------------------------------------
// Создание массива.

BYTE strAnSndArr::Create(BYTE nArr_)
{
Free(); if(nArr_==0) return 1; pArr=new strAnSnd[nArr_]; if(pArr==NULL) return 2; nArr=nArr_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива структур.

BYTE strAnSndArr::IsOK(void)
{
if(pArr==NULL) return 1; if(nArr==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

BYTE strAnSndArr::Init(strParAnSnd *PAS,BYTE nPAS,float tStep,BYTE flNew)
{
BYTE i;

if(PAS==NULL) return 1; if(nPAS==0) return 2; if(tStep<=0.0F) return 3;
if(flNew==0) { if(IsOK()!=0) return 4; if(nPAS!=nArr) return 5; Clear();}
else { if(Create(nPAS)!=0) return 6;}
if(nPAS!=nArr) return 7; for(i=0;i<nArr;i++) { if(pArr[i].Init(PAS+i,tStep)!=0) return 8;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Начало работы.

BYTE strAnSndArr::Start(void)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nArr;i++) if(pArr[i].Start()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг работы.

BYTE strAnSndArr::Step(float *pVal,float *pRes,BYTE nVal)
{
BYTE i; float v,*fp;

if(nVal==0) return 1; if(IsOK()!=0) return 2; if(nVal!=nArr) return 3;
for(i=0;i<nArr;i++) { if(pVal!=NULL) v=pVal[i]; else v=0.; if(pRes==NULL) fp=NULL; else fp=pRes+i;
if(pArr[i].Step(v,fp)!=0) return 4;}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура для анализа потока данных.

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

BYTE strAnalyseSound::Init(float tStep,BYTE flNew)
{
if(tStep<=0.0F) return 1;
if(AnSndVowel.Init(ParAnSndVowel,nVoicesVowel,tStep,flNew)!=0) return 1;
if(AnSndCons.Init(ParAnSndCons,nVoicesCons,tStep,flNew)!=0) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Начало работы.

BYTE strAnalyseSound::Start(void)
{
if(AnSndVowel.Start()!=0) return 1; if(AnSndCons.Start()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг работы.

BYTE strAnalyseSound::Step(float *pVal,BYTE nVal,BYTE typNet,BYTE *typSnd,BYTE *numSnd)
{
BYTE n,i,typ; float *fpV,*fpC,vM,v;

if(pVal==NULL) return 1; if(nVal==0) return 2; if(typSnd==NULL) return 3; if(numSnd==NULL) return 4;
switch(typNet) { default: return 5;
case typNNW_Vowel: n=nVoicesVowel; fpV=pVal; fpC=NULL; break; // Для гласных и сонорных звуков.
case typNNW_Cons: n=nVoicesCons; fpV=NULL; fpC=pVal; break; // Для согласных взрывных и шипящих звуков.
case typNNW_Spectr: n=nVoicesVowel+nVoicesCons; fpV=pVal; fpC=pVal+nVoicesVowel; break; // Применение нейронных сетей сразу для всего спектра.
}
if(nVal!=n) return 6;
if(AnSndVowel.Step(fpV,ResVowel,nVoicesVowel)!=0) return 7;
if(AnSndCons.Step(fpC,ResCons,nVoicesCons)!=0) return 8;

n=UCHAR_MAX; typ=UCHAR_MAX; vM=0.0F;
for(i=0;i<nVoicesVowel;i++) { v=ResVowel[i]; if(v>vM) { vM=v; n=i; typ=typNNW_Vowel;}}
for(i=0;i<nVoicesCons;i++) { v=ResCons[i]; if(v>vM) { vM=v; n=i; typ=typNNW_Cons;}}
if(vM==0.0F||typ==UCHAR_MAX||n==UCHAR_MAX) { NoSymb: *typSnd=UCHAR_MAX; *numSnd=UCHAR_MAX; return 0;}
if(vM*0.5F<LevSoundDecStore) goto NoSymb; *typSnd=typ; *numSnd=n; return 0;
}
