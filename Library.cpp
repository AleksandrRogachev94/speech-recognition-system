/*...........................................................................................................

// Выделение и освобождение памяти.
AllocString,FreeString,AllocPString,FreePString,AllocBYTE,FreeBYTE,AllocSHRT,FreeSHRT,AllocDWORD,FreeDWORD,
AllocFloat,FreeFloat,AllocDouble,FreeDouble,AllocComplex,FreeComplex,

// Рисование.
DrawLine_,
CrSelPen,CrSelPen_,UnSelDelPen,CrSelBrush,UnSelDelBrush,
DrawRect_,ImgRectC,ImgWinC,DrawTri,

// Работа со строками.
IsOKStr,StrCopy,StrCat,GetString,CompareStr_,CompareStr,CompareStrCase,ReadString,DupString,StrSybmConv,
LoadString_,LoadDupString,GetFilter,FindNumFilter,GetNumExtFilter,GetListExtFilter,CheckExtListFilt,GetExtPnt,
ChangeChar,

// Работа с окнами.
ShowWin,UpdateWindow_,CloseWin_,DestroyWin_,SizeMovWin,EnableChWin,ShowChWin,CloseChWin,SetPosWindowCenter,
SetPosWindowCenter_,SetPosWindow,GetDlgWinRect,SetMinSizeWin,CheckWindowSize,GetSizeDlg,DlgProcVoid,

// Работа со шрифтами.
GetFont,SetFont,

// Работа с меню.
SetStMenuItem_,

// Работа с окнами редактирования.
SetByteEdt,GetByteEdt,SetUSHRT_Edt,GetUSHRT_Edt,SetUINT_Edt,GetUINT_Edt,SetFlEdt,GetFlEdt,

// Работа с окном флага.
SetChBox,GetChBox,

// Работа со списками.
ClearList,

// Работа с комбинированными списками.
SetSizeCombo,SetSelCombo,GetSelCombo,FillStrCombo,

// Работа с полосой прокрутки.
ScrollFun,ScrollFunS,ScrollFun32,SetRangePageScrollBar,

// Работа с полосой процента выполненной работы.
InitProgress,SetColProgr,ShowProgress,

// Работа с файлами и директориями.
IsFileDirExists,IsFileExist,IsFileExist_,GetName,
OpenHandleFile_,CloseHandleFile_,ReadFile_,WriteFile_,SeekFile,SizeOfFile,
FileNameQuest,CheckCreateDir,Process,

// Работа с библиотеками *.dll.
LoadLib,

// Работа со звуком.
PlayWave_,PlayWave,

// Работа с изображениями.
DrawBitmap,CreateHeaderBMP,CreateInfoBMP,DeleteInfoBMP,SetColArrRGBQuad,GetColArrRGBQuad,GetColComp,SetBitBmp16,
InitImgBitmap,GetSzBmp,GetBitPerPix,GetTypBMP,GetLSizeBMP,GetRelPosH,GetRelPosV,
ReadDIB_FN,ReadDIB_FH,WriteDIB_FN,WriteDIB_FH,

// Разное.
SetBit,IsOKRect,ProcMess,SoundBlock,IsColLight,GetRandNum,RandomizeArr,AttemptJump,

// Получение целых чисел из других типов.
GetBYTE,GetSHRT_Test,GetUSHRT_Test,GetUSHRT_Test,GetUSHRT_Test,GetIntTest,GetIntTest,GetUINT_Test,GetUINT_Test,

// Сообщения.
ErrMessage,Message,Message_,

// Отдельные сообщения.
MessQuestFileOverWrite

...........................................................................................................*/

#include "stdafx.h"

#include "Project_con.h"
#include "cmplx.h"
#include "resource.h"

#pragma comment(lib, "winmm.lib")

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Программы.

BYTE AllocString(char **Str,size_t ln); // Выделение памяти для строки.
void FreeString(char **Str); // Освобождение памяти для строки.
BYTE AllocPString(char ***pStr,BYTE n); // Выделение памяти для массива указателей на char.
void FreePString(char ***pStr); // Освобождение памяти для массива указателей на char.
BYTE AllocDWORD(DWORD **dwpp,size_t ln); // Выделение памяти для массива 'DWORD'.
void FreeDWORD(DWORD **dwpp); // Освобождение памяти для массива 'DWORD'.
BYTE CrSelPen(HDC hdc,HPEN *hPen,HPEN *hPenP,BYTE Wid,DWORD Col); // Создание и выбор пера.
void UnSelDelPen(HDC hdc,HPEN *hPen,HPEN *hPenP); // Освобождение и удаление пера.
BYTE CrSelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP,DWORD Col); // Создание и выбор кисти.
void UnSelDelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP); // Освобождение и удаление кисти.
void ImgRectC(HDC hdc,RECT *rc,DWORD ColP,DWORD ColB,BYTE Wid); // Закрашивание прямоугольника.
BYTE IsOKStr(char *str); // Проверка строки.
BYTE StrCopy(char *Dst,size_t lnDst,char *Src); // Копирование строк.
BYTE StrCat(char *Dst,size_t lnDst,char *Src); // Объединение строк.
BYTE GetString(char **String,char **Items,BYTE n); // Сборка строки из нескольких строк.
BYTE IsOKRect(RECT *rc); // Проверка прямоугольника.
SHRT GetSHRT_Test(float v); // Получение числа 'SHRT' из числа 'float' с проверкой выхода за пределы 'SHRT'.
USHRT GetUSHRT_Test(int iv); // Получение числа 'USHRT' из числа 'int' с проверкой выхода за пределы 'USHRT'.
int GetIntTest(float v); // Получение числа 'int' из числа 'float' с проверкой выхода за пределы 'int'.
void ErrMessage(void); // Выдача сообщения об ошибке.
void ProcMess(void); // Опрос очереди сообщений и обработка сообщений.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные переменные.

extern HINSTANCE hInst; // Идентификатор приложения.
extern LRESULT LRes; // Вспомогательная переменная.

extern HCURSOR cur_wait; // Курсоры общего назначения.

extern DWORD ColDial; // Цвет фона или диалогового окна.

extern char TxtStr[strL_Txt],TxtMem[strL_Txt]; // Вспомогательные строки.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Выделение и освобождение памяти.

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для строки.

