typedef struct {
    u8 pad0[6];
    s16 x;
    s16 y;
    u8 padA;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
} Win;
typedef struct {
    u8 pad0[0x37];
    u8 id;
    u8 pad38[8];
} Sub;
typedef struct {
    Sub sub[8];
    u8 pad200[0x2C];
    u32 vals[38];
} Rec;
typedef struct {
    u8 pad0[0x1E];
    u16 a;
    u16 b;
    u16 c;
    u8 pad24[0xC];
    u8 n;
    u8 pad31[0x1F];
    u16 mode;
} Cfg;
extern s32 gFadeDirection;
extern s32 D_800D05D8;
extern f32 D_800C6CF8;
extern s32 gSelectStepHandle;
extern Cfg *gRecords;
extern Rec *gSlotTableB[];
extern u8 D_800A14D5;
extern u8 gMaskSlot;
extern char D_800A5418[];
extern char D_800A541C[];
extern char D_800A5428[];
extern char D_800A5434[];
extern f64 D_800A5440;
s32 find_object_by_id();
s32 stream_draw_entry();
void func_8004CF7C(s32 arg0, u16 arg1, s16 arg2, s16 arg3, f32 arg4, u8 arg5, u16 arg6);
char *pool_get_item();void *textObjGet(u32);
void group_set_color(Win *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void draw_palette_sprite(void *, s16, s16, void *);void text_obj_set_enabled(u32);void func_8005A6E0(u32);
s32 memset();
s32 formatString();

/* Draws the results/best-time panel for the current record: the record name, the time
   (or the scaled time in mode 1), and the position/count line when the flag at
   D_800A14D5 is set. Clears the flag-dependent line otherwise. */
void func_8005D0B0(void)
{
    char name_buf[16];
    char count_buf[8];
    char time_buf[16];
    Win *win;
    u32 time_val;

    memset(name_buf, 0, 16);
    gFadeDirection = 0;
    if (gMaskSlot != 0) {
        stream_draw_entry(find_object_by_id(0), 0, 0, 0);
        gMaskSlot--;
    }
    func_8004CF7C(D_800D05D8, 0, 0x68, 0x4A, D_800C6CF8, 0, 0xFF);
    win = textObjGet(0);
    group_set_color(win, win->b, win->c, win->d, 0xFF);
    formatString(name_buf, D_800A5418, pool_get_item(gSelectStepHandle, gSlotTableB[gRecords->a][gRecords->b].sub[gRecords->c].id + 0x1E4));
    draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y), (void *)(name_buf));
    memset(time_buf, 0, 10);
    win = textObjGet(2);
    time_val = gSlotTableB[gRecords->a][gRecords->b].vals[gRecords->c];
    if (gRecords->mode == 0) {
        formatString(time_buf, D_800A541C, (u16)(time_val / 1000), (u16)(time_val % 1000 / 100));
    } else {
        time_val = time_val * D_800A5440;
        formatString(time_buf, D_800A5428, (u16)(time_val / 1000), (u16)(time_val % 1000 / 100));
    }
    group_set_color(win, win->b, win->c, win->d, win->e);
    draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y), (void *)(time_buf));
    if (D_800A14D5 != 0) {
        text_obj_set_enabled(0xD);
        win = textObjGet(0xE);
        memset(count_buf, 0, 2);
        group_set_color(win, win->b, win->c, win->d, win->e);
        if (gRecords->a == 0) {
            if (gRecords->n == 0) {
                draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y), (void *)(pool_get_item(gSelectStepHandle, 0x174)));
            } else {
                formatString(count_buf, D_800A5434, gRecords->n);
                draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y), (void *)(count_buf));
            }
        } else {
            formatString(count_buf, D_800A5434, 3);
            draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y), (void *)(count_buf));
        }
    } else {
        func_8005A6E0(0xD);
    }
}
