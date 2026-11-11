typedef struct { char pad[0x14]; void *commands; } CommandObject;
typedef struct { char pad[0x178]; s32 field; } ViewObject;
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
extern s32 D_800AFA88;
extern s32 D_800D05D8;
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
s32 func_80005C48();
s32 func_80005DEC();
void *gfx_get_dl();
s32 gfx_set_dl();
s32 gfx_push_mtx();
s32 view_gfx_setup();
s32 func_8000E8FC();
s32 updateScreenFade();
void func_800131C0(s32);
s32 func_80013E60();
s32 func_80015780();
s32 mtx_pool_alloc();
s32 func_80022214();
s32 nodeListRunCallbacks();
s32 func_80041320();
s32 streamOrderInit();
s32 func_80041FF4();
s32 func_80042264();
void *find_object_by_id();
s32 streamProcessList();
s32 func_80047564();
s32 func_80047C78();
s32 func_8004C794();
s32 func_8004C7B8();
s32 loadBestSplitTimes();
s32 update_split_times();
s32 func_8005508C();
s32 func_80057810();
s32 func_800578E0();
s32 func_80057998();
s32 select_state_free();
s32 func_8005B6A8();
s32 scene_boot_init();
s32 UpdateChannelDeltas();
s32 pack_tile_rows();
s32 func_8006DDD8();
s32 func_8006E33C();
s32 func_8006ECB4();
s32 func_8006F0E0();
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
s32 copyStringAligned();
extern s32 gSceneSlot0;
extern void *gSceneSlot1;
extern u8 D_800A13B0;
extern u8 D_800A13B1;
extern u8 D_800A13B2;
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
extern u8 D_800A73E0[];
extern u8 gOrderState[];
extern u8 gStreamState[];
static inline static u32 inline_fn(u32 arg0)
{
  return (u32) arg0;
}

