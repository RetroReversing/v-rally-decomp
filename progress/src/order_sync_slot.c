extern char gOrderState[];

/* Copies two 16-bit fields from obj (offsets 0x90 and 0xDC) into the slot record that gOrderState+0x8A28 points to, if it exists. */
void order_sync_slot(void *obj)
{
    if (*(void **) (gOrderState + 0x8A28) != NULL) {
        ((s16 *) *(void **) (gOrderState + 0x8A28))[6] = (s16) *(s32 *) ((s8 *) obj + 0x90);
        ((s16 *) *(void **) (gOrderState + 0x8A28))[7] = (s16) *(s32 *) ((s8 *) obj + 0xDC);
    }
}
