/*...........................................................................................................

// Библиотечные программы.
FastFT,GetN,GetN_,
GetWeightWinSTFT,
GetWeightWinCosHann,GetWeightGauss,GetWeightHamming,GetWeightBlackman,GetWeightBlackmanHarris,GetWeightNatall,
GetWeightBlackmanNatall,GetWeightFlatTop,GetWeightBarlett,GetWeightBarlettHann,GetWeightLanczos,
GetWeightKaiserBess,GetBesselI0,
GetMaxAccurate,AbsValue,

// Программы спектральной обработки.
ComputeSpDiag,

// Структура параметров спектральной обработки.
struct strParSpProc { strParSpProc,IsOK,Check,Read_,Write_,Read,Write,SetDlg,GetDlg,OnCreateDlg},

// Класс спектральной диаграммы.
class clSpDiag { clSpDiag,Zero_St,Free_St,IsOK_St},

// Структура векторов и параметров для тренировки нейронной сети.
struct strNeurVect {
strNeurVect,~strNeurVect,Zero,ZeroPar,Free,Alloc,IsOK,SetZero,GetSetWeightsShifts},

// Структура эталонных значений слоя нейрона.
struct strEtalVal {
strEtalVal,~strEtalVal,Zero,Free,Alloc,IsOK,GetMinMax,Correct},

// Структура нейрона.
struct strNeuron {
strNeuron,~strNeuron,
Zero,ZeroPar,Free,Alloc,IsOK,IsOK_Vect,
GetSetArrSearch,GetSetWeightsShifts,
Read,Write,ZeroInit,RandInit,RandChange,AddWeightsShiftsGroup,SetValEqualEtal,SetEtalEqualVal},
CopyStrNeuron,

// Структура слоя нейронов.
struct strLay {
strLay,~strLay,Zero,InitPar,Free,Alloc,IsOK,Get,Read,Write,AllocWeights,
FreeVect,AllocVect,IsOK_Vect,SetZeroVect,
GetSetArrSearch,SetFlagTShUse,ZeroInit,RandInit,RandChange,AddWeightsShiftsGroup,
FreeEtal,AllocEtal,SetValEqualEtal,SetEtalEqualVal},
CopyStrLay,

// Структура входного слоя нейронов.
struct strInpLay {
strInpLay,~strInpLay,Zero,Free,Alloc,IsOK,Get},
CopyInpLay,

// Класс массива структур входного или выходного слоя нейронов.
struct clInpLayArr {
clInpLayArr,~clInpLayArr,Zero,Free,Alloc,IsOK},

// Параметры частотной коррекции спектральных линий.
struct strParFreqCorrPeaks { strParFreqCorrPeaks,Init,IsOK,Check,Read,Write,SetDlg,GetDlg},
CopyParFreqCorrPeaks,DlgParFreqCorrPeaks,FreqCorrPeaks,

// Параметры частотной коррекции спектра.
struct strParFreqCorrSpectr { strParFreqCorrSpectr,Init,Check,Read,Write,SetDlg,GetDlg},
CopyParFreqCorrSpectr,DlgParFreqCorrSpectr,FreqCorrSpectr,

// Структура свойств и параметров нейронной сети.
struct strPropNNW { strPropNNW,Init,Read,Write},
CopyPropNNW,

// Структура всей нейронной сети.
struct strNNW {
strNNW,~strNNW,Zero,FreeInit,Free,Alloc,IsOK,IsOK_Lay,Get,GetOutLay,
Read,Write,Read_,Write_,Read,Write,Write,
Compute,ComputeFrom,FreqCorrect,ZeroInit,RandInit,RandInit_,RandChange,RandChange_,
ComputeErrBackProp,TrainStepSequent,TrainStepSequentRep,TrainStepSequentLayWeights,
TrainStepSequentLayEtal,TrainStepSequentLayCorr,
ComputeAdaptStepAll,ComputeAdaptStepLay,
FreeVect,AllocVect,IsOK_Vect,SetZeroVect,
TrainGroupErrSumVect,TrainGroupAdaptStep,ZeroNumDenomAdaptStepGroup,FindAlphaGroup,CorrectAlpha,
MultCoeAlpha,SetAlphaConst,GetEqualAdaptStep,AddWeightsShiftsGroup,
GetSetArrSearch,PaintNNW,
FreeEtal,AllocEtal,
ZeroNames,FreeNames,SetNames,IsOK_Name},
CopyNNW,

// Структура параметров тренировки нейронной сети групповым методом поиска.
struct strParTrainNNWSearch { IsOK},

// Структура параметров тренировки нейронной методом случайного поиска (Монте-Карло).
struct strParTrainNNW_RandMC { IsOK},

// Структура вспомогательных массивов для тренировки сети методом поиска.
struct strArrTrSearch { strArrTrSearch,~strArrTrSearch,Zero,Free,Create,IsOK},

// Структура параметров слоя.
struct strParLay { strParLay,IsOK,Print,Read,Write},

// Структура параметров нейронной сети.
struct strParNNW {
strParNNW,~strParNNW,Zero,Free,Alloc,ReAlloc,IsOK,IsOK_,Get,Init,InsItem,DelItem,Read_,Write_,Read,Write,
Write,ZeroNames,FreeNames,SetNames,IsOK_Name,EdtParFreqCorrPeaks,EdtParFreqCorrSpectr},

// Класс диалогового окна настройки параметров нейронной сети.
struct clDlgParNNW {
clDlgParNNW,~clDlgParNNW,Zero,IsOK,
OnOpenDlg,SetDlgWinEdt,FillLBLayers,UnSelLayer,OnChangeLayer,SelectLayer_,SelectLayer,
SetWinParLay_,SetWinParLay,UnSetWinParLay,AcceptChanges,SetParLaySel,AddInsItem,DelItem,SelectTypNNW,
ReadParNNW,WriteParNNW,ChBtnAccept,ChBtnDelAdd,OnChangeFlags,EnableRadioTypNet,EnableBtnTypInpData,
SelectTypInpData,MsgCommand,Command},
DlgProcParNNW,

// Структура спектральной линии.
struct strSpectrLine { strSpectrLine,Zero},

// Структура массива спектральных линий.
struct strSpLines {
strSpLines,~strSpLines,Zero,Free,Create,IsOK,Get},

// Класс двумерного массива спектральных линий.
class clSpLinesArr {
clSpLinesArr,~clSpLinesArr,Zero,Free,Clear,Create,IsOK,Get},

// Структура параметров нахождения спектральных линий гласных звуков и предварительного распознавания гласных и согласных звуков.
struct strParGetPeaks { strParGetPeaks,Init,IsOK,Check,Read_,Read,Write_,Write,SetDlg,GetDlg,OnCreateDlg},
DlgParPeaks,

// Структура параметров нахождения спектральных линий гласных звуков и предварительного распознавания гласных и согласных звуков.
struct strParInpSpectr { strParInpSpectr,Init,IsOK},

// Структура параметров тренировки сети.
struct strParTrainNNW { strParTrainNNW,Init,IsOK,Check,Read_,Read,Write_,Write,SetDlg,GetDlg,OnCreateDlg},
DlgParTrainNNW,

// Функции для расчётов и тренировок методом искусственных нейронных сетей.
CreateNNW,GetParNNW,GetNumVectParNNW,ComputeLayer,ComputeLayerFirst,ComputeAdaptStep,ComputeAdaptStepFirst,
ComputeAdaptStep_,CorrectAdaptStep,CorrectAdaptStepSimple,CorrectAdaptStepSmooth,
GetFunAct,FunAct_Sigm,FunAct_BiSigm,FunAct_HypTang,FunAct_Log,FunAct_Lin,
FunDerAct,FunDerAct_Sigm,FunDerAct_BiSigm,FunDerAct_HypTang,FunDerAct_Log,FunDerAct_Lin,
GetCoeDeriv,SetErrOutLay,ComputeErr,CorrectWeights,CorrectWeightsFirst,
AddVectors,AddVectorsFirst,AddAdaptStep,AddAdaptStepFirst,FindErrOutLay,
GetNumInput,CorrectY,SetValEtalOutLay,SetErrLayEtal,ComputeAdaptStepY,CorrFreq,

// Функции для формирования входных векторов и распознавания.
RecognSoundNNW_VC,GetNInpDataNetVC,InputDataNetVC,RecognSoundNNW_Sp,InputDataNetSp,
DecSnd_Instant,FindPeaks,GetTruePeaks,CheckPeak,ResTriFun,InpSpectrRow,GetEnvelope,

// Функции для синтеза звука.
Synthesis,SumCos,SumCosCorr

...........................................................................................................*/

#include "stdafx.h"

#include "Project_con.h"
#include "cmplx.h"
#include "Project_cls.h"
#include "Project_pro.h"
#include "resource.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Программы.

void FreeString(char **Str); // Освобождение памяти для строки.
BYTE AllocFloat(float **fpp,size_t ln); // Выделение памяти для массива 'float'.
void FreeFloat(float **fpp); // Освобождение памяти для массива 'float'.
BYTE AllocDouble(double **dpp,size_t ln); // Выделение памяти для массива 'double'.
void FreeDouble(double **dpp); // Освобождение памяти для массива 'double'.
BYTE AllocComplex(complex **cpp,size_t ln); // Выделение памяти для массива 'complex'.
void FreeComplex(complex **cpp); // Освобождение памяти для массива 'complex'.
void EnableChWin(HWND hDlg,int id,BYTE flag); // Ввод и снятие блокировки дочернего окна.
void SetPosWindowCenter(HWND hDlg); // Помещение окна в центр другого окна или экрана.
BYTE SetUSHRT_Edt(HWND hDlg,int id,USHRT Val); // Установка значения 'USHRT' в окно редактирования.
BYTE GetUSHRT_Edt(HWND hDlg,int id,USHRT *pVal); // Получение значения 'USHRT' из окна редактирования.
BYTE SetUINT_Edt(HWND hDlg,int id,UINT Val); // Установка значения 'UINT' в окно редактирования.
BYTE GetUINT_Edt(HWND hDlg,int id,UINT *pVal); // Получение значения 'UINT' из окна редактирования.
BYTE SetFlEdt(HWND hDlg,int id,float Val,char *Form); // Установка значения с плавающей точкой в окно редактирования.
BYTE GetFlEdt(HWND hDlg,int id,float *Val); // Получение значения с плавающей точкой из окна редактирования.
BYTE SetChBox(HWND hDlg,int id,BYTE flag); // Установка флага в окне.
BYTE GetChBox(HWND hDlg,int id,BYTE *flag); // Получение флага из окна.
BYTE SetSelCombo(HWND hDlg,UINT id,BYTE num); // Установка номера выбранной строки в комбинированном списке.
BYTE GetSelCombo(HWND hDlg,UINT id,BYTE *num); // Получение номера выбранной строки в комбинированном списке.
BYTE SetSizeCombo(HWND hDlg,int id,BYTE num); // Установка размера комбинированного списка по числу строк.
BYTE FillStrCombo(HWND hDlg,UINT id,UINT *IDSArr,BYTE nArr,BYTE nSel); // Заполнение комбинированного списка.
BYTE CrSelPen(HDC hdc,HPEN *hPen,HPEN *hPenP,BYTE Wid,DWORD Col); // Создание и выбор пера.
void UnSelDelPen(HDC hdc,HPEN *hPen,HPEN *hPenP); // Освобождение и удаление пера.
BYTE CrSelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP,DWORD Col); // Создание и выбор кисти.
void UnSelDelBrush(HDC hdc,HBRUSH *hBrush,HBRUSH *hBrushP); // Освобождение и удаление кисти.
void DrawLine_(HDC hdc,int xI,int yI,int xF,int yF); // Рисование линии.
void ImgRectC(HDC hdc,RECT *rc,DWORD ColP,DWORD ColB,BYTE Wid); // Закрашивание прямоугольника.
BYTE FileNameQuest(HWND hwnd,BYTE flWrite,UINT idSFilt,char *PathToDir,char *extFile,UINT IDS_Header,
  char *FileNameN,USHRT szFileNameN,char *PathToDirN,USHRT szPathToDirN,char *ExtN,USHRT szExtN,BYTE flChExt); // Выводит стандартный диалог для запроса имени файла и получает имя файла и директории.
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // Получение имени файла включая путь.
BYTE CompareStrCase(char *strA,char *strB); // Сравнение строк (с учётом длины строк и типа букв) без различения прописных и строчных букв.
BYTE IsOKStr(char *str); // Проверка строки.
BYTE StrCopy(char *Dst,size_t lnDst,char *Src); // Копирование строк.
BYTE DupString(char **Str,char *Src); // Выделение памяти для строки и копирование.
BYTE GetBYTE(float v); // Получение числа 'BYTE' из числа 'float' с проверкой выхода за пределы 'BYTE'.
USHRT GetUSHRT_Test(int iv); // Получение числа 'USHRT' из числа 'int' с проверкой выхода за пределы 'USHRT'.
USHRT GetUSHRT_Test(float v); // Получение числа 'USHRT' из числа 'float' с проверкой выхода за пределы 'USHRT'.
USHRT GetUSHRT_Test(double d); // Получение числа 'USHRT' из числа 'double' с проверкой выхода за пределы 'USHRT'.
int GetIntTest(float v); // Получение числа 'int' из числа 'float' с проверкой выхода за пределы 'int'.
UINT GetUINT_Test(double d); // Получение числа 'UINT' из числа 'double' с проверкой выхода за пределы 'UINT'.
pFunAct GetFunAct(BYTE Typ); // Функция выбора функции активации нейронных элементов.
pFunDerAct GetFunDerAct(BYTE Typ); // Функция выбора производной функции активации нейронных элементов.
void Message(UINT StrID,UINT typ); // Вывод сообщения.
void ProcMess(void); // Опрос очереди сообщений и обработка сообщений.
void SoundBlock(void); // Звук при заблокированном действии.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные классы и структуры.

extern struct strParGetPeaks ParGetPeaks; // Структура параметров нахождения спектральных линий.
extern struct strParInpSpectr ParInpSp; // Структура параметров нахождения спектральных линий гласных звуков и предварительного распознавания гласных и согласных звуков.
extern struct strParIncHighSynth ParIHS; // Структура параметров увеличения амплитуд высоких гармоник при синтезе звука.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные переменные.

extern HINSTANCE hInst; // Идентификатор приложения.
extern LRESULT LRes; // Вспомогательная переменная.
extern HFONT hFontA; // Шрифты.

extern char TxtStr[strL_Txt],TxtMem[strL_Txt]; // Вспомогательные строки.

extern char PathToProgDir[strL_Path]; // Директория программы.
extern char PathToDirParNNW[strL_Path]; // Директория с файлами параметров нейронной сети.
extern char PathToDirN[strL_Path]; // Директория выбранного файла.
extern char FileNameN[strL_FileName]; // Имя выбранного файла.
extern char ExtN[szExt]; // Расширение выбранного файла.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Директории.

extern char *dirParNNW; // Директория с файлами параметров нейронных сетей.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Расширения файлов.

extern char *extParNNW_Vowel,*extParNNW_Cons,*extParNNW_Spectr; // Расширения файлов параметров нейронных сетей.
extern char *extNNW_Vowel,*extNNW_Cons,*extNNW_Spectr; // Расширение файлов нейронных сетей.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Идентификаторы строк функций активации.

UINT idS_FunAct[nTypFunAct]={IDS_FunAct_Sigmoid,IDS_FunAct_SigmBiPolar,IDS_FunAct_HypTang,IDS_FunAct_Log,
IDS_FunAct_Lin};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Идентификаторы строк названий окон сглаживания при спектральном преобразовании в движущемся окне.

UINT IDSArrWinSpectr[nTypMovWinSpectr]={IDS_SpectrWinName_Cos,IDS_SpectrWinName_CosHann,IDS_SpectrWinName_Hamming,
IDS_SpectrWinName_Blackman,IDS_SpectrWinName_BlackmanHarris,IDS_SpectrWinName_KaizerBessel,
IDS_SpectrWinName_Natall,IDS_SpectrWinName_BlNatall,IDS_SpectrWinName_FlatTop,IDS_SpectrWinName_Barlett,
IDS_SpectrWinName_BarHann,IDS_SpectrWinName_Lanczos,IDS_SpectrWinName_Gauss,IDS_SpectrWinName_NoSmooth};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Идентификаторы строк названий методов тренировки сети.

extern UINT IDSArrMethTrain[nMethTrain];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Параметры выходного слоя сети - гласных и согласных букв.

extern char SignVoicesVowel[nVoicesVowel]; // Массив обозначений гласных букв.
extern DWORD ColVoicesVowel[nVoicesVowel]; // Цвета обозначения гласных букв.
extern char SignVoicesCons[nVoicesCons]; // Массив обозначений согласных букв.
extern DWORD ColVoicesCons[nVoicesCons]; // Цвета обозначения согласных букв.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Форматы.

extern char *FormAmp; // Амплитуда сигнала.
extern char *FormCoeff; // Коэффициент.
extern char *FormTimeDur; // Короткий промежуток времени (с).
extern char *FormTime; // Время (с).
extern char *FormFreq; // Частота (Гц).
extern char *FormDB; // Значение в дБ.

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

//-----------------------------------------------------------------------------------------------------------
// Более точное нахождение максимума по трём точкам: параболическая аппроксимация.

BYTE GetMaxAccurate(float *Fun,float *pos,float *amp)
{
double A,B,C,X,v;

if(Fun==NULL) return 1; if(pos==NULL) return 2; if(amp==NULL) return 3;
C=(double)Fun[1]; B=((double)Fun[2]-(double)Fun[0])*0.5; A=((double)Fun[2]+(double)Fun[0])*0.5-C;
v=A; if(v<0.) v=-v; if(v<SmCnst24_d) return 4; X=-B/A*0.5; *pos=(float)X; *amp=(float)(A*X*X+B*X+C); return 0;
}

//--------------------------------------------------------------------------------------------------------------------------
// Норма вектора.

