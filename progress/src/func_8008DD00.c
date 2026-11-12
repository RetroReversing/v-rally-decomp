/* RSP task descriptor, as in libultra's OSTask. */
#ifdef PORT
typedef struct {u32 type,flags; unsigned long boot; u32 bootSize; unsigned long ucode; u32 ucodeSize; unsigned long data; u32 dataSize; unsigned long stack; u32 stackSize; unsigned long output; unsigned long outputSize; unsigned long input; u32 inputSize; unsigned long yield; u32 yieldSize;} OSTask;
#else
typedef struct {u32 type,flags,boot,bootSize,ucode,ucodeSize,data,dataSize,stack,stackSize,output,outputSize,input,inputSize,yield,yieldSize;} OSTask;
#endif
extern OSTask D_800AB9A0;
void __osCopyBytes(void *,void *,s32);
u32 osVirtualToPhysical(void *);
void osWritebackDCache(void *,s32);
void sp_status_write(s32);
s32 rsp_set_pc_if_halted(s32);
s32 sp_dma_start(s32,s32,void *,s32);
s32 sp_status_busy(void);

/* Loads an RSP task. Copies src into the global task D_800AB9A0 (64 bytes), turns its pointers
 * into physical addresses, and points data/yield at the yield buffer when flag bit 0 is set.
 * Then it resets the RSP, DMAs the ucode and data, and DMAs the boot code. */
void func_8008DD00(OSTask *src) {
OSTask *task=&D_800AB9A0;
#ifdef PORT
__osCopyBytes(src,task,sizeof(OSTask));
#else
__osCopyBytes(src,task,64);
#endif
if (D_800AB9A0.ucode) {
D_800AB9A0.ucode=osVirtualToPhysical((void *)D_800AB9A0.ucode);
}
if (D_800AB9A0.data) {
D_800AB9A0.data=osVirtualToPhysical((void *)D_800AB9A0.data);
}
if (D_800AB9A0.stack) {
D_800AB9A0.stack=osVirtualToPhysical((void *)D_800AB9A0.stack);
}
if (D_800AB9A0.output) {
D_800AB9A0.output=osVirtualToPhysical((void *)D_800AB9A0.output);
}
if (D_800AB9A0.outputSize) {
D_800AB9A0.outputSize=osVirtualToPhysical((void *)D_800AB9A0.outputSize);
}
if (D_800AB9A0.input) {
D_800AB9A0.input=osVirtualToPhysical((void *)D_800AB9A0.input);
}
if (D_800AB9A0.yield) {
D_800AB9A0.yield=osVirtualToPhysical((void *)D_800AB9A0.yield);
}
if(D_800AB9A0.flags&1) {
D_800AB9A0.data=D_800AB9A0.yield;
D_800AB9A0.dataSize=D_800AB9A0.yieldSize;
src->flags&=~1;
if(D_800AB9A0.flags&4) {
D_800AB9A0.ucode=*(u32 *)((src->yield+0xBFC)|0xA0000000);
}
}
osWritebackDCache(task,64);
sp_status_write(0x2B00);
do {}while(rsp_set_pc_if_halted(0x04001000)==-1);
do {}while(sp_dma_start(1,0x04000FC0,task,64)==-1);
do {}while(sp_status_busy()!=0);
do {}while(sp_dma_start(1,0x04001000,(void *)task->boot,task->bootSize)==-1);
}
