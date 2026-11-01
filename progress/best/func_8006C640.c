typedef struct Item {
    s32 x;
    u8 pad[0xC];
} Item;
typedef struct Group {
    Item item[4];
} Group;
typedef struct Game {
    u8 pad00[0x20];
    u16 sel;
} Game;
typedef struct Tbl {
    u8 pad[0x15A];
    u16 v;
} Tbl;
extern Game *D_800C35A0;
extern Group D_800C3750[];
extern s32 D_800ADF40[];
extern u8 D_800C7124[];
extern u8 func_8006B924(Item *);

void func_8006C640(void)
{
    u8 idx;
    u8 i;
    u8 r;
    s32 d;

    idx = D_800C35A0->sel;
    for (i = 0; i < 3; i++) {
        r = func_8006B924(&D_800C3750[idx].item[i]);
        if (r == 5) {
            ((Tbl *)(D_800C7124 + (idx * 3 + i) * 2))->v = 0xFFFF;
        } else {
            d = D_800ADF40[idx] - D_800C3750[idx].item[i].x;
            if (d >= 0) {
                if (d >= 0x4000) {
                    d = 0x3FFE;
                }
                d &= ~1;
            } else {
                d = -d;
                if (d >= 0x4000) {
                    d = 0x3FFE;
                }
                d |= 1;
            }
            ((Tbl *)(D_800C7124 + (idx * 3 + i) * 2))->v = d | (r << 14);
        }
    }
}
