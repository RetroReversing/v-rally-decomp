typedef struct Game { u8 pad0[0xE]; u16 e; u8 pad10[0xE]; u16 mode; u8 pad20[0xC]; u16 flags; } Game;
extern s32 *D_800C8048;
extern Game *D_800C35A0;
extern void *D_800C7F84;
extern void *D_800C811C;
extern char D_800C7950[];
extern unsigned char D_800C8324;
extern int D_800AFA6C;
extern unsigned short D_800C3630;
extern unsigned char D_800C792F;
extern int D_800C8370;
extern int D_800B65EC;
extern int D_800B65F0;
extern int D_800B65F4;
extern int D_800B7040;
extern int D_800C34F4;
extern int D_800B6AFC;
extern int D_800C8374;
extern int D_800AFA50;
extern unsigned char D_800C8120;
extern int D_800C35C0;
extern int D_800B5B4C;
extern signed char D_800C5E54;
extern float D_800C35E0;
extern float D_800C35D8;
extern int D_800C81D4;
extern int D_800B0AE0;
extern short D_800B5B50;
s32 func_80005500();
s32 func_80005718();
s32 func_80005ACC();
s32 func_80005B00();
s32 func_8000DA84();
s32 func_8000DB14();
s32 func_8000E8B8();
s32 func_8000E8FC();
s32 func_80010128();
s32 func_80010468();
s32 func_800131C0();
s32 func_80013E60();
s32 func_80013EA0();
s32 func_80013F3C();
s32 func_800144C8();
s32 func_80015780();
s32 func_8001B8CC();
s32 func_8001FC14();
s32 func_8001FF80();
void *func_80022318(void **, u8 *);
s32 func_800234AC();
s32 func_800234E0();
s32 func_80023604();
s32 func_8002362C();
s32 func_8002EDCC();
s32 func_80034FF0();
s32 func_800354F4();
s32 func_80038D1C();
s32 func_80038D40();
s32 func_800405D8();
s32 func_80040CF4();
s32 func_800412FC();
s32 func_80041E0C();
s32 func_80042264();
s32 func_800422C8();
void *func_8004240C();
s32 func_80042554();
s32 func_80048ADC();
s32 func_80049294();
s32 func_80049654();
s32 func_80050B38();
s32 func_80050F08();
s32 func_800516BC();
s32 func_80053B2C();
s32 func_8005B3AC();
s32 func_80069424();
s32 func_8006AC04();
s32 func_8007301C();
s32 func_80077054();
s32 func_8007BDC4();
s32 func_8007E9D4();
s32 func_8007EAA0();
s32 func_8007EE9C();
s32 func_8007F050();
s32 func_8007F4E4();
s32 func_8007F634();
s32 func_8007F6E0();
s32 func_80080440();
s32 func_80080514();
s32 func_80081540();
s32 func_80081B44();
s32 func_80084BF0();
s32 func_80086854();
s32 func_80086A34();
s32 MusSetMasterVolume();
s32 func_80086D90();
s32 func_80086DE8();
s32 osGetTime();
s32 osSetThreadPri();
s32 osViBlack();
extern s32 D_8009B5A4;
extern s32 D_8009B5A8;
extern s32 D_8009B5AC;
extern s32 D_8009B960;
extern s32 D_8009B964;
extern s32 *D_8009B968;
extern s8 D_8009B96C;
extern s32 D_8009B9D8;
extern s32 D_8009D538;
extern s32 D_8009D540;
extern s32 D_8009F640;
extern void *D_800A0384;
extern s32 D_800A1740;
extern char D_800A3F9C[];
extern char D_800A3FAC[];
extern char D_800A3FB8[];
extern char D_800A3FC0[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_8000F60C;
extern s32 func_80042A7C;
typedef struct PNode { u8 pad0[4]; struct PNode *next; u8 pad8[0x40]; s32 *p48; } PNode;
void func_8000F660(void)
{
  s32 *temp_v1;
  s32 var_a0;
  s32 temp_s3;
  s32 temp_s4;
  s32 temp_s5;
  s32 temp_v0;
  s32 temp_v0_6;
  s32 var_s1;
  s32 var_v0;
  s32 var_v1;
  u32 temp_a1;
  s32 initial_mode;
  u16 temp_v0_8;
  s32 temp_s2;
  s32 temp_v1_2;
  PNode *temp_a0;
  PNode *temp_a0_2;
  void *temp_s0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_7;
  D_800C8324 = 0U;
  D_800AFA6C = 0;
  D_800C3630 = 0U;
  var_s1 = 0;
  if (D_800C792F == 2)
  {
    D_8009D540 = 0x19;
    D_800C8370 = 0x10;
  }
  else
  {
    D_8009D540 = 0x19;
    D_800C8370 = 0x18;
  }
  func_80005B00(0, 0x2810);
  func_8000DB14(D_8009B5AC, 1);
  D_8009B5A4 = D_8009B5AC;
  D_8009B5A8 = D_8009B5AC;
  func_8006AC04();
  temp_s5 = func_8007F4E4(6, 2, 1);
  temp_s3 = func_8007F4E4(9, 2, 0x10);
  temp_s4 = func_8007F4E4(4, 0, 1);
  if (D_8009B9D8 == 2)
  {
    D_8009B9D8 = func_8007EAA0(3, 0x54C70);
  }
  func_8005B3AC();
  temp_v0 = func_80080440();
  D_800B65EC = -0x46;
  D_800B65F0 = 0;
  D_800B65F4 = 0x46;
  initial_mode = *((u16 *) (((char *) D_800C35A0) + 0x1E));
  *(s32 *)0x800B7040 = temp_v0;
  D_800C34F4 = 0;
  D_800B6AFC = 0;
  if (initial_mode == 7)
  {
    func_80050F08();
    D_800C35A0->e = 1U;
    func_80015780(0, 0, 9, 0xB4, 1, 0);
    func_8001B8CC(D_800C8374);
    func_80041E0C();
    func_80040CF4(0);
    var_a0 = 1;
    D_800C35A0->mode = 7U;
  }
  else
  {
    func_80015780(0, 0, 9, 0xB4, 1, 0);
    func_8001B8CC(D_800C8374);
    func_80041E0C();
    func_80040CF4(0);
    var_a0 = 0;
  }
  func_800416EC(var_a0);
  func_80023604();
  func_8001FF80();
  temp_s2 = *((u8 *) (((char *) D_800C35A0) + 0xF));
  func_80069424();
  func_800234AC();
  func_80038D40();
  if (((u32) (D_800C35A0->mode - 7)) < 2U)
  {
    func_800234E0();
    temp_a0 = **((PNode ***) (D_800AE850 + 0x73F0));
    D_8009D538 = *temp_a0->p48;
    *temp_a0->p48 = 0;
    if ((D_800C35A0->mode == 7) && (D_800C35A0->e == 2))
    {
      temp_a0 = temp_a0->next; *temp_a0->p48 = 1;
    }
    if (D_800C35A0->mode == 8)
    {
      D_800C35A0->e = 1U;
    }
  }
  func_800422C8();
  if (((u32) (D_800C35A0->mode - 7)) < 2U)
  {
    temp_a0_2 = **((PNode ***) (D_800AE850 + 0x73F0));
    *temp_a0_2->p48 = D_8009D538;
    temp_a1 = D_800C35A0->mode;
    if (temp_a1 == 7)
    {
      if (D_800C35A0->e == 2)
      {
        temp_a0_2 = temp_a0_2->next; *temp_a0_2->p48 = 6;
      }
      if (D_800C35A0->mode == temp_a1)
      {
        func_80081540(&D_800A3F9C);
        D_800AFA50 = func_80034FF0(&D_800A3FAC, 0);
      }
    }
  }
  func_80049654();
  D_800C8120 = 1U;
  D_800C35C0 = 0;
  D_8009D538 = 1;
  func_80081B44();
  if (D_8009B9D8 != 2)
  {
    func_8007EE9C(D_8009B9D8);
  }
  D_8009B9D8 = 2;
  func_80005B00(0, 0x220E);
  func_80042264();
  func_80050B38();
  D_8009B960 = func_8007F050(1);
  D_8009B964 = func_8007F050(2);
  if (D_800C35A0->mode == 7)
  {
    D_8009D538 |= 0xA01;
    func_80080514(D_800B5B4C, &func_80042A7C, 3);
    func_8007E9D4();
  }
  temp_v1 = D_800C8048;
  D_800A1740 = 0;
  D_800C8048 = &func_8000F60C;
  D_8009B96C = 0;
  D_8009B968 = temp_v1;
  osViBlack(1);
  D_800C5E54 = 4;
  func_8000DA84();
  D_800C7F84 = temp_v0_2 = func_8004240C(0);
  func_8000E8FC(((struct { u8 pad[0x178]; s32 x; } *) temp_v0_2)->x, D_8009B5A8, D_8009B5AC);
  func_80005718(D_8009B5A4, *((s32 *) (((char *) D_800C7F84) + 0x178)));
  func_8007F6E0(temp_s3);
  func_80005ACC();
  func_8007F6E0(temp_s5);
  func_8000E8FC(*((s32 *) (((char *) D_800C7F84) + 0x178)), D_8009B5A8, D_8009B5AC);
  func_80005718(D_8009B5A4, *((s32 *) (((char *) D_800C7F84) + 0x178)));
  func_8007F6E0(temp_s3);
  if (D_800C8120 != 0)
  {
    temp_s0 = &D_800C35D8;
    temp_s2 = (temp_s2 - 1) * 2;
    do
    {
      if (((D_800C35A0->mode == 7) && (!(D_8009F640 & 0x80))) && (D_800C5E54 == 0))
      {
        D_8009F640 |= 0x80;
        func_80086A34(1);
        func_80086854(D_800C7950);
        func_80086DE8((s32) (D_800C35E0 * 80.0f));
      }
      if (!(D_8009F640 & 1))
      {
        var_v1 = var_s1 & 0xFF;
        if (D_800C35A0->e == 2)
        {
          if (D_8009F640 & 2)
          {
            goto block_35;
          }
        }
      }
      else
      {
        block_35:
        var_s1 += 1;
        var_v1 = var_s1 & 0xFF;
      }
      if (((var_s1 & 0xFF) == 8) && (!(D_8009F640 & 8)))
      {
        D_8009F640 &= ~1;
        D_8009F640 &= ~2;
        MusSetMasterVolume(3, (s32) ((*((f32 *) temp_s0)) * 32767.0f));
        temp_v1_2 = *((u8 *) (((char *) temp_s0) + (-0x10)));
        *((s32 *) (((char *) temp_s0) + 0xC)) = 0;
        if (temp_v1_2 != 0xFF)
        {
          func_80086D90(D_800C81D4 + (temp_v1_2 * 0xC), 0);
        }
        D_8009F640 |= 8;
        var_s1 = 0;
        func_80086854(D_800C7950);
        func_80086DE8((s32) ((*((f32 *) (((char *) temp_s0) + 8))) * 112.0f));
      }
      func_80005ACC();
      func_8007F6E0(temp_s5);
      osGetTime();
      func_80013F3C();
      func_80042554();
      osSetThreadPri(D_800B0AE0, 6);
      func_8001FC14();
      if ((*((u8 *) (((char *) D_800A0384) + 0x384))) == 0)
      {
        D_800C7F84 = func_8004240C(1);
        func_8002362C();
        if ((*((u8 *) (((char *) D_800A0384) + 0x384))) == 0)
        {
          func_80010468();
        }
      }
      func_80048ADC();
      func_80013EA0();
      func_800412FC();
      func_80013F3C();
      func_800405D8();
      if ((*((u8 *) (((char *) D_800A0384) + 0x384))) == 0)
      {
        func_8002EDCC();
        if (((u32) ((*((u16 *) (((char *) D_800C811C) + 4))) - 3)) < 2U)
        {
          func_800354F4();
        }
      }
      func_80038D1C();
      func_80013EA0();
      D_800C7F84 = temp_v0_3 = func_8004240C(temp_s2 + 4);
      func_8000E8B8(((struct { u8 pad[0x178]; s32 x; } *) temp_v0_3)->x);
      func_80005500(*((s32 *) (((char *) D_800C7F84) + 0x178)), D_8009B5A4);
      temp_v0_4 = func_80022318((void **)(D_800C7F84 + 0x28), (u8 *)(&D_800A3FB8));
      if (temp_v0_4 != NULL)
      {
        (*((s32 (**)(s32)) (((char *) temp_v0_4) + 0x14)))(*((s32 *) (((char *) temp_v0_4) + 0x10)));
      }
      temp_v0_5 = func_80022318((void **)(D_800C7F84 + 0x28), (u8 *)(&D_800A3FC0));
      if (temp_v0_5 != NULL)
      {
        (*((s32 (**)(s32)) (((char *) temp_v0_5) + 0x14)))(*((s32 *) (((char *) temp_v0_5) + 0x10)));
      }
      func_8007BDC4();
      func_80049294();
      func_800516BC();
      func_80013F3C();
      if (D_800C35C0 != 0)
      {
        do
        {
          func_8007F6E0(temp_s3);
          temp_v0_6 = D_800C35C0 - 1;
          D_800C35C0 = temp_v0_6;
        }
        while (temp_v0_6 != 0);
      }
      if (D_800C35A0->flags & 4)
      {
        func_800144C8(func_80084BF0(0));
      }
      if ((*((u16 *) (((char *) D_800C811C) + 4))) == 0)
      {
        func_800354F4();
      }
      func_80077054();
      if (D_800C8324 != 0)
      {
        func_8007301C();
      }
      func_80013EA0();
      temp_v0_7 = func_8004240C(temp_s2 + 4);
      D_800C7F84 = temp_v0_7;
      if (D_800C35A0->flags & 2)
      {
        func_800131C0(((struct { u8 pad[0x178]; s32 x; } *) temp_v0_7)->x);
      }
      osGetTime();
      D_8009B96C = 1;
      if (D_800C792F != 3)
      {
        if (func_80013E60() < 0x78)
        {
          func_8007F6E0(temp_s4);
        }
        if ((func_80013E60() >= 0xC9) && (((u32) (D_800C35A0->mode - 7)) >= 2U))
        {
          temp_v0_8 = D_800C3630 + 1;
          D_800C3630 = temp_v0_8;
          if (((u32) (temp_v0_8 & 0xFFFF)) >= 2U)
          {
            D_800B5B50 = 1;
            D_800C3630 = 0U;
          }
        }
      }
      else
        if (func_80013E60() < 0xC8)
      {
        func_8007F6E0(temp_s4);
      }
    }
    while (D_800C8120 != 0);
  }
  func_80053B2C();
  func_8007F634(temp_s3);
  func_8007F634(temp_s5);
  func_8007F634(temp_s4);
  D_800C8048 = (s32 *) D_8009B968;
  func_80010128();
}
