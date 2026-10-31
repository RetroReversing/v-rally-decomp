#include "snapshot31_verified.h"

extern u8 D_800A73E0[], D_800AE850[];
void func_80089980(void) ;







extern u8 D_800A1C80;
extern s32 osVirtualToPhysical(s32);
extern s32 func_800914C0(void);
s32 func_8008A6D0(s32 arg0,s32 arg1) ;








s32 func_80098720(u8);
s32 func_80098680(u8 *arg0,u8 *arg1,s32 arg2) {
 u8 *p2=arg1; unsigned short new_var; s32 n=arg2-1;
 s32 first; s32 second; s32 d; u8 c1; u8 c2; char pad[8];
 if(arg2!=0) { do {
 c1=*arg0; c2=*p2; first=func_80098720(c1); second=func_80098720(c2);
 d=first-second;
 if((d!=0)||(c1==0)) return d;
 arg0++; n--; p2++;
 } while(n!=-1); }
 new_var=0; return new_var;
}
s32 func_80095960(void) ;