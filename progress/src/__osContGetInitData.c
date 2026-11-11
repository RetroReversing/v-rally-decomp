typedef struct {
    u16 type;
    u8 status;
    u8 errno;
} OSContStatus;

typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
    u8 dummy1;
} __OSContRequesFormat;

extern u32 __osContPifRam[16];
extern u8 D_800B60E0;

void __osContGetInitData(u8 *pattern, OSContStatus *data) {
    u8 *pifEntry;
    __OSContRequesFormat resp;
    int i;
    u8 bits = 0;

    /* Reads each channel's init/query response from the PIF RAM. Fills data[i]
       with type and status for every channel that answered, and stores a bitmask
       of the connected channels in *pattern. */
    pifEntry = (u8*)&__osContPifRam;

    for (i = 0; i < D_800B60E0; i++, pifEntry += sizeof(resp), data++) {
        resp = *((__OSContRequesFormat*)pifEntry);
        data->errno = (resp.rxsize & 0xC0) >> 4;

        if (data->errno != 0) {
            continue;
        }

        data->type = ((resp.typel << 8) | resp.typeh);
        data->status = resp.status;
        bits |= (1 << i);
    }
    *pattern = bits;
}
