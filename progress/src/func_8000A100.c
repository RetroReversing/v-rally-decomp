extern char stream_state[];
extern void func_80009FC8(s32 block);

/* Frees the two saved stream blocks and copies the 0x32E6 word into the 0x7DA6 slot. */
void func_8000A100(void) {
    func_80009FC8(*(s32 *)(stream_state + 0x32FA));
    func_80009FC8(*(s32 *)(stream_state + 0x32FE));
    *(s32 *)(stream_state + 0x7DA6) = *(s32 *)(stream_state + 0x32E6);
}
