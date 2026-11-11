/* Looks at the type byte at obj+3. Type 6 selects the block at obj+0xC with count 3,
 * type 0xA selects the block at obj+0x10 with count 4. Other types return without output. */
void objGetTypedBlock(void *obj, void **block, s16 *count)
{
    s16 n;
    u8 type;

    type = *(u8 *)((char *)obj + 3);
    if (type == 6) {
        goto type6;
    }
    if (type == 0xA) {
        goto typeA;
    }
    return;
type6:
    *block = (char *)obj + 0xC;
    n = 3;
    goto store;
typeA:
    *block = (char *)obj + 0x10;
    n = 4;
store:
    *count = n;
    return;
}
