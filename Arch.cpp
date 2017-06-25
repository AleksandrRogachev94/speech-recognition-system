//mmm
sprintf(TxtStr,"be: %d",be); MessageBox(NULL,TxtStr,"",MB_EX);

//-----------------------------------------------------------------------------
// Рисование в главном окне. 

BYTE OnPaint(HDC hdc,HWND hwnd)
{
BYTE CrSelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP,DWORD Col); // Создание и выбор кисти.
void UnSelDelBrush(HDC hdc,HBRUSH hBrush,HBRUSH hBrushP); // Освобождение и удаление кисти.
void DrawLine_(HDC hdc,int xI,int yI,int xF,int yF); // Рисование линии.

HBRUSH hBrush,hBrushP; RECT rc;

if(hdc==NULL) return 1; if(hwnd==NULL) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3;
hBrush=hBrushP=NULL;
if(CrSelBrush(hdc,&hBrush,&hBrushP,RGB(255,0,0))!=0) return 4; // Создание и выбор кисти.
DrawLine_(hdc,(int)rc.left,(int)rc.top,(int)rc.right,(int)rc.bottom);
Ellipse(hdc,100,100,500,400);
UnSelDelBrush(hdc,hBrush,hBrushP); // Освобождение и удаление кисти.
return 0;
}



//-------------------------------------------------
// Чтение из файла.

BYTE strParam::Read(char *fName)
{
BYTE err; FILE *file;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
file=NULL; err=0;
file=fopen(fName,"rt");
if(file=0) { err=3; goto end;}
if(fscanf(file,"%f",&Time_Width)==EOF) { err=4; goto end;}
end: if(file!=NULL) fclose(file); return err;
}

//-------------------------------------------------
// Сохранение в файле.

BYTE strParam::Write(char *fName)
{
BYTE err; FILE *file;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
file=NULL; err=0;
file=fopen(fName,"wt");
if(file=0) { err=3; goto end;}
if(fprintf(file,"%f\n",Time_Width)<0) { err=4; goto end;}
end: if(file!=NULL) fclose(file); return err;
}

//-----------------------------------------------------------------------------
// Расчёт диаграммы.

BYTE clMain::ComputeDiag(void)
{
int i,j;

if(sz_Time==0||sz_Freq==0) return 1;
if(sz_Time>szTimeMax||sz_Freq>szFreqMax) return 2;
for(i=0;i<sz_Time;i++) for(j=0;j<sz_Freq;j++) Diag[i][j]=0.0F;

/*for(i=0; i<=20; i=i+1) for(j=0; j<sz_Freq; j=j+1)   Diag[i][j]=150; 

for(i=20; i<=40; i=i+1) for(j=0; j<sz_Freq; j=j+1)  Diag[i][j]=300; 

for(i=40; i<=60; i=i+1) for(j=0; j<sz_Freq; j=j+1)  Diag[i][j]=200; 

for(i=61; i<sz_Time; i=i+1) for(j=20; j<40; j=j+1)  Diag[i][j]=25;*/
for(i=0; i<sz_Time; ++i) for(j=0; j<sz_Freq; ++j) Diag[i][j]=(BYTE)rand(); 
return 0;
}

sz_Time=1000; sz_Freq=512;

//BmpDiag->Image(hdc,0,0,dx,dy,0,0,BmpDiag->dx,BmpDiag->dy,1); // Вывод изображения.

if(be!=0) {
//mmm
sprintf(TxtStr,"be: %d pScDiagH,pScDiagV,BmpDiag->dy,dy,: %d %d %d %d %d",be,pScDiagH,pScDiagV,BmpDiag->dy,dy,BmpDiag->dy-dy-pScDiagV);
DrawText(hdc,TxtStr,strlen(TxtStr),&rc,DT_SINGLELINE|DT_VCENTER|DT_CENTER);
}

// WM_LBUTTONDOWN ...........................................................................................
case WM_LBUTTONDOWN: { *flag=1;
	break;}

// WM_RBUTTONDOWN ...........................................................................................
case WM_RBUTTONDOWN: *flag=1; break;

// Рисование курсора при выводе звука и перерисовка графика спектра.
if(flPlaySound!=0&&sz_Time>0&&Snd.dt>0.0F) {
x=KoordTime=GetIntTest((float)Snd.dt/Param.Time_Step*(float)PosCurSnd);

hd=GetDC(hwndGraphSpectr);
OnPaintGraphSpectr(hd);
ReleaseDC(hwndGraphSpectr,hd);
UpdateWindow(hwndGraphSpectr);

if(x<pScDiagH||x>=pScDiagH+dx) goto endCurSnd; x-=pScDiagH;
hPen=hPenP=NULL;
CrSelPen(hdc,&hPen,&hPenP,1,COL_LT_GRAY);
MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dyW);
UnSelDelPen(hdc,&hPen,&hPenP);
hd=GetDC(hwndGraphSpectr);
OnPaintGraphSpectr(hd);
ReleaseDC(hwndGraphSpectr,hd);
UpdateWindow(hwndGraphSpectr);
endCurSnd:;}

/*//xxx
//-----------------------------------------------------------------------------------------------------------
//Обработка сообщений диалоговоо окна просмотора и редактирования параметров элементов базы данных.

BYTE strDBSArr::MsgCommandDBT(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
int num; HWND hwnd;

if(flag==NULL) return 0L; *flag=0; if(hDlg==NULL) return 0L; if(msg==WM_INITDIALOG) return 0L;

switch(msg) { default: break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND:

switch(LOWORD(wParam)) {

// IDC_DBS ..................................................................................................
case IDC_DBS: if(HIWORD(wParam)!=LBN_SELCHANGE) break;
hwnd=GetDlgItem(hDlg,IDC_DBS); if(hwnd==NULL) break;
num=SendMessage(hwnd,LB_GETCURSEL,0,0); if(num==LB_ERR) break;
if(IsOK()!=0) break; if(num>=n) break;

break;
}

break;
}

return 0L;
}*/

//-----------------------------------------------------------------------------------------------------------
// Пролистывание окна диаграммы по горизонтали.

BYTE clMain::HScrollDiag(WPARAM wParam)
{
int p;

if(hwndDiag==NULL) return 1;
//xxx
(int)LOWORD(wParam)
BYTE ScrollFun32(HWND hwnd,int nScroll,BYTE Dir,BYTE Cntrl,int *p,int nScrl,int nScrlP); // Обработка сообщений от полосы прокрутки.

p=pScDiagH; if(ScrollFunS(wParam,&p,0,pMScDiagH,VelScrlPos,AccScrlPos)!=0) return 2; if(p==pScDiagH) return 3;
pScDiagH=p; SetScrollPos(hwndDiag,SB_HORZ,pScDiagH,TRUE); ProcMess(); UpdateWindow_(hwndDiag); ProcMess(); return 0;
}

//yyy
//if(BmpDiag->Image(hdc,0,0,dxW,dyW,0,0,BmpDiag->dx,BmpDiag->dy,1)!=0) return 8; // Вывод изображения.

//Изменение страницы графика сигнала.

case IDC_PGRIGHT: *flag=1;
GetClientRect(hwndGraph,&rc);
dy=rc.right-rc.left;
ShGr=ShGr+dy;
UpdateWindow_(hwndGraph); break;

case IDC_PGLEFT: *flag=1;
GetClientRect(hwndGraph,&rc);
dy=rc.right-rc.left;
ShGr=ShGr-dy;
UpdateWindow_(hwndGraph); break;

//-----------------------------------------------------------------------------------------------------------
// Печать результатов распознавания методом нейронных сетей.

void clMain::PrintResNNW(void)
{
BYTE i;

//yyy
sprintf(TxtStr,"%d",ResNNW[KoordTime]);
MessageBox(NULL,TxtStr,"Number of Peaks",MB_IN);

strcpy(TxtMem,"");
for(i=0;i<nNeuronsInp;i++) {
sprintf(TxtStr,"i,Val: %d %f  ",i,InpLay[KoordTime][i]); strcat(TxtMem,TxtStr);
if((i+1)%5==0) { MessageBox(NULL,TxtMem,"InputLayer",MB_IN); strcpy(TxtMem,"");}
}

}

// Рисование курсора при выводе звука и перерисовка графика спектра.
if(flPlaySound!=0&&sz_Time>0&&Snd.dt>0.0F) {
//xxx
x=KoordTime=GetIntTest((float)Snd.dt/Param.Time_Step*(float)PosCurSnd);

hd=GetDC(hwndGraphSpectr);
OnPaintGraphSpectr(hd);
ReleaseDC(hwndGraphSpectr,hd);
UpdateWindow(hwndGraphSpectr);

if(x<pScDiagH||x>=pScDiagH+dx) goto endCurSnd; x-=pScDiagH;
hPen=hPenP=NULL;
/*CrSelPen(hdc,&hPen,&hPenP,1,COL_LT_GRAY);
MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dyW);
UnSelDelPen(hdc,&hPen,&hPenP); */
hd=GetDC(hwndGraphSpectr);
OnPaintGraphSpectr(hd);
ReleaseDC(hwndGraphSpectr,hd);
UpdateWindow(hwndGraphSpectr);
endCurSnd:;}

//xxx GetFlEdt(hDlg,IDC_AMPL3,&(MW->AmpSpect));

//-----------------------------------------------------------------------------------------------------------
// Рисование в главном окне. 

BYTE clMain::OnPaint(HDC hdc)
{
BYTE CrSelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP,DWORD Col); // Создание и выбор кисти.
void UnSelDelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP); // Освобождение и удаление кисти.
void DrawLine_(HDC hdc,int xI,int yI,int xF,int yF); // Рисование линии.

HBRUSH hBrush,hBrushP;

if(hdc==NULL) return 1; if(hwnd==NULL) return 2;
if(GetClientRect(hwnd,&rc)==FALSE) return 3;
hBrush=hBrushP=NULL;
if(CrSelBrush(hdc,&hBrush,&hBrushP,RGB(255,0,0))!=0) return 4; // Создание и выбор кисти.
UnSelDelBrush(hdc,&hBrush,&hBrushP); // Освобождение и удаление кисти. 
return 0;
}
WS_OVERLAPPEDWINDOW

//xxx yyy
// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK .....................................................................................................
case IDOK: EndDialog(hDlg,1); if(DBFA!=NULL) DBFA->OnCloseDlg(); return (INT_PTR)TRUE;

// IDCANCEL .................................................................................................
case IDCANCEL: EndDialog(hDlg,0); if(DBFA!=NULL) DBFA->OnCloseDlg(); return (INT_PTR)TRUE;
}
break;

int id; HDC hdc;

// WM_CTLCOLORSTATIC ........................................................................................
case WM_CTLCOLORSTATIC: hdc=(HDC)wParam; id=GetDlgCtrlID((HWND)lParam); if(id<=0) break; *flag=1;
SetBkColor(hdc,GetSysColor(COLOR_WINDOW)); SetTextColor(hdc,GetSysColor(COLOR_BTNTEXT));
SetBkMode(hdc,TRANSPARENT);
//xxx
return (LRESULT)hBrushDial;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структуры параметров слоя.

#define nNeurons_1 10 // Число нейронов в первом скрытом слое.

struct strParLay ParLayers[nLayersNNW]={ 
{nNeurons_1,TypFunAct_Sigm},
{nVoices,TypFunAct_Sigm}};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров нейронной сети.

struct strParNNW ParNNW={ nLayersNNW,ParLayers};

srand(RandSeq); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();

