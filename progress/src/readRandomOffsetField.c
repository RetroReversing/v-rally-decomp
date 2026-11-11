int randomScaled(int a);

/* Reads two bytes from the stream at `cur`. The first goes through randomScaled() and the
 * second is added to it; the sum is stored at +0xB4 of `obj`. Returns the stream past both bytes. */
void *readRandomOffsetField(char *obj, unsigned char *cur) {
    int v = randomScaled(*cur++);
    obj[0xB4] = v;
    v += *cur;
    obj[0xB4] = v;
    return cur + 1;
}
