/*...........................................................................................................

// Библиотечные программы.
FastFT,GetN,GetN_,
GetWeightWinSTFT,
GetWeightWinCosHann,GetWeightGauss,GetWeightHamming,GetWeightBlackman,GetWeightBlackmanHarris,GetWeightNatall,
GetWeightBlackmanNatall,GetWeightFlatTop,GetWeightBarlett,GetWeightBarlettHann,GetWeightLanczos,
GetWeightKaiserBess,GetBesselI0,

// Структура параметров спектральной обработки.
struct strParSpProc { strParSpProc,IsOK},

// Структура нейрона.
struct strNeuron {
strNeuron,~strNeuron,
Zero,ZeroPar,Free,Alloc,IsOK,
Read,Write},

// Структура слоя нейронов.
struct strLay {
strLay,~strLay,Zero,InitPar,Free,Alloc,IsOK,Get,Read,AllocWeights},

// Структура входного слоя нейронов.
struct strInpLay {
strInpLay,~strInpLay,Zero,Free,Alloc,IsOK,Get},
CopyInpLay,

// Параметры частотной коррекции спектра.
struct strParFreqCorrSpectr { strParFreqCorrSpectr,Init,IsOK,Check,Read},
FreqCorrSpectr,

// Структура свойств и параметров нейронной сети.
struct strPropNNW { strPropNNW,Init,Read},

// Структура всей нейронной сети.
struct strNNW {
strNNW,~strNNW,Zero,Free,Alloc,IsOK,IsOK_Lay,Get,GetOutLay,Read,Read_,Read,Compute,Compute_,FreqCorrect},

// Функции для расчётов методом искусственных нейронных сетей.
ComputeLayer,ComputeLayerFirst,
GetFunAct,FunAct_Sigm,FunAct_BiSigm,FunAct_HypTang,FunAct_Log,FunAct_Lin,

// Функции для формирования входных векторов и распознавания.
RecognSoundNNW_Sp,InputDataNetSp,InpSpectrRow,
DecSnd_Instant,

// Структура параметров для анализа потока данных для звука.
struct strParAnSnd { IsOK},

// Структура для анализа потока данных для звука.
struct strAnSnd {
strAnSnd,~strAnSnd,Zero,Free,Init,IsOK,Start,Step},

// Структура для анализа потока данных для нескольких звуков.
struct strAnSndArr {
strAnSndArr,~strAnSndArr,Zero,Free,Clear,Create,IsOK,Init,Start,Step},

// Структура для анализа потока данных.
struct strAnalyseSound { Init,Start,Step},

// Структура для распознавания одного символа.
struct strRecSymb { strRecSymb,Zero,Init,IncCntSymb},

// Структура для анализа потока данных.
struct strAnalyseData { strAnalyseData,Init,Reset,GetSymb},

// Вспомогательные программы.
GetNumSound,GetSymbSound,GetOutArr,

// Структура слова в словаре.
struct strWordDict {
strWordDict,~strWordDict,Zero,Free,
ZeroTranscr,FreeTranscr,ClearTranscr,AllocTranscr,IsOK_Transcr,
Get,Read};

// Структура словаря.
struct strDictionary {
strDictionary,~strDictionary,Zero,Free,Alloc,IsOK,Get,GetWord,Read,Read_,Read};

// Структура для распознавания транскрипции слова.
struct strRecognTranscr { strRecognTranscr,Zero,Init,Start,Step},

// Структура для распознавания слова.
struct strRecognWord {
strRecognWord,~strRecognWord,Zero,ZeroRT,FreeRT,AllocRT,IsOK_RT,Init,Start,Step},

// Структура для распознавания слов.
struct strRecognAllWords {
strRecognAllWords,~strRecognAllWords,Zero,Free,Alloc,IsOK,Init,Start,Step}

...........................................................................................................*/

#include "stdafx.h"

#include "VC_con.h"
#include "cmplx.h"
#include "VC_pro.h"
#include "VC_cls.h"
#include "resource.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Программы.

BYTE AllocString(char **Str,size_t ln); // Выделение памяти для строки.
void FreeString(char **Str); // Освобождение памяти для строки.
BYTE AllocPString(char ***pStr,BYTE n); // Выделение памяти для массива указателей на char.
BYTE IsOKStr(char *str); // Проверка строки.
BYTE DupString(char **Str,char *Src); // Выделение памяти для строки и копирование.
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // Получение имени файла включая путь.
BYTE GetBYTE(float v); // Получение числа 'BYTE' из числа 'float' с проверкой выхода за пределы 'BYTE'.
USHRT GetUSHRT_Test(float v); // Получение числа 'USHRT' из числа 'float' с проверкой выхода за пределы 'USHRT'.
USHRT GetUSHRT_Test(double d); // Получение числа 'USHRT' из числа 'double' с проверкой выхода за пределы 'USHRT'.
pFunAct GetFunAct(BYTE Typ); // Функция выбора функции активации нейронных элементов.
void Message(UINT StrID,UINT typ); // Вывод сообщения.
void ProcMess(void); // Опрос очереди сообщений и обработка сообщений.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные классы и структуры.

extern struct strParAnSnd ParAnSnd[nVoices]; // Структура параметров для анализа потока данных для звука.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные переменные.

extern HINSTANCE hInst; // Идентификатор приложения.

extern char TxtStr[strL_Txt],TxtMem[strL_Txt]; // Вспомогательные строки.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Директории.

extern char *dirParNNW; // Директория с файлами параметров нейронных сетей.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Расширения файлов.

extern char *extParNNW_Vowel,*extParNNW_Cons,*extParNNW_Spectr; // Расширения файлов параметров нейронных сетей.
extern char *extNNW_Vowel,*extNNW_Cons,*extNNW_Spectr; // Расширение файлов нейронных сетей.

//-----------------------------------------------------------------------------------------------------------
// Быстрое преобразование Фурье.

