# Microsoft Developer Studio Project File - Name="Project" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Project - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Project.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Project.mak" CFG="Project - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Project - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Project - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Project - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G4 /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib winmm.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Project - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Project - Win32 Release"
# Name "Project - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cmplx.cpp
# End Source File
# Begin Source File

SOURCE=.\Library.cpp
# End Source File
# Begin Source File

SOURCE=.\Project.cpp
# End Source File
# Begin Source File

SOURCE=.\Project.rc
# End Source File
# Begin Source File

SOURCE=.\Project_cls.cpp
# End Source File
# Begin Source File

SOURCE=.\Project_pro.cpp
# End Source File
# Begin Source File

SOURCE=.\Project_snd.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cmplx.h
# End Source File
# Begin Source File

SOURCE=.\Library.h
# End Source File
# Begin Source File

SOURCE=.\Project.h
# End Source File
# Begin Source File

SOURCE=.\Project_cls.h
# End Source File
# Begin Source File

SOURCE=.\Project_con.h
# End Source File
# Begin Source File

SOURCE=.\Project_pro.h
# End Source File
# Begin Source File

SOURCE=.\Project_snd.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Accept.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_AcceptS.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Add.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Adjust.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Amp.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Browse.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Delete.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_DoProc.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Ins.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_NNW_ErrCntrl.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_NNW_ErrTrain.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_NNW_Inp.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_NNW_Stat.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_NNW_Syn.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_NNW_Train.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_NNW_View.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Save.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_SetTime.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Sign.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_SndCap.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_SndRec.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Sound.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Spct.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Text.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_Time.bmp
# End Source File
# Begin Source File

SOURCE=.\Icon_WatchNNW.bmp
# End Source File
# Begin Source File

SOURCE=.\IconAmp.bmp
# End Source File
# Begin Source File

SOURCE=.\IconSign.bmp
# End Source File
# Begin Source File

SOURCE=.\IconSpct.bmp
# End Source File
# Begin Source File

SOURCE=.\Program.ico
# End Source File
# Begin Source File

SOURCE=.\ViewNNW.ico
# End Source File
# Begin Source File

SOURCE=.\WinText.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
