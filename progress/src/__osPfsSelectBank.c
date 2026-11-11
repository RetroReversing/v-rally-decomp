int __osContRamWrite(int a, int b, int c, char *d, int e);

/* Selects bank `bank` of the controller pak: fills a 32-byte block with the bank number and
 * writes it to the pak at 0x400 (the bank-select page). On success, records the bank in
 * the pak state at +0x65. */
void __osPfsSelectBank(char *pfs, char bank) {
    char buf[32];
    int i;

    for (i = 31; i >= 0; i--) {
        buf[i] = bank;
    }
    if (__osContRamWrite(*(int *)(pfs + 4), *(int *)(pfs + 8), 0x400, buf, 0) == 0) {
        pfs[0x65] = bank;
    }
}
