#include "annotated.h"



char * __stdcall GetWinapiStringAlloc(UINT id)

{
  int copied;
  char *result;
  CHAR scratch [256];
  
  copied = LoadStringA(_Module,id,scratch,0xfe);
  if (copied == 0) {
    Sprintf_(scratch,s_Cannot_Load_Resource___d___missi_00460112,id);
    MessageBoxA((HWND)0x0,scratch,(LPCSTR)&lpCaption_0046013e,0x10);
    DoSomethingThenExit_(1);
  }
  result = (char *)TurboAlloc_(0xff);
  if (result == (char *)0x0) {
    Sprintf_(scratch,s_Cannot_Load_Resource___d___out_o_00460142,id);
    MessageBoxA((HWND)0x0,scratch,(LPCSTR)&lpCaption_0046016c,0x10);
    DoSomethingThenExit_(1);
  }
  Strcpy(result,scratch);
  return result;
}



void __stdcall GetWinapiString(char *result,UINT id)

{
  int copied;
  CHAR scratch [256];
  
  copied = LoadStringA(_Module,id,scratch,0xfe);
  if (copied == 0) {
    Sprintf_(scratch,s_Cannot_Load_Resource___d___missi_00460170,id);
    MessageBoxA((HWND)0x0,scratch,(LPCSTR)&lpCaption_0046019c,0x10);
    DoSomethingThenExit_(1);
  }
  Strcpy(result,scratch);
  return;
}



void __stdcall Draw::StringWithCurrentFontAndColor(short x,short y,char *value)

{
  StringWithCurrentFontAndColor(x,y,value);
  return;
}



void __cdecl Game::ShowTaskbar(short shouldShow)

{
  HWND hWnd;
  
                    // if VER_PLATFORM_WIN32_WINDOWS, not VER_PLATFORM_WIN32s
  if (_dwPlatformId == 1) {
    hWnd = FindWindowA(s_Shell_TrayWnd_004601cc,(LPCSTR)0x0);
    ShowWindow(hWnd,(uint)(shouldShow != 0));
  }
  return;
}



ATOM __cdecl Game::CreateWindow(undefined4 param_1)

{
  ATOM windowClass;
  WNDCLASSEXA local_34;
  
  GetWinapiString((char *)&lpWindowName_00464880,0x4e21);
  local_34.lpszClassName = s_TLCSSG_004601be;
  local_34.lpszMenuName = (LPCSTR)0x100;
  local_34.style = 0x1040;
  local_34.hInstance = _Module;
  local_34.lpfnWndProc = MainWndProc;
  local_34.hCursor = (HCURSOR)0x0;
  local_34.hIcon = LoadIconA(_Module,(LPCSTR)0x80);
  local_34.hbrBackground = (HBRUSH)GetStockObject(1);
  local_34.cbClsExtra = 0;
  local_34.cbWndExtra = 0;
  local_34.cbSize = 0x30;
  if (_dwPlatformId == 2) {
    local_34.hIconSm = (HICON)0x0;
  }
  else {
    local_34.hIconSm = LoadIconA(_Module,(LPCSTR)0x81);
  }
  windowClass = RegisterClassExA(&local_34);
  ShowTaskbar(0);
  if (windowClass != 0) {
    window = CreateWindowExA(0,s_TLCSSG_004601be,(LPCSTR)&lpWindowName_00464880,0xca0000,
                             _DesktopRect.left,_DesktopRect.top,_DesktopRect.right,
                             _DesktopRect.bottom,(HWND)0x0,(HMENU)0x0,_Module,(LPVOID)0x0);
    if (window == (HWND)0x0) {
      windowClass = 0;
    }
    else {
      ShowWindow(window,1);
      UpdateWindow(window);
    }
  }
  return windowClass;
}



void Game::MakeWindowAnnoying(void)

{
  int titleBarHeight;
  int menuBarHeight;
  int screenWidth;
  int screenHeight;
  int screenHeight_;
  uint xPadding;
  int leftPadding;
  UINT uFlags;
  
  titleBarHeight = GetSystemMetrics(SM_CYCAPTION);
  menuBarHeight = GetSystemMetrics(SM_CYMENU);
  GetSystemMetrics(1);
  screenWidth = GetSystemMetrics(SM_CXSCREEN);
  screenHeight = GetSystemMetrics(SM_CYSCREEN);
  uFlags = 6;
  screenHeight_ = GetSystemMetrics(SM_CYSCREEN);
                    // move window to (0,0); resize to whole screen
  SetWindowPos(window,(HWND)0x0,0,0,(int)(short)screenWidth,screenHeight_,uFlags);
  xPadding = (int)(short)screenWidth - 512;
  leftPadding = (int)xPadding >> 1;
  if (leftPadding < 0) {
    leftPadding = leftPadding + (uint)((xPadding & 1) != 0);
  }
  mouseInputRect.left = leftPadding + _DesktopRect.left;
  xPadding = (int)(short)(((short)screenHeight - (short)menuBarHeight) - (short)titleBarHeight) -
             384;
  titleBarHeight = (int)xPadding >> 1;
  if (titleBarHeight < 0) {
    titleBarHeight = titleBarHeight + (uint)((xPadding & 1) != 0);
  }
  mouseInputRect.top = titleBarHeight + _DesktopRect.top;
                    // this is incorrect, but it doesn’t break anything
  mouseInputRect.right = mouseInputRect.right + 511;
  mouseInputRect.bottom = mouseInputRect.top + 383;
  SetDrawAreaXY((undefined2)mouseInputRect.left,(undefined2)mouseInputRect.top);
  return;
}



