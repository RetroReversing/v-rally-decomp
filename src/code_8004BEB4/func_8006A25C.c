#include "common.h"

extern s8 D_8009BBBC; extern void *D_800A1468; extern u8 D_800A16D4,D_800A16D5; extern s32 D_800C8374; extern char D_800C02AE[]; s32 func_8001B8CC(s32);
void func_8006A25C(void) {
s32 one=1; s32 arg; s32 st; s32 *p; s32 *q;
*(s8 *)((char *)D_800A1468+0x2BD)=one;
st=D_800A16D4;
switch(st) {
case 0:
arg=*(s32 *)(D_800C02AE+0x80C6);
D_8009BBBC=one;
func_8001B8CC(arg);
D_800A16D5=0;

break;
case 1: case 2: break;
case 3:
if(D_800A16D5) {
q=*(s32 **)(D_800C02AE+0x325A); p=q;
p=*(s32 **)((char *)q+0x10)+(*(s16 *)((char *)q+2)*5);
p[4]=0;
}
break;
}
}
