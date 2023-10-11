typedef unsigned char   undefined;

typedef pointer32 ImageBaseOffset32;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef int    wchar_t;
typedef unsigned short    word;
#define unkbyte9   unsigned long long
#define unkbyte10   unsigned long long
#define unkbyte11   unsigned long long
#define unkbyte12   unsigned long long
#define unkbyte13   unsigned long long
#define unkbyte14   unsigned long long
#define unkbyte15   unsigned long long
#define unkbyte16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory;
    dword DataIsDirectory;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

typedef unsigned short    wchar16;
typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

typedef ulong ULONG_PTR;

typedef union _union_518 _union_518, *P_union_518;

typedef void * HANDLE;

typedef struct _struct_519 _struct_519, *P_struct_519;

typedef void * PVOID;

typedef ulong DWORD;

struct _struct_519 {
    DWORD Offset;
    DWORD OffsetHigh;
};

union _union_518 {
    struct _struct_519 s;
    PVOID Pointer;
};

struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union _union_518 u;
    HANDLE hEvent;
};

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

typedef void * LPVOID;

typedef int BOOL;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef struct _TIME_ZONE_INFORMATION _TIME_ZONE_INFORMATION, *P_TIME_ZONE_INFORMATION;

typedef struct _TIME_ZONE_INFORMATION * LPTIME_ZONE_INFORMATION;

typedef long LONG;

typedef wchar_t WCHAR;

typedef struct _SYSTEMTIME _SYSTEMTIME, *P_SYSTEMTIME;

typedef struct _SYSTEMTIME SYSTEMTIME;

typedef ushort WORD;

struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};

struct _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
};

typedef struct _OVERLAPPED * LPOVERLAPPED;

typedef struct _SECURITY_ATTRIBUTES * LPSECURITY_ATTRIBUTES;

typedef struct _STARTUPINFOA _STARTUPINFOA, *P_STARTUPINFOA;

typedef char CHAR;

typedef CHAR * LPSTR;

typedef uchar BYTE;

typedef BYTE * LPBYTE;

struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
};

typedef struct _STARTUPINFOA * LPSTARTUPINFOA;

typedef struct _SYSTEMTIME * LPSYSTEMTIME;

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA, *P_FLOATING_SAVE_AREA;

typedef struct _FLOATING_SAVE_AREA FLOATING_SAVE_AREA;

struct _FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[80];
    DWORD Cr0NpxState;
};

struct _CONTEXT {
    DWORD ContextFlags;
    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;
    FLOATING_SAVE_AREA FloatSave;
    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;
    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;
    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;
    BYTE ExtendedRegisters[512];
};

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD * ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD * PEXCEPTION_RECORD;

typedef struct _CONTEXT CONTEXT;

typedef CONTEXT * PCONTEXT;

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

typedef BOOL (* PHANDLER_ROUTINE)(DWORD);

typedef struct Rect16 Rect16, *PRect16;

struct Rect16 {
    short x;
    short y;
    short w;
    short h;
};

typedef struct SavedPartEntity SavedPartEntity, *PSavedPartEntity;

struct SavedPartEntity {
    short x;
    short row;
    short partId;
};

typedef struct Room Room, *PRoom;

typedef struct OtherEntity OtherEntity, *POtherEntity;

typedef struct LadderEntity LadderEntity, *PLadderEntity;

typedef struct Dlist Dlist, *PDlist;

typedef struct EntityBase? EntityBase?, *PEntityBase?;

typedef short PartId;

typedef struct RectEx RectEx, *PRectEx;

typedef struct DlistNode DlistNode, *PDlistNode;

typedef struct EntityBaseBase? EntityBaseBase?, *PEntityBaseBase?;

typedef short EntityType;

struct Dlist {
    struct DlistNode * head;
    struct DlistNode * tail;
};

struct RectEx {
    struct Rect16 rect;
    undefined2 mode;
};

struct EntityBaseBase? {
    struct Rect16 inner;
    undefined field1_0x8;
    undefined field2_0x9;
    undefined field3_0xa;
    undefined field4_0xb;
    undefined field5_0xc;
    undefined field6_0xd;
};

struct EntityBase? {
    struct EntityBaseBase? rect;
    ushort spriteId;
    EntityType type;
};

struct OtherEntity {
    struct EntityBase? base;
    PartId partId;
    undefined field2_0x14;
    undefined field3_0x15;
    struct RectEx activation?;
};