void InitEntities(void)

{
  short i;
  
  i = 0;
  do {
    _Entities[i].available = 1;
    i = i + 1;
  } while (i < 0x3c);
  return;
}



void StartLevel(void)

{
  short i;
  Dlist *list;
  void *current;
  Room *room;
  short local_6;
  short building;
  short count;
  ushort partsCount;
  
  building = _GameState->building;
  if (building == 0) {
    _BuildingTextResourceId = 0x177c;
  }
  else if (building == 1) {
    _BuildingTextResourceId = 0x1770;
  }
  else if (building == 2) {
    _BuildingTextResourceId = 0x177a;
  }
  FUN_00446186(_BuildingTextResourceId);
  _Area = (Area *)Resource::Load(_LevelAreaResourceIds[_GameState->level],&_AREA);
  _RoomCount = _Area->roomCount;
  room = _Area->rooms;
  InitEntities();
  _RoomInitialPartsCounts = (ushort *)Resource::Load(_GameState->level + 0x582,_pINTS);
  GenInitialPartIds(*_RoomInitialPartsCounts);
  _InitialBananaPartsCount = *_RoomInitialPartsCounts - _Level_partResource->definitionCount;
  _ActualBananaPartsCount = _InitialBananaPartsCount;
  Memset(_Rooms,0,0x40);
  for (local_6 = 0; local_6 < _RoomCount; local_6 = local_6 + 1) {
    _Rooms[local_6] = room;
    current = room->entities;
    i = 3;
    do {
      count = room->structuralEntityCounts[i];
      if (count != 0) {
        room->structuralEntityGroups[i] = (OtherEntity *)current;
        current = (void *)((int)(EntityBase_ *)current + count * 0x20);
      }
      i = i + -1;
    } while (-1 < i);
    i = 0;
    do {
      count = room->ladderEntityCounts[i];
      if (count != 0) {
        room->ladderEntityGroups[i] = (LadderEntity *)current;
        current = (void *)((int)current + count * 0x28);
      }
      i = i + 1;
    } while (i < 4);
    i = 0;
    do {
      count = room->cEntityCounts_[i];
      if (count != 0) {
        room->cEntityGroups_[i] = current;
        current = (void *)((int)&(((EntityBase_ *)current)->rect).inner + count * 10);
      }
      i = i + 1;
    } while (i < 6);
    i = 0;
    do {
      count = room->dEntityCounts_[i];
      if (count != 0) {
        room->dEntityGroups_[i] = current;
        current = (void *)((int)&(((EntityBase_ *)current)->rect).inner + count * 10);
      }
      i = i + 1;
    } while (i < 6);
    i = 0;
    do {
      count = room->eEntityCounts_[i];
      if (count != 0) {
        room->eEntityGroups_[i] = current;
        current = (void *)((int)&(((EntityBase_ *)current)->rect).inner + count * 10);
      }
      i = i + 1;
    } while (i < 6);
    if (local_6 != 0) {
      list = DlistNew();
      room->partEntities = list;
      partsCount = _RoomInitialPartsCounts[local_6];
      room->partEntityCount = partsCount;
      if (partsCount != 0) {
        room->partEntityCount = 0;
        PlacePartEntity(room,_RoomInitialPartsCounts[local_6],-1);
      }
    }
    room = (Room *)current;
  }
  _RoomIndex = 0;
  return;
}



ushort __stdcall RoomIsObverse(short roomIndex)

{
  return _Rooms[roomIndex]->flags & 1;
}



EntityNode * NextAvailableEntityNode(void)

{
  EntityNode *node;
  
  for (node = _Entities; node->available != 1; node = node + 1) {
  }
  return node;
}



ushort __stdcall PlacePartEntity(Room *room,short count,PartId partId)

