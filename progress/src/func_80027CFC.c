/* identical to func_800270DC in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80027CFC in V-RALLY (matched), with its names changed by decompdecomp */

void func_80027CFC(unsigned char *a)
{
  unsigned int x = a[1];
  unsigned int y = a[2];
  unsigned int v = (y | (~x)) | 0x90;
  unsigned int w = a[1] & v;
  a[2] = v;
  a[3] = a[1] & v;
}