struct LadderEntity {
    struct EntityBase? base;
    undefined field1_0x12;
    undefined field2_0x13;
    undefined field3_0x14;
    undefined field4_0x15;
    undefined field5_0x16;
    undefined field6_0x17;
    undefined field7_0x18;
    undefined field8_0x19;
    undefined field9_0x1a;
    undefined field10_0x1b;
    undefined field11_0x1c;
    undefined field12_0x1d;
    struct RectEx collision?;
};

struct DlistNode {
    struct DlistNode * next;
    struct DlistNode * prev;
};

struct Room {
    ushort flags; // bit 0 obverse
    short structuralEntityCounts[4];
    short ladderEntityCounts[4];
    short cEntityCounts?[6];
    undefined4 cEntityGroups?[6];
    short dEntityCounts?[6];
    undefined4 dEntityGroups?[6];
    short eEntityCounts?[6];
    undefined4 eEntityGroups?[6];
    struct OtherEntity * structuralEntityGroups[4];
    struct LadderEntity * ladderEntityGroups[4];
    short partEntityCount;
    struct Dlist * partEntities;
    undefined2 field13_0xa4[6];
    undefined2 field14_0xb0[6];
    undefined2 field15_0xbc[50];
    undefined entities[468];
};

typedef struct Actor Actor, *PActor;

struct Actor {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined * currentDynamics;
    undefined * obverseDynamics;
    undefined * reverseDynamics;
    undefined field85_0x5e;
    undefined field86_0x5f;
    undefined field87_0x60;
    undefined field88_0x61;
    undefined field89_0x62;
    undefined field90_0x63;
    undefined field91_0x64;
    undefined field92_0x65;
    undefined field93_0x66;
    undefined field94_0x67;
    undefined field95_0x68;
    undefined field96_0x69;
    undefined field97_0x6a;
    undefined field98_0x6b;
    undefined field99_0x6c;
    undefined field100_0x6d;
    undefined field101_0x6e;
    undefined field102_0x6f;
    undefined field103_0x70;
    undefined field104_0x71;
    undefined field105_0x72;
    undefined field106_0x73;
    undefined field107_0x74;
    undefined field108_0x75;
    undefined field109_0x76;
    undefined field110_0x77;
    undefined field111_0x78;
    undefined field112_0x79;
    undefined field113_0x7a;
    undefined field114_0x7b;
    undefined field115_0x7c;
    undefined field116_0x7d;
    undefined field117_0x7e;
    undefined field118_0x7f;
    undefined field119_0x80;
    undefined field120_0x81;
    undefined field121_0x82;
    undefined field122_0x83;
    undefined field123_0x84;
    undefined field124_0x85;
    undefined field125_0x86;
    undefined field126_0x87;
    undefined field127_0x88;
    undefined field128_0x89;
    undefined field129_0x8a;
    undefined field130_0x8b;
    undefined field131_0x8c;
    undefined field132_0x8d;
    undefined field133_0x8e;
    undefined field134_0x8f;
    undefined field135_0x90;
    undefined field136_0x91;
    undefined field137_0x92;
    undefined field138_0x93;
    undefined field139_0x94;
    undefined field140_0x95;
    undefined field141_0x96;
    undefined field142_0x97;
    undefined field143_0x98;
    undefined field144_0x99;
    undefined field145_0x9a;
    undefined field146_0x9b;
    undefined field147_0x9c;
    undefined field148_0x9d;
    undefined field149_0x9e;
    undefined field150_0x9f;
    undefined field151_0xa0;
    undefined field152_0xa1;
    undefined field153_0xa2;
    undefined field154_0xa3;
    undefined field155_0xa4;
    undefined field156_0xa5;
    undefined field157_0xa6;
    undefined field158_0xa7;
};

typedef struct Area Area, *PArea;

struct Area {
    short roomCount;
    struct Room rooms[16];
    undefined field2_0x2f42[32928];
};

typedef struct HeapNode HeapNode, *PHeapNode;

struct HeapNode {
    struct DlistNode node;
    void * heap;
};

typedef struct PartResource PartResource, *PPartResource;

