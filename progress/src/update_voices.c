s32 func_80087910(s32 *, s32);
s32 func_80088514(s32 *);
s32 func_8008871C(s32 *, s32);
s32 voice_slot_restart(s32 *, s32);
s32 func_80088B30(s32 *);
s32 func_80088BF4(s32 *);
s32 func_80088D10(s32 *);
f32 func_80088F1C(s32 *);
f32 blinkTick(s32 *);
s32 voiceUpdatePitch(s32 *, s32, f32);
s32 func_8008910C(s32 *, s32);
s32 alSynStopVoice(void *, s32);
extern s32 gOrderState;
extern s32 gStreamState;

/* Steps every active voice in the voice table (stride 0x134, at the pointer stored at 0x800B68F0):
 * runs its timers and envelope, stops it when its counter runs out, and writes its output level.
 * Returns the value at gOrderState + 0x7420. */
s32 update_voices(void)
{
  volatile s32 pad[2];
  f32 level;
  s32 *voice;
  s32 temp_v0;
  s32 vi;
  s32 voff;
  s32 minus_one;
  u32 tick;
  s16 *vp;
  voice = *((s32 **) 0x800B68F0);
  vi = 0;
  if ((*((s32 *) (((char *) (&gStreamState)) + 0x757E))) > 0)
  {
    minus_one = -1;
    vp = (s16 *) (((u8 *) voice) + 0xA2);
    voff = 0;
    loop_start:
    {
      if ((*voice) != 0)
      {
        if ((*((s32 *) (((char *) vp) + (-0x9E)))) != 0)
        {
          voice_slot_restart(voice, vi);
        }
        tick = (*((u32 *) (((char *) vp) + (-0x9A)))) + (*((u16 *) (((char *) vp) + (-0xE))));
        *((u32 *) (((char *) vp) + (-0x9A))) = tick;
        if ((*((u16 *) (((char *) vp) + (-0x10)))) != 0x7FFF)
        {
          if (((u32) (*((u32 *) (((char *) vp) + (-0x6A))))) < tick)
          {
            loop_7:
            if ((*voice) != 0)
            {
              func_8008871C(voice, vi);
              if (((u32) (*((u32 *) (((char *) vp) + (-0x6A))))) >= ((u32) (*((u32 *) (((char *) vp) + (-0x9A))))))
              {
                goto block_9;
              }
              goto loop_7;
            }

          }
          else
          {
            block_9:
            if ((*voice) != 0)
            {
              goto block_10;
            }

          }
        }
        else
        {
          block_10:
          if (((*((s32 *) (((char *) vp) + (-0x6E)))) != 0) && (((u32) (*((u32 *) (((char *) vp) + (-0x8E))))) < ((u32) (*((u32 *) (((char *) vp) + (-0x9A)))))))
          {
            func_80088B30(voice);
          }

          if (((*((s32 *) (((char *) vp) + (-0x72)))) != 0) && (((u32) (*((u32 *) (((char *) vp) + (-0x8E))))) < ((u32) (*((u32 *) (((char *) vp) + (-0x9A)))))))
          {
            func_80088BF4(voice);
          }
          temp_v0 = *((s32 *) (((char *) vp) + (-0x96)));
          if ((temp_v0 != minus_one) && ((*((s32 *) (((char *) vp) + (-0x96))) = --temp_v0, temp_v0 == minus_one)))
          {
            *voice = func_80087910(voice, 0);
            if ((*((u8 *) (((char *) vp) + 0x1F))) != 0)
            {
              *((u8 *) (((char *) vp) + 0x1F)) = 0U;
              alSynStopVoice(((u8 *) (&gOrderState)) + 0x2304, (*((s32 *) (((char *) (&gStreamState)) + 0x7576))) + voff);
              goto block_20;
            }
          }
          else
          {
            block_20:
            if ((*((u8 *) (((char *) vp) + 0x1F))) != 0)
            {
              if ((*((u8 *) (((char *) vp) + 0x19))) != 0)
              {
                func_80088D10(voice);
              }
              if (((*((u8 *) (((char *) vp) + 0x2A))) != 0) && (((u32) (*((u32 *) (((char *) vp) + (-0x16))))) < ((u32) (*((u32 *) (((char *) vp) + (-0x9A)))))))
              {
                func_80088514(voice);
              }
              level = *((f32 *) (((char *) vp) + (-0x76)));
              if ((*((u8 *) (((char *) vp) + 0x2B))) != 0)
              {
                level += func_80088F1C(voice);
              }
              if ((*((u8 *) (((char *) vp) + 0x24))) != 0)
              {
                level += blinkTick(voice);
              }
              if ((*((s32 *) (((char *) vp) + (-0x9E)))) == 0)
              {
                voiceUpdatePitch(voice, vi, level);
                func_8008910C(voice, vi);
              }
            }

          }
          *vp = (s16) (((u32) ((*((u32 *) (((char *) vp) + (-0x9A)))) - (*((s32 *) (((char *) vp) + (-0x66)))))) >> 8);
        }
      }
      voff += 0x1C;
      vi += 1;
      vp += 0x9A;
      voice = (s32 *) (((u8 *) voice) + 0x134);
    }

    if (vi < (*((s32 *) (((char *) (&gStreamState)) + 0x757E))))
    {
      goto loop_start;
    }
  }
  return *((s32 *) (((char *) (&gOrderState)) + 0x7420));
}
