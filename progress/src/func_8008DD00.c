/* RSP task descriptor, as in libultra's OSTask. */
typedef struct {u32 type,flags,boot,bootSize,ucode,ucodeSize,data,dataSize,stack,stackSize,output,outputSize,input,inputSize,yield,yieldSize;} OSTask;
extern OSTask D_800AB9A0;
void __osCopyBytes(void *,void *,s32);
u32 osVirtualToPhysical(void *);
void osWritebackDCache(void *,s32);
void func_80095AC0(s32);
s32 func_80095A90(s32);
s32 sp_dma_start(s32,s32,void *,s32);
s32 func_80095960(void);

/* Loads an RSP task. Copies src into the global task D_800AB9A0 (64 bytes), turns its pointers
 * into physical addresses, and points data/yield at the yield buffer when flag bit 0 is set.
 * Then it resets the RSP, DMAs the ucode and data, and DMAs the boot code. */
void func_8008DD00(OSTask *src) {
OSTask *task=&D_800AB9A0;
__osCopyBytes(src,task,64);
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
func_80095AC0(0x2B00);
do {}while(func_80095A90(0x04001000)==-1);
do {}while(sp_dma_start(1,0x04000FC0,task,64)==-1);
do {}while(func_80095960()!=0);
do {}while(sp_dma_start(1,0x04001000,(void *)task->boot,task->bootSize)==-1);
}
