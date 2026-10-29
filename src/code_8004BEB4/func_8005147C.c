#include "snapshot29_0433f7af8f6d.h"

extern s32 D_800A1234;
extern s32 D_800AE850;
extern s32 D_800C02AE;
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
  if ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x1E))) == 0)
  {
    if ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x1A))) == 1)
    {
      temp_v1 = *(*((s32 **) (((char *) arg0) + 0x48)));
      if (temp_v1 < 5)
      {
        __repair_addr = (char *) (D_800A1234 + (temp_v1 * 0x44));
        *((s16 *) (((char *) __repair_addr) + 0xA)) = 1;
        temp_v0 = D_800A1234 + ((*(*((s32 **) (((char *) arg0) + 0x48)))) * 0x44);
        *((u16 *) (((char *) temp_v0) + 8)) = (u16) ((*((u16 *) (((char *) temp_v0) + 8))) & 0xFDFF);
        new_var = ((char *) arg0) + 0x48;
        temp_v0_2 = ((char *) (D_800A1234 + ((*(*((s32 **) new_var))) * 0x44))) + 0xC;
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
    if (((*((s32 *) (((char *) (&D_800AE850)) + 0x2410))) & 0x0200FFFF) != 0x02000001)
    {
      var_a0 = *(*((void ***) (((char *) (&D_800AE850)) + 0x73F0)));
      if (var_a0 != NULL)
      {
        base = D_800A1234;
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
