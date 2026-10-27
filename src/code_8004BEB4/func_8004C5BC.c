#include "common.h"

extern char D_800C02AE[];
void func_8004C5BC(void **arg0) {
    s32 (*hook)(void *);
    s32 (*send)(s32, s32, s32, s32, s32, u16);
    void *cur, *next, *global;
    cur = *arg0;
    global = *(void **)(D_800C02AE + 0x7CD6);
    if(cur == 0) return;
    do {
        next = *(void **)((u8 *)cur + 4);
        if (*(s32 *)((u8 *)cur + 0xC) & 1) {
            hook = *(s32 (**)(void *))((u8 *)cur + 0x30);
            if (hook != 0) hook(cur);
            if ((*(s32 *)((u8 *)cur + 0xC) & 2) == 0) {
                (*(s32 (**)(s32, s32, s32, s32, s32, u16))((u8 *)cur + 0x2C))(*(s32 *)((u8 *)global + 0x178), *(s32 *)((u8 *)cur + 0x24),
                     *(s32 *)((u8 *)cur + 0x10), *(s32 *)((u8 *)cur + 0x14),
                     *(s32 *)((u8 *)cur + 0x20), (u32)*(u16 *)((u8 *)cur + 0x1C));
            }
        }
        cur = next;
    } while(cur);
}
