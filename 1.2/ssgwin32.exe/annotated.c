#include "annotated.h"



void __stdcall TryWinapiLoadStringIntoBuffer(char *result,UINT id)

{
  int iVar1;
  CHAR error [256];
  
  iVar1 = LoadStringA(hInstance_0046485c,id,error,0xfe);
  if (iVar1 == 0) {
    Sprintf2(error,s_Cannot_Load_Resource___d___missi_00460170,id);
    MessageBoxA((HWND)0x0,error,(LPCSTR)&lpCaption_0046019c,0x10);
    DoSomethingThenExit_(1);
  }
  Strcpy(result,error);
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
  short building;
  short count;
  ushort partsCount;
  short roomIndex;
  
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
  for (roomIndex = 0; roomIndex < _RoomCount; roomIndex = roomIndex + 1) {
    _Rooms[roomIndex] = room;
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
    if (roomIndex != 0) {
      list = DlistNew();
      room->partEntities = list;
      partsCount = _RoomInitialPartsCounts[roomIndex];
      room->partEntityCount = partsCount;
      if (partsCount != 0) {
        room->partEntityCount = 0;
        PlacePartEntity(room,_RoomInitialPartsCounts[roomIndex],-1);
      }
    }
    room = (Room *)current;
  }
  _RoomIndex = 0;
  return;
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
  ushort *pSpriteId;
  
  locationIndex = 0;
  result = 1;
                    // is room obverse?
  if ((room->flags & 1) == 0) {
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
          pSpriteId = &(entity->base).spriteId;
          *pSpriteId = *pSpriteId + 1;
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



void __stdcall ShowAlertMessage(char *param_1,undefined param_2)

{
  char *lpCaption;
  char text [500];
  
  Sprintf3(text,param_1,&param_2);
                    // 20102 = "Alert"
  lpCaption = TryWinapiLoadString(20102);
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