struct PartResource {
    undefined field0_0x0;
    undefined field1_0x1;
    short definitionCount;
    short slotCount;
    short criticalSlotCount;
    undefined field5_0x8;
    undefined field6_0x9;
    undefined field7_0xa;
    undefined field8_0xb;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
    undefined field13_0x10;
    undefined field14_0x11;
    undefined field15_0x12;
    undefined field16_0x13;
    undefined field17_0x14;
    undefined field18_0x15;
    undefined field19_0x16;
    undefined field20_0x17;
    undefined field21_0x18;
    undefined field22_0x19;
    undefined field23_0x1a;
    undefined field24_0x1b;
    undefined field25_0x1c;
    undefined field26_0x1d;
    undefined field27_0x1e;
    undefined field28_0x1f;
    undefined field29_0x20;
    undefined field30_0x21;
    undefined field31_0x22;
    undefined field32_0x23;
    undefined field33_0x24;
    undefined field34_0x25;
    undefined field35_0x26;
    undefined field36_0x27;
    undefined field37_0x28;
    undefined field38_0x29;
    undefined field39_0x2a;
    undefined field40_0x2b;
    undefined field41_0x2c;
    undefined field42_0x2d;
    undefined field43_0x2e;
    undefined field44_0x2f;
};

typedef struct PuzzleState PuzzleState, *PPuzzleState;

struct PuzzleState {
    undefined2 completion[43];
    undefined2 mode{0,1,2,3,4}; // 0 = on, 1 = off, 2 = fully solved, 3 = on (endgame), 4 = off (endgame)
};

typedef struct EntityNode EntityNode, *PEntityNode;

struct EntityNode {
    struct DlistNode node;
    undefined2 available;
    undefined field2_0xa;
    undefined field3_0xb;
    struct OtherEntity inner;
};

typedef struct GameState GameState, *PGameState;

typedef struct BuildingState BuildingState, *PBuildingState;

struct BuildingState {
    undefined field0_0x0[620];
    char puzzleDoors[150];
    short savedPartEntities;
    undefined field3_0x304[398];
    undefined field4_0x492[552];
};

struct GameState {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined2 field28_0x1c;
    undefined2 field29_0x1e;
    ushort missingCriticalSlots;
    short installedParts;
    undefined2 everBeenReadyToRace?;
    undefined2 field33_0x26;
    undefined2 field34_0x28;
    undefined field35_0x2a;
    undefined field36_0x2b;
    ushort field37_0x2c;
    short level; // [0,15)
    short building; // [0,3)
    short levelInBuilding; // [0,5)
    short buildingCompletedLevels[3]; // [0,5) or -1
    short buildingIsInitialised[3]; // true iff parts placement is done
    undefined field43_0x40[48];
    struct PuzzleState puzzles[8]; // balance, electricity, energy, force, gear, jigsaw, magnet, smachine
    struct BuildingState buildings[3];
    undefined field46_0x175e[5999];
};

typedef struct PartDefinition PartDefinition, *PPartDefinition;

struct PartDefinition {
    struct DlistNode field0_0x0;
    short slotId;
    undefined field2_0xa;
    undefined field3_0xb;
    undefined field4_0xc;
    undefined field5_0xd;
    undefined field6_0xe;
    undefined field7_0xf;
    undefined field8_0x10;
    undefined field9_0x11;
    undefined field10_0x12;
    undefined field11_0x13;
    undefined field12_0x14;
    undefined field13_0x15;
    undefined field14_0x16;
    undefined field15_0x17;
    undefined field16_0x18;
    undefined field17_0x19;
    undefined field18_0x1a;
    undefined field19_0x1b;
    undefined field20_0x1c;
    undefined field21_0x1d;
    undefined field22_0x1e;
    undefined field23_0x1f;
    undefined field24_0x20;
    undefined field25_0x21;
    undefined field26_0x22;
    undefined field27_0x23;
    undefined field28_0x24;
    undefined field29_0x25;
    undefined field30_0x26;
    undefined field31_0x27;
    undefined field32_0x28;
    undefined field33_0x29;
    undefined field34_0x2a;
    undefined field35_0x2b;
    undefined field36_0x2c;
    undefined field37_0x2d;
    undefined field38_0x2e;
    undefined field39_0x2f;
    undefined field40_0x30;
    undefined field41_0x31;
    undefined field42_0x32;
    undefined field43_0x33;
    undefined field44_0x34;
    undefined field45_0x35;
    undefined field46_0x36;
    byte flags; // bit 6 = recycled
    undefined field48_0x38;
    undefined field49_0x39;
    undefined field50_0x3a;
    undefined field51_0x3b;
    undefined field52_0x3c;
    undefined field53_0x3d;
    undefined field54_0x3e;
    undefined field55_0x3f;
    undefined field56_0x40;
    undefined field57_0x41;
    undefined field58_0x42;
    undefined field59_0x43;
    undefined field60_0x44;
    undefined field61_0x45;
    undefined field62_0x46;
    undefined field63_0x47;
    undefined field64_0x48;
    undefined field65_0x49;
    undefined field66_0x4a;
    undefined field67_0x4b;
    undefined field68_0x4c;
    undefined field69_0x4d;
    undefined field70_0x4e;
    undefined field71_0x4f;
    undefined field72_0x50;
    undefined field73_0x51;
    undefined field74_0x52;
    undefined field75_0x53;
    undefined field76_0x54;
    undefined field77_0x55;
    undefined field78_0x56;
    undefined field79_0x57;
    undefined field80_0x58;
    undefined field81_0x59;
    undefined field82_0x5a;
    undefined field83_0x5b;
    undefined field84_0x5c;
    undefined field85_0x5d;
    undefined field86_0x5e;
    undefined field87_0x5f;
    undefined field88_0x60;
    undefined field89_0x61;
};

