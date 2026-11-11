s32 sortPartitionEntries(s32 lo, s32 hi);

/* Recursive quicksort over the entry index range [lo, hi] of D_800B55F0. */
void func_80056F8C(s32 lo, s32 hi) {
    s32 split;

    if (lo < hi) {
        split = sortPartitionEntries(lo, hi);
        func_80056F8C(lo, split);
        func_80056F8C(split + 1, hi);
    }
}
