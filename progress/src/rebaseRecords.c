void rebaseRecord(char *rec);

/* Calls rebaseRecord on each of the count records in the table at rec[0]. Each record is 0x18 bytes. */
void rebaseRecords(char *rec)
{
    char *p = *(char **)rec;
    int i;

    for (i = 0; i < *(unsigned short *)(rec + 4); i++) {
        rebaseRecord(p);
        p += 0x18;
    }
}
