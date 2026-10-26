#include "common.h"

s32 func_8000DA84();
s32 func_80037DE4();
s32 func_8005A338();
s32 func_80086854();
s32 func_80086A34();
s32 MusSetMasterVolume();
s32 func_80086DE8();
extern s32 D_8009F640;
extern void *D_800A1468;
extern char D_800A5498[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_8005DC40;
extern s32 func_8005DD2C;

s32 func_8005DFC8(s32 arg0, s32 arg1) {
    void *temp_s0;

    if (!(D_8009F640 & 0x40)) {
        D_8009F640 |= 0x40;
        func_80086A34(1);
        func_8000DA84();
        temp_s0 = D_800AE850 + 0x5558;
        func_80037DE4(temp_s0, &D_800A5498);
        MusSetMasterVolume(3, (s32) (*(f32 *)(D_800C02AE + 0x332A) * 32767.0f));
        func_80086854(temp_s0);
        func_80086DE8((s32) (*(f32 *)(D_800C02AE + 0x3332) * 112.0f));
    }
    func_8005A338(arg0, arg1);
    *(s32 * *)((char *)D_800A1468 + 0x288) = &func_8005DC40;
    *(s32 * *)((char *)D_800A1468 + 0x28C) = &func_8005DD2C;
    return 0;
}
