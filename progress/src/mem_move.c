s32 memcpy();
s32 func_80097CC0();
/* Copies a block for memmove semantics: forward memcpy when src is at or above dst, otherwise the backward copy routine. Returns dst. */ u32 mem_move(u32 dst, u32 src)
{
  if (src >= dst)
  {
    memcpy();
  }
  else
    if (dst || src)
  {
    func_80097CC0(dst);
  }
  else
  {
    func_80097CC0(dst);
  }
  return dst;
}
