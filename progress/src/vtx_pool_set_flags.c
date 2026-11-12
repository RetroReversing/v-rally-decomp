/* Sets field 3 of each 8-halfword (16-byte) record in the block to 3. */
void vtx_pool_set_flags(s16 *recs, s32 count)
{
    s32 pad;
    s32 i;

    for (i = 0; i < count; i++) {
        recs[3] = 3;
        recs += 8;
    }
}
