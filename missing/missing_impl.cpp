#include "missing_impl.h"
#include "dbiimpl.h"
#include "trace.h"
#include "pdb.h"
#include "crc32.h"
#include "srcimpl.h"
#include "array.h"
#include "utf8.h"
#include <Windows.h>
#include "cvdump.h"


BOOL IS_SZ_FORMAT_PDB(PDB1 *pdb) 
{
    //unimplemented; return true; 
    return true;
}
wchar_t *SZNameFromTSRecord(PTYPE pts, wchar_t *szNameBuf, unsigned short len) { unimplemented; return {  }; }
BOOL fNeedsSzConversion(PSYM psym)          { unimplemented; return {  }; }
BOOL fConvertSymRecStToSz(PSYM psym)        { unimplemented; return {  }; }
BOOL fIsRefSym(PSYM psym)                   { unimplemented; return {  }; }
SZ szUDTName(PB pb)                         { unimplemented; return {  }; }
CB cbForType(PTYPE ptypeT)                  { unimplemented; return {  }; }
BOOL fConvertTypeRecStToSz(PTYPE ptypeT) { unimplemented; return {  }; }
BOOL fNeedsSzConversion(PTYPE psym) { unimplemented; return {  }; }
BOOL fGetSymName(PSYM psym, ST *st) { unimplemented; return {  }; }
BOOL fSymIsData(PSYM) { unimplemented; return {  }; }
BOOL fSymIsGlobal(PSYM) { unimplemented; return {  }; }
PB pbEndType(PTYPE ptypeT) { unimplemented; return {  }; }
BOOL fNeeds16bitConversion(PTYPE ptypeT) { unimplemented; return {  }; }
BOOL trace_(TR tr, const char* szFmt, ...) 
{
    va_list ap;
    va_start(ap, szFmt);
    vprintf(szFmt, ap);
    va_end(ap);
    return TRUE;
}
BOOL traceW_(TR tr, const wchar_t* szFmt, ...)
{ 
    va_list ap;
    va_start(ap, szFmt);
    vwprintf(szFmt, ap);
    va_end(ap);
    return TRUE;
}

template<>
BOOL Array<unsigned long>::save(Buffer* pbuf) const { unimplemented; return {  }; }

BOOL NameMap::open(PDB* ppdb, BOOL fWrite, OUT NameMap** ppnm) { unimplemented; return {  }; }

BOOL WidenTi::fCreate(
    WidenTi *&widen_ti,
    unsigned cTypeInitialCache,
    BOOL fNB10Syms)
{
    unimplemented; return {};
}

bool SrcCommon::Add(IN PCSrcHeader psrcheader, IN const void * pvData) { unimplemented; return {  }; }
bool SrcCommon::QueryByName(IN SZ_CONST szFile, OUT PSrcHeaderOut psrcheaderOut) const { unimplemented; return {  }; }
// 
// SrcImpl
//

SrcImpl::SrcImpl(struct PDB *pdb) { unimplemented; }
SrcImpl::~SrcImpl() { unimplemented; }
bool SrcImpl::internalInit(bool fWrite) { unimplemented; return {  }; }
bool SrcImpl::Close() { unimplemented; return {  }; }
bool SrcImpl::Remove(IN SZ_CONST szFile) { unimplemented; return {  }; }
bool SrcImpl::GetData(IN PCSrcHeaderOut pcsrcheader, OUT void * pvData) const { unimplemented; return {  }; }
bool SrcImpl::GetEnum(OUT EnumSrc ** ppenum) const { unimplemented; return {  }; }
bool SrcImpl::GetHeaderBlock(SrcHeaderBlock &shb) const { unimplemented; return {  }; }
bool SrcImpl::RemoveW(__in_z wchar_t *wcsFile) { unimplemented; return {  }; }
bool SrcImpl::QueryByNameW(__in_z wchar_t *wcsFile, OUT PSrcHeaderOut psrcheaderOut) const { unimplemented; return {  }; }
bool SrcImpl::AddW(PCSrcHeaderW psrcheader, const void * pvData)  { unimplemented; return {  }; }
bool SrcImpl::fBuildStreamName(WSZ_CONST szFile, _Out_opt_z_cap_(cchStreamNameMax) wchar_t szStrmName[cchStreamNameMax]) { unimplemented; return {  }; }


