typedef struct { char pad[0x14]; void *commands; } CommandObject;
#ifdef PORT
typedef struct { char pad[0x178]; void *field; } ViewObject;
#else
typedef struct { char pad[0x178]; s32 field; } ViewObject;
#endif
extern u32 gRaceState;
extern s8 D_800C81FF;
extern void *gRecords;
extern s32 D_800C81DC;
extern s32 D_800B7040;
extern s32 D_800C5D20;
extern s32 D_800C5D24;
extern s32 D_800C5D28;
extern s32 D_800C5D2C;
extern s32 D_800C5D30;
extern void *g_camera;
#ifdef PORT
extern void *D_800AFA88;
#else
extern s32 D_800AFA88;
#endif
#ifdef PORT
extern void *D_800D05D8;
#else
extern s32 D_800D05D8;
#endif
extern void *D_800ADF80;
extern s32 gSelectStep;
extern s32 gSelectStepHandle;
extern u8 D_800AFA5C;
extern u8 D_800C81FE;
extern u32 gDecodeBlk;
extern s32 gFadeDirection;
extern s32 D_800B0AE0;
extern s32 D_800C35C0;
extern s32 D_800C3504;
s32 view_set_rect();
void *view_get_ctx_id();
s32 scene_teardown();
s32 func_80005ACC();
s32 obj_get_owner();
s32 func_80005DEC();
void *gfx_get_dl();
s32 gfx_set_dl();
s32 gfx_push_mtx();
s32 view_gfx_setup();
s32 func_8000E8FC();
s32 updateScreenFade();
#ifdef PORT
void hud_build_dl(void *);
#else
void hud_build_dl(s32);
#endif
s32 func_80013E60();
s32 func_80015780();
s32 mtx_pool_alloc();
s32 func_80022214();
s32 nodeListRunCallbacks();
s32 func_80041320();
s32 streamOrderInit();
s32 func_80041FF4();
s32 order_setup_objects();
void *find_object_by_id();
s32 streamProcessList();
s32 stream_arm_flush();
s32 stream_flush_if_pending();
s32 func_8004C794();
s32 func_8004C7B8();
s32 loadBestSplitTimes();
s32 update_split_times();
s32 hiscore_update_season_standings();
s32 func_80057810();
s32 object_free_blocks();
s32 func_80057998();
s32 select_state_free();
s32 func_8005B6A8();
s32 scene_boot_init();
s32 UpdateChannelDeltas();
s32 pack_tile_rows();
s32 build_glyph_lookup();
s32 unpackAllRecords();
s32 func_8006ECB4();
s32 glyph_record_pack();
s32 save_race_to_pak();
s32 taskOpen();
s32 func_8007F634();
s32 taskRecvMsg();
s32 poolAllocHeadNode();
s32 heapReleaseBlock();
s32 cont_port_is_connected(s32, s32);
s32 func_80089B70();
s32 func_80089B80();
s32 guMtxF2L(s32 *, s32);
s32 guMtxIdent(s32);
s32 guOrthoF(s32 *, f32, f32, f32, f32, f32, f32, f32);
s32 osSetThreadPri(s32, s32);
s32 strCpy();
extern s32 gSceneSlot0;
extern void *gSceneSlot1;
extern u8 gSelectResetPending;
extern u8 gSelectResetFlag;
extern u8 select_reset_requested;
extern char D_800A13C0[];
extern void *gSelectState;
extern char D_800A14BC[];
extern s32 D_800A14C0;
extern u8 gStreamPhase;
extern char D_800A5268[];
extern char D_800A5274[];
extern char D_800A527C[];
extern char D_800A5284[];
extern char D_800A528C[];
extern char D_800A5294[];
extern char D_800A529C[];
extern char D_800A52A8[];
extern char D_800A52B4[];
extern char D_800A52C0[];
extern char D_800A52CC[];
extern char D_800A52D8[];
extern char D_800A52E4[];
extern u8 gGameState[];
extern u8 gOrderState[];
extern u8 stream_state[];
static inline static u32 inline_fn(u32 arg0)
{
  return (u32) arg0;
}

