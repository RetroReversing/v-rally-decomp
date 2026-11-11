extern void pif_lock(void);
extern void pif_unlock(void);
extern void order_write_request(s32);
extern u32 pakQueryStatus(s32, u16 *);
extern void __osSiRawStartDma(s32, void *);
extern s32 osRecvMesg(s32, void *, s32);
extern u8 gOrderState[];
extern u8 gStreamState[];
extern u8 D_800B6EB0[];

/* Reads one 32-byte block from the controller pak at page arg1 into dst (arg2). Polls the
 * pak status first and retries while it reports busy. Returns 0 on success or an error code. */
u32 pakReadBlock(s32 mq, u8 page, u8 *dst) {
    u8 pkt[20];
    s32 var_v0;
    u16 temp_v1;
    u32 err;
    u32 result;
    u8 *var_s3 = dst;
    u8 *var_v1;
    u8 *var_s2;
    pif_lock();
    result = pakQueryStatus(mq, (u16 *)pkt);
    temp_v1 = (*(u16 *)pkt & 0xC000) & 0xFFFF;
    var_s2 = D_800B6EB0;
    err = result;
    if (err == 0) {
        if (temp_v1 == 0x8000) {
            if (((u32)page & 0xFF) >= 0x40U) err = -1;
        } else if (temp_v1 != 0xC000) err = 8;
        if (err == 0) {
            do {
                if ((pkt[2] & 0x80) != 0)
                    pakQueryStatus(mq, (u16 *)pkt);
            } while ((pkt[2] & 0x80) != 0);
            order_write_request(page & 0xFF);
            __osSiRawStartDma(1, D_800B6EB0);
            osRecvMesg(mq, 0, 1);
            __osSiRawStartDma(0, D_800B6EB0);
            gStreamState[0x3272] = 4;
            osRecvMesg(mq, 0, 1);
            var_v0 = 3;
            do { var_v0--; var_s2++; } while (var_v0 >= 0);
            __builtin_memcpy(pkt + 8, var_s2, 12);
            err = (pkt[9] & 0xC0) >> 4;
            var_v1 = &pkt[12];
            if (err == 0) {
                u8 *end = &pkt[20];
                do { *var_s3++ = *var_v1++; } while ((s32)var_v1 < (s32)end);
            }
        }
    }
    pif_unlock();
    return err;
}