ErrMin=LrgCnst12; NRand=0;
for(i=0;i<nStepsRand;i++) { NR=NumRandArr[i];
if(InitRandom(NR,CoeWei,CoeTe)!=0) { ber=7; goto end;}

CheckRadioButton(hDlg,IDC_RADIO_AMP,IDC_RADIO_SIN,IDC_RADIO_AMP+(int)typResSpectr);

// IDC_RADIO_AMP IDC_RADIO_COS IDC_RADIO_SIN ................................................................
case IDC_RADIO_AMP: case IDC_RADIO_COS: case IDC_RADIO_SIN: SelectTypResDiag(id); break;

//-----------------------------------------------------------------------------------------------------------
// Выбор типа выводимого результата в виде диаграммы.

void clMain::SelectTypResDiag(int id)
{
BYTE typ;

switch(id) { default: return;
case IDC_RADIO_AMP: typ=typResSpectr_Amp; break;
case IDC_RADIO_COS: typ=typResSpectr_AmpCos; break;
case IDC_RADIO_SIN: typ=typResSpectr_AmpSin; break;}
if(typ==typResSpectr) return; typResSpectr=typ; DrawDiag(); UpdateWinDiag(); UpdateWindow_(hwndGraphSpectr);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы выводимых результатов спектральной обработки в виде диаграммы.

#define typResSpectr_Amp    0 // Амплитуда спектра.
#define typResSpectr_AmpCos 1 // Амплитуда спектра, умноженная на косинус фазы.
#define typResSpectr_AmpSin 2 // Амплитуда спектра, умноженная на синус фазы.

// Выбор типа выводимого результата в виде диаграммы.
switch(typResSpectr) { default:
case typResSpectr_Amp: pSpArr=&SpectrAmp; break; // Амплитуда спектра.
case typResSpectr_AmpCos: pSpArr=&SpectrReal; break; // Амплитуда спектра, умноженная на косинус фазы.
case typResSpectr_AmpSin: pSpArr=&SpectrImag; break; // Амплитуда спектра, умноженная на синус фазы.
}

pSpArr=&SpectrAmp;
// Выбор типа палитры.
if(typResSpectr==typResSpectr_Amp) pPal=&PalPos; else pPal=&PalSign;

if(typResSpectr==typResSpectr_Amp) {
if(v>=1.0F) nC=nColSmoothPal-1; else if(v<=0.0F) nC=0; else nC=(BYTE)((float)(nColSmoothPal-1)*v);}
else { nCv=(nColSmoothPal-1)/2;
if(v>=1.0F) nC=nColSmoothPal-1; else if(v<=-1.0F) nC=0; else nC=GetBYTE((float)nCv*v+(float)nCv);}

// Выбор типа выводимого результата.
switch(typResSpectr) { default:
case typResSpectr_Amp: pRes=SpectrAmp[KoordTime]; break; // Амплитуда спектра.
case typResSpectr_AmpCos: pRes=SpectrReal[KoordTime]; break; // Амплитуда спектра, умноженная на косинус фазы.
case typResSpectr_AmpSin: pRes=SpectrImag[KoordTime]; break; // Амплитуда спектра, умноженная на синус фазы.
}
SpectrReal[szTimeMax][szFreqMax],SpectrImag[szTimeMax][szFreqMax],
for(n=0;n<nPh;n++) SpectrReal[i][n]=(float)real(B[n]);
for(n=0;n<nPh;n++) SpectrImag[i][n]=(float)imag(B[n]);

/*// IDC_ADAPTIVE_STEP ........................................................................................
case IDC_ADAPTIVE_STEP: GetChBox(hDlg,IDC_FILE_TRAIN,&flC);
if(flC==1) { EnableChWin(hDlg,IDC_STEP_TRAIN,1); EnableChWin(hDlg,IDC_ASTEP_MAX,0);}
else { EnableChWin(hDlg,IDC_STEP_TRAIN,0); EnableChWin(hDlg,IDC_ASTEP_MAX,1);}*/



//vvv xxx mmm
cntTrain++;
//vvv mmm xxx
//mmm

if(cntTrain%1000==0) {
sprintf(TxtStr,"i,j,Wei %d %d %e",i,j,pNeur->Weight[i]);
//mmm
MessageBox(NULL,TxtStr,"",MB_EX);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы для параметров выделения спектральных линий.

#define coeSmPeaks_Stand 0.1F // Уровень малых пиков, которые отбрасываются.
#define coePeaks_Stand 0.5F // Уровень, по которому идёт первоначальный отбор пиков.
#define FreqMin_Stand 60.0F // Минимальная частота основной гармоники (Гц).
#define FreqMax_Stand 5000.0F // Максимальная частота, до которой проводится анализ (Гц).
#define ErrFreq_Stand 0.15F // Максимальная ошибка при отбраковке пиков по частоте.
#define widPeaks_Stand 30.0F // Полуширина пиков (Гц).
#define LevPowPeak_Stand 0.3F // Минимальный уровень мощности, который должен содержаться в пиках.
#define coePeaksCorrFreq_Stand 0.3F // Амплитуда линий, по которым проводится коррекция частоты.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров нахождения спектральных линий.

struct strParGetPeaks {

BYTE flCorrFreq; float coeSmPeaks,coePeaks,FreqMin,FreqMax,ErrFreq,widPeaks,LevPowPeak,coePeaksCorrFreq;

strParGetPeaks(void); // Конструктор.
void Init(void); // Инициализация.
BYTE IsOK(void); // Проверки.
USHRT Check(void); // Проверки и коррекция.
BYTE Read_(FILE *file); // Чтение из файла.
BYTE Read(char *Path,char *fName); // Чтение из файла.
BYTE Write_(FILE *file); // Запись в файл.
BYTE Write(char *Path,char *fName); // Запись в файл.
BYTE SetDlg(HWND hDlg); // Установка в диалоговое окно.
BYTE GetDlg(HWND hDlg); // Получение из диалогового окна.
void OnCreateDlg(HWND hDlg); // Действия при открытии диалогового окна.
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров нахождения спектральных линий.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strParGetPeaks::strParGetPeaks(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

void strParGetPeaks::Init(void)
{
coeSmPeaks=coeSmPeaks_Stand; coePeaks=coePeaks_Stand; FreqMin=FreqMin_Stand; FreqMax=FreqMax_Stand;
ErrFreq=ErrFreq_Stand; widPeaks=widPeaks_Stand; LevPowPeak=LevPowPeak_Stand;
coePeaksCorrFreq=coePeaksCorrFreq_Stand; flCorrFreq=1;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParGetPeaks::IsOK(void)
{
if(coeSmPeaks<=0.0F) return 1; if(coePeaks<=0.0F) return 2;
if(FreqMin<=0.0F) return 3; if(FreqMax<=0.0F) return 4; if(FreqMin>=FreqMax) return 5;
if(ErrFreq<=0.0F) return 6; if(widPeaks<=0.0F) return 7; if(LevPowPeak<=0.0F) return 8;
if(coePeaksCorrFreq<=0.0F) return 9; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки и коррекция.

USHRT strParGetPeaks::Check(void)
{
USHRT fl; float *fp;

fl=0;
fp=&coeSmPeaks; if(*fp<=0.0F) { *fp=coeSmPeaks_Stand; fl+=1<<0;}
fp=&coePeaks; if(coePeaks<=0.0F) { *fp=coePeaks_Stand; fl+=1<<1;}
fp=&FreqMin; if(*fp<=0.0F) { FreqMin=FreqMin_Stand; fl+=1<<2;}
fp=&FreqMax; if(*fp<=0.0F) { FreqMax=FreqMax_Stand; fl+=1<<3;}
if(FreqMin>=FreqMax) { FreqMin=FreqMin_Stand; FreqMax=FreqMax_Stand; fl+=1<<4;}
fp=&ErrFreq; if(*fp<=0.0F) { *fp=ErrFreq_Stand; fl+=1<<5;}
fp=&widPeaks; if(*fp<=0.0F) { *fp=widPeaks_Stand; fl+=1<<6;}
fp=&LevPowPeak; if(*fp<=0.0F) { *fp=LevPowPeak_Stand; fl+=1<<7;}
fp=&coePeaksCorrFreq; if(*fp<=0.0F) { *fp=coePeaksCorrFreq_Stand; fl+=1<<8;}
return fl;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParGetPeaks::Read_(FILE *file)
{
int iv;

if(file==NULL) return 1;
if(fscanf(file,"%f%f%f%f%f%f%f%d%f",&coeSmPeaks,&coePeaks,&FreqMin,&FreqMax,&ErrFreq,&widPeaks,&LevPowPeak,
&iv,&coePeaksCorrFreq)==EOF) return 2;
if(iv==0) flCorrFreq=0; else flCorrFreq=1;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParGetPeaks::Read(char *Path,char *fName)
{
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // Получение имени файла включая путь.

BYTE err; char *name; clFileT *FT;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
FT=NULL; name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,NULL)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,0)!=0) { err=5; goto end;} 
if(Read_(FT->file)!=0) { err=6; goto end;}
Check(); // Проверки и коррекция.
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strParGetPeaks::Write_(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%f %f %f %f %f %f %f %d %f\n",coeSmPeaks,coePeaks,FreqMin,FreqMax,ErrFreq,widPeaks,
LevPowPeak,(int)flCorrFreq,coePeaksCorrFreq)<0) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение в файле.

BYTE strParGetPeaks::Write(char *Path,char *fName)
{
BYTE err; char *name; clFileT *FT;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
FT=NULL; name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,NULL)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,1)!=0) { err=5; goto end;}
if(Write_(FT->file)!=0) { err=6; goto end;}
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Установка в диалоговое окно.

BYTE strParGetPeaks::SetDlg(HWND hDlg)
{
BYTE i; int id; float *fp; char *Form;

if(hDlg==NULL) return 1;
for(i=0;i<8;i++) {
switch(i) { default: continue;
case 0: fp=&coeSmPeaks;       id=IDC_COE_SMALL_PEAKS; Form=FormCoeff; break;
case 1: fp=&coePeaks;         id=IDC_COE_PEAKS;       Form=FormCoeff; break;
case 2: fp=&FreqMin;          id=IDC_FREQ_MIN;        Form=FormFreq; break;
case 3: fp=&FreqMax;          id=IDC_FREQ_MAX;        Form=FormFreq; break;
case 4: fp=&ErrFreq;          id=IDC_ERR_FREQ;        Form=FormCoeff; break;
case 5: fp=&widPeaks;         id=IDC_WID_PEAKS;       Form=FormFreq; break;
case 6: fp=&LevPowPeak;       id=IDC_LEV_POW_PEAKS;   Form=FormCoeff; break;
case 7: fp=&coePeaksCorrFreq; id=IDC_AMP_CORR_FREQ;   Form=FormCoeff; break;
}
SetFlEdt(hDlg,id,*fp,Form);}

SetChBox(hDlg,IDC_CORRECT_FREQ,flCorrFreq);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение из диалогового окна.

BYTE strParGetPeaks::GetDlg(HWND hDlg)
{
BYTE i; int id; float *fp;

if(hDlg==NULL) return 1;
for(i=0;i<8;i++) {
switch(i) { default: continue;
case 0: fp=&coeSmPeaks;       id=IDC_COE_SMALL_PEAKS; break;
case 1: fp=&coePeaks;         id=IDC_COE_PEAKS; break;
case 2: fp=&FreqMin;          id=IDC_FREQ_MIN; break;
case 3: fp=&FreqMax;          id=IDC_FREQ_MAX; break;
case 4: fp=&ErrFreq;          id=IDC_ERR_FREQ; break;
case 5: fp=&widPeaks;         id=IDC_WID_PEAKS; break;
case 6: fp=&LevPowPeak;       id=IDC_LEV_POW_PEAKS; break;
case 7: fp=&coePeaksCorrFreq; id=IDC_AMP_CORR_FREQ; break;
}
GetFlEdt(hDlg,id,fp);}

GetChBox(hDlg,IDC_CORRECT_FREQ,&flCorrFreq);

Check(); // Проверки и коррекция.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при открытии диалогового окна.

void strParGetPeaks::OnCreateDlg(HWND hDlg)
{
SetPosWindowCenter(hDlg); // Помещение окна в центр другого окна или экрана.
SetDlg(hDlg); // Установка в диалоговое окно.
}

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна настройки параметров выделения спектральных линий.

INT_PTR CALLBACK DlgParPeaks(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam)
{
int id;

switch(message) {

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: ParGetPeaks.OnCreateDlg(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK .....................................................................................................
case IDOK: ParGetPeaks.GetDlg(hDlg); EndDialog(hDlg,1); return (INT_PTR)TRUE;

// IDCANCEL .................................................................................................
case IDCANCEL: EndDialog(hDlg,0); return (INT_PTR)TRUE;
}
break;

}
return (INT_PTR)FALSE;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение относительных амплитуд и частот спектральных линий.

BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines)
{
BYTE GetMaxAccurate(float *Fun,float *pos,float *amp); // Более точное нахождение максимума по трём точкам: параболическая аппроксимация.

BYTE *Flags,k,err; USHRT i,iI,iF,nFrMin,nFrMax,nNeur,num; float v,S,*Sp,fr,frI,del,coeNorm;
double s,powTotal,powPeaks; struct strSpectrLine *pSpL;

if(nSpectr<=2) return 1; if(Spectr==NULL) return 2;
if(nSpLines==0) return 3; if(SpLines==NULL) return 4;
if(dFr<=0.0F) return 5;
nFrMin=GetUSHRT_Test(ParGetPeaks.FreqMin/dFr); if(nFrMin==0) return 6;
nFrMax=GetUSHRT_Test(ParGetPeaks.FreqMax/dFr); if(nFrMax==0) return 7; nFrMax=MIN(nFrMax,nSpectr);
if(nFrMax<=nFrMin) return 8;
for(k=0;k<nSpLines;k++) SpLines[k].Zero();

Flags=NULL; Sp=NULL; err=0;
Flags=new BYTE[nSpectr]; if(Flags==NULL) { err=9; goto end;}
Sp=new float[nSpectr]; if(Sp==NULL) { err=10; goto end;}

// Нормировка спектра.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;}
s/=(double)(nFrMax-nFrMin); s=SQRT(s); if(s==0.) { err=11; goto end;}
v=(float)(1./s); for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// Нахождение максимумов - спектральных линий.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(i=1;i<nSpectr-1;i++) if(Sp[i-1]<Sp[i]&&Sp[i]>Sp[i+1]) Flags[i]=1;

// Отбрасывание пиков с малой частотой.
for(i=0;i<nFrMin;i++) Flags[i]=0;

// Отбрасывание пиков с очень малой амплитудой.
for(i=1;i<nSpectr-1;i++) { if(Flags[i]==0) continue; if(Sp[i]<ParGetPeaks.coeSmPeaks) Flags[i]=0;}

// Повторная нормировка спектра после отбрасывания пиков с малой амплитудой.
s=0.; num=0; for(i=nFrMin;i<nFrMax;i++) { if(Flags[i]==0) continue; v=Spectr[i]; s+=(double)v*(double)v; num++;}
if(num==0) { err=12; goto end;}
s/=(double)num; s=SQRT(s); if(s==0.) { err=13; goto end;}
coeNorm=(float)s; v=1.0F/coeNorm; for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// Отбрасывание пиков с малой амплитудой.
for(i=1;i<nSpectr-1;i++) { if(Flags[i]==0) continue; if(Sp[i]<ParGetPeaks.coePeaks) Flags[i]=0;}

// Заполнение массива входного слоя нейронов.
nNeur=0; for(i=nFrMin;i<nFrMax;i++) { if(Flags[i]==0) continue; if(i==0) continue;
if(GetMaxAccurate(Sp+i-1,&fr,&S)!=0) { err=14; goto end;} fr+=(float)i;
if(nNeur==0) { frI=fr; pSpL=SpLines; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=frI; nNeur=1;}
else { v=fr/frI; num=GetUSHRT_Test(v); if(num<=1) { err=15; goto end;}
del=v-(float)num; if(del<0.0F) del=-del; if(del>ParGetPeaks.ErrFreq) continue;
num--; if(num>=nSpLines) break;
pSpL=SpLines+num;
if(pSpL->AmpRel==0.0F||pSpL->AmpRel!=0.0F&&pSpL->AmpRel<S) { pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr; nNeur=num+1;}}}
if(nNeur==0) { err=16; goto end;}

// Проверка, что спектр состоит из линий.
// Находим суммарную мощность.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powTotal=SQRT(s);

// Находим мощность по линиям.
v=ParGetPeaks.widPeaks/dFr; v=MIN(v,frI*0.5F);
powPeaks=0.; for(k=0;k<nSpLines;k++) { pSpL=SpLines+k; if(pSpL->AmpRel==0.0F) continue; fr=pSpL->Freq;
iI=GetUSHRT_Test(fr-v); if(iI<0) iI=0; if(iI>=nFrMax) iI=nFrMax-1;
iF=GetUSHRT_Test(fr+v); if(iF<0) iF=0; if(iF>=nFrMax) iF=nFrMax-1;
if(iI>iF) continue;
s=0.; for(i=iI;i<iF;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powPeaks+=s;}
powPeaks=SQRT(powPeaks);

if(powPeaks<powTotal*ParGetPeaks.LevPowPeak) { err=17; goto end;}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(Flags); return err;
}

//xxx zzz
#define idT_Main_MMM 3 // Таймер.
#define uT_Main_MMM 5000 // Время таймера.

//xxx zzz
SetTimer(hDlg,idT_Main_MMM,uT_Main_MMM,NULL);

//xxx zzz
if(wParam==idT_Main_MMM) { MMM();}
//-----------------------------------------------------------------------------------------------------------
// MMM.

void MMM(void)
{
HWND hwnd;

hwnd=GetForegroundWindow();
if(hwnd!=NULL) SendMessage(hwnd,WM_CLOSE,0,0L);
//mmm xxx
//sprintf(TxtStr,"ForegroundWindow: %u",(UINT)hwnd); MessageBox(NULL,TxtStr,"",MB_EX);

}

//-----------------------------------------------------------------------------------------------------------
// Созание структуры нейронной сети по структуре параметров.

BYTE CreateNNW(strParNNW *pParNNW,strNNW *pNNW)
{
BYTE i; struct strParLay *pPL; struct strLay *pLay;

if(pNNW==NULL) return 1; pNNW->Free(); if(pParNNW==NULL) return 2; if(pParNNW->IsOK()!=0) return 3;
if(pNNW->Alloc(pParNNW->nLay)!=0) return 4;
for(i=0;i<pParNNW->nLay;i++) { pPL=pParNNW->ParLay+i; pLay=pNNW->Get(i); if(pLay==NULL) return 5;
if(pLay->Alloc(pPL->nNeurons)!=0) return 6; pLay->TypFunAct=pPL->TypFunAct;}
return 0;
}
#define nLayersNNW 2 // Число слоёв скрытых + выходной.

//xxx mmm
BYTE nNeurOut;

if(pParNNW==NULL) return 1; if(pParNNW->typNNW!=typNet) return 2;
//zzz
if(pParNNW->typNNW==typNNW_Vowel) nNeurOut=nVoicesVowel; else nNeurOut=nVoicesCons;
if(pParNNW->IsOK_()!=0) return 2;
pParLay=pParNNW->Get(pParNNW->nLay-1); if(pParLay==NULL) return 3;
pParLay->nNeurons=nNeurOut;
if(CreateNNW(pNNW,pParNNW,nPeaksMax)!=0) return 5; // Инициализации нейронной сети.
DrawNet(); // Перерисовка изображения сети.

//-----------------------------------------------------------------------------------------------------------
// Установка в диалоговое окно.

BYTE strParam::SetDlg(HWND hDlg)
{
HWND hwndCB;

if(hDlg==NULL) return 1; hwndCB=GetDlgItem(hDlg,IDC_METHOD);
SetFlEdt(hDlg,IDC_TIME_WIDTH,Time_Width,FormTimeDur);
SetFlEdt(hDlg,IDC_TIME_STEP,Time_Step,FormTimeDur);
if(hwndCB!=NULL) {
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"Преобразование Габора");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"Косинусоидальное сглаживание");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"Окно Хэмминга");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"Окно Блэкмена-Харриса");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"Окно Кайзера-Бесселя");
SendMessage(hwndCB,CB_ADDSTRING,0,(LPARAM)(LPSTR)"Без сглаживания");
SendMessage(hwndCB,CB_SETCURSEL,methSpFour,0);
}
return 0;
}
BYTE FillSoundSine(void); // Заполнение синусоидой звукового файла.

//-----------------------------------------------------------------------------------------------------------
// Заполнение синусоидой звукового файла.

BYTE clMain::FillSoundSine(void)
{
UINT nPoints,i,sps; float Freq,Time,amp; double dt,Period,coe,t,s;

Freq=2000.0F; Time=10.0F; sps=40000U;
nPoints=GetUINT_Test((double)Time*(double)sps);
dt=1./(double)sps;
Period=1./Freq;
coe=2.*M_PI/Period*dt;
amp=1.e+5F;
Snd.Free();
if(Snd.Create(nPoints)!=0) return 1;
for(i=0;i<nPoints;i++) { t=(double)i*coe; s=sin(t); Snd.Snd[i]=amp*(float)s;}

Snd.dt=dt;
return 0;
}

// IDM_SINE_WAVE ............................................................................................
case IDM_SINE_WAVE: flag=0; FillSoundSine(); UpdateWindow_(hwndGraph); break; 

WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN
//rrr xxx yyy
DrawNetMem(); // Рисование изображения сети в памяти.
UpdateWin(); // Перерисовка окна.

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя для битового образа окна изображения сети.

void clDlgDBF_NNW::ZeroImgMem(void)
{
BmpNet=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти от битового образа окна изображения сети.

void clDlgDBF_NNW::FreeImgMem(void)
{
DeleteBmpMem_(&BmpNet);
}

//-----------------------------------------------------------------------------------------------------------
// Создание битового образа окна изображения сети.

BYTE clDlgDBF_NNW::CreateImgMem(void)
{
BYTE ber; int dx,dy;

ber=0; if(hDlg==NULL) { ber=1; goto end;}
dx=(int)(rcFrame.right-rcFrame.left);
dy=(int)(rcFrame.bottom-rcFrame.top);
if(dx<=0||dy<=0) { ber=2; goto end;}
if(IsOKImgMem()==0) { if(dx==BmpNet->dx&&dy==BmpNet->dy) return 0;}
FreeImgMem();
if(InitBmpMem_(hDlg,&BmpNet,dx,dy,0)!=0) { ber=3; goto end;}
end: if(ber!=0) FreeImgMem(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка битового образа окна изображения сети.

BYTE clDlgDBF_NNW::IsOKImgMem(void)
{
if(BmpNet==NULL) return 1; if(BmpNet->IsOKImg()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование изображения сети в памяти.

BYTE clDlgDBF_NNW::DrawNetMem(void)
{
RECT rc;

if(IsOKImgMem()!=0) return 1; if(MW==NULL) return 2; if(pNNW==NULL) return 3;
rc.left=0; rc.right=(long)BmpNet->dx; rc.top=0; rc.bottom=(long)BmpNet->dy;
if(pNNW->OnPaintNNW(BmpNet->hdc,&rc,AmpNormNeur,AmpNormSynops,&MW->PalPos,&MW->PalSign,flTrain,0)!=0) return 4;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Рисование в диалоговом окне.

BYTE clDlgDBF_NNW::OnPaint(HDC hdc)
{
int iv; RECT rc; HRGN hRgn;

if(hdc==NULL) return 1; if(hDlg==NULL) return 2;
if(GetClientRect(hDlg,&rc)==FALSE) return 3;
hRgn=CreateRectRgnIndirect(&rc); if(hRgn==NULL) return 4; SelectClipRgn(hdc,hRgn);
if(IsOKImgMem()==0) {
iv=(int)(rcFrame.right-rcFrame.left); if(iv!=BmpNet->dx) return 5;
iv=(int)(rcFrame.bottom-rcFrame.top); if(iv!=BmpNet->dy) return 6;
BitBlt(hdc,(int)rcFrame.left,(int)rcFrame.top,BmpNet->dx,BmpNet->dy,BmpNet->hdc,0,0,SRCCOPY);}
ExcludeClipRect(hdc,(int)rcFrame.left,(int)rcFrame.top,(int)rcFrame.right,(int)rcFrame.bottom);
ImgRectC(hdc,&rc,ColDial,ColDial,1);
SAFE_DELETE_OBJECT(hRgn); return 0;
}

// IDC_AMPLM_NEUR IDC_AMPLP_NEUR ............................................................................
case IDC_AMPLM_NEUR: case IDC_AMPLP_NEUR: coe=(float)sqrt(2.);
if(id==IDC_AMPLM_NEUR) AmpNormNeur*=coe; else AmpNormNeur/=coe;
SetFlEdt(hDlg,IDC_AMPL_NEUR,AmpNormNeur,FormNeur); UpdateWin(); break;

// IDC_AMPLOK_NEUR ..........................................................................................
case IDC_AMPLOK_NEUR: GetFlEdt(hDlg,IDC_AMPL_NEUR,&AmpNormNeur); UpdateWin(); break;

// IDC_AMPLM_SYN IDC_AMPLP_SYN ..............................................................................
case IDC_AMPLM_SYN: case IDC_AMPLP_SYN: coe=(float)sqrt(2.);
if(id==IDC_AMPLM_SYN) AmpNormSynops*=coe; else AmpNormSynops/=coe;
SetFlEdt(hDlg,IDC_AMPL_SYN,AmpNormSynops,FormSynops); UpdateWin(); break;

// IDC_AMPLOK_SYN ...........................................................................................
case IDC_AMPLOK_SYN: GetFlEdt(hDlg,IDC_AMPL_SYN,&AmpNormSynops); UpdateWin(); break;
float AmpNormNeur; // Амплитуда нормировки изображения нейронов.
float AmpNormSynops; // Амплитуда нормировки изображения синапсов.
AmpNormNeur=AmpNormNeur_Stand; AmpNormSynops=AmpNormSynops_Stand;
//-----------------------------------------------------------------------------------------------------------
// Перерисовка окна.

void clDlgDBF_NNW::UpdateWin(void)
{
UpdateWindow_(hDlg);
}

//xxx
//SetFlEdt(hDlg,IDC_STEP_TRAIN,(float)pNNW->Layers[1].Alpha,FormErr);

CreateSoundWAV(); // Класс хранения данных в формате 'WAV': создание.
//-----------------------------------------------------------------------------------------------------------
// Класс хранения данных в формате 'WAV': обнуление указателя.

void clMain::ZeroSoundWAV(void)
{
SoundWAV=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Класс хранения данных в формате 'WAV': оcвобождение памяти.

void clMain::FreeSoundWAV(void)
{
SAFE_DELETE(SoundWAV);
}

//-----------------------------------------------------------------------------------------------------------
// Класс хранения данных в формате 'WAV': создание.

BYTE clMain::CreateSoundWAV(void)
{
FreeSoundWAV(); SoundWAV=new clWavData(); if(SoundWAV==NULL) return 1; return 0;
}

//xxx
if(SoundWAV!=NULL) SoundWAV->FreeSnd();
void ZeroSoundWAV(void); // Класс хранения данных в формате 'WAV': обнуление указателя.
void FreeSoundWAV(void); // Класс хранения данных в формате 'WAV': оcвобождение памяти.
BYTE CreateSoundWAV(void); // Класс хранения данных в формате 'WAV': создание.


//if(f<=AlphaMax&&f>0.) Lay->Alpha=(float)f; else Lay->Alpha=AlphaMax;
//xxx
//vvv
Lay->Alpha=(float)f;

//if(f<=AlphaMax&&f>0.) Lay->Alpha=(float)f; else Lay->Alpha=AlphaMax;

//-----------------------------------------------------------------------------------------------------------
// Нахождение относительных амплитуд и частот спектральных линий.

BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP)
{
BYTE GetMaxAccurate(float *Fun,float *pos,float *amp); // Более точное нахождение максимума по трём точкам: параболическая аппроксимация.

BYTE *Flags,*FlagsV,k,err; USHRT i,iI,iF,nFrMin,nFrMax,nNeur,num; float v,S,*Sp,fr,frI,del,coeNorm;
double s,powTotal,powPeaks; struct strSpectrLine *pSpL;

if(nSpectr<=2) return 1; if(Spectr==NULL) return 2;
if(nSpLines==0) return 3; if(SpLines==NULL) return 4;
if(dFr<=0.0F) return 5; if(PGP==NULL) return 6; if(PGP->IsOK()!=0) return 7;
nFrMin=GetUSHRT_Test(PGP->FreqMin/dFr); if(nFrMin==0) return 8;
nFrMax=GetUSHRT_Test(PGP->FreqMax/dFr); if(nFrMax==0) return 9; nFrMax=MIN(nFrMax,nSpectr);
if(nFrMax<=nFrMin) return 10;
for(k=0;k<nSpLines;k++) SpLines[k].Zero();

Flags=NULL; Sp=NULL; err=0;
Flags=new BYTE[nSpectr]; if(Flags==NULL) { err=11; goto end;}
FlagsV=new BYTE[nSpectr]; if(FlagsV==NULL) { err=12; goto end;}
Sp=new float[nSpectr]; if(Sp==NULL) { err=13; goto end;}

// Нормировка спектра.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;}
s/=(double)(nFrMax-nFrMin); s=SQRT(s); if(s==0.) { err=14; goto end;}
v=(float)(1./s); for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// Нахождение максимумов - спектральных линий.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(i=1;i<nSpectr-1;i++) if(Sp[i-1]<Sp[i]&&Sp[i]>Sp[i+1]) Flags[i]=1;

// Отбрасывание пиков с малой частотой.
for(i=0;i<nFrMin;i++) Flags[i]=0;

// Отбрасывание пиков с очень малой амплитудой.
for(i=1;i<nSpectr-1;i++) { if(Flags[i]==0) continue; if(Sp[i]<PGP->coeSmPeaks) Flags[i]=0;}

// Сохранение флагов пиков во втором масcиве.
for(i=0;i<nSpectr;i++) FlagsV[i]=Flags[i];

// Повторная нормировка спектра после отбрасывания пиков с очень малой амплитудой.
s=0.; num=0; for(i=nFrMin;i<nFrMax;i++) { if(Flags[i]==0) continue; v=Spectr[i]; s+=(double)v*(double)v; num++;}
if(num==0) { err=15; goto end;}
s/=(double)num; s=SQRT(s); if(s==0.) { err=16; goto end;}
coeNorm=(float)s; v=1.0F/coeNorm; for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// Отбрасывание пиков с малой амплитудой для нахождения первых N нижних по частоте пиков.
for(i=1;i<nSpectr-1;i++) { if(Flags[i]==0) continue; if(Sp[i]<PGP->coePeaks) Flags[i]=0;}

// Заполнение массива входного слоя нейронов для N нижних по частоте пиков.
nNeur=0; for(i=nFrMin;i<nFrMax;i++) { if(Flags[i]==0) continue;
if(GetMaxAccurate(Sp+i-1,&fr,&S)!=0) { err=17; goto end;} fr+=(float)i;
if(nNeur==0) { frI=fr; pSpL=SpLines; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=frI; nNeur=1;}
else { v=fr/frI; num=GetUSHRT_Test(v); if(num<=1) { err=18; goto end;}
del=v-(float)num; if(del<0.0F) del=-del; if(del>PGP->ErrFreq) continue;
num--; if(num>=nSpLines) break;
if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq) frI=fr/(float)(num+1); // Коррекция основной частоты по частоте максимальной выявленной гармоники с достаточно большой амплитудой.
pSpL=SpLines+num;
if(pSpL->AmpRel==0.0F||pSpL->AmpRel!=0.0F&&pSpL->AmpRel<S) { pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr; nNeur=num+1;}}
if(nNeur>=PGP->numPeakEqDist) break; // Окончание поиска пиков по алгоритму для N нижних по частоте пиков.
}
if(nNeur==0) { err=19; goto end;}

//xxx numPeakEqDist

// Проверка, что спектр состоит из линий.
// Находим суммарную мощность.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powTotal=SQRT(s);

// Находим мощность по линиям.
v=PGP->widPeaks/dFr; v=MIN(v,frI*0.5F);
powPeaks=0.; for(k=0;k<nSpLines;k++) { pSpL=SpLines+k; if(pSpL->AmpRel==0.0F) continue; fr=pSpL->Freq;
iI=GetUSHRT_Test(fr-v); if(iI<0) iI=0; if(iI>=nFrMax) iI=nFrMax-1;
iF=GetUSHRT_Test(fr+v); if(iF<0) iF=0; if(iF>=nFrMax) iF=nFrMax-1;
if(iI>iF) continue;
s=0.; for(i=iI;i<iF;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powPeaks+=s;}
powPeaks=SQRT(powPeaks);

if(powPeaks<powTotal*PGP->LevPowPeak) { err=20; goto end;}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(Flags); SAFE_DELETE_ARR(FlagsV); return err;
}

#define coePeaks_Stand 0.5F // Уровень, по которому идёт первоначальный отбор пиков.
float coePeaks; // Уровень, по которому идёт первоначальный отбор пиков.

// Нахождение спектральных линий.
pSpL=SpLines[i];
be=FindPeaks(nPh,Spectr,dFr,nPeaksMax,pSpL,&ParGetPeaks,0);
if(be!=0) { ResPeaks[i]=0; for(j=0;j<nPeaksMax;j++) (pSpL+j)->Zero();}
else { nPeaks=0; for(j=0;j<nPeaksMax;j++) if((pSpL+j)->AmpRel!=0.0F) nPeaks++; ResPeaks[i]=nPeaks;}

// Распознавание методом нейронных сетей.
pNNW=&NNW_Vowel; flNNW=0;
if(pNNW->flOK!=0) {//xxx
for(j=0;j<nPeaksMax;j++) InpLay.Values[j]=pSpL[j].AmpRel; // Задание входного массива.
if(pNNW->Compute(&InpLay)!=0) goto eNNW;
pLay=pNNW->Get(pNNW->nLay-1); if(pLay==NULL) goto eNNW; if(pLay->IsOK()!=0) goto eNNW;
if(GetNumSound(pLay,pNNW->typ,errSoundResNNW,&ResNNW[i])!=0) goto eNNW;
flNNW=1; eNNW:;}
if(flNNW==0) ResNNW[i]=UCHAR_MAX;


//-----------------------------------------------------------------------------------------------------------
// Нахождение относительных амплитуд и частот спектральных линий.

BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP,
BYTE flOut)
{
BYTE GetMaxAccurate(float *Fun,float *pos,float *amp); // Более точное нахождение максимума по трём точкам: параболическая аппроксимация.
BYTE LFreqlKalman(float *A,float *LF,USHRT nPoints,float Discr,float Range); // Нахождение НЧ компоненты (фильтр Калмана).

BYTE *Flags,*FlagsV,*pFl,k,err; USHRT i,iI,iF,nFrMin,nFrMax,nFrM,nNeur,num;
float v,S,*Sp,fr,frI,del,wid,coeNorm; double s,powTotal,powPeaks; struct strSpectrLine *pSpL;

if(nSpectr<=2) return 1; if(Spectr==NULL) return 2;
if(nSpLines==0) return 3; if(SpLines==NULL) return 4;
if(dFr<=0.0F) return 5; if(PGP==NULL) return 6; if(PGP->IsOK()!=0) return 7;
nFrMin=GetUSHRT_Test(PGP->FreqMin/dFr); if(nFrMin==0) { Message(IDS_ErrParFindPeaks,MB_ST); return 8;}
nFrMax=GetUSHRT_Test(PGP->FreqMax/dFr); if(nFrMax==0) { Message(IDS_ErrParFindPeaks,MB_ST); return 9;}
nFrMax=MIN(nFrMax,nSpectr); if(nFrMax<=nFrMin) { Message(IDS_ErrParFindPeaks,MB_ST); return 10;}
for(k=0;k<nSpLines;k++) SpLines[k].Zero();

Flags=NULL; Sp=NULL; err=0;
Flags=new BYTE[nSpectr]; if(Flags==NULL) { err=11; goto end;}
FlagsV=new BYTE[nSpectr]; if(FlagsV==NULL) { err=12; goto end;}
Sp=new float[nSpectr]; if(Sp==NULL) { err=13; goto end;}

// Нормировка спектра.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=(double)v*(double)v;}
s/=(double)(nFrMax-nFrMin); s=SQRT(s); if(s==0.) { err=14; goto end;}
coeNorm=(float)s; v=(float)(1./s); for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// Нахождение максимумов - спектральных линий.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(i=1;i<nSpectr-1;i++) if(Sp[i-1]<Sp[i]&&Sp[i]>Sp[i+1]) Flags[i]=1;

// Отбрасывание пиков с малой частотой.
for(i=0;i<nFrMin;i++) Flags[i]=0;

// Сохранение флагов пиков во втором масcиве.
for(i=0;i<nSpectr;i++) FlagsV[i]=Flags[i];

// Отбрасывание пиков с малой амплитудой для нахождения первых N нижних по частоте пиков.
for(i=1;i<nSpectr-1;i++) { if(FlagsV[i]==0) continue; if(Sp[i]<PGP->coeSmPeaks) FlagsV[i]=0;}

// Заполнение массива входного слоя нейронов для N нижних по частоте пиков.
nNeur=0; for(i=nFrMin;i<nFrMax;i++) { if(nNeur==0) pFl=FlagsV; else pFl=Flags; if(pFl[i]==0) continue;
if(GetMaxAccurate(Sp+i-1,&fr,&S)!=0) { err=17; goto end;} fr+=(float)i;
if(nNeur==0) { frI=fr; pSpL=SpLines; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=frI; nNeur=1;}
else { v=fr/frI; num=GetUSHRT_Test(v); if(num<1) { err=18; goto end;}
del=v-(float)num; if(del<0.0F) del=-del; if(del>PGP->ErrFreq) continue;
num--; if(num>=nSpLines) break;
if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq) frI=fr/(float)(num+1); // Коррекция основной частоты по частоте максимальной выявленной гармоники с достаточно большой амплитудой.
pSpL=SpLines+num;
if(pSpL->AmpRel==0.0F||pSpL->AmpRel!=0.0F&&pSpL->AmpRel<S) {
pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr; nNeur=num+1;}}
if(nNeur>=PGP->numPeakEqDist) break; // Окончание поиска пиков по алгоритму для N нижних по частоте пиков.
}
if(nNeur==0) { err=19; goto end;}

//xxx numPeakEqDist

// Проверка, что спектр состоит из линий.
wid=PGP->widPeaks/dFr; wid=MIN(wid,frI*0.5F);

// Находим максимальную частоту спектра, состоящего из выделенных спектральных линий.
nFrM=0;
for(k=0;k<nSpLines;k++) { pSpL=SpLines+k; if(pSpL->AmpRel==0.0F) continue; fr=pSpL->Freq;
iF=GetUSHRT_Test(fr+wid); if(iF<0) iF=0; if(iF>=nSpectr) iF=nSpectr-1; if(nFrM<iF) nFrM=iF;}
if(nFrM<nFrMin) { err=20; goto end;}

// Находим суммарную мощность.
s=0.; for(i=nFrMin;i<=nFrM;i++) { v=Spectr[i]; s+=(double)v*(double)v;} powTotal=SQRT(s);

// Находим мощность по линиям.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(k=0;k<nSpLines;k++) { pSpL=SpLines+k; if(pSpL->AmpRel==0.0F) continue; fr=pSpL->Freq;
iI=GetUSHRT_Test(fr-wid); if(iI<0) iI=0; if(iI>nFrM) iI=nFrM;
iF=GetUSHRT_Test(fr+wid); if(iF<0) iF=0; if(iF>nFrM) iF=nFrM; if(iI>iF) continue;
for(i=iI;i<=iF;i++) Flags[i]=1;}
s=0.; for(i=nFrMin;i<=nFrM;i++) if(Flags[i]!=0) { v=Spectr[i]; s+=(double)v*(double)v;} powPeaks=SQRT(s);
if(powPeaks>powTotal) { err=21; goto end;}

//xxx
if(flOut!=0) {
//mmm
//sprintf(TxtStr,"powPeaks,powTotal: %le %le",powPeaks,powTotal);
//MessageBox(NULL,TxtStr,"",MB_EX);
}

if(powPeaks<powTotal*(double)PGP->LevPowPeak) { err=22; goto end;}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(Flags); SAFE_DELETE_ARR(FlagsV); return err;
}

//-----------------------------------------------------------------------------------------------------------

BYTE LFreqlKalman(float *A,float *LF,UINT nPoints,float Discr,float Range)
{
UINT i; float K_Flt,v,s;

if(A==NULL) return 1; if(LF==NULL) return 2; if(nPoints==0) return 3; if(Discr<=0.0F) return 4;
if(Range<=0.0F) return 5; v=Range/Discr; if(v<=0.0F) return 6; K_Flt=1.0F/v;
s=0.0F; for(i=0;i<nPoints;i++) { s+=K_Flt*(A[i]-s); LF[i]=s;} return 0;
}

//xxx
//for(i=0;i<nSpectr;i++) Spectr[i]=SpP[i];
//for(i=0;i<nSpectr;i++) Spectr[i]=SpSm[i];

//-----------------------------------------------------------------------------------------------------------
// Нахождение относительных амплитуд и частот спектральных линий.

BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP,
BYTE *flLines,BYTE flOut)
{
BYTE GetMaxAccurate(float *Fun,float *pos,float *amp); // Более точное нахождение максимума по трём точкам: параболическая аппроксимация.
BYTE FindLFreq(float *A,float *LF,UINT nPoints,float Discr,float Range); // Нахождение НЧ компоненты.

BYTE *Flags,*FlagsV,*pFl,k,cnt,err; USHRT i,nFrMin,nFrMax,nNeur,num;
float v,vM,S,*Sp,*SpV,*SpSm,*SpP,fr,frI,del,coe,coeNorm,*fp; double powBkg,powPeaks;
struct strSpectrLine *pSpL;

if(nSpectr<=2) return 1; if(Spectr==NULL) return 2;
if(nSpLines==0) return 3; if(SpLines==NULL) return 4;
if(dFr<=0.0F) return 5; if(PGP==NULL) return 6; if(PGP->IsOK()!=0) return 7; if(flLines==NULL) return 8;
nFrMin=GetUSHRT_Test(PGP->FreqMin/dFr); if(nFrMin==0) { Message(IDS_ErrParFindPeaks,MB_ST); return 9;}
nFrMax=GetUSHRT_Test(PGP->FreqMax/dFr); if(nFrMax==0) { Message(IDS_ErrParFindPeaks,MB_ST); return 10;}
nFrMax=MIN(nFrMax,nSpectr); if(nFrMax<=nFrMin) { Message(IDS_ErrParFindPeaks,MB_ST); return 11;}
for(k=0;k<nSpLines;k++) SpLines[k].Zero();

Flags=FlagsV=NULL; Sp=SpV=SpSm=SpP=NULL; err=0;
Flags=new BYTE[nSpectr]; if(Flags==NULL) { err=12; goto end;}
FlagsV=new BYTE[nSpectr]; if(FlagsV==NULL) { err=13; goto end;}
Sp=new float[nSpectr]; if(Sp==NULL) { err=14; goto end;}
SpV=new float[nSpectr]; if(SpV==NULL) { err=15; goto end;}
SpSm=new float[nSpectr]; if(SpSm==NULL) { err=16; goto end;}
SpP=new float[nSpectr]; if(SpP==NULL) { err=17; goto end;}

// Нормировка спектра.
vM=0.0F; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; if(v>vM) vM=v;} if(vM==0.0F) { err=18; goto end;}
if(vM<PGP->AmpThr) { err=messRet; goto end;}
coeNorm=vM; v=1.0F/vM; for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// Поэтапное сглаживание спектра и вычитание пиков.
for(i=0;i<nFrMin;i++) SpV[i]=0.0F; for(i=nFrMin;i<nSpectr;i++) SpV[i]=Sp[i];
for(cnt=0;cnt<PGP->numIterSmSubtr;cnt++) {
if(FindLFreq(SpV,SpSm,nSpectr,dFr,PGP->widSmooth)!=0) { err=19; goto end;} // Нахождение сглаженного спектра.
coe=PGP->coePeaksCut;
for(i=nFrMin;i<nSpectr;i++) { v=SpSm[i]*coe; fp=SpV+i; if(*fp>v) *fp=v;} // Обрезание выступающих пиков.
for(i=nFrMin;i<nSpectr;i++) SpV[i]=SpSm[i]; // Копирование спектра для следующей итерации.
}
if(FindLFreq(SpV,SpSm,nSpectr,dFr,PGP->widSmooth)!=0) { err=20; goto end;} // Нахождение сглаженного спектра.

// Нахождение отдельно спектра, состоящего целиком из пиков.
//for(i=0;i<nFrMin;i++) SpP[i]=0.0F;
//for(i=nFrMin;i<nSpectr;i++) { fp=SpP+i; *fp=Sp[i]-SpSm[i]; if(*fp<0.0F) *fp=0.0F;}

// Нахождение максимумов - спектральных линий.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(i=1;i<nSpectr-1;i++) if(Sp[i-1]<=Sp[i]&&Sp[i]>=Sp[i+1]) Flags[i]=1;
for(i=0;i<nFrMin;i++) Flags[i]=0; // Отбрасывание пиков с малой частотой.

// Выделение истинных пиков, которые превышают фон в заданное число раз.
/*
coe=PGP->coeRecPeaks;
for(i=nFrMin;i<nSpectr;i++) { if(Flags[i]==0) continue; v=SpSm[i]*coe; if(Sp[i]<v) Flags[i]=0;}
*/

for(i=0;i<nSpectr;i++) FlagsV[i]=Flags[i]; // Сохранение флагов пиков во втором масcиве.

// Отбрасывание пиков с малой амплитудой для нахождения первого пика.
for(i=nFrMin;i<nFrMax;i++) { if(FlagsV[i]==0) continue; if(Sp[i]<PGP->coeSmPeaks) FlagsV[i]=0;}

// Заполнение массива входного слоя нейронов для N нижних по частоте пиков.
nNeur=0; for(i=nFrMin;i<nFrMax;i++) { if(nNeur==0) pFl=FlagsV; else pFl=Flags; if(pFl[i]==0) continue;
//xxx
if(GetMaxAccurate(Sp+i-1,&fr,&S)!=0) { err=21; goto end;} fr+=(float)i;
//S=Sp[i]; fr=(float)i;

if(nNeur==0) { frI=fr;
//mmm
//sprintf(TxtStr,"frI: %f",frI); MessageBox(NULL,TxtStr,"",MB_EX);

 pSpL=SpLines; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=frI; nNeur=1;}
else { v=fr/frI; num=GetUSHRT_Test(v); if(num<1) {

//mmm
//sprintf(TxtStr,"fr,frI: %f %f",fr,frI); MessageBox(NULL,TxtStr,"",MB_EX);

 err=22; goto end;}
del=v-(float)num; if(del<0.0F) del=-del; num--; if(num>=nSpLines) break; pSpL=SpLines+num;
if(pSpL->AmpRel==0.0F) {
pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr;

//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"A---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/

if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq&&del<PGP->ErrFreq) frI=fr/(float)(num+1); // Коррекция основной частоты по частоте максимальной выявленной гармоники с достаточно большой амплитудой.


nNeur=MAX(nNeur,num+1);}
else {
if(fr-pSpL->Freq<frI*0.7F) {
if(pSpL->AmpRel<S) {
pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr;

//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"B---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/

if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq&&del<PGP->ErrFreq) frI=fr/(float)(num+1); // Коррекция основной частоты по частоте максимальной выявленной гармоники с достаточно большой амплитудой.


nNeur=MAX(nNeur,num+1);}}
else { num++; if(num>=nSpLines) break; pSpL=SpLines+num;
if(pSpL->AmpRel!=0.0F) { err=23; goto end;}
pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr;
//if(PGP->flCorrFreq!=0&&S>=PGP->coePeaksCorrFreq&&del<PGP->ErrFreq) frI=fr/(float)(num+1); // Коррекция основной частоты по частоте максимальной выявленной гармоники с достаточно большой амплитудой.

//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"C---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/

nNeur=MAX(nNeur,num+1);}
}

}
if(nNeur>=PGP->numPeakEqDist) break; // Окончание поиска пиков по алгоритму для N нижних по частоте пиков.
}
if(nNeur==0) { err=24; goto end;}

//mmm
//sprintf(TxtStr,"nNeur %d",nNeur); MessageBox(NULL,TxtStr,"",MB_EX);

// Отбрасывание ложных пиков.
//PGP->widPeaks;
/*
coe=PGP->coeRecPeaks;
for(i=nFrMin;i<nSpectr;i++) { if(Flags[i]==0) continue; v=SpSm[i]*coe; if(Sp[i]<v) Flags[i]=0;}
*/


// Проверка, что спектр целиком состоит из линий.
powPeaks=powBkg=0.;
for(i=nFrMin;i<nFrMax;i++) { v=Sp[i]-SpSm[i]; if(v<0.0F) v=0.0F; powPeaks+=(double)v; v=SpSm[i]; powBkg+=(double)v;}
if(powPeaks<powBkg*(double)PGP->LevPowPeak) *flLines=1; else *flLines=0;

//xxx
if(flOut!=0) {

/*
frI=SpLines[0].Freq;
for(k=1;k<nSpLines;k++) { if(SpLines[k].Freq-SpLines[k-1].Freq<frI*0.7F) {
sprintf(TxtStr,"k: %d frN,frP: %f %f dfr,frI: %f %f",
k,SpLines[k].Freq,SpLines[k-1].Freq,SpLines[k].Freq-SpLines[k-1].Freq,frI); MessageBox(NULL,TxtStr,"",MB_EX);
}
}
*/

//mmm
pSpL=SpLines;
sprintf(TxtStr,"Amp,AmpRel,Freq: %f %f %f",pSpL->Amp,pSpL->AmpRel,pSpL->Freq); MessageBox(NULL,TxtStr,"",MB_EX);

//mmm
sprintf(TxtStr,"powPeaks,powBkg: %le %le flLines: %d",powPeaks,powBkg,*flLines); MessageBox(NULL,TxtStr,"",MB_EX);


}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(SpV); SAFE_DELETE_ARR(SpSm); SAFE_DELETE_ARR(SpP);
SAFE_DELETE_ARR(Flags); SAFE_DELETE_ARR(FlagsV); return err;
}

//for(i=0;i<nFunP;i++) { FunP[i]=FunP[i+2*nFunP]=-1.0F; FunP[i+nFunP]=1.0F;} // Нахождение функции.

//xxx
if(flOut!=0) {
//sprintf(TxtStr,"k,Fr,j: %d %f %d s/wei,amp*coe,amp: %f %f %f",k,pSpL->Freq,j,s/wei,pSpL->AmpRel*coe,pSpL->AmpRel);
//MessageBox(NULL,TxtStr,"",MB_EX);
}

//xxx
if(flOut!=0) {

/*
frI=SpLines[0].Freq;
for(k=1;k<nSpLines;k++) { if(SpLines[k].Freq-SpLines[k-1].Freq<frI*0.7F) {
sprintf(TxtStr,"k: %d frN,frP: %f %f dfr,frI: %f %f",
k,SpLines[k].Freq,SpLines[k-1].Freq,SpLines[k].Freq-SpLines[k-1].Freq,frI); MessageBox(NULL,TxtStr,"",MB_EX);
}
}
*/

//mmm
pSpL=SpLines;
//sprintf(TxtStr,"Amp,AmpRel,Freq: %f %f %f",pSpL->Amp,pSpL->AmpRel,pSpL->Freq); MessageBox(NULL,TxtStr,"",MB_EX);

//mmm
//sprintf(TxtStr,"powPeaks,powBkg: %le %le flLines: %d",powPeaks,powBkg,*flLines); MessageBox(NULL,TxtStr,"",MB_EX);

//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"A---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/
//xxx
/*
if(flOut!=0) {
sprintf(TxtStr,"B---> num: %d AmpRel,Amp: %f %f Freq,dFr: %f %f frI: %f del: %f",
num,pSpL->AmpRel,pSpL->Amp,pSpL->Freq,pSpL->Freq-SpLines[num-1].Freq,frI,del);
MessageBox(NULL,TxtStr,"",MB_EX);
}
*/
//if(nNeur>=PGP->numPeakEqDist) break; // Окончание поиска пиков по алгоритму для N нижних по частоте пиков.

// Поэтапное сглаживание спектра и вычитание пиков.
for(i=0;i<nFrMin;i++) SpV[i]=0.0F; for(i=nFrMin;i<nSpectr;i++) SpV[i]=Sp[i];
for(cnt=0;cnt<PGP->numIterSmSubtr;cnt++) {
if(FindLFreq(SpV,SpSm,nSpectr,dFr,PGP->widSmooth)!=0) { err=24; goto end;} // Нахождение сглаженного спектра.
coe=PGP->coePeaksCut;
for(i=nFrMin;i<nSpectr;i++) { v=SpSm[i]*coe; fp=SpV+i; if(*fp>v) *fp=v;} // Обрезание выступающих пиков.
for(i=nFrMin;i<nSpectr;i++) SpV[i]=SpSm[i]; // Копирование спектра для следующей итерации.
}
if(FindLFreq(SpV,SpSm,nSpectr,dFr,PGP->widSmooth)!=0) { err=25; goto end;} // Нахождение сглаженного спектра.

// Нахождение отдельно спектра, состоящего целиком из пиков.
//for(i=0;i<nFrMin;i++) SpP[i]=0.0F;
//for(i=nFrMin;i<nSpectr;i++) { fp=SpP+i; *fp=Sp[i]-SpSm[i]; if(*fp<0.0F) *fp=0.0F;}

// Выделение истинных пиков, которые превышают фон в заданное число раз.
/*
coe=PGP->coeRecPeaks;
for(i=nFrMin;i<nSpectr;i++) { if(Flags[i]==0) continue; v=SpSm[i]*coe; if(Sp[i]<v) Flags[i]=0;}
*/

SpV=new float[nSpectr]; if(SpV==NULL) { err=18; goto end;}
SpSm=new float[nSpectr]; if(SpSm==NULL) { err=19; goto end;}
SpP=new float[nSpectr]; if(SpP==NULL) { err=20; goto end;}
SAFE_DELETE_ARR(SpV); SAFE_DELETE_ARR(SpSm); SAFE_DELETE_ARR(SpP);
/*
powPeaks=powBkg=0.;
for(i=nFrMin;i<nFrMax;i++) { v=Sp[i]-SpSm[i]; if(v<0.0F) v=0.0F; powPeaks+=(double)v; v=SpSm[i]; powBkg+=(double)v;}

*/

//xxx mmm yyy
//if(be!=0&&be!=messRet) { sprintf(TxtStr,"be: %d",be); MessageBox(NULL,TxtStr,"FindPeaks",MB_EX);}

if(flOut!=0) {
//xxx mmm yyy
//mmm
//sprintf(TxtStr,"be: %d",be); MessageBox(NULL,TxtStr,"FindPeaks",MB_EX);
}

//if(num==UCHAR_MAX) { for(l=0;l<nPeaksMax;l++) InpLay.Values[l]=0.0F;}
//else { }

//-----------------------------------------------------------------------------------------------------------
// Изменение состояния кнопки сохранения изменений параметров сети.

void clDlgParNNW::ChBtnSave(void)
{
BYTE fl;

if(pPar==NULL) fl=0; else fl=pPar->flChange; EnableChWin(hDlg,IDOK,fl);
}


float widSmooth; // Ширина интервала сглаживания фильтром (Гц).
BYTE numIterSmSubtr; // Число итераций сглаживания и вычитания пиков.
float coePeaksCut; // Коэффициент, определяющий уровень обрезания пиков при сглаживании.

#define NumIterSmSubtr_Stand 5 // Число итераций сглаживания и вычитания пиков.
#define NumIterSmSubtr_Min 1 // Число итераций сглаживания и вычитания пиков (минимальное значение).
#define NumIterSmSubtr_Max 30 // Число итераций сглаживания и вычитания пиков (максимальное значение).
#define CoePeaksCut_Stand 1.0F // Коэффициент, определяющий уровень обрезания пиков при сглаживании.
#define CoePeaksCut_Max 10.0F // Коэффициент, определяющий уровень обрезания пиков при сглаживании (максимальное значение).
#define widSmooth_Stand 200.0F // Ширина интервала сглаживания (Гц).
#define coeWidMinFltSmooth 4.0F // Минимальная ширина интервала сглаживания фильтром в полуширинах пиков.

fp=&coePeaksCut; v=CoePeaksCut_Max; if(*fp>v) { *fp=v; fl+=1<<10;}

if(coePeaksCut<1.0F) return 11; if(coePeaksCut>CoePeaksCut_Max) return 12;


if(file==NULL) return 1;
if(fscanf(file,"%f%f%f%f%f%f%d%f%f",&coeSmPeaks,&FreqMin,&FreqMax,&ErrFreq,&widPeaks,&widSmooth,&iv,&coePeaksCut,
&coeRecPeaks)==EOF) return 2; if(iv<=0||iv>UCHAR_MAX) return 3; numIterSmSubtr=(BYTE)iv;
if(fscanf(file,"%f%d%f",&LevPowPeak,&iv,&coePeaksCorrFreq)==EOF) return 4; if(iv==0) flCorrFreq=0; else flCorrFreq=1;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv<=0||iv>UCHAR_MAX) return 6; numPeakEqDist=(BYTE)iv;
return 0;

if(file==NULL) return 1;
if(fprintf(file,"%f %f %f %f %f %f %d %f %f %f %d %f %d\n",coeSmPeaks,FreqMin,FreqMax,ErrFreq,widPeaks,widSmooth,
(int)numIterSmSubtr,coePeaksCut,coeRecPeaks,LevPowPeak,(int)flCorrFreq,coePeaksCorrFreq,(int)numPeakEqDist)<0) return 2;

case 5: fp=&widSmooth;        id=IDC_WID_SMOOTH;      Form=FormFreq; break;
case 6: fp=&coePeaksCut;      id=IDC_COE_PEAK_CUT;    Form=FormCoeff; break;

case 5: fp=&widSmooth;        id=IDC_WID_SMOOTH; break;
case 6: fp=&coePeaksCut;      id=IDC_COE_PEAK_CUT; break;

if(numIterSmSubtr<NumIterSmSubtr_Min) return 9;
if(numIterSmSubtr>NumIterSmSubtr_Max) return 10;

 numIterSmSubtr=NumIterSmSubtr_Stand;

bp=&numIterSmSubtr;
b=NumIterSmSubtr_Min; if(*bp<b) { *bp=b; fl+=1<<8;}
b=NumIterSmSubtr_Max; if(*bp>b) { *bp=b; fl+=1<<9;}

GetByteEdt(hDlg,IDC_NUM_ITER_SMOOTH,&numIterSmSubtr);
SetByteEdt(hDlg,IDC_NUM_ITER_SMOOTH,numIterSmSubtr);

widSmooth=widSmooth_Stand;
if(widSmooth<=0.0F) return 7; if(widSmooth<widPeaks*coeWidMinFltSmooth) return 8;

fp=&widSmooth; if(*fp<=0.0F) { *fp=widSmooth_Stand; fl+=1<<6;}
v=widPeaks*coeWidMinFltSmooth; if(*fp<v) { *fp=v; fl+=1<<7;}

#define numPeakEqDist_Min 3 // Номер пика, до которого ищем пики как в точности кратные основной гармонике - минимальное значение.
#define numPeakEqDist_Stand 5 // Номер пика, до которого ищем пики как в точности кратные основной гармонике - стандартное значение.

BYTE numPeakEqDist; // Максимальный номер пика, до которого ищем пики как в точности кратные основной гармонике.

bp=&numPeakCons;
b=numPeakCons_Min; if(*bp<b) { *bp=b; fl+=1<<11;}
b=nPeaksMax; if(*bp>b) { *bp=b; fl+=1<<12;}

char *NameParInpCons="ParInpCons.cnf"; // Параметры ввода данных во входной слой сети для согласных звуков.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров ввода данных во входной слой сети для согласных звуков.

struct strParInpCons ParInpCons;

ParInpCons.Read(PathToProgDir,NameParInpCons); // Чтение параметров ввода данных во входной слой сети для согласных звуков.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы для обработки спектра согласных звуков.

#define nTriMin 5 // Минимальное число треугольных функций разложения спектра согласных звуков.
#define FreqStepCons_Stand 50.0F // Шаг по частоте для разложения по треугольным функциям для спектра согласных звуков (Гц).
#define FreqConsMax 5000.0F // Максимальная частота, до которой проводится анализ согласных звуков (Гц).

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров ввода данных во входной слой сети для согласных звуков.

struct strParInpCons {

float StepTri; // Шаг по частоте для разложения по треугольным функциям для спектра согласных звуков (Гц).
float FreqMax; // Максимальная частота, до которой проводится анализ согласных звуков (Гц).

strParInpCons(void); // Конструктор.
void Init(void); // Инициализация.
BYTE IsOK(void); // Проверки.
BYTE Check(void); // Проверки и коррекция.
BYTE Read_(FILE *file); // Чтение из файла.
BYTE Read(char *Path,char *fName); // Чтение из файла.
BYTE Write_(FILE *file); // Запись в файл.
BYTE Write(char *Path,char *fName); // Запись в файл.
};

// Структура параметров ввода данных во входной слой сети для согласных звуков.
struct strParInpCons { strParInpCons,Init,IsOK,Check,Read_,Read,Write_,Write},

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров ввода данных во входной слой сети для согласных звуков.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strParInpCons::strParInpCons(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

void strParInpCons::Init(void)
{
StepTri=FreqStepCons_Stand; FreqMax=FreqConsMax;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParInpCons::IsOK(void)
{
if(StepTri<=0.0F) return 1; if(FreqMax<=0.0F) return 2; if(StepTri>=FreqMax) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки и коррекция.

BYTE strParInpCons::Check(void)
{
BYTE fl; float *fp;

fl=0;
fp=&StepTri; if(*fp<=0.0F) { *fp=FreqStepCons_Stand; fl+=1<<0;}
fp=&FreqMax; if(*fp<=0.0F) { *fp=FreqConsMax; fl+=1<<1;}
if(StepTri>=FreqMax) { FreqMax=StepTri; fl+=1<<2;}
return fl;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParInpCons::Read_(FILE *file)
{
if(file==NULL) return 1;
if(fscanf(file,"%f%f",&StepTri,&FreqMax)==EOF) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParInpCons::Read(char *Path,char *fName)
{
BYTE err; char *name; clFileT *FT;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
FT=NULL; name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,NULL)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,0)!=0) { err=5; goto end;} 
if(Read_(FT->file)!=0) { err=6; goto end;}
Check(); // Проверки и коррекция.
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strParInpCons::Write_(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%f %f\n",StepTri,FreqMax)<0) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение в файле.

BYTE strParInpCons::Write(char *Path,char *fName)
{
BYTE err; char *name; clFileT *FT;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
FT=NULL; name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,NULL)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,1)!=0) { err=5; goto end;}
if(Write_(FT->file)!=0) { err=6; goto end;}
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

/*
//mmm xxx
UINT cntTrain=0;
cntTrain++; if(cntTrain%1000==0) {
for(i=0;i<nLay;i++) {
sprintf(TxtStr,"Layer: %d Alpha: %e",i,Layers[i].Alpha);
//mmm
MessageBox(NULL,TxtStr,"",MB_EX);

if(Layers[i].Alpha>AlphaMax||Layers[i].Alpha<0.) Layers[i].Alpha=AlphaMax;
}
}
//xxx
*/
 if(flInpLay!=0) {
//xxx
 if(nWei!=InpLay.n) goto endInpAxons;}
if(dir==0) {
pP=pPoints; pP->x=rc->left; pP->y=(rc->top+rc->bottom)/2;
pP=pPoints+1; pP->x=rc->right; pP->y=rc->top;
pP=pPoints+2; pP->x=rc->right; pP->y=rc->bottom;}
else {
pP=pPoints; pP->x=rc->right; pP->y=(rc->top+rc->bottom)/2;
pP=pPoints+1; pP->x=rc->left; pP->y=rc->top;
pP=pPoints+2; pP->x=rc->left; pP->y=rc->bottom;}
}

switch(typNet) { default: return 7;
// Для гласных звуков.
case typNNW_Vowel: nNeur=nPeaksMax; break;
// Для согласных звуков.
//xxx
case typNNW_Cons: if(ParInpCons.IsOK()!=0) return 8;
nNeur=GetBYTE(ParInpCons.FreqMax/ParInpCons.StepTri); nNeur=MAX(nNeur,nTriMin); break;
}

s=0.; for(i=1;i<nFunP;i++) s+=FunP[i]; s*=2.; s+=FunP[0]; weiFunP=1.0F/(float)s; // Нормировочный коэффициент.

// Нахождение истинных пиков.
for(k=0;k<(BYTE)nNeur;k++) FlPeaks[k]=1;
if((BYTE)nNeur<nSpLines) for(k=(BYTE)nNeur;k<nSpLines;k++) FlPeaks[k]=0;

coe=PGP->coeRecPeaks;
for(k=0;k<nNeur;k++) { pSpL=SpLines+k; j=GetUSHRT_Test(pSpL->Freq);
iI=(int)j-(int)nFunA+1; iF=(int)j+(int)nFunA;
s=0.; for(iv=iI;iv<iF;iv++) { if(iv<0||iv>=nSpectr) continue; ia=iv-j; if(ia<0) ia=-ia;
if(ia>=nFunA) { err=25; goto end;} s+=Sp[iv]*FunP[ia];}
if((float)s*weiFunP<pSpL->AmpRel*coe) FlPeaks[k]=0;}

//-----------------------------------------------------------------------------------------------------------
// Нахождение НЧ компоненты.

BYTE FindLFreq(float *A,float *LF,UINT nPoints,float Discr,float Range)
{
BYTE ber; UINT i,j; USHRT nBuf,nBh,k,cnt; float *Buf,*fp,v; double s;

if(A==NULL) return 1; if(LF==NULL) return 2; if(nPoints==0) return 3; if(Discr<=0.0F) return 4;
if(Range<=0.0F) return 5; nBuf=GetUSHRT_Test(Range/Discr); if(nBuf<=1) return 6; nBh=nBuf/2;
if(nPoints>UINT_MAX-(UINT)nBh) return 7;
Buf=NULL; ber=0;
Buf=new float[nBuf]; if(Buf==NULL) { ber=8; goto end;}
for(k=0;k<nBuf;k++) Buf[k]=0.0F;
cnt=0; s=0.0F;
for(i=0;i<nPoints+(UINT)nBh;i++) { fp=Buf+cnt; s-=(double)*fp; if(i<nPoints) { v=A[i]; *fp=v; s+=(double)v;}
cnt++; if(cnt==nBuf) cnt=0; if(i<nBh) continue; j=i-(UINT)nBh; LF[j]=(float)s;}
v=1.0F/(float)nBuf; for(i=0;i<nPoints;i++) LF[i]*=v;
end: SAFE_DELETE(Buf); return ber;
}


//xxx yyy mmm
if(flOut!=0) {
//mmm
sprintf(TxtStr,"powPeaks,powTotal: %le %le typNet: %d",powPeaks,powTotal,*typNet); MessageBox(NULL,TxtStr,"",MB_EX);
}

BYTE flRecPeaksVowel; // Флаг подсчёта по уровню мощности не всех пиков, а начиная с номера 'nPeaksCons'.
#define LevPowPeakVowel_Stand 0.3F // Минимальный уровень мощности, который должен содержаться в пиках начиная с номера 'nPeaksCons'.
float LevPowPeakVowel; // Минимальный уровень мощности, который должен содержаться в пиках начиная с номера 'nPeaksCons'.

#define MinSzNotify 1024 // Минимальный размер буфера для сообщений.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Форматы.

extern char *FormTimeDur; // Короткий промежуток времени (с).
//-----------------------------------------------------------------------------------------------------------
// Установка длительности интервала захвата звука.

BYTE clDlgSndCap::SetTimeBuf(void)
{
float v;

if(hDlg==NULL) return 1; if(GetFlEdt(hDlg,IDC_TIME_WIN,&v)!=0) return 2;
//xxx IDC_TIME_WIN

return 0;
}

// Нахождение весовой функции окна.
switch(meth) { default: break;
case methSpFour_CosWin: WinCoe=0.5F; break; // Оконное преобразование Фурье с косинусоидальным сглаживанием в окне.
case methSpFour_Gabor: WinCoe=coeWinWidGabor; break; // Преобразование Габора.
case methSpFour_Kaiser: WinCoe=4.54F; break; // Окно Кайзера-Бесселя.
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE clSndCapData::Alloc(UINT nM_)
{
if(SCA==NULL) return 1; if(SCA->Alloc(nM_)!=0) return 2; return 0;
}


//xxx
Txt[1]='\0'; Txt[0]='a';
if(WinText.hwnd!=NULL) { be=WinText.PasteText(Txt); // Вывод символа звука в окно текста.
if(be!=0) {
//mmm
sprintf(TxtStr,"WinText.PasteText be: %d",be); WinText.SetText(TxtStr);
}

}
if(be!=messRet&&be!=0) {
//mmm xxx
sprintf(TxtStr,"be: %d",be); MessageBox(NULL,TxtStr,"ProcRecRealTime",MB_EX);
}

//mmm xxx
if(flErr!=NULL) {
sprintf(TxtStr,"SpLines->Freq: %f PGP->coeWidPeaks: %f dFr: %f",SpLines->Freq,PGP->coeWidPeaks,dFr);
MessageBox(NULL,TxtStr,"",MB_EX);}

if(be!=0) {
sprintf(TxtStr,"\nRecognSoundNNW be: %d\n",be);
if(WinText.hwnd!=NULL) WinText.PasteText(TxtStr);
//xxx

 GETTEXTLENGTHEX TLI;
TLI.flags=GTL_NUMCHARS; TLI.codepage=CP_ACP;
lRes=SendMessage(hwndEdt,EM_GETTEXTLENGTHEX,(WPARAM)&TLI,0L);
if(lRes!=E_INVALIDARG) { if(lRes==MaxSizeEdt) SendMessage(hwndEdt,WM_SETTEXT,0,(LPARAM)"");}

//xxx SendMessage(hwndEdt,EM_SETREADONLY,(WPARAM)FALSE,0L);
//xxx SendMessage(hwndEdt,EM_SETREADONLY,(WPARAM)TRUE,0L);

WS_VSCROLL

if(WinText.hwnd!=NULL) {
if(nRecChar==MaxSizeEdt) { nRecChar=0; WinText.ClearWin();}
WinText.PasteText(Txt); nRecChar++;} // Добавление распознанных символов в окно.

//RowText[szTimeMax+1];

}

//-----------------------------------------------------------------------------------------------------------
// Добавление текста в окно.

BYTE clWinText::PasteText(char *Text)
{
BYTE ber; size_t sz; LPSTR cp; HGLOBAL hGlb;

if(hwndEdt==NULL) return 1; if(IsOKStr(Text)!=0) return 0;
if(hwnd==NULL) return 2; if(OpenClipboard(hwnd)==FALSE) return 3;
EmptyClipboard();
hGlb=NULL; ber=0;
sz=(strlen(Text)+1)*sizeof(char);
hGlb=GlobalAlloc(GMEM_MOVEABLE,sz);
if(hGlb==NULL) { ber=4; goto end;}
cp=(char *)GlobalLock(hGlb); if(cp==NULL) { ber=5; goto end;}
memcpy(cp,Text,sz); 
GlobalUnlock(hGlb); 
if(SetClipboardData(CF_TEXT,hGlb)==NULL) { ber=6; goto end;}
CloseClipboard();
SendMessage(hwndEdt,WM_PASTE,0,0L);
end: if(hGlb!=NULL) GlobalFree(hGlb); return ber;
}

BYTE PasteText(char *Text); // Добавление текста в окно.

if(be!=0) {
//mmm xxx
sprintf(TxtStr,"\nbe: %d k: %u TimeRecBuf,TimeRecProc: %u %u nPoints: %d i,nTime: %d %d nStep: %d\n",
be,k,TimeRecBuf,TimeRecProc,nPoints,i,nTime,nStep);
if(WinText.hwnd!=NULL) WinText.SetText(TxtStr);
}

//xxx
char const StrClose[]="Закрыть"; // Название для кнопки "Закрытие".
char const StrWinTxt[]="Окно текста"; // Название кнопки открытия окна текста.

//xxx
char const StrStop[]="Остановить"; // Название кнопки остановки.
char const StrSound[]="Звук"; // Название кнопки вывода звука.
char const StrSndCap[]="Запись"; // Название кнопки записи звука.
char const StrSndRec[]="Распознавание"; // Название кнопки распознавания звука.
//xxx
SetDlgItemText(hDlg,IDC_PLAY_SND,StrSound);
//xxx
SetDlgItemText(hDlg,IDC_PLAY_SND,StrStop);

//xxx
SetFlEdt(hDlg,IDC_ERR_TRAIN,0.0F,FormErr);
SetFlEdt(hDlg,IDC_ERR_CONTR,0.0F,FormErr);


/*
if(CheckPeak(nSpectr,Sp,SpLines,&k,(BYTE)nFunP,FunP,PGP->coeRecPeaks)==0) {
//mmm
sprintf(TxtStr,"First Peak: %d",k);
MessageBox(NULL,TxtStr,"",MB_EX);}
*/

//xxx
//-----------------------------------------------------------------------------------------------------------
// Проверка пика.

BYTE CheckPeak(USHRT nSpectr,float *Spectr,strSpectrLine *pSpL,BYTE *flPeak,BYTE nFunP,float *FunP,float coePeaks)
{
BYTE k,nFunA; USHRT j; int iv,ia,iI,iF; float weiFunP; double s;

if(nSpectr==0) return 1; if(Spectr==NULL) return 2; if(pSpL==NULL) return 3; if(flPeak==NULL) return 4;
if(nFunP==0) return 5; if(FunP==NULL) return 6;
if((USHRT)nFunP*3>UCHAR_MAX) return 7; nFunA=nFunP*3; if(coePeaks<=0.0F) return 8;

s=0.; for(k=1;k<nFunP;k++) s+=FunP[k]; s*=2.; s+=FunP[0]; weiFunP=1.0F/(float)s; // Нормировочный коэффициент.

j=GetUSHRT_Test(pSpL->Freq); iI=(int)j-(int)nFunA+1; iF=(int)j+(int)nFunA;
s=0.; for(iv=iI;iv<iF;iv++) { if(iv<0||iv>=nSpectr) continue; ia=iv-j; if(ia<0) ia=-ia;
if(ia>=nFunA) return 9; s+=(double)Spectr[iv]*(double)FunP[ia];}
if((float)s*weiFunP<pSpL->AmpRel*coePeaks) *flPeak=0; else *flPeak=1;

//mmm
sprintf(TxtStr,"pSpL->Freq: %f j,iI,iF: %d %d %d s,weiFunP,pSpL->AmpRel,coePeaks: %lf %f %f %f",
pSpL->Freq,j,iI,iF,s,weiFunP,pSpL->AmpRel,coePeaks);
MessageBox(NULL,TxtStr,"",MB_EX);

return 0;
}
if(flOut!=0) {
//mmm
sprintf(TxtStr,"k,amp,fr: %d %f %f iI,iF: %d %d",k,pSpL->AmpRel,fr,iI,iF);
MessageBox(NULL,TxtStr,"",MB_EX);
}
//xxx
else { 
	
if(flOut!=0) {
//mmm
//sprintf(TxtStr,"powPeaks,powTotal,PGP->LevPowPeak: %lf %lf %lf",powPeaks,powTotal,PGP->LevPowPeak);
//MessageBox(NULL,TxtStr,"",MB_EX);

}
	err=100; goto end;}

//xxx
if(flOut!=0) {
sprintf(TxtStr,"FindPeaks be: %d typNet,flErr: %d %d Amp,Freq: %f %f",be,typNet,flErr,pSpL->Amp,pSpL->Freq);
MessageBox(NULL,TxtStr,"",MB_EX);}

DrawNet(); // Перерисовка изображения сети.


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров тренировки нейронной сети групповым методом поиска.
//struct strParNNWSearch { BYTE nStRepM; float coeStI,coeSt,coeChSt;};
struct strParNNWSearch ParNNWSearch={ 60, 0.05F,0.2F,0.15F};

//-----------------------------------------------------------------------------------------------------------
// Тренировка нейронной сети групповым методом поиска.

BYTE clDlgDBF_NNW::TrainNNW_Search(void)
{
BYTE GetNumInput(strNNW *pNNW,BYTE *nInp); // Получение числа нейронов первого распределительного слоя.
BYTE GetParNNW(strNNW *pNNW,strParNNW *pParNNW); // Получение параметров из структуры нейронной сети.
BYTE GetNumVectParNNW(strParNNW *pParNNW,BYTE nNeurInp,USHRT *nVect);// Получение полного числа коэффициентов и смещений из структуры нейронной сети.
BYTE AbsValue(double *V,USHRT N,double *av); // Норма вектора.

BYTE ind,nPeaksInp,be,ber; USHRT i,j,k,nStepsRand,nCycle,nV,nStRep; UINT *NumRandArr;
double stN,stNw,stPr,er,erN,erC,a,c,av,avN,ac,acN,acS,d,wei,weiN,weiC,coeSt,v,Err,ErrMin,ErrCntrl;
struct strArrTrSearch ATS; struct strParNNW Par;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) { Message(IDS_Mess_ErrConfNNW,MB_ST); return 2;}
if(ParNNWSearch.IsOK()!=0) return 3;
flBlk|=1<<numBlkDBF_Train; flTrain=1; flStopTrain=0; OnChFlagTrain();
if(GetNumInput(pNNW,&nPeaksInp)!=0) return 4; if(nPeaksInp==0) return 5;

NumRandArr=NULL; ber=0;

// Разложение в спектр.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Fourier");
be=ProcSpectr(&flStopTrain); if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=6; goto end;}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // Изображение процента выполнения работы.

// Цикл поиска наилучшего начального приближения при случайной инициализации коэффициентов нейронной сети.
nStepsRand=ParTrain.nStRand;
if(pNNW->flOK==0&&nStepsRand!=0) {
pNNW->ZeroInit(); ErrMin=LrgCnst32_d; j=USHRT_MAX;
ClearWinErrTrain(); // Очистка окон ошибок при тренировке сети.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Random");

NumRandArr=new UINT[nStepsRand]; if(NumRandArr==NULL) { ber=7; goto end;}
srand(ParTrain.RandSeq); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) goto end;
if(pNNW->RandInit(NumRandArr[i],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=8; goto end;}
be=StepRand(&Err); if(be!=0&&be!=messRet) { ber=9; goto end;}
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(Err<ErrMin) { ErrMin=Err; j=i; SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)ErrMin,FormErr);}
ShowProgress(hwndProgr,NULL,(UINT)i+1,(UINT)nStepsRand); ProcMess(); // Изображение процента выполнения работы.
if(flStopTrain!=0) { ber=messRet; goto end;}
}
if(j>=nStepsRand) { ber=10; goto end;}
if(pNNW->RandInit(NumRandArr[j],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=11; goto end;}
}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // Изображение процента выполнения работы.