typedef struct { unsigned char pad_0[14]; unsigned short field_E; unsigned char pad_10[14]; unsigned short field_1E; unsigned char pad_20[12]; unsigned short field_2C; unsigned char pad_2E[4]; unsigned char field_32; unsigned char field_33; unsigned char pad_34[4]; unsigned short field_38; } __repair_record_D_800C35A0;
/* Runs the results/select screen: picks the summary text for the last race state, updates best split and season records, then loops per frame until the player leaves. */
void func_8005A790(void)
{
  f32 proj_mtx[4][4];
  s32 *select_text;
  u8 any_left;
  u32 split_best;
  void *view_buf;
  s32 wait_count_unused;
  s32 split_tmp;
  s32 step_arg;
  s32 split_ok;
  s32 step_arg_unused;
  u8 split_faster;
  s32 unused_a2;
  s32 any_nonzero;
  s32 view_tmp;
  u8 idx_b;
  u16 rec_mode;
  u16 rec_mode_b;
  u16 rec_mode_c;
  u16 split_slot;
  u32 race_state_now;
  s32 *step_ptr;
  void *view;
  u8 port_state;
  void *split_base;
  #ifdef PORT
void *view_field;
#else
s32 view_field;
#endif
  void *cam_obj_1;
  void *cam_obj_2;
  void *cam_obj_0;
  void *cam_obj;
  void *cmd_ptr;
  void *cam_obj_b;
  void *cam_obj_c;
  void *cam_obj_d;
  void *cam_obj_e;
  void *cam_obj_f;
  s32 mtx_addr;
  void *gfx_ctx;
  void *gfx_dl;
  s32 port_off;
  s32 slot;
  u16 rec_field38;
  u8 idx_a;
  s32 task_main;
  s32 task_timer;
  step_ptr = &gSelectStep;
  select_text = NULL;
  if ((gRaceState != 5) & (gRaceState != 0))
  {
    if (((u32) (gRaceState - 2)) >= 2U)
    {
      if (gRaceState != 6)
      {
        return;
      }
    }
  }
  {
    if (gRaceState == 6)
    {
      D_800C81FF = (s8) (*((u16 *) ((char *)gRecords + 14)));
      *((u16 *) ((char *)gRecords + 14)) = 1U;
      return;
    }
    task_main = taskOpen(6, 2, 1);
    D_800C81DC = taskOpen(9, 2, 0x10);
    task_timer = taskOpen(4, 0, 1);
    if (gSceneSlot1 == NULL)
    {
      if (gSceneSlot0 == 0)
      {
        scene_boot_init();
      }
    }
    func_80015780(1, 0, 0xF, 0xB4, 1, 0);
    slot = 0;
    func_80089B70();
    D_800B7040 = poolAllocHeadNode();
    func_8004C794();
    stream_arm_flush();
    streamOrderInit();
    func_80041320();
    order_setup_objects();
    do
    {
      *((s32 *) (((slot & 255) * 4) + (stream_state + 0x5A72))) = 0;
      slot += 1;
    }
    while (((u32) (slot & 0xFF)) < 5U);
    D_800C5D20 = func_80041FF4(2, &D_800A5274);
    D_800C5D24 = func_80041FF4(2, &D_800A527C);
    D_800C5D28 = func_80041FF4(1, &D_800A5284);
    D_800C5D2C = func_80041FF4(1, &D_800A528C);
    D_800C5D30 = func_80041FF4(0, &D_800A5294);
    cam_obj_0 = find_object_by_id(4);
    view = ((ViewObject *)cam_obj_0)->field;
    g_camera = cam_obj_0;
    D_800AFA88 = view;
    cam_obj_1 = find_object_by_id(1);
    view = ((ViewObject *)cam_obj_1)->field;
    g_camera = cam_obj_1;
    D_800D05D8 = view;
    cam_obj_2 = find_object_by_id(1);
    #ifdef PORT
view = ((ViewObject *)cam_obj_2)->field;
#else
view_tmp = ((ViewObject *)cam_obj_2)->field;
#endif
    #ifndef PORT
view = (void *) view_tmp;
#endif
    g_camera = cam_obj_2;
    D_800ADF80 = view;
    if (gSelectStep != 0)
    {
      step_arg = ((s32 *) (&D_800A14BC))[*step_ptr];
    
    gSelectStepHandle = func_80057810(step_arg);}
    else
    {
      step_arg = D_800A14C0;
    
    gSelectStepHandle = func_80057810(step_arg);}
    func_80057998();
    *((s8 *) (((char *) gSelectState) + 0x299)) = 0;
    *((s8 *) (((char *) gSelectState) + 0x29D)) = 1;
    *((s8 *) (((char *) gSelectState) + 0x298)) = 0;
    *((s8 *) (((char *) gSelectState) + 0x29C)) = 1;
    *((s8 *) (((char *) gSelectState) + 0x29B)) = 0;
    *((s8 *) (((char *) gSelectState) + 0x29A)) = 0;
    *((s8 *) (((char *) gSelectState) + 0x2BE)) = 0;
    if ((gSelectResetPending != 0) || ((gSelectResetFlag | select_reset_requested) != 0))
    {
      D_800AFA5C = 0U;
      select_text = &D_800A529C;
    }
    else
    {
      race_state_now = gRaceState;
      switch (race_state_now)
      {
        case 5:
          unpackAllRecords();
          select_text = &D_800A52A8;
          D_800AFA5C = 0U;
          if ((((__repair_record_D_800C35A0*)gRecords)->field_1E) == 7)
        {
          select_text = &D_800A5268;
        }
          break;

        case 0:
          rec_mode = ((__repair_record_D_800C35A0*)gRecords)->field_1E;
          if ((rec_mode != 0) & (rec_mode < 5U))
        {
          D_800AFA5C = 1U;
          select_text = &D_800A52B4;
        }
        else
          if (rec_mode == 5)
        {
          D_800AFA5C = 3U;
          select_text = &D_800A52C0;
        }
        else
          if (rec_mode == 7)
        {
          select_text = &D_800A5268;
        }
          break;

        case 3:
          rec_mode_b = ((__repair_record_D_800C35A0*)gRecords)->field_1E;
          if ((rec_mode_b != 0) & (rec_mode_b < 5U))
        {
          func_8006ECB4();
          save_race_to_pak();
          D_800AFA5C = 1U;
          select_text = &D_800A52CC;
        }
        else
        {
          if (rec_mode_b == 5)
          {
            split_base = gOrderState + 0x7DB0;
            split_ok = 1;
            if (((u8) D_800C81FE) < 8U)
            {
              idx_b = 0;
              do
              {
                split_ok &= -((*((u16 *) (((char *) (((idx_b & 255) * 2) + split_base)) + 0x10))) != 0);
                idx_b += 1;
              }
              while (((u32) (idx_b & 0xFF)) < 8U);
              if (split_ok & 0xFF)
              {
                split_best = *((u32 *)split_base);
                split_faster = 0;
                if ((((u32) (*((u32 *) (((char *) split_base) + 4)))) < split_best) && (((u32) (*((u32 *) (((char *) split_base) + 8)))) < split_best))
                {
                  split_faster = ((u32) (*((u32 *) (((char *) split_base) + 0xC)))) < split_best;
                }

                if ((*((u16 *) ((char *)gRecords + 14))) == 2)
                {
                  split_tmp = *((u32 *) (((char *) split_base) + 4));
                  split_best = *((u32 *) (((char *) split_base) + 8));
                  if (split_best < (u32)split_tmp)
                  {
                    if (((u32) (*((u32 *) (((char *) split_base) + 0xC)))) < split_best)
                    {
                      split_faster = 1;
                    }
                  }
                }
                if (split_faster != 0)
                {
                  rec_field38 = ((__repair_record_D_800C35A0*)gRecords)->field_38;
                  if (rec_field38 == 0)
                  {
                    ((__repair_record_D_800C35A0*)gRecords)->field_38 = (u16) (rec_field38 + 1);
                  }
                }
                loadBestSplitTimes();
                goto block_56;
              }
            }
            else
            {
              unused_a2 = 1;
              idx_a = 0;
              do
              {
                split_slot = *((u16 *) (((char *) (split_base - (-((idx_a & 0xFF) * 2)))) + 0x20));
                idx_a += 1;
                unused_a2 &= -(split_slot != 0);
                any_left = unused_a2 & 0xFF;
              }
              while ((((u32) (idx_a & 0xFF)) < 4U) & (any_left != 0));
              if (any_left != 0)
              {
                update_split_times();
                block_56:
                hiscore_update_season_standings();

                UpdateChannelDeltas();
                save_race_to_pak();
              }
            }
          }
          D_800AFA5C = 3U;
          select_text = &D_800A52D8;
        }
          break;

        case 2:
          rec_mode_c = ((__repair_record_D_800C35A0*)gRecords)->field_1E;
          if (rec_mode_c == 5)
        {
          D_800AFA5C = 3U;
          select_text = &D_800A52E4;
        }
        else
          if (rec_mode_c == 0)
        {
          glyph_record_pack(((__repair_record_D_800C35A0*)gRecords)->field_32);
          if ((*((u16 *) ((char *)gRecords + 14))) == race_state_now)
          {
            glyph_record_pack(((__repair_record_D_800C35A0*)gRecords)->field_33);
          }
          build_glyph_lookup();
          save_race_to_pak();
          D_800AFA5C = 2U;
          select_text = &D_800A5268;
        }
        else
          if ((rec_mode_c != 0) & (rec_mode_c < 5U))
        {
          pack_tile_rows();
          save_race_to_pak();
          D_800AFA5C = 1U;
          select_text = &D_800A5268;
        }
        else
          if (rec_mode_c == 7)
        {
          select_text = &D_800A52A8;
        }
          break;

      }

    }
    strCpy(gSelectState + 0x2AD, (D_800AFA5C * 0x24) + ((u8 *) (&D_800A13C0)));
    strCpy(gSelectState + 0x2A1, select_text);
    *((s8 *) (((char *) gSelectState) + 0x29E)) = 1;
    *((u8 *) (((char *) gSelectState) + 0x2A0)) = 0U;
    *((s8 *) (((char *) gSelectState) + 0x29F)) = 0;
    *((u8 *) (((char *) gSelectState) + 0x2BA)) = 0U;
    *((s8 *) (((char *) gSelectState) + 0x2BB)) = 0;
    *((s32 *) (((char *) gSelectState) + 0x288)) = 0;
    *((s32 *) (((char *) gSelectState) + 0x28C)) = 0;
    *((s32 *) (((char *) gSelectState) + 0x290)) = 0;
    *((s8 *) (((char *) gSelectState) + 0x2BD)) = -1;
    gFadeDirection = 0;
    do
    {
      func_80005ACC();
      taskRecvMsg(task_main);
      streamProcessList();
      osSetThreadPri(D_800B0AE0, 6);
      cam_obj = find_object_by_id(0);
      g_camera = cam_obj;
      view_gfx_setup(((ViewObject *)cam_obj)->field);
      view_set_rect(*((void **) (((char *) g_camera) + 0x178)), gSceneSlot0);
      if ((*((s8 *) (((char *) gSelectState) + 0x2BD))) == 1)
      {
        *((s8 *) (((char *) gSelectState) + 0x2BD)) = 0;
        *((u8 *) (((char *) gSelectState) + 0x249)) = 3U;
      }
      if ((((*((u8 *) (((char *) gSelectState) + 0x249))) != 0) || ((*((s8 *) (((char *) gSelectState) + 0x2BD))) == (-1))) && ((*((u8 *) (((char *) gSelectState) + 0x2BA))) == 0))
      {
        func_8000E8FC(*((void **) (((char *) g_camera) + 0x178)), gSceneSlot1, 0);
      }
      else
      {
        gfx_ctx = view_get_ctx_id(*((void **) (((char *) g_camera) + 0x178)));
        cmd_ptr = ((CommandObject *)gfx_ctx)->commands;
        ((CommandObject *)gfx_ctx)->commands = (void *) (cmd_ptr + 8);
        view_buf = gSceneSlot1;
        *((s32 *) (((char *) cmd_ptr) + 0)) = (s32) ((((*((s16 *) (((char *) view_buf) + 4))) - 1) & 0xFFF) | 0xFF100000);
        *((s32 *) (((char *) cmd_ptr) + 4)) = obj_get_owner(view_buf);
      }
      cam_obj_b = find_object_by_id(2);
      g_camera = cam_obj_b;
      slot = 0;
      view_gfx_setup(((ViewObject *)cam_obj_b)->field);
      view_set_rect(*((void **) (((char *) g_camera) + 0x178)), gSceneSlot0);
      cam_obj_c = find_object_by_id(3);
      g_camera = cam_obj_c;
      view_gfx_setup(((ViewObject *)cam_obj_c)->field);
      cam_obj_d = find_object_by_id(4);
      view_field = ((ViewObject *)cam_obj_d)->field;
      g_camera = cam_obj_d;
      view_gfx_setup(view_field);
      view_set_rect(*((void **) (((char *) g_camera) + 0x178)), gSceneSlot0);
      cam_obj_e = find_object_by_id(1);
      g_camera = cam_obj_e;
      view_gfx_setup(((ViewObject *)cam_obj_e)->field);
      view_set_rect(*((void **) (((char *) g_camera) + 0x178)), gSceneSlot0);
      mtx_addr = mtx_pool_alloc();
      guMtxIdent(mtx_addr);
      gfx_ctx = view_get_ctx_id(D_800ADF80);
      gfx_dl = gfx_get_dl(gfx_ctx);
      *((s32 *) (((char *) gfx_dl) + 0)) = 0xDA380003;
      *((s32 *) (((char *) gfx_dl) + 4)) = mtx_addr;
      gfx_set_dl(gfx_ctx, gfx_dl + 8);
      mtx_addr = mtx_pool_alloc();
      guOrthoF(&proj_mtx, (f32) (*((s16 *) (((char *) D_800ADF80) + 8))), (f32) (*((s16 *) (((char *) D_800ADF80) + 0xC))), (f32) (*((s16 *) (((char *) D_800ADF80) + 0xE))), (f32) (*((s16 *) (((char *) D_800ADF80) + 0xA))), -1.0f, 10.0f, 1.0f);
      guMtxF2L(&proj_mtx, mtx_addr);
      gfx_push_mtx(gfx_ctx, mtx_addr);
      func_8005B6A8();
      updateScreenFade(D_800AFA88);
      loop_77:
      port_off = (slot & 255) * 0x10;

      port_state = *((u8 *) ((gOrderState + 0x239C) + port_off));
      if (port_state != cont_port_is_connected(slot & 255, 2))
      {
        *((gOrderState + 0x239D) + port_off) = 1;
        *((s32 *) ((gOrderState + 0x2394) + port_off)) = 0;
      }
      slot += 1;
      if (((u32) (slot & 0xFF)) < 4U)
      {
        goto loop_77;
      }
      if (D_800C35C0 != 0)
      {
        do
        {
          taskRecvMsg(D_800C81DC);
          split_tmp = D_800C35C0 - 1;
          D_800C35C0 = split_tmp;
        }
        while (split_tmp != 0);
      }
      cam_obj_f = find_object_by_id(2);
      g_camera = cam_obj_f;
      if ((((__repair_record_D_800C35A0*)gRecords)->field_2C) & 2)
      {
        hud_build_dl(((ViewObject *)cam_obj_f)->field);
      }
      if (func_80013E60() < 0x78)
      {
        taskRecvMsg(task_timer);
      }
      *((s8 *) (((char *) gSelectState) + 0x234)) = 1;
    }
    while ((*((u8 *) (((char *) gSelectState) + 0x2A0))) == 0);
    if ((*((u8 *) (((char *) gSelectState) + 0x232))) != 0)
    {
      *((u8 *) (((char *) gSelectState) + 0x232)) = 0U;
    }
    select_state_free();
    object_free_blocks(gSelectStepHandle);
    func_8004C7B8();
    stream_flush_if_pending();
    nodeListRunCallbacks(D_800B7040);
    heapReleaseBlock(D_800B7040);
    func_80022214();
    func_80005DEC();
    D_800C3504 = obj_get_owner(gSceneSlot1);
    if (gStreamPhase == 1)
    {
      gStreamPhase = 0;
    }
    if ((*((s16 *) (((char *) gSceneSlot1) + 4))) != 0x140)
    {
      scene_teardown();
    }
    func_8007F634(task_main);
    func_8007F634(D_800C81DC);
    func_8007F634(task_timer);
    func_80089B80();
  }
}
