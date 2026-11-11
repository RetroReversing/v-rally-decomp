s32 strCmp();
extern char D_800A4AE0[];
extern char D_800A4AE8[];
extern char D_800A4AF0[];
extern char gStreamState[];

/* Reads the name string at item+0x4C and sets the stream mode byte (gStreamState+0x331A) to 0x18, 0x19 or 0x1A for the three known names. Unknown names leave the mode unchanged. */
void streamSetModeByName(char *item)
{
  char *name;
  s8 mode;

  name = item + 0x4C;
  if (strCmp(name, D_800A4AE0) == 0)
  {
    mode = 0x18;
  }
  else if (strCmp(name, D_800A4AE8) == 0)
  {
    mode = 0x19;
  }
  else if (strCmp(name, D_800A4AF0) == 0)
  {
    mode = 0x1A;
  }
  else
  {
    return;
  }
  gStreamState[0x331A] = mode;
}
