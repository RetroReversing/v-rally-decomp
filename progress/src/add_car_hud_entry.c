#define FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 *poolAlloc(s32, s32);
extern void *gSelectState;
extern f64 D_800A5238;

/* Adds a HUD entry for one car: fills a 0x24-byte entry from the car's data (position,
 * colour and kind; the 'S' and 'R' kinds get a scale), then links it into the active list
 * in gSelectState (the sub-list at +0x1F0 when present, otherwise the main list). */
void add_car_hud_entry(void *car) {
    void *next;
    void *entry;
    void *head;
    s32 i;
    s32 flag;
    s8 kind;
    u8 alpha;
    void *cur;
    void *sub;
    void *slot;
    void *list;

    entry = poolAlloc(1, 0x24);
    FIELD(entry, s16 *, 4) = (s16) FIELD(car, s32 *, 0x90);
    FIELD(entry, s16 *, 6) = (s16) FIELD(car, s32 *, 0xDC);
    FIELD(entry, s16 *, 8) = (s16) FIELD(car, s32 *, 0x128);
    i = 0;
    FIELD(entry, s8 *, 0xA) = (s8) FIELD(car, s32 *, 0x174);
    do {
        flag = i & 0xFF;
        i += 1;
        slot = (u8 *)entry + (flag * 2);
        flag = FIELD(car, s32 *, 0x1C0) == 1;
        FIELD(slot, s8 *, 0x1B) = 0;
        FIELD(slot, s8 *, 0x1A) = flag;
    } while ((u32)(i & 0xFF) < 4U);
    if (FIELD(car, s32 *, 0x44) >= 6) {
        FIELD(entry, u8 *, 0xB) = (u8) FIELD(car, s32 *, 0x20C);
        FIELD(entry, u8 *, 0xC) = (u8) FIELD(car, s32 *, 0x258);
        FIELD(entry, u8 *, 0xD) = (u8) FIELD(car, s32 *, 0x2A4);
        if (FIELD(car, s32 *, 0x44) >= 9) {
            FIELD(entry, u8 *, 0xE) = (u8) FIELD(car, s32 *, 0x2F0);
            if (FIELD(car, s32 *, 0x44) >= 0xA) {
                kind = FIELD(car, s8 *, 0x2F8);
                if (kind == 0x53) {
                    FIELD(entry, f32 *, 0x10) = (f32) ((f64) FIELD(car, s32 *, 0x388) * D_800A5238);
                    FIELD(entry, f32 *, 0x14) = (f32) ((f64) FIELD(car, s32 *, 0x3D4) * D_800A5238);
                    if (FIELD(car, s32 *, 0x44) == 0xD) {
                        FIELD(entry, s16 *, 0x18) = (s16) FIELD(car, s32 *, 0x420);
                        goto finished;
                    } else {
                        FIELD(entry, s16 *, 0x18) = 0;
                        goto finished;
                    }
                } else if (kind == 0x52) {
                    FIELD(entry, s16 *, 0x18) = (s16) FIELD(car, s32 *, 0x388);
                    FIELD(entry, f32 *, 0x10) = 1.0f;
                    FIELD(entry, f32 *, 0x14) = 1.0f;
                }
            } else {
                goto block_17;
            }
        } else {
            FIELD(entry, s16 *, 0x18) = 0;
            FIELD(entry, u8 *, 0xE) = 0xFFU;
            FIELD(entry, f32 *, 0x10) = 1.0f;
            FIELD(entry, f32 *, 0x14) = 1.0f;
        }
    } else {
        cur = FIELD(gSelectState, void **, 0x1F0);
        if (cur == NULL) {
            FIELD(entry, u8 *, 0xB) = 0xC8U;
            FIELD(entry, u8 *, 0xC) = 0xC8U;
            FIELD(entry, u8 *, 0xD) = 0xC8U;
            FIELD(entry, u8 *, 0xE) = 0xFF;
            goto block_17;
        } else {
            FIELD(entry, u8 *, 0xB) = (u8) FIELD(cur, u8 *, 0xF);
            FIELD(entry, u8 *, 0xC) = (u8) FIELD(FIELD(gSelectState, void **, 0x1F0), u8 *, 0x10);
            FIELD(entry, u8 *, 0xD) = (u8) FIELD(FIELD(gSelectState, void **, 0x1F0), u8 *, 0x11);
            alpha = FIELD(FIELD(gSelectState, void **, 0x1F0), u8 *, 0x12);
        }
        FIELD(entry, u8 *, 0xE) = alpha;
block_17:
        FIELD(entry, s16 *, 0x18) = 0;
block_18:
        FIELD(entry, f32 *, 0x10) = 1.0f;
        FIELD(entry, f32 *, 0x14) = 1.0f;
    }
finished:
    sub = FIELD(gSelectState, void **, 0x1F0);
    if (sub != NULL) {
        next = FIELD(sub, void **, 0x2C);
        if (next != NULL) {
            *(void **)next = entry;
        } else {
            FIELD(sub, void **, 0x28) = entry;
        }
        FIELD(FIELD(gSelectState, void **, 0x1F0), void **, 0x2C) = entry;
        list = FIELD(gSelectState, void **, 0x1F0);
        FIELD(list, u8 *, 0x4C) = (u8) (FIELD(list, u8 *, 0x4C) + 1);
        return;
    }
    head = FIELD(gSelectState, void **, 4);
    if (head != NULL) {
        *(void **)head = entry;
    } else {
        FIELD(gSelectState, void **, 0) = entry;
    }
    FIELD(gSelectState, void **, 4) = entry;
    FIELD(gSelectState, s32 *, 8) = (s32) (FIELD(gSelectState, s32 *, 8) + 1);
}
