s32 init_car_from_record();
extern char gStreamState[];
static inline char *inline_fn(int arg0)
{
  return gStreamState + arg0;
}

/* Initialises a car from the stream's record table. If the stream object's +0x1A value is 1,
 * the slot is 1 when the car's +0x2C value is 2 or 3, else 0. Otherwise (or when the +0x1A
 * test fails) the slot is the car's +0x2F byte. The record for that slot (at 0x44 +
 * record_index * 0x28) is passed to init_car_from_record. */
void car_init_from_stream_record(void *car)
{
  s32 temp_v1;
  u8 slot;
  int slotMask;
  slot = 0;
  slotMask = 0xFF;
  if ((*((u16 *) (((char *) (*((void **) (gStreamState + 0x32F2)))) - -0x1E))) == 0)
  {
    if ((*((u16 *) (((char *) (*((void **) inline_fn(0x32F2)))) + 0x1A))) == 1)
    {
      temp_v1 = *((s32 *) (((char *) (*((void **) (((char *) car) + 0x48)))) + 0x2C));
      if (temp_v1 >= 0)
      {
        if (temp_v1 >= 2)
        {
          slot = temp_v1 < 4;
        }
      }
    }
    else
    {
      goto block_5;
    }
  }
  else
  {
    block_5:
    slot = *((u8 *) (((char *) (*((void **) (((char *) car) + 0x48)))) + 0x2F));

  }
  init_car_from_record(car, (*((void **) (gStreamState + 0x32F2))) + (((*((u8 *) (((char *) ((*((void **) (gStreamState + 0x32F2))) + (slot & slotMask))) + 0x32))) * 0x28) + 0x44));
}
