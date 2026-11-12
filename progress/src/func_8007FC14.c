extern volatile int gHeapBusy;

/* Spins until the heap is no longer marked busy. */
void func_8007FC14(void)
{
    int busy;
    s32 *flag;

    flag = &gHeapBusy;
    if ((*flag) == 1)
    {
        do
        {
        }
        while (gHeapBusy == 1);
    }
}
