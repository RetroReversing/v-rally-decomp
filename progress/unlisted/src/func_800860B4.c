extern s32 D_800C6F14;
extern s32 D_800C5CF0;
extern s32 D_800C358C;
extern s32 D_800A1B80;
extern void *D_800C80C0;
s32 taskOpen(s32, s32, s32);
s32 create_thread_on_ctx(void *, s32, s32, s32);
void func_80085D90(void);
void func_80085FB8(void);

/* Sets up two handles with taskOpen, starts the worker thread func_80085D90 on a 0x2000-byte
 * stack, and swaps in func_80085FB8 as the callback at D_800C80C0, saving the previous callback in D_800A1B80. */
void func_800860B4(void)
{
    s32 old;

    D_800C6F14 = taskOpen(0xC, 3, 8);
    D_800C5CF0 = taskOpen(0xC, 4, 8);
    D_800C358C = create_thread_on_ctx(func_80085D90, 0x2000, 0x74, 0);
    old = (s32) D_800C80C0;
    D_800C80C0 = func_80085FB8;
    D_800A1B80 = old;
}
