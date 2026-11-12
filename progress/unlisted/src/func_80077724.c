typedef struct { s32 a; u8 pad[0x30]; u16 flags; } TextObj;
typedef struct { u8 pad[0x22]; u16 track; } RaceInfo;
typedef struct { u8 pad[0x178]; s32 gfx; } Ctx;
extern TextObj D_800C820C;
extern Ctx *g_camera;
extern u8 D_800C81FC;
extern u8 D_800C81FD;
extern u8 D_800C81FE;
extern u8 D_800C81FF;
extern s8 D_800C8308;
extern s32 gSelectStepHandle;
extern char D_800C8380[];
extern s32 D_800D0664;
extern RaceInfo *gRecords;
extern u32 D_800AFA6C;
extern u16 D_800B6610[];
extern u16 D_800A1814[];
extern u8 D_800A17E8;
extern s32 D_800A1798;
extern s32 D_800A5EAC;
extern void *gCarEntries;
s32 view_set_rect(s32, s32);
s32 view_get_ctx_id(s32);
s32 *gfx_get_dl(s32);
s32 gfx_set_dl(s32, s32 *);
s32 gfx_push_mtx(s32, s32);
s32 func_8000C244(s32, s32, s16, s32, void *, s32);
s32 func_8000C9B0(void *, void *, u8, f32, u8);
s32 view_gfx_setup(s32);
s32 mtx_pool_alloc(void);
Ctx *find_object_by_id(s32);
void *pool_get_item(s32, s32);
s32 func_80073108(s32, s16, s32, s32, s32);
s32 func_80078724(s32);
s32 func_80084BF0(s32);
s32 func_80085778(s32, s32);
void guMtxF2L(f32 (*)[4], s32);
void guMtxIdent(void *);
void guOrthoF(f32 (*)[4], f32, f32, f32, f32, f32, f32, f32);

