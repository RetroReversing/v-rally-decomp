typedef void (*SpriteHook)(void *);
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
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
void *func_80034FF0(s32, s32);
void func_8003B614(void *);
void func_8003B884(void *);
void func_8003CC50(void *);
void func_8003CC98(void *);

void func_80039A00(s32 ctx, s32 menu)
{
    GState *g = D_800C35A0;
    u32 i;
    s32 yy, ww, hh;
    u32 count;
    s32 off;
    s32 x;
    Node *node;
    Rect *r;
    Obj *obj, *obj2;
    s32 y, w, ix, by;
    s16 px, py;

    if (g->mode == 7)
        return;
    off = 0;
    i = 1;
    count = g->count;
    if (count == 0)
        return;
#define base (menu + 0x4C)
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
                    if (!(g->entries[g->sel[1]].flags & 1)) goto flags4; {
                        px = w - 0x47;
                        py = y + 0x11;
                        obj = ((Obj *)func_80040260((void *)(ctx), px, py, (s16)(5), func_8003CC50, 1));
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                        obj = ((Obj *)func_80040260((void *)(ctx), px, py, (s16)(5), func_8003CC98, 1));
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unk7A = 5;
                        obj->unkA8 = D_800C7F84;
                        obj = ((Obj *)func_80040260((void *)(ctx), w - 0x31, py, (s16)(5), func_8003CC98, 1));
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                    }
                }
                g = D_800C35A0;
                {s32 index=((volatile GState*)g)->sel[1]; index=index*5; index <<=3; g=(GState*)((u8*)g+index); if(g->entries[0].flags & 1) {
                    py = y + 7;
                    obj = ((Obj *)func_80040260((void *)(ctx), (u16)ww + (u16)-0x4D, py, (s16)(5), (SpriteHook)(NULL), 1));
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj = ((Obj *)func_80040260((void *)(ctx), w - 0x74, py, (s16)(5), (SpriteHook)(NULL), 1));
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj->unk7A = 1;
                    obj = ((Obj *)func_80040260((void *)(ctx), x + 0x32, py, (s16)(5), (SpriteHook)(NULL), 1));
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj->unk7A = 1;
                }}
