/* Fills the header block of a record at state+0x24 (counter, timestamp and a link) and the
 * eight-slot table at state+0x7C from the source object (`src`, +0x174 for each table entry).
 * The table is cleared first, then one entry is copied per count at src+0x128. */
void func_80023CE0(void *src, void *state)
{
    s32 *table;
    s32 *p;
    s32 i;
    s32 *q;
    s32 *rec;
    s32 val;

    rec = *(s32 **)((u8 *)state + 0x24);
    val = *(s32 *)((u8 *)src + 0x90);
    table = *(s32 **)((u8 *)state + 0x7C);
    rec[1] = val;
    *(s32 *)(*(u8 **)((u8 *)state + 0x24)) = *(s32 *)(*(u8 **)((u8 *)state + 0x24) + 4) + 1;
    *(s32 *)(*(u8 **)((u8 *)state + 0x24) + 0xC) = *(s32 *)((u8 *)src + 0xDC);
    table[8] = *(s32 *)((u8 *)src + 0x128);
    p = table + 7;
    for (i = 7; i >= 0; i--) {
        *p-- = 0;
    }
    i = 0;
    if (table[8] >= 0) {
        q = table;
        do {
            *q++ = *(s32 *)((u8 *)src + 0x174);
            src = (u8 *)src + 0x4C;
            i++;
        } while (table[8] >= i);
    }
}
