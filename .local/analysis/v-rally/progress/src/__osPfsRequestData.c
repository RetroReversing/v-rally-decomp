extern OSPifRam D_800C8130;
extern u8 D_800C3520;
extern u8 D_800B60E0;

void __osPfsRequestData(u8 cmd) {
    u8* ptr = (u8*)&D_800C8130;
    __OSContRequesFormat requestformat;
    int i;

    D_800C3520 = cmd;
    D_800C8130.pifstatus = 1 ;
    requestformat.dummy = 0xff ;
    requestformat.txsize = 1 ;
    requestformat.rxsize = 3 ;
    requestformat.cmd = cmd;
    requestformat.typeh = 0xff ;
    requestformat.typel = 0xff ;
    requestformat.status = 0xff ;
    requestformat.dummy1 = 0xff ;

    for (i = 0; i < D_800B60E0; i++) {
        *((__OSContRequesFormat*)ptr) = requestformat;
        ptr += sizeof(__OSContRequesFormat);
    }

    *ptr = 0xfe ;
}