flags4:
                g = D_800C35A0;
                {s32 index=((volatile GState*)g)->sel[1]; index=index*5; index <<=3; g=(GState*)((u8*)g+index); if(g->entries[0].flags & 4) {
                    by = yy + hh;
                    obj = ((Obj *)func_80040260((void *)(ctx), ix, by - 0x12, (s16)(5), func_8003B884, 1));
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj->unk76 = 4;
                    obj->unkA8 = D_800C7F84;
                    obj2 = ((Obj *)func_80040260((void *)(ctx), ix + 0x14, by - 0x44, (s16)(5), (SpriteHook)(NULL), 1));
                    obj2->unkA4 = func_80034FF0(base, 0);
                    obj2->unk7A = 4;
                    obj2->unkA8 = D_800C7F84;
                    obj->unk8C = obj2;
                }}
            } else {
                if (g->entries[g->sel[1]].flags & 1) {
                    if (D_800ADFE1) {
                        px = w - 0x47;
                        py = y + 0x11;
                        obj = ((Obj *)func_80040260((void *)(ctx), px, py, (s16)(5), func_8003CC98, 1));
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unk7A = 5;
                        obj->unkA8 = D_800C7F84;
                        obj = ((Obj *)func_80040260((void *)(ctx), w - 0x31, py, (s16)(5), func_8003CC98, 1));
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                        obj = ((Obj *)func_80040260((void *)(ctx), px, py, (s16)(5), func_8003CC50, 1));
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                    } else {
                        obj = ((Obj *)func_80040260((void *)(ctx), w - 0x47, y + 0x11, (s16)(5), (SpriteHook)(NULL), 1));
                        obj->unkA4 = func_80034FF0(menu + 0x4C, 0);
                        obj->unkA8 = D_800C7F84;
                    }
                    py = (u16)(yy + hh) + (u16)-0x17;
                    obj = ((Obj *)func_80040260((void *)(ctx), ix + 0xA, py, (s16)(5), func_8003B614, 1));
                    obj->unkA4 = func_80034FF0(base, 0);
                    obj->unk7A = 1;
                    obj->unkA8 = D_800C7F84;
                    obj = ((Obj *)func_80040260((void *)(ctx), ix + 0x21, py, (s16)(5), func_8003B614, 1));
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
                        obj = ((Obj *)func_80040260((void *)(ctx), ix, py, (s16)(5), func_8003CC98, 1));
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unk7A = 5;
                        obj->unkA8 = D_800C7F84;
                        obj = ((Obj *)func_80040260((void *)(ctx), ix + 0x17, py, (s16)(5), func_8003CC98, 1));
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unkA8 = D_800C7F84;
                        obj = ((Obj *)func_80040260((void *)(ctx), ix - off, y + 7, (s16)(5), (SpriteHook)(NULL), 1));
                        obj->unkA4 = func_80034FF0(base, 0);
                        obj->unk7A = 1;
                    }
                } else {
                    if (g->entries[g->sel[i]].flags & 1) {
                        off = (node->kind == 3) ? 14 : 0;
                        switch(node->kind){case 3:{
                            if (D_800ADFE1) {
                                s32 sx = ix + ww;
                                py = y + 0x11;
                                obj = ((Obj *)func_80040260((void *)(ctx), sx - 0x46, py, (s16)(5), func_8003CC98, 1));
                                obj->unkA4 = func_80034FF0(base, 0);
                                obj->unk7A = 5;
                                obj->unkA8 = D_800C7F84;
                                obj = ((Obj *)func_80040260((void *)(ctx), (u16)sx + (u16)-0x2F, py, (s16)(5), func_8003CC98, 1));
                                obj->unkA4 = func_80034FF0(base, 0);
                                obj->unkA8 = D_800C7F84;
                            }
                            obj = ((Obj *)func_80040260((void *)(ctx), ix + ww - 0x5E, y + 7, (s16)(5), (SpriteHook)(NULL), 1));
                            obj->unkA4 = func_80034FF0(menu + 0x4C, 0);
                            obj->unk7A = 1;
                        }break;default:{
                            if (D_800ADFE1) {
                                py = y + 0x11;
                                obj = ((Obj *)func_80040260((void *)(ctx), ix, py, (s16)(5), func_8003CC98, 1));
                                obj->unkA4 = func_80034FF0(base, 0);
                                obj->unkA8 = D_800C7F84;
                                obj->unk7A = 5;
                                obj = ((Obj *)func_80040260((void *)(ctx), x + 0x2B, py, (s16)(5), func_8003CC98, 1));
                                obj->unkA4 = func_80034FF0(base, 0);
                                obj->unkA8 = D_800C7F84;
                            }
                            obj = ((Obj *)func_80040260((void *)(ctx), ix, y + 7, (s16)(5), (SpriteHook)(NULL), 1));
                            obj->unkA4 = func_80034FF0(menu + 0x4C, 0);
                            obj->unk7A = 1;
                        }break;}
                    }
                }
            } else {
                if (g->flags12 & 1) {
                    if (g->entries[g->sel[i]].flags & 1) {
                        if (node->kind == 1)
                            yy = y + 8;
                        if (D_800ADFE1) {
                            py = yy + hh - 0x15;
                            obj = ((Obj *)func_80040260((void *)(ctx), x, py, (s16)(5), func_8003CC98, 1));
                            obj->unkA4 = func_80034FF0(base, 0);
                            obj->unkA8 = D_800C7F84;
                            obj->unk7A = 5;
                            obj = ((Obj *)func_80040260((void *)(ctx), x + 0x17, py, (s16)(5), func_8003CC98, 1));
                            obj->unkA4 = func_80034FF0(base, 0);
                            obj->unkA8 = D_800C7F84;
                        }
                    }
                } else {
                    if (g->entries[g->sel[i]].flags & 1) {
                        if (node->kind == 3)
                            ix = x + 6;
                        if (D_800ADFE1) {
                            py = (u16)hh + (u16)-0x1D;
                            obj = ((Obj *)func_80040260((void *)(ctx), ix, py, (s16)(5), func_8003CC98, 1));
                            obj->unkA4 = func_80034FF0(base, 0);
                            obj->unk7A = 5;
                            obj->unkA8 = D_800C7F84;
                            obj = ((Obj *)func_80040260((void *)(ctx), ix + 0x17, py, (s16)(5), func_8003CC98, 1));
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
