#include "common.h"

s32 func_8003AB38(s32,void*);
extern u8 D_8009FE18[];
void func_8003B7BC(void *arg0)
{
s32 *temp_s1;
s32 base,idx;
s32 var_v1;
u16 new_var;
s32 flags;
void *temp_a0;
temp_a0=*(void**)((char*)*(void**)((char*)arg0+0xA8)+0x24);
if(temp_a0!=NULL){
temp_s1=(s32*)**(s32**)((char*)temp_a0+0x6C);
idx=*(u16*)((char*)arg0+0x76);
temp_s1=(s32*)((s32)temp_s1+idx*4);
if(*(s32*)((char*)temp_a0+0x14)&0x100){
*(s32*)((char*)arg0+0x80)|=4;
}
if(*(u16*)((char*)arg0+0x78)==0){
func_8003AB38(*temp_s1,D_8009FE18);
}
var_v1=0xE;
if(*temp_s1!=0){
new_var=*(u16*)((char*)arg0+0x78);
flags=*(s32*)((char*)arg0+0x80);
*(s16*)((char*)arg0+0x7A)=(s16)(D_8009FE18[new_var]-0x30);
*(s32*)((char*)arg0+0x80)=flags&~4;
return;
}
*(s16*)((char*)arg0+0x7A)=var_v1;
*(s32*)((char*)arg0+0x80)|=4;
}
}
