extern char gOrderState[];

/* Like order_sync_slot, but writes the two 16-bit fields at offsets 0x98 and 0x9A of the slot record. */
void order_sync_slot_ext(void *obj)
{
    if (*(void **) (gOrderState + 0x8A28) != NULL) {
        ((s16 *) *(void **) (gOrderState + 0x8A28))[0x98 / 2] = (s16) *(s32 *) ((s8 *) obj + 0x90);
        ((s16 *) *(void **) (gOrderState + 0x8A28))[0x9A / 2] = (s16) *(s32 *) ((s8 *) obj + 0xDC);
    }
}
