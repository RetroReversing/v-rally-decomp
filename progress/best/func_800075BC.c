typedef struct 
{
  u32 w0;
  u32 w1;
} Gfx;
typedef struct 
{
  char pad[20];
  Gfx *dl;
} Draw;
typedef struct 
{
  char pad[4];
  u16 format;
  u16 width;
  u16 height;
  char padA[6];
  void **palettes;
  void **images;
} Tex;
u32 osVirtualToPhysical(void *);
s32 func_800075BC(Draw *draw, Tex *texture, s32 arg2)
{
  Tex *arg1 = texture;
  Draw *arg0 = draw;
  u32 sync;
  s32 var_a0;
  u16 new_var2;
  s32 var_a0_2;
  s32 var_a0_3;
  s32 var_a0_4;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v1;
  s32 var_v1_2;
  unsigned short var_v1_3;
  u16 temp_a0;
  u16 new_var;
  u16 temp_a0_4;
  u16 temp_a0_7;
  u16 temp_v1_4;
  u32 temp_a1;
  u32 temp_a1_2;
  u32 temp_a1_3;
  Gfx *temp_a0_2;
  Gfx *temp_a0_5;
  Gfx *temp_a0_6;
  Gfx *temp_a0_8;
  Draw *new_var3;
  Gfx *temp_a0_9;
  Gfx *temp_s0;
  Gfx *temp_s0_2;
  Gfx *temp_s0_3;
  Gfx *temp_s0_4;
  Gfx *temp_s0_5;
  Gfx *temp_v0;
  Gfx *temp_v1;
  Gfx *temp_v1_10;
  Gfx *temp_v1_11;
  Gfx *temp_v1_12;
  Gfx *temp_v1_13;
  Gfx *temp_v1_14;
  Gfx *temp_v1_15;
  Gfx *temp_v1_16;
  Gfx *temp_v1_17;
  Gfx *temp_v1_18;
  Gfx *temp_v1_19;
  Gfx *temp_v1_20;
  Gfx *temp_v1_21;
  Gfx *temp_v1_22;
  Gfx *temp_v1_23;
  Gfx *temp_v1_2;
  Gfx *temp_v1_3;
  Gfx *temp_v1_5;
  Gfx *temp_v1_6;
  Gfx *temp_v1_7;
  Gfx *temp_v1_8;
  Gfx *temp_v1_9;
  temp_v1 = arg0->dl;
  arg0->dl = temp_v1 + 1;
  temp_v1->w0 = 0xD7000002;
  temp_v1->w1 = 0x80008000;
  temp_v1_2 = arg0->dl;
  arg0->dl = temp_v1_2 + 1;
  temp_v1_2->w0 = 0xE3001201;
  temp_v1_2->w1 = 0x2000;
  temp_v1_3 = arg0->dl;
  arg0->dl = temp_v1_3 + 1;
  temp_v1_3->w0 = 0xE3000C00;
  temp_v1_3->w1 = 0x80000;
  temp_v1_4 = arg1->format;
  switch ((s32) temp_v1_4)
  {
    case 0x10:
      temp_s0 = arg0->dl;
      arg0->dl = temp_s0 + 1;
      temp_s0->w0 = 0xFD500000;
      temp_s0->w1 = osVirtualToPhysical(arg1->images[arg2 & 255]);
      temp_v1_5 = arg0->dl;
      arg0->dl = temp_v1_5 + 1;
      temp_v1_5->w0 = 0xF5500000;
      temp_v1_5->w1 = 0x07000000;
      temp_v1_6 = arg0->dl;
      arg0->dl = temp_v1_6 + 1;
      temp_v1_6->w0 = 0xE6000000;
      temp_v1_6->w1 = 0;
      temp_v1_7 = arg0->dl;
      arg0->dl = temp_v1_7 + 1;
      temp_v1_7->w0 = 0xF3000000;
      temp_a0 = arg1->width;
      temp_a1 = temp_a0 >> 4;
      var_v1 = 0x800;
      if (temp_a1 != 0)
    {
      var_v1 = temp_a1 + 0x7FF;
    }
      var_a0 = (((s32) ((temp_a0 * arg1->height) + 3)) >> 2) - 1;
      if (var_a0 >= 0x800)
    {
      var_a0 = 0x7FF;
    }
      var_a0 = ((var_a0 & 0xfff) << 12) | 0x07000000;
      if (temp_a1 != 0)
    {
      var_v0 = (var_v1 / ((s32) temp_a1)) & 0xFFF;
    }
    else
    {
      var_v0 = var_v1 & 0xFFF;
    }
      temp_v1_7->w1 = (s32) (var_a0 | var_v0);
      temp_v1_8 = arg0->dl;
      arg0->dl = temp_v1_8 + 1;
      temp_v1_8->w0 = (sync = 0xE7000000);
      temp_v1_8->w1 = 0;
      temp_a0_2 = arg0->dl;
      arg0->dl = temp_a0_2 + 1;
      new_var = (u16) arg1->width;
      temp_a0_9 = temp_a0_2;
      temp_a0_9->w1 = 0;
      temp_a0_9->w0 = (s32) ((((((s32) ((new_var >> 1) + 7)) >> 3) & 0x1FF) << 9) | 0xF5400000);
      temp_a0_2 = arg0->dl;
      arg0->dl = temp_a0_2 + 1;
      temp_a0_2->w0 = 0xF2000000;
      temp_a0_2->w1 = (s32) (((((arg1->width - 1) * 4) & 0xFFF) << 0xC) | (((arg1->height - 1) * 4) & 0xFFF));
      temp_s0_2 = arg0->dl;
      arg0->dl = temp_s0_2 + 1;
      temp_s0_2->w0 = 0xFD100000;
      temp_s0_2->w1 = osVirtualToPhysical(*arg1->palettes);
      temp_v1_9 = arg0->dl;
      arg0->dl = temp_v1_9 + 1;
      temp_v1_9->w0 = 0xE8000000;
      temp_v1_9->w1 = 0;
      temp_v1_10 = arg0->dl;
      arg0->dl = temp_v1_10 + 1;
      temp_v1_10->w0 = 0xF5000100;
      temp_v1_10->w1 = 0x07000000;
      temp_v1_11 = arg0->dl;
      arg0->dl = temp_v1_11 + 1;
      temp_v1_11->w0 = 0xE6000000;
      temp_v1_11->w1 = 0;
      var_a0_2 = 0x07030000;
      goto block_22;

    case 0x100:
      temp_s0_3 = arg0->dl;
      arg0->dl = temp_s0_3 + 1;
      temp_s0_3->w0 = 0xFD500000;
      temp_s0_3->w1 = osVirtualToPhysical(arg1->images[arg2 & 255]);
      temp_v1_12 = arg0->dl;
      arg0->dl = temp_v1_12 + 1;
      temp_v1_12->w0 = 0xF5500000;
      temp_v1_12->w1 = 0x07000000;
      temp_v1_13 = arg0->dl;
      arg0->dl = temp_v1_13 + 1;
      temp_v1_13->w0 = 0xE6000000;
      temp_v1_13->w1 = 0;
      temp_v1_14 = arg0->dl;
      arg0->dl = temp_v1_14 + 1;
      temp_v1_14->w0 = 0xF3000000;
      temp_a0_4 = arg1->width;
      temp_a1_2 = temp_a0_4 >> 3;
      var_v1_2 = 0x800;
      if (temp_a1_2 != 0)
    {
      var_v1_2 = temp_a1_2 + 0x7FF;
    }
      var_a0_3 = (((s32) ((temp_a0_4 * arg1->height) + 1)) >> 1) - 1;
      if (var_a0_3 >= 0x800)
    {
      var_a0_3 = (double) 0x7FF;
    }
      var_a0_3 = ((var_a0_3 & 0xfff) << 12) | 0x07000000;
      if (temp_a1_2 != 0)
    {
      var_v0_2 = (var_v1_2 / ((s32) temp_a1_2)) & 0xFFF;
    }
    else
    {
      var_v0_2 = var_v1_2 & 0xFFF;
    }
      temp_v1_14->w1 = (s32) (var_a0_3 | var_v0_2);
      temp_v1_15 = arg0->dl;
      arg0->dl = temp_v1_15 + 1;
      temp_v1_15->w0 = (sync = 0xE7000000);
      temp_v1_15->w1 = 0;
      temp_a0_5 = arg0->dl;
      arg0->dl = temp_a0_5 + 1;
      temp_a1_3 = (s32) ((((((s32) (arg1->width + 7)) >> 3) & 0x1FF) << 9) | 0xF5480000);
      temp_a0_5->w1 = 0;
      temp_a0_5->w0 = temp_a1_3;
      temp_a0_6 = arg0->dl;
      arg0->dl = temp_a0_6 + 1;
      temp_a0_6->w0 = 0xF2000000;
      temp_a0_6->w1 = (s32) (((((arg1->width - 1) * 4) & 0xFFF) << 0xC) | (((arg1->height - 1) * 4) & 0xFFF));
      temp_s0_4 = arg0->dl;
      arg0->dl = temp_s0_4 + 1;
      temp_s0_4->w0 = 0xFD100000;
      arg0->dl->w1 = osVirtualToPhysical(*arg1->palettes);
      temp_v1_16 = arg0->dl;
      arg0->dl = temp_v1_16 + 1;
      temp_v1_16->w0 = 0xE8000000;
      temp_v1_16->w1 = 0;
      temp_v1_17 = arg0->dl;
      arg0->dl = temp_v1_17 + 1;
      temp_v1_17->w0 = 0xF5000100;
      temp_v1_17->w1 = 0x07000000;
      ;
      temp_v1_18 = arg0->dl;
      arg0->dl = temp_v1_18 + 1;
      temp_v1_18->w0 = 0xE6000000;
      temp_v1_18->w1 = 0;
      var_a0_2 = 0x073F0000;
      ;
      block_22:
    temp_v1_18 = arg0->dl;

      arg0->dl++;
      temp_v1_18->w0 = 0xF0000000;
      temp_v1_18->w1 = (s32) (0x073F0000 | 0xC000);
      temp_v0 = arg0->dl;
      arg0->dl = temp_v0 + 1;
      temp_v0->w0 = sync;
      temp_v0->w1 = 0;
      goto block_31;

    case 0xa0:
      temp_s0_5 = arg0->dl;
      new_var3 = arg0;
      new_var3->dl = temp_s0_5 + 1;
      temp_s0_5->w0 = 0xFD180000;
      temp_s0_5->w1 = osVirtualToPhysical(texture->images[arg2 & 255]);
      temp_v1_19 = new_var3->dl;
      new_var3->dl = temp_v1_19 + 1;
      temp_v1_19->w0 = 0xF5180000;
      temp_v1_19->w1 = 0x07000000;
      temp_v1_20 = new_var3->dl;
      new_var3->dl = temp_v1_20 + 1;
      temp_v1_20->w0 = 0xE6000000;
      temp_v1_20->w1 = 0;
      temp_v1_21 = new_var3->dl;
      new_var3->dl = temp_v1_21 + 1;
      temp_v1_21->w0 = 0xF3000000;
      temp_a0_7 = arg1->width;
      temp_a1_3 = temp_a0_7 >> 1;
      var_v1_3 = 0x800;
      if (((s32) temp_a1_3) > 0)
    {
      var_v1_3 = temp_a1_3 + 0x7FF;
    }
      var_a0_4 = (temp_a0_7 * arg1->height) - 1;
      if (var_a0_4 >= 0x800)
    {
      var_a0_4 = 0x7FF;
    }
      var_a0_4 = ((var_a0_4 & 0xfff) << 12) | 0x07000000;
      do
    {
      if (((s32) temp_a1_3) > 0)
      {
        var_v0_3 = (var_v1_3 / ((s32) temp_a1_3)) & 0xFFF;
      }
      else
      {
        var_v0_3 = var_v1_3 & 0xFFF;
      }
      temp_v1_21->w1 = (s32) (var_a0_4 | var_v0_3);
      temp_v1_22 = new_var3->dl;
      new_var3->dl = temp_v1_22 + 1;
      temp_v1_22->w0 = 0xE7000000;
      temp_v1_22->w1 = 0;
      temp_a0_8 = new_var3->dl;
      new_var3->dl = temp_a0_8 + 1;
      new_var2 = texture->width;
      temp_a0_8->w1 = 0;
      temp_a0_8->w0 = (s32) ((((((s32) ((new_var2 * 2) + 7)) >> 3) & 0x1FF) << 9) | 0xF5180000);
      temp_a0_9 = new_var3->dl;
      new_var3->dl = temp_a0_9 + 1;
      temp_a0_9->w0 = 0xF2000000;
      temp_a0_9->w1 = (s32) (((((texture->width - 1) * 4) & 0xFFF) << 0xC) | (((texture->height - 1) * 4) & 0xFFF));
      temp_v1_23 = arg0->dl;
      new_var3->dl = temp_v1_23 + 1;
      temp_v1_23->w0 = 0xE3001001;
      temp_v1_23->w1 = 0;
      break;
    }
    while (0);

  }

  block_31:
  return 0;

}
