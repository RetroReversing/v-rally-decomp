typedef struct Pos {
    u8 pad00[8];
    s16 xA;
    s16 x8;
    s16 xC;
    s16 xE;
} Pos;
typedef struct Obj {
    u8 pad00[0xC];
    s32 type;
    u8 pad10[0x178 - 0x10];
    Pos *pos;
} Obj;
typedef struct Widget {
    u8 pad00[0x7A];
    s16 kind;
    u8 pad7C[0xA4 - 0x7C];
    s32 text;
    Obj *obj;
} Widget;
typedef struct Slot {
    u8 flags;
    u8 pad[0x27];
} Slot;
typedef struct Game {
    u8 pad00[0xE];
    u16 mode;
    u8 pad10[2];
    u16 opts;
    u8 pad14[0x1E - 0x14];
    u16 state;
    u8 pad20[0x31 - 0x20];
    u8 order[3];
    u8 pad34[0x48 - 0x34];
    Slot slots[1];
} Game;
extern Game *D_800C35A0;
extern Obj *D_800C7F84;
extern void func_8003BA9C();
extern s32 func_80034FF0(s32, s32);
extern Widget *func_80040260(s32, s16, s16, u16, void *, s32);
extern Obj *func_8004240C(s32);

void func_8003970C(s32 arg0, s32 arg1, s32 arg2)
{
    Obj *obj;
    Pos *pos;
    Widget *w;
    u32 i;
    s32 k;
    s32 x;
    s32 y;
    s32 dx;
    u32 px;
    u32 py;
    s32 ey;

    if (D_800C35A0->state == 7) {
        return;
    }
    switch (D_800C35A0->mode) {
    case 1:
        if (!(D_800C35A0->slots[D_800C35A0->order[1]].flags & 2)) {
            return;
        }
        D_800C7F84 = func_8004240C(1);
        x = D_800C7F84->pos->xC;
        y = D_800C7F84->pos->xE;
        w = func_80040260(arg0, x - 0x32, y - 0x10, arg2, func_8003BA9C, 0);
        w->text = func_80034FF0(arg1 + 0x4C, 0);
        w->obj = D_800C7F84;
        w = func_80040260(arg0, x - 0x46, y - 0x20, arg2, 0, 0);
        w->text = func_80034FF0(arg1 + 0x4C, 0);
        w->kind = 2;
        break;
    case 2:
        for (i = 1, k = 1; i < 3; i++, k += 2) {
            if (D_800C35A0->slots[D_800C35A0->order[i]].flags & 2) {
                obj = func_8004240C(k);
                pos = obj->pos;
                D_800C7F84 = obj;
                dx = 0;
                ey = pos->xE - 8;
                x = pos->xC - 0x10;
                px = pos->x8 + 0x14;
                py = pos->xA + 6;
                if (!(D_800C35A0->opts & 1)) {
                    x = pos->xC - 0x20;
                    dx = (obj->type == 1) ? 0x14 : 0;
                }
                px += x;
                py += ey;
                w = func_80040260(arg0, px - 0x1A + dx, py - 0xA, arg2, func_8003BA9C, 0);
                w->text = func_80034FF0(arg1 + 0x4C, 0);
                w->kind = 4;
                w->obj = D_800C7F84;
                w = func_80040260(arg0, px - 0x28 + dx, py - 0x15, arg2, 0, 0);
                w->text = func_80034FF0(arg1 + 0x4C, 0);
                w->kind = 3;
            }
        }
        break;
    }
}
