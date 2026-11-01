#define F(e,t,o) (*(t*)((u8*)(e)+(o)))
s32 func_8007F4E4(s32, s32, s32);
s32 func_8007F6E0(s32);
s32 func_8007F73C(s32, s32);
void func_80085C58(void);
void func_80086370(s32);
void func_800863B0(s32, u8);
s32 osContStartQuery(void *);
s32 osContGetQuery(void *);
s32 osContStartReadData(void *);
s32 osContGetReadData(void *);
extern void *D_800A1B70;
extern s32 D_800AE850;
void func_80085D90(void)
{
  void *temp_s5;
  s32 temp_v0_2;
  s32 temp_s6;
  s32 temp_s0;
  s32 var_s1;
  s32 var_s3;
  s32 two;
  s32 temp_v1_2;
  u16 temp_a1;
  u16 temp_v1;
  void *temp_a0;
  void *temp_a1_2;
  void *temp_a2;
  void *temp_v0;
  void *temp_v1_3;
  var_s3 = 0;
  var_s1 = func_8007F4E4(4, 0, 8);
  temp_s6 = var_s1;
  temp_s5 = (u8 *) (&D_800AE850);
  temp_s5 = temp_s5 + 0x5A38;
  two = 2;
  *((u8 *) (((u8 *) D_800A1B70) + 0x39C)) = (u8) ((*((u8 *) (((u8 *) D_800A1B70) + 0x39C))) | 1);
  loop:
  func_8007F6E0(temp_s6);

  if (!((*((u8 *) (((u8 *) D_800A1B70) + 0x39C))) & 1))
  {
    goto loop;
  }
  osContStartReadData(temp_s5);
  func_8007F73C(0, 3);
  osContGetReadData(((u8 *) D_800A1B70) + 0x1C);
  osContStartQuery(temp_s5);
  func_8007F73C(0, 3);
  osContGetQuery(((u8 *) D_800A1B70) + 0xC);
  temp_a0 = D_800A1B70;
  for (var_s1 = 0; var_s1 < (*((s32 *) (((u8 *) temp_a0) + 4))); var_s1++)
  {
    temp_a2 = (void *) ((var_s1 * 4) + ((s32) temp_a0));
    temp_a1 = *(*((u16 **) (((u8 *) temp_a2) + 0x34)));
    temp_v0 = (void *) (((*((u8 *) (((u8 *) (*((void **) (((u8 *) temp_a2) + 0x38C)))) + 3))) * 2) + ((s32) temp_a0));
    *((u16 *) (((u8 *) temp_v0) + 0x44)) = temp_a1;
    temp_v1 = (*((u16 *) (((u8 *) temp_v0) + 0x4C))) | (~temp_a1);
    *((u16 *) (((u8 *) temp_v0) + 0x4C)) = temp_v1;
    *((s16 *) (((u8 *) temp_v0) + 0x54)) = (s16) ((*((u16 *) (((u8 *) temp_v0) + 0x44))) & temp_v1);
    temp_a1_2 = *((void **) (((u8 *) temp_a2) + 0x38C));
    temp_v1_2 = *((s32 *) (((u8 *) temp_a1_2) + 4));
    if (temp_v1_2 == 1)
    {
      temp_s0 = *((s32 *) (((u8 *) temp_a1_2) + 8));
      if (temp_s0 == temp_v1_2)
      {
        temp_v0_2 = *((s32 *) (((u8 *) temp_a1_2) + 0x10));
        *((s32 *) (((u8 *) temp_a1_2) + 0x10)) = temp_v0_2 + 1;
        if ((*((s32 *) (((u8 *) temp_a1_2) + 0xC))) == temp_v0_2)
        {
          func_80086370(*((s32 *) (((u8 *) (*((void **) (((u8 *) temp_a2) + 0x38C)))) + 0)));
          *((s32 *) (((u8 *) (*((void **) (((u8 *) (((u8 *) D_800A1B70) + (var_s1 * 4))) + 0x38C)))) + 0x10)) = temp_s0;
        }
        else
        {
          temp_v1_3 = *((void **) (((u8 *) temp_a2) + 0x38C));
          if ((*((s32 *) (((u8 *) temp_v1_3) + 0x10))) == two)
          {
            func_800863B0(*((s32 *) (((u8 *) temp_v1_3) + 0)), *((u8 *) (((u8 *) temp_v1_3) + 0x14)));
          }
        }
      }
      else
        if ((*((volatile s32 *) (((u8 *) temp_a1_2) + 8))) == 0)
      {
        func_800863B0(*((s32 *) (((u8 *) temp_a1_2) + 0)), *((u8 *) (((u8 *) temp_a1_2) + 0x14)));
        *((s32 *) (((u8 *) (*((void **) (((u8 *) (((u8 *) D_800A1B70) + (var_s1 * 4))) + 0x38C)))) + 8)) = two;
      }
    }
    temp_a0 = D_800A1B70;
  }

  var_s3++;
  if ((var_s3 & 0xFF) != 0x1E)
  {
    goto loop;
  }
  var_s3 = 0;
  func_80085C58();
  goto loop;
}