typedef short PuzzleCategory;

typedef struct tagWNDCLASSA tagWNDCLASSA, *PtagWNDCLASSA;

typedef uint UINT;

typedef long LONG_PTR;

typedef LONG_PTR LRESULT;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ * HWND;

typedef uint UINT_PTR;

typedef UINT_PTR WPARAM;

typedef LONG_PTR LPARAM;

typedef LRESULT (* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ * HINSTANCE;

typedef struct HICON__ HICON__, *PHICON__;

typedef struct HICON__ * HICON;

typedef HICON HCURSOR;

typedef struct HBRUSH__ HBRUSH__, *PHBRUSH__;

typedef struct HBRUSH__ * HBRUSH;

typedef CHAR * LPCSTR;

struct HBRUSH__ {
    int unused;
};

struct tagWNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
};

struct HICON__ {
    int unused;
};

struct HINSTANCE__ {
    int unused;
};

struct HWND__ {
    int unused;
};

typedef struct tagMSG tagMSG, *PtagMSG;

typedef struct tagMSG MSG;

typedef struct tagPOINT tagPOINT, *PtagPOINT;

typedef struct tagPOINT POINT;

struct tagPOINT {
    LONG x;
    LONG y;
};

struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
};

typedef struct tagMSG * LPMSG;

typedef struct tagWNDCLASSA WNDCLASSA;

typedef struct tagWNDCLASSEXA tagWNDCLASSEXA, *PtagWNDCLASSEXA;

typedef struct tagWNDCLASSEXA WNDCLASSEXA;

struct tagWNDCLASSEXA {
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
};

typedef struct tagPAINTSTRUCT tagPAINTSTRUCT, *PtagPAINTSTRUCT;

typedef struct tagPAINTSTRUCT * LPPAINTSTRUCT;

typedef struct HDC__ HDC__, *PHDC__;

typedef struct HDC__ * HDC;

typedef struct tagRECT tagRECT, *PtagRECT;

typedef struct tagRECT RECT;

struct HDC__ {
    int unused;
};

struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

struct tagPAINTSTRUCT {
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
};

typedef struct tagPAINTSTRUCT PAINTSTRUCT;

typedef BOOL (* WNDENUMPROC)(HWND, LPARAM);

typedef int INT_PTR;

typedef INT_PTR (* DLGPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct tagPALETTEENTRY tagPALETTEENTRY, *PtagPALETTEENTRY;

typedef struct tagPALETTEENTRY PALETTEENTRY;

struct tagPALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
};

typedef struct tagBITMAPINFO tagBITMAPINFO, *PtagBITMAPINFO;

typedef struct tagBITMAPINFOHEADER tagBITMAPINFOHEADER, *PtagBITMAPINFOHEADER;

typedef struct tagBITMAPINFOHEADER BITMAPINFOHEADER;

typedef struct tagRGBQUAD tagRGBQUAD, *PtagRGBQUAD;

typedef struct tagRGBQUAD RGBQUAD;

struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};

struct tagRGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
};

struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[1];
};

