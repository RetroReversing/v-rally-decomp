extern s32 D_800A159C[16];
typedef struct { u32 w0,w1; } Command;
typedef struct { char pad[20]; void *cursor; } Packet;
typedef struct { char pad[0x178]; s32 model; } Actor;
extern s32 D_800D05D8;
extern s32 gSelectStepHandle;
extern s32 D_800B6718[][4];
void *memcpy(void*, const void*, unsigned int);
typedef struct { char pad[0x1e]; u16 track,course,slot; char gap[0x2c]; u16 units; } Manager;
typedef struct { s32 time; char pad[2]; char name[10]; } Record;
typedef struct { char pad[0x2c]; Record times[8][4]; s32 speed[38]; } Course;
extern Course *gSlotTableB[];
extern char hud_ident_mtx[];
extern char *g_camera;
extern char *gLeague;
extern char *gRecords;
typedef struct { s32 x; s32 y; s32 z; } Vec3Word;
s32 view_set_rect(s32, u16 *);
void *view_get_ctx_id(s32);
void *gfx_get_dl(void *);
s32 gfx_set_dl();
s32 gfx_push_mtx(void *, s32);
s32 gfx_draw_fill_rect(s32, s32 *, s32 *);
s32 camera_refresh_and_copy();
s32 obj_mtx_visible(s32, void *, s32 *);
s32 mtx_pool_alloc();
s32 func_8001C1A8(s32 *, s32 *);
Actor *find_object_by_id(s32);
s32 func_8004CF7C(s32, s32, s32, s32, f32, s32, s32);
s32 draw_item_bar(s32, s32, f32, s32, s32);
s32 func_80052E94(s32, s16 *);
s16 *pool_get_item(s32, s32);
void *textObjGet(u32);
s32 group_set_color(void *, u8, u8, u8, s32);
void draw_palette_sprite(void *, s16, s16, void *);
void text_obj_set_enabled(u32);
void text_obj_set_disabled(u32);
s32 func_8005D4A4(s32);
s32 getRankedIndex(s32);
s32 memset();
s32 appendString(s16 *, s32 *);
s32 format_to_buffer();
s32 guMtxIdent(void *);
extern s32 gRecordTimeScale;
extern u16 D_800A0370;
extern u16 D_800A0372;
extern u16 D_800A0374;
extern u16 D_800A0376;
extern void *gSelectState;
extern u8 D_800A14D5;
extern s32 D_800A14DC;
extern u16 D_800A155C;
extern u16 D_800A155E;
extern u16 D_800A1560;
extern u16 D_800A1562;
extern s32 D_800A1564;
extern s32 D_800A156C;
extern s32 D_800A1578;
extern s32 D_800A1584;
extern s32 D_800A15DC;
extern s32 D_800A161C;
extern s32 D_800A5418;
extern s32 D_800A541C;
extern s32 D_800A5428;
extern s32 D_800A5434;
extern s32 D_800A54FC;
extern const char D_800A5504[4] __attribute__((aligned(2)));
extern s32 D_800A5508;
extern s32 D_800A5524;
extern s32 D_800A552C;
extern f64 D_800A5538;
extern f64 D_800A5540;
extern f64 D_800A5548;

