typedef struct Obj
{
  u8 pad[0x7c];
  s32 count;
  void *items[16];
} Obj;
extern u8 gOrderState[];
extern u8 D_800B7280[];
s32 func_80082438(u8 *);
Obj *nameNodeFindOrAdd(Obj *, u8 *, s32);
void func_800826DC(Obj *);

/* Walks the path list in gOrderState one name at a time, starting at the root
   object. A name ending in '/' opens (or creates) a sub-directory under the
   current one; the final name is added as a file entry in that directory. */
void stream_build_path_tree(void)
{
  u8 *name;
  u8 buf[0x80];
  s32 count;
  u8 *path_base;
  u8 *src_start;
  int done = 0;
  s32 index = 0;
  Obj *obj = *((Obj **) (gOrderState + 0x8AB4));
  do
  {
    u8 *dst;
    u8 *p;
    count = 0;
    name = buf;
    path_base = gOrderState - (-0x8A30);
    dst = buf;
    p = (src_start = path_base + index);
    do
    {
      *(dst++) = *(p++);
      index++;
      count++;
    }
    while ((((s8) gOrderState[0x8A2F + index]) != '/') && (((s8) gOrderState[0x8A2F + index]) != 0));
    if (((s8) buf[count - 1]) == '/')
    {
      name[count] = 0;
      obj = nameNodeFindOrAdd(obj, name, count);
      if (((s8) gOrderState[0x8A30 + index]) == 0)
      {
        done = 1;
      }
    }
    else
    {
      obj->count++;
#ifdef PORT
      obj->items[obj->count] = (void *)(uintptr_t) func_80082438(buf);
#else
      obj->items[obj->count] = (void *) func_80082438(buf);
#endif
      done = 1;
      if ((*obj).count >= 2)
      {
        func_800826DC(obj);
      }
    }
  }
  while (!done);
}