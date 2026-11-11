extern char gOrderState[];
extern char gStreamState[];

/* Per-frame bookkeeping between the stream and order state: moves the stream's
   positive 0x3092 count into the order's running total; a pending value at 0x3116
   is then loaded into the stream's count and its 0x308E field is updated from the
   0x311A value. A negative count is clamped to zero. */
void func_80081D8C(void)
{
    s32 pending;

    if (*(s32 *)(gStreamState + 0x3092) > 0) {
        *(s32 *)(gOrderState + 0x8ACC) = (s32) (*(s32 *)(gOrderState + 0x8ACC) + *(s32 *)(gStreamState + 0x3092));
    }
    pending = *(s32 *)(gStreamState + 0x3116);
    if (pending > 0) {
        *(s32 *)(gStreamState + 0x3116) = 0;
        *(s32 *)(gStreamState + 0x3092) = (s32) (pending + *(s32 *)(gOrderState + 0x8ACC));
        *(s32 *)(gStreamState + 0x308E) = (s32) (*(s32 *)(gStreamState + 0x311A) - *(s32 *)(gOrderState + 0x8ACC));
        return;
    }
    if (*(s32 *)(gStreamState + 0x3092) < 0) {
        *(s32 *)(gStreamState + 0x3092) = 0;
    }
}
