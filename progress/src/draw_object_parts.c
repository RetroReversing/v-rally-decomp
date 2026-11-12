s32 draw_object_dl();
extern u8 D_8009BBBC;
extern void *D_8009BFD8[];
extern char stream_state[];

/* Draws an object's parts: for each part of its part list, calls the draw handler
   selected by the part's index in D_8009BFD8, then runs draw_object_dl on the
   sub-object's first child unless D_8009BBBC is set. */
void draw_object_parts(char *obj, s32 arg1, s32 arg2, s32 drawArg, s32 arg4)
{
  u32 i;
  char *part;
  char *listRef;
  char *sub;
  s32 arg4Copy;
  s32 partCount;
  char *partList;
  s32 pad[2];
  do
  {
    listRef = *((char **) (obj + 0x44));
    arg4Copy = arg4;
    partList = *((char * volatile *) (obj + 0x44));
    partCount = *((s32 *) (listRef + 0x20));
    i = 0;
    sub = obj + 0x3C;
    *((s32 *) (stream_state + 0x7022)) = drawArg;
    part = partList + 0x24;
    if (partCount != 0)
    {
      do
      {
        ((void (*)(void *, s32, s32, s32)) (*((void **) (((u8 *) D_8009BFD8) + ((*((u16 *) (part + 6))) << 2)))))(sub, arg1, arg2, arg4Copy);
        i += 1;
        part += 8;
      }
      while (i < (*((u32 *) ((*((char **) (sub + 8))) + 0x20))));
    }
  }
  while (0);
  i = D_8009BBBC == 0;
  if (i)
  {
    draw_object_dl(*((s32 *) ((*((char **) (stream_state + 0x7CD6))) + 0x24)), drawArg, arg4Copy);
  }
}
