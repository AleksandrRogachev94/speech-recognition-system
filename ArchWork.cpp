struct strParProcAR ParProcAR; // Структура параметров авторегрессионного анализа.

IDS_SpectrWinName_DolphCheb,
BYTE GetWeightDolphCheb(float *Weight,USHRT nPoints,float Wid,float CoeWin); // Окно Дольфа-Чебышева.
case methSpFour_DolphCheb: be=GetWeightDolphCheb(Weight,nP,Wid,coeWinDolphCheb); break; // Окно Дольфа-Чебышева.

//-----------------------------------------------------------------------------------------------------------
// Окно Дольфа-Чебышева.

BYTE GetWeightDolphCheb(float *Weight,USHRT nPoints,float Wid,float CoeWin)
{
if(Weight==NULL) return 1; if(nPoints==0) return 2; if(Wid<SmCnst4) return 3; if(CoeWin<=0.0F) return 4;

//aaa xxx
// Окно Кайзера-Бесселя.
if(GetWeightKaiserBess(Weight,nPoints,Wid,CoeWin)!=0) return 5;

return 0;
}

/*
Окно Дольфа-Чебышева

#define acosh(x)        (log((x) + sqrt((x) * (x) - 1)))

void DolphChebyshev (double * win, int n, double db)
{
    int i, j, m = n-1;
    for (j = 0; j < n; j++)
    {
        win[j] = 0;
        for (i = 0; i < n; i++)
        {
            double t = PI*(i - m*.5)/n;
            double x = cosh(acosh(pow(10, db / 20)) / m) * cos(t);
            double w = fabs(x) <= 1.0 ? cos(m * acos(x)) : cosh(m * acosh(x));
            win[j] += w * cos(t*(j - m*.5)*2);
        }
    }
    double scale = 1./win[n/2];
    for (i = 0; i < n; i++)
    {
        win[i] *= scale;
    }
}
*/

Дольфа-Чебышева

#define methSpFour_DolphCheb 13 // Окно Дольфа-Чебышева.

// Функции авторегрессионного анализа.
ProcAutoRegr,LevinsonDurbin,FindARSignalForw,

// Структура параметров авторегрессионного анализа.
struct strParProcAR { strParProcAR,Init,Check,Read,Write},


// Класс конвейера для нахождения корреляционных функций.
class clConveyer {
clConveyer,~clConveyer,Zero,ZeroSig,IsOKSig,ZeroBuf,FreeBuf,Alloc,IsOKBuf,IsOK,Set,Start,MoveTo,
GetCorrFunc},

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс конвейера для нахождения корреляционных функций.

//-----------------------------------------------------------------------------------------------------------

