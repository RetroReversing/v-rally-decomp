typedef struct FrameBuf
{
  s16 x;
  s16 y;
  s16 w;
  s16 h;
  s32 unk8;
  s32 alloc;
  s32 heap;
  s8 ready;
  s8 b15;
  s32 srcFlags;
  f32 scaleX;
  f32 scaleY;
  s32 unk24;
} FrameBuf;
u32 func_8000E2F0(s32);
s32 poolAlloc(s32, s32);
void heapFreeBlock(FrameBuf *);
extern s32 D_8009B720[];

/* Sets up a frame buffer from a display mode word (mode). The mode picks the size: bit 0x200
 * gives 640x480, otherwise 320x240. Bit 0x80 doubles the bytes per pixel. The pixel buffer
 * comes from the frame buffer's heap; if that fails the buffer is torn down.
 * Returns 1 if fb was non-NULL, 0 otherwise. */
s32 frame_buffer_setup(FrameBuf *fb, s32 mode)
{
  s32 var_a0 = mode;
  s32 ret = 0;
  s32 bpp = 2;
  u32 v;
  s32 temp_s1;
  s32 alloc;
  if (fb != NULL)
  {
    temp_s1 = var_a0;
    if (temp_s1 & 0x10000)
    {
      var_a0 = temp_s1 + 2;
    }
    v = func_8000E2F0(var_a0);
    if (v < 0xE)
    {
      var_a0 = D_8009B720[v];
      var_a0 |= 0x400;
    }
    else
      if (v < 0x1C)
    {
      v -= 0xE;
      var_a0 = D_8009B720[v];
      var_a0 |= 0x800;
    }
    else
      if (v >= 0x2A)
    {
      v -= 0x2A;
      var_a0 = D_8009B720[v];
      var_a0 |= 0x800;
    }
    else
    {
      v -= 0x1C;
      var_a0 = D_8009B720[v];
      var_a0 |= 0x400;
    }
    if (var_a0 & 0x80)
    {
      bpp = 4;
    }
    fb->x = 0;
    fb->y = 0;
    if (var_a0 & 0x200)
    {
      fb->h = 0x1E0;
      fb->w = 0x280;
    }
    else
    {
      fb->h = 0xF0;
      fb->w = 0x140;
    }
    alloc = poolAlloc(fb->heap, ((fb->w * fb->h) * bpp) + 8);
    fb->alloc = alloc;
    if (alloc != 0)
    {
      fb->ready = 1;
      fb->srcFlags = temp_s1;
      fb->x = 0;
      fb->y = 0;
      fb->b15 = 0;
      fb->unk24 = 0x4A;
      fb->scaleX = 1.0f;
      fb->scaleY = 1.0f;
    }
    else
    {
      heapFreeBlock(fb);
    }
    ret = 1;
  }
  return ret;
}
