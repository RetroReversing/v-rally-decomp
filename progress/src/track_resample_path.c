typedef struct 
{
  u16 pad0;
  u16 pad2;
  s16 h;
  u16 x;
  u16 y;
  u16 z;
} PEnt;
typedef struct 
{
  u8 pad[0xE];
  u8 keyB;
  u8 keyA;
  u8 pad10[4];
  u8 startVal;
  u8 valA;
  u8 valB;
  u8 endVal;
  u8 pad18[4];
  PEnt *tbl;
} PDef;
typedef struct 
{
  u8 pad[0x4C];
  s32 index4C;
  u8 pad50[4];
  u8 *points54;
  u8 pad58[0x20];
  PDef *def;
  u8 pad7C[0xC];
  u16 n;
  u16 stride8A;
} PObj;
extern void func_8002FFA4(void *, s32, s16, void *);
extern s32 func_8003035C(void *, s32, void *);
static inline s32 lerp(s32 to, s32 from, s32 num, s32 den)
{
  s32 q = (((s16) (to - from)) * num) / den;
  return q + from;
}
/* Fills the per-point table of a track path: linear ramps between the keyed
 * points A and B, then holds and ramps out to the last point. */
void track_resample_path(PObj *obj)
{
  u16 ptA[3];
  u16 ptB[3];
  u16 cur[3];
  s32 keyA;
  s32 keyB;
  s32 valA;
  s32 valB;
  s32 startVal;
  s32 endVal;
  s32 tmp;
  u16 idx;
  s32 span;
  keyA = obj->def->keyA;
  keyB = obj->def->keyB;
  valA = obj->def->valA;
  valB = obj->def->valB;
  startVal = obj->def->startVal;
  endVal = obj->def->endVal;
  idx = 0;
  if (((s32) keyB) < ((s32) keyA))
  {
    tmp = keyA;
    keyA = keyB;
    keyB = tmp;
    idx = valA;
    valA = valB;
    valB = idx;
  }
  if (keyA != 0)
  {
    func_8002FFA4(obj, 0, startVal, &ptA);
    func_8002FFA4(obj, keyA, valA, &ptB);
    for (idx = 0; idx < keyA; idx++)
    {
      cur[0] = lerp(ptB[0], ptA[0], idx, keyA);
      cur[1] = lerp(ptB[1], ptA[1], idx, keyA);
      cur[2] = lerp(ptB[2], ptA[2], idx, keyA);
      obj->def->tbl[idx].x = cur[0];
      obj->def->tbl[idx].y = cur[1];
      obj->def->tbl[idx].z = cur[2];
      obj->def->tbl[idx].h = (s16) func_8003035C(obj, idx, &cur);
    }

  }
  else
  {
    valA = startVal;
  }
  if (keyB != 0)
  {
    func_8002FFA4(obj, keyA, valA, &ptA);
    func_8002FFA4(obj, keyB, (s16) valB, &ptB);
    if (keyA == keyB)
    {
      obj->def->tbl[idx].x = ptB[0];
      obj->def->tbl[idx].y = ptB[1];
      obj->def->tbl[idx].z = ptB[2];
      obj->def->tbl[idx].h = (s16) func_8003035C(obj, keyB, &ptB);
    }
    else
    {
      span = keyB - keyA;
      for (idx = keyA; idx < keyB; idx++)
      {
        cur[0] = lerp(ptB[0], ptA[0], idx - keyA, span);
        cur[1] = lerp(ptB[1], ptA[1], idx - keyA, span);
        cur[2] = lerp(ptB[2], ptA[2], idx - keyA, span);
        obj->def->tbl[idx].x = cur[0];
        obj->def->tbl[idx].y = cur[1];
        obj->def->tbl[idx].z = cur[2];
        obj->def->tbl[idx].h = (s16) func_8003035C(obj, idx, &cur);
      }

    }
  }
  else
  {
    valB = valA;
    keyB = keyA;
  }
  func_8002FFA4(obj, keyB, (s16) valB, &ptA);
  func_8002FFA4(obj, obj->n - 1, endVal, &ptB);
  if (keyB == (obj->n - 1))
  {
    obj->def->tbl[idx].x = ptB[0];
    obj->def->tbl[idx].y = ptB[1];
    obj->def->tbl[idx].z = ptB[2];
    obj->def->tbl[idx].h = endVal * 10;
    return;
  }
  idx = keyB;
  {
  s32 nextKey = keyB + 1;
  for (; idx <= (obj->n - 1); idx++)
  {
    cur[0] = ptB[0] - ptA[0];
    cur[0] = lerp(cur[0], 0, idx - keyB, obj->n - nextKey);
    cur[0] += ptA[0];
    cur[1] = ptB[1] - ptA[1];
    cur[1] = lerp(cur[1], 0, idx - keyB, obj->n - nextKey);
    cur[1] += ptA[1];
    cur[2] = ptB[2] - ptA[2];
    cur[2] = lerp(cur[2], 0, idx - keyB, obj->n - nextKey);
    cur[2] += ptA[2];
    obj->def->tbl[idx].x = cur[0];
    obj->def->tbl[idx].y = cur[1];
    obj->def->tbl[idx].z = cur[2];
    obj->def->tbl[idx].h = (s16) func_8003035C(obj, idx, &cur);
  }
  }
}
