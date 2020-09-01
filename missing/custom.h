#pragma once

#include "cvinfo.h"
#include "pdbtypdefs.h"
#include "pdb.h"


// @@@ from szst.h
typedef char *UTFSZ;
typedef const char *UTFSZ_CONST;

// try to patch up the holes in the codebase
class Allocator
{
public:
    void *fAllocBytes(size_t Bytes) { return nullptr; }
    void *AllocBytes(size_t Bytes) { return nullptr; }
};

template<size_t N>
struct SafeStackAllocator : public Allocator
{
    size_t Size = N;

    template<typename T>
    T *Alloc(size_t Bytes) { return nullptr; }
};

class SymTiIter
{
public:
    SymTiIter(SYMTYPE *psym) {}
    TI rti() { return {}; }
    bool next() { return false; }
    bool fId() { return false; }
};

inline void *pbEndSym(SYMTYPE *psym) { return nullptr; }

#define SZLEAFIDX(x) x
#define SZSYMIDX(x) x
inline void fGetSymRecTypName(SYMTYPE *psym, const char **foo) {}
inline bool fNameFromSym(SYMTYPE *psym, wchar_t *szName, unsigned long *len) { return false; }
inline size_t cbForSt(ST stName) { return 0; }


#define PREFAST_SUPPRESS(x, y)

template <typename T>
class COMRefPtr
{
public:
    T *intr;

    //T *operator () { return intr; }
    T **operator &() { return &intr; }
    void operator =(T *value) { intr = value; }
    //operator =(unsigned __int64 value) { intr = (T *)value; }

    T &operator *() { return *intr; }
    T *operator ->() { return intr; }
    bool operator ==(T *value) { return (intr == value); }

};

inline BOOL FCalculateSHA256(PB pb, unsigned long cb, PB *pbHash, unsigned long *cbHash)
{
    return false;
}

