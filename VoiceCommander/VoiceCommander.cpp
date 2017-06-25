/*...........................................................................................................

WinMain,InitCommonControls_,
RegisterClassAll,RegisterClassMain,RegisterClassText,
InitMain,

// Класс главного окна.
class clMain {
clMain,~clMain,Zero,Free,
ZeroBrushes,FreeBrushes,CreateBrushes,
ZeroMenu,FreeMenu,CreateMenu,ShowMenu,
ZeroHelp,FreeHelp,CreateHelp,ChMenuHelp,
OnCreate,CreateDlgCntrl,GetMinSizeWin,SetMinSize,MoveWinCorner,
MsgCommand,MsgCommandCntrl,Command,CommandCntrl,OnPaint,
ZeroSndCapData,FreeSndCapData,CreateSndCapData,
ZeroSndCap,FreeSndCap,CreateSndCap,SaveBufSound,StartCaptureSound,StopCaptureSound,StopCaptureSound_,
ChBtnMenuCaptureSound,SetTxtBtnRecSound,DlgAdjSound,ProcRecRealTime,GetNumSndRecogn,ShowProgr,
LoadNNW,LoadDict,
SetPntWinText,GetSizeWinText,OpenWinText,ChMenuWinText,ClearWinText,SetWinText,
RecognTxtCommand,AddSymbTextWin,AddWordTextWin,DoCommand,OpenSysProg,OpenProgFiles,ShowCommand,SetText,
SetWord,SetString,ChMenuDoCommands,ChMenuOutWords,OnCloseWin},
FunSndCap_CallBack,DecSnd_Store,
WndProcMain,DlgProcCntrlMain,

// Класс для окна текста распознавания.
class clWinText {
clWinText,~clWinText,Zero,SetParPnt,
ZeroBrushes,FreeBrushes,CreateBrushes,
CreateWindow,CloseWindow,OnCloseWin,GetMinSizeWin,SetMinSize,
CreateEdt,CloseEdt,ChPosSizeChWin,SetPosSizeChWin,SetText,ClearWin,MsgCommand},
WndViewText,

DlgAbout,GetPath

...........................................................................................................*/

#include "stdafx.h"
#include <shlobj.h>

#include "VC_con.h"
#include "cmplx.h"
#include "VC_cls.h"
#include "VC_pro.h"
#include "VC_snd.h"
#include "VC.h"
#include "resource.h"

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
BYTE IsOKStr(char *str); // Проверка строки.
BYTE GetString(char **String,char **Items,BYTE n); // Сборка строки из нескольких строк.
void ImgWinC(HWND hwnd,DWORD ColP,DWORD ColB); // Закрашивание окна.
void SetStMenuItem_(HMENU hMenu,UINT id,SCHAR En,SCHAR Ch); // Установка состояния пункта меню.
void CloseWin_(HWND *hwnd); // Закрытие окна.
void DestroyWin_(HWND *hwnd); // Уничтожение окна с обнулением 'hwnd'.
void ShowWin(HWND hwnd,BYTE flVis); // Отображение или скрытие окна.
BYTE SetPosWindow(HWND hwnd,RECT *rc); // Установка расположения окна.
void SetPosWindowCenter(HWND hDlg); // Помещение окна в центр другого окна или экрана.
BYTE CheckWindowSize(HWND hwnd,int dxm,int dym); // Установка минимального размера окна.
HWND InitProgress(HWND hDlg,int id); // Инициализация окна показа процента выполнения работы.
void SetColProgr(HWND hwnd,DWORD BkgCol,DWORD BarCol); // Установка цветов индикаторной полосы показа процента выполнения работы.
USHRT GetUSHRT_Test(int iv); // Получение числа 'USHRT' из числа 'int' с проверкой выхода за пределы 'USHRT'.
USHRT GetUSHRT_Test(double d); // Получение числа 'USHRT' из числа 'double' с проверкой выхода за пределы 'USHRT'.
UINT GetUINT_Test(float v); // Получение числа 'UINT' из числа 'float' с проверкой выхода за пределы 'UINT'.
void Message(UINT StrID,UINT typ); // Вывод сообщения.
void ErrMessage(void); // Выдача сообщения об ошибке.
void SoundBlock(void); // Звук при заблокированном действии.
void ProcMess(void); // Опрос очереди сообщений и обработка сообщений.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные переменные.

HINSTANCE hInst; // Идентификатор приложения.
LRESULT LRes; // Вспомогательная переменная.

// Курсоры общего назначения.
HCURSOR cur_wait;

BYTE methDecSound=methDecSnd_Store; // Метод обработки потока звуков.

DWORD ColDial; // Цвет фона или диалогового окна.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Массивы.

// Идентификаторы названий команд.
int IDA_Commands[nCommands]={IDS_Command_ShutDownQuest,IDS_Command_ShutDown,IDS_Command_CloseWin,
IDS_Command_StopRec,IDS_Command_ShowHelp,IDS_Command_OpenNotepad,IDS_Command_OpenPaint,IDS_Command_OpenWord,
IDS_Command_IntExpl};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Классы и структуры.

