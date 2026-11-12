s32 func_80042B84(void *, u8, u8, u8, s32);

/* Registers the object's record (its embedded block at +0x4C) with func_80042B84, passing
 * the four state bytes stored at +0xDF, +0x12B, +0x177 and the word at +0x1C3. */
void func_8001D908(void *obj)
{
    func_80042B84((char *)obj + 0x4C, *(u8 *)((char *)obj + 0xDF), *(u8 *)((char *)obj + 0x12B),
                  *(u8 *)((char *)obj + 0x177), (s32)*(u8 *)((char *)obj + 0x1C3));
}
