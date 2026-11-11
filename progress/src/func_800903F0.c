extern s8 gOrderState[];
extern s8 gStreamState[];

/* Copies the cart bus timing registers (PI domain 1 and 2 latch, pulse width,
 * page size and release) into the stream state, and clears the flag at 0x758B. */
void func_800903F0(void) {
    s32 dom1Lat;
    s32 dom1Pwd;
    s32 dom1Pgs;
    s32 dom1Rls;
    s32 dom2Lat;
    s32 dom2Pwd;
    s32 dom2Pgs;
    s32 dom2Rls;

    dom1Lat = *(volatile s32 *)0xA4600014;
    dom1Pwd = *(volatile s32 *)0xA4600018;
    dom1Pgs = *(volatile s32 *)0xA460001C;
    dom1Rls = *(volatile s32 *)0xA4600020;
    dom2Lat = *(volatile s32 *)0xA4600024;
    dom2Pwd = *(volatile s32 *)0xA4600028;
    dom2Pgs = *(volatile s32 *)0xA460002C;
    dom2Rls = *(volatile s32 *)0xA4600030;
    gStreamState[0x758B] = 0;
    gOrderState[0x78A1] = 1;
    gStreamState[0x7587] = dom1Lat;
    gStreamState[0x758A] = dom1Pwd;
    gStreamState[0x7588] = dom1Pgs;
    gStreamState[0x7589] = dom1Rls;
    gOrderState[0x789D] = dom2Lat;
    gOrderState[0x78A0] = dom2Pwd;
    gOrderState[0x789E] = dom2Pgs;
    gOrderState[0x789F] = dom2Rls;
}
