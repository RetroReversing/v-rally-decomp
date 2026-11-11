/* Copies eight 32-bit fields from obj (offsets 0x90, 0xDC, 0x128, ... 0x2A4, 0x4C apart)
 * into the block that ctx points to through its +0x28 pointer, at +0xA8 to +0xC4. */
#define CTX_BLOCK(ctx) (*(u8 **)((u8 *)(ctx) + 0x28))

void func_80023EF4(void *obj, void *ctx)
{
    *(s32 *)(CTX_BLOCK(ctx) + 0xA8) = *(s32 *)((u8 *)obj + 0x90);
    *(s32 *)(CTX_BLOCK(ctx) + 0xAC) = *(s32 *)((u8 *)obj + 0xDC);
    *(s32 *)(CTX_BLOCK(ctx) + 0xB0) = *(s32 *)((u8 *)obj + 0x128);
    *(s32 *)(CTX_BLOCK(ctx) + 0xB4) = *(s32 *)((u8 *)obj + 0x174);
    *(s32 *)(CTX_BLOCK(ctx) + 0xB8) = *(s32 *)((u8 *)obj + 0x1C0);
    *(s32 *)(CTX_BLOCK(ctx) + 0xBC) = *(s32 *)((u8 *)obj + 0x20C);
    *(s32 *)(CTX_BLOCK(ctx) + 0xC0) = *(s32 *)((u8 *)obj + 0x258);
    *(s32 *)(CTX_BLOCK(ctx) + 0xC4) = *(s32 *)((u8 *)obj + 0x2A4);
}
