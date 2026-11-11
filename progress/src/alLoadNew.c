s32 func_80093790(void *a0, void *fn2, void *fn3, s32 n4);
s32 alHeapDBAlloc(s32, s32, s32, s32, s32);
extern void *alAdpcmPull;
extern void *alLoadParam;

/* Initialises an audio load object: sets up its load state, allocates two buffers from the heap, and stores the read callback and its argument block at 0x34. */
void alLoadNew(void *load, s32 (*read)(void *), s32 heap)
{
    func_80093790(load, &alAdpcmPull, &alLoadParam, 0);
    *(s32 *)((s8 *)load + 0x14) = alHeapDBAlloc(0, 0, heap, 1, 0x20);
    *(s32 *)((s8 *)load + 0x18) = alHeapDBAlloc(0, 0, heap, 1, 0x20);
    *(s32 *)((s8 *)load + 0x30) = read((s8 *)load + 0x34);
    *(s32 *)((s8 *)load + 0x3C) = 0;
    *(s32 *)((s8 *)load + 0x40) = 1;
    *(s32 *)((s8 *)load + 0x44) = 0;
}
