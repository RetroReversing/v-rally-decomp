#define H(o) (*(s16*)(p+(o)))
#define U(o) (*(u16*)(p+(o)))
#define W(o) (*(s32*)(p+(o)))
#define CMD(a,b) {u32 *q=cmd;cmd+=2;q[0]=(a);q[1]=(b);}
extern s32 osVirtualToPhysical(s32);
extern void func_800914E0(void *, void *, s32);
extern u16 _getRate(f64, f64, s32, void *);
extern s16 D_800A38A0[];
extern s32 D_800A7070;
extern s32 D_800A7074;
void *_pullSubFrame(u8 *p, u16 *arg1, s16 *arg2, s32 n, s32 arg4, u32 *cmd)
{
  void *input = *((void **) p);
  u32 *last;
  s16 rate;
  if ((W(0x48) != 1) || (n == 0))
  {
    return cmd;
  }
  if (!input)
  {
    func_800914E0(&D_800A7070, &D_800A7074, 0x16f);
  }
  cmd = ((u32 *(*)(void *, u16 *, s32, s32, u32 *)) (*((u32 *) (((u8 *) input) + 4))))(input, arg1, n, arg4, cmd);
  CMD((*arg1) | 0x08000000, (((*arg2) + 0x440) << 16) | ((n * 2) & 0xffff));
  CMD((((*arg2) + 0x580) & 0xffff) | 0x08080000, (((*arg2) + 0x6c0) << 16) | (((*arg2) + 0x800) & 0xffff));
 { if (W(0x38)) { W(0x38) = 0; rate = (H(0x1a) * D_800A38A0[H(0x18)]) >> 15; U(0x28) = rate; U(0x26) = _getRate(H(0x1c), rate, W(0x34), p + 0x24); rate = (H(0x1a) * D_800A38A0[127 - H(0x18)]) >> 15; U(0x2e) = rate; U(0x2c) = _getRate(H(0x1e), rate, W(0x34), p + 0x2a); CMD(U(0x1c) | 0x09060000, 0); CMD(U(0x1e) | 0x09040000, 0); CMD(U(0x28) | 0x09020000, (U(0x26) << 16) | U(0x24)); CMD(U(0x2e) | 0x09000000, (U(0x2c) << 16) | U(0x2a)); CMD(U(0x20) | 0x09080000, U(0x22)); last = cmd; last[0] = 0x03090000; } else { last = cmd; last[0] = 0x03080000; } cmd = cmd + 2; }
  last[1] = osVirtualToPhysical(W(0x14));
  *arg1 += n * 2;
  W(0x30) += n;
  return cmd;
}
