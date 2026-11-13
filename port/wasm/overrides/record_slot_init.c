/* port (WebAssembly build): the switch cases follow the console's jump table. The matched C's labels compile to
   the same code but a different table, which the judge doesn't compare: this fix belongs in the matched C. */
extern s32 D_800A5060;
extern s32 D_800A5064;
extern s32 D_800A5068;
extern s32 D_800A506C;
extern s32 D_800A5070;
extern s32 D_800A5074;
extern s32 D_800A5078;
extern s32 D_800A507C;
extern s32 D_800A5080;
extern s32 D_800A5084;
extern s32 D_800A5088;
extern s32 D_800A508C;
extern s32 D_800A5090;
extern s32 D_800A5094;
extern s32 D_800A5098;
extern s32 D_800A50A0;
extern s32 D_800A50A4;
extern s32 D_800A50A8;
extern s32 D_800A50AC;
extern s32 D_800A50B0;
extern u8 *gRecords;
extern s32 strCmp(u8 *, u8 *);

/* Sets the 0x44 field of record slot `slot` from a per-code constant (case labels follow
 * jtbl_800A50B8; codes 5, 15, 18, 21 and any other code use D_800A5074) and then checks the other slots' links; repeats with the next
 * code until all four are consistent. */
void record_slot_init(s32 slot, s32 code)
{
  s32 off = (slot &= 0xff) * 0x28;
  int new_var;
  s32 off44 = off + 0x44;
  s32 ok;
  s32 x;
  s32 limit;
  u8 i;
  u8 *base;
  u8 *p;
  u8 v;
  limit = 0x16;
  for (;;)
  {
    switch (code & 0xff)
    {
      case 0:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5060;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5060;
#endif
        break;

      case 1:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5064;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5064;
#endif
        break;

      case 2:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5068;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5068;
#endif
        break;

      case 3:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A506C;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A506C;
#endif
        break;

      case 4:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5070;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5070;
#endif
        break;

      case 6:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5078;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5078;
#endif
        break;

      case 7:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A507C;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A507C;
#endif
        break;

      case 8:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5080;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5080;
#endif
        break;

      case 9:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5084;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5084;
#endif
        break;

      case 10:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5088;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5088;
#endif
        break;

      case 11:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A508C;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A508C;
#endif
        break;

      case 12:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5090;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5090;
#endif
        break;

      case 13:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5094;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5094;
#endif
        break;

      case 14:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5098;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5098;
#endif
        break;

      case 16:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A50A0;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A50A0;
#endif
        break;

      case 17:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A50A4;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A50A4;
#endif
        break;

      case 19:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A50A8;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A50A8;
#endif
        break;

      case 20:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A50AC;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A50AC;
#endif
        break;

      case 22:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A50B0;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A50B0;
#endif
        break;

      case 5:

      case 15:

      case 18:

      case 21:

      default:
#ifdef PORT
        *((s32 *) (((u8 *)gRecords + off) + 0x44)) = D_800A5074;
#else
        *((s32 *) (((u8 *)(off + (s32)gRecords)) + 0x44)) = D_800A5074;
#endif
        break;

    }

    ok = 1;
    i = 0;
    do
    {
      base = gRecords;
      v = *(i + base + 0x32);
      if (slot != v)
      {
        p = base + ((v * 0x28) + 0x44);
        new_var = strCmp(base + off44, p);
        x = new_var;
        ok &= -(x != 0);
      }
      if (!(ok & 0xff))
      {
        x = code + 1;
        new_var = -(((x & 0xff) ^ limit) != 0);
        code = x & new_var;
      }
      i++;
    }
    while (i < 4);
    if (ok & 0xff)
    {
      break;
    }
  }

}
