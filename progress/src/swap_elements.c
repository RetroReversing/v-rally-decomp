/* Swaps two records of size bytes, one byte at a time. */
void swap_elements(u32 size, u8 *a, u8 *b)
{
    u32 i;
    u8 tmp;

    i = size;
    while (i != 0) {
        tmp = *a;
        i -= 1;
        *a = *b;
        a += 1;
        *b = tmp;
        b += 1;
    }
}
