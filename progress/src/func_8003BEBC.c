extern int gTimerEffectBusy;
s32 func_80038A8C(s32);
s32 timer_advance_stage(void *);
extern s32 D_8009BA30;
extern s32 gPadFlags;
extern void *gRaceCtx;
extern char gOrderState[];
extern char stream_state[];

typedef struct Sprite {
  u8 pad00[0x70];
  s16 ofs_x;
  s16 ofs_y;
  u8 pad74[4];
  u16 timer;
  s16 kind;
  u8 pad7C[4];
  s32 flags;
  u8 pad84[0xF];
  u8 fade;
  u8 pad94[4];
  u16 scale;
  u16 scale_out;
  u8 pad9C[8];
  void *desc;
} Sprite;

/* Per-frame update for a sprite object. While the sprite is armed and the game is not paused,
 * it counts down a timer (flag bit 4 marks a pending tick). When the timer runs out, the slot is
 * released. Otherwise it grows or shrinks its scale (kind 3 is the slow path), and recentres the
 * sprite by half its size. If the sprite is not armed, flag bit 4 is set. */
void func_8003BEBC(Sprite *o)
{
  f32 scale_f;
  f32 x;
  f32 y;
  s32 var_v0;
  u16 timer;
  void *tex;
  if (((*((s32 *) (((char *) (*((void **) (stream_state + 0x7CD6)))) + 0x24))) != 0) && ((*((u8 *) (((char *) gRaceCtx) + 0x384))) == 0))
  {
    if (!(gPadFlags & 2))
    {
      timer = o->timer;
      o->flags = (s32) ((o->flags) & (~4));
      if (timer != 0)
      {
        o->timer = (u16) (timer - 1);
        o->flags = (s32) ((o->flags) | 4);
        if ((o->timer) == 0)
        {
          if (gTimerEffectBusy == 0)
          {
            func_80038A8C((((u8 *) o)[0x7B] + 7) & 0xFF);
            gTimerEffectBusy = 4;
            D_8009BA30 = 0;
          }
          var_v0 = (o->flags) & (~4);
          goto block_20;
        }
      }
      else
      {
        if ((o->kind) == 3)
        {
          o->scale -= 0x20;
        }
        else
        {
          o->scale = (o->scale) + 0x20;
        }
        o->fade = (u8) ((o->fade) - 4);
        if ((o->kind) == 3)
        {
          if (((s16) (o->scale)) < 0x201)
          {
            timer_advance_stage(o);
          }
        }
        else
          if (((s16) (o->scale)) >= 0x400)
        {
          timer_advance_stage(o);
          if ((o->kind) == 3)
          {
            o->scale = 0x400;
          }
          else
          {
            o->scale = 0x100;
          }
        }
        scale_f = 1024.0f;
        scale_f = scale_f / ((f32) ((s16) (o->scale)));
        tex = *(*((void ***) (((char *) (*((void **) (((char *) o) + 0xA4)))) + 4)));
        {
        f32 w = (f32) (*((u16 *) (((char *) tex) + 6)));
        x = scale_f * w;
        }
        y = (f32) (*((u16 *) (((char *) tex) + 8)));
        scale_f = scale_f * y;
        x *= 0.5f;
        scale_f *= 0.5f;
        y = scale_f;
        o->scale_out = *((volatile s16 *) (&o->scale));
        o->ofs_x = -x;
        o->ofs_y = -y;
      }
    }
  }
  else
  {
    var_v0 = (o->flags) | 4;
    block_20:
    o->flags = var_v0;

  }
}
