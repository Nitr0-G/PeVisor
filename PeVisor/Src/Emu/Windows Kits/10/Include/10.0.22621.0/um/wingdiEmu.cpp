/*
 ███▄ ▄███▓▄▄▄      ██▀███  ██▓█    ██  ██████     ▄▄▄      ██ ▄█▄▄▄          ███▄    █ ██▄▄▄█████▓██▀███  ▒█████   ▄████ 
▓██▒▀█▀ ██▒████▄   ▓██ ▒ ██▓██▒██  ▓██▒██    ▒    ▒████▄    ██▄█▒████▄        ██ ▀█   █▓██▓  ██▒ ▓▓██ ▒ ██▒██▒  ██▒██▒ ▀█▒
▓██    ▓██▒██  ▀█▄ ▓██ ░▄█ ▒██▓██  ▒██░ ▓██▄      ▒██  ▀█▄ ▓███▄▒██  ▀█▄     ▓██  ▀█ ██▒██▒ ▓██░ ▒▓██ ░▄█ ▒██░  ██▒██░▄▄▄░
▒██    ▒██░██▄▄▄▄██▒██▀▀█▄ ░██▓▓█  ░██░ ▒   ██▒   ░██▄▄▄▄██▓██ █░██▄▄▄▄██    ▓██▒  ▐▌██░██░ ▓██▓ ░▒██▀▀█▄ ▒██   ██░▓█  ██▓
▒██▒   ░██▒▓█   ▓██░██▓ ▒██░██▒▒█████▓▒██████▒▒    ▓█   ▓██▒██▒ █▓█   ▓██▒   ▒██░   ▓██░██░ ▒██▒ ░░██▓ ▒██░ ████▓▒░▒▓███▀▒
░ ▒░   ░  ░▒▒   ▓▒█░ ▒▓ ░▒▓░▓ ░▒▓▒ ▒ ▒▒ ▒▓▒ ▒ ░    ▒▒   ▓▒█▒ ▒▒ ▓▒▒   ▓▒█░   ░ ▒░   ▒ ▒░▓   ▒ ░░  ░ ▒▓ ░▒▓░ ▒░▒░▒░ ░▒   ▒ 
░  ░      ░ ▒   ▒▒ ░ ░▒ ░ ▒░▒ ░░▒░ ░ ░░ ░▒  ░ ░     ▒   ▒▒ ░ ░▒ ▒░▒   ▒▒ ░   ░ ░░   ░ ▒░▒ ░   ░     ░▒ ░ ▒░ ░ ▒ ▒░  ░   ░ 
░      ░    ░   ▒    ░░   ░ ▒ ░░░░ ░ ░░  ░  ░       ░   ▒  ░ ░░ ░ ░   ▒         ░   ░ ░ ▒ ░ ░       ░░   ░░ ░ ░ ▒ ░ ░   ░ 
       ░        ░  ░  ░     ░    ░          ░           ░  ░  ░       ░  ░            ░ ░            ░        ░ ░       ░ 
                                                                                                                          

*/
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/wingdiEmu.hpp"
/*
int
__cdecl
AddFontResourceA(
      LPCSTR  namelessArg_0  );

*/
void EmuApi::EmuAddFontResourceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    std::string rlanamelessArg_0;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)namelessArg_0, rlanamelessArg_0)) { printf("Error when read namelessArg_0 in AddFontResourceA"); _CrtDbgBreak(); }


    int AddFontResourceAResult = AddFontResourceA((LPCSTR)rlanamelessArg_0.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &AddFontResourceAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)namelessArg_0, rlanamelessArg_0)) { printf("Error when read namelessArg_0 in AddFontResourceA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddFontResourceA\n";
    #endif

    return;
}


/*
int
__cdecl
AddFontResourceW(
      LPCWSTR  namelessArg_0  );

*/
void EmuApi::EmuAddFontResourceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    std::wstring rlwnamelessArg_0;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_0, rlwnamelessArg_0)) { printf("Error when read namelessArg_0 in AddFontResourceW"); _CrtDbgBreak(); }


    int AddFontResourceWResult = AddFontResourceW((LPCWSTR)rlwnamelessArg_0.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &AddFontResourceWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_0, rlwnamelessArg_0)) { printf("Error when read namelessArg_0 in AddFontResourceW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddFontResourceW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AnimatePalette(
      HPALETTE              hPal         ,
      UINT                  iStartIndex  ,
      UINT                  cEntries     ,
      const PALETTEENTRY *  ppe          );

*/
void EmuApi::EmuAnimatePalette(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HPALETTE hPal{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hPal);

    UINT iStartIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iStartIndex);

    UINT cEntries{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cEntries);

    PALETTEENTRY ppe{};
    uc_reg_read(uc, UC_X86_REG_R9, &ppe);


    BOOL AnimatePaletteResult = AnimatePalette((HPALETTE)hPal,(UINT)iStartIndex,(UINT)cEntries,(const PALETTEENTRY *)&ppe);


    uc_reg_write(uc, UC_X86_REG_EAX, &AnimatePaletteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hPal);
    uc_reg_write(uc, UC_X86_REG_EDX, &iStartIndex);
    uc_reg_write(uc, UC_X86_REG_R8D, &cEntries);
    uc_reg_write(uc, UC_X86_REG_R9, &ppe);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAnimatePalette\n";
    #endif

    return;
}


/*
BOOL
__cdecl
Arc(
      HDC  hdc  ,
      int  x1   ,
      int  y1   ,
      int  x2   ,
      int  y2   ,
      int  x3   ,
      int  y3   ,
      int  x4   ,
      int  y4   );

*/
void EmuApi::EmuArc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x1);

    int y1{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y1);

    int x2{};
    uc_reg_read(uc, UC_X86_REG_R9D, &x2);

    int y2{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &y2, sizeof(y2));

    int x3{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &x3, sizeof(x3));

    int y3{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &y3, sizeof(y3));

    int x4{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &x4, sizeof(x4));

    int y4{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &y4, sizeof(y4));


    BOOL ArcResult = Arc((HDC)hdc,(int)x1,(int)y1,(int)x2,(int)y2,(int)x3,(int)y3,(int)x4,(int)y4);


    uc_reg_write(uc, UC_X86_REG_EAX, &ArcResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x1);
    uc_reg_write(uc, UC_X86_REG_R8D, &y1);
    uc_reg_write(uc, UC_X86_REG_R9D, &x2);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &y2, sizeof(y2));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &x3, sizeof(x3));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &y3, sizeof(y3));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &x4, sizeof(x4));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &y4, sizeof(y4));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuArc\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BitBlt(
      HDC    hdc     ,
      int    x       ,
      int    y       ,
      int    cx      ,
      int    cy      ,
      HDC    hdcSrc  ,
      int    x1      ,
      int    y1      ,
      DWORD  rop     );

*/
void EmuApi::EmuBitBlt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    int cx{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cx);

    int cy{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cy, sizeof(cy));

    HDC hdcSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));

    int x1{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &x1, sizeof(x1));

    int y1{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &y1, sizeof(y1));

    DWORD rop{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &rop, sizeof(rop));


    BOOL BitBltResult = BitBlt((HDC)hdc,(int)x,(int)y,(int)cx,(int)cy,(HDC)hdcSrc,(int)x1,(int)y1,(DWORD)rop);


    uc_reg_write(uc, UC_X86_REG_EAX, &BitBltResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9D, &cx);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cy, sizeof(cy));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &x1, sizeof(x1));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &y1, sizeof(y1));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &rop, sizeof(rop));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBitBlt\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CancelDC(
      HDC  hdc  );

*/
void EmuApi::EmuCancelDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL CancelDCResult = CancelDC((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &CancelDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCancelDC\n";
    #endif

    return;
}


/*
BOOL
__cdecl
Chord(
      HDC  hdc  ,
      int  x1   ,
      int  y1   ,
      int  x2   ,
      int  y2   ,
      int  x3   ,
      int  y3   ,
      int  x4   ,
      int  y4   );

*/
void EmuApi::EmuChord(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x1);

    int y1{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y1);

    int x2{};
    uc_reg_read(uc, UC_X86_REG_R9D, &x2);

    int y2{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &y2, sizeof(y2));

    int x3{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &x3, sizeof(x3));

    int y3{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &y3, sizeof(y3));

    int x4{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &x4, sizeof(x4));

    int y4{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &y4, sizeof(y4));


    BOOL ChordResult = Chord((HDC)hdc,(int)x1,(int)y1,(int)x2,(int)y2,(int)x3,(int)y3,(int)x4,(int)y4);


    uc_reg_write(uc, UC_X86_REG_EAX, &ChordResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x1);
    uc_reg_write(uc, UC_X86_REG_R8D, &y1);
    uc_reg_write(uc, UC_X86_REG_R9D, &x2);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &y2, sizeof(y2));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &x3, sizeof(x3));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &y3, sizeof(y3));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &x4, sizeof(x4));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &y4, sizeof(y4));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuChord\n";
    #endif

    return;
}


/*
int
__cdecl
ChoosePixelFormat(
      HDC                            hdc   ,
      const PIXELFORMATDESCRIPTOR *  ppfd  );

*/
void EmuApi::EmuChoosePixelFormat(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PIXELFORMATDESCRIPTOR ppfd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ppfd);


    int ChoosePixelFormatResult = ChoosePixelFormat((HDC)hdc,(const PIXELFORMATDESCRIPTOR *)&ppfd);


    uc_reg_write(uc, UC_X86_REG_EAX, &ChoosePixelFormatResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &ppfd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuChoosePixelFormat\n";
    #endif

    return;
}


/*
HMETAFILE
__cdecl
CloseMetaFile(
      HDC  hdc  );

*/
void EmuApi::EmuCloseMetaFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    HMETAFILE CloseMetaFileResult = CloseMetaFile((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_RAX, &CloseMetaFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseMetaFile\n";
    #endif

    return;
}


/*
int
__cdecl
CombineRgn(
      HRGN  hrgnDst   ,
      HRGN  hrgnSrc1  ,
      HRGN  hrgnSrc2  ,
      int   iMode     );

*/
void EmuApi::EmuCombineRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HRGN hrgnDst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hrgnDst);

    HRGN hrgnSrc1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgnSrc1);

    HRGN hrgnSrc2{};
    uc_reg_read(uc, UC_X86_REG_R8, &hrgnSrc2);

    int iMode{};
    uc_reg_read(uc, UC_X86_REG_R9D, &iMode);


    int CombineRgnResult = CombineRgn((HRGN)hrgnDst,(HRGN)hrgnSrc1,(HRGN)hrgnSrc2,(int)iMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &CombineRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hrgnDst);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgnSrc1);
    uc_reg_write(uc, UC_X86_REG_R8, &hrgnSrc2);
    uc_reg_write(uc, UC_X86_REG_R9D, &iMode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCombineRgn\n";
    #endif

    return;
}


/*
HMETAFILE
__cdecl
CopyMetaFileA(
      HMETAFILE  namelessArg_0  ,
      LPCSTR     namelessArg_1  );

*/
void EmuApi::EmuCopyMetaFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMETAFILE namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    LPSTR namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    std::string rlanamelessArg_1;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)namelessArg_1, rlanamelessArg_1)) { printf("Error when read namelessArg_1 in CopyMetaFileA"); _CrtDbgBreak(); }


    HMETAFILE CopyMetaFileAResult = CopyMetaFileA((HMETAFILE)namelessArg_0,(LPCSTR)rlanamelessArg_1.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CopyMetaFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)namelessArg_1, rlanamelessArg_1)) { printf("Error when read namelessArg_1 in CopyMetaFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyMetaFileA\n";
    #endif

    return;
}


/*
HMETAFILE
__cdecl
CopyMetaFileW(
      HMETAFILE  namelessArg_0  ,
      LPCWSTR    namelessArg_1  );

*/
void EmuApi::EmuCopyMetaFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMETAFILE namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    LPWSTR namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    std::wstring rlwnamelessArg_1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_1, rlwnamelessArg_1)) { printf("Error when read namelessArg_1 in CopyMetaFileW"); _CrtDbgBreak(); }


    HMETAFILE CopyMetaFileWResult = CopyMetaFileW((HMETAFILE)namelessArg_0,(LPCWSTR)rlwnamelessArg_1.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CopyMetaFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_1, rlwnamelessArg_1)) { printf("Error when read namelessArg_1 in CopyMetaFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyMetaFileW\n";
    #endif

    return;
}


/*
HBITMAP
__cdecl
CreateBitmap(
      int           nWidth     ,
      int           nHeight    ,
      UINT          nPlanes    ,
      UINT          nBitCount  ,
      const void *  lpBits     );

*/
void EmuApi::EmuCreateBitmap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nWidth{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nWidth);

    int nHeight{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nHeight);

    UINT nPlanes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nPlanes);

    UINT nBitCount{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nBitCount);

    PVOID lpBits{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpBits, sizeof(lpBits));


    HBITMAP CreateBitmapResult = CreateBitmap((int)nWidth,(int)nHeight,(UINT)nPlanes,(UINT)nBitCount,(const void *)&lpBits);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateBitmapResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nWidth);
    uc_reg_write(uc, UC_X86_REG_EDX, &nHeight);
    uc_reg_write(uc, UC_X86_REG_R8D, &nPlanes);
    uc_reg_write(uc, UC_X86_REG_R9D, &nBitCount);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpBits, sizeof(lpBits));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateBitmap\n";
    #endif

    return;
}


/*
HBITMAP
__cdecl
CreateBitmapIndirect(
      const BITMAP *  pbm  );

*/
void EmuApi::EmuCreateBitmapIndirect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBITMAP pbm{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pbm);

    BITMAP stpbm{};

    if(pbm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbm, &stpbm, sizeof(stpbm));
    }


    HBITMAP CreateBitmapIndirectResult = CreateBitmapIndirect((const BITMAP *)&stpbm);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateBitmapIndirectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pbm);

    if(pbm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbm, &stpbm, sizeof(stpbm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateBitmapIndirect\n";
    #endif

    return;
}


/*
HBRUSH
__cdecl
CreateBrushIndirect(
      const LOGBRUSH *  plbrush  );

*/
void EmuApi::EmuCreateBrushIndirect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PLOGBRUSH plbrush{};
    uc_reg_read(uc, UC_X86_REG_RCX, &plbrush);

    LOGBRUSH stplbrush{};

    if(plbrush != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)plbrush, &stplbrush, sizeof(stplbrush));
    }


    HBRUSH CreateBrushIndirectResult = CreateBrushIndirect((const LOGBRUSH *)&stplbrush);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateBrushIndirectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &plbrush);

    if(plbrush != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)plbrush, &stplbrush, sizeof(stplbrush));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateBrushIndirect\n";
    #endif

    return;
}


/*
HBITMAP
__cdecl
CreateCompatibleBitmap(
      HDC  hdc  ,
      int  cx   ,
      int  cy   );

*/
void EmuApi::EmuCreateCompatibleBitmap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int cx{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cx);

    int cy{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cy);


    HBITMAP CreateCompatibleBitmapResult = CreateCompatibleBitmap((HDC)hdc,(int)cx,(int)cy);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateCompatibleBitmapResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &cx);
    uc_reg_write(uc, UC_X86_REG_R8D, &cy);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateCompatibleBitmap\n";
    #endif

    return;
}


/*
HBITMAP
__cdecl
CreateDiscardableBitmap(
      HDC  hdc  ,
      int  cx   ,
      int  cy   );

*/
void EmuApi::EmuCreateDiscardableBitmap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int cx{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cx);

    int cy{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cy);


    HBITMAP CreateDiscardableBitmapResult = CreateDiscardableBitmap((HDC)hdc,(int)cx,(int)cy);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDiscardableBitmapResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &cx);
    uc_reg_write(uc, UC_X86_REG_R8D, &cy);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDiscardableBitmap\n";
    #endif

    return;
}


/*
HDC
__cdecl
CreateCompatibleDC(
      HDC  hdc  );

*/
void EmuApi::EmuCreateCompatibleDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    HDC CreateCompatibleDCResult = CreateCompatibleDC((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateCompatibleDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateCompatibleDC\n";
    #endif

    return;
}


/*
HDC
__cdecl
CreateDCA(
      LPCSTR            pwszDriver  ,
      LPCSTR            pwszDevice  ,
      LPCSTR            pszPort     ,
      const DEVMODEA *  pdm         );

*/
void EmuApi::EmuCreateDCA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pwszDriver{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pwszDriver);

    std::string rlapwszDriver;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pwszDriver, rlapwszDriver)) { printf("Error when read pwszDriver in CreateDCA"); _CrtDbgBreak(); }

    LPSTR pwszDevice{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pwszDevice);

    std::string rlapwszDevice;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pwszDevice, rlapwszDevice)) { printf("Error when read pwszDevice in CreateDCA"); _CrtDbgBreak(); }

    LPSTR pszPort{};
    uc_reg_read(uc, UC_X86_REG_R8, &pszPort);

    std::string rlapszPort;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszPort, rlapszPort)) { printf("Error when read pszPort in CreateDCA"); _CrtDbgBreak(); }

    PDEVMODEA pdm{};
    uc_reg_read(uc, UC_X86_REG_R9, &pdm);

    DEVMODEA stpdm{};

    if(pdm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdm, &stpdm, sizeof(stpdm));
    }


    HDC CreateDCAResult = CreateDCA((LPCSTR)rlapwszDriver.data(),(LPCSTR)rlapwszDevice.data(),(LPCSTR)rlapszPort.data(),(const DEVMODEA *)&stpdm);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDCAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pwszDriver, rlapwszDriver)) { printf("Error when read pwszDriver in CreateDCA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pwszDevice, rlapwszDevice)) { printf("Error when read pwszDevice in CreateDCA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszPort, rlapszPort)) { printf("Error when read pszPort in CreateDCA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &pdm);

    if(pdm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdm, &stpdm, sizeof(stpdm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDCA\n";
    #endif

    return;
}


/*
HDC
__cdecl
CreateDCW(
      LPCWSTR           pwszDriver  ,
      LPCWSTR           pwszDevice  ,
      LPCWSTR           pszPort     ,
      const DEVMODEW *  pdm         );

*/
void EmuApi::EmuCreateDCW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pwszDriver{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pwszDriver);

    std::wstring rlwpwszDriver;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszDriver, rlwpwszDriver)) { printf("Error when read pwszDriver in CreateDCW"); _CrtDbgBreak(); }

    LPWSTR pwszDevice{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pwszDevice);

    std::wstring rlwpwszDevice;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszDevice, rlwpwszDevice)) { printf("Error when read pwszDevice in CreateDCW"); _CrtDbgBreak(); }

    LPWSTR pszPort{};
    uc_reg_read(uc, UC_X86_REG_R8, &pszPort);

    std::wstring rlwpszPort;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszPort, rlwpszPort)) { printf("Error when read pszPort in CreateDCW"); _CrtDbgBreak(); }

    PDEVMODEW pdm{};
    uc_reg_read(uc, UC_X86_REG_R9, &pdm);

    DEVMODEW stpdm{};

    if(pdm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdm, &stpdm, sizeof(stpdm));
    }


    HDC CreateDCWResult = CreateDCW((LPCWSTR)rlwpwszDriver.data(),(LPCWSTR)rlwpwszDevice.data(),(LPCWSTR)rlwpszPort.data(),(const DEVMODEW *)&stpdm);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDCWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszDriver, rlwpwszDriver)) { printf("Error when read pwszDriver in CreateDCW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszDevice, rlwpwszDevice)) { printf("Error when read pwszDevice in CreateDCW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszPort, rlwpszPort)) { printf("Error when read pszPort in CreateDCW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &pdm);

    if(pdm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdm, &stpdm, sizeof(stpdm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDCW\n";
    #endif

    return;
}


/*
HBITMAP
__cdecl
CreateDIBitmap(
      HDC                       hdc     ,
      const BITMAPINFOHEADER *  pbmih   ,
      DWORD                     flInit  ,
      const void *              pjBits  ,
      const BITMAPINFO *        pbmi    ,
      UINT                      iUsage  );

*/
void EmuApi::EmuCreateDIBitmap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PBITMAPINFOHEADER pbmih{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pbmih);

    BITMAPINFOHEADER stpbmih{};

    if(pbmih != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbmih, &stpbmih, sizeof(stpbmih));
    }

    DWORD flInit{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flInit);

    PVOID pjBits{};
    uc_reg_read(uc, UC_X86_REG_R9, &pjBits);

    PBITMAPINFO pbmi{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pbmi, sizeof(pbmi));

    BITMAPINFO stpbmi{};

    if(pbmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbmi, &stpbmi, sizeof(stpbmi));
    }

    UINT iUsage{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &iUsage, sizeof(iUsage));


    HBITMAP CreateDIBitmapResult = CreateDIBitmap((HDC)hdc,(const BITMAPINFOHEADER *)&stpbmih,(DWORD)flInit,(const void *)&pjBits,(const BITMAPINFO *)&stpbmi,(UINT)iUsage);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDIBitmapResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &pbmih);

    if(pbmih != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbmih, &stpbmih, sizeof(stpbmih));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &flInit);
    uc_reg_write(uc, UC_X86_REG_R9, &pjBits);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pbmi, sizeof(pbmi));

    if(pbmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbmi, &stpbmi, sizeof(stpbmi));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &iUsage, sizeof(iUsage));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDIBitmap\n";
    #endif

    return;
}


/*
HBRUSH
__cdecl
CreateDIBPatternBrush(
      HGLOBAL  h       ,
      UINT     iUsage  );

*/
void EmuApi::EmuCreateDIBPatternBrush(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL h{};
    uc_reg_read(uc, UC_X86_REG_RCX, &h);

    UINT iUsage{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iUsage);


    HBRUSH CreateDIBPatternBrushResult = CreateDIBPatternBrush((HGLOBAL)h,(UINT)iUsage);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDIBPatternBrushResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &h);
    uc_reg_write(uc, UC_X86_REG_EDX, &iUsage);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDIBPatternBrush\n";
    #endif

    return;
}


/*
HBRUSH
__cdecl
CreateDIBPatternBrushPt(
      const void *  lpPackedDIB  ,
      UINT          iUsage       );

*/
void EmuApi::EmuCreateDIBPatternBrushPt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID lpPackedDIB{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPackedDIB);

    UINT iUsage{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iUsage);


    HBRUSH CreateDIBPatternBrushPtResult = CreateDIBPatternBrushPt((const void *)&lpPackedDIB,(UINT)iUsage);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDIBPatternBrushPtResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpPackedDIB);
    uc_reg_write(uc, UC_X86_REG_EDX, &iUsage);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDIBPatternBrushPt\n";
    #endif

    return;
}


/*
HRGN
__cdecl
CreateEllipticRgn(
      int  x1  ,
      int  y1  ,
      int  x2  ,
      int  y2  );

*/
void EmuApi::EmuCreateEllipticRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int x1{};
    uc_reg_read(uc, UC_X86_REG_ECX, &x1);

    int y1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &y1);

    int x2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &x2);

    int y2{};
    uc_reg_read(uc, UC_X86_REG_R9D, &y2);


    HRGN CreateEllipticRgnResult = CreateEllipticRgn((int)x1,(int)y1,(int)x2,(int)y2);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateEllipticRgnResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &x1);
    uc_reg_write(uc, UC_X86_REG_EDX, &y1);
    uc_reg_write(uc, UC_X86_REG_R8D, &x2);
    uc_reg_write(uc, UC_X86_REG_R9D, &y2);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateEllipticRgn\n";
    #endif

    return;
}


/*
HRGN
__cdecl
CreateEllipticRgnIndirect(
      const RECT *  lprect  );

*/
void EmuApi::EmuCreateEllipticRgnIndirect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRECT lprect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprect);

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }


    HRGN CreateEllipticRgnIndirectResult = CreateEllipticRgnIndirect((const RECT *)&stlprect);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateEllipticRgnIndirectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprect);

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateEllipticRgnIndirect\n";
    #endif

    return;
}


/*
HFONT
__cdecl
CreateFontIndirectA(
      const LOGFONTA *  lplf  );

*/
void EmuApi::EmuCreateFontIndirectA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PLOGFONTA lplf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lplf);

    LOGFONTA stlplf{};

    if(lplf != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lplf, &stlplf, sizeof(stlplf));
    }


    HFONT CreateFontIndirectAResult = CreateFontIndirectA((const LOGFONTA *)&stlplf);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFontIndirectAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lplf);

    if(lplf != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lplf, &stlplf, sizeof(stlplf));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFontIndirectA\n";
    #endif

    return;
}


/*
HFONT
__cdecl
CreateFontIndirectW(
      const LOGFONTW *  lplf  );

*/
void EmuApi::EmuCreateFontIndirectW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PLOGFONTW lplf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lplf);

    LOGFONTW stlplf{};

    if(lplf != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lplf, &stlplf, sizeof(stlplf));
    }


    HFONT CreateFontIndirectWResult = CreateFontIndirectW((const LOGFONTW *)&stlplf);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFontIndirectWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lplf);

    if(lplf != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lplf, &stlplf, sizeof(stlplf));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFontIndirectW\n";
    #endif

    return;
}


/*
HFONT
__cdecl
CreateFontA(
      int     cHeight          ,
      int     cWidth           ,
      int     cEscapement      ,
      int     cOrientation     ,
      int     cWeight          ,
      DWORD   bItalic          ,
      DWORD   bUnderline       ,
      DWORD   bStrikeOut       ,
      DWORD   iCharSet         ,
      DWORD   iOutPrecision    ,
      DWORD   iClipPrecision   ,
      DWORD   iQuality         ,
      DWORD   iPitchAndFamily  ,
      LPCSTR  pszFaceName      );

*/
void EmuApi::EmuCreateFontA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int cHeight{};
    uc_reg_read(uc, UC_X86_REG_ECX, &cHeight);

    int cWidth{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cWidth);

    int cEscapement{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cEscapement);

    int cOrientation{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cOrientation);

    int cWeight{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cWeight, sizeof(cWeight));

    DWORD bItalic{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &bItalic, sizeof(bItalic));

    DWORD bUnderline{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &bUnderline, sizeof(bUnderline));

    DWORD bStrikeOut{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &bStrikeOut, sizeof(bStrikeOut));

    DWORD iCharSet{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &iCharSet, sizeof(iCharSet));

    DWORD iOutPrecision{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &iOutPrecision, sizeof(iOutPrecision));

    DWORD iClipPrecision{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &iClipPrecision, sizeof(iClipPrecision));

    DWORD iQuality{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &iQuality, sizeof(iQuality));

    DWORD iPitchAndFamily{};
    uc_mem_read(uc, (DWORD_PTR)SP+104, &iPitchAndFamily, sizeof(iPitchAndFamily));

    LPSTR pszFaceName{};
    uc_mem_read(uc, (DWORD_PTR)SP+112, &pszFaceName, sizeof(pszFaceName));

    std::string rlapszFaceName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszFaceName, rlapszFaceName)) { printf("Error when read pszFaceName in CreateFontA"); _CrtDbgBreak(); }


    HFONT CreateFontAResult = CreateFontA((int)cHeight,(int)cWidth,(int)cEscapement,(int)cOrientation,(int)cWeight,(DWORD)bItalic,(DWORD)bUnderline,(DWORD)bStrikeOut,(DWORD)iCharSet,(DWORD)iOutPrecision,(DWORD)iClipPrecision,(DWORD)iQuality,(DWORD)iPitchAndFamily,(LPCSTR)rlapszFaceName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFontAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &cHeight);
    uc_reg_write(uc, UC_X86_REG_EDX, &cWidth);
    uc_reg_write(uc, UC_X86_REG_R8D, &cEscapement);
    uc_reg_write(uc, UC_X86_REG_R9D, &cOrientation);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cWeight, sizeof(cWeight));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &bItalic, sizeof(bItalic));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &bUnderline, sizeof(bUnderline));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &bStrikeOut, sizeof(bStrikeOut));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &iCharSet, sizeof(iCharSet));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &iOutPrecision, sizeof(iOutPrecision));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &iClipPrecision, sizeof(iClipPrecision));
    uc_mem_write(uc, (DWORD_PTR)SP+96, &iQuality, sizeof(iQuality));
    uc_mem_write(uc, (DWORD_PTR)SP+104, &iPitchAndFamily, sizeof(iPitchAndFamily));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszFaceName, rlapszFaceName)) { printf("Error when read pszFaceName in CreateFontA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFontA\n";
    #endif

    return;
}


/*
HFONT
__cdecl
CreateFontW(
      int      cHeight          ,
      int      cWidth           ,
      int      cEscapement      ,
      int      cOrientation     ,
      int      cWeight          ,
      DWORD    bItalic          ,
      DWORD    bUnderline       ,
      DWORD    bStrikeOut       ,
      DWORD    iCharSet         ,
      DWORD    iOutPrecision    ,
      DWORD    iClipPrecision   ,
      DWORD    iQuality         ,
      DWORD    iPitchAndFamily  ,
      LPCWSTR  pszFaceName      );

*/
void EmuApi::EmuCreateFontW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int cHeight{};
    uc_reg_read(uc, UC_X86_REG_ECX, &cHeight);

    int cWidth{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cWidth);

    int cEscapement{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cEscapement);

    int cOrientation{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cOrientation);

    int cWeight{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cWeight, sizeof(cWeight));

    DWORD bItalic{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &bItalic, sizeof(bItalic));

    DWORD bUnderline{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &bUnderline, sizeof(bUnderline));

    DWORD bStrikeOut{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &bStrikeOut, sizeof(bStrikeOut));

    DWORD iCharSet{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &iCharSet, sizeof(iCharSet));

    DWORD iOutPrecision{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &iOutPrecision, sizeof(iOutPrecision));

    DWORD iClipPrecision{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &iClipPrecision, sizeof(iClipPrecision));

    DWORD iQuality{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &iQuality, sizeof(iQuality));

    DWORD iPitchAndFamily{};
    uc_mem_read(uc, (DWORD_PTR)SP+104, &iPitchAndFamily, sizeof(iPitchAndFamily));

    LPWSTR pszFaceName{};
    uc_mem_read(uc, (DWORD_PTR)SP+112, &pszFaceName, sizeof(pszFaceName));

    std::wstring rlwpszFaceName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszFaceName, rlwpszFaceName)) { printf("Error when read pszFaceName in CreateFontW"); _CrtDbgBreak(); }


    HFONT CreateFontWResult = CreateFontW((int)cHeight,(int)cWidth,(int)cEscapement,(int)cOrientation,(int)cWeight,(DWORD)bItalic,(DWORD)bUnderline,(DWORD)bStrikeOut,(DWORD)iCharSet,(DWORD)iOutPrecision,(DWORD)iClipPrecision,(DWORD)iQuality,(DWORD)iPitchAndFamily,(LPCWSTR)rlwpszFaceName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFontWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &cHeight);
    uc_reg_write(uc, UC_X86_REG_EDX, &cWidth);
    uc_reg_write(uc, UC_X86_REG_R8D, &cEscapement);
    uc_reg_write(uc, UC_X86_REG_R9D, &cOrientation);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cWeight, sizeof(cWeight));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &bItalic, sizeof(bItalic));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &bUnderline, sizeof(bUnderline));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &bStrikeOut, sizeof(bStrikeOut));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &iCharSet, sizeof(iCharSet));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &iOutPrecision, sizeof(iOutPrecision));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &iClipPrecision, sizeof(iClipPrecision));
    uc_mem_write(uc, (DWORD_PTR)SP+96, &iQuality, sizeof(iQuality));
    uc_mem_write(uc, (DWORD_PTR)SP+104, &iPitchAndFamily, sizeof(iPitchAndFamily));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszFaceName, rlwpszFaceName)) { printf("Error when read pszFaceName in CreateFontW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFontW\n";
    #endif

    return;
}


/*
HBRUSH
__cdecl
CreateHatchBrush(
      int       iHatch  ,
      COLORREF  color   );

*/
void EmuApi::EmuCreateHatchBrush(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int iHatch{};
    uc_reg_read(uc, UC_X86_REG_ECX, &iHatch);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_EDX, &color);


    HBRUSH CreateHatchBrushResult = CreateHatchBrush((int)iHatch,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateHatchBrushResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &iHatch);
    uc_reg_write(uc, UC_X86_REG_EDX, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateHatchBrush\n";
    #endif

    return;
}


/*
HDC
__cdecl
CreateICA(
      LPCSTR            pszDriver  ,
      LPCSTR            pszDevice  ,
      LPCSTR            pszPort    ,
      const DEVMODEA *  pdm        );

*/
void EmuApi::EmuCreateICA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pszDriver{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pszDriver);

    std::string rlapszDriver;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszDriver, rlapszDriver)) { printf("Error when read pszDriver in CreateICA"); _CrtDbgBreak(); }

    LPSTR pszDevice{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pszDevice);

    std::string rlapszDevice;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszDevice, rlapszDevice)) { printf("Error when read pszDevice in CreateICA"); _CrtDbgBreak(); }

    LPSTR pszPort{};
    uc_reg_read(uc, UC_X86_REG_R8, &pszPort);

    std::string rlapszPort;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszPort, rlapszPort)) { printf("Error when read pszPort in CreateICA"); _CrtDbgBreak(); }

    PDEVMODEA pdm{};
    uc_reg_read(uc, UC_X86_REG_R9, &pdm);

    DEVMODEA stpdm{};

    if(pdm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdm, &stpdm, sizeof(stpdm));
    }


    HDC CreateICAResult = CreateICA((LPCSTR)rlapszDriver.data(),(LPCSTR)rlapszDevice.data(),(LPCSTR)rlapszPort.data(),(const DEVMODEA *)&stpdm);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateICAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszDriver, rlapszDriver)) { printf("Error when read pszDriver in CreateICA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszDevice, rlapszDevice)) { printf("Error when read pszDevice in CreateICA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszPort, rlapszPort)) { printf("Error when read pszPort in CreateICA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &pdm);

    if(pdm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdm, &stpdm, sizeof(stpdm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateICA\n";
    #endif

    return;
}


/*
HDC
__cdecl
CreateICW(
      LPCWSTR           pszDriver  ,
      LPCWSTR           pszDevice  ,
      LPCWSTR           pszPort    ,
      const DEVMODEW *  pdm        );

*/
void EmuApi::EmuCreateICW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pszDriver{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pszDriver);

    std::wstring rlwpszDriver;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszDriver, rlwpszDriver)) { printf("Error when read pszDriver in CreateICW"); _CrtDbgBreak(); }

    LPWSTR pszDevice{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pszDevice);

    std::wstring rlwpszDevice;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszDevice, rlwpszDevice)) { printf("Error when read pszDevice in CreateICW"); _CrtDbgBreak(); }

    LPWSTR pszPort{};
    uc_reg_read(uc, UC_X86_REG_R8, &pszPort);

    std::wstring rlwpszPort;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszPort, rlwpszPort)) { printf("Error when read pszPort in CreateICW"); _CrtDbgBreak(); }

    PDEVMODEW pdm{};
    uc_reg_read(uc, UC_X86_REG_R9, &pdm);

    DEVMODEW stpdm{};

    if(pdm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdm, &stpdm, sizeof(stpdm));
    }


    HDC CreateICWResult = CreateICW((LPCWSTR)rlwpszDriver.data(),(LPCWSTR)rlwpszDevice.data(),(LPCWSTR)rlwpszPort.data(),(const DEVMODEW *)&stpdm);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateICWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszDriver, rlwpszDriver)) { printf("Error when read pszDriver in CreateICW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszDevice, rlwpszDevice)) { printf("Error when read pszDevice in CreateICW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszPort, rlwpszPort)) { printf("Error when read pszPort in CreateICW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &pdm);

    if(pdm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdm, &stpdm, sizeof(stpdm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateICW\n";
    #endif

    return;
}


/*
HDC
__cdecl
CreateMetaFileA(
      LPCSTR  pszFile  );

*/
void EmuApi::EmuCreateMetaFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pszFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pszFile);

    std::string rlapszFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszFile, rlapszFile)) { printf("Error when read pszFile in CreateMetaFileA"); _CrtDbgBreak(); }


    HDC CreateMetaFileAResult = CreateMetaFileA((LPCSTR)rlapszFile.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMetaFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszFile, rlapszFile)) { printf("Error when read pszFile in CreateMetaFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMetaFileA\n";
    #endif

    return;
}


/*
HDC
__cdecl
CreateMetaFileW(
      LPCWSTR  pszFile  );

*/
void EmuApi::EmuCreateMetaFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pszFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pszFile);

    std::wstring rlwpszFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszFile, rlwpszFile)) { printf("Error when read pszFile in CreateMetaFileW"); _CrtDbgBreak(); }


    HDC CreateMetaFileWResult = CreateMetaFileW((LPCWSTR)rlwpszFile.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMetaFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszFile, rlwpszFile)) { printf("Error when read pszFile in CreateMetaFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMetaFileW\n";
    #endif

    return;
}


/*
HPALETTE
__cdecl
CreatePalette(
      const LOGPALETTE *  plpal  );

*/
void EmuApi::EmuCreatePalette(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PLOGPALETTE plpal{};
    uc_reg_read(uc, UC_X86_REG_RCX, &plpal);

    LOGPALETTE stplpal{};

    if(plpal != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)plpal, &stplpal, sizeof(stplpal));
    }


    HPALETTE CreatePaletteResult = CreatePalette((const LOGPALETTE *)&stplpal);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreatePaletteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &plpal);

    if(plpal != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)plpal, &stplpal, sizeof(stplpal));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreatePalette\n";
    #endif

    return;
}


