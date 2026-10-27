#include "common.h"

s32 func_8008260C(u8 *a, u8 *b) {
 s32 i=0; u8 *p,*q;
 if (*a==0) goto finish;
 p=a; q=b;
 for (;;) {
   if (*q==0) goto finish;
   if ((u8)func_800825E0(*p) > (u8)func_800825E0(*q)) return 1;
   if ((u8)func_800825E0(*p) < (u8)func_800825E0(*q)) return 0;
   p++; q++; i++;
   if (*p==0) break;
 }
finish: return a[i]!=0;
}
