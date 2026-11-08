typedef struct { char pad[0x14]; void *commands; } CommandObject;
typedef struct { char pad[0x178]; s32 field; } ViewObject;
extern u32 D_800B6880;
extern s8 D_800C81FF;
extern void *D_800C35A0;
extern s32 D_800C81DC;
extern s32 D_800B7040;
extern s32 D_800C5D20;
extern s32 D_800C5D24;
extern s32 D_800C5D28;
extern s32 D_800C5D2C;
extern s32 D_800C5D30;
extern void *D_800C7F84;
extern s32 D_800AFA88;
extern s32 D_800D05D8;
extern void *D_800ADF80;
extern s32 D_800C3558;
extern s32 D_800C8328;
extern u8 D_800AFA5C;
extern u8 D_800C81FE;
extern u32 D_800B6600;
extern s32 D_800B5C60;
extern s32 D_800B0AE0;
extern s32 D_800C35C0;
extern s32 D_800C3504;
s32 func_80005500();
void *func_800056FC();
s32 func_80005948();
s32 func_80005ACC();
s32 func_80005C48();
s32 func_80005DEC();
void *func_80006008();
s32 func_80006014();
s32 func_800061FC();
s32 func_8000E8B8();
s32 func_8000E8FC();
s32 func_8000F49C();
void func_800131C0(s32);
s32 func_80013E60();
s32 func_80015780();
s32 func_8001BD1C();
s32 func_80022214();
s32 func_80022484();
s32 func_80041320();
s32 func_80041E0C();
s32 func_80041FF4();
s32 func_80042264();
void *func_8004240C();
s32 func_80042554();
s32 func_80047564();
s32 func_80047C78();
s32 func_8004C794();
s32 func_8004C7B8();
s32 func_80054E8C();
s32 func_80054F8C();
s32 func_8005508C();
s32 func_80057810();
s32 func_800578E0();
s32 func_80057998();
s32 func_80057AAC();
s32 func_8005B6A8();
s32 func_8005BB14();
s32 func_8006C99C();
s32 pack_tile_rows();
s32 func_8006DDD8();
s32 func_8006E33C();
s32 func_8006ECB4();
s32 func_8006F0E0();
s32 func_8006F75C();
s32 func_8007F4E4();
s32 func_8007F634();
s32 func_8007F6E0();
s32 func_80080440();
s32 func_80080478();
s32 func_800857C0(s32, s32);
s32 func_80089B70();
s32 func_80089B80();
s32 guMtxF2L(s32 *, s32);
s32 guMtxIdent(s32);
s32 guOrthoF(s32 *, f32, f32, f32, f32, f32, f32, f32);
s32 osSetThreadPri(s32, s32);
s32 func_80098290();
extern s32 D_8009B5A4;
extern void *D_8009B5A8;
extern u8 D_800A13B0;
extern u8 D_800A13B1;
extern u8 D_800A13B2;
extern char D_800A13C0[];
extern void *D_800A1468;
extern char D_800A14BC[];
extern s32 D_800A14C0;
extern u8 D_800A16D4;
extern char D_800A5268[];
extern char D_800A5274[];
extern char D_800A527C[];
extern char D_800A5284[];
extern char D_800A528C[];
extern char D_800A5294[];
extern char D_800A529C[];
extern char D_800A52A8[];
extern char D_800A52B4[];
extern char D_800A52C0[];
extern char D_800A52CC[];
extern char D_800A52D8[];
extern char D_800A52E4[];
extern u8 D_800A73E0[];
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
static inline static u32 inline_fn(u32 arg0)
{
  return (u32) arg0;
}

