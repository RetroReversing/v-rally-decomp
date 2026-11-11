s32 stream_check_buttons(s32, s32);
s32 func_80084BF0(s32);
s32 func_80084DD4(s32);
extern s32 gRecordTimeScale;
extern s32 D_800A18D0;
extern u8 D_800C83C4[];
extern volatile u8 D_800C83C5;
extern u16 D_800C8240[];
extern void *gRecords;

/* Handles the pending record-save choice in D_800C83C4: each choice is tested against the
 * matching argument, and the last one also sets the record flag bits in arg4 once it is confirmed. */
void func_8007C3E0(s32 choice0, s32 choice1, s32 choice2, s32 choice3, s32 flagBits) {
    s32 pad;
    u16 recFlags;

    if (func_80084DD4(0) != 0) {
        pad = func_80084BF0(0);
        switch (D_800C83C4[0]) {
        case 0:
            stream_check_buttons(pad, choice0);
            return;
        case 1:
            stream_check_buttons(pad, choice1);
            return;
        case 2:
            stream_check_buttons(pad, choice2);
            return;
        case 3:
            if (stream_check_buttons(pad, choice3) != 0) {
                recFlags = *(u16 *)((u8 *)gRecords + 0x2C);
                if (recFlags & 0x8000) {
                    D_800C83C4[0] = 0U;
                    D_800A18D0 |= flagBits;
                    D_800C83C5 = (s8) gRecordTimeScale;
                    return;
                }
                *(u16 *)((u8 *)gRecords + 0x2C) = (u16) (recFlags | flagBits);
                D_800C83C4[0] = 0U;
                D_800C8240[0] = (u16) (D_800C8240[0] | flagBits);
                D_800C83C5 = (s8) gRecordTimeScale;
                return;
            }
            break;
        default:
            D_800C83C4[0] = 0U;
            D_800C83C5 = (s8) gRecordTimeScale;
            break;
        }
    }
}
