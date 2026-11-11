extern char gOrderState[];

typedef struct {
    u8 b[12];
} Blk12;

/* Offsets inside gOrderState: the PIF command buffer, and the flag set when a command is queued. */
#define PFS_PIF_BUF_OFF 0x8660
#define PFS_CMD_READY_OFF 0x869C

/* Builds a controller pak write-block command in the PIF buffer: four zero bytes, a 12-byte
 * header (0x0A, 0x01, 0x05, page, then the 8 data bytes), and an 0xFE end marker. */
void pfs_build_write_cmd(u8 page, u8 *data)
{
    Blk12 cmd;
    u8 *pif;
    s32 i;
    u8 *src;

    pif = (u8 *)gOrderState + PFS_PIF_BUF_OFF;
    *(s32 *)(gOrderState + PFS_CMD_READY_OFF) = 1;
    cmd.b[0] = 10;
    cmd.b[1] = 1;
    cmd.b[2] = 5;
    cmd.b[3] = page;
    src = data;
    for (i = 4; i < 12; i++) {
        cmd.b[i] = *src++;
    }
    for (i = 3; i >= 0; i--) {
        *pif++ = 0;
    }
    *(Blk12 *)pif = cmd;
    pif[12] = 0xFE;
}
