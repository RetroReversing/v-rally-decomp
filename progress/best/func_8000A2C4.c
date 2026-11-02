typedef struct 
{
  u32 w0;
  u32 w1;
} Gfx;
typedef struct 
{
  s16 x;
  s16 y;
  s16 w;
  s16 h;
  u8 pad[0x24];
  void *p;
} R;
typedef struct 
{
  u8 pad[0x10];
  s16 a0;
  u16 a1;
  s16 a2;
  u16 a3;
  s16 a4;
  u16 a5;
  s16 a6;
  u16 a7;
} Q;
s32 func_800056FC();
s32 func_80005C48(s32);
void *func_80006008(s32);
s32 func_80006014(s32, void *);
s32 osVirtualToPhysical(s32, void *);
extern s16 *D_8009B5A4;
extern s32 D_8009B5A8;
extern s32 D_8009B5D0;
void func_8000A2C4(void *a, s32 arg1, s32 arg2, u8 arg3)
{
  s16 *arg0 = a;
  char *q;
  s32 v;
  s32 t;
  s32 w;
  Gfx *g;
  Gfx *g0;
  Gfx *g1;
  Gfx *g2;
  Gfx *g3;
  Gfx *g4;
  Gfx *g5;
  Gfx *g6;
  Gfx *g7;
  Gfx *g8;
  Gfx *g9;
  q = *((char **) (((char *) a) + 0x2C));
  v = func_800056FC();
  g = func_80006008(v);
  t = func_80005C48(D_8009B5A8);
  g0 = g++;
  g0->w0 = 0xDE000000;
  g0->w1 = (u32) (&D_8009B5D0);
  g1 = g++;
  g1->w0 = 1;
  g1->w0 = ((D_8009B5A4[2] - g1->w0) & 0xFFF) | 0xFF100000;
  g1->w1 = osVirtualToPhysical(t, D_8009B5A4);
  if (!arg3)
  {
    *((s16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x10)) = 0;
    *((s16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x18)) = 0;
    *((s16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x14)) = arg1 * 4;
    *((s16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x1C)) = arg2 * 4;
    *((u16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x16)) = *((u16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x12));
    *((u16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x1E)) = *((u16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x1A));
    g2 = g;
    g2->w0 = ((((s32) (((f32) arg0[0]) * 4.0f)) & 0xFFF) << 12) | ((((s32) (((f32) arg0[1]) * 4.0f)) & 0xFFF) | 0xED000000);
    w = arg0[2];
  }
  else
  {
    *((s16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x10)) = 0;
    *((s16 *) ((*((char **) (((char *) a) + 0x2C))) + 0x18)) = 0;
    g2 = g;
    g2->w0 = ((((s32) (((f32) arg0[0]) * 4.0f)) & 0xFFF) << 12) | ((((s32) (((f32) arg0[1]) * 4.0f)) & 0xFFF) | 0xED000000);
    w = arg0[2] + 8;
  }
  g++;
  g2->w1 = ((((s32) (((f32) w) * 4.0f)) & 0xFFF) << 12) | (((s32) (((f32) arg0[3]) * 4.0f)) & 0xFFF);
 do { g3 = g++; g4 = g++; g5 = g++; g6 = g++; g7 = g++; g8 = g++; g3->w0 = 0xE200001C; g3->w1 = 0; g4->w1 = 0x200000; g4->w0 = 0xE3000A01; g4->w1 = 0x200000; g5->w1 = 0x8000; g5->w0 = 0xE3001001; g6->w0 = 0x05000017; g6->w1 = ((u32) q) + 0x38; g7->w0 = 0xE7000000; g7->w1 = 0; g8->w0 = 0x0A000000; } while (0);
  g8->w1 = ((u32) q) + 0x10;
  g9 = g++;
  g9->w0 = 0xE7000000;
  g9->w1 = 0;
  g9->w0 = 0xE7000000;
  g9->w1 = 0;
  g9->w0 = 0xE7000000;
g9->w1 = 0;
  g = g + 0;
  func_80006014(v, g);
}
