#include "common.h"

void func_80098560(void *a, s32 b, s32 c);

void *func_80080570(void **arg0, s32 arg1) {
    char key[8];
    char *p;
    char *node;
    s32 k0;
    s32 k1;

    p = key;
    do {
        *p = 0;
        p++;
    } while (p < key + 8);
    func_80098560(key, arg1, 8);
    k0 = *(s32 *)key;
    k1 = *(s32 *)(key + 4);
    if (arg0 != NULL) {
        node = *arg0;
        while (node != NULL) {
            if (k0 == *(s32 *)(node + 0xC) && k1 == *(s32 *)(node + 0x10)) {
                return node;
            }
            node = *(char **)(node + 4);
        }
    }
    return NULL;
}
