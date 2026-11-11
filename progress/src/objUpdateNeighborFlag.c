extern s32 D_8009D534;

/* If the object's +0xA8 record has a neighbour, sets bit 4 of the object's flags at +0x80 when the neighbour's linked record's first word equals D_8009D534, otherwise clears it. */
void objUpdateNeighborFlag(void *arg0)
{
  void *neighbor;

  neighbor = *((void **) (((char *) (*((void **) (((char *) arg0) + 0xA8)))) + 0x24));
  if (neighbor != NULL)
  {
    if ((*(*((s32 **) (((char *) (*((void **) (((char *) neighbor) + 0x6C)))) + 0x24)))) == D_8009D534)
    {
      *((s32 *) (((char *) arg0) + 0x80)) = (*((s32 *) (((char *) arg0) + 0x80))) | 4;
    }
    else
    {
      *((s32 *) (((char *) arg0) + 0x80)) = (*((s32 *) (((char *) arg0) + 0x80))) & ~4;
    }
  }
}
