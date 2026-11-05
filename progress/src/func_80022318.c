void func_8001B730(u8 *a0);
s32 func_80098180(const u8 *a0, const u8 *a1);
u8 *func_80098290(u8 *dst, u8 *src);

void *func_80022318(void **arg0, u8 *arg1) {
    s32 buf[4];
    void *node;

    func_80098290((u8 *)buf, arg1);
    func_8001B730((u8 *)buf);
    node = *arg0;
    if (node != NULL) {
        do {
            if (func_80098180(*(void **)((u8 *)node + 0xC), (const u8 *)buf) == 0) {
                return node;
            }
            node = *(void **)((u8 *)node + 4);
        } while (node != NULL);
    }
    return NULL;
}
