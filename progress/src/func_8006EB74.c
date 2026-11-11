extern f64 D_800A58C0;extern u8 gStreamState[];extern u8 *gRecords;
#define F8(o,t) (*(t *)(gStreamState+(o)))
#define O8(o,t) (*(t *)(gRecords+(o)))
static inline s16 *slot8(u8 *base, s32 idx) { return (s16 *)(base+idx*40+0x50); }
/* Unpacks the 16-bit status word at gStreamState+0x6e5e into the float scale fields, the
 * per-slot flags in gRecords, and the mode/config fields in gRecords and gStreamState. */
void func_8006EB74(void) {
s32 slot,j;u16 *statusWord=(u16 *)(gStreamState+0x6e5e);u8 *obj;
slot=0;
F8(0x333a,f32)=(f32)((f64)((*statusWord>>4)&15)*D_800A58C0);
F8(0x332e,f32)=(f32)((f64)(*statusWord&15)*D_800A58C0);
F8(0x3332,f32)=(f32)((f64)(F8(0x6e76,u8)&15)*D_800A58C0);
obj=gRecords;
do {
*slot8(obj,slot&255)=(*statusWord>>12)&1;
slot++;
}while((u32)(slot&255)<4);
O8(0x2a,u16)=statusWord[1];
O8(0x38,s16)=*statusWord>>15;
O8(0x2f,s8)=statusWord[2];
F8(0x32a8,s16)=(*statusWord>>14)&1;
O8(0x12,s16)=(*statusWord>>13)&1;
O8(0x16,s16)=(*statusWord>>10)&3;
F8(0x32aa,s32)=(*statusWord>>8)&3;
}
