extern void *poolAlloc(s32, s32);
extern void *resolve_path(void *);
extern u32 *func_80081664(s32, s32);
extern u8 gStringTablePath;

typedef struct
{
  u32 *src;
  u32 **tbl;
  u32 n;
} S;

/* Loads a string table file. Its first word is the big-endian string count, and the
 * NUL-terminated strings follow. Returns a pool-allocated S with a pointer to each string. */
void *func_80057810(s32 fileIndex)
{
  S *table;
  u32 *data;
  u32 count;
  s32 i;
  s32 pad[2];
  char *str;
  u32 x;

  table = poolAlloc(1, 12);
  resolve_path(&gStringTablePath);
  data = func_80081664(1, fileIndex);
  table->src = data;
  count = *data;
  count = (((count >> 24) | ((count >> 8) & 0xff00)) | ((count & 0xff00) << 8)) | (count << 24);
  table->n = count;
  table->tbl = poolAlloc(1, count * 4);
  str = ((char *) table->src) + 4;
  i = 0;
  if (count)
  {
    do
    {
      { do { u32 **__repair_index_scope_base = table->tbl; s32 __repair_index_scope_offset = i; *(__repair_index_scope_base + __repair_index_scope_offset) = (u32 *)str; } while (0); }
      while (*(str++))
      {
        ;
      }

      i++;
    }
    while (((u32) i) < count);
  }
  return table;
}
