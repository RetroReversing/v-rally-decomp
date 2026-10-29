#include "snapshot29_0433f7af8f6d.h"

typedef struct { s32 a; s32 b; s8 c; } S56;
typedef struct { s32 a; s32 b; } S56AB;
extern void *D_800A1468;
extern s8 D_800A16D4;
extern S56 D_800A56A0;
extern s32 func_800580D0(s32, s32);
extern s32 func_8005E0D0(s32,  s32);
extern s32 func_80047F94(void);

s32 func_800642F8(void) {
    S56 *src = &D_800A56A0;
    S56 *dst;
    s8 c;
    *(s8 *)((u8 *)D_800A1468 + 0x2BD) = 1;
    func_800580D0(0, 0);
    *(s8 *)((u8 *)D_800A1468 + 0x24D) = 0;
    dst = (S56 *)((u8 *)D_800A1468 + 0x204);
    __builtin_memcpy(dst, src, 9);
    c = dst->c;
    func_8005E0D0(0,  0);
    D_800A16D4 = 2;
    func_80047F94();
    return 0;
}