/*
HPEN
__cdecl
CreatePen(
      int       iStyle  ,
      int       cWidth  ,
      COLORREF  color   );

*/
void EmuApi::EmuCreatePen(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int iStyle{};
    uc_reg_read(uc, UC_X86_REG_ECX, &iStyle);

    int cWidth{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cWidth);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_R8D, &color);


    HPEN CreatePenResult = CreatePen((int)iStyle,(int)cWidth,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreatePenResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &iStyle);
    uc_reg_write(uc, UC_X86_REG_EDX, &cWidth);
    uc_reg_write(uc, UC_X86_REG_R8D, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreatePen\n";
    #endif

    return;
}


/*
HPEN
__cdecl
CreatePenIndirect(
      const LOGPEN *  plpen  );

*/
void EmuApi::EmuCreatePenIndirect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PLOGPEN plpen{};
    uc_reg_read(uc, UC_X86_REG_RCX, &plpen);

    LOGPEN stplpen{};

    if(plpen != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)plpen, &stplpen, sizeof(stplpen));
    }


    HPEN CreatePenIndirectResult = CreatePenIndirect((const LOGPEN *)&stplpen);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreatePenIndirectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &plpen);

    if(plpen != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)plpen, &stplpen, sizeof(stplpen));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreatePenIndirect\n";
    #endif

    return;
}


/*
HRGN
__cdecl
CreatePolyPolygonRgn(
      const POINT *  pptl   ,
      const INT *    pc     ,
      int            cPoly  ,
      int            iMode  );

*/
void EmuApi::EmuCreatePolyPolygonRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    POINT pptl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pptl);

    PINT pc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pc);

    int rlpc{};

    if(pc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pc, &rlpc, sizeof(rlpc));
    }

    int cPoly{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cPoly);

    int iMode{};
    uc_reg_read(uc, UC_X86_REG_R9D, &iMode);


    HRGN CreatePolyPolygonRgnResult = CreatePolyPolygonRgn((const POINT *)&pptl,(const INT *)&rlpc,(int)cPoly,(int)iMode);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreatePolyPolygonRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pptl);
    uc_reg_write(uc, UC_X86_REG_RDX, &pc);

    if(pc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pc, &rlpc, sizeof(rlpc));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &cPoly);
    uc_reg_write(uc, UC_X86_REG_R9D, &iMode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreatePolyPolygonRgn\n";
    #endif

    return;
}


/*
HBRUSH
__cdecl
CreatePatternBrush(
      HBITMAP  hbm  );

*/
void EmuApi::EmuCreatePatternBrush(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HBITMAP hbm{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hbm);


    HBRUSH CreatePatternBrushResult = CreatePatternBrush((HBITMAP)hbm);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreatePatternBrushResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hbm);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreatePatternBrush\n";
    #endif

    return;
}


/*
HRGN
__cdecl
CreateRectRgn(
      int  x1  ,
      int  y1  ,
      int  x2  ,
      int  y2  );

*/
void EmuApi::EmuCreateRectRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int x1{};
    uc_reg_read(uc, UC_X86_REG_ECX, &x1);

    int y1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &y1);

    int x2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &x2);

    int y2{};
    uc_reg_read(uc, UC_X86_REG_R9D, &y2);


    HRGN CreateRectRgnResult = CreateRectRgn((int)x1,(int)y1,(int)x2,(int)y2);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateRectRgnResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &x1);
    uc_reg_write(uc, UC_X86_REG_EDX, &y1);
    uc_reg_write(uc, UC_X86_REG_R8D, &x2);
    uc_reg_write(uc, UC_X86_REG_R9D, &y2);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateRectRgn\n";
    #endif

    return;
}


/*
HRGN
__cdecl
CreateRectRgnIndirect(
      const RECT *  lprect  );

*/
void EmuApi::EmuCreateRectRgnIndirect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRECT lprect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprect);

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }


    HRGN CreateRectRgnIndirectResult = CreateRectRgnIndirect((const RECT *)&stlprect);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateRectRgnIndirectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprect);

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateRectRgnIndirect\n";
    #endif

    return;
}


/*
HRGN
__cdecl
CreateRoundRectRgn(
      int  x1  ,
      int  y1  ,
      int  x2  ,
      int  y2  ,
      int  w   ,
      int  h   );

*/
void EmuApi::EmuCreateRoundRectRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int x1{};
    uc_reg_read(uc, UC_X86_REG_ECX, &x1);

    int y1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &y1);

    int x2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &x2);

    int y2{};
    uc_reg_read(uc, UC_X86_REG_R9D, &y2);

    int w{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &w, sizeof(w));

    int h{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &h, sizeof(h));


    HRGN CreateRoundRectRgnResult = CreateRoundRectRgn((int)x1,(int)y1,(int)x2,(int)y2,(int)w,(int)h);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateRoundRectRgnResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &x1);
    uc_reg_write(uc, UC_X86_REG_EDX, &y1);
    uc_reg_write(uc, UC_X86_REG_R8D, &x2);
    uc_reg_write(uc, UC_X86_REG_R9D, &y2);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &w, sizeof(w));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &h, sizeof(h));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateRoundRectRgn\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateScalableFontResourceA(
      DWORD   fdwHidden  ,
      LPCSTR  lpszFont   ,
      LPCSTR  lpszFile   ,
      LPCSTR  lpszPath   );

*/
void EmuApi::EmuCreateScalableFontResourceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD fdwHidden{};
    uc_reg_read(uc, UC_X86_REG_ECX, &fdwHidden);

    LPSTR lpszFont{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFont);

    std::string rlalpszFont;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFont, rlalpszFont)) { printf("Error when read lpszFont in CreateScalableFontResourceA"); _CrtDbgBreak(); }

    LPSTR lpszFile{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszFile);

    std::string rlalpszFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFile, rlalpszFile)) { printf("Error when read lpszFile in CreateScalableFontResourceA"); _CrtDbgBreak(); }

    LPSTR lpszPath{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszPath);

    std::string rlalpszPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszPath, rlalpszPath)) { printf("Error when read lpszPath in CreateScalableFontResourceA"); _CrtDbgBreak(); }


    BOOL CreateScalableFontResourceAResult = CreateScalableFontResourceA((DWORD)fdwHidden,(LPCSTR)rlalpszFont.data(),(LPCSTR)rlalpszFile.data(),(LPCSTR)rlalpszPath.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateScalableFontResourceAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &fdwHidden);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFont, rlalpszFont)) { printf("Error when read lpszFont in CreateScalableFontResourceA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFile, rlalpszFile)) { printf("Error when read lpszFile in CreateScalableFontResourceA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszPath, rlalpszPath)) { printf("Error when read lpszPath in CreateScalableFontResourceA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateScalableFontResourceA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateScalableFontResourceW(
      DWORD    fdwHidden  ,
      LPCWSTR  lpszFont   ,
      LPCWSTR  lpszFile   ,
      LPCWSTR  lpszPath   );

*/
void EmuApi::EmuCreateScalableFontResourceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD fdwHidden{};
    uc_reg_read(uc, UC_X86_REG_ECX, &fdwHidden);

    LPWSTR lpszFont{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFont);

    std::wstring rlwlpszFont;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFont, rlwlpszFont)) { printf("Error when read lpszFont in CreateScalableFontResourceW"); _CrtDbgBreak(); }

    LPWSTR lpszFile{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszFile);

    std::wstring rlwlpszFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFile, rlwlpszFile)) { printf("Error when read lpszFile in CreateScalableFontResourceW"); _CrtDbgBreak(); }

    LPWSTR lpszPath{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszPath);

    std::wstring rlwlpszPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszPath, rlwlpszPath)) { printf("Error when read lpszPath in CreateScalableFontResourceW"); _CrtDbgBreak(); }


    BOOL CreateScalableFontResourceWResult = CreateScalableFontResourceW((DWORD)fdwHidden,(LPCWSTR)rlwlpszFont.data(),(LPCWSTR)rlwlpszFile.data(),(LPCWSTR)rlwlpszPath.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateScalableFontResourceWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &fdwHidden);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFont, rlwlpszFont)) { printf("Error when read lpszFont in CreateScalableFontResourceW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFile, rlwlpszFile)) { printf("Error when read lpszFile in CreateScalableFontResourceW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszPath, rlwlpszPath)) { printf("Error when read lpszPath in CreateScalableFontResourceW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateScalableFontResourceW\n";
    #endif

    return;
}


/*
HBRUSH
__cdecl
CreateSolidBrush(
      COLORREF  color  );

*/
void EmuApi::EmuCreateSolidBrush(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_ECX, &color);


    HBRUSH CreateSolidBrushResult = CreateSolidBrush((COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateSolidBrushResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSolidBrush\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteDC(
      HDC  hdc  );

*/
void EmuApi::EmuDeleteDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL DeleteDCResult = DeleteDC((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteDC\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteMetaFile(
      HMETAFILE  hmf  );

*/
void EmuApi::EmuDeleteMetaFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMETAFILE hmf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hmf);


    BOOL DeleteMetaFileResult = DeleteMetaFile((HMETAFILE)hmf);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteMetaFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hmf);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteMetaFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteObject(
      HGDIOBJ  ho  );

*/
void EmuApi::EmuDeleteObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGDIOBJ ho{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ho);


    BOOL DeleteObjectResult = DeleteObject((HGDIOBJ)&ho);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteObjectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ho);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteObject\n";
    #endif

    return;
}


/*
int
__cdecl
DescribePixelFormat(
      HDC                      hdc           ,
      int                      iPixelFormat  ,
      UINT                     nBytes        ,
      LPPIXELFORMATDESCRIPTOR  ppfd          );

*/
void EmuApi::EmuDescribePixelFormat(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int iPixelFormat{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iPixelFormat);

    UINT nBytes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nBytes);

    LPPIXELFORMATDESCRIPTOR ppfd{};
    uc_reg_read(uc, UC_X86_REG_R9, &ppfd);

    PIXELFORMATDESCRIPTOR stppfd{};

    if(ppfd != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppfd, &stppfd, sizeof(stppfd));
    }


    int DescribePixelFormatResult = DescribePixelFormat((HDC)hdc,(int)iPixelFormat,(UINT)nBytes,(LPPIXELFORMATDESCRIPTOR)&stppfd);


    uc_reg_write(uc, UC_X86_REG_EAX, &DescribePixelFormatResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iPixelFormat);
    uc_reg_write(uc, UC_X86_REG_R8D, &nBytes);
    uc_reg_write(uc, UC_X86_REG_R9, &ppfd);

    if(ppfd != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ppfd, &stppfd, sizeof(stppfd));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDescribePixelFormat\n";
    #endif

    return;
}


/*
int
__cdecl
DeviceCapabilitiesA(
      LPCSTR            pDevice       ,
      LPCSTR            pPort         ,
      WORD              fwCapability  ,
      LPSTR             pOutput       ,
      const DEVMODEA *  pDevMode      );

*/
void EmuApi::EmuDeviceCapabilitiesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pDevice);

    std::string rlapDevice;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pDevice, rlapDevice)) { printf("Error when read pDevice in DeviceCapabilitiesA"); _CrtDbgBreak(); }

    LPSTR pPort{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pPort);

    std::string rlapPort;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pPort, rlapPort)) { printf("Error when read pPort in DeviceCapabilitiesA"); _CrtDbgBreak(); }

    WORD fwCapability{};
    uc_reg_read(uc, UC_X86_REG_R8W, &fwCapability);

    LPSTR pOutput{};
    uc_reg_read(uc, UC_X86_REG_R9, &pOutput);

    std::string rlapOutput;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pOutput, rlapOutput)) { printf("Error when read pOutput in DeviceCapabilitiesA"); _CrtDbgBreak(); }

    PDEVMODEA pDevMode{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pDevMode, sizeof(pDevMode));

    DEVMODEA stpDevMode{};

    if(pDevMode != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pDevMode, &stpDevMode, sizeof(stpDevMode));
    }


    int DeviceCapabilitiesAResult = DeviceCapabilitiesA((LPCSTR)rlapDevice.data(),(LPCSTR)rlapPort.data(),(WORD)fwCapability,(LPSTR)rlapOutput.data(),(const DEVMODEA *)&stpDevMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeviceCapabilitiesAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pDevice, rlapDevice)) { printf("Error when read pDevice in DeviceCapabilitiesA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pPort, rlapPort)) { printf("Error when read pPort in DeviceCapabilitiesA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8W, &fwCapability);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pOutput, rlapOutput)) { printf("Error when read pOutput in DeviceCapabilitiesA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pDevMode, sizeof(pDevMode));

    if(pDevMode != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pDevMode, &stpDevMode, sizeof(stpDevMode));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeviceCapabilitiesA\n";
    #endif

    return;
}


/*
int
__cdecl
DeviceCapabilitiesW(
      LPCWSTR           pDevice       ,
      LPCWSTR           pPort         ,
      WORD              fwCapability  ,
      LPWSTR            pOutput       ,
      const DEVMODEW *  pDevMode      );

*/
void EmuApi::EmuDeviceCapabilitiesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pDevice);

    std::wstring rlwpDevice;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pDevice, rlwpDevice)) { printf("Error when read pDevice in DeviceCapabilitiesW"); _CrtDbgBreak(); }

    LPWSTR pPort{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pPort);

    std::wstring rlwpPort;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pPort, rlwpPort)) { printf("Error when read pPort in DeviceCapabilitiesW"); _CrtDbgBreak(); }

    WORD fwCapability{};
    uc_reg_read(uc, UC_X86_REG_R8W, &fwCapability);

    LPWSTR pOutput{};
    uc_reg_read(uc, UC_X86_REG_R9, &pOutput);

    std::wstring rlwpOutput;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pOutput, rlwpOutput)) { printf("Error when read pOutput in DeviceCapabilitiesW"); _CrtDbgBreak(); }

    PDEVMODEW pDevMode{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pDevMode, sizeof(pDevMode));

    DEVMODEW stpDevMode{};

    if(pDevMode != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pDevMode, &stpDevMode, sizeof(stpDevMode));
    }


    int DeviceCapabilitiesWResult = DeviceCapabilitiesW((LPCWSTR)rlwpDevice.data(),(LPCWSTR)rlwpPort.data(),(WORD)fwCapability,(LPWSTR)rlwpOutput.data(),(const DEVMODEW *)&stpDevMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeviceCapabilitiesWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pDevice, rlwpDevice)) { printf("Error when read pDevice in DeviceCapabilitiesW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pPort, rlwpPort)) { printf("Error when read pPort in DeviceCapabilitiesW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8W, &fwCapability);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pOutput, rlwpOutput)) { printf("Error when read pOutput in DeviceCapabilitiesW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pDevMode, sizeof(pDevMode));

    if(pDevMode != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pDevMode, &stpDevMode, sizeof(stpDevMode));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeviceCapabilitiesW\n";
    #endif

    return;
}


/*
int
__cdecl
DrawEscape(
      HDC     hdc      ,
      int     iEscape  ,
      int     cjIn     ,
      LPCSTR  lpIn     );

*/
void EmuApi::EmuDrawEscape(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int iEscape{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iEscape);

    int cjIn{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cjIn);

    LPSTR lpIn{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpIn);

    std::string rlalpIn;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpIn, rlalpIn)) { printf("Error when read lpIn in DrawEscape"); _CrtDbgBreak(); }


    int DrawEscapeResult = DrawEscape((HDC)hdc,(int)iEscape,(int)cjIn,(LPCSTR)rlalpIn.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawEscapeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iEscape);
    uc_reg_write(uc, UC_X86_REG_R8D, &cjIn);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpIn, rlalpIn)) { printf("Error when read lpIn in DrawEscape"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawEscape\n";
    #endif

    return;
}


/*
BOOL
__cdecl
Ellipse(
      HDC  hdc     ,
      int  left    ,
      int  top     ,
      int  right   ,
      int  bottom  );

*/
void EmuApi::EmuEllipse(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int left{};
    uc_reg_read(uc, UC_X86_REG_EDX, &left);

    int top{};
    uc_reg_read(uc, UC_X86_REG_R8D, &top);

    int right{};
    uc_reg_read(uc, UC_X86_REG_R9D, &right);

    int bottom{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));


    BOOL EllipseResult = Ellipse((HDC)hdc,(int)left,(int)top,(int)right,(int)bottom);


    uc_reg_write(uc, UC_X86_REG_EAX, &EllipseResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &left);
    uc_reg_write(uc, UC_X86_REG_R8D, &top);
    uc_reg_write(uc, UC_X86_REG_R9D, &right);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEllipse\n";
    #endif

    return;
}


/*
int
__cdecl
EnumFontFamiliesExA(
      HDC            hdc        ,
      LPLOGFONTA     lpLogfont  ,
      FONTENUMPROCA  lpProc     ,
      LPARAM         lParam     ,
      DWORD          dwFlags    );

*/
void EmuApi::EmuEnumFontFamiliesExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPLOGFONTA lpLogfont{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpLogfont);

    LOGFONTA stlpLogfont{};

    if(lpLogfont != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLogfont, &stlpLogfont, sizeof(stlpLogfont));
    }

    FONTENUMPROCA lpProc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    int EnumFontFamiliesExAResult = EnumFontFamiliesExA((HDC)hdc,(LPLOGFONTA)&stlpLogfont,(FONTENUMPROCA)lpProc,(LPARAM)lParam,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumFontFamiliesExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpLogfont);

    if(lpLogfont != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLogfont, &stlpLogfont, sizeof(stlpLogfont));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumFontFamiliesExA\n";
    #endif

    return;
}


/*
int
__cdecl
EnumFontFamiliesExW(
      HDC            hdc        ,
      LPLOGFONTW     lpLogfont  ,
      FONTENUMPROCW  lpProc     ,
      LPARAM         lParam     ,
      DWORD          dwFlags    );

*/
void EmuApi::EmuEnumFontFamiliesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPLOGFONTW lpLogfont{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpLogfont);

    LOGFONTW stlpLogfont{};

    if(lpLogfont != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLogfont, &stlpLogfont, sizeof(stlpLogfont));
    }

    FONTENUMPROCW lpProc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    int EnumFontFamiliesExWResult = EnumFontFamiliesExW((HDC)hdc,(LPLOGFONTW)&stlpLogfont,(FONTENUMPROCW)lpProc,(LPARAM)lParam,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumFontFamiliesExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpLogfont);

    if(lpLogfont != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLogfont, &stlpLogfont, sizeof(stlpLogfont));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumFontFamiliesExW\n";
    #endif

    return;
}


/*
int
__cdecl
EnumFontFamiliesA(
      HDC            hdc        ,
      LPCSTR         lpLogfont  ,
      FONTENUMPROCA  lpProc     ,
      LPARAM         lParam     );

*/
void EmuApi::EmuEnumFontFamiliesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpLogfont{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpLogfont);

    std::string rlalpLogfont;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpLogfont, rlalpLogfont)) { printf("Error when read lpLogfont in EnumFontFamiliesA"); _CrtDbgBreak(); }

    FONTENUMPROCA lpProc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    int EnumFontFamiliesAResult = EnumFontFamiliesA((HDC)hdc,(LPCSTR)rlalpLogfont.data(),(FONTENUMPROCA)lpProc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumFontFamiliesAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpLogfont, rlalpLogfont)) { printf("Error when read lpLogfont in EnumFontFamiliesA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumFontFamiliesA\n";
    #endif

    return;
}


/*
int
__cdecl
EnumFontFamiliesW(
      HDC            hdc        ,
      LPCWSTR        lpLogfont  ,
      FONTENUMPROCW  lpProc     ,
      LPARAM         lParam     );

*/
void EmuApi::EmuEnumFontFamiliesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpLogfont{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpLogfont);

    std::wstring rlwlpLogfont;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpLogfont, rlwlpLogfont)) { printf("Error when read lpLogfont in EnumFontFamiliesW"); _CrtDbgBreak(); }

    FONTENUMPROCW lpProc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    int EnumFontFamiliesWResult = EnumFontFamiliesW((HDC)hdc,(LPCWSTR)rlwlpLogfont.data(),(FONTENUMPROCW)lpProc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumFontFamiliesWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpLogfont, rlwlpLogfont)) { printf("Error when read lpLogfont in EnumFontFamiliesW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumFontFamiliesW\n";
    #endif

    return;
}


/*
int
__cdecl
EnumFontsA(
      HDC            hdc        ,
      LPCSTR         lpLogfont  ,
      FONTENUMPROCA  lpProc     ,
      LPARAM         lParam     );

*/
void EmuApi::EmuEnumFontsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpLogfont{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpLogfont);

    std::string rlalpLogfont;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpLogfont, rlalpLogfont)) { printf("Error when read lpLogfont in EnumFontsA"); _CrtDbgBreak(); }

    FONTENUMPROCA lpProc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    int EnumFontsAResult = EnumFontsA((HDC)hdc,(LPCSTR)rlalpLogfont.data(),(FONTENUMPROCA)lpProc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumFontsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpLogfont, rlalpLogfont)) { printf("Error when read lpLogfont in EnumFontsA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumFontsA\n";
    #endif

    return;
}


/*
int
__cdecl
EnumFontsW(
      HDC            hdc        ,
      LPCWSTR        lpLogfont  ,
      FONTENUMPROCW  lpProc     ,
      LPARAM         lParam     );

*/
void EmuApi::EmuEnumFontsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpLogfont{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpLogfont);

    std::wstring rlwlpLogfont;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpLogfont, rlwlpLogfont)) { printf("Error when read lpLogfont in EnumFontsW"); _CrtDbgBreak(); }

    FONTENUMPROCW lpProc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    int EnumFontsWResult = EnumFontsW((HDC)hdc,(LPCWSTR)rlwlpLogfont.data(),(FONTENUMPROCW)lpProc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumFontsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpLogfont, rlwlpLogfont)) { printf("Error when read lpLogfont in EnumFontsW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumFontsW\n";
    #endif

    return;
}


/*
int
__cdecl
EnumObjects(
      HDC           hdc     ,
      int           nType   ,
      GOBJENUMPROC  lpFunc  ,
      LPARAM        lParam  );

*/
void EmuApi::EmuEnumObjects(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int nType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nType);

    GOBJENUMPROC lpFunc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFunc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    int EnumObjectsResult = EnumObjects((HDC)hdc,(int)nType,(GOBJENUMPROC)lpFunc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumObjectsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &nType);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFunc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumObjects\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EqualRgn(
      HRGN  hrgn1  ,
      HRGN  hrgn2  );

*/
void EmuApi::EmuEqualRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HRGN hrgn1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hrgn1);

    HRGN hrgn2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn2);


    BOOL EqualRgnResult = EqualRgn((HRGN)hrgn1,(HRGN)hrgn2);


    uc_reg_write(uc, UC_X86_REG_EAX, &EqualRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hrgn1);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn2);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEqualRgn\n";
    #endif

    return;
}


/*
int
__cdecl
Escape(
      HDC     hdc      ,
      int     iEscape  ,
      int     cjIn     ,
      LPCSTR  pvIn     ,
      LPVOID  pvOut    );

*/
void EmuApi::EmuEscape(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int iEscape{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iEscape);

    int cjIn{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cjIn);

    LPSTR pvIn{};
    uc_reg_read(uc, UC_X86_REG_R9, &pvIn);

    std::string rlapvIn;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pvIn, rlapvIn)) { printf("Error when read pvIn in Escape"); _CrtDbgBreak(); }

    LPVOID pvOut{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pvOut, sizeof(pvOut));


    int EscapeResult = Escape((HDC)hdc,(int)iEscape,(int)cjIn,(LPCSTR)rlapvIn.data(),(LPVOID)&pvOut);


    uc_reg_write(uc, UC_X86_REG_EAX, &EscapeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iEscape);
    uc_reg_write(uc, UC_X86_REG_R8D, &cjIn);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pvIn, rlapvIn)) { printf("Error when read pvIn in Escape"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pvOut, sizeof(pvOut));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEscape\n";
    #endif

    return;
}


/*
int
__cdecl
ExtEscape(
      HDC     hdc        ,
      int     iEscape    ,
      int     cjInput    ,
      LPCSTR  lpInData   ,
      int     cjOutput   ,
      LPSTR   lpOutData  );

*/
void EmuApi::EmuExtEscape(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int iEscape{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iEscape);

    int cjInput{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cjInput);

    LPSTR lpInData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpInData);

    std::string rlalpInData;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpInData, rlalpInData)) { printf("Error when read lpInData in ExtEscape"); _CrtDbgBreak(); }

    int cjOutput{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cjOutput, sizeof(cjOutput));

    LPSTR lpOutData{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpOutData, sizeof(lpOutData));

    std::string rlalpOutData;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpOutData, rlalpOutData)) { printf("Error when read lpOutData in ExtEscape"); _CrtDbgBreak(); }


    int ExtEscapeResult = ExtEscape((HDC)hdc,(int)iEscape,(int)cjInput,(LPCSTR)rlalpInData.data(),(int)cjOutput,(LPSTR)rlalpOutData.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &ExtEscapeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iEscape);
    uc_reg_write(uc, UC_X86_REG_R8D, &cjInput);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpInData, rlalpInData)) { printf("Error when read lpInData in ExtEscape"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cjOutput, sizeof(cjOutput));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpOutData, rlalpOutData)) { printf("Error when read lpOutData in ExtEscape"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExtEscape\n";
    #endif

    return;
}


/*
int
__cdecl
ExcludeClipRect(
      HDC  hdc     ,
      int  left    ,
      int  top     ,
      int  right   ,
      int  bottom  );

*/
void EmuApi::EmuExcludeClipRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int left{};
    uc_reg_read(uc, UC_X86_REG_EDX, &left);

    int top{};
    uc_reg_read(uc, UC_X86_REG_R8D, &top);

    int right{};
    uc_reg_read(uc, UC_X86_REG_R9D, &right);

    int bottom{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));


    int ExcludeClipRectResult = ExcludeClipRect((HDC)hdc,(int)left,(int)top,(int)right,(int)bottom);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExcludeClipRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &left);
    uc_reg_write(uc, UC_X86_REG_R8D, &top);
    uc_reg_write(uc, UC_X86_REG_R9D, &right);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExcludeClipRect\n";
    #endif

    return;
}


/*
HRGN
__cdecl
ExtCreateRegion(
      const XFORM *    lpx     ,
      DWORD            nCount  ,
      const RGNDATA *  lpData  );

*/
void EmuApi::EmuExtCreateRegion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PXFORM lpx{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpx);

    XFORM stlpx{};

    if(lpx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpx, &stlpx, sizeof(stlpx));
    }

    DWORD nCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nCount);

    PRGNDATA lpData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpData);

    RGNDATA stlpData{};

    if(lpData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpData, &stlpData, sizeof(stlpData));
    }


    HRGN ExtCreateRegionResult = ExtCreateRegion((const XFORM *)&stlpx,(DWORD)nCount,(const RGNDATA *)&stlpData);


    uc_reg_write(uc, UC_X86_REG_RAX, &ExtCreateRegionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpx);

    if(lpx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpx, &stlpx, sizeof(stlpx));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &nCount);
    uc_reg_write(uc, UC_X86_REG_R8, &lpData);

    if(lpData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpData, &stlpData, sizeof(stlpData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExtCreateRegion\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ExtFloodFill(
      HDC       hdc    ,
      int       x      ,
      int       y      ,
      COLORREF  color  ,
      UINT      type   );

*/
void EmuApi::EmuExtFloodFill(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_R9D, &color);

    UINT type{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &type, sizeof(type));


    BOOL ExtFloodFillResult = ExtFloodFill((HDC)hdc,(int)x,(int)y,(COLORREF)color,(UINT)type);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExtFloodFillResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9D, &color);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &type, sizeof(type));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExtFloodFill\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FillRgn(
      HDC     hdc   ,
      HRGN    hrgn  ,
      HBRUSH  hbr   );

*/
void EmuApi::EmuFillRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn);

    HBRUSH hbr{};
    uc_reg_read(uc, UC_X86_REG_R8, &hbr);


    BOOL FillRgnResult = FillRgn((HDC)hdc,(HRGN)hrgn,(HBRUSH)hbr);


    uc_reg_write(uc, UC_X86_REG_EAX, &FillRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_R8, &hbr);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFillRgn\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FloodFill(
      HDC       hdc    ,
      int       x      ,
      int       y      ,
      COLORREF  color  );

*/
void EmuApi::EmuFloodFill(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_R9D, &color);


    BOOL FloodFillResult = FloodFill((HDC)hdc,(int)x,(int)y,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_EAX, &FloodFillResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9D, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFloodFill\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FrameRgn(
      HDC     hdc   ,
      HRGN    hrgn  ,
      HBRUSH  hbr   ,
      int     w     ,
      int     h     );

*/
void EmuApi::EmuFrameRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn);

    HBRUSH hbr{};
    uc_reg_read(uc, UC_X86_REG_R8, &hbr);

    int w{};
    uc_reg_read(uc, UC_X86_REG_R9D, &w);

    int h{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &h, sizeof(h));


    BOOL FrameRgnResult = FrameRgn((HDC)hdc,(HRGN)hrgn,(HBRUSH)hbr,(int)w,(int)h);


    uc_reg_write(uc, UC_X86_REG_EAX, &FrameRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_R8, &hbr);
    uc_reg_write(uc, UC_X86_REG_R9D, &w);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &h, sizeof(h));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFrameRgn\n";
    #endif

    return;
}


