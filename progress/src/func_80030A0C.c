typedef struct Sample
{
  u16 a;
  u16 b;
  s16 angle;
  char pad[6];
} Sample;
typedef struct Stats
{
  s16 a;
  s16 b;
  s16 c;
  s16 d;
  s16 e;
  s16 f;
  u16 mode;
  u8 eidx;
  u8 fidx;
  s16 rise;
  u16 fall;
  char pad14[4];
  s16 field18;
  u8 field1a;
  u8 pad1b;
  Sample *samples;
} Stats;
typedef struct Road
{
  char pad0[8];
  s16 index;
  u16 flags;
  char padc[0x4c];
  struct Road *prev;
  struct Road *next;
  char pad60[0x18];
  Stats *stats;
  char pad7c[0xc];
  u16 count;
} Road;
u16 func_8002D2A0(s32);
s32 func_8002D2C8(s32, s32);
void track_sample_lookup(Road *, s32, s32 *);
void getTrackPoint(Road *, s32, s32 *);
extern s32 gSnapIndex;
extern char D_800A73E0[];
extern char gStreamState[];
void func_80033724(void);
struct VolCount{char pad[136];volatile u16 count;};union VolRoad{Road road;};
typedef union{Road *ptr;u32 bits;} RootBits;
void func_80030A0C(Road *arg0)
{
  u32 heights[8];
  s32 p30[4];
  s32 p40[4];
  s32 p50[4];

int new_var4;
  u16 second_count;
s32 sp6C;
  u16 sp76;
  u16 sp7E;
  int new_var;
  Sample *sp84;
  char *sp8C;
  Sample *var_a2_2;
  Sample *var_a2_3;
  Sample *var_s3;
  s32 temp_a0_8;
  s32 temp_a0_9;
  s32 temp_v0_2;
  s16 var_v0_2;
  s32 *temp_v1_6;
  Road *temp_a0;
  s32 temp_a0_2;
  s32 temp_a0_3;
  s32 temp_a0_4;
  s32 temp_a0_6;
  s32 temp_a0_7;
  s32 temp_s3;
  s32 temp_v0_3;
  Road *temp_v0_5;
  s32 temp_v1_10;
  s32 temp_v1_2;
  s32 temp_v1_4;
  s32 temp_v1_7;
  s32 temp_v1_8;
  s32 temp_v1_9;
  Road *var_a0;
  s32 var_a0_2;
  s32 var_a0_3;
  s32 var_a0_4;
  Road *var_a0_5;
  Road *var_a0_6;
  s32 var_a0_7;
  s32 var_a1;
  u32 *new_var3;

  u32 var_a1_2;
  s32 var_a1_3;
  s32 var_a1_4;
  s32 var_a2;
  unsigned short new_var2;
  s32 var_fp;
  s32 var_s0;
  Road *var_s2;
  s32 var_s4;
  s32 var_v0_3;
  s32 var_v0_5;
  s32 var_v0_6;
  s32 var_v0_7;
  s32 var_a1_5;
  s32 var_a1_6;
  u16 temp_a0_5;
  u16 temp_v1;
  u16 temp_v1_11;
  u16 var_v0_4;
  u16 var_v0_8;
  u16 var_v1;
  s32 temp_v0;
  s32 temp_v1_3;
  s32 var_s1;
  s32 var_v0;
  void *temp_s0_3;
  Stats *temp_s6;
  void *temp_v0_4;
  Stats *temp_v0_6;
  void *temp_v1_5;
  u16 *flags;
  s16 *negative;
s16 phase_i;

  var_s2=(Road*)((RootBits)arg0).bits;
  sp6C = 0;
  sp76 = 0;
  sp8C = (char *) heights;
  do
  {
    temp_s6 = var_s2->stats;
    flags = &var_s2->flags;
    negative = &temp_s6->b;
    var_s2->index = sp76++;
    temp_s6->field1a = 0;
    sp84 = temp_s6->samples;
    var_s2->stats->field18 = 0;
    temp_s6->a = 0U;
    *negative = 0U;
    temp_v1 = var_s2->count;
    temp_v0 = temp_v1 >> 1;
    phase_i = (s16) temp_v0;

    if (((s32) temp_v0) < (temp_v1 - 2))
    {
      do
      {
        getTrackPoint((Road *) var_s2, (s32) ((s16) phase_i), &p30[0]);
        getTrackPoint((Road *) var_s2, ((s16) phase_i) + 1, &p40[0]);
        var_a0 = var_s2->next;
        if ((var_a0 != 0) && (((s16) phase_i) == (var_s2->count - 1)))
        {
          var_a1 = 1;
          getTrackPoint(var_a0, var_a1, p50);
        }
        else
        {
          var_a0 = var_s2;
          var_a1 = ((s16) phase_i) + 2;
          getTrackPoint(var_a0, var_a1, p50);
        }
        var_s0 = func_8002D2C8(p50[2] - p40[2], p50[0] - p40[0]);
        var_a0_2 = func_8002D2C8(p40[2] - p30[2], p40[0] - p30[0]);
        if ((var_s0 < (-0x400)) & (var_a0_2 >= 0x401))
        {
          var_s0 += 0x1000;
        }
        if ((var_a0_2 < (-0x400)) & (var_s0 >= 0x401))
        {
          var_a0_2 += 0x1000;
        }
        var_s0 = var_s0 - var_a0_2;
if(var_s0<0){*negative=(u16)(*negative-var_s0);goto inc_first;}if(var_s0>0){temp_s6->a=(u16)(temp_s6->a+var_s0);}inc_first:var_v0=++phase_i;}
      while ((s16)var_v0 < (var_s2->count - 2));
    }
    temp_a0 = var_s2->next;

new_var4=1;
    if (temp_a0 != 0)
    {
      second_count = ((volatile Road*)temp_a0)->count;
      var_s1 = 1;
      var_v0_2 = 1;
      temp_v0_2 = 1;var_v0=1;
      goto second_test;
      second_body:
      {
        getTrackPoint((Road *) temp_a0, (s32) ((s16) var_s1), &p30[0]);
        getTrackPoint((Road *) var_s2->next, ((s16) var_s1) + 1, &p40[0]);
        getTrackPoint((Road *) var_s2->next, ((s16) var_s1) + 2, &p50[0]);
        var_s0 = func_8002D2C8(p50[2] - p40[2], p50[0] - p40[0]);
        var_a0_3 = func_8002D2C8(p40[2] - p30[2], p40[0] - p30[0]);
        if ((var_s0 < (-0x400)) & (var_a0_3 >= 0x401))
        {
          var_s0 += 0x1000;
        }
        if ((var_a0_3 < (-0x400)) & (var_s0 >= 0x401))
        {
          var_a0_3 += 0x1000;
        }
        var_s0 = var_s0 - var_a0_3;
        if (var_s0 < 0)
        {
          *negative = (u16) ((*negative) - var_s0);
        }
        else
          if (var_s0 > 0)
        {
          temp_s6->a = (u16) (temp_s6->a + var_s0);
        }
var_v0=var_s1+1;var_s1=var_v0;temp_a0=var_s2->next;{s32 load_once;for(load_once=1;load_once;load_once=0){second_count=temp_a0->count;}}{s32 count_once;for(count_once=1;count_once;count_once=0){var_v0=(s16)var_v0;}}var_v0_2=var_v0;
      }

      second_test:
      second_count=(u32)second_count>>1;if(var_v0<second_count)
      {
        goto second_body;
      }{u32 alive_x=second_count;s16 alive_y=alive_x;alive_y+=0x13579bdfu;alive_y-=0x13579bdfu;if(alive_y!=alive_x){func_80033724();}}

    }
    var_a1 = (s16) (*negative);
    temp_v1_2 = (*((Stats **) (gStreamState + 0x7CD2)))->fall * 0x578;
{if(temp_v1_2>=0)var_v0=temp_v1_2;else var_v0=temp_v1_2+4095;{u32 identity_x=(u32)temp_v1_2;u32 identity_y=identity_x;identity_y+=0x13579bdfu;identity_y-=0x13579bdfu;var_v0=(s32)((u32)var_v0+(identity_y-identity_x));}var_a0_2=var_v0>>12;}
    if (var_a0_2 < var_a1)
    {
      var_v0_4 = (*flags) | 8;
      goto block_41;
      e_exit:
      var_s2->stats->eidx = var_s1;

      goto e_after;
      f_exit:
      var_s2->stats->fidx = var_s1;

      goto f_after;
    }
    if (var_a0_2 < ((s16) temp_s6->a))
    {
      var_v0_4 = (*flags) | 4;
      block_41:
      *flags = var_v0_4;

    }
    var_s2->stats->rise = 0;
    var_s2->stats->fall = 0;
    var_s0 = -1;
    var_s1 = 0;
    temp_v1_3 = (temp_v1_4 = var_s2->count) - 1;
    temp_s3 = temp_v1_3 / 2;
    if (((s32) temp_v1_3) > 0)
    {
      do
      {
        getTrackPoint((Road *) var_s2, var_s1, &p30[0]);

        if (((var_s1 == 0) | (var_s1 == temp_s3)) != 0)
        {

          sp6C = p30[1];
{s32 once;var_v0=var_s0+1;var_s0=var_v0;for(once=1;once;once=0){{s32 loaded_base=(s32)((RootBits)(Road*)sp8C).bits;temp_v0_4=(void*)((((s32)(var_v0<<16))>>14)+loaded_base);}*((s32*)((char*)temp_v0_4+16))=0;*((s32*)temp_v0_4)=0;}}
        }
        else
        {
          temp_a0_3 = p30[1] - sp6C;
          temp_v1_4 = var_s0 << 0x10;
          if (temp_a0_3 > 0)
          {
            temp_v1_4>>=14;temp_v1_5=temp_v1_4+(s32)sp8C;
            *((s32 *) (((char *) temp_v1_5) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_5) + 0x10))) + temp_a0_3);
          }
          else
            if (temp_a0_3 < 0)
          {
            temp_v1_6 = (temp_v1_4 >> 0xE) + (s32)sp8C;
            *temp_v1_6 -= temp_a0_3;
          }
        }
        var_s1 += 1;
      }
      while (var_s1 < (var_s2->count - 1));
    }
    if (heights[4] != 0)
    {
      var_s2->stats->rise = (s16) (-heights[4]);
    }
    if (heights[0] != 0)
    {
      var_s2->stats->rise = (s16) heights[0];
    }
    if (heights[5] != 0)
    {
      var_s2->stats->fall = (s16) (-heights[5]);
    }
    if (heights[1] != 0)
    {
      var_s2->stats->fall = (s16) heights[1];
    }
    heights[6] = 0;

    heights[2] = 0;
    temp_v0_5 = var_s2->next;
    if (temp_v0_5 != 0)
    {
temp_v1_3=temp_v0_5->count;temp_v1_3-=1;temp_v1_3+=(s32)((u32)temp_v1_3>>31);temp_s3=temp_v1_3>>1;
temp_a0_3=var_s0+1;
var_s1=0;
      if (temp_s3 > 0)
      {

        temp_s0_3 = (((s32) (temp_a0_3 << 0x10)) >> 0xE) + (s32)sp8C;
        do
        {
          getTrackPoint((Road *) var_s2->next, var_s1, &p30[0]);
          if (var_s1 == 0)
          {
            sp6C = p30[1];
            *((s32 *) (((char *) temp_s0_3) + 0x0)) = 0;
            *((s32 *) (((char *) temp_s0_3) + 0x10)) = 0;
          }
          else
          {
            var_a0_2 = p30[1] - sp6C;
            if (var_a0_2 > 0)
            {
              *((s32 *) (((char *) temp_s0_3) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_s0_3) + 0x10))) + var_a0_2);
            }
            else
            {
              new_var = 0x0;
              if (var_a0_2 < 0)
              {
                *((s32 *) (((char *) temp_s0_3) + new_var)) = (s32) ((*((s32 *) (((char *) temp_s0_3) + 0x0))) - var_a0_2);
              }
            }
          }
          var_s1 += 1;
        }
        while (var_s1 < temp_s3);
      }
    }
    temp_a0_5 = (*((Stats **) (gStreamState + 0x7CD2)))->fall;
    var_v0_5 = temp_a0_5 * 0x2BC;
    if (var_v0_5 < 0)
    {
      var_v0_5 += 0xFFF;
    }
    var_a2 = var_v0_5 >> 0xC;
    var_v0_6 = temp_a0_5 * 0x384;
    if (var_v0_6 < 0)
    {
      var_v0_6 += 0xFFF;
    }
    var_a1_2 = var_v0_6 >> 0xC;
    var_v0_7 = temp_a0_5 * 0x4B0;
    if (var_v0_7 < 0)
    {
      var_v0_7 += 0xFFF;
    }
    var_a0_4 = var_v0_7 >> 0xC;
    if (gSnapIndex == 5)
    {
      var_a2 += 0x12C;
      var_a1_2 += 0x12C;
      var_a0_4 += 0x12C;
    }
    if ((heights[0] != 0) && (heights[5] != 0))
    {
      if (((u32) var_a2) < ((u32) heights[5]))
      {
        *flags = (u16) ((*flags) | 0x80);
      }
      if ((((u32) var_a0_4) < ((u32) heights[5])) && (((u32) var_a0_4) < heights[6]))
      {
        *flags = (u16) (((*flags) | 0x20) & 0xFF7F);
      }
      if ((((u32) var_a1_2) < heights[0]) && (((u32) (var_a1_2 / 3)) < ((u32) heights[5])))
      {
        *flags = (u16) (((*flags) & 0xFF7F) | 0x10);
      }
      if ((((u32) (var_a1_2 / 3)) < heights[0]) && (((u32) var_a1_2) < ((u32) heights[5])))
      {
        *flags = (u16) (((*flags) & 0xFF7F) | 0x10);
      }
    }
    if ((heights[1] != 0) && (heights[6] != 0))
    {
      if (((u32) var_a2) < heights[6])
      {
        *flags = (u16) ((*flags) | 0x80);
      }
      if ((((u32) var_a1_2) < heights[1]) && (((u32) (var_a1_2 / 3)) < heights[6]))
      {
        *flags = (u16) (((*flags) | 0x10) & 0xFF7F);
      }
      if ((((u32) (var_a1_2 / 3)) < heights[1]) && (((u32) var_a1_2) < heights[6]))
      {
        *flags = (u16) (((*flags) | 0x10) & 0xFF7F);
      }
    }
    var_fp = 0;
    sp7E = 0;
    temp_v1_5 = (void *)var_s2->stats;
    ((Stats*)temp_v1_5)->mode=2;
    temp_v0_6 = var_s2->stats;
    var_s4 = 0;
    var_s1 = 0;
    temp_v0_6->c = 0U;
    temp_v0_6->d = 0U;
    temp_s6 = (Stats *) (&temp_v0_6->c);
    negative = &temp_v0_6->d;
    temp_v1_10 = var_s2->count;
    if (temp_v1_10 > 0)
    {
      var_s3 = sp84;
      do
      {
        if (var_s1 == 0)
        {
          var_a0_5 = var_s2->prev;
          if (var_a0_5)
          {
            track_sample_lookup(var_a0_5, var_a0_5->count - 2, p30);
          }
          else
          {
            track_sample_lookup(var_s2, 0, p30);
          }
        }
        else
        {
          track_sample_lookup(var_s2, var_s1 - 1, p30);
        }
        track_sample_lookup((Road *) var_s2, var_s1, &p40[0]);
        if (var_s1 == (var_s2->count - 1))
        {
          var_a0_6 = var_s2->next;
          if (var_a0_6)
          {
            track_sample_lookup(var_a0_6, 1, p50);
          }
          else
          {
            track_sample_lookup(var_s2, var_s1, p50);
          }
        }
        else
        {
          track_sample_lookup(var_s2, var_s1 + 1, p50);
        }
        var_s0 = func_8002D2C8(p50[2] - p40[2], p50[0] - p40[0]);
        var_a0_7 = func_8002D2C8(p40[2] - p30[2], p40[0] - p30[0]);
        if ((var_s0 < (-0x400)) & (var_a0_7 >= 0x401))
        {
          var_s0 += 0x1000;
        }
        if ((var_a0_7 < (-0x400)) & (var_s0 >= 0x401))
        {
          var_a0_7 += 0x1000;
        }
        var_s0 = var_s0 - var_a0_7;
        var_s3->angle = var_s0;
        temp_v1_7 = p40[0] - p30[0];
        temp_a0_6 = p40[2] - p30[2];
        var_s3->a = func_8002D2A0((temp_v1_7 * temp_v1_7) + (temp_a0_6 * temp_a0_6));
        temp_v1_8 = p50[0] - p40[0];
        temp_a0_7 = p50[2] - p40[2];
        var_s3->b = func_8002D2A0((temp_v1_8 * temp_v1_8) + (temp_a0_7 * temp_a0_7));
        if (var_s0 < 0)
        {
          *negative = (u16) ((*negative) - var_s0);
          sp7E = var_s3->b + (sp7E + var_s3->a);
        }
        else
          if (var_s0 > 0)
        {
          temp_s6->a = (u16) (temp_s6->a + var_s0);
          var_fp = var_s3->b + (var_fp + var_s3->a);
        }
        if (var_s4 == 0)
        {
          if (((s16) (*negative)) >= 0xFB)
          {
            var_s4 = 1;
            var_v0_8 = (*flags) | 2;
            goto block_130;
          }
          if (((s16) temp_s6->a) >= 0xFB)
          {
            if (var_s1)
            {
              var_s4 = 1;
              var_v0_8 = (*flags) | 1;
            }
            else
            {
              var_s4 = 1;
              var_v0_8 = (*flags) | 1;
            }
            block_130:
            *flags = var_v0_8;

          }
        }
        var_s1 += 1;
        var_s3++;
      }
      while (var_s1 < ((s32) var_s2->count));
    }
    var_s2->stats->eidx = 0;
    var_s0 = 0;
    var_s4 = 0;
    var_s2->stats->fidx = 0;
    var_s1 = 0;
    var_a1_5 = 0;
    var_v0_3 = var_s2->count;
    if (var_v0_3 > 0)
    {
      var_a2_2 = sp84;
      loop_134:
      temp_a0_8 = (*var_a2_2).angle;

      if (temp_a0_8 < 0)
      {
        var_s0 -= temp_a0_8;
      }
      temp_v1_9 = var_s4 == 0;
      if ((temp_a0_8 >= 0) & (var_s4 == 0))
      {
        var_a1_5 = 0;
      }
      if (((var_a1_5 == 0) & (var_s4 == 0)) && (temp_a0_8 < 0))
      {
        var_a1_5 = var_s1;
      }
      if (var_s0 >= 0xFB)
      {
        if (var_s4 == 0)
        {
          var_s4 = 1;
        }
        if (temp_a0_8 < 0)
        {
          if (var_s1 == (var_s2->count - 1))
          {
            var_s2->stats->eidx = var_s1;
          }
          goto block_145;
        }
        goto e_exit;
      }
      else
      {
        block_145:
        var_s1 += 1;

        var_a2_2++;
        if (var_s1 < ((s32) var_s2->count))
        {
          goto loop_134;
        }
      }
    }
    e_after:
    if (var_s4 != 0)
    {
      var_s2->stats->eidx = (s8) ((((s32) (var_s1 - var_a1_5)) / 2) + var_a1_5);
      var_s0 = 0;
      if (((((u16) var_s2->count) >> 1) + 2) < ((s32) ((u8) var_s2->stats->eidx)))
      {
        *flags = (u16) ((*flags) | 0x400);
        goto block_149;
      }
    }
    else
    {
      block_149:
      var_s0 = 0;

    }

    var_s4 = 0;
    var_s1 = 0;
    var_a1_6 = 0;
    var_v0_3 = var_s2->count;
    if (var_v0_3>0)
    {
      var_a2_3 = sp84;
      new_var2 = var_s4 == 0;
      loop_152:
      temp_a0_9 = var_a2_3->angle;

      if (temp_a0_9 > 0)
      {
        var_s0 += temp_a0_9;
      }
      temp_v1_10 = new_var2;
      if ((temp_a0_9 < 1) & (var_s4 == 0))
      {
        var_a1_6 = 0;
      }
      if (((var_a1_6 == 0) & (var_s4 == 0)) && (temp_a0_9 > 0))
      {
        var_a1_6 = var_s1;
      }
      if (var_s0 >= 0xFB)
      {
        if (var_s4 == 0)
        {
          var_s4 = 1;
        }
        if (temp_a0_9 > 0)
        {
          if (var_s1 == (var_s2->count - 1))
          {
            var_s2->stats->fidx = var_s1;
          }
          goto block_163;
        }
        goto f_exit;
      }
      else
      {
        block_163:
        var_s1 += 1;

        var_a2_3++;
        if (var_s1 < ((s32) var_s2->count))
        {
          goto loop_152;
        }
      }
    }
    f_after:
    if (var_s4 != 0)
    {
      var_s2->stats->fidx = (s8) ((((s32) (var_s1 - var_a1_6)) / 2) + var_a1_6);
      if (((((u16) var_s2->count) >> 1) + 2) < ((s32) ((u8) var_s2->stats->fidx)))
      {
        *flags = (u16) ((*flags) | 0x200);
      }
    }

    var_s2->stats->e = (s16) (((s32) (((s16) temp_s6->a) << 0xE)) / ((s32) ((var_fp & 0xFFFF) + 1)));
    var_v1 = sp7E;
    var_s2->stats->f = (s16) (((s32) (((s16) (*negative)) << 0xE)) / ((s32) (var_v1 + 1)));
    temp_v1_11 = *flags;
    if (!(temp_v1_11 & 3))
    {
      *flags = (u16) (temp_v1_11 | 0x800);
    }
    var_s2 = var_s2->next;
  }
  while ((var_s2 != arg0) & (var_s2 != 0));
/* Each unsigned add/sub pair is an identity modulo 2^32, so this guard
 * is always false. GCC 2.7.2 removes its code but retains the otherwise
 * unused spill slots required by the original frame. The referenced game
 * function is already defined elsewhere and is never called here. */
{u32 cancelled_x=(u32)sp76;u32 cancelled_y0;cancelled_y0=cancelled_x;cancelled_y0+=0x13579bdfu;cancelled_y0-=0x13579bdfu;if((cancelled_y0!=cancelled_x)){func_80033724();}}
var_v0=(s16)sp76-1;{u32 final_x=(u32)var_v0;u32 final_y=final_x;final_y+=1u;final_y-=1u;var_v0=(s32)((u32)var_v0+(final_y-final_x));}*((s32*)(D_800A73E0+0x6C08))=var_v0;
}


/* Revalidated after the local macOS toolchain signing repair. */
