extern s32 gRecords;
extern char gOrderState[];
extern char gStreamState[];

/* Finds the node in the list at gOrderState+0x73F0 whose id matches this car's kind (+0xA8 owner),
 * then sets the car's value at +0x7A from that node's record slot. Does nothing if no node matches. */
void func_8003EF20(void *car)
{
  void *owner;
  u32 kind;
  char *list;
  s32 dir;
  s32 value;
  s16 base;
  void *node;
  u8 *slot;
  owner = *((void **) (((u8 *) car) + 0xA8));
  node = *((void **) (((u8 *) owner) + 0x24));
  if (node != NULL)
  {
    kind = *((u32 *) (((u8 *) (*((void **) (((u8 *) (*((void **) (((u8 *) owner) + 0x24)))) + 0x6C)))) + 8));
    if (kind >= 2)
    {
      dir = -1;
      base = (*((u16 *) (((u8 *) (*((void **) (((u8 *) owner) + 0x178)))) + 0xA))) + 6;
    }
    else
    {
      dir = 1;
      base = (*((u16 *) (((u8 *) (*((void **) (((u8 *) owner) + 0x178)))) + 0xA))) + 0x10;
    }
    list = gOrderState + 0x73F0;
    *((s16 *) (((u8 *) car) + 0xE)) = base;
    for (node = *(*((void ***) list)); node != NULL; node = *((void **) (((u8 *) node) + 4)))
    {
      if ((*((s32 *) (((u8 *) (*((void **) (((u8 *) node) + 0x6C)))) + 8))) == (kind + dir))
      {
        break;
      }
    }

    if (node != NULL)
    {
      slot = ((u8 *) ((gRecords + ((*((u8 *) ((gRecords + (*((s32 *) (((u8 *) (*((void **) (((u8 *) node) + 0x48)))) + 0x2C)))) + 0x32))) * 0x28)) + (*((u16 *) (((u8 *) car) + 0x78))))) + 0x44;
      value = *slot;
      if (value < 0x41)
      {
        *((s16 *) (((u8 *) car) + 0x7A)) = value - 0x16;
      }
      else
        if (1)
      {
        *((s16 *) (((u8 *) car) + 0x7A)) = value - 0x41;
      }
    }
  }
}
