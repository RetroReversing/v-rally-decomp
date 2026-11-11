s32 heapFreeBlock(void *);

typedef struct { s32 pad[3]; void *child; } ObjE2;

s32 func_8000E2B0(ObjE2 *arg0) {
    s32 *p;
    void *child;
    p = (s32 *)arg0;
    child = (void *)p[3];
    if (child) {
        heapFreeBlock(child);
        return heapFreeBlock(p);
    }
    return 0;
}
