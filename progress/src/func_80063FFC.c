typedef struct 
{
  u8 b[0x500];
} Blob;
extern Blob D_800C02AE;
extern u8 *D_800C35A0;
extern u8 *D_800C3508;
extern s32 D_800D0634[];
extern u8 D_8009E260;
extern u8 D_800A14D6;
extern u8 D_800A14D7;
extern u8 D_800A14D8;
extern u8 D_800A16D4;
extern void *D_800A1468;
extern s32 func_80064504;
extern s32 func_8006A24C;
extern void func_800416EC();
extern s32 func_80057B40(s32, s32, s32, s32);void *func_800592AC(u32);
void func_8005C0E8(s32, u32, u32);
extern s32 hud_setup_stage_results(void);
void func_80061F34(void *, void *);
extern s32 func_8006A25C(void);
extern s32 func_8008A0D8(s32, s32, s32);
extern s32 func_8008A270(s32, s32, s32);
extern s32 func_8008A290(s32, s32, s32, void *);
void func_80063FFC(void)
{
  s32 new_var;
  u8 *p = (u8 *) D_800C02AE.b;
  u8 *a0;
  s32 t;
  s32 i;
  u16 s2;
  u8 s0;
  u8 s1;
  {
    u8 *first = D_800C35A0;
    t = *((u16 *) (first + 0x1e));
    i = *((u16 *) (first + 0x20));
    t = ((s32 *) 0x800D0634)[(u16) t];
    {
      s32 base = (6 * (118 * i)) + t;
      s32 offset = (*((u16 *) (first + 0x22))) << 6;
      *(first + 0x2e) = *((u8 *) ((base + offset) + 0x37));
    }
    func_80061F34(first, (void *)t);
  }
  {
    u8 *menu = D_800C3508;
    if (D_800A16D4)
    {
      *((s32 *) (((u8 *) D_800A1468) + 0x28c)) = &func_80064504;
      func_8008A270((s32) menu, 3, 0x14);
    }
    else
    {
      *((s32 *) (((u8 *) D_800A1468) + 0x28c)) = &func_80064504;
      func_8008A270((s32) menu, 3, 0x14);
    }
  }
  func_8008A290((s32) D_800C3508, 3, 0x10000, &func_8006A24C);
  func_8006A25C();
  if ((*((u16 *) (D_800C35A0 + 0xe))) < 2)
  {
    func_8008A0D8((s32) D_800C3508, 0x1a, 0);
    *((s8 *) (((u8 *) func_800592AC(2)) + 0x41)) = 0;
    func_8005C0E8(2, 1, 4);
  }
  hud_setup_stage_results();
  if ((s16) D_800A16D4 >= 3)
  {
    goto done;
  }
  switch (D_800A16D4)
  {
    case 0:
      switch ((s8) D_800A16D4)
    {
      case 0:
      {
        a0 = D_800C35A0;
        D_8009E260 = 4;
        s2 = *((volatile u16 *) (a0 + 0xe));
        new_var = *((volatile s32 *) (a0 + 0x20));
        t = new_var;
        s0 = *(a0 + 0x21);
        s1 = *(a0 + 0x23);
        *((u16 *) (a0 + 0xe)) = 1;
        if (new_var == 0x10003)
        {
          *((u16 *) (a0 + 0x1e)) = 5;
          *((u16 *) (a0 + 0x20)) = 1;
          *((u16 *) (a0 + 0x22)) = 2;
        }
        else
          if (new_var == 0x60004)
        {
          *((u16 *) (a0 + 0x1e)) = 5;
          *((u16 *) (a0 + 0x20)) = 6;
          *((u16 *) (a0 + 0x22)) = 0;
        }
        else
          if (new_var == 0x20001)
        {
          shared:
          *((u16 *) (a0 + 0x1e)) = 5;
          *((u16 *) (a0 + 0x20)) = 1;
          *((u16 *) (a0 + 0x22)) = 2;
        }
        else
          if (t == 0x40000)
        {
          *((u16 *) (a0 + 0x1e)) = 4;
          *((u16 *) (a0 + 0x20)) = 1;
          *((u16 *) (a0 + 0x20)) = 0;
          *((u16 *) (a0 + 0x22)) = 1;
        }
        else
          if (t == 0x50001)
        {
          *((u16 *) (a0 + 0x1e)) = 5;
          *((u16 *) (a0 + 0x20)) = 10;
          *((u16 *) (a0 + 0x22)) = 0;
        }
        {
          u16 c;
          u16 r;
          u16 s;
          u8 *snap = D_800C35A0;
          c = *((u16 *) (snap + 0x1e));
          r = *((u16 *) (snap + 0x20));
          s = *((u16 *) (snap + 0x22));
          D_800A14D6 = c;
          D_800A14D7 = r;
          D_800A14D8 = s;
        }
        func_800416EC();
        {
          u8 *restore = D_800C35A0;
          D_8009E260 = 1;
          *((u16 *) (restore + 0x20)) = s0;
          *((u16 *) (restore + 0x1e)) = 0;
          *((u16 *) (restore + 0x22)) = s1;
          *((u16 *) (restore + 0xe)) = s2;
        }
      }
        break;

    }

      break;

    case 1:

    case 2:
      break;

  }

  done:
  func_80057B40(0x1c, 2, 0, 0);

}

