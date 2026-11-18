extern char gOrderState[];
void sort_range(s32 lo, s32 hi);

/* Stores the new order state pointer at gOrderState+0x87D0, then sorts the first count entries if there are any. */
void order_set_and_sort(s32 state, s32 count)
{
    if (count != 0) {
        *(s32 *) (gOrderState + 0x87D0) = state;
        sort_range(0, count - 1);
    }
}
