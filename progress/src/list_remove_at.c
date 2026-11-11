extern void streamReleaseEntry();
extern s32 list_unlink_free();

/* Walks `skip` nodes down the list whose head is *listHead (node->next at +4), then frees the payload at
 * node+0xC and unlinks the node from the list. Returns 0 if the list ends before `skip` steps. */
s32 list_remove_at(s32 skip, void **listHead)
{
  void **node;
  node = *listHead;
  while (((skip & 0xFF) != 0) & (node != 0))
  {
    skip--;
    node = *((void ***) (((char *) node) + 4));
  }

  if (((skip & 0xFF) != 0) || (node == 0))
  {
    return 0;
  }
  streamReleaseEntry(*((void **) (((char *) node) + 0xC)));
  list_unlink_free(node, listHead);
  return 1;
}