{
  ushort *puVar1;
  short rows;
  PartId id;
  uint collision;
  int wtf;
  short j;
  EntityBaseBase_ rect;
  short locations [90];
  OtherEntity *entity;
  ushort result;
  LadderEntity *ladder;
  EntityNode *partNode;
  EntityNode *entityNode;
  short done;
  short partHeight;
  short columnWidth;
  short partWidth_;
  ushort baseSpriteId;
  short rowHeight;
  short firstPartY;
  short columns;
  short firstPartX;
  short i;
  short locationCount;
  short locationIndex;
  short partCount;
  short structuralCount;
  short ladderCount;
  bool bad;
  
  locationIndex = 0;
  result = 1;
                    // is room obverse?
  if ((*(byte *)&room->flags & 1) == 0) {
                    // room #4 through #15, reverse side (big sprites), three floors
    rows = 3;
    firstPartX = 24;
    columns = 7;
    firstPartY = 88;
    rowHeight = 100;
    baseSpriteId = 0xc4a;
    partWidth_ = 32;
    columnWidth = 64;
    partHeight = 24;
  }
  else {
                    // rooms #1 through #3, obverse side (small sprites), six floors
    rows = 6;
    firstPartX = 16;
    columns = 15;
    firstPartY = 52;
    rowHeight = 50;
    baseSpriteId = 0xbc7;
    partWidth_ = 16;
    columnWidth = 32;
    partHeight = 13;
  }
                    // generate a complete but random list of possible locations [0,locations);
                    // locations are numbered in latin reading order, e.g. for obverse (15x6),
                    // |0  1  2  3  4  5  6  7  8  9  10 11 12 13 14|
                    // |15 16 17 18 19 20 21 22 23 24 25 26 27 28 29|
                    // |...                                         |
  locationCount = rows * columns;
  DonkeyShuffle(locationCount,locations);
                    // for count times...
  i = 0;
  if (0 < count) {
    do {
                    // ...attempt to place a part entity...
      entityNode = NextAvailableEntityNode();
      done = 0;
      while (done == 0) {
                    // ...at the next location from the list that passes certain tests:
        rect._8_2_ = 0;
        rect._10_4_ = 0;
        rect.inner.y = (locations[locationIndex] / columns) * rowHeight + firstPartY;
        rect.inner.x = (locations[locationIndex] % columns) * columnWidth + firstPartX;
        locationIndex = locationIndex + 1;
        if (locationCount <= locationIndex) {
          return 0;
        }
        rect.inner.w = columnWidth;
        rect.inner.h = partHeight;
        bad = false;
                    // 1. avoid intersecting other part entities
        partCount = room->partEntityCount;
        partNode = (EntityNode *)DlistHead(room->partEntities);
        for (j = 0; (!bad && (j < partCount)); j = j + 1) {
          collision = CheckCollision((Rect16 *)&rect,(Rect16 *)&partNode->inner);
          if ((short)collision != 0) {
            bad = true;
          }
          partNode = (EntityNode *)DlistNext(&partNode->node);
        }
                    // 2. avoid intersecting structural entities of type > 3 (e.g. gaps, doors)
        entity = room->structuralEntityGroups[0];
        structuralCount = room->structuralEntityCounts[0];
        for (j = 0; (!bad && (j < structuralCount)); j = j + 1) {
          if ((3 < (entity->base).type) &&
             (collision = CheckCollision((Rect16 *)&rect,(Rect16 *)entity), (short)collision != 0))
          {
            bad = true;
          }
          entity = entity + 1;
        }
                    // 3. avoid intersecting ladder entities (vents, paddles, trampolines)
        ladderCount = room->ladderEntityCounts[0];
        ladder = room->ladderEntityGroups[0];
        for (j = 0; (!bad && (j < ladderCount)); j = j + 1) {
          collision = CheckCollision((Rect16 *)&rect,(Rect16 *)ladder);
          if ((short)collision != 0) {
            bad = true;
          }
          ladder = ladder + 1;
        }
        if (!bad) {
          done = 1;
        }
      }
                    // what the fuck?
      wtf = (int)columnWidth >> 1;
      if (wtf < 0) {
        wtf = wtf + (uint)(((int)columnWidth & 1U) != 0);
      }
      rect.inner.x = rect.inner.x + (short)wtf;
      rect.inner.w = partWidth_;
      rect._10_4_ = 0;
      entity = &entityNode->inner;
      Memcpy(entity,&rect,0xe);
      (entity->base).spriteId = baseSpriteId;
      if (partId == 1000) {
                    // partId is bananas, so place bananas as a fresh part
        entity->partId = 1000;
      }
      else if (partId == -1) {
                    // no partId given, so place random part as fresh part
        id = NextInitialPartId();
        entity->partId = id;
      }
      else {
                    // place given partId as either fresh or recycled
        entity->partId = partId;
                    // is part recycled?
        if ((_Level_partDefinitions[partId].flags & 0x40) != 0) {
          puVar1 = &(entity->base).spriteId;
          *puVar1 = *puVar1 + 1;
        }
      }
      *(undefined2 *)&entity->field_0x14 = 0;
      Memcpy(&entity->activation_,&rect,10);
      (entity->activation_).mode = 0x800;
      room->partEntityCount = room->partEntityCount + 1;
      entityNode->available = 0;
      DlistInsert(room->partEntities,&entityNode->node,-1);
      i = i + 1;
    } while (i < count);
  }
  return result;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __stdcall LoadPartEntity(short roomIndex,short x,short row,short partId,short param_5)

{
  EntityNode *node;
  undefined4 uVar1;
  undefined2 uVar2;
  EntityBaseBase_ rect;
  ushort spriteId;
  Room *room;
  
  room = _Rooms[roomIndex];
  node = NextAvailableEntityNode();
  rect._8_2_ = 0;
  rect.inner.x = x;
  if ((*(byte *)&room->flags & 1) == 0) {
    if (2 < row) {
      row = row + -3;
    }
    rect.inner.y = row * 100 + 88;
    rect.inner.w = 20;
    rect.inner.h = 13;
    spriteId = 0xc4a;
  }
  else {
    rect.inner.y = row * 50 + 52;
    rect.inner.w = 10;
    rect.inner.h = 7;
    spriteId = 0xbc7;
  }
  if ((partId != 1000) && ((_Level_partDefinitions[partId].flags & 0x40) != 0)) {
    spriteId = spriteId + 1;
  }
  Memcpy(&node->inner,&rect,0xe);
  (node->inner).base.spriteId = spriteId;
  (node->inner).partId = partId;
  *(undefined2 *)&(node->inner).field_0x14 = 0;
  Memcpy(&(node->inner).activation_,&rect,10);
  (node->inner).activation_.mode = 0x800;
  if (param_5 == 0) {
    room->partEntityCount = room->partEntityCount + 1;
    if (roomIndex == _RoomIndex) {
      _DAT_00460318 = _DAT_00460318 + 1;
      uVar1 = FUN_00412ac4((node->inner).base.spriteId);
      *(undefined4 *)&(node->inner).base.rect.field_0xa = uVar1;
      uVar2 = (undefined2)((uint)uVar1 >> 0x10);
      FUN_0041395c(*(undefined4 *)&(node->inner).base.rect.field_0xa,CONCAT22(uVar2,rect.inner.x),
                   CONCAT22(uVar2,rect.inner.y),0x14);
      FUN_00412dc8(*(undefined4 *)&(node->inner).base.rect.field_0xa);
    }
  }
  node->available = 0;
  DlistInsert(room->partEntities,&node->node,-1);
  return;
}



void __stdcall LoadEntities(char *puzzleEntityTypes,SavedPartEntity *partEntities)

{
  OtherEntity *entity;
  ushort spriteId;
  short j;
  short roomIndex;
  short partEntityCount;
  ushort flags;
  Room *room;
  
  InitEntities();
  _ActualBananaPartsCount = 0;
  roomIndex = 0;
  do {
    room = _Rooms[roomIndex];
    if (room != (Room *)0x0) {
      flags = room->flags;
      entity = room->structuralEntityGroups[0];
      for (j = 0; j < room->structuralEntityCounts[0]; j = j + 1) {
                    // is entity a puzzle door?
        if (((entity->base).type == 7) || ((entity->base).type == 9)) {
          (entity->base).type = (short)*puzzleEntityTypes;
          puzzleEntityTypes = puzzleEntityTypes + 1;
                    // is door unlocked?
          if ((entity->base).type == 9) {
            (entity->activation_).mode = 4;
            if ((flags & 1) == 0) {
              spriteId = 0xc26;
            }
            else {
              spriteId = 0xbc0;
            }
            (entity->base).spriteId = spriteId;
          }
        }
        entity = entity + 1;
      }
      DlistInit(room->partEntities);
                    // FIXME this is a length field, like (ushort,SavedPartEntity[])
      partEntityCount = partEntities->x;
      room->partEntityCount = partEntityCount;
      partEntities = (SavedPartEntity *)&partEntities->row;
      j = 0;
      if (0 < partEntityCount) {
        do {
          LoadPartEntity(roomIndex,partEntities->x,partEntities->row,partEntities->partId,1);
          if (partEntities->partId == 1000) {
            _ActualBananaPartsCount = _ActualBananaPartsCount + 1;
          }
          partEntities = partEntities + 1;
          j = j + 1;
        } while (j < partEntityCount);
      }
    }
    roomIndex = roomIndex + 1;
  } while (roomIndex < 0x10);
  return;
}



uint __stdcall CheckCollision(Rect16 *p,Rect16 *q)

{
  uint result;
  short pRight;
  short pBottom;
  short qBottom;
  short qRight;
  short pLeft;
  short pTop;
  short qLeft;
  short qTop;
  
  result = 0;
  pLeft = p->x;
  pRight = pLeft + p->w;
  pTop = p->y;
  pBottom = pTop + p->h;
  qLeft = q->x;
  qRight = qLeft + q->w;
  qTop = q->y;
  qBottom = qTop + q->h;
  if ((((pLeft < qRight) && (qLeft < pRight)) && (pTop < qBottom)) && (qTop < pBottom)) {
    result = (uint)(pLeft < qLeft);
    if (qRight < pRight) {
      result = result | 2;
    }
    if (pTop < qTop) {
      result = result | 4;
    }
    if (qBottom < pBottom) {
      result = result | 8;
    }
    if ((short)result == 0) {
      result = 0xf;
    }
  }
  return result;
}



void __stdcall Draw::Integer(short x,short y,short value,short color)

{
  char valueString [20];
  
  SetCurrentColor(color);
  Sprintf_(valueString,&_d,(int)value);
  StringWithCurrentFontAndColor(x,y,valueString);
  return;
}



int __stdcall Puzzles::CountSolvedInCategory(PuzzleCategory category)

{
  short i;
  int result;
  
  result = 0;
  i = 0;
  do {
    if (_GameState->puzzles[(short)category].completion[i] != 0) {
      result = result + 1;
    }
    i = i + 1;
  } while (i < 43);
  return result;
}



void Puzzles::Customization::Draw(void)

{
  int count;
  short category;
  undefined2 color_;
  
  category = 0;
  do {
    if ((int)(short)(&DAT_00466750)[category * 7] - 1U < 4) {
      color_ = 0x81c;
    }
    else {
      color_ = 0;
    }
    ::Draw::Integer(0xf6,tableY[category],CATEGORY_LEN[category],color_);
    count = CountSolvedInCategory(category);
    ::Draw::Integer(0x164,tableY[category],(short)count,color_);
    category = category + 1;
  } while (category < 8);
  return;
}



void __stdcall ShowAlertMessage(char *message,undefined param_2)

{
  char *lpCaption;
  char text [500];
  
  Sprintf_(text,message,&param_2);
                    // 20102 = "Alert"
  lpCaption = GetWinapiStringAlloc(20102);
  MessageBoxA((HWND)0x0,text,lpCaption,0x30);
  TurboFree_(lpCaption);
  return;
}



void __stdcall DonkeyShuffle(short len,short *result)

{
  short *current;
  int random;
  short p;
  short q;
  short i;
  short scratch;
  
  i = 0;
  current = result;
  if (0 < len) {
    do {
      *current = i;
      current = current + 1;
      i = i + 1;
    } while (i < len);
  }
  i = 0;
  if (0 < (short)(len * 10)) {
    do {
      if (len == 0) {
        p = 0;
        q = 0;
      }
      else {
        random = Random();
        p = (short)(random % (int)len);
        random = Random();
        q = (short)(random % (int)len);
      }
      scratch = result[p];
      result[p] = result[q];
      result[q] = scratch;
      i = i + 1;
    } while (i < (short)(len * 10));
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __stdcall EnterBuilding(void)

{
  short sVar1;
  GameState *pGVar2;
  ushort criticalSlotCount;
  int iVar3;
  
  _GameState->levelInBuilding = _GameState->buildingCompletedLevels[_GameState->building] + 1;
  _GameState->level = _GameState->building * 5 + _GameState->levelInBuilding;
  LoadPartDefinitions_();
  StartLevel();
  if (_GameState->buildingIsInitialised[_GameState->building] == 0) {
    FUN_0041abd6();
    criticalSlotCount = GetCriticalSlotCount();
    _GameState->missingCriticalSlots = criticalSlotCount;
    if (_GameState->levelInBuilding == 0) {
      _GameState->field34_0x28 = 0;
      _GameState->field28_0x1c = 10;
    }
    else {
      _GameState->field28_0x1c =
           *(undefined2 *)(_GameState->buildings[_GameState->building].field0_0x0 + 2);
    }
    iVar3 = Random();
    _GameState->field37_0x2c = (ushort)(iVar3 % 100 < 0x32);
    FUN_00417abd();
    *(undefined2 *)&_GameState->field_0x1a = 0;
    _GameState->everBeenReadyToRace_ = 0;
    _GameState->field33_0x26 = 0xffff;
    _GameState->field29_0x1e = *(undefined2 *)(&DAT_00461abc + _GameState->levelInBuilding * 2);
    _GameState->installedParts = 0;
    FUN_00417c69();
  }
  else {
    FUN_0041a823();
    FUN_00417abd();
    pGVar2 = _GameState;
    sVar1 = _GameState->building;
    Memcpy(&_GameState->field_0x1a,_GameState->buildings + sVar1,0x14);
    ezFUN_0043da4e((ushort *)(pGVar2->buildings[sVar1].field0_0x0 + 0x14));
    LoadEntities(pGVar2->buildings[sVar1].puzzleDoors,
                 (SavedPartEntity *)&pGVar2->buildings[sVar1].savedPartEntities);
    FUN_00435050(pGVar2->buildings[sVar1].field4_0x492);
    _DAT_00461aae = 1;
  }
  FUN_0043bfee(2,0,1);
  Puzzles::SetVtableForGivenCategory(&PTR_LAB_00461b2c);
  return;
}



void Draw::DirtyInit(void)

{
  Memset(dirtyTiles,0,0x300);
  dirtyMode = 0;
  return;
}



void __cdecl Draw::DirtyCopy(byte (*dirtyTiles) [24] [32])

{
  Memcpy(Draw::dirtyTiles,dirtyTiles,0x300);
  if (dirtyMode == 0) {
    dirtyMode = 1;
  }
  return;
}



void __cdecl Draw::DirtyRect(Rect16 *rectOptional)

{
  bool *tile;
  short x2;
  short y;
  short x;
  short y2;
  short x1;
  short y1;
  
  if (rectOptional == (Rect16 *)0x0) {
    dirtyMode = -1;
  }
  else {
    x1 = rectOptional->x;
    x2 = x1 + rectOptional->w + -1;
    y1 = rectOptional->y;
    y2 = y1 + rectOptional->h + -1;
    if (x1 < 0) {
      x1 = 0;
    }
    if (511 < x2) {
      x2 = 511;
    }
    if (y1 < 0) {
      y1 = 0;
    }
    if (383 < y2) {
      y2 = 383;
    }
    for (y = y1 >> 4; y <= y2 >> 4; y = y + 1) {
      tile = dirtyTiles[y] + (x1 >> 4);
      for (x = x1 >> 4; x <= x2 >> 4; x = x + 1) {
        *tile = true;
        tile = tile + 1;
      }
    }
    if (dirtyMode == 0) {
      dirtyMode = 1;
    }
  }
  return;
}



uint Is16Color(void)

{
  return (uint)(_ColorMode == 16);
}



bool Is256Color(void)

{
  return _ColorMode == 256;
}



void __cdecl Game::SetDrawAreaXY(undefined2 param_1,undefined2 param_2)

{
  drawAreaX = param_1;
  drawAreaY = param_2;
  return;
}



void __stdcall ActorUpdateDynamics(short actorIndex,short obverse)

{
  int i;
  undefined *result;
  
  i = (int)actorIndex;
  if (obverse == 1) {
    result = _Actors[i].obverseDynamics;
  }
  else {
    result = _Actors[i].reverseDynamics;
  }
  _Actors[i].currentDynamics = result;
  return;
}



DlistNode * __stdcall DlistHead(DlistNode **param_1)

{
  if (param_1 == (DlistNode **)0x0) {
    return (DlistNode *)0x0;
  }
  return *param_1;
}



DlistNode * __stdcall DlistNext(DlistNode *param_1)

{
  return param_1->next;
}



void __stdcall DlistInsert(Dlist *list,DlistNode *node,short beforeIndex)

{
  DlistNode *nextChosen;
  DlistNode *prev;
  ushort i;
  DlistNode *nextToTry;
  
  if (list->head == (DlistNode *)0x0) {
    list->tail = node;
    list->head = node;
    list->head->prev = (DlistNode *)0x0;
    list->head->next = (DlistNode *)0x0;
    return;
  }
  if (beforeIndex == -1) {
    nextChosen = (DlistNode *)0x0;
    prev = list->tail;
    list->tail = node;
  }
  else {
    i = 0;
    nextToTry = list->head;
    prev = (DlistNode *)0x0;
    while ((nextChosen = nextToTry, i < (ushort)beforeIndex && (nextChosen != (DlistNode *)0x0))) {
      i = i + 1;
      prev = nextChosen;
      nextToTry = nextChosen->next;
    }
    if (nextChosen == (DlistNode *)0x0) {
      list->tail = node;
    }
    else {
      nextChosen->prev = node;
    }
  }
  node->next = nextChosen;
  node->prev = prev;
  if (prev != (DlistNode *)0x0) {
    prev->next = node;
  }
  if (beforeIndex == 0) {
    list->head = node;
  }
  return;
}



void __stdcall DlistRemove(Dlist *list,DlistNode *node)

{
  DlistNode *prev;
  
  prev = node->prev;
  if (prev == (DlistNode *)0x0) {
    list->head = node->next;
  }
  else {
    prev->next = node->next;
  }
  if (node->next != (DlistNode *)0x0) {
    node->next->prev = prev;
    return;
  }
  list->tail = node->prev;
  return;
}



Dlist * DlistNew(void)

{
  Dlist *result;
  
  result = (Dlist *)PoolAlloc(8);
  result->tail = (DlistNode *)0x0;
  result->head = (DlistNode *)0x0;
  return result;
}



void __stdcall DlistInit(Dlist *list)

{
  if (list != (Dlist *)0x0) {
    list->tail = (DlistNode *)0x0;
    list->head = (DlistNode *)0x0;
  }
  return;
}



void * __stdcall PoolAlloc(uint len)

{
  HeapNode *node;
  void *result;
  
  node = (HeapNode *)DlistHead(_Pool_freeNodes);
  DlistRemove(_Pool_freeNodes,(DlistNode *)node);
  result = TurboAlloc_(len);
  node->heap = result;
  DlistInsert(_Pool_usedNodes,(DlistNode *)node,-1);
  return node->heap;
}



void __stdcall GenInitialPartIds(ushort count)

{
  short i;
  short definitionCount;
  
  definitionCount = _Level_partResource->definitionCount;
  _InitialPartIds_index = 0;
  DonkeyShuffle(count,_InitialPartIds);
  i = 0;
  if (0 < (short)count) {
    do {
      if (definitionCount <= _InitialPartIds[i]) {
        _InitialPartIds[i] = 1000;
      }
      i = i + 1;
    } while (i < (short)count);
  }
  return;
}



PartId NextInitialPartId(void)

{
  short i;
  
  i = _InitialPartIds_index;
  _InitialPartIds_index = _InitialPartIds_index + 1;
  return _InitialPartIds[i];
}



ushort GetCriticalSlotCount(void)

{
  return _Level_partResource->criticalSlotCount;
}



void Puzzles::SetVtableForCurrentCategory(void)

{
  if ((DAT_004697b6 != 0) && (DAT_004697b6 == 1)) {
    switch(currentCategory) {
    case BALANCE:
      SetVtableForGivenCategory(&vtableForBalance);
      break;
    case ELECTRICITY:
      SetVtableForGivenCategory(&vtableForElectricity);
      break;
    case ENERGY:
      SetVtableForGivenCategory(&vtableForEnergy);
      break;
    case FORCE:
      SetVtableForGivenCategory(&vtableForForce);
      break;
    case GEAR:
      SetVtableForGivenCategory(&vtableForGear);
      break;
    case JIGSAW:
      SetVtableForGivenCategory(&vtableForJigsaw);
      break;
    case MAGNET:
      SetVtableForGivenCategory(&vtableForMagnet);
      break;
    case SIMPLE_MACHINE:
      SetVtableForGivenCategory(&vtableForSimpleMachine);
      break;
    default:
      SetVtableForGivenCategory(&vtableForEnergy);
    }
  }
  return;
}



void __cdecl PickapuzzleMenu::OnClick(astruct *param_1)

{
  switch(*(undefined4 *)&param_1->field30_0x1e) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
                    // category radio buttons
    Puzzles::currentCategory = param_1->field30_0x1e;
    FUN_0043fb50();
    if (Puzzles::CATEGORY_LEN[(short)Puzzles::currentCategory] < Puzzles::currentPuzzle) {
      Puzzles::currentPuzzle = 1;
    }
    Draw();
    FUN_004465a5(0x1f4e,10,0);
    return;
  case 8:
                    // Do Puzzle button
    DAT_004697b6 = 1;
    FUN_004465a5(0x1f4e,10,0);
    return;
  case 9:
                    // Go Through button
    FUN_0044d87c(1);
    Puzzles::SetVtableForGivenCategory(&PTR_LAB_00461b2c);
    FUN_004465a5(0x1f4e,10,0);
    return;
  case 10:
                    // Go Back button
    FUN_0044d87c(0);
    Puzzles::SetVtableForGivenCategory(&PTR_LAB_00461b2c);
    FUN_004465a5(0x1f4e,10,0);
    return;
  case 0xb:
                    // up arrow
    Puzzles::currentPuzzle = Puzzles::currentPuzzle + 1;
    if (Puzzles::CATEGORY_LEN[(short)Puzzles::currentCategory] < Puzzles::currentPuzzle) {
      Puzzles::currentPuzzle = 1;
    }
    Draw();
    return;
  case 0xc:
                    // down arrow
    if ((Puzzles::currentPuzzle != 0) &&
       (Puzzles::currentPuzzle = Puzzles::currentPuzzle + -1, Puzzles::currentPuzzle < 1)) {
      Puzzles::currentPuzzle = Puzzles::CATEGORY_LEN[(short)Puzzles::currentCategory];
    }
    Draw();
  }
  return;
}



void PickapuzzleMenu::Draw(void)

{
  char currentPuzzleString [8];
  
  Nfnt::LoadWithCache(15000);
  FUN_00430de8(23,65,79,15);
  Sprintf_(currentPuzzleString,&_d,(int)Puzzles::currentPuzzle);
  ::Draw::String(15000,currentPuzzleString,26,77,0);
  FUN_00430abc(23,65,79,15);
  Nfnt::Unload(15000);
  return;
}



void Puzzles::ComputeCurrentPuzzle(void)

{
  int random;
  short count;
  int i;
  bool done;
  
  done = false;
  while (!done) {
    currentCategory = ComputeCurrentCategory();
    ComputeCandidatePuzzles(currentCategory);
    count = 3;
    if (candidatePuzzles[2] == -1) {
      count = 2;
    }
    if (candidatePuzzles[1] == -1) {
      count = count + -1;
    }
    if (candidatePuzzles[0] != -1) {
      if (count == 0) {
        i = 0;
      }
      else {
        random = Random();
        i = random % (int)count;
      }
      done = true;
    }
  }
  currentPuzzle = candidatePuzzles[(short)i] + 1;
  return;
}



undefined2 Puzzles::CheckEndgame(void)

{
  short i;
  undefined2 endgame;
  short incompletePuzzles;
  short category;
  short category1;
  
  incompletePuzzles = 0;
  category = 0;
  do {
    for (i = 0; i < CATEGORY_LEN[category]; i = i + 1) {
      if (_GameState->puzzles[category].completion[i] == 0) {
        incompletePuzzles = incompletePuzzles + 1;
      }
    }
    category = category + 1;
  } while (category < 8);
  if (incompletePuzzles < 7) {
                    // set all category modes to 3
    category1 = 0;
    do {
      _GameState->puzzles[category1].mode = ON_ENDGAME;
      category1 = category1 + 1;
    } while (category1 < 8);
    Puzzles::endgame = 1;
    endgame = 1;
  }
  else {
    endgame = 0;
  }
  return endgame;
}



short Puzzles::ComputeCurrentCategory(void)

{
  short category;
  int i;
  short categories_len;
  short result;
  short unknown [32762];
  short categories [8];
  
  result = 0;
  categories_len = 0;
                    // build list of candidate categories
  category = 0;
  do {
    if ((_GameState->puzzles[category].mode == ON) ||
       (_GameState->puzzles[category].mode == ON_ENDGAME)) {
      categories[categories_len] = category;
      categories_len = categories_len + 1;
    }
    category = category + 1;
  } while (category < 8);
  if (categories_len == 0) {
    ThrowChosenCategoriesExhausted();
  }
  else {
    if (categories_len == 0) {
                    // unreachable
      i = 0;
    }
    else {
      i = Random();
      i = i % (int)categories_len;
    }
    result = categories[i];
  }
  return result;
}



void __cdecl Puzzles::ComputeCandidatePuzzles(short category)

{
  short endgameDword;
  short puzzle;
  short i;
  short endgame;
  int random;
  short i_;
  short categoryLen;
  
                    // let puzzleCandidates = {-1, -1, -1}
  i = 0;
  do {
    candidatePuzzles[i] = 0xffff;
    i = i + 1;
  } while (i < 3);
  categoryLen = CATEGORY_LEN[category];
  endgame = CheckEndgame();
  if (endgame == 0) {
                    // not endgame
    i_ = 0;
    puzzle = 0;
                    // pick first three unsolved puzzles in category
    if (0 < categoryLen) {
      do {
                    // if puzzle is not yet solved
        if (_GameState->puzzles[category].completion[puzzle] == 0) {
          candidatePuzzles[i_] = puzzle;
          i_ = i_ + 1;
        }
      } while ((i_ < 3) && (puzzle = puzzle + 1, puzzle < categoryLen));
    }
  }
  else if (categoryLen == 0) {
                    // unreachable
    candidatePuzzles[0] = 0;
  }
  else {
                    // endgame; pick one random puzzle in category
    random = Random();
    candidatePuzzles[0] = (undefined2)(random % (int)categoryLen);
  }
  return;
}



void Puzzles::TurnAllOffCategoriesBackOn(void)

{
  short category;
  
  category = 0;
  do {
    if (_GameState->puzzles[category].mode == OFF) {
      _GameState->puzzles[category].mode = ON;
    }
    category = category + 1;
  } while (category < 8);
  return;
}



Fourcc __cdecl Resource::ResolveFourcc(char *fourccString)

{
  short i;
  Fourcc in_ECX;
  char *presult;
  Fourcc result;
  
                    // accept raw uint16 packed in pointer
  if (((uint)fourccString & 0xffff0000) == 0) {
    result = (uint)fourccString & 0xffff;
  }
  else {
    presult = (char *)&result;
    i = 0;
    result = in_ECX;
    do {
      *presult = *fourccString;
      fourccString = fourccString + 1;
      presult = (char *)((int)presult + 1);
      i = i + 1;
    } while (i < 4);
  }
  return result;
}



void * __stdcall Resource::Load(ushort id,LPCSTR fourcc)

{
  void *result;
  
  result = Load(id,fourcc);
  return result;
}



void __stdcall Puzzles::SetVtableForGivenCategory(undefined4 param_1)

{
  *(undefined4 *)(DAT_0046a35c + DAT_0046336c * 4) = param_1;
  return;
}



Nfnt * __stdcall Nfnt::GetFromCache(short resourceId)

{
  Nfnt *current;
  
  if (resourceId == -1) {
    resourceId = currentFont;
  }
  for (current = (Nfnt *)DlistHead(cache);
      (current != (Nfnt *)0x0 && (resourceId != current->resourceId));
      current = (Nfnt *)DlistNext(&current->node)) {
  }
  return current;
}



short __stdcall SetCurrentColor(short color)

{
  short old;
  
  old = _CurrentColor;
  _CurrentColor = color;
  _CurrentColorClamped = ClampColorIndex_(color);
  return old;
}



void __stdcall Draw::StringWithCurrentFontAndColor(short x,short y,char *text)

{
  short baselineY_;
  undefined2 color;
  
  color = _CurrentColorClamped;
  baselineY_ = GetFontBaselineY_(Nfnt::currentFont);
  String(Nfnt::currentFont,text,x,baselineY_ + y,color);
  return;
}



void * __stdcall Memcpy(void *dest,void *src,uint len)

{
  uint i;
  void *current;
  
  current = dest;
                    // WARNING: Load size is inaccurate
  for (i = len >> 2; i != 0; i = i - 1) {
    *(undefined4 *)current = *src;
    src = (undefined4 *)((int)src + 4);
    current = (undefined4 *)((int)current + 4);
  }
                    // WARNING: Load size is inaccurate
  for (i = len & 3; i != 0; i = i - 1) {
    *(undefined *)current = *src;
    src = (undefined4 *)((int)src + 1);
    current = (void *)((int)current + 1);
  }
  return dest;
}



void * __stdcall Memset(void *result,byte value,uint len)

{
  uint i;
  void *current;
  
  current = result;
  for (i = len >> 2; i != 0; i = i - 1) {
    *(uint *)current = CONCAT22(CONCAT11(value,value),CONCAT11(value,value));
    current = (undefined4 *)((int)current + 4);
  }
  for (i = len & 3; i != 0; i = i - 1) {
    *(byte *)current = value;
    current = (void *)((int)current + 1);
  }
  return result;
}



char * __stdcall Strcpy(char *dest,char *src)

{
  uint len;
  uint uVar1;
  char *pSrc;
  void *pDest;
  char c;
  
  len = 0xffffffff;
  pSrc = src;
  do {
    if (len == 0) break;
    len = len - 1;
    c = *pSrc;
    pSrc = pSrc + 1;
  } while (c != '\0');
  pDest = dest;
  for (uVar1 = ~len >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined4 *)pDest = *(undefined4 *)src;
    src = (char *)((int)src + 4);
    pDest = (undefined4 *)((int)pDest + 4);
  }
  for (len = ~len & 3; len != 0; len = len - 1) {
    *(char *)pDest = *src;
    src = (char *)((int)src + 1);
    pDest = (void *)((int)pDest + 1);
  }
  return dest;
}



int __stdcall Sprintf_(char *dest,char *format,...)

{
  int iVar1;
  undefined in_CL;
  undefined in_DL;
  
  iVar1 = Sprintf0((char)dest,in_DL,in_CL,FUN_0045226c,dest,format,&stack0x0000000c);
  return iVar1;
}



int __stdcall Sprintf_(char *dest,char *format,...)

{
  int iVar1;
  undefined in_CL;
  undefined in_DL;
  
  *dest = '\0';
  iVar1 = Sprintf0((char)&dest,in_DL,in_CL,&LAB_00452a4c,&dest,format,&stack0x0000000c);
  return iVar1;
}



int __stdcall Sprintf_(char *dest,char *format,...)

{
  int iVar1;
  undefined in_CL;
  undefined in_DL;
  undefined4 in_stack_0000000c;
  
  *dest = '\0';
  iVar1 = Sprintf0((char)&dest,in_DL,in_CL,&LAB_00452a4c,&dest,format,in_stack_0000000c);
  return iVar1;
}



uint __cdecl ToUpper(uint c)

{
  uint result;
  
  if (c == 0xffffffff) {
    return 0xffffffff;
  }
  result = c & 0xff;
  if ((_AsciiProperties[result] & LOWER) != 0) {
    return result - 0x20;
  }
  return result;
}



int __cdecl Atoi(char *input)

{
  char c;
  int result;
  char *input_;
  bool negative;
  
                    // skip whitespace
  result = 0;
  do {
    input_ = input;
    c = *input_;
    input = input_ + 1;
  } while ((_AsciiProperties[c] & WHITESPACE) != 0);
                    // parse sign
  if ((c == '+') || (c == '-')) {
    negative = c == '-';
    c = *input;
    input = input_ + 2;
  }
  else {
    negative = false;
  }
                    // parse digits
  while (('/' < c && (c < ':'))) {
    result = result * 10 + (int)c + -0x30;
    c = *input;
    input = input + 1;
  }
  if (negative) {
    result = -result;
  }
  return result;
}



int Random(void)

{
  uint uVar1;
  
  if (_Random_q != 0) {
    _Random_q = _Random_q * 0x4e35;
  }
  uVar1 = (uint)((ulonglong)_Random_p * 0x4e35);
  _Random_q = (int)((ulonglong)_Random_p * 0x4e35 >> 0x20) + _Random_p * 0x15a4 + _Random_q +
              (uint)(0xfffffffe < uVar1);
  _Random_p = uVar1 + 1;
  return _Random_q & 0x7fffffff;
}



void __stdcall WinapiExitProcess(UINT exitCode)

{
                    // WARNING: Subroutine does not return
  ExitProcess(exitCode);
}


