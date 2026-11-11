extern s32 D_800A0264[];
s32 func_8002E778(s32 *, s32 *);

typedef struct {
  s32 x;
  s32 y;
  s32 z;
} S_vec3;

/* Checks whether the target (arg1's +0x58 position) is within the entity's range (ent[3]) on
 * the XZ plane. If it is, calls the entity's handler from D_800A0264 with the distance. */
void func_800469E0(s32 **arg0, s32 *arg1)
{
  S_vec3 offset;
  S_vec3 dir;
  u32 dist;
  S_vec3 *targetPos;
  s32 *ent;

  if (*(s32 *)(*(s32 **)((u8 *)arg1 + 0x48)) < 4)
  {
    targetPos = *(S_vec3 **)((u8 *)arg1 + 0x58);
    ent = *arg0;
    offset = *(S_vec3 *)((u8 *)targetPos + 0xC);
    dir.x = offset.x - ent[0];
    dir.y = 0;
    dir.z = offset.z - ent[2];
    func_8002E778((s32 *)&dir, (s32 *)&dir);
    dist = dir.x + dir.z;
    if (dist < (u32)ent[3])
    {
      ((void (*)(s32 *, s32, s32 *, u32 *))D_800A0264[*(u16 *)((u8 *)ent + 0x14)])((s32 *)((u8 *)ent + 0x1C), *(u16 *)((u8 *)ent + 0x16), arg1, &dist);
    }
  }
}
