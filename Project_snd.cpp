/*...........................................................................................................

// Класс звукового сигнала, прочитанного из файла *.wav.
class clWavData {
clWavData,~clWavData,Zero,Free,
ZeroSnd,FreeSnd,AllocSnd,IsOKSnd,
Init_Header,IsOK_Header,
Read_,ReadData,Write_,WriteData,Read,Write},

// Структура отрезка звукового сигнала.
struct strSndBuf {
strSndBuf,~strSndBuf,Zero,Free,Create,IsOK},

// Набор отрезков звука, полученных при записи.
class clSndCapArr {
clSndCapArr,~clSndCapArr,Zero,Free,Clear,Alloc,ReAlloc,CheckSize,IsOK,Create,Get},

// Класс звука, полученного при записи в виде отдельных отрезков.
class clSndCapData {
clSndCapData,~clSndCapData,Zero,FreeSCA,CreateSCA,Free,Add,IsOK,Get,CreateCycle,AddCycle,GetCycle},
FillSndArr,

// Класс объекта для захвата звука (контейнер).
class clDLLObjSoundCap {
clDLLObjSoundCap,~clDLLObjSoundCap,Zero_,ZeroPntFunc,SetPntFunc,
FillInfDevices,InitDirectSound,UnInitDirectSound,Open,Close,StartCapture,StopCapture,CheckMessage,
GetParSnd,FillCB_Devices,FillCB_Formats,SetNotifySize},

// Класс для работы с библиотекой захвата звука.
class clLoadDLLSndCap {
clLoadDLLSndCap,~clLoadDLLSndCap,Zero,Free,
FreeLibr,LoadLibr,ZeroFunLib,LoadFunLib,Load,
ZeroDLLObj,FreeDLLObj,LoadDLLObj,
StartCapture,StopCapture},

// Класс диалогового окна настройки захвата звука.
class clDlgSndCap {
clDlgSndCap,~clDlgSndCap,Zero,Free,Dialog,Create,SelDevice,SelFormat,ChBntSave,MsgCommand,Command},
DlgAdjSoundCapture

...........................................................................................................*/

#include "stdafx.h"
#include "Project_con.h"
#include "Project_cls.h"
#include "Project_snd.h"
#include "resource.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Программы.

void FreeString(char **Str); // Освобождение памяти для строки.
BYTE AllocBYTE(BYTE **bpp,size_t ln); // Выделение памяти для массива 'BYTE'.
void FreeBYTE(BYTE **bpp); // Освобождение памяти для массива 'BYTE'.
BYTE AllocSHRT(SHRT **shipp,size_t ln); // Выделение памяти для массива 'SHRT'.
void FreeSHRT(SHRT **shipp); // Освобождение памяти для массива 'SHRT'.
HANDLE OpenHandleFile_(char *name,BYTE indWr); // Открытие файла.
void CloseHandleFile_(HANDLE *File); // Закрытие файла.
BYTE ReadFile_(HANDLE File,LPVOID Buf,DWORD len); // Чтение файла.
BYTE WriteFile_(HANDLE File,LPVOID Buf,DWORD len); // Запись в файл.
BYTE SizeOfFile(HANDLE File,DWORD *ln); // Получение размера файла.
long SeekFile(HANDLE File,long offs,DWORD MoveMethod); // Позиционирование внутри файла.
void ImgWinC(HWND hwnd,DWORD ColP,DWORD ColB); // Закрашивание окна.
void CloseWin_(HWND *hwnd); // Закрытие окна.
void SetPosWindowCenter(HWND hDlg); // Помещение окна в центр другого окна или экрана.
void EnableChWin(HWND hDlg,int id,BYTE flag); // Ввод и снятие блокировки дочернего окна.
BYTE SetFlEdt(HWND hDlg,int id,float Val,char *Form); // Установка значения с плавающей точкой в окно редактирования.
BYTE GetFlEdt(HWND hDlg,int id,float *Val); // Получение значения с плавающей точкой из окна редактирования.
BYTE SetSizeCombo(HWND hDlg,int id,BYTE num); // Установка размера комбинированного списка по числу строк.
BYTE GetSelCombo(HWND hDlg,UINT id,BYTE *num); // Получение номера выбранной строки в комбинированном списке.
BYTE IsOKStr(char *str); // Проверка строки.
BYTE CompareStr(char *strA,char *strB); // Сравнение строк (с учётом длины строк и типа букв).
void SetBit(BYTE *bp,BYTE num,BYTE b); // Установка бита в числе 'BYTE'.
void Message(UINT StrID,UINT typ); // Вывод сообщения.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные переменные.

extern HINSTANCE hInst; // Идентификатор приложения.
extern LRESULT LRes; // Вспомогательная переменная.

extern HCURSOR cur_wait; // Курсоры общего назначения.

extern DWORD ColDial; // Цвет фона или диалогового окна.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Строки.

extern char TxtStr[strL_Txt]; // Вспомогательные строки.

extern char PathToProgDir[strL_Path]; // Директория программы.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс звукового сигнала, прочитанного из файла *.wav.

//-----------------------------------------------------------------------------------------------------------