/* Draws the post-race stats panel: best speed, record times, ranked rows and the camera/GFX setup for the HUD overlay. */
void hud_draw_stats_panel(void)
{
  char line_buf[16];
  s32 rank_row;
  char rank_buf[8];
  char time_buf[24];
  char *records;
  u32 track;
  u32 course;
  u16 units;
  s32 *zero_base;
  s32 *zero_slot;
  s32 *base_vec;
  f64 speed_f;
  s16 idx;
  s32 row_time;
  s32 term;
  s32 speed_whole;
  s32 j;
  s32 j_sum;
  s32 i;
  u32 val;
  s32 prev_time;
  s16 time_val;
  u32 speed_frac;
  s32 idx_plus1;
  u8 rank_byte;
  void *dl;
  void *ident;
  void *obj_b;
  void *obj_c;
  void *cam;
  void *cam_mtx;
  void *text;
  void *gfx;
  void *cur;
  void *cur2;
  char *actor;
  memset(line_buf, 0, 0x10);
  prev_time = 0;
  if ((*((u8 *) (((char *) gSelectState) + 0x249))) != 0)
  {
    memset(time_buf, 0, 0xA);
    text = textObjGet(1);
    {
    records = gRecords;
track=*((u16*)(records+0x1e)); course=*((u16*)(records+0x20)); val=gSlotTableB[track][course].speed[*((u16*)(records+0x22))];
 units=*((u16*)(records+0x50));
    }
 if (units == 0) { speed_whole = val / 1000; speed_frac = ((u32) (val % 1000)) / 100; format_to_buffer(time_buf, &D_800A541C, speed_whole & 0xFFFF, speed_frac & 0xFFFF); } else { speed_f = (f64) ((s32) val); if (((s32) val) < 0) { speed_f += D_800A5538; } speed_f *= D_800A5540; if (!(speed_f >= D_800A5548)) { val = (s32) speed_f; } else { val = (s32) (speed_f - D_800A5548); val |= 0x80000000; } speed_whole = val / 1000; speed_frac = ((u32) (val % 1000)) / 100; format_to_buffer(time_buf, &D_800A5428, speed_whole & 0xFFFF, speed_frac & 0xFFFF); } group_set_color(text, *((u8 *) (((char *) text) + 0xB)), *((u8 *) (((char *) text) + 0xC)), *((u8 *) (((char *) text) + 0xD)), (s32) (*((u8 *) (((char *) text) + 0xE)))); draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)(*((s16 *) (((char *) text) + 0x8))), (void *)(time_buf)); if (D_800A14D5 != 0) { text_obj_set_enabled(0xE); text = textObjGet(0xF); group_set_color(text, *((u8 *) (((char *) text) + 0xB)), *((u8 *) (((char *) text) + 0xC)), *((u8 *) (((char *) text) + 0xD)), (s32) (*((u8 *) (((char *) text) + 0xE)))); memset(rank_buf, 0, 2); if ((*((u16 *) (((char *) gRecords) + 0x1E))) == 0) { rank_byte = *((u8 *) (((char *) gRecords) + 0x30)); if (rank_byte == 0) { draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)(*((s16 *) (((char *) text) + 0x8))), (void *)(pool_get_item(gSelectStepHandle, 0x174))); } else { format_to_buffer(rank_buf, &D_800A5434, rank_byte); draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 6))), (s16)(*((s16 *) (((char *) text) + 8))), (void *)(rank_buf)); } } else { rank_byte = 3; format_to_buffer(rank_buf, &D_800A5434, rank_byte); draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)(*((s16 *) (((char *) text) + 0x8))), (void *)(rank_buf)); } } else { text_obj_set_disabled(0xE); } if ((*((s16 *) (((char *) gLeague) + 0x2))) != 4) { text = textObjGet(0x10); i = 0; do { idx = i & 0xFF; idx_plus1 = idx + 1; format_to_buffer(line_buf, &D_800A54FC, idx_plus1, gSlotTableB[((Manager*)gRecords)->track][((Manager*)gRecords)->course].times[((Manager*)gRecords)->slot][idx].name); i += 1; draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)((s16) ((*((s16 *) (((char *) text) + 0x8))) + (idx * 0x16))), (void *)(line_buf)); } while (((u32) (i & 0xFF)) < 3U); text = textObjGet(0x12); obj_b = textObjGet(0x11); i = 0;
 do { idx = i & 0xFF;
 row_time = gSlotTableB[((Manager*)gRecords)->track][((Manager*)gRecords)->course].times[((Manager*)gRecords)->slot][idx].time; memset(line_buf, 0, 0xF);
 func_80052E94(row_time, line_buf);
 draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)((s16) ((*((s16 *) (((char *) text) + 0x8))) + (idx * 0x16))), (void *)(line_buf));
 if (idx == 0) { prev_time = row_time; } else { memset(line_buf, 0, 0xF); __builtin_memcpy(line_buf, &D_800A5504, 3); func_80052E94(row_time - prev_time, (s16 *) (&line_buf[2])); appendString(line_buf, &D_800A5508); draw_palette_sprite((void *)(obj_b), (s16)(*((s16 *) (((char *) obj_b) + 0x6))), (s16)((s16) ((*((s16 *) (((char *) obj_b) + 0x8))) + ((idx - 1) * 0x16))), (void *)(line_buf)); } i += 1;
 } while (((u32) (i & 0xFF)) < 3U);
 } else if ((*((u16 *) (((char *) gRecords) + 0x22))) != 0) { text_obj_set_enabled(0x14); text_obj_set_enabled(0x18); text_obj_set_enabled(0x19); text_obj_set_enabled(0x1A); text = textObjGet(0x10); memset(line_buf, 0, 0x10); i = 0;  do { j = i & 0xFF; format_to_buffer(line_buf, &D_800A54FC, j + 1, (VRALValue) (gRecords + (((*((u8 *) (((char *) (gRecords + (getRankedIndex(j) & 0xFF))) + 0x32))) * 0x28) + 0x44))); draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)((s16) ((*((s16 *) (((char *) text) + 0x8))) + (j * 0x16))), (void *)(line_buf)); i += 1;  } while (((u32) (i & 0xFF)) < 4U); text = textObjGet(0x12); obj_c = textObjGet(0x11);

  rank_row = 0;

 do { j = 0;

 row_time = 0;

 if ((*((u16 *) (((char *) gRecords) + 0x22))) != 0) { do { term = D_800B6718[(j & 0xFF)][(getRankedIndex(rank_row & 0xFF)&0xff)];

 j += 1;

 row_time += term;

 } while (((u32) (j & 0xFF)) < ((u16) (*((u16 *) (((char *) gRecords) + 0x22))))); }

 memset(line_buf, 0, 0x10);

 func_80052E94(row_time, line_buf);

 idx = rank_row & 0xFF;

 draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)((s16) ((*((s16 *) (((char *) text) + 0x8))) + (idx * 0x16))), (void *)(line_buf));

 if (idx == 0) { prev_time = row_time;

 } else { memset(line_buf, 0, 0x10);

 __builtin_memcpy(line_buf, &D_800A5504, 3);

 func_80052E94(row_time - prev_time, (s16 *) (&line_buf[2]));

 appendString(line_buf, &D_800A5508);

 draw_palette_sprite((void *)(obj_c), (s16)(*((s16 *) (((char *) obj_c) + 0x6))), (s16)((s16) ((*((s16 *) (((char *) obj_c) + 0x8))) + ((idx - 1) * 0x16))), (void *)(line_buf));

 } rank_row += 1;

 } while (((u32) (rank_row & 0xFF)) < 4U);

 } else { text_obj_set_disabled(0x18); text_obj_set_disabled(0x14); text_obj_set_disabled(0x19); text_obj_set_disabled(0x1A); } memset(time_buf, 0, 0xA); text = textObjGet(3); if ((*((u16 *) (((char *) gRecords) + 0x50))) == 0) { time_val = ((u32) ((val * gRecordTimeScale) * 0xE10)) / ((u32) (D_800A14DC * 0x3E8)); format_to_buffer(time_buf, &D_800A5524, time_val & 0xFFFF); } else { time_val = ((u32) ((val * gRecordTimeScale) * 0xE10)) / ((u32) (D_800A14DC * 0x3E8)); format_to_buffer(time_buf, &D_800A552C, time_val & 0xFFFF); } group_set_color(text, *((u8 *) (((char *) text) + 0xB)), *((u8 *) (((char *) text) + 0xC)), *((u8 *) (((char *) text) + 0xD)), (s32) (*((u8 *) (((char *) text) + 0xE)))); draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)(*((s16 *) (((char *) text) + 0x8))), (void *)(time_buf)); text = textObjGet(0x15); group_set_color(text, *((u8 *) (((char *) text) + 0xB)), *((u8 *) (((char *) text) + 0xC)), *((u8 *) (((char *) text) + 0xD)), (s32) (*((u8 *) (((char *) text) + 0xE)))); 
    draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)(*((s16 *) (((char *) text) + 0x8))), (void *)(pool_get_item(gSelectStepHandle, (*((u16 *) (((char *) gRecords) + 0x22))) + 0x21A)));
    text = textObjGet(0x16);
    group_set_color(text, *((u8 *) (((char *) text) + 0xB)), *((u8 *) (((char *) text) + 0xC)), *((u8 *) (((char *) text) + 0xD)), (s32) (*((u8 *) (((char *) text) + 0xE))));
    format_to_buffer(line_buf, &D_800A5418, pool_get_item(gSelectStepHandle, (u8)gSlotTableB[((Manager*)gRecords)->track][((Manager*)gRecords)->course].times[((Manager*)gRecords)->slot][0].name[5] + 0x1E4));
    draw_palette_sprite((void *)(text), (s16)(*((s16 *) (((char *) text) + 0x6))), (s16)(*((s16 *) (((char *) text) + 0x8))), (void *)(line_buf));
  }
  if ((*((u8 *) (((char *) gSelectState) + 0x249))) == 1)
  {
    D_800A0370 = D_800A155C;
    D_800A0372 = D_800A155E;
    D_800A0374 = D_800A1560;
    D_800A0376 = D_800A1562;
  }
  g_camera = find_object_by_id(3);
  view_set_rect(((Actor*)g_camera)->model, &D_800A155C);
  *((Vec3Word *) (g_camera + 0x118)) = *((Vec3Word *) (&D_800A156C));
  *((Vec3Word *) (g_camera + 0x124)) = *((Vec3Word *) (&D_800A1578));
  *((s32 *) (((char *) g_camera) + 0x130)) = 0;
  *((f32 *) (((char *) g_camera) + 0x134)) = 100.0f;
  *((s32 *) (((char *) g_camera) + 0x138)) = 0;
  *((f32 *) (((char *) g_camera) + 0x10C)) = 0.4f;
  *((f32 *) (((char *) g_camera) + 0x110)) = 0.4f;
  *((f32 *) (((char *) g_camera) + 0x114)) = 1.0f;
  camera_refresh_and_copy(g_camera, &D_800A155C);
  gfx = view_get_ctx_id(((Actor*)g_camera)->model);
  dl = gfx_get_dl(gfx);
  ident = hud_ident_mtx;
  cam = g_camera;
  guMtxIdent(ident);
