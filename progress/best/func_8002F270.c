#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
typedef struct 
{
  u32 a;
  u32 b;
} Gfx;
void *func_80006008(void *);
void func_80006014(void *, void *);
void func_800061FC(void *, s32);
void func_800068C0(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80006EF8(void *, s32);
void func_800071EC(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_800075BC(void *, void *, s32);
void func_80008B28(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80010BFC(s32, void *, void *);
s32 func_8001BD1C(void);
void guMtxIdentF(void *);
extern u8 D_8009EB00[];
extern u8 D_8009EB40[];
extern s32 D_8009FF30;
extern f64 D_800A4A60;
extern u8 D_800C02AE[];
void func_8002F270(void *arg0, s32 *arg1, s32 arg2, void *arg3, void *arg4)
{
  struct 
  {
    f32 mat[16];
    u16 origin[4];
    s32 offset[3];
    s16 delta[4] __attribute__((aligned(8)));
  } tr;
  void *sp9C;
  volatile u8 spA7;
  register Gfx *g;
  Gfx *p;
  f64 temp_fs0;
  u16 temp_a0;
  s16 temp_a1;
  s16 temp_a2_2;
  register s32 var_v0_4;
  register s32 var_v0_5;
  s32 var_v0_6;
  s32 temp_s0;
  s32 temp_v0;
  s32 var_fp;
  register s32 var_s3;
  s32 var_s7;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v1;
  arg1 = arg1;
  var_s3 = 0;
  var_s7 = 1;
  var_fp = 0;
  spA7 = 0;
  *((u16 *) (((u8 *) arg4) + 0x78)) = 0;
  guMtxIdentF(tr.mat);
  if ((arg2--) != 0)
  {
    temp_fs0 = D_800A4A60;
    do
    {
      if ((*((s32 *) (((u8 *) (((u8 *) arg1) + 0x16)) + 0xA))) & 1)
      {
        if (spA7 == 0)
        {
          func_800075BC(arg4, arg3, 0);
          spA7 = 1;
        }
        if (var_s7 != 0)
        {
          var_s7 = 0;
          if (!(var_fp & 0xFF))
          {
            var_fp = 1;
            g = func_80006008(arg4);
            if (D_8009FF30 == 5)
            {
              p = g++;
              p->a = 0xDE000000;
              p->b = (u32) D_8009EB40;
            }
            else
            {
              p = g++;
              p->a = 0xDE000000;
              p->b = (u32) D_8009EB00;
            }
            p = (g += 1);
            p->a = 0xDE000000;
            p->b = (u32) D_8009EB00;
            p = g++;
            p->a = 0xFA000000;
            p->b = (((*((u8 *) (((u8 *) D_800C02AE) + 0x6C27))) << 24) | ((*((u8 *) (((u8 *) D_800C02AE) + 0x6C27))) << 16)) | ((*((u8 *) (((u8 *) D_800C02AE) + 0x6C27))) << 8);
            p = g++;
            p->a = 0xFB000000;
            p->b = ((((*((u8 *) (((u8 *) D_800C02AE) + 0x6C26))) << 24) | ((*((u8 *) (((u8 *) D_800C02AE) + 0x6C26))) << 16)) | ((*((u8 *) (((u8 *) D_800C02AE) + 0x6C26))) << 8)) | (*((u8 *) (((u8 *) D_800C02AE) + 0x6C28)));
            func_80006014(arg4, g);
          }
          temp_v0 = func_8001BD1C();
          tr.mat[12] = (f32) (*arg1);
          tr.mat[13] = (f32) (*((s32 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0x12))));
          tr.mat[14] = (f32) (*((s32 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-((int) 0xE)))));
          tr.origin[0] = (u16) (*arg1);
          tr.origin[1] = (u16) (*((s32 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0x12))));
          tr.origin[2] = (u16) (*((s32 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0xE))));
          tr.offset[0] = 0;
          tr.offset[1] = 0;
          tr.offset[2] = 0;
          var_v0_2 = (s32) ((*((f32 *) (((u8 *) (*((void **) (((u8 *) D_800C02AE) + 0x7cd6)))) + 0x118))) - ((f32) (*arg1)));
          if (0 > ((short) var_v0_2))
          {
            var_v0_2 = -var_v0_2;
          }
          var_s3 = 0;
          if (var_v0_2 < 0x1771)
          {
            var_v0_3 = (s32) ((*((f32 *) (((u8 *) (*((void **) (((u8 *) D_800C02AE) + 0x7cd6)))) + 0x120))) - ((f32) (*((s32 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0xE))))));
            if (var_v0_3 < 0)
            {
              var_v0_3 = -var_v0_3;
            }
            if (var_v0_3 < 0x1771)
            {
              var_s3 = func_80010BFC(temp_v0, (*((void **) (((u8 *) D_800C02AE) + 0x7cd6))) + 0x38, &tr);
              if (var_s3 != 1)
              {
                var_s7 = 1;
                goto block_40;
              }
              func_800061FC(arg4, temp_v0);
              goto block_36;
            }
            goto block_35;
          }
          goto block_35;
        }
        temp_a0 = (*arg1) - tr.origin[0];
        tr.delta[0] = temp_a0;
        temp_a2_2 = (*((s32 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0x12)))) - tr.origin[1];
        tr.delta[1] = temp_a2_2;
        var_v0_4 = temp_a0;
        if (0 > temp_a0)
        {
          var_v0_4 = -var_v0_4;
        }
        temp_a1 = (*((s32 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0xE)))) - tr.origin[2];
        tr.delta[2] = temp_a1;
        if (((f64) var_v0_4) < temp_fs0)
        {
          var_v0_5 = temp_a2_2;
          if (temp_a2_2 < 0)
          {
            var_v0_5 = -var_v0_5;
          }
          if (((f64) var_v0_5) < temp_fs0)
          {
            var_v0_6 = temp_a1;
            if (temp_a1 < 0)
            {
              var_v0_6 = -var_v0_6;
            }
            if (((f64) var_v0_6) < temp_fs0)
            {
              var_v1 = (*((s32 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0x12)))) - (*((s32 *) (((u8 *) (*((void **) (((u8 *) sp9C) + 0x5c)))) + 0x58)));
              if (0 > var_v1)
              {
                var_v1 = -var_v1;
              }
              if (var_v1 < 0xA0)
              {
                tr.offset[0] = (s32) temp_a0;
                tr.offset[1] = (s32) temp_a2_2;
                tr.offset[2] = (s32) temp_a1;
              }
              else
              {
                goto block_34;
              }
            }
            else
            {
              goto block_34;
            }
          }
          else
          {
            goto block_34;
          }
        }
        else
        {
          block_34:
          arg1 -= 9;

          ++arg2;
          var_s7 = 1;
          var_s3 = 0;
        }
        block_35:
        block_36:
        if (var_s3 != 1)
        {
          var_s7 = 1;
          goto block_40;
        }


        temp_s0 = func_80006EF8(arg4, 0) & 0xFFFF;
        func_800068C0(arg4, temp_s0, (s16) tr.offset[0], (s16) tr.offset[1], (s32) ((s16) tr.offset[2]), (s32) ((s16) ((*((u16 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0xA)))) + tr.offset[0])), (s32) ((s16) ((*((u16 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0x8)))) + tr.offset[1])), (s32) ((s16) ((*((u16 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0x6)))) + tr.offset[2])), (s32) ((s16) ((*((u16 *) (((u8 *) (((u8 *) arg1) + 0x16)) + 0x2))) + tr.offset[0])), (s32) ((s16) ((*((u16 *) (((u8 *) (((u8 *) arg1) + 0x16)) + 0x4))) + tr.offset[1])), (s32) ((s16) ((*((u16 *) (((u8 *) (((u8 *) arg1) + 0x16)) + 0x6))) + tr.offset[2])), (s32) ((s16) ((*((u16 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0x4)))) + tr.offset[0])), (s32) ((s16) ((*((u16 *) (((u8 *) (((u8 *) arg1) + 0x16)) + (-0x2)))) + tr.offset[1])), (s32) ((s16) ((*((u16 *) (((u8 *) (((u8 *) arg1) + 0x16)) + 0x0))) + tr.offset[2])));
        func_800071EC(arg4, temp_s0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        func_80008B28(arg4, temp_s0, 0, 0, (s32) (*((u16 *) (((u8 *) arg3) + 0x6))), 0, (s32) (*((u16 *) (((u8 *) arg3) + 0x6))), (s32) (*((u16 *) (((u8 *) arg3) + 0x8))), 0, (s32) (*((u16 *) (((u8 *) arg3) + 0x8))));
      }
      else
      {
        block_40:
        ;

        ;
      }
      arg1 += 9;
    }
    while ((arg2--) != 0);
  }
}

