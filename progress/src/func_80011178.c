typedef struct { s32 x, y, z; } Vec3i;

typedef struct CamEntry {
    u8 pad00[0xE]; s16 unkE; s32 unk10; u8 pad14[2]; s16 unk16;
    u8 pad18[2]; s16 unk1A; s32 unk1C; u8 pad20[2]; s16 unk22; u8 pad24[4];
} CamEntry;

typedef struct CarObj {
    u8 pad00[0x40]; s16 m[9]; u8 pad52[2]; s32 x, y, z;
} CarObj;

typedef struct CarInfo { s32 unk0; u8 pad04[0x1C]; s32 unk20; } CarInfo;
typedef struct CarState { u8 pad00[0x39C]; s32 unk39C; } CarState;

typedef struct Car {
    u8 pad00[0x14]; u32 flags; u8 pad18[0x30]; CarInfo *info; u8 pad4C[0x10];
    CarObj *obj; u8 pad60[0x20]; CarState *state;
} Car;

typedef struct CamData {
    u8 pad00[0xD0]; f32 D0; u8 padD4[8]; f32 DC; f32 E0, E4, E8, EC, F0, F4, F8, FC, F100;
} CamData;

typedef struct Game {
    u8 pad00[0x20]; u16 flags; u8 pad22[2]; Car *car; u8 pad28[0x10]; CamData cd;
} Game;

typedef struct CamMode { u8 pad00[8]; s32 unk8; } CamMode;

typedef struct Cam {
    u8 pad00[0x10]; s32 unk10, unk14, unk18; u8 pad1C[4]; s32 unk20, unk24;
    u8 pad28[8]; u32 mode; s32 unk34; Vec3i v[2]; s32 unk50, unk54; u8 pad58[8];
    s32 unk60; u8 pad64[4]; u16 unk68; s16 unk6A; CamMode *unk6C;
} Cam;

typedef struct { s32 x, y, z; } OffTbl;

extern Game *D_800C7F84;
extern u8 *D_800C35A0;
extern u8 D_800A16F4[];
extern CamEntry *D_8009BEE0;
extern OffTbl D_8009CE8C[];
extern f32 D_8009F590;
extern f64 D_800A4030;
extern f64 D_800A4038;
extern s32 D_8009BA38;
extern s32 D_8009BA30;

s32 func_80010DEC(s32, s32, s32);
void func_80010E08(s32, s32, s32, s32 *, s32);
void func_80010EC8(Cam *, Car *);
void func_80010F90(Cam *, Car *);
s32 func_8001FD14(Car *);
s32 func_8002D2C8(s16, s16);
s32 func_8002D2E4(s32);
s32 func_8002D348(s32);
void func_8002D75C(s32, s32, s32, s32 *);
void func_8002E148(s16 *, s16 *);
void *func_8002E514(void *, void *, void *);

