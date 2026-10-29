#include "snapshot29_0433f7af8f6d.h"

typedef struct {u32 w[177];} Scene658;
extern u8 *D_800C3508,*D_800C35A0,*D_800A1468,*D_800A14D0;
extern s32 *D_800A11B0; extern u8 D_800A1620[];extern Scene658 *D_800D0634[];extern s32 D_800AFA58,D_800D05D8;extern f64 D_800A56D8;
void func_80061740(Scene658);void func_80062184(Scene658,s32);s32 func_800592AC(s32);void func_8005937C(u8,u16);void func_8005C198(void);void func_8006185C(s32,s32);void func_80064F98(void);
void func_8004D08C(s32,s32,s16,s16,f32,f32,s32,s32);
#define H(p,o) (*(u16*)((u8*)(p)+(o)))
#define S(p,o) (*(s16*)((u8*)(p)+(o)))
#define P(p,o) (*(u8**)((u8*)(p)+(o)))
void func_80065860(void){
Scene658 scene;

f64 offset;
s32 selected;
u8 i;
u8 *item;
u8 *icons;
s32 result;
item=P(D_800C3508,16)+S(D_800C3508,2)*20;
if(D_800A1468[0x245]==0){
selected=item[14]-item[13];
H(D_800C35A0,32)=selected;
D_800A1468[0x23C]=D_800A1620[(u16)selected];
func_8005937C(item[14],H(D_800D0634[D_800A1468[0x23C]],20));
if(selected!=D_800AFA58){
if(*D_800A11B0)func_8005C198();
if(D_800A1468[0x2BE]==0){
func_80061740(*D_800D0634[D_800A1620[H(D_800C35A0,32)]]);
D_800AFA58=selected;
}
H(D_800C35A0,34)=0;
}
func_800592AC(selected);
scene=*D_800D0634[D_800A1468[0x23C]];
}else{
result=func_800592AC(H(D_800C35A0,30)-1);
scene=*D_800D0634[H(D_800C35A0,30)];
func_8006185C(result,0);
}
func_80062184(scene,0);
if(S(D_800C3508,2)==1)func_80064F98();
if(D_800A1468[0x24D]==0 && D_800A1468[0x2BE]==0){
i=0;
if(i<H(&scene,20)){
offset=D_800A56D8;
icons=(u8*)&scene+0x2BC;
do{
func_8004D08C(D_800D05D8,i,S(D_800A14D0,0),(s16)(H(D_800A14D0,2)+i*D_800A14D0[8]),(f32)((f64)*(f32*)(D_800A14D0+4)-offset),*(f32*)(D_800A14D0+4),icons[i],255);
i++;
}while(i<H(&scene,20));
}
}
}
