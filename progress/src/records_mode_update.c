#define H(p,n) (*(u16*)((p)+(n)))
extern u8 stream_state;
extern u8 D_800A5260;
extern u8 D_800A52F0;
extern u8 D_800A52FC;
extern u8 D_800A5308;
extern u8 D_800A5318;
extern u8 D_800A5328;
extern u8 D_800A5338;
extern s32 D_800D0668;
extern s32 D_800B5B48;
extern s32 D_800D0660;
extern s32 D_800D0664;
extern s32 D_800C3588;
extern u8 D_800C8308;
extern u8 D_800C72D4;
extern u8 D_800C34D8;
extern u16 D_800D0628;
extern u16 D_800B5B52;
extern s32 D_800B6658[];
extern s32 D_800B55FC[];
extern u8 *gRecords;
void resolve_path(void *);
s32 func_80081664(s32, void *);
s32 getTexturePack(void *, s32);
void func_800407D0();
void func_80052844(void *);
void input_set_all_flags(s32);
void memset(void *, s32, s32);
static inline s32 inline_fn(s32 *arg0, u8 arg1)
{
  return arg0[arg1];
}

/* Called when the record/mode state changes: sets up the per-mode objects,
 * then clears or validates the stored record table for the new mode (gRecords
 * field 30 = mode, field 34 = record count). Ends by refreshing the four slots. */
void records_mode_update(void)
{
  u8 i;
  u8 j;
  s32 ok;
  u16 *count;
  u8 *p;
  resolve_path(&D_800A5260);
  D_800D0668 = func_80081664(6, &D_800A52F0);
  D_800B5B48 = func_80081664(6, &D_800A52FC);
  resolve_path(&D_800A5308);
  D_800D0660 = getTexturePack(&D_800A5318, 0);
  resolve_path(&D_800A5328);
  D_800D0664 = getTexturePack(&D_800A5338, 0);
  *((&stream_state) + 0x805A) = 0;
  p = gRecords;
  if (H(p, 14) == 1)
  {
    H(p, 54) = 3;
  }
  else
  {
    H(p, 54) = 0;
  }
  switch (H(gRecords, 30))
  {
    case 0:
      func_800407D0();
      D_800C3588 = -1;
      memset(count = &D_800C34D8, 0, 28);
      break;

    case 5:
      if (H(gRecords, 34) == 0)
    {
      func_80052844(gRecords);
    }
      ok = 1;
      {
      u16 *count = &D_800D0628;
      u8 i;
      u8 j;
      for (i = 0; i < 4; i++)
    {
      for (j = 0; j < (*count); j++)
      {
        if (1)
        {
        }
        {
        s32 t = ok & -(inline_fn(((s32 (*)[4]) D_800B6658)[j], i) == 0);
        ok = t & -(inline_fn(((s32 (*)[4]) (D_800B6658 + 48))[j], i) == 0);
        }
      }

    }
      }

      if ((u8) ok)
    {
      func_800407D0();
    }
      break;

    case 1:

    case 2:

    case 3:

    case 4:
      if (H(gRecords, 34) == 0)
    {
      u8 *q;
      D_800C72D4 = 0;
      func_800407D0();
      q = gRecords;
      for (i = 0; i < 4; i++)
      {
        for (j = 0; j < 4; j++)
        {
          s32 *r = &D_800B55FC[H(q, 30)];
          s32 off = i * 32;
          *(s32 *)((u8 *)r + off) = 0;
          r = &D_800B55FC[4 + H(q, 30)];
          *(s32 *)((u8 *)r + off) = 0;
        }

      }

    }
    else
      if (D_800C72D4 != (H(gRecords, 34) - 1))
    {
      func_800407D0();
    }
    else
    {
      D_800C72D4++;
    }
      H(gRecords, 32) = 0;
      D_800B5B52 = H(gRecords, 30);
      break;

  }

  for (i = 0; i < 4; i++)
  {
    input_set_all_flags(i);
  }

}
