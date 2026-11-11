void *poolAllocNode(s32, s32);
extern void func_8004C088(void);
extern void func_8004C370(void);

/* Allocates a 0x58-byte object and copies the source object's fields into it at fixed
 * offsets. Sets all of its colour bytes to 0xFF and installs the two callbacks. */
void func_8004C4D0(s32 pool_id, s8 *src)
{
    s8 *obj;
    s32 src_field_3D4;
    u8 full;

    obj = poolAllocNode(pool_id, 0x58);
    *(s32 *)(obj + 0x10) = *(s32 *)(src + 0x90);
    *(s32 *)(obj + 0x20) = *(s32 *)(src + 0xDC);
    *(s32 *)(obj + 0x30) = *(s32 *)(src + 0x128);
    *(s32 *)(obj + 0x14) = *(s32 *)(src + 0x174);
    *(s32 *)(obj + 0x24) = *(s32 *)(src + 0x1C0);
    *(s32 *)(obj + 0x34) = *(s32 *)(src + 0x20C);
    *(s32 *)(obj + 0x18) = *(s32 *)(src + 0x258);
    *(s32 *)(obj + 0x28) = *(s32 *)(src + 0x2A4);
    *(s32 *)(obj + 0x38) = *(s32 *)(src + 0x2F0);
    *(s32 *)(obj + 0x1C) = *(s32 *)(src + 0x33C);
    *(s32 *)(obj + 0x2C) = *(s32 *)(src + 0x388);
    src_field_3D4 = *(s32 *)(src + 0x3D4);
    full = 0xFF;
    *(u8 *)(obj + 0x40) = full;
    *(u8 *)(obj + 0x44) = full;
    *(u8 *)(obj + 0x48) = full;
    *(u8 *)(obj + 0x4C) = full;
    *(u8 *)(obj + 0x41) = full;
    *(u8 *)(obj + 0x45) = full;
    *(u8 *)(obj + 0x49) = full;
    *(u8 *)(obj + 0x4D) = full;
    *(u8 *)(obj + 0x42) = full;
    *(s32 *)(obj + 0x3C) = src_field_3D4;
    *(u8 *)(obj + 0x46) = full;
    *(u8 *)(obj + 0x4A) = full;
    *(u8 *)(obj + 0x4E) = full;
    *(u8 *)(obj + 0x43) = full;
    *(u8 *)(obj + 0x47) = full;
    *(u8 *)(obj + 0x4B) = full;
    *(u8 *)(obj + 0x4F) = full;
    *(s32 *)(obj + 0xC) = 1;
    *(void (**)(void))(obj + 0x54) = func_8004C088;
    *(void (**)(void))(obj + 0x50) = func_8004C370;
}
