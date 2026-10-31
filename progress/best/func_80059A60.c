typedef struct Style {
    struct Style *next;
    u16 id;
    s16 x;
    s16 y;
    u8 pad0A;
    u8 r, g, b, a;
    u8 pad0F[0x1A - 0xF];
    u8 visible;
    u8 mode;
} Style;

typedef struct Widget {
    struct Widget *next;
    u8 sub[0x24];
    Style *styles;
    u8 pad2C[0x41 - 0x2C];
    u8 active;
    u8 mode;
    u8 pad43[0x4D - 0x43];
    u8 nstyles;
    u8 useStyleMode;
} Widget;

typedef struct Group {
    struct Group *next;
    u16 w0;
    u16 w1;
    u8 b8;
    s8 b9;
    u8 active;
} Group;

typedef struct Task {
    u8 pad[0x10];
    void *arg;
    void (*fn)(void *);
} Task;

typedef struct Menu {
    Style *styles;
    u8 pad4[4];
    s32 nstyles;
    Widget *widgets;
    u8 pad10[4];
    s32 nwidgets;
    Group *groups;
    u8 pad1C[4];
    s32 ngroups;
    Group *groups2;
    u8 pad28[4];
    s32 ngroups2;
    u8 pad30[0x222 - 0x30];
    s16 f222;
    u8 pad224[0x232 - 0x224];
    u8 f232;
    s8 f233;
    u8 pad234[0x249 - 0x234];
    u8 f249;
    u8 pad24A;
    s8 f24B;
    u8 pad24C;
    u8 f24D;
    u8 pad24E[0x28C - 0x24E];
    void (*callback)(void);
    u8 pad290[0x2BD - 0x290];
    s8 f2BD;
} Menu;

extern Menu *D_800A1468;
extern Task *D_800C5D20[];
extern void *D_800C7F84;
extern u8 D_800C02AE[];
extern void *func_8004240C(s32);
extern void func_80047B54(void *, u16, s32, s32);
extern void func_8005BCD4(void);
extern void func_800599D0(void *, u8);
extern Style *func_800592D0(s32);
extern Widget *func_800592AC(u16);
extern void func_80059618(Style *, u8, u8, u8, u8);
extern void *func_80057918(s32, u16);
extern void func_800596F4(Style *, s16, s16, void *);

void func_80059A60(void)
{
    u8 i;
    u8 j;
    u8 n;
    s32 which;
    Style *s;
    Widget *w;
    Group *g;
    u8 *flags;

    if (D_800A1468->f232 && D_800A1468->f233 >= 0) {
        func_80047B54(func_8004240C(0), D_800A1468->f233, 0, 0);
    }
    if (D_800A1468->f249) {
        for (i = 0; i < 5; i++) {
            if (D_800C5D20[i] == NULL) {
                continue;
            }
            switch (i) {
            case 0:
                which = 2;
                break;
            case 1:
                which = 2;
                break;
            default:
                which = 1;
                break;
            }
            D_800C7F84 = func_8004240C(which);
            if (i != 1 || !D_800A1468->f24D) {
                D_800C5D20[i]->fn(D_800C5D20[i]->arg);
            }
        }
    }
    if (D_800A1468->callback) {
        D_800A1468->callback();
    }
    if (D_800A1468->f249 && D_800A1468->f222 >= 0) {
        func_8005BCD4();
    }
    if (D_800A1468->nstyles && D_800A1468->f249) {
        n = D_800A1468->nstyles;
        s = D_800A1468->styles;
        for (i = 0; i < n; i++, s = s->next) {
            if (s->visible) {
                func_800599D0(s, s->mode);
            }
        }
    }
    if (D_800A1468->nwidgets) {
        n = D_800A1468->nwidgets;
        w = D_800A1468->widgets;
        for (i = 0; i < n; i++, w = w->next) {
            flags = &w->active;
            if (*flags) {
                func_800599D0(w->sub, w->mode);
                if (!w->useStyleMode || w->mode) {
                    s = w->styles;
                    for (j = 0; j < w->nstyles; s = s->next, j++) {
                        if (s->visible) {
                            u8 hl;
                            if (w->useStyleMode) {
                                hl = s->mode;
                            } else {
                                hl = flags[1];
                            }
                            if (hl) {
                                func_80059618(s, 220, 220, 14, 255);
                            } else {
                                func_80059618(s, s->r, s->g, s->b, s->a);
                            }
                            func_800596F4(s, s->x, s->y, func_80057918(*(s32 *)(D_800C02AE + 0x807A), s->id));
                        }
                    }
                }
            }
        }
    }
    if (D_800A1468->ngroups) {
        n = D_800A1468->ngroups;
        g = D_800A1468->groups;
        for (i = 0; i < n; i++) {
            if (g->active) {
                D_800A1468->f24D = 0;
                s = func_800592D0(g->b9);
                for (j = 0; j < g->b8; j++, s = s->next) {
                    func_800599D0(s, s->mode);
                }
                w = func_800592AC(g->w0);
                func_800599D0(w->sub, w->mode);
                w = func_800592AC(g->w1);
                func_800599D0(w->sub, w->mode);
                D_800A1468->f24D = 1;
            }
        }
    }
    if (D_800A1468->ngroups2) {
        n = D_800A1468->ngroups2;
        g = D_800A1468->groups2;
        for (i = 0; i < n; i++) {
            if (g->active) {
                D_800A1468->f24D = 0;
                if (g->b9) {
                    s = func_800592D0(g->b8);
                    for (j = 0; j < g->b9; j++, s = s->next) {
                        func_800599D0(s, s->mode);
                    }
                }
                w = func_800592AC(g->w0);
                for (j = 0; j < g->w1; j++, w = w->next) {
                    func_800599D0(w->sub, w->mode);
                }
                D_800A1468->f24D = 1;
            }
        }
    }
    if (D_800A1468->f24B >= 0) {
        D_800A1468->f24B--;
    }
    if (D_800A1468->f2BD >= 0 && D_800A1468->f249) {
        D_800A1468->f249--;
    }
}