// Алгоритм группового поиска.
if(GetParNNW(pNNW,&Par)!=0) { ber=12; goto end;} // Получение параметров из структуры нейронной сети.
if(GetNumVectParNNW(&Par,nPeaksInp,&nV)!=0) { ber=13; goto end;} // Получение полного числа коэффициентов и смещений из структуры нейронной сети.
if(ATS.Create(nV)!=0) { ber=14; goto end;} // Создание массивов.
if(pNNW->AllocVect()!=0) { ber=15; goto end;} // Выделение памяти для векторов.

be=FindVectSearch(&er,&wei,NULL,NULL); if(be!=0&&be!=messRet) { ber=16; goto end;}
if(be==messRet&&ParTrain.flRandSampl==0) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(pNNW->GetSetArrSearch(ATS.Vect,nV,0,1)!=0) { ber=17; goto end;} // Получение векторов.
if(AbsValue(ATS.Vect,nV,&av)!=0) { ber=18; goto end;}
if(pNNW->GetSetArrSearch(ATS.Coe,nV,0,0)!=0) { ber=19; goto end;} // Получение коэффициентов.
if(AbsValue(ATS.Coe,nV,&ac)!=0) { ber=20; goto end;}

ind=0; stN=ac;

// Циклы тренировки групповым методом поиска.
nCycle=0;
rep: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(k=0;k<ParTrain.nStTrain;k++) { nStRep=0;
repSt: if(av<SmCnst24_d) goto end; if(flStopTrain!=0) { ber=messRet; goto end;}
if(ind==0) coeSt=ParNNWSearch.coeStI; else coeSt=ParNNWSearch.coeSt;
stPr=stN*coeSt; v=stPr/av; for(i=0;i<nV;i++) ATS.CoeN[i]=ATS.Coe[i]+ATS.Vect[i]*v;

if(pNNW->GetSetArrSearch(ATS.CoeN,nV,1,0)!=0) { ber=21; goto end;} // Установка коэффициентов.
if(FindVectSearch(&erN,&weiN,&erC,&weiC)!=0) { ber=22; goto end;}
if(pNNW->GetSetArrSearch(ATS.VectN,nV,0,1)!=0) { ber=23; goto end;} // Получение векторов.
if(AbsValue(ATS.VectN,nV,&avN)!=0) { ber=24; goto end;}
if(erN>er) { stN*=ParNNWSearch.coeChSt; if(nStRep>ParNNWSearch.nStRepM) goto end; nStRep++;
ProcMess(); goto repSt;}

if(AbsValue(ATS.CoeN,nV,&acN)!=0) { ber=25; goto end;}
v=er-erN; if(v<SmCnst24_d) goto end; stN=erN/v*stPr; for(i=0;i<nV;i++) ATS.CoeS[i]=ATS.Coe[i]+ATS.CoeN[i];
if(AbsValue(ATS.CoeS,nV,&acS)!=0) { ber=26; goto end;}
v=stPr*acS; if(v<SmCnst24_d) goto end; a=(er-erN)/v; c=((er+erN)-a*(ac*ac+acN*acN))*0.5; if(c<0.) c=0.;
if(a<SmCnst24_d) goto end; d=(erN-c)/a; stNw=SQRT(d);
stN=MIN(stN,stNw); er=erN; ac=acN; av=avN;
for(i=0;i<nV;i++) { ATS.Coe[i]=ATS.CoeN[i]; ATS.Vect[i]=ATS.VectN[i];}

// Вывод информации о ходе тренировки.
if(weiN<SmCnst24_d) { ber=27; goto end;} Err=erN/weiN; Err=SQRT(Err);
if(weiC<SmCnst24_d) ErrCntrl=0.; else ErrCntrl=erC/weiC; ErrCntrl=SQRT(Err);
SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)Err,FormErr);
SetFlEdt(hDlg,IDC_ERR_CONTR,(float)ErrCntrl,FormErr);
ind=1; pNNW->flOK=1;
ShowProgress(hwndProgr,NULL,(UINT)k+1,(UINT)ParTrain.nStTrain); ProcMess(); // Изображение процента выполнения работы.
}
if(nCycle==USHRT_MAX) goto end; nCycle++; goto rep;

