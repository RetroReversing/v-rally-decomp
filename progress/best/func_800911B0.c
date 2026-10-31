typedef struct {
    u16 flags; u16 pad; s32 buffer; struct Mode *mode; s32 control; u8 pad10[16];
    u32 xscale; f32 yfactor; u16 origin; u16 pad2a; u32 yscale;
} Obj;
typedef struct Mode {
    u32 unk0, unk4, width, burst, vsync, hsync, leap, hvideo, xscale, unk24;
    struct { u32 origin, yscale, vvideo, vburst, vintr; } f[2];
} Mode;
extern Obj *D_800A3A34, *D_800A3A30;
extern s32 D_800A258C;
extern volatile u32 D_A4400000;
extern s32 osVirtualToPhysical(s32);
void func_800911B0(void) {
    Obj *prev;
    Obj *cur;
    Mode *mode;
    s32 field, origin, hvideo, vvideo, ctrl;
    u32 scaled;
    cur = D_800A3A34;
    field = (*(volatile u32 *)0xA4400010) & 1;
    mode = cur->mode;
    origin = osVirtualToPhysical(cur->buffer) + mode->f[field].origin;
    if (cur->flags & 2) cur->xscale |= mode->xscale & ~0xFFFu;
    else cur->xscale = mode->xscale;
    if (cur->flags & 4) {
        scaled = (u32)(cur->yfactor * (f32)(mode->f[field].yscale & 0xFFF));
        cur->yscale = scaled;
        cur->yscale = scaled | (mode->f[field].yscale & ~0xFFFu);
    } else cur->yscale = mode->f[field].yscale;
    hvideo = mode->hvideo;
    vvideo = mode->f[field].vvideo - (D_800A258C << 16) + D_800A258C;
    hvideo &= -((cur->flags & 0x20) == 0);
    if (cur->flags & 0x40) { cur->yscale = 0; origin = osVirtualToPhysical(cur->buffer); }
    if (cur->flags & 0x80) {
        cur->yscale = ((u32)cur->origin << 16) & 0x03FF0000;
        origin = osVirtualToPhysical(cur->buffer);
    }
    *(volatile u32 *)0xA4400004 = origin;
    *(volatile u32 *)0xA4400008 = mode->width;
    *(volatile u32 *)0xA4400014 = mode->burst;
    *(volatile u32 *)0xA4400018 = mode->vsync;
    *(volatile u32 *)0xA440001C = mode->hsync;
    *(volatile u32 *)0xA4400020 = mode->leap;
    *(volatile u32 *)0xA4400024 = hvideo;
    *(volatile u32 *)0xA4400028 = vvideo;
    *(volatile u32 *)0xA440002C = mode->f[field].vburst;
    *(volatile u32 *)0xA440000C = mode->f[field].vintr;
    *(volatile u32 *)0xA4400030 = cur->xscale;
    *(volatile u32 *)0xA4400034 = cur->yscale;
    ctrl = cur->control;
    prev = D_800A3A30;
    D_800A3A30 = cur;
    D_800A3A34 = prev;
    D_A4400000 = ctrl;
    __builtin_memcpy(prev, cur, sizeof(Obj));
}
