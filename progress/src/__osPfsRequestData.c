extern OSPifRam __osPifBuf;
extern u8 __osPfsLastCmd;
extern u8 __osMaxControllers;

/* Fills the PIF buffer with one controller-pak request block per channel, then writes the end-of-list byte. */ void __osPfsRequestData(u8 cmd) {
    u8* cursor = (u8*)&__osPifBuf;
    __OSContRequesFormat req;
    int i;

    __osPfsLastCmd = cmd;
    __osPifBuf.pifstatus = 1 ;
    req.dummy = 0xff ;
    req.txsize = 1 ;
    req.rxsize = 3 ;
    req.cmd = cmd;
    req.typeh = 0xff ;
    req.typel = 0xff ;
    req.status = 0xff ;
    req.dummy1 = 0xff ;

    for (i = 0; i < __osMaxControllers; i++) {
        *((__OSContRequesFormat*)cursor) = req;
        cursor += sizeof(__OSContRequesFormat);
    }

    *cursor = 0xfe ;
}
