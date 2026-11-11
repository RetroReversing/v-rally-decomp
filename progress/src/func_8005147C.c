/* Car table entry, 0x44 bytes each. Offsets from the matched code. */
typedef struct CarEntry {
  u8 pad00[8];
  u16 flags;
  s16 active;
  s16 unk0C;
  u8 pad0E[0x44 - 0x0E];
} CarEntry;

extern s32 gCarEntries;
extern s32 gOrderState;
extern s32 gStreamState;

/* Updates the car table for the object list at gOrderState. Each object's car index
   (at obj+0x48, a pointer to an s32) selects a CarEntry. The first branch handles the
   player's object when the first-player flag is clear; cars with index below 5 get
   active = 1, the 0x0200 flag cleared, and the field at 0x0C zeroed. */
void func_8005147C(void *arg0)
{
  char *__repair_addr;
  char *new_var2;
  s32 temp_v1;
  s32 temp_v1_2;
  char *new_var;
  void *temp_v0;
  void *temp_v0_2;
  void *var_a0;
  s32 base;
  if ((*((u16 *) (((char *) (*((void **) (((char *) (&gStreamState)) + 0x32F2)))) + 0x1E))) == 0)
  {
    if ((*((u16 *) (((char *) (*((void **) (((char *) (&gStreamState)) + 0x32F2)))) + 0x1A))) == 1)
    {
      temp_v1 = *(*((s32 **) (((char *) arg0) + 0x48)));
      if (temp_v1 < 5)
      {
        __repair_addr = (char *) (gCarEntries + (temp_v1 * 0x44));
        *((s16 *) (((char *) __repair_addr) + 0xA)) = 1;
        temp_v0 = gCarEntries + ((*(*((s32 **) (((char *) arg0) + 0x48)))) * 0x44);
        *((u16 *) (((char *) temp_v0) + 8)) = (u16) ((*((u16 *) (((char *) temp_v0) + 8))) & 0xFDFF);
        new_var = ((char *) arg0) + 0x48;
        temp_v0_2 = ((char *) (gCarEntries + ((*(*((s32 **) new_var))) * 0x44))) + 0xC;
        *((s16 *) temp_v0_2) = 0;
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
    if (((*((s32 *) (((char *) (&gOrderState)) + 0x2410))) & 0x0200FFFF) != 0x02000001)
    {
      var_a0 = *(*((void ***) (((char *) (&gOrderState)) + 0x73F0)));
      if (var_a0 != NULL)
      {
        base = gCarEntries;
        do
        {
          temp_v1_2 = *(*((s32 **) (((char *) var_a0) + 0x48)));
          if (temp_v1_2 < 5)
          {
            new_var2 = ((char *) (base + (temp_v1_2 * 0x44))) + 0xA;
            *((s16 *) new_var2) = 1;
            temp_v0_2 = base + ((*(*((s32 **) (((char *) var_a0) + 0x48)))) * 0x44);
            *((u16 *) (((char *) temp_v0_2) + 8)) = (u16) ((*((u16 *) (((char *) temp_v0_2) + 8))) & 0xFDFF);
            { char *__repair_store_address = (char *)base; __repair_store_address += ((*(*((s32 **) (((char *) var_a0) + 0x48)))) * 0x44); *(s16 *)(__repair_store_address + 0xC) = 0; }
          }
          var_a0 = *((void **) (((char *) var_a0) + 4));
        }
        while (var_a0 != NULL);
      }
    }

  }
}
