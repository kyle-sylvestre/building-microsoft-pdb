#pragma once


// Invalid Placeholders

struct DirEntry 
{ 
    WORD        SubSectionType;
    WORD        ModuleIndex;
    DWORD       lfoStart;
    SIZE_T      Size; 
};

#define SSTMODULE 0x1
#define SSTPUBLIC 0x2
#define SSTTYPES  0x3
#define SSTSYMBOLS 0x4
#define SSTLIBRARIES 0x5
#define SSTSRCLNSEG 0x6

typedef struct _IMAGE_FILE_HEADER_EX {
    WORD    Machine;
    WORD    NumberOfSections;
    DWORD   TimeDateStamp;
    DWORD   PointerToSymbolTable;
    DWORD   NumberOfSymbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER_EX, *PIMAGE_FILE_HEADER_EX;



#define EXTENDED_COFF_OBJ_GUID "slkdjfs"