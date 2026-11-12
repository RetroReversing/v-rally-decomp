/* Walks a linked list of stream nodes (next pointer at +4, flag word at +0x14) and returns the first node whose flags contain all bits in `flags`, or 0 if none (or if list is NULL). */ void *streamListFindByFlags(int *list, unsigned char flags)
{
  char *node;
  int listIsNull;
  listIsNull = !list;
  if (listIsNull)
  {
 do { return 0; } while (0);
  }
  for (node = *((char **) list); node; node = *((char **) (node + 4)))
  {
    if (((*((unsigned int *) (node + 0x14))) & flags) == flags)
    {
      return node;
    }
  }

  return 0;
}
