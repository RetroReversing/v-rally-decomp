#include "snapshot29_0433f7af8f6d.h"

extern u8 D_800ADFE1;
extern u32 D_8009D530;
extern s32 D_8009D538, D_8009D540;
extern u8 D_800A1210;
extern char D_800A73E0[], D_800C02AE[];
void func_80020DB0(void *);
void func_80038AE4(s32);
void func_80020E0C(void **arg0) {
 s32 temp_a1, temp_v0, temp_v1_5; u16 temp_v0_2;
 char *new_var; void *temp_a0,*temp_a0_2,*temp_a2,*temp_v0_3,*temp_v1,*temp_v1_2,*temp_v1_3,*temp_v1_4,*new_var3,*var_s0,*var_v0;
 var_s0=*arg0;
 if(var_s0!=NULL) do {
  if(*(s32 *)((char *)*(void **)((char *)var_s0+0x6C)+0x34)!=0) {
   if(*(u16 *)((char *)*(void **)(D_800C02AE+0x32F2)+0x1E)==0 &&
      *(s32 *)*(void **)((char *)var_s0+0x48)>=4 && D_800A1210 && D_800ADFE1) func_80020DB0(var_s0);
   temp_v1=*(void **)((char *)var_s0+0x6C);
   *(s32 *)((char *)temp_v1+0x34)-=1;
   if(*(s32 *)((char *)*(void **)((char *)var_s0+0x6C)+0x34)<=0) *(s32 *)((char *)var_s0+0x14)&=~0x10;
  }
  if(!(*(s32 *)((char *)var_s0+0x14)&0x190)) {
   func_80020DB0(var_s0);
   temp_a0=*(void **)((char *)var_s0+0x6C);
   if(D_8009D530<*(u32 *)((char *)temp_a0+4)) *(u32 *)((char *)temp_a0+4)=D_8009D530;
   temp_v1_2=*(void **)((char *)var_s0+0x6C); ++*(s32 *)((char *)temp_v1_2+0x20);
   temp_a0_2=*(void **)((char *)var_s0+0x6C);
   if(*(s32 *)((char *)temp_a0_2+0x20)==D_8009D540) {
    *(s32 *)((char *)temp_a0_2+0x20)=0;
    temp_v1_3=*(void **)((char *)var_s0+0x6C); temp_v0=*(s32 *)((char *)temp_v1_3+0x10);
    new_var=(char *)var_s0;
    if(temp_v0!=0) *(s32 *)((char *)temp_v1_3+0x10)=temp_v0-1;
    else {
     temp_a2=*(void **)((char *)var_s0+0x48); temp_a1=*(s32 *)temp_a2;
     if(temp_a1<5 && !(D_8009D538&0x800)) {
      temp_v0_2=*(u16 *)((char *)*(void **)(D_800C02AE+0x32F2)+0x1E);
      if(temp_v0_2!=0 && temp_v0_2!=5 && !(*(u16 *)((char *)*(void **)(D_800C02AE+0x32F2)+0x2C)&8)) {
       if(*(u16 *)((char *)*(void **)(D_800C02AE+0x32F2)+0xE)==2) {
        if(temp_a1!=0) goto pick_node_self;
        var_v0=*(void **)((char *)var_s0+4);
        goto pick_node_done;
pick_node_self:
        var_v0=*(void **)((char *)var_s0+0);
pick_node_done:
        if((*(s32 *)((char *)var_v0+0x14)&0x300)!=0x100) *(s32 *)((char *)*(void **)((char *)var_s0+0x48)+0x20)=9;
       } else *(s32 *)((char *)temp_a2+0x20)=9;
      }
     }
    }
   }
  }
  temp_v1_4=*(void **)((char *)var_s0+0x48);
  if(*(s32 *)temp_v1_4<4) {
   if(*(s32 *)((char *)var_s0+0x14)&0x20) {
    if(*(s32 *)((char *)temp_v1_4+0x20)==0 && *(s32 *)((char *)*(void **)((char *)var_s0+0x6C)+0x1C)==0x78) func_80038AE4(0x11);
    temp_v0_3=*(void **)((char *)var_s0+0x6C); temp_v1_5=*(s32 *)((char *)temp_v0_3+0x1C)-1; *(s32 *)((char *)temp_v0_3+0x1C)=temp_v1_5;
    if(temp_v1_5==-1) *(s32 *)((char *)*(void **)((char *)var_s0+0x6C)+0x1C)=0xB8;
   } else *(s32 *)((char *)*(void **)((char *)var_s0+0x6C)+0x1C)=0xB8;
  }
  var_s0=*(void **)((char *)var_s0+4);
 } while(var_s0!=NULL);
}
