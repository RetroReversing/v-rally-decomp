#include "common.h"

extern u8 D_8009BA34;
extern u8 D_800ADFEC[];
extern u8 *D_800AE004;

void func_80012F7C(void *arg0) {
    u8 *node;
    u8 *mgr;
    u8 *tbl;
    u8 *cntp;
    u8 *head;
    u8 *entry;
    u8 *entries;
    u8 *cnt;
    u16 i;
    u16 a3;
    s32 more;

    mgr = *(u8 **)((u8 *)arg0 + 0x8C);
    tbl = D_800AE004;
    cntp = D_800ADFEC;
    D_8009BA34 = 0;
    head = *(u8 **)(mgr + 0x28);
    a3 = 0;
    if (tbl == NULL) goto reset;
    {
        entries = *(u8 **)tbl;
        node = head;
        while (1) {
            if (node == NULL) {
                a3 = 0;
                break;
            }
            for (i = 0; i < *(u16 *)(*(u8 **)(cntp + 0x18) + 4); i++) {
                entry = (u8 *)(i * 0x34);
                entry += (u32)entries;
                if (*(s32 *)(entry + 0xC) > *(s32 *)(node + 0x34) &&
                    *(s32 *)(entry + 0xC) < *(s32 *)(node + 0x3C) &&
                    *(s32 *)(entry + 0x14) > *(s32 *)(node + 0x44) &&
                    *(s32 *)(entry + 0x14) < *(s32 *)(node + 0x48)) {
                    if (*(u8 **)(node + 0x7C) == NULL) {
                        *(u8 **)(node + 0x7C) = entry;
                    } else {
                        *(u8 **)(*(u8 **)(node + 0x7C) + 0x24) = entry;
                        *(u8 **)(*(u8 **)(*(u8 **)(node + 0x7C) + 0x24) + 0x24) = NULL;
                    }
                }
            }
            if (a3 == 0) {
                a3 = 1;
            }
            cnt = *(u8 **)(node + 0x7C);
            if (cnt != NULL && *(u8 **)(cnt + 0x24) == NULL) {
                *(u8 **)(cnt + 0x24) = cnt;
            }
            node = *(u8 **)(node + 0x5C);
            { s32 flag = a3 ^ 1; s32 different = head != node; more = different | flag; }
            if (more == 0) {
                break;
            }
        }
reset:
        a3 = 0;
    }
    D_8009BA34 = 0;
    node = head;
    while (1) {
        if (node == NULL) break;
        if (*(u8 **)(node + 0x7C) == NULL) {
            D_8009BA34++;
        }
        if (a3 == 0) {
            a3 = 1;
        }
        node = *(u8 **)(node + 0x5C);
        { s32 flag = a3 ^ 1; s32 different = head != node; more = different | flag; }
        if (more == 0) {
            break;
        }
    }
}
