#include "common.h"

void func_8008989C(s32 *p,s32 a,s32 n){s32 pad[2];s32 i=0,t;if(n>0)do{t=*p;i++;if(t)*p=t+a;p++;}while(i<n);(void)&pad;
}
