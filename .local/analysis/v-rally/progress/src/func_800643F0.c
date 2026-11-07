typedef struct { u8 b; u8 pad[0x17]; } E18;
extern E18 D_800C7FA1[];
extern u8 D_800C81FC;
extern u8 D_800A16D4;
extern u8 *D_800A1468;
extern char D_800C02AE[];
void func_8005C198(void);
void func_8005E470(s32, s32);
void func_8005E28C(s32, s32);

s32 func_800643F0(s32 arg0, s32 arg1)
{
  u8 *p;
  u8 *q;
  u8 i;
  u32 v;
  u16 t;

  func_8005C198();
  func_8005E470(arg0, arg1);
  i = 1;
  D_800A1468[0x2BD] = 1;
  p = *(u8 **)(D_800C02AE + 0x32F2);
  if (*(u16 *)(p + 0x2C) & 0x800) {
    *(s16 *)(p + 0x1E) = 8;
    v = p[0x23] & 3;
    D_800C7FA1[0].b = v;
    if (v == 0) { D_800C81FC = i; } else { D_800C81FC = 0; }
    v &= 0xFF;
    do {
      if (i == v) {
        D_800C7FA1[i].b = 0;
        i++;
      } else {
        D_800C7FA1[i].b = i;
        i++;
      }
    } while (i < 4);
    q = *(u8 **)(D_800C02AE + 0x32F2);
    t = *(u16 *)(q + 0x20);
    *(u16 *)(q + 0x20) = 0;
    *(u16 *)(q + 0x22) = t;
  }
  D_800A16D4 = 1;
  func_8005E28C(0, 0);
  return 0;
}