clMain MW;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров для анализа потока данных для звука.
//struct strParAnSnd { char Symb; BYTE type; float tStore,weiStore,weiInst; BYTE nCntSymb,nCntNoSymb;};

struct strParAnSnd ParAnSnd[nVoices+1]={
// Гласные звуки.
{'а',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'э',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'о',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'у',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'ы',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'я',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'е',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'ё',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'ю',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
{'и',typSnd_Vowel,tStVowel,     weiStoreVowel,weiInstVowel, nCntSymbVowel,nCntNoSymbVowel},
// Сонорные звуки.
{'л',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
{'м',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
{'н',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
{'р',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
{'в',typSnd_Sonor,tStSonor,     weiStoreSonor,weiInstSonor, nCntSymbSonor,nCntNoSymbSonor},
// Импульсные согласные звуки.
{'б',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'п',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'г',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'к',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'д',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'т',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'ч',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
{'ц',typSnd_ConsPulse,tStPulse, weiStorePulse,weiInstPulse, nCntSymbPulse,nCntNoSymbPulse},
// Турбулентные согласные звуки.
{'ж',typSnd_ConsTone,tStHTone,  weiStoreTone,weiInstTone,   nCntSymbTone,nCntNoSymbTone},
{'з',typSnd_ConsTone,tStHTone,  weiStoreTone,weiInstTone,   nCntSymbTone,nCntNoSymbTone},
{'й',typSnd_ConsTone,tStHTone,  weiStoreTone,weiInstTone,   nCntSymbTone,nCntNoSymbTone},
// Шипящие согласные звуки.
{'с',typSnd_ConsTurb,tStTurb,   weiStoreTurb,weiInstTurb,   nCntSymbTurb,nCntNoSymbTurb},
{'ф',typSnd_ConsTurb,tStTurb,   weiStoreTurb,weiInstTurb,   nCntSymbTurb,nCntNoSymbTurb},
{'х',typSnd_ConsTurb,tStTurb,   weiStoreTurb,weiInstTurb,   nCntSymbTurb,nCntNoSymbTurb},
// Шипяще-тоновые согласные звуки.
{'ш',typSnd_ConsHiss,tStHiss,   weiStoreHiss,weiInstHiss,   nCntSymbHiss,nCntNoSymbHiss},
{'щ',typSnd_ConsHiss,tStHiss,   weiStoreHiss,weiInstHiss,   nCntSymbHiss,nCntNoSymbHiss},
// Молчание.
{' ',typSnd_Silence,tStSilence, 0.0F,0.0F, nCntSymbSilence,nCntNoSymbSilence}
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Строки.

char TxtStr[strL_Txt],TxtMem[strL_Txt]; // Вспомогательные строки.
char PathToProgDir[strL_Path]; // Директория программы.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Названия классов.

char const NameClassMainWin[]="ClassMainWinVoiceCommander"; // Имя класса главного окна.
char const ClassNameText[]="ClassNameText"; // Имя класса для окна текста.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Названия окон.

char const TitleVC[]="Голосовое управление компьютером"; // Название программы.
char const NameWinText[]="Результат распознавания"; // Заголовок окна текста.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Расширения файлов.

char *extHTM=".htm"; // Расширение файлов справки в формате '*.htm'.
char *extNNW_Spectr=".nnws"; // Расширение файла нейронной сети.
char *extDict=".txt"; // Расширение файла словаря.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Директории.

char *dirHelp="Help\\"; // Директория с файлами справки.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Имена файлов.

char *NameDLLSoundCap="SoundCap.dll"; // Имя библиотеки *.dll для захвата звука.
char *nameNNW_Spectr="NeuralNet"; // Имя файла нейронной сети.
char *nameHlpProg="VC"; // Имя справки по программе.
char *nameDict="Dictionary"; // Имя файла словаря.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Шрифты.

char *NameFontWinTest="Times New Roman"; // Шрифт для окна вывода текста.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Пути к различным директориям компьютера.

char const *PathToProgFiles="\\Program Files\\";
char const *PathToMOffice="Microsoft Office\\Office10\\";
char const *PathInternExpl="Internet Explorer\\";

//-----------------------------------------------------------------------------------------------------------

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
BYTE InitCommonControls_(void); // Загрузка классов для кнопок и окон управления 'Windows'.
BYTE RegisterClassAll(void); // Регистрация всех классов.
BYTE GetPath(BYTE typ); // Получение имени директории с программой.

UNREFERENCED_PARAMETER(hPrevInstance);
UNREFERENCED_PARAMETER(lpCmdLine);

MSG msg; HACCEL hAccelTable; HWND hwnd;

hInst=hInstance;
ColDial=GetSysColor(COLOR_BTNFACE); // Получение цвета фона или диалогового окна.
cur_wait=LoadCursor(NULL,IDC_WAIT);
if(InitCommonControls_()!=0) return FALSE; // Загрузка классов для кнопок и окон управления 'Windows'.

if(RegisterClassAll()!=0) return FALSE; // Регистрация всех классов.
if(GetPath(0)!=0) return FALSE; // Получение имени директории с программой.

// Создание главного окна.
hwnd=CreateWindow(NameClassMainWin,TitleVC,WS_POPUP|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,0,0,0,0,NULL,NULL,hInst,NULL);
if(hwnd==NULL) { ErrMessage(); return FALSE;}
ShowWin(hwnd,1);

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
ATOM RegisterClassText(void); // Регистрация класса окна текста.

if(!RegisterClassMain()) return 1; // Регистрация класса главного окна.
if(!RegisterClassText()) return 2; // Регистрация класса окна текста.
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
wcex.lpszMenuName	= NULL;
wcex.lpszClassName	= NameClassMainWin;
wcex.hIconSm		= LoadIcon(hInst,MAKEINTRESOURCE(IDI_PROG));
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
// Инициализация класса главного окна.

BYTE InitMain(HWND hwnd)
{
if(hwnd==NULL) return 1; if(MW.OnCreate(hwnd)!=0) return 2; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс главного окна.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

clMain::clMain(void)
{
Zero();
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
hwnd=hDlg=hwndProgr=NULL; ZeroBrushes(); ZeroMenu(); ZeroHelp(); ZeroSndCap(); ZeroSndCapData();
flDoCommands=1;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clMain::Free(void)
{
FreeBrushes(); FreeMenu(); FreeHelp(); FreeSndCap(); FreeSndCapData();
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
// Обнуление указателей для меню.

void clMain::ZeroMenu(void)
{
hMenu=hMenu_=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти от меню.

void clMain::FreeMenu(void)
{
if(hMenu_!=NULL) { DestroyMenu(hMenu_); hMenu_=NULL;} hMenu=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Создание и загрузка меню.

BYTE clMain::CreateMenu(void)
{
BYTE ber;

FreeMenu(); if(hInst==NULL) return 1;
hMenu_=LoadMenu(hInst,(LPCTSTR)IDM_MAIN); if(hMenu_==NULL) return 2;
ber=0;
hMenu=GetSubMenu(hMenu_,0); if(hMenu==NULL) { ber=3; goto end;}
end: if(ber!=0) FreeMenu(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Отображает меню на экране.

BYTE clMain::ShowMenu(LPARAM lParam)
{
int cmd; POINT pt;

if(hwnd==NULL) return 1; if(hMenu==NULL) return 2;
pt.x=(long)LOWORD(lParam);
pt.y=(long)HIWORD(lParam);
if(ClientToScreen(hwnd,&pt)==FALSE) return 3;
cmd=(int)TrackPopupMenu(hMenu,TPM_LEFTALIGN|TPM_TOPALIGN|TPM_RETURNCMD|TPM_RIGHTBUTTON,(int)pt.x,(int)pt.y,0,hwnd,NULL);
if(cmd!=0) SendMessage(hwnd,WM_COMMAND,cmd,0L); return 0;
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
// Дейсвтия в начале работы программы.

BYTE clMain::OnCreate(HWND hwnd_)
{
if(hwnd_==NULL) return 1; hwnd=hwnd_;
if(CreateMenu()!=0) return 2; // Создание и загрузка меню.
if(CreateDlgCntrl()!=0) return 3; // Создание диалогового управляющего окна.
MoveWinCorner(); // Перемещение окна в нижний правый угол.
if(CreateSndCap()!=0) return 4; // Создание объекта класса библиотеки захвата звука.
if(CreateSndCapData()!=0) return 5; // Класс хранения данных при записи звука: создание.
if(LoadNNW()!=0) { Message(IDS_NoNNW_Found,MB_EX); return messRet;} // Загрузка нейронных сетей.
if(LoadDict()!=0) Message(IDS_NoDict_Loaded,MB_IN); // Загрузка словаря.
AnStream.Init(); // Инициализация структуры для обработки потока символов звуков.
SetPntWinText(); // Установка параметров и указателей для окна текста.
GetSizeWinText(); // Установка размеров окна текста.
CreateHelp(); // Создание класса для вывода файла справки.
ChMenuDoCommands(); // Изменение выделения пункта меню принятия команд.
ChMenuOutWords(); // Изменение выделения пункта меню вывода в окно распознанных слов.
ChBtnMenuCaptureSound(); // Выделение пункта меню захвата звука и изменение кнопки.
return 0;
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
if(GetMinSizeWin()!=0) return 5; // Получение минимального размера окна.
CheckWindowSize(hwnd,(int)dxMin,(int)dyMin); // Установка минимального размера окна.

hwndProgr=InitProgress(hDlg,IDC_PROGRESS_AMP_SOUND); // Инициализация окна показа процента выполнения работы.
SetColProgr(hwndProgr,COL_WHITE,COL_RED); // Установка цветов полосы прогресса.

SetTxtBtnRecSound(); // Установка текста в кнопку распознавания звука.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение минимального размера окна.

BYTE clMain::GetMinSizeWin(void)
{
if(hDlg==NULL) return 1; if(GetClientRect(hDlg,&rc)==FALSE) return 2;
dxMin=GetUSHRT_Test((int)(rc.right-rc.left)+GetSystemMetrics(SM_CXDLGFRAME)*2);
dyMin=GetUSHRT_Test((int)(rc.bottom-rc.top)+GetSystemMetrics(SM_CYDLGFRAME)*2+GetSystemMetrics(SM_CYCAPTION));
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка минимального размера окна.

void clMain::SetMinSize(LPMINMAXINFO lpMinMax)
{
BYTE SetMinSizeWin(HWND hwnd,LPMINMAXINFO lpMinMax,int dxm,int dym); // Установка минимального размера окна.

SetMinSizeWin(hwnd,lpMinMax,(int)dxMin,(int)dyMin);
}

//-----------------------------------------------------------------------------------------------------------
// Перемещение окна в нижний правый угол.

BYTE clMain::MoveWinCorner(void)
{
BYTE SizeMovWin(HWND hwnd,int shX,int shY,int dX,int dY,BYTE flChild); // Перемещение окна и изменение его размеров.

int dx,dy; POINT pt;

if(hwnd==NULL) return 1; if(GetWindowRect(GetDesktopWindow(),&rc)==FALSE) return 2;
pt.x=rc.right; pt.y=rc.bottom;
if(GetWindowRect(hwnd,&rc)==FALSE) return 3; 
dx=(int)(rc.right-rc.left);
dy=(int)(rc.bottom-rc.top);
if(dx<=0||dy<=0) return 4;
if(SizeMovWin(hwnd,(int)(pt.x-(long)dx-rc.left),(int)(pt.y-(long)dy-rc.top),0,0,0)!=0) return 5;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка очереди сообщений главного окна.

LRESULT clMain::MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
if(flag==NULL) return 0L; *flag=0; if(hwnd==NULL) return 0L; if(msg==WM_CREATE) return 0L;

switch(msg) { default: break;

// WM_ERASEBKGND ............................................................................................
case WM_ERASEBKGND: *flag=1; break;

// WM_SYSCOMMAND ............................................................................................
case WM_SYSCOMMAND: if(wParam==SC_CLOSE) { *flag=1; OnCloseWin();} break;

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
// Обработка очереди сообщений окна управления.

LRESULT clMain::MsgCommandCntrl(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
int id; HDC hdc;

if(flag==NULL) return 0L; *flag=0; if(hDlg==NULL) return 0L; if(msg==WM_INITDIALOG) return 0L;

switch(msg) { default: break;

// WM_CTLCOLORSTATIC ........................................................................................
case WM_CTLCOLORSTATIC: hdc=(HDC)wParam; id=GetDlgCtrlID((HWND)lParam); if(id<=0) break; *flag=1;
SetBkColor(hdc,GetSysColor(COLOR_WINDOW)); SetTextColor(hdc,GetSysColor(COLOR_BTNTEXT));
SetBkMode(hdc,TRANSPARENT); if(id==IDC_TEXT||id==IDC_WORD) return (LRESULT)hBrushBkg; return (LRESULT)hBrushDial;

// WM_RBUTTONDOWN ...........................................................................................
case WM_RBUTTONDOWN: *flag=1; SetFocus(hwnd); ShowMenu(lParam); break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: if(CommandCntrl(wParam)==0) *flag=1; break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Команды.

BYTE clMain::Command(WPARAM wParam)
{
INT_PTR CALLBACK DlgAbout(HWND,UINT,WPARAM,LPARAM); // Функция диалогового окна о программе.

BYTE flag; int wmId;

if(hwnd==NULL) return 1; flag=2; wmId=LOWORD(wParam);

switch(wmId) {

// IDM_SERVICE ..............................................................................................
case IDM_SERVICE: if(flCaptSound==0) StartCaptureSound(); else flStopCaptSound=1; break;

// IDM_DO_COMMANDS ..........................................................................................
case IDM_DO_COMMANDS: flDoCommands=1-flDoCommands; ChMenuDoCommands(); SetText(""); break;

// IDM_OUT_WORDS ............................................................................................
case IDM_OUT_WORDS: flOutWords=1-flOutWords; ChMenuOutWords(); SetText(""); break;

// IDM_WIN_TEXT .............................................................................................
case IDM_WIN_TEXT: OpenWinText(); break;

// IDM_ADJUST_SOUND .........................................................................................
case IDM_ADJUST_SOUND: DlgAdjSound(); break;

// IDM_HELP .................................................................................................
case IDM_HELP: if(Help!=NULL) Help->ShowContent(); break;

// IDM_ABOUT ................................................................................................
case IDM_ABOUT: DialogBox(hInst,(LPCTSTR)IDD_ABOUTBOX,hwnd,(DLGPROC)DlgAbout); break;

// IDM_EXIT .................................................................................................
case IDM_EXIT: OnCloseWin(); break;
}
return flag;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка команд окна управления.

BYTE clMain::CommandCntrl(WPARAM wParam)
{
int id;

if(hDlg==NULL) return 1; id=LOWORD(wParam);

switch(id) { default: return 2;

// IDC_ON_OFF ...............................................................................................
case IDC_ON_OFF: if(flCaptSound==0) StartCaptureSound(); else flStopCaptSound=1; break;
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование в окне.

void clMain::OnPaint(HDC hdc)
{
if(hdc==NULL) return;
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
// Обнуление указателя на объект класса библиотеки захвата звука.

void clMain::ZeroSndCap(void)
{
SndCap=NULL; TimeRecBuf=TimeRecProc=nRecChar=nRecText=0; cntShutDown=0; flCaptSound=0; flStopCaptSound=1;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление объекта класса библиотеки захвата звука.

void clMain::FreeSndCap(void)
{
SAFE_DELETE(SndCap);
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
end: if(ber!=0) FreeSndCap(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение при записи звука.

BYTE clMain::SaveBufSound(DWORD szBuf,void *pBuf)
{
UINT sz;

if(szBuf==0) return 1; if(pBuf==NULL) return 2; if(SndCapData==NULL) return 3; sz=szBuf/sizeof(SHRT);
if(SndCapData->AddCycle(sz,(SHRT *)pBuf)!=0) return 4;
TimeRecBuf+=sz; if(ProcRecRealTime()!=0) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Включение записи звука.

BYTE clMain::StartCaptureSound(void)
{
BYTE nChan,nbPS,ber;

if(SndCap==NULL) return 1; if(SndCap->Obj==NULL) return 2;
if(SndCapData==NULL) return 3; SndCapData->Free();

TimeRecBuf=TimeRecProc=nRecChar=nRecText=cntPause=0; cntShutDown=0;
if(SndCapData->CreateCycle(szSndCapDataCycle)!=0) return 4; // Выделение памяти для цикла хранения данных при распознавании звука.
SetText(""); SetWord(""); if(WinText.hwnd!=NULL) WinText.ClearWin();
if(AnSound.Init(ParSpectr.Time_Step,1)!=0) return 5; // Инициализация структуры для обработки потока символов звуков.
AnStream.Reset(); // Сброс счётчиков.
if(RecNNW.Alloc(nRecCharMax)!=0) return 6;
if(RecText.Alloc(nSzRecTextMax)!=0) return 7;

if(SndCap->StartCapture()!=0) return 8; // Запуск захвата звука.
ber=0;
SndCap->Obj->GetParSnd(&SndCapData->nSPS,&nChan,&nbPS);
if(nChan!=1) { ber=9; goto end;} if(nbPS!=16) { ber=10; goto end;}
if(szSndCapDataCycle*szNotifySndCap<SndCapData->nSPS*ParSpectr.Time_Width) { ber=11; goto end;}

flCaptSound=1; flStopCaptSound=0; ChBtnMenuCaptureSound();
while(1) { if(SndCap->Obj->CheckMessage()!=0) break;}

end: StopCaptureSound_(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Остановка записи звука.

void clMain::StopCaptureSound_(void)
{
flStopCaptSound=1; if(SndCap==NULL) return;
SndCap->StopCapture(); // Остановка захвата звука.
if(SndCapData!=NULL) SndCapData->Free(); // Освобождение памяти.
flCaptSound=0; ChBtnMenuCaptureSound();
}

//-----------------------------------------------------------------------------------------------------------
// Выделение пункта меню захвата звука и изменение кнопки.

void clMain::ChBtnMenuCaptureSound(void)
{
SetStMenuItem_(hMenu,IDM_SERVICE,1,flCaptSound); SetTxtBtnRecSound();
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопку распознавания звука.

void clMain::SetTxtBtnRecSound(void)
{
int id; char *cp;

if(hDlg==NULL) return; if(flCaptSound==0) id=IDS_Btn_Recogn; else id=IDS_Btn_Stop;
cp="-"; if(hInst!=NULL) { if(LoadString(hInst,id,TxtStr,strL_Txt)!=0) cp=TxtStr;}
SetDlgItemText(hDlg,IDC_ON_OFF,cp);
}

//-----------------------------------------------------------------------------------------------------------
// Настройка захвата звука.

BYTE clMain::DlgAdjSound(void)
{
BYTE flRet,ber; clDlgSndCap *DSC;

if(flCaptSound!=0) { SoundBlock(); return messRet;}
if(hwnd==NULL) return 1; if(SndCap==NULL) return 2; if(SndCap->Obj==NULL) return 3;
DSC=NULL; ber=0;
DSC=new clDlgSndCap(); if(DSC==NULL) { ber=4; goto end;}
if(DSC->Dialog(hwnd,SndCap->Obj,&flRet)!=0) { ber=5; goto end;}
end: SAFE_DELETE(DSC); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка и распознавание в реальном времени.

BYTE clMain::ProcRecRealTime(void)
{
BYTE GetN_(USHRT nPoints,USHRT *Np,USHRT NpM,BYTE *Mp); // Даёт минимальное число 'Np', являющееся 2 в целой степени, которое превышает 'nPoints'.
BYTE GetWeightWinSTFT(BYTE meth,float *Weight,USHRT nP,float Wid); // Нахождение весовой функции окна при спектральном разложении.
BYTE FastFT(complex *A,complex *B,BYTE M,SCHAR dir,BYTE prcMess); // Быстрое преобразование Фурье.
BYTE RecognSoundNNW_Sp(float *Spectr,USHRT nSpectr,float dFr,strNNW *pNNW,pFunDecSnd DecSnd,PNT_DATA Pnt,
  BYTE *numSnd); // Распознавание звуков методом нейронных сетей.
BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE *numSnd); // Функция принятия решения при распознавании звука - простейший пороговый классификатор, основанный на текущих значениях.
BYTE DecSnd_Store(PNT_DATA Pnt,strLay *pLay,BYTE *numSnd); // Функция принятия решения при распознавании звука - метод с накоплением результата распознавания.
BYTE GetSymbSound(BYTE num,char *pSymb); // Получение символа звука.

BYTE M,numSnd,flStart,ber; SHRT iv,*Sound; USHRT i,n,nWinWid,nPoints,nPh,nStep,nTI; UINT k,nTime,ui;
float v,*Weight,*Spectr,dFr; double dt,s; complex *A,*B; char Symb; pFunDecSnd pFunDecSnd;

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

// Нахождение интеграла по мощности для индикации амплитуды.
s=0.0F; for(n=0;n<nPh;n++) { v=Spectr[n]; s+=POW2D(v);} s/=(double)nPh; s=SQRT(s);
ShowProgr(s,(double)AmpNormSound); // Изображение полосы прогресса.

// Распознавание методом нейронных сетей.
if(methDecSound==methDecSnd_Inst) pFunDecSnd=DecSnd_Instant; else pFunDecSnd=DecSnd_Store; // Установка способа принятия решения по звуку.
numSnd=UCHAR_MAX;
if(RecognSoundNNW_Sp(Spectr,nPh,dFr,&NNW_Spectr,pFunDecSnd,(PNT_DATA)this,&numSnd)!=0) { ber=15; goto end;}
if(numSnd==UCHAR_MAX) Symb='-'; else { if(GetSymbSound(numSnd,&Symb)!=0) Symb='-';} // Получение символа звука.

if(nRecChar>=RecNNW.sz) { ber=16; goto end;}
RecNNW.String[nRecChar]=Symb; nRecChar++;
RecognTxtCommand(numSnd,Symb); // Распознавание текста и команд.
// Вывод текста в большое окно.
if(nRecChar==RecNNW.sz) { RecNNW.String[nRecChar]='\0'; nRecChar=0;
if(WinText.hwnd!=NULL) WinText.SetText(RecNNW.String);}
}
TimeRecProc+=(UINT)(nTime-1)*(UINT)nStep;

end: FreeComplex(&A); FreeComplex(&B); FreeSHRT(&Sound); FreeFloat(&Spectr); FreeFloat(&Weight); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Получение номера звука при распознавании потока речи.

BYTE clMain::GetNumSndRecogn(strLay *pLay,BYTE *numSnd)
{
BYTE GetOutArr(strLay *pLay,float *pArr,BYTE nArr); // Нахождение массива выходов нейронных элементов.

BYTE nArr,ber; float *pArr;

if(pLay==NULL) return 1; if(pLay->IsOK()!=0) return 2; if(numSnd==NULL) return 3;
nArr=nVoices; if((USHRT)nArr!=pLay->n) return 6;
pArr=NULL; ber=0;
pArr=new float[nArr]; if(pArr==NULL) { ber=7; goto end;}
if(GetOutArr(pLay,pArr,nArr)!=0) { ber=8; goto end;}
if(AnSound.Step(pArr,nArr,numSnd)!=0) { ber=9; goto end;}
end: SAFE_DELETE_ARR(pArr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Полоса прогресса.

void clMain::ShowProgr(double v,double vMax)
{
void ShowProgress(HWND hwndProgr,double v,double vMax); // Изображение процента по величине.

ShowProgress(hwndProgr,v,vMax); ProcMess();
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка нейронной сети.

BYTE clMain::LoadNNW(void)
{
if(NNW_Spectr.Read(PathToProgDir,nameNNW_Spectr,extNNW_Spectr)!=0) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка словаря.

BYTE clMain::LoadDict(void)
{
if(Dict.Read(PathToProgDir,nameDict,extDict)!=0) { Message(IDS_NoDict_Found,MB_IN); return 1;} // Чтение словаря из файла.
if(RecWords.Init(&Dict)!=0) return 2; // Инициализация структуры для распознавания слов.
return 0;
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
if(WinText.hwnd==NULL) WinText.CreateWin(); else WinText.CloseWin(); ChMenuWinText();
}

//-----------------------------------------------------------------------------------------------------------
// Изменение состояния кнопки и пункта меню открытия окна текста.

void clMain::ChMenuWinText(void)
{
BYTE Ch;

if(WinText.hwnd==NULL) Ch=0; else Ch=1; SetStMenuItem_(hMenu,IDM_WIN_TEXT,1,Ch);
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
// Распознавание текста и команд.

void clMain::RecognTxtCommand(BYTE numSnd,char Symb)
{
BYTE comm,flS,fl; UINT numWord; char *cp;

// Пауза при получении команд.
if(flDoCommands!=0) {
if(cntPause!=0) { flS=0; cntPause--; if(cntPause==0) { SetWord(""); if(cntShutDown!=0) cntShutDown--;}} else flS=1;}
else flS=1;

// Анализ потока символов.
if(AnStream.GetSymb(numSnd,flS)!=messRet) return;

// Распознавание слов.
fl=RecWords.Step(numSnd,&numWord);
if(fl==messRet) { cp=Dict.GetWord(numWord);
if(cp!=NULL) { if(flOutWords==0) SetWord(cp); else AddWordTextWin(cp);} return;}

// Вывод потока символов - добавление распознанного символа в окно.
if(flDoCommands==0&&flOutWords==0) { if(numSnd==UCHAR_MAX) return; AddSymbTextWin(Symb); return;}
if(flDoCommands==0) return; if(flS==0) return;

// Выполнение команд.
comm=UCHAR_MAX;
switch(numSnd) {
default: break;
case numSymbA: comm=commCloseWin; break; // 'А'.
case numSymbV: if(cntShutDown==0) comm=commShutDownQ; else comm=commShutDown; break; // 'В'.
case numSymbM: comm=commStopRec; break; // 'М'.
case numSymbU: comm=commShowHelp; break; // 'У'.
case numSymbE: comm=commOpenNotepad; break; // 'Э'.
case numSymbR: comm=commOpenPaint; break; // 'Р'.
case numSymbO: comm=commOpenWord; break; // 'О'.
case numSymbI: comm=commOpenIE; break; // 'И'.
}
if(comm==UCHAR_MAX) return; if(comm>=nCommands) return;
if(cntShutDown!=0&&comm!=commShutDown) return;

ShowCommand(comm); DoCommand(comm); // Отображение и подача команды.
if(ParSpectr.Time_Step<=0.0F) return;
cntPause=GetUINT_Test(TimePauseComm/ParSpectr.Time_Step); // Установка паузы до следующей команды.
}

//-----------------------------------------------------------------------------------------------------------
// Добавление распознанного символа в окно.

BYTE clMain::AddSymbTextWin(char Symb)
{
if(RecText.IsOK()!=0) return 1; if(nRecText>=RecText.sz) return 2;
RecText.String[nRecText]=Symb; nRecText++; RecText.String[nRecText]='\0'; SetText(RecText.String);
if(nRecText==RecText.sz) nRecText=0; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Добавление распознанного слова в окно.

BYTE clMain::AddWordTextWin(char *Str)
{
BYTE i; USHRT sz; size_t ln; char *cp;

if(RecText.IsOK()!=0) return 1; if(nRecText>=RecText.sz) return 2;
ln=strlen(Str); if(ln>UCHAR_MAX) return 3; sz=(USHRT)ln+1; if(sz>RecText.sz) return 4;
if(nRecText>RecText.sz-(UINT)sz) nRecText=0; cp=RecText.String+nRecText;
for(i=0;i<(BYTE)ln;i++) cp[i]=Str[i]; cp[ln]=' '; cp[ln+1]='\0'; SetText(RecText.String);
nRecText+=(UINT)sz; if(nRecText==RecText.sz) nRecText=0; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выполнение команд.

void clMain::DoCommand(BYTE comm)
{
HWND hwndV;

switch(comm) { default: return;
// Выключение компьютера - вопрос и подтверждение.
case commShutDown: case commShutDownQ:
if(cntShutDown!=0) { ExitWindowsEx(EWX_LOGOFF,0); cntShutDown=0;} else cntShutDown=3; break;
// Закрытие окна программы.
case commCloseWin: hwndV=GetForegroundWindow(); if(hwndV==hwnd) { SetString(IDS_CanNotCloseProg); break;}
if(hwndV!=NULL) SendMessage(hwndV,WM_CLOSE,0,0L); break;
// Остановка работы.
case commStopRec: flStopCaptSound=1; break;
// Показать справку по программе.
case commShowHelp: if(Help!=NULL) Help->ShowContent(); else Message(IDS_Err_NoHelpFile,MB_IN); break;
// Открыть блокнот.
case commOpenNotepad: OpenSysProg("notepad.exe"); break;
// Открыть редактор изображений.
case commOpenPaint: OpenSysProg("mspaint.exe"); break;
// Открыть 'WinWord'.
case commOpenWord: OpenProgFiles((char *)PathToMOffice,"winword.exe"); break;
// Открыть 'Internet Explorer'.
case commOpenIE: OpenProgFiles((char *)PathInternExpl,"iexplore.exe"); break;
}
}

//-----------------------------------------------------------------------------------------------------------
// Открытие системной программы.

BYTE clMain::OpenSysProg(char *NameProg)
{
BYTE Process(char *Path,char *Dir,char *Name,char *ComStr,char *CurrDir,BYTE show,BYTE wait); // Запуск другой программы.

BYTE ber; UINT ui; char *SysDir;

if(IsOKStr(NameProg)!=0) return 1;
SysDir=NULL; ber=0;
if(AllocString(&SysDir,(size_t)MAX_PATH)!=0) { ber=2; goto end;}
ui=GetSystemDirectory((LPTSTR)SysDir,(UINT)MAX_PATH); if(ui==0||ui>MAX_PATH) { ber=3; goto end;}
if(Process(SysDir,"\\",NameProg,NULL,NULL,1,0)!=0) { ber=3; goto end;}
end: FreeString(&SysDir); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Открытие программы из директории "Program Files".

BYTE clMain::OpenProgFiles(char *PathProg,char *NameProg)
{
BYTE Process(char *Path,char *Dir,char *Name,char *ComStr,char *CurrDir,BYTE show,BYTE wait); // Запуск другой программы.

BYTE ber; UINT ui; char *SysDir,*Path,*cp,*Items[2];

if(IsOKStr(NameProg)!=0) return 1;
Path=SysDir=NULL; ber=0;
if(AllocString(&SysDir,(size_t)MAX_PATH)!=0) { ber=2; goto end;}
ui=GetSystemDirectory((LPTSTR)SysDir,(UINT)MAX_PATH); if(ui==0||ui>MAX_PATH) { ber=3; goto end;}
cp=strchr(SysDir,':'); if(cp==NULL) { ber=4; goto end;} *(cp+1)='\0';
Items[0]=SysDir; Items[1]=(char *)PathToProgFiles;
if(GetString(&Path,Items,2)!=0) { ber=5; goto end;}
if(Process(Path,PathProg,NameProg,NULL,NULL,1,0)!=0) { ber=6; goto end;}
end: FreeString(&SysDir); FreeString(&Path); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Отображение команд в окне.

BYTE clMain::ShowCommand(BYTE comm)
{
if(comm>=nCommands) return 1; if(SetString(IDA_Commands[comm])!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка текста в окне.

void clMain::SetText(char *txt)
{
if(hDlg==NULL) return; if(txt==NULL) SetDlgItemText(hDlg,IDC_TEXT,"");
SetDlgItemText(hDlg,IDC_TEXT,txt);
}

//-----------------------------------------------------------------------------------------------------------
// Установка слова в окне.

void clMain::SetWord(char *txt)
{
if(hDlg==NULL) return; if(txt==NULL) SetDlgItemText(hDlg,IDC_WORD,"");
SetDlgItemText(hDlg,IDC_WORD,txt);
}

//-----------------------------------------------------------------------------------------------------------
// Установка строки в окне.

BYTE clMain::SetString(int idS)
{
char *cp;

if(idS<=0) return 1; if(hDlg==NULL) return 2; if(hInst==NULL) return 3;
if(LoadString(hInst,idS,TxtStr,strL_Txt)!=0) cp=TxtStr; else cp=""; SetWord(cp); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Изменение выделения пункта меню принятия команд.

void clMain::ChMenuDoCommands(void)
{
SetStMenuItem_(hMenu,IDM_DO_COMMANDS,1,flDoCommands);
}

//-----------------------------------------------------------------------------------------------------------
// Изменение выделения пункта меню вывода в окно распознанных слов.

void clMain::ChMenuOutWords(void)
{
SetStMenuItem_(hMenu,IDM_OUT_WORDS,1,flOutWords);
}

//-----------------------------------------------------------------------------------------------------------
// Действия при закрытии окна.

void clMain::OnCloseWin(void)
{
if(flCaptSound!=0) { Message(IDS_Mess_CanNotExit,MB_ST); return;} DestroyWindow(hwnd);
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

BYTE DecSnd_Store(PNT_DATA Pnt,strLay *pLay,BYTE *numSnd)
{
clMain *MW_;

MW_=(clMain *)Pnt; if(MW_==NULL) return 1; if(MW_->GetNumSndRecogn(pLay,numSnd)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Функция главного окна.

LRESULT CALLBACK WndProcMain(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE InitMain(HWND hwnd); // Инициализация класса главного окна.

BYTE flag;

if(msg!=WM_CREATE) { LRes=MW.MsgCommand(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}

switch(msg) {

default: return DefWindowProc(hwnd,msg,wParam,lParam);

// WM_CREATE ................................................................................................
case WM_CREATE: if(InitMain(hwnd)!=0) { PostMessage(hwnd,WM_CLOSE,0,0L); return 0L;} break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hwnd); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: PostQuitMessage(0); break;
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
HFONT GetFont(char *nameFont,SHRT Wid,SHRT Hei); // Загрузка шрифта.

FreeFont(); if(IsOKStr(NameFontWinTest)!=0) return 1;
hFontText=GetFont(NameFontWinTest,0,-HeiFontText); if(hFontText==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание окна.

BYTE clWinText::CreateWin(void)
{
BYTE IsOKRect(RECT *rc); // Проверка прямоугольника.

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
SetPosWindowCenter(hwnd); // Помещение окна в центр другого окна или экрана.

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
CloseEdt(); CloseWin(); MW.ChMenuWinText();
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
BYTE SetFont(HWND hwnd,HFONT hFont); // Программа для установки шрифта в окне.

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

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна о программе.

INT_PTR CALLBACK DlgAbout(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
void SetPosWindowCenter(HWND hDlg); // Помещение окна в центр другого окна или экрана.

switch (message)
{
// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG:	SetPosWindowCenter(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND:
if(LOWORD(wParam)==IDOK||LOWORD(wParam)==IDCANCEL) { EndDialog(hDlg,LOWORD(wParam)); return (INT_PTR)TRUE;}
break;
}
return (INT_PTR)FALSE;
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
