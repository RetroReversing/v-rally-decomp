extern void func_8004C7F0(void *);
extern void stream_free_all_blocks(void);
extern s32 classifyStreamCode(void *);
extern void resolve_path(void *);
extern void appendString(void *, void *);
extern void *memset(void *, int, u32);
extern u8 aTexPackDir[];
extern u8 D_800A564C[];
extern u8 D_800A5654[];
extern u8 D_800A565C[];
extern u8 *D_800A14E4[];
extern u8 gOrderState[];
extern u8 *gRecords;
extern u8 *gSlotTableB[];

/* Resolves the current path, then builds a 12-byte name from three fixed strings and the
 * index looked up from the record table, and passes the name and two more strings on. */
void func_80061F34(void *scene, void *base) {
    u8 temp[12];
    u8 *p;
    u32 index;
    resolve_path(aTexPackDir);
    stream_free_all_blocks();
    func_8004C7F0(gOrderState + 0x130C + gRecords[0x2E] * 28);
    p = gRecords;
    index = classifyStreamCode(gSlotTableB[*(u16 *)(p + 0x1E)] + *(u16 *)(p + 0x20) * 0x2C4 + (*(u16 *)(p + 0x22) * 14 + 0x24C));
    memset(temp, 0, 12);
    appendString(temp, D_800A564C);
    appendString(temp, D_800A14E4[index & 0xFF]);
    appendString(temp, D_800A5654);
    func_8004C7F0(temp);
    func_8004C7F0(D_800A565C);
}