/*
int
__cdecl
GetROP2(
      HDC  hdc  );

*/
void EmuApi::EmuGetROP2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetROP2Result = GetROP2((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetROP2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetROP2\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetAspectRatioFilterEx(
      HDC     hdc     ,
      LPSIZE  lpsize  );

*/
void EmuApi::EmuGetAspectRatioFilterEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSIZE lpsize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpsize);

    SIZE stlpsize{};

    if(lpsize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsize, &stlpsize, sizeof(stlpsize));
    }


    BOOL GetAspectRatioFilterExResult = GetAspectRatioFilterEx((HDC)hdc,(LPSIZE)&stlpsize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetAspectRatioFilterExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpsize);

    if(lpsize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsize, &stlpsize, sizeof(stlpsize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetAspectRatioFilterEx\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
GetBkColor(
      HDC  hdc  );

*/
void EmuApi::EmuGetBkColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    COLORREF GetBkColorResult = GetBkColor((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetBkColorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetBkColor\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
GetDCBrushColor(
      HDC  hdc  );

*/
void EmuApi::EmuGetDCBrushColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    COLORREF GetDCBrushColorResult = GetDCBrushColor((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDCBrushColorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDCBrushColor\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
GetDCPenColor(
      HDC  hdc  );

*/
void EmuApi::EmuGetDCPenColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    COLORREF GetDCPenColorResult = GetDCPenColor((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDCPenColorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDCPenColor\n";
    #endif

    return;
}


/*
int
__cdecl
GetBkMode(
      HDC  hdc  );

*/
void EmuApi::EmuGetBkMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetBkModeResult = GetBkMode((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetBkModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetBkMode\n";
    #endif

    return;
}


/*
LONG
__cdecl
GetBitmapBits(
      HBITMAP  hbit     ,
      LONG     cb       ,
      LPVOID   lpvBits  );

*/
void EmuApi::EmuGetBitmapBits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HBITMAP hbit{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hbit);

    LONG cb{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cb);

    LPVOID lpvBits{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpvBits);


    LONG GetBitmapBitsResult = GetBitmapBits((HBITMAP)hbit,(LONG)cb,(LPVOID)&lpvBits);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetBitmapBitsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hbit);
    uc_reg_write(uc, UC_X86_REG_EDX, &cb);
    uc_reg_write(uc, UC_X86_REG_R8, &lpvBits);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetBitmapBits\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetBitmapDimensionEx(
      HBITMAP  hbit    ,
      LPSIZE   lpsize  );

*/
void EmuApi::EmuGetBitmapDimensionEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HBITMAP hbit{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hbit);

    LPSIZE lpsize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpsize);

    SIZE stlpsize{};

    if(lpsize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsize, &stlpsize, sizeof(stlpsize));
    }


    BOOL GetBitmapDimensionExResult = GetBitmapDimensionEx((HBITMAP)hbit,(LPSIZE)&stlpsize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetBitmapDimensionExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hbit);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpsize);

    if(lpsize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsize, &stlpsize, sizeof(stlpsize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetBitmapDimensionEx\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetBoundsRect(
      HDC     hdc     ,
      LPRECT  lprect  ,
      UINT    flags   );

*/
void EmuApi::EmuGetBoundsRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPRECT lprect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprect);

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }

    UINT flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flags);


    UINT GetBoundsRectResult = GetBoundsRect((HDC)hdc,(LPRECT)&stlprect,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetBoundsRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprect);

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetBoundsRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetBrushOrgEx(
      HDC      hdc   ,
      LPPOINT  lppt  );

*/
void EmuApi::EmuGetBrushOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }


    BOOL GetBrushOrgExResult = GetBrushOrgEx((HDC)hdc,(LPPOINT)&stlppt);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetBrushOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetBrushOrgEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharWidthA(
      HDC    hdc       ,
      UINT   iFirst    ,
      UINT   iLast     ,
      LPINT  lpBuffer  );

*/
void EmuApi::EmuGetCharWidthA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iFirst);

    UINT iLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iLast);

    LPINT lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    int rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }


    BOOL GetCharWidthAResult = GetCharWidthA((HDC)hdc,(UINT)iFirst,(UINT)iLast,(LPINT)&rllpBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharWidthAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &iLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharWidthA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharWidthW(
      HDC    hdc       ,
      UINT   iFirst    ,
      UINT   iLast     ,
      LPINT  lpBuffer  );

*/
void EmuApi::EmuGetCharWidthW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iFirst);

    UINT iLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iLast);

    LPINT lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    int rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }


    BOOL GetCharWidthWResult = GetCharWidthW((HDC)hdc,(UINT)iFirst,(UINT)iLast,(LPINT)&rllpBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharWidthWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &iLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharWidthW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharWidth32A(
      HDC    hdc       ,
      UINT   iFirst    ,
      UINT   iLast     ,
      LPINT  lpBuffer  );

*/
void EmuApi::EmuGetCharWidth32A(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iFirst);

    UINT iLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iLast);

    LPINT lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    int rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }


    BOOL GetCharWidth32AResult = GetCharWidth32A((HDC)hdc,(UINT)iFirst,(UINT)iLast,(LPINT)&rllpBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharWidth32AResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &iLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharWidth32A\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharWidth32W(
      HDC    hdc       ,
      UINT   iFirst    ,
      UINT   iLast     ,
      LPINT  lpBuffer  );

*/
void EmuApi::EmuGetCharWidth32W(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iFirst);

    UINT iLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iLast);

    LPINT lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    int rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }


    BOOL GetCharWidth32WResult = GetCharWidth32W((HDC)hdc,(UINT)iFirst,(UINT)iLast,(LPINT)&rllpBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharWidth32WResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &iLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharWidth32W\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharWidthFloatA(
      HDC     hdc       ,
      UINT    iFirst    ,
      UINT    iLast     ,
      PFLOAT  lpBuffer  );

*/
void EmuApi::EmuGetCharWidthFloatA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iFirst);

    UINT iLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iLast);

    PFLOAT lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    FLOAT rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }


    BOOL GetCharWidthFloatAResult = GetCharWidthFloatA((HDC)hdc,(UINT)iFirst,(UINT)iLast,(PFLOAT)&rllpBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharWidthFloatAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &iLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharWidthFloatA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharWidthFloatW(
      HDC     hdc       ,
      UINT    iFirst    ,
      UINT    iLast     ,
      PFLOAT  lpBuffer  );

*/
void EmuApi::EmuGetCharWidthFloatW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iFirst);

    UINT iLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iLast);

    PFLOAT lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    FLOAT rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }


    BOOL GetCharWidthFloatWResult = GetCharWidthFloatW((HDC)hdc,(UINT)iFirst,(UINT)iLast,(PFLOAT)&rllpBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharWidthFloatWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &iLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharWidthFloatW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharABCWidthsA(
      HDC    hdc     ,
      UINT   wFirst  ,
      UINT   wLast   ,
      LPABC  lpABC   );

*/
void EmuApi::EmuGetCharABCWidthsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT wFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &wFirst);

    UINT wLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &wLast);

    LPABC lpABC{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpABC);

    ABC stlpABC{};

    if(lpABC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpABC, &stlpABC, sizeof(stlpABC));
    }


    BOOL GetCharABCWidthsAResult = GetCharABCWidthsA((HDC)hdc,(UINT)wFirst,(UINT)wLast,(LPABC)&stlpABC);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharABCWidthsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &wFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &wLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpABC);

    if(lpABC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpABC, &stlpABC, sizeof(stlpABC));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharABCWidthsA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharABCWidthsW(
      HDC    hdc     ,
      UINT   wFirst  ,
      UINT   wLast   ,
      LPABC  lpABC   );

*/
void EmuApi::EmuGetCharABCWidthsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT wFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &wFirst);

    UINT wLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &wLast);

    LPABC lpABC{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpABC);

    ABC stlpABC{};

    if(lpABC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpABC, &stlpABC, sizeof(stlpABC));
    }


    BOOL GetCharABCWidthsWResult = GetCharABCWidthsW((HDC)hdc,(UINT)wFirst,(UINT)wLast,(LPABC)&stlpABC);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharABCWidthsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &wFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &wLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpABC);

    if(lpABC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpABC, &stlpABC, sizeof(stlpABC));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharABCWidthsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharABCWidthsFloatA(
      HDC         hdc     ,
      UINT        iFirst  ,
      UINT        iLast   ,
      LPABCFLOAT  lpABC   );

*/
void EmuApi::EmuGetCharABCWidthsFloatA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iFirst);

    UINT iLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iLast);

    LPABCFLOAT lpABC{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpABC);

    ABCFLOAT stlpABC{};

    if(lpABC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpABC, &stlpABC, sizeof(stlpABC));
    }


    BOOL GetCharABCWidthsFloatAResult = GetCharABCWidthsFloatA((HDC)hdc,(UINT)iFirst,(UINT)iLast,(LPABCFLOAT)&stlpABC);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharABCWidthsFloatAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &iLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpABC);

    if(lpABC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpABC, &stlpABC, sizeof(stlpABC));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharABCWidthsFloatA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharABCWidthsFloatW(
      HDC         hdc     ,
      UINT        iFirst  ,
      UINT        iLast   ,
      LPABCFLOAT  lpABC   );

*/
void EmuApi::EmuGetCharABCWidthsFloatW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iFirst);

    UINT iLast{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iLast);

    LPABCFLOAT lpABC{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpABC);

    ABCFLOAT stlpABC{};

    if(lpABC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpABC, &stlpABC, sizeof(stlpABC));
    }


    BOOL GetCharABCWidthsFloatWResult = GetCharABCWidthsFloatW((HDC)hdc,(UINT)iFirst,(UINT)iLast,(LPABCFLOAT)&stlpABC);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharABCWidthsFloatWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &iLast);
    uc_reg_write(uc, UC_X86_REG_R9, &lpABC);

    if(lpABC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpABC, &stlpABC, sizeof(stlpABC));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharABCWidthsFloatW\n";
    #endif

    return;
}


/*
int
__cdecl
GetClipBox(
      HDC     hdc     ,
      LPRECT  lprect  );

*/
void EmuApi::EmuGetClipBox(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPRECT lprect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprect);

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }


    int GetClipBoxResult = GetClipBox((HDC)hdc,(LPRECT)&stlprect);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClipBoxResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprect);

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipBox\n";
    #endif

    return;
}


/*
int
__cdecl
GetClipRgn(
      HDC   hdc   ,
      HRGN  hrgn  );

*/
void EmuApi::EmuGetClipRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn);


    int GetClipRgnResult = GetClipRgn((HDC)hdc,(HRGN)hrgn);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClipRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipRgn\n";
    #endif

    return;
}


/*
int
__cdecl
GetMetaRgn(
      HDC   hdc   ,
      HRGN  hrgn  );

*/
void EmuApi::EmuGetMetaRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn);


    int GetMetaRgnResult = GetMetaRgn((HDC)hdc,(HRGN)hrgn);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMetaRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMetaRgn\n";
    #endif

    return;
}


/*
HGDIOBJ
__cdecl
GetCurrentObject(
      HDC   hdc   ,
      UINT  type  );

*/
void EmuApi::EmuGetCurrentObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT type{};
    uc_reg_read(uc, UC_X86_REG_EDX, &type);


    HGDIOBJ GetCurrentObjectResult = GetCurrentObject((HDC)hdc,(UINT)type);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCurrentObjectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &type);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCurrentObject\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCurrentPositionEx(
      HDC      hdc   ,
      LPPOINT  lppt  );

*/
void EmuApi::EmuGetCurrentPositionEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }


    BOOL GetCurrentPositionExResult = GetCurrentPositionEx((HDC)hdc,(LPPOINT)&stlppt);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentPositionExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCurrentPositionEx\n";
    #endif

    return;
}


/*
int
__cdecl
GetDeviceCaps(
      HDC  hdc    ,
      int  index  );

*/
void EmuApi::EmuGetDeviceCaps(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int index{};
    uc_reg_read(uc, UC_X86_REG_EDX, &index);


    int GetDeviceCapsResult = GetDeviceCaps((HDC)hdc,(int)index);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDeviceCapsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &index);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDeviceCaps\n";
    #endif

    return;
}


/*
int
__cdecl
GetDIBits(
      HDC           hdc      ,
      HBITMAP       hbm      ,
      UINT          start    ,
      UINT          cLines   ,
      LPVOID        lpvBits  ,
      LPBITMAPINFO  lpbmi    ,
      UINT          usage    );

*/
void EmuApi::EmuGetDIBits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HBITMAP hbm{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hbm);

    UINT start{};
    uc_reg_read(uc, UC_X86_REG_R8D, &start);

    UINT cLines{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cLines);

    LPVOID lpvBits{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpvBits, sizeof(lpvBits));

    LPBITMAPINFO lpbmi{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpbmi, sizeof(lpbmi));

    BITMAPINFO stlpbmi{};

    if(lpbmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpbmi, &stlpbmi, sizeof(stlpbmi));
    }

    UINT usage{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &usage, sizeof(usage));


    int GetDIBitsResult = GetDIBits((HDC)hdc,(HBITMAP)hbm,(UINT)start,(UINT)cLines,(LPVOID)&lpvBits,(LPBITMAPINFO)&stlpbmi,(UINT)usage);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDIBitsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hbm);
    uc_reg_write(uc, UC_X86_REG_R8D, &start);
    uc_reg_write(uc, UC_X86_REG_R9D, &cLines);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpvBits, sizeof(lpvBits));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpbmi, sizeof(lpbmi));

    if(lpbmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpbmi, &stlpbmi, sizeof(stlpbmi));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &usage, sizeof(usage));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDIBits\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFontData(
      HDC    hdc       ,
      DWORD  dwTable   ,
      DWORD  dwOffset  ,
      PVOID  pvBuffer  ,
      DWORD  cjBuffer  );

*/
void EmuApi::EmuGetFontData(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    DWORD dwTable{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwTable);

    DWORD dwOffset{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwOffset);

    PVOID pvBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &pvBuffer);

    DWORD cjBuffer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cjBuffer, sizeof(cjBuffer));


    DWORD GetFontDataResult = GetFontData((HDC)hdc,(DWORD)dwTable,(DWORD)dwOffset,(PVOID)&pvBuffer,(DWORD)cjBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFontDataResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwTable);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwOffset);
    uc_reg_write(uc, UC_X86_REG_R9, &pvBuffer);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cjBuffer, sizeof(cjBuffer));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFontData\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetGlyphOutlineA(
      HDC             hdc       ,
      UINT            uChar     ,
      UINT            fuFormat  ,
      LPGLYPHMETRICS  lpgm      ,
      DWORD           cjBuffer  ,
      LPVOID          pvBuffer  ,
      const MAT2 *    lpmat2    );

*/
void EmuApi::EmuGetGlyphOutlineA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT uChar{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uChar);

    UINT fuFormat{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fuFormat);

    LPGLYPHMETRICS lpgm{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpgm);

    GLYPHMETRICS stlpgm{};

    if(lpgm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpgm, &stlpgm, sizeof(stlpgm));
    }

    DWORD cjBuffer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cjBuffer, sizeof(cjBuffer));

    LPVOID pvBuffer{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &pvBuffer, sizeof(pvBuffer));

    MAT2 * lpmat2{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpmat2, sizeof(lpmat2));

    MAT2 stlpmat2{};

    if(lpmat2 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmat2, &stlpmat2, sizeof(stlpmat2));
    }


    DWORD GetGlyphOutlineAResult = GetGlyphOutlineA((HDC)hdc,(UINT)uChar,(UINT)fuFormat,(LPGLYPHMETRICS)&stlpgm,(DWORD)cjBuffer,(LPVOID)&pvBuffer,(const MAT2 *)&stlpmat2);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGlyphOutlineAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &uChar);
    uc_reg_write(uc, UC_X86_REG_R8D, &fuFormat);
    uc_reg_write(uc, UC_X86_REG_R9, &lpgm);

    if(lpgm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpgm, &stlpgm, sizeof(stlpgm));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cjBuffer, sizeof(cjBuffer));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &pvBuffer, sizeof(pvBuffer));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpmat2, sizeof(lpmat2));

    if(lpmat2 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmat2, &stlpmat2, sizeof(stlpmat2));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGlyphOutlineA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetGlyphOutlineW(
      HDC             hdc       ,
      UINT            uChar     ,
      UINT            fuFormat  ,
      LPGLYPHMETRICS  lpgm      ,
      DWORD           cjBuffer  ,
      LPVOID          pvBuffer  ,
      const MAT2 *    lpmat2    );

*/
void EmuApi::EmuGetGlyphOutlineW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT uChar{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uChar);

    UINT fuFormat{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fuFormat);

    LPGLYPHMETRICS lpgm{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpgm);

    GLYPHMETRICS stlpgm{};

    if(lpgm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpgm, &stlpgm, sizeof(stlpgm));
    }

    DWORD cjBuffer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cjBuffer, sizeof(cjBuffer));

    LPVOID pvBuffer{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &pvBuffer, sizeof(pvBuffer));

    MAT2 * lpmat2{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpmat2, sizeof(lpmat2));

    MAT2 stlpmat2{};

    if(lpmat2 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmat2, &stlpmat2, sizeof(stlpmat2));
    }


    DWORD GetGlyphOutlineWResult = GetGlyphOutlineW((HDC)hdc,(UINT)uChar,(UINT)fuFormat,(LPGLYPHMETRICS)&stlpgm,(DWORD)cjBuffer,(LPVOID)&pvBuffer,(const MAT2 *)&stlpmat2);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGlyphOutlineWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &uChar);
    uc_reg_write(uc, UC_X86_REG_R8D, &fuFormat);
    uc_reg_write(uc, UC_X86_REG_R9, &lpgm);

    if(lpgm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpgm, &stlpgm, sizeof(stlpgm));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cjBuffer, sizeof(cjBuffer));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &pvBuffer, sizeof(pvBuffer));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpmat2, sizeof(lpmat2));

    if(lpmat2 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmat2, &stlpmat2, sizeof(stlpmat2));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGlyphOutlineW\n";
    #endif

    return;
}


/*
int
__cdecl
GetGraphicsMode(
      HDC  hdc  );

*/
void EmuApi::EmuGetGraphicsMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetGraphicsModeResult = GetGraphicsMode((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGraphicsModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGraphicsMode\n";
    #endif

    return;
}


/*
int
__cdecl
GetMapMode(
      HDC  hdc  );

*/
void EmuApi::EmuGetMapMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetMapModeResult = GetMapMode((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMapModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMapMode\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetMetaFileBitsEx(
      HMETAFILE  hMF       ,
      UINT       cbBuffer  ,
      LPVOID     lpData    );

*/
void EmuApi::EmuGetMetaFileBitsEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMETAFILE hMF{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMF);

    UINT cbBuffer{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cbBuffer);

    LPVOID lpData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpData);


    UINT GetMetaFileBitsExResult = GetMetaFileBitsEx((HMETAFILE)hMF,(UINT)cbBuffer,(LPVOID)&lpData);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMetaFileBitsExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMF);
    uc_reg_write(uc, UC_X86_REG_EDX, &cbBuffer);
    uc_reg_write(uc, UC_X86_REG_R8, &lpData);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMetaFileBitsEx\n";
    #endif

    return;
}


/*
HMETAFILE
__cdecl
GetMetaFileA(
      LPCSTR  lpName  );

*/
void EmuApi::EmuGetMetaFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetMetaFileA"); _CrtDbgBreak(); }


    HMETAFILE GetMetaFileAResult = GetMetaFileA((LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &GetMetaFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetMetaFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMetaFileA\n";
    #endif

    return;
}


/*
HMETAFILE
__cdecl
GetMetaFileW(
      LPCWSTR  lpName  );

*/
void EmuApi::EmuGetMetaFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetMetaFileW"); _CrtDbgBreak(); }


    HMETAFILE GetMetaFileWResult = GetMetaFileW((LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &GetMetaFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetMetaFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMetaFileW\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
GetNearestColor(
      HDC       hdc    ,
      COLORREF  color  );

*/
void EmuApi::EmuGetNearestColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_EDX, &color);


    COLORREF GetNearestColorResult = GetNearestColor((HDC)hdc,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNearestColorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNearestColor\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetNearestPaletteIndex(
      HPALETTE  h      ,
      COLORREF  color  );

*/
void EmuApi::EmuGetNearestPaletteIndex(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HPALETTE h{};
    uc_reg_read(uc, UC_X86_REG_RCX, &h);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_EDX, &color);


    UINT GetNearestPaletteIndexResult = GetNearestPaletteIndex((HPALETTE)h,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNearestPaletteIndexResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &h);
    uc_reg_write(uc, UC_X86_REG_EDX, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNearestPaletteIndex\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetObjectType(
      HGDIOBJ  h  );

*/
void EmuApi::EmuGetObjectType(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGDIOBJ h{};
    uc_reg_read(uc, UC_X86_REG_RCX, &h);


    DWORD GetObjectTypeResult = GetObjectType((HGDIOBJ)&h);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetObjectTypeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &h);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetObjectType\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetOutlineTextMetricsA(
      HDC                   hdc     ,
      UINT                  cjCopy  ,
      LPOUTLINETEXTMETRICA  potm    );

*/
void EmuApi::EmuGetOutlineTextMetricsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT cjCopy{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cjCopy);

    LPOUTLINETEXTMETRICA potm{};
    uc_reg_read(uc, UC_X86_REG_R8, &potm);

    OUTLINETEXTMETRICA stpotm{};

    if(potm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)potm, &stpotm, sizeof(stpotm));
    }


    UINT GetOutlineTextMetricsAResult = GetOutlineTextMetricsA((HDC)hdc,(UINT)cjCopy,(LPOUTLINETEXTMETRICA)&stpotm);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetOutlineTextMetricsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &cjCopy);
    uc_reg_write(uc, UC_X86_REG_R8, &potm);

    if(potm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)potm, &stpotm, sizeof(stpotm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetOutlineTextMetricsA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetOutlineTextMetricsW(
      HDC                   hdc     ,
      UINT                  cjCopy  ,
      LPOUTLINETEXTMETRICW  potm    );

*/
void EmuApi::EmuGetOutlineTextMetricsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT cjCopy{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cjCopy);

    LPOUTLINETEXTMETRICW potm{};
    uc_reg_read(uc, UC_X86_REG_R8, &potm);

    OUTLINETEXTMETRICW stpotm{};

    if(potm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)potm, &stpotm, sizeof(stpotm));
    }


    UINT GetOutlineTextMetricsWResult = GetOutlineTextMetricsW((HDC)hdc,(UINT)cjCopy,(LPOUTLINETEXTMETRICW)&stpotm);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetOutlineTextMetricsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &cjCopy);
    uc_reg_write(uc, UC_X86_REG_R8, &potm);

    if(potm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)potm, &stpotm, sizeof(stpotm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetOutlineTextMetricsW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetPaletteEntries(
      HPALETTE        hpal         ,
      UINT            iStart       ,
      UINT            cEntries     ,
      LPPALETTEENTRY  pPalEntries  );

*/
void EmuApi::EmuGetPaletteEntries(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HPALETTE hpal{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hpal);

    UINT iStart{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iStart);

    UINT cEntries{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cEntries);

    LPPALETTEENTRY pPalEntries{};
    uc_reg_read(uc, UC_X86_REG_R9, &pPalEntries);

    PALETTEENTRY stpPalEntries{};

    if(pPalEntries != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pPalEntries, &stpPalEntries, sizeof(stpPalEntries));
    }


    UINT GetPaletteEntriesResult = GetPaletteEntries((HPALETTE)hpal,(UINT)iStart,(UINT)cEntries,(LPPALETTEENTRY)&stpPalEntries);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPaletteEntriesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hpal);
    uc_reg_write(uc, UC_X86_REG_EDX, &iStart);
    uc_reg_write(uc, UC_X86_REG_R8D, &cEntries);
    uc_reg_write(uc, UC_X86_REG_R9, &pPalEntries);

    if(pPalEntries != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pPalEntries, &stpPalEntries, sizeof(stpPalEntries));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPaletteEntries\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
GetPixel(
      HDC  hdc  ,
      int  x    ,
      int  y    );

*/
void EmuApi::EmuGetPixel(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);


    COLORREF GetPixelResult = GetPixel((HDC)hdc,(int)x,(int)y);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPixelResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPixel\n";
    #endif

    return;
}


/*
int
__cdecl
GetPixelFormat(
      HDC  hdc  );

*/
void EmuApi::EmuGetPixelFormat(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetPixelFormatResult = GetPixelFormat((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPixelFormatResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPixelFormat\n";
    #endif

    return;
}


/*
int
__cdecl
GetPolyFillMode(
      HDC  hdc  );

*/
void EmuApi::EmuGetPolyFillMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetPolyFillModeResult = GetPolyFillMode((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPolyFillModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPolyFillMode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetRasterizerCaps(
      LPRASTERIZER_STATUS  lpraststat  ,
      UINT                 cjBytes     );

*/
void EmuApi::EmuGetRasterizerCaps(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRASTERIZER_STATUS lpraststat{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpraststat);

    RASTERIZER_STATUS stlpraststat{};

    if(lpraststat != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpraststat, &stlpraststat, sizeof(stlpraststat));
    }

    UINT cjBytes{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cjBytes);


    BOOL GetRasterizerCapsResult = GetRasterizerCaps((LPRASTERIZER_STATUS)&stlpraststat,(UINT)cjBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRasterizerCapsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpraststat);

    if(lpraststat != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpraststat, &stlpraststat, sizeof(stlpraststat));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &cjBytes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRasterizerCaps\n";
    #endif

    return;
}


/*
int
__cdecl
GetRandomRgn(
      HDC   hdc   ,
      HRGN  hrgn  ,
      INT   i     );

*/
void EmuApi::EmuGetRandomRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn);

    INT i{};
    uc_reg_read(uc, UC_X86_REG_R8D, &i);


    int GetRandomRgnResult = GetRandomRgn((HDC)hdc,(HRGN)hrgn,(INT)i);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRandomRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_R8D, &i);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRandomRgn\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetRegionData(
      HRGN       hrgn       ,
      DWORD      nCount     ,
      LPRGNDATA  lpRgnData  );

*/
void EmuApi::EmuGetRegionData(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hrgn);

    DWORD nCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nCount);

    LPRGNDATA lpRgnData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpRgnData);

    RGNDATA stlpRgnData{};

    if(lpRgnData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRgnData, &stlpRgnData, sizeof(stlpRgnData));
    }


    DWORD GetRegionDataResult = GetRegionData((HRGN)hrgn,(DWORD)nCount,(LPRGNDATA)&stlpRgnData);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRegionDataResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_EDX, &nCount);
    uc_reg_write(uc, UC_X86_REG_R8, &lpRgnData);

    if(lpRgnData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRgnData, &stlpRgnData, sizeof(stlpRgnData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRegionData\n";
    #endif

    return;
}


/*
int
__cdecl
GetRgnBox(
      HRGN    hrgn  ,
      LPRECT  lprc  );

*/
void EmuApi::EmuGetRgnBox(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hrgn);

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }


    int GetRgnBoxResult = GetRgnBox((HRGN)hrgn,(LPRECT)&stlprc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRgnBoxResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRgnBox\n";
    #endif

    return;
}


/*
HGDIOBJ
__cdecl
GetStockObject(
      int  i  );

*/
void EmuApi::EmuGetStockObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int i{};
    uc_reg_read(uc, UC_X86_REG_ECX, &i);


    HGDIOBJ GetStockObjectResult = GetStockObject((int)i);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetStockObjectResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &i);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetStockObject\n";
    #endif

    return;
}


/*
int
__cdecl
GetStretchBltMode(
      HDC  hdc  );

*/
void EmuApi::EmuGetStretchBltMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetStretchBltModeResult = GetStretchBltMode((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetStretchBltModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetStretchBltMode\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetSystemPaletteEntries(
      HDC             hdc          ,
      UINT            iStart       ,
      UINT            cEntries     ,
      LPPALETTEENTRY  pPalEntries  );

*/
void EmuApi::EmuGetSystemPaletteEntries(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iStart{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iStart);

    UINT cEntries{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cEntries);

    LPPALETTEENTRY pPalEntries{};
    uc_reg_read(uc, UC_X86_REG_R9, &pPalEntries);

    PALETTEENTRY stpPalEntries{};

    if(pPalEntries != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pPalEntries, &stpPalEntries, sizeof(stpPalEntries));
    }


    UINT GetSystemPaletteEntriesResult = GetSystemPaletteEntries((HDC)hdc,(UINT)iStart,(UINT)cEntries,(LPPALETTEENTRY)&stpPalEntries);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemPaletteEntriesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iStart);
    uc_reg_write(uc, UC_X86_REG_R8D, &cEntries);
    uc_reg_write(uc, UC_X86_REG_R9, &pPalEntries);

    if(pPalEntries != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pPalEntries, &stpPalEntries, sizeof(stpPalEntries));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemPaletteEntries\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetSystemPaletteUse(
      HDC  hdc  );

*/
void EmuApi::EmuGetSystemPaletteUse(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    UINT GetSystemPaletteUseResult = GetSystemPaletteUse((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemPaletteUseResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemPaletteUse\n";
    #endif

    return;
}


/*
int
__cdecl
GetTextCharacterExtra(
      HDC  hdc  );

*/
void EmuApi::EmuGetTextCharacterExtra(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetTextCharacterExtraResult = GetTextCharacterExtra((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextCharacterExtraResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextCharacterExtra\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetTextAlign(
      HDC  hdc  );

*/
void EmuApi::EmuGetTextAlign(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    UINT GetTextAlignResult = GetTextAlign((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextAlignResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextAlign\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
GetTextColor(
      HDC  hdc  );

*/
void EmuApi::EmuGetTextColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    COLORREF GetTextColorResult = GetTextColor((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextColorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextColor\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextExtentPointA(
      HDC     hdc       ,
      LPCSTR  lpString  ,
      int     c         ,
      LPSIZE  lpsz      );

*/
void EmuApi::EmuGetTextExtentPointA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetTextExtentPointA"); _CrtDbgBreak(); }

    int c{};
    uc_reg_read(uc, UC_X86_REG_R8D, &c);

    LPSIZE lpsz{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpsz);

    SIZE stlpsz{};

    if(lpsz != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }


    BOOL GetTextExtentPointAResult = GetTextExtentPointA((HDC)hdc,(LPCSTR)rlalpString.data(),(int)c,(LPSIZE)&stlpsz);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextExtentPointAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetTextExtentPointA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &c);
    uc_reg_write(uc, UC_X86_REG_R9, &lpsz);

    if(lpsz != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextExtentPointA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextExtentPointW(
      HDC      hdc       ,
      LPCWSTR  lpString  ,
      int      c         ,
      LPSIZE   lpsz      );

*/
void EmuApi::EmuGetTextExtentPointW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetTextExtentPointW"); _CrtDbgBreak(); }

    int c{};
    uc_reg_read(uc, UC_X86_REG_R8D, &c);

    LPSIZE lpsz{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpsz);

    SIZE stlpsz{};

    if(lpsz != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }


    BOOL GetTextExtentPointWResult = GetTextExtentPointW((HDC)hdc,(LPCWSTR)rlwlpString.data(),(int)c,(LPSIZE)&stlpsz);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextExtentPointWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetTextExtentPointW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &c);
    uc_reg_write(uc, UC_X86_REG_R9, &lpsz);

    if(lpsz != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextExtentPointW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextExtentPoint32A(
      HDC     hdc       ,
      LPCSTR  lpString  ,
      int     c         ,
      LPSIZE  psizl     );

*/
void EmuApi::EmuGetTextExtentPoint32A(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetTextExtentPoint32A"); _CrtDbgBreak(); }

    int c{};
    uc_reg_read(uc, UC_X86_REG_R8D, &c);

    LPSIZE psizl{};
    uc_reg_read(uc, UC_X86_REG_R9, &psizl);

    SIZE stpsizl{};

    if(psizl != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)psizl, &stpsizl, sizeof(stpsizl));
    }


    BOOL GetTextExtentPoint32AResult = GetTextExtentPoint32A((HDC)hdc,(LPCSTR)rlalpString.data(),(int)c,(LPSIZE)&stpsizl);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextExtentPoint32AResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetTextExtentPoint32A"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &c);
    uc_reg_write(uc, UC_X86_REG_R9, &psizl);

    if(psizl != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)psizl, &stpsizl, sizeof(stpsizl));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextExtentPoint32A\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextExtentPoint32W(
      HDC      hdc       ,
      LPCWSTR  lpString  ,
      int      c         ,
      LPSIZE   psizl     );

*/
void EmuApi::EmuGetTextExtentPoint32W(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetTextExtentPoint32W"); _CrtDbgBreak(); }

    int c{};
    uc_reg_read(uc, UC_X86_REG_R8D, &c);

    LPSIZE psizl{};
    uc_reg_read(uc, UC_X86_REG_R9, &psizl);

    SIZE stpsizl{};

    if(psizl != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)psizl, &stpsizl, sizeof(stpsizl));
    }


    BOOL GetTextExtentPoint32WResult = GetTextExtentPoint32W((HDC)hdc,(LPCWSTR)rlwlpString.data(),(int)c,(LPSIZE)&stpsizl);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextExtentPoint32WResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetTextExtentPoint32W"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &c);
    uc_reg_write(uc, UC_X86_REG_R9, &psizl);

    if(psizl != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)psizl, &stpsizl, sizeof(stpsizl));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextExtentPoint32W\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextExtentExPointA(
      HDC     hdc         ,
      LPCSTR  lpszString  ,
      int     cchString   ,
      int     nMaxExtent  ,
      LPINT   lpnFit      ,
      LPINT   lpnDx       ,
      LPSIZE  lpSize      );

*/
void EmuApi::EmuGetTextExtentExPointA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpszString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszString);

    std::string rlalpszString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszString, rlalpszString)) { printf("Error when read lpszString in GetTextExtentExPointA"); _CrtDbgBreak(); }

    int cchString{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchString);

    int nMaxExtent{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nMaxExtent);

    LPINT lpnFit{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpnFit, sizeof(lpnFit));

    int rllpnFit{};

    if(lpnFit != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnFit, &rllpnFit, sizeof(rllpnFit));
    }

    LPINT lpnDx{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpnDx, sizeof(lpnDx));

    int rllpnDx{};

    if(lpnDx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnDx, &rllpnDx, sizeof(rllpnDx));
    }

    LPSIZE lpSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpSize, sizeof(lpSize));

    SIZE stlpSize{};

    if(lpSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSize, &stlpSize, sizeof(stlpSize));
    }


    BOOL GetTextExtentExPointAResult = GetTextExtentExPointA((HDC)hdc,(LPCSTR)rlalpszString.data(),(int)cchString,(int)nMaxExtent,(LPINT)&rllpnFit,(LPINT)&rllpnDx,(LPSIZE)&stlpSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextExtentExPointAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszString, rlalpszString)) { printf("Error when read lpszString in GetTextExtentExPointA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchString);
    uc_reg_write(uc, UC_X86_REG_R9D, &nMaxExtent);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpnFit, sizeof(lpnFit));

    if(lpnFit != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnFit, &rllpnFit, sizeof(rllpnFit));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpnDx, sizeof(lpnDx));

    if(lpnDx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnDx, &rllpnDx, sizeof(rllpnDx));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpSize, sizeof(lpSize));

    if(lpSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSize, &stlpSize, sizeof(stlpSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextExtentExPointA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextExtentExPointW(
      HDC      hdc         ,
      LPCWSTR  lpszString  ,
      int      cchString   ,
      int      nMaxExtent  ,
      LPINT    lpnFit      ,
      LPINT    lpnDx       ,
      LPSIZE   lpSize      );

*/
void EmuApi::EmuGetTextExtentExPointW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpszString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszString);

    std::wstring rlwlpszString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszString, rlwlpszString)) { printf("Error when read lpszString in GetTextExtentExPointW"); _CrtDbgBreak(); }

    int cchString{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchString);

    int nMaxExtent{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nMaxExtent);

    LPINT lpnFit{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpnFit, sizeof(lpnFit));

    int rllpnFit{};

    if(lpnFit != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnFit, &rllpnFit, sizeof(rllpnFit));
    }

    LPINT lpnDx{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpnDx, sizeof(lpnDx));

    int rllpnDx{};

    if(lpnDx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnDx, &rllpnDx, sizeof(rllpnDx));
    }

    LPSIZE lpSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpSize, sizeof(lpSize));

    SIZE stlpSize{};

    if(lpSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSize, &stlpSize, sizeof(stlpSize));
    }


    BOOL GetTextExtentExPointWResult = GetTextExtentExPointW((HDC)hdc,(LPCWSTR)rlwlpszString.data(),(int)cchString,(int)nMaxExtent,(LPINT)&rllpnFit,(LPINT)&rllpnDx,(LPSIZE)&stlpSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextExtentExPointWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszString, rlwlpszString)) { printf("Error when read lpszString in GetTextExtentExPointW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchString);
    uc_reg_write(uc, UC_X86_REG_R9D, &nMaxExtent);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpnFit, sizeof(lpnFit));

    if(lpnFit != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnFit, &rllpnFit, sizeof(rllpnFit));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpnDx, sizeof(lpnDx));

    if(lpnDx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnDx, &rllpnDx, sizeof(rllpnDx));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpSize, sizeof(lpSize));

    if(lpSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSize, &stlpSize, sizeof(stlpSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextExtentExPointW\n";
    #endif

    return;
}


/*
int
__cdecl
GetTextCharset(
      HDC  hdc  );

*/
void EmuApi::EmuGetTextCharset(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetTextCharsetResult = GetTextCharset((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextCharsetResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextCharset\n";
    #endif

    return;
}


/*
int
__cdecl
GetTextCharsetInfo(
      HDC              hdc      ,
      LPFONTSIGNATURE  lpSig    ,
      DWORD            dwFlags  );

*/
void EmuApi::EmuGetTextCharsetInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPFONTSIGNATURE lpSig{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSig);

    FONTSIGNATURE stlpSig{};

    if(lpSig != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSig, &stlpSig, sizeof(stlpSig));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    int GetTextCharsetInfoResult = GetTextCharsetInfo((HDC)hdc,(LPFONTSIGNATURE)&stlpSig,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextCharsetInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpSig);

    if(lpSig != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSig, &stlpSig, sizeof(stlpSig));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextCharsetInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TranslateCharsetInfo(
      DWORD *        lpSrc    ,
      LPCHARSETINFO  lpCs     ,
      DWORD          dwFlags  );

*/
void EmuApi::EmuTranslateCharsetInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PDWORD lpSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSrc);

    DWORD rllpSrc{};

    if(lpSrc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSrc, &rllpSrc, sizeof(rllpSrc));
    }

    LPCHARSETINFO lpCs{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCs);

    CHARSETINFO stlpCs{};

    if(lpCs != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCs, &stlpCs, sizeof(stlpCs));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    BOOL TranslateCharsetInfoResult = TranslateCharsetInfo((DWORD *)&rllpSrc,(LPCHARSETINFO)&stlpCs,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &TranslateCharsetInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpSrc);

    if(lpSrc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSrc, &rllpSrc, sizeof(rllpSrc));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCs);

    if(lpCs != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCs, &stlpCs, sizeof(stlpCs));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTranslateCharsetInfo\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFontLanguageInfo(
      HDC  hdc  );

