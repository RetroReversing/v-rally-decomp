/* Picks the next mode word for the object at ctx+0x4C. Does nothing unless the record at
 * ctx+0x70 has a status (+0x28) other than -1. Mode 0x18 is used when the record at ctx+0x6C
 * has a level of at least 2 and the value behind ctx+0x48 is not 5. Otherwise mode 0x10. */
void func_80042CC4(void *ctx)
{
    if (*(s32 *)(*(u8 **)((u8 *)ctx + 0x70) + 0x28) != -1) {
        if (((u32) *(u32 *)(*(u8 **)((u8 *)ctx + 0x6C) + 8) >= 2U) && (**(s32 **)((u8 *)ctx + 0x48) != 5)) {
            *(s32 *)(*(u8 **)((u8 *)ctx + 0x4C) + 0x14) = 0x18;
            return;
        }
        *(s32 *)(*(u8 **)((u8 *)ctx + 0x4C) + 0x14) = 0x10;
    }
}
