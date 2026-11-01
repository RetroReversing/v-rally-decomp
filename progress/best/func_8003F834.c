#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
extern void *D_800C35A0;
extern void *D_800C7F84;
extern void *func_8004240C(s32);
extern void *func_80040260(s32, s16, s16, s32, void *, s32);
extern void *func_80034FF0(s32, s32);
extern void func_8003F11C(void);
extern void func_8003F34C(void);
extern void func_8003F2CC(void);
typedef struct { unsigned char pad[164]; void * value; } __repair_field_A4;
typedef struct { unsigned char pad[168]; void * value; } __repair_field_A8;
void func_8003F834(s32 arg0, s32 arg1)
{
  u32 i;
  u32 j;
  u32 n;
  u32 mode;
  u32 w;
  u16 x;
  s16 y;
  void *obj;
  u8 *new_var;
  void *rec;
  void *p;
  void *screen;
  u16 *q;
  screen = D_800C35A0;
  mode = *((u16 *) (((u8 *) screen) + 0x1E));
  if ((mode != 0) & (mode != 7))
  {
    n = *((u16 *) (((u8 *) screen) + 0xE));
    if (n)
    {
      i = 1;
      j = (i << 1) - 1;
      do
      {
        obj = func_8004240C(j);
        rec = *((void **) (((u8 *) obj) + 0x178));
        q = (u16 *) (((u8 *) rec) + 8);
        w = *((u16 *) (((u8 *) rec) + 0xC));
        x = ((s16) w) / 2;
        y = (*((s16 *) (((u8 *) rec) + 0xE))) / 4;
        screen = D_800C35A0;
        if (((*((u16 *) (((u8 *) screen) + 0xE))) == 2) && ((*((u16 *) (((u8 *) screen) + 0x12))) & 1))
        {
          y += 8;
        }
        p = func_80040260(arg0, (s16) (q[0] + x), (s16) (q[1] + y), 15, func_8003F11C, 1);
        ((__repair_field_A4 *)p)->value = func_80034FF0(arg1 + 0x4C, 0);
        ((__repair_field_A8 *)p)->value = obj;
        screen = D_800C7F84;
        rec = *((void **) (((u8 *) screen) + 0x178));
        y = (*((s16 *) (((u8 *) rec) + 0xE))) / 3;
        w = *((u16 *) (((u8 *) rec) + 0xC));
        x = ((u32) (((s16) w) + (w >> 15))) >> 1;
        screen = D_800C35A0;
        if (((*((u16 *) (((u8 *) screen) + 0xE))) == 2) && ((*((u16 *) (((u8 *) screen) + 0x12))) & 1))
        {
          y += 12;
        }
        p = func_80040260(arg0, (s16) (q[0] + x), (s16) (q[1] + y), 15, func_8003F34C, 1);
        screen = func_80034FF0(arg1 + 0x4C, 0);
        ((__repair_field_A4 *)p)->value = screen;
        new_var = ((u8 *) (*((void **) (((u8 *) screen) + 4)))) + 0;
        ((__repair_field_A8 *)p)->value = obj;
        *((s16 *) (((u8 *) p) + 0x70)) = -((*((u16 *) (((u8 *) (*((void **) new_var))) + 8))) >> 1);
        screen = D_800C7F84;
        rec = *((void **) (((u8 *) ((short) screen)) + 0x178));
        w = *((u16 *) (((u8 *) rec) + 0xC));
        x = ((s16) w) / 2;
        y = (*((s16 *) (((u8 *) rec) + 0xE))) / 2;
        screen = D_800C35A0;
        if (((*((u16 *) (((u8 *) screen) + 0xE))) == 2) && ((*((u16 *) (((u8 *) screen) + 0x12))) & 1))
        {
          y += 8;
        }
        p = func_80040260(arg0, (s16) (q[0] + x), (s16) (q[1] + y), 15, func_8003F2CC, 1);
        ((__repair_field_A4 *)p)->value = func_80034FF0(arg1 + 0x4C, 0);
        ((__repair_field_A8 *)p)->value = obj;
        *((s16 *) (((u8 *) p) + 0x70)) = -((*((u16 *) (((u8 *) (*((void **) (((u8 *) (*((void **) (((u8 *) (((__repair_field_A4 *)p)->value)) + 4)))) + 0)))) + 8))) >> 1);
        i++;
        j = (i << 1) - 1;
      }
      while (i <= n);
    }
  }
}

