#include "decompdecomp_sync_72635f1f065f43374cdd.h"
#line 1 "func.c"
extern s32 D_800A19B0,D_800B5B40;
extern void (*D_800C8090)(s32),(*D_800C80A8)(s32);
extern s32 D_800C72D8[];
typedef struct Dispatch { s32 pad[2]; s32 (*call)(s32); } Dispatch;
extern Dispatch *D_800C5BB0[];
s32 func_8007EF5C(s32 arg0) {
 volatile s32 sp10; s32 result=0; s32 p; s32 q;
 if(D_800A19B0==1) D_800C80A8(D_800B5B40-4);
 D_800A19B0=1; do { D_800B5B40=(s32)__builtin_mips_live_return_address(); } while (0);
 if(!(arg0&0xffff0000)){p=D_800C72D8[arg0];sp10=arg0;}else {p=arg0;sp10=1;}
 if(p==0){D_800C8090(D_800B5B40-4);q=0;}else q=p-8;
 if(q) result=D_800C5BB0[sp10]->call(q+8);
 D_800A19B0=0;return result;
}
