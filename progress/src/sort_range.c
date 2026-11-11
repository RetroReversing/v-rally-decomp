s32 sort_partition();
void sort_range(s32 lo, s32 hi);

/* Recursive quicksort of the records in the sort table over indices lo..hi
 * (inclusive): sort_partition splits the range at a pivot, then both halves
 * are sorted. */
void sort_range(s32 lo, s32 hi)
{
    s32 split;

    if (lo < hi) {
        split = sort_partition();
        sort_range(lo, split);
        sort_range(split + 1, hi);
    }
}
