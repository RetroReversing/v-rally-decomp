extern char *D_800B0BCC;
extern char D_800A5020[];
int strncmp(char *a, char *b, int c);
void order_table_swap(int a, int b);

/* Walks the first `count` 20-byte records of the table at D_800B0BCC. Each record whose 4-byte
 * name at +2 matches D_800A5020 is reported to order_table_swap with its index and its running
 * match number. */
void func_8005235C(int count) {
    char pad[8];
    int matches = 0;
    int idx = 0;
    int off;

    if (count > 0) {
        off = 0;
        do {
            if (strncmp(D_800B0BCC + off + 2, D_800A5020, 4) == 0) {
                int matchNo = matches & 0xFFFF;
                matches++;
                order_table_swap(idx & 0xFFFF, matchNo);
            }
            idx++;
            off += 0x14;
        } while (idx < count);
    }
}
