typedef struct 
{
  u32 w0;
  u32 w1;
} Gfx;
typedef struct 
{
  char pad[0x14];
  Gfx *dl;
  char pad18[0x64];
  void *image;
  void *palette;
  s32 flags;
  u16 height;
  u16 width;
} RenderState;
typedef struct 
{
  u32 unused;
  u16 format;
  u16 width;
  u16 height;
  char pad[6];
  void **palettes;
  void **images;
} Texture;
u32 osVirtualToPhysical(void *);
s32 func_80009164(RenderState *, Texture *, u8);
s32 func_80009164(RenderState *arg0, Texture *arg1, u8 arg2)
{
  Gfx *p;
  void *oldImage;
  void *oldPalette;
  Gfx *temp_a0_10;
  Gfx *temp_a0_3;
  Gfx *temp_a0_4;
  Gfx *temp_a0_6;
  Gfx *temp_a0_7;
  Gfx *temp_a0_9;
  Gfx *temp_s0;
  Gfx *temp_s0_2;
  Gfx *temp_s0_3;
  Gfx *temp_s0_4;
  Gfx *temp_s0_5;
  Gfx *temp_v1_10;
  Gfx *temp_v1_11;
  Gfx *temp_v1_12;
  Gfx *temp_v1_13;
  Gfx *temp_v1_15;
  Gfx *temp_v1_16;
  Gfx *temp_v1_17;
  Gfx *temp_v1_18;
  Gfx *temp_v1_19;
  Gfx *temp_v1_20;
  Gfx *temp_v1_21;
  Gfx *temp_v1_22;
  Gfx *temp_v1_2;
  Gfx *temp_v1_3;
  Gfx *temp_v1_4;
  Gfx *temp_v1_5;
  Gfx *temp_v1_7;
  Gfx *temp_v1_8;
  Gfx *temp_v1_9;
  s32 temp_v1_14;
  s32 temp_v1_6;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a0_3;
  s32 var_a0_4;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v1;
  s32 var_v1_2;
  s32 var_v1_3;
  u16 temp_a0_2;
  u16 temp_a0_5;
  u16 temp_a0_8;
  u16 temp_v1;
  u16 width;
  u32 tile;
  s32 temp_a0;
  u32 temp_a1;
  u32 temp_a1_2;
  u32 temp_a1_3;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  temp_a0 = arg0->flags;
  temp_a0 &= 0x7FFFFFFF;
  temp_a0 |= 0x80000000;
  arg0->flags = temp_a0;
  temp_v1 = arg1->format;
  switch (temp_v1)
  {
    case 0x10:
      arg0->flags = (temp_a0 & 0xFCFFFFFF) | 0x01000000;
      oldImage = arg0->image;
      temp_v0 = *arg1->images;
      if (oldImage != temp_v0)
    {
      arg0->image = temp_v0;
      temp_s0 = arg0->dl;
      arg0->height = arg1->height;
      width = arg1->width;
      arg0->dl = temp_s0 + 1;
      arg0->width = width;
      temp_s0->w0 = 0xFD500000;
      temp_s0->w1 = osVirtualToPhysical(*arg1->images);
      temp_v1_2 = arg0->dl;
      arg0->dl = temp_v1_2 + 1;
      temp_v1_2->w0 = 0xF5500000;
      temp_v1_2->w1 = 0x07000000;
      temp_v1_3 = arg0->dl;
      arg0->dl = temp_v1_3 + 1;
      temp_v1_3->w0 = 0xE6000000;
      temp_v1_3->w1 = 0;
      temp_v1_4 = arg0->dl++;
      temp_v1_4->w0 = 0xF3000000;
      temp_a0_2 = arg1->width;
      temp_a1 = temp_a0_2 >> 4;
      var_v1 = 0x800;
      if (temp_a1 != 0)
      {
        var_v1 = temp_a1 + 0x7FF;
      }
      var_a0 = (((s32) ((temp_a0_2 * arg1->height) + 3)) >> 2) - 1;
      if (var_a0 >= 0x800)
      {
        var_a0 = 0x7FF;
      }
      tile = ((var_a0 & 0xFFF) << 12) | 0x07000000;
      if (temp_a1 != 0)
      {
        var_v0 = (var_v1 / ((s32) temp_a1)) & 0xFFF;
      }
      else
      {
        var_v0 = var_v1 & 0xFFF;
      }
      temp_v1_4->w1 = tile | var_v0;
      temp_v1_5 = arg0->dl;
      arg0->dl = temp_v1_5 + 1;
      temp_v1_5->w0 = 0xE7000000;
      temp_v1_5->w1 = 0;
      temp_a0_3 = arg0->dl;
      arg0->dl = temp_a0_3 + 1;
      temp_a0_3->w0 = (((((s32) ((((u16) arg1->width) >> 1) + 7)) >> 3) & 0x1FF) << 9) | 0xF5400000;
      temp_a0_3->w1 = 0;
      temp_a0_4 = arg0->dl;
      arg0->dl = temp_a0_4 + 1;
      temp_a0_4->w0 = 0xF2000000;
      temp_a0_4->w1 = ((((arg1->width - 1) * 4) & 0xFFF) << 0xC) | (((arg1->height - 1) * 4) & 0xFFF);
    }
      temp_v1_6 = arg2 & 0xFF;
      temp_v0_2 = arg1->palettes[temp_v1_6];
      oldPalette = arg0->palette;
      if (oldPalette != temp_v0_2)
    {
      temp_s0_2 = arg0->dl;
      arg0->palette = temp_v0_2;
      arg0->dl = temp_s0_2 + 1;
      temp_s0_2->w0 = 0xFD100000;
      temp_s0_2->w1 = osVirtualToPhysical(arg1->palettes[temp_v1_6]);
      temp_v1_7 = arg0->dl;
      arg0->dl = temp_v1_7 + 1;
      temp_v1_7->w0 = 0xE8000000;
      temp_v1_7->w1 = 0;
      temp_v1_8 = arg0->dl;
      temp_v1_8->w0 = 0xF5000100;
      arg0->dl = temp_v1_8 + 1;
      temp_v1_8->w0 = 0xF5000100;
      temp_v1_8->w1 = 0x07000000;
      temp_v1_9 = arg0->dl;
      arg0->dl = temp_v1_9 + 1;
      temp_v1_9->w0 = 0xE6000000;
      temp_v1_9->w1 = 0;
      p = arg0->dl;
      var_a0_2 = 0x0703C000;
      goto block_28;
    }
      goto block_38;

    case 0x100:
      arg0->flags = (temp_a0 & 0xFCFFFFFF) | 0x01000000;
      oldImage = arg0->image;
      temp_v0_3 = *arg1->images;
      if (oldImage != temp_v0_3)
    {
      arg0->image = temp_v0_3;
      temp_s0_3 = arg0->dl;
      arg0->height = arg1->height;
      width = arg1->width;
      arg0->dl = temp_s0_3 + 1;
      arg0->width = width;
      temp_s0_3->w0 = 0xFD500000;
      temp_s0_3->w1 = osVirtualToPhysical(*arg1->images);
      temp_v1_10 = arg0->dl;
      arg0->dl = temp_v1_10 + 1;
      temp_v1_10->w0 = 0xF5500000;
      temp_v1_10->w1 = 0x07000000;
      temp_v1_11 = arg0->dl;
      arg0->dl = temp_v1_11 + 1;
      temp_v1_11->w0 = 0xE6000000;
      temp_v1_11->w1 = 0;
      temp_v1_12 = arg0->dl++;
      temp_v1_12->w0 = 0xF3000000;
      temp_a0_5 = arg1->width;
      temp_a1_2 = temp_a0_5 >> 3;
      var_v1_2 = 0x800;
      if (temp_a1_2 != 0)
      {
        var_v1_2 = temp_a1_2 + 0x7FF;
      }
      var_a0_3 = (((s32) ((temp_a0_5 * arg1->height) + 1)) >> 1) - 1;
      if (var_a0_3 >= 0x800)
      {
        var_a0_3 = 0x7FF;
      }
      tile = ((var_a0_3 & 0xFFF) << 12) | 0x07000000;
      if (temp_a1_2 != 0)
      {
        var_v0_2 = (var_v1_2 / ((s32) temp_a1_2)) & 0xFFF;
      }
      else
      {
        var_v0_2 = var_v1_2 & 0xFFF;
      }
      temp_v1_12->w1 = tile | var_v0_2;
      temp_v1_13 = arg0->dl;
      arg0->dl = temp_v1_13 + 1;
      temp_v1_13->w0 = 0xE7000000;
      temp_v1_13->w1 = 0;
      temp_a0_6 = arg0->dl;
      arg0->dl = temp_a0_6 + 1;
      temp_a0_6->w0 = (((((s32) (arg1->width + 7)) >> 3) & 0x1FF) << 9) | 0xF5480000;
      temp_a0_6->w1 = 0;
      temp_a0_7 = arg0->dl;
      arg0->dl = temp_a0_7 + 1;
      temp_a0_7->w0 = 0xF2000000;
      temp_a0_7->w1 = ((((arg1->width - 1) * 4) & 0xFFF) << 0xC) | (((arg1->height - 1) * 4) & 0xFFF);
    }
      temp_v1_14 = arg2 & 0xFF;
      oldPalette = arg0->palette;
      temp_v0_4 = arg1->palettes[temp_v1_14];
      if (oldPalette != temp_v0_4)
    {
      temp_s0_4 = arg0->dl;
      arg0->palette = temp_v0_4;
      arg0->dl = temp_s0_4 + 1;
      temp_s0_4->w0 = 0xFD100000;
      temp_s0_4->w1 = osVirtualToPhysical(arg1->palettes[temp_v1_14]);
      temp_v1_15 = arg0->dl;
      arg0->dl = temp_v1_15 + 1;
      temp_v1_15->w0 = 0xE8000000;
      temp_v1_15->w1 = 0;
      temp_v1_16 = arg0->dl;
      arg0->dl = temp_v1_16 + 1;
      temp_v1_16->w0 = 0xF5000100;
      temp_v1_16->w1 = 0x07000000;
      temp_v1_17 = arg0->dl;
      arg0->dl = temp_v1_17 + 1;
      temp_v1_17->w0 = 0xE6000000;
      temp_v1_17->w1 = 0;
      p = arg0->dl;
      var_a0_2 = 0x073FC000;
      p->w0 = 0xF0000000;
      block_28:
      arg0->dl = p + 1;

      p->w1 = var_a0_2;
      temp_v1_18 = arg0->dl;
      arg0->dl = temp_v1_18 + 1;
      temp_v1_18->w0 = 0xE7000000;
      temp_v1_18->w1 = 0;
    }
      goto block_38;

    case 0xA0:
      if (arg0->image != (*arg1->images))
    {
      arg0->flags = temp_a0 & 0xFCFFFFFF;
      temp_s0_5 = arg0->dl;
      arg0->height = arg1->height;
      width = arg1->width;
      arg0->dl = temp_s0_5 + 1;
      arg0->width = width;
      temp_s0_5->w0 = 0xFD180000;
      temp_s0_5->w1 = osVirtualToPhysical(*arg1->images);
      temp_v1_19 = arg0->dl;
      arg0->dl = temp_v1_19 + 1;
      temp_v1_19->w0 = 0xF5180000;
      temp_v1_19->w1 = 0x07000000;
      temp_v1_20 = arg0->dl;
 do { arg0->dl = temp_v1_20 + 1; temp_v1_20->w0 = 0xE6000000; temp_v1_20->w1 = 0; temp_v1_21 = arg0->dl++; temp_v1_21->w0 = 0xF3000000; temp_a0_8 = arg1->width; temp_a1_3 = temp_a0_8 >> 1; var_v1_3 = 0x800; if (((s32) temp_a1_3) > 0) { var_v1_3 = temp_a1_3 + 0x7FF; } var_a0_4 = (temp_a0_8 * arg1->height) - 1; if (var_a0_4 >= 0x800) { var_a0_4 = 0x7FF; } tile = ((var_a0_4 & 0xFFF) << 12) | 0x07000000; if (((s32) temp_a1_3) > 0) { var_v0_3 = (var_v1_3 / ((s32) temp_a1_3)) & 0xFFF; } else { var_v0_3 = var_v1_3 & 0xFFF; } temp_v1_21->w1 = tile | var_v0_3; temp_v1_22 = arg0->dl; arg0->dl = temp_v1_22 + 1; temp_v1_22->w0 = 0xE7000000; temp_v1_22->w1 = 0; temp_a0_9 = arg0->dl; arg0->dl = temp_a0_9 + 1; temp_a0_9->w0 = (((((s32) ((arg1->width * 2) + 7)) >> 3) & 0x1FF) << 9) | 0xF5180000; temp_a0_9->w1 = 0; temp_a0_10 = arg0->dl; arg0->dl = temp_a0_10 + 1; temp_a0_10->w0 = 0xF2000000; temp_a0_10->w1 = ((((arg1->width - 1) * 4) & 0xFFF) << 0xC) | (((arg1->height - 1) * 4) & 0xFFF); arg0->palette = NULL; } while (0);
    }

  }

  block_38:
  return 0;

}
