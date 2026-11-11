/* identical to func_80087FD8 in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to toLowerChar in V-RALLY (matched), with its names changed by decompdecomp */

unsigned char toLowerChar(char arg0)
{
  if (((unsigned char) (arg0 - 0x41)) < 0x1B)
  {
    return arg0 + 0x20;
  }
  return arg0;
}