*/
void EmuApi::EmuGetFontLanguageInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    DWORD GetFontLanguageInfoResult = GetFontLanguageInfo((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFontLanguageInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFontLanguageInfo\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetCharacterPlacementA(
      HDC             hdc         ,
      LPCSTR          lpString    ,
      int             nCount      ,
      int             nMexExtent  ,
      LPGCP_RESULTSA  lpResults   ,
      DWORD           dwFlags     );

*/
void EmuApi::EmuGetCharacterPlacementA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetCharacterPlacementA"); _CrtDbgBreak(); }

    int nCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nCount);

    int nMexExtent{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nMexExtent);

    LPGCP_RESULTSA lpResults{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpResults, sizeof(lpResults));

    GCP_RESULTSA stlpResults{};

    if(lpResults != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpResults, &stlpResults, sizeof(stlpResults));
    }

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));


    DWORD GetCharacterPlacementAResult = GetCharacterPlacementA((HDC)hdc,(LPCSTR)rlalpString.data(),(int)nCount,(int)nMexExtent,(LPGCP_RESULTSA)&stlpResults,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharacterPlacementAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetCharacterPlacementA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nCount);
    uc_reg_write(uc, UC_X86_REG_R9D, &nMexExtent);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpResults, sizeof(lpResults));

    if(lpResults != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpResults, &stlpResults, sizeof(stlpResults));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharacterPlacementA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetCharacterPlacementW(
      HDC             hdc         ,
      LPCWSTR         lpString    ,
      int             nCount      ,
      int             nMexExtent  ,
      LPGCP_RESULTSW  lpResults   ,
      DWORD           dwFlags     );

*/
void EmuApi::EmuGetCharacterPlacementW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetCharacterPlacementW"); _CrtDbgBreak(); }

    int nCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nCount);

    int nMexExtent{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nMexExtent);

    LPGCP_RESULTSW lpResults{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpResults, sizeof(lpResults));

    GCP_RESULTSW stlpResults{};

    if(lpResults != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpResults, &stlpResults, sizeof(stlpResults));
    }

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));


    DWORD GetCharacterPlacementWResult = GetCharacterPlacementW((HDC)hdc,(LPCWSTR)rlwlpString.data(),(int)nCount,(int)nMexExtent,(LPGCP_RESULTSW)&stlpResults,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharacterPlacementWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetCharacterPlacementW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nCount);
    uc_reg_write(uc, UC_X86_REG_R9D, &nMexExtent);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpResults, sizeof(lpResults));

    if(lpResults != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpResults, &stlpResults, sizeof(stlpResults));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharacterPlacementW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFontUnicodeRanges(
      HDC         hdc   ,
      LPGLYPHSET  lpgs  );

*/
void EmuApi::EmuGetFontUnicodeRanges(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPGLYPHSET lpgs{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpgs);

    GLYPHSET stlpgs{};

    if(lpgs != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpgs, &stlpgs, sizeof(stlpgs));
    }


    DWORD GetFontUnicodeRangesResult = GetFontUnicodeRanges((HDC)hdc,(LPGLYPHSET)&stlpgs);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFontUnicodeRangesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpgs);

    if(lpgs != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpgs, &stlpgs, sizeof(stlpgs));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFontUnicodeRanges\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetGlyphIndicesA(
      HDC     hdc    ,
      LPCSTR  lpstr  ,
      int     c      ,
      LPWORD  pgi    ,
      DWORD   fl     );

*/
void EmuApi::EmuGetGlyphIndicesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpstr{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpstr);

    std::string rlalpstr;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpstr, rlalpstr)) { printf("Error when read lpstr in GetGlyphIndicesA"); _CrtDbgBreak(); }

    int c{};
    uc_reg_read(uc, UC_X86_REG_R8D, &c);

    LPWORD pgi{};
    uc_reg_read(uc, UC_X86_REG_R9, &pgi);

    WORD rlpgi{};

    if(pgi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pgi, &rlpgi, sizeof(rlpgi));
    }

    DWORD fl{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &fl, sizeof(fl));


    DWORD GetGlyphIndicesAResult = GetGlyphIndicesA((HDC)hdc,(LPCSTR)rlalpstr.data(),(int)c,(LPWORD)&rlpgi,(DWORD)fl);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGlyphIndicesAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpstr, rlalpstr)) { printf("Error when read lpstr in GetGlyphIndicesA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &c);
    uc_reg_write(uc, UC_X86_REG_R9, &pgi);

    if(pgi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pgi, &rlpgi, sizeof(rlpgi));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &fl, sizeof(fl));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGlyphIndicesA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetGlyphIndicesW(
      HDC      hdc    ,
      LPCWSTR  lpstr  ,
      int      c      ,
      LPWORD   pgi    ,
      DWORD    fl     );

*/
void EmuApi::EmuGetGlyphIndicesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpstr{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpstr);

    std::wstring rlwlpstr;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpstr, rlwlpstr)) { printf("Error when read lpstr in GetGlyphIndicesW"); _CrtDbgBreak(); }

    int c{};
    uc_reg_read(uc, UC_X86_REG_R8D, &c);

    LPWORD pgi{};
    uc_reg_read(uc, UC_X86_REG_R9, &pgi);

    WORD rlpgi{};

    if(pgi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pgi, &rlpgi, sizeof(rlpgi));
    }

    DWORD fl{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &fl, sizeof(fl));


    DWORD GetGlyphIndicesWResult = GetGlyphIndicesW((HDC)hdc,(LPCWSTR)rlwlpstr.data(),(int)c,(LPWORD)&rlpgi,(DWORD)fl);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGlyphIndicesWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpstr, rlwlpstr)) { printf("Error when read lpstr in GetGlyphIndicesW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &c);
    uc_reg_write(uc, UC_X86_REG_R9, &pgi);

    if(pgi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pgi, &rlpgi, sizeof(rlpgi));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &fl, sizeof(fl));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGlyphIndicesW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextExtentPointI(
      HDC     hdc    ,
      LPWORD  pgiIn  ,
      int     cgi    ,
      LPSIZE  psize  );

*/
void EmuApi::EmuGetTextExtentPointI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWORD pgiIn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pgiIn);

    WORD rlpgiIn{};

    if(pgiIn != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pgiIn, &rlpgiIn, sizeof(rlpgiIn));
    }

    int cgi{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cgi);

    LPSIZE psize{};
    uc_reg_read(uc, UC_X86_REG_R9, &psize);

    SIZE stpsize{};

    if(psize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)psize, &stpsize, sizeof(stpsize));
    }


    BOOL GetTextExtentPointIResult = GetTextExtentPointI((HDC)hdc,(LPWORD)&rlpgiIn,(int)cgi,(LPSIZE)&stpsize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextExtentPointIResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &pgiIn);

    if(pgiIn != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pgiIn, &rlpgiIn, sizeof(rlpgiIn));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &cgi);
    uc_reg_write(uc, UC_X86_REG_R9, &psize);

    if(psize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)psize, &stpsize, sizeof(stpsize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextExtentPointI\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextExtentExPointI(
      HDC     hdc          ,
      LPWORD  lpwszString  ,
      int     cwchString   ,
      int     nMaxExtent   ,
      LPINT   lpnFit       ,
      LPINT   lpnDx        ,
      LPSIZE  lpSize       );

*/
void EmuApi::EmuGetTextExtentExPointI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWORD lpwszString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpwszString);

    WORD rllpwszString{};

    if(lpwszString != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpwszString, &rllpwszString, sizeof(rllpwszString));
    }

    int cwchString{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cwchString);

    int nMaxExtent{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nMaxExtent);

    LPINT lpnFit{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpnFit, sizeof(lpnFit));

    int rllpnFit{};

    if(lpnFit != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnFit, &rllpnFit, sizeof(rllpnFit));
    }

    LPINT lpnDx{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpnDx, sizeof(lpnDx));

    int rllpnDx{};

    if(lpnDx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnDx, &rllpnDx, sizeof(rllpnDx));
    }

    LPSIZE lpSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpSize, sizeof(lpSize));

    SIZE stlpSize{};

    if(lpSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSize, &stlpSize, sizeof(stlpSize));
    }


    BOOL GetTextExtentExPointIResult = GetTextExtentExPointI((HDC)hdc,(LPWORD)&rllpwszString,(int)cwchString,(int)nMaxExtent,(LPINT)&rllpnFit,(LPINT)&rllpnDx,(LPSIZE)&stlpSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextExtentExPointIResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpwszString);

    if(lpwszString != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpwszString, &rllpwszString, sizeof(rllpwszString));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &cwchString);
    uc_reg_write(uc, UC_X86_REG_R9D, &nMaxExtent);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpnFit, sizeof(lpnFit));

    if(lpnFit != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnFit, &rllpnFit, sizeof(rllpnFit));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpnDx, sizeof(lpnDx));

    if(lpnDx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnDx, &rllpnDx, sizeof(rllpnDx));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpSize, sizeof(lpSize));

    if(lpSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSize, &stlpSize, sizeof(stlpSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextExtentExPointI\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharWidthI(
      HDC     hdc       ,
      UINT    giFirst   ,
      UINT    cgi       ,
      LPWORD  pgi       ,
      LPINT   piWidths  );

*/
void EmuApi::EmuGetCharWidthI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT giFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &giFirst);

    UINT cgi{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cgi);

    LPWORD pgi{};
    uc_reg_read(uc, UC_X86_REG_R9, &pgi);

    WORD rlpgi{};

    if(pgi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pgi, &rlpgi, sizeof(rlpgi));
    }

    LPINT piWidths{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &piWidths, sizeof(piWidths));

    int rlpiWidths{};

    if(piWidths != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)piWidths, &rlpiWidths, sizeof(rlpiWidths));
    }


    BOOL GetCharWidthIResult = GetCharWidthI((HDC)hdc,(UINT)giFirst,(UINT)cgi,(LPWORD)&rlpgi,(LPINT)&rlpiWidths);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharWidthIResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &giFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &cgi);
    uc_reg_write(uc, UC_X86_REG_R9, &pgi);

    if(pgi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pgi, &rlpgi, sizeof(rlpgi));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &piWidths, sizeof(piWidths));

    if(piWidths != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)piWidths, &rlpiWidths, sizeof(rlpiWidths));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharWidthI\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCharABCWidthsI(
      HDC     hdc      ,
      UINT    giFirst  ,
      UINT    cgi      ,
      LPWORD  pgi      ,
      LPABC   pabc     );

*/
void EmuApi::EmuGetCharABCWidthsI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT giFirst{};
    uc_reg_read(uc, UC_X86_REG_EDX, &giFirst);

    UINT cgi{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cgi);

    LPWORD pgi{};
    uc_reg_read(uc, UC_X86_REG_R9, &pgi);

    WORD rlpgi{};

    if(pgi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pgi, &rlpgi, sizeof(rlpgi));
    }

    LPABC pabc{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pabc, sizeof(pabc));

    ABC stpabc{};

    if(pabc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pabc, &stpabc, sizeof(stpabc));
    }


    BOOL GetCharABCWidthsIResult = GetCharABCWidthsI((HDC)hdc,(UINT)giFirst,(UINT)cgi,(LPWORD)&rlpgi,(LPABC)&stpabc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCharABCWidthsIResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &giFirst);
    uc_reg_write(uc, UC_X86_REG_R8D, &cgi);
    uc_reg_write(uc, UC_X86_REG_R9, &pgi);

    if(pgi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pgi, &rlpgi, sizeof(rlpgi));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pabc, sizeof(pabc));

    if(pabc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pabc, &stpabc, sizeof(stpabc));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCharABCWidthsI\n";
    #endif

    return;
}


/*
int
__cdecl
AddFontResourceExA(
      LPCSTR  name  ,
      DWORD   fl    ,
      PVOID   res   );

*/
void EmuApi::EmuAddFontResourceExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR name{};
    uc_reg_read(uc, UC_X86_REG_RCX, &name);

    std::string rlaname;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)name, rlaname)) { printf("Error when read name in AddFontResourceExA"); _CrtDbgBreak(); }

    DWORD fl{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fl);

    PVOID res{};
    uc_reg_read(uc, UC_X86_REG_R8, &res);


    int AddFontResourceExAResult = AddFontResourceExA((LPCSTR)rlaname.data(),(DWORD)fl,(PVOID)&res);


    uc_reg_write(uc, UC_X86_REG_EAX, &AddFontResourceExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)name, rlaname)) { printf("Error when read name in AddFontResourceExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fl);
    uc_reg_write(uc, UC_X86_REG_R8, &res);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddFontResourceExA\n";
    #endif

    return;
}


/*
int
__cdecl
AddFontResourceExW(
      LPCWSTR  name  ,
      DWORD    fl    ,
      PVOID    res   );

*/
void EmuApi::EmuAddFontResourceExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR name{};
    uc_reg_read(uc, UC_X86_REG_RCX, &name);

    std::wstring rlwname;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)name, rlwname)) { printf("Error when read name in AddFontResourceExW"); _CrtDbgBreak(); }

    DWORD fl{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fl);

    PVOID res{};
    uc_reg_read(uc, UC_X86_REG_R8, &res);


    int AddFontResourceExWResult = AddFontResourceExW((LPCWSTR)rlwname.data(),(DWORD)fl,(PVOID)&res);


    uc_reg_write(uc, UC_X86_REG_EAX, &AddFontResourceExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)name, rlwname)) { printf("Error when read name in AddFontResourceExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fl);
    uc_reg_write(uc, UC_X86_REG_R8, &res);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddFontResourceExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveFontResourceExA(
      LPCSTR  name  ,
      DWORD   fl    ,
      PVOID   pdv   );

*/
void EmuApi::EmuRemoveFontResourceExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR name{};
    uc_reg_read(uc, UC_X86_REG_RCX, &name);

    std::string rlaname;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)name, rlaname)) { printf("Error when read name in RemoveFontResourceExA"); _CrtDbgBreak(); }

    DWORD fl{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fl);

    PVOID pdv{};
    uc_reg_read(uc, UC_X86_REG_R8, &pdv);


    BOOL RemoveFontResourceExAResult = RemoveFontResourceExA((LPCSTR)rlaname.data(),(DWORD)fl,(PVOID)&pdv);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveFontResourceExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)name, rlaname)) { printf("Error when read name in RemoveFontResourceExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fl);
    uc_reg_write(uc, UC_X86_REG_R8, &pdv);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveFontResourceExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveFontResourceExW(
      LPCWSTR  name  ,
      DWORD    fl    ,
      PVOID    pdv   );

*/
void EmuApi::EmuRemoveFontResourceExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR name{};
    uc_reg_read(uc, UC_X86_REG_RCX, &name);

    std::wstring rlwname;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)name, rlwname)) { printf("Error when read name in RemoveFontResourceExW"); _CrtDbgBreak(); }

    DWORD fl{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fl);

    PVOID pdv{};
    uc_reg_read(uc, UC_X86_REG_R8, &pdv);


    BOOL RemoveFontResourceExWResult = RemoveFontResourceExW((LPCWSTR)rlwname.data(),(DWORD)fl,(PVOID)&pdv);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveFontResourceExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)name, rlwname)) { printf("Error when read name in RemoveFontResourceExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fl);
    uc_reg_write(uc, UC_X86_REG_R8, &pdv);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveFontResourceExW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
AddFontMemResourceEx(
      PVOID    pFileView  ,
      DWORD    cjSize     ,
      PVOID    pvResrved  ,
      DWORD *  pNumFonts  );

*/
void EmuApi::EmuAddFontMemResourceEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID pFileView{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pFileView);

    DWORD cjSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cjSize);

    PVOID pvResrved{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvResrved);

    PDWORD pNumFonts{};
    uc_reg_read(uc, UC_X86_REG_R9, &pNumFonts);

    DWORD rlpNumFonts{};

    if(pNumFonts != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pNumFonts, &rlpNumFonts, sizeof(rlpNumFonts));
    }


    HANDLE AddFontMemResourceExResult = AddFontMemResourceEx((PVOID)&pFileView,(DWORD)cjSize,(PVOID)&pvResrved,(DWORD *)&rlpNumFonts);


    uc_reg_write(uc, UC_X86_REG_RAX, &AddFontMemResourceExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pFileView);
    uc_reg_write(uc, UC_X86_REG_EDX, &cjSize);
    uc_reg_write(uc, UC_X86_REG_R8, &pvResrved);
    uc_reg_write(uc, UC_X86_REG_R9, &pNumFonts);

    if(pNumFonts != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pNumFonts, &rlpNumFonts, sizeof(rlpNumFonts));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddFontMemResourceEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveFontMemResourceEx(
      HANDLE  h  );

*/
void EmuApi::EmuRemoveFontMemResourceEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE h{};
    uc_reg_read(uc, UC_X86_REG_RCX, &h);


    BOOL RemoveFontMemResourceExResult = RemoveFontMemResourceEx((HANDLE)h);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveFontMemResourceExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &h);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveFontMemResourceEx\n";
    #endif

    return;
}


/*
HFONT
__cdecl
CreateFontIndirectExA(
      const ENUMLOGFONTEXDVA *  namelessArg_0  );

*/
void EmuApi::EmuCreateFontIndirectExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PENUMLOGFONTEXDVA namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    ENUMLOGFONTEXDVA stnamelessArg_0{};

    if(namelessArg_0 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_0, &stnamelessArg_0, sizeof(stnamelessArg_0));
    }


    HFONT CreateFontIndirectExAResult = CreateFontIndirectExA((const ENUMLOGFONTEXDVA *)&stnamelessArg_0);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFontIndirectExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);

    if(namelessArg_0 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_0, &stnamelessArg_0, sizeof(stnamelessArg_0));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFontIndirectExA\n";
    #endif

    return;
}


/*
HFONT
__cdecl
CreateFontIndirectExW(
      const ENUMLOGFONTEXDVW *  namelessArg_0  );

*/
void EmuApi::EmuCreateFontIndirectExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PENUMLOGFONTEXDVW namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    ENUMLOGFONTEXDVW stnamelessArg_0{};

    if(namelessArg_0 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_0, &stnamelessArg_0, sizeof(stnamelessArg_0));
    }


    HFONT CreateFontIndirectExWResult = CreateFontIndirectExW((const ENUMLOGFONTEXDVW *)&stnamelessArg_0);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFontIndirectExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);

    if(namelessArg_0 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_0, &stnamelessArg_0, sizeof(stnamelessArg_0));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFontIndirectExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetViewportExtEx(
      HDC     hdc     ,
      LPSIZE  lpsize  );

*/
void EmuApi::EmuGetViewportExtEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSIZE lpsize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpsize);

    SIZE stlpsize{};

    if(lpsize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsize, &stlpsize, sizeof(stlpsize));
    }


    BOOL GetViewportExtExResult = GetViewportExtEx((HDC)hdc,(LPSIZE)&stlpsize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetViewportExtExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpsize);

    if(lpsize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsize, &stlpsize, sizeof(stlpsize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetViewportExtEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetViewportOrgEx(
      HDC      hdc      ,
      LPPOINT  lppoint  );

*/
void EmuApi::EmuGetViewportOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPPOINT lppoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lppoint);

    POINT stlppoint{};

    if(lppoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppoint, &stlppoint, sizeof(stlppoint));
    }


    BOOL GetViewportOrgExResult = GetViewportOrgEx((HDC)hdc,(LPPOINT)&stlppoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetViewportOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lppoint);

    if(lppoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppoint, &stlppoint, sizeof(stlppoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetViewportOrgEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetWindowExtEx(
      HDC     hdc     ,
      LPSIZE  lpsize  );

*/
void EmuApi::EmuGetWindowExtEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSIZE lpsize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpsize);

    SIZE stlpsize{};

    if(lpsize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsize, &stlpsize, sizeof(stlpsize));
    }


    BOOL GetWindowExtExResult = GetWindowExtEx((HDC)hdc,(LPSIZE)&stlpsize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowExtExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpsize);

    if(lpsize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsize, &stlpsize, sizeof(stlpsize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowExtEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetWindowOrgEx(
      HDC      hdc      ,
      LPPOINT  lppoint  );

*/
void EmuApi::EmuGetWindowOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPPOINT lppoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lppoint);

    POINT stlppoint{};

    if(lppoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppoint, &stlppoint, sizeof(stlppoint));
    }


    BOOL GetWindowOrgExResult = GetWindowOrgEx((HDC)hdc,(LPPOINT)&stlppoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lppoint);

    if(lppoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppoint, &stlppoint, sizeof(stlppoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowOrgEx\n";
    #endif

    return;
}


/*
int
__cdecl
IntersectClipRect(
      HDC  hdc     ,
      int  left    ,
      int  top     ,
      int  right   ,
      int  bottom  );

*/
void EmuApi::EmuIntersectClipRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int left{};
    uc_reg_read(uc, UC_X86_REG_EDX, &left);

    int top{};
    uc_reg_read(uc, UC_X86_REG_R8D, &top);

    int right{};
    uc_reg_read(uc, UC_X86_REG_R9D, &right);

    int bottom{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));


    int IntersectClipRectResult = IntersectClipRect((HDC)hdc,(int)left,(int)top,(int)right,(int)bottom);


    uc_reg_write(uc, UC_X86_REG_EAX, &IntersectClipRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &left);
    uc_reg_write(uc, UC_X86_REG_R8D, &top);
    uc_reg_write(uc, UC_X86_REG_R9D, &right);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIntersectClipRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InvertRgn(
      HDC   hdc   ,
      HRGN  hrgn  );

*/
void EmuApi::EmuInvertRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn);


    BOOL InvertRgnResult = InvertRgn((HDC)hdc,(HRGN)hrgn);


    uc_reg_write(uc, UC_X86_REG_EAX, &InvertRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInvertRgn\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LineDDA(
      int          xStart  ,
      int          yStart  ,
      int          xEnd    ,
      int          yEnd    ,
      LINEDDAPROC  lpProc  ,
      LPARAM       data    );

*/
void EmuApi::EmuLineDDA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int xStart{};
    uc_reg_read(uc, UC_X86_REG_ECX, &xStart);

    int yStart{};
    uc_reg_read(uc, UC_X86_REG_EDX, &yStart);

    int xEnd{};
    uc_reg_read(uc, UC_X86_REG_R8D, &xEnd);

    int yEnd{};
    uc_reg_read(uc, UC_X86_REG_R9D, &yEnd);

    LINEDDAPROC lpProc{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpProc, sizeof(lpProc));

    LPARAM data{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &data, sizeof(data));


    BOOL LineDDAResult = LineDDA((int)xStart,(int)yStart,(int)xEnd,(int)yEnd,(LINEDDAPROC)lpProc,(LPARAM)data);


    uc_reg_write(uc, UC_X86_REG_EAX, &LineDDAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &xStart);
    uc_reg_write(uc, UC_X86_REG_EDX, &yStart);
    uc_reg_write(uc, UC_X86_REG_R8D, &xEnd);
    uc_reg_write(uc, UC_X86_REG_R9D, &yEnd);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpProc, sizeof(lpProc));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &data, sizeof(data));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLineDDA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LineTo(
      HDC  hdc  ,
      int  x    ,
      int  y    );

*/
void EmuApi::EmuLineTo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);


    BOOL LineToResult = LineTo((HDC)hdc,(int)x,(int)y);


    uc_reg_write(uc, UC_X86_REG_EAX, &LineToResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLineTo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MaskBlt(
      HDC      hdcDest  ,
      int      xDest    ,
      int      yDest    ,
      int      width    ,
      int      height   ,
      HDC      hdcSrc   ,
      int      xSrc     ,
      int      ySrc     ,
      HBITMAP  hbmMask  ,
      int      xMask    ,
      int      yMask    ,
      DWORD    rop      );

*/
void EmuApi::EmuMaskBlt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdcDest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdcDest);

    int xDest{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xDest);

    int yDest{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yDest);

    int width{};
    uc_reg_read(uc, UC_X86_REG_R9D, &width);

    int height{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &height, sizeof(height));

    HDC hdcSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));

    int xSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &xSrc, sizeof(xSrc));

    int ySrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &ySrc, sizeof(ySrc));

    HBITMAP hbmMask{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &hbmMask, sizeof(hbmMask));

    int xMask{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &xMask, sizeof(xMask));

    int yMask{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &yMask, sizeof(yMask));

    DWORD rop{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &rop, sizeof(rop));


    BOOL MaskBltResult = MaskBlt((HDC)hdcDest,(int)xDest,(int)yDest,(int)width,(int)height,(HDC)hdcSrc,(int)xSrc,(int)ySrc,(HBITMAP)hbmMask,(int)xMask,(int)yMask,(DWORD)rop);


    uc_reg_write(uc, UC_X86_REG_EAX, &MaskBltResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdcDest);
    uc_reg_write(uc, UC_X86_REG_EDX, &xDest);
    uc_reg_write(uc, UC_X86_REG_R8D, &yDest);
    uc_reg_write(uc, UC_X86_REG_R9D, &width);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &height, sizeof(height));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &xSrc, sizeof(xSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &ySrc, sizeof(ySrc));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &hbmMask, sizeof(hbmMask));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &xMask, sizeof(xMask));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &yMask, sizeof(yMask));
    uc_mem_write(uc, (DWORD_PTR)SP+96, &rop, sizeof(rop));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMaskBlt\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PlgBlt(
      HDC            hdcDest  ,
      const POINT *  lpPoint  ,
      HDC            hdcSrc   ,
      int            xSrc     ,
      int            ySrc     ,
      int            width    ,
      int            height   ,
      HBITMAP        hbmMask  ,
      int            xMask    ,
      int            yMask    );

*/
void EmuApi::EmuPlgBlt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdcDest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdcDest);

    POINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPoint);

    HDC hdcSrc{};
    uc_reg_read(uc, UC_X86_REG_R8, &hdcSrc);

    int xSrc{};
    uc_reg_read(uc, UC_X86_REG_R9D, &xSrc);

    int ySrc{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ySrc, sizeof(ySrc));

    int width{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &width, sizeof(width));

    int height{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &height, sizeof(height));

    HBITMAP hbmMask{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &hbmMask, sizeof(hbmMask));

    int xMask{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &xMask, sizeof(xMask));

    int yMask{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &yMask, sizeof(yMask));


    BOOL PlgBltResult = PlgBlt((HDC)hdcDest,(const POINT *)&lpPoint,(HDC)hdcSrc,(int)xSrc,(int)ySrc,(int)width,(int)height,(HBITMAP)hbmMask,(int)xMask,(int)yMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &PlgBltResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdcDest);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPoint);
    uc_reg_write(uc, UC_X86_REG_R8, &hdcSrc);
    uc_reg_write(uc, UC_X86_REG_R9D, &xSrc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ySrc, sizeof(ySrc));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &width, sizeof(width));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &height, sizeof(height));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &hbmMask, sizeof(hbmMask));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &xMask, sizeof(xMask));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &yMask, sizeof(yMask));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPlgBlt\n";
    #endif

    return;
}


/*
int
__cdecl
OffsetClipRgn(
      HDC  hdc  ,
      int  x    ,
      int  y    );

*/
void EmuApi::EmuOffsetClipRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);


    int OffsetClipRgnResult = OffsetClipRgn((HDC)hdc,(int)x,(int)y);


    uc_reg_write(uc, UC_X86_REG_EAX, &OffsetClipRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOffsetClipRgn\n";
    #endif

    return;
}


