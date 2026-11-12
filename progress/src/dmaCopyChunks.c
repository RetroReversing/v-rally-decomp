extern char stream_state[];
s32 osCreateMesgQueue(s32 *a, s32 *b, s32 c);
s32 osRecvMesg(s32 *a, s32 *b, s32 c);
s32 osSendMesg(char *a, s32 *b, s32 c);
typedef struct
{
  s32 w[6];
} Pkt6;
typedef struct
{
  s32 pkt[9];
  s32 sp34[6];
  s32 sp4C;
} Locals80;

/* Copies size bytes from romAddr to ramAddr in chunks of at most 0x4000 bytes. Each chunk
 * is sent as a DMA request (with the six trailing words of req) to the DMA queue and waited on
 * before the next one. */
void dmaCopyChunks(s32 romAddr, s32 ramAddr, u32 size, Pkt6 req)
{
  Locals80 l;
  u32 len;

  while (size != 0)
  {
    len = size;
    if (size >= 0x4001U)
    {
      len = 0x4000;
    }
    l.pkt[0] = romAddr;
    l.pkt[1] = ramAddr;
    l.pkt[2] = len;
    *((Pkt6 *) (l.pkt + 3)) = req;
    osCreateMesgQueue(l.sp34, &l.sp4C, 1);
    osSendMesg(stream_state + 0x768A, l.pkt, 1);
    osRecvMesg(l.sp34, &l.sp4C, 1);
    romAddr += len;
    size -= len;
    ramAddr += len;
  }
}
