/* Copies count bytes from src to dst, one byte at a time. */
void alCopy(unsigned char *src, unsigned char *dst, int count) { int i; for (i = 0; i < count; i++) { *dst++ = *src++; } }
