/* Reads three bytes from src into obj+0xD0, obj+0xC6 and obj+0xC7. Returns src advanced past them. */
unsigned char *func_80087F4C(char *obj, unsigned char *src) {
    obj[0xD0] = *src++;
    obj[0xC6] = *src++;
    obj[0xC7] = *src;
    return src + 1;
}
