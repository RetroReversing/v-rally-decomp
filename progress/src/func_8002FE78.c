extern char gOrderState[];

s32 func_80084DD4(s32);
s32 cont_port_is_connected(s32, s32);
s32 func_800858A4(s32, s32, s32);

/* For each of the four controller ports, clears its 16-byte slot at gOrderState+0x2394.
 * If the port passes func_80084DD4, and cont_port_is_connected reports state 1 for it, the port's
 * flag is set through func_800858A4(port, 2, 1). */
void func_8002FE78(void) {
    u8 port;
    u32 n;

    port = 0;
    do {
        n = port;
        *(s32 *)(gOrderState + 0x2394 + (n << 4)) = 0;
        if (func_80084DD4(n) != 0) {
            if (cont_port_is_connected(n, 2) != 0) {
                func_800858A4(n, 2, 1);
            }
        }
        port++;
    } while (port < 4);
}
