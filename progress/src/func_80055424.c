extern char stream_state[];
s32 soundNameHash();
u8 *poolAlloc();
static inline u8 **inline_fn(char *arg0, u32 arg1)
{
  return ((u8 **) arg0) + arg1;
}

/* Adds one sound request to the queue table, keyed by seed + name hash + first char of name.
 * An existing entry with the same key just gets its count bumped; otherwise a new node is linked
 * into the first free bucket slot of the table. */
void func_80055424(u8 *name, u16 seed, s32 value)
{
  s32 hash = soundNameHash(name, seed & 0xFFFF);
  u32 bucket = hash & 0xFFFF;
  u8 **new_var;
  u8 **new_var2;
  u8 *node = *inline_fn(stream_state + 0x3902, bucket);
  u8 firstChar;
  s32 slot;
  if (node == 0)
  {
    node = poolAlloc(1, 0xC);
    *inline_fn(stream_state + 0x3902, bucket) = node;
    firstChar = *name;
    node[2] = 1;
    *((s32 *) (node + 4)) = value;
    *((u16 *) node) = firstChar + (seed + hash);
    node[8] = *name;
    return;
  }
  ;
  if (((*((u16 *) node)) == ((u32) (((seed & 0xFFFF) + bucket) + (*name)))) && ((*((s8 *) (node + 8))) == (*name)))
  {
    node[2] += 1;
    return;
  }
  if (new_var || stream_state)
  {
    slot = 0;
  }
  else
  {
    slot = 0;
  }
  if ((*((s32 *) (stream_state + 0x3902))) != 0)
  {
    do
    {
      slot++;
    }
    while ((*((s32 *) ((stream_state + 0x3902) + ((slot & 0xFF) * 4)))) != 0);
  }
  {
    u8 *fresh = poolAlloc(1, 0xC);
    u8 **tail = inline_fn(stream_state + 0x3902, slot & 0xFF);
    *tail = fresh;
    *((u16 *) fresh) = (*name) + (seed + hash);
    new_var = tail;
    *((s32 *) ((*new_var) + 4)) = value;
    new_var2 = tail;
    (*new_var)[2] = 1;
    (*new_var2)[8] = *name;
  }
}
