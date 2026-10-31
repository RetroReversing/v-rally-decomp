typedef struct 
{
  u16 w[7];
} Rec14;
extern u8 D_800A16F4[];
extern Rec14 D_800C70D4[];
void func_8006F4A8(s32 arg0)
{
  s32 a3 = arg0 & 0xFF;
  u16 new_var;
  Rec14 *a2 = (Rec14 *) (((u8 *) D_800C70D4) + (a3 * 0xE));
  u16 v1;
  u16 v0;
  D_800A16F4[a3] = 2;
  v0 = a2->w[1] & 0xF000;
  a2->w[2] |= 0x8000;
  v1 = a2->w[0];
  a2->w[0] = ((v1 | 0x3D60) & 0xBD60) | (a3 & 0x1F);
  v1 = v0 | 0x492;
  a2->w[2] |= 0x7F00;
  ((u8 *) a2)[5] = 0x55;
  a2->w[1] = v1;
  new_var = v1;
  switch (v1 = a3)
  {
    case 0:
      v0 = (new_var & 0xFFF) | 0x4000;
      a2->w[1] = v0;
      break;

    case 1:
      v0 = (new_var & 0xFFF) | 0x7000;
      a2->w[1] = v0;
      break;

    case 2:
      v0 = (new_var & 0xFFF) | 0x6000;
      a2->w[1] = v0;
      break;

    case 3:
      v0 = (new_var & 0xFFF) | 0x5000;
      a2->w[1] = v0;
      break;

  }

  a2->w[5] = 0x4210;
  a2->w[6] = 0x7583;
  a2->w[4] = 0;
  ((u8 *) a2)[6] = 0x55;
  ((u8 *) a2)[7] = 0x55;
  a2->w[0] &= 0x7FFF;
}
