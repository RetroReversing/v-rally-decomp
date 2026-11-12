/* Reads one flag byte from the stream at src, stores it in obj+0xB0, and when it is
 * non-zero copies the float at obj+0x28 to obj+0x4C. Returns the advanced stream pointer. */
unsigned char *read_flag_and_copy_pos(char *obj, unsigned char *src) {
    unsigned char flag = *src++;
    obj[0xB0] = flag;
    if (flag) {
        *(float *)(obj + 0x4C) = *(float *)(obj + 0x28);
    }
    return src;
}
