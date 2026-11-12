extern char *gControllerInputContext;

/* Counts the four controller ports whose status byte (stride 4, at +0xF) has bit 3 clear. */
unsigned char func_80084E10(void)
{
    u8 connected;
    s32 port;

    connected = 0;
    port = 0;
    do {
        if ((gControllerInputContext[port * 4 + 0xF] & 8) == 0) {
            connected++;
        }
        port++;
    } while (port < 4);
    return connected;
}
