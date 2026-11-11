extern void *gSelectState;
extern s32 gSelectBuffer;
extern void func_80062B70();
extern void func_80062DF4();
extern void func_8005C198();
extern s32 select_reset_text(s32, s32);
extern void heapFreeBlock(s32);

/* Resets the select-screen state: frees the heap block held in gSelectBuffer if any,
   runs the two teardown calls, and installs two callbacks in the select state. */
s32 func_800631A4(s32 arg0, s32 arg1)
{
    func_8005C198();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    select_reset_text(arg0, arg1);
    *(void (**)())((s8 *)gSelectState + 0x288) = func_80062B70;
    *(void (**)())((s8 *)gSelectState + 0x28C) = func_80062DF4;
    return 0;
}
