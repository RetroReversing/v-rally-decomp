#define sp70 sp40[12]
#define sp74 sp40[13]
#define sp78 sp40[14]
#define sp80 vec[0]
#define sp88 vec[1]
#define CMD(a,b) {u32 *g=p; p+=2; g[0]=(a);g[1]=(b);}
void *func_80006008(s32);
s32 func_80006014(s32, void *);
s32 func_800061FC(s32, s32);
s32 func_800068C0(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80006CF8(s32, s32);
s32 func_800072F4(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80010BFC(s32, void *, s32 *);
s32 func_8001BD1C();
s32 guMtxIdentF(s32 *);
extern u8 *D_800C7F84;
void func_8003737C(s32 arg0)
{
  f32 sp40[16];
  void *new_var;
  f32 temp_ft1;
  volatile f32 temp_fv0;
  s32 temp_s0_2;
  s32 temp_v0;
  u32 temp_v0_8;
  f32 vec[2];
  void *temp_s0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v0_7;
  temp_s0 = *((void **) (((char *) D_800C7F84) + 0x178));
  guMtxIdentF(&sp40);
  temp_v0 = func_8001BD1C();
  sp70 = *((f32 *) (((char *) D_800C7F84) + 0x118));
  sp74 = *((f32 *) (((char *) D_800C7F84) + 0x11C));
  sp78 = *((f32 *) (((char *) D_800C7F84) + 0x120));
  func_80010BFC(temp_v0, D_800C7F84 + 0x38, &sp40);
  ;
  {
    u32 *p = func_80006008(arg0);
    CMD(0xE7000000, 0);
    CMD(0xE3000A01, 0x100000);
    CMD(0xE200001C, 0x504240);
    CMD(0xFCFFFFFF, 0xFFFE793C);
    CMD(0xD9FFF9FF, 0);
    CMD(0xD9FFFFFF, 0x200004);
    func_80006014(arg0, p);
  }
  func_800061FC(arg0, temp_v0);
  temp_v0_8 = func_80006CF8(arg0, 0);
  sp80 = (temp_ft1 = *((f32 *) (((char *) D_800C7F84) + 0x148)));
  temp_fv0 = sp88;
  temp_s0_2 = 0xFFFF;
  ;
  new_var = temp_s0;
  temp_s0_2 = temp_v0_8 & temp_s0_2;
  func_800068C0(arg0, temp_s0_2, (s16) ((s32) (((f32) (-(*((s16 *) (((char *) new_var) + 0xC))))) - temp_ft1)), (s16) (((s32) (*((u16 *) (((char *) new_var) + 0xE)))) * (-1)), (s32) ((s16) ((s32) ((-200.0f) - temp_fv0))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) new_var) + 0xC)))) - sp80))), (s32) ((s16) (((s32) (*((u16 *) (((char *) new_var) + 0xE)))) * (-1))), (s32) ((s16) ((s32) ((-200.0f) - temp_fv0))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) temp_s0) + 0xC)))) + sp80))), (s32) ((s16) (*((u16 *) (((char *) temp_s0) + 0xE)))), (s32) ((s16) ((s32) (temp_fv0 + (-200.0f)))), (s32) ((s16) ((s32) (((f32) (-(*((s16 *) (((char *) new_var) + 0xC))))) + sp80))), (s32) ((s16) (*((u16 *) (((char *) new_var) + 0xE)))), (s32) ((s16) ((s32) ((*((f32 *) (((char *) D_800C7F84) + 0x150))) + (-200.0f)))));
  func_800072F4(arg0, temp_s0_2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80);
}

