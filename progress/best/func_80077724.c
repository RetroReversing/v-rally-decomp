extern u32 D_800AFA6C;
s32 func_80005500(s32, s32);
s32 func_800056FC(s32);
void *func_80006008(s32);
s32 func_80006014(s32, s32);
s32 func_800061FC(s32, s32);
s32 func_8000C244(s32, s32, s16, s32, s32 *, s32);
s32 func_8000C9B0(void *, void *, s32, f32, s32);
s32 func_8000E8B8(s32);
s32 func_8001BD1C();
void *func_8004240C(s32);
s32 *func_80057918(s32, s32);
s32 func_80073108(s32, s16, s32, s32, s32);
s32 func_80078724(s32);
s32 func_80084BF0(s32);
s32 func_80085778(s32, s32);
s32 guMtxF2L(s32 *, s32);
s32 guMtxIdent(void *);
void guOrthoF(void *, f32, f32, f32, f32, f32, f32, f32);
extern char D_800C8380[];
extern char D_800C8370[];
extern void *D_800A1234;
extern s32 D_800A1798;
extern u8 D_800A17E8;
extern s32 D_800A1814;
extern s32 D_800A5EAC;
extern s32 D_800AE850;
extern s32 D_800C02AE;
s32 func_80077724(void)
{
  f32 sp20[4][4];
  f32 scale;
  s32 *var_a1;
  s32 *var_a1_4;
  short var_a1_2;
  s32 var_a1_3;
  s32 var_a1_5;
  s32 var_a1_6;
  s16 temp_s0_3;
  s16 temp_s0_4;
  s16 temp_s0_5;
  s16 temp_s0_6;
  s16 temp_s0_7;
  s32 temp_a0;
  s32 temp_a1;
  s32 temp_s0_2;
  s32 *new_var4;
  s32 temp_v0_10;
  int new_var2;
  s32 temp_v0_2;
  s32 temp_v0_5;
  char *new_var;
  s32 temp_v0_6;
  s32 temp_v0_7;
  s32 temp_v0_8;
  s32 temp_v0_9;
  s32 var_a0_2;
  s32 var_a0_3;
  s32 var_a0_5;
  s32 var_a0_6;
  s32 var_s1;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  long long var_v0_5;
  s32 var_v0_6;
  char *new_var3;
  void *temp_s0;
  void *temp_s2;
  void *temp_v0;
  void *temp_v0_3;
  void *temp_v0_4;
  void *var_a0;
  void *var_a0_4;
  temp_s2 = ((char *) (&D_800C02AE)) + 0x7F92;
  var_s1 = 0x0;
  if ((*((u16 *) (((char *) (&D_800C02AE)) + 0x7F92))) & 0x800)
  {
    goto block_37;
  }
  {
    temp_v0 = func_8004240C(4);
    temp_a0 = *((s32 *) (((char *) temp_v0) + 0x178));
    *((void **) (((char *) (&D_800C02AE)) + 0x7CD6)) = temp_v0;
    func_8000E8B8(temp_a0);
    temp_a0 = *((s32 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x7CD6)))) + 0x178));
    func_80005500(temp_a0, temp_a0 + 8);
    temp_s0 = D_800C8380;
    guMtxIdent(temp_s0);
    temp_v0_2 = func_800056FC(*((s32 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x7CD6)))) + 0x178)));
    temp_v0_3 = func_80006008(temp_v0_2);
    *((s32 *) (((char *) temp_v0_3) + 0)) = 0xDA380003;
    *((void **) (((char *) temp_v0_3) + 4)) = temp_s0;
    func_80006014(temp_v0_2, temp_v0_3 + 8);
    temp_s0_2 = func_8001BD1C();
    guOrthoF(sp20, 0.0f, 320.0f, 240.0f, 0.0f, -1.0f, 10.0f, 1.0f);
    scale = 1.0f;
    guMtxF2L(&sp20, temp_s0_2);
    func_800061FC(temp_v0_2, temp_s0_2);
    temp_v0_4 = func_80006008(temp_v0_2);
    *((s32 *) (((char *) temp_v0_4) + 0)) = 0xDE000000;
    *((s32 **) (((char *) temp_v0_4) + 4)) = &D_800A1798;
    func_80006014(temp_v0_2, temp_v0_4 + 8);
    if ((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F4E))) != 0)
    {
      if (D_800AFA6C == (*((u16 *) (((char *) (&D_800A1814)) + ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x22))) * 2)))))
      {
        D_800AFA6C = (u32) (D_800AFA6C - 1);
        temp_v0_5 = func_80084BF0(0);
        if (temp_v0_5 & 0x8000)
        {
          func_80085778(0, temp_v0_5);
          D_800AFA6C = (u32) (D_800AFA6C + 1);
        }
        if ((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F51))) == 2)
        {
          temp_v0_6 = func_80084BF0(1);
          if (temp_v0_6 & 0x8000)
          {
            func_80085778(1, temp_v0_6);
            D_800AFA6C = (u32) (D_800AFA6C + 1);
          }
        }
        func_80078724(temp_v0_2);
        temp_s0_3 = 0x131 - (D_800A17E8 + func_8000C9B0(((char *) (&D_800C02AE)) + 0x7F5E, &D_800A5EAC, 1, scale, 1));
        func_80073108(temp_v0_2, temp_s0_3, 0xDA, *((s32 *) (((char *) (&D_800C02AE)) + 0x103B6)), 0);
        func_8000C244(*((s32 *) (((char *) (&D_800C02AE)) + 0x7F5E)), temp_v0_2, (s16) (temp_s0_3 + D_800A17E8), 0xDC, &D_800A5EAC, 1);
        return 0;
      }
      if ((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F4F))) != 5)
      {
        if (((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F4F))) ^ 2) == 0)
        {
          var_a0 = temp_s2;
          var_a0 = var_a0 - 0x34;
          var_a1 = func_80057918(*((s32 *) (((char *) (&D_800C02AE)) + 0x807A)), 0xD6);
        }
        else
        {
          var_a0 = temp_s2 - 0x34;
          var_a1 = func_80057918(*((s32 *) (((char *) (&D_800C02AE)) + 0x807A)), 0xD7);
        }
      }
      else
      {
        var_s1 = 1;
        if (((u8) (*((u8 *) (((char *) (&D_800C02AE)) + 0x7F50)))) < 8U)
        {
          var_a0_2 = 0;
          var_v0 = 0 & 0xFF;
          do
          {
            var_a0_2 += 1;
            var_s1 &= -((*((u16 *) ((((char *) (&D_800AE850)) + 0x7DC0) + (var_v0 * 2)))) != 0);
            var_v0 = var_a0_2 & 0xFF;
          }
          while ((((u32) (var_a0_2 & 0xFF)) < 8U) & (var_s1 & 0xFF));
          var_v0_2 = var_s1 & 0xFF;
        }
        else
        {
          ;
          var_v0_3 = 8 & 0xFF;
          do
          {
            var_a0_3 += 1;
            var_s1 &= -((*((u16 *) ((((char *) (&D_800AE850)) + 0x7DC0) + (var_v0_3 * 2)))) != 0);
            var_v0_3 = var_a0_3 & 0xFF;
          }
          while ((((u32) (8 & 0xFF)) < 0xCU) & (var_s1 & 0xFF));
          var_v0_2 = var_s1 & 0xFF;
        }
        var_a1_2 = 0xD7;
        if (var_v0_2 == 0)
        {
          var_a1_2 = 0xD5;
        }
        var_a0 = ((char *) (&D_800C02AE)) + 0x7F5E;
        var_a1 = func_80057918(*((s32 *) (((char *) (&D_800C02AE)) + 0x807A)), var_a1_2);
      }
      temp_a1 = (D_800A17E8 + func_8000C9B0(var_a0, var_a1, 1, scale, 1)) + 0x15;
      if (((u32) D_800AFA6C) < ((u16) (*((u16 *) (((char *) (&D_800A1814)) + ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x22))) * 2))))))
      {
        temp_s0_4 = 0x140 - temp_a1;
        func_80073108(temp_v0_2, temp_s0_4, 0xDA, *((s32 *) (((char *) (&D_800C02AE)) + 0x103B6)), 0);
        temp_s0_5 = temp_s0_4 + D_800A17E8;
        if ((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F4F))) != 5)
        {
          var_a1_3 = 0xD6;
          if (((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F4F))) ^ 2) == 0)
          {
          }
          else
          {
            goto block_30;
          }
        }
        else
        {
          var_a1_3 = 0xD5;
          if (!(var_s1 & 0xFF))
          {
          }
          else
          {
            block_30:
            var_a1_3 = 0xD7;

          }
        }
        func_8000C244(*((s32 *) (((char *) (&D_800C02AE)) + 0x7F5E)), temp_v0_2, temp_s0_5, 0xDC, func_80057918(*((s32 *) (((char *) (&D_800C02AE)) + 0x807A)), var_a1_3), 1);
      }
      temp_v0_7 = func_80084BF0(0);
      if (temp_v0_7 & 0x8000)
      {
        func_80085778(0, temp_v0_7);
        *((s8 *) (((char *) (&D_800C02AE)) + 0x805A)) = 1;
      }
      if ((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F51))) == 2)
      {
        temp_v0_8 = func_80084BF0(1);
        if (temp_v0_8 & 0x8000)
        {
          func_80085778(1, temp_v0_8);
          *((s8 *) (((char *) (&D_800C02AE)) + 0x805A)) = 1;
        }
      }
      goto block_37;
    }
    goto later;
    block_37:
    if ((*((u16 *) (((char *) D_800A1234) + 0xC))) == (*((u16 *) (((char *) D_800A1234) + 0xE))))
    {
      *((s8 *) (((char *) (&D_800C02AE)) + 0x805A)) = 1;
    }

    return 1;
    new_var = ((char *) (&D_800C02AE)) + 0x103B6;
    later:
    if (((u32) D_800AFA6C) >= 0x19U)
    {
      func_80078724(temp_v0_2);
      var_a0_5 = 5;
      if ((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F4F))) != var_a0_5)
      {
        if (((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F4F))) ^ 2) == 0)
        {
          var_a0_4 = temp_s2 - 0x34;
          var_a1_4 = func_80057918(*((s32 *) (((char *) (&D_800C02AE)) + 0x807A)), 0xD6);
        }
        else
        {
          var_a0_4 = temp_s2 - 0x34;
          var_a1_4 = func_80057918(*((s32 *) (((char *) (&D_800C02AE)) + 0x807A)), 0xD7);
        }
      }
      else
      {
        var_s1 = 1;
        if (((u8) (*((u8 *) (((char *) (&D_800C02AE)) + 0x7F50)))) < 8U)
        {
          var_a0_5 = 0;
          var_v0_4 = 0 & 0xFF;
          do
          {
            var_a0_5 += 1;
            var_s1 &= -((*((u16 *) ((((char *) (&D_800AE850)) + 0x7DC0) + (var_v0_4 * 2)))) != 0);
            var_v0_4 = var_a0_5 & 0xFF;
          }
          while ((((u32) (var_a0_5 & 0xFF)) < 8U) & (var_s1 & 0xFF));
          var_v0_5 = var_s1 & 0xFF;
        }
        else
        {
          var_a0_6 = 8;
          var_v0_6 = 8 & 0xFF;
          do
          {
            var_a0_6 += 1;
            var_s1 &= -((*((u16 *) ((((char *) (&D_800AE850)) + 0x7DC0) + (var_v0_6 * 2)))) != 0);
            var_v0_6 = var_a0_6 & 0xFF;
          }
          while ((((u32) (var_a0_6 & 0xFF)) < 0xCU) & (var_s1 & 0xFF));
          var_v0_5 = var_s1 & 0xFF;
        }
        var_a1_5 = 0xD7;
        if (var_v0_5 == 0)
        {
          var_a1_5 = 0xD5;
        }
        var_a0_4 = ((char *) (&D_800C02AE)) + 0x7F5E;
        var_a1_4 = func_80057918(*((s32 *) (((char *) (&D_800C02AE)) + 0x807A)), var_a1_5);
      }
      temp_s0_6 = 0x140 - ((D_800A17E8 + func_8000C9B0(var_a0_4, var_a1_4, 1, scale, 1)) + 0x15);
      func_80073108(temp_v0_2, temp_s0_6, 0xDA, *((s32 *) new_var), 0);
      temp_s0_7 = temp_s0_6 + D_800A17E8;
      new_var2 = 0;
      new_var4 = (s32 *) (((char *) (&D_800C02AE)) + 0x807A);
      if ((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F4F))) != 5)
      {
        var_a1_6 = 0xD6;
        if (((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F4F))) ^ 2) == new_var2)
        {
        }
        else
        {
          goto block_62;
        }
      }
      else
      {
        var_a1_6 = 0xD5;
        if (!(var_s1 & 0xFF))
        {
        }
        else
        {
          block_62:
          var_a1_6 = 0xD7;

        }
      }
      new_var3 = (char *) D_800A1234;
      func_8000C244(*((s32 *) (((char *) (&D_800C02AE)) + 0x7F5E)), temp_v0_2, temp_s0_7, 0xDC, func_80057918(*new_var4, var_a1_6), 1);
      temp_v0_9 = func_80084BF0(0);
      if (temp_v0_9 & 0x8000)
      {
        func_80085778(0, temp_v0_9);
        *(((char *) (&D_800C02AE)) + 0x805A) = 1;
      }
      if ((*((u8 *) (((char *) (&D_800C02AE)) + 0x7F51))) == 2)
      {
        temp_v0_10 = func_80084BF0(1);
        if (temp_v0_10 & 0x8000)
        {
          func_80085778(1, temp_v0_10);
          *((s8 *) (((char *) (&D_800C02AE)) + 0x805A)) = 1;
        }
      }
      if ((*((u16 *) (new_var3 + 0xC))) == (*((u16 *) (((char *) D_800A1234) + 0xE))))
      {
        *((s8 *) (((char *) (&D_800C02AE)) + 0x805A)) = 1;
      }
    }

    return 0;
  }
}
