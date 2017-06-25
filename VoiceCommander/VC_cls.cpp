/*...........................................................................................................

// Открытие и закрытие файлов.
class clFileT {
clFileT,~clFileT,Close,Open},

// Класс строки.
class clString {
clString,~clString,Zero,Free,Alloc,IsOK,SetZero},

// Набор строк.
class clListString {
clListString,~clListString,Zero,Free,Clear,Alloc,IsOK,Set,Get},

// Вывод справки "*.htm" через 'Explorer'.
class clHelpEx {
clHelpEx,~clHelpEx,Zero,Free,
ZeroLS,FreeLS,CreateLS,ReadLS,
Show,Set,ShowContent,ShowTopic}

...........................................................................................................*/

#include "stdafx.h"

#include "VC_con.h"
#include "VC_cls.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Программы.

BYTE AllocString(char **Str,size_t ln); // Выделение памяти для строки.
void FreeString(char **Str); // Освобождение памяти для строки.
BYTE IsOKStr(char *str); // Проверка строки.
BYTE DupString(char **Str,char *Src); // Выделение памяти для строки и копирование.
BYTE GetString(char **String,char **Items,BYTE n); // Сборка строки из нескольких строк.
BYTE GetName(char **Name,char *path,char *dir,char *name,char *ext); // Получение имени файла включая путь.
BYTE IsFileExist(char *Name,char *PathDir,char *dir,char *ext); // Проверка существования файла.
BYTE IsFileExist_(char *PathName); // Проверка существования файла.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Глобальные переменные.

extern char *extHTM; // Расширение файлов справки в формате '*.htm'.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Строки.

extern char TxtStr[strL_Txt]; // Вспомогательная строка.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Открытие и закрытие файлов.

//-----------------------------------------------------------------------------------------------------------

clFileT::clFileT(void)
{
File=-1; file=NULL;
}

//-----------------------------------------------------------------------------------------------------------

