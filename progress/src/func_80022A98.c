extern s32 gMirrorListHead;

/* Walks the 11 descriptors (0x1C bytes each) at table+0xD0 and fills the output
   array out with the words they select from the per-slot data at table+0x48 and
   table+0x74. Entries with flag bit 0 use the gMirrorListHead negation rule. */
void func_80022A98(u8 *table, s32 *out)
{
    s32 pad[3];
    s32 *out_ptr;
    u8 *dst_tmp;
    s32 *dst;
    u8 *slot;
    u8 *src_base;
    int negate_a;
    s32 dflt;
    s32 val;
    u32 neg_b;
    u32 desc_ofs;
    u32 desc_ofs2;
    u32 idx;
    u32 k;
    u32 src_ofs;
    u32 i;
    u32 n;

    idx = 0;
    desc_ofs = 0;
    out_ptr = out;
    slot = table;
    do
    {
        if ((*((u32 *) ((desc_ofs + (*((u32 *) (table + 0xD0)))) + 8))) & 1)
        {
            do
            {
                k = 0;
                if ((*((u32 *) (desc_ofs + (*((u32 *) (table + 0xD0)))))) != 0)
                {
                    negate_a = (idx ^ 6) < 1;
                    val = negate_a;
                    dflt = gMirrorListHead;
                    src_base = slot;
                    desc_ofs2 = desc_ofs;
                    dst = out_ptr;
                    src_ofs = (u32) 0;
                    do
                    {
                        neg_b = (k ^ 0x54) < 1;
                        if (desc_ofs)
                        {
                        }
                        if (val & neg_b)
                        {
                            *dst = dflt - (*((s32 *) (src_ofs + (*((s32 *) (src_base + 0x48))))));
                        }
                        else
                        {
                            *dst = *((s32 *) (src_ofs + (*((s32 *) (src_base + 0x48)))));
                        }
                        dst++;
                        k++;
                        src_ofs += 4;
                    }
                    while (k < (*((u32 *) (desc_ofs2 + (*((u32 *) (table + 0xD0)))))));
                }
            }
            while (0);
            out_ptr += *((u32 *) (desc_ofs + (*((u32 *) (table + 0xD0)))));
        }
        if ((*((u32 *) ((desc_ofs + (*((u32 *) (table + 0xD0)))) + 8))) & 2)
        {
            k = 0;
            dst_tmp = (desc_ofs + (*((u32 *) (table + 0xD0)))) + 4;
            if ((*((u32 *) dst_tmp)) != 0)
            {
                if (dst)
                {
                    desc_ofs2 = (u32) slot;
                    src_base = (u8 *) desc_ofs;
                    dst = out_ptr;
                }
                else
                {
                    desc_ofs2 = (u32) slot;
                    src_base = (u8 *) desc_ofs;
                    dst = out_ptr;
                }
                do
                {
                    *dst = *((s32 *) ((*((s32 *) (desc_ofs2 + 0x74))) + (k * 4)));
                    k++;
                    dst++;
                }
                while (k < (*((u32 *) ((((u32) src_base) + (*((u32 *) (table + 0xD0)))) + 4))));
            }
            out_ptr += *((u32 *) ((desc_ofs + (*((u32 *) (table + 0xD0)))) + 4));
        }
        desc_ofs += 0x1C;
        idx++;
        slot += 4;
    }
    while (idx < 0xB);
}
