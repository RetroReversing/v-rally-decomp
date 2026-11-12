/* Stores the byte at src into obj+0xB4 and returns the position after it, for reading a stream one byte at a time. */
void *obj_read_byte_0xB4(void *obj, u8 *src) {
    *(u8 *)((s8 *)obj + 0xB4) = (u8) *src;
    return src + 1;
}
