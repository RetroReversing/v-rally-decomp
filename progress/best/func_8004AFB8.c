typedef struct { u8 pad[0xDD]; u8 count; } MenuPage;
typedef struct {
    u8 pad0[8]; u8 page; MenuPage pages[4]; u8 pad381;
    u8 id; u8 cursor; u8 unk384; u8 pad385[0x1D]; u8 unk3A2;
} Menu;
typedef struct { u8 a[4]; u8 b[4]; u8 c[4]; s16 d[14]; } CarSetup;
typedef struct {
    u8 pad0[0x1E]; u16 unk1E, unk20, unk22; u8 pad24[0xE];
    u8 unk32[0x22]; CarSetup set[1];
} GameState;

extern Menu *D_800A0384;
extern u8 D_800A0389;
extern u8 D_800A03D8;
extern u8 D_800A03D9;
extern f64 D_800A4EE0;
extern f64 D_800A4EE8;
extern f64 D_800A4EF0;
extern f64 D_800A4EF8;
extern f64 D_800A4F00;
extern f64 D_800A4F08;
extern f64 D_800A4F10;
extern u8 D_800C02AE[];

#define M D_800A0384
extern GameState *D_800C35A0;
#define G D_800C35A0
#define F(off) ((f32 *)(D_800C02AE + (off)))
#define CURSET (G->set[G->unk32[M->id]])

void MusSetMasterVolume(s32, s32);
void func_800494D4(u8);
void func_80049D50(void);
s32 func_80049E28(void);
void func_8004E224(u8, s32);
u8 func_8006204C(u8, u8, u8);
s32 func_80084BF0(u8);
s8 func_80084C0C(u8, s32);
void func_80085778(u8, s32);

