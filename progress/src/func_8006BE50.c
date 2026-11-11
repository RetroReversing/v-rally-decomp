/* Rolls a two-block parameter history in an object: the current block (0x10..0x1B)
 * is copied to the previous block (0x20..0x2B). Mode 0 also loads the next current
 * block from the staging bytes at 0x00..0x0B and clears the flag at 0x1C. */
void func_8006BE50(void *arg0, s32 arg1)
{
    s32 mode;

    mode = arg1 & 0xFF;
    switch (mode) {
    case 0:
        *(s8 *)((u8 *)arg0 + 0x2C) = 0;
        *(s8 *)((u8 *)arg0 + 0x1C) = 0;
        *(u8 *)((u8 *)arg0 + 0x26) = *(u8 *)((u8 *)arg0 + 0x16);
        *(u8 *)((u8 *)arg0 + 0x27) = *(u8 *)((u8 *)arg0 + 0x17);
        *(u8 *)((u8 *)arg0 + 0x28) = *(u8 *)((u8 *)arg0 + 0x18);
        *(s32 *)((u8 *)arg0 + 0x20) = *(s32 *)((u8 *)arg0 + 0x10);
        *(u8 *)((u8 *)arg0 + 0x24) = *(u8 *)((u8 *)arg0 + 0x14);
        *(u8 *)((u8 *)arg0 + 0x2A) = *(u8 *)((u8 *)arg0 + 0x1A);
        *(u8 *)((u8 *)arg0 + 0x2B) = *(u8 *)((u8 *)arg0 + 0x1B);
        *(u8 *)((u8 *)arg0 + 0x16) = *(u8 *)((u8 *)arg0 + 6);
        *(u8 *)((u8 *)arg0 + 0x17) = *(u8 *)((u8 *)arg0 + 7);
        *(u8 *)((u8 *)arg0 + 0x18) = *(u8 *)((u8 *)arg0 + 8);
        *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 0);
        *(u8 *)((u8 *)arg0 + 0x14) = *(u8 *)((u8 *)arg0 + 4);
        *(u8 *)((u8 *)arg0 + 0x1A) = *(u8 *)((u8 *)arg0 + 0xA);
        *(u8 *)((u8 *)arg0 + 0x1B) = *(u8 *)((u8 *)arg0 + 0xB);
        return;
    case 1:
        *(s8 *)((u8 *)arg0 + 0x2C) = 0;
        *(u8 *)((u8 *)arg0 + 0x26) = *(u8 *)((u8 *)arg0 + 0x16);
        *(u8 *)((u8 *)arg0 + 0x27) = *(u8 *)((u8 *)arg0 + 0x17);
        *(u8 *)((u8 *)arg0 + 0x28) = *(u8 *)((u8 *)arg0 + 0x18);
        *(s32 *)((u8 *)arg0 + 0x20) = *(s32 *)((u8 *)arg0 + 0x10);
        *(u8 *)((u8 *)arg0 + 0x24) = *(u8 *)((u8 *)arg0 + 0x14);
        *(u8 *)((u8 *)arg0 + 0x2A) = *(u8 *)((u8 *)arg0 + 0x1A);
        *(u8 *)((u8 *)arg0 + 0x2B) = *(u8 *)((u8 *)arg0 + 0x1B);
        return;
    }
}
