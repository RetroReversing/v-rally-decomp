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

void func_80050FC4(s32 arg0)
{
  u8 *base;
  u8 *file;
  s32 new_var;
  u8 *p;
  Entry4 *e;
  u8 i;
  u8 n;
  void *state = D_800AE850 + 0x7320;
  if (!func_80022184(state))
  {
    func_8002283C();
  }
  if (func_80022184(state))
  {
    base = D_800A1234;
    func_80081540(D_800A4FE4);
    file = func_80081664(1, arg0);
    p = file;
    __builtin_memcpy(base, file, 0x118);
    n = base[0x111];
    p += 0x118;
    for (i = 0; i < n; i++)
    {
      e = (Entry4 *) (base + (i * 0x44));
      e->p4 = func_8007EAA0(1, (e->size4 + 3) & (~3));
      e = e;
      copy4(e->p4, p, (e->size4 + 3) & (~3));
      e->mode = 4;
      e->zero = 0;
      e->flags = (e->flags & 0xfbff) | 0x200;
      p += (e->size4 + 3) & (~3);
    }

    for (i = 0; i < n; i++)
    {
      e = (Entry4 *) (base + (i * 0x44));
      e->p0 = func_8007EAA0(1, (e->size0 + 3) & (~3));
      copy4(e->p0, p, (e->size0 + 3) & (~3));
      p += (e->size0 + 3) & (~3);
    }

    *((Block4 *) (D_800C02AE + 0x7f66)) = *((Block4 *) D_800C35A0);
    {
      u32 dest = (u32) D_800C35A0;
      u32 end = ((u32) p) + 0xf4;
      if ((dest < end) & (((u32) p) < dest))
      {
        u32 *dst = (u32 *) (dest + 0xf4);
        s32 n = 61;
        u32 *src = (u32 *) end;
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
        u32 *src = (u32 *) p;
        u32 *dst = (u32 *) dest;
        s32 n = 61;
        do
        {
          u32 v = *(src++);
          *(dst++) = v;
          --n;
        }
        while (new_var = n);
      }
    }
    *((u16 *) (D_800C35A0 + 0x2c)) = (*((u16 *) (D_800C02AE + 0x7f92))) | 0x10;
    base[0x114] = 0;
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