/*
int
__cdecl
OffsetRgn(
      HRGN  hrgn  ,
      int   x     ,
      int   y     );

*/
void EmuApi::EmuOffsetRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hrgn);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);


    int OffsetRgnResult = OffsetRgn((HRGN)hrgn,(int)x,(int)y);


    uc_reg_write(uc, UC_X86_REG_EAX, &OffsetRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOffsetRgn\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PatBlt(
      HDC    hdc  ,
      int    x    ,
      int    y    ,
      int    w    ,
      int    h    ,
      DWORD  rop  );

*/
void EmuApi::EmuPatBlt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    int w{};
    uc_reg_read(uc, UC_X86_REG_R9D, &w);

    int h{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &h, sizeof(h));

    DWORD rop{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &rop, sizeof(rop));


    BOOL PatBltResult = PatBlt((HDC)hdc,(int)x,(int)y,(int)w,(int)h,(DWORD)rop);


    uc_reg_write(uc, UC_X86_REG_EAX, &PatBltResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9D, &w);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &h, sizeof(h));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &rop, sizeof(rop));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPatBlt\n";
    #endif

    return;
}


/*
BOOL
__cdecl
Pie(
      HDC  hdc     ,
      int  left    ,
      int  top     ,
      int  right   ,
      int  bottom  ,
      int  xr1     ,
      int  yr1     ,
      int  xr2     ,
      int  yr2     );

*/
void EmuApi::EmuPie(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int left{};
    uc_reg_read(uc, UC_X86_REG_EDX, &left);

    int top{};
    uc_reg_read(uc, UC_X86_REG_R8D, &top);

    int right{};
    uc_reg_read(uc, UC_X86_REG_R9D, &right);

    int bottom{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));

    int xr1{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &xr1, sizeof(xr1));

    int yr1{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &yr1, sizeof(yr1));

    int xr2{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &xr2, sizeof(xr2));

    int yr2{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &yr2, sizeof(yr2));


    BOOL PieResult = Pie((HDC)hdc,(int)left,(int)top,(int)right,(int)bottom,(int)xr1,(int)yr1,(int)xr2,(int)yr2);


    uc_reg_write(uc, UC_X86_REG_EAX, &PieResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &left);
    uc_reg_write(uc, UC_X86_REG_R8D, &top);
    uc_reg_write(uc, UC_X86_REG_R9D, &right);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &xr1, sizeof(xr1));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &yr1, sizeof(yr1));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &xr2, sizeof(xr2));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &yr2, sizeof(yr2));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPie\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PlayMetaFile(
      HDC        hdc  ,
      HMETAFILE  hmf  );

*/
void EmuApi::EmuPlayMetaFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HMETAFILE hmf{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hmf);


    BOOL PlayMetaFileResult = PlayMetaFile((HDC)hdc,(HMETAFILE)hmf);


    uc_reg_write(uc, UC_X86_REG_EAX, &PlayMetaFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hmf);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPlayMetaFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PaintRgn(
      HDC   hdc   ,
      HRGN  hrgn  );

*/
void EmuApi::EmuPaintRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn);


    BOOL PaintRgnResult = PaintRgn((HDC)hdc,(HRGN)hrgn);


    uc_reg_write(uc, UC_X86_REG_EAX, &PaintRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPaintRgn\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PolyPolygon(
      HDC            hdc  ,
      const POINT *  apt  ,
      const INT *    asz  ,
      int            csz  );

*/
void EmuApi::EmuPolyPolygon(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POINT apt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &apt);

    PINT asz{};
    uc_reg_read(uc, UC_X86_REG_R8, &asz);

    int rlasz{};

    if(asz != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)asz, &rlasz, sizeof(rlasz));
    }

    int csz{};
    uc_reg_read(uc, UC_X86_REG_R9D, &csz);


    BOOL PolyPolygonResult = PolyPolygon((HDC)hdc,(const POINT *)&apt,(const INT *)&rlasz,(int)csz);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolyPolygonResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &apt);
    uc_reg_write(uc, UC_X86_REG_R8, &asz);

    if(asz != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)asz, &rlasz, sizeof(rlasz));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &csz);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolyPolygon\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PtInRegion(
      HRGN  hrgn  ,
      int   x     ,
      int   y     );

*/
void EmuApi::EmuPtInRegion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hrgn);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);


    BOOL PtInRegionResult = PtInRegion((HRGN)hrgn,(int)x,(int)y);


    uc_reg_write(uc, UC_X86_REG_EAX, &PtInRegionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPtInRegion\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PtVisible(
      HDC  hdc  ,
      int  x    ,
      int  y    );

*/
void EmuApi::EmuPtVisible(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);


    BOOL PtVisibleResult = PtVisible((HDC)hdc,(int)x,(int)y);


    uc_reg_write(uc, UC_X86_REG_EAX, &PtVisibleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPtVisible\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RectInRegion(
      HRGN          hrgn    ,
      const RECT *  lprect  );

*/
void EmuApi::EmuRectInRegion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hrgn);

    PRECT lprect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprect);

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }


    BOOL RectInRegionResult = RectInRegion((HRGN)hrgn,(const RECT *)&stlprect);


    uc_reg_write(uc, UC_X86_REG_EAX, &RectInRegionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprect);

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRectInRegion\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RectVisible(
      HDC           hdc     ,
      const RECT *  lprect  );

*/
void EmuApi::EmuRectVisible(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PRECT lprect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprect);

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }


    BOOL RectVisibleResult = RectVisible((HDC)hdc,(const RECT *)&stlprect);


    uc_reg_write(uc, UC_X86_REG_EAX, &RectVisibleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprect);

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRectVisible\n";
    #endif

    return;
}


/*
BOOL
__cdecl
Rectangle(
      HDC  hdc     ,
      int  left    ,
      int  top     ,
      int  right   ,
      int  bottom  );

*/
void EmuApi::EmuRectangle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int left{};
    uc_reg_read(uc, UC_X86_REG_EDX, &left);

    int top{};
    uc_reg_read(uc, UC_X86_REG_R8D, &top);

    int right{};
    uc_reg_read(uc, UC_X86_REG_R9D, &right);

    int bottom{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));


    BOOL RectangleResult = Rectangle((HDC)hdc,(int)left,(int)top,(int)right,(int)bottom);


    uc_reg_write(uc, UC_X86_REG_EAX, &RectangleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &left);
    uc_reg_write(uc, UC_X86_REG_R8D, &top);
    uc_reg_write(uc, UC_X86_REG_R9D, &right);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRectangle\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RestoreDC(
      HDC  hdc       ,
      int  nSavedDC  );

*/
void EmuApi::EmuRestoreDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int nSavedDC{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nSavedDC);


    BOOL RestoreDCResult = RestoreDC((HDC)hdc,(int)nSavedDC);


    uc_reg_write(uc, UC_X86_REG_EAX, &RestoreDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &nSavedDC);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRestoreDC\n";
    #endif

    return;
}


/*
HDC
__cdecl
ResetDCA(
      HDC               hdc   ,
      const DEVMODEA *  lpdm  );

*/
void EmuApi::EmuResetDCA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PDEVMODEA lpdm{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdm);

    DEVMODEA stlpdm{};

    if(lpdm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdm, &stlpdm, sizeof(stlpdm));
    }


    HDC ResetDCAResult = ResetDCA((HDC)hdc,(const DEVMODEA *)&stlpdm);


    uc_reg_write(uc, UC_X86_REG_RAX, &ResetDCAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdm);

    if(lpdm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdm, &stlpdm, sizeof(stlpdm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuResetDCA\n";
    #endif

    return;
}


/*
HDC
__cdecl
ResetDCW(
      HDC               hdc   ,
      const DEVMODEW *  lpdm  );

*/
void EmuApi::EmuResetDCW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PDEVMODEW lpdm{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdm);

    DEVMODEW stlpdm{};

    if(lpdm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdm, &stlpdm, sizeof(stlpdm));
    }


    HDC ResetDCWResult = ResetDCW((HDC)hdc,(const DEVMODEW *)&stlpdm);


    uc_reg_write(uc, UC_X86_REG_RAX, &ResetDCWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdm);

    if(lpdm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdm, &stlpdm, sizeof(stlpdm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuResetDCW\n";
    #endif

    return;
}


/*
UINT
__cdecl
RealizePalette(
      HDC  hdc  );

*/
void EmuApi::EmuRealizePalette(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    UINT RealizePaletteResult = RealizePalette((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &RealizePaletteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRealizePalette\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveFontResourceA(
      LPCSTR  lpFileName  );

*/
void EmuApi::EmuRemoveFontResourceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in RemoveFontResourceA"); _CrtDbgBreak(); }


    BOOL RemoveFontResourceAResult = RemoveFontResourceA((LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveFontResourceAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in RemoveFontResourceA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveFontResourceA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveFontResourceW(
      LPCWSTR  lpFileName  );

*/
void EmuApi::EmuRemoveFontResourceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in RemoveFontResourceW"); _CrtDbgBreak(); }


    BOOL RemoveFontResourceWResult = RemoveFontResourceW((LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveFontResourceWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in RemoveFontResourceW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveFontResourceW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RoundRect(
      HDC  hdc     ,
      int  left    ,
      int  top     ,
      int  right   ,
      int  bottom  ,
      int  width   ,
      int  height  );

*/
void EmuApi::EmuRoundRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int left{};
    uc_reg_read(uc, UC_X86_REG_EDX, &left);

    int top{};
    uc_reg_read(uc, UC_X86_REG_R8D, &top);

    int right{};
    uc_reg_read(uc, UC_X86_REG_R9D, &right);

    int bottom{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));

    int width{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &width, sizeof(width));

    int height{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &height, sizeof(height));


    BOOL RoundRectResult = RoundRect((HDC)hdc,(int)left,(int)top,(int)right,(int)bottom,(int)width,(int)height);


    uc_reg_write(uc, UC_X86_REG_EAX, &RoundRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &left);
    uc_reg_write(uc, UC_X86_REG_R8D, &top);
    uc_reg_write(uc, UC_X86_REG_R9D, &right);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &width, sizeof(width));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &height, sizeof(height));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRoundRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ResizePalette(
      HPALETTE  hpal  ,
      UINT      n     );

*/
void EmuApi::EmuResizePalette(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HPALETTE hpal{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hpal);

    UINT n{};
    uc_reg_read(uc, UC_X86_REG_EDX, &n);


    BOOL ResizePaletteResult = ResizePalette((HPALETTE)hpal,(UINT)n);


    uc_reg_write(uc, UC_X86_REG_EAX, &ResizePaletteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hpal);
    uc_reg_write(uc, UC_X86_REG_EDX, &n);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuResizePalette\n";
    #endif

    return;
}


/*
int
__cdecl
SaveDC(
      HDC  hdc  );

*/
void EmuApi::EmuSaveDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int SaveDCResult = SaveDC((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &SaveDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSaveDC\n";
    #endif

    return;
}


/*
int
__cdecl
SelectClipRgn(
      HDC   hdc   ,
      HRGN  hrgn  );

*/
void EmuApi::EmuSelectClipRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn);


    int SelectClipRgnResult = SelectClipRgn((HDC)hdc,(HRGN)hrgn);


    uc_reg_write(uc, UC_X86_REG_EAX, &SelectClipRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSelectClipRgn\n";
    #endif

    return;
}


/*
int
__cdecl
ExtSelectClipRgn(
      HDC   hdc   ,
      HRGN  hrgn  ,
      int   mode  );

*/
void EmuApi::EmuExtSelectClipRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgn);

    int mode{};
    uc_reg_read(uc, UC_X86_REG_R8D, &mode);


    int ExtSelectClipRgnResult = ExtSelectClipRgn((HDC)hdc,(HRGN)hrgn,(int)mode);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExtSelectClipRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_R8D, &mode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExtSelectClipRgn\n";
    #endif

    return;
}


/*
int
__cdecl
SetMetaRgn(
      HDC  hdc  );

*/
void EmuApi::EmuSetMetaRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int SetMetaRgnResult = SetMetaRgn((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMetaRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMetaRgn\n";
    #endif

    return;
}


/*
HGDIOBJ
__cdecl
SelectObject(
      HDC      hdc  ,
      HGDIOBJ  h    );

*/
void EmuApi::EmuSelectObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HGDIOBJ h{};
    uc_reg_read(uc, UC_X86_REG_RDX, &h);


    HGDIOBJ SelectObjectResult = SelectObject((HDC)hdc,(HGDIOBJ)&h);


    uc_reg_write(uc, UC_X86_REG_RAX, &SelectObjectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &h);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSelectObject\n";
    #endif

    return;
}


/*
HPALETTE
__cdecl
SelectPalette(
      HDC       hdc         ,
      HPALETTE  hPal        ,
      BOOL      bForceBkgd  );

*/
void EmuApi::EmuSelectPalette(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HPALETTE hPal{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hPal);

    BOOL bForceBkgd{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bForceBkgd);


    HPALETTE SelectPaletteResult = SelectPalette((HDC)hdc,(HPALETTE)hPal,(BOOL)bForceBkgd);


    uc_reg_write(uc, UC_X86_REG_RAX, &SelectPaletteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hPal);
    uc_reg_write(uc, UC_X86_REG_R8D, &bForceBkgd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSelectPalette\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
SetBkColor(
      HDC       hdc    ,
      COLORREF  color  );

*/
void EmuApi::EmuSetBkColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_EDX, &color);


    COLORREF SetBkColorResult = SetBkColor((HDC)hdc,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetBkColorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetBkColor\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
SetDCBrushColor(
      HDC       hdc    ,
      COLORREF  color  );

*/
void EmuApi::EmuSetDCBrushColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_EDX, &color);


    COLORREF SetDCBrushColorResult = SetDCBrushColor((HDC)hdc,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDCBrushColorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDCBrushColor\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
SetDCPenColor(
      HDC       hdc    ,
      COLORREF  color  );

*/
void EmuApi::EmuSetDCPenColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_EDX, &color);


    COLORREF SetDCPenColorResult = SetDCPenColor((HDC)hdc,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDCPenColorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDCPenColor\n";
    #endif

    return;
}


/*
int
__cdecl
SetBkMode(
      HDC  hdc   ,
      int  mode  );

*/
void EmuApi::EmuSetBkMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int mode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &mode);


    int SetBkModeResult = SetBkMode((HDC)hdc,(int)mode);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetBkModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &mode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetBkMode\n";
    #endif

    return;
}


/*
LONG
__cdecl
SetBitmapBits(
      HBITMAP       hbm     ,
      DWORD         cb      ,
      const void *  pvBits  );

*/
void EmuApi::EmuSetBitmapBits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HBITMAP hbm{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hbm);

    DWORD cb{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cb);

    PVOID pvBits{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvBits);


    LONG SetBitmapBitsResult = SetBitmapBits((HBITMAP)hbm,(DWORD)cb,(const void *)&pvBits);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetBitmapBitsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hbm);
    uc_reg_write(uc, UC_X86_REG_EDX, &cb);
    uc_reg_write(uc, UC_X86_REG_R8, &pvBits);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetBitmapBits\n";
    #endif

    return;
}


/*
UINT
__cdecl
SetBoundsRect(
      HDC           hdc     ,
      const RECT *  lprect  ,
      UINT          flags   );

*/
void EmuApi::EmuSetBoundsRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PRECT lprect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprect);

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }

    UINT flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flags);


    UINT SetBoundsRectResult = SetBoundsRect((HDC)hdc,(const RECT *)&stlprect,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetBoundsRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprect);

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetBoundsRect\n";
    #endif

    return;
}


/*
int
__cdecl
SetDIBits(
      HDC                 hdc       ,
      HBITMAP             hbm       ,
      UINT                start     ,
      UINT                cLines    ,
      const void *        lpBits    ,
      const BITMAPINFO *  lpbmi     ,
      UINT                ColorUse  );

*/
void EmuApi::EmuSetDIBits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HBITMAP hbm{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hbm);

    UINT start{};
    uc_reg_read(uc, UC_X86_REG_R8D, &start);

    UINT cLines{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cLines);

    PVOID lpBits{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpBits, sizeof(lpBits));

    PBITMAPINFO lpbmi{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpbmi, sizeof(lpbmi));

    BITMAPINFO stlpbmi{};

    if(lpbmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpbmi, &stlpbmi, sizeof(stlpbmi));
    }

    UINT ColorUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &ColorUse, sizeof(ColorUse));


    int SetDIBitsResult = SetDIBits((HDC)hdc,(HBITMAP)hbm,(UINT)start,(UINT)cLines,(const void *)&lpBits,(const BITMAPINFO *)&stlpbmi,(UINT)ColorUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDIBitsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hbm);
    uc_reg_write(uc, UC_X86_REG_R8D, &start);
    uc_reg_write(uc, UC_X86_REG_R9D, &cLines);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpBits, sizeof(lpBits));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpbmi, sizeof(lpbmi));

    if(lpbmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpbmi, &stlpbmi, sizeof(stlpbmi));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ColorUse, sizeof(ColorUse));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDIBits\n";
    #endif

    return;
}


/*
int
__cdecl
SetDIBitsToDevice(
      HDC                 hdc        ,
      int                 xDest      ,
      int                 yDest      ,
      DWORD               w          ,
      DWORD               h          ,
      int                 xSrc       ,
      int                 ySrc       ,
      UINT                StartScan  ,
      UINT                cLines     ,
      const void *        lpvBits    ,
      const BITMAPINFO *  lpbmi      ,
      UINT                ColorUse   );

*/
void EmuApi::EmuSetDIBitsToDevice(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int xDest{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xDest);

    int yDest{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yDest);

    DWORD w{};
    uc_reg_read(uc, UC_X86_REG_R9D, &w);

    DWORD h{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &h, sizeof(h));

    int xSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &xSrc, sizeof(xSrc));

    int ySrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &ySrc, sizeof(ySrc));

    UINT StartScan{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &StartScan, sizeof(StartScan));

    UINT cLines{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &cLines, sizeof(cLines));

    PVOID lpvBits{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lpvBits, sizeof(lpvBits));

    PBITMAPINFO lpbmi{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &lpbmi, sizeof(lpbmi));

    BITMAPINFO stlpbmi{};

    if(lpbmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpbmi, &stlpbmi, sizeof(stlpbmi));
    }

    UINT ColorUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &ColorUse, sizeof(ColorUse));


    int SetDIBitsToDeviceResult = SetDIBitsToDevice((HDC)hdc,(int)xDest,(int)yDest,(DWORD)w,(DWORD)h,(int)xSrc,(int)ySrc,(UINT)StartScan,(UINT)cLines,(const void *)&lpvBits,(const BITMAPINFO *)&stlpbmi,(UINT)ColorUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDIBitsToDeviceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &xDest);
    uc_reg_write(uc, UC_X86_REG_R8D, &yDest);
    uc_reg_write(uc, UC_X86_REG_R9D, &w);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &h, sizeof(h));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &xSrc, sizeof(xSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ySrc, sizeof(ySrc));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &StartScan, sizeof(StartScan));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &cLines, sizeof(cLines));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &lpvBits, sizeof(lpvBits));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &lpbmi, sizeof(lpbmi));

    if(lpbmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpbmi, &stlpbmi, sizeof(stlpbmi));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+96, &ColorUse, sizeof(ColorUse));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDIBitsToDevice\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SetMapperFlags(
      HDC    hdc    ,
      DWORD  flags  );

*/
void EmuApi::EmuSetMapperFlags(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    DWORD flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &flags);


    DWORD SetMapperFlagsResult = SetMapperFlags((HDC)hdc,(DWORD)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMapperFlagsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMapperFlags\n";
    #endif

    return;
}


/*
int
__cdecl
SetGraphicsMode(
      HDC  hdc    ,
      int  iMode  );

*/
void EmuApi::EmuSetGraphicsMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int iMode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iMode);


    int SetGraphicsModeResult = SetGraphicsMode((HDC)hdc,(int)iMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetGraphicsModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iMode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetGraphicsMode\n";
    #endif

    return;
}


/*
int
__cdecl
SetMapMode(
      HDC  hdc    ,
      int  iMode  );

*/
void EmuApi::EmuSetMapMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int iMode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iMode);


    int SetMapModeResult = SetMapMode((HDC)hdc,(int)iMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMapModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iMode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMapMode\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SetLayout(
      HDC    hdc  ,
      DWORD  l    );

*/
void EmuApi::EmuSetLayout(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    DWORD l{};
    uc_reg_read(uc, UC_X86_REG_EDX, &l);


    DWORD SetLayoutResult = SetLayout((HDC)hdc,(DWORD)l);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetLayoutResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &l);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetLayout\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetLayout(
      HDC  hdc  );

*/
void EmuApi::EmuGetLayout(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    DWORD GetLayoutResult = GetLayout((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLayoutResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLayout\n";
    #endif

    return;
}


/*
HMETAFILE
__cdecl
SetMetaFileBitsEx(
      UINT          cbBuffer  ,
      const BYTE *  lpData    );

*/
void EmuApi::EmuSetMetaFileBitsEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT cbBuffer{};
    uc_reg_read(uc, UC_X86_REG_ECX, &cbBuffer);

    PBYTE lpData{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpData);

    BYTE rllpData{};

    if(lpData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpData, &rllpData, sizeof(rllpData));
    }


    HMETAFILE SetMetaFileBitsExResult = SetMetaFileBitsEx((UINT)cbBuffer,(const BYTE *)&rllpData);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetMetaFileBitsExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &cbBuffer);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpData);

    if(lpData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpData, &rllpData, sizeof(rllpData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMetaFileBitsEx\n";
    #endif

    return;
}


/*
UINT
__cdecl
SetPaletteEntries(
      HPALETTE              hpal         ,
      UINT                  iStart       ,
      UINT                  cEntries     ,
      const PALETTEENTRY *  pPalEntries  );

*/
void EmuApi::EmuSetPaletteEntries(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HPALETTE hpal{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hpal);

    UINT iStart{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iStart);

    UINT cEntries{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cEntries);

    PALETTEENTRY pPalEntries{};
    uc_reg_read(uc, UC_X86_REG_R9, &pPalEntries);


    UINT SetPaletteEntriesResult = SetPaletteEntries((HPALETTE)hpal,(UINT)iStart,(UINT)cEntries,(const PALETTEENTRY *)&pPalEntries);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetPaletteEntriesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hpal);
    uc_reg_write(uc, UC_X86_REG_EDX, &iStart);
    uc_reg_write(uc, UC_X86_REG_R8D, &cEntries);
    uc_reg_write(uc, UC_X86_REG_R9, &pPalEntries);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetPaletteEntries\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
SetPixel(
      HDC       hdc    ,
      int       x      ,
      int       y      ,
      COLORREF  color  );

*/
void EmuApi::EmuSetPixel(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_R9D, &color);


    COLORREF SetPixelResult = SetPixel((HDC)hdc,(int)x,(int)y,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetPixelResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9D, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetPixel\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetPixelV(
      HDC       hdc    ,
      int       x      ,
      int       y      ,
      COLORREF  color  );

*/
void EmuApi::EmuSetPixelV(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_R9D, &color);


    BOOL SetPixelVResult = SetPixelV((HDC)hdc,(int)x,(int)y,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetPixelVResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9D, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetPixelV\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetPixelFormat(
      HDC                            hdc     ,
      int                            format  ,
      const PIXELFORMATDESCRIPTOR *  ppfd    );

*/
void EmuApi::EmuSetPixelFormat(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int format{};
    uc_reg_read(uc, UC_X86_REG_EDX, &format);

    PIXELFORMATDESCRIPTOR ppfd{};
    uc_reg_read(uc, UC_X86_REG_R8, &ppfd);


    BOOL SetPixelFormatResult = SetPixelFormat((HDC)hdc,(int)format,(const PIXELFORMATDESCRIPTOR *)&ppfd);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetPixelFormatResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &format);
    uc_reg_write(uc, UC_X86_REG_R8, &ppfd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetPixelFormat\n";
    #endif

    return;
}


/*
int
__cdecl
SetPolyFillMode(
      HDC  hdc   ,
      int  mode  );

*/
void EmuApi::EmuSetPolyFillMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int mode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &mode);


    int SetPolyFillModeResult = SetPolyFillMode((HDC)hdc,(int)mode);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetPolyFillModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &mode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetPolyFillMode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
StretchBlt(
      HDC    hdcDest  ,
      int    xDest    ,
      int    yDest    ,
      int    wDest    ,
      int    hDest    ,
      HDC    hdcSrc   ,
      int    xSrc     ,
      int    ySrc     ,
      int    wSrc     ,
      int    hSrc     ,
      DWORD  rop      );

*/
void EmuApi::EmuStretchBlt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdcDest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdcDest);

    int xDest{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xDest);

    int yDest{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yDest);

    int wDest{};
    uc_reg_read(uc, UC_X86_REG_R9D, &wDest);

    int hDest{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));

    HDC hdcSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));

    int xSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &xSrc, sizeof(xSrc));

    int ySrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &ySrc, sizeof(ySrc));

    int wSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));

    int hSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));

    DWORD rop{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &rop, sizeof(rop));


    BOOL StretchBltResult = StretchBlt((HDC)hdcDest,(int)xDest,(int)yDest,(int)wDest,(int)hDest,(HDC)hdcSrc,(int)xSrc,(int)ySrc,(int)wSrc,(int)hSrc,(DWORD)rop);


    uc_reg_write(uc, UC_X86_REG_EAX, &StretchBltResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdcDest);
    uc_reg_write(uc, UC_X86_REG_EDX, &xDest);
    uc_reg_write(uc, UC_X86_REG_R8D, &yDest);
    uc_reg_write(uc, UC_X86_REG_R9D, &wDest);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &xSrc, sizeof(xSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &ySrc, sizeof(ySrc));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &rop, sizeof(rop));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuStretchBlt\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetRectRgn(
      HRGN  hrgn    ,
      int   left    ,
      int   top     ,
      int   right   ,
      int   bottom  );

*/
void EmuApi::EmuSetRectRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HRGN hrgn{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hrgn);

    int left{};
    uc_reg_read(uc, UC_X86_REG_EDX, &left);

    int top{};
    uc_reg_read(uc, UC_X86_REG_R8D, &top);

    int right{};
    uc_reg_read(uc, UC_X86_REG_R9D, &right);

    int bottom{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));


    BOOL SetRectRgnResult = SetRectRgn((HRGN)hrgn,(int)left,(int)top,(int)right,(int)bottom);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetRectRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hrgn);
    uc_reg_write(uc, UC_X86_REG_EDX, &left);
    uc_reg_write(uc, UC_X86_REG_R8D, &top);
    uc_reg_write(uc, UC_X86_REG_R9D, &right);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetRectRgn\n";
    #endif

    return;
}


/*
int
__cdecl
StretchDIBits(
      HDC                 hdc         ,
      int                 xDest       ,
      int                 yDest       ,
      int                 DestWidth   ,
      int                 DestHeight  ,
      int                 xSrc        ,
      int                 ySrc        ,
      int                 SrcWidth    ,
      int                 SrcHeight   ,
      const void *        lpBits      ,
      const BITMAPINFO *  lpbmi       ,
      UINT                iUsage      ,
      DWORD               rop         );

*/
void EmuApi::EmuStretchDIBits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int xDest{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xDest);

    int yDest{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yDest);

    int DestWidth{};
    uc_reg_read(uc, UC_X86_REG_R9D, &DestWidth);

    int DestHeight{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &DestHeight, sizeof(DestHeight));

    int xSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &xSrc, sizeof(xSrc));

    int ySrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &ySrc, sizeof(ySrc));

    int SrcWidth{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &SrcWidth, sizeof(SrcWidth));

    int SrcHeight{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &SrcHeight, sizeof(SrcHeight));

    PVOID lpBits{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lpBits, sizeof(lpBits));

    PBITMAPINFO lpbmi{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &lpbmi, sizeof(lpbmi));

    BITMAPINFO stlpbmi{};

    if(lpbmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpbmi, &stlpbmi, sizeof(stlpbmi));
    }

    UINT iUsage{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &iUsage, sizeof(iUsage));

    DWORD rop{};
    uc_mem_read(uc, (DWORD_PTR)SP+104, &rop, sizeof(rop));


    int StretchDIBitsResult = StretchDIBits((HDC)hdc,(int)xDest,(int)yDest,(int)DestWidth,(int)DestHeight,(int)xSrc,(int)ySrc,(int)SrcWidth,(int)SrcHeight,(const void *)&lpBits,(const BITMAPINFO *)&stlpbmi,(UINT)iUsage,(DWORD)rop);


    uc_reg_write(uc, UC_X86_REG_EAX, &StretchDIBitsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &xDest);
    uc_reg_write(uc, UC_X86_REG_R8D, &yDest);
    uc_reg_write(uc, UC_X86_REG_R9D, &DestWidth);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &DestHeight, sizeof(DestHeight));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &xSrc, sizeof(xSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ySrc, sizeof(ySrc));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &SrcWidth, sizeof(SrcWidth));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &SrcHeight, sizeof(SrcHeight));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &lpBits, sizeof(lpBits));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &lpbmi, sizeof(lpbmi));

    if(lpbmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpbmi, &stlpbmi, sizeof(stlpbmi));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+96, &iUsage, sizeof(iUsage));
    uc_mem_write(uc, (DWORD_PTR)SP+104, &rop, sizeof(rop));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuStretchDIBits\n";
    #endif

    return;
}


/*
int
__cdecl
SetROP2(
      HDC  hdc   ,
      int  rop2  );

*/
void EmuApi::EmuSetROP2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int rop2{};
    uc_reg_read(uc, UC_X86_REG_EDX, &rop2);


    int SetROP2Result = SetROP2((HDC)hdc,(int)rop2);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetROP2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &rop2);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetROP2\n";
    #endif

    return;
}


/*
int
__cdecl
SetStretchBltMode(
      HDC  hdc   ,
      int  mode  );

*/
void EmuApi::EmuSetStretchBltMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int mode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &mode);


    int SetStretchBltModeResult = SetStretchBltMode((HDC)hdc,(int)mode);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetStretchBltModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &mode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetStretchBltMode\n";
    #endif

    return;
}


/*
UINT
__cdecl
SetSystemPaletteUse(
      HDC   hdc  ,
      UINT  use  );

*/
void EmuApi::EmuSetSystemPaletteUse(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT use{};
    uc_reg_read(uc, UC_X86_REG_EDX, &use);


    UINT SetSystemPaletteUseResult = SetSystemPaletteUse((HDC)hdc,(UINT)use);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetSystemPaletteUseResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &use);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetSystemPaletteUse\n";
    #endif

    return;
}


/*
int
__cdecl
SetTextCharacterExtra(
      HDC  hdc    ,
      int  extra  );

*/
void EmuApi::EmuSetTextCharacterExtra(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int extra{};
    uc_reg_read(uc, UC_X86_REG_EDX, &extra);


    int SetTextCharacterExtraResult = SetTextCharacterExtra((HDC)hdc,(int)extra);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetTextCharacterExtraResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &extra);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetTextCharacterExtra\n";
    #endif

    return;
}


/*
COLORREF
__cdecl
SetTextColor(
      HDC       hdc    ,
      COLORREF  color  );

*/
void EmuApi::EmuSetTextColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    COLORREF color{};
    uc_reg_read(uc, UC_X86_REG_EDX, &color);


    COLORREF SetTextColorResult = SetTextColor((HDC)hdc,(COLORREF)color);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetTextColorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &color);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetTextColor\n";
    #endif

    return;
}


/*
UINT
__cdecl
SetTextAlign(
      HDC   hdc    ,
      UINT  align  );

*/
void EmuApi::EmuSetTextAlign(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT align{};
    uc_reg_read(uc, UC_X86_REG_EDX, &align);


    UINT SetTextAlignResult = SetTextAlign((HDC)hdc,(UINT)align);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetTextAlignResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &align);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetTextAlign\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetTextJustification(
      HDC  hdc    ,
      int  extra  ,
      int  count  );

*/
void EmuApi::EmuSetTextJustification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int extra{};
    uc_reg_read(uc, UC_X86_REG_EDX, &extra);

    int count{};
    uc_reg_read(uc, UC_X86_REG_R8D, &count);


    BOOL SetTextJustificationResult = SetTextJustification((HDC)hdc,(int)extra,(int)count);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetTextJustificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &extra);
    uc_reg_write(uc, UC_X86_REG_R8D, &count);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetTextJustification\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UpdateColors(
      HDC  hdc  );

