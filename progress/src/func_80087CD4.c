/* Stores the byte at *src into obj's field at 0xB1 and returns the advanced source pointer. */
u8 *func_80087CD4(void *obj, u8 *src) {
    *(u8 *)((s8 *)obj + 0xB1) = (u8) *src;
    return src + 1;
}
