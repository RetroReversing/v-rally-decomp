void func_8000DBC0(int a);

/* Swaps the two buffer words at +0x20 (current) and +0x24 (pending) when a pending buffer is set,
 * then finishes the frame on the current buffer. */
void func_8000DF74(char *obj) {
    char *p = obj;
    if (*(int *)(p + 0x24)) {
        int t = *(int *)(p + 0x20);
        *(int *)(p + 0x20) = *(int *)(p + 0x24);
        *(int *)(p + 0x24) = t;
    }
    func_8000DBC0(*(int *)(p + 0x20));
}
