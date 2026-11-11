extern char D_800A73E0[];
extern char gOrderState[];

/* Rebuilds the five-slot table of list entries, then walks slot 4 down to slot 0,
   adding each entry's weight into the running total of the entry it links to. */
void func_80042DE0(void)
{
  void *slot[5];
  u16 i;
  char *node;
  char *tbl;
  char *ent;
  s32 idx;
  char *cur;
  s32 t1;
  s32 v1;
  s32 sum;
  char *base4;
  s32 five;
  char *tbl2;
  s32 one;
  s32 *list;
  i = 0;
  do
  {
    slot[i] = NULL;
    i++;
  }
  while (i < 5);
  list = *((s32 **) (gOrderState + 0x73F0));
  node = *((char **) list);
  if (node != NULL)
  {
    tbl = D_800A73E0 + 0x6C00;
    do
    {
      ent = *((char **) (node + 0x6C));
      idx = *((s32 *) (ent + 8));
      v1 = (*((u8 *) tbl)) * 4;
      if ((*((s32 *) ((v1 + (*((char **) ent))) - 4))) == 0)
      {
        slot[idx] = node;
      }
      node = *((char **) (node + 4));
    }
    while (node != NULL);
  }
  cur = slot[4];
  if (cur != NULL)
  {
    t1 = 4;
    five = 5;
    tbl2 = D_800A73E0 + 0x6C00;
    one = 1;
    do
    {
      if ((*(*((s32 **) (cur + 0x48)))) == five)
      {
        cur = *((char **) (cur + 0x6C));
        base4 = *((char **) cur);
        base4 += 4;
        sum = *((s32 *) (cur + 0xC));
        v1 = *((s32 *) (cur + 4));
        if ((*((s32 *) ((base4 + ((*((u8 *) tbl2)) * 4)) - 8))) == 0)
        {
          idx = *((s32 *) (cur + 8));
          if (((u32) idx) >= 5)
          {
            idx = 4;
          }
          if (((u32) one) < ((u32) idx))
          {
            i = 1;
            do
            {
              node = slot[i];
              i++;
              if (node != NULL)
              {
                sum += *((s32 *) ((*((char **) (node + 0x6C))) + 0xC));
              }
            }
            while (((u32) i) < ((u32) idx));
          }
          *((s32 *) ((base4 + ((*((u8 *) tbl2)) * 4)) - 8)) = v1 + sum;
        }
      }
      v1 = t1 - 1;
      t1 = v1;
      cur = slot[(u16) v1];
    }
    while (cur != NULL);
  }
}
