s32 strCmp(const u8 *a, const u8 *b);
void carSaveToSlot(void *car, void *list, s32 slot);
extern char D_800A4774[];
extern char D_800A477C[];
extern char D_800A4784[];
extern char D_800A478C[];
extern char D_800A4794[];
extern char D_800A479C[];
extern char D_800A47A4[];
extern char gOrderState[];
extern char gStreamState[];

/* Picks the car's mode from its name field (car + 0x4C) by comparing it against the 7 known
 * names in order, then saves the car into the slot for that mode. Does nothing unless the
 * current state is below 3. */
void carSetModeByName(s32 car) {
    s32 nameField;

    if (*(u16 *)((u8 *)*(void **)(gStreamState + 0x32F2) + 0xE) < 3U) {
        nameField = car + 0x4C;
        if (strCmp(nameField, D_800A4774) == 0) {
            carSaveToSlot(car, **(s32 **)(gOrderState + 0x73F0), 1);
            return;
        }
        if (strCmp(nameField, D_800A477C) == 0) {
            carSaveToSlot(car, **(s32 **)(gOrderState + 0x73F0), 0);
            return;
        }
        if (strCmp(nameField, D_800A4784) == 0) {
            carSaveToSlot(car, **(s32 **)(gOrderState + 0x73F0), 2);
            return;
        }
        if (strCmp(nameField, D_800A478C) == 0) {
            carSaveToSlot(car, **(s32 **)(gOrderState + 0x73F0), 3);
            return;
        }
        if (strCmp(nameField, D_800A4794) == 0) {
            carSaveToSlot(car, **(s32 **)(gOrderState + 0x73F0), 4);
            return;
        }
        if (strCmp(nameField, D_800A479C) == 0) {
            carSaveToSlot(car, **(s32 **)(gOrderState + 0x73F0), 5);
            return;
        }
        if (strCmp(nameField, D_800A47A4) == 0) {
            carSaveToSlot(car, **(s32 **)(gOrderState + 0x73F0), 6);
        }
    }
}
