typedef struct {u8 pad00[4];s32 channel; s32 id; u8 pad0c[0x40]; s32 version,dir_size,inode_size,bank,off5c; s32 off60; volatile u8 status64; u8 status;} OSPfs;
s32 __osPfsSelectBank(OSPfs*,s32);s32 func_80096830(s32,s32,s32,u16*);s32 __osCheckPackId(OSPfs*,u16*);s32 __osRepairPackId(OSPfs*,u16*,u16*);void func_80091600(u16*,void*,s32);
static __inline__ void checksum(u16 *ptr,u16 *sum,u16 *inv){u16 *end=ptr+14;*sum=*inv=0;do{u16 x=*ptr++;u16 a=*sum;u16 b=*inv;*sum=a+x;*inv=b+~x;}while(ptr<end);}
s32 __osGetId(OSPfs*p){u16 data[16];u16 repaired[16];u16 sum,inv;s32 ret;u16*id;u16*q;u8 v;
if(p->status!=0){ret=__osPfsSelectBank(p,0);if(ret!=0)return ret;}ret=func_80096830(p->channel,p->id,1,data);if(ret!=0)return ret;
checksum(data,&sum,&inv);id=data;
if(data[14]!=sum||data[15]!=inv){ret=__osCheckPackId(p,id);if(ret==10){ret=__osRepairPackId(p,id,repaired);id=repaired;if(ret!=0)return ret;}else if(ret!=0)return ret;}
if(!(id[12]&1)){ret=__osRepairPackId(p,id,repaired);id=repaired;if(ret!=0)return ret;if(!(repaired[12]&1))return 11;}
func_80091600(id,(u8*)p+0xc,0x20);p->version=((u8*)id)[0x1B];v=((u8*)id)[0x1A];p->dir_size=0x10;p->inode_size=8;p->status64=v;p->off60=v*2+3;p->bank=(p->status64+1)*8;p->off5c=p->bank+p->status64*8;
ret=func_80096830(p->channel,p->id,7,(u16*)((u8*)p+0x2c));if(ret!=0)return ret;return 0;}
