extern u8 D_80001D10[], D_80001DE0[];
extern s32 D_8009B6F0[], D_8009B6F4[];
extern u8 D_800C83D0[], D_800D03D0[];
extern u8 gStreamState[];
void func_8007F798(s32, s32, void *);
void osWritebackDCacheAll(void);

/* The OSTask as libultra lays it out (RSP task header). */
typedef struct {
    u32 type, flags;
    u8 *ucode_boot;
    u32 ucode_boot_size;
    s32 ucode, ucode_size, ucode_data, ucode_data_size;
    s32 dram_stack, dram_stack_size;
    u8 *output_buff, *output_buff_size;
    s32 data_ptr;
    s32 data_size;
    u8 *yield_data_ptr;
    s32 yield_data_size;
    u8 pad40[4];
    s32 unk44;
    s16 unk48;
    s16 unk4A;
} Task;

typedef struct { u32 w0, w1; } G;

/* Graphics context: display-list cursor and bounds, the task header and the
 * ucode mode (selects the ucode pair from the tables). */
typedef struct {
    u8 pad0[0xC];
    G *dl_end;
    G *dl_start;
    G *dl;
    u8 pad18[0x1C - 0x18];
    u16 mode;
    u8 pad1E[2];
    Task task;
    u8 pad6C[0x70 - 0x6C];
    u32 f70;
    u32 f74;
    u8 pad78[2];
    u16 f7A;
} Ctx;

/* Ends the display list with two end-of-list commands, fills the task header
 * for the ucode picked by c->mode, writes back the data cache and submits it. */
void func_8000DD40(Ctx *c)
{
    G *g;
    Task *t;
    s32 start;
    s32 size;

    c->task.unk44 = 0;
    { G *_g = c->dl++; _g->w0 = 0xE9000000; _g->w1 = 0; }
    { G *_g = c->dl++; _g->w0 = 0xDF000000; _g->w1 = 0; }
    t = &c->task;
    if ((u32)c->dl > (u32)c->dl_end) for (;;);
    if (c->f74 < c->f70 + (c->f7A << 4)) for (;;);
    g = c->dl;
    start = (s32)c->dl_start;
    t->type = 1;
    t->flags = 6;
    size = (s32)g - start;
    size >>= 3;
    size <<= 3;
    t->ucode_boot = D_80001D10;
    t->ucode_boot_size = D_80001DE0 - D_80001D10;
    t->data_ptr = start;
    t->data_size = size;
    t->ucode = D_8009B6F0[c->mode * 2];
    t->ucode_data = D_8009B6F4[c->mode * 2];
    t->ucode_size = 0x1000;
    t->ucode_data_size = 0x800;
    t->output_buff = D_800C83D0;
    t->output_buff_size = D_800D03D0;
    t->yield_data_ptr = gStreamState + 0x5E32;
    t->dram_stack = 0;
    t->dram_stack_size = 0;
    t->yield_data_size = 0xC00;
    switch (c->mode) {
    case 0: case 1: case 2: case 3: case 4:
        t->unk48 = 1;
        t->unk4A = -10;
        break;
    case 5:
        t->unk48 = 2;
        t->unk4A = 10;
        break;
    }
    osWritebackDCacheAll();
    func_8007F798(9, 1, t);
}
