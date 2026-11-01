/* Same-name source lead: __osPfsRequestData in marioparty; donor defaults. Destination verification required. */
void __osPfsRequestData(u8 cmd) {
    u8* ptr = (u8*)&__osPfsPifRam;
    __OSContRequesFormat requestformat;
    int i;

    __osContLastCmd = cmd;
    __osPfsPifRam.pifstatus = 1 ;
    requestformat.dummy = 0xff ;
    requestformat.txsize = 1 ;
    requestformat.rxsize = 3 ;
    requestformat.cmd = cmd;
    requestformat.typeh = 0xff ;
    requestformat.typel = 0xff ;
    requestformat.status = 0xff ;
    requestformat.dummy1 = 0xff ;

    for (i = 0; i < __osMaxControllers; i++) {
        *((__OSContRequesFormat*)ptr) = requestformat;
        ptr += sizeof(__OSContRequesFormat);
    }

    *ptr = 0xfe ;
}
