s32 mat3x3_from_euler();

/* Sets an object's transform: writes the three angles (as s16 copies) to a
   local array, builds the rotation matrix into the object's matrix block at
   +0x40, then stores the three position words at +0x54. */
void func_800230C0(void *obj, s32 *pos, s32 *angles) {
    s16 ang[3];
    s32 *src;
    u32 i;
    void *dst;

    dst = *(void **)((char *)obj + 0x30);
    ang[0] = angles[0];
    src = pos;
    ang[1] = angles[1];
    ang[2] = angles[2];
    dst += 0x40;
    mat3x3_from_euler(ang, dst);
    i = 0;
    do {
        *(s32 *)((char *)dst + 0x14) = *src;
        src += 1;
        i += 1;
        dst += 4;
    } while (i < 3U);
}
