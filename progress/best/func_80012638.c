extern int D_800AE004;
s32 func_8001FEE8();
s32 func_80042290();
u64 osGetTime();
s32 func_80098090();
s32 func_800980C4();
extern u8 D_8009BA34;
extern s32 D_8009D538;
extern char D_800A73E0[];
extern char D_800C02AE[];
typedef struct 
{
  s32 x;
  s32 y;
  s32 z;
} Vec;
typedef struct 
{
  u8 p0[0x20];
  u16 flags;
  u8 p22[2];
  void *node;
  u8 p28[0xe0];
  s32 f108;
  u8 p10c[8];
  f32 f114;
  f32 f118;
  f32 f11c;
  f32 f120;
  f32 f124;
  f32 f128;
  f32 f12c;
  s32 f130;
  f32 f134;
  s32 f138;
} Cam;
void func_80012638(void *arg0)
{
  Cam *cam;
  s32 delta[3];
  Vec pos;
  s16 temp_v0_2;
  s32 temp_a0;
  s32 temp_a1;
  s32 temp_a2;
  s32 temp_t5;
  s32 temp_v0_4;
  s32 var_t0;
  s16 var_a3;
  s32 var_v0;
  s32 var_v0_2;
  u32 temp_a0_2;
  u32 var_t1;
  void *temp_a0_3;
  void *temp_s3;
  void *temp_t4;
  void *temp_v0;
  void *temp_v0_3;
  void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v0_7;
  void *temp_v0_8;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  void *var_a1;
  void *var_a2;
  void *var_s0;
  void *var_s1;
  func_800980C4((u32) osGetTime());
  cam = *((Cam **) (D_800C02AE + 0x7cd6));
  var_s1 = NULL;
  cam->f130 = 0;
  cam->f134 = 100.0f;
  cam->f138 = 0;
  cam->f114 = 1.0f;
  if (((!(D_8009D538 & 2)) && (D_8009BA34 == 0)) && (D_800AE004 != 0))
  {
    temp_s3 = cam->node;
    temp_v0 = *((void **) (((char *) temp_s3) + 0x58));
    pos = *((Vec *) (((char *) temp_v0) + 0xc));
    temp_t5 = func_8001FEE8(temp_s3);
    temp_t4 = (var_a2 = *((void **) (((char *) (*((void **) (((char *) temp_s3) + 0x8C)))) + 0x28)));
    var_s0 = NULL;
    temp_v1 = *((void **) (((char *) temp_t4) + 0x58));
    if (temp_v1 != NULL)
    {
      var_a2 = temp_v1;
    }
    var_t1 = 0x05F5E0FF;
    var_a3 = 0;
    do
    {
      temp_v0_3 = *((void **) (((char *) var_a2) + 0x7C));
      var_t0 = 0;
      if (temp_v0_3 != NULL)
      {
        var_a1 = temp_v0_3;
        loop_8:
        if (var_a1 == (*((void **) (((char *) arg0) + 0x8C))))
        {
          var_t0 = 1;
        }

        delta[0] = pos.x - (*((s32 *) (((char *) var_a1) + 0xC)));
        delta[2] = pos.z - (*((s32 *) (((char *) var_a1) + 0x14)));
        temp_a0_2 = ((delta[0] >> 4) * (delta[0] >> 4)) + ((delta[2] >> 4) * (delta[2] >> 4));
        if (var_t1 >= temp_a0_2)
        {
          var_t1 = temp_a0_2;
          var_s0 = *((void **) (((char *) var_a2) + 0x7C));
          var_s1 = var_a2;
        }
        temp_v0_5 = *((void **) (((char *) var_a2) + 0x7C));
        temp_v1_2 = *((void **) (((char *) temp_v0_5) + 0x24));
        if (temp_v0_5 != temp_v1_2)
        {
          var_a1 = *((void **) (((char *) var_a1) + 0x24));
          if (var_a1 != NULL)
          {
            goto loop_8;
          }
        }
        if (var_t0 != 0)
        {
          var_s0 = *((void **) (((char *) arg0) + 0x8C));
        }
      }
      temp_v0_6 = *((void **) (((char *) var_a2) + 0x5C));
      if (temp_v0_6 != NULL)
      {
        var_a2 = temp_v0_6;
      }
      temp_v0_2 = var_a3 + 1;
      var_a3 = temp_v0_2;
    }
    while (((s16) temp_v0_2) < 3);
    if (var_s0 != NULL)
    {
      if (((*((void **) (((char *) arg0) + 0x8C))) != var_s0) && (((u32) (*((u32 *) (((char *) arg0) + 0x88)))) >= 0x33U))
      {
        if (var_s1 == temp_t4)
        {
          temp_a0 = *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x60)))) + 0x28));
          if (((u32) ((*((u16 *) (((char *) var_a2) + 0x88))) - temp_a0)) < 10U)
          {
            temp_v0_7 = *((void **) (((char *) var_s1) + 0x5C));
            if (temp_v0_7 != NULL)
            {
              temp_v1_2 = *((void **) (((char *) temp_v0_7) + 0x7C));
              if (temp_v1_2 != NULL)
              {
                var_s0 = temp_v1_2;
                var_s1 = temp_v0_7;
              }
            }
          }
        }
        if (((temp_t5 >= 0x83) & (var_s1 != NULL)) && ((temp_a0_3 = *((void **) (((char *) var_s1) + 0x5C)), temp_a0_3 != NULL)))
        {
          var_v0_2 = var_s1 != NULL;
          if ((*((s16 *) (((char *) var_s1) + 8))) != 1)
          {
            temp_v0_8 = *((void **) (((char *) temp_a0_3) + 0x7C));
            if (temp_v0_8 != NULL)
            {
              var_s0 = temp_v0_8;
            }
            goto block_33;
          }
        }
        else
        {
          block_33:
          var_v0_2 = var_s1 != NULL;

        }
        if ((var_s1 != NULL) & (var_s0 != NULL))
        {
          var_a3 = func_80098090() % 6;
          while (var_a3 > 0)
          {
            temp_v1_3 = *((void **) (((char *) var_s0) + 0x24));
            var_s0 = temp_v1_3;
            if (temp_v1_3 == NULL)
            {
              var_s0 = *((void **) (((char *) var_s1) + 0x7C));
            }
            var_a3 -= 1;
          }

        }
        *((void **) (((char *) arg0) + 0x8C)) = var_s0;
        *((u32 *) (((char *) arg0) + 0x88)) = 0U;
      }
      else
      {
        *((u32 *) (((char *) arg0) + 0x88)) = (u32) ((*((u32 *) (((char *) arg0) + 0x88))) + 1);
      }
      cam = *((Cam **) (D_800C02AE + 0x7cd6));
      cam->flags = (u16) (cam->flags & 0xFF77);
      cam->f118 = (f32) (*((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x8C)))) + 0xC)));
      cam->f11c = (f32) (*((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x8C)))) + 0x10)));
      temp_v1_3 = (char *) (*((void **) (((char *) arg0) + 0x8C)));
      cam->f120 = (f32) (*((s32 *) (temp_v1_3 + 0x14)));
      cam->f124 = (f32) pos.x;
      cam->f128 = (f32) pos.y;
      cam->f12c = (f32) pos.z;
      cam->f108 = 0;
      if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE))) == 1)
      {
        cam->f114 = 0.5f;
      }
      else
      {
        cam->f114 = 1.0f;
      }
    }
  }
  func_80042290(*((void **) (D_800C02AE + 0x7CD6)));
}

