typedef struct { u8 flags; u8 pad[0x27]; } GEntry;
typedef struct {
    u8 pad0[0xE]; u16 count; u8 pad10[2]; u16 flags12; u8 pad14[0xA]; u16 mode; u8 pad20[0x11]; u8 sel[0x17]; GEntry entries[1];
} GState;
extern GState *D_800C35A0;
typedef struct { s16 pad[4]; s16 x, y, w, h; } Rect;
typedef struct Node { u8 pad0[0xC]; s32 kind; u8 pad10[0x168]; Rect *rect; } Node;
extern Node *D_800C7F84;
typedef struct Obj { u8 pad0[0x76]; s16 unk76, unk78, unk7A; u8 pad7C[0x10]; struct Obj *unk8C; u8 pad90[0x14]; void *unkA4; Node *unkA8; } Obj;
extern u8 D_800ADFE0;
extern u8 D_800ADFE1;
typedef void (*Cb)();
Node *func_8004240C(s32);
Obj *func_80040260(s32, s16, s16, s16, Cb, s32);
void *func_80034FF0(s32, s32);
void func_8003B614();
void func_8003B884();
void func_8003CC50();
void func_8003CC98();

void func_80039A00(s32 ctx, s32 menu)
{
    GState *g = D_800C35A0;
    u32 i, count;
    s32 off;
    s32 base;
    Node *node;
    Rect *r;
    Obj *obj, *obj2;
    s32 x, y, w, ix, yy, hh, ww, by;
    s16 px, py;

    if (g->mode == 7)
        return;
    off = 0;
    i = 1;
    count = g->count;
    if (count == 0)
        return;
    base = menu + 0x4C;
    do {
        node = func_8004240C(((i - 1) * 2) | 1);
        r = node->rect;
        x = r->x;
        y = r->y;
        D_800C7F84 = node;
        ix = x + 20;
        yy = y + 6;
        w = r->w;
        ww = w - 16;
        hh = r->h - 8;
        g = D_800C35A0;
        switch (g->count) {
        case 1:
            if (g->mode == 0) {
                if (D_800ADFE0 >= 2) {
                    if (g->entries[g->sel[1]].flags & 1) {
                        px = w - 0x47;
                        py = y + 0x11;
                        obj = func_80040260(ctx, px, py, 5, func_8003CC50, 1);
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                        obj = func_80040260(ctx, px, py, 5, func_8003CC98, 1);
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unk7A = 5;
                        obj->unkA8 = D_800C7F84;
                        obj = func_80040260(ctx, w - 0x31, py, 5, func_8003CC98, 1);
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                    }
                }
                g = D_800C35A0;
                if (g->entries[g->sel[1]].flags & 1) {
                    py = y + 7;
                    obj = func_80040260(ctx, ww - 0x4D, py, 5, NULL, 1);
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj = func_80040260(ctx, w - 0x74, py, 5, NULL, 1);
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj->unk7A = 1;
                    obj = func_80040260(ctx, x + 0x32, py, 5, NULL, 1);
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj->unk7A = 1;
                }
                g = D_800C35A0;
                if (g->entries[g->sel[1]].flags & 4) {
                    by = yy + hh;
                    obj = func_80040260(ctx, ix, by - 0x12, 5, func_8003B884, 1);
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj->unk76 = 4;
                    obj->unkA8 = D_800C7F84;
                    obj2 = func_80040260(ctx, ix + 0x14, by - 0x44, 5, NULL, 1);
                    obj2->unkA4 = func_80034FF0(base, 0);
                    obj2->unk7A = 4;
                    obj2->unkA8 = D_800C7F84;
                    obj->unk8C = obj2;
                }
            } else {
                if (g->entries[g->sel[1]].flags & 1) {
                    if (D_800ADFE1) {
                        px = w - 0x47;
                        py = y + 0x11;
                        obj = func_80040260(ctx, px, py, 5, func_8003CC98, 1);
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unk7A = 5;
                        obj->unkA8 = D_800C7F84;
                        obj = func_80040260(ctx, w - 0x31, py, 5, func_8003CC98, 1);
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                        obj = func_80040260(ctx, px, py, 5, func_8003CC50, 1);
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                    } else {
                        obj = func_80040260(ctx, w - 0x47, y + 0x11, 5, NULL, 1);
                        obj->unkA4 = func_80034FF0(menu + 0x4C, 0);
                        obj->unkA8 = D_800C7F84;
                    }
                    py = yy + hh - 0x17;
                    obj = func_80040260(ctx, ix + 0xA, py, 5, func_8003B614, 1);
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj->unk7A = 1;
                    obj->unkA8 = D_800C7F84;
                    obj = func_80040260(ctx, ix + 0x21, py, 5, func_8003B614, 1);
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj->unkA8 = D_800C7F84;
                }
            }
            break;
        case 2:
            if (g->mode == 0) {
                if (g->flags12 & 1) {
                    ix = x;
                    if (g->entries[g->sel[i]].flags & 1) {
                        py = y + 0x11;
                        obj = func_80040260(ctx, ix, py, 5, func_8003CC98, 1);
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unk7A = 5;
                        obj->unkA8 = D_800C7F84;
                        obj = func_80040260(ctx, ix + 0x17, py, 5, func_8003CC98, 1);
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                        obj = func_80040260(ctx, ix - off, y + 7, 5, NULL, 1);
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unk7A = 1;
                    }
                } else {
                    if (g->entries[g->sel[i]].flags & 1) {
                        off = (node->kind == 3) ? 14 : 0;
                        if (node->kind == 3) {
                            if (D_800ADFE1) {
                                s32 sx = ix + ww;
                                py = y + 0x11;
                                obj = func_80040260(ctx, sx - 0x46, py, 5, func_8003CC98, 1);
                                obj->unkA4 = func_80034FF0(base, 0);
                                obj->unk7A = 5;
                                obj->unkA8 = D_800C7F84;
                                obj = func_80040260(ctx, sx - 0x2F, py, 5, func_8003CC98, 1);
                                obj->unkA4 = func_80034FF0(base, 0);
                                obj->unkA8 = D_800C7F84;
                            }
                            obj = func_80040260(ctx, ix + ww - 0x5E, y + 7, 5, NULL, 1);
                            obj->unkA4 = func_80034FF0(menu + 0x4C, 0);
                            obj->unk7A = 1;
                        } else {
                            if (D_800ADFE1) {
                                py = y + 0x11;
                                obj = func_80040260(ctx, ix, py, 5, func_8003CC98, 1);
                                obj->unkA4 = func_80034FF0(base, 0);
                                obj->unkA8 = D_800C7F84;
                                obj->unk7A = 5;
                                obj = func_80040260(ctx, x + 0x2B, py, 5, func_8003CC98, 1);
                                obj->unkA4 = func_80034FF0(base, 0);
                                obj->unkA8 = D_800C7F84;
                            }
                            obj = func_80040260(ctx, ix, y + 7, 5, NULL, 1);
                            obj->unkA4 = func_80034FF0(menu + 0x4C, 0);
                            obj->unk7A = 1;
                        }
                    }
                }
            } else {
                if (g->flags12 & 1) {
                    if (g->entries[g->sel[i]].flags & 1) {
                        if (node->kind == 1)
                            yy = y + 8;
                        if (D_800ADFE1) {
                            py = yy + hh - 0x15;
                            obj = func_80040260(ctx, x, py, 5, func_8003CC98, 1);
                            obj->unkA4 = func_80034FF0(base, 0);
                            obj->unkA8 = D_800C7F84;
                            obj->unk7A = 5;
                            obj = func_80040260(ctx, x + 0x17, py, 5, func_8003CC98, 1);
                            obj->unkA4 = func_80034FF0(base, 0);
                            obj->unkA8 = D_800C7F84;
                        }
                    }
                } else {
                    if (g->entries[g->sel[i]].flags & 1) {
                        if (node->kind == 3)
                            ix = x + 6;
                        if (D_800ADFE1) {
                            py = hh - 0x1D;
                            obj = func_80040260(ctx, ix, py, 5, func_8003CC98, 1);
                            obj->unkA4 = func_80034FF0(base, 0);
                            obj->unk7A = 5;
                            obj->unkA8 = D_800C7F84;
                            obj = func_80040260(ctx, ix + 0x17, py, 5, func_8003CC98, 1);
                            obj->unkA4 = func_80034FF0(base, 0);
                            obj->unkA8 = D_800C7F84;
                        }
                    }
                }
            }
            break;
        }
        i++;
    } while (i <= count);
}