*/
void EmuApi::EmuUpdateColors(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL UpdateColorsResult = UpdateColors((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &UpdateColorsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUpdateColors\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AlphaBlend(
      HDC            hdcDest      ,
      int            xoriginDest  ,
      int            yoriginDest  ,
      int            wDest        ,
      int            hDest        ,
      HDC            hdcSrc       ,
      int            xoriginSrc   ,
      int            yoriginSrc   ,
      int            wSrc         ,
      int            hSrc         ,
      BLENDFUNCTION  ftn          );

*/
void EmuApi::EmuAlphaBlend(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdcDest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdcDest);

    int xoriginDest{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xoriginDest);

    int yoriginDest{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yoriginDest);

    int wDest{};
    uc_reg_read(uc, UC_X86_REG_R9D, &wDest);

    int hDest{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));

    HDC hdcSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));

    int xoriginSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &xoriginSrc, sizeof(xoriginSrc));

    int yoriginSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &yoriginSrc, sizeof(yoriginSrc));

    int wSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));

    int hSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));

    BLENDFUNCTION ftn{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &ftn, sizeof(ftn));


    BOOL AlphaBlendResult = AlphaBlend((HDC)hdcDest,(int)xoriginDest,(int)yoriginDest,(int)wDest,(int)hDest,(HDC)hdcSrc,(int)xoriginSrc,(int)yoriginSrc,(int)wSrc,(int)hSrc,(BLENDFUNCTION)ftn);


    uc_reg_write(uc, UC_X86_REG_EAX, &AlphaBlendResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdcDest);
    uc_reg_write(uc, UC_X86_REG_EDX, &xoriginDest);
    uc_reg_write(uc, UC_X86_REG_R8D, &yoriginDest);
    uc_reg_write(uc, UC_X86_REG_R9D, &wDest);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &xoriginSrc, sizeof(xoriginSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &yoriginSrc, sizeof(yoriginSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &ftn, sizeof(ftn));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAlphaBlend\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TransparentBlt(
      HDC   hdcDest        ,
      int   xoriginDest    ,
      int   yoriginDest    ,
      int   wDest          ,
      int   hDest          ,
      HDC   hdcSrc         ,
      int   xoriginSrc     ,
      int   yoriginSrc     ,
      int   wSrc           ,
      int   hSrc           ,
      UINT  crTransparent  );

*/
void EmuApi::EmuTransparentBlt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdcDest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdcDest);

    int xoriginDest{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xoriginDest);

    int yoriginDest{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yoriginDest);

    int wDest{};
    uc_reg_read(uc, UC_X86_REG_R9D, &wDest);

    int hDest{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));

    HDC hdcSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));

    int xoriginSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &xoriginSrc, sizeof(xoriginSrc));

    int yoriginSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &yoriginSrc, sizeof(yoriginSrc));

    int wSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));

    int hSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));

    UINT crTransparent{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &crTransparent, sizeof(crTransparent));


    BOOL TransparentBltResult = TransparentBlt((HDC)hdcDest,(int)xoriginDest,(int)yoriginDest,(int)wDest,(int)hDest,(HDC)hdcSrc,(int)xoriginSrc,(int)yoriginSrc,(int)wSrc,(int)hSrc,(UINT)crTransparent);


    uc_reg_write(uc, UC_X86_REG_EAX, &TransparentBltResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdcDest);
    uc_reg_write(uc, UC_X86_REG_EDX, &xoriginDest);
    uc_reg_write(uc, UC_X86_REG_R8D, &yoriginDest);
    uc_reg_write(uc, UC_X86_REG_R9D, &wDest);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &xoriginSrc, sizeof(xoriginSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &yoriginSrc, sizeof(yoriginSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &crTransparent, sizeof(crTransparent));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTransparentBlt\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GradientFill(
      HDC         hdc      ,
      PTRIVERTEX  pVertex  ,
      ULONG       nVertex  ,
      PVOID       pMesh    ,
      ULONG       nMesh    ,
      ULONG       ulMode   );

*/
void EmuApi::EmuGradientFill(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PTRIVERTEX pVertex{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pVertex);

    TRIVERTEX stpVertex{};

    if(pVertex != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pVertex, &stpVertex, sizeof(stpVertex));
    }

    ULONG nVertex{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nVertex);

    PVOID pMesh{};
    uc_reg_read(uc, UC_X86_REG_R9, &pMesh);

    ULONG nMesh{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nMesh, sizeof(nMesh));

    ULONG ulMode{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &ulMode, sizeof(ulMode));


    BOOL GradientFillResult = GradientFill((HDC)hdc,(PTRIVERTEX)&stpVertex,(ULONG)nVertex,(PVOID)&pMesh,(ULONG)nMesh,(ULONG)ulMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &GradientFillResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &pVertex);

    if(pVertex != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pVertex, &stpVertex, sizeof(stpVertex));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &nVertex);
    uc_reg_write(uc, UC_X86_REG_R9, &pMesh);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nMesh, sizeof(nMesh));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &ulMode, sizeof(ulMode));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGradientFill\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GdiAlphaBlend(
      HDC            hdcDest      ,
      int            xoriginDest  ,
      int            yoriginDest  ,
      int            wDest        ,
      int            hDest        ,
      HDC            hdcSrc       ,
      int            xoriginSrc   ,
      int            yoriginSrc   ,
      int            wSrc         ,
      int            hSrc         ,
      BLENDFUNCTION  ftn          );

*/
void EmuApi::EmuGdiAlphaBlend(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdcDest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdcDest);

    int xoriginDest{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xoriginDest);

    int yoriginDest{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yoriginDest);

    int wDest{};
    uc_reg_read(uc, UC_X86_REG_R9D, &wDest);

    int hDest{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));

    HDC hdcSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));

    int xoriginSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &xoriginSrc, sizeof(xoriginSrc));

    int yoriginSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &yoriginSrc, sizeof(yoriginSrc));

    int wSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));

    int hSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));

    BLENDFUNCTION ftn{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &ftn, sizeof(ftn));


    BOOL GdiAlphaBlendResult = GdiAlphaBlend((HDC)hdcDest,(int)xoriginDest,(int)yoriginDest,(int)wDest,(int)hDest,(HDC)hdcSrc,(int)xoriginSrc,(int)yoriginSrc,(int)wSrc,(int)hSrc,(BLENDFUNCTION)ftn);


    uc_reg_write(uc, UC_X86_REG_EAX, &GdiAlphaBlendResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdcDest);
    uc_reg_write(uc, UC_X86_REG_EDX, &xoriginDest);
    uc_reg_write(uc, UC_X86_REG_R8D, &yoriginDest);
    uc_reg_write(uc, UC_X86_REG_R9D, &wDest);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &xoriginSrc, sizeof(xoriginSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &yoriginSrc, sizeof(yoriginSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &ftn, sizeof(ftn));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGdiAlphaBlend\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GdiTransparentBlt(
      HDC   hdcDest        ,
      int   xoriginDest    ,
      int   yoriginDest    ,
      int   wDest          ,
      int   hDest          ,
      HDC   hdcSrc         ,
      int   xoriginSrc     ,
      int   yoriginSrc     ,
      int   wSrc           ,
      int   hSrc           ,
      UINT  crTransparent  );

*/
void EmuApi::EmuGdiTransparentBlt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdcDest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdcDest);

    int xoriginDest{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xoriginDest);

    int yoriginDest{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yoriginDest);

    int wDest{};
    uc_reg_read(uc, UC_X86_REG_R9D, &wDest);

    int hDest{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));

    HDC hdcSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));

    int xoriginSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &xoriginSrc, sizeof(xoriginSrc));

    int yoriginSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &yoriginSrc, sizeof(yoriginSrc));

    int wSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));

    int hSrc{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));

    UINT crTransparent{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &crTransparent, sizeof(crTransparent));


    BOOL GdiTransparentBltResult = GdiTransparentBlt((HDC)hdcDest,(int)xoriginDest,(int)yoriginDest,(int)wDest,(int)hDest,(HDC)hdcSrc,(int)xoriginSrc,(int)yoriginSrc,(int)wSrc,(int)hSrc,(UINT)crTransparent);


    uc_reg_write(uc, UC_X86_REG_EAX, &GdiTransparentBltResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdcDest);
    uc_reg_write(uc, UC_X86_REG_EDX, &xoriginDest);
    uc_reg_write(uc, UC_X86_REG_R8D, &yoriginDest);
    uc_reg_write(uc, UC_X86_REG_R9D, &wDest);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hDest, sizeof(hDest));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hdcSrc, sizeof(hdcSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &xoriginSrc, sizeof(xoriginSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &yoriginSrc, sizeof(yoriginSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &wSrc, sizeof(wSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &hSrc, sizeof(hSrc));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &crTransparent, sizeof(crTransparent));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGdiTransparentBlt\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GdiGradientFill(
      HDC         hdc      ,
      PTRIVERTEX  pVertex  ,
      ULONG       nVertex  ,
      PVOID       pMesh    ,
      ULONG       nCount   ,
      ULONG       ulMode   );

*/
void EmuApi::EmuGdiGradientFill(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PTRIVERTEX pVertex{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pVertex);

    TRIVERTEX stpVertex{};

    if(pVertex != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pVertex, &stpVertex, sizeof(stpVertex));
    }

    ULONG nVertex{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nVertex);

    PVOID pMesh{};
    uc_reg_read(uc, UC_X86_REG_R9, &pMesh);

    ULONG nCount{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nCount, sizeof(nCount));

    ULONG ulMode{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &ulMode, sizeof(ulMode));


    BOOL GdiGradientFillResult = GdiGradientFill((HDC)hdc,(PTRIVERTEX)&stpVertex,(ULONG)nVertex,(PVOID)&pMesh,(ULONG)nCount,(ULONG)ulMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &GdiGradientFillResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &pVertex);

    if(pVertex != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pVertex, &stpVertex, sizeof(stpVertex));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &nVertex);
    uc_reg_write(uc, UC_X86_REG_R9, &pMesh);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nCount, sizeof(nCount));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &ulMode, sizeof(ulMode));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGdiGradientFill\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PlayMetaFileRecord(
      HDC            hdc            ,
      LPHANDLETABLE  lpHandleTable  ,
      LPMETARECORD   lpMR           ,
      UINT           noObjs         );

*/
void EmuApi::EmuPlayMetaFileRecord(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPHANDLETABLE lpHandleTable{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpHandleTable);

    HANDLETABLE stlpHandleTable{};

    if(lpHandleTable != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpHandleTable, &stlpHandleTable, sizeof(stlpHandleTable));
    }

    LPMETARECORD lpMR{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpMR);

    METARECORD stlpMR{};

    if(lpMR != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMR, &stlpMR, sizeof(stlpMR));
    }

    UINT noObjs{};
    uc_reg_read(uc, UC_X86_REG_R9D, &noObjs);


    BOOL PlayMetaFileRecordResult = PlayMetaFileRecord((HDC)hdc,(LPHANDLETABLE)&stlpHandleTable,(LPMETARECORD)&stlpMR,(UINT)noObjs);


    uc_reg_write(uc, UC_X86_REG_EAX, &PlayMetaFileRecordResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpHandleTable);

    if(lpHandleTable != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpHandleTable, &stlpHandleTable, sizeof(stlpHandleTable));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpMR);

    if(lpMR != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMR, &stlpMR, sizeof(stlpMR));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &noObjs);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPlayMetaFileRecord\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumMetaFile(
      HDC         hdc    ,
      HMETAFILE   hmf    ,
      MFENUMPROC  proc   ,
      LPARAM      param  );

*/
void EmuApi::EmuEnumMetaFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HMETAFILE hmf{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hmf);

    MFENUMPROC proc{};
    uc_reg_read(uc, UC_X86_REG_R8, &proc);

    LPARAM param{};
    uc_reg_read(uc, UC_X86_REG_R9, &param);


    BOOL EnumMetaFileResult = EnumMetaFile((HDC)hdc,(HMETAFILE)hmf,(MFENUMPROC)proc,(LPARAM)param);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumMetaFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hmf);
    uc_reg_write(uc, UC_X86_REG_R8, &proc);
    uc_reg_write(uc, UC_X86_REG_R9, &param);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumMetaFile\n";
    #endif

    return;
}


/*
HENHMETAFILE
__cdecl
CloseEnhMetaFile(
      HDC  hdc  );

*/
void EmuApi::EmuCloseEnhMetaFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    HENHMETAFILE CloseEnhMetaFileResult = CloseEnhMetaFile((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_RAX, &CloseEnhMetaFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseEnhMetaFile\n";
    #endif

    return;
}


/*
HENHMETAFILE
__cdecl
CopyEnhMetaFileA(
      HENHMETAFILE  hEnh        ,
      LPCSTR        lpFileName  );

*/
void EmuApi::EmuCopyEnhMetaFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hEnh{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEnh);

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CopyEnhMetaFileA"); _CrtDbgBreak(); }


    HENHMETAFILE CopyEnhMetaFileAResult = CopyEnhMetaFileA((HENHMETAFILE)hEnh,(LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CopyEnhMetaFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEnh);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CopyEnhMetaFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyEnhMetaFileA\n";
    #endif

    return;
}


/*
HENHMETAFILE
__cdecl
CopyEnhMetaFileW(
      HENHMETAFILE  hEnh        ,
      LPCWSTR       lpFileName  );

*/
void EmuApi::EmuCopyEnhMetaFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hEnh{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEnh);

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CopyEnhMetaFileW"); _CrtDbgBreak(); }


    HENHMETAFILE CopyEnhMetaFileWResult = CopyEnhMetaFileW((HENHMETAFILE)hEnh,(LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CopyEnhMetaFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEnh);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CopyEnhMetaFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyEnhMetaFileW\n";
    #endif

    return;
}


/*
HDC
__cdecl
CreateEnhMetaFileA(
      HDC           hdc         ,
      LPCSTR        lpFilename  ,
      const RECT *  lprc        ,
      LPCSTR        lpDesc      );

*/
void EmuApi::EmuCreateEnhMetaFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpFilename{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFilename);

    std::string rlalpFilename;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFilename, rlalpFilename)) { printf("Error when read lpFilename in CreateEnhMetaFileA"); _CrtDbgBreak(); }

    PRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    LPSTR lpDesc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDesc);

    std::string rlalpDesc;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDesc, rlalpDesc)) { printf("Error when read lpDesc in CreateEnhMetaFileA"); _CrtDbgBreak(); }


    HDC CreateEnhMetaFileAResult = CreateEnhMetaFileA((HDC)hdc,(LPCSTR)rlalpFilename.data(),(const RECT *)&stlprc,(LPCSTR)rlalpDesc.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateEnhMetaFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFilename, rlalpFilename)) { printf("Error when read lpFilename in CreateEnhMetaFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDesc, rlalpDesc)) { printf("Error when read lpDesc in CreateEnhMetaFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateEnhMetaFileA\n";
    #endif

    return;
}


/*
HDC
__cdecl
CreateEnhMetaFileW(
      HDC           hdc         ,
      LPCWSTR       lpFilename  ,
      const RECT *  lprc        ,
      LPCWSTR       lpDesc      );

*/
void EmuApi::EmuCreateEnhMetaFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpFilename{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFilename);

    std::wstring rlwlpFilename;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFilename, rlwlpFilename)) { printf("Error when read lpFilename in CreateEnhMetaFileW"); _CrtDbgBreak(); }

    PRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    LPWSTR lpDesc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDesc);

    std::wstring rlwlpDesc;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDesc, rlwlpDesc)) { printf("Error when read lpDesc in CreateEnhMetaFileW"); _CrtDbgBreak(); }


    HDC CreateEnhMetaFileWResult = CreateEnhMetaFileW((HDC)hdc,(LPCWSTR)rlwlpFilename.data(),(const RECT *)&stlprc,(LPCWSTR)rlwlpDesc.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateEnhMetaFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFilename, rlwlpFilename)) { printf("Error when read lpFilename in CreateEnhMetaFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDesc, rlwlpDesc)) { printf("Error when read lpDesc in CreateEnhMetaFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateEnhMetaFileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteEnhMetaFile(
      HENHMETAFILE  hmf  );

*/
void EmuApi::EmuDeleteEnhMetaFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hmf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hmf);


    BOOL DeleteEnhMetaFileResult = DeleteEnhMetaFile((HENHMETAFILE)hmf);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteEnhMetaFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hmf);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteEnhMetaFile\n";
    #endif

    return;
}

/*
HENHMETAFILE
__cdecl
GetEnhMetaFileA(
      LPCSTR  lpName  );

*/
void EmuApi::EmuGetEnhMetaFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetEnhMetaFileA"); _CrtDbgBreak(); }


    HENHMETAFILE GetEnhMetaFileAResult = GetEnhMetaFileA((LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &GetEnhMetaFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetEnhMetaFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnhMetaFileA\n";
    #endif

    return;
}


/*
HENHMETAFILE
__cdecl
GetEnhMetaFileW(
      LPCWSTR  lpName  );

*/
void EmuApi::EmuGetEnhMetaFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetEnhMetaFileW"); _CrtDbgBreak(); }


    HENHMETAFILE GetEnhMetaFileWResult = GetEnhMetaFileW((LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &GetEnhMetaFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetEnhMetaFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnhMetaFileW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetEnhMetaFileBits(
      HENHMETAFILE  hEMF    ,
      UINT          nSize   ,
      LPBYTE        lpData  );

*/
void EmuApi::EmuGetEnhMetaFileBits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hEMF{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEMF);

    UINT nSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nSize);

    LPBYTE lpData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpData);

    BYTE rllpData{};

    if(lpData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpData, &rllpData, sizeof(rllpData));
    }


    UINT GetEnhMetaFileBitsResult = GetEnhMetaFileBits((HENHMETAFILE)hEMF,(UINT)nSize,(LPBYTE)&rllpData);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetEnhMetaFileBitsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEMF);
    uc_reg_write(uc, UC_X86_REG_EDX, &nSize);
    uc_reg_write(uc, UC_X86_REG_R8, &lpData);

    if(lpData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpData, &rllpData, sizeof(rllpData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnhMetaFileBits\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetEnhMetaFileDescriptionA(
      HENHMETAFILE  hemf           ,
      UINT          cchBuffer      ,
      LPSTR         lpDescription  );

*/
void EmuApi::EmuGetEnhMetaFileDescriptionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hemf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hemf);

    UINT cchBuffer{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchBuffer);

    LPSTR lpDescription{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpDescription);

    std::string rlalpDescription;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDescription, rlalpDescription)) { printf("Error when read lpDescription in GetEnhMetaFileDescriptionA"); _CrtDbgBreak(); }


    UINT GetEnhMetaFileDescriptionAResult = GetEnhMetaFileDescriptionA((HENHMETAFILE)hemf,(UINT)cchBuffer,(LPSTR)rlalpDescription.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetEnhMetaFileDescriptionAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hemf);
    uc_reg_write(uc, UC_X86_REG_EDX, &cchBuffer);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDescription, rlalpDescription)) { printf("Error when read lpDescription in GetEnhMetaFileDescriptionA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnhMetaFileDescriptionA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetEnhMetaFileDescriptionW(
      HENHMETAFILE  hemf           ,
      UINT          cchBuffer      ,
      LPWSTR        lpDescription  );

*/
void EmuApi::EmuGetEnhMetaFileDescriptionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hemf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hemf);

    UINT cchBuffer{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchBuffer);

    LPWSTR lpDescription{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpDescription);

    std::wstring rlwlpDescription;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDescription, rlwlpDescription)) { printf("Error when read lpDescription in GetEnhMetaFileDescriptionW"); _CrtDbgBreak(); }


    UINT GetEnhMetaFileDescriptionWResult = GetEnhMetaFileDescriptionW((HENHMETAFILE)hemf,(UINT)cchBuffer,(LPWSTR)rlwlpDescription.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetEnhMetaFileDescriptionWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hemf);
    uc_reg_write(uc, UC_X86_REG_EDX, &cchBuffer);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDescription, rlwlpDescription)) { printf("Error when read lpDescription in GetEnhMetaFileDescriptionW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnhMetaFileDescriptionW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetEnhMetaFileHeader(
      HENHMETAFILE     hemf             ,
      UINT             nSize            ,
      LPENHMETAHEADER  lpEnhMetaHeader  );

*/
void EmuApi::EmuGetEnhMetaFileHeader(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hemf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hemf);

    UINT nSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nSize);

    LPENHMETAHEADER lpEnhMetaHeader{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpEnhMetaHeader);

    ENHMETAHEADER stlpEnhMetaHeader{};

    if(lpEnhMetaHeader != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpEnhMetaHeader, &stlpEnhMetaHeader, sizeof(stlpEnhMetaHeader));
    }


    UINT GetEnhMetaFileHeaderResult = GetEnhMetaFileHeader((HENHMETAFILE)hemf,(UINT)nSize,(LPENHMETAHEADER)&stlpEnhMetaHeader);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetEnhMetaFileHeaderResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hemf);
    uc_reg_write(uc, UC_X86_REG_EDX, &nSize);
    uc_reg_write(uc, UC_X86_REG_R8, &lpEnhMetaHeader);

    if(lpEnhMetaHeader != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpEnhMetaHeader, &stlpEnhMetaHeader, sizeof(stlpEnhMetaHeader));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnhMetaFileHeader\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetEnhMetaFilePaletteEntries(
      HENHMETAFILE    hemf              ,
      UINT            nNumEntries       ,
      LPPALETTEENTRY  lpPaletteEntries  );

*/
void EmuApi::EmuGetEnhMetaFilePaletteEntries(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hemf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hemf);

    UINT nNumEntries{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nNumEntries);

    LPPALETTEENTRY lpPaletteEntries{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpPaletteEntries);

    PALETTEENTRY stlpPaletteEntries{};

    if(lpPaletteEntries != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPaletteEntries, &stlpPaletteEntries, sizeof(stlpPaletteEntries));
    }


    UINT GetEnhMetaFilePaletteEntriesResult = GetEnhMetaFilePaletteEntries((HENHMETAFILE)hemf,(UINT)nNumEntries,(LPPALETTEENTRY)&stlpPaletteEntries);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetEnhMetaFilePaletteEntriesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hemf);
    uc_reg_write(uc, UC_X86_REG_EDX, &nNumEntries);
    uc_reg_write(uc, UC_X86_REG_R8, &lpPaletteEntries);

    if(lpPaletteEntries != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPaletteEntries, &stlpPaletteEntries, sizeof(stlpPaletteEntries));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnhMetaFilePaletteEntries\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetEnhMetaFilePixelFormat(
      HENHMETAFILE             hemf      ,
      UINT                     cbBuffer  ,
      PIXELFORMATDESCRIPTOR *  ppfd      );

*/
void EmuApi::EmuGetEnhMetaFilePixelFormat(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hemf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hemf);

    UINT cbBuffer{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cbBuffer);

    PIXELFORMATDESCRIPTOR * ppfd{};
    uc_reg_read(uc, UC_X86_REG_R8, &ppfd);

    PIXELFORMATDESCRIPTOR * dpppfd{};

    if(ppfd != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppfd, &dpppfd, sizeof(dpppfd));
    }


    UINT GetEnhMetaFilePixelFormatResult = GetEnhMetaFilePixelFormat((HENHMETAFILE)hemf,(UINT)cbBuffer,(PIXELFORMATDESCRIPTOR *)&ppfd);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetEnhMetaFilePixelFormatResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hemf);
    uc_reg_write(uc, UC_X86_REG_EDX, &cbBuffer);
    uc_reg_write(uc, UC_X86_REG_R8, &ppfd);

    if(ppfd != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ppfd, &dpppfd, sizeof(dpppfd));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnhMetaFilePixelFormat\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetWinMetaFileBits(
      HENHMETAFILE  hemf      ,
      UINT          cbData16  ,
      LPBYTE        pData16   ,
      INT           iMapMode  ,
      HDC           hdcRef    );

*/
void EmuApi::EmuGetWinMetaFileBits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HENHMETAFILE hemf{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hemf);

    UINT cbData16{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cbData16);

    LPBYTE pData16{};
    uc_reg_read(uc, UC_X86_REG_R8, &pData16);

    BYTE rlpData16{};

    if(pData16 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pData16, &rlpData16, sizeof(rlpData16));
    }

    INT iMapMode{};
    uc_reg_read(uc, UC_X86_REG_R9D, &iMapMode);

    HDC hdcRef{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hdcRef, sizeof(hdcRef));


    UINT GetWinMetaFileBitsResult = GetWinMetaFileBits((HENHMETAFILE)hemf,(UINT)cbData16,(LPBYTE)&rlpData16,(INT)iMapMode,(HDC)hdcRef);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWinMetaFileBitsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hemf);
    uc_reg_write(uc, UC_X86_REG_EDX, &cbData16);
    uc_reg_write(uc, UC_X86_REG_R8, &pData16);

    if(pData16 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pData16, &rlpData16, sizeof(rlpData16));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &iMapMode);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hdcRef, sizeof(hdcRef));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWinMetaFileBits\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PlayEnhMetaFile(
      HDC           hdc     ,
      HENHMETAFILE  hmf     ,
      const RECT *  lprect  );

*/
void EmuApi::EmuPlayEnhMetaFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HENHMETAFILE hmf{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hmf);

    PRECT lprect{};
    uc_reg_read(uc, UC_X86_REG_R8, &lprect);

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }


    BOOL PlayEnhMetaFileResult = PlayEnhMetaFile((HDC)hdc,(HENHMETAFILE)hmf,(const RECT *)&stlprect);


    uc_reg_write(uc, UC_X86_REG_EAX, &PlayEnhMetaFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hmf);
    uc_reg_write(uc, UC_X86_REG_R8, &lprect);

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPlayEnhMetaFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PlayEnhMetaFileRecord(
      HDC                    hdc  ,
      LPHANDLETABLE          pht  ,
      const ENHMETARECORD *  pmr  ,
      UINT                   cht  );

*/
void EmuApi::EmuPlayEnhMetaFileRecord(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPHANDLETABLE pht{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pht);

    HANDLETABLE stpht{};

    if(pht != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pht, &stpht, sizeof(stpht));
    }

    PENHMETARECORD pmr{};
    uc_reg_read(uc, UC_X86_REG_R8, &pmr);

    ENHMETARECORD stpmr{};

    if(pmr != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pmr, &stpmr, sizeof(stpmr));
    }

    UINT cht{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cht);


    BOOL PlayEnhMetaFileRecordResult = PlayEnhMetaFileRecord((HDC)hdc,(LPHANDLETABLE)&stpht,(const ENHMETARECORD *)&stpmr,(UINT)cht);


    uc_reg_write(uc, UC_X86_REG_EAX, &PlayEnhMetaFileRecordResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &pht);

    if(pht != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pht, &stpht, sizeof(stpht));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pmr);

    if(pmr != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pmr, &stpmr, sizeof(stpmr));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &cht);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPlayEnhMetaFileRecord\n";
    #endif

    return;
}


/*
HENHMETAFILE
__cdecl
SetEnhMetaFileBits(
      UINT          nSize  ,
      const BYTE *  pb     );

*/
void EmuApi::EmuSetEnhMetaFileBits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT nSize{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nSize);

    PBYTE pb{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pb);

    BYTE rlpb{};

    if(pb != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pb, &rlpb, sizeof(rlpb));
    }


    HENHMETAFILE SetEnhMetaFileBitsResult = SetEnhMetaFileBits((UINT)nSize,(const BYTE *)&rlpb);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetEnhMetaFileBitsResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nSize);
    uc_reg_write(uc, UC_X86_REG_RDX, &pb);

    if(pb != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pb, &rlpb, sizeof(rlpb));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetEnhMetaFileBits\n";
    #endif

    return;
}


/*
HENHMETAFILE
__cdecl
SetWinMetaFileBits(
      UINT                  nSize         ,
      const BYTE *          lpMeta16Data  ,
      HDC                   hdcRef        ,
      const METAFILEPICT *  lpMFP         );

*/
void EmuApi::EmuSetWinMetaFileBits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT nSize{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nSize);

    PBYTE lpMeta16Data{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMeta16Data);

    BYTE rllpMeta16Data{};

    if(lpMeta16Data != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMeta16Data, &rllpMeta16Data, sizeof(rllpMeta16Data));
    }

    HDC hdcRef{};
    uc_reg_read(uc, UC_X86_REG_R8, &hdcRef);

    METAFILEPICT * lpMFP{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpMFP);

    METAFILEPICT stlpMFP{};

    if(lpMFP != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMFP, &stlpMFP, sizeof(stlpMFP));
    }


    HENHMETAFILE SetWinMetaFileBitsResult = SetWinMetaFileBits((UINT)nSize,(const BYTE *)&rllpMeta16Data,(HDC)hdcRef,(const METAFILEPICT *)&stlpMFP);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetWinMetaFileBitsResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nSize);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpMeta16Data);

    if(lpMeta16Data != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMeta16Data, &rllpMeta16Data, sizeof(rllpMeta16Data));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hdcRef);
    uc_reg_write(uc, UC_X86_REG_R9, &lpMFP);

    if(lpMFP != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMFP, &stlpMFP, sizeof(stlpMFP));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWinMetaFileBits\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GdiComment(
      HDC           hdc     ,
      UINT          nSize   ,
      const BYTE *  lpData  );

*/
void EmuApi::EmuGdiComment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT nSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nSize);

    PBYTE lpData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpData);

    BYTE rllpData{};

    if(lpData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpData, &rllpData, sizeof(rllpData));
    }


    BOOL GdiCommentResult = GdiComment((HDC)hdc,(UINT)nSize,(const BYTE *)&rllpData);


    uc_reg_write(uc, UC_X86_REG_EAX, &GdiCommentResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &nSize);
    uc_reg_write(uc, UC_X86_REG_R8, &lpData);

    if(lpData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpData, &rllpData, sizeof(rllpData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGdiComment\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextMetricsA(
      HDC            hdc   ,
      LPTEXTMETRICA  lptm  );

*/
void EmuApi::EmuGetTextMetricsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPTEXTMETRICA lptm{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lptm);

    TEXTMETRICA stlptm{};

    if(lptm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lptm, &stlptm, sizeof(stlptm));
    }


    BOOL GetTextMetricsAResult = GetTextMetricsA((HDC)hdc,(LPTEXTMETRICA)&stlptm);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextMetricsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lptm);

    if(lptm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lptm, &stlptm, sizeof(stlptm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextMetricsA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTextMetricsW(
      HDC            hdc   ,
      LPTEXTMETRICW  lptm  );

*/
void EmuApi::EmuGetTextMetricsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPTEXTMETRICW lptm{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lptm);

    TEXTMETRICW stlptm{};

    if(lptm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lptm, &stlptm, sizeof(stlptm));
    }


    BOOL GetTextMetricsWResult = GetTextMetricsW((HDC)hdc,(LPTEXTMETRICW)&stlptm);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextMetricsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lptm);

    if(lptm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lptm, &stlptm, sizeof(stlptm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextMetricsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AngleArc(
      HDC    hdc         ,
      int    x           ,
      int    y           ,
      DWORD  r           ,
      FLOAT  StartAngle  ,
      FLOAT  SweepAngle  );

*/
void EmuApi::EmuAngleArc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    DWORD r{};
    uc_reg_read(uc, UC_X86_REG_R9D, &r);

    FLOAT StartAngle{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &StartAngle, sizeof(StartAngle));

    FLOAT SweepAngle{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &SweepAngle, sizeof(SweepAngle));


    BOOL AngleArcResult = AngleArc((HDC)hdc,(int)x,(int)y,(DWORD)r,(FLOAT)StartAngle,(FLOAT)SweepAngle);


    uc_reg_write(uc, UC_X86_REG_EAX, &AngleArcResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9D, &r);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &StartAngle, sizeof(StartAngle));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &SweepAngle, sizeof(SweepAngle));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAngleArc\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PolyPolyline(
      HDC            hdc  ,
      const POINT *  apt  ,
      const DWORD *  asz  ,
      DWORD          csz  );

*/
void EmuApi::EmuPolyPolyline(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POINT apt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &apt);

    PDWORD asz{};
    uc_reg_read(uc, UC_X86_REG_R8, &asz);

    DWORD rlasz{};

    if(asz != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)asz, &rlasz, sizeof(rlasz));
    }

    DWORD csz{};
    uc_reg_read(uc, UC_X86_REG_R9D, &csz);


    BOOL PolyPolylineResult = PolyPolyline((HDC)hdc,(const POINT *)&apt,(const DWORD *)&rlasz,(DWORD)csz);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolyPolylineResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &apt);
    uc_reg_write(uc, UC_X86_REG_R8, &asz);

    if(asz != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)asz, &rlasz, sizeof(rlasz));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &csz);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolyPolyline\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetWorldTransform(
      HDC      hdc   ,
      LPXFORM  lpxf  );

*/
void EmuApi::EmuGetWorldTransform(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPXFORM lpxf{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpxf);

    XFORM stlpxf{};

    if(lpxf != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpxf, &stlpxf, sizeof(stlpxf));
    }


    BOOL GetWorldTransformResult = GetWorldTransform((HDC)hdc,(LPXFORM)&stlpxf);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWorldTransformResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpxf);

    if(lpxf != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpxf, &stlpxf, sizeof(stlpxf));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWorldTransform\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWorldTransform(
      HDC            hdc   ,
      const XFORM *  lpxf  );

*/
void EmuApi::EmuSetWorldTransform(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PXFORM lpxf{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpxf);

    XFORM stlpxf{};

    if(lpxf != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpxf, &stlpxf, sizeof(stlpxf));
    }


    BOOL SetWorldTransformResult = SetWorldTransform((HDC)hdc,(const XFORM *)&stlpxf);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWorldTransformResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpxf);

    if(lpxf != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpxf, &stlpxf, sizeof(stlpxf));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWorldTransform\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ModifyWorldTransform(
      HDC            hdc   ,
      const XFORM *  lpxf  ,
      DWORD          mode  );

*/
void EmuApi::EmuModifyWorldTransform(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PXFORM lpxf{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpxf);

    XFORM stlpxf{};

    if(lpxf != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpxf, &stlpxf, sizeof(stlpxf));
    }

    DWORD mode{};
    uc_reg_read(uc, UC_X86_REG_R8D, &mode);


    BOOL ModifyWorldTransformResult = ModifyWorldTransform((HDC)hdc,(const XFORM *)&stlpxf,(DWORD)mode);


    uc_reg_write(uc, UC_X86_REG_EAX, &ModifyWorldTransformResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpxf);

    if(lpxf != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpxf, &stlpxf, sizeof(stlpxf));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &mode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuModifyWorldTransform\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CombineTransform(
      LPXFORM        lpxfOut  ,
      const XFORM *  lpxf1    ,
      const XFORM *  lpxf2    );

