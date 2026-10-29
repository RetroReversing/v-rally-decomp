#include "snapshot29_0433f7af8f6d.h"

extern char *D_800C35A0;
extern u8 D_800AE850[]; extern char D_800C02AE[];
extern s32 func_80098180(const u8*,const u8*);
void func_800544D4(void) {
s32 temp_a1, temp_v1; u32 var_s0,var_s1,var_s2,var_s3;
var_s2=0;
do {
temp_a1=(var_s2&255)<<6;
if (*(u8*)(D_800C02AE+0x33AE + temp_a1)==1) {
var_s1=0; var_s3=temp_a1;
for (;;) {
var_s0=var_s1&255;
if (func_80098180((u8*)(((var_s0*5)<<3)+0x44+D_800C35A0),(u8*)(var_s3+D_800C02AE+0x33A8))==0) break;
if(var_s0>=4U) break;
var_s1++;
}
temp_v1=(var_s1&255)*5;
D_800AE850[0x2531+temp_v1]+=7;
D_800AE850[0x2545]+=7;
}
var_s2++;
}while((var_s2&255)<4U);
}
