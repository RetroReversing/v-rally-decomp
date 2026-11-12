#ifdef PORT
#define ADDR_OF(x) ((uintptr_t)(x))
#else
#define ADDR_OF(x) (x)
#endif
u16 list_count(void *);
void func_80012F7C(void *);
s32 named_entry_set_value(void **, u8 *, s32);
void func_80042D20(s32, void *);
s32 order_find_by_key(void *);
void mirrorListClearBuffers(void *);
extern s32 gSelectStepConfirmed;
extern u8 D_800A4900[];
extern u8 gGameState[];
extern u8 gOrderState[];

/* Resets per-car race state for the car at arg0: on the first call it sets up the checkpoint
 * list, and if this car is the current one it renumbers the list. Then it clears the car's
 * status bits (0x20..0x200) and rebuilds its record at 0x70 from the car's spec at 0x44. */
void raceResetCar(void *car) {
    s32 temp_v0;
    s32 temp_v1;
    s32 i;
    s32 statusFlags;
    void *obj;
    void *node;

    if (*(u16 *)(gGameState + 0x6BFE) == 0) {
        *(u16 *)(gGameState + 0x6BFE) = list_count(*(void **)(gOrderState + 0x73F0));
        func_80012F7C(car);
    }
    temp_v1 = *(s32 *)(gOrderState + 0x73F0);
    if (*(void **)ADDR_OF(temp_v1 + 4) == car) {
        node = *(void **)ADDR_OF(temp_v1);
        i = 0;
        if (*(u16 *)(gGameState + 0x6BFE) != 0) {
            do {
                temp_v1 = i & 0xFFFF;
                *(s32 *)((u8 *)*(void **)((u8 *)node + 0x1C) + 0x2C) = temp_v1;
                i++;
                *(s32 *)((u8 *)*(void **)((u8 *)node + 0x48) + 0x2C) = temp_v1;
                node = *(void **)((u8 *)node + 4);
            } while ((u32)(i & 0xFFFF) < *(u16 *)(gGameState + 0x6BFE));
        }
        func_80042D20(i, node);
        mirrorListClearBuffers(car);
    }
    statusFlags = *(s32 *)((u8 *)car + 0x14);
    *(s32 *)(gGameState + 0x706C) = 0;
    gGameState[0x6BC8] = 0;
    gSelectStepConfirmed = 0;
    statusFlags &= ~0x20;
    statusFlags &= ~0x40;
    statusFlags &= ~0x80;
    statusFlags &= ~0x100;
    statusFlags &= ~0x200;
    *(s32 *)((u8 *)car + 0x14) = statusFlags;
    temp_v0 = order_find_by_key(car);
    if (temp_v0 != 0) {
        named_entry_set_value((void **)ADDR_OF(temp_v0 + 0x28), (u8 *)(D_800A4900), 0);
    }
    *(s32 *)(*(u8 **)((u8 *)car + 0x70) + 0x28) = *(s32 *)(*(u8 **)((u8 *)car + 0x44) + 0x28);
    *(s32 *)(*(u8 **)((u8 *)car + 0x70) + 4) = 1;
    *(s32 *)(*(u8 **)((u8 *)car + 0x70) + 0) = *(s32 *)(*(u8 **)((u8 *)car + 0x44) + 0);
    *(s32 *)(*(u8 **)((u8 *)car + 0x70) + 8) = 0;
    *(s32 *)(*(u8 **)((u8 *)car + 0x70) + 0xC) = 0;
    *(s32 *)(*(u8 **)((u8 *)car + 0x70) + 0x20) = 0;
    *(s32 *)(*(u8 **)((u8 *)car + 0x70) + 0x24) = 0;
    *(s32 *)(*(u8 **)((u8 *)car + 0x9C) + 0x34) = 0;
}
