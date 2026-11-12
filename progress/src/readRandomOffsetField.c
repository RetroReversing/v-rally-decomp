int rand_scaled(int a);

/* Reads two bytes from the stream at `cur`. The first goes through rand_scaled() and the
 * second is added to it; the sum is stored at +0xB4 of `obj`. Returns the stream past both bytes. */
void *readRandomOffsetField(char *obj, unsigned char *cur) {
    int v = rand_scaled(*cur++);
    obj[0xB4] = v;
    v += *cur;
    obj[0xB4] = v;
    return cur + 1;
}