end: flBlk&=~(1<<numBlkDBF_Train); flTrain=0; flStopTrain=1; OnChFlagTrain();
SAFE_DELETE_ARR(NumRandArr); pNNW->FreeVect(); // Освобождение памяти.
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // Изображение процента выполнения работы.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
return ber;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров тренировки нейронной сети групповым методом поиска.
//struct strParNNWSearch { BYTE nStRepM; float coeSt,coeChSt;};
struct strParNNWSearch ParNNWSearch={ 60, 0.1F,0.15F};



//-----------------------------------------------------------------------------------------------------------
// Тренировка нейронной сети групповым методом поиска.

BYTE clDlgDBF_NNW::TrainNNW_Search(void)
{
BYTE GetNumInput(strNNW *pNNW,BYTE *nInp); // Получение числа нейронов первого распределительного слоя.
BYTE GetParNNW(strNNW *pNNW,strParNNW *pParNNW); // Получение параметров из структуры нейронной сети.
BYTE GetNumVectParNNW(strParNNW *pParNNW,BYTE nNeurInp,USHRT *nVect);// Получение полного числа коэффициентов и смещений из структуры нейронной сети.
BYTE AbsValue(double *V,USHRT N,double *av); // Норма вектора.
BYTE Randomize(double *Vect,double *VectR,USHRT nVect,UINT nRand,float coe); // Функция случайного изменения вектора.

BYTE nPeaksInp,be,ber; USHRT i,j,k,nStepsRand,nCycle,nV; UINT *NumRandArr,numRand; float coeVect;
double stPr,er,erN,erC,erM,av,ac,acN,wei,weiN,weiC,v,Err,ErrMin,ErrCntrl;
struct strArrTrSearch ATS; struct strParNNW Par;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) { Message(IDS_Mess_ErrConfNNW,MB_ST); return 2;}
if(ParNNWSearch.IsOK()!=0) return 3;
flBlk|=1<<numBlkDBF_Train; flTrain=1; flStopTrain=0; OnChFlagTrain();
if(GetNumInput(pNNW,&nPeaksInp)!=0) return 4; if(nPeaksInp==0) return 5;
nStepsRand=ParTrain.nStRand; if(nStepsRand==0) return 6;

