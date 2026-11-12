s32 strCmp(void *,void *); extern u8 D_8009D468[],D_8009D474[]; extern u8 gOrderState[];
#define gSnapshotBlock (*(void **)(gOrderState+0x8A28))

/* Ors the flag word of each named entry into the state word at +0xA0. The record
 * list at arg0 holds 0x4C-byte entries (name at +0x4C in the record, count at +0x44);
 * each name is looked up in the 14-byte name table from the current entry onward, and
 * the matching 16-bit flags from D_8009D474 are or-ed in. */
void func_8001D4EC(u8 *arg0)
{
    s32 j;
    u32 rec;
    s32 recOff;
    u16 *flags;
    u8 *names;
    u8 *state;
    s32 pad[2];

    if (gSnapshotBlock) {
        *(s32 *)((u8 *)gSnapshotBlock + 0xA0) = 0;
        rec = 0;
        if (*(u32 *)(arg0 + 0x44)) {
            names = D_8009D468;
            recOff = 0x4C;
entryLoop:
            {
                j = 0;
#ifdef PORT
                while (strCmp(arg0 + recOff, names + (rec + j) * 14)) {
#else
                while (strCmp(arg0 + recOff, (void *)((rec + j) * 14 + (u32)names))) {
#endif
                    j++;
                }
                state = gSnapshotBlock;
                flags = (u16 *)(D_8009D474 + (rec + j) * 14);
                *(s32 *)(state + 0xA0) |= *flags;
                rec++;
                recOff += 0x4C;
            }
            if (rec < *(u32 *)(arg0 + 0x44)) goto entryLoop;
        }
    }
}
