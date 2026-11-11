s32 car_heading_error();

/* Sets flag 0x20 in the car's flags word (+0x14) while its heading error is
 * between 0x501 and 0xAFF, i.e. the car is facing away from the track.
 * Flag 0x80 clears 0x20 again. */
void func_800448A4(void *car) {
    s32 flags;
    s32 new_flags;
    s32 err;

    err = car_heading_error();
    flags = ~0x20;
    if ((u32)(err - 0x501) < 0x5FFU) {
        new_flags = *(vs32 *)((char *)car + 0x14) | 0x20;
    } else {
        new_flags = flags & *(vs32 *)((char *)car + 0x14);
    }
    *(vs32 *)((char *)car + 0x14) = new_flags;
    flags = *(vs32 *)((char *)car + 0x14);
    if (flags & 0x80) {
        *(vs32 *)((char *)car + 0x14) = flags & ~0x20;
    }
}
