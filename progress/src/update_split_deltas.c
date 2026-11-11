typedef struct { s32 v; s32 pad[3]; } Sample;
extern Sample D_800C3650[4][4];
extern s32 D_800ADF30[4];
extern u16 g_split_deltas[12];
u8 func_8006B924(Sample *);

/* For each of the 4 players and 3 splits, stores the time difference from the reference
   split time as a u16: magnitude in the low 14 bits, sign in bit 0, the lookup code in
   bits 14-15. A code of 5 means no entry matched, and the delta is set to 0xFFFF. */
void update_split_deltas(void)
{
  u16 *out;
  u8 i;
  u8 j;
  u8 code;
  s32 d;

  out = g_split_deltas;
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
