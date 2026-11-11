extern u8 D_800C8246[];
extern u8 D_800C8262[];
extern void *gCarList;

s32 func_80041A04(s32, u16);

/* Queues phase 8 for the four cars listed in D_800C8246 (each entry indexes a
   40-byte record in D_800C8262), then clears the per-car phase flags for every
   car in gCarList and stores each car's list index. */
void resetCarPhases(void) {
    s32 index;
    void *car;

    func_80041A04(8, *(u16 *)(D_800C8262 + D_800C8246[0] * 40));
    func_80041A04(8, *(u16 *)(D_800C8262 + D_800C8246[1] * 40));
    func_80041A04(8, *(u16 *)(D_800C8262 + D_800C8246[2] * 40));
    func_80041A04(8, *(u16 *)(D_800C8262 + D_800C8246[3] * 40));
    car = *(void **)gCarList;
    index = 0;
    if (car != 0) {
        do {
            *(s32 *)((u8 *)*(void **)((u8 *)car + 0x28) + 0x50) = 1;
            *(s32 *)((u8 *)*(void **)((u8 *)car + 0x54) + 0x50) = 1;
            *(s32 *)((u8 *)*(void **)((u8 *)car + 0x1C) + 0x2C) = index & 0xFF;
            *(s32 *)((u8 *)*(void **)((u8 *)car + 0x48) + 0x2C) = index & 0xFF;
            car = *(void **)((u8 *)car + 4);
            index += 1;
        } while (car != 0);
    }
}