*/
void EmuApi::EmuCombineTransform(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPXFORM lpxfOut{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpxfOut);

    XFORM stlpxfOut{};

    if(lpxfOut != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpxfOut, &stlpxfOut, sizeof(stlpxfOut));
    }

    PXFORM lpxf1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpxf1);

    XFORM stlpxf1{};

    if(lpxf1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpxf1, &stlpxf1, sizeof(stlpxf1));
    }

    PXFORM lpxf2{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpxf2);

    XFORM stlpxf2{};

    if(lpxf2 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpxf2, &stlpxf2, sizeof(stlpxf2));
    }


    BOOL CombineTransformResult = CombineTransform((LPXFORM)&stlpxfOut,(const XFORM *)&stlpxf1,(const XFORM *)&stlpxf2);


    uc_reg_write(uc, UC_X86_REG_EAX, &CombineTransformResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpxfOut);

    if(lpxfOut != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpxfOut, &stlpxfOut, sizeof(stlpxfOut));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpxf1);

    if(lpxf1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpxf1, &stlpxf1, sizeof(stlpxf1));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpxf2);

    if(lpxf2 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpxf2, &stlpxf2, sizeof(stlpxf2));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCombineTransform\n";
    #endif

    return;
}


/*
HBITMAP
__cdecl
CreateDIBSection(
      HDC                 hdc       ,
      const BITMAPINFO *  pbmi      ,
      UINT                usage     ,
      void **             ppvBits   ,
      HANDLE              hSection  ,
      DWORD               offset    );

*/
void EmuApi::EmuCreateDIBSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PBITMAPINFO pbmi{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pbmi);

    BITMAPINFO stpbmi{};

    if(pbmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbmi, &stpbmi, sizeof(stpbmi));
    }

    UINT usage{};
    uc_reg_read(uc, UC_X86_REG_R8D, &usage);

    PVOID * ppvBits{};
    uc_reg_read(uc, UC_X86_REG_R9, &ppvBits);

    PVOID * dpppvBits{};

    if(ppvBits != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppvBits, &dpppvBits, sizeof(dpppvBits));
    }

    HANDLE hSection{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hSection, sizeof(hSection));

    DWORD offset{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &offset, sizeof(offset));


    HBITMAP CreateDIBSectionResult = CreateDIBSection((HDC)hdc,(const BITMAPINFO *)&stpbmi,(UINT)usage,(void **)&dpppvBits,(HANDLE)hSection,(DWORD)offset);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDIBSectionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &pbmi);

    if(pbmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbmi, &stpbmi, sizeof(stpbmi));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &usage);
    uc_reg_write(uc, UC_X86_REG_R9, &ppvBits);

    if(ppvBits != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ppvBits, &dpppvBits, sizeof(dpppvBits));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hSection, sizeof(hSection));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &offset, sizeof(offset));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDIBSection\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDIBColorTable(
      HDC        hdc       ,
      UINT       iStart    ,
      UINT       cEntries  ,
      RGBQUAD *  prgbq     );

*/
void EmuApi::EmuGetDIBColorTable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iStart{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iStart);

    UINT cEntries{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cEntries);

    RGBQUAD * prgbq{};
    uc_reg_read(uc, UC_X86_REG_R9, &prgbq);

    RGBQUAD stprgbq{};

    if(prgbq != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)prgbq, &stprgbq, sizeof(stprgbq));
    }


    UINT GetDIBColorTableResult = GetDIBColorTable((HDC)hdc,(UINT)iStart,(UINT)cEntries,(RGBQUAD *)&stprgbq);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDIBColorTableResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iStart);
    uc_reg_write(uc, UC_X86_REG_R8D, &cEntries);
    uc_reg_write(uc, UC_X86_REG_R9, &prgbq);

    if(prgbq != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)prgbq, &stprgbq, sizeof(stprgbq));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDIBColorTable\n";
    #endif

    return;
}


/*
UINT
__cdecl
SetDIBColorTable(
      HDC              hdc       ,
      UINT             iStart    ,
      UINT             cEntries  ,
      const RGBQUAD *  prgbq     );

*/
void EmuApi::EmuSetDIBColorTable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    UINT iStart{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iStart);

    UINT cEntries{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cEntries);

    RGBQUAD * prgbq{};
    uc_reg_read(uc, UC_X86_REG_R9, &prgbq);

    RGBQUAD stprgbq{};

    if(prgbq != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)prgbq, &stprgbq, sizeof(stprgbq));
    }


    UINT SetDIBColorTableResult = SetDIBColorTable((HDC)hdc,(UINT)iStart,(UINT)cEntries,(const RGBQUAD *)&stprgbq);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDIBColorTableResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &iStart);
    uc_reg_write(uc, UC_X86_REG_R8D, &cEntries);
    uc_reg_write(uc, UC_X86_REG_R9, &prgbq);

    if(prgbq != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)prgbq, &stprgbq, sizeof(stprgbq));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDIBColorTable\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetColorAdjustment(
      HDC                      hdc   ,
      const COLORADJUSTMENT *  lpca  );

*/
void EmuApi::EmuSetColorAdjustment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PCOLORADJUSTMENT lpca{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpca);

    COLORADJUSTMENT stlpca{};

    if(lpca != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpca, &stlpca, sizeof(stlpca));
    }


    BOOL SetColorAdjustmentResult = SetColorAdjustment((HDC)hdc,(const COLORADJUSTMENT *)&stlpca);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetColorAdjustmentResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpca);

    if(lpca != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpca, &stlpca, sizeof(stlpca));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetColorAdjustment\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetColorAdjustment(
      HDC                hdc   ,
      LPCOLORADJUSTMENT  lpca  );

*/
void EmuApi::EmuGetColorAdjustment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPCOLORADJUSTMENT lpca{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpca);

    COLORADJUSTMENT stlpca{};

    if(lpca != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpca, &stlpca, sizeof(stlpca));
    }


    BOOL GetColorAdjustmentResult = GetColorAdjustment((HDC)hdc,(LPCOLORADJUSTMENT)&stlpca);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetColorAdjustmentResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpca);

    if(lpca != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpca, &stlpca, sizeof(stlpca));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetColorAdjustment\n";
    #endif

    return;
}


/*
HPALETTE
__cdecl
CreateHalftonePalette(
      HDC  hdc  );

*/
void EmuApi::EmuCreateHalftonePalette(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    HPALETTE CreateHalftonePaletteResult = CreateHalftonePalette((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateHalftonePaletteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateHalftonePalette\n";
    #endif

    return;
}


/*
int
__cdecl
StartDocA(
      HDC               hdc   ,
      const DOCINFOA *  lpdi  );

*/
void EmuApi::EmuStartDocA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    DOCINFOA * lpdi{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdi);

    DOCINFOA stlpdi{};

    if(lpdi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdi, &stlpdi, sizeof(stlpdi));
    }


    int StartDocAResult = StartDocA((HDC)hdc,(const DOCINFOA *)&stlpdi);


    uc_reg_write(uc, UC_X86_REG_EAX, &StartDocAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdi);

    if(lpdi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdi, &stlpdi, sizeof(stlpdi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuStartDocA\n";
    #endif

    return;
}


/*
int
__cdecl
StartDocW(
      HDC               hdc   ,
      const DOCINFOW *  lpdi  );

*/
void EmuApi::EmuStartDocW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    DOCINFOW * lpdi{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdi);

    DOCINFOW stlpdi{};

    if(lpdi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdi, &stlpdi, sizeof(stlpdi));
    }


    int StartDocWResult = StartDocW((HDC)hdc,(const DOCINFOW *)&stlpdi);


    uc_reg_write(uc, UC_X86_REG_EAX, &StartDocWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdi);

    if(lpdi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdi, &stlpdi, sizeof(stlpdi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuStartDocW\n";
    #endif

    return;
}


/*
int
__cdecl
EndDoc(
      HDC  hdc  );

*/
void EmuApi::EmuEndDoc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int EndDocResult = EndDoc((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &EndDocResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEndDoc\n";
    #endif

    return;
}


/*
int
__cdecl
StartPage(
      HDC  hdc  );

*/
void EmuApi::EmuStartPage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int StartPageResult = StartPage((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &StartPageResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuStartPage\n";
    #endif

    return;
}


/*
int
__cdecl
EndPage(
      HDC  hdc  );

*/
void EmuApi::EmuEndPage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int EndPageResult = EndPage((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &EndPageResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEndPage\n";
    #endif

    return;
}


/*
int
__cdecl
AbortDoc(
      HDC  hdc  );

*/
void EmuApi::EmuAbortDoc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int AbortDocResult = AbortDoc((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &AbortDocResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAbortDoc\n";
    #endif

    return;
}


/*
int
__cdecl
SetAbortProc(
      HDC        hdc   ,
      ABORTPROC  proc  );

*/
void EmuApi::EmuSetAbortProc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    ABORTPROC proc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &proc);


    int SetAbortProcResult = SetAbortProc((HDC)hdc,(ABORTPROC)proc);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetAbortProcResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &proc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetAbortProc\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AbortPath(
      HDC  hdc  );

*/
void EmuApi::EmuAbortPath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL AbortPathResult = AbortPath((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &AbortPathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAbortPath\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ArcTo(
      HDC  hdc     ,
      int  left    ,
      int  top     ,
      int  right   ,
      int  bottom  ,
      int  xr1     ,
      int  yr1     ,
      int  xr2     ,
      int  yr2     );

*/
void EmuApi::EmuArcTo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int left{};
    uc_reg_read(uc, UC_X86_REG_EDX, &left);

    int top{};
    uc_reg_read(uc, UC_X86_REG_R8D, &top);

    int right{};
    uc_reg_read(uc, UC_X86_REG_R9D, &right);

    int bottom{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));

    int xr1{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &xr1, sizeof(xr1));

    int yr1{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &yr1, sizeof(yr1));

    int xr2{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &xr2, sizeof(xr2));

    int yr2{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &yr2, sizeof(yr2));


    BOOL ArcToResult = ArcTo((HDC)hdc,(int)left,(int)top,(int)right,(int)bottom,(int)xr1,(int)yr1,(int)xr2,(int)yr2);


    uc_reg_write(uc, UC_X86_REG_EAX, &ArcToResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &left);
    uc_reg_write(uc, UC_X86_REG_R8D, &top);
    uc_reg_write(uc, UC_X86_REG_R9D, &right);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bottom, sizeof(bottom));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &xr1, sizeof(xr1));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &yr1, sizeof(yr1));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &xr2, sizeof(xr2));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &yr2, sizeof(yr2));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuArcTo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BeginPath(
      HDC  hdc  );

*/
void EmuApi::EmuBeginPath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL BeginPathResult = BeginPath((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &BeginPathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBeginPath\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CloseFigure(
      HDC  hdc  );

*/
void EmuApi::EmuCloseFigure(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL CloseFigureResult = CloseFigure((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &CloseFigureResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseFigure\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EndPath(
      HDC  hdc  );

*/
void EmuApi::EmuEndPath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL EndPathResult = EndPath((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &EndPathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEndPath\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FillPath(
      HDC  hdc  );

*/
void EmuApi::EmuFillPath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL FillPathResult = FillPath((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &FillPathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFillPath\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FlattenPath(
      HDC  hdc  );

*/
void EmuApi::EmuFlattenPath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL FlattenPathResult = FlattenPath((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &FlattenPathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFlattenPath\n";
    #endif

    return;
}


/*
int
__cdecl
GetPath(
      HDC      hdc  ,
      LPPOINT  apt  ,
      LPBYTE   aj   ,
      int      cpt  );

*/
void EmuApi::EmuGetPath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPPOINT apt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &apt);

    POINT stapt{};

    if(apt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)apt, &stapt, sizeof(stapt));
    }

    LPBYTE aj{};
    uc_reg_read(uc, UC_X86_REG_R8, &aj);

    BYTE rlaj{};

    if(aj != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)aj, &rlaj, sizeof(rlaj));
    }

    int cpt{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cpt);


    int GetPathResult = GetPath((HDC)hdc,(LPPOINT)&stapt,(LPBYTE)&rlaj,(int)cpt);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &apt);

    if(apt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)apt, &stapt, sizeof(stapt));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &aj);

    if(aj != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)aj, &rlaj, sizeof(rlaj));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &cpt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPath\n";
    #endif

    return;
}


/*
HRGN
__cdecl
PathToRegion(
      HDC  hdc  );

*/
void EmuApi::EmuPathToRegion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    HRGN PathToRegionResult = PathToRegion((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_RAX, &PathToRegionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPathToRegion\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PolyDraw(
      HDC            hdc  ,
      const POINT *  apt  ,
      const BYTE *   aj   ,
      int            cpt  );

*/
void EmuApi::EmuPolyDraw(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POINT apt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &apt);

    PBYTE aj{};
    uc_reg_read(uc, UC_X86_REG_R8, &aj);

    BYTE rlaj{};

    if(aj != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)aj, &rlaj, sizeof(rlaj));
    }

    int cpt{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cpt);


    BOOL PolyDrawResult = PolyDraw((HDC)hdc,(const POINT *)&apt,(const BYTE *)&rlaj,(int)cpt);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolyDrawResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &apt);
    uc_reg_write(uc, UC_X86_REG_R8, &aj);

    if(aj != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)aj, &rlaj, sizeof(rlaj));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &cpt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolyDraw\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SelectClipPath(
      HDC  hdc   ,
      int  mode  );

*/
void EmuApi::EmuSelectClipPath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int mode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &mode);


    BOOL SelectClipPathResult = SelectClipPath((HDC)hdc,(int)mode);


    uc_reg_write(uc, UC_X86_REG_EAX, &SelectClipPathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &mode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSelectClipPath\n";
    #endif

    return;
}


/*
int
__cdecl
SetArcDirection(
      HDC  hdc  ,
      int  dir  );

*/
void EmuApi::EmuSetArcDirection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int dir{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dir);


    int SetArcDirectionResult = SetArcDirection((HDC)hdc,(int)dir);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetArcDirectionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &dir);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetArcDirection\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMiterLimit(
      HDC     hdc    ,
      FLOAT   limit  ,
      PFLOAT  old    );

*/
void EmuApi::EmuSetMiterLimit(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    FLOAT limit{};
    uc_reg_read(uc, UC_X86_REG_EDX, &limit);

    PFLOAT old{};
    uc_reg_read(uc, UC_X86_REG_R8, &old);

    FLOAT rlold{};

    if(old != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)old, &rlold, sizeof(rlold));
    }


    BOOL SetMiterLimitResult = SetMiterLimit((HDC)hdc,(FLOAT)limit,(PFLOAT)&rlold);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMiterLimitResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &limit);
    uc_reg_write(uc, UC_X86_REG_R8, &old);

    if(old != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)old, &rlold, sizeof(rlold));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMiterLimit\n";
    #endif

    return;
}


/*
BOOL
__cdecl
StrokeAndFillPath(
      HDC  hdc  );

*/
void EmuApi::EmuStrokeAndFillPath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL StrokeAndFillPathResult = StrokeAndFillPath((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &StrokeAndFillPathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuStrokeAndFillPath\n";
    #endif

    return;
}


/*
BOOL
__cdecl
StrokePath(
      HDC  hdc  );

*/
void EmuApi::EmuStrokePath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL StrokePathResult = StrokePath((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &StrokePathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuStrokePath\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WidenPath(
      HDC  hdc  );

*/
void EmuApi::EmuWidenPath(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL WidenPathResult = WidenPath((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &WidenPathResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWidenPath\n";
    #endif

    return;
}


/*
HPEN
__cdecl
ExtCreatePen(
      DWORD             iPenStyle  ,
      DWORD             cWidth     ,
      const LOGBRUSH *  plbrush    ,
      DWORD             cStyle     ,
      const DWORD *     pstyle     );

*/
void EmuApi::EmuExtCreatePen(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD iPenStyle{};
    uc_reg_read(uc, UC_X86_REG_ECX, &iPenStyle);

    DWORD cWidth{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cWidth);

    PLOGBRUSH plbrush{};
    uc_reg_read(uc, UC_X86_REG_R8, &plbrush);

    LOGBRUSH stplbrush{};

    if(plbrush != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)plbrush, &stplbrush, sizeof(stplbrush));
    }

    DWORD cStyle{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cStyle);

    PDWORD pstyle{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pstyle, sizeof(pstyle));

    DWORD rlpstyle{};

    if(pstyle != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pstyle, &rlpstyle, sizeof(rlpstyle));
    }


    HPEN ExtCreatePenResult = ExtCreatePen((DWORD)iPenStyle,(DWORD)cWidth,(const LOGBRUSH *)&stplbrush,(DWORD)cStyle,(const DWORD *)&rlpstyle);


    uc_reg_write(uc, UC_X86_REG_RAX, &ExtCreatePenResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &iPenStyle);
    uc_reg_write(uc, UC_X86_REG_EDX, &cWidth);
    uc_reg_write(uc, UC_X86_REG_R8, &plbrush);

    if(plbrush != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)plbrush, &stplbrush, sizeof(stplbrush));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &cStyle);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pstyle, sizeof(pstyle));

    if(pstyle != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pstyle, &rlpstyle, sizeof(rlpstyle));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExtCreatePen\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMiterLimit(
      HDC     hdc     ,
      PFLOAT  plimit  );

*/
void EmuApi::EmuGetMiterLimit(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    PFLOAT plimit{};
    uc_reg_read(uc, UC_X86_REG_RDX, &plimit);

    FLOAT rlplimit{};

    if(plimit != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)plimit, &rlplimit, sizeof(rlplimit));
    }


    BOOL GetMiterLimitResult = GetMiterLimit((HDC)hdc,(PFLOAT)&rlplimit);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMiterLimitResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &plimit);

    if(plimit != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)plimit, &rlplimit, sizeof(rlplimit));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMiterLimit\n";
    #endif

    return;
}


/*
int
__cdecl
GetArcDirection(
      HDC  hdc  );

*/
void EmuApi::EmuGetArcDirection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    int GetArcDirectionResult = GetArcDirection((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetArcDirectionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetArcDirection\n";
    #endif

    return;
}


/*
int
__cdecl
GetObjectA(
      HANDLE  h   ,
      int     c   ,
      LPVOID  pv  );

*/
void EmuApi::EmuGetObjectA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE h{};
    uc_reg_read(uc, UC_X86_REG_RCX, &h);

    int c{};
    uc_reg_read(uc, UC_X86_REG_EDX, &c);

    LPVOID pv{};
    uc_reg_read(uc, UC_X86_REG_R8, &pv);


    int GetObjectAResult = GetObjectA((HANDLE)h,(int)c,(LPVOID)&pv);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetObjectAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &h);
    uc_reg_write(uc, UC_X86_REG_EDX, &c);
    uc_reg_write(uc, UC_X86_REG_R8, &pv);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetObjectA\n";
    #endif

    return;
}


/*
int
__cdecl
GetObjectW(
      HANDLE  h   ,
      int     c   ,
      LPVOID  pv  );

*/
void EmuApi::EmuGetObjectW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE h{};
    uc_reg_read(uc, UC_X86_REG_RCX, &h);

    int c{};
    uc_reg_read(uc, UC_X86_REG_EDX, &c);

    LPVOID pv{};
    uc_reg_read(uc, UC_X86_REG_R8, &pv);


    int GetObjectWResult = GetObjectW((HANDLE)h,(int)c,(LPVOID)&pv);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetObjectWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &h);
    uc_reg_write(uc, UC_X86_REG_EDX, &c);
    uc_reg_write(uc, UC_X86_REG_R8, &pv);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetObjectW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveToEx(
      HDC      hdc   ,
      int      x     ,
      int      y     ,
      LPPOINT  lppt  );

*/
void EmuApi::EmuMoveToEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_R9, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }


    BOOL MoveToExResult = MoveToEx((HDC)hdc,(int)x,(int)y,(LPPOINT)&stlppt);


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveToExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveToEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TextOutA(
      HDC     hdc       ,
      int     x         ,
      int     y         ,
      LPCSTR  lpString  ,
      int     c         );

*/
void EmuApi::EmuTextOutA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in TextOutA"); _CrtDbgBreak(); }

    int c{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &c, sizeof(c));


    BOOL TextOutAResult = TextOutA((HDC)hdc,(int)x,(int)y,(LPCSTR)rlalpString.data(),(int)c);


    uc_reg_write(uc, UC_X86_REG_EAX, &TextOutAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in TextOutA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &c, sizeof(c));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTextOutA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TextOutW(
      HDC      hdc       ,
      int      x         ,
      int      y         ,
      LPCWSTR  lpString  ,
      int      c         );

*/
void EmuApi::EmuTextOutW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in TextOutW"); _CrtDbgBreak(); }

    int c{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &c, sizeof(c));


    BOOL TextOutWResult = TextOutW((HDC)hdc,(int)x,(int)y,(LPCWSTR)rlwlpString.data(),(int)c);


    uc_reg_write(uc, UC_X86_REG_EAX, &TextOutWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in TextOutW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &c, sizeof(c));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTextOutW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ExtTextOutA(
      HDC           hdc       ,
      int           x         ,
      int           y         ,
      UINT          options   ,
      const RECT *  lprect    ,
      LPCSTR        lpString  ,
      UINT          c         ,
      const INT *   lpDx      );

*/
void EmuApi::EmuExtTextOutA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    UINT options{};
    uc_reg_read(uc, UC_X86_REG_R9D, &options);

    PRECT lprect{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lprect, sizeof(lprect));

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }

    LPSTR lpString{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpString, sizeof(lpString));

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in ExtTextOutA"); _CrtDbgBreak(); }

    UINT c{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &c, sizeof(c));

    PINT lpDx{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpDx, sizeof(lpDx));

    int rllpDx{};

    if(lpDx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDx, &rllpDx, sizeof(rllpDx));
    }


    BOOL ExtTextOutAResult = ExtTextOutA((HDC)hdc,(int)x,(int)y,(UINT)options,(const RECT *)&stlprect,(LPCSTR)rlalpString.data(),(UINT)c,(const INT *)&rllpDx);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExtTextOutAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9D, &options);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lprect, sizeof(lprect));

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in ExtTextOutA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &c, sizeof(c));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpDx, sizeof(lpDx));

    if(lpDx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDx, &rllpDx, sizeof(rllpDx));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExtTextOutA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ExtTextOutW(
      HDC           hdc       ,
      int           x         ,
      int           y         ,
      UINT          options   ,
      const RECT *  lprect    ,
      LPCWSTR       lpString  ,
      UINT          c         ,
      const INT *   lpDx      );

*/
void EmuApi::EmuExtTextOutW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    UINT options{};
    uc_reg_read(uc, UC_X86_REG_R9D, &options);

    PRECT lprect{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lprect, sizeof(lprect));

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }

    LPWSTR lpString{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpString, sizeof(lpString));

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in ExtTextOutW"); _CrtDbgBreak(); }

    UINT c{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &c, sizeof(c));

    PINT lpDx{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpDx, sizeof(lpDx));

    int rllpDx{};

    if(lpDx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDx, &rllpDx, sizeof(rllpDx));
    }


    BOOL ExtTextOutWResult = ExtTextOutW((HDC)hdc,(int)x,(int)y,(UINT)options,(const RECT *)&stlprect,(LPCWSTR)rlwlpString.data(),(UINT)c,(const INT *)&rllpDx);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExtTextOutWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9D, &options);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lprect, sizeof(lprect));

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in ExtTextOutW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &c, sizeof(c));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpDx, sizeof(lpDx));

    if(lpDx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDx, &rllpDx, sizeof(rllpDx));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExtTextOutW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PolyTextOutA(
      HDC                hdc       ,
      const POLYTEXTA *  ppt       ,
      int                nstrings  );

*/
void EmuApi::EmuPolyTextOutA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POLYTEXTA ppt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ppt);

    int nstrings{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nstrings);


    BOOL PolyTextOutAResult = PolyTextOutA((HDC)hdc,(const POLYTEXTA *)&ppt,(int)nstrings);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolyTextOutAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &ppt);
    uc_reg_write(uc, UC_X86_REG_R8D, &nstrings);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolyTextOutA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PolyTextOutW(
      HDC                hdc       ,
      const POLYTEXTW *  ppt       ,
      int                nstrings  );

*/
void EmuApi::EmuPolyTextOutW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POLYTEXTW ppt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ppt);

    int nstrings{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nstrings);


    BOOL PolyTextOutWResult = PolyTextOutW((HDC)hdc,(const POLYTEXTW *)&ppt,(int)nstrings);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolyTextOutWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &ppt);
    uc_reg_write(uc, UC_X86_REG_R8D, &nstrings);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolyTextOutW\n";
    #endif

    return;
}


/*
HRGN
__cdecl
CreatePolygonRgn(
      const POINT *  pptl    ,
      int            cPoint  ,
      int            iMode   );

*/
void EmuApi::EmuCreatePolygonRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    POINT pptl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pptl);

    int cPoint{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cPoint);

    int iMode{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iMode);


    HRGN CreatePolygonRgnResult = CreatePolygonRgn((const POINT *)&pptl,(int)cPoint,(int)iMode);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreatePolygonRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pptl);
    uc_reg_write(uc, UC_X86_REG_EDX, &cPoint);
    uc_reg_write(uc, UC_X86_REG_R8D, &iMode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreatePolygonRgn\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DPtoLP(
      HDC      hdc   ,
      LPPOINT  lppt  ,
      int      c     );

*/
void EmuApi::EmuDPtoLP(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }

    int c{};
    uc_reg_read(uc, UC_X86_REG_R8D, &c);


    BOOL DPtoLPResult = DPtoLP((HDC)hdc,(LPPOINT)&stlppt,(int)c);


    uc_reg_write(uc, UC_X86_REG_EAX, &DPtoLPResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &c);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDPtoLP\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LPtoDP(
      HDC      hdc   ,
      LPPOINT  lppt  ,
      int      c     );

*/
void EmuApi::EmuLPtoDP(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }

    int c{};
    uc_reg_read(uc, UC_X86_REG_R8D, &c);


    BOOL LPtoDPResult = LPtoDP((HDC)hdc,(LPPOINT)&stlppt,(int)c);


    uc_reg_write(uc, UC_X86_REG_EAX, &LPtoDPResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &c);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLPtoDP\n";
    #endif

    return;
}


/*
BOOL
__cdecl
Polygon(
      HDC            hdc  ,
      const POINT *  apt  ,
      int            cpt  );

*/
void EmuApi::EmuPolygon(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POINT apt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &apt);

    int cpt{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cpt);


    BOOL PolygonResult = Polygon((HDC)hdc,(const POINT *)&apt,(int)cpt);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolygonResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &apt);
    uc_reg_write(uc, UC_X86_REG_R8D, &cpt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolygon\n";
    #endif

    return;
}


/*
BOOL
__cdecl
Polyline(
      HDC            hdc  ,
      const POINT *  apt  ,
      int            cpt  );

*/
void EmuApi::EmuPolyline(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POINT apt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &apt);

    int cpt{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cpt);


    BOOL PolylineResult = Polyline((HDC)hdc,(const POINT *)&apt,(int)cpt);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolylineResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &apt);
    uc_reg_write(uc, UC_X86_REG_R8D, &cpt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolyline\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PolyBezier(
      HDC            hdc  ,
      const POINT *  apt  ,
      DWORD          cpt  );

*/
void EmuApi::EmuPolyBezier(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POINT apt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &apt);

    DWORD cpt{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cpt);


    BOOL PolyBezierResult = PolyBezier((HDC)hdc,(const POINT *)&apt,(DWORD)cpt);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolyBezierResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &apt);
    uc_reg_write(uc, UC_X86_REG_R8D, &cpt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolyBezier\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PolyBezierTo(
      HDC            hdc  ,
      const POINT *  apt  ,
      DWORD          cpt  );

*/
void EmuApi::EmuPolyBezierTo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POINT apt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &apt);

    DWORD cpt{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cpt);


    BOOL PolyBezierToResult = PolyBezierTo((HDC)hdc,(const POINT *)&apt,(DWORD)cpt);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolyBezierToResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &apt);
    uc_reg_write(uc, UC_X86_REG_R8D, &cpt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolyBezierTo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PolylineTo(
      HDC            hdc  ,
      const POINT *  apt  ,
      DWORD          cpt  );

*/
void EmuApi::EmuPolylineTo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    POINT apt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &apt);

    DWORD cpt{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cpt);


    BOOL PolylineToResult = PolylineTo((HDC)hdc,(const POINT *)&apt,(DWORD)cpt);


    uc_reg_write(uc, UC_X86_REG_EAX, &PolylineToResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &apt);
    uc_reg_write(uc, UC_X86_REG_R8D, &cpt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPolylineTo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetViewportExtEx(
      HDC     hdc   ,
      int     x     ,
      int     y     ,
      LPSIZE  lpsz  );

*/
void EmuApi::EmuSetViewportExtEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPSIZE lpsz{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpsz);

    SIZE stlpsz{};

    if(lpsz != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }


    BOOL SetViewportExtExResult = SetViewportExtEx((HDC)hdc,(int)x,(int)y,(LPSIZE)&stlpsz);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetViewportExtExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9, &lpsz);

    if(lpsz != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetViewportExtEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetViewportOrgEx(
      HDC      hdc   ,
      int      x     ,
      int      y     ,
      LPPOINT  lppt  );

*/
void EmuApi::EmuSetViewportOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_R9, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }


    BOOL SetViewportOrgExResult = SetViewportOrgEx((HDC)hdc,(int)x,(int)y,(LPPOINT)&stlppt);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetViewportOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetViewportOrgEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWindowExtEx(
      HDC     hdc   ,
      int     x     ,
      int     y     ,
      LPSIZE  lpsz  );

*/
void EmuApi::EmuSetWindowExtEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPSIZE lpsz{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpsz);

    SIZE stlpsz{};

    if(lpsz != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }


    BOOL SetWindowExtExResult = SetWindowExtEx((HDC)hdc,(int)x,(int)y,(LPSIZE)&stlpsz);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowExtExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9, &lpsz);

    if(lpsz != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowExtEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWindowOrgEx(
      HDC      hdc   ,
      int      x     ,
      int      y     ,
      LPPOINT  lppt  );

*/
void EmuApi::EmuSetWindowOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_R9, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }


    BOOL SetWindowOrgExResult = SetWindowOrgEx((HDC)hdc,(int)x,(int)y,(LPPOINT)&stlppt);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowOrgEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OffsetViewportOrgEx(
      HDC      hdc   ,
      int      x     ,
      int      y     ,
      LPPOINT  lppt  );

*/
void EmuApi::EmuOffsetViewportOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_R9, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }


    BOOL OffsetViewportOrgExResult = OffsetViewportOrgEx((HDC)hdc,(int)x,(int)y,(LPPOINT)&stlppt);


    uc_reg_write(uc, UC_X86_REG_EAX, &OffsetViewportOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOffsetViewportOrgEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OffsetWindowOrgEx(
      HDC      hdc   ,
      int      x     ,
      int      y     ,
      LPPOINT  lppt  );

*/
void EmuApi::EmuOffsetWindowOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_R9, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }


    BOOL OffsetWindowOrgExResult = OffsetWindowOrgEx((HDC)hdc,(int)x,(int)y,(LPPOINT)&stlppt);


    uc_reg_write(uc, UC_X86_REG_EAX, &OffsetWindowOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOffsetWindowOrgEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ScaleViewportExtEx(
      HDC     hdc   ,
      int     xn    ,
      int     dx    ,
      int     yn    ,
      int     yd    ,
      LPSIZE  lpsz  );

*/
void EmuApi::EmuScaleViewportExtEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int xn{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xn);

    int dx{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dx);

    int yn{};
    uc_reg_read(uc, UC_X86_REG_R9D, &yn);

    int yd{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &yd, sizeof(yd));

    LPSIZE lpsz{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpsz, sizeof(lpsz));

    SIZE stlpsz{};

    if(lpsz != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }


    BOOL ScaleViewportExtExResult = ScaleViewportExtEx((HDC)hdc,(int)xn,(int)dx,(int)yn,(int)yd,(LPSIZE)&stlpsz);


    uc_reg_write(uc, UC_X86_REG_EAX, &ScaleViewportExtExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &xn);
    uc_reg_write(uc, UC_X86_REG_R8D, &dx);
    uc_reg_write(uc, UC_X86_REG_R9D, &yn);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &yd, sizeof(yd));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpsz, sizeof(lpsz));

    if(lpsz != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuScaleViewportExtEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ScaleWindowExtEx(
      HDC     hdc   ,
      int     xn    ,
      int     xd    ,
      int     yn    ,
      int     yd    ,
      LPSIZE  lpsz  );

*/
void EmuApi::EmuScaleWindowExtEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int xn{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xn);

    int xd{};
    uc_reg_read(uc, UC_X86_REG_R8D, &xd);

    int yn{};
    uc_reg_read(uc, UC_X86_REG_R9D, &yn);

    int yd{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &yd, sizeof(yd));

    LPSIZE lpsz{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpsz, sizeof(lpsz));

    SIZE stlpsz{};

    if(lpsz != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }


    BOOL ScaleWindowExtExResult = ScaleWindowExtEx((HDC)hdc,(int)xn,(int)xd,(int)yn,(int)yd,(LPSIZE)&stlpsz);


    uc_reg_write(uc, UC_X86_REG_EAX, &ScaleWindowExtExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &xn);
    uc_reg_write(uc, UC_X86_REG_R8D, &xd);
    uc_reg_write(uc, UC_X86_REG_R9D, &yn);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &yd, sizeof(yd));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpsz, sizeof(lpsz));

    if(lpsz != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuScaleWindowExtEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetBitmapDimensionEx(
      HBITMAP  hbm   ,
      int      w     ,
      int      h     ,
      LPSIZE   lpsz  );

*/
void EmuApi::EmuSetBitmapDimensionEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HBITMAP hbm{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hbm);

    int w{};
    uc_reg_read(uc, UC_X86_REG_EDX, &w);

    int h{};
    uc_reg_read(uc, UC_X86_REG_R8D, &h);

    LPSIZE lpsz{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpsz);

    SIZE stlpsz{};

    if(lpsz != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }


    BOOL SetBitmapDimensionExResult = SetBitmapDimensionEx((HBITMAP)hbm,(int)w,(int)h,(LPSIZE)&stlpsz);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetBitmapDimensionExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hbm);
    uc_reg_write(uc, UC_X86_REG_EDX, &w);
    uc_reg_write(uc, UC_X86_REG_R8D, &h);
    uc_reg_write(uc, UC_X86_REG_R9, &lpsz);

    if(lpsz != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsz, &stlpsz, sizeof(stlpsz));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetBitmapDimensionEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetBrushOrgEx(
      HDC      hdc   ,
      int      x     ,
      int      y     ,
      LPPOINT  lppt  );