clFileT::~clFileT(void)
{
Close();
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие файла.

void clFileT::Close(void)
{
if(file!=NULL) { fclose(file); file=NULL;} if(File!=-1) { _close(File); File=-1;}
}

//-----------------------------------------------------------------------------------------------------------
// Открытие файла.

BYTE clFileT::Open(char *name,BYTE wr)
{
BYTE ber; char *mode;

Close(); if(name==NULL) return 1; ber=0;
if(wr==0) File=_open(name,_O_RDONLY|_O_SEQUENTIAL|_O_TEXT);
else File=_open(name,_O_CREAT|_O_WRONLY|_O_SEQUENTIAL|_O_TEXT|_O_TRUNC,_S_IREAD|_S_IWRITE);
if(File==-1) { ber=2; goto end;}

if(wr==0) mode="rt"; else mode="wt";
file=fdopen(File,mode); if(file==NULL) { ber=3; goto end;}

end: if(ber!=0) Close(); 
return ber;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Класс строки.

//-----------------------------------------------------------------------------------------------------------

clString::clString(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clString::~clString(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя и инициализация параметров.

void clString::Zero(void)
{
sz=0; String=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clString::Free(void)
{
FreeString(&String); sz=0;
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE clString::Alloc(UINT sz_)
{
BYTE ber;

Free(); if(sz_==0) return 1; sz=sz_; ber=0;
if(AllocString(&String,(size_t)sz)!=0) { ber=2; goto end;}
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE clString::IsOK(void)
{
if(String==NULL) return 1; if(sz==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление массива.

BYTE clString::SetZero(void)
{
UINT i;

if(IsOK()!=0) return 1; for(i=0;i<=sz;i++) String[i]='\0'; return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Набор строк.

//-----------------------------------------------------------------------------------------------------------

clListString::clListString(void)
{
Zero();
}

//-----------------------------------------------------------------------------------------------------------

clListString::~clListString(void)
{
Free();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя и инициализация параметров.

void clListString::Zero(void)
{
nList=0; List=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Освобождение памяти.

void clListString::Free(void)
{
Clear(); SAFE_DELETE_ARR(List); nList=0;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление строк.

void clListString::Clear(void)
{
USHRT i;

if(IsOK()!=0) return; for(i=0;i<nList;i++) SAFE_DELETE(List[i]);
}

//-----------------------------------------------------------------------------------------------------------
// Выделение памяти.

BYTE clListString::Alloc(USHRT nList_)
{
BYTE ber; USHRT i;

Free(); if(nList_==0) return 1; nList=nList_; ber=0;
List=new char *[nList]; if(List==NULL) { ber=2; goto end;}
for(i=0;i<nList;i++) List[i]=NULL;
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Проверки.

BYTE clListString::IsOK(void)
{
if(List==NULL) return 1; if(nList==0) return 2; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Установка строки в массив.

BYTE clListString::Set(USHRT num,char *txt)
{
if(IsOK()!=0) return 1; if(num>=nList) return 2; if(DupString(List+num,txt)!=0) return 3; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Получение строки.

char *clListString::Get(USHRT num)
{
if(IsOK()!=0) return NULL; if(num>=nList) return NULL; return List[num];
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Вывод справки "*.htm" через 'Explorer'.

//-----------------------------------------------------------------------------------------------------------

clHelpEx::clHelpEx(void)
{
Zero(); CreateLS();
}

//-----------------------------------------------------------------------------------------------------------

clHelpEx::~clHelpEx(void)
{
Free(); FreeLS();
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателей и инициализация параметров.

void clHelpEx::Zero(void)
{
Name=CurrDir=NULL; ZeroLS();
}

//-----------------------------------------------------------------------------------------------------------
// Закрытие справки.

void clHelpEx::Free(void)
{
FreeString(&Name); FreeString(&CurrDir);
}

//-----------------------------------------------------------------------------------------------------------
// Обнуление указателя на класс списка строк.

void clHelpEx::ZeroLS(void)
{
LS=NULL;
}

//-----------------------------------------------------------------------------------------------------------
// Удаление класса списка строк.

void clHelpEx::FreeLS(void)
{
SAFE_DELETE(LS);
}

//-----------------------------------------------------------------------------------------------------------
// Создание списка строк.

BYTE clHelpEx::CreateLS(void)
{
FreeLS(); LS=new clListString(); if(LS==NULL) return 1; return 0;
}

//-----------------------------------------------------------------------------------------------------------
// Чтение списка строк.

BYTE clHelpEx::ReadLS(void)
{
BYTE ber; int iv; char *NameInf; clFileT *FT;

if(LS==NULL) return 1; LS->Free(); if(IsOKStr(CurrDir)!=0) return 2;
NameInf=NULL; FT=NULL; ber=0;
if(GetName(&NameInf,CurrDir,NULL,"Topics",".inf")!=0) { ber=3; goto end;}
if(IsFileExist_(NameInf)!=0) { ber=messRet; goto end;} // Проверка существования файла.
FT=new clFileT(); if(FT==NULL) { ber=4; goto end;}
if(FT->Open(NameInf,0)!=0) { ber=5; goto end;}
if(fscanf(FT->file,"%d\n",&iv)==EOF) { ber=6; goto end;} if(iv<0||iv>USHRT_MAX) { ber=7; goto end;}
if(iv==0) goto end;
if(LS->Alloc((USHRT)iv)!=0) { ber=8; goto end;}

while(1) {
if(fscanf(FT->file,"%d%s",&iv,TxtStr)==EOF) break; if(iv<=0||iv>USHRT_MAX) { ber=9; goto end;}
if(iv>=LS->nList) continue;
if(LS->Set(iv-1,TxtStr)!=0) { ber=10; goto end;}
if(fscanf(FT->file,"\n")==EOF) break;}

end: SAFE_DELETE(FT); FreeString(&NameInf); if(ber!=0) LS->Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Показ справки.

BYTE clHelpEx::Show(char *Topic)
{
BYTE Process(char *Path,char *Dir,char *Name,char *ComStr,char *CurrDir,BYTE show,BYTE wait); // Запуск другой программы.

BYTE n,ber; char *ComStr,*PathSys,*Path,*Items[5],*cp;

if(IsOKStr(Name)!=0) return 1;
PathSys=Path=ComStr=NULL; ber=0;

if(AllocString(&PathSys,(size_t)MAX_PATH)!=0) { ber=2; goto end;}
if(GetSystemDirectory((LPTSTR)PathSys,MAX_PATH)==0) { ber=3; goto end;}
cp=strchr(PathSys,':'); if(cp==NULL) { ber=4; goto end;} *cp='\0';
Items[0]=PathSys; Items[1]=":\\Program Files\\Internet Explorer\\";
if(GetString(&Path,Items,2)!=0) { ber=5; goto end;}

Items[0]="-nohome "; Items[1]=CurrDir; Items[2]=Name; n=3;
if(IsOKStr(Topic)==0) { Items[3]="#"; Items[4]=Topic; n+=2;}
if(GetString(&ComStr,Items,n)!=0) { ber=6; goto end;}

if(Process(Path,NULL,"iexplore.exe",ComStr,CurrDir,1,0)!=0) { ber=7; goto end;}

end: FreeString(&PathSys); FreeString(&Path); FreeString(&ComStr); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Установка параметров и проверка наличия файла.

BYTE clHelpEx::Set(char *Path,char *Dir,char *DirFile,char *Name_)
{
BYTE ber;

Free(); if(IsOKStr(Name_)!=0) return 1; ber=0;
if(GetName(&CurrDir,Path,Dir,DirFile,"\\")!=0) { ber=2; goto end;}
if(GetName(&Name,NULL,NULL,Name_,extHTM)!=0) { ber=3; goto end;}
if(IsFileExist(Name,CurrDir,NULL,NULL)!=0) { ber=4; goto end;}
ReadLS(); // Чтение списка строк.
end: if(ber!=0) Free(); return ber;
}

//-----------------------------------------------------------------------------------------------------------
// Показ содержания файла справки.

void clHelpEx::ShowContent(void)
{
Show(NULL);
}

//-----------------------------------------------------------------------------------------------------------
// Показ справки по заданной теме.

BYTE clHelpEx::ShowTopic(DWORD Topic)
{
char *cp;

if(Topic>USHRT_MAX) return 1; if(Topic==0) return 2; if(LS==NULL) return 3;
cp=LS->Get((USHRT)Topic-1); if(cp==NULL) return 4; if(Show(cp)!=0) return 5; return 0;
}
