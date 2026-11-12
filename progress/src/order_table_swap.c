/* Swaps two u16 entries of the order table at gOrderState+0x1210; indices are truncated to 16 bits. */
extern char gOrderState[];

void order_table_swap(s32 arg0, s32 arg1) {
    u16 *temp_a0;
    u16 *temp_a1;
    u16 temp_v1;

#ifdef PORT
    temp_a0 = (u16 *)((u8 *)*(void **)(gOrderState + 0x1210) + (arg0 & 0xFFFF) * 2);
    temp_a1 = (u16 *)((u8 *)*(void **)(gOrderState + 0x1210) + (arg1 & 0xFFFF) * 2);
#else
    temp_a0 = ((arg0 & 0xFFFF) * 2) + *(s32 *)(gOrderState + 0x1210);
    temp_a1 = ((arg1 & 0xFFFF) * 2) + *(s32 *)(gOrderState + 0x1210);
#endif
    temp_v1 = *temp_a0;
    *temp_a0 = *temp_a1;
    *temp_a1 = temp_v1;
}
