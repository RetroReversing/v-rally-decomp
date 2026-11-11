typedef struct Game { u8 pad0[0xE]; u16 e; u8 pad10[0xE]; u16 mode; u8 pad20[0xC]; u16 flags; } Game;
extern s32 *D_800C8048;
extern Game *gRecords;
extern void *g_camera;
extern void *g_ent_list;
extern char D_800C7950[];
extern unsigned char D_800C8324;
extern int D_800AFA6C;
extern unsigned short D_800C3630;
extern unsigned char D_800C792F;
extern int D_800C8370;
extern int D_800B65EC;
extern int D_800B65F0;
extern int D_800B65F4;
extern int D_800B7040;
extern int D_800C34F4;
extern int D_800B6AFC;
extern int D_800C8374;
extern int D_800AFA50;
extern unsigned char D_800C8120;
extern int D_800C35C0;
extern int D_800B5B4C;
extern signed char D_800C5E54;
extern float gSpeedAccum;
extern float D_800C35D8;
extern int gSoundState;
extern int D_800B0AE0;
extern short D_800B5B50;
s32 view_set_rect();
s32 func_80005718();
s32 func_80005ACC();
s32 scene_switch();
s32 func_8000DA84();
s32 video_mode_setup();
s32 view_gfx_setup();
s32 func_8000E8FC();
s32 func_80010128();
s32 func_80010468();
s32 func_800131C0();
s32 func_80013E60();
s32 func_80013EA0();
s32 func_80013F3C();
s32 func_800144C8();
s32 func_80015780();
s32 stream_alloc_slots();
s32 func_8001FC14();
s32 func_8001FF80();
void *named_entry_lookup(void **, u8 *);
s32 func_800234AC();
s32 func_800234E0();
s32 func_80023604();
s32 func_8002362C();
s32 func_8002EDCC();
s32 getTexturePack();
s32 func_800354F4();
s32 func_80038D1C();
s32 streamUpdateVoiceVolume();
s32 func_800405D8();
void func_80040CF4(u8);
s32 func_800412FC();
s32 streamOrderInit();
s32 func_80042264();
s32 func_800422C8();
void *find_object_by_id();
s32 streamProcessList();
s32 func_80048ADC();
s32 func_80049294();
s32 func_80049654();
s32 func_80050B38();
s32 func_80050F08();
s32 race_check_finish();
s32 updateRaceState();
s32 records_mode_update();
s32 func_80069424();
s32 func_8006AC04();
s32 func_8007301C();
s32 func_80077054();
s32 hud_draw_air_stats();
s32 rect_hud_setup();
s32 poolAlloc();
s32 heapFreeBlock();
s32 heapQueryFreeSize();
s32 taskOpen();
s32 func_8007F634();
s32 taskRecvMsg();
s32 poolAllocHeadNode();
s32 func_80080514();
s32 resolve_path();
s32 func_80081B44();
s32 func_80084BF0();
s32 start_track_voices();
s32 voicesSetIdleParams();
s32 MusSetMasterVolume();
s32 voiceSetVolumeByKey();
s32 func_80086DE8();
s32 osGetTime();
s32 osSetThreadPri();
s32 osViBlack();
extern s32 gSceneSlot0;
extern s32 gSceneSlot1;
extern s32 gSceneSlot2;
extern s32 gFreeHeap1;
extern s32 gFreeHeap2;
extern s32 *gTimerCallback;
extern s8 gTimerStarted;
extern s32 gSceneHeapBlock;
extern s32 gPadFlags;
extern s32 gRecordTimeScale;
extern s32 gRaceFlags;
extern void *gRaceCtx;
extern s32 D_800A1740;
extern char D_800A3F9C[];
extern char D_800A3FAC[];
extern char D_800A3FB8[];
extern char D_800A3FC0[];
extern char gOrderState[];
extern char gStreamState[];
extern s32 timerServiceTick;
extern s32 func_80042A7C;
typedef struct PNode { u8 pad0[4]; struct PNode *next; u8 pad8[0x40]; s32 *p48; } PNode;
void func_8000F660(void)
{
  s32 *temp_v1;
  s32 var_a0;
  s32 temp_s3;
  s32 temp_s4;
  s32 temp_s5;
  s32 temp_v0;
  s32 temp_v0_6;
  s32 var_s1;
  s32 var_v0;
  s32 var_v1;
  u32 temp_a1;
  s32 initial_mode;
  u16 temp_v0_8;
  s32 temp_s2;
  s32 temp_v1_2;
  PNode *temp_a0;
  PNode *temp_a0_2;
  void *temp_s0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_7;
  D_800C8324 = 0U;
  D_800AFA6C = 0;
  D_800C3630 = 0U;
  var_s1 = 0;
  if (D_800C792F == 2)
  {
    gRecordTimeScale = 0x19;
    D_800C8370 = 0x10;
  }
  else
  {
    gRecordTimeScale = 0x19;
    D_800C8370 = 0x18;
  }
  scene_switch(0, 0x2810);
  video_mode_setup(gSceneSlot2, 1);
  gSceneSlot0 = gSceneSlot2;
  gSceneSlot1 = gSceneSlot2;
  func_8006AC04();
  temp_s5 = taskOpen(6, 2, 1);
  temp_s3 = taskOpen(9, 2, 0x10);
  temp_s4 = taskOpen(4, 0, 1);
  if (gSceneHeapBlock == 2)
  {
    gSceneHeapBlock = poolAlloc(3, 0x54C70);
  }
  records_mode_update();
  temp_v0 = poolAllocHeadNode();
  D_800B65EC = -0x46;
  D_800B65F0 = 0;
  D_800B65F4 = 0x46;
  initial_mode = *((u16 *) (((char *) gRecords) + 0x1E));
  *(s32 *)0x800B7040 = temp_v0;
  D_800C34F4 = 0;
  D_800B6AFC = 0;
  if (initial_mode == 7)
  {
    func_80050F08();
    gRecords->e = 1U;
    func_80015780(0, 0, 9, 0xB4, 1, 0);
    stream_alloc_slots(D_800C8374);
    streamOrderInit();
    func_80040CF4(0);
    var_a0 = 1;
    gRecords->mode = 7U;
  }
  else
  {
    func_80015780(0, 0, 9, 0xB4, 1, 0);
    stream_alloc_slots(D_800C8374);
    streamOrderInit();
    func_80040CF4(0);
    var_a0 = 0;
  }
  func_800416EC(var_a0);
  func_80023604();
  func_8001FF80();
  temp_s2 = *((u8 *) (((char *) gRecords) + 0xF));
  func_80069424();
  func_800234AC();
  streamUpdateVoiceVolume();
  if (((u32) (gRecords->mode - 7)) < 2U)
  {
    func_800234E0();
    temp_a0 = **((PNode ***) (gOrderState + 0x73F0));
    gPadFlags = *temp_a0->p48;
    *temp_a0->p48 = 0;
    if ((gRecords->mode == 7) && (gRecords->e == 2))
    {
      temp_a0 = temp_a0->next; *temp_a0->p48 = 1;
    }
    if (gRecords->mode == 8)
    {
      gRecords->e = 1U;
    }
  }
  func_800422C8();
  if (((u32) (gRecords->mode - 7)) < 2U)
  {
    temp_a0_2 = **((PNode ***) (gOrderState + 0x73F0));
    *temp_a0_2->p48 = gPadFlags;
    temp_a1 = gRecords->mode;
    if (temp_a1 == 7)
    {
      if (gRecords->e == 2)
      {
        temp_a0_2 = temp_a0_2->next; *temp_a0_2->p48 = 6;
      }
      if (gRecords->mode == temp_a1)
      {
        resolve_path(&D_800A3F9C);
        D_800AFA50 = getTexturePack(&D_800A3FAC, 0);
      }
    }
  }
  func_80049654();
  D_800C8120 = 1U;
  D_800C35C0 = 0;
  gPadFlags = 1;
  func_80081B44();
  if (gSceneHeapBlock != 2)
  {
    heapFreeBlock(gSceneHeapBlock);
  }
  gSceneHeapBlock = 2;
  scene_switch(0, 0x220E);
  func_80042264();
  func_80050B38();
  gFreeHeap1 = heapQueryFreeSize(1);
  gFreeHeap2 = heapQueryFreeSize(2);
  if (gRecords->mode == 7)
  {
    gPadFlags |= 0xA01;
    func_80080514(D_800B5B4C, &func_80042A7C, 3);
    rect_hud_setup();
  }
  temp_v1 = D_800C8048;
  D_800A1740 = 0;
  D_800C8048 = &timerServiceTick;
  gTimerStarted = 0;
  gTimerCallback = temp_v1;
  osViBlack(1);
  D_800C5E54 = 4;
  func_8000DA84();
  g_camera = temp_v0_2 = find_object_by_id(0);
  func_8000E8FC(((struct { u8 pad[0x178]; s32 x; } *) temp_v0_2)->x, gSceneSlot1, gSceneSlot2);
  func_80005718(gSceneSlot0, *((s32 *) (((char *) g_camera) + 0x178)));
  taskRecvMsg(temp_s3);
  func_80005ACC();
  taskRecvMsg(temp_s5);
  func_8000E8FC(*((s32 *) (((char *) g_camera) + 0x178)), gSceneSlot1, gSceneSlot2);
  func_80005718(gSceneSlot0, *((s32 *) (((char *) g_camera) + 0x178)));
  taskRecvMsg(temp_s3);
  if (D_800C8120 != 0)
  {
    temp_s0 = &D_800C35D8;
    temp_s2 = (temp_s2 - 1) * 2;
    do
    {
      if (((gRecords->mode == 7) && (!(gRaceFlags & 0x80))) && (D_800C5E54 == 0))
      {
        gRaceFlags |= 0x80;
        voicesSetIdleParams(1);
        start_track_voices(D_800C7950);
        func_80086DE8((s32) (gSpeedAccum * 80.0f));
      }
      if (!(gRaceFlags & 1))
      {
        var_v1 = var_s1 & 0xFF;
        if (gRecords->e == 2)
        {
          if (gRaceFlags & 2)
          {
            goto block_35;
          }
        }
      }
      else
      {
        block_35:
        var_s1 += 1;
        var_v1 = var_s1 & 0xFF;
      }
      if (((var_s1 & 0xFF) == 8) && (!(gRaceFlags & 8)))
      {
        gRaceFlags &= ~1;
        gRaceFlags &= ~2;
        MusSetMasterVolume(3, (s32) ((*((f32 *) temp_s0)) * 32767.0f));
        temp_v1_2 = *((u8 *) (((char *) temp_s0) + (-0x10)));
        *((s32 *) (((char *) temp_s0) + 0xC)) = 0;
        if (temp_v1_2 != 0xFF)
        {
          voiceSetVolumeByKey(gSoundState + (temp_v1_2 * 0xC), 0);
        }
        gRaceFlags |= 8;
        var_s1 = 0;
        start_track_voices(D_800C7950);
        func_80086DE8((s32) ((*((f32 *) (((char *) temp_s0) + 8))) * 112.0f));
      }
      func_80005ACC();
      taskRecvMsg(temp_s5);
      osGetTime();
      func_80013F3C();
      streamProcessList();
      osSetThreadPri(D_800B0AE0, 6);
      func_8001FC14();
      if ((*((u8 *) (((char *) gRaceCtx) + 0x384))) == 0)
      {
        g_camera = find_object_by_id(1);
        func_8002362C();
        if ((*((u8 *) (((char *) gRaceCtx) + 0x384))) == 0)
        {
          func_80010468();
        }
      }
      func_80048ADC();
      func_80013EA0();
      func_800412FC();
      func_80013F3C();
      func_800405D8();
      if ((*((u8 *) (((char *) gRaceCtx) + 0x384))) == 0)
      {
        func_8002EDCC();
        if (((u32) ((*((u16 *) (((char *) g_ent_list) + 4))) - 3)) < 2U)
        {
          func_800354F4();
        }
      }
      func_80038D1C();
      func_80013EA0();
      g_camera = temp_v0_3 = find_object_by_id(temp_s2 + 4);
      view_gfx_setup(((struct { u8 pad[0x178]; s32 x; } *) temp_v0_3)->x);
      view_set_rect(*((s32 *) (((char *) g_camera) + 0x178)), gSceneSlot0);
      temp_v0_4 = named_entry_lookup((void **)(g_camera + 0x28), (u8 *)(&D_800A3FB8));
      if (temp_v0_4 != NULL)
      {
        (*((s32 (**)(s32)) (((char *) temp_v0_4) + 0x14)))(*((s32 *) (((char *) temp_v0_4) + 0x10)));
      }
      temp_v0_5 = named_entry_lookup((void **)(g_camera + 0x28), (u8 *)(&D_800A3FC0));
      if (temp_v0_5 != NULL)
      {
        (*((s32 (**)(s32)) (((char *) temp_v0_5) + 0x14)))(*((s32 *) (((char *) temp_v0_5) + 0x10)));
      }
      hud_draw_air_stats();
      func_80049294();
      race_check_finish();
      func_80013F3C();
      if (D_800C35C0 != 0)
      {
        do
        {
          taskRecvMsg(temp_s3);
          temp_v0_6 = D_800C35C0 - 1;
          D_800C35C0 = temp_v0_6;
        }
        while (temp_v0_6 != 0);
      }
      if (gRecords->flags & 4)
      {
        func_800144C8(func_80084BF0(0));
      }
      if ((*((u16 *) (((char *) g_ent_list) + 4))) == 0)
      {
        func_800354F4();
      }
      func_80077054();
      if (D_800C8324 != 0)
      {
        func_8007301C();
      }
      func_80013EA0();
      temp_v0_7 = find_object_by_id(temp_s2 + 4);
      g_camera = temp_v0_7;
      if (gRecords->flags & 2)
      {
        func_800131C0(((struct { u8 pad[0x178]; s32 x; } *) temp_v0_7)->x);
      }
      osGetTime();
      gTimerStarted = 1;
      if (D_800C792F != 3)
      {
        if (func_80013E60() < 0x78)
        {
          taskRecvMsg(temp_s4);
        }
        if ((func_80013E60() >= 0xC9) && (((u32) (gRecords->mode - 7)) >= 2U))
        {
          temp_v0_8 = D_800C3630 + 1;
          D_800C3630 = temp_v0_8;
          if (((u32) (temp_v0_8 & 0xFFFF)) >= 2U)
          {
            D_800B5B50 = 1;
            D_800C3630 = 0U;
          }
        }
      }
      else
        if (func_80013E60() < 0xC8)
      {
        taskRecvMsg(temp_s4);
      }
    }
    while (D_800C8120 != 0);
  }
  updateRaceState();
  func_8007F634(temp_s3);
  func_8007F634(temp_s5);
  func_8007F634(temp_s4);
  D_800C8048 = (s32 *) gTimerCallback;
  func_80010128();
}
