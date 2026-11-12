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
/* Builds the race UI context at gRaceCtx: clears the menu rows, fills the label strings for the current select step and records state, then creates the rectangle set and the slot names. */ void init_race_ui(void)
{
  int text_id_alt;
  s32 ui_tmp;
  s32 ui_set_handle;
  s32 rect_set;
  s32 text_table_id;
  s32 text_id;
  s32 col;
  s32 row_index;
  s32 row;
  u8 is_locked;
  char *ctx_alias;
  s32 text_str;
  Blob default_block = D_800A4E90;
  gRaceCtx = poolAlloc(1, 0x3A8);
  B(gRaceCtx, 0x383) = 0;
  B(gRaceCtx, 0x8) = 0;
  B(gRaceCtx, 0x384) = 0;
  {
    char *dest = gRaceCtx;
    is_locked = 0;
    if (U(gRecords, 0xE) == 2)
    {
      is_locked = U(gRecords, 0x1A) == 0;
    }
    B(dest, 0x3A2) = is_locked;
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
  row_index = 0;
  col = 0;
  *((Blob *) (gRaceCtx + 0x386)) = default_block;
  do
  {
    col = 0;
    row = ((u8) row_index) * 222 + 10;
    do
    {
      memset((gRaceCtx + row) + (((u8) col) * 42), 0, 42);
      col++;
    }
    while (((u8) col) < 5);
    col = 0;
    row_index++;
  }
  while (((u8) row_index) < 4);
  if (gSelectStep != 0)
  {
    text_table_id = D_800A14BC[gSelectStep];
  
  gSelectStepHandle = func_80057810(text_table_id);}
  else
  {
    text_table_id = D_800A14C0;
  
  gSelectStepHandle = func_80057810(text_table_id);}
  if (U(gRecords, 0x1E) == 0)
  {
    B(gRaceCtx, 0xE6) = (s8) (5 - B(gRaceCtx, 0x3A2));
    text_id = pool_get_item(gSelectStepHandle, 0x1AF);
    strCpy(gRaceCtx + 0xA, text_id);
    if (B(gRaceCtx, 0x3A2) == 0)
    {
      text_id = pool_get_item(gSelectStepHandle, 0x1B1);
      strCpy(gRaceCtx + 0x34, text_id);
    }
    text_id = pool_get_item(gSelectStepHandle, 0x1B2);
    strCpy(gRaceCtx + (((2 - B(gRaceCtx, 0x3A2)) * 0x2A) + 0xA), text_id);
    text_id = pool_get_item(gSelectStepHandle, 0x1B5);
    strCpy(gRaceCtx + (((3 - B(gRaceCtx, 0x3A2)) * 0x2A) + 0xA), text_id);
    text_str = pool_get_item(gSelectStepHandle, 6);
    ctx_alias = gRaceCtx;
    strCpy(ctx_alias + (((4 - B(ctx_alias, 0x3A2)) * 0x2A) + 0xA), text_str);
  }
  else
  {
    B(gRaceCtx, 0xE6) = 3;
    text_id = pool_get_item(gSelectStepHandle, 0x1AF);
    strCpy(gRaceCtx + 0xA, text_id);
    if (U(gRecords, 0x1E) != 5)
    {
      text_id_alt = 0x1B3;
    }
    else
    {
      text_id_alt = 0x1B0;
    }
    if (U(gRecords, 0x1E) == 5)
    {
      text_id = pool_get_item(gSelectStepHandle, 0x1B0);
    }
    else
    {
      text_id = pool_get_item(gSelectStepHandle, 0x1B3);
    }
    strCpy(gRaceCtx + 0x34, text_id);
    text_str = pool_get_item(gSelectStepHandle, 0x1B5);
    strCpy(gRaceCtx + 0x5E, text_str);
  }
  B(gRaceCtx, 0x380) = 2;
  text_id = pool_get_item(gSelectStepHandle, 0x145);
  strCpy(gRaceCtx + 0x2A4, text_id);
  text_id = pool_get_item(gSelectStepHandle, 0x143);
  strCpy(gRaceCtx + 0x2CE, text_id);
  B(gRaceCtx, 0x1C4) = 4;
  text_id = pool_get_item(gSelectStepHandle, 0x19F);
  strCpy(gRaceCtx + 0xE8, text_id);
  text_id = pool_get_item(gSelectStepHandle, 0x1A0);
  strCpy(gRaceCtx + 0x112, text_id);
  text_id = pool_get_item(gSelectStepHandle, 0x1A1);
  strCpy(gRaceCtx + 0x13C, text_id);
  text_id = pool_get_item(gSelectStepHandle, 0x1B4);
  strCpy(gRaceCtx + 0x166, text_id);
  B(gRaceCtx, 0x2A2) = 5;
  text_id = pool_get_item(gSelectStepHandle, 0x40);
  strCpy(gRaceCtx + 0x1C6, text_id);
  text_id = pool_get_item(gSelectStepHandle, 0x42);
  strCpy(gRaceCtx + 0x1F0, text_id);
  text_id = pool_get_item(gSelectStepHandle, 0x47);
  strCpy(gRaceCtx + 0x21A, text_id);
  text_id = pool_get_item(gSelectStepHandle, 0x4B);
  strCpy(gRaceCtx + 0x244, text_id);
  text_id = pool_get_item(gSelectStepHandle, 0x4F);
  strCpy(gRaceCtx + 0x26E, text_id);
  B(gRaceCtx, 0x382) = 0;
  resolve_path(&D_800A4EAC);
  ui_set_handle = func_80081664(6, &D_800A4EB4);
  W(gRaceCtx, 0x0) = ui_set_handle;
  rect_set = make_rect_set(ui_set_handle);
  W(gRaceCtx, 0x4) = rect_set;
  rect_set_set_item_pos(rect_set, 0x80, 0x33);
  rect_set_set_scale(W(gRaceCtx, 0x4), F(gRaceCtx, 0x3A4), 1.0f, 1.0f);
  B(gRaceCtx, 0x383) = 0;
  func_80049F18();
  func_8004C794();
  init_slot_names();
}
