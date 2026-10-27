#include "common.h"

extern u8 D_800C02AE[];
s32 func_80081E0C(void);
s32 func_80082094(void);
void func_80083B40(void);
void func_80083BD4(void);
void func_80081D8C(void);
s32 func_80081C30(void) {
    u32 c;
    u8 **out;
    s32 *count;
    *(s32 *)(D_800C02AE + 0x309A) = 0;
    *(s32 *)(D_800C02AE + 0x3096) = 0;
    *(s32 *)(D_800C02AE + 0x309E) = 0;
    func_80081E0C();
    switch (*(u16 *)(D_800C02AE + 0x30BC)) {
    case 0:
        { u8 **p = (u8 **)(D_800C02AE + 0x30F2); count = (s32 *)((u8 *)p - 0x60); out = p; }
        *out = *(u8 **)(D_800C02AE + 0x30EA);
        for (;;) {
            if (--*count >= 0) {
                u8 *p = *(u8 **)(count - 1);
                *(u8 **)(count - 1) = p + 1;
                c = *p; } else { c = func_80082094(); }
            if (c == -1) break;
            *(*out)++ = c;
        }
        func_80081D8C();
        return 0;
    case 1:
        func_80083B40(); func_80083BD4(); goto done;
    case 2: goto fail; case 3: goto fail; case 4: goto fail;
    case 5: goto fail; case 6: goto fail; case 7: goto fail; case 8: goto fail;
    default: goto fail;
    }
fail: func_80081D8C(); return -1;
done: func_80081D8C(); return 0;
}
