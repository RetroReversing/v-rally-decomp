extern s32 D_8009CE8C;
extern s32 D_8009CE90;
extern s32 D_8009CE94;
extern s32 D_8009CE98;
extern s32 D_8009CE9C;
extern s32 D_8009CEA0;
extern char stream_state[];
/* Fills in the state block obj from entry 'index' of the 0x4C-byte table (or from fixed defaults when table is NULL), then sets the per-mode volume globals from obj's mode field at +0xE. */
#ifdef PORT
void func_80011058(void *obj, char *table, s32 index)
#else
void func_80011058(void *obj, s32 table, s32 index)
#endif
{
  s32 value;
  s32 v;
  s32 idx;
  char *temp;
  idx = index & 0xFFFF;
  do
  {
    if (table != 0)
    {
#ifdef PORT
      temp = table + ((index & 0xFFFF) * 0x4C);
#else
      temp = (char *) (((index & 0xFFFF) * 0x4C) + table);
#endif
      *((s32 *) (((char *) obj) + 0x10)) = *((s32 *) (temp + 0x90));
      *((s32 *) (((char *) obj) + 0x14)) = *((s32 *) (temp + 0xDC));
      v = *((s32 *) (temp + 0x128));
      *((s16 *) (((char *) obj) + 0x6A)) = 0x1000;
      *((s32 *) (((char *) obj) + 0x30)) = 2;
      *((s32 *) (((char *) obj) + 0x18)) = v;
    }
    else
    {
      *((s32 *) (((char *) obj) + 0x10)) = 0x80;
      *((s32 *) (((char *) obj) + 0x14)) = 0x14;
      *((s32 *) (((char *) obj) + 0x18)) = 5;
      *((s16 *) (((char *) obj) + 0x6A)) = 0x1000;
      *((s32 *) (((char *) obj) + 0x30)) = 2;
    }
    obj = *((void **) (stream_state + 0x32F2));
  }
  while (0);
  v = *((u16 *) (((char *) obj) + 0xE));
  switch (v)
  {
    case 1:
      value = -0x87;
      D_8009CE90 = value;
      D_8009CE8C = 0;
      value = 0x2B;
      break;
    case 2:
      if ((*((u16 *) (((char *) obj) + 0x12))) & 1)
      {
        value = -0x56;
        D_8009CE9C = value;
        D_8009CE90 = value;
        value = 0x34;
      }
      else
      {
        value = -0x87;
        D_8009CE9C = value;
        D_8009CE90 = value;
        value = 0x2B;
      }
      D_8009CE98 = 0;
      D_8009CE8C = 0;
      D_8009CEA0 = value;
      break;
    default: return;
  }

  D_8009CE94 = value;
}
