#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
extern u8 D_800AE850[],D_800C02AE[];extern void func_80041564(void);extern void func_80098290(void *,void *);
#define STATE D_800C35A0
extern u8 *D_800C35A0;
extern u8 D_800C7F90[],D_800C7F94[],D_800C7F98[],D_800C7F9C[],D_800C7FA2[],D_800C7FA4[];
#define REC(off,t) F(D_800C7F90,t,off+i*24)
void func_800746C0(void){
u8 *car=F(F(D_800AE850,u8 *,0x73F0),u8 *,0);u8 *meta,*stats; s32 *times,*values;u8 i; u32 j; s32 diff;
func_80041564();
switch(F(STATE,u16,14)){
case 1:
i=0;meta=F(car,u8 *,0x6c);times=F(meta,s32 *,0x24);values=F(meta,s32 *,0x28);
do {
j=i;
F(D_800C7FA4,u8 *,j*24)=car;
func_80098290(D_800C7F90+j*24,STATE+(F(STATE,u8,0x32)*40+0x44));
F(D_800C7F9C,s32,j*24)=values[j];F(D_800C7F94,s32,j*24)=times[j];
F(D_800C7FA2,u8,j*24)=F(STATE,u16,0x4e + F(STATE,u8,0x32)*40); stats=F(F(car,u8 *,0x6c),u8 *,0x14);
diff=F(D_800C7F94,s32,j*24)-F(stats,s32,(F(STATE,u16,0x22)<<6)+0x2c);if(diff<0)diff=-diff;
F(D_800C7F98,s32,j*24)=diff;i++;
if(F(D_800C7F94,s32,j*24)==15000){
F(D_800C7F94,s32,j*24)=0;F(D_800C7F9C,s32,j*24)=0;F(D_800C7F98,s32,j*24)=0;
}
}while(i<6);
break;
case 2:
i=0;meta=F(car,u8 *,0x6c);times=F(meta,s32 *,0x24);values=F(meta,s32 *,0x28);
do {
F(D_800C7FA4,u8 *,i*24)=car;
func_80098290(D_800C7F90+i*24,STATE+(F(STATE,u8,0x32)*40+0x44));
F(D_800C7F9C,s32,i*24)=values[i];F((unsigned)D_800C7F94,s32,i*24)=times[i];
F(D_800C7FA2,u8,i*24)=F(STATE,u16,0x4e + F(STATE,u8,0x32)*40);
stats=F(F(car,u8 *,0x6c),u8 *,0x14);
diff=F(D_800C7F94,s32,i*24)-F(stats,s32,(F(STATE,u16,0x22)<<6)+0x2c);if(diff<0)diff=-diff;
F(D_800C7F98,s32,i*24)=diff;F(D_800C02AE,u8,0x7ce2 + 0x72)=F(stats,u8,(F(STATE,u16,0x22)<<6)+0x30);
if(F(D_800C7F94,s32,i*24)==15000){F(D_800C7F94,s32,i*24)=0;F(D_800C7F9C,s32,i*24)=0;F(D_800C7F98,s32,i*24)=0;}
i += 1;
}while(i<3);
if(F(STATE,u16,0x1a))car=F(car,u8 *,4);car=F(car,u8 *,4);
i=3;meta=F(car,u8 *,0x6c);times=F(meta,s32 *,0x24);values=F(meta,s32 *,0x28);
do {
F(D_800C7FA4,u8 *,i*24)=car;
func_80098290(D_800C7F90+i*24,STATE+(F(STATE,u8,0x33)*40+0x44));
F(D_800C7F9C,s32,i*24)=values[i-3];F(D_800C7F94,s32,i*24)=times[i-3];
F(D_800C7FA2,u8,i*24)=F(STATE,u16,0x4e + F(STATE,u8,0x33)*40);
stats=F(F(car,u8 *,0x6c),u8 *,0x14);
diff=F(D_800C7F94,s32,i*24)-F(stats,s32,(F(STATE,u16,0x22)<<6)+0x2c);if(diff<0)diff=-diff;
F(D_800C7F98,s32,i*24)=diff;
if(F(D_800C7F94,s32,i*24)==15000){F((short)D_800C7F94,s32,i*24)=0;F(D_800C7F9C,s32,i*24)=0;F(D_800C7F98,s32,i*24)=0;}
++i;
}while(i<6);
break;default:return;
}
func_80098290(D_800C7F90+i*24,stats+((F(STATE,u16,0x22)<<6)+0x2c)+6);
F(D_800C7FA4,u8 *,i*24)=car;F(D_800C7F94,s32,i*24)=F(stats,s32,(F(STATE,u16,0x22)<<6)+0x2c);F(D_800C7F9C,s32,i*24)=F(stats,u8,(F(STATE,u16,0x22)<<6)+0x36);F(D_800C7FA2,u8,i*24)=F(stats,u8,(F(STATE,u16,0x22)<<6)+0x30);
}
