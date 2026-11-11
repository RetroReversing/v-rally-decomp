typedef struct SortEntry { s16 data[16]; u16 key; } SortEntry;
extern SortEntry *D_800B55F0;
extern u16 *D_800AFA60;
extern SortEntry D_800C5E08;

/* Hoare partition step for the quicksort of D_800B55F0: the pivot is the sort
 * key of the entry at lo, keys are looked up through D_800AFA60. Swaps entries
 * until the scans cross and returns the split index. */
s32 sortPartitionEntries(s32 lo, s32 hi) {
s32 left;
s32 right;
s32 pivot;
left=lo-1;
right=hi+1;
pivot=D_800AFA60[D_800B55F0[lo].key];
for(;;) {
do { right--; } while(pivot<D_800AFA60[D_800B55F0[right].key]);
do { left++; } while(D_800AFA60[D_800B55F0[left].key]<pivot);
if(left>=right) break;
D_800C5E08=D_800B55F0[left];
D_800B55F0[left]=D_800B55F0[right];
D_800B55F0[right]=D_800C5E08;
}
return right;
}
