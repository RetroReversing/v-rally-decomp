extern void *D_8009D6B0;
extern char D_800AE850[];
extern char D_800C02AE[];

void func_80028158(void *, s32, void *, s32);
s32 func_80027CB4(u8, u8, u8, s8);
void func_80050048(s32);
void func_8004F3C4(void);
s32 func_8001FFC4(void *, s32, s32, s32);
void func_80023134(void *, void *, void *);
void func_80024B28(void *);

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Quad20B04;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Tri20B04;

void func_80020B04(void **arg0) {
    void *node;
    s32 mask;
    void *pay;
    u8 *bytes;
    s32 hi;
    s32 word;
    void *p54;
    Quad20B04 quad;
    Tri20B04 tri;
    s32 kind;
    u16 flag;

    node = *arg0;
    if (D_8009D6B0 != NULL) {
        node = D_8009D6B0;
    }
    if (node != NULL) {
        mask = 0xFFFF0000;
        do {
            pay = *(void **)((char *)node + 0x48);
            D_8009D6B0 = NULL;
            bytes = (u8 *)pay + 4;
            func_80028158(node, *(s32 *)pay, bytes, *(s32 *)((char *)pay + 0x20));
            if ((*(s32 *)(*(s32 *)(D_800AE850 + 0x73F0) + 8) & 1) != 0) {
                D_8009D6B0 = node;
                return;
            }
            kind = *(s32 *)(*(s32 *)((char *)node + 0x48) + 0x20);
            if ((kind == 0) || (kind == 9)) {
                flag = *(u16 *)(*(s32 *)(D_800C02AE + 0x32F2) + 0x1E);
                if (flag != 0) {
                    u8 b8 = bytes[4];
                    u8 b9 = bytes[5];
                    s32 fl = *(s32 *)((char *)node + 0x14);
                    s8 b4 = (s8)bytes[0];
                    u8 b5 = bytes[1];
                    if ((fl & 0x10) == 0) {
                        func_80050048(func_80027CB4(b5, b8, b9, b4));
                    }
                } else {
                    func_80050048(func_80027CB4(bytes[1], bytes[4], bytes[5], (s8)bytes[0]));
                }
            }
            p54 = *(void **)((char *)node + 0x54);
            {
                s32 w = *(s32 *)((char *)p54 + 0x20);
                hi = w >> 16;
                if (hi != 0) {
                    *(s32 *)((char *)p54 + 0x20) = w + mask;
                }
            }
            if (hi == 1) {
                func_8004F3C4();
            }
            if ((bytes[1] & 0x80) != 0) {
                {
                    s32 p = *(s32 *)((char *)node + 0x54);
                    s32 w = *(s32 *)(p + 0x20);
                    if ((w & 0xFFFF) != 0) {
                        *(s32 *)(p + 0x20) = w - 1;
                    if (*(u16 *)(*(s32 *)((char *)node + 0x54) + 0x22) != 0) {
                            goto join20;
                        }
                        if (hi != 0) {
                            goto join20;
                        }
                        if (1) {
                        {
                            s32 p8c = *(s32 *)((char *)node + 0x8C);
                            s32 p60 = *(s32 *)((char *)node + 0x60);
                            s32 a1v = *(s32 *)(p8c + 0x28);
                            s32 a3v = *(s32 *)(p60 + 0x28);
                            tri.a = 0;
                            tri.b = func_8001FFC4(&quad, a1v, 0, (s16)a3v);
                        }
                        tri.c = 0;
                        quad.b -= 0x5A;
                        func_80023134(node, &quad, &tri);
                        func_80024B28(node);
                        *(s32 *)(*(s32 *)((char *)node + 0x54) + 0x20) = 0x320000;
                        *(s32 *)((char *)node + 0x14) |= 0x40;
                    }
                }
            }
            } else {
                p54 = *(void **)((char *)node + 0x54);
                *(s32 *)((char *)p54 + 0x20) &= mask;
                p54 = *(void **)((char *)node + 0x54);
                *(s32 *)((char *)p54 + 0x20) |= 0x14;
            }
            join20:
            *(s32 *)(*(s32 *)((char *)node + 0x48) + 0x14) = (s8)bytes[0];
            *(s32 *)(*(s32 *)((char *)node + 0x48) + 0x1C) = bytes[3];
            *(s32 *)(*(s32 *)((char *)node + 0x48) + 0xC) = bytes[4];
            *(s32 *)(*(s32 *)((char *)node + 0x48) + 0x10) = bytes[5];
            *(s32 *)(*(s32 *)((char *)node + 0x48) + 0x18) = 0;
            node = *(void **)((char *)node + 4);
        } while (node != NULL);
    }
}
