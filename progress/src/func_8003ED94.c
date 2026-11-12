extern void *gCarList;
extern u8 *gRecords;
static inline u8 getRecordField44(u8 *rec)
{
  return rec[0x44];
}

/* Updates a car's standing against the others in gCarList: when another car shares this
 * car's id, it reads this car's record entry (rows of 40 bytes) and sets the car's
 * position fields, clamping the result at zero. */
void func_8003ED94(void *arg0)
{
  u8 *car;
  void *other;
  void *info;
  u8 *recBase;
  s32 tmp;
  u8 recIdx;
  s32 targetId;
  s32 ff;
  car = arg0;
  other = *((void **) ((*((u8 **) (car + 0xA8))) + 0x24)); info=other;
  info = *((void **) (((u8 *) info) + 0x6C));
  targetId = *((s32 *) (((u8 *) info) + 8));
  recIdx = 0;
  if ((*((s32 *) (((u8 *) info) + 0x20))) == 0)
  {
    other = *((void **) gCarList);
    ff = 255;
    while (other)
    {
      *((s32 *) (car + 0x80)) &= ~4;
      car[0x92] = (car[0x91] = (car[0x90] = ff));
      if ((*((u16 *) (car + 0x76))) == (*((s32 *) ((*((u8 **) (((u8 *) other) + 0x6C))) + 8))))
      {
        recBase = gRecords;
        tmp = *((u8 *) (recBase + recIdx + 0x32));
        recBase += tmp * 40;
        recBase += *((u16 *) (car + 0x78));
        tmp = getRecordField44(recBase);
        if (tmp >= 65)
        {
          *((s16 *) (car + 0x7A)) = getRecordField44(recBase) - 65;
        }
        else
        {
          *((s16 *) (car + 0x7A)) = getRecordField44(recBase) - 22;
        }
        if ((*((s16 *) (car + 0x7A))) < 0)
        {
          *((s16 *) (car + 0x7A)) = 0;
        }
        if (targetId == (*((u16 *) (car + 0x76))))
        {
          car[0x90] = 254;
          car[0x91] = 213;
          car[0x92] = 30;
        }
        break;
      }
      other = *((void **) (((u8 *) other) + 4));
      do
      {
      }
      while (0);
      recIdx++;
    }

  }
}
