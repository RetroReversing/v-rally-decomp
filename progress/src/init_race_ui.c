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
void *memset();
void strCpy();
void resolve_path();
void rect_set_set_item_pos();
void func_80049F18();
void func_8004C794();
void init_slot_names();
/* Builds the race UI context at gRaceCtx: clears the menu rows, fills the label strings for the current select step and records state, then creates the rectangle set and the slot names. */ /* Builds the race UI context at gRaceCtx: clears the menu rows, fills the label strings for the current select step and records state, then creates the rectangle set and the slot names. */ void init_race_ui(void)
{
  int str_id_alt;
  s32 ui_tmp;
  s32 ui_set;
  s32 rect_handle;
  s32 table_id;
  s32 str_id;
  s32 col_i;
  s32 row_i;
  s32 row_ofs;
  u8 locked;
  char *ctx;
  s32 str_ptr;
  Blob default_rows = D_800A4E90;
  gRaceCtx = poolAlloc(1, 0x3A8);
  B(gRaceCtx, 0x383) = 0;
  B(gRaceCtx, 0x8) = 0;
  B(gRaceCtx, 0x384) = 0;
  {
    char *dest = gRaceCtx;
    locked = 0;
    if (U(gRecords, 0xE) == 2)
    {
      locked = U(gRecords, 0x1A) == 0;
    }
    B(dest, 0x3A2) = locked;
  }
  {
    u16 record_mode = U(gRecords, 0xE);
    D_800A0389 = 5;
    if ((record_mode == 2) && (U(gRecords, 0x12) & 1))
    {
      F(gRaceCtx, 0x3A4) = 0.9f;
    }
    else
    {
      F(gRaceCtx, 0x3A4) = 1.0f;
    }
  }
  row_i = 0;
  col_i = 0;
  *((Blob *) (gRaceCtx + 0x386)) = default_rows;
  do
  {
    col_i = 0;
    row_ofs = ((u8) row_i) * 222 + 10;
    do
    {
      memset((gRaceCtx + row_ofs) + (((u8) col_i) * 42), 0, 42);
      col_i++;
    }
    while (((u8) col_i) < 5);
    col_i = 0;
    row_i++;
  }
  while (((u8) row_i) < 4);
  if (gSelectStep != 0)
  {
    table_id = D_800A14BC[gSelectStep];
  
  gSelectStepHandle = func_80057810(table_id);}
  else
  {
    table_id = D_800A14C0;
  
  gSelectStepHandle = func_80057810(table_id);}
  if (U(gRecords, 0x1E) == 0)
  {
    B(gRaceCtx, 0xE6) = (s8) (5 - B(gRaceCtx, 0x3A2));
    str_id = pool_get_item(gSelectStepHandle, 0x1AF);
    strCpy(gRaceCtx + 0xA, str_id);
    if (B(gRaceCtx, 0x3A2) == 0)
    {
      str_id = pool_get_item(gSelectStepHandle, 0x1B1);
      strCpy(gRaceCtx + 0x34, str_id);
    }
    str_id = pool_get_item(gSelectStepHandle, 0x1B2);
    strCpy(gRaceCtx + (((2 - B(gRaceCtx, 0x3A2)) * 0x2A) + 0xA), str_id);
    str_id = pool_get_item(gSelectStepHandle, 0x1B5);
    strCpy(gRaceCtx + (((3 - B(gRaceCtx, 0x3A2)) * 0x2A) + 0xA), str_id);
    str_ptr = pool_get_item(gSelectStepHandle, 6);
    ctx = gRaceCtx;
    strCpy(ctx + (((4 - B(ctx, 0x3A2)) * 0x2A) + 0xA), str_ptr);
  }
  else
  {
    B(gRaceCtx, 0xE6) = 3;
    str_id = pool_get_item(gSelectStepHandle, 0x1AF);
    strCpy(gRaceCtx + 0xA, str_id);
    if (U(gRecords, 0x1E) != 5)
    {
      str_id_alt = 0x1B3;
    }
    else
    {
      str_id_alt = 0x1B0;
    }
    if (U(gRecords, 0x1E) == 5)
    {
      str_id = pool_get_item(gSelectStepHandle, 0x1B0);
    }
    else
    {
      str_id = pool_get_item(gSelectStepHandle, 0x1B3);
    }
    strCpy(gRaceCtx + 0x34, str_id);
    str_ptr = pool_get_item(gSelectStepHandle, 0x1B5);
    strCpy(gRaceCtx + 0x5E, str_ptr);
  }
  B(gRaceCtx, 0x380) = 2;
  str_id = pool_get_item(gSelectStepHandle, 0x145);
  strCpy(gRaceCtx + 0x2A4, str_id);
  str_id = pool_get_item(gSelectStepHandle, 0x143);
  strCpy(gRaceCtx + 0x2CE, str_id);
  B(gRaceCtx, 0x1C4) = 4;
  str_id = pool_get_item(gSelectStepHandle, 0x19F);
  strCpy(gRaceCtx + 0xE8, str_id);
  str_id = pool_get_item(gSelectStepHandle, 0x1A0);
  strCpy(gRaceCtx + 0x112, str_id);
  str_id = pool_get_item(gSelectStepHandle, 0x1A1);
  strCpy(gRaceCtx + 0x13C, str_id);
  str_id = pool_get_item(gSelectStepHandle, 0x1B4);
  strCpy(gRaceCtx + 0x166, str_id);
  B(gRaceCtx, 0x2A2) = 5;
  str_id = pool_get_item(gSelectStepHandle, 0x40);
  strCpy(gRaceCtx + 0x1C6, str_id);
  str_id = pool_get_item(gSelectStepHandle, 0x42);
  strCpy(gRaceCtx + 0x1F0, str_id);
  str_id = pool_get_item(gSelectStepHandle, 0x47);
  strCpy(gRaceCtx + 0x21A, str_id);
  str_id = pool_get_item(gSelectStepHandle, 0x4B);
  strCpy(gRaceCtx + 0x244, str_id);
  str_id = pool_get_item(gSelectStepHandle, 0x4F);
  strCpy(gRaceCtx + 0x26E, str_id);
  B(gRaceCtx, 0x382) = 0;
  resolve_path(&D_800A4EAC);
  ui_set = func_80081664(6, &D_800A4EB4);
  W(gRaceCtx, 0x0) = ui_set;
  rect_handle = make_rect_set(ui_set);
  W(gRaceCtx, 0x4) = rect_handle;
  rect_set_set_item_pos(rect_handle, 0x80, 0x33);
  rect_set_set_scale(W(gRaceCtx, 0x4), F(gRaceCtx, 0x3A4), 1.0f, 1.0f);
  B(gRaceCtx, 0x383) = 0;
  func_80049F18();
  func_8004C794();
  init_slot_names();
}
