s32 poolAlloc();
s32 sorted_list_insert();
s32 memset();

/* Allocates one pool node of `size` bytes, zeroes it, and inserts it into the sorted list `list` under `key` (low 16 bits). Returns the node. */
s32 sortedListAllocNode(s32 list, s32 size, s32 key)
{
  unsigned short new_var;
  int new_var2;
  s32 temp_v0;
  new_var2 = 0xFFFF;
  new_var = key & new_var2;
  temp_v0 = poolAlloc(1);
  memset(temp_v0, 0, size);
  sorted_list_insert(temp_v0, list, new_var);
  return temp_v0;
}
