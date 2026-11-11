extern u8 gWorkSlots[];
void func_80058E28();
void func_8005914C();
s32 workSlotInit();

/* Initialises the five 0x24-byte work slots in gWorkSlots, each with the two callbacks. */
void workSlotsInitAll(void)
{
  u8 i;

  for (i = 0; i < 5; i++) {
    workSlotInit(gWorkSlots + i * 0x24, func_80058E28, func_8005914C);
  }
}
