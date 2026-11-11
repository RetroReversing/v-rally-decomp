extern unsigned int D_800A58C8[];

/* Standard CRC-32 (reflected polynomial, table-driven) over len bytes of data,
 * starting from 0xFFFFFFFF. The caller inverts the result if needed. */
unsigned int crc32_compute(unsigned char *data, int len)
{
    unsigned int crc = 0xFFFFFFFF;

    while (len--) {
        crc = D_800A58C8[(*data++ ^ crc) & 0xFF] ^ (crc >> 8);
    }
    return crc;
}