typedef struct tagBITMAPINFO BITMAPINFO;

typedef struct tagLOGPALETTE tagLOGPALETTE, *PtagLOGPALETTE;

typedef struct tagLOGPALETTE LOGPALETTE;

struct tagLOGPALETTE {
    WORD palVersion;
    WORD palNumEntries;
    PALETTEENTRY palPalEntry[1];
};

typedef struct tagPALETTEENTRY * LPPALETTEENTRY;

typedef LONG * PLONG;

typedef CHAR * LPCH;

typedef struct _OSVERSIONINFOA _OSVERSIONINFOA, *P_OSVERSIONINFOA;

struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR szCSDVersion[128];
};

typedef struct _OSVERSIONINFOA * LPOSVERSIONINFOA;

typedef short SHORT;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[192]; // Actual DOS program
};

typedef ULONG_PTR DWORD_PTR;

typedef ULONG_PTR SIZE_T;

typedef struct tagPOINT * LPPOINT;

typedef struct tagPOINTS tagPOINTS, *PtagPOINTS;

struct tagPOINTS {
    SHORT x;
    SHORT y;
};

typedef struct tagPOINTS POINTS;

typedef struct HPALETTE__ HPALETTE__, *PHPALETTE__;

struct HPALETTE__ {
    int unused;
};

typedef HINSTANCE HMODULE;

typedef int (* FARPROC)(void);

typedef WORD ATOM;

typedef struct tagRECT * LPRECT;

typedef void * HGDIOBJ;

typedef struct HRSRC__ HRSRC__, *PHRSRC__;

typedef struct HRSRC__ * HRSRC;

struct HRSRC__ {
    int unused;
};

typedef DWORD COLORREF;

typedef DWORD * LPDWORD;

typedef struct HPALETTE__ * HPALETTE;

typedef void * LPCVOID;

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ * HMENU;

struct HMENU__ {
    int unused;
};

typedef int INT;

typedef int HFILE;

typedef HANDLE HGLOBAL;

typedef BYTE * PBYTE;

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct Var Var, *PVar;

struct Var {
    word wLength;
    word wValueLength;
    word wType;
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset;
    dword NameIsString;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 332
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef struct IMAGE_RESOURCE_DIR_STRING_U_16 IMAGE_RESOURCE_DIR_STRING_U_16, *PIMAGE_RESOURCE_DIR_STRING_U_16;

struct IMAGE_RESOURCE_DIR_STRING_U_16 {
    word Length;
    wchar16 NameString[8];
};

typedef struct StringFileInfo StringFileInfo, *PStringFileInfo;

struct StringFileInfo {
    word wLength;
    word wValueLength;
    word wType;
};

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    dword Name;
    word Id;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct StringTable StringTable, *PStringTable;

struct StringTable {
    word wLength;
    word wValueLength;
    word wType;
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_RESOURCE_DIR_STRING_U_8 IMAGE_RESOURCE_DIR_STRING_U_8, *PIMAGE_RESOURCE_DIR_STRING_U_8;

struct IMAGE_RESOURCE_DIR_STRING_U_8 {
    word Length;
    wchar16 NameString[4];
};

typedef struct VS_VERSION_INFO VS_VERSION_INFO, *PVS_VERSION_INFO;

struct VS_VERSION_INFO {
    word StructLength;
    word ValueLength;
    word StructType;
    wchar16 Info[16];
    byte Padding[2];
    dword Signature;
    word StructVersion[2];
    word FileVersion[4];
    word ProductVersion[4];
    dword FileFlagsMask[2];
    dword FileFlags;
    dword FileOS;
    dword FileType;
    dword FileSubtype;
    dword FileTimestamp;
};

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};

typedef struct VarFileInfo VarFileInfo, *PVarFileInfo;

struct VarFileInfo {
    word wLength;
    word wValueLength;
    word wType;
};

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};

typedef struct IMAGE_DIRECTORY_ENTRY_EXPORT IMAGE_DIRECTORY_ENTRY_EXPORT, *PIMAGE_DIRECTORY_ENTRY_EXPORT;

struct IMAGE_DIRECTORY_ENTRY_EXPORT {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Name;
    dword Base;
    dword NumberOfFunctions;
    dword NumberOfNames;
    dword AddressOfFunctions;
    dword AddressOfNames;
    dword AddressOfNameOrdinals;
};

