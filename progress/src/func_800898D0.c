extern s32 D_800B0100;
extern s32 *D_800B6160;
extern void voice_reset(void);

/* Starts a voice: resets the voice hardware, stamps it with the next serial number, sets its
   volume to full, stores the program index and parameters, and loads the table entry for
   the program into the voice's first two words. Returns the serial number. */
s32 func_800898D0(u8 *voice, s32 program, s16 param1, s16 param2, s32 param3) {
    s32 serial;
    s32 value;
    s32 *table;

    voice_reset();
    serial = D_800B0100;
    D_800B0100 = serial + 1;
    voice[0xB3] = 0x7F;
    table = D_800B6160;
    *(s16 *)(voice + 0x9E) = program;
    program <<= 2;
    *(s16 *)(voice + 0x96) = param1;
    *(s16 *)(voice + 0xA8) = param2;
    *(s32 *)(voice + 0x40) = serial;
    *(s32 *)(voice + 0x44) = param3;
#ifdef PORT
    value = *(s32 *)((u8 *)table + program);
#else
    value = *(s32 *)(program + (s32)table);
#endif
    *(s32 *)(voice + 0x78) = value;
    *(s32 *)voice = value;
    return *(s32 *)(voice + 0x40);
}
