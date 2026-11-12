extern s32 D_8009E250;
extern s32 D_8009E254;
extern s32 D_8009E258;

/* Store object state offsets 0x90 and 0xDC into global state variables */
void func_8001CF3C(u8 *obj) {
    D_8009E250 = *(s32 *)(obj + 0x90);
    D_8009E254 = *(s32 *)(obj + 0x90);
    D_8009E258 = *(s32 *)(obj + 0xDC);
}
