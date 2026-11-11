/* identical to func_8008A704 in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80084DD4 in V-RALLY (matched), with its names changed by decompdecomp */

extern unsigned char gContPort0Found;
extern s32 gContCtx;
extern char D_800B21D0[];
s32 func_80084DD4(s32 arg0)
{
  int new_var;
  u8 *new_var2;
  if (gContPort0Found != 0)
  {
    new_var2 = (u8 *) (((char *) (gContCtx + ((arg0 & 0xFF) * 4))) + 0xF);
    return ((*new_var2) & (new_var = 8)) == 0;
  }
  if (gContPort0Found || gContCtx)
  {
    return 0;
  }
  else
  {
    return 0;
  }
  if (1)
  {
    do
    {
    }
    while (0);
  }
}
