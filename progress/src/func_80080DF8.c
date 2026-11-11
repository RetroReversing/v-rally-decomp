extern s32 gHeapBusy;
extern volatile s32 gHeapCallerRa;
extern s32 D_800C5BB0[], heapPanicFn, heapReentryFn;
extern u8 gOrderState[], gStreamState[];
extern s32 gVoiceCount;
s32 heapFreeBlock(void *arg0) ;

/* Frees a heap block, merging it with its free neighbours. A block whose flag at -10 is clear is
 * handed to the fallback free routine in gStreamState. Returns 1 when the block is freed or was
 * already free, and 0 when no neighbour is left to check. */
s32 func_80080DF8(u8 *block) {
 u8 *nextBlock; unsigned int result; u8 **link; u8 *prevBlock;
 if(!block[-10]) return (*(s32(**)(u8*))(gStreamState+0x7dda))(block);
 block-=0x14; if(!block[10]) return 1;
 prevBlock=*(u8**)block; block[10]=0; block[11]=0; nextBlock=*(u8**)(block+4);
 if(!prevBlock[10]) {prevBlock=*(u8**)prevBlock; *(u8**)block=prevBlock; *(u8**)(prevBlock+4)=block;}
 if(nextBlock && !nextBlock[10]) {link=(u8**)(prevBlock+4); block=nextBlock; *(u8**)nextBlock=prevBlock; *link=block; nextBlock=*(u8**)(block+4);}
 {s32 result=1; if(nextBlock) return result; prevBlock=(u8*)(s32)*(s8*)(prevBlock+8); if((s32)prevBlock==result) block[-9]=0; return 1;}
}
