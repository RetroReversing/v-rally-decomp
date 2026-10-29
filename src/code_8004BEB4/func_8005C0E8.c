#include "snapshot29_0433f7af8f6d.h"

extern void *func_800592AC();
void func_8005C0E8(s32 start, u32 offset, u32 end, u16 value) {
    u32 i;
    u32 limit = start + offset;
    void *p;
    void *node;
    u16 v;
    i = end - 1;
    while ((u16)i >= start + offset) {
            void *previous = func_800592AC((u16)i - offset);
            p = func_800592AC((u16)i);
            node = *(void **)((u8 *)p + 0x28);
            { u32 j = 0;
            v = *(u16 *)((u8 *)previous + 0xC);
            if (*(u8 *)((u8 *)p + 0x4C) != 0) {
                do {
                    *(u16 *)((u8 *)node + 8) = v;
                    node = *(void **)node;
                    j++;
                } while ((u16)j < *(u8 *)((u8 *)p + 0x4C));
            }
            }
            i--;
            *(u16 *)((u8 *)p + 0xC) = v;
    }
}
