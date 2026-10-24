#include "common.h"

s32 func_8005060C();
extern void *D_800A1234;
extern void *D_800A1238;
extern char D_800AE850[];
extern char D_800C02AE[];
static inline char *inline_fn()
{
  return (char *) (*((void **) (D_800C02AE + 0x32F2)));
}

void func_800506D8(void)
{
  func_8005060C(D_800A1234);
  if (0 == (*((u16 *) (inline_fn() + 0x1E))))
  {
    func_8005060C(D_800A1238);
  }
 do { D_800A1234 = D_800AE850 + 0x2408; D_800A1238 = D_800C02AE + 0x592A; } while (0);
}
