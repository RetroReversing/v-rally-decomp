extern char gOrderState[];

/* Sort comparator: returns nonzero when the score of entry *idxB is below the score of entry *idxA.
 * Scores are 4-byte words in the table at gOrderState + 0x18B8, indexed by entry number. */
int compareScores(unsigned char *idxA, unsigned char *idxB)
{
    char *table;
    char *entryA;
    int scoreA;
    int stride;

    table = gOrderState + 0x18B8;
    stride = 4;
    entryA = table + (*idxA) * 4;
    return (*((unsigned int *)(table + (*idxB) * stride))) < (scoreA = *((unsigned int *)entryA));
}