BYTE AbsValue(double *V,USHRT N,double *av)
{
USHRT i; double v,sum;

if(V==NULL) return 1; if(N==0) return 2; if(av==NULL) return 3;
sum=0.; for(i=0;i<N;i++) { v=V[i]; sum+=v*v;} *av=SQRT(sum); return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Программы спектральной обработки.

//-----------------------------------------------------------------------------------------------------------
// Расчёт спектральной диаграммы.

BYTE ComputeSpDiag(float *Snd,UINT nSnd,double dt,clSpDiag *Diag,strParSpProc *Param,PNT_DATA Pnt,
pFunShowProgr FSP,BYTE *flStop)
{
BYTE GetN_(USHRT nPoints,USHRT *Np,USHRT NpM,BYTE *Mp); // Даёт минимальное число 'Np', являющееся 2 в целой степени, которое превышает 'nPoints'.
BYTE GetWeightWinSTFT(BYTE meth,float *Weight,USHRT nP,float Wid); // Нахождение весовой функции окна при спектральном разложении.
BYTE FastFT(complex *A,complex *B,BYTE M,SCHAR dir,BYTE prcMess); // Быстрое преобразование Фурье.

BYTE M,be,meth,ber; SHRT iv,nv; USHRT nWinWid,nPoints,nPh,n; UINT i,k,nTime; __int64 l; float v,*Weight;
double d,WinStep; complex *A,*B; clArrFloat *pArrFr;

if(Diag==NULL) return 1; Diag->Free_St();
if(Snd==NULL) return 2; if(nSnd==0) return 3; if(dt<=0.) return 4;
if(Param==NULL) return 5; if(Param->IsOK()!=0) return 6;
meth=Param->methSpFour;
nWinWid=GetUSHRT_Test((double)Param->Time_Width/dt); if(nWinWid<nWinWid_Min) nWinWid=nWinWid_Min;
be=GetN_(nWinWid,&nPoints,0,&M); if(be==messRet) return 7; if(be!=0) return 8;
nPh=nPoints/2;
d=(double)(nSnd-1)*dt; nTime=GetUINT_Test(d/(double)Param->Time_Step); if(nTime==0) return 9;
if(nTime>1) WinStep=d/(double)(nTime-1); else WinStep=0.;

A=B=NULL; Weight=NULL; ber=0;
if(Diag->Alloc(nTime,(UINT)nPh)!=0) { ber=10; goto end;}
if(AllocComplex(&A,(size_t)nPoints)!=0) { ber=11; goto end;}
if(AllocComplex(&B,(size_t)nPoints)!=0) { ber=12; goto end;}
if(AllocFloat(&Weight,(size_t)nPh)!=0) { ber=13; goto end;}

// Нахождение весовой функции окна.
if(meth!=methSpFour_NoWin) { v=Param->Time_Width*0.5F/(float)dt;
if(GetWeightWinSTFT(meth,Weight,nPh,v)!=0) { ber=14; goto end;}}

// Цикл по временным точкам.
for(i=0;i<nTime;i++) { k=GetUINT_Test((double)i*WinStep/dt);
pArrFr=Diag->Get(i); if(pArrFr==NULL) { ber=15; goto end;}
if(pArrFr->IsOK()!=0) { ber=16; goto end;}
for(n=0;n<nPoints;n++) { iv=(SHRT)((int)n-(int)nPh); if(iv>=0) nv=iv; else nv=-iv;
l=(__int64)k+(__int64)iv; if(l<0||l>=nSnd) v=0.0F; else v=Snd[l];
if(meth!=methSpFour_NoWin) { if(nv<nPh) v*=Weight[nv]; else v=0.0F;}
A[n]=complex((double)v,0.);}

if(FastFT(A,B,M,1,1)!=0) { ber=17; goto end;}
for(n=0;n<nPh;n++) pArrFr->Arr[n]=(float)abs(B[n]);
if(FSP!=NULL) (*FSP)(Pnt,i+1,nTime); // Показ процента выполненной работы.
if(flStop!=NULL) { if(*flStop!=0) { ber=messRet; goto end;}}
}

Diag->stArr=WinStep; // Шаг диаграммы по времени.
Diag->stLn=1./(dt*(double)nPoints); // Шаг диаграммы по частоте.

end: FreeComplex(&A); FreeComplex(&B); FreeFloat(&Weight); if(FSP!=NULL) (*FSP)(Pnt,0,0);
if(ber!=0) Diag->Free_St(); return ber;
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

//-----------------------------------------------------------------------------------------------------------
// Проверки и исправления.

BYTE strParSpProc::Check(void)
{
BYTE fl; float *fp,v;

fl=0;
fp=&Time_Width;
v=Time_Width_Spectr_Min; if(*fp<v) { *fp=v; fl+=1<<0;}
v=Time_Width_Spectr_Max; if(*fp>v) { *fp=v; fl+=1<<1;}
fp=&Time_Step;
v=Time_Step_Spectr_Min; if(*fp<v) { *fp=v; fl+=1<<2;}
v=Time_Step_Spectr_Max; if(*fp>v) { *fp=v; fl+=1<<3;}
if(methSpFour>=nTypMovWinSpectr) { methSpFour=methSpFour_KaisBess; fl+=1<<4;}
return fl;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParSpProc::Read_(FILE *file)
{
int iv;

if(file==NULL) return 1;
if(fscanf(file,"%f%f%d",&Time_Step,&Time_Width,&iv)==EOF) return 2;
if(iv<0||iv>=nTypMovWinSpectr) iv=methSpFour_KaisBess; methSpFour=(BYTE)iv;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strParSpProc::Write_(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%f  %f  %d\n",Time_Step,Time_Width,(int)methSpFour)<0) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParSpProc::Read(char *Path,char *fName)
{
BYTE err; char *name; clFileT *FT;

if(fName==NULL) return 1; if(strlen(fName)==0) return 2;
FT=NULL; name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,NULL)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,0)!=0) { err=5; goto end;}
if(Read_(FT->file)!=0) { err=6; goto end;}
Check(); // Проверки и исправления.
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение в файле.

BYTE strParSpProc::Write(char *Path,char *fName)
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

BYTE strParSpProc::SetDlg(HWND hDlg)
{
if(hDlg==NULL) return 1;
SetFlEdt(hDlg,IDC_TIME_WIDTH,Time_Width,FormTimeDur);
SetFlEdt(hDlg,IDC_TIME_STEP,Time_Step,FormTimeDur);
SetSizeCombo(hDlg,IDC_METHOD,nTypMovWinSpectr);
FillStrCombo(hDlg,IDC_METHOD,IDSArrWinSpectr,nTypMovWinSpectr,methSpFour);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение из диалогового окна.

BYTE strParSpProc::GetDlg(HWND hDlg)
{
if(hDlg==NULL) return 1;
GetFlEdt(hDlg,IDC_TIME_WIDTH,&Time_Width);
GetFlEdt(hDlg,IDC_TIME_STEP,&Time_Step);
GetSelCombo(hDlg,IDC_METHOD,&methSpFour);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при открытии диалогового окна.

void strParSpProc::OnCreateDlg(HWND hDlg)
{
SetPosWindowCenter(hDlg); // Помещение окна в центр другого окна или экрана.
SetDlg(hDlg); // Установка в диалоговое окно.
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс спектральной диаграммы.

//-----------------------------------------------------------------------------------------------------------

clSpDiag::clSpDiag(void):clArr2Float()
{
Zero_St();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление шагов.

void clSpDiag::Zero_St(void)
{
stArr=stLn=0.;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти с обнулением шагов.

void clSpDiag::Free_St(void)
{
Free(); Zero_St();
}

//-----------------------------------------------------------------------------------------------------------
// Проверки включая проверки шагов.
 
BYTE clSpDiag::IsOK_St(void)
{
if(IsOK_()!=0) return 1; if(stArr<=0.) return 2; if(stLn<=0.) return 3; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура векторов и параметров для тренировки нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strNeurVect::strNeurVect(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strNeurVect::~strNeurVect(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void strNeurVect::Zero(void)
{
nWeights=0; Weights=Shifts=NULL; ZeroPar();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов для векторов.

void strNeurVect::ZeroPar(void)
{
T=0.; flSmart=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массива из памяти.

void strNeurVect::Free(void)
{
SAFE_DELETE_ARR(Weights); SAFE_DELETE_ARR(Shifts); nWeights=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strNeurVect::Alloc(USHRT nWeights_)
{
BYTE ber;

Free(); if(nWeights_==0) return 1; ber=0; nWeights=nWeights_;
Weights=new double[nWeights]; if(Weights==NULL) { ber=2; goto end;}
if(flSmart!=0) {
Shifts=new double[nWeights]; if(Shifts==NULL) { ber=3; goto end;}}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива.

BYTE strNeurVect::IsOK(void)
{
if(nWeights==0) return 1; if(Weights==NULL) return 2; if(flSmart!=0) { if(Shifts==NULL) return 3;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка нулей в массив векторов.

BYTE strNeurVect::SetZero(void)
{
USHRT i;

T=0.; if(IsOK()!=0) return 1;
for(i=0;i<nWeights;i++) Weights[i]=0.;
if(flSmart!=0) for(i=0;i<nWeights;i++) Shifts[i]=0.;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение или установка массива весов и смещений.

BYTE strNeurVect::GetSetWeightsShifts(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet)
{
USHRT i,nV;

if(Arr==NULL) return 1; if(szArr==0) return 2; if(nFill==NULL) return 3; if(IsOK()!=0) return 4;
nV=nWeights;
if(flSmart!=0) { if(nV>USHRT_MAX-nWeights) return 5; nV+=nWeights;}
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

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура эталонных значений слоя нейрона.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strEtalVal::strEtalVal(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strEtalVal::~strEtalVal(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void strEtalVal::Zero(void)
{
nVal=0; pVal=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массива из памяти.

void strEtalVal::Free(void)
{
SAFE_DELETE_ARR(pVal); nVal=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE strEtalVal::Alloc(UINT nVal_)
{
UINT i;

Free(); if(nVal_==0) return 1;
pVal=new double[nVal_]; if(pVal==NULL) return 2; nVal=nVal_;
for(i=0;i<nVal;i++) pVal[i]=0.; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массива.

BYTE strEtalVal::IsOK(void)
{
if(nVal==0) return 1; if(pVal==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение минимального и максимального значений.

BYTE strEtalVal::GetMinMax(double *pMin,double *pMax)
{
UINT i; double v,vm,vM;

if(IsOK()!=0) return 1; vm=LrgCnst32_d; vM=-LrgCnst32_d;
for(i=0;i<nVal;i++) { v=pVal[i]; if(v>vM) vM=v; if(v<vm) vm=v;}
if(pMin!=NULL) *pMin=vm; if(pMax!=NULL) *pMax=vM; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Корректировка.

BYTE strEtalVal::Correct(double coe,double shift)
{
UINT i; double v;

if(IsOK()!=0) return 1; for(i=0;i<nVal;i++) { v=pVal[i]; pVal[i]=v*coe+shift;} return 0;
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
Val=T=0.; Err=0.; flTUse=1; flSmart=0;
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
// Проверки массива векторов.

BYTE strNeuron::IsOK_Vect(void)
{
if(Vect.IsOK()!=0) return 1; if(Vect.nWeights!=nWeights) return 2; if(flSmart!=Vect.flSmart) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение или установка массива весов и смещений или векторов весов и смещений.

BYTE strNeuron::GetSetArrSearch(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet,BYTE flArr)
{
if(flArr==0) { if(GetSetWeightsShifts(Arr,szArr,nFill,flSet)!=0) return 1;}
else { if(Vect.GetSetWeightsShifts(Arr,szArr,nFill,flSet)!=0) return 2;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение или установка массива весов и смещений.

BYTE strNeuron::GetSetWeightsShifts(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet)
{
USHRT i,nV;

if(Arr==NULL) return 1; if(szArr==0) return 2; if(nFill==NULL) return 3; if(IsOK()!=0) return 4;
nV=nWeights;
if(flSmart!=0) { if(nV>USHRT_MAX-nWeights) return 5; nV+=nWeights;}
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

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strNeuron::Write(FILE *file)
{
USHRT i;

if(file==NULL) return 1;
if(fprintf(file,"%d %d %d %le\n",(int)nWeights,(int)flTUse,(int)flSmart,T)<0) return 2;
if(IsOK()!=0) { if(fprintf(file,"\n")<0) return 3; return 4;}
for(i=0;i<nWeights;i++) if(fprintf(file,"%le ",Weights[i])<0) return 5;
if(flSmart!=0) { if(fprintf(file,"\n")<0) return 6;
for(i=0;i<nWeights;i++) if(fprintf(file,"%le ",Shifts[i])<0) return 7;}
if(fprintf(file,"\n")<0) return 8;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление весовых коэффициентов и порогового уровня.

void strNeuron::ZeroInit(void)
{
USHRT i;

if(IsOK()!=0) return; T=0.;
for(i=0;i<nWeights;i++) Weights[i]=0.;
if(flSmart!=0) for(i=0;i<nWeights;i++) Shifts[i]=0.;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение начального приближения весовых коэффициентов и пороговых уровней.

BYTE strNeuron::RandInit(float CoeWei,float CoeTe)
{
USHRT i; double coe,vr;

if(IsOK()!=0) return 1; vr=1./(double)RAND_MAX;
coe=2./sqrt((double)nWeights)*(double)CoeWei;
for(i=0;i<nWeights;i++) Weights[i]+=((double)rand()*vr-0.5)*coe;
coe=2.*(double)CoeTe;
if(flSmart!=0) for(i=0;i<nWeights;i++) Shifts[i]+=((double)rand()*vr-0.5)*coe;
if(flTUse!=0) T+=((double)rand()*vr-0.5)*coe; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Случайное изменение весовых коэффициентов и пороговых уровней.

BYTE strNeuron::RandChange(float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA)
{
USHRT i; double coe,vr,v,*dp;

if(IsOK()!=0) return 1; vr=1./(double)RAND_MAX;
coe=2./sqrt((double)nWeights)*(double)CoeWeiA;
for(i=0;i<nWeights;i++) {
dp=&Weights[i]; v=*dp; if(v<0.) v=-v; v*=(double)CoeWeiR; v=MAX(v,coe); *dp+=v*((double)rand()*vr-0.5);}
coe=2.*(double)CoeTeA;
if(flSmart!=0) for(i=0;i<nWeights;i++) {
dp=&Shifts[i]; v=*dp; if(v<0.) v=-v; v*=(double)CoeTeR; v=MAX(v,coe); *dp+=v*((double)rand()*vr-0.5);}
if(flTUse!=0) {
dp=&T; v=*dp; if(v<0.) v=-v; v*=(double)CoeTeR; v=MAX(v,coe); *dp+=v*((double)rand()*vr-0.5);}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Добавление вектора приращения к коэффициентам и смещениям при групповом обучении.

BYTE strNeuron::AddWeightsShiftsGroup(double Alpha)
{
USHRT i;

if(IsOK()!=0) return 1; if(IsOK_Vect()!=0) return 2;
if(flTUse!=0) T+=Vect.T*Alpha;
for(i=0;i<nWeights;i++) Weights[i]+=Vect.Weights[i]*Alpha;
if(flSmart!=0) for(i=0;i<nWeights;i++) Shifts[i]+=Vect.Shifts[i]*Alpha;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка значения, равного эталонному значению в послойном обучении.

BYTE strNeuron::SetValEqualEtal(UINT numSample)
{
if(Etal.IsOK()!=0) return 1; if(numSample>=Etal.nVal) Val=0.; else Val=Etal.pVal[numSample]; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка эталонного значения, равного текущему значению нейрона в послойном обучении.

BYTE strNeuron::SetEtalEqualVal(UINT numSample)
{
if(Etal.IsOK()!=0) return 1; if(numSample>=Etal.nVal) return 2; Etal.pVal[numSample]=Val; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Копирование структуры нейрона.

BYTE CopyStrNeuron(strNeuron *Dst,strNeuron *Src)
{
USHRT i;

if(Dst==NULL) return 1; Dst->Free(); Dst->Vect.Free(); Dst->ZeroPar(); Dst->Vect.ZeroPar();
if(Src==NULL) return 2; Dst->flTUse=Src->flTUse; Dst->flSmart=Src->flSmart; Dst->T=Src->T;
if(Src->IsOK()!=0) return 3; if(Dst->Alloc(Src->nWeights)!=0) return 4;
for(i=0;i<Src->nWeights;i++) Dst->Weights[i]=Src->Weights[i];
if(Src->flSmart!=0) for(i=0;i<Src->nWeights;i++) Dst->Shifts[i]=Src->Shifts[i];
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
TypFunAct=TypFunAct_Sigm; Alpha=AlphaTrain_Stand; flTUse=1; flSmart=0; Numer=Denom=0.;
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
// Запись в файл.

BYTE strLay::Write(FILE *file)
{
USHRT i;

if(file==NULL) return 1;
if(fprintf(file,"%d %d %d %d\n",(int)n,(int)flTUse,(int)flSmart,(int)TypFunAct)<0) return 2;
if(IsOK()!=0) { if(fprintf(file,"\n")<0) return 3; return 4;}
for(i=0;i<n;i++) if(Neurons[i].Write(file)!=0) return 5;
if(fprintf(file,"\n")<0) return 6;
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

//-----------------------------------------------------------------------------------------------------------
// Удаление массивов векторов из памяти.

void strLay::FreeVect(void)
{
USHRT i;

if(IsOK()!=0) return; for(i=0;i<n;i++) Neurons[i].Vect.Free();
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массивов векторов.

BYTE strLay::AllocVect(void)
{
USHRT i; struct strNeuron *pNeur;

if(IsOK()!=0) return 1;
for(i=0;i<n;i++) { pNeur=Neurons+i; if(pNeur->nWeights==0) return 2;
pNeur->Vect.flSmart=pNeur->flSmart; pNeur->Vect.flTUse=pNeur->flTUse;
if(pNeur->Vect.Alloc(pNeur->nWeights)!=0) return 3;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массивов векторов.

BYTE strLay::IsOK_Vect(void)
{
USHRT i;

if(IsOK()!=0) return 1; for(i=0;i<n;i++) if(Neurons[i].IsOK_Vect()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка нулей в массивы векторов.

BYTE strLay::SetZeroVect(void)
{
USHRT i;

if(IsOK()!=0) return 1; for(i=0;i<n;i++) if(Neurons[i].Vect.SetZero()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение или установка массива весов и смещений или векторов весов и смещений.

BYTE strLay::GetSetArrSearch(double *Arr,USHRT szArr,USHRT *nFill,BYTE flSet,BYTE flArr)
{
USHRT i,na,ns;

if(Arr==NULL) return 1; if(szArr==0) return 2; if(nFill==NULL) return 3; if(IsOK()!=0) return 4; ns=0;
for(i=0;i<n;i++) { if(ns>szArr) return 5;
if(Neurons[i].GetSetArrSearch(Arr+ns,szArr-ns,&na,flSet,flArr)!=0) return 6;
if(ns>USHRT_MAX-na) return 7; ns+=na;} *nFill=ns; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка флагов использования порогов и смещений во все нейроны.

BYTE strLay::SetFlagTShUse(void)
{
USHRT i;

if(IsOK()!=0) return 1; for(i=0;i<n;i++) { Neurons[i].flTUse=flTUse; Neurons[i].flSmart=flSmart;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление весовых коэффициентов и пороговых уровней всех нейронов.

void strLay::ZeroInit(void)
{
USHRT i;

if(IsOK()!=0) return; for(i=0;i<n;i++) Neurons[i].ZeroInit();
} 

//-----------------------------------------------------------------------------------------------------------
// Нахождение начального приближения весовых коэффициентов и пороговых уровней.

BYTE strLay::RandInit(float CoeWei,float CoeTe)
{
USHRT i;

if(IsOK()!=0) return 1; for(i=0;i<n;i++) if(Neurons[i].RandInit(CoeWei,CoeTe)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Случайное изменение весовых коэффициентов и пороговых уровней.

BYTE strLay::RandChange(float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA)
{
USHRT i;

if(IsOK()!=0) return 1; for(i=0;i<n;i++) if(Neurons[i].RandChange(CoeWeiR,CoeTeR,CoeWeiA,CoeTeA)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Добавление вектора приращения к коэффициентам и смещениям при групповом обучении.

BYTE strLay::AddWeightsShiftsGroup(void)
{
USHRT i; struct strNeuron *pNeur;

if(IsOK()!=0) return 1;
for(i=0;i<n;i++) { pNeur=Get(i); if(pNeur==NULL) return 2; if(pNeur->AddWeightsShiftsGroup(Alpha)!=0) return 3;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление из памяти массивов эталонных значений нейронов.

BYTE strLay::FreeEtal(void)
{
USHRT i; struct strNeuron *pNeur;

if(IsOK()!=0) return 1; for(i=0;i<n;i++) { pNeur=Get(i); if(pNeur==NULL) return 2; pNeur->Etal.Free();} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массивов эталонных значений нейронов.

BYTE strLay::AllocEtal(UINT nSamples)
{
USHRT i; struct strNeuron *pNeur;

FreeEtal(); if(nSamples==0) return 1; if(IsOK()!=0) return 2;
for(i=0;i<n;i++) { pNeur=Get(i); if(pNeur==NULL) return 3; if(pNeur->Etal.Alloc(nSamples)!=0) return 4;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка значений нейронов, равных эталонным значениям в послойном обучении.

BYTE strLay::SetValEqualEtal(UINT numSample)
{
USHRT i; struct strNeuron *pNeur;

if(IsOK()!=0) return 1;
for(i=0;i<n;i++) { pNeur=Get(i); if(pNeur==NULL) return 2; if(pNeur->SetValEqualEtal(numSample)!=0) return 3;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка эталонных значений нейронов, равных текущим значениям нейронов в послойном обучении.

BYTE strLay::SetEtalEqualVal(UINT numSample)
{
USHRT i; struct strNeuron *pNeur;

if(IsOK()!=0) return 1;
for(i=0;i<n;i++) { pNeur=Get(i); if(pNeur==NULL) return 2; if(pNeur->SetEtalEqualVal(numSample)!=0) return 3;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Копирование структуры слоя нейронов.

BYTE CopyStrLay(strLay *Dst,strLay *Src)
{
BYTE CopyStrNeuron(strNeuron *Dst,strNeuron *Src); // Копирование структуры нейрона.

USHRT i;

if(Dst==NULL) return 1; Dst->Free(); Dst->InitPar();
if(Src==NULL) return 2; Dst->TypFunAct=Src->TypFunAct; Dst->flTUse=Src->flTUse;
if(Src->IsOK()!=0) return 3; if(Dst->Alloc(Src->n)!=0) return 4;
for(i=0;i<Src->n;i++) if(CopyStrNeuron(Dst->Neurons+i,Src->Neurons+i)!=0) return 5; return 0;
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
// Класс массива структур входного или выходного слоя нейронов.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

clInpLayArr::clInpLayArr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

clInpLayArr::~clInpLayArr(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void clInpLayArr::Zero(void)
{
Data=NULL; nData=0; n=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление объектов из памяти.

void clInpLayArr::Free(void)
{
SAFE_DELETE_ARR(Data); nData=0; n=0;
}

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

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE clInpLayArr::IsOK(void)
{
if(Data==NULL) return 1; if(nData==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение указателя на структуру данных.

strInpLay *clInpLayArr::Get(UINT num)
{
if(IsOK()!=0) return NULL; if(num>=nData) return NULL; return Data+num;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Параметры частотной коррекции спектральных линий.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strParFreqCorrPeaks::strParFreqCorrPeaks(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация параметров.

void strParFreqCorrPeaks::Init(void)
{
numIni=numIniFrCorr_Stand; numFin=numFinFrCorr_Stand; CorrDB=CorrDBFrCorr_Stand;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParFreqCorrPeaks::IsOK(void)
{
if(numFin<=numIni) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки и коррекция.

USHRT strParFreqCorrPeaks::Check(void)
{
USHRT fl;

fl=0;
if(CorrDB<0.0F) { CorrDB=0.0F; fl+=1<<0;}
if(numIni>numIniFrCorr_Max) { numIni=numIniFrCorr_Max; fl+=1<<1;}
if(numIni>=numFin) { numFin=numIni+1; fl+=1<<2;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParFreqCorrPeaks::Read(FILE *file)
{
USHRT *usp; int iv;

if(file==NULL) return 1;
usp=&numIni; if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0) iv=0; if(iv>USHRT_MAX) return 3; *usp=(USHRT)iv;
usp=&numFin; if(fscanf(file,"%d",&iv)==EOF) return 4; if(iv<0) iv=0; if(iv>USHRT_MAX) return 5; *usp=(USHRT)iv;
if(fscanf(file,"%f",&CorrDB)==EOF) return 6;
Check(); // Проверки и коррекция.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strParFreqCorrPeaks::Write(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%d %d %e\n",(int)numIni,(int)numFin,CorrDB)<0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка в диалоговое окно.

void strParFreqCorrPeaks::SetDlg(HWND hDlg)
{
if(hDlg==NULL) return;
SetUSHRT_Edt(hDlg,IDC_NUM_INI,numIni);
SetUSHRT_Edt(hDlg,IDC_NUM_FIN,numFin);
SetFlEdt(hDlg,IDC_FR_CORR_DB,CorrDB,FormDB);
}

//-----------------------------------------------------------------------------------------------------------
// Получение из диалогового окна.

BYTE strParFreqCorrPeaks::GetDlg(HWND hDlg)
{
if(hDlg==NULL) return 1;
GetUSHRT_Edt(hDlg,IDC_NUM_INI,&numIni);
GetUSHRT_Edt(hDlg,IDC_NUM_FIN,&numFin);
GetFlEdt(hDlg,IDC_FR_CORR_DB,&CorrDB);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Копирование структуры параметров частотной коррекции спектральных линий.

BYTE CopyParFreqCorrPeaks(strParFreqCorrPeaks *Dst,strParFreqCorrPeaks *Src)
{
if(Dst==NULL) return 1; if(Src==NULL) return 2; if(Src->IsOK()!=0) return 3;
Dst->numIni=Src->numIni; Dst->numFin=Src->numFin; Dst->CorrDB=Src->CorrDB; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна настройки параметров частотной коррекции спектральных линий.

INT_PTR CALLBACK DlgParFreqCorrPeaks(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{
int id; struct strParFreqCorrPeaks *PFCP;

if(msg!=WM_INITDIALOG) PFCP=(strParFreqCorrPeaks *)GetWindowLong(hDlg,DWL_USER);

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetWindowLong(hDlg,DWL_USER,(long)lParam); PFCP=(strParFreqCorrPeaks *)lParam;
if(PFCP!=NULL) PFCP->SetDlg(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK .....................................................................................................
case IDOK: if(PFCP!=NULL) PFCP->GetDlg(hDlg); EndDialog(hDlg,1); return (INT_PTR)TRUE;

// IDCANCEL .................................................................................................
case IDCANCEL: EndDialog(hDlg,0); return (INT_PTR)TRUE;
}
break;
}

return (INT_PTR)FALSE;
}

//-----------------------------------------------------------------------------------------------------------
// Частотная коррекция входного массива.

BYTE FreqCorrPeaks(strParFreqCorrPeaks *PFC,BYTE typNNW,BYTE nPCons,strInpLay *InpLay)
{
USHRT i,j; double coe,amp,ampF;

if(PFC==NULL) return 1; if(PFC->CorrDB<=0.0F) return 0; if(PFC->IsOK()!=0) return 2;
if(InpLay==NULL) return 3; if(InpLay->IsOK()!=0) return 4;

switch(typNNW) { default: return messRet;
// Гласные и сонорные звуки.
case typNNW_Vowel:
coe=PFC->CorrDB/(double)(PFC->numFin-PFC->numIni)/20.; ampF=pow(10.,PFC->CorrDB/20.);
for(i=0;i<InpLay->n;i++) { if(i<=PFC->numIni) continue;
if(i>=PFC->numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-PFC->numIni)); InpLay->Values[i]*=amp;}
break;
// Согласные импульсные и шипящие звуки.
case typNNW_Cons: if(InpLay->n<=nPCons) return 5;
coe=PFC->CorrDB/(double)(PFC->numFin-PFC->numIni)/20.; ampF=pow(10.,PFC->CorrDB/20.);
for(j=nPCons;j<InpLay->n;j++) { i=j-nPCons; if(i<=PFC->numIni) continue;
if(i>=PFC->numFin) amp=ampF; else amp=pow(10.,coe*(double)(i-PFC->numIni)); InpLay->Values[j]*=amp;}
break;
}
return 0;
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
// Запись в файл.

BYTE strParFreqCorrSpectr::Write(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%f %f %f\n",FrIni,FrFin,CorrDB)<0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка в диалоговое окно.

void strParFreqCorrSpectr::SetDlg(HWND hDlg)
{
if(hDlg==NULL) return;
SetFlEdt(hDlg,IDC_FREQ_INI,FrIni,FormFreq);
SetFlEdt(hDlg,IDC_FREQ_FIN,FrFin,FormFreq);
SetFlEdt(hDlg,IDC_FR_CORR_DB,CorrDB,FormDB);
}

//-----------------------------------------------------------------------------------------------------------
// Получение из диалогового окна.

BYTE strParFreqCorrSpectr::GetDlg(HWND hDlg)
{
if(hDlg==NULL) return 1;
GetFlEdt(hDlg,IDC_FREQ_INI,&FrIni);
GetFlEdt(hDlg,IDC_FREQ_FIN,&FrFin);
GetFlEdt(hDlg,IDC_FR_CORR_DB,&CorrDB);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Копирование структуры параметров частотной коррекции спектра.

BYTE CopyParFreqCorrSpectr(strParFreqCorrSpectr *Dst,strParFreqCorrSpectr *Src)
{
if(Dst==NULL) return 1; if(Src==NULL) return 2;
Dst->FrIni=Src->FrIni; Dst->FrFin=Src->FrFin; Dst->CorrDB=Src->CorrDB; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна настройки параметров частотной коррекции спектра.

INT_PTR CALLBACK DlgParFreqCorrSpectr(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{
int id; struct strParFreqCorrSpectr *PFCS;

if(msg!=WM_INITDIALOG) PFCS=(strParFreqCorrSpectr *)GetWindowLong(hDlg,DWL_USER);

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetWindowLong(hDlg,DWL_USER,(long)lParam); PFCS=(strParFreqCorrSpectr *)lParam;
if(PFCS!=NULL) PFCS->SetDlg(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK .....................................................................................................
case IDOK: if(PFCS!=NULL) PFCS->GetDlg(hDlg); EndDialog(hDlg,1); return (INT_PTR)TRUE;

// IDCANCEL .................................................................................................
case IDCANCEL: EndDialog(hDlg,0); return (INT_PTR)TRUE;
}
break;
}

return (INT_PTR)FALSE;
}

//-----------------------------------------------------------------------------------------------------------
// Частотная коррекция входного массива.

BYTE FreqCorrSpectr(strParFreqCorrSpectr *PFC,float dFr,strInpLay *InpLay)
{
USHRT i; float fr; double coe,amp,ampF;

if(PFC==NULL) return 1; if(PFC->CorrDB<=0.0F) return 0; if(PFC->IsOK()!=0) return 2; if(dFr<=0.0F) return 3;
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
flType=typNNW_Vowel; flTypInpData=typDataNNW_SpectrRow;
flFrCorr=1; typFrCorr=0; flFrCompr=typFrCompr=0;
nPCons=nPeaksCons; FreqCorrPeaks.Init(); FreqCorrSpectr.Init();
dFr=0.0F; dFrTri=0.0F; FreqMin=FreqMax=0.0F;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strPropNNW::Read(FILE *file)
{
BYTE *bp; int iv;

if(file==NULL) return 1;
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0||iv>=nTypesNNW) return 3; flType=(BYTE)iv;
if(fscanf(file,"%d",&iv)==EOF) return 4; if(iv<0||iv>=nDiffDataNNW) return 5; flTypInpData=(BYTE)iv;
if(fscanf(file,"%d",&iv)==EOF) return 6; bp=&flFrCorr; if(iv==0) *bp=0; else *bp=1;
if(fscanf(file,"%d",&iv)==EOF) return 7; bp=&flFrCompr; if(iv==0) *bp=0; else *bp=1;
if(fscanf(file,"%d",&iv)==EOF) return 8; bp=&nPCons; if(iv<0||iv>UCHAR_MAX) return 9; *bp=(BYTE)iv;
if(fscanf(file,"%f%f%f%f",&dFr,&dFrTri,&FreqMin,&FreqMax)==EOF) return 10;

// Чтение параметров частотной корекции.
if(flFrCorr!=0) {
if(fscanf(file,"%d",&iv)==EOF) return 11; bp=&typFrCorr; if(iv==0) *bp=0; else *bp=1;

if(flType==typNNW_Vowel&&flTypInpData==typDataNNW_Peaks) {
if(FreqCorrPeaks.Read(file)!=0) return 12;}
if(flType==typNNW_Vowel&&flTypInpData!=typDataNNW_Peaks||flType!=typNNW_Vowel) {
if(FreqCorrSpectr.Read(file)!=0) return 13;}
}

// Чтение параметров частотной компрессии.
if(flFrCompr!=0) {
if(fscanf(file,"%d",&iv)==EOF) return 14; bp=&typFrCompr; if(iv==0) *bp=0; else *bp=1;
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strPropNNW::Write(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%d %d %d %d %d\n",(int)flType,(int)flTypInpData,(int)flFrCorr,(int)flFrCompr,(int)nPCons)<0) return 2;
if(fprintf(file,"%f %f %f %f\n",dFr,dFrTri,FreqMin,FreqMax)<0) return 3;

// Чтение параметров частотной корекции.
if(flFrCorr!=0) {
if(fprintf(file,"%d\n",(int)typFrCorr)<0) return 4;
if(flType==typNNW_Vowel&&flTypInpData==typDataNNW_Peaks) {
if(FreqCorrPeaks.Write(file)!=0) return 5;}

if(flType==typNNW_Vowel&&flTypInpData!=typDataNNW_Peaks||flType!=typNNW_Vowel) {
if(FreqCorrSpectr.Write(file)!=0) return 6;}
}

// Чтение параметров частотной компрессии.
if(flFrCompr!=0) {
if(fprintf(file,"%d\n",(int)typFrCompr)<0) return 7;
}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Копирование структуры свойств и параметров нейронной сети.

BYTE CopyPropNNW(strPropNNW *Dst,strPropNNW *Src)
{
BYTE CopyParFreqCorrPeaks(strParFreqCorrPeaks *Dst,strParFreqCorrPeaks *Src); // Копирование структуры параметров частотной коррекции спектральных линий.
BYTE CopyParFreqCorrSpectr(strParFreqCorrSpectr *Dst,strParFreqCorrSpectr *Src); // Копирование структуры параметров частотной коррекции спектра.

if(Dst==NULL) return 1; if(Src==NULL) return 2;
Dst->flType=Src->flType; Dst->flTypInpData=Src->flTypInpData; Dst->nPCons=Src->nPCons;
Dst->flFrCorr=Src->flFrCorr; Dst->typFrCorr=Src->typFrCorr;
Dst->flFrCompr=Src->flFrCompr; Dst->typFrCompr=Src->typFrCompr;
Dst->dFr=Src->dFr; Dst->dFrTri=Src->dFrTri; Dst->FreqMin=Src->FreqMin; Dst->FreqMax=Src->FreqMax;
if(CopyParFreqCorrPeaks(&Dst->FreqCorrPeaks,&Src->FreqCorrPeaks)!=0) return 3;
if(CopyParFreqCorrSpectr(&Dst->FreqCorrSpectr,&Src->FreqCorrSpectr)!=0) return 4;
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
Free(); FreeNames();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void strNNW::Zero(void)
{
nLay=0; Layers=NULL; typ=typNNW_Vowel; flOK=flChange=0; ZeroNames();
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти и инициализация параметров.

void strNNW::FreeInit(void)
{
Free(); Par.Init(); FreeNames(); typ=typNNW_Vowel; flOK=flChange=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массива нейронов из памяти.

void strNNW::Free(void)
{
SAFE_DELETE_ARR(Layers); nLay=0; flOK=flChange=0; InpLay.Free();
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
if(nLay==0) return 1; if(Layers==NULL) return 2; return 0;
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
if(fscanf(file,"%d",&iv)==EOF) return 3; if(iv<0) return 4; if(iv>UCHAR_MAX) return 5; if(iv==0) goto end;
if(Alloc((BYTE)iv)!=0) return 6;
for(i=0;i<nLay;i++) if(Layers[i].Read(file)!=0) return 7; flOK=1;
end: flChange=0; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strNNW::Write(FILE *file)
{
BYTE i;

if(file==NULL) return 1; if(Par.Write(file)!=0) return 2;
if(fprintf(file,"%d\n",(int)nLay)<0) return 3; if(IsOK()!=0) return 0;
for(i=0;i<nLay;i++) if(Layers[i].Write(file)!=0) return 4;
return 0;
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
// Запись в файл.

BYTE strNNW::Write_(char *fName)
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
// Чтение из файла.

BYTE strNNW::Read(char *Path,char *fName,char *ext)
{
BYTE err; char *name;

if(IsOKStr(fName)!=0) return 1; if(IsOKStr(ext)!=0) return 2;
name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,ext)!=0) { err=3; goto end;}
if(SetNames(Path,fName)!=0) { err=4; goto end;}
if(Read_(name)!=0) { err=5; goto end;} flChange=0;
end: FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение в файл.

BYTE strNNW::Write(char *Path,char *fName,char *ext,BYTE flSetChange)
{
BYTE err; char *name;

if(IsOKStr(fName)!=0) return 1; if(IsOKStr(ext)!=0) return 2;
name=NULL; err=0;
if(GetName(&name,Path,NULL,fName,ext)!=0) { err=3; goto end;}
if(Write_(name)!=0) { err=4; goto end;}
if(flSetChange!=0) flChange=0;
end: FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение в файле.

BYTE strNNW::Write(void)
{
BYTE err; char *name,*ext;

if(IsOK_Name()!=0) return 1;
switch(typ) { default: return 2;
case typNNW_Vowel:  ext=extNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   ext=extNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: ext=extNNW_Spectr; break; // Для всего спектра.
}
name=NULL; err=0;
if(GetName(&name,PathDir,NULL,NameFile,ext)!=0) { err=3; goto end;}
if(Write_(name)!=0) { err=4; goto end;} flChange=0;
end: FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Установка входного слоя и расчёт.

BYTE strNNW::Compute(strInpLay *InpLay_)
{
BYTE CopyInpLay(strInpLay *Dst,strInpLay *Src); // Копирование структуры входного слоя сети.

if(IsOK()!=0) return 1; if(CopyInpLay(&InpLay,InpLay_)!=0) return 2;
if(Par.flFrCorr!=0) { if(FreqCorrect()!=0) return 3;} // Частотная коррекция входного массива.
if(ComputeFrom(0)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт начиная со слоя 'layIni'.

BYTE strNNW::ComputeFrom(BYTE layIni)
{
BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay" - первом скрытом слое.
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay".

BYTE i,in;

if(IsOK()!=0) return 1; if(layIni>nLay-1) return 2;
if(layIni==0) { in=1; if(ComputeLayerFirst(&InpLay,Layers)!=0) return 3;} else in=layIni;
if(in<nLay) for(i=in;i<nLay;i++) if(ComputeLayer(Layers+i-1,Layers+i)!=0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Частотная коррекция входного массива.

BYTE strNNW::FreqCorrect(void)
{
BYTE FreqCorrPeaks(strParFreqCorrPeaks *PFC,BYTE typNNW,BYTE nPCons,strInpLay *InpLay); // Частотная коррекция входного массива.
BYTE FreqCorrSpectr(strParFreqCorrSpectr *PFC,float dFr,strInpLay *InpLay); // Частотная коррекция входного массива.

BYTE fl; float dFr;

fl=Par.flTypInpData;
// Коррекция частот для спектральных линий.
if(typ==typNNW_Vowel&&fl==typDataNNW_Peaks) {
if(FreqCorrPeaks(&Par.FreqCorrPeaks,typ,Par.nPCons,&InpLay)!=0) return 1;}
// Коррекция частот для спектра.
else { if(fl==typDataNNW_SpectrRow) dFr=Par.dFr; else dFr=Par.dFrTri;
if(FreqCorrSpectr(&Par.FreqCorrSpectr,dFr,&InpLay)!=0) return 2;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление весовых коэффициентов и пороговых уровней всех нейронов.

void strNNW::ZeroInit(void)
{
BYTE i;

if(IsOK()!=0) return; flOK=0; flChange=1; for(i=0;i<nLay;i++) Layers[i].ZeroInit();
} 

//-----------------------------------------------------------------------------------------------------------
// Нахождение начального приближения весовых коэффициентов и пороговых уровней.

BYTE strNNW::RandInit(UINT RandSeq,float CoeWei,float CoeTe)
{
srand(RandSeq); if(RandInit_(CoeWei,CoeTe)!=0) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение начального приближения весовых коэффициентов и пороговых уровней.

BYTE strNNW::RandInit_(float CoeWei,float CoeTe)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) if(Layers[i].RandInit(CoeWei,CoeTe)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Случайное изменение весовых коэффициентов и пороговых уровней.

BYTE strNNW::RandChange(UINT RandSeq,float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA)
{
srand(RandSeq); if(RandChange_(CoeWeiR,CoeTeR,CoeWeiA,CoeTeA)!=0) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Случайное изменение весовых коэффициентов и пороговых уровней.

BYTE strNNW::RandChange_(float CoeWeiR,float CoeTeR,float CoeWeiA,float CoeTeA)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) if(Layers[i].RandChange(CoeWeiR,CoeTeR,CoeWeiA,CoeTeA)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение ошибки методом обратного распространения ошибки.

BYTE strNNW::ComputeErrBackProp(strInpLay *True)
{
BYTE SetErrOutLay(strInpLay *True,strLay *Lay); // Установка ошибок для выходного слоя нейронной сети.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // Расчёт ошибок методом обратного распространения ошибки.

BYTE i; struct strLay *pLay;

if(True==NULL) return 1; if(True->IsOK()!=0) return 2; if(IsOK()!=0) return 3; if(nLay<=1) return 4;
pLay=Layers+nLay-1; if(True->n!=pLay->n) return 5;
if(SetErrOutLay(True,pLay)!=0) return 6; // Установка ошибок для выходного слоя нейронной сети.
for(i=0;i<nLay-1;i++) if(ComputeErr(Layers+nLay-2-i,Layers+nLay-1-i)!=0) return 7; // Расчёт ошибок методом обратного распространения ошибки.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг цикла обучения методом обратного распространения ошибки.

BYTE strNNW::TrainStepSequent(strInpLay *True,float AlphaConst,float AlphaMin,float AlphaMax,BYTE flAdaptSt,
BYTE flEqualAdaptSt,float coeAlpha)
{
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.

BYTE i; float v; double Alpha;

if(IsOK()!=0) return 1; if(InpLay.IsOK()!=0) return 2;
if(AlphaConst<=0.0F) return 3; if(AlphaMin<0.0F) return 4; if(AlphaMax<=0.0F) return 5;
if(AlphaMax<AlphaMin) return 6;
if(ComputeErrBackProp(True)!=0) return 7; // Нахождение ошибки методом обратного распространения ошибки.

// Нахождение адаптивного шага.
if(flAdaptSt!=0) {
if(ComputeAdaptStepAll(AlphaMin,AlphaMax,coeAlpha)!=0) return 8; // Расчёт адаптивного шага для всех слоёв сети.
if(flEqualAdaptSt!=0) {
if(GetEqualAdaptStep(&Alpha)!=0) return 9; // Нахождение одного адаптивного шага для всех слоёв.
v=coeAlpha; if(v>0.0F&&v<1.0F) Alpha*=(double)v; // Замедляющий множитель для адаптивного шага.
if(CorrectAdaptStep(&Alpha,AlphaMin,AlphaMax)!=0) return 10; // Корректировка адаптивного шага.
if(Alpha<=0.) return messStop;
if(SetAlphaConst(Alpha)!=0) return 11; // Установка одинакового шага во все слои.
}}

Alpha=(double)AlphaConst; if(flAdaptSt!=0) Alpha=Layers[0].Alpha;
if(CorrectWeightsFirst(&InpLay,Layers,Alpha)!=0) return 12; // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
if(nLay>1) for(i=1;i<nLay;i++) { if(flAdaptSt!=0) Alpha=Layers[i].Alpha;
if(CorrectWeights(Layers+i-1,Layers+i,Alpha)!=0) return 13;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг цикла обучения методом повторного обратного распространения ошибки.

BYTE strNNW::TrainStepSequentRep(strInpLay *True,float AlphaConst,float AlphaMin,float AlphaMax,
BYTE flAdaptSt,float coeAlpha)
{
BYTE SetErrOutLay(strInpLay *True,strLay *Lay); // Установка ошибок для выходного слоя нейронной сети.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // Расчёт ошибок методом обратного распространения ошибки.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.

BYTE i,n,nL; double Alpha; struct strLay *pLay;

if(True==NULL) return 1; if(True->IsOK()!=0) return 2; if(IsOK()!=0) return 3; if(InpLay.IsOK()!=0) return 4;
if(AlphaConst<=0.0F) return 5; if(AlphaMin<0.0F) return 6; if(AlphaMax<=0.0F) return 7;
if(AlphaMax<AlphaMin) return 8;
pLay=Layers+nLay-1; if(True->n!=pLay->n) return 9;
if(SetErrOutLay(True,pLay)!=0) return 10; // Установка ошибок для выходного слоя нейронной сети.

Alpha=(double)AlphaConst;
for(n=0;n<nLay;n++) { nL=nLay-1-n;
if(n>0) for(i=0;i<n;i++) if(ComputeErr(Layers+nLay-2-i,Layers+nLay-1-i)!=0) return 11; // Расчёт ошибок методом обратного распространения ошибки.
if(flAdaptSt!=0) { if(ComputeAdaptStepLay(nL,AlphaMin,AlphaMax,coeAlpha)!=0) return 12;} // Расчёт адаптивного шага начиная со слоя 'nL'.
if(flAdaptSt!=0) Alpha=Layers[nL].Alpha;
if(nL==0) { if(CorrectWeightsFirst(&InpLay,Layers+nL,Alpha)!=0) return 13;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
else { if(CorrectWeights(Layers+nL-1,Layers+nL,Alpha)!=0) return 14;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.
if(ComputeFrom(nL)!=0) return 15; // Расчёт начиная со слоя 'layIni'.
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг цикла метода последовательного послойного обучения - корректировка весов и порогов для слоя 'numLay'.

BYTE strNNW::TrainStepSequentLayWeights(UINT numSample,strInpLay *InpLay_,BYTE numLay,float AlphaConst,
float AlphaMin,float AlphaMax,BYTE flAdaptSt,float coeAlpha)
{
BYTE ComputeLayerFirst(strInpLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay" - первом скрытом слое.
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay".
BYTE SetErrLayEtal(UINT numSample,strLay *Lay); // Установка ошибок относительно эталонных значений для слоя нейронной сети.
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha); // Расчёт адаптивного шага для первого скрытого слоя 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha); // Расчёт адаптивного шага для слоя 'Lay'.
BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha); // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.

double Alpha; struct strLay *pLay,*pLayPrev;

if(IsOK()!=0) return 1; if(numLay>=nLay) return 2;
if(AlphaConst<=0.0F) return 3; if(AlphaMin<0.0F) return 4; if(AlphaMax<=0.0F) return 5;
if(AlphaMax<AlphaMin) return 6;
pLay=Get(numLay); if(pLay==NULL) return 7; if(pLay->IsOK()!=0) return 8;
if(numLay==0) { pLayPrev=NULL; if(InpLay_==NULL) return 9; if(InpLay_->IsOK()!=0) return 10;}
else { pLayPrev=Get(numLay-1); if(pLayPrev==NULL) return 11; if(pLayPrev->IsOK()!=0) return 12;}

// Установка значений предыдущего слоя и расчёт по нейронной сети значений в следующем слое.
if(numLay==0) { if(ComputeLayerFirst(InpLay_,pLay)!=0) return 13;}
else {
if(pLayPrev->SetValEqualEtal(numSample)!=0) return 14; // Установка значений нейронов, равных эталонным значениям в послойном обучении.
if(ComputeLayer(pLayPrev,pLay)!=0) return 15; // Расчёт по нейронной сети значений в следующем слое.
}

if(SetErrLayEtal(numSample,pLay)!=0) return 16; // Установка ошибок относительно эталонных значений для слоя нейронной сети.

// Нахождение и установка адаптивного шага для расчёта весов и порогов.
if(flAdaptSt!=0) {
if(numLay==0) { if(ComputeAdaptStepFirst(InpLay_,pLay,AlphaMin,AlphaMax,coeAlpha)!=0) return 17;}
else { if(ComputeAdaptStep(pLayPrev,pLay,AlphaMin,AlphaMax,coeAlpha)!=0) return 18;}}
if(flAdaptSt==0) Alpha=(double)AlphaConst; else Alpha=pLay->Alpha; // Установка адаптивного шага.

// Корректировка весовых коэффициентов и порогов.
if(numLay==0) { if(CorrectWeightsFirst(InpLay_,pLay,Alpha)!=0) return 19;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.
else { if(CorrectWeights(pLayPrev,pLay,Alpha)!=0) return 20;} // Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Шаг цикла метода последовательного послойного обучения - корректировка эталонных значений для слоя 'numLay-1'.

BYTE strNNW::TrainStepSequentLayEtal(UINT numSample,BYTE numLay,float AlphaConst,float AlphaMin,float AlphaMax,
BYTE flAdaptSt,float coeAlpha)
{
BYTE ComputeLayer(strLay *LayPrev,strLay *Lay); // Расчёт значений нейронов в слое "Lay".
BYTE SetErrLayEtal(UINT numSample,strLay *Lay); // Установка ошибок относительно эталонных значений для слоя нейронной сети.
BYTE ComputeErr(strLay *LayPrev,strLay *Lay); // Расчёт ошибок методом обратного распространения ошибки.
BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha,double *Alpha); // Расчёт адаптивного шага для расчёта эталонных значений слоя.
BYTE CorrectY(UINT numSample,strLay *Lay,double Alpha); // Коррекция значений нейронов скрытого слоя.

double Alpha; struct strLay *pLay,*pLayPrev;

if(IsOK()!=0) return 1; if(numLay>=nLay) return 2; if(numLay==0) return 3;
if(AlphaConst<=0.0F) return 4; if(AlphaMin<0.0F) return 5; if(AlphaMax<=0.0F) return 6;
if(AlphaMax<AlphaMin) return 7;
pLay=Get(numLay); if(pLay==NULL) return 8; if(pLay->IsOK()!=0) return 9;
pLayPrev=Get(numLay-1); if(pLayPrev==NULL) return 10; if(pLayPrev->IsOK()!=0) return 11;

if(pLayPrev->SetValEqualEtal(numSample)!=0) return 12; // Установка значений нейронов, равных эталонным значениям в послойном обучении.
if(ComputeLayer(pLayPrev,pLay)!=0) return 13; // Расчёт по нейронной сети значений в следующем слое.
if(SetErrLayEtal(numSample,pLay)!=0) return 14; // Установка ошибок относительно эталонных значений для слоя нейронной сети.
if(ComputeErr(pLayPrev,pLay)!=0) return 15; // Расчёт ошибок предыдущего слоя методом обратного распространения ошибки.

// Нахождение и установка адаптивного шага для расчёта эталонных значений.
if(flAdaptSt==0) Alpha=(double)AlphaConst; // Установка постоянного адаптивного шага.
else { if(ComputeAdaptStepY(pLayPrev,pLay,AlphaMin,AlphaMax,coeAlpha,&Alpha)!=0) return 16;} // Расчёт адаптивного шага для расчёта эталонных значений слоя.
if(CorrectY(numSample,pLayPrev,Alpha)!=0) return 17; // Коррекция значений нейронов предыдущего скрытого слоя.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Корректировка эталонных значений и весовых коэффициентов.

BYTE strNNW::TrainStepSequentLayCorr(BYTE numLay)
{
BYTE flCorr,ber; USHRT i,j; double ym,yM,coe,sh,*tArr,*dp; struct strLay *pLay,*pLayPrev;
struct strNeuron *pNeur,*pNeurP;

if(IsOK()!=0) return 1; if(numLay>nLay-1) return 2; if(numLay==0) return 3;
pLay=Get(numLay); if(pLay==NULL) return 4;
pLayPrev=Get(numLay-1); if(pLayPrev==NULL) return 5;

switch(pLayPrev->TypFunAct) { default: flCorr=0; break;
case TypFunAct_Sigm: flCorr=2; break; // Сигмоидная функция.
case TypFunAct_BiSigm: // Биполярная cигмоидная функция.
case TypFunAct_HypTan: // Гиперболический тангенс.
flCorr=1; break;}
if(flCorr==0) return 0; // Корректировки не требуется.

tArr=NULL; ber=0;
if(flCorr==2) {
tArr=new double[pLay->n]; if(tArr==NULL) { ber=6; goto end;}
for(j=0;j<pLay->n;j++) tArr[j]=0.;}

// Корректировка весовых коэффициентов и порогов слоя 'numLay' и эталонных значений слоя 'numLay-1'.
for(i=0;i<pLayPrev->n;i++) { pNeurP=pLayPrev->Neurons+i; if(pNeurP->Etal.IsOK()!=0) { ber=7; goto end;}
if(pNeurP->Etal.GetMinMax(&ym,&yM)!=0) { ber=8; goto end;}

// Масштабирование эталонных амплитуд и корректировка весовых коэффициентов для функций активации, определённых на интервале [-1;1].
if(flCorr==1) { coe=MAX(ABS(ym),ABS(yM)); if(coe>1.) {
if(pNeurP->Etal.Correct(1./coe,0.)!=0) { ber=9; goto end;}
for(j=0;j<pLay->n;j++) { pNeur=pLay->Neurons+j; if(pNeur->IsOK()!=0) { ber=10; goto end;}
pNeur->Weights[i]*=coe;}
}}

// Масштабирование и сдвиг эталонных амплитуд и порогов для сигмоидной функции активации, определённой на интервале [0;1].
if(flCorr==2) { if(!(ym>=0.&&yM<=1.)) {
coe=yM-ym; if(coe<1.) coe=1.; sh=ym/coe;
if(pNeurP->Etal.Correct(1./coe,-sh)!=0) { ber=11; goto end;}
for(j=0;j<pLay->n;j++) { pNeur=pLay->Neurons+j; if(pNeur->IsOK()!=0) { ber=12; goto end;}
dp=pNeur->Weights+i; tArr[j]-=*dp*ym; *dp*=coe;}
}}
}

if(flCorr==2) for(j=0;j<pLay->n;j++) { pNeur=pLay->Neurons+j; pNeur->T+=tArr[j];} // Корректировка весовых коэффициентов.

end: SAFE_DELETE_ARR(tArr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для всех слоёв сети.

BYTE strNNW::ComputeAdaptStepAll(float AlphaMin,float AlphaMax,float coeAlpha)
{
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha); // Расчёт адаптивного шага для первого скрытого слоя 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha); // Расчёт адаптивного шага для слоя 'Lay'.

BYTE i;

if(AlphaMin<0.0F) return 1; if(AlphaMax<=0.0F) return 2; if(AlphaMax<AlphaMin) return 3;
if(Layers->IsOK()!=0) return 4; if(InpLay.IsOK()!=0) return 5;
if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax,coeAlpha)!=0) return 6;
for(i=1;i<nLay;i++) { if(ComputeAdaptStep(Layers+i-1,Layers+i,AlphaMin,AlphaMax,coeAlpha)!=0) return 7;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для слоя с номером 'numLay'.

BYTE strNNW::ComputeAdaptStepLay(BYTE numLay,float AlphaMin,float AlphaMax,float coeAlpha)
{
BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha); // Расчёт адаптивного шага для первого скрытого слоя 'Lay'.
BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha); // Расчёт адаптивного шага для слоя 'Lay'.

if(AlphaMin<0.0F) return 1; if(AlphaMax<=0.0F) return 2; if(AlphaMax<AlphaMin) return 3;
if(Layers->IsOK()!=0) return 4; if(numLay>=nLay) return 5;
if(numLay==0) { if(InpLay.IsOK()!=0) return 6;
if(ComputeAdaptStepFirst(&InpLay,Layers,AlphaMin,AlphaMax,coeAlpha)!=0) return 7;}
else { if(ComputeAdaptStep(Layers+numLay-1,Layers+numLay,AlphaMin,AlphaMax,coeAlpha)!=0) return 8;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массивов векторов из памяти.

void strNNW::FreeVect(void)
{
BYTE i;

if(IsOK()!=0) return; for(i=0;i<nLay;i++) Layers[i].FreeVect();
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массивов векторов.

BYTE strNNW::AllocVect(void)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) if(Layers[i].AllocVect()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массивов векторов.

BYTE strNNW::IsOK_Vect(void)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) if(Layers[i].IsOK_Vect()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка нулей в массивы векторов.

BYTE strNNW::SetZeroVect(void)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) if(Layers[i].SetZeroVect()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение ошибки и суммирование векторов при обучении групповым методом.

BYTE strNNW::TrainGroupErrSumVect(strInpLay *True,double Wei)
{
BYTE AddVectors(strLay *LayPrev,strLay *Lay,double Wei); // Приращение массива векторов для нейронов слоя при групповом обучении.
BYTE AddVectorsFirst(strInpLay *LayPrev,strLay *Lay,double Wei); // Приращение массива векторов для нейронов первого скрытого слоя при групповом обучении.

BYTE i;

if(IsOK()!=0) return 1; if(InpLay.IsOK()!=0) return 2;
if(ComputeErrBackProp(True)!=0) return 3; // Нахождение ошибки методом обратного распространения ошибки.
if(AddVectorsFirst(&InpLay,Layers,Wei)!=0) return 4;
if(nLay>1) for(i=1;i<nLay;i++) { if(AddVectors(Layers+i-1,Layers+i,Wei)!=0) return 5;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Добавление слагаемых к вспомогательным переменным для нахождения адаптивного шага при предъявлении образца данных при групповом обучении.

BYTE strNNW::TrainGroupAdaptStep(strInpLay *True,double Wei)
{
BYTE AddAdaptStep(strLay *LayPrev,strLay *Lay,double Wei); // Суммирование в переменные для нахождения адаптивного шага при групповом обучении.
BYTE AddAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,double Wei); // Суммирование в переменные для нахождения адаптивного шага при групповом обучении.

BYTE i;

if(IsOK()!=0) return 1; if(Wei<=0.) return 2;
if(ComputeErrBackProp(True)!=0) return 3; // Нахождение ошибки методом обратного распространения ошибки.
if(AddAdaptStepFirst(&InpLay,Layers,Wei)!=0) return 4;
if(nLay>1) for(i=1;i<nLay;i++) { if(AddAdaptStep(Layers+i-1,Layers+i,Wei)!=0) return 5;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление вспомогательных переменных для суммирования при нахождении адаптивного шага при предъявлении образца данных при групповом обучении.

BYTE strNNW::ZeroNumDenomAdaptStepGroup(void)
{
BYTE i; struct strLay *pLay;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) { pLay=Get(i); if(pLay==NULL) return 2; pLay->Denom=pLay->Numer=0.;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение адаптивного шага при групповом обучении.

BYTE strNNW::FindAlphaGroup(void)
{
BYTE GetCoeDeriv(BYTE typ,double *coe); // Получение коэффициента для нахождения производной в центре интервала.

BYTE i; double d,coe; struct strLay *pLay;

if(IsOK()!=0) return 1;
for(i=0;i<nLay;i++) { pLay=Get(i); if(pLay==NULL) return 2; d=pLay->Denom;
if(GetCoeDeriv(pLay->TypFunAct,&coe)!=0) return 3; // Получение коэффициента для нахождения производной в центре интервала.
if(d<SmCnst24_d) pLay->Alpha=LrgCnst32_d; else pLay->Alpha=coe*pLay->Numer/d;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Корректировка адаптивного шага для каждого слоя.

BYTE strNNW::CorrectAlpha(float AlphaMin,float AlphaMax)
{
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

BYTE i; struct strLay *pLay;

if(IsOK()!=0) return 1;
for(i=0;i<nLay;i++) { pLay=Get(i); if(pLay==NULL) return 2;
if(CorrectAdaptStep(&pLay->Alpha,AlphaMin,AlphaMax)!=0) return 3;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Умножение адаптивного шага на замедляющий коэффициент.

BYTE strNNW::MultCoeAlpha(float CoeAlpha)
{
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

BYTE i; struct strLay *pLay;

if(IsOK()!=0) return 1; if(CoeAlpha<=0.0F) return 2; if(CoeAlpha>1.0F) return 3;
for(i=0;i<nLay;i++) { pLay=Get(i); if(pLay==NULL) return 4; pLay->Alpha*=(double)CoeAlpha;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка одинакового шага во все слои.

BYTE strNNW::SetAlphaConst(double Alpha)
{
BYTE i; struct strLay *pLay;

if(IsOK()!=0) return 1;
for(i=0;i<nLay;i++) { pLay=Get(i); if(pLay==NULL) return 2; pLay->Alpha=Alpha;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение одного адаптивного шага для всех слоёв.

BYTE strNNW::GetEqualAdaptStep(double *pAlpha)
{
BYTE GetCoeDeriv(BYTE typ,double *coe); // Получение коэффициента для нахождения производной в центре интервала.

BYTE i; double v,sN,sD; struct strLay *pLay;

if(pAlpha==NULL) return 1; if(IsOK()!=0) return 2;
sN=sD=0.;
for(i=0;i<nLay;i++) { pLay=Get(i); if(pLay==NULL) return 3;
if(GetCoeDeriv(pLay->TypFunAct,&v)!=0) return 4; // Получение коэффициента для нахождения производной в центре интервала.
if(v<=0.) return 5; v=1./v; sN+=pLay->Numer*v; sD+=pLay->Denom*v*v;}
if(sD<SmCnst24_d) *pAlpha=LrgCnst32_d; else *pAlpha=sN/sD; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Добавление вектора приращения к коэффициентам и смещениям при групповом обучении.

BYTE strNNW::AddWeightsShiftsGroup(void)
{
BYTE i; struct strLay *pLay;

if(IsOK()!=0) return 1;
for(i=0;i<nLay;i++) { pLay=Get(i); if(pLay==NULL) return 2; if(pLay->AddWeightsShiftsGroup()!=0) return 3;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение или установка массива весов и смещений или векторов весов и смещений.

BYTE strNNW::GetSetArrSearch(double *Arr,USHRT szArr,BYTE flSet,BYTE flArr)
{
BYTE i; USHRT na,ns;

if(Arr==NULL) return 1; if(szArr==0) return 2; if(IsOK()!=0) return 3; ns=0;
for(i=0;i<nLay;i++) { if(ns>szArr) return 4;
if(Layers[i].GetSetArrSearch(Arr+ns,szArr-ns,&na,flSet,flArr)!=0) return 5;
if(ns>USHRT_MAX-na) return 6; ns+=na;} if(ns!=szArr) return 7; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Визуализация работы нейронной сети.

BYTE strNNW::PaintNNW(HDC hdc,RECT *rc,float AmpNormNeur,float AmpNormAxons,float AmpNormInp,
strPal *PalPos,strPal *PalPosNeg,BYTE flWork,BYTE flAxons)
{
BYTE DrawRect_(HDC hdc,RECT *rc); // Рисование прямоугольника.
BYTE DrawTri(HDC hdc,RECT *rc,BYTE ax,BYTE dir); // Рисование треугольника.
BYTE IsColLight(DWORD Col); // Проверка цвета - светлый или тёмный.

BYTE j,num,*BC,flInpLay,flTri,flSignNeur,ber; USHRT i,k,nWei,nW,sz,szN;
int dxW,dxWin,dyWin,xI,yI,xF,yF,shX,shY,sh; DWORD Col,ColT,*pCol; size_t ln; float stX,stXN,stY,v,va;
double Y; char *pSign,*cp,c; HPEN hPen,hPenP; HBRUSH hBrush,hBrushP; RECT rcv;
struct strLay *pLay,*pLayN; struct strNeuron *pNeur,*pNeurN; struct strPal *pPal;

if(hdc==NULL) return 1; if(rc==NULL) return 2;
ImgRectC(hdc,rc,COL_WHITE,ColBkgWinNet,1);
if(IsOK()!=0) return 3; if(InpLay.IsOK()!=0) flInpLay=0; else flInpLay=1;
dxW=(int)(rc->right-rc->left); if(dxW<=0) return 4; dxWin=dxW-(2*szImgNeurMax+2); if(dxWin<=0) return 5;
dyWin=(int)(rc->bottom-rc->top); if(dyWin<=0) return 6; dyWin-=2*szImgNeurMax+2*szImgLetter+4; if(dyWin<=0) return 7;
stY=(float)dyWin/(float)nLay;
shX=(int)rc->left+szImgNeurMax+1;
shY=(int)rc->bottom-(szImgNeurMax+1);
SelectObject(hdc,hFontA);

hBrush=hBrushP=NULL; hPen=hPenP=NULL; ber=0;

// Рисование аксонов для скрытых слоёв.
if(flWork!=0) { if(AmpNormAxons<=0.0F) goto endHidAxons; if(PalPosNeg==NULL) goto endHidAxons;}
if(nLay==1) goto endHidAxons;
for(j=0;j<nLay-1;j++) {
pLay=Get(j); if(pLay==NULL) { ber=8; goto end;} if(pLay->IsOK()!=0) { ber=9; goto end;}
if(pLay->n==1) stX=0.0F; else stX=(float)dxWin/(float)(pLay->n-1);
pLayN=Get(j+1); if(pLayN==NULL) { ber=10; goto end;} if(pLayN->IsOK()!=0) { ber=11; goto end;}
if(pLayN->n==1) stXN=0.0F; else stXN=(float)dxWin/(float)(pLayN->n-1);
yI=shY-GetIntTest((float)(j+1)*stY);
yF=shY-GetIntTest((float)(j+2)*stY);
for(i=0;i<pLay->n;i++) { pNeur=pLay->Get(i); if(pNeur==NULL) { ber=12; goto end;} if(pNeur->IsOK()!=0) { ber=13; goto end;}
xI=shX+GetIntTest((float)i*stX);
for(k=0;k<pLayN->n;k++) { pNeurN=pLayN->Get(k); if(pNeurN==NULL) { ber=14; goto end;} if(pNeurN->IsOK()!=0) { ber=15; goto end;}
if(pNeurN->nWeights!=pLay->n) { ber=16; goto end;}
xF=shX+GetIntTest((float)k*stXN);
if(flWork==0) { if(pNeurN->flSmart==0) Col=ColAxons; else Col=ColAxonsSmartNeur;}
else {
// Выбор изображаемой величины для аксонов.
switch(flAxons) { default: 
case flAxons_Axons: v=(float)pNeurN->Weights[i]; break; // Весовые коэффициенты 'Wij'.
case flAxons_Shifts: if(pNeurN->flSmart!=0) v=(float)pNeurN->Shifts[i]; else continue; break; // Смещения 'Sij' для "умных" нейронов.
case flAxons_Trans: // Передающиеся величины: 'Yi*Wij'.
case flAxons_Excit: // Возбуждения - передающиеся величины минус смещения: '(Yi-Sij)*Wij'.
Y=pNeur->Val; if(flAxons==flAxons_Excit&&pNeurN->flSmart!=0) Y-=pNeurN->Shifts[i];
v=(float)(pNeurN->Weights[i]*Y); break;}

v/=AmpNormAxons; CHECK_LIM(v,-1.0F,1.0F); va=ABS(v); if(va<LevNoDrawAxons) continue;
v=(v+1.0F)*0.5F; v*=(float)nColSmoothPal; num=GetBYTE(v); if(num>=nColSmoothPal) num=nColSmoothPal-1;
BC=PalPosNeg->MasRGB[num]; Col=RGB(BC[0],BC[1],BC[2]);}
CrSelPen(hdc,&hPen,&hPenP,1,Col); DrawLine_(hdc,xI,yI,xF,yF); UnSelDelPen(hdc,&hPen,&hPenP);
}}}
endHidAxons:;

// Рисование аксонов для входного слоя.
if(flWork!=0&&flInpLay==0) { if(flAxons==flAxons_Trans||flAxons==flAxons_Excit) goto endInpAxons;}
if(flWork!=0) { if(AmpNormAxons<=0.0F) goto endInpAxons; if(PalPosNeg==NULL) goto endInpAxons;}
nWei=0;
pLay=Get(0); if(pLay==NULL) { ber=17; goto end;} if(pLay->IsOK()!=0) { ber=18; goto end;}
for(k=0;k<pLay->n;k++) { pNeur=pLay->Get(k); if(pNeur==NULL) { ber=19; goto end;} if(pNeur->IsOK()!=0) { ber=20; goto end;}
nW=pNeur->nWeights; if(k==0) nWei=nW; else if(nWei!=nW) { ber=21; goto end;}} if(nWei==0) goto endInpAxons;
if(nWei==1) stX=0.0F; else stX=(float)dxWin/(float)(nWei-1);
if(pLay->n==1) stXN=0.0F; else stXN=(float)dxWin/(float)(pLay->n-1);
yI=shY; yF=shY-GetIntTest(stY);
for(i=0;i<nWei;i++) {
xI=shX+GetIntTest((float)i*stX);
for(k=0;k<pLay->n;k++) { pNeur=pLay->Get(k); if(pNeur==NULL) { ber=22; goto end;} if(pNeur->IsOK()!=0) { ber=23; goto end;}
if(pNeur->nWeights!=nWei) { ber=24; goto end;}
xF=shX+GetIntTest((float)k*stXN);

if(flWork==0) { if(pNeur->flSmart==0) Col=ColAxons; else Col=ColAxonsSmartNeur;}
else {
// Выбор изображаемой величины для аксонов.
switch(flAxons) { default: 
case flAxons_Axons: v=(float)pNeur->Weights[i]; break; // Весовые коэффициенты 'Wij'.
case flAxons_Shifts: if(pNeur->flSmart!=0) v=(float)pNeur->Shifts[i]; else continue; break; // Смещения 'Sij' для "умных" нейронов.
case flAxons_Trans: // Передающиеся величины: 'Yi*Wij'.
case flAxons_Excit: // Возбуждения - передающиеся величины минус смещения: '(Yi-Sij)*Wij'.
if(flInpLay==0) continue; if(i>=InpLay.n) continue;
Y=InpLay.Values[i]; if(flAxons==flAxons_Excit&&pNeur->flSmart!=0) Y-=pNeur->Shifts[i];
v=(float)(pNeur->Weights[i]*Y); break;}

v/=AmpNormAxons; CHECK_LIM(v,-1.0F,1.0F); va=ABS(v); if(va<LevNoDrawAxons) continue;
v=(v+1.0F)*0.5F; v*=(float)nColSmoothPal; num=GetBYTE(v); if(num>=nColSmoothPal) num=nColSmoothPal-1;
BC=PalPosNeg->MasRGB[num]; Col=RGB(BC[0],BC[1],BC[2]);}
CrSelPen(hdc,&hPen,&hPenP,1,Col); DrawLine_(hdc,xI,yI,xF,yF); UnSelDelPen(hdc,&hPen,&hPenP);
}}
endInpAxons:;

// Рисование нейронов и печать номеров нейронов скрытых слоёв.
if(flWork!=0) { if(AmpNormNeur<=0.0F) goto endNeurAmp;}
CrSelPen(hdc,&hPen,&hPenP,1,ColCircleNeur);
if(flWork==0) SetTextColor(hdc,ColTxtNumNeur);
for(j=0;j<nLay;j++) { pLay=Get(j); if(pLay==NULL) { ber=25; goto end;} if(pLay->IsOK()!=0) { ber=26; goto end;}
if(pLay->TypFunAct==TypFunAct_Sigm) flSignNeur=0; else flSignNeur=1;
if(flSignNeur==0) pPal=PalPos; else pPal=PalPosNeg; if(pPal==NULL) continue;
yI=shY-GetIntTest((float)(j+1)*stY);
if(pLay->n==1) stX=0.0F; else stX=(float)dxWin/(float)(pLay->n-1);
sz=GetUSHRT_Test(MIN(stX,stY)*coeSzNeur*0.5F); if(sz>0) sz=MIN(sz,szImgNeurMax); else sz=szImgNeurMax;
for(i=0;i<pLay->n;i++) { pNeur=pLay->Get(i); if(pNeur==NULL) { ber=27; goto end;}
xI=shX+GetIntTest((float)i*stX);
if(flWork==0) Col=ColNeur; else {
v=(float)pNeur->Val/AmpNormNeur; if(flSignNeur!=0) { CHECK_LIM(v,-1.0F,1.0F); v=(v+1.0F)*0.5F;}
v*=(float)nColSmoothPal; num=GetBYTE(v); if(num>=nColSmoothPal) num=nColSmoothPal-1;
BC=pPal->MasRGB[num]; Col=RGB(BC[0],BC[1],BC[2]);}
if(CrSelBrush(hdc,&hBrush,&hBrushP,Col)!=0) { ber=28; goto end;} // Создание и выбор кисти.
Ellipse(hdc,xI-(int)sz,yI-(int)sz,xI+(int)sz,yI+(int)sz);
UnSelDelBrush(hdc,&hBrush,&hBrushP);
// Печать номеров нейронов.
if(flWork!=0) { if(IsColLight(Col)==0) ColT=ColImgLetterLt; else ColT=ColImgLetterDk; SetTextColor(hdc,ColT);}
rcv.left=(long)(xI-(int)sz); rcv.right=(long)(xI+(int)sz); rcv.top=(long)(yI-(int)sz); rcv.bottom=(long)(yI+(int)sz);
sprintf(TxtStr,"%d",(int)i+1);
DrawText(hdc,TxtStr,strlen(TxtStr),&rcv,DT_SINGLELINE|DT_VCENTER|DT_CENTER);
}}
UnSelDelPen(hdc,&hPen,&hPenP);
endNeurAmp:;

// Рисование порогов.
if(flWork==0) goto endNeurThr; if(AmpNormAxons<=0.0F) goto endNeurThr; if(PalPosNeg==NULL) goto endNeurThr;
CrSelPen(hdc,&hPen,&hPenP,1,ColRectNeurThr);
szN=GetUSHRT_Test(stY*coeSzNeurThr*0.5F); szN=MIN(szN,szImgNeurThrMax);
for(j=0;j<nLay;j++) { pLay=Get(j); if(pLay==NULL) { ber=29; goto end;} if(pLay->IsOK()!=0) { ber=30; goto end;}
yI=shY-GetIntTest((float)(j+1)*stY);
if(pLay->n==1) stX=0.0F; else stX=(float)dxWin/(float)(pLay->n-1);
sz=GetUSHRT_Test(MIN(stX,stY)*coeSzNeur*0.5F); if(sz>0) sz=MIN(sz,szImgNeurMax); else sz=szImgNeurMax;
sh=yI+sz+szN+2;
for(i=0;i<pLay->n;i++) { pNeur=pLay->Get(i); if(pNeur==NULL) { ber=31; goto end;} if(pNeur->flTUse==0) continue;
xI=shX+GetIntTest((float)i*stX);
v=(float)pNeur->T/AmpNormAxons; CHECK_LIM(v,-1.0F,1.0F); v=(v+1.0F)*0.5F; v*=(float)nColSmoothPal;
num=GetBYTE(v); if(num>=nColSmoothPal) num=nColSmoothPal-1;
BC=PalPosNeg->MasRGB[num]; Col=RGB(BC[0],BC[1],BC[2]);
if(CrSelBrush(hdc,&hBrush,&hBrushP,Col)!=0) { ber=32; goto end;} // Создание и выбор кисти.
rcv.left=(long)(xI-(int)sz); rcv.right=(long)(xI+(int)sz); rcv.top=(long)(sh-(int)szN); rcv.bottom=(long)(sh+(int)szN);
DrawRect_(hdc,&rcv);
UnSelDelBrush(hdc,&hBrush,&hBrushP);
}}
UnSelDelPen(hdc,&hPen,&hPenP);
endNeurThr:;

// Рисование амплитуд входных сигналов. Печать номеров входных сигналов при изображении структуры сети.
if(flInpLay==0) goto endInpAmp;
if(flWork!=0) { if(AmpNormInp<=0.0F) goto endInpAmp; if(PalPos==NULL) goto endInpAmp;}
flTri=0;
SetTextColor(hdc,ColTxtNumInpLay);
CrSelPen(hdc,&hPen,&hPenP,1,ColRectInpLay);
yI=shY; if(InpLay.n==1) stX=0.0F; else stX=(float)dxWin/(float)(InpLay.n-1);
sz=GetUSHRT_Test(stX*coeSzNeur*0.5F); sz=MIN(sz,szImgNeurMax);
szN=GetUSHRT_Test(stY*coeSzNeur*0.5F); szN=MIN(szN,szImgNeurMax);
for(i=0;i<InpLay.n;i++) {
xI=shX+GetIntTest((float)i*stX);
if(flWork==0) Col=ColInpLay; else {
v=(float)InpLay.Values[i]/AmpNormInp*(float)nColSmoothPal; num=GetBYTE(v); if(num>=nColSmoothPal) num=nColSmoothPal-1;
BC=PalPos->MasRGB[num]; Col=RGB(BC[0],BC[1],BC[2]);}
if(CrSelBrush(hdc,&hBrush,&hBrushP,Col)!=0) { ber=33; goto end;} // Создание и выбор кисти.
rcv.left=(long)(xI-(int)sz); rcv.right=(long)(xI+(int)sz); rcv.top=(long)(yI-(int)szN); rcv.bottom=(long)(yI+(int)szN);
if(typ==typNNW_Cons) { if(i<Par.nPCons) flTri=0; else flTri=1;}
if(flTri==0) DrawRect_(hdc,&rcv); else DrawTri(hdc,&rcv,1,0);
UnSelDelBrush(hdc,&hBrush,&hBrushP);
if(flWork==0) {
sprintf(TxtStr,"%d",(int)i+1);
DrawText(hdc,TxtStr,strlen(TxtStr),&rcv,DT_SINGLELINE|DT_VCENTER|DT_CENTER);}
}
UnSelDelPen(hdc,&hPen,&hPenP);
endInpAmp:;

// Печать изображения звуков (букв).
CrSelPen(hdc,&hPen,&hPenP,1,ColRectLetter);
switch(typ) { default: { ber=34; goto end;}
case typNNW_Vowel:  i=nVoicesVowel; pCol=ColVoicesVowel; pSign=SignVoicesVowel; break; // Гласные звуки.
case typNNW_Cons:   i=nVoicesCons;  pCol=ColVoicesCons;  pSign=SignVoicesCons; break; // Согласные звуки.
case typNNW_Spectr: i=nVoicesVowel+nVoicesCons; break; // Согласные звуки.
}
pLay=Get(nLay-1); if(pLay==NULL) { ber=35; goto end;} if(pLay->IsOK()!=0) { ber=36; goto end;}
if(i!=pLay->n) { ber=37; goto end;}
if(pLay->n==1) stX=0.0F; else stX=(float)dxWin/(float)(pLay->n-1);
yI=szImgLetter+2; sz=szImgLetter;

for(i=0;i<pLay->n;i++) {
xI=shX+GetIntTest((float)i*stX);
if(typ!=typNNW_Spectr) { Col=pCol[i]; c=pSign[i];}
else if(i<nVoicesVowel) { Col=ColVoicesVowel[i]; c=SignVoicesVowel[i];}
else { k=i-nVoicesVowel; Col=ColVoicesCons[k]; c=SignVoicesCons[k];}
if(IsColLight(Col)==0) ColT=ColImgLetterLt; else ColT=ColImgLetterDk; SetTextColor(hdc,ColT);
if(CrSelBrush(hdc,&hBrush,&hBrushP,Col)!=0) { ber=38; goto end;} // Создание и выбор кисти.
rcv.left=(long)(xI-(int)sz); rcv.right=(long)(xI+(int)sz); rcv.top=(long)(yI-(int)sz); rcv.bottom=(long)(yI+(int)sz);
DrawRect_(hdc,&rcv);
UnSelDelBrush(hdc,&hBrush,&hBrushP);
TxtStr[0]=c; TxtStr[1]='\0';
DrawText(hdc,TxtStr,strlen(TxtStr),&rcv,DT_SINGLELINE|DT_VCENTER|DT_CENTER);
}
UnSelDelPen(hdc,&hPen,&hPenP);

// Печать названий функций активации при изображении структуры сети.
if(flWork!=0) goto endImgFunAct; if(hInst==NULL) goto endImgFunAct;
SelectObject(hdc,hFontA);
SetTextColor(hdc,ColTextFunAct);
if(CrSelBrush(hdc,&hBrush,&hBrushP,ColBkgTextFunAct)!=0) { ber=39; goto end;} // Создание и выбор кисти.
CrSelPen(hdc,&hPen,&hPenP,1,ColFrameTextFunAct);
for(j=0;j<nLay;j++) { pLay=Get(j); if(pLay==NULL) { ber=40; goto end;} if(pLay->IsOK()!=0) { ber=41; goto end;}
yI=shY-GetIntTest((float)(j+1)*stY)+szImgNeurMax+szImgLettFunAct+2; xI=dxW/2; szN=szImgLettFunAct;
k=(USHRT)pLay->TypFunAct; if(k>=nTypFunAct) continue;
cp=NULL; if(LoadString(hInst,idS_FunAct[k],TxtStr,strL_Txt)!=0) cp=TxtStr; if(cp==NULL) continue;
ln=strlen(cp); if(ln==0) continue;
if(DrawText(hdc,cp,ln,&rcv,DT_SINGLELINE|DT_CALCRECT)==0) { ber=42; goto end;}
sz=GetUSHRT_Test((int)(rcv.right-rcv.left)+2*(int)szImgLettFunAct)/2; if(sz==0) continue;
rcv.left=(long)(xI-(int)sz); rcv.right=(long)(xI+(int)sz); rcv.top=(long)(yI-(int)szN); rcv.bottom=(long)(yI+(int)szN);
DrawRect_(hdc,&rcv); DrawText(hdc,cp,ln,&rcv,DT_SINGLELINE|DT_VCENTER|DT_CENTER);}
UnSelDelPen(hdc,&hPen,&hPenP);
UnSelDelBrush(hdc,&hBrush,&hBrushP);
endImgFunAct:;

end: UnSelDelBrush(hdc,&hBrush,&hBrushP); UnSelDelPen(hdc,&hPen,&hPenP); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление из памяти массивов эталонных значений нейронов.

BYTE strNNW::FreeEtal(void)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) if(Layers[i].FreeEtal()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массивов эталонных значений нейронов.

BYTE strNNW::AllocEtal(UINT nSamples)
{
BYTE i;

if(IsOK()!=0) return 1; if(nSamples==0) return 2;
for(i=0;i<nLay;i++) if(Layers[i].AllocEtal(nSamples)!=0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей на строки директории и имени файла.

void strNNW::ZeroNames(void)
{
PathDir=NameFile=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление из памяти строк директории и имени файла.

void strNNW::FreeNames(void)
{
FreeString(&PathDir); FreeString(&NameFile);
}

//-----------------------------------------------------------------------------------------------------------
// Установка строк директории и имени файла.

BYTE strNNW::SetNames(char *Path,char *fName)
{
if(IsOKStr(fName)!=0) return 1;
if(DupString(&PathDir,Path)!=0) FreeString(&PathDir);
if(DupString(&NameFile,fName)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка строки имени файла.

BYTE strNNW::IsOK_Name(void)
{
if(NameFile==NULL) return 1; if(strlen(NameFile)==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Копирование структуры нейронной сети.

BYTE CopyNNW(strNNW *Dst,strNNW *Src)
{
BYTE CopyPropNNW(strPropNNW *Dst,strPropNNW *Src); // Копирование структуры свойств и параметров нейронной сети.
BYTE CopyStrLay(strLay *Dst,strLay *Src); // Копирование структуры слоя нейронов.

BYTE i;

if(Dst==NULL) return 1; Dst->Free(); Dst->Par.Init(); Dst->FreeNames(); Dst->InpLay.Free();
if(Src==NULL) return 2;
Dst->typ=Src->typ;
if(CopyPropNNW(&Dst->Par,&Src->Par)!=0) return 3;
if(Src->IsOK()!=0) return 4; if(Dst->Alloc(Src->nLay)!=0) return 5; Dst->flOK=Src->flOK;
for(i=0;i<Src->nLay;i++) if(CopyStrLay(Dst->Layers+i,Src->Layers+i)!=0) return 6;
DupString(&Dst->PathDir,Src->PathDir);
DupString(&Dst->NameFile,Src->NameFile);
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров тренировки нейронной сети групповым методом поиска.

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParTrainNNWSearch::IsOK(void)
{
if(nStRepM==0) return 1; if(coeStI<=0.0F) return 2; if(coeSt<=0.0F) return 3; if(coeChSt<=0.0F) return 4; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура вспомогательных массивов для тренировки сети методом поиска.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strArrTrSearch::strArrTrSearch(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strArrTrSearch::~strArrTrSearch(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей.

void strArrTrSearch::Zero(void)
{
Coe=CoeN=CoeS=Vect=VectN=NULL; nV=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strArrTrSearch::Free(void)
{
SAFE_DELETE_ARR(Coe);
SAFE_DELETE_ARR(CoeN);
SAFE_DELETE_ARR(CoeS);
SAFE_DELETE_ARR(Vect);
SAFE_DELETE_ARR(VectN);
nV=0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание массивов.

BYTE strArrTrSearch::Create(USHRT nV_)
{
BYTE ber;

if(nV_==0) return 1; Free(); ber=0; nV=nV_;
Coe=new double[nV]; if(Coe==NULL) { ber=1; goto end;}
CoeN=new double[nV]; if(CoeN==NULL) { ber=2; goto end;}
CoeS=new double[nV]; if(CoeS==NULL) { ber=3; goto end;}
Vect=new double[nV]; if(Vect==NULL) { ber=4; goto end;}
VectN=new double[nV]; if(VectN==NULL) { ber=5; goto end;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strArrTrSearch::IsOK(void)
{
if(Coe==NULL) return 1; if(CoeN==NULL) return 2; if(CoeS==NULL) return 3;
if(Vect==NULL) return 4; if(VectN==NULL) return 5; if(nV==0) return 6; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров слоя.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strParLay::strParLay(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

void strParLay::Init(void)
{
nNeurons=nNeurons_Stand; TypFunAct=TypFunAct_Sigm; flTUse=1; flSmart=0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParLay::IsOK(void)
{
if(nNeurons==0) return 1; if(TypFunAct>=nTypFunAct) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Печать в строку.

void strParLay::Print(void)
{
char *cp,*cTUse,*cShUse;

cp="-"; if(hInst!=NULL&&TypFunAct<nTypFunAct) { if(LoadString(hInst,idS_FunAct[TypFunAct],TxtMem,strL_Txt)!=0) cp=TxtMem;}
if(flTUse==0) cTUse="-"; else cTUse="+";
if(flSmart==0) cShUse="-"; else cShUse="+";
sprintf(TxtStr,"%d %s %s %s" ,(int)nNeurons,cp,cTUse,cShUse);
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParLay::Read(FILE *file)
{
int iv;

if(file==NULL) return 1; Init();
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0) return 3; if(iv>USHRT_MAX) return 4; if(iv==0) return 0;
nNeurons=(USHRT)iv;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv<0) return 6; if(iv>nTypFunAct) return 7; TypFunAct=(BYTE)iv;
if(fscanf(file,"%d",&iv)==EOF) return 8; if(iv==0) flTUse=0; else flTUse=1;
if(fscanf(file,"%d",&iv)==EOF) return 9; if(iv==0) flSmart=0; else flSmart=1;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strParLay::Write(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%d %d %d %d  ",(int)nNeurons,(int)TypFunAct,(int)flTUse,(int)flSmart)<0) return 2; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strParNNW::strParNNW(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strParNNW::~strParNNW(void)
{
Free(); FreeNames();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void strParNNW::Zero(void)
{
nLay=0; ParLay=NULL; Par.Init(); flChange=0; ZeroNames();
}

//-----------------------------------------------------------------------------------------------------------
// Удаление объектов из памяти.

void strParNNW::Free(void)
{
SAFE_FREE(ParLay); nLay=0; flChange=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массива структур параметров слоёв нейронов.

BYTE strParNNW::Alloc(BYTE nLay_)
{
size_t sz;

Free(); if(nLay_==0) return 1; nLay=nLay_; sz=sizeof(strParLay)*(size_t)nLay;
ParLay=(strParLay *)malloc(sz); if(ParLay==NULL) { nLay=0; return messNoMem;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Перераспределение памяти для массива структур параметров слоёв нейронов.

BYTE strParNNW::ReAlloc(BYTE nLay_)
{
size_t sz; struct strParLay *ParLay_;

if(nLay_==0) { Free(); return 0;}
if(IsOK()!=0) { if(Alloc(nLay_)!=0) return 1; return 0;} if(nLay_==nLay) return 0;
sz=sizeof(strParLay)*(size_t)nLay_;
ParLay_=(strParLay *)realloc((void *)ParLay,sz); if(ParLay_==NULL) return messNoMem;
if(ParLay!=ParLay_) ParLay=ParLay_; nLay=nLay_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParNNW::IsOK(void)
{
if(nLay==0) return 1; if(ParLay==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки включая структуры параметров слоёв нейронов.

BYTE strParNNW::IsOK_(void)
{
BYTE i;

if(IsOK()!=0) return 1; for(i=0;i<nLay;i++) if(ParLay[i].IsOK()!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение указателя на параметры слоя.

strParLay *strParNNW::Get(BYTE num)
{
if(IsOK()!=0) return NULL; if(num>=nLay) return NULL; return &ParLay[num];
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация структуры параметров нейронной сети.

BYTE strParNNW::Init(BYTE typNNW)
{
struct strParLay *pPL;

if(typNNW>=nTypesNNW) return 1; Free(); Par.Init(); Par.flType=typNNW;
if(Alloc(1)!=0) return 2; pPL=Get(0); if(pPL==NULL) return 3;

switch(Par.flType) { default: return 4;
case typNNW_Vowel: pPL->nNeurons=nVoicesVowel; break; // Гласные звуки.
case typNNW_Cons: pPL->nNeurons=nVoicesCons; break; // Согласные звуки.
case typNNW_Spectr: pPL->nNeurons=(USHRT)nVoicesVowel+(USHRT)nVoicesCons; break; // Применение нейронных сетей сразу для всего спектра.
}

pPL->TypFunAct=TypFunAct_Sigm;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Вставка слоя.

BYTE strParNNW::InsItem(BYTE num)
{
BYTE i; SHRT j;

if(IsOK()!=0) { if(Alloc(1)!=0) return 1;}
else { if((int)nLay+1>UCHAR_MAX) return 2; if(ReAlloc(nLay+1)!=0) return 3;
if(num<nLay-1) for(i=num;i<nLay-1;i++) { j=(SHRT)nLay-2+(SHRT)num-(SHRT)i; COPY(&ParLay[j+1],&ParLay[j]);}}
flChange=1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление слоя.

BYTE strParNNW::DelItem(BYTE num)
{
BYTE i;

if(IsOK()!=0) return 1; if(num>=nLay) return 2;
if(num<nLay-1) for(i=num+1;i<nLay-1;i++) COPY(&ParLay[i-1],&ParLay[i]);
if(ReAlloc(nLay-1)!=0) return 3; flChange=1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParNNW::Read_(FILE *file)
{
BYTE i; int iv;

if(file==NULL) return 1; Free(); Par.Init(); flChange=1;
if(Par.Read(file)!=0) return 2;
if(fscanf(file,"%d",&iv)==EOF) return 3; if(iv<0) return 4; if(iv>UCHAR_MAX) return 5; if(iv==0) return 0;
if(Alloc((BYTE)iv)!=0) return 6; for(i=0;i<nLay;i++) if(ParLay[i].Read(file)!=0) return 7;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE strParNNW::Write_(FILE *file)
{
BYTE i;

if(file==NULL) return 1;
if(Par.Write(file)!=0) return 2;
if(fprintf(file,"%d\n",(int)nLay)<0) return 3;
if(IsOK()!=0) { if(fprintf(file,"\n")<0) return 4; return 0;}
for(i=0;i<nLay;i++) { if(ParLay[i].Write(file)!=0) return 5; if(fprintf(file,"\n")<0) return 6;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParNNW::Read(char *Path,char *fName,char *ext)
{
BYTE err; char *name; clFileT *FT;

if(IsOKStr(fName)!=0) return 1; if(IsOKStr(ext)!=0) return 2;
Free(); Par.Init(); FreeNames();
name=NULL; FT=NULL; err=0;
if(GetName(&name,Path,NULL,fName,ext)!=0) { err=3; goto end;}
if(SetNames(Path,fName)!=0) { err=4; goto end;}
FT=new clFileT(); if(FT==NULL) { err=5; goto end;}
if(FT->Open(name,0)!=0) { err=6; goto end;} 
if(Read_(FT->file)!=0) { err=7; goto end;}
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение в файле.

BYTE strParNNW::Write(char *Path,char *fName,char *ext)
{
BYTE err; char *name; clFileT *FT;

if(IsOKStr(fName)!=0) return 1; if(IsOKStr(ext)!=0) return 2;
name=NULL; FT=NULL; err=0;
if(GetName(&name,Path,NULL,fName,ext)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,1)!=0) { err=5; goto end;} 
if(Write_(FT->file)!=0) { err=6; goto end;}
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение в файле.

BYTE strParNNW::Write(void)
{
BYTE err; char *name,*ext; clFileT *FT;

if(IsOK_Name()!=0) return 1;
switch(Par.flType) { default: return 2;
case typNNW_Vowel:  ext=extParNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   ext=extParNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: ext=extParNNW_Spectr; break; // Для всего спектра.
}
name=NULL; FT=NULL; err=0;
if(GetName(&name,PathDir,NULL,NameFile,ext)!=0) { err=3; goto end;}
FT=new clFileT(); if(FT==NULL) { err=4; goto end;}
if(FT->Open(name,1)!=0) { err=5; goto end;} 
if(Write_(FT->file)!=0) { err=6; goto end;}
end: SAFE_DELETE(FT); FreeString(&name); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей на строки директории и имени файла.

void strParNNW::ZeroNames(void)
{
PathDir=NameFile=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление из памяти строк директории и имени файла.

void strParNNW::FreeNames(void)
{
FreeString(&PathDir); FreeString(&NameFile);
}

//-----------------------------------------------------------------------------------------------------------
// Установка строк директории и имени файла.

BYTE strParNNW::SetNames(char *Path,char *fName)
{
if(IsOKStr(fName)!=0) return 1;
if(DupString(&PathDir,Path)!=0) FreeString(&PathDir);
if(DupString(&NameFile,fName)!=0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка строки имени файла.

BYTE strParNNW::IsOK_Name(void)
{
if(NameFile==NULL) return 1; if(strlen(NameFile)==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Настройка параметров частотной коррекции спектральных линий.

BYTE strParNNW::EdtParFreqCorrPeaks(HWND hDlg)
{
INT_PTR CALLBACK DlgParFreqCorrPeaks(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam); // Функция диалогового окна настройки параметров частотной коррекции спектральных линий.

BYTE fl;

if(hDlg==NULL) return 1; if(hInst==NULL) return 2;
fl=(BYTE)DialogBoxParam(hInst,MAKEINTRESOURCE(IDD_PAR_FREQ_CORR_PEAKS),hDlg,(DLGPROC)DlgParFreqCorrPeaks,
(LPARAM)&Par.FreqCorrPeaks); if(fl==0) return messRet; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Настройка параметров частотной коррекции спектра.

BYTE strParNNW::EdtParFreqCorrSpectr(HWND hDlg)
{
INT_PTR CALLBACK DlgParFreqCorrSpectr(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam); // Функция диалогового окна настройки параметров частотной коррекции спектра.

BYTE fl;

if(hDlg==NULL) return 1; if(hInst==NULL) return 2;
fl=(BYTE)DialogBoxParam(hInst,MAKEINTRESOURCE(IDD_PAR_FREQ_CORR_SPECTR),hDlg,(DLGPROC)DlgParFreqCorrSpectr,
(LPARAM)&Par.FreqCorrSpectr); if(fl==0) return messRet; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс диалогового окна настройки параметров нейронной сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

clDlgParNNW::clDlgParNNW(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

clDlgParNNW::~clDlgParNNW(void)
{
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов и указателей.

void clDlgParNNW::Zero(void)
{
hDlg=NULL; numSel=UCHAR_MAX; selLay=NULL; flChLay=0; pPar=NULL; flLastLay=0; blkChType=1;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE clDlgParNNW::IsOK(void)
{
if(pPar==NULL) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при открытии диалогового окна.

BYTE clDlgParNNW::OnOpenDlg(HWND hDlg_)
{
if(hDlg_==NULL) return 1; hDlg=hDlg_; if(IsOK()!=0) return 2;
SetPosWindowCenter(hDlg); // Помещение окна в центр другого окна или экрана.
SetSizeCombo(hDlg,IDC_FUN_ACT,nTypFunAct);
FillStrCombo(hDlg,IDC_FUN_ACT,idS_FunAct,nTypFunAct,TypFunAct_Sigm); // Список функций активации.

SetDlgWinEdt(); // Установка параметров в окнах редактирования.
FillLBLayers(); // Заполнение списка слоёв нейронной сети.

// Установка состояния окон управления и кнопок.
EnableRadioTypNet(); // Установка состояния кнопок задания типа сети.
EnableBtnTypInpData(); // Установка состояния кнопок в зависимости от типа входных данных для сети.
ChBtnAccept(); // Изменение состояния кнопки принятия изменений.
SetUSHRT_Edt(hDlg,IDC_NUM_NEURONS,nNeurons_Stand);

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров в окнах редактирования.

void clDlgParNNW::SetDlgWinEdt(void)
{
BYTE typ;

if(hDlg==NULL) return; if(IsOK()!=0) return;

typ=pPar->Par.flType; if(typ>=nTypesNNW) typ=nTypesNNW-1;
CheckRadioButton(hDlg,IDC_RADIO_VOWEL,IDC_RADIO_SPECTR,IDC_RADIO_VOWEL+(int)typ);

typ=pPar->Par.flTypInpData; if(typ>=nDiffDataNNW) typ=nDiffDataNNW-1;
CheckRadioButton(hDlg,IDC_RADIO_TYP_NNW_PEAKS,IDC_RADIO_TYP_NNW_SPECTR_ALL,IDC_RADIO_TYP_NNW_PEAKS+(int)typ);

SetChBox(hDlg,IDC_FREQ_CORR,pPar->Par.flFrCorr);
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение списка слоёв нейронной сети.

BYTE clDlgParNNW::FillLBLayers(void)
{
BYTE i; HWND hwnd; struct strParLay *pPL;

if(hDlg==0) return 1; if(IsOK()!=0) return 2; if(pPar->IsOK()!=0) return 3;
hwnd=GetDlgItem(hDlg,IDC_LIST_LAYERS); if(hwnd==NULL) return 4;
SendMessage(hwnd,LB_RESETCONTENT,0,0L);
for(i=0;i<pPar->nLay;i++) { pPL=pPar->Get(i); pPL->Print(); SendMessage(hwnd,LB_ADDSTRING,0,(LPARAM)(LPSTR)TxtStr);}
SelectLayer_(0); SendMessage(hwnd,LB_SETCURSEL,0,0L); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Отмена выбора слоя.

void clDlgParNNW::UnSelLayer(void)
{
numSel=UCHAR_MAX; selLay=NULL; UnSetWinParLay();
}

//-----------------------------------------------------------------------------------------------------------
// Изменение выбранного слоя.

BYTE clDlgParNNW::OnChangeLayer(void)
{
long msg; HWND hwnd;

UnSelLayer(); if(hDlg==NULL) return 1; hwnd=GetDlgItem(hDlg,IDC_LIST_LAYERS); if(hwnd==NULL) return 2;
msg=SendMessage(hwnd,LB_GETCURSEL,0,0L); if(msg==LB_ERR) return 3; if(msg>=UCHAR_MAX) return 4;
SelectLayer_((BYTE)msg); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выбор слоя с отображением параметров в окнах.

void clDlgParNNW::SelectLayer_(BYTE num)
{
if(SelectLayer(num)!=0) return; SetWinParLay_();
}

//-----------------------------------------------------------------------------------------------------------
// Выбор слоя.

BYTE clDlgParNNW::SelectLayer(BYTE num)
{
if(IsOK()!=0) return 1; if(num>=pPar->nLay) return 2; numSel=num; selLay=pPar->Get(numSel);
if(num==pPar->nLay-1) flLastLay=1; else flLastLay=0; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров слоя нейронной сети в окнах.

void clDlgParNNW::SetWinParLay_(void)
{
if(SetWinParLay()!=0) UnSetWinParLay(); flChLay=0; ChBtnAccept(); ChBtnDelAdd();
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров слоя нейронной сети в окнах.

BYTE clDlgParNNW::SetWinParLay(void)
{
if(selLay==NULL) return 1; if(hDlg==NULL) return 0;
SetUSHRT_Edt(hDlg,IDC_NUM_NEURONS,selLay->nNeurons);
SetSelCombo(hDlg,IDC_FUN_ACT,selLay->TypFunAct);
SetChBox(hDlg,IDC_CHECK_THR_USE,selLay->flTUse);
SetChBox(hDlg,IDC_CHECK_SHIFTS_USE,selLay->flSmart);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Очистка окон параметров слоя нейронной сети.

void clDlgParNNW::UnSetWinParLay(void)
{
if(hDlg==NULL) return;
SetDlgItemText(hDlg,IDC_NUM_NEURONS,"");
SetSelCombo(hDlg,IDC_FUN_ACT,TypFunAct_Sigm);
SetChBox(hDlg,IDC_CHECK_THR_USE,1);
SetChBox(hDlg,IDC_CHECK_SHIFTS_USE,0);
}

//-----------------------------------------------------------------------------------------------------------
// Принятие изменений параметров слоя.

BYTE clDlgParNNW::AcceptChanges(void)
{
long msg; HWND hwnd;

if(hDlg==NULL) return 1; if(IsOK()!=0) return 2; if(selLay==NULL) return 3; if(numSel>=pPar->nLay) return 4;
SetParLaySel(); selLay->Print();
hwnd=GetDlgItem(hDlg,IDC_LIST_LAYERS); if(hwnd==NULL) return 5;
msg=SendMessage(hwnd,LB_DELETESTRING,(WPARAM)numSel,0L); if(msg==LB_ERR) return 6;
msg=SendMessage(hwnd,LB_INSERTSTRING,(WPARAM)numSel,(LPARAM)(LPCTSTR)TxtStr);
if(msg==LB_ERR||msg==LB_ERRSPACE) return 7;
SendMessage(hwnd,LB_SETCURSEL,(WPARAM)numSel,0L);
flChLay=0; ChBtnAccept(); pPar->flChange=1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров выбранного слоя.

BYTE clDlgParNNW::SetParLaySel(void)
{
USHRT nNeur;

if(selLay==NULL) return 1; if(hDlg==NULL) return 2;
if(GetSelCombo(hDlg,IDC_FUN_ACT,&selLay->TypFunAct)!=0) return 3;
GetChBox(hDlg,IDC_CHECK_THR_USE,&selLay->flTUse);
GetChBox(hDlg,IDC_CHECK_SHIFTS_USE,&selLay->flSmart);
if(flLastLay==0) { GetUSHRT_Edt(hDlg,IDC_NUM_NEURONS,&nNeur); if(nNeur==0) nNeur=1; selLay->nNeurons=nNeur;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Вставка слоя.

BYTE clDlgParNNW::AddInsItem(BYTE flAdd)
{
long msg; BYTE num; HWND hwnd;

if(IsOK()!=0) return 1;
if(pPar->IsOK()!=0) num=0; else { if(numSel>=pPar->nLay) return 2; if(flAdd!=0) num=numSel+1; else num=numSel;}
if(pPar->InsItem(num)!=0) return 3;
SelectLayer(num); SetParLaySel(); SetWinParLay_(); if(selLay==NULL) return 4;
if(hDlg==NULL) return 5; hwnd=GetDlgItem(hDlg,IDC_LIST_LAYERS); if(hwnd==NULL) return 6;
selLay->Print();
msg=SendMessage(hwnd,LB_INSERTSTRING,(WPARAM)num,(LPARAM)(LPCTSTR)TxtStr);
if(msg==LB_ERR||msg==LB_ERRSPACE) return 7;
SendMessage(hwnd,LB_SETCURSEL,(WPARAM)num,0L);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление слоя.

BYTE clDlgParNNW::DelItem(void)
{
HWND hwnd;

if(IsOK()!=0) return 1; if(numSel>=pPar->nLay) return 2; if(hDlg==NULL) return 3;
hwnd=GetDlgItem(hDlg,IDC_LIST_LAYERS); if(hwnd==NULL) return 4;
if(numSel<pPar->nLay) SendMessage(hwnd,LB_DELETESTRING,(WPARAM)numSel,0L);
if(pPar->DelItem(numSel)!=0) return 5;
if(numSel<pPar->nLay) SelectLayer_(numSel);
else if(numSel==pPar->nLay&&pPar->nLay>0) SelectLayer_(numSel-1); else UnSelLayer();
if(numSel<pPar->nLay) SendMessage(hwnd,LB_SETCURSEL,(WPARAM)numSel,0L);
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выбор типа нейронной сети.

void clDlgParNNW::SelectTypNNW(int id)
{
BYTE typ;

if(blkChType!=0) return; if(IsOK()!=0) return;
switch(id) { default: return;
case IDC_RADIO_VOWEL:  typ=typNNW_Vowel; break; // Для гласных звуков.
case IDC_RADIO_CONS:   typ=typNNW_Cons; break; // Для согласных звуков.
case IDC_RADIO_SPECTR: typ=typNNW_Spectr; break; // Для всего спектра.
}
if(typ==pPar->Par.flType) return; pPar->Par.flType=typ; EnableBtnTypInpData(); pPar->flChange=1;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение параметров из файла.

BYTE clDlgParNNW::ReadParNNW(void)
{
BYTE err; int idSFilt; char *ext;

if(hDlg==NULL) return 1; if(IsOK()!=0) return 2;
switch(pPar->Par.flType) { default: return 3;
case typNNW_Vowel:  idSFilt=IDS_Filt_ParNNW_Vowel;  ext=extParNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   idSFilt=IDS_Filt_ParNNW_Cons;   ext=extParNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: idSFilt=IDS_Filt_ParNNW_Spectr; ext=extParNNW_Spectr; break; // Для всего спектра.
}
strcpy(FileNameN,"");
err=FileNameQuest(hDlg,0,idSFilt,PathToDirParNNW,ext,IDS_HeaderDlg_OpenParNNW,FileNameN,
strL_FileName,PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 4;
if(CompareStrCase(ExtN,ext)!=0) return 5; strcpy(PathToDirParNNW,PathToDirN);
if(pPar->Read(PathToDirN,FileNameN,ext)!=0) return 6; pPar->flChange=1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись параметров в файл.

BYTE clDlgParNNW::WriteParNNW(void)
{
BYTE fl,err; int idSFilt; char *ext;

if(hDlg==NULL) return 1; if(IsOK()!=0) return 2;
switch(pPar->Par.flType) { default: return 3;
case typNNW_Vowel:  idSFilt=IDS_Filt_ParNNW_Vowel;  ext=extParNNW_Vowel; break; // Для гласных звуков.
case typNNW_Cons:   idSFilt=IDS_Filt_ParNNW_Cons;   ext=extParNNW_Cons; break; // Для согласных звуков.
case typNNW_Spectr: idSFilt=IDS_Filt_ParNNW_Spectr; ext=extParNNW_Spectr; break; // Для всего спектра.
}
fl=0; if(pPar->IsOK_Name()==0) { if(StrCopy(FileNameN,strL_FileName,pPar->NameFile)==0) fl=1;}
if(fl==0) strcpy(FileNameN,"ParNNW");
err=FileNameQuest(hDlg,1,idSFilt,PathToDirParNNW,ext,IDS_HeaderDlg_SaveParNNW,FileNameN,
strL_FileName,PathToDirN,strL_Path,ExtN,szExt,0); if(err==messRet) return messRet; if(err!=0) return 4;
if(CompareStrCase(ExtN,ext)!=0) return 5; strcpy(PathToDirParNNW,PathToDirN);
if(pPar->Write(PathToDirN,FileNameN,ext)!=0) return 6;
if(pPar->IsOK_Name()!=0) { if(pPar->SetNames(PathToDirN,FileNameN)!=0) return 7;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Изменение состояния кнопки принятия изменений.

void clDlgParNNW::ChBtnAccept(void)
{
EnableChWin(hDlg,IDC_ACCEPT,flChLay);
}

//-----------------------------------------------------------------------------------------------------------
// Блокировка и разблокирование кнопок удаления и добавления.

void clDlgParNNW::ChBtnDelAdd(void)
{
BYTE fl;

if(flLastLay==0) fl=1; else fl=0; EnableChWin(hDlg,IDC_DEL,fl); EnableChWin(hDlg,IDC_ADD,fl);
}

//-----------------------------------------------------------------------------------------------------------
// Действия при изменении флагов параметров.

BYTE clDlgParNNW::OnChangeFlags(int id)
{
BYTE fl,num,*bp;

if(hDlg==NULL) return 1; if(selLay==NULL) return 2;
switch(id) { default: return 3;
case IDC_CHECK_THR_USE: bp=&selLay->flTUse; num=numParLay_TUse; break;
case IDC_CHECK_SHIFTS_USE: bp=&selLay->flSmart; num=numParLay_Shifts; break;
}
if(GetChBox(hDlg,id,&fl)!=0) return 4;
if(fl!=*bp) flChLay|=1<<num; else flChLay&=~(1<<num); ChBtnAccept(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка состояния кнопок задания типа сети.

void clDlgParNNW::EnableRadioTypNet(void)
{
BYTE En;

if(blkChType!=0) En=0; else En=1;
EnableChWin(hDlg,IDC_RADIO_VOWEL,En);
EnableChWin(hDlg,IDC_RADIO_CONS,En);
EnableChWin(hDlg,IDC_RADIO_SPECTR,En);
}

//-----------------------------------------------------------------------------------------------------------
// Установка состояния кнопок в зависимости от типа входных данных для сети.

void clDlgParNNW::EnableBtnTypInpData(void)
{
BYTE EnP,EnSpT,EnSpTE;

if(IsOK()!=0) EnP=EnSpT=EnSpTE=0; else
switch(pPar->Par.flType) { default: EnP=EnSpT=EnSpTE=0; break;
case typNNW_Vowel: EnP=EnSpT=EnSpTE=1; break; // Для гласных звуков.
case typNNW_Cons: EnP=EnSpT=1; EnSpTE=0; break; // Для согласных звуков.
case typNNW_Spectr: EnP=EnSpT=EnSpTE=0; break; // Для всего спектра.
}
EnableChWin(hDlg,IDC_RADIO_TYP_NNW_PEAKS,EnP);
EnableChWin(hDlg,IDC_RADIO_TYP_NNW_SPECTR_TRI,EnSpT);
EnableChWin(hDlg,IDC_RADIO_TYP_NNW_SPECTR_TRI_ENV,EnSpTE);

if(pPar->Par.flType==typNNW_Vowel) EnP=1; else EnP=0;
EnableChWin(hDlg,IDC_PARAM_FREQ_CORR_PEAKS,EnP);
}

//-----------------------------------------------------------------------------------------------------------
// Выбор типа входных данных для сети.

void clDlgParNNW::SelectTypInpData(int id)
{
BYTE typ;

if(IsOK()!=0) return;
switch(id) { default: return;
case IDC_RADIO_TYP_NNW_PEAKS: typ=typDataNNW_Peaks; break; // По пикам.
case IDC_RADIO_TYP_NNW_SPECTR_TRI: typ=typDataNNW_SpectrTri; break; // По спектру с разложением по треугольным функциям.
case IDC_RADIO_TYP_NNW_SPECTR_TRI_ENV: typ=typDataNNW_SpectrTriEnv; break; // По спектру с разложением огибающей по треугольным функциям.
case IDC_RADIO_TYP_NNW_SPECTR_ALL: typ=typDataNNW_SpectrRow; break; // Непосредственно спектр.
}

if(typ==pPar->Par.flTypInpData) return; pPar->Par.flTypInpData=typ; pPar->flChange=1;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка сообщений диалогового окна.

BYTE clDlgParNNW::MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
if(flag==NULL) return 0L; *flag=0; if(hDlg==NULL) return 0L; if(msg==WM_INITDIALOG) return 0L;

switch(msg) { default: break;

// WM_SYSCOMMAND ............................................................................................
case WM_SYSCOMMAND: if(wParam==SC_CLOSE) { *flag=1; EndDialog(hDlg,0); return (INT_PTR)TRUE;} break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: if(Command(wParam)==0) { *flag=1; break;} break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Обработка команд диалогового окна.

BYTE clDlgParNNW::Command(WPARAM wParam)
{
BYTE flag,fl,be; int id;

if(hDlg==NULL) return 1; flag=0; id=LOWORD(wParam);

switch(id) { default: flag=2; break;

// IDC_LIST_LAYERS ..........................................................................................
case IDC_LIST_LAYERS: if(HIWORD(wParam)==LBN_SELCHANGE) { OnChangeLayer(); break;} break;

// IDC_NUM_NEURONS ..........................................................................................
case IDC_NUM_NEURONS: if(HIWORD(wParam)!=EN_CHANGE) break; if(selLay==NULL) break; if(flLastLay!=0) break;
flChLay|=1<<numParLay_Neurons; ChBtnAccept(); break;

// IDC_FUN_ACT ..............................................................................................
case IDC_FUN_ACT: if(HIWORD(wParam)!=CBN_SELCHANGE) break; if(selLay==NULL) break;
flChLay|=1<<numParLay_FunAct; ChBtnAccept(); break;

// IDC_CHECK_THR_USE IDC_CHECK_SHIFTS_USE ...................................................................
case IDC_CHECK_THR_USE: case IDC_CHECK_SHIFTS_USE: OnChangeFlags(id); break;

// IDC_ACCEPT ...............................................................................................
case IDC_ACCEPT: if(selLay==NULL) { SoundBlock(); break;} AcceptChanges(); break;

// IDC_ADD ..................................................................................................
case IDC_ADD: if(AddInsItem(1)!=0) SoundBlock(); break;

// IDC_INS ..................................................................................................
case IDC_INS: if(AddInsItem(0)!=0) SoundBlock(); break;

// IDC_DEL ..................................................................................................
case IDC_DEL: DelItem(); break;

// IDC_FREQ_CORR ............................................................................................
case IDC_FREQ_CORR: if(IsOK()!=0) break; GetChBox(hDlg,IDC_FREQ_CORR,&pPar->Par.flFrCorr); pPar->flChange=1; break;

// IDC_PARAM_FREQ_CORR_PEAKS ................................................................................
case IDC_PARAM_FREQ_CORR_PEAKS: if(IsOK()!=0) break; fl=pPar->EdtParFreqCorrPeaks(hDlg);
if(fl!=0||fl==messRet) break; pPar->flChange=1; break;

// IDC_PARAM_FREQ_CORR_SPECTR ...............................................................................
case IDC_PARAM_FREQ_CORR_SPECTR: if(IsOK()!=0) break; fl=pPar->EdtParFreqCorrSpectr(hDlg);
if(fl!=0||fl==messRet) break; pPar->flChange=1; break;

// IDC_RADIO_TYP_NNW_PEAKS IDC_RADIO_TYP_NNW_SPECTR_TRI IDC_RADIO_TYP_NNW_SPECTR_TRI_ENV IDC_RADIO_TYP_NNW_SPECTR_ALL
case IDC_RADIO_TYP_NNW_PEAKS: case IDC_RADIO_TYP_NNW_SPECTR_TRI: case IDC_RADIO_TYP_NNW_SPECTR_TRI_ENV:
case IDC_RADIO_TYP_NNW_SPECTR_ALL: SelectTypInpData(id); break;

// IDC_RADIO_VOWEL IDC_RADIO_CONS IDC_RADIO_SPECTR ..........................................................
case IDC_RADIO_VOWEL: case IDC_RADIO_CONS: case IDC_RADIO_SPECTR: SelectTypNNW(id); break;

// IDC_READ .................................................................................................
case IDC_READ: be=ReadParNNW(); if(be==messRet) break; SetDlgWinEdt(); FillLBLayers(); break;

// IDC_WRITE ................................................................................................
case IDC_WRITE: WriteParNNW(); break;

// IDOK .....................................................................................................
case IDOK: EndDialog(hDlg,0); return (INT_PTR)TRUE;
}

return flag;
}

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна задания параметров нейронной сети.

INT_PTR CALLBACK DlgProcParNNW(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE flag; int id; struct clDlgParNNW *DPNNW;

if(msg!=WM_INITDIALOG) { DPNNW=(clDlgParNNW *)GetWindowLong(hDlg,DWL_USER);
if(DPNNW!=NULL) { LRes=DPNNW->MsgCommand(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) {

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetWindowLong(hDlg,DWL_USER,(long)lParam); DPNNW=(clDlgParNNW *)lParam;
if(DPNNW!=NULL) DPNNW->OnOpenDlg(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK .....................................................................................................
case IDOK: EndDialog(hDlg,0); return (INT_PTR)TRUE;
}
break;
}

return (INT_PTR)FALSE;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура спектральной линии.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strSpectrLine::strSpectrLine(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление идентификаторов.

void strSpectrLine::Zero(void)
{
AmpRel=Amp=Freq=0.0F;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура массива спектральных линий.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strSpLines::strSpLines(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

strSpLines::~strSpLines(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и параметров.

void strSpLines::Zero(void)
{
nSpL=0; pSpL=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strSpLines::Free(void)
{
SAFE_DELETE_ARR(pSpL); nSpL=0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание массива.

BYTE strSpLines::Create(BYTE nSpL_)
{
Free(); if(nSpL_==0) return 1; pSpL=new strSpectrLine[nSpL_]; if(pSpL==NULL) return 2; nSpL=nSpL_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strSpLines::IsOK(void)
{
if(nSpL==0) return 1; if(pSpL==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение указателя на структуру спектральной линии.

strSpectrLine *strSpLines::Get(BYTE num)
{
if(IsOK()!=0) return NULL; if(num>=nSpL) return NULL; return pSpL+num;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс двумерного массива спектральных линий.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

clSpLinesArr::clSpLinesArr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

clSpLinesArr::~clSpLinesArr(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и параметров.

void clSpLinesArr::Zero(void)
{
nArr=0; pArr=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clSpLinesArr::Free(void)
{
Clear(); SAFE_DELETE_ARR(pArr); nArr=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление структур массивов.

void clSpLinesArr::Clear(void)
{
UINT i;

if(IsOK()!=0) return; for(i=0;i<nArr;i++) SAFE_DELETE(pArr[i]);
}

//-----------------------------------------------------------------------------------------------------------
// Создание массива.

BYTE clSpLinesArr::Create(UINT nArr_)
{
BYTE ber; UINT i;

Free(); if(nArr_==0) return 1; pArr=new typPntSpLines[nArr_]; if(pArr==NULL) return 2; nArr=nArr_;
for(i=0;i<nArr;i++) pArr[i]=NULL; ber=0;
for(i=0;i<nArr;i++) { pArr[i]=new strSpLines; if(pArr[i]==NULL) { ber=4; goto end;}}
end: return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE clSpLinesArr::IsOK(void)
{
if(nArr==0) return 1; if(pArr==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение указателя на структуру массива спектральных линии.

strSpLines *clSpLinesArr::Get(UINT num)
{
if(IsOK()!=0) return NULL; if(num>=nArr) return NULL; return pArr[num];
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров нахождения спектральных линий гласных звуков и предварительного распознавания гласных и согласных звуков.

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
AmpThr=AmpThr_Stand; coeShPeaks=coeShPeaks_Stand;
ampSmPeaksMS=ampSmPeaksMS_Stand; ampSmPeaksAbs=ampSmPeaksAbs_Stand;
ampPeaksBad=ampPeaksBad_Stand; ampPeaksCorrFreq=ampPeaksCorrFreq_Stand;
FreqMin=FreqMinPeaks_Stand; FreqMax=FreqMax_Stand; FreqBaseMax=FreqBaseMax_Stand;
ErrFreq=ErrFreq_Stand; coeWidPeaks=coeWidPeaks_Stand;
coeRecPeaksSpectr=CoeRecPeaksSpectr_Stand;
coeRecPeaksVowel=CoeRecPeaksVowel_Stand;
coeRecPeaksCons=CoeRecPeaksCons_Stand;
LevPowPeak=LevPowPeak_Stand;
flCorrFreq=1; FreqDiscrCons=FreqDiscrCons_Stand;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParGetPeaks::IsOK(void)
{
float *fp;

if(ampSmPeaksMS<=0.0F) return 1;
if(FreqMin<=0.0F) return 2; if(FreqMax<=0.0F) return 3; if(FreqMin>=FreqMax) return 4;
if(ErrFreq<=0.0F) return 5; if(coeWidPeaks<=0.0F) return 6;
fp=&coeRecPeaksSpectr; if(*fp<CoeRecPeaks_Min) return 7; if(*fp>CoeRecPeaks_Max) return 8;
fp=&coeRecPeaksVowel; if(*fp>CoeRecPeaks_Max) return 9;
fp=&coeRecPeaksCons; if(*fp<CoeRecPeaks_Min) return 10; if(*fp>CoeRecPeaks_Max) return 11;
if(LevPowPeak<=0.0F) return 12; if(ampPeaksCorrFreq<=0.0F) return 13;
if(FreqDiscrCons<=0.0F) return 14; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки и коррекция.

UINT strParGetPeaks::Check(void)
{
UINT fl; float *fp,v;

fl=0;
fp=&AmpThr; if(*fp<0.0F) { *fp=0.0F; fl+=1<<0;}
fp=&ampSmPeaksMS; v=ampSmPeaksMS_Min; if(*fp<v) { *fp=v; fl+=1<<1;}
fp=&FreqMin;
v=FreqMinPeaks_Min; if(*fp<v) { FreqMin=v; fl+=1<<2;}
v=FreqMinPeaks_Max; if(*fp>v) { FreqMin=v; fl+=1<<3;}
fp=&FreqMax; if(*fp<=0.0F) { FreqMax=FreqMax_Stand; fl+=1<<4;}
if(FreqMin>=FreqMax) { FreqMin=FreqMinPeaks_Stand; FreqMax=FreqMax_Stand; fl+=1<<5;}
fp=&ErrFreq; if(*fp<=0.0F) { *fp=ErrFreq_Stand; fl+=1<<6;}
fp=&coeWidPeaks; if(*fp<=0.0F) { *fp=coeWidPeaks_Stand; fl+=1<<7;}
fp=&coeRecPeaksSpectr;
v=CoeRecPeaks_Min; if(*fp<v) { *fp=v; fl+=1<<8;}
v=CoeRecPeaks_Max; if(*fp>v) { *fp=v; fl+=1<<9;}
fp=&coeRecPeaksCons;
v=CoeRecPeaks_Min; if(*fp<v) { *fp=v; fl+=1<<10;}
v=CoeRecPeaks_Max; if(*fp>v) { *fp=v; fl+=1<<11;}
fp=&LevPowPeak; if(*fp<=0.0F) { *fp=LevPowPeak_Stand; fl+=1<<12;}
fp=&ampPeaksCorrFreq; if(*fp<=0.0F) { *fp=ampPeaksCorrFreq_Stand; fl+=1<<13;}
return fl;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParGetPeaks::Read_(FILE *file)
{
int iv;

if(file==NULL) return 1;
if(fscanf(file,"%f%f%f%f%f%f%f",&AmpThr,&ampSmPeaksMS,&FreqMin,&FreqMax,&ErrFreq,&coeWidPeaks,&coeRecPeaksSpectr)==EOF) return 2;
if(fscanf(file,"%f%d%f",&LevPowPeak,&iv,&ampPeaksCorrFreq)==EOF) return 3; if(iv==0) flCorrFreq=0; else flCorrFreq=1;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParGetPeaks::Read(char *Path,char *fName)
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

BYTE strParGetPeaks::Write_(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%f %f %f %f %f %f %f %f %d %f\n",AmpThr,ampSmPeaksMS,FreqMin,FreqMax,ErrFreq,coeWidPeaks,
coeRecPeaksSpectr,LevPowPeak,(int)flCorrFreq,ampPeaksCorrFreq)<0) return 2;
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
for(i=0;i<9;i++) {
switch(i) { default: continue;
case 0: fp=&AmpThr;            id=IDC_AMP_THRESHOLD;   Form=FormAmp; break;
case 1: fp=&ampSmPeaksMS;      id=IDC_COE_SMALL_PEAKS; Form=FormCoeff; break;
case 2: fp=&FreqMin;           id=IDC_FREQ_MIN;        Form=FormFreq; break;
case 3: fp=&FreqMax;           id=IDC_FREQ_MAX;        Form=FormFreq; break;
case 4: fp=&ErrFreq;           id=IDC_ERR_FREQ;        Form=FormCoeff; break;
case 5: fp=&coeWidPeaks;       id=IDC_WID_PEAKS;       Form=FormCoeff; break;
case 6: fp=&coeRecPeaksSpectr; id=IDC_COE_RECOGN_PEAK; Form=FormCoeff; break;
case 7: fp=&LevPowPeak;        id=IDC_LEV_POW_PEAKS;   Form=FormCoeff; break;
case 8: fp=&ampPeaksCorrFreq;  id=IDC_AMP_CORR_FREQ;   Form=FormCoeff; break;
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
for(i=0;i<9;i++) {
switch(i) { default: continue;
case 0: fp=&AmpThr;            id=IDC_AMP_THRESHOLD; break;
case 1: fp=&ampSmPeaksMS;      id=IDC_COE_SMALL_PEAKS; break;
case 2: fp=&FreqMin;           id=IDC_FREQ_MIN; break;
case 3: fp=&FreqMax;           id=IDC_FREQ_MAX; break;
case 4: fp=&ErrFreq;           id=IDC_ERR_FREQ; break;
case 5: fp=&coeWidPeaks;       id=IDC_WID_PEAKS; break;
case 6: fp=&coeRecPeaksSpectr; id=IDC_COE_RECOGN_PEAK; break;
case 7: fp=&LevPowPeak;        id=IDC_LEV_POW_PEAKS; break;
case 8: fp=&ampPeaksCorrFreq;  id=IDC_AMP_CORR_FREQ; break;
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

INT_PTR CALLBACK DlgParPeaks(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{
int id; struct strParGetPeaks *PGP;

if(msg!=WM_INITDIALOG) PGP=(strParGetPeaks *)GetWindowLong(hDlg,DWL_USER);

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetWindowLong(hDlg,DWL_USER,(long)lParam); PGP=(strParGetPeaks *)lParam;
if(PGP!=NULL) PGP->OnCreateDlg(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK .....................................................................................................
case IDOK: if(PGP!=NULL) PGP->GetDlg(hDlg); EndDialog(hDlg,1); return (INT_PTR)TRUE;

// IDCANCEL .................................................................................................
case IDCANCEL: EndDialog(hDlg,0); return (INT_PTR)TRUE;
}
break;
}

return (INT_PTR)FALSE;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров нахождения спектральных линий гласных звуков и предварительного распознавания гласных и согласных звуков.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strParInpSpectr::strParInpSpectr(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

void strParInpSpectr::Init(void)
{
AmpThr=AmpThr_Stand; FreqMin=FreqMin_Stand; FreqMax=FreqMax_Stand; FreqDiscrTri=FreqDiscrTri_Stand;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParInpSpectr::IsOK(void)
{
if(FreqMin<=0.0F) return 2; if(FreqMax<=0.0F) return 3; if(FreqMin>=FreqMax) return 4;
if(FreqDiscrTri<=0.0F) return 5; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура параметров тренировки сети.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

strParTrainNNW::strParTrainNNW(void)
{
Init();
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация.

void strParTrainNNW::Init(void)
{
methTrain=methTrain_GroupSearch;
flAdaptSt=0; flRandSampl=0; flEqualAdaptSt=0; Alpha=AlphaTrain_Stand; CoeAdaptStep=CoeAdaptStep_Stand;
AlphaMin=AlphaMinTrain_Stand;
AlphaMax=AlphaMaxTrain_Stand;
nStRand=nStRand_Stand; nStTrain=nStTrain_Stand; RandSeq=RandSeq_Stand;
coeWei=coeWei_Stand; coeTe=coeTe_Stand; coeVect=coeVect_Stand;
nStSeqLay=nStSeqLay_Stand;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strParTrainNNW::IsOK(void)
{
if(Alpha<=0.0F) return 1; if(nStTrain==0) return 2; if(coeWei<=0.0F) return 3; if(coeTe<=0.0F) return 4;
if(AlphaMin<0.0F) return 5; if(AlphaMax<=0.0F) return 6; if(AlphaMax<AlphaMin) return 7; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки и коррекция.

USHRT strParTrainNNW::Check(void)
{
USHRT fl; float *fp,v;

fl=0;
fp=&Alpha; if(*fp<=0.0F) { *fp=AlphaTrain_Stand; fl+=1<<0;}
fp=&AlphaMin; if(*fp<0.0F) { *fp=0.0F; fl+=1<<1;}
fp=&AlphaMax;
if(*fp<=0.0F) { *fp=AlphaMaxTrain_Stand; fl+=1<<2;}
if(*fp<AlphaMin) { *fp=AlphaMin; fl+=1<<3;}
if(*fp<=0.0F) { *fp=AlphaMaxTrain_Stand; fl+=1<<4;}

fp=&CoeAdaptStep; v=CoeAdaptStep_Min;
if(*fp<v) { *fp=v; fl+=1<<5;}
if(*fp>1.0F) { *fp=1.0F; fl+=1<<6;}

if(nStTrain==0) { nStTrain=nStTrain_Stand; fl+=1<<7;}
if(nStSeqLay==0) { nStSeqLay=nStSeqLay_Stand; fl+=1<<8;}

return fl;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParTrainNNW::Read_(FILE *file)
{
BYTE *bp; int iv;

if(file==NULL) return 1;
if(fscanf(file,"%d",&iv)==EOF) return 2; if(iv<0) iv=0; if(iv>USHRT_MAX) iv=USHRT_MAX; nStRand=(USHRT)iv;
if(fscanf(file,"%d",&iv)==EOF) return 3; if(iv<0) iv=0; if(iv>USHRT_MAX) iv=USHRT_MAX; nStTrain=(USHRT)iv;
if(fscanf(file,"%u",&RandSeq)==EOF) return 4;
if(fscanf(file,"%d",&iv)==EOF) return 5; if(iv>=nMethTrain) iv=0; methTrain=(BYTE)iv;
if(fscanf(file,"%d",&iv)==EOF) return 6; bp=&flAdaptSt; if(iv==0) *bp=0; else *bp=1;
if(fscanf(file,"%e",&Alpha)==EOF) return 7;
if(fscanf(file,"%e%e",&AlphaMin,&AlphaMax)==EOF) return 8;
if(fscanf(file,"%d",&iv)==EOF) return 9; bp=&flEqualAdaptSt; if(iv==0) *bp=0; else *bp=1;
if(fscanf(file,"%f",&CoeAdaptStep)==EOF) return 10;
if(fscanf(file,"%d",&iv)==EOF) return 11; bp=&flRandSampl; if(iv==0) *bp=0; else *bp=1;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE strParTrainNNW::Read(char *Path,char *fName)
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

BYTE strParTrainNNW::Write_(FILE *file)
{
if(file==NULL) return 1;
if(fprintf(file,"%d %d %u %d  %d %e %e %e %d %f %d\n",(int)nStRand,(int)nStTrain,RandSeq,(int)methTrain,
(int)flAdaptSt,Alpha,AlphaMin,AlphaMax,(int)flEqualAdaptSt,CoeAdaptStep,(int)flRandSampl)<0) return 2;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Сохранение в файле.

BYTE strParTrainNNW::Write(char *Path,char *fName)
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

void strParTrainNNW::SetDlg(HWND hDlg)
{
if(hDlg==NULL) return;
SetUSHRT_Edt(hDlg,IDC_NUM_STEPS_RAND,nStRand);
SetUSHRT_Edt(hDlg,IDC_NUM_STEPS_TRAIN,nStTrain);
SetUINT_Edt(hDlg,IDC_NUM_RAND_SEQ,RandSeq);
SetSizeCombo(hDlg,IDC_COMBO_METH,nMethTrain);
FillStrCombo(hDlg,IDC_COMBO_METH,IDSArrMethTrain,nMethTrain,methTrain);

SetChBox(hDlg,IDC_ADAPTIVE_STEP,flAdaptSt);
SetFlEdt(hDlg,IDC_STEP_TRAIN,Alpha,FormCoeff);
SetFlEdt(hDlg,IDC_ASTEP_MIN,AlphaMin,FormCoeff);
SetFlEdt(hDlg,IDC_ASTEP_MAX,AlphaMax,FormCoeff);
SetChBox(hDlg,IDC_EQUAL_ADAPT_STEP,flEqualAdaptSt);
SetFlEdt(hDlg,IDC_COE_ADAPT_STEP,CoeAdaptStep,FormCoeff);

SetChBox(hDlg,IDC_RAND_SAMPLES,flRandSampl);
}

//-----------------------------------------------------------------------------------------------------------
// Получение из диалогового окна.

BYTE strParTrainNNW::GetDlg(HWND hDlg)
{
if(hDlg==NULL) return 1;
GetUSHRT_Edt(hDlg,IDC_NUM_STEPS_RAND,&nStRand);
GetUSHRT_Edt(hDlg,IDC_NUM_STEPS_TRAIN,&nStTrain);
GetUINT_Edt(hDlg,IDC_NUM_RAND_SEQ,&RandSeq);
GetSelCombo(hDlg,IDC_COMBO_METH,&methTrain);

GetChBox(hDlg,IDC_ADAPTIVE_STEP,&flAdaptSt);
GetFlEdt(hDlg,IDC_STEP_TRAIN,&Alpha);
GetFlEdt(hDlg,IDC_ASTEP_MIN,&AlphaMin);
GetFlEdt(hDlg,IDC_ASTEP_MAX,&AlphaMax);
GetChBox(hDlg,IDC_EQUAL_ADAPT_STEP,&flEqualAdaptSt);
GetFlEdt(hDlg,IDC_COE_ADAPT_STEP,&CoeAdaptStep);

GetChBox(hDlg,IDC_RAND_SAMPLES,&flRandSampl);

Check(); // Проверки и коррекция.
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Действия при открытии диалогового окна.

void strParTrainNNW::OnCreateDlg(HWND hDlg)
{
SetPosWindowCenter(hDlg); // Помещение окна в центр другого окна или экрана.
SetDlg(hDlg); // Установка в диалоговое окно.
}

//-----------------------------------------------------------------------------------------------------------
// Функция диалогового окна настройки тренировки сети.

INT_PTR CALLBACK DlgParTrainNNW(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{
int id; struct strParTrainNNW *PTNNW; BYTE fl;

if(msg==WM_INITDIALOG) { SetWindowLong(hDlg,DWL_USER,(long)lParam); PTNNW=(strParTrainNNW *)lParam;}
else PTNNW=(strParTrainNNW *)GetWindowLong(hDlg,DWL_USER);

switch(msg) {

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: if(PTNNW!=NULL) PTNNW->SetDlg(hDlg); return (INT_PTR)TRUE;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: id=LOWORD(wParam);

switch(id) { default: break;

// IDOK IDCANCEL ............................................................................................
case IDOK: case IDCANCEL: if(id==IDOK) { fl=1; if(PTNNW!=NULL) PTNNW->GetDlg(hDlg);} else fl=0;
EndDialog(hDlg,(int)fl); return (INT_PTR)TRUE;
}
break;
}

return (INT_PTR)FALSE;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Функции для расчётов и тренировок методом искусственных нейронных сетей.

//-----------------------------------------------------------------------------------------------------------
// Создание структуры нейронной сети по структуре параметров.

BYTE CreateNNW(strNNW *pNNW,strParNNW *pParNNW,USHRT nNeurInp)
{
BYTE CopyPropNNW(strPropNNW *Dst,strPropNNW *Src); // Копирование структуры свойств и параметров нейронной сети.

BYTE i; USHRT n; struct strLay *pLay; struct strParLay *pPL;

if(pNNW==NULL) return 1; pNNW->FreeInit();
if(pParNNW==NULL) return 2; if(pParNNW->IsOK()!=0) return 3; if(nNeurInp==0) return 4;
if(CopyPropNNW(&pNNW->Par,&pParNNW->Par)!=0) return 5; pNNW->typ=pNNW->Par.flType;
if(pNNW->Alloc(pParNNW->nLay)!=0) return 6;
for(i=0;i<pParNNW->nLay;i++) { pPL=pParNNW->ParLay+i; pLay=pNNW->Get(i); if(pLay==NULL) return 7;
if(pLay->Alloc(pPL->nNeurons)!=0) return 8;
pLay->TypFunAct=pPL->TypFunAct; pLay->flTUse=pPL->flTUse; pLay->flSmart=pPL->flSmart;
if(pLay->SetFlagTShUse()!=0) return 9;
if(i==0) n=nNeurInp; else n=pParNNW->ParLay[i-1].nNeurons; if(pLay->AllocWeights(n)!=0) return 10;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение параметров из структуры нейронной сети.

BYTE GetParNNW(strNNW *pNNW,strParNNW *pParNNW)
{
BYTE CopyPropNNW(strPropNNW *Dst,strPropNNW *Src); // Копирование структуры свойств и параметров нейронной сети.

BYTE i; struct strParLay *pPL; struct strLay *pLay;

if(pNNW==NULL) return 1; if(pNNW->IsOK()!=0) return 2; if(pParNNW==NULL) return 3;
pParNNW->Free(); pParNNW->Par.Init();
if(CopyPropNNW(&pParNNW->Par,&pNNW->Par)!=0) return 4;
if(pParNNW->Alloc(pNNW->nLay)!=0) return 5;
for(i=0;i<pNNW->nLay;i++) { pPL=pParNNW->ParLay+i; pLay=pNNW->Get(i); if(pLay==NULL) return 6;
pPL->nNeurons=pLay->n; pPL->TypFunAct=pLay->TypFunAct; pPL->flTUse=pLay->flTUse; pPL->flSmart=pLay->flSmart;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение полного числа коэффициентов и смещений из структуры нейронной сети.

BYTE GetNumVectParNNW(strParNNW *pParNNW,USHRT nNeurInp,USHRT *nVect)
{
BYTE i; USHRT n,nP,nN; UINT nA,nV; struct strParLay *pPL;

if(pParNNW==NULL) return 1; if(pParNNW->IsOK_()!=0) return 2; if(nNeurInp==0) return 3; if(nVect==NULL) return 4;
n=0; for(i=0;i<pParNNW->nLay;i++) {
if(i==0) nP=nNeurInp; else { pPL=pParNNW->ParLay+i-1; nP=pPL->nNeurons;} if(nP==0) return 5;
pPL=pParNNW->ParLay+i; nN=pPL->nNeurons; nV=(UINT)nN; if(pPL->flSmart!=0) nV*=2; if(nV==0) return 6;
if((UINT)nP>UINT_MAX/nV) return 7; nA=(UINT)nP*nV;
if(pPL->flTUse!=0) { if(nA>UINT_MAX-(UINT)nN) return 8; nA+=(UINT)nN;}
if(nA>USHRT_MAX) return 9; if(n>USHRT_MAX-(USHRT)nA) return 10; n+=(USHRT)nA;}
*nVect=n; return 0;
}

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
// Расчёт адаптивного шага для слоя 'Lay'.

BYTE ComputeAdaptStep(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,USHRT nValNeurPrev,strLay *Lay,double *Alpha,double *pNumer,double *pDenom); // Расчёт адаптивного шага для последовательного метода тренировки.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

BYTE ber; USHRT i; float v; double Alpha,*Arr; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->Neurons->IsOK()!=0) return 2;
Arr=NULL; ber=0;
Arr=new double[LayPrev->n]; if(Arr==NULL) { ber=3; goto end;}
for(i=0;i<LayPrev->n;i++) { pNeur=LayPrev->Neurons+i; Arr[i]=pNeur->Val;}
if(ComputeAdaptStep_(Arr,LayPrev->n,Lay,&Alpha,&Lay->Numer,&Lay->Denom)!=0) { ber=4; goto end;}
v=coeAlpha; if(v>0.0F&&v<1.0F) Alpha*=(double)v; Lay->Alpha=Alpha; // Замедляющий множитель для адаптивного шага.
if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) { ber=5; goto end;} // Корректировка адаптивного шага.
end: SAFE_DELETE_ARR(Arr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для первого скрытого слоя 'Lay'.

BYTE ComputeAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha)
{
BYTE ComputeAdaptStep_(double *ValNeurPrev,USHRT nValNeurPrev,strLay *Lay,double *Alpha,double *pNumer,double *pDenom); // Расчёт адаптивного шага для последовательного метода тренировки.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

BYTE ber; USHRT i; float v; double Alpha,*Arr;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
Arr=NULL; ber=0;
Arr=new double[LayPrev->n]; if(Arr==NULL) { ber=3; goto end;}
for(i=0;i<LayPrev->n;i++) Arr[i]=LayPrev->Values[i];
if(ComputeAdaptStep_(Arr,LayPrev->n,Lay,&Alpha,&Lay->Numer,&Lay->Denom)!=0) { ber=4; goto end;}
v=coeAlpha; if(v>0.0F&&v<1.0F) Alpha*=(double)v; Lay->Alpha=Alpha; // Замедляющий множитель для адаптивного шага.
if(CorrectAdaptStep(&Lay->Alpha,AlphaMin,AlphaMax)!=0) { ber=5; goto end;} // Корректировка адаптивного шага.
end: SAFE_DELETE_ARR(Arr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для последовательного метода тренировки.

BYTE ComputeAdaptStep_(double *ValNeurPrev,USHRT nValNeurPrev,strLay *Lay,double *pAlpha,
double *pNumer,double *pDenom)
{
BYTE GetCoeDeriv(BYTE typ,double *coe); // Получение коэффициента для нахождения производной в центре интервала.

USHRT i,j; double fN,fD,f,s,sum,sPrev,Gam,Alf,coe,v; pFunDerAct FunDerAct; struct strNeuron *pNeur;

if(ValNeurPrev==NULL) return 1; if(nValNeurPrev==0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4; if(pAlpha==NULL) return 5;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 6;
if(GetCoeDeriv(Lay->TypFunAct,&coe)!=0) return 7;
s=0.; for(i=0;i<nValNeurPrev;i++) { v=ValNeurPrev[i]; s+=v*v;} sPrev=1.+s;
fN=fD=0.;
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; f=FunDerAct(pNeur->Val); Gam=pNeur->Err;
if(pNeur->flSmart==0) sum=sPrev;
else { sum=1.;
s=0.; for(i=0;i<nValNeurPrev;i++) { v=ValNeurPrev[i]-pNeur->Shifts[i]; s+=v*v;} sum+=s;
s=0.; for(i=0;i<nValNeurPrev;i++) { v=pNeur->Weights[i]; s+=v*v;} sum+=s;}
Alf=sum*Gam*f; fN+=Gam*Alf; fD+=Alf*Alf;}
if(fD<=0.) return 7; *pAlpha=coe*fN/fD;
if(pNumer!=NULL) *pNumer=fN; if(pDenom!=NULL) *pDenom=fD; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Корректировка адаптивного шага.

BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax)
{
BYTE CorrectAdaptStepSimple(double *pAlpha,float AlphaMin,float AlphaMax); // Простая корректировка адаптивного шага.
BYTE CorrectAdaptStepSmooth(double *pAlpha,float AlphaMin,float AlphaMax); // Гладкая корректировка адаптивного шага.

#if flCorrAdaptStep==0 // Тип корректировки адаптивного шага (0 - простой, 1 - со сглаживанием).
return CorrectAdaptStepSimple(pAlpha,AlphaMin,AlphaMax); // Простая корректировка адаптивного шага.
#else
return CorrectAdaptStepSmooth(pAlpha,AlphaMin,AlphaMax); // Гладкая корректировка адаптивного шага.
#endif
}

//-----------------------------------------------------------------------------------------------------------
// Простая корректировка адаптивного шага.

BYTE CorrectAdaptStepSimple(double *pAlpha,float AlphaMin,float AlphaMax)
{
double A;

if(pAlpha==NULL) return 1; if(AlphaMin<0.0F) return 2; if(AlphaMax<=0.0F) return 3; if(AlphaMax<AlphaMin) return 4;
A=*pAlpha; A=MIN(A,(double)AlphaMax); A=MAX(A,(double)AlphaMin); *pAlpha=A; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Гладкая корректировка адаптивного шага.

BYTE CorrectAdaptStepSmooth(double *pAlpha,float AlphaMin,float AlphaMax)
{
double A,a;

if(pAlpha==NULL) return 1; if(AlphaMin<0.0F) return 2; if(AlphaMax<=0.0F) return 3; if(AlphaMax<AlphaMin) return 4;
A=*pAlpha;
a=(double)AlphaMax; if(A>a) { if(A>LrgCnst32_d) A=a*2.; else A*=2./(1.+A/a);}
a=(double)AlphaMin; if(A<a) { if(A<SmCnst32_d) A=a*0.5; else A*=(1.+a/A)*0.5;}
*pAlpha=A; return 0;
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
case TypFunAct_Sigm:   FunAct=FunAct_Sigm; break;      //Сигмоидная функция.
case TypFunAct_BiSigm: FunAct=FunAct_BiSigm; break;   // Биполярная cигмоидная функция.
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

//-----------------------------------------------------------------------------------------------------------
// Функция выбора производной функции активации нейронных элементов.

pFunDerAct GetFunDerAct(BYTE Typ)
{
double FunDerAct_Sigm(double y); // Производная функции активации нейроннных элементов. Сигмоидная функция.
double FunDerAct_BiSigm(double y); // Производная функции активации нейроннных элементов. Биполярная cигмоидная функция.
double FunDerAct_HypTang(double y); // Производная функции активации нейроннных элементов. Гиперболический тангенс.
double FunDerAct_Log(double y); // Производная функции активации нейроннных элементов. Логарифмическая.
double FunDerAct_Lin(double y); // Производная функции активации нейроннных элементов. Линейная.

pFunDerAct FunDerAct;

switch(Typ) { default: FunDerAct=NULL; break;
case TypFunAct_Sigm:   FunDerAct=FunDerAct_Sigm; break;      //Сигмоидная функция.
case TypFunAct_BiSigm: FunDerAct=FunDerAct_BiSigm; break;   // Биполярная cигмоидная функция.
case TypFunAct_HypTan: FunDerAct=FunDerAct_HypTang; break; // Гиперболический тангенс.
case TypFunAct_Log:    FunDerAct=FunDerAct_Log; break; // Логарифмическая.
case TypFunAct_Lin:    FunDerAct=FunDerAct_Lin; break; // Линейная.
}
return FunDerAct;
}

//-----------------------------------------------------------------------------------------------------------
// Производная функции активации нейроннных элементов. Сигмоидная функция.

double FunDerAct_Sigm(double y)
{
return y*(1.-y);
}

//-----------------------------------------------------------------------------------------------------------
// Производная функции активации нейроннных элементов. Биполярная cигмоидная функция.

double FunDerAct_BiSigm(double y)
{
return 0.5*(1.-y*y);
}

//-----------------------------------------------------------------------------------------------------------
// Производная функции активации нейроннных элементов. Гиперболический тангенс.

double FunDerAct_HypTang(double y)
{
return 1.-y*y;
}

//-----------------------------------------------------------------------------------------------------------
// Производная функции активации нейроннных элементов. Логарифмическая.

double FunDerAct_Log(double y)
{
double aM,v;

aM=IPE_MAX; if(y>=-aM&&y<=aM) { v=exp(y); v=2.*v/(1.+v*v);} else v=0.; return v;
}

//-----------------------------------------------------------------------------------------------------------
// Производная функции активации нейроннных элементов. Линейная.

double FunDerAct_Lin(double y)
{
return 1.;
}

//-----------------------------------------------------------------------------------------------------------
// Получение коэффициента для нахождения производной в центре интервала.

BYTE GetCoeDeriv(BYTE typ,double *coe)
{
if(coe==NULL) return 1;
switch(typ) { default: *coe=1.; break;
case TypFunAct_Sigm: *coe=4.; break; // Сигмоидная функция.
case TypFunAct_BiSigm: *coe=2.; break; // Сигмоидная биполярная функция.
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка ошибок для выходного слоя нейронной сети.

BYTE SetErrOutLay(strInpLay *True,strLay *Lay)
{
USHRT i; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
if(True==NULL) return 3; if(True->IsOK()!=0) return 4; if(Lay->n!=True->n) return 5;
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; pNeur->Err=pNeur->Val-True->Values[i];} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт ошибок методом обратного распространения ошибки.

BYTE ComputeErr(strLay *LayPrev,strLay *Lay)
{
USHRT i,j; double Sum,f; pFunDerAct FunDerAct; struct strNeuron *pNeur,*pNeurPr;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;

// Цикл по "j" - перебираем нейроны предыдущего слоя, где ищем ошибку.
for(j=0;j<LayPrev->n;j++) { pNeurPr=LayPrev->Neurons+j;
// Цикл по "i" - перебираем все нейроны слоя "Lay", по которому идёт суммирование.
Sum=0.; for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur->nWeights!=LayPrev->n) return 6;
f=FunDerAct(pNeur->Val); Sum+=pNeur->Err*f*pNeur->Weights[j];}
pNeurPr->Err=Sum;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки.

BYTE CorrectWeights(strLay *LayPrev,strLay *Lay,double Alpha)
{
USHRT i,j; double f,v,*pw,*ps; pFunDerAct FunDerAct; struct strNeuron *pNeur,*pNeurPr;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
if(Alpha<=0.) return 0;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;

// Цикл по "j" - перебираем все нейроны второго слоя "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK()!=0) return 6;
if(pNeur->nWeights!=LayPrev->n) return 7;
f=FunDerAct(pNeur->Val); v=pNeur->Err*f*Alpha;
if(pNeur->flTUse!=0) pNeur->T+=v; // Корректировка порогов.

// Цикл по "i" - перебираем нейроны предыдущего слоя "LayPrev".
// Корректировка весов.
if(pNeur->flSmart==0) for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i; pNeur->Weights[i]-=pNeurPr->Val*v;}
else
// Корректировка весов и смещений.
for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i; pw=pNeur->Weights+i; ps=pNeur->Shifts+i;
*pw-=(pNeurPr->Val-*ps)*v; *ps+=*pw*v;}
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Корректировка весовых коэффициентов и порогов методом обратного распространения ошибки для первого скрытого слоя.

BYTE CorrectWeightsFirst(strInpLay *LayPrev,strLay *Lay,double Alpha)
{
USHRT i,j,nWei; double f,v,*pw,*ps; pFunDerAct FunDerAct; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
if(Alpha<=0.) return 0;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;

// Цикл по "j" - перебираем все нейроны второго слоя "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK()!=0) return 6;
nWei=MIN(pNeur->nWeights,LayPrev->n);
f=FunDerAct(pNeur->Val); v=pNeur->Err*f*Alpha;
if(pNeur->flTUse!=0) pNeur->T+=v; // Корректировка порогов.

// Цикл по "i" - перебираем нейроны предыдущего слоя "LayPrev".
// Корректировка весов.
if(pNeur->flSmart==0) for(i=0;i<nWei;i++) pNeur->Weights[i]-=LayPrev->Values[i]*v;
else
// Корректировка весов и смещений.
for(i=0;i<nWei;i++) { pw=pNeur->Weights+i; ps=pNeur->Shifts+i;
*pw-=(LayPrev->Values[i]-*ps)*v; *ps+=*pw*v;}
}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Приращение массива векторов для нейронов слоя при групповом обучении.

BYTE AddVectors(strLay *LayPrev,strLay *Lay,double Wei)
{
USHRT i,j; double f,v; pFunDerAct FunDerAct; struct strNeuron *pNeur,*pNeurPr;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;

// Цикл по "j" - перебираем все нейроны второго слоя "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK_Vect()!=0) return 6;
if(pNeur->Vect.nWeights!=LayPrev->n) return 7;
f=FunDerAct(pNeur->Val); v=pNeur->Err*f*Wei;
if(pNeur->flTUse!=0) pNeur->Vect.T+=v; // Приращение компоненты вектора для порога.

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

BYTE AddVectorsFirst(strInpLay *LayPrev,strLay *Lay,double Wei)
{
USHRT i,j; double f,v,*pw,*ps; pFunDerAct FunDerAct; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
FunDerAct=GetFunDerAct(Lay->TypFunAct); if(FunDerAct==NULL) return 5;

// Цикл по "j" - перебираем все нейроны второго слоя "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK_Vect()!=0) return 6;
if(pNeur->Vect.nWeights!=LayPrev->n) return 7;
f=FunDerAct(pNeur->Val); v=pNeur->Err*f*Wei;
if(pNeur->flTUse!=0) pNeur->Vect.T+=v; // Приращение компоненты вектора для порога.

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

//-----------------------------------------------------------------------------------------------------------
// Суммирование в переменные для нахождения адаптивного шага при групповом обучении.

BYTE AddAdaptStep(strLay *LayPrev,strLay *Lay,double Wei)
{
USHRT i,j; double alp,sW,sS,Num,Den,w; struct strNeuron *pNeur,*pNeurPr;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;

Num=Den=0.;
// Цикл по "j" - перебираем все нейроны второго слоя "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK_Vect()!=0) return 5;
if(pNeur->Vect.nWeights!=LayPrev->n) return 7;

sW=sS=0.;
// Цикл по "i" - перебираем нейроны предыдущего слоя "LayPrev".
if(pNeur->flSmart==0)
// Суммирование в массив векторов для весов.
for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i; sW-=pNeurPr->Val*pNeur->Vect.Weights[i];}
else
// Суммирование в массивы векторов для весов и смещений.
for(i=0;i<LayPrev->n;i++) { pNeurPr=LayPrev->Neurons+i; w=pNeur->Vect.Weights[i];
sW-=w*(pNeurPr->Val-pNeur->Shifts[i]);
sS+=w*pNeur->Vect.Shifts[i];
}
alp=sS; if(pNeur->flSmart!=0) alp+=sS; if(pNeur->flTUse!=0) alp+=pNeur->Vect.T;
Num+=alp*pNeur->Err; Den+=alp*alp;
}
Lay->Numer+=Num*Wei; Lay->Denom+=Den*Wei; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Суммирование в переменные для нахождения адаптивного шага при групповом обучении.

BYTE AddAdaptStepFirst(strInpLay *LayPrev,strLay *Lay,double Wei)
{
USHRT i,j; double alp,sW,sS,Num,Den,w; struct strNeuron *pNeur;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;

Num=Den=0.;
// Цикл по "j" - перебираем все нейроны второго слоя "Lay".
for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->IsOK_Vect()!=0) return 5;
if(pNeur->Vect.nWeights!=LayPrev->n) return 7;

sW=sS=0.;
// Цикл по "i" - перебираем нейроны предыдущего слоя "LayPrev".
if(pNeur->flSmart==0)
// Суммирование в массив векторов для весов.
for(i=0;i<LayPrev->n;i++) { sW-=LayPrev->Values[i]*pNeur->Vect.Weights[i];}
else
// Суммирование в массивы векторов для весов и смещений.
for(i=0;i<LayPrev->n;i++) { w=pNeur->Vect.Weights[i];
sW-=w*(LayPrev->Values[i]-pNeur->Shifts[i]);
sS+=w*pNeur->Vect.Shifts[i];
}
alp=sS; if(pNeur->flSmart!=0) alp+=sS; if(pNeur->flTUse!=0) alp+=pNeur->Vect.T;
Num+=alp*pNeur->Err; Den+=alp*alp;
}
Lay->Numer+=Num*Wei; Lay->Denom+=Den*Wei; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение ошибки выходного слоя нейронов.

BYTE FindErrOutLay(strInpLay *True,strLay *Lay,double *pErr)
{
USHRT i; double v,sum; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
if(True==NULL) return 3; if(True->IsOK()!=0) return 4;
if(Lay->n!=True->n) return 5; if(pErr==NULL) return 6;
sum=0.; for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; v=pNeur->Val-True->Values[i]; sum+=v*v;}
*pErr=sum/(double)Lay->n; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа нейронов первого распределительного слоя.

BYTE GetNumInput(strNNW *pNNW,USHRT *nInp)
{
USHRT i,nW,n; struct strLay *pLay; struct strNeuron *pNeur;

if(pNNW==NULL) return 1; if(nInp==NULL) return 2;
pLay=pNNW->Get(0); if(pLay==NULL) return 3; if(pLay->IsOK()!=0) return 4;
n=0; for(i=0;i<pLay->n;i++) { pNeur=pLay->Neurons+i; nW=pNeur->nWeights; if(i==0) n=nW; else if(n!=nW) return 5;}
*nInp=n; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Коррекция значений нейронов скрытого слоя.

BYTE CorrectY(UINT numSample,strLay *Lay,double Alpha)
{
USHRT i; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur->Etal.IsOK()!=0) return 3;
if(numSample>=pNeur->Etal.nVal) return 4; pNeur->Etal.pVal[numSample]-=pNeur->Err*Alpha;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка эталонных значений для выходного слоя нейронной сети.

BYTE SetValEtalOutLay(UINT numSample,strInpLay *True,strLay *Lay)
{
USHRT i; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
if(True==NULL) return 3; if(True->IsOK()!=0) return 4; if(Lay->n!=True->n) return 5;
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur->Etal.IsOK()!=0) return 6;
if(numSample>=pNeur->Etal.nVal) return 7; pNeur->Etal.pVal[numSample]=True->Values[i];}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка ошибок относительно эталонных значений для слоя нейронной сети.

BYTE SetErrLayEtal(UINT numSample,strLay *Lay)
{
USHRT i; struct strNeuron *pNeur;

if(Lay==NULL) return 1; if(Lay->IsOK()!=0) return 2;
for(i=0;i<Lay->n;i++) { pNeur=Lay->Neurons+i; if(pNeur->Etal.IsOK()!=0) return 3;
if(numSample>=pNeur->Etal.nVal) return 4; pNeur->Err=pNeur->Val-pNeur->Etal.pVal[numSample];}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт адаптивного шага для расчёта эталонных значений слоя.

BYTE ComputeAdaptStepY(strLay *LayPrev,strLay *Lay,float AlphaMin,float AlphaMax,float coeAlpha,double *pAlpha)
{
BYTE GetCoeDeriv(BYTE typ,double *coe); // Получение коэффициента для нахождения производной в центре интервала.
BYTE CorrectAdaptStep(double *pAlpha,float AlphaMin,float AlphaMax); // Корректировка адаптивного шага.

USHRT i,j; float v; double s,sumN,sumD,coe; struct strNeuron *pNeur,*pNeurP;

if(LayPrev==NULL) return 1; if(LayPrev->IsOK()!=0) return 2;
if(Lay==NULL) return 3; if(Lay->IsOK()!=0) return 4;
if(pAlpha==NULL) return 5;
if(GetCoeDeriv(Lay->TypFunAct,&coe)!=0) return 6;

sumN=sumD=0.; for(j=0;j<Lay->n;j++) { pNeur=Lay->Neurons+j; if(pNeur->nWeights!=LayPrev->n) return 7;
s=0.; for(i=0;i<LayPrev->n;i++) { pNeurP=LayPrev->Neurons+i; s+=pNeurP->Err*pNeur->Weights[i];}
sumN+=s*pNeur->Err; sumD+=s*s;}
if(sumD<=0.) return 8; *pAlpha=sumN/sumD*coe;
v=coeAlpha; if(v>0.0F&&v<1.0F) *pAlpha*=(double)v; // Замедляющий множитель для адаптивного шага.
if(CorrectAdaptStep(pAlpha,AlphaMin,AlphaMax)!=0) return 9; // Корректировка адаптивного шага.
return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Функции для формирования входных векторов и распознавания.

//-----------------------------------------------------------------------------------------------------------
// Распознавание звуков методом нейронных сетей.

BYTE RecognSoundNNW_VC(float *Spectr,USHRT nSpectr,float dFr,strNNW *NNW_Vowel,strNNW *NNW_Cons,
pFunDecSnd DecSnd,PNT_DATA Pnt,BYTE *numSnd,BYTE *typSnd,BYTE flOut)
{
BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nPCons,BYTE nSpLines,strSpectrLine *SpLines,
  strParGetPeaks *PGP,BYTE *typNet,BYTE *flErr); // Нахождение относительных амплитуд и частот спектральных линий.
BYTE InputDataNetVC(BYTE typInp,BYTE typNet,float FreqMin,float FreqMax,float dFr,float dFrTri,float AmpThr,
  BYTE nPCons,float *Spectr,USHRT nSpectr,strSpectrLine *pSpL,BYTE nSpL,strInpLay *InpLay); // Нахождение входных данных для нейронной сети.

BYTE num,typNet,typ,err,nPeaks,be,ber; float FreqMin,FreqMax,dFrTri,AmpThr;
struct strInpLay InpLay; struct strLay *pLay; struct strSpectrLine *pSpL;
struct strNNW *pNNW,*pNNW_V,*pNNW_C;

if(Spectr==NULL) return 1; if(nSpectr==0) return 2; if(dFr<=0.0F) return 3;
pNNW_V=NNW_Vowel; if(pNNW_V!=NULL) { if(pNNW_V->IsOK()!=0||pNNW_V->flOK==0) pNNW_V=NULL;}
pNNW_C=NNW_Cons; if(pNNW_C!=NULL) if(pNNW_C->IsOK()!=0||pNNW_C->flOK==0) pNNW_C=NULL;
if(pNNW_V==NULL&&pNNW_C==NULL) return 4; if(DecSnd==NULL) return 5;
if(numSnd==NULL) return 6; if(typSnd==NULL) return 7;
nPeaks=nPeaksMax;

if(pNNW_C!=NULL) {
if(pNNW_C->Par.nPCons!=nPeaksCons) return 8;
if(pNNW_C->Par.dFrTri!=ParGetPeaks.FreqDiscrCons) return 9;
}

pSpL=NULL; ber=0;
pSpL=new strSpectrLine[nPeaks]; if(pSpL==NULL) { ber=10; goto end;}

// Нахождение спектральных линий.
typNet=UCHAR_MAX;
be=FindPeaks(nSpectr,Spectr,dFr,nPeaksCons,nPeaks,pSpL,&ParGetPeaks,&typNet,&err);
if(flOut!=0&&err!=0) { Message(IDS_ErrParFindPeaks,MB_ST);
sprintf(TxtStr,"Error: %d",err); MessageBox(NULL,TxtStr,"",MB_EX);}
if(be!=0||typNet>=nTypesNNW) { err=1; goto eNNW;}

// Распознавание методом нейронных сетей.
err=0; if(typNet>=nTypesNNW) { err=2; goto eNNW;}
if(typNet==typNNW_Vowel) pNNW=pNNW_V; else pNNW=pNNW_C; if(pNNW==NULL) { err=3; goto eNNW;}
if(typNet!=pNNW->typ) { err=4; goto eNNW;} if(pNNW->flOK==0) { err=5; goto eNNW;}

// Ввод данных в нейронную сеть.
FreqMin=pNNW->Par.FreqMin;
FreqMax=pNNW->Par.FreqMax;
dFrTri=pNNW->Par.dFrTri;
AmpThr=ParInpSp.AmpThr;
if(InputDataNetVC(pNNW->Par.flTypInpData,pNNW->typ,FreqMin,FreqMax,dFr,dFrTri,AmpThr,pNNW->Par.nPCons,
Spectr,nSpectr,pSpL,nPeaks,&InpLay)!=0) { err=6; goto eNNW;}

// Распознавание методом нейронных сетей.
if(pNNW->Compute(&InpLay)!=0) { err=7; goto eNNW;}
pLay=pNNW->GetOutLay(); if(pLay==NULL) { err=8; goto eNNW;} if(pLay->IsOK()!=0) { err=9; goto eNNW;}
if((*DecSnd)(Pnt,pLay,pNNW->typ,&typ,&num)!=0) { err=10; goto eNNW;}
eNNW: if(err!=0) { *numSnd=*typSnd=UCHAR_MAX;} else { *numSnd=num; *typSnd=typ;}

end: InpLay.Free(); SAFE_DELETE_ARR(pSpL); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Получение числа входных нейронов сети.

BYTE GetNInpDataNetVC(BYTE typInp,BYTE typNet,float FreqMax,float dFr,float dFrTri,BYTE nPCons,USHRT *nInp)
{
USHRT nFrTri;

if(nInp==NULL) return 1;
if(typInp==typDataNNW_SpectrTri||typInp==typDataNNW_SpectrTriEnv||typInp==typDataNNW_Peaks&&typNet==typNNW_Cons) {
if(dFrTri<=0.0F) return 2; if(FreqMax<=0.0F) return 3;
nFrTri=GetUSHRT_Test(FreqMax/dFrTri); if(nFrTri==0) return 4;}

switch(typInp) { default: return 5;
// По спектральным линиям.
case typDataNNW_Peaks: if(typNet==typNNW_Vowel) *nInp=nPeaksMax;
else { if(nFrTri>USHRT_MAX-(USHRT)nPCons) return 6; *nInp=nFrTri+(USHRT)nPCons; *nInp=MIN(*nInp,nPeaksMax);} break;
// По спектру с разложением по треугольным функциям или с разложением огибающей по треугольным функциям.
case typDataNNW_SpectrTri: case typDataNNW_SpectrTriEnv: *nInp=nFrTri; break;
// Непосредственно спектр.
case typDataNNW_SpectrRow: if(dFr<=0.0F) return 7; if(FreqMax<=0.0F) return 8;
*nInp=GetUSHRT_Test(FreqMax/dFr); break;
}
if(*nInp==0) return messRet; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение входных данных для нейронной сети.

BYTE InputDataNetVC(BYTE typInp,BYTE typNet,float FreqMin,float FreqMax,float dFr,float dFrTri,float AmpThr,
BYTE nPCons,float *Spectr,USHRT nSpectr,strSpectrLine *pSpL,BYTE nSpL,strInpLay *InpLay)
{
BYTE ResTriFun(USHRT nSpectr,float *Spectr,float dFr,float DiscrTri,float FreqMin,float FreqMax,float AmpThr,
  strInpLay *InpLay); // Разложение спектра по треугольным функциям.
BYTE GetEnvelope(USHRT nSpectr,float *pSpEnv,BYTE nPeaks,strSpectrLine *pSpL,float Del); // Получение огибающей спектра по спектральным линиям.
BYTE InpSpectrRow(USHRT nSpectr,float *Spectr,float dFr,float FreqMin,float FreqMax,float AmpThr,
  strInpLay *InpLay); // Подстановка непосредственно спектра.

BYTE be,err; USHRT nInp,nFrMax,nFrTri,j; float *pSpEnv,v;

if(InpLay==NULL) return 1; if(typNet==typNNW_Spectr) return 2;
if(FreqMin<=0.0F) return 3; if(FreqMax<=0.0F) return 4; if(FreqMin>=FreqMax) return 5;
if(typInp!=typDataNNW_Peaks) { if(Spectr==NULL) return 6; if(nSpectr==0) return 7; if(dFr<=0.0F) return 8;}
if(typInp==typDataNNW_Peaks||typInp==typDataNNW_SpectrTriEnv) { if(pSpL==NULL) return 9; if(nSpL==0) return 10;}

if(typInp==typDataNNW_SpectrTri||typInp==typDataNNW_SpectrTriEnv||typInp==typDataNNW_Peaks&&typNet==typNNW_Cons) {
if(dFrTri<=0.0F) return 11; nFrTri=GetUSHRT_Test(FreqMax/dFrTri); if(nFrTri==0) return 9;}

pSpEnv=NULL; err=0;

switch(typInp) { default: err=13; goto end;
// По спектральным линиям.
case typDataNNW_Peaks:
if(typNet==typNNW_Vowel) nInp=nPeaksMax;
else { if(nFrTri>USHRT_MAX-(USHRT)nPCons) { err=14; goto end;} nInp=nFrTri+(USHRT)nPCons;}
nInp=MIN(nInp,nSpL);
if(InpLay->Alloc(nInp)!=0) { err=15; goto end;}
for(j=0;j<nInp;j++) InpLay->Values[j]=(double)pSpL[j].AmpRel; // Задание входного массива.
break;

// По спектру с разложением по треугольным функциям.
case typDataNNW_SpectrTri:
nInp=nFrTri; if(InpLay->Alloc(nInp)!=0) { err=16; goto end;}
be=ResTriFun(nSpectr,Spectr,dFr,dFrTri,FreqMin,FreqMax,AmpThr,InpLay); // Разложение спектра по треугольным функциям.
if(be!=messRet&&be!=0) { err=17; goto end;} if(be==messRet) { err=messRet; goto end;}
break;

// По спектру с разложением огибающей по треугольным функциям.
case typDataNNW_SpectrTriEnv: if(typNet==typNNW_Cons) { err=18; goto end;}
nInp=nFrTri; if(InpLay->Alloc(nInp)!=0) { err=19; goto end;}
pSpEnv=new float[nSpectr]; if(pSpEnv==NULL) { err=20; goto end;}
v=dFrTri/dFr;
if(GetEnvelope(nSpectr,pSpEnv,nSpL,pSpL,v)!=0) { err=21; goto end;}
be=ResTriFun(nSpectr,pSpEnv,dFr,dFrTri,FreqMin,FreqMax,AmpThr,InpLay); // Разложение спектра по треугольным функциям.
if(be!=messRet&&be!=0) { err=22; goto end;} if(be==messRet) { err=messRet; goto end;}
break;

// Непосредственно спектр.
case typDataNNW_SpectrRow:
nFrMax=GetUSHRT_Test(FreqMax/dFr); if(nFrMax==0) { err=23; goto end;}
nFrMax=MIN(nFrMax,nSpectr);
nInp=nFrMax; if(InpLay->Alloc(nInp)!=0) { err=24; goto end;}
be=InpSpectrRow(nSpectr,Spectr,dFr,FreqMin,FreqMax,AmpThr,InpLay);
if(be!=messRet&&be!=0) { err=25; goto end;} if(be==messRet) { err=messRet; goto end;}
break;
}

end: SAFE_DELETE_ARR(pSpEnv); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Распознавание звуков методом нейронных сетей.

BYTE RecognSoundNNW_Sp(float *Spectr,USHRT nSpectr,float dFr,strNNW *pNNW,pFunDecSnd DecSnd,PNT_DATA Pnt,
BYTE *numSnd,BYTE *typSnd)
{
BYTE InputDataNetSp(float FreqMin,float FreqMax,float dFr,float AmpThr,float *Spectr,USHRT nSpectr,strInpLay *InpLay); // Нахождение входных данных для нейронной сети.

BYTE num,typ,err; float FreqMin,FreqMax,AmpThr; struct strInpLay InpLay; struct strLay *pLay;

if(Spectr==NULL) return 1; if(nSpectr==0) return 2; if(dFr<=0.0F) return 3;
if(pNNW==NULL) return 4; if(pNNW->typ!=typNNW_Spectr) return 5;
if(pNNW->IsOK()!=0) return 6; if(pNNW->flOK==0) return 7;
if(DecSnd==NULL) return 8; if(numSnd==NULL) return 9; if(typSnd==NULL) return 10;
if(dFr!=pNNW->Par.dFr) return 11;
err=0;

// Ввод данных в нейронную сеть.
FreqMin=pNNW->Par.FreqMin;
FreqMax=pNNW->Par.FreqMax;
AmpThr=ParInpSp.AmpThr;
if(InputDataNetSp(FreqMin,FreqMax,dFr,AmpThr,Spectr,nSpectr,&InpLay)!=0) { err=1; goto eNNW;}

// Распознавание методом нейронных сетей.
if(pNNW->Compute(&InpLay)!=0) { err=2; goto eNNW;}
pLay=pNNW->GetOutLay(); if(pLay==NULL) { err=3; goto eNNW;} if(pLay->IsOK()!=0) { err=4; goto eNNW;}
if((*DecSnd)(Pnt,pLay,typNNW_Spectr,&typ,&num)!=0) { err=5; goto eNNW;}
eNNW: if(err!=0) { *numSnd=*typSnd=UCHAR_MAX;} else { *numSnd=num; *typSnd=typ;}

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
// Функция принятия решения при распознавании звука - простейший пороговый классификатор, основанный на текущих значениях.

BYTE DecSnd_Instant(PNT_DATA Pnt,strLay *pLay,BYTE typNet,BYTE *typSnd,BYTE *numSnd)
{
BYTE GetNumSound(strLay *pLay,float Err,BYTE *numSnd); // Нахождение номера звука, которому соответствует максимальное значение в выходном массиве нейронов.

BYTE num;

if(pLay==NULL) return 1; if(typSnd==NULL) return 2; if(numSnd==NULL) return 3;
switch(typNet) { default: return 4;
case typNNW_Vowel: break; // Гласные и сонорные звуки.
case typNNW_Cons: break; // Согласные импульсные и шипящие звуки.
case typNNW_Spectr: break; // Применение нейронных сетей сразу для всего спектра.
}
if(GetNumSound(pLay,errSoundResNNW,&num)!=0) return 5;

switch(typNet) {
// Гласные и сонорные звуки.
case typNNW_Vowel:
// Согласные импульсные и шипящие звуки.
case typNNW_Cons:
*typSnd=typNet; *numSnd=num; break;

// Применение нейронных сетей сразу для всего спектра.
case typNNW_Spectr:
if(num<nVoicesVowel) { *typSnd=typNNW_Vowel; *numSnd=num;}
else { num-=nVoicesVowel; if(num>=nVoicesCons) return 6; *typSnd=typNNW_Cons; *numSnd=num;}
break;
}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение относительных амплитуд и частот спектральных линий.

BYTE FindPeaks(USHRT nSpectr,float *Spectr,float dFr,BYTE nPCons,BYTE nSpLines,strSpectrLine *SpLines,
strParGetPeaks *PGP,BYTE *typNet,BYTE *flErr)
{
BYTE GetMaxAccurate(float *Fun,float *pos,float *amp); // Более точное нахождение максимума по трём точкам: параболическая аппроксимация.
BYTE CheckPeak(USHRT nSpectr,float *Spectr,float FreqPeak,float AmpPeak,BYTE nFunP,float *FunP,float coePeaks,
  BYTE *pFlPeak); // Проверка пика по критерию хорошей различимости на фоне спектра.
BYTE GetTruePeaks(USHRT nSpectr,float *Spectr,BYTE nPeaks,strSpectrLine *SpLines,BYTE *FlPeaks,BYTE nFunP,
  float *FunP,float coePeaks); // Нахождение истинных пиков по критерию хорошей различимости на фоне спектра.

BYTE *Flags,*FlPeaks,k,n,nPeaks,fl,err; USHRT i,iLim,nFrMin,nFrMax,nFrI,nFrIMax,nNeur,num,nFunP,nFunA,nFunTri,widMax;
int iv,ia,iI,iF; float v,S,*Sp,*FunP,*FunTri,fr,frI,del,coe,coeNorm,weiFunTri,wid,ampMax; double powTotal,powPeaks,s;
struct strSpectrLine *pSpL;

if(nSpectr<=2) return 1; if(Spectr==NULL) return 2;
if(nSpLines==0) return 3; if(nPCons==0) return 4; if(nSpLines<=nPCons) return 5; if(SpLines==NULL) return 6;
if(dFr<=0.0F) return 7; if(PGP==NULL) return 8; if(PGP->IsOK()!=0) return 9;
if(typNet==NULL) return 10; // Если надо обработать звук без распознавания, в *typNet хранится информация о типе звука.
if(flErr!=NULL) *flErr=0;
nFrMin=GetUSHRT_Test(PGP->FreqMin/dFr); if(nFrMin==0||nFrMin>nSpectr) { if(flErr!=NULL) *flErr=1; return 11;}
nFrMax=GetUSHRT_Test(PGP->FreqMax/dFr); if(nFrMax==0) { if(flErr!=NULL) *flErr=2; return 12;}
nFrMax=MIN(nFrMax,nSpectr); if(nFrMax<=nFrMin) { if(flErr!=NULL) *flErr=3; return 13;}
nFunTri=GetUSHRT_Test(PGP->FreqDiscrCons/dFr); if(nFunTri<=1) { if(flErr!=NULL) *flErr=4; return 14;}
for(k=0;k<nSpLines;k++) SpLines[k].Zero();

// Нахождение максимума спектра.
ampMax=0.0F; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; if(v>ampMax) ampMax=v;}
if(ampMax==0.0F) return messRet;

// Нахождение среднеквадратичного.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=POW2D(v);} s/=(double)(nFrMax-nFrMin); s=SQRT(s);
coeNorm=(float)s; if(coeNorm<PGP->AmpThr) return messRet;

Flags=FlPeaks=NULL; Sp=FunP=FunTri=NULL; err=0;
// Выделение памяти.
Flags=new BYTE[nSpectr]; if(Flags==NULL) { err=15; goto end;}
Sp=new float[nSpectr]; if(Sp==NULL) { err=16; goto end;}
FunTri=new float[nFunTri]; if(FunTri==NULL) { err=17; goto end;}
FlPeaks=new BYTE[nSpLines]; if(FlPeaks==NULL) { err=18; goto end;}
wid=PGP->FreqBaseMax/dFr;
nFrIMax=GetUSHRT_Test(wid); if(nFrIMax==0) { if(flErr!=NULL) *flErr=5; err=19; goto end;}
widMax=GetUSHRT_Test(wid*PGP->coeWidPeaks*3.0F); if(widMax==0) { if(flErr!=NULL) *flErr=6; err=20; goto end;}
FunP=new float[widMax]; if(FunP==NULL) { err=21; goto end;} // Выделение памяти.

// Нахождение треугольной функции.
coe=1.0F/(float)nFunTri; for(i=0;i<nFunTri;i++) FunTri[i]=(float)(nFunTri-i)*coe; // Нахождение функции.
s=0.; for(i=1;i<nFunTri;i++) s+=(double)FunTri[i]; s*=2.; s+=(double)FunTri[0]; weiFunTri=1.0F/(float)s; // Нормировочный коэффициент.

// Нормировка спектра на среднеквадратичное и фильтр, удаляющий сигнал помех на низких частотах.
v=1.0F/coeNorm; for(i=0;i<nFrMin;i++) Sp[i]=0.0F; for(i=nFrMin;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// Если надо обработать как согласный глухой или шипящий звук, сразу переходим к разложению по треугольным функциям.
if(*typNet==typNNW_Cons) goto TriCons;

// Нахождение максимумов - спектральных линий.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(i=1;i<nSpectr-1;i++) if(Sp[i-1]<=Sp[i]&&Sp[i]>=Sp[i+1]) Flags[i]=1;
for(i=0;i<nFrMin;i++) Flags[i]=0; // Отбрасывание пиков с малой частотой.

// Нахождение первого пика.
nFrI=nFrMin;
FindFirst:
num=USHRT_MAX; for(i=nFrI;i<nFrIMax;i++) { if(Flags[i]==0) continue; v=Sp[i];
if(v<PGP->ampSmPeaksMS||v*coeNorm<ampMax*PGP->ampSmPeaksAbs) continue; num=i; break;}
if(num==USHRT_MAX) goto TriCons; // Если первый пик не найден в заданном диапазоне частот, идёт обработка как для шипящих и глухих согласных.
if(GetMaxAccurate(Sp+num-1,&fr,&S)!=0) { err=22; goto end;} fr+=(float)num;
frI=fr; nFrI=(USHRT)frI+2;
if(nFrI>=nFrIMax) goto TriCons; // Если первый пик не найден в заданном диапазоне частот, идёт обработка как для шипящих и глухих согласных.

// Нахождение функции для выделения пиков. Для нахождения функции нужна основная частота, по которой определяется ширина пика.
wid=frI*PGP->coeWidPeaks;
nFunP=GetUSHRT_Test(wid); if(nFunP==0) { if(flErr!=NULL) *flErr=7; err=23; goto end;}
if((int)nFunP*3>(int)nSpectr) { if(flErr!=NULL) *flErr=8; err=24; goto end;} nFunA=nFunP*3;
if(nFunA>widMax) { if(flErr!=NULL) *flErr=9; err=25; goto end;}
coe=(float)(M_PI*0.5/(double)nFunP); for(i=0;i<nFunA;i++) FunP[i]=(float)cos((double)coe*(double)i); // Нахождение функции.

// Определение, является ли первый пик истинным. Если нет, продолжаем поиск первого пика.
if(CheckPeak(nSpectr,Sp,frI,S,(BYTE)nFunP,FunP,PGP->coeRecPeaksCons,&fl)!=0) { err=26; goto end;}
if(fl==0) goto FindFirst;

pSpL=SpLines; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=frI; nNeur=1; // Занесение информации для первого пика.

// Заполнение массива входного слоя нейронов для нижних по частоте пиков (первый уже найден).
for(i=nFrI;i<nFrMax;i++) { if(Flags[i]==0) continue;
if(GetMaxAccurate(Sp+i-1,&fr,&S)!=0) { err=27; goto end;} fr+=(float)i;
v=fr/frI; num=GetUSHRT_Test(v); if(num<1) { err=28; goto end;}
del=v-(float)num; if(del<0.0F) del=-del; num--; if(num>=nSpLines) break;

// Проверяем, является ли этот пик истинным. Он должен превышать заданный уровень от среднеквадратичного и хорошо выделяться на фоне.
if(CheckPeak(nSpectr,Sp,fr,S,(BYTE)nFunP,FunP,PGP->coeRecPeaksVowel,&fl)!=0) { err=29; goto end;}
if(S<PGP->ampPeaksBad&&fl==0) continue;

pSpL=SpLines+num;
// Занесение вновь найденного пика на свободное место.
if(pSpL->AmpRel==0.0F) { pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr;
if(PGP->flCorrFreq!=0&&S>=PGP->ampPeaksCorrFreq&&del<PGP->ErrFreq) frI=fr/(float)(num+1); // Коррекция основной частоты по частоте максимальной выявленной гармоники с достаточно большой амплитудой.
nNeur=MAX(nNeur,num+1);}
// Занесение вновь найденного пика на место, где уже был найден пик.
else {
// Если сдвиг по частоте до вновь найденного пика невелика, пробуем заменить имеющийся пик на найденный.
if(fr-pSpL->Freq<frI*PGP->coeShPeaks) {
if(pSpL->AmpRel<S) { pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr;
if(PGP->flCorrFreq!=0&&S>=PGP->ampPeaksCorrFreq&&del<PGP->ErrFreq) frI=fr/(float)(num+1); // Коррекция основной частоты по частоте максимальной выявленной гармоники с достаточно большой амплитудой.
nNeur=MAX(nNeur,num+1);}}
// Если сдвиг по частоте велик, добавляем найденный пик как новый, несмотря на то, что его позиция не совсем соответствует номеру.
else { num++; if(num>=nSpLines) break; pSpL=SpLines+num;
if(pSpL->AmpRel<S) { pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=fr; nNeur=MAX(nNeur,num+1);}}
}}

// Нахождение истинных пиков (для характеристики всего спектра).
if(GetTruePeaks(nSpectr,Sp,(BYTE)nNeur,SpLines,FlPeaks,(BYTE)nFunP,FunP,PGP->coeRecPeaksSpectr)!=0) { err=30; goto end;}

// Находим мощность по истинным пикам.
for(i=0;i<nSpectr;i++) Flags[i]=0;
for(k=0;k<(BYTE)nNeur;k++) { if(FlPeaks[k]==0) continue;
pSpL=SpLines+k; if(pSpL->AmpRel==0.0F) continue; fr=pSpL->Freq;
iI=(int)GetUSHRT_Test(fr-wid); if(iI<0) iI=0; if(iI>=(int)nSpectr) iI=(int)nSpectr-1;
iF=(int)GetUSHRT_Test(fr+wid); if(iF<0) iF=0; if(iF>=(int)nSpectr) iF=(int)nSpectr-1; if(iI>iF) continue;
for(i=(USHRT)iI;i<=(USHRT)iF;i++) Flags[i]=1;}
s=0.; for(i=nFrMin;i<nFrMax;i++) if(Flags[i]!=0) { v=Sp[i]; s+=POW2D(v);} powPeaks=SQRT(s);

// Находим суммарную мощность.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Sp[i]; s+=POW2D(v);} powTotal=SQRT(s);
if(powPeaks>powTotal) { err=31; goto end;}

// Если надо обработать как гласный или сонорный звук, берём то разложение по спектральным линиям, которое получилось.
if(*typNet==typNNW_Vowel) goto end;

// Анализ спектра по доле истинных пиков в спектре. Выход из программы, если определено, что звук гласный или сонорный.
if(powPeaks>powTotal*(double)PGP->LevPowPeak) { *typNet=typNNW_Vowel; goto end;}

// Анализ согласных звуков, содержащих как пики (спектральные линии), так и непрерывный спектр.
*typNet=typNNW_Cons;

// Находим истинные пики (для согласных) для занесения во входы нейронов.
nPeaks=MIN(nPCons,(BYTE)nNeur);
if(GetTruePeaks(nSpectr,Sp,nPeaks,SpLines,FlPeaks,(BYTE)nFunP,FunP,PGP->coeRecPeaksCons)!=0) { err=32; goto end;}

// Если первый пик не истинный, всё анализируется как непрерывный спектр.
if(FlPeaks[0]==0) goto TriCons;

// Заносим первые 'nPCons' пиков в массив, если они подряд истинные. Остальные пики обнуляем.
n=0; for(k=0;k<nPeaks;k++) { if(FlPeaks[k]==0) break; n++;}
if(n<nPCons) for(k=n;k<nPCons;k++) { pSpL=SpLines+k; pSpL->Zero();}

// Находим конечную верхнюю частоту интервала для последнего пика.
if(n==0) fr=0.0F; else { pSpL=SpLines+n-1; fr=pSpL->Freq+wid;} iLim=GetUSHRT_Test(fr);
goto TriSum;

// Разложение спектра по треугольным функциям для шипящих и глухих согласных.
TriCons: *typNet=typNNW_Cons;
for(k=0;k<nPCons;k++) (SpLines+k)->Zero(); iLim=0;
TriSum:
for(k=nPCons;k<nSpLines;k++) { iI=((int)(k-nPCons)+1)*(int)nFunTri; pSpL=SpLines+k;
if(iI<iLim) { pSpL->Zero(); continue;}
s=0.; for(iv=-(int)(nFunTri-1);iv<(int)nFunTri;iv++) {
ia=iI+iv; if(ia<nFrMin) continue; if(ia<iLim) continue; if(ia>=(int)nSpectr) continue;
if(iv>=0) i=(USHRT)iv; else i=(USHRT)(-iv); if(i>=nFunTri) { err=33; goto end;}
s+=Sp[ia]*FunTri[i];}
S=(float)s*weiFunTri; pSpL->AmpRel=S; pSpL->Amp=S*coeNorm; pSpL->Freq=(float)iI;}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(FunP); SAFE_DELETE_ARR(FunTri); SAFE_DELETE_ARR(Flags);
SAFE_DELETE_ARR(FlPeaks); return err;
}

//-----------------------------------------------------------------------------------------------------------
// Нахождение истинных пиков по критерию хорошей различимости на фоне спектра.

BYTE GetTruePeaks(USHRT nSpectr,float *Spectr,BYTE nPeaks,strSpectrLine *SpLines,BYTE *FlPeaks,BYTE nFunP,
float *FunP,float coePeaks)
{
BYTE k,nFunA; USHRT j; int iv,ia,iI,iF; float weiFunP; double s; struct strSpectrLine *pSpL;

if(nSpectr==0) return 1; if(Spectr==NULL) return 2; if(nPeaks==0) return 3; if(SpLines==NULL) return 4;
if(FlPeaks==NULL) return 5; if(nFunP==0) return 6; if(FunP==NULL) return 7;
if((USHRT)nFunP*3>UCHAR_MAX) return 8; nFunA=nFunP*3;

s=0.; for(k=1;k<nFunP;k++) s+=FunP[k]; s*=2.; s+=FunP[0]; weiFunP=1.0F/(float)s; // Нормировочный коэффициент.

for(k=0;k<nPeaks;k++) FlPeaks[k]=1;
for(k=0;k<nPeaks;k++) { pSpL=SpLines+k; j=GetUSHRT_Test(pSpL->Freq);
iI=(int)j-(int)nFunA+1; iF=(int)j+(int)nFunA;
s=0.; for(iv=iI;iv<iF;iv++) { if(iv<0||iv>=nSpectr) continue; ia=iv-j; if(ia<0) ia=-ia;
if(ia>=nFunA) return 9; s+=(double)Spectr[iv]*(double)FunP[ia];}
if((float)s*weiFunP<pSpL->AmpRel*coePeaks) FlPeaks[k]=0;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка пика по критерию хорошей различимости на фоне спектра.

BYTE CheckPeak(USHRT nSpectr,float *Spectr,float FreqPeak,float AmpPeak,BYTE nFunP,float *FunP,float coePeaks,
BYTE *pFlPeak)
{
BYTE k,nFunA; USHRT j; int iv,ia,iI,iF; float weiFunP; double s;

if(nSpectr==0) return 1; if(Spectr==NULL) return 2; if(FreqPeak<=0.0F) return 3;
if(nFunP==0) return 4; if(FunP==NULL) return 5; if(pFlPeak==NULL) return 6;
if((USHRT)nFunP*3>UCHAR_MAX) return 7; nFunA=nFunP*3;
s=0.; for(k=1;k<nFunP;k++) s+=FunP[k]; s*=2.; s+=FunP[0]; weiFunP=1.0F/(float)s; // Нормировочный коэффициент.
j=GetUSHRT_Test(FreqPeak); iI=(int)j-(int)nFunA+1; iF=(int)j+(int)nFunA;
s=0.; for(iv=iI;iv<iF;iv++) { if(iv<0||iv>=nSpectr) continue; ia=iv-j; if(ia<0) ia=-ia;
if(ia>=nFunA) return 8; s+=(double)Spectr[iv]*(double)FunP[ia];}
if((float)s*weiFunP<AmpPeak*coePeaks) *pFlPeak=0; else *pFlPeak=1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Разложение спектра по треугольным функциям.

BYTE ResTriFun(USHRT nSpectr,float *Spectr,float dFr,float DiscrTri,float FreqMin,float FreqMax,float AmpThr,
strInpLay *InpLay)
{
BYTE ber; USHRT i,k,nFrMin,nFrMax,nFunTri; int iI,iv,ia; float *Sp,*FunTri,weiFunTri,ampMax,coeNorm,coe,v;
double s;

if(nSpectr==0) return 1; if(Spectr==NULL) return 2; if(dFr<=0.0F) return 3; if(DiscrTri<=0.0F) return 4;
if(FreqMin<=0.0F) return 5; if(FreqMax<=0.0F) return 6; if(FreqMax<=FreqMin) return 7;
if(AmpThr<0.0F) return 8; if(InpLay==NULL) return 9; if(InpLay->IsOK()!=0) return 10;

nFrMin=GetUSHRT_Test(FreqMin/dFr); if(nFrMin==0||nFrMin>nSpectr) return 11;
nFrMax=GetUSHRT_Test(FreqMax/dFr); if(nFrMax==0) return 12;
nFrMax=MIN(nFrMax,nSpectr); if(nFrMax<=nFrMin) return 13;
nFunTri=GetUSHRT_Test(DiscrTri/dFr); if(nFunTri<=1) return 14;

// Нахождение максимума спектра.
ampMax=0.0F; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; if(v>ampMax) ampMax=v;}
if(ampMax==0.0F) return messRet;

Sp=FunTri=NULL; ber=0;
// Выделение памяти.
Sp=new float[nSpectr]; if(Sp==NULL) { ber=15; goto end;}
FunTri=new float[nFunTri]; if(FunTri==NULL) { ber=16; goto end;}

// Нахождение среднеквадратичного.
s=0.; for(i=nFrMin;i<nFrMax;i++) { v=Spectr[i]; s+=POW2D(v);} s/=(double)(nFrMax-nFrMin); s=SQRT(s);
coeNorm=(float)s; if(coeNorm<AmpThr) return messRet;

// Нормировка спектра на среднеквадратичное и фильтр, удаляющий сигнал помех на низких частотах.
v=1.0F/coeNorm; for(i=0;i<nFrMin;i++) Sp[i]=0.0F; for(i=nFrMin;i<nSpectr;i++) Sp[i]=Spectr[i]*v;

// Нахождение треугольной функции.
coe=1.0F/(float)nFunTri; for(i=0;i<nFunTri;i++) FunTri[i]=(float)(nFunTri-i)*coe; // Нахождение функции.
s=0.; for(i=1;i<nFunTri;i++) s+=(double)FunTri[i]; s*=2.; s+=(double)FunTri[0]; weiFunTri=1.0F/(float)s; // Нормировочный коэффициент.

// Треугольное разложение.
for(k=0;k<InpLay->n;k++) { iI=((int)k+1)*(int)nFunTri;
s=0.; for(iv=-(int)(nFunTri-1);iv<(int)nFunTri;iv++) {
ia=iI+iv; if(ia<nFrMin) continue; if(ia>=(int)nSpectr) break;
if(iv>=0) i=(USHRT)iv; else i=(USHRT)(-iv); if(i>=nFunTri) { ber=17; goto end;}
s+=Sp[ia]*FunTri[i];}
InpLay->Values[k]=s*(double)weiFunTri;
}

end: SAFE_DELETE_ARR(Sp); SAFE_DELETE_ARR(FunTri); return ber;
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
// Получение огибающей спектра по спектральным линиям.

BYTE GetEnvelope(USHRT nSpEnv,float *pSpEnv,BYTE nPeaks,strSpectrLine *pSpL,float Del)
{
BYTE k; USHRT i; float frI,frF,ampI,ampF,v,coe; struct strSpectrLine *pSpI,*pSpF;

if(nSpEnv==0) return 1; if(pSpEnv==NULL) return 2;
if(nPeaks<=1) return 3; if(pSpL==NULL) return 4; if(Del<=0.0F) return 5;

k=0;
b: if(k>=nPeaks-1) return messRet;
pSpI=pSpL+k; frI=pSpI->Freq; if(frI==0.0F) { k++; goto b;} ampI=pSpI->AmpRel;
pSpF=pSpL+k+1; frF=pSpF->Freq;
if(frF>0.0F) { if(frF<=frI) return 6; ampF=pSpF->AmpRel;} else { frF=frI+Del; ampF=0.0F;}
coe=(ampF-ampI)/(frF-frI);

for(i=0;i<nSpEnv;i++) { if(i<=frI) { v=0.0F; goto e;}
if(i>frF) {
c: if(k>=nPeaks-2) { v=0.0F; goto e;} k++;
pSpI=pSpL+k; frI=pSpI->Freq; if(frI==0.0F) { k++; goto c;} ampI=pSpI->AmpRel;
pSpF=pSpL+k+1; frF=pSpF->Freq;
if(frF>0.0F) { if(frF<=frI) return 7; if(i>frF) goto c; ampF=pSpF->AmpRel;} else { frF=frI+Del; ampF=0.0F;}
coe=(ampF-ampI)/(frF-frI); if(i<=frI) { v=0.0F; goto e;}
}
v=ampI+((float)i-frI)*coe;
e: pSpEnv[i]=v;}

return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Функции для синтеза звука.

//-----------------------------------------------------------------------------------------------------------
// Синтез звука.

BYTE Synthesis(float *Wave,UINT nPoints,float Amp,USHRT nStep,clInpLayArr *pPeaks,USHRT nPM,double dt,
float Freq,BYTE flIncHigh)
{
BYTE SumCos(UINT x,double *Peaks,USHRT nPeaks,double dt,float Freq,float *Res); // Расчёт волновой формы при синтезе звука.
BYTE SumCosCorr(UINT x,double *Peaks,USHRT nPeaks,double dt,float Freq,float *Res); // Расчёт волновой формы при синтезе звука с коррекцией частот.

BYTE ber; USHRT j,nP,nPeaks,n; UINT i,k,kI; float v; double *pVal,wei,coeT; struct strInpLay *pILA,*pILB;

if(Wave==NULL) return 1; if(nPoints==0) return 2; if(nStep==0) return 3;
if(pPeaks==NULL) return 4; if(pPeaks->IsOK()!=0) return 5; if(pPeaks->nData<=1) return 6;
if(dt<=0.) return 7; if(Freq<=0.0F) return 8;

nP=0; for(i=0;i<pPeaks->nData;i++) {
pILA=pPeaks->Get(i); if(pILA==NULL) return 9; if(pILA->IsOK()!=0) return 10; if(nP<pILA->n) nP=pILA->n;}

pVal=NULL; ber=0;
pVal=new double[nP]; if(pVal==NULL) { ber=11; goto end;}

coeT=1./(double)nStep;
for(i=0;i<pPeaks->nData-1;i++) { kI=i*(UINT)nStep;
pILA=pPeaks->Get(i); if(pILA==NULL) { ber=12; goto end;} if(pILA->IsOK()!=0) { ber=13; goto end;}
pILB=pPeaks->Get(i+1); if(pILB==NULL) { ber=14; goto end;} if(pILB->IsOK()!=0) { ber=15; goto end;}
nPeaks=MIN(pILA->n,pILB->n); if(nPM!=0) nPeaks=MIN(nPeaks,nPM); if(nPeaks>nP) { ber=16; goto end;}

for(j=0;j<nStep;j++) { k=kI+j; if(k>=nPoints) break;
wei=(double)j*coeT;
for(n=0;n<nPeaks;n++) pVal[n]=pILA->Values[n]*(1.-wei)+pILB->Values[n]*wei;
if(flIncHigh==0) { if(SumCos(k,pVal,nPeaks,dt,Freq,&v)!=0) { ber=17; goto end;}}
else { if(SumCosCorr(k,pVal,nPeaks,dt,Freq,&v)!=0) { ber=18; goto end;}}
Wave[k]=v*Amp;}}

kI=pPeaks->nData*(UINT)nStep; if(kI<nPoints) for(k=kI;k<nPoints;k++) Wave[k]=0.0F;

end: SAFE_DELETE_ARR(pVal); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт волновой формы при синтезе звука.

BYTE SumCos(UINT x,double *Peaks,USHRT nPeaks,double dt,float Freq,float *Res)
{
USHRT i; double sum,coe,v;

if(Peaks==NULL) return 1; if(nPeaks==0) return 2; if(dt<=0.) return 3; if(Freq<=0.0F) return 4;
if(Res==NULL) return 5; coe=2.*M_PI*dt;
sum=0.; for(i=0;i<nPeaks;i++) { v=Peaks[i]*cos((double)x*coe*(double)Freq*(double)(i+1)); sum+=v;}
*Res=(float)sum; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Расчёт волновой формы при синтезе звука с коррекцией частот.

BYTE SumCosCorr(UINT x,double *Peaks,USHRT nPeaks,double dt,float Freq,float *Res)
{
BYTE nc; USHRT i; double sum,coe,v,fc,CorrMax;

if(Peaks==NULL) return 1; if(nPeaks==0) return 2; if(dt<=0.) return 3; if(Freq<=0.0F) return 4;
if(Res==NULL) return 5; coe=2.*M_PI*dt; nc=ParIHS.nc; CorrMax=ParIHS.CorrMax;
sum=0.; for(i=0;i<nPeaks;i++) { v=Peaks[i]*cos((double)x*coe*(double)Freq*(double)(i+1));
if(i>(USHRT)nc) { fc=(1.+(double)ParIHS.coeCorr*(double)(i-(USHRT)nc)); if(fc>CorrMax) fc=CorrMax; v*=fc;}
sum+=v;}
*Res=(float)sum; return 0;
}
