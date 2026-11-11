#define PTR_AT(p,o) (*(u8 **)((u8 *)(p)+(o)))
#define W32_AT(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define H16_AT(p,o) (*(u16 *)((u8 *)(p)+(o)))
extern u8 gOrderState[];
extern u8 gStreamState[];
typedef struct 
{
  u8 pad[0x44];
} Ent;
void func_80022BE8(void *, s32);
void init_car_from_record(void *, void *);
void func_800234E0(void);
/* Re-seeds the entries of one race-state slot list (the 0x73F0 node table) from
   the entry array, flagging each entry as dirty. Mode 7 also clears the per-node
   status bits; the other modes only update the entries they own. */
void func_8004F89C(Ent *arg0)
{
  long long new_var;
  u8 *node = 0;
  u8 *obj;
  u8 *game = PTR_AT(gStreamState, 0x32F2);
  u16 mode = H16_AT(game, 0x1E);
  u8 index = ((u8 *) arg0)[0x114];
  u8 i;
  if (mode != 7)
  {
    if (mode == 0)
    {
      s32 layout = H16_AT(game, 0x1A);
      if (layout == 1)
      {
        Ent *e = &arg0[index];
        if (H16_AT(e, 8) & 0x800)
        {
          if (index == 0)
          {
            node = PTR_AT(PTR_AT(gOrderState, 0x73F0), 0);
          }
          else
            if (index == layout)
          {
            node = PTR_AT(PTR_AT(gOrderState, 0x73F0), 4);
            node = PTR_AT(node, 0);
          }
          obj = (u8 *) (&arg0[index]);
          func_80022BE8(node, W32_AT(obj, 0));
          init_car_from_record(node, obj + 0x1C);
          W32_AT(PTR_AT(node, 0x88), 0) = W32_AT(obj, 0x18);
          if (W32_AT(PTR_AT(node, 0x48), 0) != 7)
          {
            *((u8 *) (gStreamState + 0x80BE)) = 1;
          }
          H16_AT(obj, 8) = (H16_AT(obj, 8) | 0x400) & 0xFDFF;
          node = PTR_AT(node, 4);
          W32_AT(PTR_AT(node, 0x5C), 0x6C) = 0;
          W32_AT(PTR_AT(node, 0x30), 0x6C) = 0;
          return;
        }
        if (index == 0)
        {
          node = PTR_AT(PTR_AT(gOrderState, 0x73F0), 0);
          node = PTR_AT(node, 4);
        }
        else
          if (index == layout)
        {
          node = PTR_AT(PTR_AT(gOrderState, 0x73F0), 4);
        }
        obj = (u8 *) (&arg0[index]);
        func_80022BE8(node, W32_AT(obj, 0));
        init_car_from_record(node, obj + 0x1C);
        W32_AT(PTR_AT(node, 0x88), 0) = W32_AT(obj, 0x18);
        W32_AT(node, 0x14) &= ~0x10;
        H16_AT(obj, 8) |= 0x400;
        W32_AT(PTR_AT(node, 0x5C), 0x6C) = 1;
        W32_AT(PTR_AT(node, 0x30), 0x6C) = 1;
      }
      else
        if (index == 0)
      {
        node = PTR_AT(PTR_AT(gOrderState, 0x73F0), 0);
        for (i = 0; i < H16_AT(arg0, 0x110); i++)
        {
          obj = (u8 *) (&arg0[i]);
          func_80022BE8(node, W32_AT(obj, 0));
          init_car_from_record(node, obj + 0x1C);
          H16_AT(obj, 8) = (H16_AT(obj, 8) | 0x400) & 0xFDFF;
          node = PTR_AT(node, 4);
        }

      }
    }
    else
      if (index == 0)
    {
      node = PTR_AT(PTR_AT(gOrderState, 0x73F0), 0);
      i = 0;
      do
      {
        obj = (u8 *) (&arg0[i]);
        func_80022BE8(node, W32_AT(obj, 0));
        init_car_from_record(node, obj + 0x1C);
        i++;
        H16_AT(obj, 0xA) = 4;
        H16_AT(obj, 0xC) = 0;
        H16_AT(obj, 8) = (H16_AT(obj, 8) | 0x400) & 0xFDFF;
        node = PTR_AT(node, 4);
      }
      while (i < 4U);
    }
  }
  else
  {
    if (index == 0)
    {
      node = PTR_AT(PTR_AT(gOrderState, 0x73F0), 0);
      for (i = 0; i < H16_AT(arg0, 0x110); i++)
      {
        obj = (u8 *) (&arg0[i]);
        func_80022BE8(node, W32_AT(obj, 0));
        init_car_from_record(node, obj + 0x1C);
        H16_AT(obj, 0xA) = 4;
        H16_AT(obj, 0xC) = 0;
        H16_AT(obj, 8) = (H16_AT(obj, 8) | 0x400) & 0xFDFF;
        W32_AT(node, 0x14) &= ~0x20;
        W32_AT(node, 0x14) &= ~0x40;
        W32_AT(node, 0x14) &= ~0x80;
        W32_AT(node, 0x14) &= ~0x100;
        W32_AT(node, 0x14) &= ~0x200;
        mode = 0x10;
        W32_AT(node, 0x14) &= ~mode;
        W32_AT(PTR_AT(node, 0x6C), 0x34) = 0;
        node = PTR_AT(node, 4);
      }

    }
    func_800234E0();
  }
}
