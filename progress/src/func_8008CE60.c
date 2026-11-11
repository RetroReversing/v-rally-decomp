typedef struct {
	u16     type;
	u8      status;
	u8	errno;
} OSContStatus;

typedef struct
{
      u8 dummy;
      u8 txsize;
      u8 rxsize;
      u8 cmd;
      u8 typeh;
      u8 typel;
      u8 status;
      u8 dummy1;
} __OSContRequesFormat;

typedef struct
{
      u32 ramarray[15];
      u32 pifstatus;
} OSPifRam;

extern OSPifRam D_800C8130;
extern u8 D_800B60E0;

/* Reads the init/status response for each controller channel (D_800B60E0
 * channels) from the PIF buffer. Each channel's type and status go into
 * data[ch]; channels with no error set their bit in *pattern. */
void func_8008CE60(u8* pattern, OSContStatus* data) {
    u8* ptr;
    __OSContRequesFormat requestformat;
    int i;
    u8 bits = 0;

    ptr = (u8*)&D_800C8130;

    for (i = 0; i < D_800B60E0; i++, ptr += sizeof(requestformat), data++) {
        requestformat = *((__OSContRequesFormat*)ptr);
        data->errno = ((( requestformat ).rxsize & 0xC0 ) >> 4) ;

        if (data->errno != 0) {
            continue;
        }

        data->type = ((requestformat.typel << 8) | requestformat.typeh);
        data->status = requestformat.status;
        bits |= (1 << i);
    }
    *pattern = bits;
}
