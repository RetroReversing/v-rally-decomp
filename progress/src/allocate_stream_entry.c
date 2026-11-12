/* Allocates a pool block (size from D_800C3370) and stores its pointer in D_800C3398 and D_800C339C. */
extern int D_800C3370;
extern int D_800C3398;
extern int D_800C339C;
int poolAlloc(int a, int b);

int allocate_stream_entry(int arg0) {
    int t = poolAlloc(arg0, D_800C3370);

    D_800C3398 = t;
    D_800C339C = t;
    return 0;
}
