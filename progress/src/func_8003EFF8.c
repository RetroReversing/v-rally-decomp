extern char gOrderState[];

/* Sets the state flags on the object at obj: when its +0xA8 target has a child at +0x24,
 * clears the flag at +0x78 and sets bit 4 at +0x80; if that child's +0x14 flags match 0x20,
 * sets +0x78 to 1 and clears bit 4 again when bit 3 of the order word at 0x121C is set. */
void func_8003EFF8(void *obj)
{
    void *target;
    void *child;
    s32 bit;

    target = *(void **)((char *)obj + 0xA8);
    child = *(void **)((char *)target + 0x24);
    if (child != NULL) {
        *(s16 *)((char *)obj + 0x78) = 0;
        *(s32 *)((char *)obj + 0x80) |= 4;
        if ((*(s32 *)((char *)child + 0x14) & 0x320) == 0x20) {
            bit = (*(u32 *)(gOrderState + 0x121C) >> 3) & 1;
            *(s16 *)((char *)obj + 0x78) = 1;
            if (bit) {
                *(s32 *)((char *)obj + 0x80) &= ~4;
            }
        }
    }
}
