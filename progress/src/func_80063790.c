typedef struct Record {
    s32 w[5];
    u16 count;
    u8 pad16[0x2BC - 0x16];
    u8 colors[8];
} Record;
typedef struct Disp {
    s16 x;
    u16 y;
    f32 f;
    u8 step;
} Disp;
typedef struct State {
    u8 pad00[0x20];
    u16 sel;
    u16 h22;
} State;
extern VRMenuManager *D_800C3508;
extern State *D_800C35A0;
extern u8 D_800C352C[];
extern s32 D_800B3DA0;
extern u8 *D_800A1468;
extern s32 *D_800A11B0;
extern Disp *D_800A14D0;
extern f64 D_800A5698;
extern s32 D_800D05D8;
extern Record *D_800D0634;
extern void func_8005937C(u8, u16);
extern void func_8005C198(void);
extern void func_80061740(Record);
extern void func_8006185C(s32, s32);
extern void func_80062184(Record, s32);
extern void func_80062E68(void);
extern void func_8004D08C(s32, u8, s16, s16, f32, f32, u8, u8);
extern s32 func_800592AC(u16);

void func_80063790(void)
{
    VRMenuItem *item;
    s32 n;
    u8 i;
    s32 bit;
    s32 sel;
    u8 alpha;
    Record record;
    f64 scale;

    item = &D_800C3508->items[D_800C3508->count];
    n = item->value - item->pad00[13];
    if (!D_800A1468[0x245]) {
        *(u16 *)((u8 *)D_800C35A0 + 0x20) = n;
        func_8005937C(item->value, D_800D0634[n].count);
        if (n != D_800B3DA0) {
            if (*D_800A11B0) {
                func_8005C198();
            }
            if (!D_800A1468[0x2BE]) {
                func_80061740(D_800D0634[n]);
                D_800B3DA0 = n;
            }
        }
        D_800C35A0->h22 = 0;
    } else {
        func_8006185C(func_800592AC(D_800C35A0->sel), 0);
    }
    record = D_800D0634[D_800C35A0->sel];
    if (D_800C3508->count == 1 && D_800A1468[0x245]) {
        func_80062E68();
    }
    func_80062184(record, 1);
    if (!D_800A1468[0x24D] && !D_800A1468[0x2BE]) {
        i = 0;
        if (i < record.count) scale = D_800A5698;
        for (; i < record.count; i++) {
            sel = D_800C35A0->sel;
            bit = 1 << i;
            if ((D_800C352C[sel] & bit) != bit) {
                if ((sel == 0 & i == 6) || (sel == 1 & i == 4) || (sel == 5 & i == 6) || (sel == 6 & i == 5)) {
                    alpha = 200;
                } else {
                    alpha = 130;
                }
                func_8004D08C(D_800D05D8, i, D_800A14D0->x, D_800A14D0->y + i * D_800A14D0->step,
                              D_800A14D0->f - scale, D_800A14D0->f, record.colors[i], alpha);
            } else {
                func_8004D08C(D_800D05D8, i, D_800A14D0->x, D_800A14D0->y + i * D_800A14D0->step,
                              D_800A14D0->f - scale, D_800A14D0->f, record.colors[i], 255);
            }
        }
    }
}
