#include "decompdecomp_terminal_80022374.h"
#line 1 "func.c"
void *func_80022318(void **, u8 *);
s32 func_80022374(void **list, u8 *name, s32 value) {
void *node;
node=func_80022318(list,name);
if(node!=NULL){*(s32 *)((u8 *)*(void **)((u8 *)node + 0x10) + 8) = value;return 1;}else{return 0;}
}

