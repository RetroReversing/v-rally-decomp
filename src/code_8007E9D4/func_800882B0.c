#include "snapshot29_0433f7af8f6d.h"

s32 func_80087910(s32 *, s32);
s32 func_80088514(s32 *);
s32 func_8008871C(s32 *, s32);
s32 func_80088AA4(s32 *, s32);
s32 func_80088B30(s32 *);
s32 func_80088BF4(s32 *);
s32 func_80088D10(s32 *);
f32 func_80088F1C(s32 *);
f32 func_80088F9C(s32 *);
s32 func_80088FF4(s32 *, s32, f32);
s32 func_8008910C(s32 *, s32);
s32 alSynStopVoice(void *, s32);
extern s32 D_800AE850;
extern s32 D_800C02AE;
s32 func_800882B0(void)
{
  volatile s32 pad[2];
  f32 var_fs0;
  s32 *var_s1;
  s32 temp_v0;
  s32 var_s2;
  s32 var_s3;
  s32 minus_one;
  u32 temp_v1;
  s16 *var_s0;
  var_s1 = *((s32 **) 0x800B68F0);
  var_s2 = 0;
  if ((*((s32 *) (((char *) (&D_800C02AE)) + 0x757E))) > 0)
  {
    minus_one = -1;
    var_s0 = (s16 *) (((u8 *) var_s1) + 0xA2);
    var_s3 = 0;
    loop_start:
    {
      if ((*var_s1) != 0)
      {
        if ((*((s32 *) (((char *) var_s0) + (-0x9E)))) != 0)
        {
          func_80088AA4(var_s1, var_s2);
        }
        temp_v1 = (*((u32 *) (((char *) var_s0) + (-0x9A)))) + (*((u16 *) (((char *) var_s0) + (-0xE))));
        *((u32 *) (((char *) var_s0) + (-0x9A))) = temp_v1;
        if ((*((u16 *) (((char *) var_s0) + (-0x10)))) != 0x7FFF)
        {
          if (((u32) (*((u32 *) (((char *) var_s0) + (-0x6A))))) < temp_v1)
          {
            loop_7:
            if ((*var_s1) != 0)
            {
              func_8008871C(var_s1, var_s2);
              if (((u32) (*((u32 *) (((char *) var_s0) + (-0x6A))))) >= ((u32) (*((u32 *) (((char *) var_s0) + (-0x9A))))))
              {
                goto block_9;
              }
              goto loop_7;
            }

          }
          else
          {
            block_9:
            if ((*var_s1) != 0)
            {
              goto block_10;
            }

          }
        }
        else
        {
          block_10:
          if (((*((s32 *) (((char *) var_s0) + (-0x6E)))) != 0) && (((u32) (*((u32 *) (((char *) var_s0) + (-0x8E))))) < ((u32) (*((u32 *) (((char *) var_s0) + (-0x9A)))))))
          {
            func_80088B30(var_s1);
          }

          if (((*((s32 *) (((char *) var_s0) + (-0x72)))) != 0) && (((u32) (*((u32 *) (((char *) var_s0) + (-0x8E))))) < ((u32) (*((u32 *) (((char *) var_s0) + (-0x9A)))))))
          {
            func_80088BF4(var_s1);
          }
          temp_v0 = *((s32 *) (((char *) var_s0) + (-0x96)));
          if ((temp_v0 != minus_one) && ((*((s32 *) (((char *) var_s0) + (-0x96))) = --temp_v0, temp_v0 == minus_one)))
          {
            *var_s1 = func_80087910(var_s1, 0);
            if ((*((u8 *) (((char *) var_s0) + 0x1F))) != 0)
            {
              *((u8 *) (((char *) var_s0) + 0x1F)) = 0U;
              alSynStopVoice(((u8 *) (&D_800AE850)) + 0x2304, (*((s32 *) (((char *) (&D_800C02AE)) + 0x7576))) + var_s3);
              goto block_20;
            }
          }
          else
          {
            block_20:
            if ((*((u8 *) (((char *) var_s0) + 0x1F))) != 0)
            {
              if ((*((u8 *) (((char *) var_s0) + 0x19))) != 0)
              {
                func_80088D10(var_s1);
              }
              if (((*((u8 *) (((char *) var_s0) + 0x2A))) != 0) && (((u32) (*((u32 *) (((char *) var_s0) + (-0x16))))) < ((u32) (*((u32 *) (((char *) var_s0) + (-0x9A)))))))
              {
                func_80088514(var_s1);
              }
              var_fs0 = *((f32 *) (((char *) var_s0) + (-0x76)));
              if ((*((u8 *) (((char *) var_s0) + 0x2B))) != 0)
              {
                var_fs0 += func_80088F1C(var_s1);
              }
              if ((*((u8 *) (((char *) var_s0) + 0x24))) != 0)
              {
                var_fs0 += func_80088F9C(var_s1);
              }
              if ((*((s32 *) (((char *) var_s0) + (-0x9E)))) == 0)
              {
                func_80088FF4(var_s1, var_s2, var_fs0);
                func_8008910C(var_s1, var_s2);
              }
            }

          }
          *var_s0 = (s16) (((u32) ((*((u32 *) (((char *) var_s0) + (-0x9A)))) - (*((s32 *) (((char *) var_s0) + (-0x66)))))) >> 8);
        }
      }
      var_s3 += 0x1C;
      var_s2 += 1;
      var_s0 += 0x9A;
      var_s1 = (s32 *) (((u8 *) var_s1) + 0x134);
    }

    if (var_s2 < (*((s32 *) (((char *) (&D_800C02AE)) + 0x757E))))
    {
      goto loop_start;
    }
  }
  return *((s32 *) (((char *) (&D_800AE850)) + 0x7420));
}
