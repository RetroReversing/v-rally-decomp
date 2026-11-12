extern u8 *gPiCurrentDev[]; extern s32 D_A4600000; extern s32 osVirtualToPhysical(void*);

/* Starts a PI DMA. s0 is the device/domain record (domain at +9, timing bytes at
 * +5..+8, cart address word at +12). gPiCurrentDev[domain] caches the last record
 * programmed for that domain; the timing registers are only rewritten when a
 * byte changed. Then DRAM address (PI_DRAM_ADDR), cart address (PI_CART_ADDR) and
 * length (PI_WR_LEN for s1 == 0, PI_RD_LEN for s1 == 1) are written. s3 is the
 * byte count. Returns 0, or -1 for a bad direction. */
s32 PiRawStartDma(u8 *s0,s32 s1,s32 s2,void *dram,s32 s3){
u32 domain;u8 *old;u32 value;volatile u32 *reg;u32 nv;
if(*(volatile u32*)0xa4600010&3)do{}while(*(volatile u32*)0xa4600010&3);
domain=s0[9];old=gPiCurrentDev[domain];
if(old!=s0){
 if(domain==0){
 if(old[5]!=s0[5])*(volatile u32*)0xa4600014=s0[5];
 if(old[6]!=s0[6])*(volatile u32*)0xa460001c=s0[6];
 if(old[7]!=s0[7])*(volatile u32*)0xa4600020=s0[7]; value=old[8];
#ifdef PORT
 nv=s0[8];if(value!=nv){reg=(volatile u32*)0xa4600018;goto writeTiming;}
#else
 old=(u8 *)(u32)s0[8];if(value!=(u32)old){reg=(volatile u32*)0xa4600018;goto writeTiming;}
#endif
 }else{
 if(old[5]!=s0[5])*(volatile u32*)0xa4600024=s0[5];
 if(old[6]!=s0[6])*(volatile u32*)0xa460002c=s0[6];
 if(old[7]!=s0[7])*(volatile u32*)0xa4600030=s0[7];
 value=old[8];
#ifdef PORT
 nv=s0[8];if(value!=nv){reg=(volatile u32*)0xa4600028;goto writeTiming;}
#else
 old=(u8 *)(u32)s0[8];if(value!=(u32)old){reg=(volatile u32*)0xa4600028;goto writeTiming;}
#endif
 }
 goto done;
 writeTiming:
#ifdef PORT
 *reg=nv;
#else
 *reg=(u32)old;
#endif
 done:gPiCurrentDev[domain]=s0;
}
*(volatile u32*)0xa4600000=osVirtualToPhysical(dram);
*(volatile u32*)0xa4600004=(*(u32*)(s0+12)|s2)&0x1fffffff;
{ volatile u32 *tail;
switch(s1){case 0:tail=(volatile u32*)0xa460000c;break;case 1:tail=(volatile u32*)0xa4600008;break;default:return -1;}
*tail=s3-1;return 0; }
}