#ifdef PORT
{ uintptr_t *w=(uintptr_t *)dl; w[0]=0xDB0E0000; w[1]=(uintptr_t)(*((u16 *) ((char*)cam+0x104))); dl+=16; }
#else
{ void *p=dl; dl+=8; *(s32*)p=0xDB0E0000; *(s32*)((char*)p+4)=(u32)(*((u16 *) ((char*)cam+0x104))); }
#endif
#ifdef PORT
{ uintptr_t *w=(uintptr_t *)dl; w[0]=0xDA380003; w[1]=(uintptr_t)ident; dl+=16; }
#else
{ void *p=dl; dl+=8; *(s32*)p=0xDA380003; *(s32*)((char*)p+4)=(u32)ident; }
#endif
#ifdef PORT
{ uintptr_t *w=(uintptr_t *)dl; w[0]=0xE7000000; w[1]=0; dl+=16; }
#else
{ void *p=dl; dl+=8; *(s32*)p=0xE7000000; *(s32*)((char*)p+4)=0; }
#endif
#ifdef PORT
{ uintptr_t *w=(uintptr_t *)dl; w[0]=0xD9FFF9FF; w[1]=0; dl+=16; }
#else
{ void *p=dl; dl+=8; *(s32*)p=0xD9FFF9FF; *(s32*)((char*)p+4)=0; }
#endif
  gfx_set_dl(gfx,dl);
  cam_mtx = cam + 0x38;
  gfx_draw_fill_rect(((Actor*)g_camera)->model, &D_800A1564, &D_800A161C);
  val = mtx_pool_alloc();
  base_vec=&D_800A1584;
  ((f32*)base_vec)[2] += 1.0f;
  zero_slot=&D_800A159C[13];
  zero_base=zero_slot-13;
  base_vec[0] = 0;
  base_vec[1] = 0;
  *zero_slot=0;

  func_8001C1A8(base_vec, zero_base);
  obj_mtx_visible(val, cam_mtx, zero_base);
  gfx_push_mtx(gfx, val);
 {
  void *command_ptr;
  command_ptr = ((Packet*)gfx)->cursor;

  ((Packet*)gfx)->cursor = (void *) (command_ptr + 8);
  ((Command*)command_ptr)->w0 = 0xFB000000;
  ((Command*)command_ptr)->w1 = -1;

 }
  draw_item_bar(((Actor*)g_camera)->model, 2, 1.6f, 0, 0xFF);
  actor=g_camera;
  cur = ((Packet*)gfx)->cursor;

  ((Packet*)gfx)->cursor = (void *) (cur + 8);
  ((Command*)cur)->w0 = 0xFB000000;
  ((Command*)cur)->w1 = 0xFF;
  draw_item_bar(((Actor*)actor)->model, 0, 1.4f, 0, 0xFF);
  val = mtx_pool_alloc();
  func_8001C1A8(base_vec, &D_800A15DC);
  obj_mtx_visible(val, cam_mtx, &D_800A15DC);
  gfx_push_mtx(gfx, val);
  cur2 = ((Packet*)gfx)->cursor;

  ((Packet*)gfx)->cursor = (void *) (cur2 + 8);
  ((Command*)cur2)->w0 = 0xFB000000;
  ((Command*)cur2)->w1 = 0xC4C4C4FF;
  draw_item_bar(((Actor*)g_camera)->model, 0, 1.4f, 0, 0xFF);
  if ((*((u8 *) (((char *) gSelectState) + 0x249))) != 0)
  {
    func_8005D4A4(0);
    func_8004CF7C(D_800D05D8, 1, 0x1E, 0x28, 3.0f, 0, 0x80);
  }
}
