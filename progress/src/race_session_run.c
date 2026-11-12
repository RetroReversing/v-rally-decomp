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
s32 order_recv_msg();
s32 video_mode_setup();
s32 view_gfx_setup();
s32 func_8000E8FC();
s32 func_80010128();
s32 func_80010468();
s32 hud_build_dl();
s32 func_80013E60();
s32 func_80013EA0();
s32 func_80013F3C();
s32 func_800144C8();
s32 func_80015780();
s32 stream_alloc_slots();
s32 func_8001FC14();
s32 func_8001FF80();
void *list_find_node(void **, u8 *);
s32 func_800234AC();
s32 order_list_clear_flags();
s32 func_80023604();
s32 stream_release_head_entry();
s32 race_update_cars_gated();
s32 getTexturePack();
s32 func_800354F4();
s32 race_tick_voices_and_spawns();
s32 streamUpdateVoiceVolume();
s32 func_800405D8();
void func_80040CF4(u8);
s32 race_draw_views();
s32 streamOrderInit();
s32 order_setup_objects();
s32 func_800422C8();
void *find_object_by_id();
s32 streamProcessList();
s32 func_80048ADC();
s32 func_80049294();
s32 init_race_ui();
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
s32 order_state_reset();
s32 input_get_buttons();
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
extern s32 overlay_frames;
extern char D_800A3F9C[];
extern char D_800A3FAC[];
extern char D_800A3FB8[];
extern char D_800A3FC0[];
extern char gOrderState[];
extern char stream_state[];
extern s32 timerServiceTick;
extern s32 func_80042A7C;
typedef struct PNode { u8 pad0[4]; struct PNode *next; u8 pad8[0x40]; s32 *p48; } PNode;
/* Runs one race session: sets up the scene, tasks and HUD, loops per frame until the race ends, then tears everything down. */
void race_session_run(void)
{
  s32 *old_timer_cb;
  s32 init_flag;
  s32 task_render;
  s32 task_timer;
  s32 task_main;
  s32 head_node;
  s32 wait_count;
  s32 frame_counter;
  s32 frame_slot;
  u32 mode_snapshot;
  s32 start_mode;
  u16 timer_tick;
  s32 car_index;
  s32 voice_key;
  PNode *node;
  PNode *pad_node;
  void *track_ptr;
  void *cam_obj;
  void *view_obj;
  void *hud_entry_a;
  void *hud_entry_b;
  void *focus_obj;
  D_800C8324 = 0U;
  D_800AFA6C = 0;
  D_800C3630 = 0U;
  frame_counter = 0;
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
  task_main = taskOpen(6, 2, 1);
  task_render = taskOpen(9, 2, 0x10);
  task_timer = taskOpen(4, 0, 1);
  if (gSceneHeapBlock == 2)
  {
    gSceneHeapBlock = poolAlloc(3, 0x54C70);
  }
  records_mode_update();
  head_node = poolAllocHeadNode();
  D_800B65EC = -0x46;
  D_800B65F0 = 0;
  D_800B65F4 = 0x46;
  start_mode = *((u16 *) (((char *) gRecords) + 0x1E));
  *(s32 *)0x800B7040 = head_node;
  D_800C34F4 = 0;
  D_800B6AFC = 0;
  if (start_mode == 7)
  {
    func_80050F08();
    gRecords->e = 1U;
    func_80015780(0, 0, 9, 0xB4, 1, 0);
    stream_alloc_slots(D_800C8374);
    streamOrderInit();
    func_80040CF4(0);
    init_flag = 1;
    gRecords->mode = 7U;
  }
  else
  {
    func_80015780(0, 0, 9, 0xB4, 1, 0);
    stream_alloc_slots(D_800C8374);
    streamOrderInit();
    func_80040CF4(0);
    init_flag = 0;
  }
  func_800416EC(init_flag);
  func_80023604();
  func_8001FF80();
  car_index = *((u8 *) (((char *) gRecords) + 0xF));
  func_80069424();
  func_800234AC();
  streamUpdateVoiceVolume();
  if (((u32) (gRecords->mode - 7)) < 2U)
  {
    order_list_clear_flags();
    node = **((PNode ***) (gOrderState + 0x73F0));
    gPadFlags = *node->p48;
    *node->p48 = 0;
    if ((gRecords->mode == 7) && (gRecords->e == 2))
    {
      node = node->next; *node->p48 = 1;
    }
    if (gRecords->mode == 8)
    {
      gRecords->e = 1U;
    }
  }
  func_800422C8();
  if (((u32) (gRecords->mode - 7)) < 2U)
  {
    pad_node = **((PNode ***) (gOrderState + 0x73F0));
    *pad_node->p48 = gPadFlags;
    mode_snapshot = gRecords->mode;
    if (mode_snapshot == 7)
    {
      if (gRecords->e == 2)
      {
        pad_node = pad_node->next; *pad_node->p48 = 6;
      }
      if (gRecords->mode == mode_snapshot)
      {
        resolve_path(&D_800A3F9C);
        D_800AFA50 = getTexturePack(&D_800A3FAC, 0);
      }
    }
  }
  init_race_ui();
  D_800C8120 = 1U;
  D_800C35C0 = 0;
  gPadFlags = 1;
  order_state_reset();
  if (gSceneHeapBlock != 2)
  {
    heapFreeBlock(gSceneHeapBlock);
  }
  gSceneHeapBlock = 2;
  scene_switch(0, 0x220E);
  order_setup_objects();
  func_80050B38();
  gFreeHeap1 = heapQueryFreeSize(1);
  gFreeHeap2 = heapQueryFreeSize(2);
  if (gRecords->mode == 7)
  {
    gPadFlags |= 0xA01;
    func_80080514(D_800B5B4C, &func_80042A7C, 3);
    rect_hud_setup();
  }
  old_timer_cb = D_800C8048;
  overlay_frames = 0;
  D_800C8048 = &timerServiceTick;
  gTimerStarted = 0;
  gTimerCallback = old_timer_cb;
  osViBlack(1);
  D_800C5E54 = 4;
  order_recv_msg();
  g_camera = cam_obj = find_object_by_id(0);
  func_8000E8FC(((struct { u8 pad[0x178]; s32 x; } *) cam_obj)->x, gSceneSlot1, gSceneSlot2);
  func_80005718(gSceneSlot0, *((s32 *) (((char *) g_camera) + 0x178)));
  taskRecvMsg(task_render);
  func_80005ACC();
  taskRecvMsg(task_main);
  func_8000E8FC(*((s32 *) (((char *) g_camera) + 0x178)), gSceneSlot1, gSceneSlot2);
  func_80005718(gSceneSlot0, *((s32 *) (((char *) g_camera) + 0x178)));
  taskRecvMsg(task_render);
  if (D_800C8120 != 0)
  {
    track_ptr = &D_800C35D8;
    car_index = (car_index - 1) * 2;
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
        frame_slot = frame_counter & 0xFF;
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
        frame_counter += 1;
        frame_slot = frame_counter & 0xFF;
      }
      if (((frame_counter & 0xFF) == 8) && (!(gRaceFlags & 8)))
      {
        gRaceFlags &= ~1;
        gRaceFlags &= ~2;
        MusSetMasterVolume(3, (s32) ((*((f32 *) track_ptr)) * 32767.0f));
        voice_key = *((u8 *) (((char *) track_ptr) + (-0x10)));
        *((s32 *) (((char *) track_ptr) + 0xC)) = 0;
        if (voice_key != 0xFF)
        {
          voiceSetVolumeByKey(gSoundState + (voice_key * 0xC), 0);
        }
        gRaceFlags |= 8;
        frame_counter = 0;
        start_track_voices(D_800C7950);
        func_80086DE8((s32) ((*((f32 *) (((char *) track_ptr) + 8))) * 112.0f));
      }
      func_80005ACC();
      taskRecvMsg(task_main);
      osGetTime();
      func_80013F3C();
      streamProcessList();
      osSetThreadPri(D_800B0AE0, 6);
      func_8001FC14();
      if ((*((u8 *) (((char *) gRaceCtx) + 0x384))) == 0)
      {
        g_camera = find_object_by_id(1);
        stream_release_head_entry();
        if ((*((u8 *) (((char *) gRaceCtx) + 0x384))) == 0)
        {
          func_80010468();
        }
      }
      func_80048ADC();
      func_80013EA0();
      race_draw_views();
      func_80013F3C();
      func_800405D8();
      if ((*((u8 *) (((char *) gRaceCtx) + 0x384))) == 0)
      {
        race_update_cars_gated();
        if (((u32) ((*((u16 *) (((char *) g_ent_list) + 4))) - 3)) < 2U)
        {
          func_800354F4();
        }
      }
      race_tick_voices_and_spawns();
      func_80013EA0();
      g_camera = view_obj = find_object_by_id(car_index + 4);
      view_gfx_setup(((struct { u8 pad[0x178]; s32 x; } *) view_obj)->x);
      view_set_rect(*((s32 *) (((char *) g_camera) + 0x178)), gSceneSlot0);
      hud_entry_a = list_find_node((void **)(g_camera + 0x28), (u8 *)(&D_800A3FB8));
      if (hud_entry_a != NULL)
      {
        (*((s32 (**)(s32)) (((char *) hud_entry_a) + 0x14)))(*((s32 *) (((char *) hud_entry_a) + 0x10)));
      }
      hud_entry_b = list_find_node((void **)(g_camera + 0x28), (u8 *)(&D_800A3FC0));
      if (hud_entry_b != NULL)
      {
        (*((s32 (**)(s32)) (((char *) hud_entry_b) + 0x14)))(*((s32 *) (((char *) hud_entry_b) + 0x10)));
      }
      hud_draw_air_stats();
      func_80049294();
      race_check_finish();
      func_80013F3C();
      if (D_800C35C0 != 0)
      {
        do
        {
          taskRecvMsg(task_render);
          wait_count = D_800C35C0 - 1;
          D_800C35C0 = wait_count;
        }
        while (wait_count != 0);
      }
      if (gRecords->flags & 4)
      {
        func_800144C8(input_get_buttons(0));
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
      focus_obj = find_object_by_id(car_index + 4);
      g_camera = focus_obj;
      if (gRecords->flags & 2)
      {
        hud_build_dl(((struct { u8 pad[0x178]; s32 x; } *) focus_obj)->x);
      }
      osGetTime();
      gTimerStarted = 1;
      if (D_800C792F != 3)
      {
        if (func_80013E60() < 0x78)
        {
          taskRecvMsg(task_timer);
        }
        if ((func_80013E60() >= 0xC9) && (((u32) (gRecords->mode - 7)) >= 2U))
        {
          timer_tick = D_800C3630 + 1;
          D_800C3630 = timer_tick;
          if (((u32) (timer_tick & 0xFFFF)) >= 2U)
          {
            D_800B5B50 = 1;
            D_800C3630 = 0U;
          }
        }
      }
      else
        if (func_80013E60() < 0xC8)
      {
        taskRecvMsg(task_timer);
      }
    }
    while (D_800C8120 != 0);
  }
  updateRaceState();
  func_8007F634(task_render);
  func_8007F634(task_main);
  func_8007F634(task_timer);
  D_800C8048 = (s32 *) gTimerCallback;
  func_80010128();
}
