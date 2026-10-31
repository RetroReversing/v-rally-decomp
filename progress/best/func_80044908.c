#define W(p,o) (*(s32*)((u8*)(p)+(o)))
#define U(p,o) (*(u32*)((u8*)(p)+(o)))
#define P(p,o) (*(u8**)((u8*)(p)+(o)))
#define H(p,o) (*(s16*)((u8*)(p)+(o)))
#define UH(p,o) (*(u16*)((u8*)(p)+(o)))
extern u8 D_800A73E0[];
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 *D_800C35A0;
void func_80044908(void *arg0)
{
  u8 *__repair_cached_pointer = D_800C35A0;
  volatile s32 vA[4];
  volatile s32 vB[4];
  volatile s32 vC[4];
  int new_var;
  s16 temp_v1_2;
  s32 *var_v1;
  s32 temp_a0;
  s32 temp_a0_3;
  s32 temp_a0_4;
  s32 temp_a0_5;
  s32 temp_a1_4;
  s32 temp_a1_7;
  u8 *temp_a2;
  s32 temp_a2_2;
  s32 temp_a2_3;
  s32 temp_a3;
  s32 temp_a3_2;
  s32 temp_t0;
  s32 temp_t0_2;
  s32 temp_t1;
  s32 temp_t2;
  s32 temp_t3;
  int temp_t9;
  u8 *temp_v0;
  s32 temp_v1_4;
  s32 temp_v1_5;
  s32 temp_v1_6;
  u8 var_a1;
  s32 var_t3;
  s32 var_t8;
  s32 var_v0;
  u16 temp_v1_3;
  s32 var_t7;
  u32 temp_a0_2;
  u32 temp_a0_6;
  u32 temp_a1_3;
  u32 temp_s0;
  u32 old;
  void *temp_a1;
  void *temp_a1_5;
  void *temp_t6_2;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v1;
  void *var_a0;
  void *var_t4;
  void *othermesh;
  temp_a1 = P(arg0, 0x70);
  var_t8 = 0;
  temp_s0 = W(temp_a1, 0x4);
  var_t7 = UH(D_800A73E0, 0x6bfe);
  old = temp_s0;
  if (UH(__repair_cached_pointer, 0x1e) == 0)
  {
    if (((W(P(arg0, 0x48), 0) + 1) <= 4) && (!(W(arg0, 0x14) & 0x100)))
    {
      if (temp_a2_2)
      {
        temp_t6_2 = P(P(arg0, 0x8C), 0x28);
        W(temp_a1, 0x4) = (u32) H(temp_t6_2, 0x8);
      }
      else
      {
        temp_t6_2 = P(P(arg0, 0x8C), 0x28);
        W(temp_a1, 0x4) = (u32) H(temp_t6_2, 0x8);
      }
      if (temp_s0 != H(temp_t6_2, 0x8))
      {
        temp_a1 = P(temp_t6_2, 0x74);
        if (!(W(arg0, 0x14) & 0x20))
        {
          var_t7 = W(P(arg0, 0x48), 0);
          var_t8 = W(P(arg0, 0x6C), 4);
          temp_v1 = (var_t7 * 8) + temp_a1;
          W(temp_v1, 0x0) = var_t8;
          W(temp_v1, 0x4) = (s32) W(P(arg0, 0x70), 0x0);
          W(P(arg0, 0x6C), 0xC) = (s32) (W(temp_a1, 0x20) - W(temp_v1, 0x0));
        }
      }
    }
  }
  else
  {
    temp_t6_2 = P(P(arg0, 0x8C), 0x28);
    if (old == 0)
    {
      if (H(temp_t6_2, 0x8) == W(D_800A73E0, 0x6c08))
      {
        W(temp_a1, 0x8) = (s32) (W(temp_a1, 0x8) - 1);
      }
      else
      {
        goto block_10;
      }
    }
    else
    {
      new_var = 0x70;
      block_10:
      if ((old == W(D_800A73E0, 0x6c08)) && (H(temp_t6_2, 0x8) == 0))
      {
        var_v0 = W(P(arg0, new_var), 0x8) + 1;
        goto block_19;
      }

      temp_v1_2 = H(temp_t6_2, 0x8);
      if (old < ((u32) temp_v1_2))
      {
        var_v0 = W(P(arg0, 0x70), 8) + 1;
        goto block_19;
      }
      else
        if (((u32) temp_v1_2) < old)
      {
        var_v0 = W(P(arg0, 0x70), 8) - 1;
        block_19:
        W(P(arg0, 0x70), 8) = (char) var_v0;

      }
    }
    W(P(arg0, 0x70), 0x4) = (u32) H(temp_t6_2, 0x8);
    var_t4 = P(P(D_800AE850, 0x73f0), 0);
    temp_t9 = W(P(arg0, 0x70), 0x8);
    if (var_t4 != NULL)
    {
      do
      {
        if (var_t4 != arg0)
        {
          othermesh = P(P(var_t4, 0x8C), 0x28);
          temp_a0 = W(P(var_t4, 0x70), 0x8);
          if (!(W(var_t4, 0x14) & 0x100))
          {
            if (temp_a0 < temp_t9)
            {
              var_t7 -= 1;
            }
            else
              if (temp_t9 == temp_a0)
            {
              temp_a0_2 = W(P(arg0, 0x60), 0x28);
              temp_a1_3 = W(P(var_t4, 0x60), 0x28);
              if ((temp_a1_3 < temp_a0_2) & (temp_t6_2 == othermesh))
              {
                var_t7 -= 1;
              }
              else
                if (temp_a0_2 == temp_a1_3)
              {
                temp_t1 = W(P(arg0, 0x80), 0x2B8) - W(temp_t6_2, 0x24);
                vA[0] = temp_t1;
                temp_t2 = W(P(arg0, 0x80), 0x2C0) - W(temp_t6_2, 0x2C);
                vA[2] = temp_t2;
                temp_t0 = W(P(var_t4, 0x80), 0x2B8) - W(temp_t6_2, 0x24);
                vB[0] = temp_t0;
                temp_a3 = W(P(var_t4, 0x80), 0x2C0) - W(temp_t6_2, 0x2C);
                vB[2] = temp_a3;
                temp_v1_3 = UH(temp_t6_2, 0x8A);
                temp_a2 = P(temp_t6_2, 0x54);
                temp_t3 = (temp_a0_2 * temp_v1_3) + (temp_v1_3 >> 1);
                temp_a0_3 = (temp_t3 + temp_v1_3) * 6;
                temp_v1_4 = temp_t3 * 6;
                temp_t0_2 = temp_t0 - temp_t1;
                temp_a1_4 = H(temp_a2, temp_a0_3) - H(temp_a2, temp_v1_4);
                vC[0] = temp_a1_4;
                temp_v0 = P(temp_t6_2, 0x54);
                temp_a3_2 = temp_a3 - temp_t2;
                temp_a0_4 = H(temp_a0_3 + temp_v0, 4) - H(temp_v1_4 + temp_v0, 4);
                vA[0] = temp_t0_2;
                vA[2] = temp_a3_2;
                vC[2] = temp_a0_4;
                var_t7 -= ((temp_a1_4 * temp_t0_2) + (temp_a0_4 * temp_a3_2)) < 1;
              }
            }
          }
        }
        var_t4 = P(var_t4, 4);
      }
      while (var_t4 != NULL);
    }
    W(P(arg0, 0x6C), 0x8) = (s32) var_t7;
    if (var_t7 == 1)
    {
      W(P(arg0, 0x6C), 0xC) = 0;
    }
    else
    {
      var_a0 = P(P(D_800AE850, 0x73f0), 0);
      var_a1 = 0;
      if (var_a0 != NULL)
      {
        do
        {
          if (W(P(var_a0, 0x6C), 0x8) == (W(P(arg0, 0x6C), 0x8) - 1))
          {
            var_a1 = 1;
          }
          else
          {
            var_a0 = P(var_a0, 4);
          }
        }
        while ((var_a1 ^ 1) & (var_a0 != NULL));
      }
      if (var_a1 & 0xFF)
      {
        temp_a1_5 = P(arg0, 0x6C);
        temp_a2_2 = W(temp_a1_5, 0xC);
        temp_v1_5 = W(P(var_a0, 0x6C), 0xC);
        if (temp_a2_2 < temp_v1_5)
        {
          W(temp_a1_5, 0xC) = temp_v1_5;
          W(P(var_a0, 0x6C), 0xC) = temp_a2_2;
        }
      }
    }
    if ((temp_s0 != H(temp_t6_2, 0x8)) && ((temp_a1 = P(temp_t6_2, 0x74), var_t7 = var_t7 - 1, (W(arg0, 0x14) & 0x20) == 0)))
    {
      temp_a0_5 = W(P(arg0, 0x70), 0x0);
      var_t3 = 1;
      var_v1 = W(P(arg0, 0x6C), 0x0) + 4;
      {
        do
        {
          var_t3 += 1;
          var_t8 += *var_v1;
          var_v1 += 1;
        }
        while (var_t3 < temp_a0_5);
      }
      var_t8 = var_t8 + W(P(arg0, 0x6C), 0x4);
      temp_v0_2 = (var_t7 * 8) + temp_a1;
      W(temp_v0_2, 0x0) = var_t8;
      temp_v1_6 = W(P(arg0, 0x70), 0x0);
      W(temp_v0_2, 0x4) = temp_v1_6;
      if (var_t7 != 0)
      {
        if ((W(temp_a1, 0x4) == temp_v1_6) && ((temp_a0_6 = W(temp_a1, 0x0), temp_a0_6 != 0)))
        {
          if (temp_a0_6 < var_t8)
          {
            W(P(arg0, 0x6C), 0xC) = (s32) (var_t8 - temp_a0_6);
          }
        }
        else
        {
          temp_v0_3 = (var_t7 * 8) + temp_a1;
          temp_a2_3 = W(temp_v0_3, -0x4);
          temp_a1_7 = W(temp_v0_3, 0x4);
          if (temp_a1_7 < temp_a2_3)
          {
            W(P(arg0, 0x6C), 0xC) = (s32) ((temp_a2_3 - temp_a1_7) + 0x36EE80);
          }
        }
      }
    }
  }
}
