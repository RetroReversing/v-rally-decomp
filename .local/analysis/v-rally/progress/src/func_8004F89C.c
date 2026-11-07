#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
#define W(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
typedef struct 
{
  u8 pad[0x44];
} Ent;
void func_80022BE8(void *, s32);
void func_800239CC(void *, void *);
void func_800234E0(void);
void func_8004F89C(Ent *arg0)
{
  long long new_var;
  u8 *node = 0;
  u8 *obj;
  u8 *g = P(D_800C02AE, 0x32F2);
  u16 mode = H(g, 0x1E);
  u8 index = ((u8 *) arg0)[0x114];
  u8 i;
  if (mode != 7)
  {
    if (mode == 0)
    {
      s32 type = H(g, 0x1A);
      if (type == 1)
      {
        Ent *e = &arg0[index];
        if (H(e, 8) & 0x800)
        {
          if (index == 0)
          {
            node = P(P(D_800AE850, 0x73F0), 0);
          }
          else
            if (index == type)
          {
            node = P(P(D_800AE850, 0x73F0), 4);
            node = P(node, 0);
          }
          obj = (u8 *) (&arg0[index]);
          func_80022BE8(node, W(obj, 0));
          func_800239CC(node, obj + 0x1C);
          W(P(node, 0x88), 0) = W(obj, 0x18);
          if (W(P(node, 0x48), 0) != 7)
          {
            *((u8 *) (D_800C02AE + 0x80BE)) = 1;
          }
          H(obj, 8) = (H(obj, 8) | 0x400) & 0xFDFF;
          node = P(node, 4);
          W(P(node, 0x5C), 0x6C) = 0;
          W(P(node, 0x30), 0x6C) = 0;
          return;
        }
        if (index == 0)
        {
          node = P(P(D_800AE850, 0x73F0), 0);
          node = P(node, 4);
        }
        else
          if (index == type)
        {
          node = P(P(D_800AE850, 0x73F0), 4);
        }
        obj = (u8 *) (&arg0[index]);
        func_80022BE8(node, W(obj, 0));
        func_800239CC(node, obj + 0x1C);
        W(P(node, 0x88), 0) = W(obj, 0x18);
        W(node, 0x14) &= ~0x10;
        H(obj, 8) |= 0x400;
        W(P(node, 0x5C), 0x6C) = 1;
        W(P(node, 0x30), 0x6C) = 1;
      }
      else
        if (index == 0)
      {
        node = P(P(D_800AE850, 0x73F0), 0);
        for (i = 0; i < H(arg0, 0x110); i++)
        {
          obj = (u8 *) (&arg0[i]);
          func_80022BE8(node, W(obj, 0));
          func_800239CC(node, obj + 0x1C);
          H(obj, 8) = (H(obj, 8) | 0x400) & 0xFDFF;
          node = P(node, 4);
        }

      }
    }
    else
      if (index == 0)
    {
      node = P(P(D_800AE850, 0x73F0), 0);
      i = 0;
      do
      {
        obj = (u8 *) (&arg0[i]);
        func_80022BE8(node, W(obj, 0));
        func_800239CC(node, obj + 0x1C);
        i++;
        H(obj, 0xA) = 4;
        H(obj, 0xC) = 0;
        H(obj, 8) = (H(obj, 8) | 0x400) & 0xFDFF;
        node = P(node, 4);
      }
      while (i < 4U);
    }
  }
  else
  {
    if (index == 0)
    {
      node = P(P(D_800AE850, 0x73F0), 0);
      for (i = 0; i < H(arg0, 0x110); i++)
      {
        obj = (u8 *) (&arg0[i]);
        func_80022BE8(node, W(obj, 0));
        func_800239CC(node, obj + 0x1C);
        H(obj, 0xA) = 4;
        H(obj, 0xC) = 0;
        H(obj, 8) = (H(obj, 8) | 0x400) & 0xFDFF;
        W(node, 0x14) &= ~0x20;
        W(node, 0x14) &= ~0x40;
        W(node, 0x14) &= ~0x80;
        W(node, 0x14) &= ~0x100;
        W(node, 0x14) &= ~0x200;
        mode = 0x10;
        W(node, 0x14) &= ~mode;
        W(P(node, 0x6C), 0x34) = 0;
        node = P(node, 4);
      }

    }
    func_800234E0();
  }
}