//BOOL Mod1::fInit() { unimplemented; return {  }; }
//BOOL Mod1::QueryFileChecksums(DWORD cb, PB pb, DWORD *pcb) { unimplemented; return {  }; }
//BOOL Mod1::QueryLines3(DWORD cb, PB pb, DWORD *pcb) { unimplemented; return {  }; }

// 
// UTF8 Unicode Impls
//

size_t UTF8ToUnicode(LPCSTR lpSrcStr, __out_ecount_opt(cchDest) LPWSTR lpDestStr, size_t cchDest)
{
    size_t src_size = strlen(lpSrcStr);
    if(src_size > 0)
        expect(cchDest >= src_size + 1);

    int res = ::mbstowcs(lpDestStr, lpSrcStr, cchDest);
    return (res != src_size) ? 0 : src_size;
}
size_t UTF8ToUnicodeCch(LPCSTR lpSrcStr, size_t cchSrc, __out_ecount_opt(cchDest) LPWSTR lpDestStr, size_t cchDest)
{
    unimplemented; return 0;
}
size_t UnicodeToUTF8(LPCWSTR lpSrcStr, __out_ecount_opt(cchDest) LPSTR lpDestStr, size_t cchDest)
{
    unimplemented; return 0;
}
size_t UnicodeToUTF8Cch(LPCWSTR lpSrcStr, size_t cchSrc, __out_ecount_opt(cchDest) LPSTR lpDestStr, size_t cchDest)
{
    unimplemented; return 0;
}
size_t UnicodeLengthOfUTF8(PCSTR pUTF8)
{
    size_t len = lstrlenA(pUTF8);
    return (len == 0) ? 0 : len + 1; // NT, functions use this for allocation
}
size_t UTF8LengthOfUnicode(PCWSTR pUni)
{
    size_t len = lstrlenW(pUni);
    return (len == 0) ? 0 : len + 1; // NT, functions use this for allocation
}
size_t UnicodeLengthOfUTF8Cb(PCSTR pUTF8, size_t cbUTF)
{
    unimplemented; return 0;
}
size_t UTF8LengthOfUnicodeCch(PCWSTR pUni, size_t cchUni)
{
    unimplemented; return 0;
}

//
// TypeTiIter
//
TypeTiIter::TypeTiIter(PTYPE type)      { unimplemented; }
bool TypeTiIter::next()                 { unimplemented; return 0; }
bool TypeTiIter::nextField()            { unimplemented; return 0; }
PB TypeTiIter::pbEndCurFieldSansPad()   { unimplemented; return 0; }
void *TypeTiIter::pbCurField()          { unimplemented; return 0; }
TI &TypeTiIter::rti()                   { unimplemented; return x; }
bool TypeTiIter::fId()                  { unimplemented; return 0; }
//struct TypeTiIter
//{
//    TI x;
//    TypeTiIter(PTYPE type);
//    bool next();
//    TI &rti();
//    bool fId();
//};

//
// cvdump.h
//
void        DumpCom()                   { unimplemented; }
void        DumpTyp()                   { unimplemented; }
void        DumpModTypC7(size_t cbTyp)  { unimplemented; }

// dumppdb.cpp
//void        DumpPdb(PDB *)                  { unimplemented; }
//void        DumpPdbFile(const wchar_t *) { unimplemented; }
//void        ShowUdtTypeId(TPI *, const char *) { unimplemented; }
//DWORD       PdbMapToken(DWORD tokenOld) { unimplemented; return 0; }


BOOL fValidateSz(SZ szStart, SZ szEnd) 
{
    //unimplemented;
    precondition(szEnd && szStart);
    return szStart < szEnd && *(szEnd - 1) == '\0';
}
BOOL fValidateSz(PB szStart, PB szEnd)
{
    //unimplemented;
    precondition(szEnd && szStart);
    return szStart < szEnd && *(szEnd - 1) == '\0';
}

CV_typ_t DumpTypRecC7(CV_typ_t cvt, WORD w, BYTE *pb, TPI *tpi, PDB *pdb) { unimplemented; return {}; }

// 
// MOD1.cpp classes
//
