u8 classifyStreamCode();
extern u8 D_8009EB83;
extern char D_800A1530[];
extern char gStreamState[];

/* Looks up the one-character stream code for a select slot: slots 0-5 read the stream
   table at gStreamState+0x10386 and classify the code there, slots 6-9 use D_8009EB83,
   and the result indexes D_800A1530. */
u8 select_stream_char(s32 slot, s32 entry, s32 sub)
{
    s32 idx;
    s32 base;
    s32 off;
    u8 type;
    s32 e;
    s32 scaled;

    idx = slot & 0xFF;
    type = 0;
    if (idx >= 0) {
        if (idx < 6) {
            e = entry & 0xFF;
            idx = idx << 2;
            scaled = (e << 1) + e;
            scaled = (scaled << 2) - e;
            scaled = (scaled << 4) + e;
            base = *(s32 *)(gStreamState + 0x10386 + idx) + (scaled << 2);
            off = (sub & 0xFF) * 14 + 0x24C;
            type = classifyStreamCode(base + off, base);
        } else if (idx < 0xA) {
            type = D_8009EB83;
        }
    }
    return D_800A1530[type];
}
