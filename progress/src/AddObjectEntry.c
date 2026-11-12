typedef s32 M2C_UNK;
M2C_UNK *poolAlloc(M2C_UNK, M2C_UNK);
M2C_UNK strCpy(M2C_UNK *, void *);
extern void *gSelectState;
extern f64 D_800A5240;

/* Allocates a 0x50-byte entry, copies the object's per-car fields into it
 * (defaulting the colour and scale when the object's count is low), and appends
 * it to the list at gSelectState. */
void AddObjectEntry(void *obj) {
    void *entry;
    void *fields;
    void *tail;
    s32 idx;
    s32 cur;
    s32 flag;
    u8 *slot;
    void *list;

    entry = poolAlloc(1, 0x50);
    *(s16 *)((s8 *)entry + 0x4A) = (s16)*(s32 *)((s8 *)obj + 0x90);
    *(s16 *)((s8 *)entry + 8) = (s16)*(s32 *)((s8 *)obj + 0xDC);
    *(s16 *)((s8 *)entry + 0xA) = (s16)*(s32 *)((s8 *)obj + 0x128);
    *(s16 *)((s8 *)entry + 0xC) = (s16)*(s32 *)((s8 *)obj + 0x174);
    fields = (void *)((u8 *)entry + 4);
    *(u8 *)((s8 *)entry + 0xE) = (s8)*(s32 *)((s8 *)obj + 0x1C0);
    if (*(u8 *)((s8 *)obj + 0x210) != 0) {
        *(u8 *)((s8 *)entry + 0x30) = 0;
    } else {
        strCpy((void *)((u8 *)entry + 0x30), (void *)((s8 *)obj + 0x1C8));
    }
    idx = 0;
    do {
        cur = idx & 0xFF;
        idx += 1;
        flag = *(s32 *)((s8 *)obj + 0x2A4);
        slot = (u8 *)entry + cur * 2;
        *(u8 *)((s8 *)slot + 0x42) = 0;
        *(u8 *)((s8 *)slot + 0x41) = (s8)(flag == 1);
    } while ((u32)(idx & 0xFF) < 4U);
    if (*(s32 *)((s8 *)obj + 0x44) >= 9) {
        *(u8 *)((s8 *)fields + 0xB) = (s8)*(s32 *)((s8 *)obj + 0x2F0);
        *(u8 *)((s8 *)fields + 0xC) = (s8)*(s32 *)((s8 *)obj + 0x33C);
        *(u8 *)((s8 *)fields + 0xD) = (s8)*(s32 *)((s8 *)obj + 0x388);
        if (*(s32 *)((s8 *)obj + 0x44) >= 12) {
            *(u8 *)((s8 *)fields + 0xE) = (s8)*(s32 *)((s8 *)obj + 0x3D4);
            if (*(s32 *)((s8 *)obj + 0x44) >= 13) {
                *(f32 *)((s8 *)fields + 0x10) = (f32)((f64)*(s32 *)((s8 *)obj + 0x46C) * D_800A5240);
                *(f32 *)((s8 *)fields + 0x14) = (f32)((f64)*(s32 *)((s8 *)obj + 0x4B8) * D_800A5240);
            } else {
                *(f32 *)((s8 *)fields + 0x10) = 1.0f;
                *(f32 *)((s8 *)fields + 0x14) = 1.0f;
            }
        } else {
            *(u8 *)((s8 *)fields + 0xE) = 0xff;
            *(f32 *)((s8 *)fields + 0x10) = 1.0f;
            *(f32 *)((s8 *)fields + 0x14) = 1.0f;
        }
    } else {
        *(u8 *)((s8 *)fields + 0xB) = 200;
        *(u8 *)((s8 *)fields + 0xC) = 200;
        *(u8 *)((s8 *)fields + 0xD) = 200;
        *(u8 *)((s8 *)fields + 0xE) = 0xff;
        *(f32 *)((s8 *)fields + 0x10) = 1.0f;
        *(f32 *)((s8 *)fields + 0x14) = 1.0f;
    }
    *(u8 *)((s8 *)fields + 0xE) = 0xcc;
    list = gSelectState;
    *(s16 *)((s8 *)fields + 0x18) = 0;
    tail = *(void **)((s8 *)list + 0x10);
    if (tail != NULL) {
        *(void **)tail = entry;
    } else {
        *(void **)((s8 *)list + 0xC) = entry;
    }
    *(void **)((s8 *)gSelectState + 0x10) = entry;
    *(void **)((s8 *)gSelectState + 0x1F0) = entry;
    *(s32 *)((s8 *)gSelectState + 0x14) += 1;
    *(u8 *)((s8 *)entry + 0x4C) = 0;
    *(u8 *)((s8 *)entry + 0x4D) = 0;
    *(u8 *)((s8 *)entry + 0x4E) = 0;
    *(void **)((s8 *)entry + 0x28) = NULL;
    *(void **)((s8 *)entry + 0x2C) = NULL;
}
