#define W(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(u16*)((p)+(o)))
#define B(p,o) (*(u8*)((p)+(o)))
#define F(p,o) (*(float*)((p)+(o)))
typedef struct 
{
  char a[28];
} Blob;
extern Blob D_800A4E90;
extern char D_800A4EAC;
extern char D_800A4EB4;
extern char *gRaceCtx;
extern char *gRecords;
extern s8 D_800A0389;
extern int D_800A14BC[];
extern int D_800A14C0;
extern int gSelectStep;
extern int gSelectStepHandle;
char *poolAlloc(int, int);
int func_80057810(int);
int pool_get_item(int, int);
int func_80081664(int, void *);
int make_rect_set(int);
void rect_set_set_scale(int, float, float, float);
void func_80049654(void)
{
  int var_a1_2;
  s32 temp_v0_2;
  s32 temp_v0_3;
  s32 temp_v0_4;
  s32 var_a0;
  s32 var_a1;
  s32 var_s0;
  s32 var_s1;
  s32 row;
  u8 var_v1;
  char *temp_v0;
  s32 text;
  Blob local = D_800A4E90;
  gRaceCtx = poolAlloc(1, 0x3A8);
  B(gRaceCtx, 0x383) = 0;
  B(gRaceCtx, 0x8) = 0;
  B(gRaceCtx, 0x384) = 0;
  {
    char *dest = gRaceCtx;
    var_v1 = 0;
    if (U(gRecords, 0xE) == 2)
    {
      var_v1 = U(gRecords, 0x1A) == 0;
    }
    B(dest, 0x3A2) = var_v1;
  }
  {
    u16 mode = U(gRecords, 0xE);
    D_800A0389 = 5;
    if ((mode == 2) && (U(gRecords, 0x12) & 1))
    {
      F(gRaceCtx, 0x3A4) = 0.9f;
    }
    else
    {
      F(gRaceCtx, 0x3A4) = 1.0f;
    }
  }
  var_s1 = 0;
  var_s0 = 0;
  *((Blob *) (gRaceCtx + 0x386)) = local;
  do
  {
    var_s0 = 0;
    row = ((u8) var_s1) * 222 + 10;
    do
    {
      memset((gRaceCtx + row) + (((u8) var_s0) * 42), 0, 42);
      var_s0++;
    }
    while (((u8) var_s0) < 5);
    var_s0 = 0;
    var_s1++;
  }
  while (((u8) var_s1) < 4);
  if (gSelectStep != 0)
  {
    var_a0 = D_800A14BC[gSelectStep];
  
  gSelectStepHandle = func_80057810(var_a0);}
  else
  {
    var_a0 = D_800A14C0;
  
  gSelectStepHandle = func_80057810(var_a0);}
  if (U(gRecords, 0x1E) == 0)
  {
    B(gRaceCtx, 0xE6) = (s8) (5 - B(gRaceCtx, 0x3A2));
    var_a1 = pool_get_item(gSelectStepHandle, 0x1AF);
    copyStringAligned(gRaceCtx + 0xA, var_a1);
    if (B(gRaceCtx, 0x3A2) == 0)
    {
      var_a1 = pool_get_item(gSelectStepHandle, 0x1B1);
      copyStringAligned(gRaceCtx + 0x34, var_a1);
    }
    var_a1 = pool_get_item(gSelectStepHandle, 0x1B2);
    copyStringAligned(gRaceCtx + (((2 - B(gRaceCtx, 0x3A2)) * 0x2A) + 0xA), var_a1);
    var_a1 = pool_get_item(gSelectStepHandle, 0x1B5);
    copyStringAligned(gRaceCtx + (((3 - B(gRaceCtx, 0x3A2)) * 0x2A) + 0xA), var_a1);
    text = pool_get_item(gSelectStepHandle, 6);
    temp_v0 = gRaceCtx;
    copyStringAligned(temp_v0 + (((4 - B(temp_v0, 0x3A2)) * 0x2A) + 0xA), text);
  }
  else
  {
    B(gRaceCtx, 0xE6) = 3;
    var_a1 = pool_get_item(gSelectStepHandle, 0x1AF);
    copyStringAligned(gRaceCtx + 0xA, var_a1);
    if (U(gRecords, 0x1E) != 5)
    {
      var_a1_2 = 0x1B3;
    }
    else
    {
      var_a1_2 = 0x1B0;
    }
    if (U(gRecords, 0x1E) == 5)
    {
      var_a1 = pool_get_item(gSelectStepHandle, 0x1B0);
    }
    else
    {
      var_a1 = pool_get_item(gSelectStepHandle, 0x1B3);
    }
    copyStringAligned(gRaceCtx + 0x34, var_a1);
    text = pool_get_item(gSelectStepHandle, 0x1B5);
    copyStringAligned(gRaceCtx + 0x5E, text);
  }
  B(gRaceCtx, 0x380) = 2;
  var_a1 = pool_get_item(gSelectStepHandle, 0x145);
  copyStringAligned(gRaceCtx + 0x2A4, var_a1);
  var_a1 = pool_get_item(gSelectStepHandle, 0x143);
  copyStringAligned(gRaceCtx + 0x2CE, var_a1);
  B(gRaceCtx, 0x1C4) = 4;
  var_a1 = pool_get_item(gSelectStepHandle, 0x19F);
  copyStringAligned(gRaceCtx + 0xE8, var_a1);
  var_a1 = pool_get_item(gSelectStepHandle, 0x1A0);
  copyStringAligned(gRaceCtx + 0x112, var_a1);
  var_a1 = pool_get_item(gSelectStepHandle, 0x1A1);
  copyStringAligned(gRaceCtx + 0x13C, var_a1);
  var_a1 = pool_get_item(gSelectStepHandle, 0x1B4);
  copyStringAligned(gRaceCtx + 0x166, var_a1);
  B(gRaceCtx, 0x2A2) = 5;
  var_a1 = pool_get_item(gSelectStepHandle, 0x40);
  copyStringAligned(gRaceCtx + 0x1C6, var_a1);
  var_a1 = pool_get_item(gSelectStepHandle, 0x42);
  copyStringAligned(gRaceCtx + 0x1F0, var_a1);
  var_a1 = pool_get_item(gSelectStepHandle, 0x47);
  copyStringAligned(gRaceCtx + 0x21A, var_a1);
  var_a1 = pool_get_item(gSelectStepHandle, 0x4B);
  copyStringAligned(gRaceCtx + 0x244, var_a1);
  var_a1 = pool_get_item(gSelectStepHandle, 0x4F);
  copyStringAligned(gRaceCtx + 0x26E, var_a1);
  B(gRaceCtx, 0x382) = 0;
  resolve_path(&D_800A4EAC);
  temp_v0_3 = func_80081664(6, &D_800A4EB4);
  W(gRaceCtx, 0x0) = temp_v0_3;
  temp_v0_4 = make_rect_set(temp_v0_3);
  W(gRaceCtx, 0x4) = temp_v0_4;
  rect_set_set_item_pos(temp_v0_4, 0x80, 0x33);
  rect_set_set_scale(W(gRaceCtx, 0x4), F(gRaceCtx, 0x3A4), 1.0f, 1.0f);
  B(gRaceCtx, 0x383) = 0;
  func_80049F18();
  func_8004C794();
  init_slot_names();
}