s32 func_80077724(void)
{
  f32 mf[4][4];
  s32 dp;
  s32 gfx;
  s32 *dl;
  s32 mtx;
  s32 pad;
  s32 w;
#define tot w
  s16 x;
  s32 m;
  s16 x2;
  s32 ok;
  u8 i;
  void *str;
  f32 scale;
  u16 *fl;

  fl = &D_800C820C.flags;
  ok = 0;
  if (*fl & 0x800)
    goto end1;
  g_camera = find_object_by_id(4);
  view_gfx_setup(g_camera->gfx);
  view_set_rect(g_camera->gfx, g_camera->gfx + 8);
  guMtxIdent(D_800C8380);
  gfx = view_get_ctx_id(g_camera->gfx);
  {
    s32 *d = gfx_get_dl(gfx);
    d[0] = 0xDA380003;
    d[1] = (s32)D_800C8380;
    gfx_set_dl(gfx, d + 2);
  }
  mtx = mtx_pool_alloc();
  guOrthoF(mf, 0.0f, 320.0f, 240.0f, 0.0f, -1.0f, 10.0f, 1.0f);
  scale = 1.0f;
  guMtxF2L(mf, mtx);
  gfx_push_mtx(gfx, mtx);
  dl = gfx_get_dl(gfx);
  dl[0] = 0xDE000000;
  dl[1] = (s32)&D_800A1798;
  gfx_set_dl(gfx, dl + 2);
  if (D_800C81FC != 0) {
    if (D_800AFA6C == D_800A1814[gRecords->track]) {
      D_800AFA6C--;
      pad = func_80084BF0(0);
      if (pad & 0x8000) {
        func_80085778(0, pad);
        D_800AFA6C++;
      }
      if (D_800C81FF == 2) {
        pad = func_80084BF0(1);
        if (pad & 0x8000) {
          func_80085778(1, pad);
          D_800AFA6C++;
        }
      }
      func_80078724(gfx);
      w = func_8000C9B0((void *)(&D_800C820C), (void *)(&D_800A5EAC), (u8)(1), (f32)(1.0f), (u8)(1));
      dp = D_800D0664;
      x = 0x131 - (D_800A17E8 + w);
      func_80073108(gfx, x, 0xDA, dp, 0);
      func_8000C244(D_800C820C.a, gfx, x + D_800A17E8, 0xDC, &D_800A5EAC, 1);
      return 0;
    }
    m = D_800C81FD;
    if (m != 5) {
      if ((m ^ 2) == 0) {
        w = D_800A17E8 + func_8000C9B0((void *)((char *)fl - 0x34), (void *)(pool_get_item(gSelectStepHandle, 0xD6)), (u8)(1), (f32)(scale), (u8)(1)) + 0x15;
      } else {
        w = D_800A17E8 + func_8000C9B0((void *)((char *)fl - 0x34), (void *)(pool_get_item(gSelectStepHandle, 0xD7)), (u8)(1), (f32)(scale), (u8)(1)) + 0x15;
      }
    } else {
      ok = 1;
      if (D_800C81FE < 8) {
        i = 0;
        do {
          ok &= -(D_800B6610[i] != 0);
          i++;
        } while ((i < 8) & ((ok & 0xFF) != 0));
      } else {
        i = 8;
        do {
          ok &= -(D_800B6610[i] != 0);
          i++;
        } while ((i < 12) & ((ok & 0xFF) != 0));
      }
      if (!(ok & 0xFF))
        str = pool_get_item(gSelectStepHandle, 0xD5);
      else
        str = pool_get_item(gSelectStepHandle, 0xD7);
      w = D_800A17E8 + func_8000C9B0((void *)(&D_800C820C), (void *)(str), (u8)(1), (f32)(1.0f), (u8)(1)) + 0x15;
    }
    if (D_800A1814[gRecords->track] > D_800AFA6C) {
      s32 xm, xs;
      dp = D_800D0664;
      xm = 0x140 - tot;
      func_80073108(gfx, xm, 0xDA, dp, 0);
      xs = xm + D_800A17E8;
      x2 = xs;
      m = D_800C81FD;
      if (m != 5) {
        if ((m ^ 2) == 0)
          str = pool_get_item(gSelectStepHandle, 0xD6);
        else
          str = pool_get_item(gSelectStepHandle, 0xD7);
      } else if (!(ok & 0xFF)) {
        str = pool_get_item(gSelectStepHandle, 0xD5);
      } else {
        str = pool_get_item(gSelectStepHandle, 0xD7);
      }
      func_8000C244(D_800C820C.a, gfx, x2, 0xDC, str, 1);
    }
    pad = func_80084BF0(0);
    if (pad & 0x8000) {
      func_80085778(0, pad);
      D_800C8308 = 1;
    }
    if (D_800C81FF == 2) {
      pad = func_80084BF0(1);
      if (pad & 0x8000) {
        func_80085778(1, pad);
        D_800C8308 = 1;
      }
    }
end1:
    if (*(u16 *)((char *)gCarEntries + 0xC) == *(u16 *)((char *)gCarEntries + 0xE))
      D_800C8308 = 1;
    return 1;
  }
  if (D_800AFA6C < 25)
    return 0;
  func_80078724(gfx);
  m = D_800C81FD;
  if (m != 5) {
    if ((m ^ 2) == 0) {
      w = D_800A17E8 + func_8000C9B0((void *)((char *)fl - 0x34), (void *)(pool_get_item(gSelectStepHandle, 0xD6)), (u8)(1), (f32)(scale), (u8)(1)) + 0x15;
    } else {
      w = D_800A17E8 + func_8000C9B0((void *)((char *)fl - 0x34), (void *)(pool_get_item(gSelectStepHandle, 0xD7)), (u8)(1), (f32)(scale), (u8)(1)) + 0x15;
    }
  } else {
    ok = 1;
    if (D_800C81FE < 8) {
      i = 0;
      do {
        ok &= -(D_800B6610[i] != 0);
        i++;
      } while ((i < 8) & ((ok & 0xFF) != 0));
    } else {
      i = 8;
      do {
        ok &= -(D_800B6610[i] != 0);
        i++;
      } while ((i < 12) & ((ok & 0xFF) != 0));
    }
    if (!(ok & 0xFF))
      str = pool_get_item(gSelectStepHandle, 0xD5);
    else
      str = pool_get_item(gSelectStepHandle, 0xD7);
    w = D_800A17E8 + func_8000C9B0((void *)(&D_800C820C), (void *)(str), (u8)(1), (f32)(1.0f), (u8)(1)) + 0x15;
  }
  {
    s32 xm, xs;
    s32 d2 = D_800D0664;
    xm = 0x140 - w;
    func_80073108(gfx, xm, 0xDA, d2, 0);
    xs = xm + D_800A17E8;
    x2 = xs;
  }
  m = D_800C81FD;
  if (m != 5) {
    if ((m ^ 2) == 0)
      str = pool_get_item(gSelectStepHandle, 0xD6);
    else
      str = pool_get_item(gSelectStepHandle, 0xD7);
  } else if (!(ok & 0xFF)) {
    str = pool_get_item(gSelectStepHandle, 0xD5);
  } else {
    str = pool_get_item(gSelectStepHandle, 0xD7);
  }
  func_8000C244(D_800C820C.a, gfx, x2, 0xDC, str, 1);
  pad = func_80084BF0(0);
  if (pad & 0x8000) {
    func_80085778(0, pad);
    D_800C8308 = 1;
  }
  if (D_800C81FF == 2) {
    pad = func_80084BF0(1);
    if (pad & 0x8000) {
      func_80085778(1, pad);
      D_800C8308 = 1;
    }
  }
  if (*(u16 *)((char *)gCarEntries + 0xC) == *(u16 *)((char *)gCarEntries + 0xE))
    D_800C8308 = 1;
  return 0;
}
