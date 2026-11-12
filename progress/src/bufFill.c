void memset(void *dst, s32 value, s32 size);

/* Fill size bytes at dst with the low byte of value. */
void bufFill(void *dst, s32 size, s32 value) { memset(dst, value, size); }
