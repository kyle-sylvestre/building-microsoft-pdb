#pragma once
#include <cassert>
#include <conio.h>

const int rmj = 1;
const int rmm = 1;
const int rup = 1;
const int rbld = 1;

typedef unsigned long ulong;
typedef unsigned short ushort;
typedef unsigned int uint;

typedef unsigned long ULONG;
typedef unsigned short USHORT;
typedef unsigned int UINT;
typedef int BOOL;
#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

typedef unsigned char*	PB;			// pointer to some bytes
typedef long	        CB;			// count of bytes

#define dassert         assert
#define precondition    dassert
#define postcondition   dassert
#define debug(x) x

//#define unimplemented assert(false)
#define unimplemented do {\
    printf("Function not found!: " __FUNCTION__ "\n");\
    _getch();\
}while(0)

#if !defined verify
  #ifdef _DEBUG
    #define verify(x)       assert((x))
  #else
    #define verify(x)       (x)
  #endif
#endif  // verify

typedef char *ST;   // Length appended string
typedef char *SZ;   // Null Terminated String
typedef unsigned char *PB; //Pointer to bytes

struct TYPTYPE;
typedef TYPTYPE* PTYPE;

struct SYMTYPE;
typedef SYMTYPE* PSYM;

typedef ULONG SIG;
typedef unsigned long DWORD;

wchar_t *SZNameFromTSRecord(PTYPE pts, wchar_t *szNameBuf, unsigned short len);
BOOL fNeedsSzConversion(PSYM psym);
BOOL fConvertSymRecStToSz(PSYM psym);
BOOL fIsRefSym(PSYM psym);
SZ szUDTName(PB pb);
PB pbEndType(PTYPE ptypeT);
CB cbForType(PTYPE ptypeT);
BOOL fNeedsSzConversion(PTYPE psym);
BOOL fConvertTypeRecStToSz(PTYPE ptypeT);
BOOL fGetSymName(PSYM psym, ST *st);
BOOL fSymIsData(PSYM);
BOOL fSymIsGlobal(PSYM); 
BOOL fNeeds16bitConversion(PTYPE ptypeT);
BOOL fValidateSz(SZ a, SZ b);
BOOL fValidateSz(PB szStart, PB szEnd);

//class IDebugSSubSectionEnum;
//class IDebugSLines;
//class IDebugSLineBlockEnum;
