s32 cont_port_is_connected(s32, s32);
extern char gOrderState[];

/* Clears the four order slots at gOrderState+0x2394 (16 bytes each): the
 * first word, and the flag byte at +8 and +9. The +8 byte is set from whether
 * controller port i is connected. */
void func_8002FB64(void)
{
    u8 slot;
    u32 n;

    n = 0;
    for (slot = 0; slot < 4; n = ++slot) {
        *((s32 *) (gOrderState + 0x2394 + (slot << 4))) = 0;
        *((s8 *) (gOrderState + 0x239C + (slot << 4))) = cont_port_is_connected(slot, 2);
        *((s8 *) (gOrderState + 0x239D + (slot << 4))) = 0;
    }
}
