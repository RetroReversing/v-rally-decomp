extern char gStreamState[];
extern char D_800A2518[];

typedef struct Ring {
    s32 *wakeFlag;
    s32 pad4;
    s32 count;
    s32 head;
    s32 capacity;
    s32 *items;
} Ring;

s32 func_8008B624(void *, void *);
void func_8008B5DC(void *, s32);

/* Pushes the word at gStreamState+0x763E onto the ring at gStreamState+0x763A
 * when it has room, then wakes the waiter (func_8008B5DC on D_800A2518) if
 * the ring's wake flag is set. */
void __osLeoResume(void) {
    Ring *ring;
    s32 idx;

    ring = *(Ring **)(gStreamState + 0x763A);
    if (ring != NULL) {
        if (ring->count < ring->capacity) {
            idx = (ring->head + ring->count) % ring->capacity;
            ring->items[idx] = *(s32 *)(gStreamState + 0x763E);
            ring->count++;
            if (*ring->wakeFlag != 0) {
                func_8008B5DC(D_800A2518, func_8008B624(ring, ring));
            }
        }
    }
}
