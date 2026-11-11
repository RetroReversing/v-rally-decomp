u32 osVirtualToPhysical(u32);

/* Appends a 2-word load command to the display list at ctx->dl (+0x14). The first word encodes the chunk size in ctx->chunkSize (+0x7A), the second the physical address of ctx->dataBase (+0x70) plus the chunk offset. */
void dlAddLoadChunk(void *ctx)
{
  void *dl;
  dl = *((void **) (((char *) ctx) + 0x14));
  if (1)
  {
    *((void **) (((char *) ctx) + 0x14)) = (void *) (dl + 8);
    *((s32 *) (((char *) dl) + 0)) = (s32) ((((0x20 - ((*((u16 *) (((char *) ctx) + 0x7A))) & 0x1F)) & 0xFF) << 0xC) | 0x01000040);
 do { } while (0);
  }
  *((s32 *) (((char *) dl) + 4)) = osVirtualToPhysical((*((s32 *) (((char *) ctx) + 0x70))) + (((*((u16 *) (((char *) ctx) + 0x7A))) * 2) * 8));
}
