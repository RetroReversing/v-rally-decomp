#include "common.h"

void *func_8008EBEC();
s32 func_8008ED0C(void *, s32, s32);

void func_8008E590(void *arg0, void *arg1, s32 arg2, s32 arg3)
{
    char *obj;
    char *base;
    char *base2;
    s32 tmp;
    s32 tmp1;
    void (*fn)(void *, s32, void *);

    if (*(char **)((char *)arg1 + 8) != NULL) {
        obj = func_8008EBEC();
        if (obj != NULL) {
            base = *(char **)((char *)arg1 + 8);
            tmp1 = *(s32 *)((char *)arg0 + 0x1C);
            tmp = *(s32 *)(base + 0xD8);
            *(s16 *)(obj + 8) = 0xB;
            *(s32 *)(obj + 0xC) = (s16)arg2;
            *(s32 *)(obj + 4) = tmp1 + tmp;
            *(s32 *)(obj + 0x10) = func_8008ED0C(arg0, arg3, tmp);
            *(s32 *)obj = 0;
            base2 = *(char **)(*(char **)((char *)arg1 + 8) + 0xC);
            fn = *(void (**)(void *, s32, void *))(base2 + 8);
            fn(base2, 3, obj);
        }
    }
}
