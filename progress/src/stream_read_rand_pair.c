int rand_scaled(int range);

/* Reads two bytes from src: the first scales a random value, which is stored at dst[0xB1]
 * and then offset by the second byte and stored again. Returns the position after both bytes. */
unsigned char *stream_read_rand_pair(char *dst, unsigned char *src) {
    int value = rand_scaled(*src++);
    dst[0xB1] = value;
    value += *src;
    dst[0xB1] = value;
    return src + 1;
}
