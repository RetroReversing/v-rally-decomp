extern u8 D_800B60E0;
extern char D_800C02AE[];

typedef struct { u8 b[8]; } Pkt;

void __osPfsRequestData(s8 arg0) {
    Pkt sp;
    register s32 var_a2;
    Pkt *var_a3;

    sp.b[0] = 0;
    var_a2 = 0;
    var_a3 = (Pkt *)(D_800C02AE + 0x7E82 + sp.b[0] - sp.b[0]);
    *(s32 *)(D_800C02AE + 0x7EBE) = 1;
    *(D_800C02AE + 0x3272) = arg0;
    sp.b[0] = 0xFF;
    sp.b[1] = 1;
    sp.b[2] = 3;
    sp.b[3] = arg0;
    sp.b[4] = 0xFF;
    sp.b[5] = 0xFF;
    sp.b[6] = 0xFF;
    sp.b[7] = 0xFF;
    while (var_a2 < D_800B60E0) {
        *var_a3 = sp;
        var_a2++;
        var_a3++;
    }
    *(u8 *)var_a3 = 0xFE;
}