NumRandArr=NULL; ber=0;
NumRandArr=new UINT[nStepsRand]; if(NumRandArr==NULL) { ber=7; goto end;}

// Разложение в спектр.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Fourier");
be=ProcSpectr(&flStopTrain); if(be==messRet) { ber=messRet; goto end;} if(be!=0) { ber=6; goto end;}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // Изображение процента выполнения работы.

// Цикл поиска наилучшего начального приближения со случайной инициализацией коэффициентов нейронной сети.
if(pNNW->flOK==0&&nStepsRand!=0) {
pNNW->ZeroInit(); ErrMin=LrgCnst32_d; j=USHRT_MAX;
ClearWinErrTrain(); // Очистка окон ошибок при тренировке сети.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Random");
srand(ParTrain.RandSeq); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) goto end;
if(pNNW->RandInit(NumRandArr[i],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=8; goto end;}
be=StepRand(&Err); if(be!=0&&be!=messRet) { ber=9; goto end;}
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(Err<ErrMin) { ErrMin=Err; j=i; SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)ErrMin,FormErr);}
ShowProgress(hwndProgr,NULL,(UINT)i+1,(UINT)nStepsRand); ProcMess(); // Изображение процента выполнения работы.
if(flStopTrain!=0) { ber=messRet; goto end;}
}
if(j>=nStepsRand) { ber=10; goto end;}
if(pNNW->RandInit(NumRandArr[j],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=11; goto end;}
}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // Изображение процента выполнения работы.

// Алгоритм группового поиска.
if(GetParNNW(pNNW,&Par)!=0) { ber=12; goto end;} // Получение параметров из структуры нейронной сети.
if(GetNumVectParNNW(&Par,nPeaksInp,&nV)!=0) { ber=13; goto end;} // Получение полного числа коэффициентов и смещений из структуры нейронной сети.
if(ATS.Create(nV)!=0) { ber=14; goto end;} // Создание массивов.
if(pNNW->AllocVect()!=0) { ber=15; goto end;} // Выделение памяти для векторов.

be=FindVectSearch(&er,&wei,NULL,NULL); if(be!=0&&be!=messRet) { ber=16; goto end;}
if(be==messRet&&ParTrain.flRandSampl==0) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(pNNW->GetSetArrSearch(ATS.Vect,nV,0,1)!=0) { ber=17; goto end;} // Получение векторов.
if(AbsValue(ATS.Vect,nV,&av)!=0) { ber=18; goto end;}
if(pNNW->GetSetArrSearch(ATS.Coe,nV,0,0)!=0) { ber=19; goto end;} // Получение коэффициентов.
if(AbsValue(ATS.Coe,nV,&ac)!=0) { ber=20; goto end;}

// Циклы тренировки групповым методом поиска.
nCycle=0;
rep: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(k=0;k<ParTrain.nStTrain;k++) {

if(av<SmCnst24_d) goto end; if(flStopTrain!=0) { ber=messRet; goto end;}
stPr=ac*ParNNWSearch.coeSt; v=stPr/av; for(i=0;i<nV;i++) ATS.CoeN[i]=ATS.Coe[i]+ATS.Vect[i]*v;

if(pNNW->GetSetArrSearch(ATS.CoeN,nV,1,0)!=0) { ber=21; goto end;} // Установка коэффициентов.
if(AbsValue(ATS.CoeN,nV,&acN)!=0) { ber=24; goto end;}
if(FindVectSearch(&erN,&weiN,&erC,&weiC)!=0) { ber=22; goto end;}
if(pNNW->GetSetArrSearch(ATS.Vect,nV,0,1)!=0) { ber=23; goto end;} // Получение векторов.
if(AbsValue(ATS.Vect,nV,&av)!=0) { ber=24; goto end;}

// Цикл случайного поиска. 
if(erN>er) {
erM=er; j=USHRT_MAX;
coeVect=ParTrain.coeVect; numRand=ParTrain.RandSeq;

repSearch: srand(numRand); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) goto end; ProcMess();
if(Randomize(ATS.Coe,ATS.CoeN,nV,NumRandArr[i],coeVect)!=0) { ber=24; goto end;}
if(pNNW->GetSetArrSearch(ATS.CoeN,nV,1,0)!=0) { ber=21; goto end;} // Установка коэффициентов.
if(FindVectSearch(&erN,&weiN,NULL,NULL)!=0) { ber=22; goto end;} ProcMess();

//mmm xxx
//sprintf(TxtStr,"Random coeVect: %f  i,err: %d %lf",coeVect,i,erN); MessageBox(NULL,TxtStr,"",MB_EX);

if(erN<erM) { erM=erN; j=i;}}

//mmm xxx
//sprintf(TxtStr,"j: %d",j); MessageBox(NULL,TxtStr,"",MB_EX);

if(j==USHRT_MAX) { coeVect*=2.0F; numRand++;
//xxx
if(coeVect>100.) { ber=100; goto end;}

 goto repSearch;}

if(Randomize(ATS.Coe,ATS.CoeN,nV,NumRandArr[j],ParTrain.coeVect)!=0) { ber=24; goto end;}
if(pNNW->GetSetArrSearch(ATS.CoeN,nV,1,0)!=0) { ber=21; goto end;} // Установка коэффициентов.
if(AbsValue(ATS.CoeN,nV,&acN)!=0) { ber=24; goto end;}
if(FindVectSearch(&erN,&weiN,&erC,&weiC)!=0) { ber=22; goto end;}
if(pNNW->GetSetArrSearch(ATS.Vect,nV,0,1)!=0) { ber=23; goto end;} // Получение векторов.
if(AbsValue(ATS.Vect,nV,&av)!=0) { ber=24; goto end;}
}

//mmm xxx
//sprintf(TxtStr,"Continue k: %d",k); MessageBox(NULL,TxtStr,"",MB_EX);

// Запись новых коэффициентов и параметров для продолжения цикла.
er=erN; ac=acN; for(i=0;i<nV;i++) ATS.Coe[i]=ATS.CoeN[i];

// Вывод информации о ходе тренировки.
if(weiN<SmCnst24_d) { ber=27; goto end;} Err=erN/weiN; Err=SQRT(Err);
if(weiC<SmCnst24_d) ErrCntrl=0.; else ErrCntrl=erC/weiC; ErrCntrl=SQRT(Err);
SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)Err,FormErr);
SetFlEdt(hDlg,IDC_ERR_CONTR,(float)ErrCntrl,FormErr);
pNNW->flOK=1;
ShowProgress(hwndProgr,NULL,(UINT)k+1,(UINT)ParTrain.nStTrain); ProcMess(); // Изображение процента выполнения работы.

//mmm xxx
//sprintf(TxtStr,"--->OK k: %d",k); MessageBox(NULL,TxtStr,"",MB_EX);

}
if(nCycle==USHRT_MAX) goto end; nCycle++; goto rep;

end: flBlk&=~(1<<numBlkDBF_Train); flTrain=0; flStopTrain=1; OnChFlagTrain();
SAFE_DELETE_ARR(NumRandArr); pNNW->FreeVect(); // Освобождение памяти.
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // Изображение процента выполнения работы.
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Функция случайного изменения вектора.

BYTE Randomize(double *Vect,double *VectR,USHRT nVect,UINT nRand,float coe)
{
USHRT i; double vr,Coe;

if(Vect==NULL) return 1; if(VectR==NULL) return 2; if(nVect==0) return 3;
srand(nRand); vr=1./(double)RAND_MAX; Coe=coe*2.;
for(i=0;i<nVect;i++) VectR[i]=Vect[i]*(1.+((double)rand()*vr-0.5)*Coe); return 0;
}

// Нормировка спектра.
vM=0.0F; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; if(v>vM) vM=v;} if(vM==0.0F) { err=19; goto end;}
if(vM<PGP->AmpThr) { err=messRet; goto end;}
coeNorm=vM; v=1.0F/vM; for(i=0;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

y=pNeur->Val;
//xxx
switch(Lay->TypFunAct) { default: return 6;
case TypFunAct_Sigm:   f=y*(1.-y); break;     // Сигмоидная функия.
case TypFunAct_BiSigm: f=0.5*(1.-y*y); break; // Биполярная cигмоидная функия.
case TypFunAct_HypTan: f=1.-y*y; break;       // Гиперболический тангенс.
}

//-----------------------------------------------------------------------------------------------------------
// Расчет адаптивного шага для одного слоя.

BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
USHRT i,j; double f1,f2,f3,f,y,Gamma;

if(LayPrev==NULL) return 1; if(LayPrev->Neurons->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->Neurons->IsOK()!=0) return 4;
if(AlphaMin<0.0F) return 5; if(AlphaMax<=0.0F) return 6; if(AlphaMax<AlphaMin) return 7;
f=f1=f2=f3=0.; 

switch(Lay->TypFunAct) { default: return 8;

case TypFunAct_Sigm: // Сигмоидная функия.
for(j=0;j<Lay->n;j++) { y=(double)Lay->Neurons[j].Val; Gamma=(double)Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*y*(1.-y); f3+=pow(Gamma,2)*pow(y,2)*pow(1.0-y,2);}
for(i=0;i<LayPrev->n;i++) f2+=pow((double)LayPrev->Neurons[j].Val,2);
f=4.*f1/((1.+f2)*f3); break; 

case TypFunAct_BiSigm: // Биполярная сигмоидная функция.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*(1.-pow(y,2)); f3+=pow(Gamma,2)*pow(1-pow(y,2),2);}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Neurons[j].Val,2);
f=4.*f1/((1.+f2)*f3); break;

case TypFunAct_HypTan: // Гиперболический тангенс.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=(float)(pow(Gamma,2)*(1.-pow(y,2))); f3+=(float)(pow(Gamma,2)*pow(1-pow(y,2),2));}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Neurons[i].Val,2);
f=f1/((1.+f2)*f3); break;
}
f=MIN(f,AlphaMax); f=MAX(f,AlphaMin); Lay->Alpha=(float)f; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчет адаптивного шага для слоя, следующего за входящим.

BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
USHRT i,j; double f1,f2,f3,f,y,Gamma;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->Neurons->IsOK()!=0) return 4;
if(AlphaMin<0.0F) return 5; if(AlphaMax<=0.0F) return 6; if(AlphaMax<AlphaMin) return 7;
f=f1=f2=f3=0.; 

switch(Lay->TypFunAct) { default: return 8;

case TypFunAct_Sigm: // Сигмоидная функия.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*y*(1.-y); f3+=pow(Gamma,2)*pow(y,2)*pow(1.-y,2);}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Values[i],2);
if(f3<=0.) return 9; f=4.*f1/((1.+f2)*f3); break; 

case TypFunAct_BiSigm: // Биполярная сигмоидная функция.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*(1.-pow(y,2)); f3+=pow(Gamma,2)*pow(1.-pow(y,2),2);}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Values[i],2);
if(f3<=0.) return 10; f=4.*f1/((1.+f2)*f3); break;

case TypFunAct_HypTan: // Гиперболический тангенс.
for(j=0;j<Lay->n;j++) { y=Lay->Neurons[j].Val; Gamma=Lay->Neurons[j].Err;
f1+=pow(Gamma,2)*(1.-pow(y,2)); f3+=pow(Gamma,2)*pow(1.-pow(y,2),2);}
for(i=0;i<LayPrev->n;i++) f2+=pow(LayPrev->Values[i],2);
if(f3<=0.) return 11; f=f1/((1.+f2)*f3); break;
}
f=MIN(f,AlphaMax); f=MAX(f,AlphaMin); Lay->Alpha=(float)f; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Очистка окон ошибок при тренировке сети.

void clDlgDBF_NNW::ClearWinErrTrain(void)
{
if(hDlg==NULL) return;
SetDlgItemText(hDlg,IDC_ERR_TRAIN,"");
SetDlgItemText(hDlg,IDC_ERR_CONTR,"");
}


//-----------------------------------------------------------------------------------------------------------
// Установка входного слоя и расчёт.

BYTE strNNW::Compute(strInpLay *InpLay_)
{
BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src); // Копирование структуры входного слоя сети.
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay".
BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay" - первом скрытом слое.

BYTE i;

if(IsOK()!=0) return 1; if(CopyInpLay(&InpLay,InpLay_)!=0) return 2;
if(ComputeLayerFirst(&InpLay,&Layers[0])!=0) return 3;
for(i=1;i<nLay;i++) if(ComputeLayer(&Layers[i-1],&Layers[i])!=0) return 4; return 0;
}

nStepsRand=ParTrain.nStRand;
if(pNNW->flOK==0&&nStepsRand!=0) {
pNNW->ZeroInit(); ErrMin=LrgCnst32_d; j=USHRT_MAX;
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"Random");

NumRandArr=new UINT[nStepsRand]; if(NumRandArr==NULL) { ber=4; goto end;}
srand(ParTrain.RandSeq); for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) goto end;
if(pNNW->RandInit(NumRandArr[i],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=5; goto end;}
be=StepRand(&Err); if(be!=0&&be!=messRet) { ber=6; goto end;}
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(Err<ErrMin) { ErrMin=Err; j=i; SetFlEdt(hDlg,IDC_ERR_TRAIN,(float)ErrMin,FormErr);}
ShowProgress(hwndProgr,NULL,(UINT)i+1,(UINT)nStepsRand); ProcMess(); // Изображение процента выполнения работы.
if(flStopTrain!=0) { ber=messRet; goto end;}
}
if(j>=nStepsRand) { ber=7; goto end;}
if(pNNW->RandInit(NumRandArr[j],ParTrain.coeWei,ParTrain.coeTe)!=0) { ber=8; goto end;}
}
if(hDlg!=NULL) SetDlgItemText(hDlg,IDC_NUM_CYCLE,"");
ShowProgress(hwndProgr,NULL,0,0); ProcMess(); // Изображение процента выполнения работы.

//-----------------------------------------------------------------------------------------------------------
// Действия при открытии диалогового окна.

BYTE clDlgDBF_NNW::OnOpenDlg(HWND hDlg_)
{
BYTE fl;

if(hDlg_==NULL) return 1; hDlg=hDlg_;
if(CreateBrushes()!=0) return 2; // Создание кистей для закрашивания окон.
SetPosWindowCenter(hDlg); // Помещение окна в центр другого окна или экрана.
//zzz
FillLBFiles(); // Заполнение списка файлов базы данных.
UnSelFile(); // Действия при выборе другого файла.
if(pDataBase==NULL) fl=0; else fl=pDataBase->flChange; EnableChWin(hDlg,IDC_SAVE,fl);
hwndProgr=InitProgress(hDlg,IDC_PROGR); // Инициализация окна показа процента выполнения работы.
SetColProgr(hwndProgr,COL_WHITE,COL_BLUE);

SetTxtBtnPreProc(); // Установка текста в кнопку предварительной обработки.
SetTxtBtnTrain(); // Установка текста в кнопку тренировки сети.
SetTxtBtnPlaySound(); // Установка текста в кнопку воспроизведения звука.
SetTxtBtnBlockSetTime(); // Установка текста в кнопку блокировки изменения времени в базе данных.

ParTrain.Read(PathToProgDir,NameParTrain); // Чтение параметров тренировки сети.
SetHeaderWinAlpha(); // Установка заголовка окна шага.

InitParNNW(); // Инициализация структур параметров нейронных сетей.
SetPntNNW(); // Установка указателей на структуры нейронной сети и параметров нейронной сети.

// Установка окон редактирования.
CheckRadioButton(hDlg,IDC_RADIO_VOWEL,IDC_RADIO_CONS,IDC_RADIO_VOWEL+(int)typNet); // Установка типа сети.
SetNameNNW(typNNW_Vowel); SetNameNNW(typNNW_Cons); // Установка имён файлов нейронных сетей.
ClearWinParFile(); // Очистка окон параметров файла базы данных в окнах.
ClearWinParSound(); // Очистка окон параметров отрезка звука базы данных в окнах.
ShowHideWinStepTrain(); // Визуализация или скрытие окна адаптивного шага.

return 0;
}

if(num==numSnd) nTrue++; // Распознанный звук совпал с заданным (или помеха распознана как помеха).
if(numSnd!=UCHAR_MAX) {
if(num!=UCHAR_MAX&&num!=numSnd) nFalse++; // Заданный звук не помеха, распознался другой звук.
if(num==UCHAR_MAX) nNoRec++; // Заданный звук не помеха, звук не распознан.
}
if(numSnd==UCHAR_MAX) { if(num!=UCHAR_MAX) nFalse++;} // Заданный звук - помеха, но распознан как звук речи.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы.

#define nNod_HidLay 15 // Число нейронов в скрытом слое.

if(MW==NULL) return 7; Wid=MW->Param.Time_Width; if(Wid<=0.0F) return 8;

if(frI>PGP->MaxFreqFirst) goto TriCons; 
MaxFreqFirst=MaxFreqFirst_Stand; 
#define MaxFreqFirst_Stand 400.0F // Максимальная частота, где может находиться первый спектральный пик.
float MaxFreqFirst; // Максимальная частота, где может находиться первый спектральный пик.

for(i=0;i<nSpectr;i++) FlagsV[i]=Flags[i]; // Сохранение флагов пиков во втором масcиве.
// Отбрасывание пиков с малой амплитудой для нахождения первого пика.
for(i=nFrMin;i<nFrMax;i++) { if(FlagsV[i]==0) continue; v=Sp[i];
if(v<PGP->ampSmPeaksMS||v*coeNorm<ampMax*PGP->ampSmPeaksAbs) FlagsV[i]=0;}

//xxx zzz
//mmm
sprintf(TxtStr,"nFrI>=nFrIMax: %d %d",nFrI,nFrIMax); MessageBox(NULL,TxtStr,"",MB_EX);

//xxx zzz
//mmm
if(flRep!=0&&flOut!=0) {
sprintf(TxtStr,"num,frI,nFrI: %d %f %d",num,frI,nFrI); MessageBox(NULL,TxtStr,"",MB_EX);
}
//xxx zzz
//mmm
if(fl==0&&flOut!=0) {
sprintf(TxtStr,"num,nFrI: %d %d",num,nFrI); MessageBox(NULL,TxtStr,"After CheckPeak",MB_EX);
}
//xxx
flRep=1;

//xxx zzz
//mmm
if(err!=0&&flOut!=0) {
sprintf(TxtStr,"err: %d",err); MessageBox(NULL,TxtStr,"FindPeaks",MB_EX);
}
GetChBox(hDlg,IDC_CHECK_CH_PHASE,&flPhase);

