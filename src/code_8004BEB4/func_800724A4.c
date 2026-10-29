#include "snapshot29_0433f7af8f6d.h"

extern u8 *D_800A1468;extern u8 D_800AE850[],D_800C02AE[];extern u8 *D_800C35A0;
typedef struct Node{struct Node *next;u16 id;u8 pad[20];u8 active;}Node;
extern Node *func_800592D0(int);extern u8 *func_80057918(void*,int);extern int func_8008E118(u8*);
void func_800724A4(void){
s8 i;Node *p,*r;u8 *b=D_800A1468+0x24f;u8 n,base,j,a,rank;u8 *text;
if(D_800AE850[0x7fc9]){n=4;base=8;}else{n=8;base=0;}
for(i=0;i<4;i++){(b+i)[1]=0;for(j=0;j<n;j++){u8 *q=(u8 *)((s32)(j*4)+(s32)b);q+=9;q[i]=0;}}
for(i=0;i<4;i++){a=(u8)((u32*)(D_800AE850+0x7db0))[i];for(j=0;j<4;j++)if(a<((u32*)(D_800AE850+0x7db0))[j])(b+i)[1]++;}
for(j=0;j<n;j++)for(i=0;i<4;i++){u8 *q; s32 offset; a=D_800AE850[0x7dd8+(base+j)*4+i];offset=(s32)(j*4)+(s32)b;q=(u8 *)(offset+9);if(a!=3)q[i]=1<<(2-a);else q[i]=0;}
for(i=0;i<4;i++){a=(u8)((u32*)(D_800AE850+0x7db0))[i];for(j=0;j<4;j++){if(i!=j&&(b+i)[1]==(b+j)[1]){if(a>=((u32*)(D_800AE850+0x7db0))[j])(b+j)[1]++;else (b+i)[1]++;i=-1;break;}}}
i=0;func_800592D0(0);p=func_800592D0(7);
for(j=0;j<n;j++){if(((u16*)(D_800AE850+0x7dc0))[j+base])(b+i)[0x29]=j,i++;else p->active=0;p=p->next;}b[0]=i;
if((u8)i==n){if(*(u16*)(D_800C35A0+14)>=2&&(b+D_800C35A0[0x32])[1]>(b+D_800C35A0[0x33])[1]) {
rank=b[2];
} else {
rank=b[1];
}
p=func_800592D0(5);if(rank==0){p->id=0x10d;p=func_800592D0(6);if(base)p->id=0x119;else p->id=0x118;}else{p->id=0x91;if(base)p->id=0x6c;p=func_800592D0(6);p->id=rank+0x119;}}
else{p=func_800592D0(5);p->id=base?0x6c:0x91;p=p->next;if(b[0]==1)p->id=0x93;else{text=func_80057918(*(void**)(D_800C02AE+0x807a),0x92);i=func_8008E118(text)-1;while((u32)(text[i]-'0')>=10)i--;text[i]=b[0]+'0';}}
if(base){p=func_800592D0(7);r=func_800592D0(15);for(i=0;i<8;i++){if(i>=4)p->active=0;else{p->id=r->id;r=r->next;}p=p->next;}}
}
