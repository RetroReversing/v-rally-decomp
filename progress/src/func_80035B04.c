typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s8 side;
    s8 pad;
} Item8;

extern char gStreamState[];
u64 osGetTime(void);
s32 func_80098090();
void rand_seed(u32);

/* Scatters a list of items at random: each gets a position (x up to 8191, y up to
   2047, z up to 8191) and a side, 0 for the first half of the list and 1 for the rest.
   The count comes from the current track's header. Reseeds the random generator first. */
void func_80035B04(Item8 *items) {
    u32 count;
    u32 remaining;
    s32 r;

    count = *(u32 *)(*(char **)(gStreamState + 0x7E6E) + 8);
    rand_seed((u32)osGetTime());
    r = count;
    count--;
    if (r != 0) {
        do {
            if (count < (*(u32 *)(*(char **)(gStreamState + 0x7E6E) + 8) >> 1)) {
                items->side = 0;
            } else {
                items->side = 1;
            }
            items->x = func_80098090() % 8191;
            items->y = func_80098090() % 2047;
            items->z = func_80098090() % 8191;
            items++;
            remaining = count;
            count--;
        } while (remaining != 0);
    }
}
