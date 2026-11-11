/* Copies the four state bytes (0x90-0x93) and the u16 at 0xE from the parent
 * object (pointer at offset 0), then sets or clears bit 4 of the flags word at 0x80
 * to match the parent's flags. */
void func_8003A73C(void *obj)
{
    u8 *parent;
    s32 clearBit4;
    s32 flags;

    parent = *(u8 **) obj;
    *(u8 *) ((u8 *) obj + 0x90) = *(u8 *) (parent + 0x90);
    *(u8 *) ((u8 *) obj + 0x91) = *(u8 *) (parent + 0x91);
    *(u8 *) ((u8 *) obj + 0x92) = *(u8 *) (parent + 0x92);
    clearBit4 = ~4;
    *(u8 *) ((u8 *) obj + 0x93) = *(u8 *) (parent + 0x93);
    parent = (u8 *) parent;
    *(u16 *) ((u8 *) obj + 0xE) = *(u16 *) (parent + 0xE);
    if (*(s32 *) (parent + 0x80) & 4) {
        flags = *(s32 *) ((u8 *) obj + 0x80) | 4;
    } else {
        flags = *(s32 *) ((u8 *) obj + 0x80) & clearBit4;
    }
    *(s32 *) ((u8 *) obj + 0x80) = flags;
}