clConveyer::clConveyer(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clConveyer::~clConveyer(void)
{
FreeBuf();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void clConveyer::Zero(void)
{
ZeroBuf(); ZeroSig(); Time=0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров для сигналов.

void clConveyer::ZeroSig(void)
{
SigA=SigB=NULL; nPoints=0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки сигналов.

BYTE clConveyer::IsOKSig(void)
{
if(SigA==NULL) return 1; if(SigB==NULL) return 2; if(nPoints==0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров для вспомогательных массивов.

void clConveyer::ZeroBuf(void)
{
Sum=NULL; Buf=NULL; nCorr=lnCorr=numBuf=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти от вспомогательных массивов.

void clConveyer::FreeBuf(void)
{
SAFE_DELETE(Sum); SAFE_DELETE(Buf); nCorr=lnCorr=numBuf=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE clConveyer::AllocBuf(USHRT nCorr_,USHRT lnCorr_)
{
BYTE ber;

FreeBuf(); if(nCorr_==0) return 1; if(lnCorr_<=1) return 2;
ber=0; nCorr=nCorr_; lnCorr=lnCorr_;
Sum=new clArrDouble(); if(Sum==NULL) { ber=4; goto end;}
if(Sum->Alloc(nCorr)!=0) { ber=5; goto end;}
Buf=new clArr2Float(); if(Buf==NULL) { ber=6; goto end;}
if(Buf->Alloc(lnCorr,nCorr)!=0) { ber=7; goto end;}
end: if(ber!=0) FreeBuf(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки вспомогательных массивов.

BYTE clConveyer::IsOKBuf(void)
{
if(nCorr==0) return 1; if(lnCorr<=1) return 2;
if(Sum==NULL) return 3; if(Sum->IsOK()!=0) return 4; if(Sum->ln!=nCorr) return 5;
if(Buf==NULL) return 6; if(Buf->IsOK()!=0) return 7; if(Buf->nArr!=lnCorr) return 8;
if(Buf->ln!=nCorr) return 9; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE clConveyer::IsOK(void)
{
if(IsOKBuf()!=0) return 1; if(IsOKSig()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка указателей на сигналы, длины сигналов и другие параметры.

BYTE clConveyer::Set(float *SigA_,float *SigB_,UINT nPoints_)
{
if(SigA_==NULL) return 1; if(SigB_==NULL) return 2; if(nPoints_==0) return 3;
SigA=SigA_; SigB=SigB_; nPoints=nPoints_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение корреляции на начальном отрезке конвейера.

BYTE clConveyer::Start(void)
{
USHRT j; UINT i; __int64 iA,iB; float v; clArrFloat *P;

Time=0; if(IsOK()!=0) return 1;
for(j=0;j<nCorr;j++) Sum->Arr[j]=0.; // Обнуление массива суммирования, где находится результат - корреляционная функция.
numBuf=0;

// Цикл нахождения корреляционных функций в зависимости от времени.
for(i=0;i<(UINT)lnCorr;i++) { iA=(__int64)i;
P=Buf->Get(numBuf); if(P==NULL) return 2; if(P->IsOK()!=0) return 3;
if(numBuf==lnCorr-1) numBuf=0; else numBuf++;

// Получение нового столбца буфера.
if(iA>=0&&iA<nPoints) {
for(j=0;j<nCorr;j++) { iB=iA-(__int64)j;
if(iB>=0&&iB<nPoints) v=SigA[iA]*SigB[iB]; else v=0.0F; P->Arr[j]=v;}}
else for(j=0;j<nCorr;j++) P->Arr[j]=0.0F;

// Добавление к сумме нового столбца буфера. Суммирование по временному окну для нахождения значений корреляционной функции.
for(j=0;j<nCorr;j++) Sum->Arr[j]+=(double)P->Arr[j];}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Перемещение начала суммирования до положения 'time'.

BYTE clConveyer::MoveTo(UINT Time_)
{
USHRT j; UINT i; __int64 iA,iB; float v; clArrFloat *P;

if(IsOK()!=0) return 1; if(Time_>=nPoints) return messRet; if(Time_<Time) return messRet;
if(Time_==Time) return 0;

// Цикл нахождения корреляционных функций в зависимости от времени.
for(i=Time;i<Time_;i++) { iA=(__int64)i+(__int64)lnCorr;
P=Buf->Get(numBuf); if(P==NULL) return 2; if(P->IsOK()!=0) return 3;
if(numBuf==lnCorr-1) numBuf=0; else numBuf++;

// Удаление из суммы старого столбца буфера.
for(j=0;j<nCorr;j++) Sum->Arr[j]-=(double)P->Arr[j];

// Получение нового столбца буфера.
if(iA>=0&&iA<nPoints) {
for(j=0;j<nCorr;j++) { iB=iA-(__int64)j;
if(iB>=0&&iB<nPoints) v=SigA[iA]*SigB[iB]; else v=0.0F; P->Arr[j]=v;}}
else for(j=0;j<nCorr;j++) P->Arr[j]=0.0F;

// Добавление к сумме нового столбца буфера. Суммирование по временному окну для нахождения значений корреляционной функции.
for(j=0;j<nCorr;j++) Sum->Arr[j]+=(double)P->Arr[j];}

Time=Time_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение текущей корреляционной функции.

BYTE clConveyer::GetCorrFunc(float *CorrFunc,USHRT nCorrFunc)
{
USHRT j;

if(CorrFunc==NULL) return 1; if(nCorrFunc==0) return 2; if(nCorr==0) return 3; if(nCorrFunc>nCorr) return 4;
if(Sum==NULL) return 5; if(Sum->IsOK()!=0) return 6; if(Sum->ln!=nCorr) return 7;
for(j=0;j<nCorrFunc;j++) CorrFunc[j]=(float)Sum->Arr[j]; return 0;
}



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Функции авторегрессионного анализа.

//-----------------------------------------------------------------------------------------------------------
// Обработка авторегрессионным методом.

BYTE ProcAutoRegr(float *Signal,UINT nPoints,double dt,clSpDiag *Diag,float tWidth,float tStep,
strParProcAR *ParAR,PNT_DATA Pnt,pFunShowProgr FSP,BYTE *flStop)
{
BYTE LevinsonDurbin(float *AC,USHRT nAC,float *CoeffA,USHRT nCoeffA,USHRT *pMax,double *Sig,float DevRel,
  float DevAbs,BYTE flAkaike,USHRT lnCorr); // Нахождение параметров АР модели, решение уравнений Юла-Уолкера методом Левинсона-Дурбина.
BYTE FindARSignalForw(float *SigI,float *SigAR,UINT nSig,UINT nI,UINT nF,float *AK,USHRT nAK); // Находит сигнал по авторегрессионной модели путём предсказания вперёд.

BYTE be,ber; USHRT lnCorr,pMax,nWinStep,pM,p,*ip; UINT n,i,j,k,nTime,nTime_,nPh;
float DevRel,*Corr,*CoeffA,*SigAR,SigAbs,v,*fp; double Sig,dfr,omg; complex c,sc,H; clConveyer *Conv;
clArrFloat *pArrFr;

if(Diag==NULL) return 1; Diag->Free_St();
if(Signal==NULL) return 2; if(nPoints==0) return 3; if(dt<=0.) return 4;
if(tWidth<=0.0F) return 5; if(tStep<=0.0F) return 6; if(ParAR==NULL) return 7;

// Проверки и нахождение параметров алгоритма.
pMax=ParAR->pMax; ip=&pMax;
p=FltAR_pMaxMin; if(*ip<p) *ip=p;
p=FltAR_pMaxMax; if(*ip>p) *ip=p;
nWinStep=GetUSHRT_Test(tStep/(float)dt); if(nWinStep<2) return 8;
nTime=nPoints/(UINT)nWinStep; if(nTime==0) return 9;
if(nTime*(UINT)nWinStep<nPoints) nTime_=nTime+1; else nTime_=nTime;
lnCorr=GetUSHRT_Test(tWidth/(float)dt);
if(lnCorr<lnCorrMin) lnCorr=lnCorrMin; if((UINT)lnCorr>nPoints) return 10;
ip=&pMax; p=lnCorr/2; if(*ip>p) *ip=p; p=FltAR_pMaxMin; if(*ip<p) *ip=p;
fp=&DevRel; *fp=ParAR->DevRel;
v=FltAR_DevRelAR_Min; if(*fp<v) *fp=v;
v=FltAR_DevRelAR_Max; if(*fp>v) *fp=v;
fp=&ParAR->DevAbs; SigAbs=*fp*(*fp);
nPh=lnCorr/2;

Conv=NULL; Corr=CoeffA=SigAR=NULL; ber=0;
// Выделение памяти.
if(Diag->Alloc(nTime_,nPh)!=0) { ber=11; goto end;}
if(AllocFloat(&Corr,(size_t)(pMax+1))!=0) { ber=12; goto end;}
if(AllocFloat(&CoeffA,(size_t)pMax)!=0) { ber=13; goto end;}
if(AllocFloat(&SigAR,(size_t)nPoints)!=0) { ber=14; goto end;}

Conv=new clConveyer(); if(Conv==NULL) { ber=15; goto end;}
if(Conv->AllocBuf(pMax+1,lnCorr)!=0) { ber=16; goto end;}
if(Conv->Set(Signal,Signal,(UINT)nPoints)!=0) { ber=17; goto end;}
if(Conv->Start()!=0) { ber=18; goto end;} // Старт вычислений автокорреляционной функции в движущемся окне методом конвейера.

// Цикл по времени.
for(n=0;n<nTime_;n++) { if(n==nTime) k=nPoints; else k=n*nWinStep;
pArrFr=Diag->Get(n); if(pArrFr==NULL) { ber=19; goto end;}
if(pArrFr->IsOK()!=0) { ber=20; goto end;} if(pArrFr->ln!=nPh) { ber=21; goto end;}
if(k==0) { for(i=0;i<nPh;i++) pArrFr->Arr[i]=0.0F; continue;}
if(k<(UINT)lnCorr) {
Zero: for(i=0;i<(UINT)nWinStep;i++) { j=k-nWinStep+i; SigAR[j]=Signal[j];}
for(i=0;i<nPh;i++) pArrFr->Arr[i]=0.0F; continue;}

if(Conv->MoveTo(k-(UINT)lnCorr)!=0) { ber=22; goto end;} // Перемещение конвейера.
if(Conv->GetCorrFunc(Corr,pMax+1)!=0) { ber=23; goto end;} // Вывод автокорреляционной функции.

// Нахождение параметров АР модели, решение уравнений Юла-Уолкера методом Левинсона-Дурбина.
be=LevinsonDurbin(Corr,pMax+1,CoeffA,pMax,&pM,&Sig,DevRel,SigAbs,ParAR->flAkaike,lnCorr);
if(be==messRet) goto Zero; if(be!=0) { ber=24; goto end;}
Sig=SQRT(Sig);

// Находит сигнал по авторегрессионной модели путём предсказания вперёд.
be=FindARSignalForw(Signal,SigAR,nPoints,k-nWinStep,k,CoeffA,pM); if(be!=messRet&&be!=0) { ber=25; goto end;}

// Нахождение спектра.
dfr=0.5/(double)lnCorr;
for(i=0;i<nPh;i++) { omg=2.*M_PI*(double)i*dfr;
sc=complex(0.,0.);
for(p=0;p<pM;p++) { c=complex(CoeffA[p],0.)*exp(complex(0.,-(double)(p+1)*omg)); sc+=c;}
H=complex(1.,0.)/(complex(1.,0.)+sc); pArrFr->Arr[i]=(float)(Sig*abs(H));}
if(FSP!=NULL) (*FSP)(Pnt,n+1,nTime_); // Показ процента выполненной работы.
if(flStop!=NULL) { if(*flStop!=0) { ber=messRet; goto end;}}
}

Diag->stArr=(double)nWinStep*dt; // Шаг диаграммы по времени.
Diag->stLn=1./(dt*(double)lnCorr); // Шаг диаграммы по частоте.

end: FreeFloat(&SigAR); FreeFloat(&Corr); FreeFloat(&CoeffA); SAFE_DELETE(Conv);
if(FSP!=NULL) (*FSP)(Pnt,0,0); if(ber!=0) Diag->Free_St(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение параметров АР модели, решение уравнений Юла-Уолкера методом Левинсона-Дурбина.

BYTE LevinsonDurbin(float *AC,USHRT nAC,float *CoeffA,USHRT nCoeffA,USHRT *pMax,double *Sig,float DevRel,
float DevAbs,BYTE flAkaike,USHRT lnCorr)
{
BYTE ber; USHRT i,k,p; double *A,*B,*pA,*pB,*pC,sA,sB,*psA,*psB,*psC,akk,v,sig,coe,s;

if(AC==NULL) return 1; if(nAC<3) return 2; if(CoeffA==NULL) return 3; if(nCoeffA<2) return 4;
if(nCoeffA>nAC-1) return 5; if(pMax==NULL) return 6;
if(DevRel<=0.0F) return 7; if(DevAbs<0.0F) return 8; if(AC[0]<SmCnst10_d) return messRet;

A=B=NULL; ber=0;
if(AllocDouble(&A,(size_t)nCoeffA)!=0) { ber=9; goto end;}
if(AllocDouble(&B,(size_t)nCoeffA)!=0) { ber=10; goto end;}

pA=A; pB=B; psA=&sA; psB=&sB;
*pA=-(double)AC[1]/(double)AC[0]; *psA=(1.-(*pA)*(*pA))*(double)AC[0];

p=1; for(k=1;k<nCoeffA;k++) {
s=0.; for(i=0;i<k;i++) s+=pA[i]*(double)AC[k-i]; akk=-((double)AC[k+1]+s)/(*psA);
v=akk; if(v<0.) v=-v; if(v>=1.) break;
pB[k]=akk; for(i=0;i<k;i++) pB[i]=pA[i]+akk*pA[k-1-i]; v=akk*akk; *psB=(1.-v)*(*psA); sig=*psB;
pC=pA; pA=pB; pB=pC; psC=psA; psA=psB; psB=psC; p++;

// Критерий Экейке для завершения итераций.
if(flAkaike!=0) { if(p>=lnCorr) break;
coe=(double)(lnCorr+1+p)/(double)(lnCorr+1-p)/((double)(lnCorr+p)/(double)(lnCorr-p));
coe*=(1.-v); if(coe>=1.) break;}

// Критерий завершения итераций, основанный на относительном и абсолютном уровне шума.
if(DevAbs>0.0F) { if(sig<(double)DevAbs) break;} if(v<(double)DevRel) break;
}

*pMax=p; if(Sig!=NULL) *Sig=*psA; for(i=0;i<p;i++) CoeffA[i]=(float)pA[i];

end: FreeDouble(&A); FreeDouble(&B); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Находит сигнал по авторегрессионной модели путём предсказания вперёд.

BYTE FindARSignalForw(float *SigI,float *SigAR,UINT nSig,UINT nI,UINT nF,float *AK,USHRT nAK)
{
USHRT i; UINT k,kp; double s;

if(SigI==NULL) return 1; if(SigAR==NULL) return 2; if(nSig==0) return 3; if(nF>nSig) return 4;
if(nI>=nF) return 5; if(AK==NULL) return 6; if(nAK==0) return 7;
for(k=nI;k<nF;k++) { s=0.;
for(i=0;i<nAK;i++) { if(k<(UINT)i+1) continue; kp=k-1-(UINT)i; s+=(double)(SigI[kp]*AK[i]);}
SigAR[k]=-(float)s;}
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров авторегрессионного анализа.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strParProcAR::strParProcAR(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

void strParProcAR::Init(void)
{
pMax=FltAR_pMaxStand; DevRel=FltAR_DevRelAR_Stand; DevAbs=0.0F; flAkaike=1;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParProcAR::Check(void)
{
BYTE fl,ind; USHRT p; float *fp,v;

ind=0;

fp=&DevRel;
v=FltAR_DevRelAR_Min; if(*fp<v) { *fp=v; ind+=1<<0;}
v=FltAR_DevRelAR_Max; if(*fp>v) { *fp=v; ind+=1<<1;}

fl=0;
p=FltAR_pMaxMax; if(pMax>p) { pMax=p; fl+=1<<0;}
p=FltAR_pMaxMin; if(pMax<p) { pMax=p; fl+=1<<1;}
if(fl!=0) ind+=1<<2;

return ind;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParProcAR::Read(FILE *file)
{
int iv;

if(file==NULL) return 1;
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv>USHRT_MAX) return 3; pMax=(USHRT)iv;
if(fscanf(file,"%e%e",&DevRel,&DevAbs)==EOF) return 4;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv==0) flAkaike=0; else flAkaike=1;
Check(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strParProcAR::Write(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%d  %e %e  %d",(int)pMax,DevRel,DevAbs,(int)flAkaike)<0) return 2;
return 0;
}

strParProcAR,clConveyer,

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Константы, задающие величины параметров авторегрессионного фильтра.

#define lnCorrMin 5 // Минимальное число точек в интеграле нахождения автокорреляционной функции.

#define FltAR_DevRelAR_Stand 5.0e-1F // Минимальное относительное отклонение в АР алгоритме, стандартное значение.
#define FltAR_DevRelAR_Min 1.e-3F // Минимальное относительное отклонение в АР алгоритме, минимальное значение.
#define FltAR_DevRelAR_Max 1.0F // Минимальное относительное отклонение в АР алгоритме, максимальное значение.

#define FltAR_pMaxStand 50 // Стандартное значение порядка АР модели.
#define FltAR_pMaxMax 50 // Максимальное значение порядка АР модели.
#define FltAR_pMaxMin 3 // Минимальное значение порядка АР модели.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров авторегрессионного анализа.

struct strParProcAR {

BYTE flAkaike; USHRT pMax; float DevRel,DevAbs;

strParProcAR(void); // Конструктор.
void Init(void); // Инициализация.
BYTE Check(void); // Проверки.
BYTE Read(FILE *file); // Чтение из файла.
BYTE Write(FILE *file); // Запись в файл.
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс конвейера для нахождения корреляционных функций.

class clConveyer {

USHRT nCorr,lnCorr,numBuf; UINT nPoints,Time; float *SigA,*SigB; clArr2Float *Buf; clArrDouble *Sum;

void Zero(void); // Обнуление указателей и инициализация параметров.
void ZeroSig(void); // Обнуление указателей и инициализация параметров для сигналов.
BYTE IsOKSig(void); // Проверки сигналов.
void ZeroBuf(void); // Обнуление указателей и инициализация параметров для вспомогательных массивов.
void FreeBuf(void); // Освобождение памяти от вспомогательных массивов.
BYTE IsOKBuf(void); // Проверки вспомогательных массивов.

public:

clConveyer(void);
~clConveyer(void);
BYTE AllocBuf(USHRT nCorr_,USHRT lnCorr_); // Выделение памяти.
BYTE IsOK(void); // Проверки.
BYTE Set(float *SigA_,float *SigB_,UINT nPoints_); // Установка указателей на сигналы, длины сигналов и другие параметры.
BYTE Start(void); // Нахождение корреляции на начальном отрезке конвейера.
BYTE MoveTo(UINT Time_); // Перемещение начала суммирования до положения 'Time_'.
BYTE GetCorrFunc(float *CorrFunc,USHRT nCorrFunc); // Получение текущей корреляционной функции.
};


case methTrain_GroupRandMC: be=TrainNNW_MonteCarlo(); break; // Групповой метод случайного поиска (Монте-Карло).
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров тренировки нейронной методом случайного поиска (Монте-Карло).
//struct strParTrainNNW_RandMC { BYTE jump; USHRT nSt; float coeWeiA,coeTeA,coeWeiR,coeTeR, ErrCoe,levJump;};
struct strParTrainNNW_RandMC ParTrNNW_MC={ 0, 30, 0.01F,0.01F, 0.01F,0.01F, 0.1F, 0.01F};

//-----------------------------------------------------------------------------------------------------------
// Тренировка нейронной сети методом случайного поиска (Монте-Карло).

BYTE clDlgDBF_NNW::TrainNNW_MonteCarlo(void)
{
BYTE GetNumInput(strNNW *pNNW,USHRT *nInp); // Получение числа нейронов первого распределительного слоя.
BYTE GetParNNW(strNNW *pNNW,strParNNW *pParNNW); // Получение параметров из структуры нейронной сети.
BYTE GetNumVectParNNW(strParNNW *pParNNW,USHRT nNeurInp,USHRT *nVect);// Получение полного числа коэффициентов и смещений из структуры нейронной сети.
BYTE AttemptJump(float U); // Проводит попытку перепрыгнуть через "потенциальный" барьер высотой 'U'.

BYTE fl,be,ber; USHRT i,k,iMin,nCycle,nV,nStepsRand,nPeaksInp; UINT *NumRandArr;
float coeWeiA,coeTeA,coeWeiR,coeTeR,v; double Err,ErrN,ErrCntrl,ErrMin; struct strArrTrSearch ATS;
struct strParNNW Par;

if(pNNW==NULL) return 1; if(pNNW->IsOK_Lay()!=0) return 2; if(ParTrNNW_MC.IsOK()!=0) return 3;
if(DataTrain.IsOK()!=0) return 4;
if(GetNumInput(pNNW,&nPeaksInp)!=0) return 5; if(nPeaksInp==0) return 6;
srand(ParTrain.RandSeq); // Инициализация случайной последовательности.
nStepsRand=ParTrNNW_MC.nSt;

ber=0;
NumRandArr=new UINT[nStepsRand]; if(NumRandArr==NULL) { ber=7; goto end;}

if(GetParNNW(pNNW,&Par)!=0) { ber=8; goto end;} // Получение параметров из структуры нейронной сети.
if(GetNumVectParNNW(&Par,nPeaksInp,&nV)!=0) { ber=9; goto end;} // Получение полного числа коэффициентов и смещений из структуры нейронной сети.
if(ATS.Create(nV)!=0) { ber=10; goto end;} // Создание массивов.
coeWeiR=ParTrNNW_MC.coeWeiR*v; coeTeR=ParTrNNW_MC.coeTeR*v;

be=StepTrainErr(&Err,&ErrCntrl); if(be!=0&&be!=messRet) { ber=11; goto end;} // Шаг предъявления образцов с нахождением ошибки.
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
SetErrWin(Err,ErrCntrl); // Установка ошибок в окнах.

// Циклы тренировки групповым методом случайного поиска Монте-Карло.
nCycle=0;
repCycle: SetUSHRT_Edt(hDlg,IDC_NUM_CYCLE,nCycle);
for(k=0;k<ParTrain.nStTrain;k++) {
if(pNNW->GetSetArrSearch(ATS.Coe,nV,0,0)!=0) { ber=12; goto end;} // Получение коэффициентов.
v=(float)Err/ParTrNNW_MC.ErrCoe; coeWeiA=ParTrNNW_MC.coeWeiA*v; coeTeA=ParTrNNW_MC.coeTeA*v;

// Заполнение массива случайных чисел.
for(i=0;i<nStepsRand;i++) NumRandArr[i]=(UINT)rand();

// Цикл случайного поиска.
ErrMin=LrgCnst32_d; iMin=USHRT_MAX;
for(i=0;i<nStepsRand;i++) { if(flStopTrain!=0) break;
if(pNNW->GetSetArrSearch(ATS.Coe,nV,1,0)!=0) { ber=13; goto end;} pNNW->flChange=1; // Установка коэффициентов.
if(pNNW->RandChange(NumRandArr[i],coeWeiR,coeTeR,coeWeiA,coeTeA)!=0) { ber=14; goto end;} pNNW->flChange=1;
be=StepTrainErr(&ErrN,&ErrCntrl); if(be!=0&&be!=messRet) { ber=15; goto end;} // Шаг предъявления образцов с нахождением ошибки.
if(be==messRet) { Message(IDS_Mess_NoSampTrainNNW,MB_ST); ber=messRet; goto end;}
if(ErrN>=ErrMin) continue; ErrMin=ErrN; iMin=i;}

ErrN=ErrMin; fl=0;
if(iMin<nStepsRand) { if(ErrN<Err) fl=1;
else if(ParTrNNW_MC.jump!=0&&AttemptJump((float)((ErrN-Err)/Err)/ParTrNNW_MC.levJump)==0) fl=2;}
if(pNNW->GetSetArrSearch(ATS.Coe,nV,1,0)!=0) { ber=16; goto end;} pNNW->flChange=1; // Установка коэффициентов.
if(fl!=0) if(pNNW->RandChange(NumRandArr[iMin],coeWeiR,coeTeR,coeWeiA,coeTeA)!=0) { ber=17; goto end;} // Занесение новых значений весов и смещений.

Err=ErrN; SetErrWin(Err,ErrCntrl); // Установка ошибок в окнах.
pNNW->flOK=1;
ShowProgr((UINT)k+1,(UINT)ParTrain.nStTrain); // Изображение процента выполнения работы.
if(flStopTrain!=0) { ber=messRet; goto end;}}
if(nCycle==USHRT_MAX) goto end; nCycle++; goto repCycle;

end: SAFE_DELETE_ARR(NumRandArr); pNNW->FreeVect(); return ber;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Структура параметров тренировки нейронной методом случайного поиска (Монте-Карло).

struct strParTrainNNW_RandMC {

BYTE jump; // Возможность прыжков в состояние с большей ошибкой.
USHRT nSt; // Число шагов в цикле поиска.
float coeWeiA,coeTeA; // Коэффициенты, задающие абсолтные случайные смещения весов и порогов.
float coeWeiR,coeTeR; // Коэффициенты, задающие относительные случайные смещения весов и порогов.
float ErrCoe; // Уровень ошибки, при которой применяются коэффициенты 'coeWei','coeTe'. Коэффициенты пропорциональны значению ошибки.
float levJump; // Уровень относительно ошибки, который регулирует вероятность перескока в новое положение.

BYTE IsOK(void); // Проверки.
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров тренировки нейронной методом случайного поиска (Монте-Карло).

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParTrainNNW_RandMC::IsOK(void)
{
if(nSt==0) return 1; if(coeWeiA<0.0F) return 2; if(coeTeA<0.0F) return 3;
if(coeWeiR<=0.0F) return 4; if(coeTeR<=0.0F) return 5; if(ErrCoe<=0.0F) return 6;
if(levJump<=0.0F) return 7; return 0;
}

#define methTrain_GroupRandMC 5 // Групповой метод случайного поиска (Монте-Карло).
case methTrain_GroupRandMC: // Групповой метод случайного поиска (Монте-Карло).
