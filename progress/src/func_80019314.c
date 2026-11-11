void updateMaxExtent(void *list, s32 *n);

/* Walks the object's command list: each entry adds its value to *extentX or *extentY (by
 * type), tracks the largest entry index into a count, and stores that count in obj+0xA
 * and adds it to *total. */
void func_80019314(u8 *obj, s32 *extentX, s32 *extentY, s32 *total)
{
  struct { s32 n; s32 pad[2]; } local;
#define maxIndex local.n
  u8 *info;
  s32 count;
  s32 *list;
  u16 *cmd;
  s32 i;
  if ((*((s16 *) (obj + 0x8))) != (-1))
  {
    info = *((u8 **) (obj + 0x18));
    count = *((u16 *) (info + 0x10));
    maxIndex = 0;
    list = *((s32 **) (info + 0x14));
    i = 0;
    if (count != 0)
    {
      ;
      do
      {
        switch ((u32) (((u16 *) (((u8 *) list) + 4))[1] - 0x18))
        {
          case 0:
            *extentY += ((u16 *) (((u8 *) list) + 4))[0];
            break;

          case 1:
            *extentX += ((u16 *) (((u8 *) list) + 4))[0];
            break;

          case 2:
            break;

          case 3:
            break;

          case 4:
            break;

          case 5:
            break;

          case 6:
            break;

          case 7:
            break;

          case 8:
            break;

          case 9:
            break;

          case 10:
            break;

          case 11:
            break;

          default:
            while (1)
          {
          }


        }

        updateMaxExtent(list, &maxIndex);
        cmd += 4;
        list += 2;
      }
      while ((++i) < count);
    }
    { s32 n = maxIndex + 1; maxIndex = n;
      *((s16 *) (obj + 0xA)) = n;
      *total += n;
    }
  }
}
