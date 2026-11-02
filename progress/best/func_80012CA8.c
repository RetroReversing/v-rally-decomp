#define sp10 vec.x
#define sp14 vec.y
#define sp18 vec.z
extern int D_800AFA6C;
extern unsigned char D_800C7FA0;
extern unsigned short D_800C8202;
extern unsigned char D_800C8200;
extern unsigned char D_800C81FC;
extern unsigned short D_800C8240;
void *func_80012B74();
s32 func_80042290();
s32 *func_80084BF0();
s32 func_80085778();
extern u16 D_8009BAA0[8][5];
extern s32 D_8009BAF0;
extern char D_800A1814[];
extern char D_800A73E0[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern void *D_800C35A0;
void func_80012CA8(void *arg0, s32 arg1, s32 arg2)
{
  struct 
  {
    s32 x;
    s32 y;
    s32 z;
  } vec;
  s32 pad[1];
  s32 *var_s0;
  s32 var_a1;
  int new_var2;
  s32 var_a2;
  u16 temp_a1;
  u8 temp_v0;
  u8 temp_v0_2;
  u32 new_var;
  void *temp_a1_2;
  void *temp_v0_3;
  void *var_s1;
  void *var_s2;
  void *var_s3;
  var_a1 = arg1;
  var_a2 = arg2;
  var_s1 = arg0;
  if (D_800AFA6C != (((u16 *) D_800A1814)[*((u16 *) (((char *) D_800C35A0) + 0x22))] - 1))
  {
    *((s32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x130)) = 0;
    *((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x134)) = 100.0f;
    *((s32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x138)) = 0;
    *((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x114)) = 1.0f;
    if ((*((void **) (D_800A73E0 + 0x6C24))) != NULL)
    {
      var_s3 = *((void **) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x24));
      if (D_800C7FA0 == 1)
      {
        var_s3 = *((void **) (((char *) var_s3) + 4));
      }
      var_s2 = *((void **) (((char *) var_s1) + 0x8C));
      if (var_s2 == NULL)
      {
        *((void **) (((char *) var_s1) + 0x8C)) = func_80012B74(D_8009BAF0);
      }
      {
        u16 *counter = &D_800C8202;
        temp_a1 = *counter;
        *counter = (u16) (temp_a1 + 1);
      }
      var_s0 = &D_8009BAA0;
      var_s0 = &D_8009BAA0;
      temp_v0 = D_800C8200 + 1;
      if (((u16) D_8009BAA0[*((u16 *) (((char *) D_800C35A0) + 0x22))][D_800C8200]) < temp_a1)
      {
        *((volatile u8 *) (&D_800C8200)) = temp_v0;
        *((void **) (((char *) var_s1) + 0x8C)) = func_80012B74((&D_8009BAF0)[temp_v0 & 0xFF]);
        var_s0 = &D_8009BAF0;
        var_s0 = &D_8009BAF0;
        temp_v0_2 = D_800C8200 + 1;
        if (D_8009BAA0[*((u16 *) (((char *) D_800C35A0) + 0x22))][D_800C8200] == 0)
        {
          D_800C8200 = temp_v0_2;
          do
          {
            *((void **) (((char *) var_s1) + 0x8C)) = func_80012B74((&D_8009BAF0)[temp_v0_2 & 0xFF]);
          }
          while (0);
        }
      }
      if (D_800C81FC == 0)
      {
        D_800C8202 = (u16) (D_800C8202 - 1);
      }
      if (D_800C8240 & 0x800)
      {
        var_s0 = func_80084BF0(0);
        func_80085778(0, var_s0);
        var_s0 = (s32 *) (((s32) var_s0) & 8);
        var_s2 += 0x34;
        if (var_s0 != NULL)
        {
          temp_a1_2 = *((void **) (((char *) (*((void **) (D_800A73E0 + 0x6C24)))) + 0));
          new_var = (u32) (var_s2 - temp_a1_2);
          if (((u32) (((*((u16 *) (((char *) (*((void **) (D_800A73E0 + 0x6C24)))) + 4))) - 1) * 0x34)) < new_var)
          {
            var_s2 = temp_a1_2;
          }
        }
        *((void **) (((char *) var_s1) + 0x8C)) = var_s2;
      }
      *((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x118)) = (f32) (*((s32 *) (((char *) (*((void **) (((char *) var_s1) + 0x8C)))) + 0xC)));
      new_var2 = 0x8C;
      *((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x11C)) = (f32) (*((s32 *) (((char *) (*((void **) (((char *) var_s1) + 0x8C)))) + 0x10)));
      *((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x120)) = (f32) (*((s32 *) (((char *) (*((void **) (((char *) var_s1) + new_var2)))) + 0x14)));
      temp_v0_3 = *((void **) (((char *) var_s3) + 0x58));
      var_a1 = *((s32 *) (((char *) temp_v0_3) + 0x10));
      var_a2 = *((s32 *) (((char *) temp_v0_3) + 0x14));
      sp10 = *((s32 *) (((char *) temp_v0_3) + 0xC));
      sp14 = var_a1;
      sp18 = var_a2;
      *((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x124)) = (f32) sp10;
      *((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x128)) = (f32) sp14;
      *((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x12C)) = (f32) sp18;
      *((s32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x108)) = 0;
    }
    func_80042290(*((void **) (D_800C02AE + 0x7CD6)), var_a1);
  }
}

