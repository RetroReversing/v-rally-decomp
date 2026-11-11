s32 func_80055D18();
s32 func_80055EE8();

/* Walks count 8-byte records starting at rec. Each record's type (u16 at +6) selects the
 * handler: 0x1A goes to func_80055D18, 0x1E to func_80055EE8. Unknown types are skipped. */
void func_800562D0(s32 ctx, void *rec, s32 arg2, s32 arg3, s32 count)
{
  u16 type;
  s32 i;
  u16 t;
  rec = rec;
  if (count != 0)
  {
    for (i = 0; i < count; i++)
    {
      type = *((u16 *) (((char *) rec) + 6));
      t = type;
      switch (t)
      {
        case 0x1A:
          func_80055D18(ctx, rec, arg2, arg3);
          break;

        case 0x1E:
          func_80055EE8(ctx, rec, arg2, arg3);
          break;

      }

      rec = ((char *) rec) + 8;
    }

  }
}
