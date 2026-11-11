s32 streamReadBytes();
s32 func_80082290();
s32 readStreamHeader();
s32 func_800848A0();
extern char gOrderState[];
extern char gStreamState[];

/* Makes entry index `index` of the table at gOrderState+0x8AE0 the current entry
 * (stored at +0x8AE4), starts it with func_800848A0, reads the 4-byte stream
 * header and then the stream header, and passes the stream's u16 at +0x30C6 on. */
void stream_load_entry(s32 index) {
    s32 *entry;

    entry = *(s32 *)(gOrderState + 0x8AE0) + (index * 8);
    *(s32 * *)(gOrderState + 0x8AE4) = entry;
    func_800848A0(*entry);
    streamReadBytes((gOrderState + 0x8AE0) - 8, 4);
    readStreamHeader();
    func_80082290(*(u16 *)(gStreamState + 0x30C6));
}