void func_8004AFB8(void) {
    s32 btn;
    u8 page;
    u8 sel;
    u8 idx;
    s32 x;
    s32 y;
    f32 *p;

    btn = func_80084BF0(M->id);
    if (btn != 0) {
        func_80085778(M->id, btn);
    }
    if ((btn & 0x800) && M->page != 3) {
        if (M->cursor == 0) {
            M->cursor = M->pages[M->page].count - 1;
        } else {
            M->cursor--;
        }
    } else if ((btn & 0x400) && M->page != 3) {
        if (M->cursor == M->pages[M->page].count - 1) {
            M->cursor = 0;
        } else {
            M->cursor++;
        }
    } else if (btn & 0x200) {
        page = M->page;
        if (page == 1) {
            switch (M->cursor) {
            case 0: p = F(0x3332); if (*p > 0.0f) *p -= D_800A4F10; break;
            case 1: p = F(0x333A); if (*p > 0.0f) *p -= D_800A4F10; break;
            case 2: p = F(0x332E); if (*p > 0.0f) *p -= D_800A4F10; break;
            }
        } else if (page == 2) {
            sel = func_8006204C(G->unk1E, G->unk20, G->unk22);
            switch (M->cursor) {
            case 0: if (CURSET.a[sel] != 0) { CURSET.a[sel]--; func_800494D4(M->id); } break;
            case 1: if (CURSET.d[sel] > -20) { CURSET.d[sel] -= 10; func_800494D4(M->id); } break;
            case 2: if (CURSET.c[sel] != 0) { CURSET.c[sel]--; func_800494D4(M->id); } break;
            case 3: if (CURSET.b[sel] != 0) { CURSET.b[sel]--; func_800494D4(M->id); } break;
            }
        } else if (page == 3) {
            if (M->cursor != 0) {
                M->cursor--;
                D_800A0389 = 5;
            }
        }
    } else if (btn & 0x100) {
        page = M->page;
        if (page == 1) {
            switch (M->cursor) {
            case 0: p = F(0x3332); if (*p < 1.0f) *p += D_800A4EE0; break;
            case 1: p = F(0x333A); if (*p < 1.0f) *p += D_800A4EE8; break;
            case 2: p = F(0x332E); if (*p < 1.0f) *p += D_800A4EF0; break;
            }
        } else if (page == 2) {
            sel = func_8006204C(G->unk1E, G->unk20, G->unk22);
            switch (M->cursor) {
            case 0: if (CURSET.a[sel] < 2) { CURSET.a[sel]++; func_800494D4(M->id); } break;
            case 1: if (CURSET.d[sel] < 20) { CURSET.d[sel] += 10; func_800494D4(M->id); } break;
            case 2: if (CURSET.c[sel] < 2) { CURSET.c[sel]++; func_800494D4(M->id); } break;
            case 3: if (CURSET.b[sel] < 2) { CURSET.b[sel]++; func_800494D4(M->id); } break;
            }
        } else if (page == 3) {
            if (M->cursor == 0) {
                M->cursor++;
            }
        }
    } else if (btn & 0x8000) {
        page = M->page;
        if (page == 0) {
            if (M->cursor == 0) {
                func_80049D50();
                MusSetMasterVolume(3, (s32)(*F(0x332A) * 32767.0f));
            } else if (G->unk1E == 0 && M->cursor == 1 && M->unk3A2 == 0) {
                M->unk384 = 0;
                M->cursor = 0;
                func_8004E224(M->id, 1);
                MusSetMasterVolume(3, (s32)(*F(0x332A) * 32767.0f));
            } else {
                if (G->unk1E == 0 && M->unk3A2 == 0) {
                    idx = M->cursor - 1;
                } else {
                    idx = M->cursor;
                }
                switch (idx) {
                case 1:
                    M->cursor = 1;
                    M->page = 3;
                    D_800A0389 = 5;
                    break;
                case 2:
                    M->cursor = 0;
                    M->page = 1;
                    break;
                case 3:
                    if (G->unk1E == 0) {
                        M->cursor = 0;
                        M->page = 2;
                    }
                    break;
                }
            }
        } else if (page == 1) {
            if (M->cursor == 3) {
                M->cursor = 0;
                M->page = 0;
            }
        } else if (page == 2) {
            if (M->cursor == 4) {
                M->cursor = 0;
                M->page = 0;
            }
        } else if (page == 3) {
            if (M->cursor == 1) {
                M->cursor = 0;
                M->page = 0;
            } else if (D_800A0389 == 0) {
                func_80049E28();
            }
        }
    } else if (btn & 0x4000) {
        if (M->page == 0) {
            func_80049D50();
            MusSetMasterVolume(3, (s32)(*F(0x332A) * 32767.0f));
        } else {
            M->cursor = 0;
            M->page = 0;
        }
    } else {
        x = func_80084C0C(M->id, 0x10000);
        y = func_80084C0C(M->id, 0x20000);
        if (x >= 90 && D_800A03D8) {
            D_800A03D8 = 0;
            if (M->page != 3) {
                if (M->cursor == 0) {
                    M->cursor = M->pages[M->page].count - 1;
                } else {
                    M->cursor--;
                }
            }
        } else if (x < -89 && D_800A03D8) {
            D_800A03D8 = 0;
            if (M->page != 3) {
                if (M->cursor == M->pages[M->page].count - 1) {
                    M->cursor = 0;
                } else {
                    M->cursor++;
                }
            }
        } else if (x > -40 && x < 40 && !D_800A03D8) {
            D_800A03D8 = 1;
        }
        if (y >= 90 && D_800A03D9) {
            D_800A03D9 = 0;
            page = M->page;
            if (page == 1) {
                switch (M->cursor) {
                case 0: p = F(0x3332); if (*p < 1.0f) *p += D_800A4EF8; break;
                case 1: p = F(0x333A); if (*p < 1.0f) *p += D_800A4F00; break;
                case 2: p = F(0x332E); if (*p < 1.0f) *p += D_800A4F08; break;
                }
            } else if (page == 2) {
                sel = func_8006204C(G->unk1E, G->unk20, G->unk22);
                switch (M->cursor) {
                case 0: if (CURSET.a[sel] < 2) { CURSET.a[sel]++; func_800494D4(M->id); } break;
                case 1: if (CURSET.d[sel] < 20) { CURSET.d[sel] += 10; func_800494D4(M->id); } break;
                case 2: if (CURSET.c[sel] < 2) { CURSET.c[sel]++; func_800494D4(M->id); } break;
                case 3: if (CURSET.b[sel] < 2) { CURSET.b[sel]++; func_800494D4(M->id); } break;
                }
            } else if (page == 3) {
                if (M->cursor == 0) {
                    M->cursor++;
                }
            }
        } else if (y < -89 && D_800A03D9) {
            D_800A03D9 = 0;
            page = M->page;
            if (page == 1) {
                switch (M->cursor) {
                case 0: p = F(0x3332); if (*p > 0.0f) *p -= D_800A4F10; break;
                case 1: p = F(0x333A); if (*p > 0.0f) *p -= D_800A4F10; break;
                case 2: p = F(0x332E); if (*p > 0.0f) *p -= D_800A4F10; break;
                }
            } else if (page == 2) {
                sel = func_8006204C(G->unk1E, G->unk20, G->unk22);
                switch (M->cursor) {
                case 0: if (CURSET.a[sel] != 0) { CURSET.a[sel]--; func_800494D4(M->id); } break;
                case 1: if (CURSET.d[sel] > -20) { CURSET.d[sel] -= 10; func_800494D4(M->id); } break;
                case 2: if (CURSET.c[sel] != 0) { CURSET.c[sel]--; func_800494D4(M->id); } break;
                case 3:
                    if (G->set[G->unk32[M->id]].b[func_8006204C(G->unk1E, G->unk20, G->unk22)] != 0) {
                        G->set[G->unk32[M->id]].b[func_8006204C(G->unk1E, G->unk20, G->unk22)]--;
                        func_800494D4(M->id);
                    }
                    break;
                }
            } else if (page == 3) {
                if (M->cursor != 0) {
                    M->cursor--;
                }
            }
        } else if (y > -40 && y < 40 && !D_800A03D9) {
            D_800A03D9 = 1;
        }
    }
    if (D_800A0389 != 0) {
        D_800A0389--;
    }
}