*/
void EmuApi::EmuSetBrushOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_R9, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }


    BOOL SetBrushOrgExResult = SetBrushOrgEx((HDC)hdc,(int)x,(int)y,(LPPOINT)&stlppt);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetBrushOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetBrushOrgEx\n";
    #endif

    return;
}


/*
int
__cdecl
GetTextFaceA(
      HDC    hdc     ,
      int    c       ,
      LPSTR  lpName  );

*/
void EmuApi::EmuGetTextFaceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int c{};
    uc_reg_read(uc, UC_X86_REG_EDX, &c);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetTextFaceA"); _CrtDbgBreak(); }


    int GetTextFaceAResult = GetTextFaceA((HDC)hdc,(int)c,(LPSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextFaceAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &c);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetTextFaceA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextFaceA\n";
    #endif

    return;
}


/*
int
__cdecl
GetTextFaceW(
      HDC     hdc     ,
      int     c       ,
      LPWSTR  lpName  );

*/
void EmuApi::EmuGetTextFaceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int c{};
    uc_reg_read(uc, UC_X86_REG_EDX, &c);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetTextFaceW"); _CrtDbgBreak(); }


    int GetTextFaceWResult = GetTextFaceW((HDC)hdc,(int)c,(LPWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTextFaceWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &c);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetTextFaceW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTextFaceW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetKerningPairsA(
      HDC            hdc         ,
      DWORD          nPairs      ,
      LPKERNINGPAIR  lpKernPair  );

*/
void EmuApi::EmuGetKerningPairsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    DWORD nPairs{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nPairs);

    LPKERNINGPAIR lpKernPair{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpKernPair);

    KERNINGPAIR stlpKernPair{};

    if(lpKernPair != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKernPair, &stlpKernPair, sizeof(stlpKernPair));
    }


    DWORD GetKerningPairsAResult = GetKerningPairsA((HDC)hdc,(DWORD)nPairs,(LPKERNINGPAIR)&stlpKernPair);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKerningPairsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &nPairs);
    uc_reg_write(uc, UC_X86_REG_R8, &lpKernPair);

    if(lpKernPair != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKernPair, &stlpKernPair, sizeof(stlpKernPair));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKerningPairsA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetKerningPairsW(
      HDC            hdc         ,
      DWORD          nPairs      ,
      LPKERNINGPAIR  lpKernPair  );

*/
void EmuApi::EmuGetKerningPairsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    DWORD nPairs{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nPairs);

    LPKERNINGPAIR lpKernPair{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpKernPair);

    KERNINGPAIR stlpKernPair{};

    if(lpKernPair != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKernPair, &stlpKernPair, sizeof(stlpKernPair));
    }


    DWORD GetKerningPairsWResult = GetKerningPairsW((HDC)hdc,(DWORD)nPairs,(LPKERNINGPAIR)&stlpKernPair);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKerningPairsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &nPairs);
    uc_reg_write(uc, UC_X86_REG_R8, &lpKernPair);

    if(lpKernPair != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKernPair, &stlpKernPair, sizeof(stlpKernPair));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKerningPairsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDCOrgEx(
      HDC      hdc   ,
      LPPOINT  lppt  );

*/
void EmuApi::EmuGetDCOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lppt);

    POINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }


    BOOL GetDCOrgExResult = GetDCOrgEx((HDC)hdc,(LPPOINT)&stlppt);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDCOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDCOrgEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FixBrushOrgEx(
      HDC      hdc  ,
      int      x    ,
      int      y    ,
      LPPOINT  ptl  );

*/
void EmuApi::EmuFixBrushOrgEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPPOINT ptl{};
    uc_reg_read(uc, UC_X86_REG_R9, &ptl);

    POINT stptl{};

    if(ptl != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ptl, &stptl, sizeof(stptl));
    }


    BOOL FixBrushOrgExResult = FixBrushOrgEx((HDC)hdc,(int)x,(int)y,(LPPOINT)&stptl);


    uc_reg_write(uc, UC_X86_REG_EAX, &FixBrushOrgExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    uc_reg_write(uc, UC_X86_REG_R9, &ptl);

    if(ptl != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ptl, &stptl, sizeof(stptl));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFixBrushOrgEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnrealizeObject(
      HGDIOBJ  h  );

*/
void EmuApi::EmuUnrealizeObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGDIOBJ h{};
    uc_reg_read(uc, UC_X86_REG_RCX, &h);


    BOOL UnrealizeObjectResult = UnrealizeObject((HGDIOBJ)&h);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnrealizeObjectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &h);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnrealizeObject\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GdiFlush(VOID);

*/
void EmuApi::EmuGdiFlush(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL GdiFlushResult = GdiFlush();


    uc_reg_write(uc, UC_X86_REG_EAX, &GdiFlushResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGdiFlush\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GdiSetBatchLimit(
      DWORD  dw  );

*/
void EmuApi::EmuGdiSetBatchLimit(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dw{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dw);


    DWORD GdiSetBatchLimitResult = GdiSetBatchLimit((DWORD)dw);


    uc_reg_write(uc, UC_X86_REG_EAX, &GdiSetBatchLimitResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dw);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGdiSetBatchLimit\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GdiGetBatchLimit(VOID);

*/
void EmuApi::EmuGdiGetBatchLimit(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GdiGetBatchLimitResult = GdiGetBatchLimit();


    uc_reg_write(uc, UC_X86_REG_EAX, &GdiGetBatchLimitResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGdiGetBatchLimit\n";
    #endif

    return;
}


/*
int
__cdecl
SetICMMode(
      HDC  hdc   ,
      int  mode  );

*/
void EmuApi::EmuSetICMMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int mode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &mode);


    int SetICMModeResult = SetICMMode((HDC)hdc,(int)mode);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetICMModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &mode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetICMMode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CheckColorsInGamut(
      HDC          hdc          ,
      LPRGBTRIPLE  lpRGBTriple  ,
      LPVOID       dlpBuffer    ,
      DWORD        nCount       );

*/
void EmuApi::EmuCheckColorsInGamut(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPRGBTRIPLE lpRGBTriple{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpRGBTriple);

    RGBTRIPLE stlpRGBTriple{};

    if(lpRGBTriple != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRGBTriple, &stlpRGBTriple, sizeof(stlpRGBTriple));
    }

    LPVOID dlpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &dlpBuffer);

    DWORD nCount{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nCount);


    BOOL CheckColorsInGamutResult = CheckColorsInGamut((HDC)hdc,(LPRGBTRIPLE)&stlpRGBTriple,(LPVOID)&dlpBuffer,(DWORD)nCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &CheckColorsInGamutResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpRGBTriple);

    if(lpRGBTriple != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRGBTriple, &stlpRGBTriple, sizeof(stlpRGBTriple));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &dlpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &nCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCheckColorsInGamut\n";
    #endif

    return;
}


/*
HCOLORSPACE
__cdecl
GetColorSpace(
      HDC  hdc  );

*/
void EmuApi::EmuGetColorSpace(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    HCOLORSPACE GetColorSpaceResult = GetColorSpace((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetColorSpaceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetColorSpace\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetLogColorSpaceA(
      HCOLORSPACE       hColorSpace  ,
      LPLOGCOLORSPACEA  lpBuffer     ,
      DWORD             nSize        );

*/
void EmuApi::EmuGetLogColorSpaceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HCOLORSPACE hColorSpace{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hColorSpace);

    LPLOGCOLORSPACEA lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    LOGCOLORSPACEA stlpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    BOOL GetLogColorSpaceAResult = GetLogColorSpaceA((HCOLORSPACE)hColorSpace,(LPLOGCOLORSPACEA)&stlpBuffer,(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLogColorSpaceAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hColorSpace);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLogColorSpaceA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetLogColorSpaceW(
      HCOLORSPACE       hColorSpace  ,
      LPLOGCOLORSPACEW  lpBuffer     ,
      DWORD             nSize        );

*/
void EmuApi::EmuGetLogColorSpaceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HCOLORSPACE hColorSpace{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hColorSpace);

    LPLOGCOLORSPACEW lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    LOGCOLORSPACEW stlpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    BOOL GetLogColorSpaceWResult = GetLogColorSpaceW((HCOLORSPACE)hColorSpace,(LPLOGCOLORSPACEW)&stlpBuffer,(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLogColorSpaceWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hColorSpace);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLogColorSpaceW\n";
    #endif

    return;
}


/*
HCOLORSPACE
__cdecl
CreateColorSpaceA(
      LPLOGCOLORSPACEA  lplcs  );

*/
void EmuApi::EmuCreateColorSpaceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPLOGCOLORSPACEA lplcs{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lplcs);

    LOGCOLORSPACEA stlplcs{};

    if(lplcs != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lplcs, &stlplcs, sizeof(stlplcs));
    }


    HCOLORSPACE CreateColorSpaceAResult = CreateColorSpaceA((LPLOGCOLORSPACEA)&stlplcs);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateColorSpaceAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lplcs);

    if(lplcs != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lplcs, &stlplcs, sizeof(stlplcs));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateColorSpaceA\n";
    #endif

    return;
}


/*
HCOLORSPACE
__cdecl
CreateColorSpaceW(
      LPLOGCOLORSPACEW  lplcs  );

*/
void EmuApi::EmuCreateColorSpaceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPLOGCOLORSPACEW lplcs{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lplcs);

    LOGCOLORSPACEW stlplcs{};

    if(lplcs != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lplcs, &stlplcs, sizeof(stlplcs));
    }


    HCOLORSPACE CreateColorSpaceWResult = CreateColorSpaceW((LPLOGCOLORSPACEW)&stlplcs);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateColorSpaceWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lplcs);

    if(lplcs != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lplcs, &stlplcs, sizeof(stlplcs));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateColorSpaceW\n";
    #endif

    return;
}


/*
HCOLORSPACE
__cdecl
SetColorSpace(
      HDC          hdc  ,
      HCOLORSPACE  hcs  );

*/
void EmuApi::EmuSetColorSpace(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HCOLORSPACE hcs{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hcs);


    HCOLORSPACE SetColorSpaceResult = SetColorSpace((HDC)hdc,(HCOLORSPACE)hcs);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetColorSpaceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hcs);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetColorSpace\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteColorSpace(
      HCOLORSPACE  hcs  );

*/
void EmuApi::EmuDeleteColorSpace(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HCOLORSPACE hcs{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hcs);


    BOOL DeleteColorSpaceResult = DeleteColorSpace((HCOLORSPACE)hcs);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteColorSpaceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hcs);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteColorSpace\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetICMProfileA(
      HDC      hdc          ,
      LPDWORD  pBufSize     ,
      LPSTR    pszFilename  );

*/
void EmuApi::EmuGetICMProfileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPDWORD pBufSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pBufSize);

    DWORD rlpBufSize{};

    if(pBufSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pBufSize, &rlpBufSize, sizeof(rlpBufSize));
    }

    LPSTR pszFilename{};
    uc_reg_read(uc, UC_X86_REG_R8, &pszFilename);

    std::string rlapszFilename;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszFilename, rlapszFilename)) { printf("Error when read pszFilename in GetICMProfileA"); _CrtDbgBreak(); }


    BOOL GetICMProfileAResult = GetICMProfileA((HDC)hdc,(LPDWORD)&rlpBufSize,(LPSTR)rlapszFilename.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetICMProfileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &pBufSize);

    if(pBufSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pBufSize, &rlpBufSize, sizeof(rlpBufSize));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszFilename, rlapszFilename)) { printf("Error when read pszFilename in GetICMProfileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetICMProfileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetICMProfileW(
      HDC      hdc          ,
      LPDWORD  pBufSize     ,
      LPWSTR   pszFilename  );

*/
void EmuApi::EmuGetICMProfileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPDWORD pBufSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pBufSize);

    DWORD rlpBufSize{};

    if(pBufSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pBufSize, &rlpBufSize, sizeof(rlpBufSize));
    }

    LPWSTR pszFilename{};
    uc_reg_read(uc, UC_X86_REG_R8, &pszFilename);

    std::wstring rlwpszFilename;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszFilename, rlwpszFilename)) { printf("Error when read pszFilename in GetICMProfileW"); _CrtDbgBreak(); }


    BOOL GetICMProfileWResult = GetICMProfileW((HDC)hdc,(LPDWORD)&rlpBufSize,(LPWSTR)rlwpszFilename.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetICMProfileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &pBufSize);

    if(pBufSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pBufSize, &rlpBufSize, sizeof(rlpBufSize));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszFilename, rlwpszFilename)) { printf("Error when read pszFilename in GetICMProfileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetICMProfileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetICMProfileA(
      HDC    hdc         ,
      LPSTR  lpFileName  );

*/
void EmuApi::EmuSetICMProfileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SetICMProfileA"); _CrtDbgBreak(); }


    BOOL SetICMProfileAResult = SetICMProfileA((HDC)hdc,(LPSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetICMProfileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SetICMProfileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetICMProfileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetICMProfileW(
      HDC     hdc         ,
      LPWSTR  lpFileName  );

*/
void EmuApi::EmuSetICMProfileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in SetICMProfileW"); _CrtDbgBreak(); }


    BOOL SetICMProfileWResult = SetICMProfileW((HDC)hdc,(LPWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetICMProfileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in SetICMProfileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetICMProfileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDeviceGammaRamp(
      HDC     hdc     ,
      LPVOID  lpRamp  );

*/
void EmuApi::EmuGetDeviceGammaRamp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPVOID lpRamp{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpRamp);


    BOOL GetDeviceGammaRampResult = GetDeviceGammaRamp((HDC)hdc,(LPVOID)&lpRamp);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDeviceGammaRampResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpRamp);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDeviceGammaRamp\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDeviceGammaRamp(
      HDC     hdc     ,
      LPVOID  lpRamp  );

*/
void EmuApi::EmuSetDeviceGammaRamp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPVOID lpRamp{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpRamp);


    BOOL SetDeviceGammaRampResult = SetDeviceGammaRamp((HDC)hdc,(LPVOID)&lpRamp);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDeviceGammaRampResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpRamp);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDeviceGammaRamp\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ColorMatchToTarget(
      HDC    hdc        ,
      HDC    hdcTarget  ,
      DWORD  action     );

*/
void EmuApi::EmuColorMatchToTarget(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HDC hdcTarget{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hdcTarget);

    DWORD action{};
    uc_reg_read(uc, UC_X86_REG_R8D, &action);


    BOOL ColorMatchToTargetResult = ColorMatchToTarget((HDC)hdc,(HDC)hdcTarget,(DWORD)action);


    uc_reg_write(uc, UC_X86_REG_EAX, &ColorMatchToTargetResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hdcTarget);
    uc_reg_write(uc, UC_X86_REG_R8D, &action);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuColorMatchToTarget\n";
    #endif

    return;
}


/*
int
__cdecl
EnumICMProfilesA(
      HDC           hdc    ,
      ICMENUMPROCA  proc   ,
      LPARAM        param  );

*/
void EmuApi::EmuEnumICMProfilesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    ICMENUMPROCA proc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &proc);

    LPARAM param{};
    uc_reg_read(uc, UC_X86_REG_R8, &param);


    int EnumICMProfilesAResult = EnumICMProfilesA((HDC)hdc,(ICMENUMPROCA)proc,(LPARAM)param);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumICMProfilesAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &proc);
    uc_reg_write(uc, UC_X86_REG_R8, &param);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumICMProfilesA\n";
    #endif

    return;
}


/*
int
__cdecl
EnumICMProfilesW(
      HDC           hdc    ,
      ICMENUMPROCW  proc   ,
      LPARAM        param  );

*/
void EmuApi::EmuEnumICMProfilesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    ICMENUMPROCW proc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &proc);

    LPARAM param{};
    uc_reg_read(uc, UC_X86_REG_R8, &param);


    int EnumICMProfilesWResult = EnumICMProfilesW((HDC)hdc,(ICMENUMPROCW)proc,(LPARAM)param);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumICMProfilesWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &proc);
    uc_reg_write(uc, UC_X86_REG_R8, &param);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumICMProfilesW\n";
    #endif

    return;
}

/*
BOOL
__cdecl
ColorCorrectPalette(
      HDC       hdc      ,
      HPALETTE  hPal     ,
      DWORD     deFirst  ,
      DWORD     num      );

*/
void EmuApi::EmuColorCorrectPalette(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HPALETTE hPal{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hPal);

    DWORD deFirst{};
    uc_reg_read(uc, UC_X86_REG_R8D, &deFirst);

    DWORD num{};
    uc_reg_read(uc, UC_X86_REG_R9D, &num);


    BOOL ColorCorrectPaletteResult = ColorCorrectPalette((HDC)hdc,(HPALETTE)hPal,(DWORD)deFirst,(DWORD)num);


    uc_reg_write(uc, UC_X86_REG_EAX, &ColorCorrectPaletteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hPal);
    uc_reg_write(uc, UC_X86_REG_R8D, &deFirst);
    uc_reg_write(uc, UC_X86_REG_R9D, &num);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuColorCorrectPalette\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglCopyContext(
      HGLRC  namelessArg_0  ,
      HGLRC  namelessArg_1  ,
      UINT   namelessArg_2  );

*/
void EmuApi::EmuwglCopyContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLRC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    HGLRC namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    UINT namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);


    BOOL wglCopyContextResult = wglCopyContext((HGLRC)namelessArg_0,(HGLRC)namelessArg_1,(UINT)namelessArg_2);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglCopyContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_RDX, &namelessArg_1);
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglCopyContext\n";
    #endif

    return;
}


/*
HGLRC
__cdecl
wglCreateContext(
      HDC  namelessArg_0  );

*/
void EmuApi::EmuwglCreateContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);


    HGLRC wglCreateContextResult = wglCreateContext((HDC)namelessArg_0);


    uc_reg_write(uc, UC_X86_REG_RAX, &wglCreateContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglCreateContext\n";
    #endif

    return;
}


/*
HGLRC
__cdecl
wglCreateLayerContext(
      HDC  namelessArg_0  ,
      int  namelessArg_1  );

*/
void EmuApi::EmuwglCreateLayerContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    int namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);


    HGLRC wglCreateLayerContextResult = wglCreateLayerContext((HDC)namelessArg_0,(int)namelessArg_1);


    uc_reg_write(uc, UC_X86_REG_RAX, &wglCreateLayerContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglCreateLayerContext\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglDeleteContext(
      HGLRC  namelessArg_0  );

*/
void EmuApi::EmuwglDeleteContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLRC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);


    BOOL wglDeleteContextResult = wglDeleteContext((HGLRC)namelessArg_0);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglDeleteContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglDeleteContext\n";
    #endif

    return;
}


/*
HGLRC
__cdecl
wglGetCurrentContext(VOID);

*/
void EmuApi::EmuwglGetCurrentContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HGLRC wglGetCurrentContextResult = wglGetCurrentContext();


    uc_reg_write(uc, UC_X86_REG_RAX, &wglGetCurrentContextResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglGetCurrentContext\n";
    #endif

    return;
}


/*
HDC
__cdecl
wglGetCurrentDC(VOID);

*/
void EmuApi::EmuwglGetCurrentDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HDC wglGetCurrentDCResult = wglGetCurrentDC();


    uc_reg_write(uc, UC_X86_REG_RAX, &wglGetCurrentDCResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglGetCurrentDC\n";
    #endif

    return;
}


/*
PROC
__cdecl
wglGetProcAddress(
      LPCSTR  namelessArg_0  );

*/
void EmuApi::EmuwglGetProcAddress(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    std::string rlanamelessArg_0;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)namelessArg_0, rlanamelessArg_0)) { printf("Error when read namelessArg_0 in wglGetProcAddress"); _CrtDbgBreak(); }


    PROC wglGetProcAddressResult = wglGetProcAddress((LPCSTR)rlanamelessArg_0.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &wglGetProcAddressResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)namelessArg_0, rlanamelessArg_0)) { printf("Error when read namelessArg_0 in wglGetProcAddress"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglGetProcAddress\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglMakeCurrent(
      HDC    namelessArg_0  ,
      HGLRC  namelessArg_1  );

*/
void EmuApi::EmuwglMakeCurrent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    HGLRC namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);


    BOOL wglMakeCurrentResult = wglMakeCurrent((HDC)namelessArg_0,(HGLRC)namelessArg_1);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglMakeCurrentResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_RDX, &namelessArg_1);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglMakeCurrent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglShareLists(
      HGLRC  namelessArg_0  ,
      HGLRC  namelessArg_1  );

*/
void EmuApi::EmuwglShareLists(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLRC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    HGLRC namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);


    BOOL wglShareListsResult = wglShareLists((HGLRC)namelessArg_0,(HGLRC)namelessArg_1);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglShareListsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_RDX, &namelessArg_1);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglShareLists\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglUseFontBitmapsA(
      HDC    namelessArg_0  ,
      DWORD  namelessArg_1  ,
      DWORD  namelessArg_2  ,
      DWORD  namelessArg_3  );

*/
void EmuApi::EmuwglUseFontBitmapsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    DWORD namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);

    DWORD namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);

    DWORD namelessArg_3{};
    uc_reg_read(uc, UC_X86_REG_R9D, &namelessArg_3);


    BOOL wglUseFontBitmapsAResult = wglUseFontBitmapsA((HDC)namelessArg_0,(DWORD)namelessArg_1,(DWORD)namelessArg_2,(DWORD)namelessArg_3);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglUseFontBitmapsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    uc_reg_write(uc, UC_X86_REG_R9D, &namelessArg_3);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglUseFontBitmapsA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglUseFontBitmapsW(
      HDC    namelessArg_0  ,
      DWORD  namelessArg_1  ,
      DWORD  namelessArg_2  ,
      DWORD  namelessArg_3  );

*/
void EmuApi::EmuwglUseFontBitmapsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    DWORD namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);

    DWORD namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);

    DWORD namelessArg_3{};
    uc_reg_read(uc, UC_X86_REG_R9D, &namelessArg_3);


    BOOL wglUseFontBitmapsWResult = wglUseFontBitmapsW((HDC)namelessArg_0,(DWORD)namelessArg_1,(DWORD)namelessArg_2,(DWORD)namelessArg_3);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglUseFontBitmapsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    uc_reg_write(uc, UC_X86_REG_R9D, &namelessArg_3);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglUseFontBitmapsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SwapBuffers(
      HDC  namelessArg_0  );

*/
void EmuApi::EmuSwapBuffers(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);


    BOOL SwapBuffersResult = SwapBuffers((HDC)namelessArg_0);


    uc_reg_write(uc, UC_X86_REG_EAX, &SwapBuffersResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSwapBuffers\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglUseFontOutlinesA(
      HDC                  namelessArg_0  ,
      DWORD                namelessArg_1  ,
      DWORD                namelessArg_2  ,
      DWORD                namelessArg_3  ,
      FLOAT                namelessArg_4  ,
      FLOAT                namelessArg_5  ,
      int                  namelessArg_6  ,
      LPGLYPHMETRICSFLOAT  namelessArg_7  );

*/
void EmuApi::EmuwglUseFontOutlinesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    DWORD namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);

    DWORD namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);

    DWORD namelessArg_3{};
    uc_reg_read(uc, UC_X86_REG_R9D, &namelessArg_3);

    FLOAT namelessArg_4{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));

    FLOAT namelessArg_5{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &namelessArg_5, sizeof(namelessArg_5));

    int namelessArg_6{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &namelessArg_6, sizeof(namelessArg_6));

    LPGLYPHMETRICSFLOAT namelessArg_7{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &namelessArg_7, sizeof(namelessArg_7));

    GLYPHMETRICSFLOAT stnamelessArg_7{};

    if(namelessArg_7 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_7, &stnamelessArg_7, sizeof(stnamelessArg_7));
    }


    BOOL wglUseFontOutlinesAResult = wglUseFontOutlinesA((HDC)namelessArg_0,(DWORD)namelessArg_1,(DWORD)namelessArg_2,(DWORD)namelessArg_3,(FLOAT)namelessArg_4,(FLOAT)namelessArg_5,(int)namelessArg_6,(LPGLYPHMETRICSFLOAT)&stnamelessArg_7);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglUseFontOutlinesAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    uc_reg_write(uc, UC_X86_REG_R9D, &namelessArg_3);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &namelessArg_5, sizeof(namelessArg_5));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &namelessArg_6, sizeof(namelessArg_6));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &namelessArg_7, sizeof(namelessArg_7));

    if(namelessArg_7 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_7, &stnamelessArg_7, sizeof(stnamelessArg_7));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglUseFontOutlinesA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglUseFontOutlinesW(
      HDC                  namelessArg_0  ,
      DWORD                namelessArg_1  ,
      DWORD                namelessArg_2  ,
      DWORD                namelessArg_3  ,
      FLOAT                namelessArg_4  ,
      FLOAT                namelessArg_5  ,
      int                  namelessArg_6  ,
      LPGLYPHMETRICSFLOAT  namelessArg_7  );

*/
void EmuApi::EmuwglUseFontOutlinesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    DWORD namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);

    DWORD namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);

    DWORD namelessArg_3{};
    uc_reg_read(uc, UC_X86_REG_R9D, &namelessArg_3);

    FLOAT namelessArg_4{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));

    FLOAT namelessArg_5{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &namelessArg_5, sizeof(namelessArg_5));

    int namelessArg_6{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &namelessArg_6, sizeof(namelessArg_6));

    LPGLYPHMETRICSFLOAT namelessArg_7{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &namelessArg_7, sizeof(namelessArg_7));

    GLYPHMETRICSFLOAT stnamelessArg_7{};

    if(namelessArg_7 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_7, &stnamelessArg_7, sizeof(stnamelessArg_7));
    }


    BOOL wglUseFontOutlinesWResult = wglUseFontOutlinesW((HDC)namelessArg_0,(DWORD)namelessArg_1,(DWORD)namelessArg_2,(DWORD)namelessArg_3,(FLOAT)namelessArg_4,(FLOAT)namelessArg_5,(int)namelessArg_6,(LPGLYPHMETRICSFLOAT)&stnamelessArg_7);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglUseFontOutlinesWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    uc_reg_write(uc, UC_X86_REG_R9D, &namelessArg_3);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &namelessArg_5, sizeof(namelessArg_5));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &namelessArg_6, sizeof(namelessArg_6));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &namelessArg_7, sizeof(namelessArg_7));

    if(namelessArg_7 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_7, &stnamelessArg_7, sizeof(stnamelessArg_7));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglUseFontOutlinesW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglDescribeLayerPlane(
      HDC                     namelessArg_0  ,
      int                     namelessArg_1  ,
      int                     namelessArg_2  ,
      UINT                    namelessArg_3  ,
      LPLAYERPLANEDESCRIPTOR  namelessArg_4  );

*/
void EmuApi::EmuwglDescribeLayerPlane(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    int namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);

    int namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);

    UINT namelessArg_3{};
    uc_reg_read(uc, UC_X86_REG_R9D, &namelessArg_3);

    LPLAYERPLANEDESCRIPTOR namelessArg_4{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));

    LAYERPLANEDESCRIPTOR stnamelessArg_4{};

    if(namelessArg_4 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_4, &stnamelessArg_4, sizeof(stnamelessArg_4));
    }


    BOOL wglDescribeLayerPlaneResult = wglDescribeLayerPlane((HDC)namelessArg_0,(int)namelessArg_1,(int)namelessArg_2,(UINT)namelessArg_3,(LPLAYERPLANEDESCRIPTOR)&stnamelessArg_4);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglDescribeLayerPlaneResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    uc_reg_write(uc, UC_X86_REG_R9D, &namelessArg_3);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));

    if(namelessArg_4 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_4, &stnamelessArg_4, sizeof(stnamelessArg_4));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglDescribeLayerPlane\n";
    #endif

    return;
}


/*
int
__cdecl
wglSetLayerPaletteEntries(
      HDC               namelessArg_0  ,
      int               namelessArg_1  ,
      int               namelessArg_2  ,
      int               namelessArg_3  ,
      const COLORREF *  namelessArg_4  );

*/
void EmuApi::EmuwglSetLayerPaletteEntries(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    int namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);

    int namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);

    int namelessArg_3{};
    uc_reg_read(uc, UC_X86_REG_R9D, &namelessArg_3);

    COLORREF * namelessArg_4{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));

    DWORD rlnamelessArg_4{};

    if(namelessArg_4 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_4, &rlnamelessArg_4, sizeof(rlnamelessArg_4));
    }


    int wglSetLayerPaletteEntriesResult = wglSetLayerPaletteEntries((HDC)namelessArg_0,(int)namelessArg_1,(int)namelessArg_2,(int)namelessArg_3,(const COLORREF *)&rlnamelessArg_4);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglSetLayerPaletteEntriesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    uc_reg_write(uc, UC_X86_REG_R9D, &namelessArg_3);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));

    if(namelessArg_4 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_4, &rlnamelessArg_4, sizeof(rlnamelessArg_4));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglSetLayerPaletteEntries\n";
    #endif

    return;
}


/*
int
__cdecl
wglGetLayerPaletteEntries(
      HDC         namelessArg_0  ,
      int         namelessArg_1  ,
      int         namelessArg_2  ,
      int         namelessArg_3  ,
      COLORREF *  namelessArg_4  );

*/
void EmuApi::EmuwglGetLayerPaletteEntries(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    int namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);

    int namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);

    int namelessArg_3{};
    uc_reg_read(uc, UC_X86_REG_R9D, &namelessArg_3);

    COLORREF * namelessArg_4{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));

    DWORD rlnamelessArg_4{};

    if(namelessArg_4 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_4, &rlnamelessArg_4, sizeof(rlnamelessArg_4));
    }


    int wglGetLayerPaletteEntriesResult = wglGetLayerPaletteEntries((HDC)namelessArg_0,(int)namelessArg_1,(int)namelessArg_2,(int)namelessArg_3,(COLORREF *)&rlnamelessArg_4);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglGetLayerPaletteEntriesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    uc_reg_write(uc, UC_X86_REG_R9D, &namelessArg_3);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &namelessArg_4, sizeof(namelessArg_4));

    if(namelessArg_4 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_4, &rlnamelessArg_4, sizeof(rlnamelessArg_4));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglGetLayerPaletteEntries\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglRealizeLayerPalette(
      HDC   namelessArg_0  ,
      int   namelessArg_1  ,
      BOOL  namelessArg_2  );

*/
void EmuApi::EmuwglRealizeLayerPalette(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    int namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);

    BOOL namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);


    BOOL wglRealizeLayerPaletteResult = wglRealizeLayerPalette((HDC)namelessArg_0,(int)namelessArg_1,(BOOL)namelessArg_2);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglRealizeLayerPaletteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglRealizeLayerPalette\n";
    #endif

    return;
}


/*
BOOL
__cdecl
wglSwapLayerBuffers(
      HDC   namelessArg_0  ,
      UINT  namelessArg_1  );

*/
void EmuApi::EmuwglSwapLayerBuffers(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    UINT namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);


    BOOL wglSwapLayerBuffersResult = wglSwapLayerBuffers((HDC)namelessArg_0,(UINT)namelessArg_1);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglSwapLayerBuffersResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglSwapLayerBuffers\n";
    #endif

    return;
}


/*
DWORD
__cdecl
wglSwapMultipleBuffers(
      UINT             namelessArg_0  ,
      const WGLSWAP *  namelessArg_1  );

*/
void EmuApi::EmuwglSwapMultipleBuffers(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_ECX, &namelessArg_0);

    PWGLSWAP namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    WGLSWAP stnamelessArg_1{};

    if(namelessArg_1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_1, &stnamelessArg_1, sizeof(stnamelessArg_1));
    }


    DWORD wglSwapMultipleBuffersResult = wglSwapMultipleBuffers((UINT)namelessArg_0,(const WGLSWAP *)&stnamelessArg_1);


    uc_reg_write(uc, UC_X86_REG_EAX, &wglSwapMultipleBuffersResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_RDX, &namelessArg_1);

    if(namelessArg_1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_1, &stnamelessArg_1, sizeof(stnamelessArg_1));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwglSwapMultipleBuffers\n";
    #endif

    return;
}


