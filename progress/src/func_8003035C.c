typedef struct { u16 x; u16 y; u16 z; } V303;
typedef struct { s16 x; s16 y; s16 z; s16 pad; } SV303;
typedef struct
{
  u8 pad[0x4C];
  s32 base;
  u32 pad50;
  V303 *table;
  u8 pad58[0x32];
  u16 stride;
} O303;
s32 func_8002D2A0(s32);

/* Returns where pos lies along the track row of obj, as a value in 0..1000
 * (500 is on the row's point). The neighbouring row on the side pos is on is
 * used for the segment; the distance ratio gives the position within it. */
s32 func_8003035C(void *obj, s32 row, void *pos)
{
  SV303 seg;
  SV303 toPos;
  SV303 prevEdge;
  s32 idx;
  s32 dist;
  s32 distPos;
  idx = row * (*(u16 *)((u8 *)obj + 0x8A)) + (*(s32 *)((u8 *)obj + 0x4C));
  prevEdge.x = (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx - 2) * 6 + 0)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 0));
  prevEdge.z = (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx - 2) * 6 + 4)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 4));
  seg.x = (*(u16 *)((u8 *)pos + 0)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 0));
  seg.z = (*(u16 *)((u8 *)pos + 4)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 4));
  if (prevEdge.x * seg.x + prevEdge.z * seg.z > 0)
  {
    seg.x = (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx - 2) * 6 + 0)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 0));
    seg.z = (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx - 2) * 6 + 4)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 4));
    toPos.x = (*(u16 *)((u8 *)pos + 0)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 0));
    toPos.z = (*(u16 *)((u8 *)pos + 4)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 4));
    dist = func_8002D2A0(seg.x * seg.x + seg.z * seg.z);
    distPos = func_8002D2A0(toPos.x * toPos.x + toPos.z * toPos.z);
    dist = distPos * 1000 / dist;
    dist = 500 - dist / 2;
  }
  else
  {
    seg.x = (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx + 2) * 6 + 0)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 0));
    seg.z = (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx + 2) * 6 + 4)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 4));
    toPos.x = (*(u16 *)((u8 *)pos + 0)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 0));
    toPos.z = (*(u16 *)((u8 *)pos + 4)) - (*(u16 *)(*(u8 **)((u8 *)obj + 0x54) + (idx) * 6 + 4));
    dist = func_8002D2A0(seg.x * seg.x + seg.z * seg.z);
    distPos = func_8002D2A0(toPos.x * toPos.x + toPos.z * toPos.z);
    dist = distPos * 1000 / dist;
    dist = dist / 2 + 500;
  }
  return dist;
}