void func_80011178(Cam *cam) {
    Car *car;
    CamEntry *ent;
    CamData *cd;
    s32 i;
    s32 ang;
    s32 r;
    s32 s1;
    s32 s0;
    s32 idx;
    u32 fl;
    s32 tgt;
    s32 cur;
#define dd i
    CamEntry **tp;
    s32 out[3];
    s16 p2[3];
    s16 p1[3];
    s16 p0[3];
    s16 a[3];
    s16 b[3];
    s16 d[3];
    s16 mtx[16];
    s32 sgn;

    car = D_800C7F84->car;
    if (car == NULL) {
        return;
    }
    fl = car->flags;
    if (fl & 0x800) {
        if (!(fl & 0x400)) {
            if (car->info->unk20 == 0) {
                car->flags = fl | 0x400;
                cam->mode = D_800A16F4[*(D_800C35A0 + car->info->unk0 + 0x32)];
                if (cam->mode >= 5) {
                    cam->mode = 2;
                }
            }
        }
    }
    if (cam->unk6C->unk8 == 1) {
        car->flags |= 0x800;
    }
    tp = &D_8009BEE0;
    ent = *tp; ent += cam->mode;
    tp=(CamEntry**)((u32)tp^(u32)cam); tp=(CamEntry**)((u32)tp^(u32)cam);
    cd = &D_800C7F84->cd;
    if (D_800C7F84->flags & 0x100) {
        if (!(D_800C7F84->flags & 0x200)) {
            cam->unk34 = cam->mode;
            D_800C7F84->flags |= 0x200;
        }
        D_800C7F84->flags &= 0xFF77;
        if (cam->mode == 0) {
            func_80010EC8(cam, car);
            goto again;
        } else if (cam->mode == 1) {
        again:
            func_80010EC8(cam, car);
        }
        if (car->state->unk39C == 4) {
            if (D_800C7F84->flags & 0x200) {
                D_800C7F84->flags &= 0xFEFF;
                cam->mode = cam->unk34;
                D_800C7F84->flags &= 0xFDFF;
            }
        }
    } else if (car->obj->m[4] < 0 && (*(u32 *)&D_800C7F84->flags & 0x880000)) {
        D_800C7F84->flags |= 0x100;
    }

    switch (cam->mode) {
    case 0:
        D_800C7F84->flags |= 8;
        cd->E0 = car->obj->x;
        cd->E4 = car->obj->y - 50;
        cd->E8 = car->obj->z;
        if (D_800C7F84->flags & 0x40) {
            cd->EC = cd->E0 - car->obj->m[2];
            cd->F0 = cd->E4 + car->obj->m[5];
            cd->F4 = cd->E8 - car->obj->m[8];
        } else {
            cd->EC = cd->E0 + car->obj->m[2];
            cd->F0 = cd->E4 + car->obj->m[5];
            cd->F4 = cd->E8 + car->obj->m[8];
        }
        for (i = 0; i < 2; i++) {
            cam->v[i].x = 0;
            cam->v[i].y = 0;
            cam->v[i].z = 0;
        }
        if (D_800C7F84->flags & 0x40) {
            d[0] = cd->EC - cd->E0;
            d[2] = cd->F4 - cd->E8;
            ang = -func_8002D2C8(d[2], d[0]);
            cam->unk50 = cam->unk54 = ang;
        } else {
            ang = func_8001FD14(car);
            cam->unk50 = cam->unk54 = ang;
        }
        a[0] = 0x1000;
        a[1] = 0;
        a[2] = 0;
        func_8002E514(car->obj->m, a, b);
        r = func_8002D2C8(b[2], b[0]);
        a[0] = 0;
        a[1] = r;
        a[2] = 0;
        func_8002E148(a, mtx);
        func_8002E514(mtx, b, a);
        r = func_8002D2C8(a[1], a[0]);
        p0[0] = car->obj->m[2];
        p0[1] = car->obj->m[8];
        p1[0] = 0;
        p1[1] = 0;
        p2[0] = car->obj->m[0];
        p2[1] = car->obj->m[6];
        func_8002D75C(*(s32 *)p0, *(s32 *)p1, *(s32 *)p2, &sgn);
        if (sgn < 0) {
            cd->D0 = 0x800 - (s16)r;
        } else {
            cd->D0 = (s16)r;
        }
        cd->F8 = car->obj->m[1];
        cd->FC = car->obj->m[4];
        cd->F100 = car->obj->m[7];
        if (D_800C7F84->flags & 0x40) {
            cd->D0 = -cd->D0;
        }
        break;
    case 1:
        D_800C7F84->flags |= 0x88;
        if (*(u16 *)(D_800C35A0 + 0x1E) == 7) {
            idx = 0;
        } else {
            idx = car->info->unk0;
        }
        cd->E0 = car->obj->x + D_8009CE8C[idx].x;
        if (D_800C7F84->flags & 0x40) {
            cd->E4 = car->obj->y + D_8009CE8C[idx].y - 40;
        } else {
            cd->E4 = car->obj->y + D_8009CE8C[idx].y;
        }
        cd->E8 = car->obj->z + D_8009CE8C[idx].z;
        if (D_800C7F84->flags & 0x40) {
            cd->EC = cd->E0 - car->obj->m[2];
            cd->F0 = cd->E4 + car->obj->m[5];
            cd->F4 = cd->E8 - car->obj->m[8];
        } else {
            cd->EC = cd->E0 + car->obj->m[2];
            cd->F0 = cd->E4 + car->obj->m[5];
            cd->F4 = cd->E8 + car->obj->m[8];
        }
        for (i = 0; i < 2; i++) {
            cam->v[i].x = 0;
            cam->v[i].y = 0;
            cam->v[i].z = 0;
        }
        if (D_800C7F84->flags & 0x40) {
            d[0] = cd->EC - cd->E0;
            d[2] = cd->F4 - cd->E8;
            ang = -func_8002D2C8(d[2], d[0]);
            cam->unk50 = cam->unk54 = ang;
        } else {
            ang = func_8001FD14(car);
            cam->unk50 = cam->unk54 = ang;
        }
        a[0] = 0x1000;
        a[1] = 0;
        a[2] = 0;
        func_8002E514(car->obj->m, a, b);
        r = func_8002D2C8(b[2], b[0]);
        a[0] = 0;
        a[1] = r;
        a[2] = 0;
        func_8002E148(a, mtx);
        func_8002E514(mtx, b, a);
        r = func_8002D2C8(a[1], a[0]);
        p0[0] = car->obj->m[2];
        p0[1] = car->obj->m[8];
        p1[0] = 0;
        p1[1] = 0;
        p2[0] = car->obj->m[0];
        p2[1] = car->obj->m[6];
        func_8002D75C(*(s32 *)p0, *(s32 *)p1, *(s32 *)p2, &sgn);
        if (sgn < 0) {
            cd->D0 = 0x800 - (s16)r;
        } else {
            cd->D0 = (s16)r;
        }
        cd->F8 = car->obj->m[1];
        cd->FC = car->obj->m[4];
        cd->F100 = car->obj->m[7];
        if (D_800C7F84->flags & 0x40) {
            cd->D0 = -cd->D0;
        }
        D_800C7F84->flags &= 0xFFF7;
        break;
    case 2:
    case 3:
    case 6:
        {
        if (cam->unk68 & 1) { tgt = cam->unk60; } else {
            tgt = (func_8001FD14(car) + 0x800) + D_8009F590 * D_800A4030;
        }
        cur = (cam->unk54 + 0x800) & 0xFFF;
        dd = tgt - cur;
        if (dd < 0) {
            dd = -dd;
        }
        if (dd > 0x800) {
            if (tgt < cur) {
                tgt += 0x1000;
            } else {
                cur += 0x1000;
            }
        }

        cur = func_80010DEC(cur, tgt, cam->unk20) - 0x800;
        if (cam->mode >= 2) {
            cam->unk20 = func_80010DEC(cam->unk20, cam->unk10, cam->unk18);
            cam->unk24 = func_80010DEC(cam->unk24, cam->unk14, cam->unk18);
        }
        cam->unk54 = cur;
        if ((D_800C7F84->flags & 0x40) || (cam->unk68 & 2)) {
            cam->unk54 = (tgt + 0x800) & 0xFFF;
            if (D_800C7F84->flags & 0x40) {
                ent += 5;
            }
        }
        func_80010E08(cam->unk54, ent->unkE, ent->unk16, out, cam->unk6A);
        cam->v[1].x = out[0];
        cam->v[1].y = ent->unk10;
        cam->v[1].z = out[2];
        if ((D_800C7F84->flags & 0x40) || (cam->unk68 & 2)) {
            cam->v[0] = cam->v[1];
        }
        cam->v[0].x = func_80010DEC(cam->v[0].x, cam->v[1].x, cam->unk24);
        cam->v[0].y = func_80010DEC(cam->v[0].y, cam->v[1].y, cam->unk24);
        cam->v[0].z = func_80010DEC(cam->v[0].z, cam->v[1].z, cam->unk24);
        cd->E0 = cam->v[0].x;
        cd->E4 = cam->v[0].y;
        cd->E8 = cam->v[0].z;
        func_80010E08(cam->unk54, ent->unk1A, ent->unk22, out, cam->unk6A);
        cd->EC = out[0];
        cd->F0 = ent->unk1C;
        cd->F4 = out[2];
        cd->E0 += car->obj->x;
        cd->E4 += car->obj->y;
        cd->E8 += car->obj->z;
        cd->EC += car->obj->x;
        cd->F0 += car->obj->y;
        cd->F4 += car->obj->z;
        cd->F8 = 0.0f;
        cd->FC = 1.0f;
        cd->F100 = 0.0f;
        cd->DC = 1.0f;
        cd->D0 = 0.0f;
        D_800C7F84->flags &= 0xFF77;
        cam->unk68 &= 0xFFFD;
        }
        break;
    case 4:
        D_8009BA38 = (D_8009BA38 + 20) & 0xFFF;
        D_800C7F84->flags &= 0xFF77;
        s0 = func_8002D348(D_8009BA38) * 3048 / 32768;
        s1 = func_8002D2E4(D_8009BA38) * 3048 / 32768;
        cd->EC = car->obj->x;
        cd->F0 = car->obj->y;
        cd->F4 = car->obj->z;
        cd->E0 = cd->EC + s0;
        cd->E4 = cd->F0 - 100.0f;
        cd->E8 = cd->F4 + s1;
        cd->F8 = 0.0f;
        cd->FC = 1.0f;
        cd->F100 = 0.0f;
        cd->DC = 1.0f;
        break;
    case 5:
        ent = *tp;
        tgt = (func_8001FD14(car) + 0x800) + D_8009F590 * D_800A4038;
        ent += 4;
        cur = (cam->unk54 + 0x800) & 0xFFF;
        dd = tgt - cur;
        if (dd < 0) {
            dd = -dd;
        }
        if (dd > 0x800) {
            if (tgt < cur) {
                tgt += 0x1000;
            } else {
                cur += 0x1000;
            }
        }
        s0 = func_80010DEC(cur, tgt, cam->unk20) - 0x800;
        if (cam->mode >= 2) {
            cam->unk20 = func_80010DEC(cam->unk20, cam->unk10, cam->unk18);
            cam->unk24 = func_80010DEC(cam->unk24, cam->unk14, cam->unk18);
        }
        cam->unk54 = s0;
        func_80010E08(cam->unk54, ent->unkE, ent->unk16, out, cam->unk6A);
        cam->v[1].x = out[0];
        cam->v[1].y = ent->unk10;
        cam->v[1].z = out[2];
        cam->v[0].x = func_80010DEC(cam->v[1].x, cam->v[1].x, cam->unk24);
        cam->v[0].y = func_80010DEC(cam->v[1].y, cam->v[1].y, cam->unk24);
        cam->v[0].z = func_80010DEC(cam->v[1].z, cam->v[1].z, cam->unk24);
        cd->E0 = cam->v[0].x;
        cd->E4 = cam->v[0].y;
        cd->E8 = cam->v[0].z;
        func_80010E08(cam->unk54, ent->unk1A, ent->unk22, out, cam->unk6A);
        cd->EC = out[0];
        cd->F0 = ent->unk1C;
        cd->F4 = out[2];
        cd->E0 += car->obj->x;
        cd->E4 += car->obj->y;
        cd->E8 += car->obj->z;
        cd->EC += car->obj->x;
        cd->F0 += car->obj->y;
        cd->F4 += car->obj->z;
        cd->F8 = 0.0f;
        cd->FC = 1.0f;
        cd->F100 = 0.0f;
        cd->D0 = 0.0f;
        D_800C7F84->flags &= 0xFF77;
        cam->unk68 &= 0xFFFD;
        break;
    }
    if (D_8009BA30 == 0) {
        func_80010F90(cam, car);
    }
}