BYTE FastFT(complex *A,complex *B,BYTE M,SCHAR dir,BYTE prcMess)
{
BYTE l; int i,j,k,n,le,leW,ip,N; double d,vd; complex U,W,T;

if(A==NULL) return 1; if(B==NULL) return 2; if(M==0) return 3; if(M>=31) return 4;
N=1<<M; n=N/2;
if(dir>=0) { d=1./(double)N; for(i=0;i<N;i++) *(B+i)=*(A+i)*complex(d,0.);}
else for(i=0;i<N;i++) *(B+i)=*(A+i);

j=1; for(i=0;i<N-1;i++) { if(i<j-1) { T=*(B+j-1); *(B+j-1)=*(B+i); *(B+i)=T;}
k=n; b: if(k>=j) goto a; j-=k; k=k/2; goto b; a: j+=k;}
for(l=0;l<M;l++) { if(prcMess!=0) ProcMess(); le=1<<(l+1); leW=le/2;
U=complex(1.,0.); vd=M_PI/(double)leW; d=sin(vd); if(dir<0) d=-d; W=complex(cos(vd),d);
for(j=0;j<leW;j++) { for(i=j;i<N;i+=le) { ip=i+leW; T=*(B+ip)*U; *(B+ip)=*(B+i)-T; *(B+i)+=T;} U*=W;}}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение 'N' - 2 в степени 'M'.

BYTE GetN(BYTE M,USHRT *N)
{
if(N==NULL) return 1; if(M==0||M>=16) return 2; *N=1<<M; if(*N<2) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Даёт минимальное число 'Np', являющееся 2 в целой степени, которое превышает 'nPoints'.
// Число 'Np' не должно превышать 'NpM' (если NpM>0).

BYTE GetN_(USHRT nPoints,USHRT *Np,USHRT NpM,BYTE *Mp)
{
BYTE GetN(BYTE M,USHRT *N); // Нахождение 'N' - 2 в степени 'M'.

USHRT M,N;

if(Np==NULL) return 1; if(nPoints<=1) return 2;
M=GetUSHRT_Test(LOG2(nPoints)); if(M>UCHAR_MAX) return messRet;
if(GetN((BYTE)M,&N)!=0) return 3; if(N<nPoints) { if(N>SHRT_MAX/2) return messRet; N*=2; M++;}
if(NpM>0&&N>NpM) return messRet; *Np=N; if(Mp!=NULL) *Mp=(BYTE)M; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение весовой функции окна при спектральном разложении.

BYTE GetWeightWinSTFT(BYTE meth,float *Weight,USHRT nP,float Wid)
{
BYTE GetWeightWinCosHann(float *Weight,USHRT nPoints,float Wid,float CoeWin); // Косинусоидальное сглаживание.
BYTE GetWeightHamming(float *Weight,USHRT nPoints,float Wid); // Окно Хэмминга.
BYTE GetWeightBlackman(float *Weight,USHRT nPoints,float Wid); // Окно Блэкмена.
BYTE GetWeightBlackmanHarris(float *Weight,USHRT nPoints,float Wid); // Окно Блэкмена-Харриса.
BYTE GetWeightKaiserBess(float *Weight,USHRT nPoints,float Wid,float CoeWin); // Окно Кайзера-Бесселя.
BYTE GetWeightNatall(float *Weight,USHRT nPoints,float Wid); // Окно Наталла.
BYTE GetWeightBlackmanNatall(float *Weight,USHRT nPoints,float Wid); // Окно Блэкмена-Наталла.
BYTE GetWeightFlatTop(float *Weight,USHRT nPoints,float Wid); // Окно с плоской вершиной.
BYTE GetWeightBarlett(float *Weight,USHRT nPoints,float Wid); // Окно Барлетта (треугольное).
BYTE GetWeightBarlettHann(float *Weight,USHRT nPoints,float Wid); // Окно Барлетта-Ханна.
BYTE GetWeightLanczos(float *Weight,USHRT nPoints,float Wid); // Окно Ланкзоса.
BYTE GetWeightGauss(float *Weight,USHRT nPoints,float Wid,float CoeWin); // Окно Гаусса.

BYTE be;

if(Weight==NULL) return 1; if(nP==0) return 2; if(Wid<=0.0F) return 3;
switch(meth) { default: return 4;
case methSpFour_Cos: be=GetWeightWinCosHann(Weight,nP,Wid,coeWinCos); break; // Косинусоидальное сглаживание.
case methSpFour_Hann: be=GetWeightWinCosHann(Weight,nP,Wid,0.0F); break; // Косинусоидальное сглаживание с параметром 0. (функция Ханна).
case methSpFour_Hamming: be=GetWeightHamming(Weight,nP,Wid); break; // Окно Хэмминга.
case methSpFour_Blackman: be=GetWeightBlackman(Weight,nP,Wid); break; // Окно Блэкмена.
case methSpFour_BlHarr: be=GetWeightBlackmanHarris(Weight,nP,Wid); break; // Окно Блэкмена-Харриса.
case methSpFour_KaisBess: be=GetWeightKaiserBess(Weight,nP,Wid,coeWinKaisBess); break; // Окно Кайзера-Бесселя.
case methSpFour_Natall: be=GetWeightNatall(Weight,nP,Wid); break; // Окно Наталла.
case methSpFour_BlNatall: be=GetWeightBlackmanNatall(Weight,nP,Wid); break; // Окно Блэкмена-Наталла.
case methSpFour_FlatTop: be=GetWeightFlatTop(Weight,nP,Wid); break; // Окно с плоской вершиной.
case methSpFour_Barlett: be=GetWeightBarlett(Weight,nP,Wid); break; // Окно Барлетта (треугольное).
case methSpFour_BarHann: be=GetWeightBarlettHann(Weight,nP,Wid); break; // Окно Барлетта-Ханна.
case methSpFour_Lanczos: be=GetWeightLanczos(Weight,nP,Wid); break; // Окно Ланкзоса.
case methSpFour_Gauss: be=GetWeightGauss(Weight,nP,Wid,coeWinGauss); break; // Окно Гаусса.
}
if(be!=0) return 5; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Косинусоидальное сглаживание.

BYTE GetWeightWinCosHann(float *Weight,USHRT nPoints,float Wid,float CoeWin)
{
USHRT i; float t,w,wb,c,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2;
c=CoeWin; fp=&c; if(*fp<0.0F) *fp=0.0F; if(*fp>1.0F) *fp=1.0F;
w=Wid*c; wb=Wid*(1.0F-c); if(wb<SmCnst4) return 3;

for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;} if(t<w) { *fp=1.0F; continue;}
x=(double)(Wid-t)/(double)wb; *fp=(float)(0.5*(1.-cos(x*M_PI)));}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Гаусса.

BYTE GetWeightGauss(float *Weight,USHRT nPoints,float Wid,float CoeWin)
{
USHRT i; float v,coe;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; if(CoeWin<SmCnst4) return 4;
coe=1.0F/(Wid*CoeWin);
for(i=0;i<nPoints;i++) { v=(float)i*coe; Weight[i]=(float)exp(-0.5*(double)(v*v));} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Хэмминга.

BYTE GetWeightHamming(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; *fp=(float)(0.54+0.46*cos(x));}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Блэкмена.

BYTE GetWeightBlackman(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; *fp=(float)(0.42+0.5*cos(x)+0.08*cos(2.*x));}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Блэкмена-Харриса.

BYTE GetWeightBlackmanHarris(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x,v;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; v=0.35875+0.48829*cos(x)+0.14128*cos(2.*x)+0.01168*cos(3.*x); *fp=(float)v;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Наталла.

BYTE GetWeightNatall(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x,v;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; v=0.355768+0.487396*cos(x)+0.144232*cos(2.*x)+0.012604*cos(3.*x); *fp=(float)v;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Блэкмена-Наталла.

BYTE GetWeightBlackmanNatall(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x,v;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; v=0.3635819+0.4891775*cos(x)+0.1365995*cos(2.*x)+0.0106411*cos(3.*x); *fp=(float)v;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно с плоской вершиной.

BYTE GetWeightFlatTop(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x,v;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; v=1.+1.93*cos(x)+1.29*cos(2.*x)+0.388*cos(3.*x)+0.032*cos(4.*x); *fp=(float)(v/4.64);}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Барлетта (треугольное).

BYTE GetWeightBarlett(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) *fp=0.0F; else *fp=(Wid-t)*coe;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Барлетта-Ханна.

BYTE GetWeightBarlettHann(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(Wid-t)/(double)Wid; *fp=(float)(0.62-0.24*(1.-x)-0.38*cos(x*M_PI));} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Ланкзоса.

BYTE GetWeightLanczos(float *Weight,USHRT nPoints,float Wid)
{
USHRT i; float t,coe,*fp; double x;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; coe=1.0F/Wid;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe)*M_PI; if(x<SmCnst4) *fp=1.0F; else *fp=(float)(sin(x)/x);} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Окно Кайзера-Бесселя.

BYTE GetWeightKaiserBess(float *Weight,USHRT nPoints,float Wid,float CoeWin)
{
double GetBesselI0(double x); // Расчёт модифицированной функции Бесселя 'I0'.

USHRT i; float t,coe,*fp; double x,v,coeF,alp;

if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; if(CoeWin<=0.0F) return 4;
coe=1.0F/Wid; alp=M_PI*(double)CoeWin; v=GetBesselI0(alp); if(v<SmCnst10_d) return 5; coeF=1./v;
for(i=0;i<nPoints;i++) { t=(float)i; fp=Weight+i; if(t>=Wid) { *fp=0.0F; continue;}
x=(double)(t*coe); v=1.-x*x; v=SQRT(v); v*=alp; v=GetBesselI0(v)*coeF; *fp=(float)v;}
return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define nSumBessI0 36 // Число членов в сумме при вычислении ряда для нахождении модифицированной функции Бесселя I0.

//-----------------------------------------------------------------------------------------------------------
// Расчёт модифицированной функции Бесселя 'I0'.

double GetBesselI0(double x)
{
BYTE i; double s,xh,p;

xh=x*0.5; s=1.; p=1.; for(i=1;i<nSumBessI0;i++) { p*=xh/(double)i; s+=p*p;} return s;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров спектральной обработки.

//-----------------------------------------------------------------------------------------------------------

strParSpProc::strParSpProc(void)
{
Time_Width=Time_Width_Spectr_Stand; Time_Step=Time_Step_Spectr_Stand; methSpFour=methSpFour_KaisBess;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParSpProc::IsOK(void)
{
if(Time_Width<=0.0F) return 1; if(Time_Step<=0.0F) return 2; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура нейрона.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strNeuron::strNeuron(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strNeuron::~strNeuron(void) 
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void strNeuron::Zero(void)
{
nWeights=0; Weights=Shifts=NULL; ZeroPar();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов.

void strNeuron::ZeroPar(void)
{
Val=T=0.; flTUse=1; flSmart=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массива весов из памяти.

void strNeuron::Free(void)
{
SAFE_DELETE_ARR(Weights); SAFE_DELETE_ARR(Shifts); nWeights=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива весов.

BYTE strNeuron::Alloc(USHRT nWeights_)
{
BYTE ber; USHRT i;

Free(); if(nWeights_==0) return 1; ber=0; nWeights=nWeights_;
Weights=new double[nWeights]; if(Weights==NULL) { ber=2; goto end;}
for(i=0;i<nWeights;i++) Weights[i]=0.;
if(flSmart!=0) {
Shifts=new double[nWeights]; if(Shifts==NULL) { ber=3; goto end;}
for(i=0;i<nWeights;i++) Shifts[i]=0.;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки

BYTE strNeuron::IsOK(void)
{
if(nWeights==0) return 1; if(Weights==NULL) return 2; if(flSmart!=0) { if(Shifts==NULL) return 3;} return 0;
} 

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strNeuron::Read(FILE *file)
{
USHRT i,n; int iv;

if(file==NULL) return 1; Free();
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0) return 3; if(iv>USHRT_MAX) return 4; n=(USHRT)iv;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv==0) flTUse=0; else flTUse=1;
if(fscanf(file,"%d",&iv)==EOF) return 6; if(iv==0) flSmart=0; else flSmart=1;
if(fscanf(file,"%le",&T)==EOF) return 7;
if(n==0) return 0; if(Alloc(n)!=0) return 8;
for(i=0;i<nWeights;i++) if(fscanf(file,"%le",Weights+i)==EOF) return 9;
if(flSmart!=0) for(i=0;i<nWeights;i++) if(fscanf(file,"%le",Shifts+i)==EOF) return 10;
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура слоя нейронов.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strLay::strLay(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strLay::~strLay(void) 
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void strLay::Zero(void)
{
n=0; Neurons=NULL; InitPar();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация или обнуление идентификаторов.

void strLay::InitPar(void)
{
TypFunAct=TypFunAct_Sigm; flTUse=1; flSmart=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массива нейронов из памяти.

void strLay::Free(void)
{
SAFE_DELETE_ARR(Neurons); n=0;
}

//-----------------------------------------------------------------------------------------------------------
//Выделение памяти для массива нейронов.

BYTE strLay::Alloc(USHRT n_)
{
Free(); if(n_==0) return 1; Neurons=new strNeuron[n_]; if(Neurons==NULL) return 2; n=n_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки

BYTE strLay::IsOK(void)
{
if(n==0) return 1; if(Neurons==NULL) return 2; return 0;
} 

//-----------------------------------------------------------------------------------------------------------
// Получение указателя на структуру нейрона.

strNeuron *strLay::Get(USHRT num)
{
if(IsOK()!=0) return NULL; if(num>=n) return NULL; return Neurons+num;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strLay::Read(FILE *file)
{
USHRT i,n_; int iv;

if(file==NULL) return 1; Free();
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0) return 3; if(iv>USHRT_MAX) return 4; n_=(USHRT)iv;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv==0) flTUse=0; else flTUse=1;
if(fscanf(file,"%d",&iv)==EOF) return 6; if(iv==0) flSmart=0; else flSmart=1;
if(fscanf(file,"%d",&iv)==EOF) return 7; if(iv<0) iv=0; if(iv>=nTypFunAct) iv=nTypFunAct-1; TypFunAct=(BYTE)iv;
if(n_==0) return 0; if(Alloc(n_)!=0) return 8;
for(i=0;i<n;i++) if(Neurons[i].Read(file)!=0) return 9;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массивов весовых коэффициентов для каждого нейрона. 

BYTE strLay::AllocWeights(USHRT nNeurPrev)
{
USHRT i;

if(nNeurPrev==0) return 1; if(IsOK()!=0) return 2;
for(i=0;i<n;i++) if(Neurons[i].Alloc(nNeurPrev)!=0) return 3; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура входного слоя нейронов.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strInpLay::strInpLay(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strInpLay::~strInpLay(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void strInpLay::Zero(void)
{
n=0; Values=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление из памяти.

void strInpLay::Free(void)
{
SAFE_DELETE_ARR(Values); n=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strInpLay::Alloc(USHRT n_)
{
USHRT i;

Free(); if(n_==0) return 1; Values=new double[n_]; if(Values==NULL) return 2; n=n_;
for(i=0;i<n;i++) Values[i]=0.0F; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strInpLay::IsOK(void)
{
if(n==0) return 1; if(Values==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Копирование структуры входного слоя сети.

BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src)
{
USHRT i;

if(Dst==NULL) return 1; Dst->Free(); if(Src==NULL) return 2; if(Src->IsOK()!=0) return 3;
if(Dst->Alloc(Src->n)!=0) return 4; for(i=0;i<Src->n;i++) Dst->Values[i]=Src->Values[i]; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Параметры частотной коррекции спектра.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strParFreqCorrSpectr::strParFreqCorrSpectr(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация параметров.

void strParFreqCorrSpectr::Init(void)
{
FrIni=FreqIniFrCorr_Stand; FrFin=FreqFinFrCorr_Stand; CorrDB=CorrDBFrCorr_Stand;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParFreqCorrSpectr::IsOK(void)
{
if(FrFin<FrIni) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки и коррекция.

USHRT strParFreqCorrSpectr::Check(void)
{
USHRT fl; float *fp;

fl=0;
fp=&CorrDB; if(*fp<0.0F) { *fp=0.0F; fl+=1<<0;}
fp=&FrIni; if(*fp<0.0F) { *fp=0.0F; fl+=1<<1;}
fp=&FrFin; if(*fp<0.0F) { *fp=0.0F; fl+=1<<2;}
if(FrFin<FrIni) { FrFin=FrIni; fl+=1<<4;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParFreqCorrSpectr::Read(FILE *file)
{
if(file==NULL) return 1;
if(fscanf(file,"%f%f%f",&FrIni,&FrFin,&CorrDB)==EOF) return 2;
Check(); // Проверки и коррекция.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Частотная коррекция входного массива.

BYTE FreqCorrSpectr(strParFreqCorrSpectr *PFC,float dFr,strInpLay *InpLay)
{
USHRT i; float fr; double coe,amp,ampF;

if(PFC==NULL) return 1; if(PFC->IsOK()!=0) return 2; if(dFr<=0.0F) return 3;
if(InpLay==NULL) return 4; if(InpLay->IsOK()!=0) return 5;
coe=PFC->CorrDB/(double)(PFC->FrFin-PFC->FrIni)/20.; ampF=pow(10.,PFC->CorrDB/20.);
for(i=0;i<InpLay->n;i++) { fr=dFr*(float)i; if(fr<=PFC->FrIni) continue;
if(fr>=PFC->FrFin) amp=ampF; else amp=pow(10.,coe*(double)(fr-PFC->FrIni)); InpLay->Values[i]*=amp;}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура свойств и параметров нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strPropNNW::strPropNNW(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация параметров.

void strPropNNW::Init(void)
{
flType=typNNW_Spectr; flTypInpData=typDataNNW_SpectrRow;
flFrCorr=1; typFrCorr=0; flFrCompr=typFrCompr=0; FreqCorrSpectr.Init();
dFr=0.0F; dFrTri=0.0F; FreqMin=FreqMax=0.0F;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strPropNNW::Read(FILE *file)
{
BYTE *bp; int iv;

if(file==NULL) return 1;
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0||iv>=UCHAR_MAX) return 3; flType=(BYTE)iv;
if(flType!=typNNW_Spectr) return 4;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv<0||iv>=UCHAR_MAX) return 6; flTypInpData=(BYTE)iv;
if(flTypInpData!=typDataNNW_SpectrRow) return 7;
if(fscanf(file,"%d",&iv)==EOF) return 8; bp=&flFrCorr; if(iv==0) *bp=0; else *bp=1;
if(fscanf(file,"%d",&iv)==EOF) return 9; bp=&flFrCompr; if(iv==0) *bp=0; else *bp=1;
if(fscanf(file,"%d",&iv)==EOF) return 10;
if(fscanf(file,"%f%f%f%f",&dFr,&dFrTri,&FreqMin,&FreqMax)==EOF) return 11;

// Чтение параметров частотной корекции.
if(flFrCorr!=0) {
if(fscanf(file,"%d",&iv)==EOF) return 12; bp=&typFrCorr; if(iv==0) *bp=0; else *bp=1;
if(FreqCorrSpectr.Read(file)!=0) return 13;
}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура всей нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strNNW::strNNW(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strNNW::~strNNW(void) 
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void strNNW::Zero(void)
{
nLay=0; Layers=NULL; typ=typNNW_Spectr; flOK=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массива нейронов из памяти.

void strNNW::Free(void)
{
SAFE_DELETE_ARR(Layers); nLay=0; flOK=0; InpLay.Free();
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива нейронов.

BYTE strNNW::Alloc(BYTE nLay_)
{
Free(); if(nLay_<=1) return 1; Layers=new strLay[nLay_]; if(Layers==NULL) return 2; nLay=nLay_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strNNW::IsOK(void)
{
if(nLay<=1) return 1; if(Layers==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки включая слои.

BYTE strNNW::IsOK_Lay(void)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) if(Layers[i].IsOK()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение указателя на структуру слоя.

strLay *strNNW::Get(BYTE num)
{
if(IsOK()!=0) return NULL; if(num>=nLay) return NULL; return Layers+num;
}

//-----------------------------------------------------------------------------------------------------------
// Получение указателя на структуру выходного слоя.

strLay *strNNW::GetOutLay(void)
{
if(IsOK()!=0) return NULL; return Layers+nLay-1;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strNNW::Read(FILE *file)
{
BYTE i; int iv;

if(file==NULL) return 1; Free(); Par.Init();
if(Par.Read(file)!=0) return 2; typ=Par.flType;
if(fscanf(file,"%d",&iv)==EOF) return 3; if(iv<0) return 4; if(iv>UCHAR_MAX) return 5; if(iv==0) return 0;
if(Alloc((BYTE)iv)!=0) return 6;
for(i=0;i<nLay;i++) if(Layers[i].Read(file)!=0) return 7; flOK=1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strNNW::Read_(char *fName)
{ 
BYTE err; clFileT *FT;

if(IsOKStr(fName)!=0) return 1;
FT=NULL; err=0;
FT=new clFileT(); if(FT==NULL) { err=2; goto end;}
if(FT->Open(fName,0)!=0) { err=3; goto end;} 
if(Read(FT->file)!=0) { err=4; goto end;}
end: SAFE_DELETE(FT); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strNNW::Read(char *Path,char *fName,char *ext)
{
BYTE err; char *name;

if(IsOKStr(fName)!=0) return 1; if(IsOKStr(ext)!=0) return 2;
name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,ext)!=0) { err=3; goto end;}
if(Read_(name)!=0) { err=4; goto end;}
end: FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Установка входного слоя и расчёт.

BYTE strNNW::Compute(strInpLay *InpLay_)
{
BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src); // Копирование структуры входного слоя сети.

if(IsOK()!=0) return 1; if(CopyInpLay(&InpLay,InpLay_)!=0) return 2;
if(Par.flFrCorr!=0) { if(FreqCorrect()!=0) return 3;} // Частотная коррекция входного массива.
if(Compute_(0)!=0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт начиная со слоя 'layIn'.

BYTE strNNW::Compute_(BYTE layIn)
{
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay".
BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay" - первом скрытом слое.

BYTE i,in;

if(IsOK()!=0) return 1; if(layIn>nLay-1) return 2;
if(layIn==0) { in=1; if(ComputeLayerFirst(&InpLay,Layers)!=0) return 3;} else in=layIn;
for(i=in;i<nLay;i++) if(ComputeLayer(Layers+i-1,Layers+i)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Частотная коррекция входного массива.

BYTE strNNW::FreqCorrect(void)
{
BYTE FreqCorrSpectr(strParFreqCorrSpectr *PFC,float dFr,strInpLay *InpLay); // Частотная коррекция входного массива.

float dFr;

if(typ!=typNNW_Spectr) return 1;
if(Par.flTypInpData==typDataNNW_SpectrRow) dFr=Par.dFr; else dFr=Par.dFrTri;
if(FreqCorrSpectr(&Par.FreqCorrSpectr,dFr,&InpLay)!=0) return 2; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Функции для расчётов методом искусственных нейронных сетей.

//-----------------------------------------------------------------------------------------------------------
// Расчёт значений нейронов в слое "Lay".

BYTE ComputeLayer(strLay *LayPrev,strLay *Lay)
{
USHRT i,j; double Sum,v; pFunAct FunAct; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
if(LayPrev==NULL) return 3; if(LayPrev->IsOK()!=0) return 4;
FunAct=GetFunAct(Lay->TypFunAct); if(FunAct==NULL) return 5;

// Цикл по "i" - перебираем все нейроны слоя "Lay", где нужно найти их значения.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur->nWeights!=LayPrev->n) return 6;
// Цикл по "j" - перебираем нейроны предыдущего слоя.
Sum=0.;
if(pNeur->flSmart==0) for(j=0;j<LayPrev->n;j++) Sum+=pNeur->Weights[j]*LayPrev->Neurons[j].Val;
else for(j=0;j<LayPrev->n;j++) { v=LayPrev->Neurons[j].Val-pNeur->Shifts[j]; Sum+=pNeur->Weights[j]*v;}
if(pNeur->flTUse!=0) Sum-=pNeur->T; pNeur->Val=(*FunAct)(Sum);}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт значений нейронов в слое "Lay" - первом скрытом слое.

BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay)
{
USHRT i,j,nWei; double Sum,v; pFunAct FunAct; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
if(LayPrev==NULL) return 3; if(LayPrev->IsOK()!=0) return 4;
FunAct=GetFunAct(Lay->TypFunAct); if(FunAct==NULL) return 5;

// Цикл по "i" - перебираем все нейроны слоя "Lay", где нужно найти их значения.
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; nWei=MIN(pNeur->nWeights,LayPrev->n);
// Цикл по "j" - перебираем нейроны предыдущего слоя.
Sum=0.;
if(pNeur->flSmart==0) for(j=0;j<nWei;j++) Sum+=pNeur->Weights[j]*LayPrev->Values[j];
else for(j=0;j<nWei;j++) { v=LayPrev->Values[j]-pNeur->Shifts[j]; Sum+=pNeur->Weights[j]*v;}
if(pNeur->flTUse!=0) Sum-=pNeur->T; pNeur->Val=(*FunAct)(Sum);
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Функция выбора функции активации нейронных элементов.

pFunAct GetFunAct(BYTE Typ)
{
double FunAct_Sigm(double Sum); // Функция активации нейроннных элементов. Сигмоидная функция.
double FunAct_BiSigm(double Sum); // Функция активации нейроннных элементов. Биполярная cигмоидная функция.
double FunAct_HypTang(double Sum); // Функция активации нейроннных элементов. Гиперболический тангенс.
double FunAct_Log(double Sum); // Функция активации нейроннных элементов. Логарифмическая.
double FunAct_Lin(double Sum); // Функция активации нейроннных элементов. Линейная.

pFunAct FunAct;

switch(Typ) { default: FunAct=NULL; break;
case TypFunAct_Sigm:   FunAct=FunAct_Sigm; break;      //Сигмоидная функия.
case TypFunAct_BiSigm: FunAct=FunAct_BiSigm; break;   // Биполярная cигмоидная функия.
case TypFunAct_HypTan: FunAct=FunAct_HypTang; break; // Гиперболический тангенс.
case TypFunAct_Log:    FunAct=FunAct_Log; break; // Логарифмическая.
case TypFunAct_Lin:    FunAct=FunAct_Lin; break; // Линейная.
}
return FunAct;
}

//-----------------------------------------------------------------------------------------------------------
// Функция активации нейроннных элементов. Сигмоидная функция.

double FunAct_Sigm(double Sum)
{
double y;

y=1./(1.+exp(-Sum)); return y;
}

//-----------------------------------------------------------------------------------------------------------
// Функция активации нейроннных элементов. Биполярная cигмоидная функция.

double FunAct_BiSigm(double Sum)
{
double y;

y=2./(1.+exp(-Sum))-1.; return y;
}

//-----------------------------------------------------------------------------------------------------------
// Функция активации нейроннных элементов. Гиперболический тангенс.

double FunAct_HypTang(double Sum)
{
double y,e,er;

e=exp(Sum); er=1./e; y=(e-er)/(e+er); return y;
}

//-----------------------------------------------------------------------------------------------------------
// Функция активации нейроннных элементов. Логарифмическая.

double FunAct_Log(double Sum)
{
double v;

if(Sum>=0.) v=Sum; else v=-Sum; v=log(v+sqrt(v*v+1.)); if(Sum<0.) v=-v; return v;
}

//-----------------------------------------------------------------------------------------------------------
// Функция активации нейроннных элементов. Линейная.

double FunAct_Lin(double Sum)
{
return Sum;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Функции для формирования входных векторов и распознавания.

//-----------------------------------------------------------------------------------------------------------
// Распознавание звуков методом нейронных сетей.

BYTE RecognSoundNNW_Sp(float *Spectr,USHRT nSpectr,float dFr,strNNW *pNNW,pFunDecSnd DecSnd,PNT_DATA Pnt,
BYTE *numSnd)
{
BYTE InputDataNetSp(float FreqMin,float FreqMax,float dFr,float AmpThr,float *Spectr,USHRT nSpectr,strInpLay *InpLay); // Нахождение входных данных для нейронной сети.

BYTE num,err; float FreqMin,FreqMax; struct strInpLay InpLay; struct strLay *pLay;

if(Spectr==NULL) return 1; if(nSpectr==0) return 2; if(dFr<=0.0F) return 3;
if(pNNW==NULL) return 4; if(pNNW->typ!=typNNW_Spectr) return 5;
if(pNNW->IsOK()!=0) return 6; if(pNNW->flOK==0) return 7; if(dFr!=pNNW->Par.dFr) return 8;
if(DecSnd==NULL) return 9; if(numSnd==NULL) return 10;
err=0;

// Ввод данных в нейронную сеть.
FreqMin=pNNW->Par.FreqMin;
FreqMax=pNNW->Par.FreqMax;
if(InputDataNetSp(FreqMin,FreqMax,dFr,AmpThr_Noice,Spectr,nSpectr,&InpLay)!=0) { err=1; goto eNNW;}

// Распознавание методом нейронных сетей.
if(pNNW->Compute(&InpLay)!=0) { err=2; goto eNNW;}
pLay=pNNW->GetOutLay(); if(pLay==NULL) { err=3; goto eNNW;} if(pLay->IsOK()!=0) { err=4; goto eNNW;}
if((*DecSnd)(Pnt,pLay,&num)!=0) { err=5; goto eNNW;}
eNNW: if(err!=0) *numSnd=UCHAR_MAX; else *numSnd=num;

InpLay.Free(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение входных данных для нейронной сети.

BYTE InputDataNetSp(float FreqMin,float FreqMax,float dFr,float AmpThr,float *Spectr,USHRT nSpectr,strInpLay *InpLay)
{
BYTE InpSpectrRow(USHRT nSpectr,float *Spectr,float dFr,float FreqMin,float FreqMax,float AmpThr,
  strInpLay *InpLay); // Подстановка непосредственно спектра.

BYTE be; USHRT nFrMax;

if(InpLay==NULL) return 1; if(FreqMin<=0.0F) return 2; if(FreqMax<=0.0F) return 3; if(FreqMin>=FreqMax) return 4;
if(Spectr==NULL) return 5; if(nSpectr==0) return 6; if(dFr<=0.0F) return 7;
nFrMax=GetUSHRT_Test(FreqMax/dFr); if(nFrMax==0) return 8;
nFrMax=MIN(nFrMax,nSpectr); if(InpLay->Alloc(nFrMax)!=0) return 9;
be=InpSpectrRow(nSpectr,Spectr,dFr,FreqMin,FreqMax,AmpThr,InpLay);
if(be!=messRet&&be!=0) return 10; if(be==messRet) return messRet; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Подстановка непосредственно спектра.

BYTE InpSpectrRow(USHRT nSpectr,float *Spectr,float dFr,float FreqMin,float FreqMax,float AmpThr,
strInpLay *InpLay)
{
USHRT j,nFrMin,nInp,nMax; float v; double s;

if(nSpectr==0) return 1; if(Spectr==NULL) return 2; if(dFr<=0.0F) return 3;
if(FreqMin<=0.0F) return 4; if(FreqMax<=0.0F) return 5; if(FreqMax<=FreqMin) return 6;
if(AmpThr<0.0F) return 7; if(InpLay==NULL) return 8; if(InpLay->IsOK()!=0) return 9;
nInp=InpLay->n; nMax=MIN(nSpectr,nInp);
nFrMin=GetUSHRT_Test(FreqMin/dFr); if(nFrMin>=nMax) return 10;

s=0.; for(j=nFrMin;j<nMax;j++) { v=Spectr[j]; s+=POW2D(v);} s/=(double)(nMax-nFrMin); s=SQRT(s);
if((float)s<AmpThr) return messRet;
v=1.0F/(float)s;
for(j=0;j<nFrMin;j++) InpLay->Values[j]=0.;
for(j=nFrMin;j<nMax;j++) InpLay->Values[j]=(double)(Spectr[j]*v);
if(nMax<nInp) for(j=nMax;j<nInp;j++) InpLay->Values[j]=0.;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Функция принятия решения при распознавании звука - простейший пороговый классификатор, основанный на текущих значениях.

BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE *numSnd)
{
BYTE GetNumSound(strLay *pLay,float Err,BYTE *numSnd); // Нахождение номера звука, которому соответствует максимальное значение в выходном массиве нейронов.

if(pLay==NULL) return 1; if(numSnd==NULL) return 2;
if(GetNumSound(pLay,errSoundResNNW,numSnd)!=0) return 3; return 0;
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
nBuf=0; Buf=NULL; weiStore=weiInst=coeWei=0.0F; cnt=0; sum=0.;
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
coeWei=weiStore+weiInst; if(coeWei<=0.0F) return 4; coeWei=1.0F/coeWei;
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
if(pRes==NULL) return 0; v=(float)(sum/(double)nBuf); *pRes=(v*weiStore+Val*weiInst)*coeWei; return 0;
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
for(i=0;i<nArr;i++) { if(pVal!=NULL) v=pVal[i]; else v=0.0F; if(pRes==NULL) fp=NULL; else fp=pRes+i;
if(pArr[i].Step(v,fp)!=0) return 4;}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура для анализа потока данных.

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

BYTE strAnalyseSound::Init(float tStep,BYTE flNew)
{
if(tStep<=0.0F) return 1; if(AnSnd.Init(ParAnSnd,nVoices,tStep,flNew)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Начало работы.

BYTE strAnalyseSound::Start(void)
{
if(AnSnd.Start()!=0) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг работы.

BYTE strAnalyseSound::Step(float *pVal,BYTE nVal,BYTE *numSnd)
{
BYTE i,n; float vM,v;

if(pVal==NULL) return 1; if(nVal==0) return 2; if(numSnd==NULL) return 3;
if(AnSnd.Step(pVal,Res,nVoices)!=0) return 4;

n=UCHAR_MAX; vM=0.0F;
for(i=0;i<nVoices;i++) { v=Res[i]; if(v>vM) { vM=v; n=i;}}
if(vM==0.0F||n==UCHAR_MAX) { *numSnd=UCHAR_MAX; return 0;}
if(vM<LevSoundDecStore) *numSnd=UCHAR_MAX; else *numSnd=n; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура для распознавания одного символа.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strRecSymb::strRecSymb(void)
{
Zero(); N_CntSymb=N_CntNoSymb=0;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация параметров.

void strRecSymb::Zero(void)
{
cntSymp=cntNotSymb=0;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

void strRecSymb::Init(USHRT NCntSymb,USHRT NCntNoSymb)
{
N_CntSymb=NCntSymb; N_CntNoSymb=NCntNoSymb;
}

//-----------------------------------------------------------------------------------------------------------
// Приращение счётчика символа или отсутсвия символа.

void strRecSymb::IncCntSymb(BYTE flag)
{
if(flag!=0) { if(cntSymp==USHRT_MAX) return; cntSymp++; cntNotSymb=0;}
else { if(cntNotSymb==USHRT_MAX) { cntSymp=0; return;} cntNotSymb++; if(cntNotSymb>=N_CntNoSymb) cntSymp=0;}
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура для анализа потока данных.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strAnalyseData::strAnalyseData(void)
{
Reset();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

void strAnalyseData::Init(void)
{
BYTE i; struct strParAnSnd *pPAS;

for(i=0;i<nVoices;i++) { pPAS=ParAnSnd+i; SymbArr[i].Init(pPAS->nCntSymb,pPAS->nCntNoSymb);}
pPAS=ParAnSnd+nVoices; NoSymb.Init(pPAS->nCntSymb,pPAS->nCntNoSymb);
}

//-----------------------------------------------------------------------------------------------------------
// Сброс счётчиков.

void strAnalyseData::Reset(void)
{
BYTE i;

for(i=0;i<nVoices;i++) SymbArr[i].Zero(); NoSymb.Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Получение символа из потока.

BYTE strAnalyseData::GetSymb(BYTE numSnd,BYTE flClear)
{
BYTE i,fl,flV,flN; struct strRecSymb *pRS;

flV=flN=0; if(numSnd<nVoices) flV=1; else flN=1;
for(i=0;i<nVoices;i++) { fl=0; if(flV!=0&&i==numSnd) fl=1; SymbArr[i].IncCntSymb(fl);}
NoSymb.IncCntSymb(flN);
if(numSnd>=nVoices) return 1; pRS=SymbArr+numSnd;
if(pRS->cntSymp>=pRS->N_CntSymb) { pRS->Zero(); return messRet;} return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Вспомогательные программы.

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

BYTE GetSymbSound(BYTE num,char *pSymb)
{
if(pSymb==NULL) return 1; if(num>=nVoices) return 2; *pSymb=ParAnSnd[num].Symb; return 0;
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

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура слова в словаре.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strWordDict::strWordDict(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strWordDict::~strWordDict(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strWordDict::Zero(void)
{
nTranscr=0; Word=NULL; Transcr=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strWordDict::Free(void)
{
FreeString(&Word); FreeTranscr();
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти от транскрипций.

void strWordDict::FreeTranscr(void)
{
ClearTranscr(); SAFE_DELETE_ARR(Transcr); nTranscr=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление строк из памяти.

void strWordDict::ClearTranscr(void)
{
BYTE i;

if(IsOK_Transcr()!=0) return; for(i=0;i<nTranscr;i++) FreeString(Transcr+i);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для транскрипций.

BYTE strWordDict::AllocTranscr(BYTE nTranscr_)
{
FreeTranscr(); if(nTranscr_==0) return 1;
if(AllocPString(&Transcr,nTranscr_)!=0) return 2;
nTranscr=nTranscr_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива транскрипций.

BYTE strWordDict::IsOK_Transcr(void)
{
if(Transcr==NULL) return 1; if(nTranscr==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение строки транскрипции.

char *strWordDict::Get(UINT num)
{
if(IsOK_Transcr()!=0) return NULL; if(num>=nTranscr) return NULL; return Transcr[num];
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strWordDict::Read(FILE *file)
{
BYTE i; int iv;

if(file==NULL) return 1; FreeTranscr();
if(fscanf(file,"%s",TxtStr)==EOF) return 2; if(DupString(&Word,TxtStr)!=0) return 3;
if(fscanf(file,"%d",&iv)==EOF) return 4; if(iv<=0) return 5; if(iv>UCHAR_MAX) return 6;
if(AllocTranscr((BYTE)iv)!=0) return 7;
for(i=0;i<nTranscr;i++) { if(fscanf(file,"%s",TxtStr)==EOF) return 8; if(DupString(Transcr+i,TxtStr)!=0) return 9;}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура словаря.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strDictionary::strDictionary(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strDictionary::~strDictionary(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strDictionary::Zero(void)
{
Words=NULL; nWords=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strDictionary::Free(void)
{
SAFE_DELETE_ARR(Words); nWords=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strDictionary::Alloc(UINT nWords_)
{
Free(); if(nWords_==0) return 1;
Words=new strWordDict[nWords_]; if(Words==NULL) return 2;
nWords=nWords_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива.

BYTE strDictionary::IsOK(void)
{
if(nWords==0) return 1; if(Words==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение структуры слова.

strWordDict *strDictionary::Get(UINT num)
{
if(IsOK()!=0) return NULL; if(num>=nWords) return NULL; return Words+num;
}

//-----------------------------------------------------------------------------------------------------------
// Получение текста распознанного слова.

char *strDictionary::GetWord(UINT num)
{
if(IsOK()!=0) return NULL; if(num>=nWords) return NULL; return Words[num].Word;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strDictionary::Read(char *Path,char *fName,char *ext)
{
BYTE err; char *name;

if(IsOKStr(fName)!=0) return 1; if(IsOKStr(ext)!=0) return 2;
name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,ext)!=0) { err=3; goto end;}
if(Read_(name)!=0) { err=4; goto end;}
end: FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strDictionary::Read_(char *fName)
{ 
BYTE err; clFileT *FT;

if(IsOKStr(fName)!=0) return 1;
FT=NULL; err=0;
FT=new clFileT(); if(FT==NULL) { err=2; goto end;}
if(FT->Open(fName,0)!=0) { err=3; goto end;} 
if(Read(FT->file)!=0) { err=4; goto end;}
end: SAFE_DELETE(FT); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strDictionary::Read(FILE *file)
{
BYTE ber; int iv; UINT i;

if(file==NULL) return 1; Free();
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<=0) return 3;
if(Alloc((UINT)iv)!=0) return 4;
ber=0;
for(i=0;i<nWords;i++) if(Words[i].Read(file)!=0) { ber=5; goto end;}
end: if(ber!=0) Free(); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура для распознавания транскрипции слова.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strRecognTranscr::strRecognTranscr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strRecognTranscr::Zero(void)
{
pTr=NULL; ln=cnt=cntNS=cntErr=cntErrM=0;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

BYTE strRecognTranscr::Init(char *pTr_)
{
size_t l;

Zero(); if(pTr_==NULL) return 1; l=strlen(pTr_); if(l==0) return 2; if(l>UCHAR_MAX) return 3;
pTr=pTr_; ln=(BYTE)l; cntErrM=GetBYTE((float)ln*PercWrongRecWord); if(cntErrM==0) cntErrM=1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Начало работы.

void strRecognTranscr::Start(void)
{
cnt=cntNS=cntErr=0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг работы.

BYTE strRecognTranscr::Step(char Symb)
{
if(pTr==NULL||ln==0) return 1; if(cnt>=ln) { start: Start(); return 0;}
if(Symb==pTr[cnt]) { cnt++; goto cont;} // Получаем очередной символ слова.
if(cnt<ln-1) { if(Symb==pTr[cnt+1]) { cntErr++; if(cntErr>cntErrM) goto start; cnt+=2; goto cont;}} // Продолжаем распознавание слова с пропуском одной буквы.
if(cnt>0) { cntNS++; if(cntNS>cntNSWord_Max) goto start;} return 0;
cont: if(cnt>=ln) { Start(); return messRet;} return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура для распознавания слова.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strRecognWord::strRecognWord(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strRecognWord::~strRecognWord(void)
{
FreeRT();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strRecognWord::Zero(void)
{
pWD=NULL; ZeroRT();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strRecognWord::ZeroRT(void)
{
RecTr=NULL; nRecTr=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strRecognWord::FreeRT(void)
{
SAFE_DELETE_ARR(RecTr); nRecTr=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strRecognWord::AllocRT(UINT nRecTr_)
{
FreeRT(); if(nRecTr_==0) return 1;
RecTr=new strRecognTranscr[nRecTr_]; if(RecTr==NULL) return 2;
nRecTr=nRecTr_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива.

BYTE strRecognWord::IsOK_RT(void)
{
if(nRecTr==0) return 1; if(RecTr==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

BYTE strRecognWord::Init(strWordDict *pWD_)
{
BYTE i;

FreeRT(); if(pWD_==NULL) return 1; if(pWD_->IsOK_Transcr()!=0) return 2;
if(AllocRT(pWD_->nTranscr)!=0) return 3;
for(i=0;i<nRecTr;i++) if(RecTr[i].Init(pWD_->Get(i))!=0) return 4; pWD=pWD_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Начало работы.

BYTE strRecognWord::Start(void)
{
BYTE i;

if(IsOK_RT()!=0) return 1; for(i=0;i<nRecTr;i++) RecTr[i].Start(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг работы.

BYTE strRecognWord::Step(char Symb)
{
BYTE i,fl,nRec;

if(IsOK_RT()!=0) return 1; nRec=0;
for(i=0;i<nRecTr;i++) { fl=RecTr[i].Step(Symb); if(fl==messRet) nRec++;}
if(nRec>0) return messRet; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура для распознавания слов.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strRecognAllWords::strRecognAllWords(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strRecognAllWords::~strRecognAllWords(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void strRecognAllWords::Zero(void)
{
RecWords=NULL; nWords=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strRecognAllWords::Free(void)
{
SAFE_DELETE_ARR(RecWords); nWords=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strRecognAllWords::Alloc(UINT nWords_)
{
Free(); if(nWords_==0) return 1;
RecWords=new strRecognWord[nWords_]; if(RecWords==NULL) return 2;
nWords=nWords_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива.

BYTE strRecognAllWords::IsOK(void)
{
if(nWords==0) return 1; if(RecWords==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

BYTE strRecognAllWords::Init(strDictionary *pDict)
{
UINT i;

Free(); if(pDict==NULL) return 1; if(pDict->IsOK()!=0) return 2; if(Alloc(pDict->nWords)!=0) return 3;
for(i=0;i<nWords;i++) if(RecWords[i].Init(pDict->Get(i))!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Начало работы.

BYTE strRecognAllWords::Start(void)
{
UINT i;

if(IsOK()!=0) return 1; for(i=0;i<nWords;i++) RecWords[i].Start(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг работы.

BYTE strRecognAllWords::Step(BYTE numSnd,UINT *numRec)
{
UINT i,j; char Symb;

if(IsOK()!=0) return 1; if(numSnd>=nVoices) return 2; Symb=ParAnSnd[numSnd].Symb;
j=UINT_MAX; for(i=0;i<nWords;i++) if(RecWords[i].Step(Symb)==messRet) { j=i; break;}
if(j>=nWords) return 0; if(numRec==NULL) return 3; *numRec=j; return messRet;
}
