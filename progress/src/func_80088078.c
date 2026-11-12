/* Stores the byte at *src into offset 0xC2 of obj and returns the next source byte pointer. */
void *func_80088078(void *obj, u8 *src) {
    *(u8 *)((s8 *)obj + 0xC2) = (u8) *src;
    return src + 1;
}