typedef struct StringInfo StringInfo, *PStringInfo;

struct StringInfo {
    word wLength;
    word wValueLength;
    word wType;
};

typedef struct HWAVEOUT__ HWAVEOUT__, *PHWAVEOUT__;

struct HWAVEOUT__ {
    int unused;
};

typedef struct tWAVEFORMATEX tWAVEFORMATEX, *PtWAVEFORMATEX;

struct tWAVEFORMATEX {
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
    WORD wBitsPerSample;
    WORD cbSize;
};

typedef UINT MMVERSION;

typedef struct timecaps_tag timecaps_tag, *Ptimecaps_tag;

struct timecaps_tag {
    UINT wPeriodMin;
    UINT wPeriodMax;
};

typedef struct wavehdr_tag wavehdr_tag, *Pwavehdr_tag;

typedef struct wavehdr_tag * LPWAVEHDR;

struct wavehdr_tag {
    LPSTR lpData;
    DWORD dwBufferLength;
    DWORD dwBytesRecorded;
    DWORD_PTR dwUser;
    DWORD dwFlags;
    DWORD dwLoops;
    struct wavehdr_tag * lpNext;
    DWORD_PTR reserved;
};

typedef struct tWAVEFORMATEX WAVEFORMATEX;

typedef WAVEFORMATEX * LPCWAVEFORMATEX;

typedef DWORD MCIERROR;

typedef struct HWAVEOUT__ * HWAVEOUT;

typedef HWAVEOUT * LPHWAVEOUT;

typedef struct tagMIDIOUTCAPSA tagMIDIOUTCAPSA, *PtagMIDIOUTCAPSA;

struct tagMIDIOUTCAPSA {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[32];
    WORD wTechnology;
    WORD wVoices;
    WORD wNotes;
    WORD wChannelMask;
    DWORD dwSupport;
};

typedef UINT MMRESULT;

typedef UINT MCIDEVICEID;

typedef struct timecaps_tag * LPTIMECAPS;

typedef struct tagMIDIOUTCAPSA * LPMIDIOUTCAPSA;




char * __stdcall GetWinapiStringAlloc(UINT id);
void __stdcall GetWinapiString(char *result,UINT id);
void InitEntities(void);
void StartLevel(void);
ushort __stdcall RoomIsObverse(short roomIndex);
EntityNode * NextAvailableEntityNode(void);
ushort __stdcall PlacePartEntity(Room *room,short count,PartId partId);
void __stdcall LoadPartEntity(short roomIndex,short x,short row,short partId,short param_5);
void __stdcall LoadEntities(char *puzzleEntityTypes,SavedPartEntity *partEntities);
uint __stdcall CheckCollision(Rect16 *p,Rect16 *q);
int __stdcall CountCompletedPuzzles(PuzzleCategory category);
void __stdcall ShowAlertMessage(char *param_1,undefined param_2);
void __stdcall DonkeyShuffle(short len,short *result);
void __stdcall EnterBuilding(void);
void __stdcall ActorUpdateDynamics(short actorIndex,short obverse);
undefined4 __stdcall DlistHead(undefined4 *param_1);
undefined4 __stdcall DlistNext(undefined4 *param_1);
void __stdcall DlistInsert(Dlist *list,DlistNode *node,short beforeIndex);
void __stdcall DlistRemove(Dlist *list,DlistNode *node);
Dlist * DlistNew(void);
void __stdcall DlistInit(Dlist *list);
void * __stdcall PoolAlloc(uint len);
void __stdcall GenInitialPartIds(ushort count);
PartId NextInitialPartId(void);
ushort GetCriticalSlotCount(void);
undefined2 Puzzles::CheckEndgame(void);
short Puzzles::ComputeCandidateCategory(void);
void __cdecl Puzzles::ComputeCandidatePuzzles(short category);
void Puzzles::TurnAllOffCategoriesBackOn(void);
void * __stdcall Memcpy(void *dest,void *src,uint len);
void * __stdcall Memset(void *result,byte value,uint len);
char * __stdcall Strcpy(char *dest,char *src);
int __stdcall Sprintf1(char *dest,char *format,...);
int __stdcall Sprintf2(char *dest,char *format,...);
int __stdcall Sprintf3(char *dest,char *format,...);
int Random(void);
void __stdcall WinapiExitProcess(UINT exitCode);