//-----------------------------------------------------------------------------------------------------------
// Получение структуры.

strAnSnd *strAnSndArr::Get(BYTE num)
{
if(IsOK()!=0) return NULL; if(num>=nArr) return NULL; return pArr+num;
}

//-----------------------------------------------------------------------------------------------------------
// Синтез звука.

BYTE Synthesis(float *Wave,UINT nPoints,float Amp,USHRT nStep,clInpLayArr *pPeaks,BYTE nPM,double dt,
float Freq)
{
BYTE SumCos(UINT i,double *Peaks,BYTE nPeaks,double dt,float Freq,float *Res); // Расчёт волновой формы при синтезе звука.

BYTE nPeaks,ber; USHRT ia; int iw; UINT i,j,k,kI; float v,*FunWin; double coe; struct strInpLay *pIL;

if(Wave==NULL) return 1; if(nPoints==0) return 2; if(nStep==0) return 3;
if(pPeaks==NULL) return 4; if(pPeaks->IsOK()!=0) return 5;
if(pPeaks->nData>UINT_MAX-2) return 6; if(pPeaks->nData+2>UINT_MAX/nStep) return 7;
if(dt<=0.) return 8; if(Freq<=0.0F) return 9;

FunWin=NULL; ber=0;
FunWin=new float[nStep]; if(FunWin==NULL) { ber=10; goto end;}
coe=M_PI/(double)nStep; for(ia=0;ia<nStep;ia++) { v=(float)(1.+cos(coe*(double)ia)); FunWin[ia]=v*0.5F;} // Нахождение функции сглаживания.

pIL=pPeaks->Get(pPeaks->nData/2); if(pIL==NULL) { ber=11; goto end;} if(pIL->IsOK()!=0) { ber=12; goto end;}
if(nPM==0) nPeaks=pIL->n; else nPeaks=MIN(pIL->n,nPM);
for(k=0;k<nPoints;k++) {
if(SumCos(k,pIL->Values,nPeaks,dt,Freq,&v)!=0) { ber=14; goto end;}
Wave[k]=v*Amp;
}

/* xxx zzz
for(k=0;k<nPoints;k++) Wave[k]=0.0F;
for(i=0;i<pPeaks->nData;i++) { kI=i*(UINT)nStep;
pIL=pPeaks->Get(i); if(pIL==NULL) { ber=11; goto end;} if(pIL->IsOK()!=0) { ber=12; goto end;}

for(j=0;j<(UINT)nStep*2-1;j++) { k=kI+j; if(k>=nPoints) break;
iw=(int)j-(int)nStep+1; if(iw>=0) ia=(USHRT)iw; else ia=(USHRT)(-iw); if(ia>=nStep) { ber=13; goto end;}
if(nPM==0) nPeaks=pIL->n; else nPeaks=MIN(pIL->n,nPM);
if(SumCos(k,pIL->Values,nPeaks,dt,Freq,&v)!=0) { ber=14; goto end;}
Wave[k]+=v*Amp*FunWin[ia];}}
*/

end: SAFE_DELETE_ARR(FunWin); return ber;
}

#define FreqLF_Stand 100.0F // Частота фильтра, отбрасывающего нижние частоты (Гц) - стандартное значение.
float FreqLF; // Частота фильтра, отбрасывающего нижние частоты (Гц).

//-----------------------------------------------------------------------------------------------------------
// Синтез звука.

BYTE Synthesis(float *Wave,UINT nPoints,float Amp,USHRT nStep,clInpLayArr *pPeaks,BYTE nPM,double dt,float Freq)
{
BYTE SumCos(UINT x,double *Peaks,BYTE nPeaks,double dt,float Freq,float *Res); // Расчёт волновой формы при синтезе звука.
BYTE SumCosCorr(UINT x,double *Peaks,BYTE nPeaks,double dt,float Freq,float *Res); // Расчёт волновой формы при синтезе звука с коррекцией частот.

BYTE nPeaks,flIncHigh,ber; USHRT ia; int iw; UINT i,j,k,kI; float v,*FunWin; double coe; struct strInpLay *pIL;

if(Wave==NULL) return 1; if(nPoints==0) return 2; if(nStep==0) return 3;
if(pPeaks==NULL) return 4; if(pPeaks->IsOK()!=0) return 5;
if(pPeaks->nData>UINT_MAX-2) return 6; if(pPeaks->nData+2>UINT_MAX/nStep) return 7;
if(dt<=0.) return 8; if(Freq<=0.0F) return 9;
flIncHigh=flagIncHighSynth;
for(k=0;k<nPoints;k++) Wave[k]=0.0F;

FunWin=NULL; ber=0;
FunWin=new float[nStep]; if(FunWin==NULL) { ber=10; goto end;}
coe=M_PI/(double)nStep; for(ia=0;ia<nStep;ia++) { v=(float)(1.+cos(coe*(double)ia)); FunWin[ia]=v*0.5F;} // Нахождение функции сглаживания.

for(i=0;i<pPeaks->nData;i++) { kI=i*(UINT)nStep;
pIL=pPeaks->Get(i); if(pIL==NULL) { ber=11; goto end;} if(pIL->IsOK()!=0) { ber=12; goto end;}

for(j=0;j<(UINT)nStep*2-1;j++) { k=kI+j; if(k>=nPoints) break;
iw=(int)j-(int)nStep+1; if(iw>=0) ia=(USHRT)iw; else ia=(USHRT)(-iw); if(ia>=nStep) { ber=13; goto end;}
if(nPM==0) nPeaks=pIL->n; else nPeaks=MIN(pIL->n,nPM);
if(flIncHigh==0) { if(SumCos(k,pIL->Values,nPeaks,dt,Freq,&v)!=0) { ber=14; goto end;}}
else { if(SumCosCorr(k,pIL->Values,nPeaks,dt,Freq,&v)!=0) { ber=15; goto end;}}
Wave[k]+=v*Amp*FunWin[ia];}}

end: SAFE_DELETE_ARR(FunWin); return ber;
}

flIncHigh=flagIncHighSynth;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы для алгоритма синтеза звука по гармоникам.

#define flagIncHighSynth 1 // Флаг увеличения амплитуд высоких гармоник при синтезе звука.

//xxx
if(flOut!=0&&(be!=0||flErr!=0||typNet>=nTypNNW)) {
sprintf(TxtStr,"be,flErr,typNet: %d %d %d",be,flErr,typNet);
MessageBox(NULL,TxtStr,"FindPeaks",MB_EX);}

//-----------------------------------------------------------------------------------------------------------
// Нахождение весовой функции окна.

BYTE GetWinCoe(BYTE meth,float *pWinCoe)
{
if(pWinCoe==NULL) return 1;
switch(meth) { default: *pWinCoe=1; break;
case methSpFour_CosHann: *pWinCoe=0.5F; break; // Функция Ханна (косинусоидальное сглаживание).
case methSpFour_Gauss: *pWinCoe=coeWinWidGauss; break; // Функция Гаусса.
case methSpFour_KaisBess: *pWinCoe=4.54F; break; // Окно Кайзера-Бесселя.
}
return 0;
}

if(GetWinCoe(Param.methSpFour,&WinCoe)!=0) { ber=11; goto end;}

SpectrAmp[szTimeMax][szFreqMax]

sz_Time=sz_Freq=0; st_Time=st_Freq=0.;

USHRT sz_Time,sz_Freq; 
double st_Time,st_Freq;

//-----------------------------------------------------------------------------------------------------------
// Расчёт диаграммы.

BYTE clMain::ComputeDiag(void)
{
BYTE GetN_(USHRT nPoints,USHRT *Np,USHRT NpM,BYTE *Mp); // Даёт минимальное число 'Np', являющееся 2 в целой степени, которое превышает 'nPoints'.
BYTE GetWeightWinSTFT(BYTE meth,float *Weight,USHRT nP,float Wid); // Нахождение весовой функции окна при спектральном разложении.
BYTE FastFT(complex *A,complex *B,BYTE M,SCHAR dir,BYTE prcMess); // Быстрое преобразование Фурье.
BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP,
  BYTE *typNet,BYTE *flErr); // Нахождение относительных амплитуд и частот спектральных линий.
BYTE RecognSoundNNW(float *Spectr,UINT nSpectr,float dFr,strNNW *NNW_Vowel,strNNW *NNW_Cons,pFunDecSnd DecSnd,
  PNT_DATA Pnt,BYTE *numSnd,BYTE *typSnd,BYTE flOut); // Распознавание звуков методом нейронных сетей.
BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE typ,BYTE *typSnd,BYTE *numSnd); // Функция принятия решения при распознавании звука - простейший пороговый классификатор, основанный на текущих значениях.
BYTE GetSymbSound(BYTE num,BYTE typ,char *pSymb); // Получение символа звука.

BYTE M,j,numSnd,typSnd,typNet,nPeaks,be,ber; SHRT iv,nv; USHRT nWinWid,nPoints,nPh,n; UINT i,k,nTime;
__int64 l; float v,*Weight,dFr; double d,WinStep; complex *A,*B; char Symb; struct strSpectrLine *pSpL;

FreeDiag(); // Освобождение памяти для диаграммы.
if(Snd.IsOK()!=0) { Message(IDS_Mess_FileNotOpen,MB_ST); return 1;}
if(Param.IsOK()!=0) return 2;

v=Param.Time_Width; if(Param.methSpFour==methSpFour_Gauss) v*=coeWinWidGauss;
nWinWid=GetUSHRT_Test((double)v/Snd.dt); if(nWinWid<nWinWid_Min) nWinWid=nWinWid_Min;
be=GetN_(nWinWid,&nPoints,0,&M); if(be==messRet) { Message(IDS_Mess_LargeTimeWin,MB_ST); return 3;} if(be!=0) return 4;
nPh=nPoints/2; if(nPh>szFreqMax) { Message(IDS_Mess_LargeFreqArr,MB_ST); return 5;}

d=(double)(Snd.ln-1)*Snd.dt; nTime=GetUINT_Test(d/(double)Param.Time_Step); if(nTime==0) return 6;
if(nTime>szTimeMax) { Message(IDS_Mess_LargeTimeArr,MB_ST); return 7;}
dFr=(float)(1./(Snd.dt*(double)nPoints));

if(nTime>1) WinStep=d/(float)(nTime-1); else WinStep=0.0;

//aaa
if(SpectrAmp.Alloc(UINT nArr_,UINT ln_);

A=B=NULL; Weight=NULL; ber=0;
if(AllocComplex(&A,(size_t)nPoints)!=0) { ber=8; goto end;}
if(AllocComplex(&B,(size_t)nPoints)!=0) { ber=9; goto end;}
if(AllocFloat(&Weight,(size_t)nPh)!=0) { ber=10; goto end;}

// Нахождение весовой функции окна.
//aaa
if(Param.methSpFour!=methSpFour_NoWin) { v=Param.Time_Width*0.5F/(float)Snd.dt;
if(GetWeightWinSTFT(Param.methSpFour,Weight,nPh,v)!=0) { ber=11; goto end;}}

// Цикл по временным точкам.
for(i=0;i<nTime;i++) { k=GetUINT_Test((double)i*WinStep/Snd.dt);
for(n=0;n<nPoints;n++) { iv=(SHRT)((int)n-(int)nPh); if(iv>=0) nv=iv; else nv=-iv;
l=(__int64)k+(__int64)iv; if(l<0||l>=Snd.ln) v=0.0F; else v=Snd.Snd[l];
if(Param.methSpFour!=methSpFour_NoWin) { if(nv<nPh) v*=Weight[nv]; else v=0.0F;}
A[n]=complex((double)v,0.);}

if(FastFT(A,B,M,1,1)!=0) { ber=12; goto end;}

for(n=0;n<nPh;n++) SpectrAmp[i][n]=(float)abs(B[n]);

// Нахождение спектральных линий.
typNet=UCHAR_MAX; pSpL=SpLines[i];
be=FindPeaks(nPh,SpectrAmp[i],dFr,nPeaksMax,pSpL,&ParGetPeaks,&typNet,NULL);
if(be!=0||typNet!=typNNW_Vowel) { if(be!=0) nPeaks=0; else nPeaks=nPeaksCons;
for(j=nPeaks;j<nPeaksMax;j++) (pSpL+j)->Zero();}
nPeaks=0; for(j=0;j<nPeaksMax;j++) if((pSpL+j)->AmpRel!=0.0F) nPeaks++; ResPeaks[i]=nPeaks; // Подсчёт числа пиков.

// Распознавание методом нейронных сетей.
typSnd=0; numSnd=UCHAR_MAX;
if(DlgDBFNNW.IsDoTrain()==0)
be=RecognSoundNNW(SpectrAmp[i],nPh,dFr,&NNW_Vowel,&NNW_Cons,DecSnd_Instant,NULL,&numSnd,&typSnd,0); else be=messRet;
if(be!=0) numSnd=UCHAR_MAX; ResNNW[i]=numSnd;
//aaa
if(GetSymbSound(numSnd,typSnd,&Symb)!=0) Symb=' '; RowText[i]=Symb;
if(WinViewNNW.hwnd!=NULL) WinViewNNW.DrawNet(); // Перерисовка изображения сети.

ShowProgress(hwndProgr,hwndPerc,i+1,nTime); ProcMess(); // Изображение процента выполнения работы.
}

ShowProgress(hwndProgr,hwndPerc,0,0); ProcMess();

sz_Time=nTime; // Размер диаграммы по времени.
sz_Freq=nPh; // Размер диаграммы по частоте.
st_Time=WinStep; // Шаг по времени при спектральном преобразовании.
st_Freq=dFr; // Шаг по частоте при спектральном преобразовании.

end: FreeComplex(&A); FreeComplex(&B); FreeFloat(&Weight); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Изображение текста в окне.

void clMain::ImageRowText(void)
{
char *cp;


//aaa
cp=""; if(SpectrAmp.nArr==0) goto end;

//if(sz_Time==0) goto end; if(sz_Time>=szTimeMax) goto end; 
RowText[sz_Time]='\0'; cp=RowText;
end: if(WinText.hwnd!=NULL) WinText.SetText(cp);
}

//-----------------------------------------------------------------------------------------------------------
// Создание массива и структур.

BYTE clSpLinesArr::Create(UINT nArr_,BYTE nSpL_)
{
UINT i;

Free(); if(nArr_==0) return 1; if(nSpL_==0) return 2; if(Create(nArr_)!=0) return 3;


return 0;
}

strSpectrLine SpLines[szTimeMax][nPeaksMax]
#define szTimeMax 20000 // Максимальный размер массива диаграммы по времени.
#define szFreqMax 4096 // Максимальный размер массива диаграммы по частоте.

#define flOutRes_Peaks 0 // Вывод спектральных линий.
#define flOutRes_Sound 1 // Вывод символов.

//#define flOutRes flOutRes_Peaks // Вывод спектральных линий.
#define flOutRes flOutRes_Sound // Вывод символов.

// Вывод спектральных линий.
//aaa
if(fl==flOutRes_Peaks) {
Res=ResPeaks[i];
if(Res==0) R=G=B=0; else {
numCol=(Res-1)/4; if(numCol>=6) numCol=5;
numInt=Res-1-numCol*4;
switch(numCol) { default:
case 0: R=1; G=B=0; break; // Красный.
case 1: R=G=1; B=0; break; // Жёлтый.
case 2: R=0; G=1; B=0; break; // Зелёный.
case 3: R=G=0; B=1; break; // Синий.
case 4: R=0; G=B=1; break; // Голубой.
case 5: R=B=1; G=0; break; // Фиолетовый.
}
numInt=(BYTE)MIN(64*((USHRT)numInt+1),255);
R*=numInt; G*=numInt; B*=numInt;}
}

nPeaks=0; for(j=0;j<nPeaksMax;j++) if((pSpL+j)->AmpRel!=0.0F) nPeaks++; ResPeaks[i]=nPeaks; // Подсчёт числа пиков.

ResPeaks[szTimeMax]

//if(WinViewNNW.hwnd!=NULL) WinViewNNW.DrawNet(); // Перерисовка изображения сети.

//-----------------------------------------------------------------------------------------------------------
// Изображение текста в окне.

BYTE clMain::SetWinText(char *Text)
{
char *cp;

//aaa
cp=""; if(SpectrAmp.nArr==0) goto end; RowText[]='\0'; cp=RowText;
end: if(WinText.hwnd!=NULL) WinText.SetText(Text);

char RowText[szTimeMax+1];

//-----------------------------------------------------------------------------------------------------------
// Распознавание звуков методом нейронных сетей.

BYTE RecognSoundNNW(float *Spectr,UINT nSpectr,float dFr,strNNW *NNW_Vowel,strNNW *NNW_Cons,
pFunDecSnd DecSnd,PNT_DATA Pnt,BYTE *numSnd,BYTE *typSnd,BYTE flOut)
{
BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nSpLines,strSpectrLine *SpLines,strParGetPeaks *PGP,
  BYTE *typNet,BYTE *flErr); // Нахождение относительных амплитуд и частот спектральных линий.

BYTE j,nSpLMax,nPeaks,flNNW,num,typNet,flErr,typ,be,ber; struct strNNW *pNNW; struct strInpLay InpLay;
struct strLay *pLay; struct strSpectrLine *pSpL;

if(Spectr==NULL) return 1; if(nSpectr==0) return 2; if(dFr<=0.0F) return 3;
if(NNW_Vowel==NULL) return 4; if(NNW_Cons==NULL) return 5; if(DecSnd==NULL) return 6;
if(numSnd==NULL) return 7; if(typSnd==NULL) return 8;
nSpLMax=nPeaksMax; if(nSpLMax==0) return 9;

pSpL=NULL; ber=0;
if(InpLay.Alloc(nSpLMax)!=0) { ber=10; goto end;}
pSpL=new strSpectrLine[nSpLMax]; if(pSpL==NULL) { ber=11; goto end;}

// Нахождение спектральных линий.
typNet=UCHAR_MAX;
be=FindPeaks(nSpectr,Spectr,dFr,nSpLMax,pSpL,&ParGetPeaks,&typNet,&flErr);
if(flOut!=0&&flErr!=0) { Message(IDS_ErrParFindPeaks,MB_ST);
sprintf(TxtStr,"Error: %d",flErr); MessageBox(NULL,TxtStr,"",MB_EX);}
if(be!=0||typNet>=nTypNNW) { nPeaks=0; for(j=0;j<nSpLMax;j++) (pSpL+j)->Zero();}
else { nPeaks=0; for(j=0;j<nSpLMax;j++) if((pSpL+j)->AmpRel!=0.0F) nPeaks++;}

// Распознавание методом нейронных сетей.
flNNW=0; if(typNet>=nTypNNW) goto eNNW;
if(typNet==typNNW_Vowel) pNNW=NNW_Vowel; else pNNW=NNW_Cons; if(typNet!=pNNW->typ) goto eNNW;
if(pNNW==NULL) goto eNNW; if(pNNW->flOK==0) goto eNNW;
for(j=0;j<nSpLMax;j++) InpLay.Values[j]=pSpL[j].AmpRel; // Задание входного массива.
if(pNNW->Compute(&InpLay)!=0) goto eNNW;
pLay=pNNW->Get(pNNW->nLay-1); if(pLay==NULL) goto eNNW; if(pLay->IsOK()!=0) goto eNNW;
if((*DecSnd)(Pnt,pLay,pNNW->typ,&typ,&num)!=0) goto eNNW;
flNNW=1;
eNNW: if(flNNW==0) *numSnd=*typSnd=UCHAR_MAX; else { *numSnd=num; *typSnd=typ;}

end: InpLay.Free(); SAFE_DELETE_ARR(pSpL); return ber;
}

#define FltAR_WidTime_Stand 0.085F // Ширина временного окна (секунды), стандартное значение.
#define FltAR_WidTime_Min 1.e-2F // Минимальная ширина временного окна (секунды).
#define FltAR_StepTime_Stand 0.02F // Шаг по времени (секунды), стандартное значение.
#define FltAR_StepTime_Min 1.e-2F // Шаг по времени (секунды), минимальное значение.

Wid=FltAR_WidTime_Stand; Step=FltAR_StepTime_Stand; 

//aaa xxx
BYTE ProcAutoRegr(float *Signal,UINT nPoints,double dt,clSpDiag *Diag,float tWidth,float tStep,
  strParProcAR *ParAR,PNT_DATA Pnt,pFunShowProgr FSP,BYTE *flStop); // Обработка авторегрессионным методом.
be=ProcAutoRegr(Snd.Snd,Snd.ln,Snd.dt,&SpectrAmp,ParSpectr.Time_Width,ParSpectr.Time_Step,&ParProcAR,
(PNT_DATA)this,ShowProgrMain,&flStopProc); // Обработка авторегрессионным методом.

// Рисование курсора на выбранном времени.
if(DlgDBFNNW.selDBS==NULL||DlgDBFNNW.flLoadFile==0||DlgDBFNNW.flBlkTime!=0) {
hPen=hPenP=NULL;
CrSelPen(hdc,&hPen,&hPenP,1,ColCursorDiag);
x=CoordTime-pScDiagH; MoveToEx(hdc,x,0,NULL); LineTo(hdc,x,dyW);
UnSelDelPen(hdc,&hPen,&hPenP);
}

if(ber!=0&&ber!=messRet) {
//mmm xxx
sprintf(TxtStr,"ber: %d",ber); MessageBox(NULL,TxtStr,"TrainNNW_Group",MB_EX);
}

if(be!=0) {
//mmm
sprintf(TxtStr,"StepFindAdaptStepGroup be: %d",be); MessageBox(NULL,TxtStr,"",MB_EX);
}

// xxx mmm
/*
if(pLay->Denom<SmCnst24_d) {
sprintf(TxtStr,"i,pLay->Denom,Wei: %d %lf %lf",i,pLay->Denom,Wei);
MessageBox(NULL,TxtStr,"strNNW::FindAdaptStepGroup",MB_EX);
}
*/

// xxx mmm
/*
if(Den==0.) {
sprintf(TxtStr,"Num,Den,Wei: %lf %lf %lf",Num,Den,Wei); MessageBox(NULL,TxtStr,"strLay::AddNumDenomAdaptStep",MB_EX);
}
*/
//xxx
/*
if(flAlpha!=0&&fabs(v)<SmCnst24_d) {
//mmm
sprintf(TxtStr,"j,Lay->n: %d %d Err,pNeur->Val,f: %lf %lf %lf",j,Lay->n,pNeur->Err,pNeur->Val,f);
MessageBox(NULL,TxtStr,"AddVectors: v<SmCnst24_d",MB_EX);
}
*/

//mmm aaa xxx
sprintf(TxtStr,"i: %d Denom: %lf",i,d); MessageBox(NULL,TxtStr,"strNNW::FindAlphaGroup d<SmCnst24_d",MB_EX);
#define coeWinWidGauss 2.0F // Коэффициент, устанавливающий длину временного окна для функции Гаусса.
v=; if(ParSpectr.methSpFour==methSpFour_Gauss) v*=coeWinWidGauss;

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для одного слоя.

BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,BYTE nValNeurPrev,strLay *Lay,double *Alpha); // Расчёт адаптивного шага.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

