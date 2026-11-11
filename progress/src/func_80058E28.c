typedef struct Cfg
{
  u8 pad[0x22B];
  s8 ctrl;
} Cfg;
extern Cfg *gSelectState;
extern u32 D_800A14A8;
extern u16 D_800A14AC;
extern u8 D_800A14AE;
extern u32 gRecordTimeScale;
extern u8 D_800B65A0;
extern u8 D_800B5C6C;
extern s8 func_80084C0C(u8, s32);
extern s32 func_80084BF0(u8);

/* Turns the selected pad's stick and buttons into the menu input bits in the
 * return value (1=left, 2=right, 4=up, 8=down, 0x10/0x20/0x80 buttons). Stick
 * direction is used when the stick is past its dead zone. A held direction only
 * repeats after a delay, and the repeat rate is taken from gRecordTimeScale. */
s32 func_80058E28(void)
{
  u8 pad[8];
  s32 ctrlIdx;
  s32 stickBits;
  s32 result;
  s32 pos;
  s8 ctrl;
  s32 buttons;
  s32 pressed;
  s32 tmp;
  s8 i;
  s32 stickX;
  s32 stickY;
  u16 holdFrames;
  result = 0;
  stickY = 0;
  ctrlIdx = gSelectState->ctrl;
  stickX = 0;
  i = 0;
  result = i;
  ctrl = ctrlIdx;
  pos = ctrlIdx >= 0;
  loop1:
  tmp = D_800B65A0;
  if ((tmp = i < tmp))
  {
    if ((pos & (pressed = ctrlIdx == i)) || (ctrlIdx < 0))
    {
      stickX = func_80084C0C(i, 0x10000);
      stickY = func_80084C0C(i, 0x20000);
    }
    i++;
    if (!(stickY | stickX))
    {
      goto loop1;
    }
  }

  stickBits = 0;
  if (stickX >= 0x50)
  {
    stickBits = 0x800;
  }
  else
    if (stickX < (-0x4F))
  {
    stickBits = 0x400;
  }
  if (stickY >= 0x60)
  {
    stickBits |= 0x100;
  }
  else
    if (stickY < (-0x5F))
  {
    stickBits |= 0x200;
  }
  buttons = 0;
  i = 0;
  stickX = (s8) ctrl;
  pos = stickX >= 0;
  loop2:
  tmp = D_800B65A0;
  if ((tmp = i < tmp))
  {
    if ((pos & (tmp = stickX == i)) || (stickX < 0))
    {
      pressed = func_80084BF0(i);
      buttons |= pressed;
      if (pressed)
      {
        D_800B5C6C = i;
      }
    }
    i++;
    if (!buttons)
    {
      goto loop2;
    }
  }

  if (buttons == 0)
  {
    buttons = stickBits;
  }
  for (i = 0; i < 32; i++)
  {
    if ((buttons & (1 << i)) == (1 << i))
    {
      buttons &= 1 << i;
      break;
    }
  }

  if (buttons)
  {
    if (D_800A14A8 == 0)
    {
      D_800A14AC = 0;
      D_800A14A8 = buttons;
    }
    else
      if (D_800A14A8 == buttons)
    {
      holdFrames = ++D_800A14AC;
      if (!D_800A14AE)
      {
        if (holdFrames == ((gRecordTimeScale * 3) >> 2))
        {
          D_800A14AE = 1;
          D_800A14AC = 0;
        }
        else
        {
          buttons = 0;
        }
      }
      else
        if (holdFrames == (gRecordTimeScale / 6))
      {
        D_800A14AC = 0;
      }
      else
      {
        buttons = 0;
      }
    }
    else
    {
      D_800A14A8 = buttons;
      D_800A14AC = 1;
      D_800A14AE = 0;
    }
  }
  else
  {
    D_800A14A8 = 0;
    D_800A14AC = 0;
    D_800A14AE = 0;
  }
  if (buttons & 0x800)
  {
    result |= 1;
  }
  if (buttons & 0x400)
  {
    result |= 2;
  }
  if (buttons & 0x200)
  {
    result |= 4;
  }
  if (buttons & 0x100)
  {
    result |= 8;
  }
  if (buttons & 0x4000)
  {
    result |= 0x20;
  }
  if (buttons & 0x8000)
  {
    result |= 0x10;
  }
  if (buttons & 0x1000)
  {
    result |= 0x80;
  }
  return result;
}
