#include "common.h"

extern s32 *D_800A9930; extern u8 *D_800B68F0; extern s32 D_800C782C;
s32 func_80086B34(void *arg0) {
s32 best,min,i,limit,spare[2]; u8 *p,*selected; s32 val, count;
best=D_800A9930[*(s32 *)arg0];
min=best+1;
p=D_800B68F0;
count=D_800C782C;
i=0;
if(count>0) {
limit=count;

do {
count=*(s32 *)p;
if(count==0) goto found;
if(*(u16 *)(p+0x9e)!=0) {
val=*(s32 *)(p+0x44);
if(val<min) {min=val;selected=p;}
}
i++;p+=0x134;
}while(i<limit);
}
if(min<best) {
*(s32 *)((u8 *)arg0+4)=func_800898D0(selected,*(s32 *)arg0,0x80,0x80,best);
*((u8 *)arg0+8)=1;return 1;
}return 0;
found:
*(s32 *)((u8 *)arg0+4)=func_800898D0(p,*(s32 *)arg0,0x80,0x80,best);
*((u8 *)arg0+8)=1;return 1;
}
