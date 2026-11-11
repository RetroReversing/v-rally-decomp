extern char *D_800B0BCC;
extern char D_800A500C[];
int strncmp(char *a, char *b, int c);
void order_table_swap(int a, int b);

/* Walks count 20-byte records and moves each one whose first 3 bytes match
 * D_800A500C to the front of the order table, keeping the matches in order. */
void func_80052224(int count) {
    char pad[8];
    int matched = 0;
    int i = 0;
    int off;

    if (count > 0) {
        off = 0;
        do {
            if (strncmp(D_800B0BCC + off, D_800A500C, 3) == 0) {
                int t = matched & 0xFFFF;
                matched++;
                order_table_swap(i & 0xFFFF, t);
            }
            i++;
            off += 0x14;
        } while (i < count);
    }
}
