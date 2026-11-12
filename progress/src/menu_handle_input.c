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

extern Menu *gRaceCtx;
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
extern u8 stream_state[];

#define M gRaceCtx
extern GameState *gRecords;
#define G gRecords
extern f32 D_800C35D8;
extern f32 D_800C35DC;
extern f32 gSpeedAccum;
extern f32 gSfxVolumeScale;
#define F(off) ((off) == 0x332A ? &D_800C35D8 : (off) == 0x332E ? &D_800C35DC : (off) == 0x3332 ? &gSpeedAccum : &gSfxVolumeScale)
#define CURSET (G->set[G->unk32[M->id]])

void MusSetMasterVolume(s32, s32);
void func_800494D4(u8);
void raceResetSlots(void);
s32 updateRaceStart(void);
void func_8004E224(u8);
u8 select_stream_char(u8, u8, u8);
s32 input_get_buttons(u8);
s8 input_get_stick_axis(u8, s32);
void input_clear_flags(u8, s32);

/* Per-frame menu input: reads pad buttons and the analog stick, moves the cursor,
   changes setup values and switches menu pages. */
void menu_handle_input(void) {
    s32 buttons;
    u8 page;
    u8 charIdx;
    u8 item;
    s32 stickX;
    s32 stickY;
    f32 *val;

    buttons = input_get_buttons(M->id);
    if (buttons != 0) {
        input_clear_flags(M->id, buttons);
    }
    if ((buttons & 0x800) && M->page != 3) {
        if (M->cursor == 0) {
            M->cursor = M->pages[M->page].count - 1;
        } else {
            M->cursor--;
        }
    } else if ((buttons & 0x400) && M->page != 3) {
        if (M->cursor == M->pages[M->page].count - 1) {
            M->cursor = 0;
        } else {
            M->cursor++;
        }
    } else if (buttons & 0x200) {
        page = M->page;
        if (page == 1) {
            switch (M->cursor) {
            case 0:
                val = F(0x3332);
                if (*val > 0.0f) *val -= D_800A4F10;
                break;
            case 1:
                val = F(0x333A);
                if (*val > 0.0f) *val -= D_800A4F10;
                break;
            case 2:
                val = F(0x332E);
                if (*val > 0.0f) *val -= D_800A4F10;
                break;
            }
        } else if (page == 2) {
            charIdx = select_stream_char(G->unk1E, G->unk20, G->unk22);
            switch (M->cursor) {
            case 0: if (CURSET.a[charIdx] != 0) { CURSET.a[charIdx]--; func_800494D4(M->id); } break;
            case 1: if (CURSET.d[charIdx] > -20) { CURSET.d[charIdx] -= 10; func_800494D4(M->id); } break;
            case 2: if (CURSET.c[charIdx] != 0) { CURSET.c[charIdx]--; func_800494D4(M->id); } break;
            case 3: if (CURSET.b[charIdx] != 0) { CURSET.b[charIdx]--; func_800494D4(M->id); } break;
            }
        } else if (page == 3) {
            if (M->cursor != 0) {
                M->cursor--;
                D_800A0389 = 5;
            }
        }
    } else if (buttons & 0x100) {
        page = M->page;
        if (page == 1) {
            switch (M->cursor) {
            case 0: val = F(0x3332); if (*val < 1.0f) *val += D_800A4EE0; break;
            case 1: val = F(0x333A); if (*val < 1.0f) *val += D_800A4EE8; break;
            case 2: val = F(0x332E); if (*val < 1.0f) *val += D_800A4EF0; break;
            }
        } else if (page == 2) {
            charIdx = select_stream_char(G->unk1E, G->unk20, G->unk22);
            switch (M->cursor) {
            case 0: if (CURSET.a[charIdx] < 2) { CURSET.a[charIdx]++; func_800494D4(M->id); } break;
            case 1: if (CURSET.d[charIdx] < 20) { CURSET.d[charIdx] += 10; func_800494D4(M->id); } break;
            case 2: if (CURSET.c[charIdx] < 2) { CURSET.c[charIdx]++; func_800494D4(M->id); } break;
            case 3: if (CURSET.b[charIdx] < 2) { CURSET.b[charIdx]++; func_800494D4(M->id); } break;
            }
        } else if (page == 3) {
            if (M->cursor == 0) {
                M->cursor++;
            }
        }
    } else if (buttons & 0x8000) {
        page = M->page;
        if (page == 0) {
            if (M->cursor == 0) {
                raceResetSlots();
                MusSetMasterVolume(3, (s32)(*F(0x332A) * 32767.0f));
            } else if (G->unk1E == 0 && M->cursor == 1 && M->unk3A2 == 0) {
                M->unk384 = 0;
                M->cursor = 0;
                func_8004E224(M->id);
                MusSetMasterVolume(3, (s32)(*F(0x332A) * 32767.0f));
            } else {
                if (G->unk1E == 0 && M->unk3A2 == 0) {
                    item = M->cursor - 1;
                } else {
                    item = M->cursor;
                }
                switch (item) {
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
                updateRaceStart();
            }
        }
    } else if (buttons & 0x4000) {
        if (M->page == 0) {
            raceResetSlots();
            MusSetMasterVolume(3, (s32)(*F(0x332A) * 32767.0f));
        } else {
            M->cursor = 0;
            M->page = 0;
        }
    } else {
        stickX = input_get_stick_axis(M->id, 0x10000);
        stickY = input_get_stick_axis(M->id, 0x20000);
        if (stickX >= 90 && D_800A03D8) {
            D_800A03D8 = 0;
            if (M->page != 3) {
                if (M->cursor == 0) {
                    M->cursor = M->pages[M->page].count - 1;
                } else {
                    M->cursor--;
                }
            }
        } else if (stickX < -89 && D_800A03D8) {
            D_800A03D8 = 0;
            if (M->page != 3) {
                if (M->cursor == M->pages[M->page].count - 1) {
                    M->cursor = 0;
                } else {
                    M->cursor++;
                }
            }
        } else if (stickX > -40 && stickX < 40 && !D_800A03D8) {
            D_800A03D8 = 1;
        }
        if (stickY >= 90 && D_800A03D9) {
            D_800A03D9 = 0;
            page = M->page;
            if (page == 1) {
                switch (M->cursor) {
                case 0: val = F(0x3332); if (*val < 1.0f) *val += D_800A4EF8; break;
                case 1: val = F(0x333A); if (*val < 1.0f) *val += D_800A4F00; break;
                case 2: val = F(0x332E); if (*val < 1.0f) *val += D_800A4F08; break;
                }
            } else if (page == 2) {
                charIdx = select_stream_char(G->unk1E, G->unk20, G->unk22);
                switch (M->cursor) {
                case 0: if (CURSET.a[charIdx] < 2) { CURSET.a[charIdx]++; func_800494D4(M->id); } break;
                case 1: if (CURSET.d[charIdx] < 20) { CURSET.d[charIdx] += 10; func_800494D4(M->id); } break;
                case 2: if (CURSET.c[charIdx] < 2) { CURSET.c[charIdx]++; func_800494D4(M->id); } break;
                case 3: if (CURSET.b[charIdx] < 2) { CURSET.b[charIdx]++; func_800494D4(M->id); } break;
                }
            } else if (page == 3) {
                if (M->cursor == 0) {
                    M->cursor++;
                }
            }
        } else if (stickY < -89 && D_800A03D9) {
            D_800A03D9 = 0;
            page = M->page;
            if (page == 1) {
                switch (M->cursor) {
                case 0:
                    val = F(0x3332);
                    if (*val > 0.0f) *val -= D_800A4F10;
                    break;
                case 1:
                    val = F(0x333A);
                    if (*val > 0.0f) *val -= D_800A4F10;
                    break;
                case 2:
                    val = F(0x332E);
                    if (*val > 0.0f) *val -= D_800A4F10;
                    break;
                }
            } else if (page == 2) {
                charIdx = select_stream_char(G->unk1E, G->unk20, G->unk22);
                switch (M->cursor) {
                case 0: if (CURSET.a[charIdx] != 0) { CURSET.a[charIdx]--; func_800494D4(M->id); } break;
                case 1: if (CURSET.d[charIdx] > -20) { CURSET.d[charIdx] -= 10; func_800494D4(M->id); } break;
                case 2: if (CURSET.c[charIdx] != 0) { CURSET.c[charIdx]--; func_800494D4(M->id); } break;
                case 3:
                    if (G->set[G->unk32[M->id]].b[select_stream_char(G->unk1E, G->unk20, G->unk22)] != 0) {
                        G->set[G->unk32[M->id]].b[select_stream_char(G->unk1E, G->unk20, G->unk22)]--;
                        func_800494D4(M->id);
                    }
                    break;
                }
            } else if (page == 3) {
                if (M->cursor != 0) {
                    M->cursor--;
                }
            }
        } else if (stickY > -40 && stickY < 40 && !D_800A03D9) {
            D_800A03D9 = 1;
        }
    }
    if (D_800A0389 != 0) {
        D_800A0389--;
    }
}
