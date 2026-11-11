extern u8 D_800C8324;
extern u8 gOrderState[];
extern u8 gStreamState[];
void func_80072C94(void *, s32);
void func_800234E0(void);

/* Runs the pending select action for the current list node, then clears the action and
 * calls func_800234E0. Case 3 falls through into case 2 when the list is not a single entry. */
void func_8007301C(void)
{
  s32 *list_head = *((s32 **) (gOrderState + 0x73F0));
  s32 pending_action = D_800C8324;
  s32 one = 1;
  void *node = (void *) (*list_head);
  switch (pending_action)
  {
    case 0:
      return;

    case 1:
      func_80072C94(node, 0);
      break;

    case 3:
      if ((*((u16 *) ((*((void **) (gStreamState + 0x32F2))) + 0xE))) == one)
    {
      func_80072C94(node, 0);
      break;
    }
      func_80072C94(node, 0);

    case 2:
      node = *((void **) (node + 4));
      if (((*((u16 *) ((*((void **) (gStreamState + 0x32F2))) + 0x1E))) == 0) && ((*((u16 *) ((*((void **) (gStreamState + 0x32F2))) + 0x1A))) == one))
    {
      node = *((void **) (node - -4));
    }
      func_80072C94(node, 1);
      break;

  }

  D_800C8324 = 0;
  func_800234E0();
}