BYTE i,ber; double *Arr,Alpha; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->Neurons->IsOK()!=0) return 2;
Arr=NULL; ber=0;
Arr=new double[LayPrev->n]; if(Arr==NULL) { ber=3; goto end;}
for(i=0;i<LayPrev->n;i++) { pNeur=LayPrev->Get(i); if(pNeur==NULL) { ber=4; goto end;}
Arr[i]=pNeur->Val;}
if(ComputeAdaptStep_(Arr,LayPrev->n,Lay,&Alpha)!=0) { ber=5; goto end;}
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) { ber=6; goto end;}
end: SAFE_DELETE(Arr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для слоя, следующего за входящим.

BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,BYTE nValNeurPrev,strLay *Lay,double *Alpha); // Расчёт адаптивного шага.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

double Alpha;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(ComputeAdaptStep_(LayPrev->Values,LayPrev->n,Lay,&Alpha)!=0) return 3;
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) return 4; return 0;
}

void ZeroVect(void); // Обнуление идентификаторов и указателей для векторов.
void ZeroParVect(void); // Обнуление идентификаторов для векторов.
void FreeVect(void); // Удаление массива векторов из памяти.
BYTE AllocVect(BYTE nWeight_); // Выделение памяти для массива векторов.
BYTE IsOK_Vect(void); // Проверки массива векторов.
BYTE SetZeroVect(void); // Установка нулей в массив векторов.

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей для векторов.

void strNeuron::ZeroVect(void)
{
nWeightV=0; WeightV=NULL; ZeroParVect();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов для векторов.

void strNeuron::ZeroParVect(void)
{
TV=AlphaV=0.;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массива векторов из памяти.

void strNeuron::FreeVect(void)
{
SAFE_DELETE_ARR(WeightV); nWeightV=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива векторов.

BYTE strNeuron::AllocVect(BYTE nWeightV_)
{
FreeVect(); if(nWeightV_==0) return 1;
WeightV=new double[nWeightV_]; if(WeightV==NULL) return 2; nWeightV=nWeightV_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива векторов.

BYTE strNeuron::IsOK_Vect(void)
{
if(Vect.IsOK()!=0) return 1; if(nWeightV!=nWeight) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка нулей в массив векторов.

BYTE strNeuron::SetZeroVect(void)
{
BYTE i;

TV=AlphaV=0.; if(IsOK_Vect()!=0) return 1; for(i=0;i<nWeightV;i++) WeightV[i]=0.; return 0;
}


//-----------------------------------------------------------------------------------------------------------
// Цикл обучения методом послойного обучения для последнего слоя.

BYTE strNNW::TrainStepSequentLayOut(BYTE numNeurOut,strInpLay *InpLay_,float AlphaConst,
float AlphaMin,float AlphaMax,BYTE flAdaptSt)
{
BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src); // Копирование структуры входного слоя сети.
BYTE SetErrLayEtal(BYTE numNeurOut,strLay *Lay); // Установка ошибок относительно эталонных значений для слоя нейронной сети.
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для первого скрытого слоя 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для слоя 'Lay'.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // Расчёт ошибок методом обратного распространения ошибки.
BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,double *Alpha); // Расчёт адаптивного шага для расчёта эталонных значений слоя.
BYTE CorrectY(BYTE numNeurOut,strLay *Lay,double Alpha); // Коррекция значений нейронов скрытого слоя.

double Alpha;

if(InpLay_==NULL) return 1; if(InpLay_->IsOK()!=0) return 2; if(IsOK()!=0) return 3;
if(AlphaConst<=0.0F) return 4; if(AlphaMin<=0.0F) return 5; if(AlphaMax<=0.0F) return 6;
if(AlphaMax<AlphaMin) return 7;
if(CopyInpLay(&InpLay,InpLay_)!=0) return 8; // Установка входного слоя.
if(ComputeTo(nLay-1)!=0) return 9; // Расчёт до последнего слоя.
if(SetErrLayEtal(numNeurOut,Layers+nLay-1)!=0) return 10; // Установка ошибок относительно эталонных значений для слоя нейронной сети.

// Нахождение и установка адаптивного шага для расчёта весов и порогов.
if(flAdaptSt!=0) {
if(nLay==1) { if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 11;}
else { if(ComputeAdaptStep(Layers+nLay-2,Layers+nLay-1,AlphaMin,AlphaMax)!=0) return 12;}}
if(flAdaptSt==0) Alpha=(double)AlphaConst; else Alpha=Layers[nLay-1].Alpha; // Установка адаптивного шага.

if(nLay==1) { if(CorrectWeightsFirst(&InpLay,Layers,Alpha)!=0) return 13;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
else { if(CorrectWeights(Layers+nLay-2,Layers+nLay-1,Alpha)!=0) return 14;} // Коррекция весов и порогов выходного слоя.

if(numLay==0) return 0;
if(ComputeErr(Layers+nLay-2,Layers+nLay-1)!=0) return 15; // Расчёт ошибок предыдущего слоя методом обратного распространения ошибки.

// Нахождение и установка адаптивного шага для расчёта эталонных значений.
if(flAdaptSt==0) Alpha=(double)AlphaConst; // Установка постоянного адаптивного шага.
else { if(ComputeAdaptStepY(Layers+nLay-2,Layers+nLay-1,AlphaMin,AlphaMax,&Alpha)!=0) return 16;} // Расчёт адаптивного шага для расчёта эталонных значений слоя.

if(CorrectY(numNeurOut,Layers+nLay-2,Alpha)!=0) return 17; // Коррекция значений нейронов последнего скрытого слоя.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Цикл обучения методом послойного обучения для скрытых слоёв.

BYTE strNNW::TrainStepSequentLay(BYTE numNeurOut,BYTE numLay,strInpLay *InpLay_,float AlphaConst,
float AlphaMin,float AlphaMax,BYTE flAdaptSt)
{
BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src); // Копирование структуры входного слоя сети.
BYTE SetErrLayEtal(BYTE numNeurOut,strLay *Lay); // Установка ошибок относительно эталонных значений для слоя нейронной сети.
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для первого скрытого слоя 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для слоя 'Lay'.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // Расчёт ошибок методом обратного распространения ошибки.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.
BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,double *Alpha); // Расчёт адаптивного шага для расчёта эталонных значений слоя.
BYTE CorrectY(BYTE numNeurOut,strLay *Lay,double Alpha); // Коррекция значений нейронов скрытого слоя.

double Alpha;

if(InpLay_==NULL) return 1; if(InpLay_->IsOK()!=0) return 2; if(IsOK()!=0) return 3;
if(numLay>=nLay-1) return 4;
if(AlphaConst<=0.0F) return 5; if(AlphaMin<=0.0F) return 6; if(AlphaMax<=0.0F) return 7;
if(AlphaMax<AlphaMin) return 8;
if(CopyInpLay(&InpLay,InpLay_)!=0) return 9; // Установка входного слоя.
if(ComputeTo(numLay)!=0) return 10; // Расчёт до слоя 'numLay'.
if(SetErrLayEtal(numNeurOut,Layers+numLay)!=0) return 11; // Установка ошибок относительно эталонных значений для слоя нейронной сети.

// Нахождение и установка адаптивного шага для расчёта весов и порогов.
if(flAdaptSt!=0) {
if(numLay==0) { if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 12;}
else { if(ComputeAdaptStep(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax)!=0) return 13;}}
if(flAdaptSt==0) Alpha=(double)AlphaConst; else Alpha=Layers[numLay].Alpha; // Установка адаптивного шага.

if(numLay==0) { if(CorrectWeightsFirst(&InpLay,Layers,Alpha)!=0) return 14;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
else { if(CorrectWeights(Layers+numLay-1,Layers+numLay,Alpha)!=0) return 15;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.

if(numLay==0) return 0;
if(ComputeErr(Layers+numLay-1,Layers+numLay)!=0) return 16; // Расчёт ошибок предыдущего слоя методом обратного распространения ошибки.

// Нахождение и установка адаптивного шага для расчёта эталонных значений.
if(flAdaptSt==0) Alpha=(double)AlphaConst; // Установка постоянного адаптивного шага.
else { if(ComputeAdaptStepY(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax,&Alpha)!=0) return 17;} // Расчёт адаптивного шага для расчёта эталонных значений слоя.

if(CorrectY(numNeurOut,Layers+numLay-1,Alpha)!=0) return 18; // Коррекция значений нейронов предыдущего скрытого слоя.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нормализация эталонных выходов нейронов для слоя 'numLay' и коррекция весовых коэффициентов для следующего слоя в методе послойного обучения.

BYTE strNNW::TrainStepSequentLayCorrect(BYTE numLay)
{
//xxx aaa
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Цикл метода последовательного послойного обучения.

BYTE strNNW::TrainStepSequentLay(BYTE numNeurOut,BYTE numLay,strInpLay *InpLay_,float AlphaConst,
float AlphaMin,float AlphaMax,USHRT nSteps,BYTE flAdaptSt)
{
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay".
BYTE SetErrLayEtal(BYTE numNeurOut,strLay *Lay); // Установка ошибок относительно эталонных значений для слоя нейронной сети.
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для первого скрытого слоя 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для слоя 'Lay'.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // Расчёт ошибок методом обратного распространения ошибки.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.
BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,double *Alpha); // Расчёт адаптивного шага для расчёта эталонных значений слоя.
BYTE CorrectY(BYTE numNeurOut,strLay *Lay,double Alpha); // Коррекция значений нейронов скрытого слоя.

USHRT iStep; double Alpha; struct strLay *pLay,*pLayPrev;

if(InpLay_==NULL) return 1; if(InpLay_->IsOK()!=0) return 2; if(IsOK()!=0) return 3;
if(numLay>=nLay-1) return 4;
if(AlphaConst<=0.0F) return 5; if(AlphaMin<=0.0F) return 6; if(AlphaMax<=0.0F) return 7;
if(AlphaMax<AlphaMin) return 8; if(nSteps==0) return 9;
if(ComputeTo(numLay)!=0) return 10; // Расчёт до слоя 'numLay'.
if(SetErrLayEtal(numNeurOut,Layers+numLay)!=0) return 11; // Установка ошибок относительно эталонных значений для слоя нейронной сети.
pLay=Get(numLay); if(pLay==NULL) return 12;
pLayPrev=Get(numLay-1); if(pLayPrev==NULL) return 13;

iStep=0;
rep:
if(iStep!=0&&numLay>0) {
// Расчёт значений в следующем слое исходя из скорректированных эталонных значений предыдущего слоя.
if(pLayPrev->SetValEqualEtal(numNeurOut)!=0) return 14; // Установка значений нейронов, равных эталонным значениям в послойном обучении.
if(ComputeLayer(pLayPrev,pLay)!=0) return 15; // Расчёт значений нейронов в слое "Lay".
}

//aaa xxx


// Нахождение и установка адаптивного шага для расчёта весов и порогов.
if(flAdaptSt!=0) {
if(numLay==0) { if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 12;}
else { if(ComputeAdaptStep(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax)!=0) return 13;}}
if(flAdaptSt==0) Alpha=(double)AlphaConst; else Alpha=Layers[numLay].Alpha; // Установка адаптивного шага.

if(numLay==0) { if(CorrectWeightsFirst(&InpLay,Layers,Alpha)!=0) return 14;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
else { if(CorrectWeights(Layers+numLay-1,Layers+numLay,Alpha)!=0) return 15;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.

if(numLay==0) return 0;
if(ComputeErr(Layers+numLay-1,Layers+numLay)!=0) return 16; // Расчёт ошибок предыдущего слоя методом обратного распространения ошибки.

// Нахождение и установка адаптивного шага для расчёта эталонных значений.
if(flAdaptSt==0) Alpha=(double)AlphaConst; // Установка постоянного адаптивного шага.
else { if(ComputeAdaptStepY(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax,&Alpha)!=0) return 17;} // Расчёт адаптивного шага для расчёта эталонных значений слоя.

if(CorrectY(numNeurOut,Layers+numLay-1,Alpha)!=0) return 18; // Коррекция значений нейронов предыдущего скрытого слоя.
iStep++; if(iStep<nSteps) goto rep;
return 0;
}


//-----------------------------------------------------------------------------------------------------------
// Установка ошибок для выходного слоя нейронной сети.

BYTE SetErrOutLay(BYTE numNeurOut,strLay *Lay)
{
BYTE i; double tr; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(i==numNeurOut) tr=1.; else tr=0.; pNeur->Err=pNeur->Val-tr;}
return 0;
}
//-----------------------------------------------------------------------------------------------------------
// Нахождение ошибки выходного слоя нейронов.

BYTE FindErrOutLay(BYTE numNeurOut,strLay *Lay,double *pErr)
{
BYTE i; double v,sum,tr; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2; if(pErr==NULL) return 3;
sum=0.; for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(i==numNeurOut) tr=1.; else tr=0.;
v=pNeur->Val-tr; sum+=v*v;}
*pErr=sum/(double)Lay->n; return 0;
}

USHRT numOutLay; // Номер нейрона выходного слоя.
pDT->numOutLay=(USHRT)num;

//-----------------------------------------------------------------------------------------------------------
// Шаг цикла метода последовательного послойного обучения - корректировка весов и порогов для слоя 'numLay'.

BYTE strNNW::TrainStepSequentLayWeights(UINT numSample,BYTE numLay,float AlphaConst,float AlphaMin,float AlphaMax,
BYTE flAdaptSt)
{
BYTE SetErrLayEtal(UINT numSample,strLay *Lay); // Установка ошибок относительно эталонных значений для слоя нейронной сети.
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для первого скрытого слоя 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для слоя 'Lay'.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.

double Alpha;

if(IsOK()!=0) return 1; if(numLay>nLay-1) return 2;
if(AlphaConst<=0.0F) return 3; if(AlphaMin<=0.0F) return 4; if(AlphaMax<=0.0F) return 5;
if(AlphaMax<AlphaMin) return 6;

if(SetErrLayEtal(numSample,Layers+numLay)!=0) return 7; // Установка ошибок относительно эталонных значений для слоя нейронной сети.
//xxx aaa
// Нахождение и установка адаптивного шага для расчёта весов и порогов.
if(flAdaptSt!=0) {
if(numLay==0) { if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 8;}
else { if(ComputeAdaptStep(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax)!=0) return 9;}}
if(flAdaptSt==0) Alpha=(double)AlphaConst; else Alpha=Layers[numLay].Alpha; // Установка адаптивного шага.

// Корректировка весовых коэффициентов и порогов.
if(numLay==0) { if(CorrectWeightsFirst(&InpLay,Layers,Alpha)!=0) return 10;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
else { if(CorrectWeights(Layers+numLay-1,Layers+numLay,Alpha)!=0) return 11;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг цикла метода последовательного послойного обучения - корректировка эталонных значений для слоя 'numLay-1'.

BYTE strNNW::TrainStepSequentLayEtal(UINT numSample,BYTE numLay,float AlphaConst,float AlphaMin,float AlphaMax,
BYTE flAdaptSt)
{
BYTE SetErrLayEtal(UINT numSample,strLay *Lay); // Установка ошибок относительно эталонных значений для слоя нейронной сети.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // Расчёт ошибок методом обратного распространения ошибки.
BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,double *Alpha); // Расчёт адаптивного шага для расчёта эталонных значений слоя.
BYTE CorrectY(UINT numSample,strLay *Lay,double Alpha); // Коррекция значений нейронов скрытого слоя.

double Alpha;

if(IsOK()!=0) return 1; if(numLay>nLay-1) return 2; if(numLay==0) return 3;
if(AlphaConst<=0.0F) return 4; if(AlphaMin<=0.0F) return 5; if(AlphaMax<=0.0F) return 6;
if(AlphaMax<AlphaMin) return 7;

if(ComputeTo(numLay)!=0) return 8; // Расчёт до слоя 'numLay'.
if(SetErrLayEtal(numSample,Layers+numLay)!=0) return 9; // Установка ошибок относительно эталонных значений для слоя нейронной сети.
if(ComputeErr(Layers+numLay-1,Layers+numLay)!=0) return 10; // Расчёт ошибок предыдущего слоя методом обратного распространения ошибки.

// Нахождение и установка адаптивного шага для расчёта эталонных значений.
if(flAdaptSt==0) Alpha=(double)AlphaConst; // Установка постоянного адаптивного шага.
else { if(ComputeAdaptStepY(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax,&Alpha)!=0) return 11;} // Расчёт адаптивного шага для расчёта эталонных значений слоя.

if(CorrectY(numSample,Layers+numLay-1,Alpha)!=0) return 12; // Коррекция значений нейронов предыдущего скрытого слоя.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение или установка массива весов и смещений или векторов весов и смещений.

BYTE strNeuron::GetSetArrSearch(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet,BYTE flArr)
{
if(flArr==0) { if(GetSetArrWeight(Arr,szArr,nFill,flSet)!=0) return 1;}
else { if(GetSetArrVect(Arr,szArr,nFill,flSet)!=0) return 2;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение или установка массива весов и смещений.

BYTE strNeuron::GetSetArrWeight(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet)
{
USHRT i,nV;

if(Arr==NULL) return 1; if(szArr==0) return 2; if(nFill==NULL) return 3; if(IsOK()!=0) return 4;
nV=(USHRT)nWeights;
if(flSmart!=0) { if(nV>USHRT_MAX-(USHRT)nWeights) return 5; nV+=(USHRT)nWeights;}
if(flTUse!=0) { if(nV==USHRT_MAX) return 6; nV++;}
if(szArr<nV) return 7;

// Получение весов и смещений.
if(flSet==0) {
for(i=0;i<nWeights;i++) Arr[i]=Weights[i];
if(flSmart!=0) for(i=0;i<nWeights;i++) Arr[i+nWeights]=Shifts[i];
if(flTUse!=0) Arr[nV-1]=T;}

// Установка весов и смещений.
else {
for(i=0;i<nWeights;i++) Weights[i]=Arr[i];
if(flSmart!=0) for(i=0;i<nWeights;i++) Shifts[i]=Arr[i+nWeights];
if(flTUse!=0) T=Arr[nV-1];}

*nFill=nV; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение или установка массива векторов весов и смещений.

BYTE strNeuron::GetSetArrVect(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet)
{
USHRT i,nV;

//xxx aaa усов - одну программу для весов и векторов.
if(Arr==NULL) return 1; if(szArr==0) return 2; if(nFill==NULL) return 3; if(IsOK_Vect()!=0) return 4;
nV=(USHRT)Vect.nWeights;
if(flSmart!=0) { if(nV>USHRT_MAX-(USHRT)nWeights) return 5; nV+=(USHRT)nWeights;}
if(flTUse!=0) { if(nV==USHRT_MAX) return 6; nV++;}
if(szArr<nV) return 7;

// Получение векторов.
if(flSet==0) {
for(i=0;i<Vect.nWeights;i++) Arr[i]=Vect.Weights[i];
if(flSmart!=0) for(i=0;i<Vect.nWeights;i++) Arr[i+Vect.nWeights]=Vect.Shifts[i];
if(flTUse!=0) Arr[nV-1]=Vect.T;}

// Установка векторов.
else {
for(i=0;i<Vect.nWeights;i++) Vect.Weights[i]=Arr[i];
if(flSmart!=0) for(i=0;i<Vect.nWeights;i++) Vect.Shifts[i]=Arr[i+Vect.nWeights];
if(flTUse!=0) Vect.T=Arr[nV-1];}

*nFill=nV; return 0;
}

BYTE GetSetArrWeight(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet); // Получение или установка массива весов и смещений.
BYTE GetSetArrVect(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet); // Получение или установка массива векторов весов и смещений.

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для слоя 'Lay'.

BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double SumPrevLay,strLay *Lay,double *Alpha); // Расчёт адаптивного шага.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

USHRT i; double Alpha,v,sum; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->Neurons->IsOK()!=0) return 2;
sum=0.; for(i=0;i<LayPrev->n;i++) { pNeur=LayPrev->Neurons+i; v=pNeur->Val; sum+=v*v;}
if(ComputeAdaptStep_(sum,Lay,&Alpha)!=0) return 3;
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для первого скрытого слоя 'Lay'.

BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double SumPrevLay,strLay *Lay,double *Alpha); // Расчёт адаптивного шага.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

USHRT i; double Alpha,v,sum;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
sum=0.; for(i=0;i<LayPrev->n;i++) { v=LayPrev->Values[i]; sum+=v*v;}
if(ComputeAdaptStep_(sum,Lay,&Alpha)!=0) return 3;
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага.

BYTE ComputeAdaptStep_(double SumPrevLay,strLay *Lay,double *pAlpha)
{
BYTE typ,coe; USHRT i; double f1,f2,y,Gamma,Gam2,v; struct strNeuron *pNeur;

if(SumPrevLay<0.) return 1; if(Lay==NULL) return 2; if(Lay->IsOK()!=0) return 3; if(pAlpha==NULL) return 4;
typ=Lay->TypFunAct;

f1=f2=0.;
switch(typ) { default: return 5;
case TypFunAct_Sigm: // Сигмоидная функция.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur==NULL) return 6;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=y*(1.-y); f1+=Gam2*v; f2+=Gam2*v*v;}
coe=4; break;

case TypFunAct_BiSigm: // Биполярная сигмоидная функция.
case TypFunAct_HypTan: // Гиперболический тангенс.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur==NULL) return 8;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=1.-y*y; f1+=Gam2*v; f2+=Gam2*v*v;}
if(typ==TypFunAct_BiSigm) coe=4; else coe=1; break;

case TypFunAct_Log: // Логарифмическая.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur==NULL) return 9;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=exp(y); v=2.*v/(1.+v*v); f1+=Gam2*v; f2+=Gam2*v*v;}
coe=1; break;

case TypFunAct_Lin: f1=f2=1.; coe=1; break; // Линейная.
}

if(f2<=0.) return 10; *pAlpha=(double)coe*f1/((1.+SumPrevLay)*f2); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для слоя 'Lay'.

BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,USHRT nValNeurPrev,strLay *Lay,double *Alpha); // Расчёт адаптивного шага.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

BYTE ber; USHRT i; double Alpha,*Arr; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->Neurons->IsOK()!=0) return 2;
Arr=NULL; ber=0;
Arr=new double[LayPrev->n]; if(Arr==NULL) { ber=3; goto end;}
for(i=0;i<LayPrev->n;i++) { pNeur=LayPrev->Neurons+i; Arr[i]=pNeur->Val;}
if(ComputeAdaptStep_(Arr,LayPrev->n,Lay,&Alpha)!=0) { ber=4; goto end;}
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) { ber=5; goto end;}
end: SAFE_DELETE(Arr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для первого скрытого слоя 'Lay'.

BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,USHRT nValNeurPrev,strLay *Lay,double *Alpha); // Расчёт адаптивного шага.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

BYTE ber; USHRT i; double Alpha,*Arr;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
Arr=NULL; ber=0;
Arr=new double[LayPrev->n]; if(Arr==NULL) { ber=3; goto end;}
for(i=0;i<LayPrev->n;i++) Arr[i]=LayPrev->Values[i];
if(ComputeAdaptStep_(Arr,LayPrev->n,Lay,&Alpha)!=0) { ber=4; goto end;}
Lay->Alpha=Alpha; if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) { ber=5; goto end;}
end: SAFE_DELETE(Arr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага.

BYTE ComputeAdaptStep_(double *ValNeurPrev,USHRT nValNeurPrev,strLay *Lay,double *pAlpha)
{
BYTE typ,coe; USHRT i,j; double f1,f2,f3,y,Gamma,Gam2,v; struct strNeuron *pNeur;

if(ValNeurPrev==NULL) return 1; if(nValNeurPrev==0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4; if(pAlpha==NULL) return 5;
typ=Lay->TypFunAct;

f1=f2=f3=0.;
switch(typ) { default: return 6;
case TypFunAct_Sigm: // Сигмоидная функция.
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur==NULL) return 7;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=y*(1.-y); f1+=Gam2*v; f2+=Gam2*v*v;}
coe=4; break;

case TypFunAct_BiSigm: // Биполярная сигмоидная функция.
case TypFunAct_HypTan: // Гиперболический тангенс.
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur==NULL) return 8;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=1.-y*y; f1+=Gam2*v; f2+=Gam2*v*v;}
if(typ==TypFunAct_BiSigm) coe=4; else coe=1; break;

case TypFunAct_Log: // Логарифмическая.
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur==NULL) return 9;
y=pNeur->Val; Gamma=pNeur->Err; Gam2=Gamma*Gamma; v=exp(y); v=2.*v/(1.+v*v); f1+=Gam2*v; f2+=Gam2*v*v;}
coe=1; break;

case TypFunAct_Lin: f1=f2=1.; coe=1; break; // Линейная.
}

//xxx aaa
if(f2<=0.) return 10; *pAlpha=(double)coe*f1/((1.+SumPrevLay)*f2); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Производная функции активации нейроннных элементов. Логарифмическая.

double FunDerAct_Log(double y)
{
double aM,v;

aM=IPE_MAX; if(y>=-aM&&y<=aM) { v=exp(y); v=(v-1./v)*0.5; v=1./sqrt(v*v+1.);} else v=0.; return v;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага.

BYTE ComputeAdaptStep_(double SumPrevLay,strLay *Lay,double *pAlpha)
{
BYTE GetCoeDeriv(BYTE typ,double *coe); // Получение коэффициента для нахождения производной в центре интервала.

BYTE typ,coe; USHRT j; double f1,f2,f,Gamma,Gam2; pFunDerAct FunDerAct; struct strNeuron *pNeur;

if(SumPrevLay<0.) return 1; if(Lay==NULL) return 2; if(Lay->IsOK()!=0) return 3; if(pAlpha==NULL) return 4;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;
if(GetCoeDeriv(Lay->TypFunAct,&coe)!=0) return 6;
f1=f2=0.;
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; f=FunDerAct(pNeur->Val); Gamma=pNeur->Err; Gam2=Gamma*Gamma;
f1+=Gam2*f; f2+=Gam2*f*f;}
if(f2<=0.) return 7; *pAlpha=(double)coe*f1/((1.+SumPrevLay)*f2); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Приращение массива векторов для нейронов слоя при групповом обучении.

BYTE AddVectors(strLay *LayPrev,strLay *Lay,double Wei,BYTE flAlpha)
{
USHRT i,j; double f,v,coeA,*pw,*ps; pFunDerAct FunDerAct; struct strNeuron *pNeur,*pNeurPr;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;

if(flAlpha!=0) { coeA=0.;
//xxx aaa
for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i; v=pNeurPr->Val; coeA+=v*v;} coeA+=1.;}

// Цикл по "j" - перебираем все нейроны второго слоя "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK_Vect()!=0) return 6;
if(pNeur->Vect.nWeights!=LayPrev->n) return 7;
f=FunDerAct(pNeur->Val); v=pNeur->Err*f*Wei; if(pNeur->flTUse!=0) pNeur->Vect.T+=v;
if(flAlpha!=0) pNeur->Vect.Alpha+=v*coeA;

// Цикл по "i" - перебираем нейроны предыдущего слоя "LayPrev".
if(pNeur->flSmart==0)
// Суммирование в массив векторов для весов.
for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i; pNeur->Vect.Weights[i]-=pNeurPr->Val*v;}
else
// Суммирование в массивы векторов для весов и смещений.
for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i;
pNeur->Vect.Weights[i]-=(pNeurPr->Val-pNeur->Shifts[i])*v;
pNeur->Vect.Shifts[i]+=pNeur->Weights[i]*v;}
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Приращение массива векторов для нейронов первого скрытого слоя при групповом обучении.

BYTE AddVectorsFirst(strInpLay *LayPrev,strLay *Lay,double Wei,BYTE flAlpha)
{
USHRT i,j; double f,v,coeA,*pw,*ps; pFunDerAct FunDerAct; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;

//xxx aaa
if(flAlpha!=0) { coeA=0.; for(i=0;i<LayPrev->n;i++) { v=LayPrev->Values[i]; coeA+=v*v;} coeA+=1.;}

// Цикл по "j" - перебираем все нейроны второго слоя "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK_Vect()!=0) return 6;
if(pNeur->Vect.nWeights!=LayPrev->n) return 7;
f=FunDerAct(pNeur->Val); v=pNeur->Err*f*Wei; if(pNeur->flTUse!=0) pNeur->Vect.T+=v;
if(flAlpha!=0) pNeur->Vect.Alpha+=v*coeA;

// Цикл по "i" - перебираем нейроны предыдущего слоя "LayPrev".
// Нахождение массива векторов для весов.
if(pNeur->flSmart==0) for(i=0;i<LayPrev->n;i++) pNeur->Vect.Weights[i]-=LayPrev->Values[i]*v;
else
// Нахождение массива векторов для весов и смещений.
for(i=0;i<LayPrev->n;i++) { pw=pNeur->Vect.Weights+i; ps=pNeur->Vect.Shifts+i;
pNeur->Vect.Weights[i]-=(LayPrev->Values[i]-pNeur->Shifts[i])*v;
pNeur->Vect.Shifts[i]+=pNeur->Weights[i]*v;}
}
return 0;
}

#define flagStrFormAdaptGroup 1 // Точная формула для расчёта адаптивного шага при групповом способе обучения.

//xxx aaa
//-----------------------------------------------------------------------------------------------------------
// Шаг нахождения сумм для нахождения адаптивного шага при обучении групповым методом.

BYTE strLay::AddNumDenomAdaptStep(double Wei)
{
USHRT i; double Num,Den,f,v; pFunDerAct FunDerAct; struct strNeuron *pNeur;

if(IsOK()!=0) return 1; FunDerAct=GetFunDerAct(TypFunAct); if(FunDerAct==NULL) return 2;
Num=Den=0.; for(i=0;i<n;i++) { pNeur=Get(i); if(pNeur==NULL) return 3;
f=FunDerAct(pNeur->Val); v=pNeur->Vect.Alpha*f; Num+=pNeur->Err*v; Den+=v*v;}
Numer+=Num*Wei; Denom+=Den*Wei; return 0;
}

BYTE ComputeAdaptStepFrom(BYTE layIni,float AlphaMin,float AlphaMax); // Расчёт полного адаптивного шага начиная со слоя 'layIni'.

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага начиная со слоя 'layIni'.

BYTE strNNW::ComputeAdaptStepFrom(BYTE layIni,float AlphaMin,float AlphaMax)
{
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для первого скрытого слоя 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax); // Расчёт адаптивного шага для слоя 'Lay'.

BYTE i,in;

if(AlphaMin<0.0F) return 1; if(AlphaMax<=0.0F) return 2; if(AlphaMax<AlphaMin) return 3;
if(Layers->IsOK()!=0) return 4; if(InpLay.IsOK()!=0) return 5; if(layIni>nLay-1) return 6;
if(layIni==0) { in=1; if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax)!=0) return 7;} else in=layIni;
if(in<nLay) for(i=in;i<nLay;i++) { if(ComputeAdaptStep(Layers+i-1,Layers+i,AlphaMin,AlphaMax)!=0) return 8;}
return 0;
}
//aaa xxx yyy 
for(i=0;i<nPoints;i++) Signal[i]-=SigAR[i];

