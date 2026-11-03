#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct 
{
  u8 pad0[0x228];
  u8 unk228;
  u8 pad229[2];
  s8 unk22B;
  u8 pad22C[0x19];
  u8 unk245;
  u8 pad246[7];
  u8 unk24D;
  u8 pad24E[0x35];
  u8 unk283;
  u8 pad284[4];
  void (*unk288)(void);
  void (*unk28C)(void);
} Obj;
extern Obj *D_800A1468;
extern u8 D_800C02AE[];
extern volatile unsigned short func_8006F4A8(u8);
extern void func_8006EE3C(u8);
extern void func_8006F0E0(u8, void *);
extern void func_8006F75C(void);
extern void func_8005A360(s32, s32, s32, s32);
extern void func_80066E20(void);
extern void func_80066EBC(void);
s32 func_8006786C(void)
{
  u8 *a1;
  u8 *v0_tbl;
  u8 *p;
  Obj *v0;
  Obj *v1_obj;
  u8 *new_var;
  Obj *t0;
  Obj *a0_obj;
  Obj *a1_obj;
  s8 v1_id;
  s32 a2;
  s32 a3;
  u8 a0;
  u8 v1;
  u8 t1;
  s32 off;
  s8 idx;
  s32 ret;
  volatile char frame_pad[8];
  func_8006F4A8(D_800A1468->unk228);
  func_8006EE3C(D_800A1468->unk228);
  v1_id = *((s8 *) (((u8 *) D_800A1468) + 0x228));
  a0 = 0;
  off = ((v1_id * 5) * 8) + 0x44;
  a1 = (*((u8 **) (D_800C02AE + 0x32F2))) + off;
  copy_loop:
  v0 = D_800A1468;

  v1 = a0 & 0xFF;
  a1[v1] = *((u8 *) ((((u8 *) v0) + v1) + 0x283));
  a0++;
  if ((a0 & 0xFF) < 3)
  {
    goto copy_loop;
  }
  a1[3] = 0;
  func_8006F0E0(D_800A1468->unk228, a1);
  func_8006F75C();
  { extern u8 * volatile D_800C35A0; v0_tbl = D_800C35A0; }
  v1_obj = D_800A1468;
  a1 = v0_tbl;
  new_var = a1;
  a0 = 1;
  idx = *((s8 *) (((u8 *) v1_obj) + 0x22B));
  t0 = v1_obj;
  a2 = *((s8 *) (((u8 *) v1_obj) + 0x228));
  t1 = *((u8 *) ((a1 + idx) + 0x32));
  a3 = a2;
  v1 = a0 & 0xFF;
  search_loop:
  if ((*((u8 *) ((a1 + (a0 & 0xFF)) + 0x32))) == a2)
  {
    v1 = a0 & 0xFF;
    goto search_done;
  }

  a0++;
  if ((a0 & 0xFF) < 4)
  {
    goto search_loop;
  }
  v1 = a0 & 0xFF;
  do
  {
    search_done:
    a0 = 0;

    if (v1 != 4)
    {
      idx = *((s8 *) (((u8 *) t0) + 0x22B));
      *((u8 *) ((a1 + idx) + 0x32)) = (u8) a3;
      p = *((u8 **) (D_800C02AE + 0x32F2));
      p += v1;
      p[0x32] = t1;
    }
    func_8005A360(a0, 0, a2, a3);
    {
      Obj *p0;
      Obj *p1;
      p0 = D_800A1468;
      p0->unk245 = 0;
      p1 = D_800A1468;
      ret = 0;
      p0->unk288 = func_80066E20;
      p0->unk28C = func_80066EBC;
      p1->unk24D = 0;
      return ret;
    }
  }
  while (0);
}

