extern s32 D_800C782C;
extern u8 D_800AE850[];
s32 func_800869B8(s32 arg0)
{
  u8 pad[8];
  s32 i;
  long hits;
  u8 *p;
  hits=0;i=0;
  p=*(u8**)0x800B68F0;
  if (D_800C782C > 0)
  {
    do
    {
      if ((*((s32 *) p)) != 0)
      {
        if ((*((u16 *) (p + 0x9e))) != 0)
        {
          if (!(arg0 & 1))
          {
            i++;
          }
          else
          {
            goto hit;
          }
        }
        else
        {
          if (arg0 & 2)
          {
            hit:
            hits++;

          }
          goto next;
        }
      }
      else
      {
        next:
        i++;

      }
 do { p += 0x134; } while (0);
    }
    while (i < D_800C782C);
  }
  return hits;
}
