typedef struct { s32 x, y, z; } Vec3S32;
typedef struct { s16 x, y, z; } Vec3S16;
typedef struct { Vec3S32 v; s32 pad[2]; } Rec;
typedef struct { u8 pad[0x10]; Rec c[12]; Rec a[12]; Rec b[12]; } RecSet;
void *func_80028E24(s32, Vec3S32 *);
void func_80028E94(void *, Vec3S16 *, u32);
void func_8002C044(void *);
void func_8002D8A0(s32, Rec *, Rec *);
extern s32 D_8009C230;

static inline void vec_add(Vec3S32 *a, Vec3S32 *b, Vec3S32 *d)
{
  d->x = a->x + b->x;
  d->y = a->y + b->y;
  d->z = a->z + b->z;
}

void func_8002BD40(u8 *arg0)
{
  Vec3S32 sp10;
  Vec3S16 sp20;
  u32 i;
  u8 *t;

  *(s32 *)(*(u8 **)(arg0 + 0x8C) + 0x334) = 0;
  *(s32 *)(*(u8 **)(arg0 + 0x8C) + 0x100) = 0;
  for (i = 0; i < 12; i++)
  {
    func_8002D8A0(*(s32 *)(arg0 + 0x5C) + 0x40, &(*(RecSet **)(arg0 + 0x80))->c[i], &(*(RecSet **)(arg0 + 0x80))->a[i]);
    vec_add(&(*(RecSet **)(arg0 + 0x80))->a[i].v, (Vec3S32 *)(*(u8 **)(arg0 + 0x58) + 0xC), &(*(RecSet **)(arg0 + 0x80))->b[i].v);
    sp10 = *(&(*(RecSet **)(arg0 + 0x80))->b[i].v);
    t = func_80028E24(D_8009C230, &sp10);
    *(u8 **)(*(u8 **)(arg0 + 0x8C) + i * 4) = t;
    sp20.x = sp10.x - *(s32 *)(t + 0x24);
    sp20.y = sp10.y - *(s32 *)(t + 0x28);
    sp20.z = sp10.z - *(s32 *)(t + 0x2C);
    func_80028E94(arg0, &sp20, i);
  }
  func_8002C044(arg0);
}
