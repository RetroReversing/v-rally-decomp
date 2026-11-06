#include "decompdecomp_contract_80059618.h"
#line 1 "func.c"
typedef struct { u8 start; u8 count; } Group;
typedef struct {
    u8 pad0[0xD0];
    Group groups[10];
    void *items[1];
} GroupTable;
typedef struct {
    u8 pad0[0xA];
    s8 group;
} GroupOwner;

void func_8000C22C(void *, s32, s32, s32, u8);
extern GroupTable *D_800A1468;

void func_80059618(GroupOwner *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    u8 i;

    for (i = D_800A1468->groups[arg0->group].start;
         i < D_800A1468->groups[arg0->group].start + D_800A1468->groups[arg0->group].count; i++) {
        func_8000C22C((void *)(D_800A1468->items[i]), (s32)((u8)(arg1)), (s32)((u8)(arg2)), (s32)((u8)(arg3)), (u8)(arg4));
    }
}

