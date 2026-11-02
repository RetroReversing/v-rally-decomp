typedef struct 
{
  u8 p[0x14];
  u32 *cmd;
  u32 *old;
  u8 p1c[0x54];
  s16 *items;
  u8 p74[6];
  u16 count;
} O;
typedef struct 
{
  s16 a;
  s16 b;
  s16 c;
} E;
extern s32 osVirtualToPhysical(void *);
extern void func_80008C8C(void *, s32);
void func_80008E80(O *arg0, E *in, s32 n, u16 *out)
{
  O *o = arg0;
  s32 remaining = n;
  s32 i;
  s32 j;
  u16 start;
  volatile char pad[8];
#define new_var n
  j = 0;
  if (new_var > 0)
  {
    do
    {
      out[j] = 0xffff;
      j++;
    }
    while (j < new_var);
  }
  start = o->count >> 5;
  for (i = 0; i < new_var; i++)
  {
    E *src;
    u16 *dst;
    j = start * 32;
    if (j < o->count)
    {
      do
      {
        E *p = (E *) (((j << 2) << 2) + ((s32) o->items));
        if (((p->a == (in + i)->a) && (p->b == (in + i)->b)) && (p->c == (in + i)->c))
        {
          *(out + i) = j;
          remaining--;
        }
        j++;
      }
      while (j < o->count);
    }
  }

  if ((o->count & 31) == 0)
  {
    u32 *cmd;
    o->old = o->cmd;
    cmd = o->cmd;
    o->cmd = cmd + 2;
    cmd[0] = 0x01020040;
    cmd[1] = osVirtualToPhysical(((u8 *) o->items) + (o->count << 4));
    func_80008C8C(((u8 *) o->items) + (o->count << 4), 32);
  }
  {
    u16 count = o->count;
    s32 end = count + remaining;
    if (!(((end - 1) / 32) != (count >> 5)))
    {
      for (i = 0; i < new_var; i++)
      {
        if (out[i] == 0xffff)
        {
          unsigned int k = o->count++;
          ((E *) ((k << 4) + ((s32) o->items)))->a = in[i].a;
          ((E *) ((k << 4) + ((s32) o->items)))->b = in[i].b;
          ((E *) ((k << 4) + ((s32) o->items)))->c = in[i].c;
          out[i] = k;
        }
      }

    }
    else
    {
      u32 *cmd;
      o->old = o->cmd;
      cmd = o->cmd;
      o->cmd = cmd + 2;
      cmd[0] = 0x01020040;
      count = (count >> 5) + 1;
      cmd[1] = osVirtualToPhysical(((u8 *) o->items) + (count << 9));
      count <<= 5;
      o->count = count;
      func_80008C8C(((u8 *) o->items) + ((count & 0xffe0) << 4), 32);
      for (i = 0; i < new_var; i++)
      {
        unsigned int k = o->count++;
        ((E *) ((k << 4) + ((s32) o->items)))->a = in[i].a;
        ((E *) ((k << 4) + ((s32) o->items)))->b = in[i].b;
        ((E *) ((k << 4) + ((s32) o->items)))->c = in[i].c;
        out[i] = k;
      }

    }
  }
}
