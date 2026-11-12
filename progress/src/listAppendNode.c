/* Appends node to the list whose head is at +0 and tail at +4 of list. The node's prev link is at +0 and next link at +4. */
void listAppendNode(void *node, void *list)
{
  if ((*((void **) (((s8 *) list) + 0))) == NULL)
  {
    *((void **) (((s8 *) list) + 0)) = node;
  }
  else
  {
    *((void **) (((s8 *) (*((void **) (((s8 *) list) + 4)))) + 4)) = node;
  }
  *((s32 *) (((s8 *) node) + 4)) = 0;
  *((void **) (((s8 *) node) + 0)) = (void *) (*((void **) (((s8 *) list) + 4)));
  *((s16 *) (((s8 *) node) + 8)) = 0;
  *((s16 *) (((s8 *) node) + 0xA)) = 0;
  *((void **) (((s8 *) list) + 4)) = node;
}
