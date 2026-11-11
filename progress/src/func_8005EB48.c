#define C (*(C02 *)(gStreamState+2))
#define O (C.o)
#define I(n) (*(s32 *)(gStreamState+(n)))
#define F(n) (*(f32 *)(gStreamState+(n)))
#define NO_VALUE 100
typedef struct 
{
  u8 p[0x12];
  u16 x12;
  u8 q[2];
  u16 x16;
  u8 r[0x14];
  u16 x2c;
  u8 t[0x22];
  u16 x50;
} Obj;
typedef struct 
{
  u8 p[0x32a6];
  u16 a;
  s32 b;
  u8 q[0x44];
  Obj *o;
  u8 r[0x38];
  f32 f;
  f32 g;
  u8 t[4];
  f32 h;
} C02;
extern u8 gStreamState[];
extern u8 gOrderState[];
extern u8 *gSelectState;
extern u8 D_800A14E0;
extern u8 D_800A14E1;
extern u8 D_800A14E2;
void func_8004D31C();
void func_8005EA28();
void slot_set_selected(s32, s32);
void func_8005EE50(s32, s16, s32);
void func_80057D5C(s32, s32, s32, s32);void *list_advance(u32, void *);
void func_8008A104(s32, s32, s32, s32);

/* Per-frame HUD refresh. Pushes the current state into the HUD slots, then
 * sums two pairs of bytes from the status table. If any value is NO_VALUE or the
 * object has the 0x1000 flag, it jumps to fail and only sets the default state. */
void func_8005EB48(void)
{
  s32 sum_a;
  s32 sum_b;
  int zero;
  s32 sum_c;
  s32 x;
  u8 *p;
  func_8004D31C();
  func_8005EA28();
  slot_set_selected(10, O->x16);
  slot_set_selected(16, C.a & 1);
  slot_set_selected(11, O->x12 & 1);
  func_8005EE50(12, (s16) (F(0x3332) * 8.0f), 0);
  func_8005EE50(13, (s16) (F(0x333a) * 8.0f), 0);
  func_8005EE50(14, (s16) (F(0x332e) * 8.0f), 0);
  x = C.b;
  if (x)
  {
    slot_set_selected(15, x - 1);
  }
  else
  {
    slot_set_selected(15, 0);
  }
  zero = 0;
  slot_set_selected(17, O->x50 != zero);
  if (!gSelectState[0x245])
  {
    func_80057D5C(21, 22, 1, zero);
  }
  gSelectState[0x245] = 1;
  sum_a = gOrderState[0x2544] + gOrderState[0x2545];
  sum_b = gOrderState[0x2546] + gOrderState[0x2547];
  sum_c = gOrderState[0x2548];
  D_800A14E0 = sum_a;
  D_800A14E1 = sum_c;
  D_800A14E2 = sum_b;
  if (((u8) sum_a) == NO_VALUE)
  {
    goto fail;
  }
  if (sum_c == NO_VALUE)
  {
    goto fail;
  }
  if (((u8) sum_b) == NO_VALUE)
  {
    goto fail;
  }
  if (O->x2c & 0x1000)
  {
    goto fail;
  }
  {
    func_8008A104(I(0x325a), 18, zero, zero);
    p = list_advance(8, (void *)(*((void **) (gSelectState + 12))));
    p[15] = 80;
    p[16] = 80;
    p[17] = 80;
    return;
  }
  fail:
  func_8008A104(I(0x325a), 18, 1, 1);

}
