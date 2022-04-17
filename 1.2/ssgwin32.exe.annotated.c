#include "ssgwin32.exe.annotated.h"



EntityNode * NextAvailableEntityNode(void)

{
  EntityNode *node;
  
  for (node = _Entities; node->available != 1; node = node + 1) {
  }
  return node;
}



ushort __stdcall PlacePartEntity(Area *area,short count,PartId partId)

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
  EntityNode *part;
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
                    // is area obverse?
  if ((area->flags & 1) == 0) {
                    // areas #4 through #15, reverse side (big sprites), three floors
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
                    // areas #1 through #3, obverse side (small sprites), six floors
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
        partCount = area->partEntityCount;
        part = (EntityNode *)DlistHead(area->partEntities);
        for (j = 0; (!bad && (j < partCount)); j = j + 1) {
          collision = CheckCollision((Rect16 *)&rect,(Rect16 *)&part->inner);
          if ((short)collision != 0) {
            bad = true;
          }
          part = (EntityNode *)DlistNext(part);
        }
                    // 2. avoid intersecting structural entities of type > 3 (e.g. gaps, doors)
        entity = (OtherEntity *)area->structuralEntityGroups[0];
        structuralCount = area->structuralEntityCounts[0];
        for (j = 0; (!bad && (j < structuralCount)); j = j + 1) {
          if ((3 < (entity->base).type) &&
             (collision = CheckCollision((Rect16 *)&rect,(Rect16 *)entity), (short)collision != 0))
          {
            bad = true;
          }
          entity = entity + 1;
        }
                    // 3. avoid intersecting ladder entities (vents, paddles, trampolines)
        ladderCount = area->ladderEntityCounts[0];
        ladder = (LadderEntity *)area->ladderEntityGroups[0];
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
      area->partEntityCount = area->partEntityCount + 1;
      entityNode->available = 0;
      DlistInsert((Dlist *)area->partEntities,&entityNode->node,-1);
      i = i + 1;
    } while (i < count);
  }
  return result;
}



uint __stdcall CheckCollision(Rect16 *p,Rect16 *q)

{
  uint uVar1;
  short pRight;
  short pBottom;
  short qBottom;
  short qRight;
  short pLeft;
  short pTop;
  short qLeft;
  short qTop;
  
  uVar1 = 0;
  pLeft = p->x;
  pRight = pLeft + p->w;
  pTop = p->y;
  pBottom = pTop + p->h;
  qLeft = q->x;
  qRight = qLeft + q->w;
  qTop = q->y;
  qBottom = qTop + q->h;
  if ((((pLeft < qRight) && (qLeft < pRight)) && (pTop < qBottom)) && (qTop < pBottom)) {
    uVar1 = (uint)(pLeft < qLeft);
    if (qRight < pRight) {
      uVar1 = uVar1 | 2;
    }
    if (pTop < qTop) {
      uVar1 = uVar1 | 4;
    }
    if (qBottom < pBottom) {
      uVar1 = uVar1 | 8;
    }
    if ((short)uVar1 == 0) {
      uVar1 = 0xf;
    }
  }
  return uVar1;
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



void __stdcall GenInitialPartIds(uint count)

{
  short i;
  short len;
  short definitionCount;
  
  definitionCount = _Level_partResource->definitionCount;
  _InitialPartIds_index = 0;
  len = (short)count;
  DonkeyShuffle(len,_InitialPartIds);
  i = 0;
  if (0 < len) {
    do {
      if (definitionCount <= _InitialPartIds[i]) {
        _InitialPartIds[i] = 1000;
      }
      i = i + 1;
    } while (i < len);
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


