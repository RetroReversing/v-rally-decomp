extern void *D_800C607C;

/* Sets the flag at +0x2E of the global block to 1 and stores half of src->+0x90 at +0x2F. */
void func_8001E600(void *src) {
    *(s8 *)((s8 *)D_800C607C + 0x2E) = 1;
    *(s8 *)((s8 *)D_800C607C + 0x2F) = (s8)((s32)*(s32 *)((s8 *)src + 0x90) / 2);
}
