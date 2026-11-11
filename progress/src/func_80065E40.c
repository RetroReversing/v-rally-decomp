typedef struct { s32 w0; s32 w1; s32 w2; s32 w3; } Chunk;
extern void *gSelectState;
extern s32 gSelectBuffer;
extern char D_800B6778[];
extern char gStreamState[];
s32 selectCopyEntryLabel();
s32 func_8005C198();
s32 heapFreeBlock();
void init_stage_screen();
void func_80066384();
void func_80066470();

/* Enters the stage select screen: copies the stream's 0xA0-byte record block into
 * D_800B6778, clears the select flag and the counter, frees the pending resource if any,
 * and installs the screen's three handlers. Returns 1. */
s32 func_80065E40(s32 arg0, s32 arg1)
{
  char *stream_base;
  Chunk *src;
  Chunk *dst;

  dst = (Chunk *)D_800B6778;
  stream_base = *(char **)(gStreamState + 0x32F2);
  src = (Chunk *)(stream_base + 0x44);
  do {
    *dst = *src;
    src++;
    dst++;
  } while (src != (Chunk *)(stream_base + 0xE4));
  *(s8 *)((char *)gSelectState + 0x245) = 0;
  *(s16 *)(*(char **)(gStreamState + 0x32F2) + 0x20) = 0;
  func_8005C198();
  if (gSelectBuffer != 0) {
    heapFreeBlock(gSelectBuffer);
    gSelectBuffer = 0;
  }
  selectCopyEntryLabel(arg0, arg1);
  *(void **)((char *)gSelectState + 0x288) = init_stage_screen;
  *(void **)((char *)gSelectState + 0x28C) = func_80066384;
  *(void **)((char *)gSelectState + 0x290) = func_80066470;
  return 1;
}
