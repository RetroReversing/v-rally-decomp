s32 memset(s32, s32, s32);

/* Resets a 0x28-byte sound/select state block: clears it, sets the mode bytes and the
 * four per-slot flag groups to 1, zeroes the four 16-bit slot values, and stores the
 * default timing and magic word. */
void func_8001B514(void *state) {
    s32 shifted;
    s32 idx;
    s8 next;
    s8 i;
    void *entry;

    memset((s32)state, 0, 0x28);
    i = 0;
    *(s16 *)((s8 *)state + 0xC) = 0;
    *(s8 *)((s8 *)state + 9) = 1;
    do {
        shifted = i << 0x18;
        next = i + 1;
        i = next;
        idx = shifted >> 0x18;
        entry = state + idx;
        *(s8 *)((s8 *)entry + 0x10) = 1;
        *(s8 *)((s8 *)entry + 0x14) = 1;
        *(s8 *)((s8 *)entry + 0x18) = 1;
        *(s16 *)((s8 *)state + (idx * 2) + 0x1C) = 0;
    } while (next < 4);
    *(s16 *)((s8 *)state + 0xA) = 8;
    *(s8 *)((s8 *)state + 4) = 7;
    *(s32 *)((s8 *)state + 0x24) = 0x75834210;
}
