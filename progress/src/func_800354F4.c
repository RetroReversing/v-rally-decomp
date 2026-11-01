typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Obj { u8 pad[0x118]; Vec3 pos; u8 pad2[0x178 - 0x124]; void *p178; } Obj;
typedef struct Mgr { u8 pad[0xE]; u16 mode; } Mgr;
typedef struct Race {
  u8 pad[4];
  u16 type;
  u8 pad6[6];
  s32 ids[3];
  Vec3 pos[2];
  s32 x30;
  void (*fn)(s32, s32, u8);
} Race;
extern Mgr *D_800C35A0;
extern u8 D_800C34D0;
extern u8 D_800C7926;
extern Obj *D_800C7F84;
extern Race *D_800C811C;
s32 func_800056FC(void *);
void func_800376C8(s32, Obj *);
Obj *func_8004240C(s32);

void func_800354F4(void)
{
  u16 mode;
  u8 i;
  u8 count;
  s32 k;
  s32 j;
  s32 r;
  Obj *obj;

  mode = D_800C35A0->mode;
  if (mode == 2)
    return;
  count = mode;
  for (i = 1; i <= count; i++)
  {
    if (D_800C34D0 != 0)
      continue;
    switch (D_800C811C->type)
    {
      case 0:
        if (D_800C7926 == 0)
        {
          k = (i - 1) * 2;
          obj = func_8004240C(k + 3);
          D_800C7F84 = obj;
          r = func_800056FC(obj->p178);
          func_800376C8(r, func_8004240C(k + 2));
        }
        break;
      case 3:
      case 4:
        j = i - 1;
        obj = func_8004240C(j * 2 + 2);
        D_800C7F84 = obj;
        r = func_800056FC(obj->p178);
        D_800C811C->fn(*(s32 *)((u8 *)D_800C811C - -(i * 4) + 0xC), r, i - 1);
        D_800C811C->pos[j].x = D_800C7F84->pos.x;
        D_800C811C->pos[j].y = D_800C7F84->pos.y;
        D_800C811C->pos[j].z = D_800C7F84->pos.z;
        break;
    }
  }
}
