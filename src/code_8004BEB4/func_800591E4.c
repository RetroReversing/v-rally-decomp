#include "snapshot31_verified.h"

#define FIELD(expr, type, offset) (*(type *)((s8 *)(expr) + (offset)))
extern s32 func_80059154(s32);
extern s32 func_8005BC60();
extern s32 func_8007EE9C(void *);
void func_800591E4(void *arg0) {
    s32 n;
    s32 c;
    void *inner;
    void *outer;
    void *base;
    func_8005BC60();
    n = FIELD(arg0, u16, 0);
    base = FIELD(arg0, void *, 0x10);
    if (n != 0) {
        outer = (s8 *)base + 4;
        do {
            c = FIELD(outer, u8, 8);
            if (c != 0) {
                inner = (s8 *)FIELD(outer, void *, 4) + 4;
                do {
                    c -= 1;
                    if (FIELD(inner, u8, 4) != 0) {
                        func_8007EE9C(FIELD(inner, void *, 0));
                    }
                    inner = (s8 *)inner + 0xC;
                } while (c != 0);
                func_8007EE9C(FIELD(outer, void *, 4));
            }
            n -= 1;
            if (FIELD(outer, u8, 0xB) != 0) {
                func_8007EE9C(FIELD(outer, void *, 0));
            }
            outer = (s8 *)outer + 0x14;
        } while (n != 0);
        base = FIELD(arg0, void *, 0x10);
    }
    func_8007EE9C(base);
    func_8007EE9C(arg0);
    func_80059154(0);
}
