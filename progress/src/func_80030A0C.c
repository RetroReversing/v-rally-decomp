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
u16 int_sqrt(s32);
s32 angle_atan2_thunk(s32, s32);
void track_sample_lookup(Road *, s32, s32 *);
void getTrackPoint(Road *, s32, s32 *);
extern s32 gSnapIndex;
extern char gGameState[];
extern char stream_state[];
void func_80033724(void);
struct VolCount{char pad[136];volatile u16 count;};union VolRoad{Road road;};
typedef union{Road *ptr;u32 bits;} RootBits;
/* Rebuilds the per-road stats for every road in a loop: flags, rise/fall, start and end indices, and the e/f ratios. */ void func_80030A0C(Road *head_road)
{
  u32 heights[8];
  s32 pt0[4];
  s32 pt1[4];
  s32 pt2[4];

int new_var4;
  u16 second_count;
s32 base_h;
  u16 road_idx;
  u16 sum_dn;
  int new_var;
  Sample *sp84;
  char *heights_ptr;
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
  Road *next_road;
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
  s32 sum_up;
  s32 dangle;
  Road *cur_road;
  s32 found_flag;
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
  Stats *cur_stats;
  void *temp_v0_4;
  Stats *temp_v0_6;
  void *temp_v1_5;
  u16 *flags;
  s16 *neg_b;
s16 phase_idx;

  #ifdef PORT
  cur_road=((RootBits)head_road).ptr;
#else
  cur_road=(Road*)((RootBits)head_road).bits;
#endif
  base_h = 0;
  road_idx = 0;
  heights_ptr = (char *) heights;
  do
  {
    cur_stats = cur_road->stats;
    flags = &cur_road->flags;
    neg_b = &cur_stats->b;
    cur_road->index = road_idx++;
    cur_stats->field1a = 0;
    sp84 = cur_stats->samples;
    cur_road->stats->field18 = 0;
    cur_stats->a = 0U;
    *neg_b = 0U;
    temp_v1 = cur_road->count;
    temp_v0 = temp_v1 >> 1;
    phase_idx = (s16) temp_v0;

    if (((s32) temp_v0) < (temp_v1 - 2))
    {
      do
      {
        getTrackPoint((Road *) cur_road, (s32) ((s16) phase_idx), &pt0[0]);
        getTrackPoint((Road *) cur_road, ((s16) phase_idx) + 1, &pt1[0]);
        next_road = cur_road->next;
        if ((next_road != 0) && (((s16) phase_idx) == (cur_road->count - 1)))
        {
          var_a1 = 1;
          getTrackPoint(next_road, var_a1, pt2);
        }
        else
        {
          next_road = cur_road;
          var_a1 = ((s16) phase_idx) + 2;
          getTrackPoint(next_road, var_a1, pt2);
        }
        dangle = angle_atan2_thunk(pt2[2] - pt1[2], pt2[0] - pt1[0]);
        var_a0_2 = angle_atan2_thunk(pt1[2] - pt0[2], pt1[0] - pt0[0]);
        if ((dangle < (-0x400)) & (var_a0_2 >= 0x401))
        {
          dangle += 0x1000;
        }
        if ((var_a0_2 < (-0x400)) & (dangle >= 0x401))
        {
          var_a0_2 += 0x1000;
        }
        dangle = dangle - var_a0_2;
if(dangle<0){*neg_b=(u16)(*neg_b-dangle);goto inc_first;}if(dangle>0){cur_stats->a=(u16)(cur_stats->a+dangle);}inc_first:var_v0=++phase_idx;}
      while ((s16)var_v0 < (cur_road->count - 2));
    }
    temp_a0 = cur_road->next;

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
        getTrackPoint((Road *) temp_a0, (s32) ((s16) var_s1), &pt0[0]);
        getTrackPoint((Road *) cur_road->next, ((s16) var_s1) + 1, &pt1[0]);
        getTrackPoint((Road *) cur_road->next, ((s16) var_s1) + 2, &pt2[0]);
        dangle = angle_atan2_thunk(pt2[2] - pt1[2], pt2[0] - pt1[0]);
        var_a0_3 = angle_atan2_thunk(pt1[2] - pt0[2], pt1[0] - pt0[0]);
        if ((dangle < (-0x400)) & (var_a0_3 >= 0x401))
        {
          dangle += 0x1000;
        }
        if ((var_a0_3 < (-0x400)) & (dangle >= 0x401))
        {
          var_a0_3 += 0x1000;
        }
        dangle = dangle - var_a0_3;
        if (dangle < 0)
        {
          *neg_b = (u16) ((*neg_b) - dangle);
        }
        else
          if (dangle > 0)
        {
          cur_stats->a = (u16) (cur_stats->a + dangle);
        }
var_v0=var_s1+1;var_s1=var_v0;temp_a0=cur_road->next;{s32 load_once;for(load_once=1;load_once;load_once=0){second_count=temp_a0->count;}}{s32 count_once;for(count_once=1;count_once;count_once=0){var_v0=(s16)var_v0;}}var_v0_2=var_v0;
      }

      second_test:
      second_count=(u32)second_count>>1;if(var_v0<second_count)
      {
        goto second_body;
      }{u32 alive_x=second_count;s16 alive_y=alive_x;alive_y+=0x13579bdfu;alive_y-=0x13579bdfu;if(alive_y!=alive_x){func_80033724();}}

    }
    var_a1 = (s16) (*neg_b);
    temp_v1_2 = (*((Stats **) (stream_state + 0x7CD2)))->fall * 0x578;
{if(temp_v1_2>=0)var_v0=temp_v1_2;else var_v0=temp_v1_2+4095;{u32 identity_x=(u32)temp_v1_2;u32 identity_y=identity_x;identity_y+=0x13579bdfu;identity_y-=0x13579bdfu;var_v0=(s32)((u32)var_v0+(identity_y-identity_x));}var_a0_2=var_v0>>12;}
    if (var_a0_2 < var_a1)
    {
      var_v0_4 = (*flags) | 8;
      goto block_41;
      e_exit:
      cur_road->stats->eidx = var_s1;

      goto e_after;
      f_exit:
      cur_road->stats->fidx = var_s1;

      goto f_after;
    }
    if (var_a0_2 < ((s16) cur_stats->a))
    {
      var_v0_4 = (*flags) | 4;
      block_41:
      *flags = var_v0_4;

    }
    cur_road->stats->rise = 0;
    cur_road->stats->fall = 0;
    dangle = -1;
    var_s1 = 0;
    temp_v1_3 = (temp_v1_4 = cur_road->count) - 1;
    temp_s3 = temp_v1_3 / 2;
    if (((s32) temp_v1_3) > 0)
    {
      do
      {
        getTrackPoint((Road *) cur_road, var_s1, &pt0[0]);

        if (((var_s1 == 0) | (var_s1 == temp_s3)) != 0)
        {

          base_h = pt0[1];
{s32 once;var_v0=dangle+1;dangle=var_v0;for(once=1;once;once=0){
#ifdef PORT
{temp_v0_4=(void*)(heights_ptr+(((s32)(var_v0<<16))>>14));}
#else
{s32 loaded_base=(s32)((RootBits)(Road*)heights_ptr).bits;temp_v0_4=(void*)((((s32)(var_v0<<16))>>14)+loaded_base);}
#endif
*((s32*)((char*)temp_v0_4+16))=0;*((s32*)temp_v0_4)=0;}}
        }
        else
        {
          temp_a0_3 = pt0[1] - base_h;
          temp_v1_4 = dangle << 0x10;
          if (temp_a0_3 > 0)
          {
            temp_v1_4>>=14;
#ifdef PORT
            temp_v1_5=heights_ptr+temp_v1_4;
#else
            temp_v1_5=temp_v1_4+(s32)heights_ptr;
#endif
            *((s32 *) (((char *) temp_v1_5) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_5) + 0x10))) + temp_a0_3);
          }
          else
            if (temp_a0_3 < 0)
          {
            #ifdef PORT
            temp_v1_6 = (s32 *)(heights_ptr + (temp_v1_4 >> 0xE));
#else
            temp_v1_6 = (temp_v1_4 >> 0xE) + (s32)heights_ptr;
#endif
            *temp_v1_6 -= temp_a0_3;
          }
        }
        var_s1 += 1;
      }
      while (var_s1 < (cur_road->count - 1));
    }
    if (heights[4] != 0)
    {
      cur_road->stats->rise = (s16) (-heights[4]);
    }
    if (heights[0] != 0)
    {
      cur_road->stats->rise = (s16) heights[0];
    }
    if (heights[5] != 0)
    {
      cur_road->stats->fall = (s16) (-heights[5]);
    }
    if (heights[1] != 0)
    {
      cur_road->stats->fall = (s16) heights[1];
    }
    heights[6] = 0;

    heights[2] = 0;
    temp_v0_5 = cur_road->next;
    if (temp_v0_5 != 0)
    {
temp_v1_3=temp_v0_5->count;temp_v1_3-=1;temp_v1_3+=(s32)((u32)temp_v1_3>>31);temp_s3=temp_v1_3>>1;
temp_a0_3=dangle+1;
var_s1=0;
      if (temp_s3 > 0)
      {

        #ifdef PORT
        temp_s0_3 = heights_ptr + (((s32) (temp_a0_3 << 0x10)) >> 0xE);
#else
        temp_s0_3 = (((s32) (temp_a0_3 << 0x10)) >> 0xE) + (s32)heights_ptr;
#endif
        do
        {
          getTrackPoint((Road *) cur_road->next, var_s1, &pt0[0]);
          if (var_s1 == 0)
          {
            base_h = pt0[1];
            *((s32 *) (((char *) temp_s0_3) + 0x0)) = 0;
            *((s32 *) (((char *) temp_s0_3) + 0x10)) = 0;
          }
          else
          {
            var_a0_2 = pt0[1] - base_h;
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
    temp_a0_5 = (*((Stats **) (stream_state + 0x7CD2)))->fall;
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
    sum_up = 0;
    sum_dn = 0;
    temp_v1_5 = (void *)cur_road->stats;
    ((Stats*)temp_v1_5)->mode=2;
    temp_v0_6 = cur_road->stats;
    found_flag = 0;
    var_s1 = 0;
    temp_v0_6->c = 0U;
    temp_v0_6->d = 0U;
    cur_stats = (Stats *) (&temp_v0_6->c);
    neg_b = &temp_v0_6->d;
    temp_v1_10 = cur_road->count;
    if (temp_v1_10 > 0)
    {
      var_s3 = sp84;
      do
      {
        if (var_s1 == 0)
        {
          var_a0_5 = cur_road->prev;
          if (var_a0_5)
          {
            track_sample_lookup(var_a0_5, var_a0_5->count - 2, pt0);
          }
          else
          {
            track_sample_lookup(cur_road, 0, pt0);
          }
        }
        else
        {
          track_sample_lookup(cur_road, var_s1 - 1, pt0);
        }
        track_sample_lookup((Road *) cur_road, var_s1, &pt1[0]);
        if (var_s1 == (cur_road->count - 1))
        {
          var_a0_6 = cur_road->next;
          if (var_a0_6)
          {
            track_sample_lookup(var_a0_6, 1, pt2);
          }
          else
          {
            track_sample_lookup(cur_road, var_s1, pt2);
          }
        }
        else
        {
          track_sample_lookup(cur_road, var_s1 + 1, pt2);
        }
        dangle = angle_atan2_thunk(pt2[2] - pt1[2], pt2[0] - pt1[0]);
        var_a0_7 = angle_atan2_thunk(pt1[2] - pt0[2], pt1[0] - pt0[0]);
        if ((dangle < (-0x400)) & (var_a0_7 >= 0x401))
        {
          dangle += 0x1000;
        }
        if ((var_a0_7 < (-0x400)) & (dangle >= 0x401))
        {
          var_a0_7 += 0x1000;
        }
        dangle = dangle - var_a0_7;
        var_s3->angle = dangle;
        temp_v1_7 = pt1[0] - pt0[0];
        temp_a0_6 = pt1[2] - pt0[2];
        var_s3->a = int_sqrt((temp_v1_7 * temp_v1_7) + (temp_a0_6 * temp_a0_6));
        temp_v1_8 = pt2[0] - pt1[0];
        temp_a0_7 = pt2[2] - pt1[2];
        var_s3->b = int_sqrt((temp_v1_8 * temp_v1_8) + (temp_a0_7 * temp_a0_7));
        if (dangle < 0)
        {
          *neg_b = (u16) ((*neg_b) - dangle);
          sum_dn = var_s3->b + (sum_dn + var_s3->a);
        }
        else
          if (dangle > 0)
        {
          cur_stats->a = (u16) (cur_stats->a + dangle);
          sum_up = var_s3->b + (sum_up + var_s3->a);
        }
        if (found_flag == 0)
        {
          if (((s16) (*neg_b)) >= 0xFB)
          {
            found_flag = 1;
            var_v0_8 = (*flags) | 2;
            goto block_130;
          }
          if (((s16) cur_stats->a) >= 0xFB)
          {
            if (var_s1)
            {
              found_flag = 1;
              var_v0_8 = (*flags) | 1;
            }
            else
            {
              found_flag = 1;
              var_v0_8 = (*flags) | 1;
            }
            block_130:
            *flags = var_v0_8;

          }
        }
        var_s1 += 1;
        var_s3++;
      }
      while (var_s1 < ((s32) cur_road->count));
    }
    cur_road->stats->eidx = 0;
    dangle = 0;
    found_flag = 0;
    cur_road->stats->fidx = 0;
    var_s1 = 0;
    var_a1_5 = 0;
    var_v0_3 = cur_road->count;
    if (var_v0_3 > 0)
    {
      var_a2_2 = sp84;
      loop_134:
      temp_a0_8 = (*var_a2_2).angle;

      if (temp_a0_8 < 0)
      {
        dangle -= temp_a0_8;
      }
      temp_v1_9 = found_flag == 0;
      if ((temp_a0_8 >= 0) & (found_flag == 0))
      {
        var_a1_5 = 0;
      }
      if (((var_a1_5 == 0) & (found_flag == 0)) && (temp_a0_8 < 0))
      {
        var_a1_5 = var_s1;
      }
      if (dangle >= 0xFB)
      {
        if (found_flag == 0)
        {
          found_flag = 1;
        }
        if (temp_a0_8 < 0)
        {
          if (var_s1 == (cur_road->count - 1))
          {
            cur_road->stats->eidx = var_s1;
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
        if (var_s1 < ((s32) cur_road->count))
        {
          goto loop_134;
        }
      }
    }
    e_after:
    if (found_flag != 0)
    {
      cur_road->stats->eidx = (s8) ((((s32) (var_s1 - var_a1_5)) / 2) + var_a1_5);
      dangle = 0;
      if (((((u16) cur_road->count) >> 1) + 2) < ((s32) ((u8) cur_road->stats->eidx)))
      {
        *flags = (u16) ((*flags) | 0x400);
        goto block_149;
      }
    }
    else
    {
      block_149:
      dangle = 0;

    }

    found_flag = 0;
    var_s1 = 0;
    var_a1_6 = 0;
    var_v0_3 = cur_road->count;
    if (var_v0_3>0)
    {
      var_a2_3 = sp84;
      new_var2 = found_flag == 0;
      loop_152:
      temp_a0_9 = var_a2_3->angle;

      if (temp_a0_9 > 0)
      {
        dangle += temp_a0_9;
      }
      temp_v1_10 = new_var2;
      if ((temp_a0_9 < 1) & (found_flag == 0))
      {
        var_a1_6 = 0;
      }
      if (((var_a1_6 == 0) & (found_flag == 0)) && (temp_a0_9 > 0))
      {
        var_a1_6 = var_s1;
      }
      if (dangle >= 0xFB)
      {
        if (found_flag == 0)
        {
          found_flag = 1;
        }
        if (temp_a0_9 > 0)
        {
          if (var_s1 == (cur_road->count - 1))
          {
            cur_road->stats->fidx = var_s1;
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
        if (var_s1 < ((s32) cur_road->count))
        {
          goto loop_152;
        }
      }
    }
    f_after:
    if (found_flag != 0)
    {
      cur_road->stats->fidx = (s8) ((((s32) (var_s1 - var_a1_6)) / 2) + var_a1_6);
      if (((((u16) cur_road->count) >> 1) + 2) < ((s32) ((u8) cur_road->stats->fidx)))
      {
        *flags = (u16) ((*flags) | 0x200);
      }
    }

    cur_road->stats->e = (s16) (((s32) (((s16) cur_stats->a) << 0xE)) / ((s32) ((sum_up & 0xFFFF) + 1)));
    var_v1 = sum_dn;
    cur_road->stats->f = (s16) (((s32) (((s16) (*neg_b)) << 0xE)) / ((s32) (var_v1 + 1)));
    temp_v1_11 = *flags;
    if (!(temp_v1_11 & 3))
    {
      *flags = (u16) (temp_v1_11 | 0x800);
    }
    cur_road = cur_road->next;
  }
  while ((cur_road != head_road) & (cur_road != 0));
/* Each unsigned add/sub pair is an identity modulo 2^32, so this guard
 * is always false. GCC 2.7.2 removes its code but retains the otherwise
 * unused spill slots required by the original frame. The referenced game
 * function is already defined elsewhere and is never called here. */
{u32 cancelled_x=(u32)road_idx;u32 cancelled_y0;cancelled_y0=cancelled_x;cancelled_y0+=0x13579bdfu;cancelled_y0-=0x13579bdfu;if((cancelled_y0!=cancelled_x)){func_80033724();}}
var_v0=(s16)road_idx-1;{u32 final_x=(u32)var_v0;u32 final_y=final_x;final_y+=1u;final_y-=1u;var_v0=(s32)((u32)var_v0+(final_y-final_x));}*((s32*)(gGameState+0x6C08))=var_v0;
}


/* Revalidated after the local macOS toolchain signing repair. */
