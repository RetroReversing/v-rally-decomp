typedef struct Obj53 {
    u8 pad0[0xE];
    u16 e;
    u8 pad10[0xE];
    u16 state;
    u16 spare;
    u16 step;
    u8 pad24[6];
    u16 flags;
} Obj53;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern Obj53 *D_800C35A0;
extern u8 D_800C365C[];
extern u8 D_800C7FA1;
extern u8 D_800C81FC;
extern u8 D_800C81FD;
extern u8 D_800C81FF;
extern u16 D_800B5B52;
extern void func_80053380(void);
extern void func_8006CE1C(void);
extern void pack_tile_rows(void);
extern void func_8006ECB4(void);
extern void func_8006F75C(void);
extern void func_80078018(void);

#define FINISH(m)                                   \
    q = D_800C35A0;                                 \
    D_800C02AE[0x7F4F] = (m);                       \
    D_800C02AE[0x7F51] = q->e;                      \
    if (D_800C02AE[0x7CF3] < q->e) {                \
        D_800C02AE[0x7F4E] = 1;                     \
    } else {                                        \
        D_800C02AE[0x7F4E] = 0;                     \
    }                                               \
    q = D_800C35A0;                                 \
    old = q->spare;                                 \
    *(s32 *)(D_800AE850 + 0x8030) = 6;              \
    q->state = 8;                                   \
    q->spare = 0;                                   \
    q->step = old;

void func_80053784(void)
{
    Obj53 *p;
    Obj53 *q;
    u16 step;
    u16 old;
    u8 i;
    u8 ok;

    pack_tile_rows();
    func_8006F75C();
    p = D_800C35A0;
    step = p->step + 1;
    p->step = step;
    switch (p->state) {
    case 1:
        if (step == 4) {
            p->flags |= 0x1000;
            func_80053380();
            func_80078018();
            func_8006CE1C();
            func_8006ECB4();
            func_8006F75C();
            if (D_800B5B52 == 0) {
                D_800B5B52++;
            }
            FINISH(2);
        }
        break;
    case 2:
        if (step == 5) {
            p->flags |= 0x2000;
            func_80053380();
            func_80078018();
            func_8006CE1C();
            func_8006ECB4();
            func_8006F75C();
            if (D_800B5B52 == 1) {
                D_800B5B52++;
            }
            FINISH(3);
        }
        break;
    case 3:
        if (step == 6) {
            func_80053380();
            ok = 1;
            i = 0;
            do {
                if (D_800C365C[i << 6] != 1) {
                    ok = 0;
                }
                i++;
            } while (i < 3 && ok);
            if (ok) {
                D_800C35A0->flags |= 0x4000;
            }
            if (D_800B5B52 == 2) {
                D_800B5B52++;
            }
            func_80078018();
            func_8006CE1C();
            func_8006ECB4();
            func_8006F75C();
            FINISH(4);
        }
        break;
    case 4:
        if (step == 3) {
            func_80053380();
            func_80078018();
            func_8006CE1C();
            func_8006ECB4();
            func_8006F75C();
            FINISH(8);
        }
        break;
    }
}
