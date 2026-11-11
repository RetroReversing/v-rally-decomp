typedef struct Packet {
    s32 w[5];
} Packet;

extern s32 gOrderState;
extern s32 gStreamState;

void dmaCopyChunks(s32, s32, s32, s32, Packet);
void *order_table_search(s32);
void func_80081C30(void);
void osWritebackDCacheAll(void);

/* Stores the new value in two state words, loads the record for that value, copies its fields into the global state, then flushes the data cache. */
void streamLoadRecord(s32 value) {
    void *rec;
    s32 base;

    *(s32 *)((u8 *)&gStreamState + 0x30EA) = value;
    *(s32 *)((u8 *)&gStreamState + 0x30EE) = value;
    rec = order_table_search(*(s32 *)((u8 *)&gOrderState + 0x8AB8));
    base = *(s32 *)((u8 *)&gOrderState + 0x8AB0) + *(s32 *)((u8 *)rec + 0x1C);
    dmaCopyChunks(base, *(s32 *)((u8 *)&gStreamState + 0x308A), 0x2000,
                  *(s32 *)((u8 *)&gOrderState + 0x2358),
                  *(Packet *)((u8 *)&gOrderState + 0x235C));
    *(s32 *)((u8 *)&gStreamState + 0x30C2) = *(s32 *)((u8 *)rec + 0x10);
    *(s32 *)((u8 *)&gStreamState + 0x30BE) = *(s32 *)((u8 *)rec + 0x14);
    *(u16 *)((u8 *)&gStreamState + 0x30BC) = *(u16 *)((u8 *)rec + 0x1A);
    *(u16 *)((u8 *)&gStreamState + 0x30BA) = *(u16 *)((u8 *)rec + 0x18);
    *(s32 *)((u8 *)&gStreamState + 0x308E) = *(s32 *)((u8 *)rec + 0x28);
    *(s32 *)((u8 *)&gStreamState + 0x3092) = *(s32 *)((u8 *)rec + 0x24);
    *(s32 *)((u8 *)&gOrderState + 0x8ACC) = *(s32 *)((u8 *)rec + 0x14);
    *(s32 *)*(s32 *)((u8 *)&gOrderState + 0x8AE4) = *(s32 *)((u8 *)rec + 0x20);
    *(s32 *)(*(s32 *)((u8 *)&gOrderState + 0x8AE4) + 4) = *(s32 *)((u8 *)rec + 0x14);
    *(s32 *)((u8 *)&gOrderState + 0x8AD0) = *(s32 *)((u8 *)rec + 0x10);
    *(s32 *)((u8 *)&gStreamState + 0x30A6) = *(s32 *)((u8 *)rec + 0x1C);
    func_80081C30();
    osWritebackDCacheAll();
}
