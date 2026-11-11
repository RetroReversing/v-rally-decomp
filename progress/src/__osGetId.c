typedef struct {u8 pad00[4];s32 channel; s32 id; u8 pad0c[0x40]; s32 version,dir_size,inode_size,bank,off5c; s32 off60; volatile u8 status64; u8 status;} OSPfs;
s32 __osPfsSelectBank(OSPfs*,s32);s32 __osContRamRead(s32,s32,s32,u16*);s32 __osCheckPackId(OSPfs*,u16*);s32 __osRepairPackId(OSPfs*,u16*,u16*);void __osCopyBytes(u16*,void*,s32);

/* Sums the 14 words of a pak ID block: the checksum pair is stored at words 14 and 15. */
static __inline__ void checksum(u16 *ptr,u16 *sum,u16 *inv){u16 *end=ptr+14;*sum=*inv=0;do{u16 x=*ptr++;u16 a=*sum;u16 b=*inv;*sum=a+x;*inv=b+~x;}while(ptr<end);}

/* Reads the pak's ID block (page 1), validates or repairs it, copies it into the
 * OSPfs header, and reads the directory block. Returns 0 on success, else an error code. */
s32 __osGetId(OSPfs *pfs){u16 raw[16];u16 repaired[16];u16 sum,inv;s32 ret;u16 *blk;u8 nbank;
if(pfs->status!=0){ret=__osPfsSelectBank(pfs,0);if(ret!=0)return ret;}ret=__osContRamRead(pfs->channel,pfs->id,1,raw);if(ret!=0)return ret;
checksum(raw,&sum,&inv);blk=raw;
if(raw[14]!=sum||raw[15]!=inv){ret=__osCheckPackId(pfs,blk);if(ret==10){ret=__osRepairPackId(pfs,blk,repaired);if(ret!=0)return ret;blk=repaired;}else if(ret!=0)return ret;}
if(!(blk[12]&1)){ret=__osRepairPackId(pfs,blk,repaired);if(ret!=0)return ret;blk=repaired;if(!(blk[12]&1))return 11;}
__osCopyBytes(blk,(u8*)pfs+0xc,0x20);pfs->version=((u8*)blk)[0x1B];nbank=((u8*)blk)[0x1A];pfs->dir_size=0x10;pfs->inode_size=8;pfs->status64=nbank;pfs->off60=nbank*2+3;pfs->bank=(pfs->status64+1)*8;pfs->off5c=pfs->bank+pfs->status64*8;
ret=__osContRamRead(pfs->channel,pfs->id,7,(u16*)((u8*)pfs+0x2c));if(ret!=0)return ret;return 0;}
