typedef struct Item22 {
    u32 count0;
    u32 count1;
    u32 flags;
    s32 pad0C;
    void (*update)(void *);
    s32 pad14[2];
} Item22;

typedef struct Obj22 {
    u8 pad0[0x1C];
    s32 *primary[11];
    s32 *mirror[11];
    s32 *aux[11];
    u8 padA0[0xD0 - 0xA0];
    Item22 *items;
} Obj22;

typedef struct Game22 {
    u8 pad0[0x1E];
    u16 f1E;
} Game22;

extern s32 gMirrorListHead;
extern Game22 *gRecords;

/* Copies the per-slot data block into the object's tables. For each of the
 * 11 slots: flag 1 copies count0 values into primary/mirror (value 0x54 of
 * slot 6 is stored as gMirrorListHead minus the source), flag 2 copies count1
 * values into aux, and flag 4 runs the slot's update callback. */
void func_80022BE8(Obj22 *obj, s32 *data)
{
    u32 slot;
    u32 j;

    for (slot = 0; slot < 11; slot++) {
        if (obj->items[slot].flags & 1) {
            for (j = 0; j < obj->items[slot].count0; j++) {
                if (gRecords->f1E != 0 || slot != 10 || *obj->mirror[0] >= 4) {
                    if (slot == 6 && j == 0x54) {
                        obj->mirror[slot][j] = gMirrorListHead - data[j];
                        obj->primary[slot][j] = gMirrorListHead - data[j];
                    } else {
                        obj->mirror[slot][j] = data[j];
                        obj->primary[slot][j] = data[j];
                    }
                }
            }
            data += obj->items[slot].count0;
        }
        if (obj->items[slot].flags & 2) {
            for (j = 0; j < obj->items[slot].count1; j++) {
                obj->aux[slot][j] = data[j];
            }
            data += obj->items[slot].count1;
        }
        if (obj->items[slot].flags & 4) {
            obj->items[slot].update(obj);
        }
    }
}
