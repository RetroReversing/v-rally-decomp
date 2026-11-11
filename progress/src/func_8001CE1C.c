extern short D_800ADFB4;
extern short D_800ADFBA;
extern short D_800ADFBE;
extern short gCurSnap2;
extern short D_800ADFC2;
extern short D_800ADFC4;
extern short gCurSnap0;

/* Copies the four snapshot words of the object at arg0 (offsets 0x90, 0xDC, 0x128, 0x174) into the current-snapshot globals, and resets the flag and the two trailing words. */
void func_8001CE1C(void *arg0) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = *(s32 *)((char *)arg0 + 0x90);
    gCurSnap0 = (s16) var_v0;
    var_v0 = *(s32 *)((char *)arg0 + 0xDC);
    D_800ADFBA = (s16) var_v0;
    var_v1 = *(s32 *)((char *)arg0 + 0x128);
    var_v0 = 0xFF;
    D_800ADFBE = 0xFF;
    gCurSnap2 = (s16) var_v1;
    var_v0 = *(s32 *)((char *)arg0 + 0x174);
    D_800ADFC2 = 0;
    D_800ADFC4 = 0;
    D_800ADFB4 = (s16) var_v0;
}
