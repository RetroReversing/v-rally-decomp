#include "common.h"

extern int D_800C6ED0;s32 func_80035438();s32 func_8007EE9C();extern char D_800AE850[],D_800C02AE[];
void func_80021E20(void *arg0){u8 var_s0,var_s1;void *temp_s0,*temp_s2;
temp_s2=**(void***)((char*)arg0+0x38);
if(arg0==**(void***)(D_800AE850+0x73f0))func_80035438(D_800C6ED0);
if(*(u16*)((char*)*(void**)(D_800C02AE+0x32f2)+0xe)<3U){
func_8007EE9C(*(void**)((char*)temp_s2+0x10));var_s1=0;func_8007EE9C(*(void**)temp_s2);
do{var_s0=var_s1;temp_s0=(void*)((u32)(var_s0*4)+(u32)temp_s2);func_8007EE9C(*(void**)((char*)temp_s0+0x38));var_s1++;func_80035438(*(s32*)((char*)temp_s0+0x1c));}while(var_s1<7);}
func_8007EE9C(temp_s2);}
