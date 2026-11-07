typedef struct { s32 v; s32 pad[3]; } Sample;
extern Sample D_800C3650[4][4];
extern s32 D_800ADF30[4];
extern u16 D_800C7206[12];
u8 func_8006B924(Sample *);

void func_8006CE1C(void)
{
  u16 *out;
  u8 i;
  u8 j;
  u8 code;
  s32 d;

  out = D_800C7206;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      code = func_8006B924(&D_800C3650[i][j]);
      if (code == 5) {
        out[i * 3 + j] = 0xFFFF;
      } else {
        d = D_800ADF30[i] - D_800C3650[i][j].v;
        if (d >= 0) {
          if (d >= 0x4000) d = 0x3FFE;
          d &= ~1;
        } else {
          d = -d;
          if (d >= 0x4000) d = 0x3FFE;
          d |= 1;
        }
        out[i * 3 + j] = d | (code << 14);
      }
    }
  }
}
