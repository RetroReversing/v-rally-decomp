extern void *func_8007EAA0(s32, s32);
extern void *func_80081540(void *);
extern u32 *func_80081664(s32, s32);
extern u8 D_800A5228;
typedef struct 
{
  u32 *src;
  u32 **tbl;
  u32 n;
} S;
void *func_80057810(s32 arg0)
{
  S *s1;
  u32 *v0;
  u32 n;
  s32 i;
  s32 pad[2];
  char *q;
  u32 x;
  s1 = func_8007EAA0(1, 12);
  func_80081540(&D_800A5228);
  v0 = func_80081664(1, arg0);
  s1->src = v0;
  n = *v0;
  n = (((n >> 24) | ((n >> 8) & 0xff00)) | ((n & 0xff00) << 8)) | (n << 24);
  s1->n = n;
  s1->tbl = func_8007EAA0(1, n * 4);
  q = ((char *) s1->src) + 4;
  i = 0;
  if (n)
  {
    do
    {
      { do { u32 **__repair_index_scope_base = s1->tbl; s32 __repair_index_scope_offset = i; *(__repair_index_scope_base + __repair_index_scope_offset) = (u32 *)q; } while (0); }
      while (*(q++))
      {
        ;
      }

      i++;
    }
    while (((u32) i) < n);
  }
  return s1;
}
