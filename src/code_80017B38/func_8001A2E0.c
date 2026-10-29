#include "snapshot29_0433f7af8f6d.h"

void func_8007EE9C(s32);
void func_8001A2E0(void *arg0)
{
    s32 i;
    void *table;
    s32 obj;

    for (i = 0; i < 12; i++) {
        table = *(void **)((char *)arg0 + 0x38);
        if (table != 0) {
            obj = *(s32 *)((char *)table + i * 4 + 0x30);
            if (obj != 0) {
                func_8007EE9C(obj);
            }
        }
    }
}
