#define U16_AT(p, o) (*(u16*)((p)+(o)))
#define S32_AT(p, o) (*(s32*)((p)+(o)))
#define PTR_AT(p, o) (*(u8**)((p)+(o)))
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 D_800A5E9C[];
extern u8 *D_800A1234;
extern u8 *D_800A17F4[];
extern u8 *D_800C35A0;
extern int func_80022184(void *);
extern void func_8002283C(void);
extern void func_80081540(void *);
extern u8 *func_80081664(int, void *);
extern u8 *func_8007EAA0(int, int);
extern void func_8007EE9C(void *);
extern void func_8008E13C(void *, void *, int);
extern void func_80098290(void *, void *, int);
typedef struct 
{
  u32 w[61];
} SaveState;
/* Loads the saved-game block for the current slot: a 0x118-byte header, a 6000-byte
 * block and a sized data block, into the working buffers. The saved mode picks the
 * track index; an unknown version word resets the track fields. */
void func_80077280(void)
{
  u8 *saveFile = 0;
  u8 *src;
  u8 *dst;
  u8 *state;
  u8 *allocation;
  u8 i;
  int k;
  long car;
  if (!func_80022184(D_800AE850 + 0x7320))
  {
    func_8002283C();
  }
  if (func_80022184(D_800AE850 + 0x7320))
  {
    dst = D_800A1234;
    func_80081540(D_800A5E9C);
    saveFile = func_80081664(1, D_800A17F4[U16_AT(D_800C35A0, 0x22)]);
    src = saveFile;
    __builtin_memcpy(dst, src, 0x118);
    allocation = func_8007EAA0(1, 6000);
    state = dst;
    PTR_AT(state, 4) = allocation;
    PTR_AT(state, 0) = func_8007EAA0(1, (S32_AT(state, 16) + 3) & (~3));
    U16_AT(state, 8) |= 1;
    src += 0x118;
    __builtin_memcpy(PTR_AT(state, 4), src, 6000);
    src += 6000;
    U16_AT(state, 12) = 0;
    func_8008E13C(PTR_AT(state, 0), src, (S32_AT(state, 16) + 3) & (~3));
    src += (S32_AT(state, 16) + 3) & (~3);
    *((SaveState *) (D_800C02AE + 0x7f66)) = *((SaveState *) D_800C35A0);
    __builtin_memcpy(D_800C35A0, src, 0xf4);
    U16_AT(D_800C35A0, 0x1e) = 8;
    for (i = 0; i < 4; i++)
    {
      k = i * 40;
      car = U16_AT(D_800C02AE, k + 0x7fb4);
      U16_AT(k + D_800C35A0, 0x4e) = car;
      func_80098290(D_800C35A0 + (k + 0x44), (D_800C02AE + k) + 0x7faa, car);
    }

    if ((D_800C02AE[0x7f4f] != 5) && (!(U16_AT(D_800C02AE, 0x7f92) & 0x800)))
    {
      switch (D_800C02AE[0x7f4f])
      {
        case 2:
          U16_AT(D_800C35A0, 0x20) = 0;
          U16_AT(D_800C35A0, 0x22) = 3;
          break;

        case 4:
          U16_AT(D_800C35A0, 0x20) = 0;
          U16_AT(D_800C35A0, 0x22) = 6;
          break;

        case 3:

        case 8:
          U16_AT(D_800C35A0, 0x20) = 0;
          U16_AT(D_800C35A0, 0x22) = 1;
          break;

      }

    }
  }
  func_8007EE9C(saveFile);
  {
  u8 *tail = D_800C35A0;
  if (U16_AT(tail, 0x1e) != 8)
  {
    U16_AT(tail, 0x1e) = 8;
    U16_AT(tail, 0x20) = 0;
    U16_AT(tail, 0x22) = 0;
    D_800C02AE[0x7f4e] = 0;
  }
  }
}
