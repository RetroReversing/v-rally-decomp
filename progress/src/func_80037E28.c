#define U2F(x) (dv = (x), (x) < 0 ? dv += u2fBias : 0, (f32)dv)
typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
} Snd;
typedef struct 
{
  char pad[0x20];
  s32 flags;
} Cam;
typedef struct 
{
  char pad[0xE];
  u16 players;
  char pad10[0xE];
  u16 mode;
} State;
typedef struct 
{
  s32 type;
  s32 rpm;
} Engine;
typedef struct 
{
  Snd *snd;
  s32 last;
  s32 w[5];
  s32 load;
} Audio;
typedef struct Car
{
  char pad0[4];
  struct Car *next;
  char pad8[0x40];
  s32 *speed;
  Engine *eng;
  s32 *surface;
  char pad54[0x14];
  Audio *audio;
  char pad6C[0x14];
  char *wheels;
  char pad84[8];
  u8 *ctrl;
  char pad90[4];
  s32 *kind;
} Car;
s32 getCounterValue(Car *);
Cam *find_object_by_id(s32);
void voicesSetParamsByKey(Snd *, s32);
void voice_alloc_request(Snd *);
s32 voiceKeyIsFree(Snd *);
void voiceSetVolumeByKey(Snd *, s32);
void func_80086E8C(Snd *, f32);
extern s32 gRaceFlags;
extern const f64 D_800A4AC8;
extern const f64 D_800A4AD0;
extern const f64 D_800A4AD8;
extern char gOrderState[];
extern State *gRecords;
extern f32 gEngineVolume;
extern f32 gSfxVolumeScale;
extern f32 gSpeedAccum;
extern u8 gEngineVoice;
extern Snd *gSoundState;
extern Cam *g_camera;
extern u8 D_800B6818;

/* Per-frame audio update for the car list: sets the engine, gear shift, tyre squeal and
 * surface voices of each car from its rpm, speed, load and wheel slip. */
