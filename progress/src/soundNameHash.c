/* Hashes a NUL-terminated sound name (hash = hash * 13 + c, low 16 bits) and returns it plus bias, folded to 11 bits. */ s32 soundNameHash(u8 *name, s32 bias)
{
    u8 *p;
    u8 c;
    u32 hash;

    hash = *name;
    p = name + 1;
    goto test;
    do {
        hash = c + ((hash & 0xFFFF) * 0xD);
        p++;
test:
        c = *p;
    } while (c != 0);
    return (hash + bias) & 0x7FF;
}
