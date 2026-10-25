#include "common.h"

extern char D_800C02AE[];

typedef struct {
    u16 key;
    u8 pad[2];
    s32 val;
    s8 tag;
} HashEnt;

s32 func_800553E8(u8 *, u16);

s32 func_800555A0(u8 *arg0, s32 arg1)
{
    u8 found;
    u16 i;
    u16 h;
    u16 k;
    s32 c;
    HashEnt *e;

    found = 0;
    k = arg1 & 0xFFFF;
    h = func_800553E8(arg0, k) & 0xFFFF;
    e = ((HashEnt **) (D_800C02AE + 0x3902))[h];
    if (e == NULL) {
        return 0;
    }
    c = *arg0;
    if (e->key == k + h + c && e->tag == c) {
        return e->val;
    }
    i = 0;
    while (i < 0x800) {
        e = ((HashEnt **) (D_800C02AE + 0x3902))[i];
        if (e != NULL && e->key == k + h + *arg0) {
            if (e->tag == *arg0) {
                found = 1;
                break;
            }
        }
        i++;
    }
    if (!found) {
        return 0;
    }
    return ((HashEnt **) (D_800C02AE + 0x3902))[i]->val;
}