void func_80037E28(void)
{
  Car *car;
  Audio *audio;
  Snd *voices;
  union { Snd *sound; u32 gear; } scratch;
  f32 *engineVolPtr;
  f32 *sfxScalePtr;
  u16 modeCopy;
  f32 throttle;
  f32 counter;
  f32 pitch;
  f64 dv;
  int rpmStep;
  f64 u2fBias;
  f32 hundred;
  s32 rpm;
  s32 kind;
  s32 speed;
  s32 step;
  s32 level;
  u32 wheelSum;
  int speedBoost;
  u8 audioOn;
  u8 w;
  audioOn = 0;
  if (!(gRaceFlags & 1))
  {
    audioOn = 1;
  }
  else
    if ((gRecords->players == 2) && (!(gRaceFlags & 2)))
  {
    audioOn = 1;
  }
  if (!audioOn)
  {
    return;
  }
  car = *(*((Car ***) (gOrderState + 0x73F0)));
  if (car == NULL)
  {
    return;
  }
  hundred=100.0f; engineVolPtr=&gEngineVolume; sfxScalePtr=(f32 *)((char *)engineVolPtr+4); u2fBias=D_800A4AC8;
  do
  {
    audio = car->audio;
    rpm = car->eng->rpm;
    voices = audio->snd;
    kind = (*car).kind[1];
    speed = car->speed[3] / 5;
    switch (car->eng->type)
    {
      case 0:
        break;

      case 1:
        if (((kind == 1) && (!(gRaceFlags & 4))) && voiceKeyIsFree(&voices[4]))
      {
        gRaceFlags |= 4;
        voice_alloc_request(&voices[4]);
        voiceSetVolumeByKey(&voices[4], gSfxVolumeScale * 150.0f);
      }
        break;

      case 2:
        throttle = audio->load;
        if (throttle > 12000.0f)
      {
        throttle = 12000.0f;
      }
        ;
        throttle = (hundred - (throttle * 0.008333334f)) * 0.01f;
        if ((gRecords->mode == 6) || (gRecords->mode == 7))
      {
        *engineVolPtr = 0.0f;
        if (gEngineVoice != 0xFF)
        {
          voiceSetVolumeByKey(&gSoundState[gEngineVoice], 0);
        }
      }
      else
      {
        step = kind;
        if (step != 1)
        {
          if (((gRecords->mode == 5) && (D_800B6818 == 0)) || ((gRecords->players == 2) && ((gRecords->mode == 5) || ((gRecords->mode != 0) & (gRecords->mode < 5)))))
          {
            throttle = 0.0f;
          }
        }
        if (kind == 1)
        {
          counter = getCounterValue(car);
          if (counter < 0.0f)
          {
            counter = -counter;
          }
          if (counter > hundred)
          {
            counter = hundred;
          }
          gEngineVolume = gSpeedAccum * ((1.0f - (counter * 0.004f)) * 112.0f);
          g_camera = find_object_by_id(1);
          if (g_camera->flags & 0x880000)
          {
            gEngineVolume *= 0.6666667f;
          }
          if (gEngineVoice != 0xFF)
          {
            if ((modeCopy = gRecords->mode) || speed)
            {
              voiceSetVolumeByKey(&gSoundState[gEngineVoice], gEngineVolume);
            }
            else
            {
              voiceSetVolumeByKey(&gSoundState[gEngineVoice], gEngineVolume);
            }
          }
        }
      }
        if (kind == 2)
      {
        break;
      }
        if (voiceKeyIsFree(&voices[4]) && ((gRecords->players != 2) | (kind == 1)))
      {
        if (voiceKeyIsFree(&voices[0]))
        {
          voice_alloc_request(&voices[0]);
        }
        if (voiceKeyIsFree(&voices[1]))
        {
          voice_alloc_request(&voices[1]);
        }
      }
        if (voices[0].b == 0)
      {
        break;
      }
        pitch = ((rpm * 12) * D_800A4AD0) - D_800A4AD8;
        do { func_80086E8C(&voices[0], pitch); } while(0);
        scratch.sound = &voices[1];
        func_80086E8C(scratch.sound, pitch);
        if (rpm < 4000)
      {
        voiceSetVolumeByKey(&voices[0], throttle * ((*sfxScalePtr) * 120.0f));
        level = speed + 30;
        voiceSetVolumeByKey(scratch.sound, (U2F(level) * throttle) * (*sfxScalePtr));
      }
      else
        if (rpm < 5500)
      {
        step = (rpmStep = ((rpm - 4000) * 40) / 1500);
        voiceSetVolumeByKey(&voices[0], ((f32)(120 - step) * throttle) * (*sfxScalePtr));
        speedBoost = speed + 30;
        step = step + speedBoost;
        voiceSetVolumeByKey(scratch.sound, (U2F(step) * throttle) * (*sfxScalePtr));
      }
      else
      {
        voiceSetVolumeByKey(&voices[0], throttle * ((*sfxScalePtr) * 80.0f));
        level = speed + 80;
        voiceSetVolumeByKey(scratch.sound, (U2F(level) * throttle) * (*sfxScalePtr));
      }
        if (kind != 1)
      {
        break;
      }
        scratch.gear = car->ctrl[0x337];
        if ((u8)scratch.gear != 0)
      {
        if ((u8)scratch.gear >= 3)
        {
          scratch.gear = 2;
        }
        if (voiceKeyIsFree(&voices[5]))
        {
          voice_alloc_request(&voices[5]);
          voiceSetVolumeByKey(&voices[5], ((f32)(u8)scratch.gear) * (gSfxVolumeScale * 56.0f));
        }
      }
        if (audio->last != (*car->surface))
      {
        audio->last = *car->surface;
        voice_alloc_request(&voices[3]);
        voiceSetVolumeByKey(&voices[3], *sfxScalePtr);
        voiceSetVolumeByKey(&voices[0], (*sfxScalePtr) * 80.0f);
        voiceSetVolumeByKey(&voices[1], (*sfxScalePtr) * 80.0f);
      }
        wheelSum = 0;
        for (w = 0; w < 4; w++)
      {
        if ((*((s32 *) ((car->wheels + (w * 4)) + 0x310))) < 0)
        {
          wheelSum += car->audio->w[w];
        }
      }

        if (wheelSum > 2000)
      {
        if (voiceKeyIsFree(&voices[2]))
        {
          voice_alloc_request(&voices[2]);
        }
        if (wheelSum > 8000)
        {
          voiceSetVolumeByKey(&voices[2], gSfxVolumeScale * 140.0f);
        }
        else
          if (wheelSum > 6000)
        {
          voiceSetVolumeByKey(&voices[2], gSfxVolumeScale * 120.0f);
        }
        else
          if (wheelSum > 4000)
        {
          voiceSetVolumeByKey(&voices[2], gSfxVolumeScale * hundred);
        }
        else
        {
          voiceSetVolumeByKey(&voices[2], gSfxVolumeScale * 80.0f);
        }
      }
      else
      {
        voicesSetParamsByKey(&voices[2], 1);
      }
        break;

    }

    car = car->next;
  }
  while (car != NULL);
}
