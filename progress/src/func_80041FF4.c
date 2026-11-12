void *find_entry_by_name(s32 *, s32);
s32 find_object_by_id(s32);
void *poolAllocNode(s32, s32);
s32 poolAllocHeadNode();
extern s32 D_800A0130;
extern s32 stream_state;

/* Looks up the object with id `id` and the entry named `name`, then allocates a 0x1C-byte record
 * for them. The record stores a fresh value, the entry's two fields and a link to the entry. */
void *func_80041FF4(s32 id, s32 name)
{
  s32 object;
  char *new_var;
  void *record;
  int new_var2;
  void *entry;
  object = find_object_by_id(id & 0xFF);
  new_var = (char *) (&stream_state);
  *((s32 *) (new_var + 0x7CD6)) = object;
  new_var2 = object + 0x28;
  entry = find_entry_by_name(&D_800A0130, name);
  record = poolAllocNode(new_var2, 0x1C);
  *((s32 *) (((char *) record) + 0x10)) = poolAllocHeadNode();
  *((s32 *) (((char *) record) + 0x14)) = (s32) (*((s32 *) (((char *) entry) + 0xC)));
  *((s32 *) (((char *) record) + 0x18)) = (s32) (*((s32 *) (((char *) entry) + 0x10)));
  *((void **) (((char *) record) + 0xC)) = entry;
  return record;
}
