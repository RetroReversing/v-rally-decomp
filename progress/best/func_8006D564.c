typedef struct Item {
    u8 pad[0x10];
} Item;
typedef struct Group {
    Item item[4];
} Group;
typedef struct Record {
    s32 w[5];
    u16 count;
    u8 pad16[0x2C - 0x16];
    Group groups[10];
    u8 pad2AC[0x18];
} Record;
typedef struct Slot {
    u8 pad00[0x28];
} Slot;
typedef struct Game {
    u8 pad00[0x1E];
    u16 mode;
    u16 sel;
    u16 sub;
    u8 pad24[0x44 - 0x24];
    u8 b44;
} Game;
extern Game *D_800C35A0;
extern Record *D_800D0634[5];
extern Group D_800C3750[12];
extern Group D_800C3650[4];
extern Item D_800C3A50[];
extern s8 D_800A16F0;
extern u8 D_800A57C0[];
extern void func_8006F820(Item *, u8);
extern void func_8006DD04(Group *);
extern void func_8006DDD8(void);
extern void func_8006D10C(void);
extern void func_8006C640(void);
extern void func_8006CE1C(void);
extern void func_8006CB9C(void);
extern void func_8006C99C(void);
extern void func_8006F4A8(u8);
extern void func_8006EE3C(u8);
extern void func_8006F0E0(u8);
extern void func_8006F75C(void);
extern void func_8002B618(u8 *, s32);
extern void func_8006F8E0(void);
extern void func_80054838(void);
extern void func_8005508C(void);

#define GROUP(p, j) ((Group *)((u8 *)(p) + ((j) * 0x40 + 0x2C)))

void func_8006D564(s32 arg0)
{
    Record *r;
    Group *g;
    u8 i;
    u8 j;
    u8 *p;
    u8 k;
    u8 mode;
    u8 sel;
    u8 sub;

    mode = D_800C35A0->mode;
    sel = D_800C35A0->sel;
    sub = D_800C35A0->sub;
    for (i = 0; i < 8; i++) {
        r = &D_800D0634[0][i];
        for (j = 0; j < r->count; j++) {
            k = 0;
            g = GROUP(r, j);
            for (; k < 3; k++) {
                func_8006F820(&g->item[k], arg0);
            }
            D_800C35A0->mode = 0;
            D_800C35A0->sel = i;
            D_800C35A0->sub = j;
            func_8006DDD8();
        }
    }
    for (j = 0; j < 4; j++) {
        p = (u8 *)D_800D0634[1];
        k = 0;
        p = (u8 *)GROUP(p, j);
        for (; k < 3; k++) {
            func_8006F820(&((Group *)p)->item[k], arg0);
        }
        D_800C35A0->mode = 1;
        D_800C35A0->sel = 0;
        D_800C35A0->sub = j;
        func_8006D10C();
    }
    for (j = 0; j < 5; j++) {
        p = (u8 *)D_800D0634[2];
        k = 0;
        p = (u8 *)GROUP(p, j);
        for (; k < 3; k++) {
            func_8006F820(&((Group *)p)->item[k], arg0);
        }
        D_800C35A0->mode = 2;
        D_800C35A0->sel = 0;
        D_800C35A0->sub = j;
        func_8006D10C();
    }
    for (j = 0; j < 6; j++) {
        p = (u8 *)D_800D0634[3];
        k = 0;
        p = (u8 *)GROUP(p, j);
        for (; k < 3; k++) {
            func_8006F820(&((Group *)p)->item[k], arg0);
        }
        D_800C35A0->mode = 3;
        D_800C35A0->sel = 0;
        D_800C35A0->sub = j;
        func_8006D10C();
    }
    for (j = 0; j < 3; j++) {
        p = (u8 *)D_800D0634[4];
        k = 0;
        p = (u8 *)GROUP(p, j);
        for (; k < 3; k++) {
            func_8006F820(&((Group *)p)->item[k], arg0);
        }
        D_800C35A0->mode = 4;
        D_800C35A0->sel = 0;
        D_800C35A0->sub = j;
        func_8006D10C();
    }
    for (i = 0; i < 12; i++) {
        for (k = 0; k < 3; k++) {
            func_8006F820(&D_800C3750[i].item[k], arg0);
        }
        D_800C35A0->sel = i;
        func_8006C640();
    }
    for (i = 0; i < 4; i++) {
        for (k = 0; k < 3; k++) {
            func_8006F820(&D_800C3650[i].item[k], arg0);
        }
        func_8006CE1C();
    }
    for (k = 0; k < 3; k++) {
        func_8006F820(&D_800C3A50[k], arg0);
        func_8006CB9C();
        func_8006F820(&D_800C3A50[k + 12], arg0);
        func_8006C99C();
    }
    D_800C35A0->mode = mode;
    D_800C35A0->sel = sel;
    D_800C35A0->sub = sub;
    func_8006F4A8(arg0);
    func_8006EE3C(arg0);
    ((struct { u8 pad[0x44]; Slot s[4]; } *)D_800C35A0)->s[(u8)arg0].pad00[0] = 0x5B;
    func_8006F0E0(arg0);
    func_8006F75C();
    D_800A16F0 = j = 0;
    func_8002B618(D_800A57C0, 0);
    func_8006F8E0();

    mode = D_800C35A0->mode;
    sel = D_800C35A0->sel;
    sub = D_800C35A0->sub;
    for (i = 0; i < 8; i++) {
        p = (u8 *)&D_800D0634[0][i];
        for (j = 0; j < ((Record *)p)->count; j++) {
            D_800C35A0->mode = 0;
            D_800C35A0->sel = i;
            D_800C35A0->sub = j;
            func_8006DD04(GROUP(p, j));
            func_8006DDD8();
        }
    }
    for (j = 0; j < 4; j++) {
        D_800C35A0->mode = 1;
        D_800C35A0->sel = 0;
        D_800C35A0->sub = j;
        p = (u8 *)D_800D0634[1];
        func_8006DD04(GROUP(p, j));
        func_8006D10C();
    }
    for (j = 0; j < 5; j++) {
        D_800C35A0->mode = 2;
        D_800C35A0->sel = 0;
        D_800C35A0->sub = j;
        p = (u8 *)D_800D0634[2];
        func_8006DD04(GROUP(p, j));
        func_8006D10C();
    }
    for (j = 0; j < 6; j++) {
        D_800C35A0->mode = 3;
        D_800C35A0->sel = 0;
        D_800C35A0->sub = j;
        p = (u8 *)D_800D0634[3];
        func_8006DD04(GROUP(p, j));
        func_8006D10C();
    }
    for (j = 0; j < 3; j++) {
        D_800C35A0->mode = 4;
        D_800C35A0->sel = 0;
        D_800C35A0->sub = j;
        p = (u8 *)D_800D0634[4];
        func_8006DD04(GROUP(p, j));
        func_8006D10C();
    }
    for (i = 0; i < 12; i++) {
        D_800C35A0->sel = i;
        func_8006DD04(&D_800C3750[i]);
        func_8006C640();
    }
    for (i = 0; i < 4; i++) {
        func_8006DD04(&D_800C3650[i]);
        func_8006CE1C();
    }
    func_8006DD04((Group *)D_800C3A50);
    func_8006CB9C();
    func_8006DD04((Group *)&D_800C3A50[12]);
    func_8006C99C();
    D_800C35A0->mode = mode;
    D_800C35A0->sel = sel;
    D_800C35A0->sub = sub;
    func_80054838();
    func_8005508C();
}
