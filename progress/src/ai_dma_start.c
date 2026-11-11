/* Audio DMA registers (AI) and the "buffer flip" flag shared with the audio code. */
#define AI_DRAM_ADDR (*(vs32 *)0xA4500000)
#define AI_LEN       (*(vs32 *)0xA4500004)

extern u8 ai_buffer_flip;
extern s32 osVirtualToPhysical(s32);
extern s32 ai_is_full(void);

/* Starts an audio DMA from virtual address vaddr for len bytes. Alternates between two
 * halves of the buffer (0x2000 apart) so the DMA does not overlap the previous one.
 * Returns 0 if the transfer started, -1 if the AI FIFO is full. */
s32 ai_dma_start(s32 vaddr, s32 len)
{
  s32 addr = vaddr;
  s32 ret;
  if (ai_buffer_flip != 0)
  {
    addr -= 0x2000;
  }
  if (((vaddr + len) & 0x1FFF) == 0)
  {
    ai_buffer_flip = 1; }
  else
  {
    ai_buffer_flip = 0;
  }
  if (ai_is_full() == 0)
  {
    ret = osVirtualToPhysical(addr);
    AI_DRAM_ADDR = ret;
    ret = 0;
    AI_LEN = len;
    return ret;
  }
  return -1;
}
