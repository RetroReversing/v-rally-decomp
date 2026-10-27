#include "common.h"

extern s32 D_800AB970,D_800AB974; extern void *D_800AB978[4]; extern s32 D_800AFA54; extern s32 func_80086D34(void*); extern void func_80086B34(void*); extern void func_80086D90(void*,s32);
void func_80089A94(void) { s32 i; void *p; if(D_800AB974!=0){ p=D_800AB978[D_800AB970]; if(*(u8*)((u8*)p+8)!=0){ if(func_80086D34(p)!=0){ i=D_800AB970; D_800AB978[i]=0; D_800AB970=i+1; if((u32)D_800AB970<4){} else D_800AB970=0; D_800AB974--;
return;
 } } else {func_80086B34(p); func_80086D90(D_800AB978[D_800AB970],D_800AFA54);} } }
