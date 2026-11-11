extern f64 D_800A6D18;

/* Reads one signed byte from `cursor`, scales it by D_800A6D18, and updates the
 * object's position at +0x2C from the change since the last delta (kept at +0x88).
 * Returns the cursor advanced past the byte. */
void *func_80087CF4(void *obj, u8 *cursor)
{
    s32 raw;
    f32 delta;
    f32 position;

    raw = *cursor;
    cursor++;
    if (raw & 0x80) {
        raw |= ~0xFF;
    }
    delta = (f32)((f64)(f32)raw * D_800A6D18);
    position = (*(f32 *)((char *)obj + 0x2C) - *(f32 *)((char *)obj + 0x88)) + delta;
    *(f32 *)((char *)obj + 0x88) = delta;
    *(f32 *)((char *)obj + 0x2C) = position;
    return cursor;
}
