typedef struct Node
{
  u8 pad00[8];
  s16 level;
  u16 flags;
  u8 pad0C[0x40];
  s32 dataOffset;
  u8 pad50[8];
  struct Node *nextA;
  struct Node *nextB;
  u8 pad60[0x28];
  u16 count;
  u16 stride;
  u16 pieceType;
} Node;
s32 func_8004E5B0(Node *, u16 *);
s32 func_8004ECA8(u16 *, u16 *);
void func_8004ED08(Node *, s32, u16, u16, s32, s32, s32);
extern u8 D_800ADFE1;

/* Walks the ring of track segments from car, deciding for each whether to emit
 * a path point (func_8004ED08) and advancing to the next segment. */
void func_8004EF40(Node *car)
{
  u16 curInfo[4];
  u16 nextInfo[4];
  s32 one;
  s32 six;
  u16 *nextInfoPtr;
  s32 special;
  s32 emit;
  s32 mode;
  s32 skipped;
  s32 dist;
  Node *seg;
  Node *origin;
  Node *node;
  Node *nextNode;
  Node *following;
  Node *link;
  Node *advance;
  u16 segType;
  u16 originType;
  u16 originFlags;
  u16 tmpA0;
  s32 tmpA1;
  skipped = 0;

  if (car->nextA != 0)
  {
    node = car;
  }
  else
  {
    node = car->nextB;
  }
  nextInfoPtr = nextInfo;
  one = 1;
  six = 6;
  do {
  seg = node->nextA;

  special = func_8004E5B0(node, &curInfo[0]);
  mode = 0;
  origin = node;
  if (curInfo[1] != 0)
  {
    if (!(special & 0xFF))
    {
      nextNode = node->nextB;
      if (nextNode != NULL)
      {
        func_8004E5B0(nextNode, nextInfoPtr);
        if (func_8004ECA8(&curInfo[0], nextInfoPtr) != 0)
        {
          segType = node->pieceType;
          mode = 1;
          if ((segType != 0x1C) & (segType != 0x14))
          {
            goto block_21;
          }
          {
            if (segType == 0x1C)
            {
              curInfo[0] = one;
              nextInfo[0] = one;
              curInfo[1] = 2;
              nextInfo[1] = one;
            }
            else
            {
              curInfo[0] = 0;
              nextInfo[0] = 0;
              mode = 5;
              if (node->flags & 0x100)
              {
                curInfo[1] = one;
                nextInfo[1] = 2;
              }
              else
              {
                curInfo[1] = 2;
                nextInfo[1] = one;
              }
            }
          }
        }
        else
          if (((curInfo[3] == 0) && (nextInfo[3] != 0)) && (curInfo[1] == nextInfo[1]))
        {
          if (curInfo[0] != 2)
          {
            curInfo[0] = curInfo[0] + 1;
          }
          block_21:
          link = node->nextB;

          if (link != NULL)
          {
            node = link;
          }
        }
      }
    }
    if (skipped != 0)
    {
      if ((D_800ADFE1 != 0) || (seg->level >= 2))
      {
        seg = seg->nextA;
      }
      dist = ((u32)(seg->count - 4) * seg->stride) + seg->dataOffset;
    }
    else if (curInfo[3] == 0)
    {
      dist = seg->dataOffset + (((seg->count / 3) & 0xFFFF) * seg->stride);
    }
    else
    {
      dist = ((u32)(seg->count >> 2) * seg->stride) + seg->dataOffset;
    }
    following = origin->nextB;
    if (following != NULL)
    {
      emit = 1;
      if (curInfo[0] == 0)
      {
        originType = origin->pieceType;
        if (((originType == following->pieceType) & (mode != 0)) && ((((u32) (originType - 0x1D)) < 2U) || (((u32) (originType - 0x12)) < 2U)))
        {
          emit = 0;
        }
      }
      if (emit != 0)
      {
        if (origin->flags & 0x20)
        {
          mode = 2;
          nextInfo[1] = six;
          nextInfo[0] = six;
        }
        originFlags = origin->flags;
        if (!(originFlags & 0x10))
        {
          if (originFlags & 0x80)
          {
            tmpA1 = curInfo[1];
            tmpA0 = curInfo[0];
            mode = 2;
            curInfo[1] = 9;
            curInfo[0] = six;
            nextInfo[1] = tmpA1;
            nextInfo[0] = tmpA0;
          }
        }
        func_8004ED08(seg, mode, curInfo[1], curInfo[0], (s32) nextInfo[1], (s32) nextInfo[0], dist);
        skipped = 0;
      }
    }
  }
  else
  {
    skipped += 1;
  }
  advance = node->nextB;
  if (advance != NULL)
  {
    node = advance;
  }
  } while ((node != car) && (node->nextB != 0));
}
