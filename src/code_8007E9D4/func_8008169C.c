#include "common.h"

s32 func_800825E0(u8);
s32 func_8008169C(u8 *a,u8 *b) {
s32 i;
for(i=0;a[i] && b[i];i++) {
if ((u8)func_800825E0(a[i]) > (u8)func_800825E0(b[i])) return 1;
if ((u8)func_800825E0(a[i]) < (u8)func_800825E0(b[i])) return 0;
}
if (!a[i] && !b[i]) return 2;
return a[i]!=0;
}
