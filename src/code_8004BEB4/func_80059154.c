#include "common.h"

extern u8 D_800C02AE[];
void func_80035438(s32);
void func_800803C0(void *,void *);
void func_80059154(s32 arg0) {
 void *owner; void *node; void *old;
 owner=*(void **)(D_800C02AE+0x5A72+(arg0&255)*4);
 node=**(void *** )((u8 *)owner+16);
 if(node) do {
 func_80035438(*(s32 *)((u8 *)node+0xA4));
 old=node;
 node=*(void **)((u8 *)node+4);
 func_800803C0(old,*(void **)((u8 *)owner+16));
 } while(node);
}
