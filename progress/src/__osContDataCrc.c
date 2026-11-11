/* CRC-8 over the 32 data bytes of a controller pak block (polynomial 0x85), followed
 * by the 8 trailing bits; returns the checksum byte. */
u8 __osContDataCrc(u8 *data)
{
    u32 crc = 0;
    u32 i;
    u32 bit;

    for (i = 0x20; i; --i) {
        for (bit = 0x80; bit; bit >>= 1) {
            crc <<= 1;

            if ((*data & bit) != 0) {
                if ((crc & 0x100) != 0) {
                    crc ^= 0x84;
                } else {
                    ++crc;
                }
            } else if (crc & 0x100) {
                crc ^= 0x85;
            }
        }

        data++;
    }
    do {
        crc <<= 1;

        if (crc & 0x100) {
            crc ^= 0x85;
        }
    } while (++i < 8U);

    return crc;
}
