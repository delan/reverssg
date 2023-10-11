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




void entry(void);
void __GetExceptDLLinfo(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4);
void FUN_00410074(void);
void FUN_00410126(void);
void FUN_00410268(void);
void FUN_0041026e(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined2 param_5);
void FUN_0041029e(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004102d7(void);
void FUN_004102ee(void);
void FUN_0041030c(void);
void FUN_0041032e(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,char *param_5);
void FUN_00410408(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5,char *param_6);
void FUN_004104a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,undefined2 *param_5);
void FUN_004104c9(void);
void FUN_00410528(undefined param_1,undefined param_2,undefined param_3,int param_4);
uint FUN_004105b0(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4);
uint FUN_004107fe(undefined param_1,undefined param_2,undefined param_3,int param_4,short param_5,int *param_6);
HGLOBAL FUN_00410937(undefined param_1,undefined param_2,undefined param_3,int param_4,ushort param_5);
LPVOID FUN_00410a01(undefined param_1,undefined param_2,undefined param_3,HGLOBAL param_4);
BOOL FUN_00410a17(undefined param_1,undefined param_2,undefined param_3,HGLOBAL param_4);
undefined4 FUN_00410a30(undefined param_1,undefined param_2,undefined param_3,HGLOBAL param_4);
int FUN_00410a44(undefined param_1,undefined param_2,undefined param_3,int param_4,ushort param_5);
undefined4 FUN_00410aa2(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
DWORD FUN_00410aaa(undefined4 param_1,undefined4 param_2,DWORD param_3,int param_4,LPVOID param_5,DWORD param_6);
void FUN_00410b42(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5,ushort param_6);
void FUN_00410bb0(undefined param_1,undefined param_2,undefined param_3,short param_4);
ATOM FUN_00410bde(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00410cfc(void);
void FUN_00410d30(void);
undefined4 FUN_00410df3(undefined param_1,undefined param_2,undefined param_3,HMODULE param_4,int param_5,undefined param_6,undefined4 param_7);
void FUN_00410f13(undefined param_1,undefined param_2,undefined param_3,HWND param_4);
LRESULT MainWndProc(undefined param_1,undefined param_2,undefined param_3,HWND param_4,UINT param_5,uint param_6,uint param_7);
int FUN_004114b6(void);
uint FUN_00411519(void);
void FUN_00411599(void);
int FUN_004115b2(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0041161a(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004116a2(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4);
void FUN_004116e1(undefined param_1,undefined param_2,undefined param_3,short param_4,LPSTR param_5,short param_6);
int FUN_00411700(int param_1);
int FUN_0041170c(short param_1);
void FUN_0041172c(undefined param_1,undefined param_2,undefined param_3,undefined2 *param_4,undefined2 *param_5);
void FUN_0041179f(void);
void FUN_00411838(void);
void FUN_0041187c(void);
void FUN_004118bf(void);
void FUN_0041191f(undefined4 param_1,uint param_2,undefined4 param_3,int param_4);
void FUN_00411991(void);
void FUN_004119e4(void);
void FUN_00411ceb(void);
void FUN_00411ff5(undefined4 param_1,short param_2,uint param_3);
void FUN_00412016(undefined4 param_1,short param_2,int param_3);
void FUN_0041202e(void);
void FUN_00412086(void);
undefined4 FUN_00412156(undefined4 param_1,undefined4 param_2,undefined4 param_3,short param_4,short param_5);
void FUN_00412250(undefined param_1,undefined param_2,undefined param_3,HDC param_4,RECT *param_5);
void FUN_00412268(void);
void FUN_0041226d(void);
void FUN_00412272(void);
undefined4 FUN_00412278(void);
void FUN_0041227c(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
uint FUN_004122a8(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
uint FUN_004122bc(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
undefined4 FUN_004122d0(undefined param_1,undefined param_2,undefined param_3,short *param_4,short *param_5);
uint FUN_0041233c(undefined param_1,undefined param_2,undefined param_3,short *param_4,short *param_5);
int FUN_00412404(void);
void FUN_00412434(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4);
void FUN_00412468(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5,short param_6);
void FUN_00412490(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004125a8(void);
undefined4 FUN_00412784(void);
void FUN_004127bc(void);
void FUN_004128c8(void);
void FUN_00412998(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined2 param_5);
void __stdcall FUN_004129d4(int param_1,short param_2);
void __stdcall FUN_00412a28(int param_1);
void * __stdcall FUN_00412ac4(ushort param_1);
undefined4 FUN_00412d0c(uint param_1,undefined4 param_2,uint param_3,uint param_4);
undefined4 FUN_00412d84(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void __stdcall FUN_00412dc8(int param_1);
void FUN_00412e18(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00412e70(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00412ec0(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
void FUN_00412f04(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4);
uint FUN_00412f98(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,ushort param_5);
void FUN_00412fe4(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00413004(void);
ushort __stdcall FUN_00413774(int param_1,short param_2);
ushort __stdcall FUN_00413794(int param_1,short param_2);
short FUN_004137b4(undefined param_1,undefined param_2,undefined param_3,int param_4);
short FUN_004137e8(undefined param_1,undefined param_2,undefined param_3,int param_4);
uint FUN_0041381c(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00413828(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00413838(void);
void FUN_00413868(void);
void FUN_004138f0(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
void FUN_00413904(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0041391c(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0041393c(undefined param_1,undefined param_2,undefined param_3,int param_4);
void __stdcall FUN_0041395c(int param_1,undefined4 param_2,undefined4 param_3,short param_4);
void FUN_00413a24(void);
void FUN_00413a2c(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_00413a54(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5,undefined4 param_6);
void FUN_00413a88(undefined param_1,undefined param_2,undefined param_3,short *param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);
void FUN_00413acc(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7);
void FUN_00413af4(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined2 param_5);
void FUN_00413b08(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5,undefined2 param_6);
void FUN_00413b24(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,undefined2 param_6);
uint FUN_00413b88(undefined param_1,undefined param_2,undefined param_3,uint param_4,undefined4 param_5,undefined4 param_6,short param_7,byte param_8);
void FUN_00413cf4(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7);
void FUN_00413d18(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5,short param_6,undefined2 param_7);
void FUN_00413d54(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,short *param_5,short *param_6,short param_7);
void FUN_00413e20(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00413e74(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
uint FUN_00413e84(undefined param_1,undefined param_2,undefined param_3,int param_4);
int FUN_00413ebc(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined2 FUN_00413ed0(undefined param_1,undefined param_2,undefined param_3,int param_4);
uint FUN_00413ee8(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4,short param_5);
void FUN_00413f88(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
undefined4 FUN_00413fdc(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
void FUN_00414088(void);
void FUN_0041408d(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
undefined4 FUN_004140e4(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_0041412e(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004143a5(void);
void FUN_00414406(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_004145e2(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_0041469e(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
uint FUN_00414700(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0041472a(void);
void FUN_0041472f(void);
void FUN_00414734(void);
void FUN_00414739(void);
void FUN_00414aa7(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int param_5);
Room * FUN_00414c47(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00414c5a(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00414ccd(undefined param_1,undefined param_2,byte param_3,undefined *param_4,short *param_5);
int FUN_00414eb6(undefined param_1,undefined param_2,undefined param_3,short param_4,undefined4 param_5);
int FUN_00414edc(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
void FUN_00414efe(undefined param_1,undefined param_2,undefined param_3,short param_4,undefined2 param_5);
void FUN_00414f21(void);
void FUN_00414f80(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_00414fcf(undefined param_1,undefined param_2,undefined param_3,ushort *param_4);
void FUN_004150d3(undefined param_1,undefined param_2,undefined param_3,int param_4,short *param_5);
void FUN_004156ec(void);
void FUN_00415774(void);
void FUN_00415970(undefined param_1,undefined param_2,undefined param_3,short param_4,undefined2 param_5,uint param_6,short param_7,short param_8);
void FUN_004159da(void);
void FUN_00415a24(void);
void FUN_00415aa2(void);
void FUN_00415af1(void);
void FUN_00415b4f(undefined param_1,undefined param_2,undefined param_3,undefined2 *param_4);
void FUN_00415b77(undefined param_1,undefined param_2,undefined param_3,uint param_4);
void FUN_00415be4(void);
void FUN_00415bf3(undefined param_1,undefined param_2,undefined param_3,int param_4);
int FUN_00415d01(undefined param_1,undefined param_2,undefined param_3,int param_4);
void __stdcall FUN_00415d3e(void);
void FUN_00415e4f(void);
void FUN_00415ea2(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00415ed6(void);
void FUN_00415f35(byte param_1,undefined param_2,byte param_3,PartDefinition *param_4,short param_5);
void FUN_004160e5(void);
void FUN_00416115(void);
void FUN_00416236(undefined param_1,undefined param_2,undefined param_3,ushort param_4,short param_5);
void FUN_004162c9(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void __stdcall FUN_004162de(undefined4 param_1);
void FUN_00416378(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_00416396(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00416485(void);
void FUN_004164bb(void);
void FUN_004164da(void);
void FUN_004165c3(undefined param_1,undefined param_2,undefined param_3,ushort param_4);
void FUN_004167de(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00416815(void);
void FUN_00416835(void);
void FUN_0041683a(void);
void FUN_0041683f(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,ushort *param_6);
void FUN_00416874(uint param_1,undefined4 param_2,uint param_3,int param_4);
void FUN_0041688a(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004168bd(void);
void FUN_004168c2(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00416932(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0041695b(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004169b7(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004169ec(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5,int param_6);
void FUN_00416b73(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5);
void FUN_00416b90(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5);
void FUN_00416bad(void);
void FUN_00416c01(void);
uint FUN_00416c3e(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
int FUN_00416c51(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,short param_6,short param_7,short param_8,uint param_9);
void FUN_00416d19(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4);
void FUN_00416d57(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4);
void FUN_00416d95(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4);
void FUN_00416dd3(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4);
void FUN_00416e11(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4);
void FUN_00416e35(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00416e51(undefined param_1,undefined param_2,undefined param_3,int param_4);
int FUN_00416e6d(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,undefined4 param_9);
int FUN_00416ea3(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,undefined4 param_9);
int FUN_00416ed9(undefined param_1,undefined param_2,undefined param_3,undefined2 *param_4,undefined2 param_5,undefined4 param_6);
int FUN_00416f13(undefined param_1,undefined param_2,undefined param_3,undefined2 *param_4,undefined2 param_5,undefined4 param_6);
void FUN_00416f4d(void);
void FUN_00416f98(void);
void FUN_00416ffd(void);
void FUN_0041704f(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0041706f(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00417096(void);
void FUN_00417112(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined2 param_5);
void FUN_0041716d(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined2 param_5,undefined2 param_6);
void FUN_004171a7(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4,undefined2 param_5);
void FUN_004171dc(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5,undefined4 param_6,short param_7,short param_8);
void FUN_00417206(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined2 param_5);
void FUN_00417216(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5);
void FUN_00417224(undefined param_1,undefined param_2,undefined param_3,int param_4,uint param_5);
void FUN_00417255(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004172bf(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004172cc(undefined param_1,undefined param_2,undefined param_3,int param_4,short param_5);
void FUN_00417328(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,short param_6);
undefined4 FUN_00417375(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5,undefined2 param_6,undefined4 param_7);
void FUN_004173aa(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004174d3(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
undefined4 FUN_00417532(undefined param_1,byte param_2,byte param_3,short param_4);
void FUN_00417792(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004178b8(undefined4 param_1,undefined4 param_2,uint param_3,short param_4);
void __stdcall DoSomethingWithEseqResources?(void);
void FUN_00417a84(void);
void FUN_00417abd(void);
void FUN_00417c57(void);
void FUN_00417c69(void);
void FUN_00417e20(void);
void FUN_00417eba(uint param_1,undefined4 param_2,uint param_3);
void FUN_004180c2(void);
void FUN_0041879f(uint param_1,undefined4 param_2,uint param_3,ushort param_4);
void FUN_00418c0d(undefined4 param_1,undefined4 param_2,undefined4 param_3,short *param_4);
uint FUN_00418ea1(undefined param_1,undefined param_2,undefined param_3,short param_4,Rect16 *param_5,short param_6);
ushort FUN_0041907c(undefined param_1,undefined param_2,undefined param_3,short param_4,Rect16 *param_5);
void FUN_00419223(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_004195bd(void);
void FUN_004196ef(void);
void FUN_00419723(void);
void FUN_00419873(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004198f8(void);
void FUN_00419a55(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_00419ac0(void);
undefined2 FUN_00419aca(undefined param_1,undefined param_2,undefined param_3,ushort *param_4);
void FUN_00419d3d(void);
void FUN_00419d84(void);
undefined4 FUN_00419e02(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0041a068(undefined param_1,undefined param_2,undefined param_3,ushort param_4);
void FUN_0041a08d(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_0041a0d0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0041a0dd(void);
void FUN_0041a0e2(void);
void FUN_0041a0e7(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0041a0fc(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5);
void FUN_0041a11d(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5);
void FUN_0041a32f(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0041a42a(undefined param_1,undefined param_2,undefined param_3,short param_4);
uint FUN_0041a491(void);
undefined2 FUN_0041a62a(void);
void FUN_0041a633(void);
void FUN_0041a70e(void);
void __stdcall FUN_0041a823(void);
void FUN_0041a8fe(void);
void FUN_0041a92e(void);
void FUN_0041a954(void);
void FUN_0041aab9(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,short param_5);
void FUN_0041abd6(void);
void FUN_0041ac6b(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5,char *param_6,undefined param_7);
void FUN_0041acce(undefined param_1,undefined param_2,undefined param_3,char *param_4,undefined param_5);
void FUN_0041ad20(void);
void FUN_0041af2d(void);
void FUN_0041b115(void);
void FUN_0041b33a(void);
uint FUN_0041b393(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0041b86a(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,int param_5,int param_6,short param_7);
void FUN_0041ba44(undefined param_1,byte param_2,byte param_3,uint param_4,undefined4 param_5,uint param_6,undefined2 param_7);
void FUN_0041bac3(undefined param_1,undefined param_2,byte param_3,undefined2 param_4,int param_5,undefined4 param_6,undefined2 param_7);
void FUN_0041bb49(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_0041bc51(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5);
void FUN_0041be66(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0041f635(void);
void FUN_0041f6da(void);
void FUN_0041f782(undefined4 param_1,undefined4 param_2,uint param_3);
undefined4 FUN_0041f800(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,int param_5,undefined4 param_6);
undefined4 FUN_0041f830(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,int param_5,undefined4 param_6,short param_7,int param_8);
undefined4 FUN_0041f88c(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5);
void FUN_0041f8e2(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5,undefined2 param_6);
uint FUN_0041f93f(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0041fdcc(void);
undefined4 FUN_0041fe0c(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_004202ac(undefined4 param_1,undefined4 param_2,uint param_3,short param_4,short param_5);
void FUN_0042035e(void);
undefined4 FUN_004204e1(undefined param_1,undefined param_2,undefined param_3,ushort param_4,ushort param_5,undefined4 param_6,int param_7,int param_8,ushort param_9);
void FUN_004205ca(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_004206fb(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_004207ae(void);
undefined4 FUN_004207dd(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined2 param_5,undefined2 param_6);
void FUN_004208c9(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00420a36(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_00420ab7(void);
void FUN_00420c31(undefined param_1,undefined param_2,byte param_3,undefined4 param_4);
undefined4 FUN_00420e7b(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,short param_6,short param_7,undefined4 param_8,short param_9,short param_10,short param_11);
void FUN_00420feb(undefined4 param_1,undefined4 param_2,undefined4 param_3);
undefined4 FUN_0042114d(void);
undefined4 FUN_004212b7(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,short param_8,short param_9);
void FUN_004212fe(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004213fd(undefined4 param_1,uint param_2,uint param_3,undefined2 param_4,ushort param_5);
void FUN_00421490(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5);
undefined4 FUN_0042194c(void);
short FUN_0042197d(void);
void FUN_00421aef(void);
void FUN_00421bc5(void);
void FUN_00421d9b(void);
void FUN_00421dfc(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_00421f12(void);
void FUN_00421f1f(void);
void FUN_00422920(void);
void FUN_00422b11(uint param_1,undefined4 param_2,uint param_3);
int FUN_00422ee1(void);
void FUN_00422fb7(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004234ab(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,undefined param_10,undefined2 param_11,undefined2 param_12,undefined2 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
void FUN_004234df(void);
void FUN_004235dc(undefined param_1,undefined param_2,undefined param_3,short param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,undefined param_10,undefined2 param_11,undefined2 param_12,undefined2 param_13);
void FUN_0042365b(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00425794(undefined param_1,undefined param_2,byte param_3,int param_4,uint param_5,int param_6,uint param_7,undefined2 param_8);
undefined4 FUN_004258b0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
int FUN_004258dd(void);
void FUN_0042591e(void);
void FUN_00425a0d(void);
undefined4 FUN_00425ab0(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5,int param_6,undefined4 param_7,short param_8,short param_9);
void FUN_00425b7d(void);
undefined4 FUN_00425bf4(void);
void FUN_00425c3a(void);
void FUN_00425cda(void);
void FUN_00425f5a(void);
void FUN_004261cb(undefined param_1,undefined param_2,undefined param_3,short param_4,undefined4 param_5,short param_6,short param_7,undefined param_8,short param_9);
void FUN_00426317(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
void FUN_0042633e(void);
void FUN_00426714(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_00426795(void);
void FUN_004267a2(void);
void FUN_004267ab(void);
void FUN_004267cc(void);
void FUN_004267f8(void);
void FUN_0042681e(void);
void FUN_00426842(void);
void FUN_00426848(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
uint FUN_004268a9(void);
void FUN_00426918(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_00426973(uint param_1,undefined4 param_2,DWORD param_3,LPCVOID *param_4);
int FUN_00426981(undefined4 param_1,undefined *param_2,byte **param_3,byte **param_4,undefined4 param_5,uint param_6);
int FUN_004269a4(undefined4 param_1,undefined4 param_2,byte **param_3,byte **param_4,undefined4 param_5,uint param_6);
void FUN_004270f8(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00427184(void);
void FUN_004272d1(uint param_1,undefined4 param_2,uint param_3);
void FUN_00427563(uint param_1,undefined4 param_2,uint param_3);
void FUN_00427645(void);
void FUN_00427794(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void FUN_00427832(void);
void FUN_00429980(void);
void FUN_00429cab(undefined4 param_1,undefined4 param_2,uint param_3,int param_4);
void FUN_0042ac69(void);
undefined4 FUN_0042ace2(void);
void FUN_0042ad7d(void);
void FUN_0042ae0e(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0042ae69(void);
void FUN_0042ae76(void);
uint FUN_0042ae95(void);
void FUN_0042aec8(void);
undefined * FUN_0042af71(void);
short FUN_0042b00b(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5);
void FUN_0042b10a(undefined4 param_1,undefined *param_2,byte **param_3,undefined4 param_4,ushort param_5,short param_6);
void FUN_0042b15b(void);
bool FUN_0042b199(undefined4 param_1,undefined4 param_2,byte **param_3,undefined4 param_4,ushort param_5);
void FUN_0042b1cb(uint param_1,undefined4 param_2,DWORD param_3);
void FUN_0042b1d8(undefined param_1,undefined param_2,undefined param_3,ushort param_4);
bool FUN_0042b260(void);
undefined4 *FUN_0042b476(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,ushort param_5,short param_6);
void FUN_0042b4e4(undefined param_1,undefined param_2,undefined param_3,uint param_4);
void FUN_0042b8fc(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
void FUN_0042b98f(void);
int FUN_0042bd1e(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0042bf6e(void);
void FUN_0042c18b(undefined param_1,undefined param_2,byte param_3,undefined4 param_4);
void FUN_0042c389(void);
void FUN_0042c4f1(uint param_1,undefined4 param_2,uint param_3,short param_4);
void FUN_0042c730(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0042c7de(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_0042c89d(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0042d141(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0042d1fc(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0042d2bf(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
undefined4 FUN_0042d67c(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
undefined4 FUN_0042d875(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
undefined4 FUN_0042dad0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
undefined4 FUN_0042dce3(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
undefined4 FUN_0042def6(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
undefined4 FUN_0042e151(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
undefined4 FUN_0042e331(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
undefined4 FUN_0042e55b(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
undefined4 FUN_0042e73b(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_0042e965(uint param_1,undefined4 param_2,uint param_3,short param_4);
void FUN_0042e9c4(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
void FUN_0042eb10(void);
void FUN_0042eb45(undefined param_1,byte param_2,byte param_3,uint param_4,undefined4 param_5,uint param_6,undefined2 param_7);
void FUN_0042ebc4(void);
void FUN_0042ec27(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_0042ed2a(uint param_1,undefined4 param_2,uint param_3);
undefined4 FUN_0042edde(void);
void FUN_0042ee23(void);
void FUN_0042eee4(void);
void FUN_0042ef3a(void);
void FUN_0042f1a8(uint param_1,undefined4 param_2,uint param_3);
void FUN_0042f1c8(void);
void FUN_0042f2ed(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0042f348(void);
void FUN_0042f355(void);
undefined4 FUN_0042f440(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,short param_5);
void __stdcall FUN_0042f4ab(void);
void FUN_0042f4e7(void);
void FUN_0042fbf7(void);
void FUN_0042fc9c(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
void FUN_0042fcbd(undefined param_1,undefined param_2,undefined param_3,short param_4);
bool FUN_0042fcd7(undefined param_1,undefined param_2,undefined param_3,ushort param_4,ushort param_5);
undefined4 FUN_0042fe06(void);
void FUN_0042fe4c(void);
undefined4 FUN_0042ff2e(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0042ff68(undefined param_1,undefined param_2,undefined param_3,short param_4);
undefined4 FUN_0042ffd7(void);
undefined4 FUN_0043013c(undefined4 param_1);
void FUN_004301fc(void);
void FUN_0043025c(void);
void FUN_004302cc(undefined param_1,undefined param_2,undefined param_3,short param_4,undefined4 param_5,short param_6);
void FUN_00430434(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_00430494(undefined param_1,undefined param_2,undefined param_3,HDC param_4,RECT *param_5);
undefined4 FUN_004305fc(undefined4 param_1,undefined4 param_2,undefined4 param_3,short param_4,short param_5,short param_6);
void FUN_0043078c(void);
void FUN_00430810(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5,byte param_6);
void FUN_00430908(void);
undefined4 FUN_00430928(undefined param_1,undefined param_2,undefined param_3,void *param_4);
void FUN_0043095c(undefined param_1,undefined param_2,undefined param_3,short *param_4);
void FUN_00430a20(undefined param_1,undefined param_2,undefined param_3,short *param_4);
void __stdcall FUN_00430abc(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4);
void FUN_00430af0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined2 param_6,undefined2 param_7,byte param_8);
undefined4 FUN_00430bbc(void);
void FUN_00430db4(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7);
void __stdcall FUN_00430de8(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4);
void FUN_00430e28(void);
void FUN_00430ef8(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5,undefined2 *param_6);
void FUN_00431024(uint param_1,undefined4 param_2,uint param_3,ushort param_4);
void FUN_00431084(uint param_1,undefined4 param_2,uint param_3,ushort param_4);
void FUN_004310d0(uint param_1,undefined4 param_2,uint param_3,short param_4);
void FUN_004310f8(void);
int FUN_004312c4(void);
void FUN_00431348(void);
void FUN_0043139c(void);
undefined1 * FUN_004313c4(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_004313d8(void);
void FUN_00431420(void);
void FUN_004314f0(undefined param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,short *param_6);
void FUN_00431588(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined2 param_6);
void FUN_004315b4(undefined param_1,undefined param_2,undefined param_3,short param_4,undefined4 param_5,int param_6);
void FUN_004317e8(undefined param_1,undefined param_2,undefined param_3,short param_4,undefined4 param_5,int param_6);
int FUN_00431a1c(int param_1,undefined4 param_2,undefined4 param_3,short param_4,short param_5);
void FUN_00431ab0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
void FUN_00431ae8(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
void FUN_00431b20(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined2 param_7,undefined4 param_8);
void FUN_00431b60(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,short param_6,short param_7,undefined4 param_8);
void FUN_00431bc4(void);
short FUN_00431bcc(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5,int param_6);
undefined4 FUN_00431cb8(undefined param_1,undefined param_2,undefined param_3,short *param_4,short *param_5);
void FUN_00431d24(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
ushort __stdcall ClampColorIndex?(short color);
void FUN_00431dc9(undefined param_1,undefined param_2,undefined param_3,undefined2 *param_4,undefined2 *param_5);
int FUN_00431dde(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
void FUN_00431df5(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00431e11(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5);
void FUN_00431ef2(void);
void FUN_00431f6c(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00432128(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004321b3(void);
void FUN_004323c3(void);
void FUN_004324b1(void);
void FUN_004326e8(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
void FUN_00432947(uint param_1,undefined4 param_2,uint param_3);
void FUN_0043299b(void);
void FUN_00432aea(void);
void FUN_00432c8f(void);
int FUN_00432d2e(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00432e65(void);
void FUN_00432f2f(void);
void FUN_00432fac(undefined4 param_1,undefined4 param_2,uint param_3,short param_4);
void FUN_00433840(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5);
void FUN_00433a0e(void);
undefined4 FUN_00433cca(void);
void FUN_00433dc0(undefined4 param_1,short param_2,undefined4 param_3,short param_4);
void FUN_00433e79(void);
void FUN_00433fe0(void);
void FUN_00433ff3(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0043404e(void);
void FUN_0043405b(void);
void FUN_004340b1(void);
void FUN_004340fd(void);
uint FUN_0043414c(void);
uint FUN_004341b9(void);
int FUN_00434250(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0043426d(undefined param_1,undefined param_2,undefined param_3,short param_4,undefined4 param_5);
short * __stdcall GetEseqResource?(ushort param_1,int param_2,short **param_3,short **param_4);
void FUN_0043435b(void);
uint FUN_00434369(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_00434aa1(void);
void FUN_00434be3(uint param_1);
void FUN_00434d2a(uint param_1,undefined4 param_2,uint param_3);
bool __stdcall FUN_00434ddd(short param_1);
int FUN_00434e8a(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5,short param_6);
uint FUN_00434fa3(uint param_1);
void FUN_00435017(undefined param_1,undefined param_2,undefined param_3,int param_4);
void __stdcall FUN_00435050(int param_1);
void FUN_004350be(void);
undefined4 FUN_004350fa(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_00435117(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 *FUN_00435122(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4,undefined4 param_5);
void FUN_00435151(undefined param_1,undefined param_2,undefined param_3,Dlist *param_4,DlistNode *param_5,code *param_6);
int ** FUN_0043527b(undefined param_1,undefined param_2,undefined param_3,int **param_4,undefined4 param_5);
int FUN_004352c9(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00435302(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00435346(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
undefined2 FUN_00435355(void);
void FUN_0043551e(uint param_1,undefined4 param_2,uint param_3);
void FUN_0043588a(void);
void FUN_004359e9(void);
int FUN_00435c2d(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4);
void FUN_00435d07(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_00435d8a(void);
void FUN_00435e98(undefined4 param_1,undefined4 param_2,uint param_3,short param_4);
void FUN_00438db6(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00438e43(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_00438efb(short param_1,undefined4 param_2,undefined4 param_3);
void FUN_00438f7b(void);
void FUN_004392dc(void);
undefined4 FUN_00439341(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,short param_6,short param_7,undefined4 param_8,short param_9,short param_10,short param_11);
void FUN_004394b1(void);
void FUN_004394c8(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004395e2(void);
void FUN_00439740(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
uint FUN_00439862(undefined param_1,undefined param_2,byte param_3,short param_4);
undefined4 FUN_00439ae0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
undefined4 FUN_00439c09(undefined param_1,undefined param_2,undefined param_3,short param_4);
undefined4 FUN_00439e1a(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5);
undefined4 FUN_0043a0f3(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
void FUN_0043a2d6(undefined param_1,undefined param_2,undefined param_3,ushort param_4,short param_5,short param_6,short param_7,short param_8);
int FUN_0043a521(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
uint FUN_0043a53a(undefined param_1,undefined param_2,undefined param_3,uint param_4);
undefined4 FUN_0043a592(void);
void FUN_0043a724(void);
void FUN_0043a834(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
undefined4 FUN_0043a8d1(void);
undefined4 FUN_0043a911(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0043a9b2(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_0043a9ca(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0043aa25(void);
void FUN_0043aa32(void);
short FUN_0043aa7d(void);
int FUN_0043aade(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short *param_5);
undefined4 *FUN_0043ab26(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,uint param_5);
void FUN_0043ab87(void);
void FUN_0043abad(void);
undefined4 FUN_0043abbe(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4,undefined2 param_5,undefined4 param_6);
undefined4 __stdcall FUN_0043ac64(undefined2 param_1,undefined4 param_2);
undefined4 FUN_0043acb4(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined4 param_5);
undefined4 FUN_0043ad04(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined4 param_5,short param_6);
short FUN_0043ad75(undefined param_1,undefined param_2,undefined param_3,ushort param_4);
undefined4 FUN_0043aed8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4);
undefined4 FUN_0043afa5(void);
undefined4 FUN_0043afac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5);
short FUN_0043b012(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,short param_5,LPCSTR param_6,DlistNode *param_7);
undefined4 FUN_0043b0b8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4);
undefined4 FUN_0043b115(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4);
void FUN_0043b1cc(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0043b21c(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5,undefined4 param_6);
void FUN_0043b24e(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined4 *param_5);
void FUN_0043b291(void);
int FUN_0043b2c2(byte param_1,undefined param_2,byte param_3,ushort param_4,undefined2 param_5);
void FUN_0043b318(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,short param_6,short param_7);
void FUN_0043b3e0(void);
void FUN_0043b427(void);
void FUN_0043b443(void);
uint FUN_0043b47e(void);
uint FUN_0043b4a4(void);
void FUN_0043b4ca(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0043b4e2(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4);
void FUN_0043b563(void);
int FUN_0043b58e(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined2 param_5,undefined2 param_6);
void FUN_0043b656(void);
undefined4 FUN_0043b69e(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0043b6bf(void);
void FUN_0043b6ec(void);
void FUN_0043b972(void);
void FUN_0043b9d2(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined2 param_5);
void FUN_0043b9f5(void);
void FUN_0043ba1d(void);
void FUN_0043ba43(undefined param_1,undefined param_2,undefined param_3,undefined2 *param_4,undefined2 *param_5);
void FUN_0043ba8c(undefined param_1,undefined param_2,undefined param_3,ushort param_4,ushort param_5,ushort param_6,ushort *param_7);
void FUN_0043bb3e(void);
void FUN_0043bb89(void);
void FUN_0043bc68(void);
void FUN_0043be66(undefined param_1,undefined param_2,byte param_3,byte param_4,undefined4 param_5,undefined4 param_6);
void __stdcall FUN_0043bfee(byte param_1,undefined4 param_2,undefined4 param_3);
uint FUN_0043c1a2(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
void FUN_0043c1c0(undefined param_1,undefined param_2,undefined param_3,uint param_4);
void FUN_0043c249(void);
void __cdecl FUN_0043c2ba(DlistNode *param_1);
void FUN_0043c323(void);
void FUN_0043c324(void);
void FUN_0043c325(void);
void FUN_0043c32a(void);
undefined4 FUN_0043c338(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
void FUN_0043c35e(void);
void FUN_0043c382(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,ushort param_5,undefined4 param_6);
void FUN_0043c412(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_0043c435(void);
void FUN_0043c49f(void);
void FUN_0043c4ec(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0043c5ee(void);
void FUN_0043c729(uint param_1,undefined4 param_2,undefined *param_3);
void FUN_0043c91a(uint param_1,undefined4 param_2,uint param_3);
void FUN_0043cd08(undefined4 param_1,undefined4 param_2,undefined4 param_3,short *param_4);
void FUN_0043d275(void);
ushort __stdcall LoadPartDefinitions?(void);
void FUN_0043d7c3(undefined4 param_1,undefined4 param_2,uint param_3);
uint FUN_0043d820(undefined param_1,undefined param_2,undefined param_3,short param_4);
uint FUN_0043d837(undefined param_1,undefined param_2,undefined param_3,short param_4);
uint FUN_0043d84e(undefined param_1,undefined param_2,undefined param_3,short param_4);
uint FUN_0043d865(undefined param_1,undefined param_2,undefined param_3,short param_4);
uint FUN_0043d87c(undefined param_1,undefined param_2,undefined param_3,short param_4);
int FUN_0043d893(undefined param_1,undefined param_2,undefined param_3,short param_4);
int FUN_0043d90c(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined2 *param_6);
uint FUN_0043d94c(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
int FUN_0043d978(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0043d9c0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0043d9e3(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0043da06(undefined param_1,undefined param_2,undefined param_3,undefined2 *param_4);
void __stdcall ezFUN_0043da4e(ushort *param_1);
void FUN_0043daa4(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_0043dae8(undefined param_1,undefined param_2,undefined param_3,int param_4,short *param_5);
void FUN_0043de85(undefined param_1,byte param_2,byte param_3,int param_4,undefined4 param_5);
void FUN_0043df27(undefined param_1,undefined param_2,undefined param_3,int param_4);
uint FUN_0043df75(uint param_1,undefined4 param_2,uint param_3,int param_4);
void FUN_0043e088(void);
void FUN_0043e096(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_0043e530(void);
uint FUN_0043e65c(void);
void FUN_0043ec54(void);
undefined4 FUN_0043ecaa(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0043f193(void);
void FUN_0043f27a(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0043f2c8(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,short param_6,short param_7,byte param_8);
void FUN_0043f579(undefined param_1,undefined param_2,undefined param_3,byte *param_4,short *param_5,short param_6);
void FUN_0043f7e9(void);
void FUN_0043f8b4(void);
void __cdecl FUN_0043f987(int param_1);
void FUN_0043fae6(void);
void FUN_0043fb50(void);
void FUN_0043fb8b(void);
void FUN_0043fd88(void);
void FUN_0043fdaa(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void __stdcall FUN_0043fef9(short param_1);
void FUN_0043ff91(undefined param_1,undefined param_2,byte param_3,int param_4);
void FUN_0043ffba(undefined param_1,undefined param_2,undefined param_3,int param_4);
void __cdecl Puzzles::ThrowChosenCategoriesExhausted(void);
void FUN_0044001b(void);
void FUN_004400eb(uint param_1,undefined4 param_2,uint param_3);
void FUN_00440113(uint param_1,undefined4 param_2,uint param_3);
undefined4 FUN_004401a3(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
undefined4 FUN_00440221(void);
bool FUN_00440260(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_00440318(void);
void FUN_00440342(void);
undefined4 FUN_004403be(undefined param_1,undefined param_2,undefined param_3,char *param_4);
void FUN_0044040c(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
uint FUN_00440472(undefined4 param_1,undefined4 param_2,uint param_3,undefined *param_4);
DlistNode *FUN_004404a8(undefined4 param_1,undefined4 param_2,uint param_3,short param_4,LPCSTR param_5);
void * __stdcall GetWinapiResource?(ushort id?,LPCSTR type?);
void FUN_00440615(uint param_1,undefined4 param_2,uint param_3,ushort param_4,LPCSTR param_5);
void FUN_0044062c(undefined param_1,undefined param_2,undefined param_3,int param_4);
void __cdecl FUN_00440695(short param_1,undefined *param_2);
void FUN_0044073c(undefined param_1,undefined param_2,undefined param_3,DlistNode *param_4);
undefined4 FUN_004407d3(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_0044080d(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,LPCSTR param_5);
void FUN_0044086e(void);
undefined4 FUN_004408cd(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_0044094e(undefined4 param_1,undefined4 param_2,uint param_3,short param_4,undefined *param_5);
void FUN_00440994(void);
void FUN_00440e11(uint param_1,undefined4 param_2,uint param_3);
void FUN_004413d3(void);
void FUN_00441442(void);
int FUN_00441514(undefined4 param_1,int param_2);
void FUN_00441531(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00441736(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0044182e(void);
void FUN_00441942(void);
void FUN_00441a34(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5,undefined4 param_6);
void FUN_00441ab9(void);
short FUN_00441b27(void);
short FUN_00441b8a(void);
void FUN_00441bea(void);
undefined4 FUN_00441c86(void);
void FUN_00441d26(uint param_1,undefined4 param_2,uint param_3);
void FUN_0044380a(void);
void FUN_00443878(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_004438d3(void);
void FUN_004438e0(void);
void FUN_004438e9(undefined4 param_1,undefined4 param_2,uint param_3,short param_4);
void FUN_004439cf(void);
void FUN_004439dc(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,undefined2 param_5);
void FUN_004439fb(undefined param_1,byte param_2,byte param_3,undefined2 *param_4);
void FUN_00443ae0(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5);
void FUN_00443b15(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
void FUN_00443b4a(undefined param_1,undefined param_2,undefined param_3,short *param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,undefined param_10,byte param_11);
void FUN_00443d53(undefined4 param_1,int param_2,uint param_3);
void FUN_00443d76(undefined4 param_1,int param_2,uint param_3);
bool FUN_00443d9c(void);
void FUN_00443db0(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
undefined4 FUN_00443e08(void);
void FUN_00443e85(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00443ed8(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00443f0b(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4);
void FUN_00443f85(void);
void FUN_00443f86(void);
undefined4 FUN_00443f87(void);
void FUN_004440c3(void);
void FUN_004440e8(uint param_1,undefined4 param_2,uint param_3);
void FUN_0044413c(uint param_1,undefined4 param_2,uint param_3);
bool FUN_00444142(undefined4 param_1,byte param_2,undefined4 param_3,short param_4);
void FUN_004444bf(void);
void FUN_004444c5(void);
void FUN_00444558(undefined param_1,byte param_2,byte param_3,short param_4,short param_5,short param_6);
undefined4 FUN_00444911(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4);
void FUN_0044510a(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_00445202(undefined4 param_1,undefined4 param_2,uint param_3);
void FUN_0044525f(void);
undefined4 FUN_004456d2(void);
undefined4 FUN_0044571b(void);
void FUN_004457b0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004458d8(undefined param_1,undefined param_2,undefined param_3,MMRESULT param_4);
undefined2 FUN_00445924(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
LRESULT SoundWndProc(undefined param_1,undefined param_2,undefined param_3,HWND param_4,UINT param_5,uint param_6,LPARAM param_7);
short FUN_00445a67(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_00445b16(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00445b61(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_00445b97(void);
bool FUN_00445bd7(void);
void FUN_00445cbc(void);
undefined4 FUN_00445cd8(void);
uint FUN_00445d1d(uint param_1);
void FUN_00445eea(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void FUN_0044600b(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_00446172(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void __stdcall FUN_00446186(ushort param_1);
void FUN_004461ff(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00446225(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined2 param_5);
void FUN_004462d4(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_004462e8(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0044634d(void);
void FUN_00446367(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00446384(void);
void FUN_0044639c(undefined param_1,undefined param_2,undefined param_3,int param_4);
void __cdecl FUN_004465a5(undefined2 param_1,undefined2 param_2,ushort param_3);
void FUN_00446654(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004466f9(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined2 param_5);
void FUN_00446778(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00446803(void);
void FUN_00446808(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00446846(undefined param_1,undefined param_2,undefined param_3,void *param_4);
void FUN_004468a4(void);
void FUN_004468ed(void);
void FUN_00446967(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00446a73(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4);
void FUN_00446ac0(undefined param_1,undefined param_2,undefined param_3,int param_4,short param_5);
void FUN_00446b08(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00446b35(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00446b4c(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00446b96(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00446bc3(void);
void FUN_00446bfe(void);
void FUN_00446c0c(void);
void FUN_00446c72(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00446ca1(void);
void FUN_00446ccc(void);
void FUN_00446d11(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00446dac(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00446e32(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00446e68(void);
void FUN_00446e9d(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00446ed9(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_00446f2c(undefined param_1,undefined param_2,undefined param_3,short param_4);
undefined4 FUN_00446f5b(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00446fc9(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
undefined4 FUN_0044701f(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0044705a(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_004470b0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004470d1(undefined param_1,undefined param_2,undefined param_3,short param_4);
undefined2 FUN_0044713f(void);
undefined2 FUN_00447146(void);
undefined2 FUN_0044714d(void);
void FUN_00447154(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00447176(void);
uint FUN_0044727e(undefined param_1,undefined param_2,undefined param_3,short param_4);
int FUN_004474c6(uint param_1,undefined4 param_2,uint param_3,ushort param_4);
undefined4 FUN_0044751f(undefined param_1,undefined param_2,byte param_3,int param_4);
void FUN_0044755f(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00447578(undefined4 param_1,undefined4 param_2,int param_3);
void FUN_00447634(byte param_1,undefined param_2,byte param_3,short param_4);
void FUN_004476a9(void);
uint FUN_004476f4(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00447710(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_0044772b(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_00447746(void);
void FUN_00447763(undefined param_1,undefined param_2,undefined param_3,char *param_4);
void FUN_004477a9(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004477db(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00447806(void);
void FUN_0044780b(undefined param_1,undefined param_2,byte param_3,undefined4 param_4);
void FUN_00447828(undefined param_1,undefined param_2,byte param_3,undefined4 param_4);
void FUN_00447845(undefined param_1,undefined param_2,byte param_3,undefined4 param_4);
void FUN_00447868(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004478cf(void);
void FUN_00447988(void);
void FUN_00447bab(uint param_1,undefined4 param_2,uint param_3);
void FUN_00448097(void);
int FUN_00448280(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_004484a5(void);
undefined4 FUN_004485f4(void);
void FUN_0044868d(uint param_1,undefined4 param_2,uint param_3);
void FUN_00448742(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0044a970(void);
void FUN_0044a9f7(void);
void FUN_0044aa9c(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5);
void FUN_0044aca2(void);
int FUN_0044ad2f(undefined param_1,undefined param_2,undefined param_3,short param_4);
undefined4 FUN_0044ae24(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,short param_8,short param_9);
void FUN_0044ae6b(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0044b030(void);
void FUN_0044b048(undefined param_1,undefined param_2,undefined param_3,short param_4,short param_5);
void FUN_0044b0dc(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0044b1c8(void);
void FUN_0044b1d5(void);
void FUN_0044b24d(void);
void __stdcall FUN_0044b38d(undefined4 param_1);
void FUN_0044b3c6(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0044b3e5(void);
void __stdcall FUN_0044b434(undefined4 param_1,undefined4 param_2);
void FUN_0044b4ba(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_0044b60a(undefined param_1,undefined param_2,undefined param_3,ushort param_4);
undefined4 FUN_0044b62f(void);
void FUN_0044b858(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0044b9e3(void);
void FUN_0044bc7c(void);
void FUN_0044bd20(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,short param_6,short param_7,byte param_8);
int FUN_0044c09d(undefined param_1,undefined param_2,undefined param_3,char *param_4);
void FUN_0044c276(void);
void FUN_0044c2df(void);
void FUN_0044c32f(void);
undefined4 __cdecl FUN_0044c371(undefined2 *param_1);
void FUN_0044c8c2(uint param_1,undefined4 param_2,uint param_3,ushort param_4);
void __cdecl FUN_0044c8f3(undefined4 param_1,undefined2 param_2);
void FUN_0044c950(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0044c95d(void);
void FUN_0044c970(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0044c9e9(void);
int FUN_0044ca04(void);
void FUN_0044ca10(void);
undefined2 FUN_0044ca15(void);
int FUN_0044ca1c(undefined param_1,undefined param_2,undefined param_3,short param_4);
uint FUN_0044ca2e(undefined param_1,undefined param_2,undefined param_3,short param_4);
int FUN_0044ca44(undefined param_1,undefined param_2,undefined param_3,int param_4);
bool FUN_0044ca51(undefined param_1,undefined param_2,undefined param_3,uint param_4);
void FUN_0044ca64(undefined param_1,undefined param_2,undefined param_3,uint param_4);
void FUN_0044ca7e(void);
void FUN_0044ca89(void);
void FUN_0044ca9b(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0044cabc(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 __stdcall FindNodeIn46A938h?(undefined4 param_1);
void __stdcall FUN_0044cb20(undefined2 param_1);
uint FUN_0044cb57(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
uint FUN_0044cb74(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
uint __stdcall FUN_0044cb93(undefined2 param_1);
void __stdcall FUN_0044cbbb(undefined4 param_1);
int __stdcall FUN_0044cc56(int param_1);
int __stdcall FUN_0044cc6c(int param_1);
int FUN_0044cc99(undefined param_1,undefined param_2,undefined param_3,int param_4);
void __stdcall FUN_0044cca4(int param_1,int *param_2);
short FUN_0044ccf5(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,byte *param_5);
void FUN_0044ced4(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,short param_7,undefined2 param_8);
void __stdcall FUN_0044cf2c(undefined4 param_1,char *param_2,undefined4 param_3,short param_4,undefined2 param_5);
uint FUN_0044cfcb(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,uint param_5,undefined2 param_6,ushort param_7,undefined2 param_8);
undefined FUN_0044d0fb(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4,byte param_5);
void FUN_0044d120(void);
void FUN_0044d121(undefined param_1,undefined param_2,undefined param_3,int param_4,ushort param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,short param_9,short param_10,undefined4 param_11,undefined2 param_12);
undefined2 __stdcall FUN_0044d4eb(undefined2 param_1);
short __stdcall SetColor?(short param_1);
void FUN_0044d531(void);
void FUN_0044d55a(void);
int FUN_0044d5aa(undefined param_1,undefined param_2,undefined param_3,ushort param_4,short param_5,short param_6,short param_7,char *param_8);
uint FUN_0044d73f(undefined2 *param_1,byte param_2,byte param_3,undefined2 param_4,char *param_5,short *param_6,short *param_7);
void __stdcall DrawString(undefined2 x,short y,undefined4 string);
undefined2 FUN_0044d81a(void);
undefined2 FUN_0044d821(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_0044d837(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4);
void FUN_0044d850(undefined param_1,undefined param_2,undefined param_3,int param_4);
void __cdecl FUN_0044d87c(short param_1);
void FUN_0044d926(void);
void FUN_0044d92c(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0044da2d(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4);
int FUN_0044da67(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0044dad6(uint param_1,undefined4 param_2,uint param_3);
void FUN_0044db32(undefined param_1,undefined param_2,undefined param_3,int param_4,short param_5,short param_6);
void FUN_0044db81(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,short param_5);
void FUN_0044dc7c(void);
uint FUN_0044dcaa(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
void FUN_0044dcbd(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0044dd69(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0044de74(void);
void FUN_0044df5a(void);
void FUN_0044e0bb(undefined4 param_1,int param_2,uint param_3,int param_4);
DlistNode * FUN_0044e278(undefined param_1,undefined param_2,undefined param_3,short param_4);
void FUN_0044e33f(void);
void FUN_0044e3aa(void);
void FUN_0044e3e3(void);
undefined4 FUN_0044e473(void);
bool FUN_0044e56e(void);
void FUN_0044e66a(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0044e720(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0044e813(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_0044e838(uint param_1,undefined4 param_2,uint param_3,ushort param_4);
void FUN_0044eb32(void);
void FUN_0044eba7(void);
void FUN_0044ebef(void);
void FUN_0044ecc8(void);
void FUN_0044ed2d(void);
void FUN_0044ed39(void);
void FUN_0044ee27(void);
void FUN_0044ef41(void);
void FUN_0044efb6(void);
void FUN_0044fb70(undefined param_1,undefined param_2,undefined param_3,int *param_4,undefined4 param_5,undefined4 param_6);
void FUN_0044fb97(undefined param_1,undefined param_2,undefined param_3,int *param_4,undefined4 param_5,undefined4 param_6);
bool FUN_0044fbbe(undefined param_1,undefined param_2,undefined param_3,short *param_4,int *param_5);
void FUN_0044fbfd(undefined param_1,undefined param_2,undefined param_3,short *param_4);
uint FUN_0044fc4d(undefined param_1,undefined param_2,undefined param_3,uint param_4);
void FUN_0044fc8b(undefined param_1,undefined param_2,undefined param_3,short *param_4,undefined2 param_5);
uint FUN_0044fcbb(undefined4 param_1,uint param_2,undefined4 param_3,short *param_4);
uint FUN_0044fccc(undefined4 param_1,uint param_2,undefined4 param_3,int param_4);
uint FUN_0044fcec(undefined param_1,undefined param_2,undefined param_3,undefined2 *param_4);
uint FUN_0044fcf7(undefined param_1,undefined param_2,undefined param_3,int *param_4);
uint FUN_0044fd09(undefined param_1,undefined param_2,undefined param_3,undefined2 *param_4);
short FUN_0044fd14(undefined param_1,undefined param_2,undefined param_3,byte *param_4);
void FUN_0044fd2c(undefined param_1,undefined param_2,undefined param_3,undefined *param_4,undefined4 param_5);
void __stdcall ezFUN_0044fd55(undefined *param_1,undefined4 param_2);
void FUN_0044fd7e(undefined param_1,undefined param_2,undefined param_3,undefined *param_4,undefined4 param_5);
void __stdcall ezFUN_0044fdb3(undefined *param_1,undefined4 param_2);
void FUN_0044fde8(undefined param_1,undefined param_2,undefined param_3,undefined *param_4);
void __stdcall ezFUN_0044fdfa(undefined *param_1);
void FUN_0044fe0c(undefined param_1,undefined param_2,undefined param_3,undefined *param_4);
char * FUN_0044fe2c(undefined param_1,undefined param_2,undefined param_3,char *param_4,char param_5,int param_6);
undefined4 *FUN_0044fe70(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4,undefined4 *param_5,uint param_6);
char * FUN_0044feec(undefined param_1,undefined param_2,undefined param_3,char *param_4,char *param_5);
char * FUN_0044ff28(undefined param_1,undefined param_2,undefined param_3,char *param_4,char param_5);
int FUN_0044ff50(undefined param_1,undefined param_2,undefined param_3,char *param_4,char *param_5);
int FUN_0044ffac(undefined param_1,undefined param_2,undefined param_3,char *param_4);
char * FUN_0044ffc8(undefined param_1,undefined param_2,undefined param_3,char *param_4,char *param_5,uint param_6);
int FUN_00450048(undefined param_1,undefined param_2,undefined param_3,byte *param_4,byte *param_5,int param_6);
void * FUN_0045008c(undefined param_1,undefined param_2,undefined param_3,void *param_4,void *param_5,uint param_6);
char * FUN_004500dc(undefined param_1,undefined param_2,undefined param_3,char *param_4,undefined4 param_5);
int FUN_00450108(undefined param_1,undefined param_2,undefined param_3,int param_4,char *param_5);
int FUN_004501ac(undefined param_1,undefined param_2,undefined param_3,void *param_4,void *param_5);
void FUN_004501d8(undefined *UNRECOVERED_JUMPTABLE);
char * FUN_004501df(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_004501f8(undefined param_1,undefined param_2,undefined param_3,int *param_4,int *param_5);
undefined4 FUN_0045025e(undefined param_1,undefined param_2,byte param_3,int param_4,undefined4 param_5,undefined4 param_6,int param_7);
undefined4 FUN_00450358(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,int param_6,undefined4 param_7);
int ** FUN_00450467(undefined param_1,undefined param_2,undefined param_3,uint param_4);
void FUN_004504b1(undefined param_1,undefined param_2,undefined param_3,int param_4);
bool FUN_004504de(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5,int param_6,byte param_7);
void FUN_0045059f(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,code *param_6,uint param_7);
void FUN_00450623(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,code *param_5,uint param_6,int param_7);
void FUN_00450670(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,code *param_5,uint param_6);
void FUN_004506aa(undefined param_1,undefined param_2,undefined param_3,int **param_4,void *param_5,int *param_6,int *param_7,int *param_8,int *param_9,int *param_10,int *param_11,undefined4 param_12,int param_13);
void FUN_004508b0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11);
void FUN_004508dd(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_0045092e(undefined param_1,undefined param_2,undefined param_3,PVOID param_4,PEXCEPTION_RECORD param_5);
void FUN_0045096d(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
void FUN_004509bb(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_00450a64(undefined param_1,undefined param_2,byte param_3,int *param_4,int param_5,undefined4 param_6,int **param_7);
int FUN_00450aea(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,undefined4 param_6);
void FUN_00450b46(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined param_5,int param_6,int *param_7,int param_8);
void FUN_00450cfa(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 param_5);
void FUN_00450e08(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_00450e1b(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4);
int * FUN_00450e38(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
undefined4 FUN_00450e8d(void);
void FUN_00451107(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,int param_5,undefined4 param_6);
void FUN_00451173(undefined param_1,undefined param_2,undefined param_3,int param_4,int *param_5,int *param_6,undefined4 param_7,int param_8,undefined4 param_9);
void FUN_004511b8(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,uint param_6,int param_7,undefined4 param_8);
void FUN_0045135e(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,uint param_6,undefined4 param_7);
int FUN_004513d0(undefined param_1,undefined param_2,undefined param_3,int param_4,int *param_5);
int FUN_0045140e(undefined param_1,undefined param_2,byte param_3,int **param_4,int param_5,int param_6,int param_7);
uint FUN_0045167f(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 * FUN_004516df(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4);
undefined4 FUN_00451715(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0045171d(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4,byte param_5);
void FUN_0045173c(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
bool FUN_00451755(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
bool FUN_00451772(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
void FUN_004517be(undefined param_1,undefined param_2,undefined param_3,int param_4);
int FUN_004517cf(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,undefined param_6,int param_7);
undefined4 *FUN_0045180d(undefined param_1,byte param_2,undefined param_3,int param_4,int param_5,undefined4 *param_6,undefined4 param_7,int param_8,int param_9,uint *param_10,int param_11,int param_12);
undefined4 *FUN_00451984(undefined param_1,undefined param_2,undefined param_3,int param_4,undefined4 *param_5,undefined4 param_6,int param_7,int param_8);
void FUN_00451ae0(int param_1,undefined param_2,undefined param_3,undefined1 param_4);
undefined4 FUN_00451b26(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00451b4b(void);
undefined4 FUN_00451b9f(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00451bc4(void);
undefined4 FUN_00451bd8(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5);
void FUN_00451bf7(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00451cb0(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4);
undefined4 FUN_00451cd8(void);
void FUN_00451d80(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4);
void FUN_00451d9c(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
undefined4 FUN_00451dac(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00451df8(void);
void FUN_00451e12(PVOID param_1,PEXCEPTION_RECORD param_2);
void FUN_00451e27(void);
void FUN_00451e30(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4);
void FUN_00451e45(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4);
int thunk_FUN_004532b8(undefined4 param_1,undefined4 param_2,LPCVOID *param_3);
undefined4 FUN_00451e80(undefined param_1,undefined param_2,undefined param_3,void **param_4,void *param_5,int param_6,void *param_7);
undefined4 FUN_00451f00(uint param_1,undefined4 param_2,DWORD param_3,LPCVOID *param_4);
undefined4 FUN_00451f94(undefined4 param_1,undefined4 param_2,DWORD param_3,LPCVOID *param_4);
int FUN_0045201c(undefined4 param_1,undefined4 param_2,DWORD param_3);
void FUN_0045207c(undefined param_1,undefined param_2,undefined param_3,undefined *param_4);
uint FUN_0045208c(undefined param_1,undefined param_2,undefined param_3,char *param_4,uint *param_5,undefined4 *param_6);
LPCVOID * FUN_0045214c(undefined param_1,undefined param_2,undefined param_3,LPCVOID *param_4,undefined4 param_5,undefined4 param_6,uint param_7);
undefined4 * FUN_004521f4(void);
LPCVOID * FUN_00452220(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
byte * FUN_0045226c(undefined4 param_1,uint param_2,byte **param_3,byte *param_4,byte *param_5,byte **param_6);
LPCVOID * FUN_0045237c(undefined4 param_1,undefined *param_2,byte **param_3,undefined *param_4,LPCVOID *param_5,byte **param_6);
uint FUN_004524ac(undefined4 param_1,undefined *param_2,byte **param_3,undefined4 param_4,uint param_5,int param_6,byte **param_7);
char * FUN_004524e0(undefined param_1,undefined param_2,undefined param_3,char **param_4);
undefined4 FUN_0045253c(undefined4 param_1,undefined4 param_2,DWORD param_3,LPCVOID *param_4,int param_5,int param_6);
char * FUN_004525a0(undefined param_1,undefined param_2,undefined param_3,int param_4);
uint FUN_00452624(undefined4 param_1,undefined4 param_2,byte **param_3,undefined4 param_4,uint param_5,uint param_6,byte **param_7);
void FUN_00452654(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_0045266c(undefined4 param_1,undefined4 param_2,LPCVOID *param_3);
undefined4 FUN_004526a0(undefined4 param_1,undefined4 param_2,LPCVOID *param_3,LPVOID *param_4);
void FUN_00452704(undefined4 param_1,undefined4 param_2,LPCVOID *param_3,int param_4);
uint FUN_00452718(undefined4 param_1,undefined4 param_2,LPCVOID *param_3,byte **param_4);
uint FUN_004527e4(uint param_1,uint param_2,byte **param_3,byte param_4,byte **param_5);
undefined *FUN_004528d8(undefined param_1,undefined param_2,undefined param_3,undefined *param_4,undefined *param_5,ushort param_6);
undefined *FUN_00452928(undefined param_1,undefined param_2,undefined param_3,undefined *param_4,short *param_5);
undefined4 FUN_004529e8(uint param_1,undefined4 param_2,DWORD param_3,LPCVOID *param_4,undefined4 param_5,int param_6,uint param_7);
void FUN_00452b70(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00452ba0(undefined param_1,undefined param_2,undefined param_3,undefined param_4,int param_5);
void FUN_00452bc8(undefined param_1,undefined param_2,undefined param_3,uint param_4,int param_5);
undefined1 *Sprintf0(undefined param_1,byte param_2,byte param_3,undefined4 param_4,undefined4 param_5,byte *param_6,uint *param_7);
int FUN_004532b8(undefined4 param_1,undefined4 param_2,LPCVOID *param_3);
uint FUN_00453304(undefined param_1,undefined param_2,undefined param_3,uint param_4);
char * FUN_00453390(undefined param_1,undefined param_2,byte param_3,char *param_4,int param_5);
char * FUN_004533fc(undefined4 param_1,undefined4 param_2,DWORD param_3,uint *param_4,LPVOID param_5,char *param_6);
int FUN_0045352c(undefined param_1,undefined param_2,undefined param_3,void *param_4,char **param_5,undefined *param_6,int param_7);
DWORD FUN_004535e4(undefined4 param_1,undefined4 param_2,DWORD param_3,uint param_4,LPCVOID param_5,DWORD param_6);
int ** FUN_004536c4(undefined param_1,undefined param_2,undefined param_3,int param_4,int **param_5,uint param_6);
int FUN_00453824(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
uint FUN_00453864(undefined param_1,undefined param_2,undefined param_3,uint param_4,uint param_5,undefined4 param_6);
void FUN_004538cc(undefined param_1,undefined param_2,undefined param_3,uint param_4);
int FUN_004538e8(undefined param_1,undefined param_2,undefined param_3,int *param_4);
void FUN_0045397c(void);
undefined4 FUN_00453ac0(undefined param_1,undefined param_2,undefined param_3,int param_4);
void FUN_00453b24(void);
undefined4 FUN_00453b38(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4);
DWORD FUN_00453b6c(undefined4 param_1,undefined4 param_2,DWORD param_3,uint param_4,LPVOID param_5,DWORD param_6);
void FUN_00453bb4(undefined4 param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,LPVOID param_5,DWORD param_6);
DWORD FUN_00453bd0(undefined4 param_1,undefined4 param_2,DWORD param_3,uint param_4,LPCVOID param_5,DWORD param_6);
void FUN_00453c18(undefined4 param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,LPCVOID param_5,DWORD param_6);
undefined4 FUN_00453c34(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4,byte param_5);
undefined4 FUN_00453c70(undefined param_1,undefined param_2,undefined param_3,uint param_4);
bool FUN_00453cb0(undefined param_1,undefined param_2,undefined param_3,uint param_4);
DWORD FUN_00453ce0(undefined param_1,undefined param_2,undefined param_3,uint param_4,LONG param_5,int param_6);
int FUN_00453d58(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4,uint param_5,uint param_6);
undefined4 FUN_00453f48(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4);
uint FUN_00453f68(undefined param_1,undefined param_2,undefined param_3,uint param_4);
undefined2 FUN_00453f90(void);
void FUN_00453fa4(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void thunk_FUN_00454090(void);
void thunk_FUN_00454090(void);
void FUN_00453fe4(void);
undefined4 FUN_00453ffc(void);
int FUN_00454024(undefined param_1,undefined param_2,undefined param_3,char *param_4);
void FUN_00454080(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00454090(void);
char * FUN_004540a8(undefined param_1,undefined param_2,undefined param_3,uint param_4,char *param_5,uint param_6,char param_7,char param_8);
void FUN_0045411c(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
void FUN_00454168(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
void FUN_00454188(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5,int param_6);
void FUN_0045420c(undefined param_1,undefined param_2,undefined param_3,undefined *param_4,undefined *param_5);
void FUN_00454224(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
undefined4 FUN_004542a0(undefined param_1,undefined param_2,undefined param_3,int param_4);
void __stdcall TurboFree?(int *param_1);
undefined4 FUN_00454470(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4,uint param_5);
void * __stdcall TurboAlloc?(uint len);
void FUN_004545fc(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0045460c(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
undefined4 FUN_0045461c(undefined param_1,undefined param_2,undefined param_3,int param_4,LPVOID *param_5,uint *param_6);
undefined4 FUN_00454688(undefined param_1,undefined param_2,undefined param_3,LPVOID param_4,int param_5);
undefined4 FUN_004546dc(undefined param_1,undefined param_2,undefined param_3,LPVOID param_4,int param_5);
undefined4 FUN_0045471c(undefined param_1,undefined param_2,undefined param_3,LPVOID param_4);
undefined4 FUN_00454758(void);
void FUN_004547a0(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4);
void FUN_00454850(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00454860(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_004548bc(void);
void FUN_004548d0(void);
undefined4 FUN_004548e0(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_0045490c(void);
void __stdcall DoSomethingThenExit?0(int param_1,int param_2,UINT exitCode);
void __stdcall DoSomethingThenExit?(UINT exitCode);
void FUN_00454980(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4);
void FUN_00454a08(void);
undefined4 *FUN_00454a0c(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4,char *param_5);
void FUN_00454a60(void);
int FUN_00454ae4(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_00454b04(undefined param_1,undefined param_2,undefined param_3,int *param_4,undefined param_5,int param_6);
undefined4 HandlerRoutine_00454c74(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_00454c98(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,undefined4 param_5);
undefined4 FUN_00454cf8(undefined param_1,undefined param_2,undefined param_3,int param_4);
undefined4 FUN_00454d74(void);
undefined4 FUN_00454d78(void);
undefined4 FUN_00454d7c(undefined param_1,undefined param_2,undefined param_3,int *param_4,uint param_5);
void FUN_00454f8c(void);
bool FUN_004551a4(undefined param_1,undefined param_2,undefined param_3,uint param_4,uint param_5,uint param_6,uint param_7);
int FUN_004552b8(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,int param_6,int param_7,int param_8,int param_9);
void FUN_00455430(undefined param_1,undefined param_2,undefined param_3,int *param_4);
void __stdcall ExitProcess(UINT uExitCode);
HGLOBAL __stdcall GlobalFree(HGLOBAL hMem);
BOOL __stdcall WritePrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpString,LPCSTR lpFileName);
BOOL __stdcall SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,BOOL Add);
BOOL __stdcall FreeLibrary(HMODULE hLibModule);
DWORD __stdcall GetEnvironmentVariableA(LPCSTR lpName,LPSTR lpBuffer,DWORD nSize);
LPCH __stdcall GetEnvironmentStrings(void);
void __stdcall GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
LONG __stdcall UnhandledExceptionFilter(_EXCEPTION_POINTERS *ExceptionInfo);
HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName);
void __stdcall RaiseException(DWORD dwExceptionCode,DWORD dwExceptionFlags,DWORD nNumberOfArguments,ULONG_PTR *lpArguments);
HGLOBAL __stdcall LoadResource(HMODULE hModule,HRSRC hResInfo);
DWORD __stdcall GetFileType(HANDLE hFile);
BOOL __stdcall CloseHandle(HANDLE hObject);
HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName);
UINT __stdcall _lread(HFILE hFile,LPVOID lpBuffer,UINT uBytes);
HFILE __stdcall _lclose(HFILE hFile);
BOOL __stdcall WriteFile(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped);
DWORD __stdcall GetPrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD nSize,LPCSTR lpFileName);
UINT __stdcall GetPrivateProfileIntA(LPCSTR lpAppName,LPCSTR lpKeyName,INT nDefault,LPCSTR lpFileName);
UINT __stdcall SetErrorMode(UINT uMode);
void __stdcall RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue);
HANDLE __stdcall GetStdHandle(DWORD nStdHandle);
LPVOID __stdcall LockResource(HGLOBAL hResData);
void __stdcall GetLocalTime(LPSYSTEMTIME lpSystemTime);
SIZE_T __stdcall GlobalSize(HGLOBAL hMem);
HGLOBAL __stdcall GlobalAlloc(UINT uFlags,SIZE_T dwBytes);
LPVOID __stdcall GlobalLock(HGLOBAL hMem);
UINT __stdcall GetWindowsDirectoryA(LPSTR lpBuffer,UINT uSize);
DWORD __stdcall GetLastError(void);
BOOL __stdcall FreeResource(HGLOBAL hResData);
BOOL __stdcall GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
DWORD __stdcall GetVersion(void);
BOOL __stdcall DeleteFileA(LPCSTR lpFileName);
BOOL __stdcall CreateDirectoryA(LPCSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
HFILE __stdcall _lopen(LPCSTR lpPathName,int iReadWrite);
LONG __stdcall _llseek(HFILE hFile,LONG lOffset,int iOrigin);
DWORD __stdcall GetCurrentDirectoryA(DWORD nBufferLength,LPSTR lpBuffer);
HANDLE __stdcall CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
FARPROC __stdcall GetProcAddress(HMODULE hModule,LPCSTR lpProcName);
LPVOID __stdcall VirtualAlloc(LPVOID lpAddress,SIZE_T dwSize,DWORD flAllocationType,DWORD flProtect);
DWORD __stdcall GetCurrentThreadId(void);
UINT __stdcall SetHandleCount(UINT uNumber);
DWORD __stdcall SetFilePointer(HANDLE hFile,LONG lDistanceToMove,PLONG lpDistanceToMoveHigh,DWORD dwMoveMethod);
BOOL __stdcall VirtualFree(LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType);
UINT __stdcall GetDriveTypeA(LPCSTR lpRootPathName);
DWORD __stdcall GetFileAttributesA(LPCSTR lpFileName);
DWORD __stdcall GetModuleFileNameA(HMODULE hModule,LPSTR lpFilename,DWORD nSize);
BOOL __stdcall ReadFile(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,LPOVERLAPPED lpOverlapped);
HRSRC __stdcall FindResourceA(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
DWORD __stdcall GetLogicalDrives(void);
BOOL __stdcall GlobalUnlock(HGLOBAL hMem);
LPSTR __stdcall GetCommandLineA(void);
BOOL __stdcall SetDlgItemTextA(HWND hDlg,int nIDDlgItem,LPCSTR lpString);
BOOL __stdcall RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
int __stdcall ReleaseDC(HWND hWnd,HDC hDC);
BOOL __stdcall SetMenu(HWND hWnd,HMENU hMenu);
ATOM __stdcall RegisterClassA(WNDCLASSA *lpWndClass);
BOOL __stdcall ScreenToClient(HWND hWnd,LPPOINT lpPoint);
HCURSOR __stdcall SetCursor(HCURSOR hCursor);
BOOL __stdcall SetForegroundWindow(HWND hWnd);
void __stdcall PostQuitMessage(int nExitCode);
BOOL __stdcall PostMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
int __stdcall MessageBoxA(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType);
int __stdcall LoadStringA(HINSTANCE hInstance,UINT uID,LPSTR lpBuffer,int cchBufferMax);
HMENU __stdcall LoadMenuA(HINSTANCE hInstance,LPCSTR lpMenuName);
HWND __stdcall SetActiveWindow(HWND hWnd);
HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance,LPCSTR lpCursorName);
BOOL __stdcall IsIconic(HWND hWnd);
BOOL __stdcall InvalidateRect(HWND hWnd,RECT *lpRect,BOOL bErase);
BOOL __stdcall InsertMenuA(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
BOOL __stdcall GetWindowRect(HWND hWnd,LPRECT lpRect);
int __stdcall GetSystemMetrics(int nIndex);
HMENU __stdcall GetSubMenu(HMENU hMenu,int nPos);
int __stdcall GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,int cchMax,UINT flags);
UINT __stdcall GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
UINT __stdcall GetMenuItemID(HMENU hMenu,int nPos);
int __stdcall GetMenuItemCount(HMENU hMenu);
BOOL __stdcall GetKeyboardState(PBYTE lpKeyState);
UINT __stdcall GetDlgItemTextA(HWND hDlg,int nIDDlgItem,LPSTR lpString,int cchMax);
HDC __stdcall GetDC(HWND hWnd);
BOOL __stdcall GetCursorPos(LPPOINT lpPoint);
BOOL __stdcall GetClipCursor(LPRECT lpRect);
HWND __stdcall GetActiveWindow(void);
HWND __stdcall FindWindowA(LPCSTR lpClassName,LPCSTR lpWindowName);
int __stdcall FillRect(HDC hDC,RECT *lprc,HBRUSH hbr);
BOOL __stdcall EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);
BOOL __stdcall EndPaint(HWND hWnd,PAINTSTRUCT *lpPaint);
SHORT __stdcall GetAsyncKeyState(int vKey);
BOOL __stdcall EndDialog(HWND hDlg,INT_PTR nResult);
BOOL __stdcall EnableMenuItem(HMENU hMenu,UINT uIDEnableItem,UINT uEnable);
BOOL __stdcall DrawMenuBar(HWND hWnd);
HWND __stdcall GetDesktopWindow(void);
LRESULT __stdcall DispatchMessageA(MSG *lpMsg);
INT_PTR __stdcall DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
BOOL __stdcall DestroyWindow(HWND hWnd);
BOOL __stdcall DestroyMenu(HMENU hMenu);
BOOL __stdcall DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
LRESULT __stdcall DefWindowProcA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
HMENU __stdcall GetSystemMenu(HWND hWnd,BOOL bRevert);
DWORD __stdcall CheckMenuItem(HMENU hMenu,UINT uIDCheckItem,UINT uCheck);
BOOL __stdcall ClientToScreen(HWND hWnd,LPPOINT lpPoint);
HMENU __stdcall CreateMenu(void);
BOOL __stdcall IntersectRect(LPRECT lprcDst,RECT *lprcSrc1,RECT *lprcSrc2);
HDC __stdcall BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
HWND __stdcall CreateWindowExA(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
BOOL __stdcall AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
HICON __stdcall LoadIconA(HINSTANCE hInstance,LPCSTR lpIconName);
BOOL __stdcall ClipCursor(RECT *lpRect);
BOOL __stdcall UpdateWindow(HWND hWnd);
BOOL __stdcall UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
BOOL __stdcall PeekMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg);
BOOL __stdcall TranslateMessage(MSG *lpMsg);
BOOL __stdcall ShowWindow(HWND hWnd,int nCmdShow);
int __stdcall ShowCursor(BOOL bShow);
ATOM __stdcall RegisterClassExA(WNDCLASSEXA *param_1);
BOOL __stdcall SetWindowPos(HWND hWnd,HWND hWndInsertAfter,int X,int Y,int cx,int cy,UINT uFlags);
BOOL __stdcall SetRect(LPRECT lprc,int xLeft,int yTop,int xRight,int yBottom);
UINT __stdcall RealizePalette(HDC hdc);
UINT __stdcall GetSystemPaletteUse(HDC hdc);
UINT __stdcall GetSystemPaletteEntries(HDC hdc,UINT iStart,UINT cEntries,LPPALETTEENTRY pPalEntries);
HGDIOBJ __stdcall GetStockObject(int i);
int __stdcall GetDeviceCaps(HDC hdc,int index);
BOOL __stdcall DeleteObject(HGDIOBJ ho);
BOOL __stdcall DeleteDC(HDC hdc);
HBRUSH __stdcall CreateSolidBrush(COLORREF color);
HPALETTE __stdcall CreatePalette(LOGPALETTE *plpal);
BOOL __stdcall TextOutA(HDC hdc,int x,int y,LPCSTR lpString,int c);
int __stdcall StretchDIBits(HDC hdc,int xDest,int yDest,int DestWidth,int DestHeight,int xSrc,int ySrc,int SrcWidth,int SrcHeight,void *lpBits,BITMAPINFO *lpbmi,UINT iUsage,DWORD rop);
UINT __stdcall SetPaletteEntries(HPALETTE hpal,UINT iStart,UINT cEntries,PALETTEENTRY *pPalEntries);
HPALETTE __stdcall SelectPalette(HDC hdc,HPALETTE hPal,BOOL bForceBkgd);
HGDIOBJ __stdcall SelectObject(HDC hdc,HGDIOBJ h);
MMRESULT __stdcall waveOutUnprepareHeader(HWAVEOUT hwo,LPWAVEHDR pwh,UINT cbwh);
MMRESULT __stdcall waveOutRestart(HWAVEOUT hwo);
MMRESULT __stdcall waveOutReset(HWAVEOUT hwo);
MMRESULT __stdcall waveOutPrepareHeader(HWAVEOUT hwo,LPWAVEHDR pwh,UINT cbwh);
MMRESULT __stdcall waveOutPause(HWAVEOUT hwo);
MMRESULT __stdcall waveOutOpen(LPHWAVEOUT phwo,UINT uDeviceID,LPCWAVEFORMATEX pwfx,DWORD_PTR dwCallback,DWORD_PTR dwInstance,DWORD fdwOpen);
UINT __stdcall waveOutGetNumDevs(void);
MMRESULT __stdcall waveOutGetErrorTextA(MMRESULT mmrError,LPSTR pszText,UINT cchText);
MMRESULT __stdcall waveOutClose(HWAVEOUT hwo);
DWORD __stdcall timeGetTime(void);
MMRESULT __stdcall timeGetDevCaps(LPTIMECAPS ptc,UINT cbtc);
MMRESULT __stdcall timeEndPeriod(UINT uPeriod);
MMRESULT __stdcall timeBeginPeriod(UINT uPeriod);
UINT __stdcall midiOutGetNumDevs(void);
MMRESULT __stdcall midiOutGetDevCapsA(UINT_PTR uDeviceID,LPMIDIOUTCAPSA pmoc,UINT cbmoc);
MMRESULT __stdcall waveOutWrite(HWAVEOUT hwo,LPWAVEHDR pwh,UINT cbwh);
MCIERROR __stdcall mciSendCommandA(MCIDEVICEID mciId,UINT uMsg,DWORD_PTR dwParam1,DWORD_PTR dwParam2);

