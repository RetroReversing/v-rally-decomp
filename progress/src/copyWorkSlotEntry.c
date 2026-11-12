/* Copies one 0x14-byte work slot record from src into the slot table at dst. The record
 * index (u16 at +0) selects the destination slot, whose table base is at dst+0x10. */
void copyWorkSlotEntry(void *src, void *dst)
{
    u16 index;
    s8 *slots;

    index = *(u16 *)((s8 *)src + 0);
    *(u16 *)((s8 *)dst + 2) = index;
    slots = *(s8 **)((s8 *)dst + 0x10);
    *(u8 *)(slots + ((s16)index * 0x14) + 0xE) = (u8)*(u8 *)((s8 *)src + 2);
    *(s32 *)((s8 *)dst + 8) = (s32)*(s32 *)((s8 *)src + 4);
    *(s32 *)((s8 *)dst + 0xC) = (s32)*(s32 *)((s8 *)src + 8);
}
