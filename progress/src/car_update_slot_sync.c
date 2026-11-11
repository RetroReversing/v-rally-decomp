typedef struct Blk40 { s32 w[10]; } Blk40;
typedef struct Slot { s32 a; s32 b; u16 flags; u16 state; u16 c; u16 d; s32 asz; s32 bsz; s32 x18; Blk40 blk; } Slot;
typedef struct Bank { Slot slots[4]; u16 count; } Bank;
typedef struct Sub { char pad0[0x6C]; s32 f6C; } Sub;
typedef struct Car { char pad0[4]; struct Car *next; char pad8[0x14 - 8]; s32 flags; char pad18[0x30 - 0x18]; Sub *p30; char pad34[0x48 - 0x34]; u8 *info; char pad4C[0x5C - 0x4C]; Sub *p5C; } Car;
typedef struct Cfg { char pad0[0xE]; u16 mode; char pad10[0x1A - 0x10]; u16 f1A; char pad1C[2]; u16 f1E; } Cfg;
typedef struct Pad { u16 btn; char pad2[4]; s16 v6; char pad8[0x44 - 8]; } Pad;

extern void func_8004F3C4(void);
extern void func_8008E13C(s32, s32, s32);
extern Bank *gCarEntries;
extern Bank *gSlotTable;
extern u8 D_800ADFE1;
extern Pad D_800B0C60[2];
#define D_800B1060 D_800B0C60
extern Car **gCarList;
extern Cfg *gRecords;

/* Syncs one car's slot from the source bank into the destination bank (copying
 * the slot buffers and flags) when the rules allow it, and resets the slot
 * state otherwise. Also clears the pad-input velocity words in the other modes. */
void car_update_slot_sync(Car *car) {
    u8 slot;
    Bank *dstBank;
    Bank *srcBank;
    Slot *dstSlot;
    Slot *srcSlot;
    s32 copyOk;
    u32 i;
    Car *cursor;

    func_8004F3C4();
    if (gRecords->f1E == 0) {
        slot = car->info[3];
        if (gRecords->f1A == 1) {
            dstBank = gSlotTable;
            srcBank = gCarEntries;
            dstSlot = &dstBank->slots[slot];
            srcSlot = &srcBank->slots[slot];
            if (dstSlot->flags & 0x10) {
                copyOk = dstSlot->state != 5;
            } else {
                copyOk = 1;
            }
            if ((dstSlot->flags & 0x80) && (srcSlot->flags & 0x80)) {
                dstSlot->flags &= ~0x80;
                copyOk = 0;
                srcSlot->flags &= ~0x100;
            }
            copyOk &= -!(srcSlot->flags & 2);
            if (copyOk && (srcSlot->d < dstSlot->d || dstSlot->d == 0)) {
                for (i = 0; i < srcBank->count; i++) {
                    dstSlot = &dstBank->slots[i];
                    dstSlot->flags = 0;
                    dstSlot->state = 0;
                    dstSlot->c = 0;
                    dstSlot->d = srcSlot->d;
                    func_8008E13C(dstSlot->a, srcSlot->a, (srcSlot->asz + 3) & ~3);
                    func_8008E13C(dstSlot->b, srcSlot->b, (srcSlot->bsz + 3) & ~3);
                    if (i != slot) {
                        cursor = *gCarList;
                        if (gRecords->mode == 2) {
                            if (i == 1) {
                                cursor = cursor->next;
                                cursor = cursor->next;
                            }
                            cursor = cursor->next;
                            cursor->p5C->f6C = 0;
                            cursor->p30->f6C = 0;
                        }
                        dstSlot->c = dstSlot->d;
                    }
                    dstSlot->blk = srcSlot->blk;
                    dstSlot->x18 = srcSlot->x18;
                    dstSlot->flags = (dstSlot->flags | 0x211) & ~0x400;
                }
                car->flags |= 0x4000;
            } else {
                dstSlot->flags = (dstSlot->flags | 0x201) & ~0x400;
                car->flags &= ~0x4000;
                dstSlot->c = 0;
            }
            if (D_800ADFE1 != 0) {
                dstSlot = &dstBank->slots[slot];
                dstSlot->state = 4;
                car->p5C->f6C = 1;
                car->p30->f6C = 1;
                srcSlot = &srcBank->slots[slot];
                srcSlot->state = 1;
                srcSlot->c = 0;
                srcSlot->d = 0;
                srcSlot->flags = (srcSlot->flags | 0x400) & ~0x200;
            } else {
                dstSlot = &dstBank->slots[slot];
                dstSlot->state = 3;
                car->p5C->f6C = 0;
                car->p30->f6C = 0;
                srcSlot = &srcBank->slots[slot];
                srcSlot->state = 3;
                srcSlot->c = 0;
                srcSlot->d = 0;
                srcSlot->flags |= 0x600;
            }
            return;
        }
        if ((D_800B1060[0].btn & 2) || (D_800B1060[1].btn & 2)) {
            D_800B1060[0].v6 = 0;
            D_800B1060[1].v6 = 0;
        }
    }
}
