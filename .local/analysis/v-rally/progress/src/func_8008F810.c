extern void func_8008D8B4(void);
extern void func_8008D920(void);
extern void func_8008F978(u8, u8 *);
extern s32 func_8008FA20(s32, u8 *);
extern s32 func_80090DC0(s32, void *);
extern s32 osRecvMesg(s32, void *, s32);
extern u8 D_800C02AE[];
extern u8 D_800AE850[];
typedef struct { u8 b[12]; } Blk12;

s32 func_8008F810(s32 mq, u8 ch, u8 *data)
{
    s32 ret = 0;
    u16 type;
    u8 *pif = D_800AE850 + 0x8660;
    Blk12 reply;
    u8 status[4];

    func_8008D8B4();
    ret = func_8008FA20(mq, status);
    type = *(u16 *)status & 0xC000;
    if (ret == 0) {
        switch (type) {
        case 0x8000:
            if (ch >= 0x40) {
                ret = -1;
            }
            break;
        case 0xC000:
            break;
        default:
            ret = 8;
            break;
        }
    }
    if (ret != 0) {
        func_8008D920();
        return ret;
    }
    while (status[2] & 0x80) {
        func_8008FA20(mq, status);
    }
    func_8008F978(ch, data);
    ret = func_80090DC0(1, D_800AE850 + 0x8660);
    osRecvMesg(mq, 0, 1);
    ret = func_80090DC0(0, D_800AE850 + 0x8660);
    D_800C02AE[0x3272] = 5;
    osRecvMesg(mq, 0, 1);
    pif += 4;
    reply = *(Blk12 *)pif;
    ret = (reply.b[1] & 0xC0) >> 4;
    func_8008D920();
    return ret;
}
