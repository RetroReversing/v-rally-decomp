#define I(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
extern s32 D_800AE850[];
extern s32 D_800C02AE[];
extern u8 *D_8009C230;
extern s32 D_8009F500[];
extern s32 D_8009F504[];
extern s32 D_8009F508[];
extern s32 D_8009F50C[];
extern s32 D_8009F518[];
extern s32 D_8009F51C[];
extern void func_8002D8A0(s32, void *, void *);
static inline void add3(s32 *d, s32 *a, s32 *b)
{
  d[0] = a[0] + b[0];
  d[1] = a[1] + b[1];
  d[2] = a[2] + b[2];
}
void func_8002B970(u8 *arg0, u8 *arg1)
{
  struct 
  {
    s32 x;
    s32 y;
    s32 z;
  } sp;
  s32 temp_a0; 
  s32 gv;
  s32 v0a;
  s32 temp_a0_5;
  s32 temp_a1;
  s32 temp_a2;
  s32 temp_v0_2;
  s32 temp_v0_3;
  u8 *new_var;
  s32 temp_v0_4;
  s32 var_a3;
  s32 var_s1;
  u8 *new_var2;
  s32 var_s2;
  s32 var_s3;
  s32 var_s4;
  void *temp_a0_2;
  void *temp_a0_3;
  void *temp_a0_4;
  u8 *new_var3;
  void *temp_a1_2;
  void *temp_a1_3;
  void *temp_a2_2;
  void *temp_a2_3;
  void *temp_v0;
  u8 *var_t0;
  struct Row { u8 pad[0x44]; s32 v; s32 w; } *r;
  gv = I(D_800AE850, 0x82AC);
  v0a = I(arg0, 0x90);
  gv -= 0x1E;
  v0a += gv;
  I(P(arg1, 0x80), 0x4) = v0a;
  var_s2 = 4;
  I(P(arg1, 0x80), 0x8) = (s32) (I(arg0, 0xDC) + I(D_800C02AE, 0x3246));
  var_a3 = 0x50;
  temp_v0_4 = 4;
  I(P(arg1, 0x80), 0xC) = (s32) I(arg0, 0x128);
  do
  {
    temp_a0 = ((struct Row *) arg0)[temp_v0_4].v;
    temp_a1 = ((struct Row *) arg0)[temp_v0_4 + 1].v;
    temp_a2 = ((struct Row *) arg0)[temp_v0_4 + 2].v;
    I((u8 *) (var_a3 + ((s32) P(arg1, 0x80))), 0x10) = (s32) (-temp_a0);
    I((u8 *) (var_a3 + ((s32) P(arg1, 0x80))), 0x14) = temp_a1;
    I((u8 *) (var_a3 + ((s32) P(arg1, 0x80))), 0x18) = temp_a2;
    I((u8 *) (var_a3 + ((s32) P(arg1, 0x80))), 0x24) = temp_a0;
    I((u8 *) (var_a3 + ((s32) P(arg1, 0x80))), 0x28) = temp_a1;
    temp_v0_4 += 3;
    var_s2 += 2;
    I((u8 *) (var_a3 + ((s32) P(arg1, 0x80))), 0x2C) = temp_a2;
    var_a3 += 0x28;
  }
  while (var_s2 <= (0xC - 1));
  var_s2 = 0;
  var_s4 = 0x100;
  var_s3 = 0x10;
  var_s1 = 0;
  do
  {
    temp_a2_2 = P(arg1, 0x80);
    func_8002D8A0(I(arg1, 0x5C) + 0x40, temp_a2_2 + var_s3, temp_a2_2 + var_s4);
    temp_a0_2 = P(arg1, 0x80);
    temp_a2_3 = P(arg1, 0x58);
    add3((s32 *) ((u8 *) (var_s1 + (s32) temp_a0_2) + 0x1F0), (s32 *) ((u8 *) (var_s1 + (s32) temp_a0_2) + 0x100), (s32 *) ((u8 *) temp_a2_3 + 0xC));
    temp_v0 = (u8 *) (var_s1 + (s32) P(arg1, 0x80));
    sp = *((typeof(sp) *) (temp_v0 + 0x1F0));
    { s32 tx; I(var_s1 + (s32) P(arg1, 0x60), 0x60) = (tx = sp.x, var_t0 = D_8009C230, tx); }
    I(var_s1 + (s32) P(arg1, 0x60), 0x64) = sp.y;
    var_s4 += 0x14;
    I(var_s1 + (s32) P(arg1, 0x60), 0x68) = sp.z;
    temp_a0_5 = var_s2 * 4;
    I((var_s2 * 4) + (s32) P(arg1, 0x60), 0x30) = (s32) (I(var_t0, 0x4C) - 1);
    var_s3 += 0x14;
    new_var3 = var_t0;
    I(temp_a0_5 + (s32) P(arg1, 0x34), 0x30) = (s32) (I(new_var3, 0x4C) - 1);
    var_s2 += 1;
    new_var2 = new_var3;
    I(temp_a0_5 + (s32) P(arg1, 0x60), 0) = ((u16) H(new_var3, 0x88)) >> 1;
    I(temp_a0_5 + (s32) P(arg1, 0x34), 0) = ((u16) H(new_var2, 0x88)) >> 1;
    var_s1 += 0x14;
  }
  while (var_s2 < 0xC);
  I(P(arg1, 0x8C), 0x578) = (s32) I(D_8009F500, H(P(D_800C02AE, 0x32F2), 0x16) * 0x30);
  I(P(arg1, 0x8C), 0x57C) = (s32) I(D_8009F504, H(P(D_800C02AE, 0x32F2), 0x16) * 0x30);
  temp_v0_2 = H(P(D_800C02AE, 0x32F2), 0x16) * 0x30;
  I(D_8009F500, temp_v0_2) = I(D_8009F500, temp_v0_2) + I(D_8009F508, temp_v0_2);
  temp_v0_3 = H(P(D_800C02AE, 0x32F2), 0x16) * 0x30;
  new_var = new_var3;
  I(D_8009F504, temp_v0_3) = I(D_8009F504, temp_v0_3) + I(D_8009F50C, temp_v0_3);
  I(P(arg1, 0x34), 0x170) = (s32) I(D_8009F518, H(P(D_800C02AE, 0x32F2), 0x16) * 0x30);
  temp_v0_4 = H(P(D_800C02AE, 0x32F2), 0x16) * 0x30;
  I(D_8009F518, temp_v0_4) = I(D_8009F518, temp_v0_4) + I(D_8009F51C, temp_v0_4);
  I(P(arg1, 0x34), 0x160) = 1;
  I(P(arg1, 0x34), 0x158) = 0;
  I(P(arg1, 0x34), 0x164) = 0;
  I(P(arg1, 0x34), 0x168) = 0;
  I(P(arg1, 0x34), 0x16C) = 0x1F4;
  I(P(arg1, 0x34), 0x154) = 0;
  P(P(arg1, 0x34), 0x150) = new_var3;
  I(P(arg1, 0x60), 0x160) = 0;
  I(P(arg1, 0x60), 0x158) = 0;
  I(P(arg1, 0x60), 0x164) = 0;
  I(P(arg1, 0x60), 0x168) = 0;
  I(P(arg1, 0x60), 0x16C) = 0x1F4;
  I(P(arg1, 0x60), 0x154) = 0;
  P(P(arg1, 0x60), 0x150) = new_var;
  I(P(arg1, 0x60), 0x178) = 0;
  I(P(arg1, 0x60), 0x174) = 0;
}

