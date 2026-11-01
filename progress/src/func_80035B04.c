typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s8 side;
    s8 pad;
} Item8;

extern char D_800C02AE[];
u64 osGetTime(void);
s32 func_80098090();
void func_800980C4(u32);

void func_80035B04(Item8 *p) {
    u32 n;
    u32 t;
    s32 r;

    n = *(u32 *)(*(char **)(D_800C02AE + 0x7E6E) + 8);
    func_800980C4((u32)osGetTime());
    r = n;
    n--;
    if (r != 0) {
        do {
            if (n < (*(u32 *)(*(char **)(D_800C02AE + 0x7E6E) + 8) >> 1)) {
                p->side = 0;
            } else {
                p->side = 1;
            }
            p->x = func_80098090() % 8191;
            p->y = func_80098090() % 2047;
            p->z = func_80098090() % 8191;
            p++;
            t = n;
            n--;
        } while (t != 0);
    }
}
