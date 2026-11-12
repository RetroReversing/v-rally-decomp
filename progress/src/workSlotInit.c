/* Clears a work slot's state and flags, then stores its poll and done callbacks. */
void workSlotInit(u8 *slot, void *poll, void *done)
{
    *(u16 *)(slot + 0) = 0;
    *(u8 *)(slot + 2) = 0;
    *(void **)(slot + 4) = poll;
    *(void **)(slot + 8) = done;
}