typedef struct { unsigned char pad_0[14]; unsigned short field_E; unsigned char pad_10[14]; unsigned short field_1E; unsigned char pad_20[12]; unsigned short field_2C; unsigned char pad_2E[4]; unsigned char field_32; unsigned char field_33; unsigned char pad_34[4]; unsigned short field_38; } __repair_record_D_800C35A0;
void func_8005A790(void)
{
  f32 sp20[4][4];
  s32 *var_s1;
  u8 temp_a0_3;
  s32 temp_s1;
  void *buffer;
  s32 temp_s4;
  s32 temp_s5;
  s32 temp_v0_12;
  s32 temp_v0_15;
  s32 var_a0;
  s32 var_a0_2;
  u8 var_a0_3;
  s32 var_a0_4;
  u8 var_a1;
  s32 var_a2;
  s32 var_s2;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  u8 var_v1;
  u16 temp_a0;
  u16 temp_a0_2;
  u16 temp_a0_4;
  u16 temp_v0_4;
  u16 temp_v0_5;
  u32 temp_s0;
  u32 temp_v1;
  s32 *new_var2;
  void *view;
  u8 temp_s0_4;
  void *temp_a3;
  s32 new_var;
  void *temp_s0_2;
  void *temp_v0;
  void *temp_v0_10;
  void *temp_v0_11;
  void *temp_v0_13;
  void *temp_v0_14;
  void *temp_v0_16;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_6;
  void *temp_v0_8;
  void *temp_v0_9;
  new_var2 = &D_800C3558;
  var_s1 = NULL;
  if ((D_800B6880 != 5) & (D_800B6880 != 0))
  {
    if (((u32) (D_800B6880 - 2)) >= 2U)
    {
      if (D_800B6880 != 6)
      {
        return;
      }
    }
  }
  {
    if (D_800B6880 == 6)
    {
      D_800C81FF = (s8) (*((u16 *) ((char *)D_800C35A0 + 14)));
      *((u16 *) ((char *)D_800C35A0 + 14)) = 1U;
      return;
    }
    temp_s5 = func_8007F4E4(6, 2, 1);
    D_800C81DC = func_8007F4E4(9, 2, 0x10);
    temp_s4 = func_8007F4E4(4, 0, 1);
    if (D_8009B5A8 == NULL)
    {
      if (D_8009B5A4 == 0)
      {
        func_8005BB14();
      }
    }
    func_80015780(1, 0, 0xF, 0xB4, 1, 0);
    var_s2 = 0;
    func_80089B70();
    D_800B7040 = func_80080440();
    func_8004C794();
    func_80047564();
    func_80041E0C();
    func_80041320();
    func_80042264();
    do
    {
      *((s32 *) (((var_s2 & 255) * 4) + (D_800C02AE + 0x5A72))) = 0;
      var_s2 += 1;
    }
    while (((u32) (var_s2 & 0xFF)) < 5U);
    D_800C5D20 = func_80041FF4(2, &D_800A5274);
    D_800C5D24 = func_80041FF4(2, &D_800A527C);
    D_800C5D28 = func_80041FF4(1, &D_800A5284);
    D_800C5D2C = func_80041FF4(1, &D_800A528C);
    D_800C5D30 = func_80041FF4(0, &D_800A5294);
    temp_v0 = func_8004240C(4);
    view = ((ViewObject *)temp_v0)->field;
    D_800C7F84 = temp_v0;
    D_800AFA88 = view;
    temp_v0_2 = func_8004240C(1);
    view = ((ViewObject *)temp_v0_2)->field;
    D_800C7F84 = temp_v0_2;
    D_800D05D8 = view;
    temp_v0_3 = func_8004240C(1);
    var_v0 = ((ViewObject *)temp_v0_3)->field;
    view = (void *) var_v0;
    D_800C7F84 = temp_v0_3;
    D_800ADF80 = view;
    if (D_800C3558 != 0)
    {
      var_a0 = ((s32 *) (&D_800A14BC))[*new_var2];
    
    D_800C8328 = func_80057810(var_a0);}
    else
    {
      var_a0 = D_800A14C0;
    
    D_800C8328 = func_80057810(var_a0);}
    func_80057998();
    *((s8 *) (((char *) D_800A1468) + 0x299)) = 0;
    *((s8 *) (((char *) D_800A1468) + 0x29D)) = 1;
    *((s8 *) (((char *) D_800A1468) + 0x298)) = 0;
    *((s8 *) (((char *) D_800A1468) + 0x29C)) = 1;
    *((s8 *) (((char *) D_800A1468) + 0x29B)) = 0;
    *((s8 *) (((char *) D_800A1468) + 0x29A)) = 0;
    *((s8 *) (((char *) D_800A1468) + 0x2BE)) = 0;
    if ((D_800A13B0 != 0) || ((D_800A13B1 | D_800A13B2) != 0))
    {
      D_800AFA5C = 0U;
      var_s1 = &D_800A529C;
    }
    else
    {
      temp_s0 = D_800B6880;
      switch (temp_s0)
      {
        case 5:
          func_8006E33C();
          var_s1 = &D_800A52A8;
          D_800AFA5C = 0U;
          if ((((__repair_record_D_800C35A0*)D_800C35A0)->field_1E) == 7)
        {
          var_s1 = &D_800A5268;
        }
          break;

        case 0:
          temp_a0 = ((__repair_record_D_800C35A0*)D_800C35A0)->field_1E;
          if ((temp_a0 != 0) & (temp_a0 < 5U))
        {
          D_800AFA5C = 1U;
          var_s1 = &D_800A52B4;
        }
        else
          if (temp_a0 == 5)
        {
          D_800AFA5C = 3U;
          var_s1 = &D_800A52C0;
        }
        else
          if (temp_a0 == 7)
        {
          var_s1 = &D_800A5268;
        }
          break;

        case 3:
          temp_a0_2 = ((__repair_record_D_800C35A0*)D_800C35A0)->field_1E;
          if ((temp_a0_2 != 0) & (temp_a0_2 < 5U))
        {
          func_8006ECB4();
          func_8006F75C();
          D_800AFA5C = 1U;
          var_s1 = &D_800A52CC;
        }
        else
        {
          if (temp_a0_2 == 5)
          {
            temp_a3 = D_800AE850 + 0x7DB0;
            var_a0_2 = 1;
            if (((u8) D_800C81FE) < 8U)
            {
              var_v1 = 0;
              do
              {
                var_a0_2 &= -((*((u16 *) (((char *) (((var_v1 & 255) * 2) + temp_a3)) + 0x10))) != 0);
                var_v1 += 1;
              }
              while (((u32) (var_v1 & 0xFF)) < 8U);
              if (var_a0_2 & 0xFF)
              {
                temp_v1 = *((u32 *)temp_a3);
                var_a0_3 = 0;
                if ((((u32) (*((u32 *) (((char *) temp_a3) + 4)))) < temp_v1) && (((u32) (*((u32 *) (((char *) temp_a3) + 8)))) < temp_v1))
                {
                  var_a0_3 = ((u32) (*((u32 *) (((char *) temp_a3) + 0xC)))) < temp_v1;
                }

                if ((*((u16 *) ((char *)D_800C35A0 + 14))) == 2)
                {
                  temp_v0_15 = *((u32 *) (((char *) temp_a3) + 4));
                  temp_v1 = *((u32 *) (((char *) temp_a3) + 8));
                  if (temp_v1 < (u32)temp_v0_15)
                  {
                    if (((u32) (*((u32 *) (((char *) temp_a3) + 0xC)))) < temp_v1)
                    {
                      var_a0_3 = 1;
                    }
                  }
                }
                if (var_a0_3 != 0)
                {
                  temp_v0_4 = ((__repair_record_D_800C35A0*)D_800C35A0)->field_38;
                  if (temp_v0_4 == 0)
                  {
                    ((__repair_record_D_800C35A0*)D_800C35A0)->field_38 = (u16) (temp_v0_4 + 1);
                  }
                }
                func_80054E8C();
                goto block_56;
              }
            }
            else
            {
              var_a2 = 1;
              var_a1 = 0;
              do
              {
                temp_v0_5 = *((u16 *) (((char *) (temp_a3 - (-((var_a1 & 0xFF) * 2)))) + 0x20));
                var_a1 += 1;
                var_a2 &= -(temp_v0_5 != 0);
                temp_a0_3 = var_a2 & 0xFF;
              }
              while ((((u32) (var_a1 & 0xFF)) < 4U) & (temp_a0_3 != 0));
              if (temp_a0_3 != 0)
              {
                func_80054F8C();
                block_56:
                func_8005508C();

                func_8006C99C();
                func_8006F75C();
              }
            }
          }
          D_800AFA5C = 3U;
          var_s1 = &D_800A52D8;
        }
          break;

        case 2:
          temp_a0_4 = ((__repair_record_D_800C35A0*)D_800C35A0)->field_1E;
          if (temp_a0_4 == 5)
        {
          D_800AFA5C = 3U;
          var_s1 = &D_800A52E4;
        }
        else
          if (temp_a0_4 == 0)
        {
          func_8006F0E0(((__repair_record_D_800C35A0*)D_800C35A0)->field_32);
          if ((*((u16 *) ((char *)D_800C35A0 + 14))) == temp_s0)
          {
            func_8006F0E0(((__repair_record_D_800C35A0*)D_800C35A0)->field_33);
          }
          func_8006DDD8();
          func_8006F75C();
          D_800AFA5C = 2U;
          var_s1 = &D_800A5268;
        }
        else
          if ((temp_a0_4 != 0) & (temp_a0_4 < 5U))
        {
          pack_tile_rows();
          func_8006F75C();
          D_800AFA5C = 1U;
          var_s1 = &D_800A5268;
        }
        else
          if (temp_a0_4 == 7)
        {
          var_s1 = &D_800A52A8;
        }
          break;

      }

    }
    func_80098290(D_800A1468 + 0x2AD, (D_800AFA5C * 0x24) + ((u8 *) (&D_800A13C0)));
    func_80098290(D_800A1468 + 0x2A1, var_s1);
    *((s8 *) (((char *) D_800A1468) + 0x29E)) = 1;
    *((u8 *) (((char *) D_800A1468) + 0x2A0)) = 0U;
    *((s8 *) (((char *) D_800A1468) + 0x29F)) = 0;
    *((u8 *) (((char *) D_800A1468) + 0x2BA)) = 0U;
    *((s8 *) (((char *) D_800A1468) + 0x2BB)) = 0;
    *((s32 *) (((char *) D_800A1468) + 0x288)) = 0;
    *((s32 *) (((char *) D_800A1468) + 0x28C)) = 0;
    *((s32 *) (((char *) D_800A1468) + 0x290)) = 0;
    *((s8 *) (((char *) D_800A1468) + 0x2BD)) = -1;
    D_800B5C60 = 0;
    do
    {
      func_80005ACC();
      func_8007F6E0(temp_s5);
      func_80042554();
      osSetThreadPri(D_800B0AE0, 6);
      temp_v0_6 = func_8004240C(0);
      D_800C7F84 = temp_v0_6;
      func_8000E8B8(((ViewObject *)temp_v0_6)->field);
      func_80005500(*((void **) (((char *) D_800C7F84) + 0x178)), D_8009B5A4);
      if ((*((s8 *) (((char *) D_800A1468) + 0x2BD))) == 1)
      {
        *((s8 *) (((char *) D_800A1468) + 0x2BD)) = 0;
        *((u8 *) (((char *) D_800A1468) + 0x249)) = 3U;
      }
      if ((((*((u8 *) (((char *) D_800A1468) + 0x249))) != 0) || ((*((s8 *) (((char *) D_800A1468) + 0x2BD))) == (-1))) && ((*((u8 *) (((char *) D_800A1468) + 0x2BA))) == 0))
      {
        func_8000E8FC(*((void **) (((char *) D_800C7F84) + 0x178)), D_8009B5A8, 0);
      }
      else
      {
        temp_v0_13 = func_800056FC(*((void **) (((char *) D_800C7F84) + 0x178)));
        temp_s0_2 = ((CommandObject *)temp_v0_13)->commands;
        ((CommandObject *)temp_v0_13)->commands = (void *) (temp_s0_2 + 8);
        buffer = D_8009B5A8;
        *((s32 *) (((char *) temp_s0_2) + 0)) = (s32) ((((*((s16 *) (((char *) buffer) + 4))) - 1) & 0xFFF) | 0xFF100000);
        *((s32 *) (((char *) temp_s0_2) + 4)) = func_80005C48(buffer);
      }
      temp_v0_8 = func_8004240C(2);
      D_800C7F84 = temp_v0_8;
      var_s2 = 0;
      func_8000E8B8(((ViewObject *)temp_v0_8)->field);
      func_80005500(*((void **) (((char *) D_800C7F84) + 0x178)), D_8009B5A4);
      temp_v0_9 = func_8004240C(3);
      D_800C7F84 = temp_v0_9;
      func_8000E8B8(((ViewObject *)temp_v0_9)->field);
      temp_v0_10 = func_8004240C(4);
      new_var = ((ViewObject *)temp_v0_10)->field;
      D_800C7F84 = temp_v0_10;
      func_8000E8B8(new_var);
      func_80005500(*((void **) (((char *) D_800C7F84) + 0x178)), D_8009B5A4);
      temp_v0_11 = func_8004240C(1);
      D_800C7F84 = temp_v0_11;
      func_8000E8B8(((ViewObject *)temp_v0_11)->field);
      func_80005500(*((void **) (((char *) D_800C7F84) + 0x178)), D_8009B5A4);
      temp_v0_12 = func_8001BD1C();
      guMtxIdent(temp_v0_12);
      temp_v0_13 = func_800056FC(D_800ADF80);
      temp_v0_14 = func_80006008(temp_v0_13);
      *((s32 *) (((char *) temp_v0_14) + 0)) = 0xDA380003;
      *((s32 *) (((char *) temp_v0_14) + 4)) = temp_v0_12;
      func_80006014(temp_v0_13, temp_v0_14 + 8);
      temp_v0_12 = func_8001BD1C();
      guOrthoF(&sp20, (f32) (*((s16 *) (((char *) D_800ADF80) + 8))), (f32) (*((s16 *) (((char *) D_800ADF80) + 0xC))), (f32) (*((s16 *) (((char *) D_800ADF80) + 0xE))), (f32) (*((s16 *) (((char *) D_800ADF80) + 0xA))), -1.0f, 10.0f, 1.0f);
      guMtxF2L(&sp20, temp_v0_12);
      func_800061FC(temp_v0_13, temp_v0_12);
      func_8005B6A8();
      func_8000F49C(D_800AFA88);
      loop_77:
      temp_s1 = (var_s2 & 255) * 0x10;

      temp_s0_4 = *((u8 *) ((D_800AE850 + 0x239C) + temp_s1));
      if (temp_s0_4 != func_800857C0(var_s2 & 255, 2))
      {
        *((D_800AE850 + 0x239D) + temp_s1) = 1;
        *((s32 *) ((D_800AE850 + 0x2394) + temp_s1)) = 0;
      }
      var_s2 += 1;
      if (((u32) (var_s2 & 0xFF)) < 4U)
      {
        goto loop_77;
      }
      if (D_800C35C0 != 0)
      {
        do
        {
          func_8007F6E0(D_800C81DC);
          temp_v0_15 = D_800C35C0 - 1;
          D_800C35C0 = temp_v0_15;
        }
        while (temp_v0_15 != 0);
      }
      temp_v0_16 = func_8004240C(2);
      D_800C7F84 = temp_v0_16;
      if ((((__repair_record_D_800C35A0*)D_800C35A0)->field_2C) & 2)
      {
        func_800131C0(((ViewObject *)temp_v0_16)->field);
      }
      if (func_80013E60() < 0x78)
      {
        func_8007F6E0(temp_s4);
      }
      *((s8 *) (((char *) D_800A1468) + 0x234)) = 1;
    }
    while ((*((u8 *) (((char *) D_800A1468) + 0x2A0))) == 0);
    if ((*((u8 *) (((char *) D_800A1468) + 0x232))) != 0)
    {
      *((u8 *) (((char *) D_800A1468) + 0x232)) = 0U;
    }
    func_80057AAC();
    func_800578E0(D_800C8328);
    func_8004C7B8();
    func_80047C78();
    func_80022484(D_800B7040);
    func_80080478(D_800B7040);
    func_80022214();
    func_80005DEC();
    D_800C3504 = func_80005C48(D_8009B5A8);
    if (D_800A16D4 == 1)
    {
      D_800A16D4 = 0;
    }
    if ((*((s16 *) (((char *) D_8009B5A8) + 4))) != 0x140)
    {
      func_80005948();
    }
    func_8007F634(temp_s5);
    func_8007F634(D_800C81DC);
    func_8007F634(temp_s4);
    func_80089B80();
  }
}
