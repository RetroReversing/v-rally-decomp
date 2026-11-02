#define CFG32 ((Cfg *)(*(void **)(D_800C02AE + 0x32F2)))
#define CFG25 ((Cfg *)(*(void **)(D_800C02AE + 0x325A)))
typedef struct
{
  unsigned char b[0x2E];
} Cfg;
typedef struct
{
  unsigned char b[0x250];
} State;
typedef struct { u32 w[40]; } Blk;
extern State *D_800A1468;
extern s32 D_800A14D0;
extern u8 D_800C02AE[];
extern unsigned char D_800AE850[];
extern void func_800593FC(s32, s32);
extern void func_8005946C(s32, s32);
extern int func_8005A388(int, int);
extern void func_8005C198(void);
extern void func_8007EE9C(s32);
extern void func_8006603C(void);
extern void func_80066384(void);
extern void func_80066470(void);
s32 func_80065C04(s32 a0, s32 a1)
{
  s16 ver;
  ver = D_800A1468->b[0x23c];
  *((u16 *) (CFG32->b + 0x22)) = 0;
  *((s16 *) (CFG32->b + 0x1e)) = ver;
  if ((((*((u16 *) (CFG32->b + 0x2c))) & 0x100) == 0) && ((*((s16 *) (CFG25->b + 2))) == 2))
  {
    *((Blk *) (D_800AE850 + 0x7F28)) = *((Blk *) (CFG32->b + 0x44));
    D_800A1468->b[0x245] = 0;
    func_8005A388(a0, a1);
    *((void (**)(void)) (D_800A1468->b + 0x288)) = func_8006603C;
    *((void (**)(void)) (D_800A1468->b + 0x28c)) = func_80066384;
    *((void (**)(void)) (D_800A1468->b + 0x290)) = func_80066470;
    func_8005C198();
    if (D_800A14D0)
    {
      func_8007EE9C(D_800A14D0);
      D_800A14D0 = 0;
    }
    *((s16 *) (CFG32->b + 0x20)) = 0;
  }
  else
  {
    D_800A1468->b[0x245] = 1;
    if (*((s16 *) (CFG25->b + 2)) == 2)
    {
      func_800593FC(a0, 13);
    }
    else
    {
      func_800593FC(a0, 8);
    }
    func_8005946C(a0, *((u16 *) (CFG32->b + 0x22)));
  }
  return 1;
}