clWavData::clWavData(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clWavData::~clWavData(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void clWavData::Zero(void)
{
SET_ZERO(&WF); pwf=&WF.wf; ZeroSnd();
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clWavData::Free(void)
{
SET_ZERO(&WF); FreeSnd();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров для массивов звука.

void clWavData::ZeroSnd(void)
{
BYTE i;

ln=0; ch=0; nBS=0; for(i=0;i<2;i++) { bSnd[i]=NULL; sSnd[i]=NULL;}
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для массивов звука.

void clWavData::FreeSnd(void)
{
BYTE i;

for(i=0;i<2;i++) { FreeBYTE(bSnd+i); FreeSHRT(sSnd+i);} ln=0; ch=0; nBS=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти для массивов звука.

BYTE clWavData::AllocSnd(UINT ln_,BYTE ch_,BYTE nBS_)
{
BYTE i,ber;

FreeSnd(); if(ln_==0) return 1; if(ch_!=1&&ch_!=2) return 2; if(nBS_!=1&&nBS_!=2) return 3;
ln=ln_; ch=ch_; nBS=nBS_; ber=0;
for(i=0;i<ch;i++) {
if(nBS==1) { if(AllocBYTE(bSnd+(UINT)i,(size_t)ln)!=0) { ber=4; goto end;}}
else { if(AllocSHRT(sSnd+(UINT)i,(size_t)ln)!=0) { ber=5; goto end;}}}
end: if(ber!=0) FreeSnd(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки массивов звука.

BYTE clWavData::IsOKSnd(void)
{
BYTE i;

if(ln==0) return 1; if(ch!=1&&ch!=2) return 2; if(nBS!=1&&nBS!=2) return 3;
for(i=0;i<ch;i++) { if(nBS==1) { if(bSnd[i]==NULL) return 4;} else { if(sSnd[i]==NULL) return 5;}}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация структуры заголовка.

void clWavData::Init_Header(BYTE ch_,BYTE nBS_,DWORD sps)
{
BYTE b;

SET_ZERO(&WF); if(pwf==NULL) pwf=&WF.wf; pwf->wFormatTag=WAVE_FORMAT_PCM;
if(ch_==1||ch_==2) pwf->nChannels=(WORD)ch_;
if(nBS_==1||nBS_==2) b=nBS_; else b=0; WF.wBitsPerSample=(WORD)b*8;
pwf->nSamplesPerSec=sps;
pwf->nAvgBytesPerSec=(DWORD)pwf->nChannels*pwf->nSamplesPerSec*(DWORD)b;
pwf->nBlockAlign=(WORD)pwf->nChannels*(WORD)b;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки структуры заголовка.

BYTE clWavData::IsOK_Header(void)
{
BYTE b;

if(pwf==NULL) return 1; if(pwf->wFormatTag!=WAVE_FORMAT_PCM) return 2;
if(pwf->nChannels>UCHAR_MAX) return 3; b=(BYTE)pwf->nChannels; if(b!=1&&b!=2) return 4;
b=(BYTE)(WF.wBitsPerSample/8); if(b!=1&&b!=2) return 5;
if(pwf->nSamplesPerSec==0) return 6;
if(pwf->nAvgBytesPerSec!=(DWORD)pwf->nChannels*pwf->nSamplesPerSec*(DWORD)b) return 7;
if(pwf->nBlockAlign!=(WORD)pwf->nChannels*(WORD)b) return 8;
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE clWavData::Read_(HANDLE File)
{
BYTE ch_,nBS_; char Buf[5]; UINT ln_; DWORD szF,szH,szS,szD,sz,dw;

Free(); if(File==INVALID_HANDLE_VALUE) return 1;
if(SizeOfFile(File,&szF)!=0) return 2; // Получение размера файла.

// Пропускаем секции RIFF, пока не встретится секция звуковых данных, эту секцию читаем.
while(szF) {

szH=2*(DWORD)sizeof(DWORD); if(szF<=szH) return 3; // Размер заголовка секции RIFF.

// Заголовок секции RIFF файла.
if(ReadFile_(File,(LPVOID)Buf,4*(DWORD)sizeof(char))!=0) return 4; Buf[4]='\0'; // Заголовок файла "RIFF".
if(CompareStr(Buf,"RIFF")!=0) return 5; // Проверка - заголовок должен быть "RIFF".
if(ReadFile_(File,(LPVOID)&szS,(DWORD)sizeof(DWORD))!=0) return 6; if(szS==0) return 7; // Размер секции.
sz=szS; // Размер непрочитанных данных секции.
if(szS%2) szS++; // Выравнивание размера секции на границу слова.
if(szH+szS>szF) return 8;

// Читаем имя (тип) RIFF секции.
dw=4*(DWORD)sizeof(char); if(sz<dw) return 9; sz-=dw;
if(ReadFile_(File,(LPVOID)Buf,dw)!=0) return 10; Buf[4]='\0'; // Заголовок блока данных.

// Если секция RIFF не "WAVE", пропускаем эту секцию.
if(CompareStr(Buf,"WAVE")!=0) { szF-=szH+szS;
if(SeekFile(File,(long)szS-(long)dw,FILE_CURRENT)<0) return 11; continue;}

// Заголовок формата.
dw=4*(DWORD)sizeof(char); if(sz<dw) return 12; sz-=dw;
if(ReadFile_(File,(LPVOID)Buf,dw)!=0) return 13; Buf[4]='\0'; // Заголовок формата.
if(CompareStr(Buf,"fmt ")!=0) return 14; // Проверка - заголовок формата должен именоваться "fmt".
dw=(DWORD)sizeof(DWORD); if(sz<dw) return 15; sz-=dw;
if(ReadFile_(File,(LPVOID)&szS,dw)!=0) return 16; // Размер блока формата.
dw=(DWORD)sizeof(PCMWAVEFORMAT); if(szS<dw) return 17; // Проверка размера блока формата.
if(szS%2) szS++; // Выравнивание размера блока формата на границу слова.
if(sz<szS) return 18;
if(ReadFile_(File,(LPVOID)&WF,dw)!=0) return 19; // Читаем структуру, описывающую формат.
if(szS>dw) if(SeekFile(File,(long)(szS-dw),FILE_CURRENT)<0) return 20; // Пропускаем дополнительные данные формата, так как они должны отсутствовать в несжатых данных.
sz-=szS;

// Проверка формата данных.
if(pwf==NULL) return 21;
if(pwf->wFormatTag!=WAVE_FORMAT_PCM) return messRet; // Не читаем другие форматы кроме несжатого звука.
if(pwf->nChannels>UCHAR_MAX) return 22; ch_=(BYTE)pwf->nChannels; if(ch_!=1&&ch_!=2) return 23;
nBS_=(BYTE)(WF.wBitsPerSample/8); if(nBS_!=1&&nBS_!=2) return 24;
if(pwf->nSamplesPerSec==0) return 25;
if(pwf->nAvgBytesPerSec!=(DWORD)ch_*pwf->nSamplesPerSec*(DWORD)nBS_) return 26;
if(pwf->nBlockAlign!=(WORD)ch_*(WORD)nBS_) return 27;

// Читаем секции данных. Выбираем секцию "data" для несжатого звука. Другие форматы не читаем.
while(sz) {
dw=4*(DWORD)sizeof(char); if(sz<dw) return 28; sz-=dw;
if(ReadFile_(File,(LPVOID)Buf,dw)!=0) return 29; Buf[4]='\0'; // Заголовок блока данных.
dw=(DWORD)sizeof(DWORD); if(sz<dw) return 30; sz-=dw;
if(ReadFile_(File,(LPVOID)&szD,dw)!=0) return 31; // Размер блока данных.
if(sz<szD) return 32;

// Если секция не "data", пропускаем эту секцию.
if(CompareStr(Buf,"data")!=0) { if(szD%2) szD++; sz-=szD;
if(SeekFile(File,(long)szD,FILE_CURRENT)<0) return 33; continue;}

// Читаем блок данных несжатого звука. Другие форматы не читаем.
ln_=(UINT)(szD/(DWORD)pwf->nBlockAlign); if(ln_*(UINT)pwf->nBlockAlign!=(UINT)szD) return 34;
if(AllocSnd(ln_,ch_,nBS_)!=0) return 35; // Выделение памяти для массивов звука.
if(ReadData(File)!=0) return 36; // Чтение данных из файла.
szF=0; break;}
}

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение данных из файла.

BYTE clWavData::ReadData(HANDLE File)
{
BYTE *bBuf,ber; SHRT *sBuf; UINT i,j; HCURSOR cur;

if(File==INVALID_HANDLE_VALUE) return 1; if(IsOKSnd()!=0) return 2;
bBuf=NULL; sBuf=NULL; cur=SetCursor(cur_wait); ber=0;

// 1 канал - звук моно. Просто читаем массив данных.
if(ch==1) {
if(nBS==1) { if(ReadFile_(File,(LPVOID)bSnd[0],(DWORD)ln*(DWORD)sizeof(BYTE))!=0) { ber=3; goto end;}}
else { if(ReadFile_(File,(LPVOID)sSnd[0],(DWORD)ln*(DWORD)sizeof(SHRT))!=0) { ber=4; goto end;}}
}

// 2 канала - звук стерео. Читаем сначала весь массив, затем распределяем данные.
else {
if(nBS==1) {
if(AllocBYTE(&bBuf,(size_t)ln*2)!=0) { ber=5; goto end;}
if(ReadFile_(File,(LPVOID)bBuf,(DWORD)ln*2*(DWORD)sizeof(BYTE))!=0) { ber=6; goto end;}
for(i=0;i<ln;i++) { j=i<<1; *(bSnd[0]+i)=bBuf[j]; *(bSnd[1]+i)=bBuf[j+1];}}
else {
if(AllocSHRT(&sBuf,(size_t)ln*2)!=0) { ber=7; goto end;}
if(ReadFile_(File,(LPVOID)sBuf,(DWORD)ln*2*(DWORD)sizeof(SHRT))!=0) { ber=8; goto end;}
for(i=0;i<ln;i++) { j=i<<1; *(sSnd[0]+i)=sBuf[j]; *(sSnd[1]+i)=sBuf[j+1];}}
}

end: SetCursor(cur); FreeBYTE(&bBuf); FreeSHRT(&sBuf); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE clWavData::Write_(HANDLE File)
{
BYTE alD,alFmt,b; DWORD szD,szFmt,szRIFF;

if(File==INVALID_HANDLE_VALUE) return 1; if(IsOKSnd()!=0) return 2; if(IsOK_Header()!=0) return 3;
alD=alFmt=b=0;
szD=(DWORD)ln*(DWORD)ch*(DWORD)nBS; if(szD==0) return 4; if(szD%2) { szD++; alD=1;}
szFmt=(DWORD)sizeof(PCMWAVEFORMAT); if(szFmt%2) { szFmt++; alFmt=1;}
szRIFF=szD+szFmt+5*(DWORD)sizeof(DWORD);

if(WriteFile_(File,(LPVOID)"RIFF",4*(DWORD)sizeof(char))!=0) return 5; // Заголовок файла "RIFF".
if(WriteFile_(File,(LPVOID)&szRIFF,(DWORD)sizeof(DWORD))!=0) return 6; // Размер секции.

if(WriteFile_(File,(LPVOID)"WAVE",4*(DWORD)sizeof(char))!=0) return 7; // Заголовок блока данных.

if(WriteFile_(File,(LPVOID)"fmt ",4*(DWORD)sizeof(char))!=0) return 8; // Заголовок формата.
if(WriteFile_(File,(LPVOID)&szFmt,(DWORD)sizeof(DWORD))!=0) return 9; // Размер секции.
if(WriteFile_(File,(LPVOID)&WF,(DWORD)sizeof(PCMWAVEFORMAT))!=0) return 10; // Запись структуры формата.
if(alFmt!=0) { if(WriteFile_(File,(LPVOID)&b,(DWORD)sizeof(BYTE))!=0) return 11;} // Выравниваем на границу слова.

if(WriteFile_(File,(LPVOID)"data",4*(DWORD)sizeof(char))!=0) return 12; // Заголовок блока данных.
if(WriteFile_(File,(LPVOID)&szD,(DWORD)sizeof(DWORD))!=0) return 13; // Размер секции.
if(WriteData(File)!=0) return 14; // Запись данных в файл.
if(alD!=0) { if(WriteFile_(File,(LPVOID)&b,(DWORD)sizeof(BYTE))!=0) return 15;} // Выравниваем на границу слова.

return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запись данных в файл.

BYTE clWavData::WriteData(HANDLE File)
{
BYTE *bBuf,ber; SHRT *sBuf; UINT i,j; HCURSOR cur;

if(File==INVALID_HANDLE_VALUE) return 1; if(IsOKSnd()!=0) return 2;
bBuf=NULL; sBuf=NULL; cur=SetCursor(cur_wait); ber=0;

// 1 канал - звук моно. Просто записываем массив данных.
if(ch==1) {
if(nBS==1) { if(WriteFile_(File,(LPVOID)bSnd[0],(DWORD)ln*(DWORD)sizeof(BYTE))!=0) { ber=3; goto end;}}
else { if(WriteFile_(File,(LPVOID)sSnd[0],(DWORD)ln*(DWORD)sizeof(SHRT))!=0) { ber=4; goto end;}}
}

// 2 канала - звук стерео. Распределяем данные, потом записываем весь массив.
else {
if(nBS==1) {
if(AllocBYTE(&bBuf,(size_t)ln*2)!=0) { ber=5; goto end;}
for(i=0;i<ln;i++) { j=i<<1; bBuf[j]=*(bSnd[0]+i); bBuf[j+1]=*(bSnd[1]+i);}
if(WriteFile_(File,(LPVOID)bBuf,(DWORD)ln*2*(DWORD)sizeof(BYTE))!=0) { ber=6; goto end;}}
else {
if(AllocSHRT(&sBuf,(size_t)ln*2)!=0) { ber=7; goto end;}
for(i=0;i<ln;i++) { j=i<<1; sBuf[j]=*(sSnd[0]+i); sBuf[j+1]=*(sSnd[1]+i);}
if(WriteFile_(File,(LPVOID)sBuf,(DWORD)ln*2*(DWORD)sizeof(SHRT))!=0) { ber=8; goto end;}}
}

end: SetCursor(cur); FreeBYTE(&bBuf); FreeSHRT(&sBuf); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение из файла.

BYTE clWavData::Read(char *fName)
{
BYTE be,ber; HANDLE File;

if(fName==NULL) return 1; Free();
File=INVALID_HANDLE_VALUE; ber=0;
File=OpenHandleFile_(fName,0);
if(File==INVALID_HANDLE_VALUE) { Message(IDS_Err_CanNotOpen,MB_EX); ber=2; goto end;}
be=Read_(File);
if(be==messRet) { Message(IDS_Err_WrongFormatWAV,MB_EX); ber=messRet; goto end;}
if(be!=0) { Message(IDS_Err_ReadFile,MB_EX); ber=3; goto end;}
end: if(ber!=0) Free(); CloseHandleFile_(&File); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Запись в файл.

BYTE clWavData::Write(char *fName)
{
BYTE ber; HANDLE File;

if(fName==NULL) return 1; if(IsOKSnd()!=0) return 2;
File=INVALID_HANDLE_VALUE; ber=0;
File=OpenHandleFile_(fName,1);
if(File==INVALID_HANDLE_VALUE) { Message(IDS_Err_CanNotSave,MB_EX); ber=3; goto end;}
if(Write_(File)!=0) { Message(IDS_Err_WriteFile,MB_EX); ber=4; goto end;}
end: CloseHandleFile_(&File); return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Структура отрезка звукового сигнала.

//-----------------------------------------------------------------------------------------------------------

strSndBuf::strSndBuf(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

strSndBuf::~strSndBuf(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей.

void strSndBuf::Zero(void)
{
ln=0; Snd=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void strSndBuf::Free(void)
{
FreeSHRT(&Snd); ln=0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание.

BYTE strSndBuf::Create(UINT ln_)
{
Free(); if(ln_==0) return 1; ln=ln_; if(AllocSHRT(&Snd,(size_t)ln)!=0) { ln=0; return 2;} return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE strSndBuf::IsOK(void)
{
if(ln==0) return 1; if(Snd==NULL) return 2; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Набор отрезков звука, полученных при записи.

//-----------------------------------------------------------------------------------------------------------
// Конструктор.

clSndCapArr::clSndCapArr(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------
// Деструктор.

clSndCapArr::~clSndCapArr(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void clSndCapArr::Zero(void)
{
nI=nM=0; Arr=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clSndCapArr::Free(void)
{
Clear(); SAFE_DELETE_ARR(Arr); nM=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление структур 'strSndBuf'.

void clSndCapArr::Clear(void)
{
UINT i;

if(IsOK()!=0) return; for(i=0;i<nM;i++) SAFE_DELETE(Arr[i]); nI=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE clSndCapArr::Alloc(UINT nM_)
{
BYTE ber; UINT i;

if(nM_==0) return 1; Free(); ber=0; nM=nM_;
Arr=new typPntSndBuf[nM]; if(Arr==NULL) { ber=2; goto end;}
for(i=0;i<nM;i++) Arr[i]=NULL;
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Перераспределение памяти.

BYTE clSndCapArr::ReAlloc(UINT nM_)
{
UINT i; typPntSndBuf *Arr_;

if(nM_<nI) return 1; if(nM_==0) { Free(); return 0;}
if(IsOK()!=0) { if(Alloc(nM_)!=0) return 2; return 0;} if(nM_==nM) return 0;
Arr_=new typPntSndBuf[nM_]; if(Arr_==NULL) return 3;
if(nM_<nM) for(i=nM_;i<nM;i++) SAFE_DELETE(Arr[i]);
for(i=0;i<MIN(nM,nM_);i++) Arr_[i]=Arr[i];
if(nM_>nM) for(i=nM;i<nM_;i++) Arr_[i]=NULL;
SAFE_DELETE_ARR(Arr); Arr=Arr_; nM=nM_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверка размера массива и при необходимости выделение памяти.

BYTE clSndCapArr::CheckSize(UINT nM_)
{
UINT nMv;

if(nM_<=nM) return 0; if(nM>UINT_MAX-nSA_Step) nMv=nM_; else nMv=nM+nSA_Step;
if(ReAlloc(nMv)!=0) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE clSndCapArr::IsOK(void)
{
if(nM==0) return 1; if(Arr==NULL) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание объекта отрезка звукового сигнала.

BYTE clSndCapArr::Create(UINT num)
{
if(IsOK()!=0) return 1; if(num>=nM) return 2; if(Arr[num]!=NULL) return 0;
Arr[num]=new strSndBuf; if(Arr[num]==NULL) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение отрезка звукового сигнала.

strSndBuf *clSndCapArr::Get(UINT num)
{
if(IsOK()!=0) return NULL; if(num>=nI) return NULL; return Arr[num];
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс звука, полученного при записи в виде отдельных отрезков.

//-----------------------------------------------------------------------------------------------------------

clSndCapData::clSndCapData(void)
{
Zero(); CreateSCA();
}

//-----------------------------------------------------------------------------------------------------------

clSndCapData::~clSndCapData(void)
{
FreeSCA();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей.

void clSndCapData::Zero(void)
{
SCA=NULL; nSPS=0; nCnt=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clSndCapData::FreeSCA(void)
{
SAFE_DELETE(SCA);
}

//-----------------------------------------------------------------------------------------------------------
// Создание класса набора отрезков звука.

BYTE clSndCapData::CreateSCA(void)
{
FreeSCA(); SCA=new clSndCapArr(); if(SCA==NULL) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление массивов звука.

void clSndCapData::Free(void)
{
if(SCA!=NULL) SCA->Free();
}

//-----------------------------------------------------------------------------------------------------------
// Добавление отрезка звукового сигнала.

BYTE clSndCapData::Add(UINT szSnd,SHRT *pSnd)
{
UINT i; struct strSndBuf *pSB;

if(szSnd==0) return 1; if(pSnd==NULL) return 2; if(SCA==NULL) return 3; if(SCA->nI>UINT_MAX-1) return 4;
if(SCA->CheckSize(SCA->nI+1)!=0) return 5; if(SCA->Create(SCA->nI)!=0) return 6; SCA->nI++;
pSB=SCA->Get(SCA->nI-1); if(pSB==NULL) return 7; if(pSB->Create(szSnd)!=0) return 8;
for(i=0;i<szSnd;i++) pSB->Snd[i]=pSnd[i]; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки набора отрезков звука.

BYTE clSndCapData::IsOK(void)
{
if(SCA==NULL) return 1; if(SCA->nI==0) return 2; if(SCA->IsOK()!=0) return 3; if(nSPS==0) return 4; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение отрезка звукового сигнала.

strSndBuf *clSndCapData::Get(UINT num)
{
if(SCA==NULL) return NULL; return SCA->Get(num);
}

//-----------------------------------------------------------------------------------------------------------
// Создание циклического буфера.

BYTE clSndCapData::CreateCycle(UINT nM_)
{
UINT i;

if(SCA==NULL) return 1; if(SCA->Alloc(nM_)!=0) return 2;
for(i=0;i<nM_;i++) if(SCA->Create(i)!=0) return 3; nCnt=0; SCA->nI=nM_; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Добавление отрезка звукового сигнала в цикл.

BYTE clSndCapData::AddCycle(UINT szSnd,SHRT *pSnd)
{
UINT i; struct strSndBuf *pSB;

if(szSnd==0) return 1; if(pSnd==NULL) return 2; if(SCA==NULL) return 3; if(SCA->nI==0) return 4;
if(nCnt>=SCA->nI) return 5; pSB=SCA->Get(nCnt); if(pSB==NULL) return 6; if(pSB->Create(szSnd)!=0) return 7;
for(i=0;i<szSnd;i++) pSB->Snd[i]=pSnd[i]; nCnt++; if(nCnt==SCA->nI) nCnt=0; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение отрезка звукового сигнала из цикла.

BYTE clSndCapData::GetCycle(UINT szSnd,SHRT *pSnd,UINT Shift)
{
UINT i,k,cnt,n,sh,ln; struct strSndBuf *pSB;

if(szSnd==0) return 1; if(pSnd==NULL) return 2; if(SCA==NULL) return 3; if(SCA->IsOK()!=0) return 4;
n=0; cnt=nCnt; for(i=0;i<SCA->nI;i++) { if(cnt==0) cnt=SCA->nI-1; else cnt--; if(cnt==nCnt) return 5;
pSB=SCA->Get(cnt); if(pSB==NULL) return 6; if(pSB->IsOK()!=0) break; n+=pSB->ln; if(n>=Shift) break;}
if(n==0) return messRet;
sh=n-Shift; ln=0; while(1) {
pSB=SCA->Get(cnt); if(pSB==NULL) return 7; if(pSB->IsOK()!=0) return 8;
if(sh>=pSB->ln) return 9; n=pSB->ln-sh; if(ln>UINT_MAX-n) return 10; if(ln+n>szSnd) n=szSnd-ln;
for(k=0;k<n;k++) pSnd[k+ln]=pSB->Snd[k+sh]; ln+=n; if(ln>szSnd) return 11; if(ln==szSnd) break;
cnt++; if(cnt==SCA->nI) cnt=0; if(cnt==nCnt) return 12; sh=0;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение структуры звука.

BYTE FillSndArr(clSndCapData *SndCapData,strSndArr *Snd)
{
UINT i,j,sz,nI; struct strSndBuf *pSB;

if(SndCapData==NULL) return 1; if(SndCapData->IsOK()!=0) return 2; if(Snd==NULL) return 3;
nI=SndCapData->SCA->nI; if(nI==0) return 4;
sz=0; for(i=0;i<nI;i++) { pSB=SndCapData->Get(i); if(pSB==NULL) continue; if(pSB->IsOK()!=0) continue;
if(sz>UINT_MAX-pSB->ln) break; sz+=pSB->ln;}
if(sz==0) return messRet; if(Snd->Create(sz)!=0) return 5;
sz=0; for(i=0;i<nI;i++) { pSB=SndCapData->Get(i); if(pSB==NULL) continue; if(pSB->IsOK()!=0) continue;
if(sz>UINT_MAX-pSB->ln) break; for(j=0;j<pSB->ln;j++) Snd->Snd[j+sz]=(float)pSB->Snd[j]; sz+=pSB->ln;}
Snd->dt=1./(double)SndCapData->nSPS; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс объекта для захвата звука (контейнер).

//-----------------------------------------------------------------------------------------------------------

clDLLObjSoundCap::clDLLObjSoundCap(void)
{
Zero_();
}

//-----------------------------------------------------------------------------------------------------------

clDLLObjSoundCap::~clDLLObjSoundCap(void)
{
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация параметров.

void clDLLObjSoundCap::Zero_(void)
{
numDevice=0; numFormat=0; ZeroPntFunc();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя на класс и указателя на функцию обратного вызова.

void clDLLObjSoundCap::ZeroPntFunc(void)
{
Pnt=0UL; funCB=NULL; pFlStop=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Установка указателей.

void clDLLObjSoundCap::SetPntFunc(PNT_DATA Pnt_,funSndCap_CallBack funCB_,BYTE *pFlStop_)
{
Pnt=Pnt_; funCB=funCB_; pFlStop=pFlStop_;
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка информации об имеющихся устройствах ввода звука.

BYTE _stdcall clDLLObjSoundCap::FillInfDevices(void)
{
return messRet;
}

//-----------------------------------------------------------------------------------------------------------
// Инициализация 'Direct Sound'.

BYTE _stdcall clDLLObjSoundCap::InitDirectSound(void)
{
return messRet;
}

//-----------------------------------------------------------------------------------------------------------
// Деинициализация 'Direct Sound'.

void _stdcall clDLLObjSoundCap::UnInitDirectSound(void)
{
}

//-----------------------------------------------------------------------------------------------------------
// Открытие интерфейса.

BYTE _stdcall clDLLObjSoundCap::Open(void)
{
return messRet;
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие интерфейса.

void _stdcall clDLLObjSoundCap::Close(void)
{
}

//-----------------------------------------------------------------------------------------------------------
// Запуск захвата звука.

BYTE _stdcall clDLLObjSoundCap::StartCapture(void)
{
return messRet;
}

//-----------------------------------------------------------------------------------------------------------
// Остановка захвата звука.

void _stdcall clDLLObjSoundCap::StopCapture(void)
{
}

//-----------------------------------------------------------------------------------------------------------
// Опрос сообщений при захвате звука.

BYTE _stdcall clDLLObjSoundCap::CheckMessage(void)
{
return messRet;
}

//-----------------------------------------------------------------------------------------------------------
// Получение параметров формата звука.

void _stdcall clDLLObjSoundCap::GetParSnd(UINT *nSPS,BYTE *nChan,BYTE *nbPS)
{
if(nSPS!=NULL) *nSPS=0; if(nChan!=NULL) *nChan=0; if(nbPS!=NULL) *nbPS=0;
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение списка имеющимися устройствами записи звука.

BYTE _stdcall clDLLObjSoundCap::FillCB_Devices(HWND hDlg,UINT id)
{
return messRet;
}

//-----------------------------------------------------------------------------------------------------------
// Заполнение списка имеющимися для выбранного устройства форматами звука.

BYTE _stdcall clDLLObjSoundCap::FillCB_Formats(HWND hDlg,UINT id)
{
return messRet;
}

//-----------------------------------------------------------------------------------------------------------
// Установка размера буфера сообщений.

void _stdcall clDLLObjSoundCap::SetNotifySize(UINT szNotify_)
{
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс для работы с библиотекой захвата звука.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Метка назначения библиотеки для захвата звука.

char *LabDLL_SoundCap="SoundCapture";

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Имена функций библиотеки для захвата звука.

char
*NP_Dll_SndCap_CreateObj="CreateObj", // Создание объекта.
*NP_Dll_SndCap_DeleteObj="DeleteObj"; // Уничтожение объекта.

//-----------------------------------------------------------------------------------------------------------

clLoadDLLSndCap::clLoadDLLSndCap(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clLoadDLLSndCap::~clLoadDLLSndCap(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void clLoadDLLSndCap::Zero(void)
{
hLib=NULL; ZeroFunLib(); ZeroDLLObj();
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clLoadDLLSndCap::Free(void)
{
ZeroFunLib(); FreeLibr(); FreeDLLObj();
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти для библиотеки.

void clLoadDLLSndCap::FreeLibr(void)
{
SAFE_FREE_LIB(hLib);
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка библиотеки.

BYTE clLoadDLLSndCap::LoadLibr(char *nameDir,char *nameDLL)
{
BYTE LoadLib(char *nameLib,char *Path,char *Dir,HMODULE *hLib); // Загрузка библиотеки '*.dll'.

BYTE ber;

FreeLibr(); if(IsOKStr(nameDLL)!=0) return 1; ber=0;
if(LoadLib(nameDLL,PathToProgDir,nameDir,&hLib)!=0) { ber=2; goto end;}
if(hLib==NULL) { ber=3; goto end;}
end: if(ber!=0) FreeLibr(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей на функции библиотеки.

void clLoadDLLSndCap::ZeroFunLib(void)
{
funCreateObj=NULL; funDeleteObj=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка функций библиотеки.

BYTE clLoadDLLSndCap::LoadFunLib(void)
{
BYTE ber; char *cp;

ber=0; ZeroFunLib(); if(hLib==NULL) return 1;

// Создание объекта.
cp=NP_Dll_SndCap_CreateObj; if(IsOKStr(cp)==0) funCreateObj=(pDll_SndCap_CreateObj)GetProcAddress(hLib,cp);
if(funCreateObj==NULL) ber+=1<<0;

// Удаление объекта.
cp=NP_Dll_SndCap_DeleteObj; if(IsOKStr(cp)==0) funDeleteObj=(pDll_SndCap_DeleteObj)GetProcAddress(hLib,cp);
if(funDeleteObj==NULL) ber+=1<<1;

if(ber!=0) { Message(IDS_Err_DLLProg,MB_EX);
if(sprintf(TxtStr,"Flags: %d",(int)ber)>0) MessageBox(NULL,TxtStr,NULL,MB_IN);
ZeroFunLib(); return 2;}
return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Загрузка библиотеки и функций.

BYTE clLoadDLLSndCap::Load(char *nameDir,char *nameDLL)
{
BYTE ber;

Free(); if(LoadLibr(nameDir,nameDLL)!=0) return 1; ber=0;
if(LoadFunLib()!=0) { ber=2; goto end;} // Загрузка функций библиотеки.
if(LoadDLLObj()!=0) { ber=3; goto end;} // Создание объекта библиотеки.
if(Obj==NULL) { ber=4; goto end;}
if(Obj->FillInfDevices()!=0) { ber=5; goto end;} // Загрузка информации об имеющихся устройствах ввода звука.
if(Obj->InitDirectSound()!=0) { ber=6; goto end;} // Инициализация 'Direct Sound'.
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей на объект библиотеки.

void clLoadDLLSndCap::ZeroDLLObj(void)
{
Obj=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление объекта библиотеки.

BYTE clLoadDLLSndCap::FreeDLLObj(void)
{
if(hLib==NULL) return 1; if(funDeleteObj==NULL) return 2; (*funDeleteObj)(&Obj); Obj=NULL; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание объекта библиотеки.

BYTE clLoadDLLSndCap::LoadDLLObj(void)
{
if(Obj!=NULL) FreeDLLObj(); if(hLib==NULL) return 1; if(funCreateObj==NULL) return 2;
if((*funCreateObj)(&Obj)!=0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Запуск захвата звука.

BYTE clLoadDLLSndCap::StartCapture(void)
{
BYTE ber;

if(Obj==NULL) return 1; ber=0;
if(Obj->Open()!=0) { ber=2; goto end;} // Открытие интерфейса.
if(Obj->StartCapture()!=0) { ber=3; goto end;} // Запуск захвата звука.
end: if(ber!=0) Obj->Close(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Остановка захвата звука.

void clLoadDLLSndCap::StopCapture(void)
{
if(Obj==NULL) return; Obj->StopCapture(); Obj->Close();
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс диалогового окна настройки захвата звука.

//-----------------------------------------------------------------------------------------------------------

clDlgSndCap::clDlgSndCap(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clDlgSndCap::~clDlgSndCap(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void clDlgSndCap::Zero(void)
{
hDlg=NULL; ObjSC=NULL; numDev=numForm=UCHAR_MAX; flCh=0;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clDlgSndCap::Free(void)
{
CloseWin_(&hDlg);
}

//-----------------------------------------------------------------------------------------------------------
// Открытие диалогового окна.

BYTE clDlgSndCap::Dialog(HWND hWndOwner,clDLLObjSoundCap *ObjSC_,BYTE *flRet)
{
LRESULT CALLBACK DlgAdjSoundCapture(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam); // Диалоговое окно настройки захвата звука.

BYTE fl;

if(hWndOwner==NULL) return 1; if(hInst==NULL) return 2; if(ObjSC_==NULL) return 3; ObjSC=ObjSC_;
fl=DialogBoxParam(hInst,(LPCTSTR)IDD_ADJ_SOUND_CAPTURE,hWndOwner,(DLGPROC)DlgAdjSoundCapture,(LPARAM)this);
if(flRet!=NULL) *flRet=fl; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Создание всех компонент объекта.

BYTE clDlgSndCap::Create(HWND hDlg_)
{
if(hDlg_==NULL) return 1; hDlg=hDlg_; SetPosWindowCenter(hDlg); if(ObjSC==NULL) return 2;
numDev=ObjSC->numDevice; numForm=ObjSC->numFormat;
SetSizeCombo(hDlg,IDC_COMBO_FORMAT,nSndForm);
ObjSC->FillCB_Devices(hDlg,IDC_COMBO_DEVICES);
ObjSC->FillCB_Formats(hDlg,IDC_COMBO_FORMAT);
ChBntSave(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выбор устройства для захвата звука.

BYTE clDlgSndCap::SelDevice(BYTE num)
{
BYTE fl;

if(ObjSC==NULL) return 1; if(num==ObjSC->numDevice) return 0;
if(numDev!=num) fl=1; else fl=0; SetBit(&flCh,0,fl); ChBntSave();
ObjSC->UnInitDirectSound(); ObjSC->numDevice=num; if(ObjSC->InitDirectSound()!=0) return 2;
ObjSC->FillCB_Formats(hDlg,IDC_COMBO_FORMAT); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Выбор формата звука.

BYTE clDlgSndCap::SelFormat(BYTE num)
{
BYTE numF,fl; HWND hwnd;

if(ObjSC==NULL) return 1; if(hDlg==NULL) return 2;
hwnd=GetDlgItem(hDlg,IDC_COMBO_FORMAT); if(hwnd==NULL) return 3;
LRes=SendMessage(hwnd,CB_GETITEMDATA,num,0L); if(LRes==CB_ERR) return 4; if(LRes>UCHAR_MAX) return 5;
numF=(BYTE)LRes; if(numF==ObjSC->numFormat) return 0;
ObjSC->numFormat=numF; if(numForm!=numF) fl=1; else fl=0; SetBit(&flCh,1,fl); ChBntSave(); return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка состояния кнопки сохранения результатов выбора устройства и формата звука.

void clDlgSndCap::ChBntSave(void)
{
EnableChWin(hDlg,IDOK,flCh);
}

//-----------------------------------------------------------------------------------------------------------
// Обработка очереди сообщений окна.

LRESULT clDlgSndCap::MsgCommand(UINT msg,WPARAM wParam,LPARAM lParam,BYTE *flag)
{
if(flag==NULL) return 0L; *flag=0; if(hDlg==NULL) return 0L; if(msg==WM_INITDIALOG) return 0L;

switch(msg) { default: break;

// WM_SYSCOMMAND ............................................................................................
case WM_SYSCOMMAND: if(wParam!=SC_CLOSE) return 0L; *flag=1; EndDialog(hDlg,0); break;

// WM_COMMAND ...............................................................................................
case WM_COMMAND: *flag=1; Command(wParam); break;

// WM_PAINT .................................................................................................
case WM_PAINT: *flag=1; ImgWinC(hDlg,ColDial,ColDial); break;
}

return 0L;
}

//-----------------------------------------------------------------------------------------------------------
// Команды от окон и органов управления.

BYTE clDlgSndCap::Command(WPARAM wParam)
{
BYTE flag,num; int id;

if(hDlg==NULL) return 1; flag=2; id=LOWORD(wParam);

switch(id) { default: break;

// IDC_COMBO_DEVICES .........................................................................................
case IDC_COMBO_DEVICES: flag=0; if(GetSelCombo(hDlg,IDC_COMBO_DEVICES,&num)!=0) break; SelDevice(num); break;

// IDC_COMBO_FORMAT ..........................................................................................
case IDC_COMBO_FORMAT: flag=0; if(GetSelCombo(hDlg,IDC_COMBO_FORMAT,&num)!=0) break; SelFormat(num); break;

// IDOK ......................................................................................................
case IDOK: flag=0; EndDialog(hDlg,flCh); break;

// IDCANCEL ..................................................................................................
case IDCANCEL: flag=0; EndDialog(hDlg,0); break;
}

return flag;
}

//-----------------------------------------------------------------------------------------------------------
// Диалоговое окно настройки захвата звука.

LRESULT CALLBACK DlgAdjSoundCapture(HWND hDlg,UINT msg,WPARAM wParam,LPARAM lParam)
{
BYTE flag; clDlgSndCap *DSC;

if(msg!=WM_INITDIALOG) { DSC=(clDlgSndCap *)GetWindowLong(hDlg,DWL_USER);
if(DSC!=NULL) { LRes=DSC->MsgCommand(msg,wParam,lParam,&flag); if(flag!=0) return LRes;}}

switch(msg) { default: break;

// WM_INITDIALOG ............................................................................................
case WM_INITDIALOG: SetWindowLong(hDlg,DWL_USER,(long)lParam); DSC=(clDlgSndCap *)lParam;
if(DSC==NULL) { fin: PostMessage(hDlg,WM_COMMAND,IDCANCEL,0L); return 0L;}
if(DSC->Create(hDlg)!=0) goto fin; return (LRESULT)TRUE;

// WM_PAINT .................................................................................................
case WM_PAINT: ImgWinC(hDlg,ColDial,ColDial); break;

// WM_CLOSE .................................................................................................
case WM_CLOSE: DestroyWindow(hDlg); break;

// WM_DESTROY ...............................................................................................
case WM_DESTROY: SetWindowLong(hDlg,DWL_USER,0L); break;
}

return FALSE;
}
