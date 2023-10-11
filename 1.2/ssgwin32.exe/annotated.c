#include "annotated.h"



char * __stdcall GetWinapiStringAlloc(UINT id)

{
  int copied;
  char *result;
  CHAR scratch [256];
  
  copied = LoadStringA(_Module,id,scratch,0xfe);
  if (copied == 0) {
    Sprintf2(scratch,s_Cannot_Load_Resource___d___missi_00460112,id);
    MessageBoxA((HWND)0x0,scratch,(LPCSTR)&lpCaption_0046013e,0x10);
    DoSomethingThenExit_(1);
  }
  result = (char *)TurboAlloc_(0xff);
  if (result == (char *)0x0) {
    Sprintf2(scratch,s_Cannot_Load_Resource___d___out_o_00460142,id);
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
    Sprintf2(scratch,s_Cannot_Load_Resource___d___missi_00460170,id);
    MessageBoxA((HWND)0x0,scratch,(LPCSTR)&lpCaption_0046019c,0x10);
    DoSomethingThenExit_(1);
  }
  Strcpy(result,scratch);
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
  _Area = (Area *)GetWinapiResource_(_LevelAreaResourceIds[_GameState->level],&_AREA);
  _RoomCount = _Area->roomCount;
  room = _Area->rooms;
  InitEntities();
  _RoomInitialPartsCounts = (ushort *)GetWinapiResource_(_GameState->level + 0x582,_pINTS);
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
          partNode = (EntityNode *)DlistNext(partNode);
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



int __stdcall CountCompletedPuzzles(PuzzleCategory category)

{
  short i;
  int result;
  
  result = 0;
  i = 0;
  do {
    if (_GameState->puzzles[category].completion[i] != 0) {
      result = result + 1;
    }
    i = i + 1;
  } while (i < 0x2b);
  return result;
}



void __stdcall ShowAlertMessage(char *param_1,undefined param_2)

{
  char *lpCaption;
  char text [500];
  
  Sprintf3(text,param_1,&param_2);
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
  FUN_0044b38d(&PTR_LAB_00461b2c);
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



undefined4 __stdcall DlistHead(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  return *param_1;
}



undefined4 __stdcall DlistNext(undefined4 *param_1)

{
  return *param_1;
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
      _GameState->puzzles[category1].mode_0_1_2_3_4_ = 3;
      category1 = category1 + 1;
    } while (category1 < 8);
    _Endgame = 1;
    endgame = 1;
  }
  else {
    endgame = 0;
  }
  return endgame;
}



short Puzzles::ComputeCandidateCategory(void)

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
                    // if category is on (normal) or on (endgame)
    if ((_GameState->puzzles[category].mode_0_1_2_3_4_ == 0) ||
       (_GameState->puzzles[category].mode_0_1_2_3_4_ == 3)) {
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
    if (_GameState->puzzles[category].mode_0_1_2_3_4_ == 1) {
      _GameState->puzzles[category].mode_0_1_2_3_4_ = 0;
    }
    category = category + 1;
  } while (category < 8);
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



int __stdcall Sprintf1(char *dest,char *format,...)

{
  int iVar1;
  undefined in_CL;
  undefined in_DL;
  
  iVar1 = Sprintf0((char)dest,in_DL,in_CL,FUN_0045226c,dest,format,&stack0x0000000c);
  return iVar1;
}



int __stdcall Sprintf2(char *dest,char *format,...)

{
  int iVar1;
  undefined in_CL;
  undefined in_DL;
  
  *dest = '\0';
  iVar1 = Sprintf0((char)&dest,in_DL,in_CL,&LAB_00452a4c,&dest,format,&stack0x0000000c);
  return iVar1;
}



int __stdcall Sprintf3(char *dest,char *format,...)

{
  int iVar1;
  undefined in_CL;
  undefined in_DL;
  undefined4 in_stack_0000000c;
  
  *dest = '\0';
  iVar1 = Sprintf0((char)&dest,in_DL,in_CL,&LAB_00452a4c,&dest,format,in_stack_0000000c);
  return iVar1;
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


