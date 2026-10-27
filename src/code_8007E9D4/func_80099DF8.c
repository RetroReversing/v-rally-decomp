#include "common.h"

extern char D_800A73E0[];
s32 func_8009912C(char *, s32, s32 *);
void func_80099DF8(char *arg0, s32 arg1, ...) {
s32 *ap;
*(s32 *)(D_800A73E0+0x6B10)=-1;
*(char **)(D_800A73E0+0x6B1C)=arg0;
*(char **)(D_800A73E0+0x6B18)=arg0;
ap=(s32 *)__builtin_next_arg(arg1);
arg0+=func_8009912C(arg0,arg1,ap);
*arg0=0;
}
