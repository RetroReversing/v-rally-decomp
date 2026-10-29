#include "snapshot29_0433f7af8f6d.h"

extern s32 D_8009D538;
extern u8 *D_800A0384;
extern u8 *D_800C35A0;
extern s32 D_800C7F84;
extern u8 D_800C8120;
extern s32 func_8004240C(s32);
extern void func_8004BEB4(void);
extern s32 func_80084BF0(s32);
extern void func_80085778(u8, s32);
extern void MusSetMasterVolume(s32, s32);
extern void func_8002FE78(void);

void func_80049294(void) {
    s32 sp10[4];
    s32 temp;
    s32 value;
    u32 i;
    s32 pad[0];

    i = 0;
    {s32 *q = sp10;
    do {
        *q = 0;
        i++;
        q++;
    } while (i < 4);
    }
    {u8 *state = D_800A0384; u8 *input = D_800C35A0;
    u8 paused;
    u8 btn;
    paused = state[0x384];
    btn = input[0xF];
    if (paused) {
        D_800C7F84 = func_8004240C((btn << 1) + 2);
        func_8004BEB4();
    }
    }
    value=0;
    for(i=0;i<*(u16*)(D_800C35A0+0xE);i++){
        temp=func_80084BF0(i&255);
        sp10[i]=temp;
        if(temp){
            value=temp;
            if(!D_800A0384[0x384] && (value&0x1000)){
                D_800A0384[0x382]=i;
                break;
            }
        }
    }
    if (!(D_8009D538 & 0x200)) {
        if (D_800A0384[0x384] == 0 &&
            (value & 0x1000) &&
            (D_8009D538 & 1) &&
            *(u16 *)(D_800C35A0 + 0x1E) != 8) {
            func_80085778(D_800A0384[0x382], 0x8000);
            D_800A0384[0x384] = 1;
            MusSetMasterVolume(3, 0);
            D_8009D538 &= ~0x4000;
            func_8002FE78();
        }
    } else {
        func_80085778(0, value);
        if (!(D_8009D538 & 1)) {
            D_8009D538 &= ~0x200;
            D_800C8120 = 0;
        }
    }
}
