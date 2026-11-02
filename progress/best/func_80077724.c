typedef struct { s32 a; u8 pad[0x30]; u16 flags; } TextObj;
typedef struct { u8 pad[0x22]; u16 track; } RaceInfo;
typedef struct { u8 pad[0x178]; s32 gfx; } Ctx;
extern TextObj D_800C820C;
extern Ctx *D_800C7F84;
extern u8 D_800C81FC;
extern u8 D_800C81FD;
extern u8 D_800C81FE;
extern u8 D_800C81FF;
extern s8 D_800C8308;
extern s32 D_800C8328;
extern char D_800C8380[];
extern s32 D_800D0664;
extern RaceInfo *D_800C35A0;
extern u32 D_800AFA6C;
extern u16 D_800B6610[];
extern u16 D_800A1814[];
extern u8 D_800A17E8;
extern s32 D_800A1798;
extern s32 D_800A5EAC;
extern void *D_800A1234;
s32 func_80005500(s32, s32);
s32 func_800056FC(s32);
s32 *func_80006008(s32);
s32 func_80006014(s32, s32 *);
s32 func_800061FC(s32, s32);
s32 func_8000C244(s32, s32, s16, s32, void *, s32);
s32 func_8000C9B0(void *, void *, s32, f32, s32);
s32 func_8000E8B8(s32);
s32 func_8001BD1C(void);
Ctx *func_8004240C(s32);
void *func_80057918(s32, s32);
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
  s32 gfx;
  s32 *dl;
  s32 mtx;
  s32 pad;
  s32 w;
  s16 x;
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
  func_8000E8B8((D_800C7F84 = func_8004240C(4))->gfx);
  func_80005500(D_800C7F84->gfx, D_800C7F84->gfx + 8);
  guMtxIdent(D_800C8380);
  gfx = func_800056FC(D_800C7F84->gfx);
  dl = func_80006008(gfx);
  {
    s32 *g = dl;
    dl += 2;
    g[0] = 0xDA380003;
    g[1] = (s32)D_800C8380;
  }
  func_80006014(gfx, dl);
  mtx = func_8001BD1C();
  guOrthoF(mf, 0.0f, 320.0f, 240.0f, 0.0f, -1.0f, 10.0f, 1.0f);
  scale = 1.0f;
  guMtxF2L(mf, mtx);
  func_800061FC(gfx, mtx);
  dl = func_80006008(gfx);
  dl[0] = 0xDE000000;
  dl[1] = (s32)&D_800A1798;
  func_80006014(gfx, dl + 2);
  if (D_800C81FC != 0) {
    if (D_800AFA6C == D_800A1814[D_800C35A0->track]) {
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
      x = 0x131 - (D_800A17E8 + func_8000C9B0(&D_800C820C, &D_800A5EAC, 1, 1.0f, 1));
      func_80073108(gfx, x, 0xDA, D_800D0664, 0);
      func_8000C244(D_800C820C.a, gfx, x + D_800A17E8, 0xDC, &D_800A5EAC, 1);
      return 0;
    }
    if (D_800C81FD != 5) {
      if ((D_800C81FD ^ 2) == 0) {
        w = func_8000C9B0((char *)fl - 0x34, func_80057918(D_800C8328, 0xD6), 1, scale, 1);
      } else {
        w = func_8000C9B0((char *)fl - 0x34, func_80057918(D_800C8328, 0xD7), 1, scale, 1);
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
        str = func_80057918(D_800C8328, 0xD5);
      else
        str = func_80057918(D_800C8328, 0xD7);
      w = func_8000C9B0(&D_800C820C, str, 1, 1.0f, 1);
    }
    w = D_800A17E8 + w + 0x15;
    if (D_800AFA6C < D_800A1814[D_800C35A0->track]) {
      x = 0x140 - w;
      func_80073108(gfx, x, 0xDA, D_800D0664, 0);
      x2 = x + D_800A17E8;
      if (D_800C81FD != 5) {
        if ((D_800C81FD ^ 2) == 0)
          str = func_80057918(D_800C8328, 0xD6);
        else
          goto d7a;
      } else if (!(ok & 0xFF)) {
        str = func_80057918(D_800C8328, 0xD5);
      } else {
d7a:
        str = func_80057918(D_800C8328, 0xD7);
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
    if (*(u16 *)((char *)D_800A1234 + 0xC) == *(u16 *)((char *)D_800A1234 + 0xE))
      D_800C8308 = 1;
    return 1;
  }
  if (D_800AFA6C < 25)
    return 0;
  func_80078724(gfx);
  if (D_800C81FD != 5) {
    if ((D_800C81FD ^ 2) == 0) {
      w = func_8000C9B0((char *)fl - 0x34, func_80057918(D_800C8328, 0xD6), 1, scale, 1);
    } else {
      w = func_8000C9B0((char *)fl - 0x34, func_80057918(D_800C8328, 0xD7), 1, scale, 1);
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
      str = func_80057918(D_800C8328, 0xD5);
    else
      str = func_80057918(D_800C8328, 0xD7);
    w = func_8000C9B0(&D_800C820C, str, 1, 1.0f, 1);
  }
  x = 0x140 - (D_800A17E8 + w + 0x15);
  func_80073108(gfx, x, 0xDA, D_800D0664, 0);
  x2 = x + D_800A17E8;
  if (D_800C81FD != 5) {
    if ((D_800C81FD ^ 2) == 0)
      str = func_80057918(D_800C8328, 0xD6);
    else
      goto d7b;
  } else if (!(ok & 0xFF)) {
    str = func_80057918(D_800C8328, 0xD5);
  } else {
d7b:
    str = func_80057918(D_800C8328, 0xD7);
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
  if (*(u16 *)((char *)D_800A1234 + 0xC) == *(u16 *)((char *)D_800A1234 + 0xE))
    D_800C8308 = 1;
  return 0;
}
