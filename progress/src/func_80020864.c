s32 MapTypeCode();

/* Updates the state record of an object: a kind of 7 is stored as-is, other kinds below 4
 * (or any kind when the object's flags lack bits 0x300) store the converted value from
 * MapTypeCode; the record's trailing flag byte is then cleared. */
void func_80020864(void *obj)
{
    s32 kind;
    void *state;
    void *cur;
    void *flags;

    do {
        cur = obj;
        state = *((void **)((char *)cur + 0x48));
        kind = *((s32 *)((char *)state + 0));
    } while (0);
    flags = state + 4;
    if (kind == 7) {
        *((s32 *)((char *)state + 0x20)) = kind;
    } else if ((kind >= 4) || (!((*((s32 *)((char *)cur + 0x14))) & 0x300))) {
        *((s32 *)((char *)(*((void **)((char *)cur + 0x48))) + 0x20)) = (s32)(MapTypeCode(kind & 0xFFFF) & 0xFFFF);
    }
    *((s8 *)((char *)flags + 7)) = 0;
}
