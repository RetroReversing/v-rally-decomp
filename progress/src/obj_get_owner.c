/* Returns the owner pointer stored at offset 0x0C of obj, or NULL if obj is NULL. */ void *obj_get_owner(u8 *obj)
{
  u8 *p;

  p = obj;
  if (p != NULL) {
    return *(void **)(p + 0xC);
  }
  return NULL;
}
