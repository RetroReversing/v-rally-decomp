extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 D_800A4FE4[];
extern u8 *D_800A1234;
extern u8 *D_800C35A0;
s32 func_80022184(void *);
void func_8002283C(void);
void func_80081540(void *);
void *func_80081664(s32, s32);
void *func_8007EAA0(s32, u32);
void func_8007EE9C(void *);
typedef struct 
{
  u32 w[61];
} Block4;
typedef struct 
{
  u32 *p0;
  u32 *p4;
  u16 flags;
  u16 mode;
  u16 zero;
  u16 pade;
  u32 size0;
  u32 size4;
  u8 rest[44];
} Entry4;
static inline static void copy4(void *destination, void *source, u32 bytes)
{
  u32 *d = destination;
  u32 *s = (u32 *) (((u8 *) source) + bytes);
  u32 n;
  if ((((u32) d) < ((u32) s)) & (((u32) source) < ((u32) d)))
  {
    n = bytes >> 2;
    d = (u32 *) (((u8 *) d) + bytes);
    if (n)
      do
    {
      --s;
      --d;
      *d = *s;
      --n;
    }
    while (n);
  }
  else
  {
    n = bytes >> 2;
    s = source;
    if (n)
      do
    {
      u32 v = *(s++);
      *(d++) = v;
      --n;
    }
    while (n);
  }
}

static inline static void copyfinal4(void *source, void *destination, u32 bytes)
{
  u32 *d = destination;
  u32 *s = (u32 *) (((u8 *) source) + bytes);
  u32 n;
  if ((((u32) d) < ((u32) s)) & (((u32) source) < ((u32) d)))
  {
    n = bytes >> 2;
    d = (u32 *) (((u8 *) d) + bytes);
    if (n)
      do
    {
      --s;
      --d;
      *d = *s;
      --n;
    }
    while (n);
  }
  else
  {
    n = bytes >> 2;
    s = source;
    if (n)
      do
    {
      u32 v = *(s++);
      *(d++) = v;
      --n;
    }
    while (n);
  }
}

/* Loads the saved game/track state from file 'arg0': copies the 0x118-byte
 * header to the state block at D_800A1234, then the entry bodies (sizes
 * rounded up to 4) into their allocations, then the 0xF4-byte record at
 * D_800C35A0 with overlap-safe copies, and finally sets the state flags. */
void func_80050FC4(s32 arg0)
{
  u8 *hdr;
  u8 *file;
  u8 *data;
  Entry4 *ent;
  u8 i;
  u8 count;
  void *state = D_800AE850 + 0x7320;
  if (!func_80022184(state))
  {
    func_8002283C();
  }
  if (func_80022184(state))
  {
    hdr = D_800A1234;
    func_80081540(D_800A4FE4);
    file = func_80081664(1, arg0);
    data = file;
    __builtin_memcpy(hdr, file, 0x118);
    count = hdr[0x111];
    data += 0x118;
    for (i = 0; i < count; i++)
    {
      ent = (Entry4 *) (hdr + (i * 0x44));
      ent->p4 = func_8007EAA0(1, (ent->size4 + 3) & (~3));
      copy4(ent->p4, data, (ent->size4 + 3) & (~3));
      ent->mode = 4;
      ent->zero = 0;
      ent->flags = (ent->flags & 0xfbff) | 0x200;
      data += (ent->size4 + 3) & (~3);
    }

    for (i = 0; i < count; i++)
    {
      ent = (Entry4 *) (hdr + (i * 0x44));
      ent->p0 = func_8007EAA0(1, (ent->size0 + 3) & (~3));
      copy4(ent->p0, data, (ent->size0 + 3) & (~3));
      data += (ent->size0 + 3) & (~3);
    }

    *((Block4 *) (D_800C02AE + 0x7f66)) = *((Block4 *) D_800C35A0);
    {
      u32 dest = (u32) D_800C35A0;
      u32 end = ((u32) data) + 0xf4;
      u32 *src, *dst;
      s32 n;
      if ((dest < end) & (((u32) data) < dest))
      {
        src = (u32 *) end;
        dst = (u32 *) (dest + 0xf4);
        n = 61;
        do
        {
          u32 v = *(--src);
          *(--dst) = v;
          --n;
        }
        while (n);
      }
      else
      {
        src = (u32 *) data;
        dst = (u32 *) dest;
        n = 61;
        do
        {
          u32 v = *(src++);
          *(dst++) = v;
          --n;
        }
        while (n);
      }
    }
    *((u16 *) (D_800C35A0 + 0x2c)) = (*((u16 *) (D_800C02AE + 0x7f92))) | 0x10;
    hdr[0x114] = 0;
    func_8007EE9C(file);
    *((u16 *) (D_800C35A0 + 0xe)) = 1;
    if (D_800C02AE[0x38f1])
    {
      *((u16 *) (D_800C35A0 + 0x12)) |= 1;
    }
    else
    {
      *((u16 *) (D_800C35A0 + 0x12)) &= 0xfffe;
    }
  }
}