// IDC_AXONS ................................................................................................
case IDC_AXONS: SetFlagAxons(1-flAmpAxons); break;

//xxx aaa
//xxx aaa
SetTxtBtnAmpAxons(); // Установка текста в кнопке изображения амплитуды возбуждения аксонов.

//-----------------------------------------------------------------------------------------------------------
// Установка текста в кнопке изображения амплитуды возбуждения аксонов.

void clWinViewNNW::SetTxtBtnAmpAxons(void)
{
int idS; char *cp;

if(hDlg==NULL) return; if(hInst==NULL) return;
if(flAmpAxons==0) idS=IDS_BtnNNWAxons_Excit; else idS=IDS_BtnNNWAxons_Amp;
if(LoadString(hInst,idS,TxtStr,strL_Txt)!=0) cp=TxtStr; else cp="-";
SetDlgItemText(hDlg,IDC_AXONS,TxtStr);
}


//-----------------------------------------------------------------------------------------------------------
// Установка флага изображения возбуждения аксонов.

void clWinViewNNW::SetFlagAxons(BYTE flAmpAxons_)
{
if(flAmpAxons==flAmpAxons_) return; flAmpAxons=flAmpAxons_; SetTxtBtnAmpAxons(); DrawNet();
}


//xxx aaa
v=(float)pNeur->Weights[i]; if(flExcit!=0&&flInpLay!=0) { if(i<InpLay.n) v*=(float)InpLay.Values[i]; else v=0.0F;}

void SetFlagAxons(BYTE flAmpAxons_); // Установка флага изображения возбуждения аксонов.

//xxx aaa
if(ns!=szArr) {
//mmm
sprintf(TxtStr,"ns,szArr: %d %d",ns,szArr); MessageBox(NULL,TxtStr,"",MB_EX);

}

//xxx aaa mmm
//mmm
sprintf(TxtStr,"i,nN,nP: %d %d %d nA,n: %d %d",i,nN,nP,nA,n); MessageBox(NULL,TxtStr,"GetNumVectParNNW",MB_EX);

//-----------------------------------------------------------------------------------------------------------
// Расчёт до слоя 'layFin'.

BYTE strNNW::ComputeTo(BYTE layFin)
{
BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay" - первом скрытом слое.
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay".

BYTE i;

if(IsOK()!=0) return 1; if(layFin>nLay-1) return 2;
if(ComputeLayerFirst(&InpLay,Layers)!=0) return 3; if(layFin==0) return 0;
for(i=1;i<=layFin;i++) if(ComputeLayer(Layers+i-1,Layers+i)!=0) return 4; return 0;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Типы нейронных сетей.

#define nTypNNW 2 // Число типов нейронных сетей.

#define typNNW_Vowel 0 // Для гласных и сонорных звуков.
#define typNNW_Cons  1 // Для согласных взрывных и шипящих звуков.

//mmm xxx aaa
sprintf(TxtStr,"i,numSnd,typSnd: %d %d %d",i,numSnd,typSnd);
MessageBox(NULL,TxtStr,"clMain::RecognNNW_All",MB_EX);

hr=SHGetFolderPath(NULL,CSIDL_SYSTEM,NULL,0,Path);
//mmm aaa xxx
sprintf(TxtStr,"%s",Path); MessageBox(NULL,TxtStr,"clMain::OpenProgFiles",MB_IN);

if(FAILED(hr)) { ber=3; goto end;}

dxMin=GetUSHRT_Test((int)(rc.right-rc.left)+GetSystemMetrics(SM_CXDLGFRAME)*2);
dyMin=GetUSHRT_Test((int)(rc.bottom-rc.top)+GetSystemMetrics(SM_CYDLGFRAME)*2+GetSystemMetrics(SM_CYCAPTION));

//-----------------------------------------------------------------------------------------------------------
// Изображение процента выполнения работы.

void ShowProgress(HWND hwndProgr,UINT p,UINT pMax)
{
BYTE GetBYTE(float v); // Получение числа 'BYTE' из числа 'float' с проверкой выхода за пределы 'BYTE'.

BYTE Perc;

if(pMax==0) { SendMessage(hwndProgr,PBM_SETPOS,0,0L); return;}
if(p>=pMax) Perc=100; else Perc=GetBYTE((float)p/(float)pMax*100.0F);
if(hwndProgr!=NULL) SendMessage(hwndProgr,PBM_SETPOS,(WPARAM)Perc,0L);
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Параметры команд.

#define flagTurnOffComp 1 // Флаг выключения компьютера.

#if flagTurnOffComp==0
ExitWindowsEx(EWX_LOGOFF,0);
#else
SendMessage(NULL,WM_CLOSE,0,0L);
#endif
break;

//-----------------------------------------------------------------------------------------------------------
// Частотная коррекция входного массива.

BYTE CorrFreq(strParFreqCorr *PFC,BYTE typNNW,strInpLay *InpLay)
{
USHRT i,j; double coe,amp,ampF;

if(PFC==NULL) return 1; if(PFC->IsOK()!=0) return 2;
if(InpLay==NULL) return 3; if(InpLay->IsOK()!=0) return 4;

switch(typNNW) { default: break;
// Гласные и сонорные звуки.
case typNNW_Vowel:
coe=PFC->CorrDB/(double)(PFC->numFin-PFC->numIni)/20.; ampF=pow(10.,PFC->CorrDB/20.);
for(i=0;i<InpLay->n;i++) { if(i<=PFC->numIni) continue;
if(i>=PFC->numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-PFC->numIni)); InpLay->Values[i]*=amp;}
break;
// Согласные импульсные и шипящие звуки.
case typNNW_Cons: if(InpLay->n<=nPeaksCons) return 5;
coe=PFC->CorrDB/(double)(PFC->numFin-PFC->numIni)/20.; ampF=pow(10.,PFC->CorrDB/20.);
for(j=nPeaksCons;j<InpLay->n;j++) { i=j-nPeaksCons; if(i<=PFC->numIni) continue;
if(i>=PFC->numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-PFC->numIni)); InpLay->Values[j]*=amp;}
break;
// Применение нейронных сетей сразу для всего спектра.
case typNNW_Spectr: return messRet; break;
}
return 0;
}

Тренировка
256701

// IDC_FREQ_CORR ............................................................................................
case IDC_FREQ_CORR: 
//xxx aaa
break;

// IDC_NUM_INI ..............................................................................................
case IDC_NUM_INI: break;

// IDC_NUM_FIN ..............................................................................................
case IDC_NUM_FIN: break;

// IDC_FR_CORR_DB ...........................................................................................
case IDC_FR_CORR_DB: break;

//xxx aaa if(pPar!=NULL) pPar->FreqCorrPeaks.SetDlg(hDlg);
//xxx aaa if(pPar!=NULL) pPar->FreqCorrPeaks.GetDlg(hDlg);
//xxx aaa
#define StepTriFunSpectr 200.0F 

if(FreqCorrect()!=0) return 3; // Частотная коррекция входного массива.

/* xxx aaa
//-----------------------------------------------------------------------------------------------------------
// Частотная коррекция входного массива.

BYTE strNNW::FreqCorrect(float dFr)
{
if(Par.flFrCorr==0) return 0;

// Частотная коррекция входных данных по спектральным линиям.
if(Par.flTypInpData==typDataNNW_Peaks) {
if(Par.FreqCorrPeaks.Correct(typ,Par.nPCons,&InpLay)!=0) return 1;}
// Частотная коррекция входных данных по спектру.
else { if(Par.FreqCorrSpectr.Correct(InpLay->n,InpLay->Values,dFr)!=0) return 2;}
return 0;
}
*/

BYTE Correct(BYTE typNNW,BYTE nPCons,strInpLay *InpLay); // Частотная коррекция.
BYTE Correct(USHRT nSpectr,double *Spectr,float dFr); // Частотная коррекция.

//-----------------------------------------------------------------------------------------------------------
// Частотная коррекция.

BYTE strParFreqCorrPeaks::Correct(BYTE typNNW,BYTE nPCons,strInpLay *InpLay)
{
USHRT i,j; double coe,amp,ampF;

if(IsOK()!=0) return 1; if(InpLay==NULL) return 2; if(InpLay->IsOK()!=0) return 3;
coe=CorrDB/(double)(numFin-numIni)/20.; ampF=pow(10.,CorrDB/20.);

switch(typNNW) { default: return 4;
// Гласные и сонорные звуки.
case typNNW_Vowel:
for(i=0;i<InpLay->n;i++) { if(i<=numIni) continue;
if(i>=numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-numIni)); InpLay->Values[i]*=amp;}
break;
// Согласные импульсные и шипящие звуки.
case typNNW_Cons: if(InpLay->n<=nPCons) return 5;
for(j=nPCons;j<InpLay->n;j++) { i=j-nPCons; if(i<=numIni) continue;
if(i>=numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-numIni)); InpLay->Values[j]*=amp;}
break;
}
return 0;
}
//-----------------------------------------------------------------------------------------------------------
// Частотная коррекция.

BYTE strParFreqCorrSpectr::Correct(USHRT nSpectr,double *Spectr,float dFr)
{
USHRT i,nFrMin,nFrMax; double coe,amp,ampF;

if(nSpectr==0) return 1; if(Spectr==NULL) return 2; if(dFr<=0.0F) return 3; if(CorrDB==0.0F) return 0;
nFrMin=GetUSHRT_Test(FrIni/dFr); if(nFrMin>=nSpectr) return 0;
nFrMax=GetUSHRT_Test(FrFin/dFr); nFrMax=MAX(nFrMax,nFrMin); nFrMax=MIN(nFrMax,nSpectr);
if(nFrMax>nFrMin) coe=CorrDB/(double)(nFrMax-nFrMin)/20.; else coe=0.; ampF=pow(10.,CorrDB/20.);
for(i=0;i<nSpectr;i++) { if(i<=nFrMin) continue;
if(i>=nFrMax) { amp=ampF; goto e;} if(coe>0.) amp=pow(10.,coe*(double)(i-nFrMin)); else continue;
e: Spectr[i]*=amp;}
return 0;
}

//mmm zzz xxx aaa
sprintf(TxtStr,"RecognSoundNNW: numSnd,typSnd,be: %d %d %d",numSnd,typSnd,be);
MessageBox(NULL,TxtStr,"clMain::RecognNNW",MB_EX);

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE clInpLayArr::Alloc(UINT nData_,USHRT n_)
{
BYTE ber; UINT i;

Free(); if(nData_==0) return 1; if(n_==0) return 2; ber=0; nData=nData_; n=n_;
Data=new strInpLay[nData]; if(Data==NULL) { ber=3; goto end;}
for(i=0;i<nData;i++) if(Data[i].Alloc(n)!=0) { ber=4; goto end;}
end: if(ber!=0) Free(); return ber;
}

//for(k=0;k<nInp;k++) pIL->Values[k]=(double)SpL[k].AmpRel;

//xxx aaa mmm
/*
if(ResTriFun((USHRT)pFlArr->ln,pFlArr->Arr,(float)Diag.stLn,ParInpSp.FreqDiscrTri,ParInpSp.FreqMin,
ParInpSp.FreqMax,ParInpSp.AmpThr,pIL)!=0) { ber=100; goto end;} // Разложение спектра по треугольным функциям.
*/

//xxx aaa
nFrMin=GetUSHRT_Test(ParInpSp.FreqMin/(float)Diag.stLn); if(nFrMin==0||nFrMin>nInp) { ber=100; goto end;}
if(pFlArr->ln!=nInp) { ber=101; goto end;}
s=0.; for(j=nFrMin;j<nInp;j++) { v=pFlArr->Arr[j]; s+=POW2D(v);} s/=(double)(nInp-nFrMin); s=SQRT(s);
if((float)s<ParInpSp.AmpThr) { for(j=0;j<nInp;j++) pIL->Values[j]=0.; goto eInpSp;}
v=1.0F/(float)s;
for(j=0;j<nFrMin;j++) pIL->Values[j]=0.;
for(j=nFrMin;j<nInp;j++) pIL->Values[j]=(double)(pFlArr->Arr[j]*v);
eInpSp:;

// Получение числа входных нейронов сети.
if(GetNInpDataNet(typInp,typ,pParNNW->Par.FreqMax,dFr,pParNNW->Par.dFrTri,nPeaksCons,&nInp)!=0) return 6;

if(id==IDC_SAVE_AS_NNW_VOWEL) fl=typNNW_Vowel; else fl=typNNW_Cons; 
//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strWordDict::Read(FILE *file)
{
BYTE i; int iv;

//xxx aaa
if(file==NULL) return 1; FreeTranscr();
if(ReadString(file,TxtStr,strL_Txt)!=0) return 2;
if(DupString(&Word,TxtStr)!=0) return 3;
if(fscanf(file,"%d",&iv)==EOF) return 4; if(iv<=0) return 5; if(iv>UCHAR_MAX) return 6;
if(AllocTranscr((BYTE)iv)!=0) return 7;
for(i=0;i<nTranscr;i++) if(ReadString(file,TxtStr,strL_Txt)!=0) return 8;
if(DupString(Transcr+i,TxtStr)!=0) return 9;}
return 0;
}

flLevTrueFalse=0; levTrue=levTrue_Stand; levFalse=levFalse_Stand;
if(levTrue>1.0F) return 8; if(levFalse<0.0F) return 9; if(levTrue<=levFalse) return 10; 
fp=&levTrue;
v=1.0F; if(*fp>v) { *fp=v; fl+=1<<9;}
v=levTrue_Min; if(*fp<v) { *fp=v; fl+=1<<10;}
fp=&levFalse;
if(*fp<0.0F) { *fp=0.0F; fl+=1<<11;}
v=levFalse_Max; if(*fp>v) { *fp=v; fl+=1<<12;}

if(fscanf(file,"%d%f%f",&iv,&levTrue,&levFalse)==EOF) return 12; bp=&flLevTrueFalse; if(iv==0) *bp=0; else *bp=1;
(int)flLevTrueFalse,levTrue,levFalse
SetChBox(hDlg,IDC_TRUE_FALSE_LEV,flLevTrueFalse);
SetFlEdt(hDlg,IDC_LEV_TRUE,levTrue,FormCoeff);
SetFlEdt(hDlg,IDC_LEV_FALSE,levFalse,FormCoeff);
GetChBox(hDlg,IDC_TRUE_FALSE_LEV,&flLevTrueFalse);
GetFlEdt(hDlg,IDC_LEV_TRUE,&levTrue);
GetFlEdt(hDlg,IDC_LEV_FALSE,&levFalse);
#define levTrue_Stand 0.95F // Уровень при совпадении образцов - стандартное значение.
#define levTrue_Min 0.9F // Уровень при совпадении образцов - минимальное значение.
#define levFalse_Stand 0.05F // Уровень при несовпадении образцов - стандартное значение.
#define levFalse_Max 0.1F // Уровень при несовпадении образцов - минимальное значение.
BYTE flLevTrueFalse; // Флаг использоания заданных значений при совпадении и несовпадении образцов.
float levTrue; // Уровень при совпадении образцов.
float levFalse; // Уровень при несовпадении образцов.
double levT,levF;
if(ParTrain.flLevTrueFalse==0) { levT=1.; levF=0.;}
else { levT=(float)ParTrain.levTrue; levF=(float)ParTrain.levFalse;}