typedef struct { unsigned char pad_0[14]; unsigned short field_E; unsigned char pad_10[14]; unsigned short field_1E; unsigned char pad_20[12]; unsigned short field_2C; unsigned char pad_2E[4]; unsigned char field_32; unsigned char field_33; unsigned char pad_34[4]; unsigned short field_38; } __repair_record_D_800C35A0;
void func_8005A790(void)
{
  f32 sp20[4][4];
  s32 *var_s1;
  u8 temp_a0_3;
  s32 temp_s1;
  void *buffer;
  s32 temp_s4;
  s32 temp_s5;
  s32 temp_v0_12;
  s32 temp_v0_15;
  s32 var_a0;
  s32 var_a0_2;
  u8 var_a0_3;
  s32 var_a0_4;
  u8 var_a1;
  s32 var_a2;
  s32 var_s2;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  u8 var_v1;
  u16 temp_a0;
  u16 temp_a0_2;
  u16 temp_a0_4;
  u16 temp_v0_4;
  u16 temp_v0_5;
  u32 temp_s0;
  u32 temp_v1;
  s32 *new_var2;
  void *view;
  u8 temp_s0_4;
  void *temp_a3;
  s32 new_var;
  void *temp_s0_2;
  void *temp_v0;
  void *temp_v0_10;
  void *temp_v0_11;
  void *temp_v0_13;
  void *temp_v0_14;
  void *temp_v0_16;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_6;
  void *temp_v0_8;
  void *temp_v0_9;
  new_var2 = &gSelectStep;
  var_s1 = NULL;
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
    temp_s5 = taskOpen(6, 2, 1);
    D_800C81DC = taskOpen(9, 2, 0x10);
    temp_s4 = taskOpen(4, 0, 1);
    if (gSceneSlot1 == NULL)
    {
      if (gSceneSlot0 == 0)
      {
        scene_boot_init();
      }
    }
    func_80015780(1, 0, 0xF, 0xB4, 1, 0);
    var_s2 = 0;
    func_80089B70();
    D_800B7040 = poolAllocHeadNode();
    func_8004C794();
    func_80047564();
    streamOrderInit();
    func_80041320();
    func_80042264();
    do
    {
      *((s32 *) (((var_s2 & 255) * 4) + (gStreamState + 0x5A72))) = 0;
      var_s2 += 1;
    }
    while (((u32) (var_s2 & 0xFF)) < 5U);
    D_800C5D20 = func_80041FF4(2, &D_800A5274);
    D_800C5D24 = func_80041FF4(2, &D_800A527C);
    D_800C5D28 = func_80041FF4(1, &D_800A5284);
    D_800C5D2C = func_80041FF4(1, &D_800A528C);
    D_800C5D30 = func_80041FF4(0, &D_800A5294);
    temp_v0 = find_object_by_id(4);
    view = ((ViewObject *)temp_v0)->field;
    g_camera = temp_v0;
    D_800AFA88 = view;
    temp_v0_2 = find_object_by_id(1);
    view = ((ViewObject *)temp_v0_2)->field;
    g_camera = temp_v0_2;
    D_800D05D8 = view;
    temp_v0_3 = find_object_by_id(1);
    var_v0 = ((ViewObject *)temp_v0_3)->field;
    view = (void *) var_v0;
    g_camera = temp_v0_3;
    D_800ADF80 = view;
    if (gSelectStep != 0)
    {
      var_a0 = ((s32 *) (&D_800A14BC))[*new_var2];
    
    gSelectStepHandle = func_80057810(var_a0);}
    else
    {
      var_a0 = D_800A14C0;
    
    gSelectStepHandle = func_80057810(var_a0);}
    func_80057998();
    *((s8 *) (((char *) gSelectState) + 0x299)) = 0;
    *((s8 *) (((char *) gSelectState) + 0x29D)) = 1;
    *((s8 *) (((char *) gSelectState) + 0x298)) = 0;
    *((s8 *) (((char *) gSelectState) + 0x29C)) = 1;
    *((s8 *) (((char *) gSelectState) + 0x29B)) = 0;
    *((s8 *) (((char *) gSelectState) + 0x29A)) = 0;
    *((s8 *) (((char *) gSelectState) + 0x2BE)) = 0;
    if ((D_800A13B0 != 0) || ((D_800A13B1 | D_800A13B2) != 0))
    {
      D_800AFA5C = 0U;
      var_s1 = &D_800A529C;
    }
    else
    {
      temp_s0 = gRaceState;
      switch (temp_s0)
      {
        case 5:
          func_8006E33C();
          var_s1 = &D_800A52A8;
          D_800AFA5C = 0U;
          if ((((__repair_record_D_800C35A0*)gRecords)->field_1E) == 7)
        {
          var_s1 = &D_800A5268;
        }
          break;

        case 0:
          temp_a0 = ((__repair_record_D_800C35A0*)gRecords)->field_1E;
          if ((temp_a0 != 0) & (temp_a0 < 5U))
        {
          D_800AFA5C = 1U;
          var_s1 = &D_800A52B4;
        }
        else
          if (temp_a0 == 5)
        {
          D_800AFA5C = 3U;
          var_s1 = &D_800A52C0;
        }
        else
          if (temp_a0 == 7)
        {
          var_s1 = &D_800A5268;
        }
          break;

        case 3:
          temp_a0_2 = ((__repair_record_D_800C35A0*)gRecords)->field_1E;
          if ((temp_a0_2 != 0) & (temp_a0_2 < 5U))
        {
          func_8006ECB4();
          save_race_to_pak();
          D_800AFA5C = 1U;
          var_s1 = &D_800A52CC;
        }
        else
        {
          if (temp_a0_2 == 5)
          {
            temp_a3 = gOrderState + 0x7DB0;
            var_a0_2 = 1;
            if (((u8) D_800C81FE) < 8U)
            {
              var_v1 = 0;
              do
              {
                var_a0_2 &= -((*((u16 *) (((char *) (((var_v1 & 255) * 2) + temp_a3)) + 0x10))) != 0);
                var_v1 += 1;
              }
              while (((u32) (var_v1 & 0xFF)) < 8U);
              if (var_a0_2 & 0xFF)
              {
                temp_v1 = *((u32 *)temp_a3);
                var_a0_3 = 0;
                if ((((u32) (*((u32 *) (((char *) temp_a3) + 4)))) < temp_v1) && (((u32) (*((u32 *) (((char *) temp_a3) + 8)))) < temp_v1))
                {
                  var_a0_3 = ((u32) (*((u32 *) (((char *) temp_a3) + 0xC)))) < temp_v1;
                }

                if ((*((u16 *) ((char *)gRecords + 14))) == 2)
                {
                  temp_v0_15 = *((u32 *) (((char *) temp_a3) + 4));
                  temp_v1 = *((u32 *) (((char *) temp_a3) + 8));
                  if (temp_v1 < (u32)temp_v0_15)
                  {
                    if (((u32) (*((u32 *) (((char *) temp_a3) + 0xC)))) < temp_v1)
                    {
                      var_a0_3 = 1;
                    }
                  }
                }
                if (var_a0_3 != 0)
                {
                  temp_v0_4 = ((__repair_record_D_800C35A0*)gRecords)->field_38;
                  if (temp_v0_4 == 0)
                  {
                    ((__repair_record_D_800C35A0*)gRecords)->field_38 = (u16) (temp_v0_4 + 1);
                  }
                }
                loadBestSplitTimes();
                goto block_56;
              }
            }
            else
            {
              var_a2 = 1;
              var_a1 = 0;
              do
              {
                temp_v0_5 = *((u16 *) (((char *) (temp_a3 - (-((var_a1 & 0xFF) * 2)))) + 0x20));
                var_a1 += 1;
                var_a2 &= -(temp_v0_5 != 0);
                temp_a0_3 = var_a2 & 0xFF;
              }
              while ((((u32) (var_a1 & 0xFF)) < 4U) & (temp_a0_3 != 0));
              if (temp_a0_3 != 0)
              {
                update_split_times();
                block_56:
                func_8005508C();

                UpdateChannelDeltas();
                save_race_to_pak();
              }
            }
          }
          D_800AFA5C = 3U;
          var_s1 = &D_800A52D8;
        }
          break;

        case 2:
          temp_a0_4 = ((__repair_record_D_800C35A0*)gRecords)->field_1E;
          if (temp_a0_4 == 5)
        {
          D_800AFA5C = 3U;
          var_s1 = &D_800A52E4;
        }
        else
          if (temp_a0_4 == 0)
        {
          func_8006F0E0(((__repair_record_D_800C35A0*)gRecords)->field_32);
          if ((*((u16 *) ((char *)gRecords + 14))) == temp_s0)
          {
            func_8006F0E0(((__repair_record_D_800C35A0*)gRecords)->field_33);
          }
          func_8006DDD8();
          save_race_to_pak();
          D_800AFA5C = 2U;
          var_s1 = &D_800A5268;
        }
        else
          if ((temp_a0_4 != 0) & (temp_a0_4 < 5U))
        {
          pack_tile_rows();
          save_race_to_pak();
          D_800AFA5C = 1U;
          var_s1 = &D_800A5268;
        }
        else
          if (temp_a0_4 == 7)
        {
          var_s1 = &D_800A52A8;
        }
          break;

      }

    }
    copyStringAligned(gSelectState + 0x2AD, (D_800AFA5C * 0x24) + ((u8 *) (&D_800A13C0)));
    copyStringAligned(gSelectState + 0x2A1, var_s1);
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
      taskRecvMsg(temp_s5);
      streamProcessList();
      osSetThreadPri(D_800B0AE0, 6);
      temp_v0_6 = find_object_by_id(0);
      g_camera = temp_v0_6;
      view_gfx_setup(((ViewObject *)temp_v0_6)->field);
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
        temp_v0_13 = view_get_ctx_id(*((void **) (((char *) g_camera) + 0x178)));
        temp_s0_2 = ((CommandObject *)temp_v0_13)->commands;
        ((CommandObject *)temp_v0_13)->commands = (void *) (temp_s0_2 + 8);
        buffer = gSceneSlot1;
        *((s32 *) (((char *) temp_s0_2) + 0)) = (s32) ((((*((s16 *) (((char *) buffer) + 4))) - 1) & 0xFFF) | 0xFF100000);
        *((s32 *) (((char *) temp_s0_2) + 4)) = func_80005C48(buffer);
      }
      temp_v0_8 = find_object_by_id(2);
      g_camera = temp_v0_8;
      var_s2 = 0;
      view_gfx_setup(((ViewObject *)temp_v0_8)->field);
      view_set_rect(*((void **) (((char *) g_camera) + 0x178)), gSceneSlot0);
      temp_v0_9 = find_object_by_id(3);
      g_camera = temp_v0_9;
      view_gfx_setup(((ViewObject *)temp_v0_9)->field);
      temp_v0_10 = find_object_by_id(4);
      new_var = ((ViewObject *)temp_v0_10)->field;
      g_camera = temp_v0_10;
      view_gfx_setup(new_var);
      view_set_rect(*((void **) (((char *) g_camera) + 0x178)), gSceneSlot0);
      temp_v0_11 = find_object_by_id(1);
      g_camera = temp_v0_11;
      view_gfx_setup(((ViewObject *)temp_v0_11)->field);
      view_set_rect(*((void **) (((char *) g_camera) + 0x178)), gSceneSlot0);
      temp_v0_12 = mtx_pool_alloc();
      guMtxIdent(temp_v0_12);
      temp_v0_13 = view_get_ctx_id(D_800ADF80);
      temp_v0_14 = gfx_get_dl(temp_v0_13);
      *((s32 *) (((char *) temp_v0_14) + 0)) = 0xDA380003;
      *((s32 *) (((char *) temp_v0_14) + 4)) = temp_v0_12;
      gfx_set_dl(temp_v0_13, temp_v0_14 + 8);
      temp_v0_12 = mtx_pool_alloc();
      guOrthoF(&sp20, (f32) (*((s16 *) (((char *) D_800ADF80) + 8))), (f32) (*((s16 *) (((char *) D_800ADF80) + 0xC))), (f32) (*((s16 *) (((char *) D_800ADF80) + 0xE))), (f32) (*((s16 *) (((char *) D_800ADF80) + 0xA))), -1.0f, 10.0f, 1.0f);
      guMtxF2L(&sp20, temp_v0_12);
      gfx_push_mtx(temp_v0_13, temp_v0_12);
      func_8005B6A8();
      updateScreenFade(D_800AFA88);
      loop_77:
      temp_s1 = (var_s2 & 255) * 0x10;

      temp_s0_4 = *((u8 *) ((gOrderState + 0x239C) + temp_s1));
      if (temp_s0_4 != cont_port_is_connected(var_s2 & 255, 2))
      {
        *((gOrderState + 0x239D) + temp_s1) = 1;
        *((s32 *) ((gOrderState + 0x2394) + temp_s1)) = 0;
      }
      var_s2 += 1;
      if (((u32) (var_s2 & 0xFF)) < 4U)
      {
        goto loop_77;
      }
      if (D_800C35C0 != 0)
      {
        do
        {
          taskRecvMsg(D_800C81DC);
          temp_v0_15 = D_800C35C0 - 1;
          D_800C35C0 = temp_v0_15;
        }
        while (temp_v0_15 != 0);
      }
      temp_v0_16 = find_object_by_id(2);
      g_camera = temp_v0_16;
      if ((((__repair_record_D_800C35A0*)gRecords)->field_2C) & 2)
      {
        func_800131C0(((ViewObject *)temp_v0_16)->field);
      }
      if (func_80013E60() < 0x78)
      {
        taskRecvMsg(temp_s4);
      }
      *((s8 *) (((char *) gSelectState) + 0x234)) = 1;
    }
    while ((*((u8 *) (((char *) gSelectState) + 0x2A0))) == 0);
    if ((*((u8 *) (((char *) gSelectState) + 0x232))) != 0)
    {
      *((u8 *) (((char *) gSelectState) + 0x232)) = 0U;
    }
    select_state_free();
    func_800578E0(gSelectStepHandle);
    func_8004C7B8();
    func_80047C78();
    nodeListRunCallbacks(D_800B7040);
    heapReleaseBlock(D_800B7040);
    func_80022214();
    func_80005DEC();
    D_800C3504 = func_80005C48(gSceneSlot1);
    if (gStreamPhase == 1)
    {
      gStreamPhase = 0;
    }
    if ((*((s16 *) (((char *) gSceneSlot1) + 4))) != 0x140)
    {
      scene_teardown();
    }
    func_8007F634(temp_s5);
    func_8007F634(D_800C81DC);
    func_8007F634(temp_s4);
    func_80089B80();
  }
}