BYTE AllocString(char **Str,size_t ln)
{
void FreeString(char **Str); // Освобождение памяти для строки.

if(Str==NULL) return 1; FreeString(Str);
*Str=new char[ln+1]; if(*Str==NULL) return messNoMem; *(*Str+ln)='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для строки.

void FreeString(char **Str)
{
if(Str==NULL) return; SAFE_DELETE_ARR(*Str);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива указателей на char.

BYTE AllocPString(char ***pStr,BYTE n)
{
void FreePString(char ***pStr); // Освобождение памяти для массива указателей на char.

BYTE i;

if(pStr==NULL) return 1; if(n==0) return 2; FreePString(pStr);
*pStr=new typPntChar[n]; if(*pStr==NULL) return messNoMem;
for(i=0;i<n;i++) (*pStr)[i]=NULL; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для массива указателей на char.

void FreePString(char ***pStr)
{
if(pStr==NULL) return; SAFE_DELETE_ARR(*pStr);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива 'BYTE'.

BYTE AllocBYTE(BYTE **bpp,size_t ln)
{
void FreeBYTE(BYTE **bpp); // Освобождение памяти для массива 'BYTE'.

if(bpp==NULL) return 1; if(ln==0) return 2; FreeBYTE(bpp);
*bpp=new BYTE[ln]; if(*bpp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для массива 'BYTE'.

void FreeBYTE(BYTE **bpp)
{
if(bpp==NULL) return; SAFE_DELETE_ARR(*bpp);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива 'SHRT'.

BYTE AllocSHRT(SHRT **shipp,size_t ln)
{
void FreeSHRT(SHRT **shipp); // Освобождение памяти для массива 'SHRT'.

if(shipp==NULL) return 1; if(ln==0) return 2; FreeSHRT(shipp);
*shipp=new SHRT[ln]; if(*shipp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для массива 'SHRT'.

void FreeSHRT(SHRT **shipp)
{
if(shipp==NULL) return; SAFE_DELETE_ARR(*shipp);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива 'DWORD'.

BYTE AllocDWORD(DWORD **dwpp,size_t ln)
{
void FreeDWORD(DWORD **dwpp); // Освобождение памяти для массива 'DWORD'.

if(dwpp==NULL) return 1; if(ln==0) return 2; FreeDWORD(dwpp);
*dwpp=new DWORD[ln]; if(*dwpp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для массива 'DWORD'.

void FreeDWORD(DWORD **dwpp)
{
if(dwpp==NULL) return; SAFE_DELETE_ARR(*dwpp);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива 'float'.

BYTE AllocFloat(float **fpp,size_t ln)
{
void FreeFloat(float **fpp); // Освобождение памяти для массива 'float'.

if(fpp==NULL) return 1; if(ln==0) return 2; FreeFloat(fpp);
*fpp=new float[ln]; if(*fpp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для массива 'float'.

void FreeFloat(float **fpp)
{
if(fpp==NULL) return; SAFE_DELETE_ARR(*fpp);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива 'double'.

BYTE AllocDouble(double **dpp,size_t ln)
{
void FreeDouble(double **dpp); // Освобождение памяти для массива 'double'.

if(dpp==NULL) return 1; if(ln==0) return 2; FreeDouble(dpp);
*dpp=new double[ln]; if(*dpp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для массива 'double'.

void FreeDouble(double **dpp)
{
if(dpp==NULL) return; SAFE_DELETE_ARR(*dpp);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива 'complex'.

BYTE AllocComplex(complex **cpp,size_t ln)
{
void FreeComplex(complex **cpp); // Освобождение памяти для массива 'complex'.

if(cpp==NULL) return 1; if(ln==0) return 2; FreeComplex(cpp);
*cpp=new complex[ln]; if(*cpp==NULL) return messNoMem; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для массива 'complex'.

void FreeComplex(complex **cpp)
{
if(cpp==NULL) return; SAFE_DELETE_ARR(*cpp);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Рисование.

//-----------------------------------------------------------------------------------------------------------
// Рисование линии.

void DrawLine_(HDC hdc,int xI,int yI,int xF,int yF)
{
if(hdc==NULL) return; MoveToEx(hdc,xI,yI,NULL); LineTo(hdc,xF,yF);
}

//-----------------------------------------------------------------------------------------------------------
// Создание и выбор пера.

BYTE CrSelPen(HDC hdc,HPEN *hPen,HPEN *hPenP,BYTE Wid,DWORD Col)
{
BYTE CrSelPen_(HDC hdc,HPEN *hPen,HPEN *hPenP,int penStyle,BYTE Wid,DWORD Col); // Создание и выбор пера.

return CrSelPen_(hdc,hPen,hPenP,PS_SOLID,Wid,Col);
}

//-----------------------------------------------------------------------------------------------------------
// Создание и выбор пера.

BYTE CrSelPen_(HDC hdc,HPEN *hPen,HPEN *hPenP,int penStyle,BYTE Wid,DWORD Col)
{
BYTE fl;

if(hdc==NULL) return 1;
if(hPen==NULL) return 2; if(*hPen!=NULL) return 3;
if(hPenP==NULL) return 4; if(*hPenP!=NULL) return 5;
if(Wid==0) fl=1; else {
*hPen=CreatePen(penStyle,(int)Wid,(COLORREF)Col);
if(*hPen!=NULL) { fl=0; *hPenP=(HPEN)SelectObject(hdc,*hPen);} else fl=2;}
if(fl!=0) *hPenP=(HPEN)SelectObject(hdc,GetStockObject(NULL_PEN));
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение и удаление пера.

void UnSelDelPen(HDC hdc,HPEN *hPen,HPEN *hPenP)
{
if(hPenP!=NULL) { if(*hPenP!=NULL&&hdc!=NULL) SelectObject(hdc,*hPenP); *hPenP=NULL;}
if(hPen!=NULL) SAFE_DELETE_OBJECT(*hPen);
}

//-----------------------------------------------------------------------------------------------------------
// Создание и выбор кисти.

BYTE CrSelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP,DWORD Col)
{
if(hdc==NULL) return 1;
if(hBrush==NULL) return 2; if(*hBrush!=NULL) return 3;
if(hBrushP==NULL) return 4; if(*hBrushP!=NULL) return 5;
*hBrush=CreateSolidBrush((COLORREF)Col);
if(*hBrush!=NULL) *hBrushP=(HBRUSH)SelectObject(hdc,*hBrush);
else *hBrushP=(HBRUSH)SelectObject(hdc,GetStockObject(NULL_BRUSH));
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение и удаление кисти.

void UnSelDelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP)
{
if(hBrushP!=NULL) { if(*hBrushP!=NULL&&hdc!=NULL) SelectObject(hdc,*hBrushP); *hBrushP=NULL;}
if(hBrush!=NULL) SAFE_DELETE_OBJECT(*hBrush);
}

//-----------------------------------------------------------------------------------------------------------
// Рисование прямоугольника.

BYTE DrawRect_(HDC hdc,RECT *rc)
{
if(hdc==NULL) return 1; if(rc==NULL) return 2;
if(Rectangle(hdc,(int)rc->left,(int)rc->top,(int)rc->right,(int)rc->bottom)==FALSE) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Закрашивание прямоугольника.

void ImgRectC(HDC hdc,RECT *rc,DWORD ColP,DWORD ColB,BYTE Wid)
{
HBRUSH hBrush,hBrushP; HPEN hPen,hPenP;

if(hdc==NULL||rc==NULL) return;
hBrush=hBrushP=NULL; hPen=hPenP=NULL;
CrSelBrush(hdc,&hBrush,&hBrushP,ColB);
CrSelPen(hdc,&hPen,&hPenP,Wid,ColP);
DrawRect_(hdc,rc);
UnSelDelBrush(hdc,&hBrush,&hBrushP);
UnSelDelPen(hdc,&hPen,&hPenP);
}

//-----------------------------------------------------------------------------------------------------------
// Закрашивание окна.

void ImgWinC(HWND hwnd,DWORD ColP,DWORD ColB)
{
void ImgRectC(HDC hdc,RECT *rc,DWORD ColP,DWORD ColB,BYTE Wid); // Закрашивание прямоугольника.

HDC hdc; RECT rc; PAINTSTRUCT ps;

if(hwnd==NULL) return;
hdc=BeginPaint(hwnd,&ps); if(hdc==NULL) goto end; if(GetClientRect(hwnd,&rc)==FALSE) goto end;
SetMapMode(hdc,MM_TEXT); SetROP2(hdc,R2_COPYPEN); SetBkMode(hdc,TRANSPARENT);
ImgRectC(hdc,&rc,ColP,ColB,1);
end: EndPaint(hwnd,&ps);
}

//-----------------------------------------------------------------------------------------------------------
// Рисование треугольника.

BYTE DrawTri(HDC hdc,RECT *rc,BYTE ax,BYTE dir)
{
BYTE ber; long l; POINT *pP;

if(hdc==NULL) return 1; if(rc==NULL) return 2;
pP=NULL; ber=0;
pP=new POINT[3]; if(pP==NULL) { ber=3; goto end;}
if(ax==0) {
if(dir==0) l=rc->left; else l=rc->right; pP->x=l; pP->y=(rc->top+rc->bottom)/2;
if(dir==0) l=rc->right; else l=rc->left; (pP+1)->x=(pP+2)->x=l; (pP+1)->y=rc->top; (pP+2)->y=rc->bottom;}
else {
if(dir==0) l=rc->top; else l=rc->bottom; pP->y=l; pP->x=(rc->left+rc->right)/2;
if(dir==0) l=rc->bottom; else l=rc->top; (pP+1)->y=(pP+2)->y=l; (pP+1)->x=rc->left; (pP+2)->x=rc->right;}
if(Polygon(hdc,pP,3)==FALSE) { ber=4; goto end;}
end: SAFE_DELETE_ARR(pP); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа со строками.

//-----------------------------------------------------------------------------------------------------------
// Проверка строки.

BYTE IsOKStr(char *str)
{
if(str==NULL) return 1; if(strlen(str)==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Копирование строк.

BYTE StrCopy(char *Dst,size_t lnDst,char *Src)
{
size_t i,lnS;

if(Dst==NULL) return 1; if(lnDst==0) return 2; if(Src==NULL) return 3; lnS=strlen(Src); if(lnS>=lnDst) return 4;
if(lnS>0) for(i=0;i<lnS;i++) Dst[i]=Src[i]; Dst[lnS]='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Объединение строк.

BYTE StrCat(char *Dst,size_t lnDst,char *Src)
{
size_t i,lnD,lnS;

if(Dst==NULL) return 1; if(lnDst==0) return 2; if(Src==NULL) return 0;
lnS=strlen(Src); if(lnS==0) return 0; lnD=strlen(Dst); if(lnS+lnD>=lnDst) return 3;
for(i=0;i<lnS;i++) Dst[i+lnD]=Src[i]; Dst[lnS+lnD]='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сборка строки из нескольких строк.

BYTE GetString(char **String,char **Items,BYTE n)
{
BYTE i; size_t ln,lns;

if(String==NULL) return 1; if(Items==NULL) return 2; if(n==0) return 3; lns=0;
for(i=0;i<n;i++) { if(Items[i]==NULL) continue; ln=strlen(Items[i]); if(szMemMax-ln<lns) return 4; lns+=ln;}
if(AllocString(String,lns)!=0) return 5; lns++; if(StrCopy(*String,lns,"")!=0) return 6;
for(i=0;i<n;i++) { if(Items[i]==NULL) continue; if(StrCat(*String,lns,Items[i])!=0) return 7;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сравнение строк (с учётом длины строк и типа букв и различения прописных и строчных букв).

BYTE CompareStr_(char *strA,char *strB,BYTE flCase)
{
BYTE CompareStr(char *strA,char *strB); // Сравнение строк (с учётом длины строк и типа букв).
BYTE CompareStrCase(char *strA,char *strB); // Сравнение строк (с учётом длины строк и типа букв) без различения прописных и строчных букв.

if(flCase==0) return CompareStrCase(strA,strB); else return CompareStr(strA,strB);
}

//-----------------------------------------------------------------------------------------------------------
// Сравнение строк (с учётом длины строк и типа букв).

BYTE CompareStr(char *strA,char *strB)
{
size_t ln;

if(strA==NULL) return 1; ln=strlen(strA); if(ln==0) return 2;
if(strB==NULL) return 3; if(strlen(strB)!=ln) return 4; if(strcmp(strA,strB)==0) return 0; return 5;
}

//-----------------------------------------------------------------------------------------------------------
// Сравнение строк (с учётом длины строк и типа букв) без различения прописных и строчных букв.

BYTE CompareStrCase(char *strA,char *strB)
{
size_t ln;

if(strA==NULL) return 1; ln=strlen(strA); if(ln==0) return 2;
if(strB==NULL) return 3; if(strlen(strB)!=ln) return 4; if(_stricmp(strA,strB)==0) return 0; return 5;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение строки из текстового файла.

BYTE ReadString(FILE *file,char *str,size_t strLen)
{
int e; size_t i; char c;

if(str==NULL) return 1; if(strLen==0) return 2; if(file==NULL) { *str='\0'; return 3;}
i=0; c=0; e=0;
while(TRUE) { e=fscanf(file,"%c",&c); if(e==EOF) break; if(c==' '&&i==0) continue; if(c=='\n'||c=='\r') break;
if(i<strLen-1) { *(str+i)=c; i++;}} *(str+i)='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для строки и копирование.

BYTE DupString(char **Str,char *Src)
{
size_t ln;

if(Str==NULL) return 1; FreeString(Str); if(Src==NULL) return 2; ln=strlen(Src); if(ln==0) return 3;
if(AllocString(Str,ln)!=0) return 4; strcpy(*Str,Src); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Преобразование символов строки в верхние или нижние символы.

BYTE StrSybmConv(char *StrI,char *StrC,size_t szStrC,BYTE flag)
{
char sh,*c,*cC; SCHAR s; size_t i,sz;

if(StrI==NULL) return 1; sz=strlen(StrI); if(sz==0) return 2; if(StrC==NULL) return 3;
if(szStrC==0) return 4; if(sz+1>szStrC) return 5;
sh='A'-'a';
for(i=0;i<sz;i++) { c=StrI+i; cC=StrC+i; s=0;
if(flag!=0) { if(*c>='a'&&*c<='z') s=1;} else { if(*c>='A'&&*c<='Z') s=-1;}
*cC=*c; if(s!=0) *cC=char((SHRT)*cC+(SHRT)sh*(SHRT)s);}
StrC[sz]='\0'; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка строки из ресурсов.

BYTE LoadString_(UINT StrID,char *String,USHRT szString)
{
if(hInst==NULL) return 1; if(String==NULL) return 2; if(szString==0) return 3;
if(LoadString(hInst,StrID,String,szString)==0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка строки из ресурсов.

BYTE LoadDupString(char **Str,UINT StrID,char *Def)
{
char *cp;

if(Str==NULL) return 1; if(hInst==NULL) return 2; FreeString(Str);
if(LoadString(hInst,StrID,TxtStr,strL_Txt)!=0) cp=TxtStr; else if(Def==NULL) return 3; else cp=Def;
if(DupString(Str,cp)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Замена символа - разделителя на ноль в строке с фильтром для открытия файлов.

BYTE GetFilter(char *Filter)
{
BYTE ChangeChar(char *String,size_t ln,char cI,char cF); // Замена символа в строке.

if(Filter==NULL) return 1; if(ChangeChar(Filter,strlen(Filter),CH_FILT,'\0')!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение номера типа файла по строке фильтра и строке расширения.

BYTE FindNumFilter(char *Filter,char *Ext,BYTE *num,BYTE flCase)
{
BYTE GetNumExtFilter(char *Filter,BYTE *nExt); // Нахождение числа типов файлов в строке фильтра.
BYTE GetListExtFilter(char *Filter,char **FiltBuf,BYTE *NumInd,char **StrExt,BYTE nExt); // Нахождение списка строк с расширениями для типов файлов в строке фильтра.

BYTE i,j,nExt,*NumInd,ber; char **ExtArr,*FiltBuf;

if(IsOKStr(Filter)!=0) return 1; if(IsOKStr(Ext)!=0) return 2; if(num==NULL) return 3;
if(GetNumExtFilter(Filter,&nExt)!=0) return 4; // Нахождение числа типов файлов в строке фильтра.

ExtArr=NULL; NumInd=NULL; FiltBuf=NULL; ber=0;
if(AllocPString(&ExtArr,nExt)!=0) { ber=5; goto end;} // Выделение памяти для массива указателей на char.
if(AllocBYTE(&NumInd,(size_t)nExt)!=0) { ber=6; goto end;} // Выделение памяти для массива индексов.
if(GetListExtFilter(Filter,&FiltBuf,NumInd,ExtArr,nExt)!=0) { ber=7; goto end;} // Нахождение списка строк с расширениями для типов файлов в строке фильтра.

j=UCHAR_MAX; for(i=0;i<nExt;i++) if(CompareStr_(Ext,ExtArr[i],flCase)==0) { j=i; *num=NumInd[i]; goto end;}
if(j==UCHAR_MAX) { ber=messRet; goto end;}

end: FreePString(&ExtArr); FreeString(&FiltBuf); FreeBYTE(&NumInd); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение числа типов файлов в строке фильтра.

BYTE GetNumExtFilter(char *Filter,BYTE *nExt)
{
USHRT k; size_t i; char *cp;

if(IsOKStr(Filter)!=0) return 1; if(nExt==NULL) return 2; i=0; k=0;
rep:
while(TRUE) { cp=Filter+i; if(*cp==CH_FILT) break; i++;}
i++; cp=Filter+i; if(*cp=='\0') return 3; if(*cp==CH_FILT) return 4;
while(TRUE) { cp=Filter+i; if(*cp==CH_FILT) break; if(*cp=='*') { k++; if(k>=UCHAR_MAX) return 5;} i++;}
i++; cp=Filter+i; if(*cp=='\0') goto end; goto rep;
end: *nExt=(BYTE)k; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение списка строк с расширениями для типов файлов в строке фильтра.

BYTE GetListExtFilter(char *Filter,char **FiltBuf,BYTE *NumInd,char **StrExt,BYTE nExt)
{
BYTE ChangeChar(char *String,size_t ln,char cI,char cF); // Замена символа в строке.

BYTE ind; USHRT k; size_t i,ln; char *cp;

if(Filter==NULL) return 1; ln=strlen(Filter); if(ln==0) return 2; if(FiltBuf==NULL) return 3;
if(NumInd==NULL) return 4; if(StrExt==NULL) return 5; if(nExt==0) return 6;
if(DupString(FiltBuf,Filter)!=0) return 7;
if(ChangeChar(*FiltBuf,ln,';','\0')!=0) return 8;
if(ChangeChar(*FiltBuf,ln,CH_FILT,'\0')!=0) return 9;
i=0; k=0; ind=0;
rep:
while(TRUE) { cp=Filter+i; if(*cp==CH_FILT) break; i++;}
i++; cp=Filter+i; if(*cp=='\0') return 10; if(*cp==CH_FILT) return 11;
if(ind==UCHAR_MAX) return 12;
while(TRUE) { cp=Filter+i; if(*cp==CH_FILT) break;
if(*cp=='*') { if(k>=nExt) return 13; StrExt[k]=*FiltBuf+i+1; NumInd[k]=ind; k++;} i++;}
i++; cp=Filter+i; if(*cp=='\0') goto end; ind++; goto rep;
end: if((BYTE)k!=nExt) return 14; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки соответствия строки расширения файла списку расширений в строке фильтра.

BYTE CheckExtListFilt(char *Str,char *Filter,BYTE nIndex,BYTE flCase,BYTE *flag)
{
BYTE GetNumExtFilter(char *Filter,BYTE *nExt); // Нахождение числа типов файлов в строке фильтра.
BYTE GetListExtFilter(char *Filter,char **FiltBuf,BYTE *NumInd,char **StrExt,BYTE nExt); // Нахождение списка строк с расширениями для типов файлов в строке фильтра.
BYTE CompareStr_(char *strA,char *strB,BYTE flCase); // Сравнение строк (с учётом длины строк и типа букв и различения прописных и строчных букв).

BYTE i,n,nExt,flAny,*NumInd,ber; char **ExtArr,*FiltBuf;

if(flag==NULL) return 1; *flag=flFiltStr_Error; if(Filter==NULL) return 2;
if(GetNumExtFilter(Filter,&nExt)!=0) return 3; // Нахождение числа типов файлов в строке фильтра.

ExtArr=NULL; NumInd=NULL; FiltBuf=NULL; ber=0;
if(AllocPString(&ExtArr,nExt)!=0) { ber=4; goto end;} // Выделение памяти для массива указателей на char.
if(AllocBYTE(&NumInd,(size_t)nExt)!=0) { ber=5; goto end;} // Выделение памяти для массива индексов.
if(GetListExtFilter(Filter,&FiltBuf,NumInd,ExtArr,nExt)!=0) { ber=6; goto end;} // Нахождение списка строк с расширениями для типов файлов в строке фильтра.

flAny=0; for(i=0;i<nExt;i++) if(CompareStr(ExtArr[i],".*")==0) { flAny=1; break;}
if(IsOKStr(Str)!=0) { if(flAny!=0) { *flag=flFiltStr_Any; goto end;} ber=7; goto end;}

for(i=0;i<nExt;i++) { if(nIndex!=NumInd[i]) continue;
if(CompareStr_(ExtArr[i],Str,flCase)==0) { *flag=flFiltStr_Exact; goto end;}}

n=nExt; for(i=0;i<nExt;i++) { if(NumInd[i]==nIndex) continue;
if(CompareStr_(ExtArr[i],Str,flCase)==0) { n=i; break;}}
if(n==nExt) { if(flAny==0) *flag=flFiltStr_NotFound; else *flag=flFiltStr_Any;} else *flag=flFiltStr_List;

end: FreePString(&ExtArr); FreeString(&FiltBuf); FreeBYTE(&NumInd); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Получение расширения с точкой.

BYTE GetExtPnt(char **ExtPnt,char *Ext)
{
size_t ln; char *cp;

if(ExtPnt==NULL) return 1; if(IsOKStr(Ext)!=0) return 2;
cp=strchr(Ext,'.'); if(cp!=NULL) cp++; else cp=Ext; ln=strlen(cp); if(ln==0) return 3;
if(AllocString(ExtPnt,(size_t)ln+1)!=0) return 4;
strcpy(*ExtPnt,"."); strcat(*ExtPnt,cp); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Замена символа в строке.

BYTE ChangeChar(char *String,size_t ln,char cI,char cF)
{
size_t i; char *cp;

if(String==NULL) return 1; if(ln==0) return 2; for(i=0;i<ln;i++) { cp=String+i; if(*cp==cI) *cp=cF;} return 0; 
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с окнами.

//-----------------------------------------------------------------------------------------------------------
// Отображение или скрытие окна.

void ShowWin(HWND hwnd,BYTE flVis)
{
if(hwnd==NULL) return; if(flVis!=0) { ShowWindow(hwnd,SW_SHOWNORMAL); UpdateWindow(hwnd);} else ShowWindow(hwnd,SW_HIDE);
}

//-----------------------------------------------------------------------------------------------------------
// Обновление окна.

void UpdateWindow_(HWND hwnd)
{
if(hwnd==NULL) return; InvalidateRect(hwnd,NULL,FALSE); UpdateWindow(hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие окна.

void CloseWin_(HWND *hwnd)
{
if(hwnd==NULL) return; if(*hwnd==NULL) return; SendMessage(*hwnd,WM_CLOSE,0,0L); *hwnd=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Уничтожение окна с обнулением 'hwnd'.

void DestroyWin_(HWND *hwnd)
{
if(hwnd==NULL) return; if(*hwnd==NULL) return; DestroyWindow(*hwnd); *hwnd=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Перемещение окна и изменение его размеров.

BYTE SizeMovWin(HWND hwnd,int shX,int shY,int dX,int dY,BYTE flChild)
{
int dx,dy; RECT rc; POINT pt; HWND hwndP;

if(hwnd==NULL) return 1; if(flChild!=0) { hwndP=GetParent(hwnd); if(hwndP==NULL) return 2;}
if(GetWindowRect(hwnd,&rc)==FALSE) return 3; 
pt.x=rc.left; pt.y=rc.top; if(flChild!=0) { if(ScreenToClient(hwndP,&pt)==FALSE) return 4;}
if(dX>0) dx=dX; else dx=(int)(rc.right-rc.left);
if(dY>0) dy=dY; else dy=(int)(rc.bottom-rc.top);
if(MoveWindow(hwnd,(int)pt.x+shX,(int)pt.y+shY,dx,dy,TRUE)==FALSE) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Ввод и снятие блокировки дочернего окна.

void EnableChWin(HWND hDlg,int id,BYTE flag)
{
BOOL b; HWND hwnd;

if(hDlg==NULL||id<=0) return; hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return;
if(flag!=0) b=TRUE; else b=FALSE; EnableWindow(hwnd,b);
}

//-----------------------------------------------------------------------------------------------------------
// Показ или скрытие дочернего окна.

void ShowChWin(HWND hDlg,int id,BYTE flVis)
{
void ShowWin(HWND hwnd,BYTE flVis); // Отображение или скрытие окна.

if(hDlg==NULL||id<=0) return; ShowWin(GetDlgItem(hDlg,id),flVis);
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие дочернего окна.

void CloseChWin(HWND hDlg,int id)
{
HWND hwnd;

if(hDlg==NULL||id<=0) return; hwnd=GetDlgItem(hDlg,id); if(hwnd!=NULL) SendMessage(hwnd,WM_CLOSE,0,0L);
}

//-----------------------------------------------------------------------------------------------------------
// Помещение окна в центр другого окна или экрана.

void SetPosWindowCenter(HWND hDlg)
{
BYTE SetPosWindowCenter_(HWND hDlg,HWND hwnd); // Помещение окна 'hDlg' в центр окна 'hwnd'.

HWND hwnd;

if(hDlg==NULL) return; hwnd=GetWindow(hDlg,GW_OWNER); if(hwnd==NULL) hwnd=GetDesktopWindow();
SetPosWindowCenter_(hDlg,hwnd);
}

//-----------------------------------------------------------------------------------------------------------
// Помещение окна 'hDlg' в центр окна 'hwnd'.

BYTE SetPosWindowCenter_(HWND hDlg,HWND hwnd)
{
long d,dW,xi,yi,*lp; RECT rc,rcW,rcD;

if(hDlg==NULL) return 1; if(hwnd==NULL) return 2;
if(GetWindowRect(hDlg,&rcW)==FALSE) return 3;
if(GetWindowRect(hwnd,&rc)==FALSE) return 4;
if(GetWindowRect(GetDesktopWindow(),&rcD)==FALSE) return 5;
lp=&xi; dW=rcW.right-rcW.left; d=rc.right-rc.left; *lp=(d-dW)/2; *lp+=rc.left;
d=rcD.right-rcD.left; if(d>dW) { if(*lp<0) *lp=0; else if(*lp+dW>d) *lp=d-dW;}
lp=&yi; dW=rcW.bottom-rcW.top; d=rc.bottom-rc.top; *lp=(d-dW)/2; *lp+=rc.top;
d=rcD.bottom-rcD.top; if(d>dW) { if(*lp<0) *lp=0; else if(*lp+dW>d) *lp=d-dW;}
if(SetWindowPos(hDlg,NULL,(int)xi,(int)yi,0,0,SWP_NOZORDER|SWP_NOSIZE)==FALSE) return 6; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка расположения окна.

BYTE SetPosWindow(HWND hwnd,RECT *rc)
{
int dx,dy;

if(hwnd==NULL) return 1; if(rc==NULL) return 2;
dx=(int)(rc->right-rc->left);
dy=(int)(rc->bottom-rc->top);
if(MoveWindow(hwnd,(int)rc->left,(int)rc->top,dx,dy,TRUE)==FALSE) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение прямоугольника дочернего окна диалога в координатах диалога.

BYTE GetDlgWinRect(HWND hDlg,int id,RECT *rc)
{
int dx,dy; POINT pt; HWND hwnd;

if(rc==NULL) return 1; if(hDlg==NULL||id<=0) goto err;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) goto err;
if(GetWindowRect(hwnd,rc)==FALSE) goto err;
dx=(int)(rc->right-rc->left);
dy=(int)(rc->bottom-rc->top); 
pt.x=rc->left; pt.y=rc->top; if(ScreenToClient(hDlg,&pt)==FALSE) goto err;
rc->left=pt.x; rc->top=pt.y; rc->right=rc->left+(long)dx; rc->bottom=rc->top+(long)dy; return 0;
err: rc->left=rc->right=rc->top=rc->bottom=0; return 2;
}

//-----------------------------------------------------------------------------------------------------------
// Установка минимального размера окна.

BYTE SetMinSizeWin(HWND hwnd,LPMINMAXINFO lpMinMax,int dxm,int dym)
{
long dx,dy; POINT *pt; RECT rc; 

pt=&lpMinMax->ptMinTrackSize;
if(hwnd==NULL) dx=dy=0; else { 
if(GetClientRect(hwnd,&rc)==FALSE) return 1; dx=rc.right-rc.left; dy=rc.bottom-rc.top;
if(GetWindowRect(hwnd,&rc)==FALSE) return 2; dx=rc.right-rc.left-dx; dy=rc.bottom-rc.top-dy;}
if(dxm>0) pt->x=(long)dxm+dx; if(dym>0) pt->y=(long)dym+dy; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка минимального размера окна.

BYTE CheckWindowSize(HWND hwnd,int dxm,int dym)
{
long dx,dy,dxc,dyc; RECT rc;

if(hwnd==NULL) return 1; if(dxm<=0||dym<=0) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3; dxc=rc.right-rc.left; dyc=rc.bottom-rc.top;
if(GetWindowRect(hwnd,&rc)==FALSE) return 4; dx=rc.right-rc.left; dy=rc.bottom-rc.top;
if(dxc>=(long)dxm&&dyc>=(long)dym) return 0; 

if(dxc<(long)dxm) dx+=(long)dxm-dxc;
if(dyc<(long)dym) dy+=(long)dym-dyc; 
SetWindowPos(hwnd,HWND_TOP,0,0,dx,dy,SWP_SHOWWINDOW|SWP_NOMOVE); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Даёт размер диалогового окна.

BYTE GetSizeDlg(HWND hwndOwner,int idD,USHRT *dx,USHRT *dy)
{
LRESULT CALLBACK DlgProcVoid(HWND,UINT,WPARAM,LPARAM); // Вспомогательная функция диалогового окна.
void DestroyWin_(HWND *hwnd); // Уничтожение окна с обнулением 'hwnd'.

BYTE ber; USHRT s; RECT rc; HWND hwnd;

if(hInst==NULL) return 1; if(hwndOwner==NULL) return 2; if(idD<=0) return 3; if(dx==NULL&&dy==NULL) return 0;
hwnd=NULL; ber=0;
hwnd=CreateDialogParam(hInst,(LPCTSTR)idD,hwndOwner,(DLGPROC)DlgProcVoid,0L);
if(hwnd==NULL) { ber=4; goto end;}
if(GetWindowRect(hwnd,&rc)==FALSE) { ber=5; goto end;}
s=GetUSHRT_Test((int)(rc.right-rc.left)); if(s==0) { ber=6; goto end;} if(dx!=NULL) *dx=s;
s=GetUSHRT_Test((int)(rc.bottom-rc.top)); if(s==0) { ber=7; goto end;} if(dy!=NULL) *dy=s;
end: DestroyWin_(&hwnd); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Вспомогательная функция диалогового окна.

LRESULT CALLBACK DlgProcVoid(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{
void ImgWinC(HWND hwnd,DWORD ColP,DWORD ColB); // Закрашивание окна.

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: return TRUE;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hDlg,ColDial,ColDial); break;
}

return FALSE;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа со шрифтами.

//-----------------------------------------------------------------------------------------------------------
// Загрузка шрифта.

HFONT GetFont(char *nameFont,SHRT Wid,SHRT Hei)
{
if(nameFont==NULL) return NULL;
return CreateFont((int)Hei,(int)Wid,0,0,FW_THIN|FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_RASTER_PRECIS,
CLIP_DEFAULT_PRECIS,PROOF_QUALITY,DEFAULT_PITCH|FF_ROMAN,nameFont);
}

//-----------------------------------------------------------------------------------------------------------
// Программа для установки шрифта в окне.

BYTE SetFont(HWND hwnd,HFONT hFont)
{
if(hwnd==NULL) return 1; if(hFont==NULL) return 2;
SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,(LPARAM)MAKELONG((WORD)TRUE,0)); return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с меню.

//-----------------------------------------------------------------------------------------------------------
// Установка состояния пункта меню.

void SetStMenuItem_(HMENU hMenu,UINT id,SCHAR En,SCHAR Ch)
{
UINT ui;

if(hMenu==NULL) return; if(id==0) return;
if(En>=0) { if(En==0) ui=MF_GR; else ui=MF_EN; EnableMenuItem(hMenu,id,ui);}
if(Ch>=0) { if(Ch==0) ui=MF_UNCH; else ui=MF_CH; CheckMenuItem(hMenu,id,ui);}
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с окнами редактирования.

//-----------------------------------------------------------------------------------------------------------
// Установка значения 'BYTE' в окно редактирования.

BYTE SetByteEdt(HWND hDlg,int id,BYTE bV)
{
if(hDlg==NULL) return 1; if(id<=0) return 2; sprintf(TxtStr,"%d",(int)bV);
if(SetDlgItemText(hDlg,id,TxtStr)==FALSE) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение значения 'BYTE' из окна редактирования.

BYTE GetByteEdt(HWND hDlg,int id,BYTE *bV)
{
int iv;

if(hDlg==NULL) return 1; if(bV==NULL) return 2; if(id<=0) return 3;
if(GetDlgItemText(hDlg,id,TxtStr,strL_Txt)==0) { *bV=0; return 4;} if(strlen(TxtStr)==0) { *bV=0; return 5;}
iv=atoi(TxtStr); if(iv<0) iv=0; if(iv>UCHAR_MAX) iv=UCHAR_MAX; *bV=(BYTE)iv; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка значения 'USHRT' в окно редактирования.

BYTE SetUSHRT_Edt(HWND hDlg,int id,USHRT Val)
{
if(hDlg==NULL) return 1; if(id<=0) return 2; sprintf(TxtStr,"%d",(int)Val);
if(SetDlgItemText(hDlg,id,TxtStr)==FALSE) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение значения 'USHRT' из окна редактирования.

BYTE GetUSHRT_Edt(HWND hDlg,int id,USHRT *pVal)
{
int iv;

if(hDlg==NULL) return 1; if(pVal==NULL) return 2; if(id<=0) return 3;
if(GetDlgItemText(hDlg,id,TxtStr,strL_Txt)==0) return 4; if(strlen(TxtStr)==0) return 5;
iv=atoi(TxtStr); *pVal=GetUSHRT_Test(iv); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка значения 'UINT' в окно редактирования.

BYTE SetUINT_Edt(HWND hDlg,int id,UINT Val)
{
if(hDlg==NULL) return 1; if(id<=0) return 2; sprintf(TxtStr,"%u",Val);
if(SetDlgItemText(hDlg,id,TxtStr)==FALSE) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение значения 'UINT' из окна редактирования.

BYTE GetUINT_Edt(HWND hDlg,int id,UINT *pVal)
{
int iv;

if(hDlg==NULL) return 1; if(pVal==NULL) return 2; if(id<=0) return 3;
if(GetDlgItemText(hDlg,id,TxtStr,strL_Txt)==0) return 4; if(strlen(TxtStr)==0) return 5;
iv=atoi(TxtStr); if(iv<0) *pVal=0; else *pVal=(UINT)iv; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка значения с плавающей точкой в окно редактирования.

BYTE SetFlEdt(HWND hDlg,int id,float Val,char *Form)
{
char *Form_;

if(hDlg==NULL) return 1; if(id<=0) return 2; if(IsOKStr(Form)!=0) Form_="%f"; else Form_=Form;
if(sprintf(TxtStr,Form_,Val)<=0) return 4; if(SetDlgItemText(hDlg,id,TxtStr)==FALSE) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение значения с плавающей точкой из окна редактирования.

BYTE GetFlEdt(HWND hDlg,int id,float *Val)
{
if(hDlg==NULL) return 1; if(Val==NULL) return 2; if(id<=0) return 3;
if(GetDlgItemText(hDlg,id,TxtStr,strL_Txt)==0) *Val=0.0F; else *Val=(float)atof(TxtStr); return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с окном флага.

//-----------------------------------------------------------------------------------------------------------
// Установка флага в окне.

BYTE SetChBox(HWND hDlg,int id,BYTE flag)
{
int fl; HWND hwnd;

if(hDlg==NULL) return 1; if(id<=0) return 2; hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 3;
if(flag!=0) fl=BST_CHECKED; else fl=BST_UNCHECKED; CheckDlgButton(hDlg,id,fl); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение флага из окна.

BYTE GetChBox(HWND hDlg,int id,BYTE *flag)
{
HWND hwnd;

if(hDlg==NULL) return 1; if(id<=0) return 2; if(flag==NULL) return 3;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 4;
if(IsDlgButtonChecked(hDlg,id)==BST_CHECKED) *flag=1; else *flag=0; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа со списками.

//-----------------------------------------------------------------------------------------------------------
// Очистка списка.

BYTE ClearList(HWND hDlg,int id)
{
HWND hwnd;

if(hDlg==NULL) return 1; if(id<=0) return 2; hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 3;
SendMessage(hwnd,LB_RESETCONTENT,0,0); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка выделенного элемента в списке.

BYTE SelItemList(HWND hDlg,int id,USHRT num)
{
HWND hwnd;

if(hDlg==NULL) return 1; if(id<=0) return 2; hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 3;
LRes=SendMessage(hwnd,LB_SETCURSEL,(WPARAM)num,0); if(LRes==LB_ERR) return 4; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с комбинированными списками.

//-----------------------------------------------------------------------------------------------------------
// Установка размера комбинированного списка по числу строк.

BYTE SetSizeCombo(HWND hDlg,int id,BYTE num)
{
BYTE SizeMovWin(HWND hwnd,int shX,int shY,int dX,int dY,BYTE flChild); // Перемещение окна и изменение его размеров.

SHRT Hei; HWND hwnd; RECT rc;

if(hDlg==NULL) return 1; if(id<=0) return 2; if(num==0) return 3;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 4;
if(GetWindowRect(hwnd,&rc)==FALSE) return 5;
Hei=(SHRT)(rc.bottom-rc.top);
LRes=SendMessage(hwnd,CB_GETITEMHEIGHT,0,0L); if(LRes!=CB_ERR) Hei+=((SHRT)LRes+1)*(SHRT)num;
if(SizeMovWin(hwnd,0,0,0,(int)Hei,1)!=0) return 6; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка номера выбранной строки в комбинированном списке.

BYTE SetSelCombo(HWND hDlg,UINT id,BYTE num)
{
HWND hwnd;

if(hDlg==NULL) return 1; if(id==0) return 2;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 3;
SendMessage(hwnd,CB_SETCURSEL,(WPARAM)num,0L); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение номера выбранной строки в комбинированном списке.

BYTE GetSelCombo(HWND hDlg,UINT id,BYTE *num)
{
HWND hwnd;

if(hDlg==NULL) return 1; if(id==0) return 2; if(num==NULL) return 3;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 4;
LRes=SendMessage(hwnd,CB_GETCURSEL,0,0L); if(LRes==CB_ERR) return 5; if(LRes>UCHAR_MAX) return 6;
*num=(BYTE)LRes; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение комбинированного списка.

BYTE FillStrCombo(HWND hDlg,UINT id,UINT *IDSArr,BYTE nArr,BYTE nSel)
{
BYTE SetSizeCombo(HWND hDlg,int id,BYTE num); // Установка размера комбинированного списка по числу строк.

BYTE i; char *cp; HWND hwnd;

if(hDlg==NULL) return 1; if(id==0) return 2; if(IDSArr==NULL) return 3; if(nArr==NULL) return 4;
if(hInst==NULL) return 5; hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return 6;
SetSizeCombo(hDlg,(int)id,nArr);
for(i=0;i<nArr;i++) { if(LoadString(hInst,IDSArr[i],TxtStr,strL_Txt)!=0) cp=TxtStr; else cp="-";
SendMessage(hwnd,CB_ADDSTRING,0,(LPARAM)(LPSTR)TxtStr);}
if(nSel<nArr) SendMessage(hwnd,CB_SETCURSEL,nSel,0); return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с полосой прокрутки.

//-----------------------------------------------------------------------------------------------------------
// Обработка сообщений от органов управления горизонтальной полосы прокрутки.

BYTE ScrollFun(WPARAM wParam,BYTE typ,SHRT *p,SHRT pMin,SHRT pMax,SHRT nScrl,SHRT nScrlP)
{
BYTE fl; SHRT k,p_; int nScroll;

if(p==NULL) return 1; if(nScrl<=0||nScrlP<=0) return 2; if(pMax<=pMin) return 3;
nScroll=(int)LOWORD(wParam);

switch(nScroll) { default: break;
case SB_TOP: *p=pMax; break;
case SB_BOTTOM: *p=pMin; break;

case SB_LINEDOWN: case SB_PAGEDOWN: case SB_LINEUP: case SB_PAGEUP:
if(nScroll==SB_LINEUP||nScroll==SB_LINEDOWN) k=nScrl; else k=nScrlP;
if(nScroll==SB_LINEDOWN||nScroll==SB_PAGEDOWN) { if(typ==0) fl=0; else fl=1;} else { if(typ!=0) fl=0; else fl=1;}
if(fl==0) { if((int)*p+(int)k<=pMax) *p+=k; else *p=pMax;}
else { if((int)*p-(int)k>=pMin) *p-=k; else *p=pMin;} break;

case SB_THUMBTRACK: p_=(SHRT)HIWORD(wParam); if(typ==0) *p=p_; else *p=pMax-p_+pMin;
if(*p<pMin) *p=pMin; if(*p>pMax) *p=pMax; break;}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка сообщений от полосы прокрутки.

BYTE ScrollFunS(WPARAM wParam,int *p,int pMin,int pMax,SHRT nScrl,SHRT nScrlP)
{
BYTE fl; SHRT k; int nScroll;

if(p==NULL) return 1; if(nScrl<=0) return 2; if(nScrlP<=0) return 3; if(pMax<pMin) return 4;
nScroll=(int)LOWORD(wParam);

switch(nScroll) { default: break;
case SB_TOP: *p=pMax; break;
case SB_BOTTOM: *p=pMin; break;

case SB_LINEDOWN: case SB_PAGEDOWN: case SB_LINEUP: case SB_PAGEUP:
if(nScroll==SB_LINEUP||nScroll==SB_LINEDOWN) k=nScrl; else k=nScrlP;
if(nScroll==SB_LINEDOWN||nScroll==SB_PAGEDOWN) fl=0; else fl=1;
if(fl==0) { if(*p+(int)k<=pMax) *p+=(int)k; else *p=pMax;}
else { if(*p-(int)k>=pMin) *p-=(int)k; else *p=pMin;} break;

case SB_THUMBTRACK: *p=(int)HIWORD(wParam); if(*p<pMin) *p=pMin; if(*p>pMax) *p=pMax; break;}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка сообщений от полосы прокрутки.

BYTE ScrollFun32(HWND hwnd,int nScroll,BYTE Dir,BYTE Cntrl,int *p,int nScrl,int nScrlP)
{
BYTE fl,ber; int k,fnBar,pMin,pMax,add; SCROLLINFO *pSI;

if(hwnd==NULL) return 1; if(p==NULL) return 2; if(nScrl<=0) return 3; if(nScrlP<=0) return 4;
pSI=NULL; ber=0;

pSI=new SCROLLINFO; if(pSI==NULL) { ber=5; goto end;} SET_ZERO(pSI); pSI->cbSize=sizeof(SCROLLINFO);
pSI->fMask=SIF_RANGE|SIF_PAGE|SIF_TRACKPOS;
if(Cntrl==0) { if(Dir==0) fnBar=SB_HORZ; else fnBar=SB_VERT;} else fnBar=SB_CTL;
if(GetScrollInfo(hwnd,fnBar,pSI)==FALSE) { ber=6; goto end;}
if(pSI->nPage>INT_MAX) { ber=7; goto end;} if(pSI->nPage>0) add=(int)pSI->nPage-1; else add=0;
pMin=pSI->nMin; pMax=pSI->nMax-add; if(pMax<pMin) { ber=8; goto end;}

switch(nScroll) { default: ber=messRet; goto end;
case SB_TOP: *p=pMax; break;
case SB_BOTTOM: *p=pMin; break;

case SB_LINEUP: case SB_PAGEUP: case SB_LINEDOWN: case SB_PAGEDOWN:
if(nScroll==SB_LINEUP||nScroll==SB_LINEDOWN) k=nScrl; else k=nScrlP;
if(nScroll==SB_LINEDOWN||nScroll==SB_PAGEDOWN) fl=0; else fl=1;
if(fl==0) { if((__int64)*p+(__int64)k<=pMax) *p+=k; else *p=pMax;}
else { if((__int64)*p-(__int64)k>=pMin) *p-=k; else *p=pMin;} break;

case SB_THUMBTRACK: *p=pSI->nTrackPos; if(*p<pMin) *p=pMin; if(*p>pMax) *p=pMax; break;}

end: SAFE_DELETE(pSI); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Установка пределов и размера страницы в полосе прокрутки с пропорциональной шириной ползунка.

BYTE SetRangePageScrollBar(HWND hwnd,BYTE Dir,BYTE Cntrl,int nMin,int nMax,UINT nPage,BYTE Update)
{
int fnBar,add; BOOL b; SCROLLINFO *pSI;

if(hwnd==NULL) return 1; if(nMax<nMin) return 2; if(nPage>INT_MAX) return 3;
if(nPage==0) add=0; else add=nPage-1; if(nMax>INT_MAX-add) return 4;
pSI=new SCROLLINFO; if(pSI==NULL) return 5; SET_ZERO(pSI); pSI->cbSize=sizeof(SCROLLINFO);
pSI->fMask=SIF_RANGE|SIF_PAGE; pSI->nMin=nMin; pSI->nMax=nMax+add; pSI->nPage=nPage;
if(Cntrl==0) { if(Dir==0) fnBar=SB_HORZ; else fnBar=SB_VERT;} else fnBar=SB_CTL;
if(Update==0) b=FALSE; else b=TRUE; SetScrollInfo(hwnd,fnBar,pSI,b); SAFE_DELETE(pSI); return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с полосой процента выполненной работы.

//-----------------------------------------------------------------------------------------------------------
// Инициализация окна показа процента выполнения работы.

HWND InitProgress(HWND hDlg,int id)
{
HWND hwnd;

if(hDlg==NULL) return NULL; if(id<=0) return NULL;
hwnd=GetDlgItem(hDlg,id); if(hwnd==NULL) return NULL;
SendMessage(hwnd,PBM_SETRANGE,0,MAKELPARAM(0,100));
SendMessage(hwnd,PBM_SETSTEP,(WPARAM)1,0L);
return hwnd;
}

//-----------------------------------------------------------------------------------------------------------
// Установка цветов индикаторной полосы показа процента выполнения работы.

void SetColProgr(HWND hwnd,DWORD BkgCol,DWORD BarCol)
{
if(hwnd==NULL) return;
SendMessage(hwnd,PBM_SETBKCOLOR,0,(LPARAM)BkgCol);
SendMessage(hwnd,PBM_SETBARCOLOR,0,(LPARAM)BarCol);
}

//-----------------------------------------------------------------------------------------------------------
// Изображение процента выполнения работы.

void ShowProgress(HWND hwndProgr,HWND hwndPerc,UINT p,UINT pMax)
{
BYTE GetBYTE(float v); // Получение числа 'BYTE' из числа 'float' с проверкой выхода за пределы 'BYTE'.

BYTE Perc;

if(pMax==0) { SendMessage(hwndProgr,PBM_SETPOS,0,0L); SetWindowText(hwndPerc,""); return;}
if(p>=pMax) Perc=100; else Perc=GetBYTE((float)p/(float)pMax*100.0F);
if(hwndProgr!=NULL) SendMessage(hwndProgr,PBM_SETPOS,(WPARAM)Perc,0L);
if(hwndPerc!=NULL) { sprintf(TxtStr,"%3d",(int)Perc); SetWindowText(hwndPerc,(LPCTSTR)TxtStr);}
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с файлами и директориями.

//-----------------------------------------------------------------------------------------------------------
// Проверка существования файла или директории.

BYTE IsFileDirExists(char *PathName,BYTE flDir)
{
BYTE ber; DWORD Fl; WIN32_FIND_DATA *FileData;

if(IsOKStr(PathName)!=0) return 1; FileData=NULL; ber=0;
FileData=new WIN32_FIND_DATA; if(FileData==NULL) { ber=2; goto end;}
if(FindFirstFile((LPCTSTR)PathName,FileData)==INVALID_HANDLE_VALUE) { ber=3; goto end;}
Fl=FileData->dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY;
if(flDir==0&&Fl!=0L||flDir!=0&&Fl==0L) { ber=4; goto end;}
end: SAFE_DELETE(FileData); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка существования файла.

BYTE IsFileExist(char *Name,char *PathDir,char *dir,char *ext)
{
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // Получение имени файла включая путь.
BYTE IsFileDirExists(char *PathName,BYTE flDir); // Проверка существования файла или директории.
void FreeString(char **Str); // Освобождение памяти для строки.

BYTE ber; char *nam;

if(IsOKStr(Name)!=0) return 1; nam=NULL; ber=0;
if(GetName(&nam,PathDir,dir,Name,ext)!=0) { ber=2; goto end;}
if(IsFileDirExists(nam,0)!=0) { ber=3; goto end;}
end: FreeString(&nam); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка существования файла.

BYTE IsFileExist_(char *PathName)
{
BYTE IsFileDirExists(char *PathName,BYTE flDir); // Проверка существования файла или директории.

return IsFileDirExists(PathName,0);
}

//-----------------------------------------------------------------------------------------------------------
// Получение имени файла включая путь.

BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext)
{
BYTE ber; char **Items;

Items=NULL; ber=0;
if(AllocPString(&Items,4)!=0) { ber=1; goto end;}
Items[0]=path; Items[1]=dir; Items[2]=name; Items[3]=ext;
if(GetString(Name,Items,4)!=0) { ber=2; goto end;}
end: FreePString(&Items); return ber;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define Err_File 0xFFFFFFFF

//-----------------------------------------------------------------------------------------------------------
// Открытие файла.

HANDLE OpenHandleFile_(char *name,BYTE indWr)
{
HANDLE Handle; DWORD Acc,CrDisp;

Handle=INVALID_HANDLE_VALUE; if(IsOKStr(name)!=0) goto end;
if(indWr!=0) { Acc=GENERIC_WRITE; CrDisp=CREATE_ALWAYS;} else { Acc=GENERIC_READ; CrDisp=OPEN_EXISTING;}
Handle=CreateFile((LPCTSTR)name,Acc,0,NULL,CrDisp,0,NULL);
end: return Handle;
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие файла.

void CloseHandleFile_(HANDLE *File)
{
if(File==NULL) return; SAFE_CLOSE_FILE(*File);
}

//-----------------------------------------------------------------------------------------------------------
// Чтение файла.

BYTE ReadFile_(HANDLE File,LPVOID Buf,DWORD len)
{
BOOL flag; DWORD lenR;
 
if(File==INVALID_HANDLE_VALUE) return 1; flag=ReadFile(File,Buf,len,&lenR,NULL);
if(flag==FALSE) { ErrMessage(); return 2;} if(flag!=FALSE&&lenR!=len) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE WriteFile_(HANDLE File,LPVOID Buf,DWORD len)
{
BOOL flag; DWORD lenW;

if(File==INVALID_HANDLE_VALUE) return 1; flag=WriteFile(File,Buf,len,&lenW,NULL);
if(flag==FALSE) { ErrMessage(); return 2;} if(flag!=FALSE&&lenW!=len) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Позиционирование внутри файла.

long SeekFile(HANDLE File,long offs,DWORD MoveMethod)
{
long Low,High; 

if(File==INVALID_HANDLE_VALUE) return -1; Low=offs; High=0L;
Low=SetFilePointer(File,Low,&High,MoveMethod); if(Low==(long)Err_File) return -2;
if(High!=0L) return -3; return Low;
}

//-----------------------------------------------------------------------------------------------------------
// Получение размера файла.

BYTE SizeOfFile(HANDLE File,DWORD *ln)
{
DWORD Low,High;

if(File==INVALID_HANDLE_VALUE) return 1; Low=GetFileSize(File,&High); if(Low==(DWORD)Err_File) return 2;
if(High!=0L) return 3; if(ln!=NULL) *ln=Low; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выводит стандартный диалог для запроса имени файла и получает имя файла и директории.

BYTE FileNameQuest(HWND hwnd,BYTE flWrite,UINT idSFilt,char *PathToDir,char *extFile,UINT IDS_Header,
char *FileNameN,USHRT szFileNameN,char *PathToDirN,USHRT szPathToDirN,char *ExtN,USHRT szExtN,BYTE flChExt)
{
BYTE GetNameFileOpen(HWND hwnd,BYTE flSave,char *StrFilt,UINT StrID,USHRT *nFilterIndex,char *PathToDir,
  char *FileNameIni,char *Ext,char *PathToDirN,USHRT szPathToDirN,char *FileNameN,USHRT szFileNameN,
  char *ExtN,USHRT szExtN,BYTE cutExt,BYTE flChExt,UINT IDS_Header); // Выводит стандартный диалог для запроса имени файла и получает имя файла и директории.
BYTE StrSybmConv(char *StrI,char *StrC,size_t szStrC,BYTE flag); // Преобразование символов строки в верхние или нижние символы.

BYTE be; USHRT nInd; char *FileNameIni;

if(PathToDir==NULL) return 1;
if(FileNameN==NULL) return 2; if(szFileNameN==0) return 3;
if(PathToDirN==NULL) return 4; if(szPathToDirN==0) return 5; if(IsOKStr(extFile)!=0) return 6;
if(idSFilt==0) return 7;
nInd=1; if(flWrite!=0) FileNameIni=FileNameN; else FileNameIni=NULL;

be=GetNameFileOpen(hwnd,flWrite,NULL,idSFilt,&nInd,PathToDir,FileNameIni,extFile,PathToDirN,szPathToDirN,
FileNameN,szFileNameN,ExtN,szExtN,1,flChExt,IDS_Header); if(be==messRet) return messRet; if(be!=0) return 8;
if(StrSybmConv(ExtN,ExtN,szExtN,0)!=0) return 9;
if(flChExt!=0) { if(CompareStr(ExtN,extFile)!=0) return 10;}
ProcMess(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка наличия директории и создание при необходимости.

BYTE CheckCreateDir(char *Path,char *dir,BYTE flCreate)
{
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // Получение имени файла включая путь.
BYTE IsFileDirExists(char *PathName,BYTE flDir); // Проверка существования файла или директории.

BYTE ber; size_t ln; char *cp;

if(dir==NULL) return 1; cp=NULL; ber=0;
if(GetName(&cp,Path,dir,NULL,NULL)!=0) { ber=2; goto end;}
ln=strlen(cp); if(ln==0) { ber=3; goto end;} if(*(cp+ln-1)=='\\') *(cp+ln-1)='\0';
if(IsFileDirExists(cp,1)!=0) {
if(flCreate!=0) { if(CreateDirectory(cp,NULL)==FALSE) { ber=4; goto end;}}
else { ber=messRet; goto end;}}
end: FreeString(&cp); return ber;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define nStrAppPath 3 // Число строк при получении пути к программе.

//-----------------------------------------------------------------------------------------------------------
// Запуск другой программы.

BYTE Process(char *Path,char *Dir,char *Name,char *ComStr,char *CurrDir,BYTE show,BYTE wait)
{
void ErrMessage(void); // Выдача сообщения об ошибке.

BYTE ber; char *AppPath,**Items; WORD *pw; PROCESS_INFORMATION *PrInf; STARTUPINFO *StUpInfo; HCURSOR cur;

AppPath=NULL; Items=NULL; PrInf=NULL; StUpInfo=NULL; cur=NULL; ber=0;
PrInf=new PROCESS_INFORMATION; if(PrInf==NULL) { ber=1; goto end;}
StUpInfo=new STARTUPINFO; if(StUpInfo==NULL) { ber=2; goto end;}
if(AllocPString(&Items,nStrAppPath)!=0) { ber=3; goto end;}
Items[0]=Path; Items[1]=Dir; Items[2]=Name;
if(GetString(&AppPath,Items,nStrAppPath)!=0) { ber=4; goto end;}

SET_ZERO(PrInf);
SET_ZERO(StUpInfo); StUpInfo->cb=sizeof(STARTUPINFO);
GetStartupInfo(StUpInfo);
pw=&StUpInfo->wShowWindow; if(show!=0) *pw=SW_SHOWNORMAL; else *pw=SW_HIDE;

if(wait!=0&&cur_wait!=NULL) cur=SetCursor(cur_wait);
if(CreateProcess(AppPath,ComStr,NULL,NULL,TRUE,CREATE_NEW_CONSOLE,NULL,CurrDir,StUpInfo,PrInf)==FALSE) {
ErrMessage(); ber=5; goto end;}
if(wait!=0) WaitForSingleObject(PrInf->hProcess,INFINITE);
SAFE_CLOSE_FILE(PrInf->hProcess);
SAFE_CLOSE_FILE(PrInf->hThread);

end: if(cur!=NULL) SetCursor(cur); SAFE_DELETE(PrInf); SAFE_DELETE(StUpInfo);
FreeString(&AppPath); FreePString(&Items); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с библиотеками *.dll.

//-----------------------------------------------------------------------------------------------------------
// Загрузка библиотеки '*.dll'.

BYTE LoadLib(char *nameLib,char *Path,char *dir,HMODULE *hLib)
{
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // Получение имени файла включая путь.
BYTE IsFileExist(char *Name,char *PathDir,char *dir,char *ext); // Проверка существования файла.
void Message_(HWND hwnd,UINT StrID,char *txt,UINT typ); // Вывод сообщения.

BYTE ber; char *cp,*ext,*extDLL=".dll";

if(IsOKStr(nameLib)!=0) return 1; if(hLib==NULL) return 2;
ber=0; cp=NULL;
if(strchr(nameLib,'.')==NULL) ext=extDLL; else ext=NULL;
if(GetName(&cp,Path,dir,nameLib,ext)!=0) { ber=3; goto end;}
if(IsFileExist(nameLib,Path,dir,ext)!=0) { Message_(NULL,IDS_Err_NoFileDLL,cp,MB_ST); ber=4; goto end;}
*hLib=LoadLibrary((LPCTSTR)cp);
if(*hLib==NULL) { ErrMessage(); Message_(NULL,IDS_Err_LoadDLL,cp,MB_EX); ber=5; goto end;}
end: FreeString(&cp); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа со звуком.

//-----------------------------------------------------------------------------------------------------------
// Вывод звука из массива.

BYTE PlayWave_(float *Wave,UINT nPoints,DWORD sps,BYTE *flStop,DWORD WOP,DWORD Pnt,HWAVEOUT *hwo_)
{
BYTE PlayWave(SHRT *Wave,UINT nPoints,DWORD sps,BYTE *flStop,DWORD WOP,DWORD Pnt,HWAVEOUT *hwo_); // Вывод звука из массива.
BYTE AllocSHRT(SHRT **shipp,size_t ln); // Выделение памяти для массива 'SHRT'.
void FreeSHRT(SHRT **shipp); // Освобождение памяти для массива 'SHRT'.

BYTE be,ber; UINT i; SHRT *wav;

if(Wave==NULL) return 1; if(nPoints==0) return 2; if(sps==0UL) return 3;
wav=NULL; ber=0;
if(AllocSHRT(&wav,(size_t)nPoints)!=0) { ber=4; goto end;}
for(i=0;i<nPoints;i++) wav[i]=GetSHRT_Test(Wave[i]);
be=PlayWave(wav,nPoints,sps,flStop,WOP,Pnt,hwo_);
if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=5; goto end;}
end: FreeSHRT(&wav); return ber;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Параметры, используемые в функции 'PlayWave'.

#define nChnls 1 // Число каналов.
#define wBytesPerSample 2 // Режим вывода 16-битовых знаковых значений.

//-----------------------------------------------------------------------------------------------------------
// Вывод звука из массива.

BYTE PlayWave(SHRT *Wave,UINT nPoints,DWORD sps,BYTE *flStop,DWORD WOP,DWORD Pnt,HWAVEOUT *hwo_)
{
BYTE be,ber; DWORD fdwOpen; HWAVEOUT hwo; WAVEFORMATEX *wfx; WAVEHDR *wh;

if(Wave==NULL) return 1; if(nPoints==0) return 2; if(sps==0UL) return 3;
if(WOP==0) fdwOpen=CALLBACK_NULL; else fdwOpen=CALLBACK_FUNCTION; fdwOpen=fdwOpen|WAVE_ALLOWSYNC;

wfx=NULL; wh=NULL; ber=0;
wfx=new WAVEFORMATEX; if(wfx==NULL) { ber=4; goto end;} SET_ZERO(wfx);
wfx->wFormatTag=WAVE_FORMAT_PCM;
wfx->nChannels=(WORD)nChnls;
wfx->nSamplesPerSec=sps;
wfx->nBlockAlign=(WORD)nChnls*(WORD)wBytesPerSample;
wfx->nAvgBytesPerSec=sps*wfx->nBlockAlign;
wfx->wBitsPerSample=(WORD)wBytesPerSample*8;
wfx->cbSize=0;

if(waveOutOpen(&hwo,WAVE_MAPPER,wfx,WOP,Pnt,fdwOpen)!=MMSYSERR_NOERROR) { ber=5; goto end;}
if(hwo_!=NULL) *hwo_=hwo;

wh=new WAVEHDR; if(wh==NULL) { ber=6; goto end;} SET_ZERO(wh);
wh->lpData=(LPSTR)Wave;
wh->dwBufferLength=(DWORD)nPoints*(DWORD)wBytesPerSample;
wh->dwBytesRecorded=0; wh->dwUser=NULL; wh->dwFlags=0; wh->dwLoops=0; wh->lpNext=NULL; wh->reserved=0;

if(waveOutPrepareHeader(hwo,wh,(UINT)sizeof(WAVEHDR))!=MMSYSERR_NOERROR) { ber=7; goto end;}
if(waveOutWrite(hwo,wh,(UINT)sizeof(WAVEHDR))!=MMSYSERR_NOERROR) { ber=8; goto end;}
while((wh->dwFlags&WHDR_DONE)==0) { ProcMess(); if(flStop!=NULL) { if(*flStop!=0) break;}}
be=0;
if(waveOutUnprepareHeader(hwo,wh,(UINT)sizeof(WAVEHDR))!=MMSYSERR_NOERROR) be+=1<<0;
if(waveOutReset(hwo)!=MMSYSERR_NOERROR) be+=1<<1;
if(waveOutClose(hwo)!=MMSYSERR_NOERROR) be+=1<<2;
if(be!=0) { ber=messRet; goto end;}

end: if(hwo_!=NULL) *hwo_=NULL; SAFE_DELETE(wfx); SAFE_DELETE(wh); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Работа с изображениями.

//-----------------------------------------------------------------------------------------------------------
// Построение битового изображения в прямоугольнике 'rc'.

BYTE DrawBitmap(HDC hdc,RECT *rc,HBITMAP hBitmap,BYTE typDrawBMP,BYTE posH,BYTE posV)
{
BYTE GetLSizeBMP(HBITMAP hbm,long *dx,long *dy); // Получение размера изображения.
int GetRelPosH(BYTE posH,int dx); // Нахождение сдвига объекта по горизонтали исходя из относительного положения точки привязки.
int GetRelPosV(BYTE posV,int dy); // Нахождение сдвига объекта по вертикали исходя из относительного положения точки привязки.

BYTE ber; int dx,dy,dxn,dyn,xi,yi,xIS,yIS,xID,yID,*ip; float scl; POINT ptSize,ptOrg; HDC hMemDC;
HBITMAP hOldBmp;

if(hdc==NULL) return 1; if(IsOKRect(rc)!=0) return 2; if(hBitmap==NULL) return 3;
dx=(int)(rc->right-rc->left);
dy=(int)(rc->bottom-rc->top);
if(typDrawBMP!=typDrawBMP_Exact) { if(SetStretchBltMode(hdc,STRETCH_DELETESCANS)==0) return 4;}
if(GetLSizeBMP(hBitmap,&ptSize.x,&ptSize.y)!=0) return 5;

hMemDC=NULL; hOldBmp=NULL; ber=0;
hMemDC=CreateCompatibleDC(hdc); if(hMemDC==NULL) { ber=6; goto end;}
hOldBmp=(HBITMAP)SelectObject(hMemDC,hBitmap); if(hOldBmp==NULL) { ber=7; goto end;}
SetMapMode(hMemDC,GetMapMode(hdc));
DPtoLP(hdc,&ptSize,1); ptOrg.x=0; ptOrg.y=0; DPtoLP(hMemDC,&ptOrg,1);

switch(typDrawBMP) { default: ber=8; goto end;

// Масштабирование изображения проводится точно по размерам прямоугольника.
case typDrawBMP_Stretch:
if(StretchBlt(hdc,(int)rc->left,(int)rc->top,dx,dy,hMemDC,(int)ptOrg.x,(int)ptOrg.y,(int)ptSize.x,(int)ptSize.y,SRCCOPY)==FALSE) { ber=9; goto end;}
break;

// Масштабирование изображения проводится так, чтобы сохранялись пропорции, а изображение помещалось в прямоугольник.
case typDrawBMP_Size:
scl=MIN((float)dx/(float)ptSize.x,(float)dy/(float)ptSize.y);
dxn=GetIntTest((float)ptSize.x*scl); if(dxn<1) dxn=1;
dyn=GetIntTest((float)ptSize.y*scl); if(dyn<1) dyn=1;
xi=(int)rc->left+(dx-dxn)/2;
yi=(int)rc->top+(dy-dyn)/2;
if(StretchBlt(hdc,xi,yi,dxn,dyn,hMemDC,(int)ptOrg.x,(int)ptOrg.y,(int)ptSize.x,(int)ptSize.y,SRCCOPY)==FALSE) { ber=10; goto end;}
break;

// Размеры изображения остаются неизменными, положение относительно прямоугольника задаётся параметрами 'posH,posV'.
case typDrawBMP_Exact:
xi=GetRelPosH(posH,dx-(int)ptSize.x);
yi=GetRelPosV(posV,dy-(int)ptSize.y);
ip=&dxn; *ip=(int)ptSize.x; if(*ip>dx) *ip=dx;
ip=&dyn; *ip=(int)ptSize.y; if(*ip>dy) *ip=dy;
ip=&xID; *ip=xi; if(*ip<0) { xIS=-*ip; *ip=0;} else xIS=0; *ip+=(int)rc->left;
ip=&yID; *ip=yi; if(*ip<0) { yIS=-*ip; *ip=0;} else yIS=0; *ip+=(int)rc->top;
if(BitBlt(hdc,xID,yID,dxn,dyn,hMemDC,xIS,yIS,SRCCOPY)==FALSE) { ber=11; goto end;}
break;}

end: if(hMemDC!=NULL&&hOldBmp!=NULL) SelectObject(hMemDC,hOldBmp); if(hMemDC!=NULL) DeleteDC(hMemDC);
return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Создание заголовка файла с изображением 'DIB'.

BYTE CreateHeaderBMP(BITMAPINFOHEADER *Info,int dx,int dy,BYTE typ,SHRT nCol)
{
DWORD Comp,Clr; WORD BitCount;

if(Info==NULL) return 1;
switch(typ) { default: return 2;
// 32 бита.
case typBmp_32: BitCount=32; Clr=0; Comp=BI_RGB; break;
// True Color.
case typBmp_24: BitCount=24; Clr=0; Comp=BI_RGB; break;
// 16 бит.
case typBmp_16: BitCount=16; Clr=3; Comp=BI_BITFIELDS; break;
// 8 бит (256 цветов).
case typBmp_8: BitCount=8; if(nCol<=0||nCol>256) return 3; Clr=nCol; Comp=BI_RGB; break;
// 4 бит (16 цветов).
case typBmp_4: BitCount=4; if(nCol<=0||nCol>16) return 4; Clr=nCol; Comp=BI_RGB; break;
// 1 бит (монохромное изображение).
case typBmp_1: BitCount=1; Clr=2; Comp=BI_RGB; break;}

Info->biBitCount=BitCount; Info->biClrUsed=Clr; Info->biCompression=Comp;
if(typ==typBmp_16) Info->biSizeImage=(DWORD)sizeof(BITMAPINFOHEADER)+Clr*(DWORD)sizeof(RGBQUAD);
else Info->biSizeImage=0L;
Info->biSize=sizeof(BITMAPINFOHEADER);
Info->biWidth=(long)dx; Info->biHeight=(long)dy;
Info->biPlanes=1; Info->biXPelsPerMeter=Info->biYPelsPerMeter=0; Info->biClrImportant=0;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение структуры информации для битового изображения.

BYTE CreateInfoBMP(BITMAPINFO **BMInfo,int dx,int dy,BYTE typBmp,DWORD *NCol,SHRT nCol)
{
BYTE CreateHeaderBMP(BITMAPINFOHEADER *Info,int dx,int dy,BYTE typ,SHRT nCol); // Создание заголовка файла с изображением 'DIB'.
BYTE SetColArrRGBQuad(DWORD *NCol,SHRT nCol,RGBQUAD *RGBCol); // Установка массива цветов.

BYTE i,bm,be,ber; SHRT nRGB_; size_t sizeRGB,len; DWORD dw,*NCol_; BITMAPINFOHEADER *Info;

if(BMInfo==NULL) return 1; if(*BMInfo!=NULL) { free((void *)*BMInfo); *BMInfo=NULL;}
if(dx<=0||dy<=0) return 2;

switch(typBmp) { default: return 3;
// 32 бита.
case typBmp_32: nRGB_=0; break;
// True Color.
case typBmp_24: nRGB_=0; break;
// 16 бит.
case typBmp_16: nRGB_=3; break;
// 8 бит (256 цветов).
case typBmp_8: if(nCol<=0||nCol>256) return 4; if(NCol==NULL) return 5; nRGB_=nCol; break;
// 4 бит (16 цветов).
case typBmp_4: if(nCol<=0||nCol>16) return 6; if(NCol==NULL) return 7; nRGB_=nCol; break;
// 1 бит (монохромное изображение).
case typBmp_1: nRGB_=2; break;}

Info=NULL; NCol_=NULL; ber=0;

Info=new BITMAPINFOHEADER; if(Info==NULL) { ber=5; goto end;}

sizeRGB=sizeof(RGBQUAD);
len=sizeof(BITMAPINFOHEADER); if(nRGB_>0) len+=(size_t)nRGB_*sizeRGB;
*BMInfo=(BITMAPINFO *)malloc(len); if(*BMInfo==NULL) { ber=6; goto end;}

if(CreateHeaderBMP(Info,dx,dy,typBmp,nRGB_)!=0) { ber=7; goto end;}
memcpy((void *)&(*BMInfo)->bmiHeader,(void *)Info,sizeof(BITMAPINFOHEADER));

switch(typBmp) { default: ber=8; goto end;
// 32 бита.
case typBmp_32: break;

// True Color.
case typBmp_24: break;

// 16 бит.
case typBmp_16: bm=31;
for(i=0;i<3;i++) { dw=(DWORD)bm; dw=dw<<((2-i)*5);
memcpy((void *)&(*BMInfo)->bmiColors[i],(void *)&dw,sizeRGB);} break;

// 8 бит (256 цветов) и 4 бита (16 цветов).
case typBmp_8: case typBmp_4:
if(SetColArrRGBQuad(NCol,nRGB_,(*BMInfo)->bmiColors)!=0) { ber=9; goto end;} break;

// 1 бит (монохромное изображение).
case typBmp_1:
if(AllocDWORD(&NCol_,2)!=0) { ber=10; goto end;}
NCol_[0]=COL_BLACK; NCol_[1]=COL_WHITE;
be=SetColArrRGBQuad(NCol_,2,(*BMInfo)->bmiColors); if(be!=0) { ber=11; goto end;}
FreeDWORD(&NCol_); break;}

end: SAFE_DELETE(Info); FreeDWORD(&NCol_); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление заголовка файла с изображением 'DIB'.

void DeleteInfoBMP(BITMAPINFO **BMInfo)
{
if(BMInfo==NULL) return; if(*BMInfo!=NULL) { free((void *)*BMInfo); *BMInfo=NULL;}
}

//-----------------------------------------------------------------------------------------------------------
// Установка массива цветов.

BYTE SetColArrRGBQuad(DWORD *NCol,SHRT nCol,RGBQUAD *RGBCol)
{
SHRT i; DWORD Col; RGBQUAD *rgb;

if(NCol==NULL) return 1; if(nCol<=0) return 2; if(RGBCol==NULL) return 3;
for(i=0;i<nCol;i++) { Col=NCol[i]; rgb=RGBCol+i; rgb->rgbReserved=0;
rgb->rgbRed=GetRValue(Col); rgb->rgbGreen=GetGValue(Col); rgb->rgbBlue=GetBValue(Col);} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение массива цветов.

BYTE GetColArrRGBQuad(DWORD *NCol,SHRT nCol,RGBQUAD *RGBCol)
{
SHRT i; RGBQUAD *rgb;

if(NCol==NULL) return 1; if(nCol<=0) return 2; if(RGBCol==NULL) return 3;
for(i=0;i<nCol;i++) { rgb=RGBCol+i; NCol[i]=RGB(rgb->rgbRed,rgb->rgbGreen,rgb->rgbBlue);} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение компонент цвета.

BYTE GetColComp(COLORREF Col,BYTE *CC)
{
if(CC==NULL) return 1; CC[0]=GetRValue(Col); CC[1]=GetGValue(Col); CC[2]=GetBValue(Col); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка бит при работе с 16-битным цветом.

BYTE SetBitBmp16(BYTE *bt,BYTE *CC)
{
USHRT v,r,g,b;

if(bt==NULL) return 1; if(CC==NULL) return 2;
b=(USHRT)CC[2]>>3; g=(USHRT)CC[1]>>3; r=(USHRT)CC[0]>>3;
v=b+(g<<5)+(r<<10); *(bt+1)=(BYTE)(v>>8); *bt=(BYTE)(v&255); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание 'DIB'.

BYTE InitImgBitmap(int dx,int dy,BYTE typBmp,UINT *dxB_,HBITMAP *hBitmap,BYTE **pvBits,DWORD *NCol,SHRT nCol)
{
BYTE GetBitPerPix(BYTE typ,BYTE *BitCount); // Получение числа бит на пиксел.
UINT GetSzBmp(UINT Width,BYTE BitCount); // Получение ширины изображения в байтах с учётом выравнивания по границе, кратной 4 байтам.
BYTE CreateInfoBMP(BITMAPINFO **BMInfo,int dx,int dy,BYTE typBmp,DWORD *NCol,SHRT nCol); // Получение структуры информации для битового изображения.
void DeleteInfoBMP(BITMAPINFO **BMInfo); // Удаление заголовка файла с изображением 'DIB'.

BYTE BitCount,ber; UINT dxB; BITMAPINFO *BMInfo;

if(hBitmap==NULL) return 1; if(dx<=0||dy<=0) return 2; if(dx>SHRT_MAX||dy>SHRT_MAX) return messLrgAr;
if(GetBitPerPix(typBmp,&BitCount)!=0) return 3;
dxB=GetSzBmp((UINT)dx,BitCount); if(dxB==0) return 4;
if((UINT)dxB>szMemMax/(UINT)dy) return messLrgAr;

BMInfo=NULL; ber=0;
if(CreateInfoBMP(&BMInfo,dx,dy,typBmp,NCol,nCol)!=0) { ber=5; goto end;}
*hBitmap=CreateDIBSection(NULL,BMInfo,DIB_RGB_COLORS,(void **)pvBits,NULL,0);
if(*hBitmap==NULL) { ber=messNoMem; goto end;}
if(pvBits!=NULL) { if(*pvBits==NULL) { ber=6; goto end;}}
if(dxB_!=NULL) *dxB_=dxB;

end: DeleteInfoBMP(&BMInfo); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Получение ширины изображения в байтах с учётом выравнивания по границе, кратной 4 байтам.

UINT GetSzBmp(UINT Width,BYTE BitCount)
{
if(BitCount==0) return 0; if(Width>(UINT_MAX-31)/BitCount) return 0;
return (((Width*(UINT)BitCount)+31)&~31)>>3;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа бит на пиксел.

BYTE GetBitPerPix(BYTE typ,BYTE *BitCount)
{
if(BitCount==NULL) return 1;

switch(typ) { default: return 2;
case typBmp_32: *BitCount=32; break; // 32 бита.
case typBmp_24: *BitCount=24; break; // True Color.
case typBmp_16: *BitCount=16; break; // 16 бит.
case typBmp_8: *BitCount=8; break; // 8 бит (256 цветов).
case typBmp_4: *BitCount=4; break; // 4 бит (16 цветов).
case typBmp_1: *BitCount=1; break; // 1 бит (монохромное изображение).
}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение типа битового изображения.

BYTE GetTypBMP(BYTE *typ,BYTE BitCount)
{
if(typ==NULL) return 1;
switch(BitCount) { default: return 2;
case 1: *typ=typBmp_1; break;
case 4: *typ=typBmp_4; break;
case 8: *typ=typBmp_8; break;
case 16: *typ=typBmp_16; break;
case 24: *typ=typBmp_24; break;
case 32: *typ=typBmp_32; break;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение размера изображения.

BYTE GetLSizeBMP(HBITMAP hbm,long *dx,long *dy)
{
BYTE k,ber; int n; long *lp,*dp; BITMAP *BmpInf;

if(hbm==NULL) return 1; BmpInf=NULL; ber=0;
BmpInf=new BITMAP; if(BmpInf==NULL) { ber=2; goto end;}
n=(int)sizeof(BITMAP); if(GetObject(hbm,n,(LPVOID)BmpInf)!=n) { ber=3; goto end;}

for(k=0;k<2;k++) {
switch(k) { default: continue;
case 0: dp=dx; lp=&BmpInf->bmWidth; break;
case 1: dp=dy; lp=&BmpInf->bmHeight; break;}
if(*lp<=0) { ber=4; goto end;} if(dp!=NULL) *dp=*lp;}

end: SAFE_DELETE(BmpInf); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение сдвига объекта по горизонтали исходя из относительного положения точки привязки.

int GetRelPosH(BYTE posH,int dx)
{
switch(posH) { default: return 0;
case posH_Left: return 0;
case posH_Center: return dx/2;
case posH_Right: return dx;}
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение сдвига объекта по вертикали исходя из относительного положения точки привязки.

int GetRelPosV(BYTE posV,int dy)
{
switch(posV) { default: return 0;
case posV_Top: return 0;
case posV_Center: return dy/2;
case posV_Bottom: return dy;}
}

//-----------------------------------------------------------------------------------------------------------
// Чтение изображения 'DIB' из файла.

BYTE ReadDIB_FN(char *FileName,HBITMAP *hBitmap,BYTE *BitCount,SHRT *dx,SHRT *dy,BYTE **BytesDIB,DWORD **NCol,
SHRT *nCol)
{
BYTE ReadDIB_FH(HANDLE File,HBITMAP *hBitmap,BYTE *BitCount,SHRT *dx,SHRT *dy,BYTE **BytesDIB,DWORD **NCol,
  SHRT *nCol); // Загрузка изображения 'DIB' из файла.

BYTE ber; HANDLE File;

if(IsOKStr(FileName)!=0) return 1; if(hBitmap==NULL) return 2; SAFE_DELETE(*hBitmap);
File=INVALID_HANDLE_VALUE; ber=0;
File=OpenHandleFile_(FileName,0); if(File==INVALID_HANDLE_VALUE) { ber=messRet; goto end;}
if(ReadDIB_FH(File,hBitmap,BitCount,dx,dy,BytesDIB,NCol,nCol)!=0) { ber=3; goto end;} // Загрузка изображения 'DIB' из файла.
end: CloseHandleFile_(&File); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение изображения 'DIB' из файла.

BYTE ReadDIB_FH(HANDLE File,HBITMAP *hBitmap,BYTE *BitCount,SHRT *dx,SHRT *dy,BYTE **BytesDIB,DWORD **NCol,
SHRT *nCol)
{
BYTE ReadFile_(HANDLE File,LPVOID Buf,DWORD len); // Чтение файла.
void DeleteInfoBMP(BITMAPINFO **BMInfo); // Удаление заголовка файла с изображением 'DIB'.
BYTE GetColArrRGBQuad(DWORD *NCol,SHRT nCol,RGBQUAD *RGBCol); // Получение массива цветов.

BYTE ber; WORD bitC; int nRGB; long *lp; DWORD sizeBMI,sizeRGB,sizeBFH,ln; void *pvBits,*pvBits_;
BITMAPFILEHEADER *Header; BITMAPINFOHEADER *Info; BITMAPINFO *BMInfo;

if(File==INVALID_HANDLE_VALUE) return 1; if(hBitmap==NULL) return 2; SAFE_DELETE(*hBitmap);
if(BytesDIB!=NULL) *BytesDIB=NULL;
if(nCol!=NULL) *nCol=0; FreeDWORD(NCol);

sizeBMI=(DWORD)sizeof(BITMAPINFOHEADER);
sizeRGB=(DWORD)sizeof(RGBQUAD);
sizeBFH=(DWORD)sizeof(BITMAPFILEHEADER);

pvBits=NULL; BMInfo=NULL; Header=NULL; Info=NULL; ber=0;
Header=new BITMAPFILEHEADER; if(Header==NULL) { ber=3; goto end;}
Info=new BITMAPINFOHEADER; if(Info==NULL) { ber=4; goto end;}

if(ReadFile_(File,(LPVOID)Header,sizeBFH)!=0) { ber=5; goto end;}
if(ReadFile_(File,(LPVOID)Info,sizeBMI)!=0) { ber=6; goto end;}

bitC=Info->biBitCount; if(bitC!=24&&bitC!=16&&bitC!=8&&bitC!=4&&bitC!=1) { ber=7; goto end;}
if(BitCount!=NULL) *BitCount=(BYTE)bitC;
lp=&Info->biWidth; if(*lp<=0||*lp>SHRT_MAX) { ber=8; goto end;} if(dx!=NULL) *dx=(SHRT)*lp;
lp=&Info->biHeight; if(*lp<=0||*lp>SHRT_MAX) { ber=9; goto end;} if(dy!=NULL) *dy=(SHRT)*lp;

if(Info->biClrUsed!=0) nRGB=(int)Info->biClrUsed; else { if(bitC!=24) nRGB=1<<bitC; else nRGB=0;}

ln=sizeBMI+(DWORD)nRGB*sizeRGB;
BMInfo=(BITMAPINFO *)malloc((size_t)ln); if(BMInfo==NULL) { ber=10; goto end;}
memcpy((void *)&BMInfo->bmiHeader,(void *)Info,(size_t)sizeBMI);
if(nRGB>0) {
if(ReadFile_(File,(LPVOID)&BMInfo->bmiColors[0],(DWORD)nRGB*sizeRGB)!=0) { ber=11; goto end;}
if(nCol!=NULL&&NCol!=NULL) { if(nRGB>SHRT_MAX) { ber=12; goto end;} *nCol=(SHRT)nRGB;
if(AllocDWORD(NCol,(size_t)nRGB)!=0) { ber=13; goto end;}
if(GetColArrRGBQuad(*NCol,(SHRT)nRGB,&BMInfo->bmiColors[0])!=0) { ber=14; goto end;}} // Установка массива цветов.
}

ln=(DWORD)Header->bfSize-(sizeBFH+sizeBMI+(DWORD)nRGB*sizeRGB);
pvBits=malloc((size_t)ln); if(pvBits==NULL) { ber=15; goto end;}
if(ReadFile_(File,(LPVOID)pvBits,ln)!=0) { ber=16; goto end;}

*hBitmap=CreateDIBSection(NULL,BMInfo,DIB_RGB_COLORS,&pvBits_,NULL,0); if(*hBitmap==NULL) { ber=17; goto end;}
memcpy(pvBits_,pvBits,(size_t)ln); if(BytesDIB!=NULL) *BytesDIB=(BYTE *)pvBits_;

end: DeleteInfoBMP(&BMInfo); if(pvBits!=NULL) free(pvBits); SAFE_DELETE(Header); SAFE_DELETE(Info); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Запись изображения 'DIB' в файл.

BYTE WriteDIB_FN(char *FileName,BYTE Bpp,int dx,int dy,BYTE *BytesDIB,DWORD *NCol,SHRT nCol)
{
BYTE WriteDIB_FH(HANDLE File,DWORD *szFile,BYTE Bpp,int dx,int dy,BYTE *BytesDIB,DWORD *NCol,SHRT nCol); // Сохранение изображения 'DIB' в файле.

BYTE ber; HANDLE File;

if(IsOKStr(FileName)!=0) return 1; if(Bpp<1&&Bpp>3) return 2; if(dx<=0||dy<=0) return 3;
if(BytesDIB==NULL) return 4;
if(Bpp==1) { if(NCol==NULL) return 5; if(nCol<=0||nCol>256) return 6;}
File=INVALID_HANDLE_VALUE; ber=0;
File=OpenHandleFile_(FileName,1); if(File==INVALID_HANDLE_VALUE) { ber=messRet; goto end;}
if(WriteDIB_FH(File,NULL,Bpp,dx,dy,BytesDIB,NCol,nCol)!=0) { ber=7; goto end;} // Сохранение изображения 'DIB' в файле.
end: CloseHandleFile_(&File); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Запись изображения 'DIB' в файл.

BYTE WriteDIB_FH(HANDLE File,DWORD *szFile,BYTE Bpp,int dx,int dy,BYTE *BytesDIB,DWORD *NCol,SHRT nCol)
{
BYTE GetTypBMP(BYTE *typ,BYTE BitCount); // Получение типа битового изображения.
UINT GetSzBmp(UINT Width,BYTE BitCount); // Получение ширины изображения в байтах с учётом выравнивания по границе, кратной 4 байтам.
BYTE CreateHeaderBMP(BITMAPINFOHEADER *Info,int dx,int dy,BYTE typ,SHRT nCol); // Создание заголовка файла с изображением 'DIB'.
long SeekFile(HANDLE File,long offs,DWORD MoveMethod); // Позиционирование внутри файла.
BYTE WriteFile_(HANDLE File,LPVOID Buf,DWORD len); // Запись в файл.

BYTE typBmp,bm,ber; SHRT i; UINT dxB; DWORD lon,len,dw,Col; long offs,offsI; BITMAPFILEHEADER *Header;
BITMAPINFOHEADER *Info; RGBQUAD rgb;

if(File==INVALID_HANDLE_VALUE) return 1; if(dx<=0||dy<=0) return 2; if(BytesDIB==NULL) return 3;
if(GetTypBMP(&typBmp,Bpp*8)!=0) return 4;
if(typBmp==typBmp_8) { if(NCol==NULL) return 5; if(nCol<=0||nCol>256) return 6;}
dxB=GetSzBmp((UINT)dx,8*Bpp); if(dxB==0) return 7;

offsI=SeekFile(File,0L,FILE_CURRENT); if(offsI<0) return 8;

Info=NULL; Header=NULL; ber=0;
Info=new BITMAPINFOHEADER; if(Info==NULL) { ber=9; goto end;}
Header=new BITMAPFILEHEADER; if(Header==NULL) { ber=10; goto end;}

if(CreateHeaderBMP(Info,dx,dy,typBmp,nCol)!=0) { ber=11; goto end;}

Header->bfType='M'*256+'B'; Header->bfReserved1=Header->bfReserved2=0;
Header->bfOffBits=(DWORD)sizeof(BITMAPFILEHEADER)+(DWORD)sizeof(BITMAPINFOHEADER)+
(DWORD)sizeof(DWORD)*(DWORD)Info->biClrUsed;

len=(DWORD)dxB*(DWORD)dy;
Header->bfSize=Header->bfOffBits+len;

lon=(DWORD)sizeof(BITMAPFILEHEADER); if(WriteFile_(File,(LPVOID)Header,lon)!=0) { ber=12; goto end;}
if(szFile!=NULL) *szFile+=lon;
lon=(DWORD)sizeof(BITMAPINFOHEADER); if(WriteFile_(File,(LPVOID)Info,lon)!=0) { ber=13; goto end;}
if(szFile!=NULL) *szFile+=lon;

switch(typBmp) { default: break;
// 8 бит.
case typBmp_8: rgb.rgbReserved=0; lon=(DWORD)sizeof(rgb);
for(i=0;i<nCol;i++) { Col=NCol[i];
rgb.rgbRed=GetRValue(Col); rgb.rgbBlue=GetBValue(Col); rgb.rgbGreen=GetGValue(Col);
if(WriteFile_(File,(LPVOID)&rgb,lon)!=0) { ber=14; goto end;}
if(szFile!=NULL) *szFile+=lon;} break;

// 16 бит.
case typBmp_16: lon=(DWORD)sizeof(DWORD); bm=31;
for(i=0;i<3;i++) { dw=(DWORD)bm; dw=dw<<((2-i)*5);
if(WriteFile_(File,(LPVOID)&dw,lon)!=0) { ber=15; goto end;}
if(szFile!=NULL) *szFile+=lon;} break;}

offs=SeekFile(File,offsI+(long)Header->bfOffBits,FILE_BEGIN); if(offs<0) { ber=16; goto end;}
lon=len; if(WriteFile_(File,(LPVOID)BytesDIB,lon)!=0) { ber=17; goto end;}
if(szFile!=NULL) *szFile+=lon;

end: SAFE_DELETE(Info); SAFE_DELETE(Header); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Получение целых чисел из других типов.

//-----------------------------------------------------------------------------------------------------------
// Получение числа 'BYTE' из числа 'float' с проверкой выхода за пределы 'BYTE'.

BYTE GetBYTE(float v)
{
float w;

if(v<=0.0F) return 0; w=v+0.5F; if(w>=(float)UCHAR_MAX) return UCHAR_MAX; return (BYTE)w;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа 'SHRT' из числа 'float' с проверкой выхода за пределы 'SHRT'.

SHRT GetSHRT_Test(float v)
{
float w;

if(v>=0.0F) w=v+0.5F; else w=v-0.5F;
if(w>=(float)SHRT_MAX) return SHRT_MAX-1; if(w<(float)(SHRT_MIN+1)) return SHRT_MIN+1; return (SHRT)w;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа 'USHRT' из числа 'int' с проверкой выхода за пределы 'USHRT'.

USHRT GetUSHRT_Test(int iv)
{
if(iv<0) return 0; if(iv>=USHRT_MAX) return USHRT_MAX; return (USHRT)iv;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа 'USHRT' из числа 'float' с проверкой выхода за пределы 'USHRT'.

USHRT GetUSHRT_Test(float v)
{
float w;

if(v<=0.0F) return 0; w=v+0.5F; if(w>=(float)USHRT_MAX) return USHRT_MAX; return (USHRT)w;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа 'USHRT' из числа 'double' с проверкой выхода за пределы 'USHRT'.

USHRT GetUSHRT_Test(double d)
{
double w;

if(d<=0.) return 0; w=d+0.5; if(w>=(double)USHRT_MAX) return USHRT_MAX; return (USHRT)w;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа 'int' из числа 'float' с проверкой выхода за пределы 'int'.

int GetIntTest(float v)
{
float w; int iM;

if(v>=0.0F) w=v+0.5F; else w=v-0.5F; iM=INT_MAX;
if(w>=(float)iM) return iM; if(w<=-(float)iM) return -iM; return (int)w;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа 'int' из числа 'double' с проверкой выхода за пределы 'int'.

int GetIntTest(double v)
{
double w; int iM;

if(v>=0.0) w=v+0.5; else w=v-0.5; iM=INT_MAX;
if(w>=(double)iM) return iM; if(w<=-(double)iM) return -iM; return (int)w;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа 'UINT' из числа 'float' с проверкой выхода за пределы 'UINT'.

UINT GetUINT_Test(float v)
{
float w;

if(v<=0.0F) return 0; w=v+0.5F; if(w>=(float)UINT_MAX) return UINT_MAX; return (UINT)w;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа 'UINT' из числа 'double' с проверкой выхода за пределы 'UINT'.

UINT GetUINT_Test(double d)
{
double w;

if(d<=0.0F) return 0; w=d+0.5F; if(w>=(double)UINT_MAX) return UINT_MAX; return (UINT)w;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Разное.

//-----------------------------------------------------------------------------------------------------------
// Установка бита в числе 'BYTE'.

void SetBit(BYTE *bp,BYTE num,BYTE b)
{
BYTE fl;

if(bp==NULL) return; if(num>=8) return; fl=1; fl=fl<<num; if(b!=0) *bp|=fl; else *bp&=~fl;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка прямоугольника.

BYTE IsOKRect(RECT *rc)
{
if(rc==NULL) return 1; if(rc->right<=rc->left) return 2; if(rc->bottom<=rc->top) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Опрос очереди сообщений и обработка сообщений.

void ProcMess(void)
{
MSG msg;

while(PeekMessage(&msg,NULL,0U,0U,PM_REMOVE)) { TranslateMessage(&msg); DispatchMessage(&msg);}
}

//-----------------------------------------------------------------------------------------------------------
// Звук при заблокированном действии.

void SoundBlock(void)
{
MessageBeep(MB_ICONHAND);
}

//-----------------------------------------------------------------------------------------------------------
// Проверка цвета - светлый или тёмный.

BYTE IsColLight(DWORD Col)
{
BYTE GetColComp(COLORREF Col,BYTE *CC); // Получение компонент цвета.

BYTE i,CC[3],max;

if(GetColComp((COLORREF)Col,CC)!=0) return 0;
max=0; for(i=0;i<3;i++) max=MAX(CC[i],max); if(max>=190) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение случайного числа от 0 до nMax-1.

UINT GetRandNum(UINT nMax)
{
UINT u;

if(nMax==0) return 0; u=(UINT)((double)rand()/(double)RAND_MAX*(double)nMax); if(u>=nMax) u=nMax-1; return u;
}

//-----------------------------------------------------------------------------------------------------------
// Случайная перетасовка порядка номеров в массиве.

BYTE RandomizeArr(UINT *NumArr,UINT nNumArr,BYTE nCycles)
{
UINT GetRandNum(UINT nMax); // Получение случайного числа от 0 до nMax-1.

BYTE c; UINT i,j,n;

if(NumArr==NULL) return 1; if(nNumArr==0) return 2; if(nCycles==0) return 3;
for(c=0;c<nCycles;c++) for(i=0;i<nNumArr;i++) { j=GetRandNum(nNumArr); if(j==i) continue;
n=NumArr[j]; NumArr[j]=NumArr[i]; NumArr[i]=n;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проводит попытку перепрыгнуть через "потенциальный" барьер высотой 'U'.

BYTE AttemptJump(float U)
{
if(U<=0.0F) return 0; if(U>IPE_MAX) return 0; if(rand()<GetIntTest((double)RAND_MAX/exp((double)U))) return 0;
return 1;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Сообщения.

//-----------------------------------------------------------------------------------------------------------
// Выдача сообщения об ошибке.

void ErrMessage(void)
{
LPVOID lpMsgBuf;

FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,
NULL,GetLastError(),MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),(LPTSTR)&lpMsgBuf,0,NULL);
MessageBox(NULL,(LPCTSTR)lpMsgBuf,"Error",MB_IN); LocalFree(lpMsgBuf);
}

//-----------------------------------------------------------------------------------------------------------
// Вывод сообщения.

void Message(UINT StrID,UINT typ)
{
if(hInst==NULL) return; if(LoadString(hInst,StrID,TxtMem,strL_Txt)==0) return; MessageBox(NULL,TxtMem,"",typ);
}

//-----------------------------------------------------------------------------------------------------------
// Вывод сообщения.

void Message_(HWND hwnd,UINT StrID,char *txt,UINT typ)
{
if(hInst==NULL) return; if(LoadString(hInst,StrID,TxtMem,strL_Txt)==0) return;
if(txt!=NULL) MessageBox(hwnd,txt,TxtMem,typ); else MessageBox(hwnd,TxtMem,"",typ);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Отдельные сообщения.

//-----------------------------------------------------------------------------------------------------------
// Вопрос о перезаписи при наличии файла с данным именем.

BYTE MessQuestFileOverWrite(char *fName)
{
BYTE be; char *cp; size_t ln;

if(hInst==NULL) return 1; if(LoadString(hInst,IDS_Quest_FileExists,TxtMem,strL_Txt)==0) return 2;
ln=strlen(fName); ln+=strlen(TxtMem)+2; cp=NULL; if(AllocString(&cp,ln)!=0) return 3;
strcpy(cp,fName); strcat(cp,"\n"); strcat(cp,TxtMem);
be=MessageBox(NULL,cp,"",MB_QU); FreeString(&cp); if(be==IDYES) return messRet; return 0;
}
