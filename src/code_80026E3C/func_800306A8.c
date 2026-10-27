#include "common.h"

s16 func_800306A8(void *arg0,s32 arg1,void *arg2)
{
s32 temp_a0,x,var_a1,var_v0;
void *table;
s32 first;
int new_var;
u16 temp_t0;
void *temp_v0,*var_a3;
var_a1=arg1;
temp_t0=*(u16*)((char*)arg0+0x88);
if(var_a1<(s32)temp_t0){
var_a3=arg0;
first=*(s32*)((char*)arg0+0x78);
do {
arg0=(void*)(var_a1<<1);
var_v0=*(s32*)((char*)first+0x1C);
arg0=(void*)((s32)arg0+var_a1);
} while(0);
}else{
if(var_a1||arg0){
temp_v0=*(void**)((char*)arg0+0x5C);
var_a3=arg0;
}else{
temp_v0=*(void**)((char*)arg0+0x5C);
var_a3=arg0;
}
if(temp_v0!=NULL)var_a3=temp_v0;
table=*(void**)((char*)var_a3+0x78);
do {
var_a1=(var_a1-temp_t0)+1;
arg0=(void*)(var_a1<<1);
arg0=(void*)((s32)arg0+var_a1);
var_v0=*(s32*)((char*)table+0x1c);
} while(0);
}
temp_a0=(s32)arg0*4;
new_var=6;
x=*(s32*)((char*)var_a3+0x24);
*(s32*)((char*)arg2)=*(s16*)(temp_a0+var_v0+new_var)+x;
*(s32*)((char*)arg2+4)=*(s16*)(temp_a0+*(s32*)((char*)*(void**)((char*)var_a3+0x78)+0x1c)+8)+*(s32*)((char*)var_a3+0x28);
*(s32*)((char*)arg2+8)=*(s16*)(temp_a0+*(s32*)((char*)*(void**)((char*)var_a3+0x78)+0x1c)+10)+*(s32*)((char*)var_a3+0x2c);
return *(s16*)(var_a1*12+*(s32*)((char*)*(void**)((char*)var_a3+0x78)+0x1c)+4);
}
