extern s32 gOrderState;

/* Copies the 3x3 matrix of u16 entries at src (9 entries, 2 bytes each) into
 * the current matrix in gOrderState at +0x7928. */
void mat3_set_current(void *src)
{
    *(u16 *) ((s8 *) &gOrderState + 0x7928) = (u16) *(u16 *) ((s8 *) src + 0);
    *(u16 *) ((s8 *) &gOrderState + 0x792A) = (u16) *(u16 *) ((s8 *) src + 2);
    *(u16 *) ((s8 *) &gOrderState + 0x792C) = (u16) *(u16 *) ((s8 *) src + 4);
    *(u16 *) ((s8 *) &gOrderState + 0x792E) = (u16) *(u16 *) ((s8 *) src + 6);
    *(u16 *) ((s8 *) &gOrderState + 0x7930) = (u16) *(u16 *) ((s8 *) src + 8);
    *(u16 *) ((s8 *) &gOrderState + 0x7932) = (u16) *(u16 *) ((s8 *) src + 0xA);
    *(u16 *) ((s8 *) &gOrderState + 0x7934) = (u16) *(u16 *) ((s8 *) src + 0xC);
    *(u16 *) ((s8 *) &gOrderState + 0x7936) = (u16) *(u16 *) ((s8 *) src + 0xE);
    *(u16 *) ((s8 *) &gOrderState + 0x7938) = (u16) *(u16 *) ((s8 *) src + 0x10);
}
