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

extern Game *g_camera;
extern u8 *gRecords;
extern u8 gRecordTier[];
extern CamEntry *D_8009BEE0;
extern OffTbl D_8009CE8C[];
extern f32 gCamPanOffset;
extern f64 D_800A4030;
extern f64 D_800A4038;
extern s32 D_8009BA38;
extern s32 D_8009BA30;

s32 lerp_q7(s32, s32, s32);
void setObjectTransform(s32, s32, s32, s32 *, s32);
void advanceStreamFrame(Cam *, Car *);
void updatePlayerPauseInput(Cam *, Car *);
s32 func_8001FD14(Car *);
s32 angle_atan2_thunk(s16, s16);
s32 cos_q12(s32);
s32 sin_q12(s32);
void func_8002D75C(s32, s32, s32, s32 *);
void mat3x3_from_euler(s16 *, s16 *);
void *mtx3_transform_vec3(void *, void *, void *);

/* Per-frame camera update: picks the mode's target position and yaw from the player car,
 * eases toward it, and writes the result into g_camera's cam_data. */
void update_camera(Cam *cam) {
    Car *car;
    CamEntry *entry;
    CamData *cam_data;
    s32 i;
    s32 heading;
    s32 yaw;
    s32 off_z;
    s32 off_x;
    s32 info_idx;
    u32 car_flags;
    s32 target_yaw;
    s32 cur_yaw;
#define dd i
    CamEntry **tbl;
    s32 pos_out[3];
    s16 pack2[3];
    s16 pack1[3];
    s16 pack0[3];
    s16 vec_a[3];
    s16 vec_b[3];
    s16 delta[3];
    s16 mtx[16];
    s32 cross_sign;

    car = g_camera->car;
    if (car == NULL) {
        return;
    }
    car_flags = car->flags;
    if (car_flags & 0x800) {
        if (!(car_flags & 0x400)) {
            if (car->info->unk20 == 0) {
                car->flags = car_flags | 0x400;
                cam->mode = gRecordTier[*(gRecords + car->info->unk0 + 0x32)];
                if (cam->mode >= 5) {
                    cam->mode = 2;
                }
            }
        }
    }
    if (cam->unk6C->unk8 == 1) {
        car->flags |= 0x800;
    }
    tbl = &D_8009BEE0;
    entry = *tbl; entry += cam->mode;
    #ifdef PORT
        /* XOR round trip on the pointer is a no-op on the PC */
#else
        tbl=(CamEntry**)((u32)tbl^(u32)cam); tbl=(CamEntry**)((u32)tbl^(u32)cam);
#endif
    cam_data = &g_camera->cd;
    if (g_camera->flags & 0x100) {
        if (!(g_camera->flags & 0x200)) {
            cam->unk34 = cam->mode;
            g_camera->flags |= 0x200;
        }
        g_camera->flags &= 0xFF77;
        if (cam->mode == 0) {
            advanceStreamFrame(cam, car);
            goto again;
        } else if (cam->mode == 1) {
        again:
            advanceStreamFrame(cam, car);
        }
        if (car->state->unk39C == 4) {
            if (g_camera->flags & 0x200) {
                g_camera->flags &= 0xFEFF;
                cam->mode = cam->unk34;
                g_camera->flags &= 0xFDFF;
            }
        }
    } else if (car->obj->m[4] < 0 && (*(u32 *)&g_camera->flags & 0x880000)) {
        g_camera->flags |= 0x100;
    }

    switch (cam->mode) {
    case 0:
        g_camera->flags |= 8;
        cam_data->E0 = car->obj->x;
        cam_data->E4 = car->obj->y - 50;
        cam_data->E8 = car->obj->z;
        if (g_camera->flags & 0x40) {
            cam_data->EC = cam_data->E0 - car->obj->m[2];
            cam_data->F0 = cam_data->E4 + car->obj->m[5];
            cam_data->F4 = cam_data->E8 - car->obj->m[8];
        } else {
            cam_data->EC = cam_data->E0 + car->obj->m[2];
            cam_data->F0 = cam_data->E4 + car->obj->m[5];
            cam_data->F4 = cam_data->E8 + car->obj->m[8];
        }
        for (i = 0; i < 2; i++) {
            cam->v[i].x = 0;
            cam->v[i].y = 0;
            cam->v[i].z = 0;
        }
        if (g_camera->flags & 0x40) {
            delta[0] = cam_data->EC - cam_data->E0;
            delta[2] = cam_data->F4 - cam_data->E8;
            heading = -angle_atan2_thunk(delta[2], delta[0]);
            cam->unk50 = cam->unk54 = heading;
        } else {
            heading = func_8001FD14(car);
            cam->unk50 = cam->unk54 = heading;
        }
        vec_a[0] = 0x1000;
        vec_a[1] = 0;
        vec_a[2] = 0;
        mtx3_transform_vec3(car->obj->m, vec_a, vec_b);
        yaw = angle_atan2_thunk(vec_b[2], vec_b[0]);
        vec_a[0] = 0;
        vec_a[1] = yaw;
        vec_a[2] = 0;
        mat3x3_from_euler(vec_a, mtx);
        mtx3_transform_vec3(mtx, vec_b, vec_a);
        yaw = angle_atan2_thunk(vec_a[1], vec_a[0]);
        pack0[0] = car->obj->m[2];
        pack0[1] = car->obj->m[8];
        pack1[0] = 0;
        pack1[1] = 0;
        pack2[0] = car->obj->m[0];
        pack2[1] = car->obj->m[6];
        func_8002D75C(*(s32 *)pack0, *(s32 *)pack1, *(s32 *)pack2, &cross_sign);
        if (cross_sign < 0) {
            cam_data->D0 = 0x800 - (s16)yaw;
        } else {
            cam_data->D0 = (s16)yaw;
        }
        cam_data->F8 = car->obj->m[1];
        cam_data->FC = car->obj->m[4];
        cam_data->F100 = car->obj->m[7];
        if (g_camera->flags & 0x40) {
            cam_data->D0 = -cam_data->D0;
        }
        break;
    case 1:
        g_camera->flags |= 0x88;
        if (*(u16 *)(gRecords + 0x1E) == 7) {
            info_idx = 0;
        } else {
            info_idx = car->info->unk0;
        }
        cam_data->E0 = car->obj->x + D_8009CE8C[info_idx].x;
        if (g_camera->flags & 0x40) {
            cam_data->E4 = car->obj->y + D_8009CE8C[info_idx].y - 40;
        } else {
            cam_data->E4 = car->obj->y + D_8009CE8C[info_idx].y;
        }
        cam_data->E8 = car->obj->z + D_8009CE8C[info_idx].z;
        if (g_camera->flags & 0x40) {
            cam_data->EC = cam_data->E0 - car->obj->m[2];
            cam_data->F0 = cam_data->E4 + car->obj->m[5];
            cam_data->F4 = cam_data->E8 - car->obj->m[8];
        } else {
            cam_data->EC = cam_data->E0 + car->obj->m[2];
            cam_data->F0 = cam_data->E4 + car->obj->m[5];
            cam_data->F4 = cam_data->E8 + car->obj->m[8];
        }
        for (i = 0; i < 2; i++) {
            cam->v[i].x = 0;
            cam->v[i].y = 0;
            cam->v[i].z = 0;
        }
        if (g_camera->flags & 0x40) {
            delta[0] = cam_data->EC - cam_data->E0;
            delta[2] = cam_data->F4 - cam_data->E8;
            heading = -angle_atan2_thunk(delta[2], delta[0]);
            cam->unk50 = cam->unk54 = heading;
        } else {
            heading = func_8001FD14(car);
            cam->unk50 = cam->unk54 = heading;
        }
        vec_a[0] = 0x1000;
        vec_a[1] = 0;
        vec_a[2] = 0;
        mtx3_transform_vec3(car->obj->m, vec_a, vec_b);
        yaw = angle_atan2_thunk(vec_b[2], vec_b[0]);
        vec_a[0] = 0;
        vec_a[1] = yaw;
        vec_a[2] = 0;
        mat3x3_from_euler(vec_a, mtx);
        mtx3_transform_vec3(mtx, vec_b, vec_a);
        yaw = angle_atan2_thunk(vec_a[1], vec_a[0]);
        pack0[0] = car->obj->m[2];
        pack0[1] = car->obj->m[8];
        pack1[0] = 0;
        pack1[1] = 0;
        pack2[0] = car->obj->m[0];
        pack2[1] = car->obj->m[6];
        func_8002D75C(*(s32 *)pack0, *(s32 *)pack1, *(s32 *)pack2, &cross_sign);
        if (cross_sign < 0) {
            cam_data->D0 = 0x800 - (s16)yaw;
        } else {
            cam_data->D0 = (s16)yaw;
        }
        cam_data->F8 = car->obj->m[1];
        cam_data->FC = car->obj->m[4];
        cam_data->F100 = car->obj->m[7];
        if (g_camera->flags & 0x40) {
            cam_data->D0 = -cam_data->D0;
        }
        g_camera->flags &= 0xFFF7;
        break;
    case 2:
    case 3:
    case 6:
        {
        if (cam->unk68 & 1) { target_yaw = cam->unk60; } else {
            target_yaw = (func_8001FD14(car) + 0x800) + gCamPanOffset * D_800A4030;
        }
        cur_yaw = (cam->unk54 + 0x800) & 0xFFF;
        dd = target_yaw - cur_yaw;
        if (dd < 0) {
            dd = -dd;
        }
        if (dd > 0x800) {
            if (target_yaw < cur_yaw) {
                target_yaw += 0x1000;
            } else {
                cur_yaw += 0x1000;
            }
        }

        cur_yaw = lerp_q7(cur_yaw, target_yaw, cam->unk20) - 0x800;
        if (cam->mode >= 2) {
            cam->unk20 = lerp_q7(cam->unk20, cam->unk10, cam->unk18);
            cam->unk24 = lerp_q7(cam->unk24, cam->unk14, cam->unk18);
        }
        cam->unk54 = cur_yaw;
        if ((g_camera->flags & 0x40) || (cam->unk68 & 2)) {
            cam->unk54 = (target_yaw + 0x800) & 0xFFF;
            if (g_camera->flags & 0x40) {
                entry += 5;
            }
        }
        setObjectTransform(cam->unk54, entry->unkE, entry->unk16, pos_out, cam->unk6A);
        cam->v[1].x = pos_out[0];
        cam->v[1].y = entry->unk10;
        cam->v[1].z = pos_out[2];
        if ((g_camera->flags & 0x40) || (cam->unk68 & 2)) {
            cam->v[0] = cam->v[1];
        }
        cam->v[0].x = lerp_q7(cam->v[0].x, cam->v[1].x, cam->unk24);
        cam->v[0].y = lerp_q7(cam->v[0].y, cam->v[1].y, cam->unk24);
        cam->v[0].z = lerp_q7(cam->v[0].z, cam->v[1].z, cam->unk24);
        cam_data->E0 = cam->v[0].x;
        cam_data->E4 = cam->v[0].y;
        cam_data->E8 = cam->v[0].z;
        setObjectTransform(cam->unk54, entry->unk1A, entry->unk22, pos_out, cam->unk6A);
        cam_data->EC = pos_out[0];
        cam_data->F0 = entry->unk1C;
        cam_data->F4 = pos_out[2];
        cam_data->E0 += car->obj->x;
        cam_data->E4 += car->obj->y;
        cam_data->E8 += car->obj->z;
        cam_data->EC += car->obj->x;
        cam_data->F0 += car->obj->y;
        cam_data->F4 += car->obj->z;
        cam_data->F8 = 0.0f;
        cam_data->FC = 1.0f;
        cam_data->F100 = 0.0f;
        cam_data->DC = 1.0f;
        cam_data->D0 = 0.0f;
        g_camera->flags &= 0xFF77;
        cam->unk68 &= 0xFFFD;
        }
        break;
    case 4:
        D_8009BA38 = (D_8009BA38 + 20) & 0xFFF;
        g_camera->flags &= 0xFF77;
        off_x = sin_q12(D_8009BA38) * 3048 / 32768;
        off_z = cos_q12(D_8009BA38) * 3048 / 32768;
        cam_data->EC = car->obj->x;
        cam_data->F0 = car->obj->y;
        cam_data->F4 = car->obj->z;
        cam_data->E0 = cam_data->EC + off_x;
        cam_data->E4 = cam_data->F0 - 100.0f;
        cam_data->E8 = cam_data->F4 + off_z;
        cam_data->F8 = 0.0f;
        cam_data->FC = 1.0f;
        cam_data->F100 = 0.0f;
        cam_data->DC = 1.0f;
        break;
    case 5:
        entry = *tbl;
        target_yaw = (func_8001FD14(car) + 0x800) + gCamPanOffset * D_800A4038;
        entry += 4;
        cur_yaw = (cam->unk54 + 0x800) & 0xFFF;
        dd = target_yaw - cur_yaw;
        if (dd < 0) {
            dd = -dd;
        }
        if (dd > 0x800) {
            if (target_yaw < cur_yaw) {
                target_yaw += 0x1000;
            } else {
                cur_yaw += 0x1000;
            }
        }
        off_x = lerp_q7(cur_yaw, target_yaw, cam->unk20) - 0x800;
        if (cam->mode >= 2) {
            cam->unk20 = lerp_q7(cam->unk20, cam->unk10, cam->unk18);
            cam->unk24 = lerp_q7(cam->unk24, cam->unk14, cam->unk18);
        }
        cam->unk54 = off_x;
        setObjectTransform(cam->unk54, entry->unkE, entry->unk16, pos_out, cam->unk6A);
        cam->v[1].x = pos_out[0];
        cam->v[1].y = entry->unk10;
        cam->v[1].z = pos_out[2];
        cam->v[0].x = lerp_q7(cam->v[1].x, cam->v[1].x, cam->unk24);
        cam->v[0].y = lerp_q7(cam->v[1].y, cam->v[1].y, cam->unk24);
        cam->v[0].z = lerp_q7(cam->v[1].z, cam->v[1].z, cam->unk24);
        cam_data->E0 = cam->v[0].x;
        cam_data->E4 = cam->v[0].y;
        cam_data->E8 = cam->v[0].z;
        setObjectTransform(cam->unk54, entry->unk1A, entry->unk22, pos_out, cam->unk6A);
        cam_data->EC = pos_out[0];
        cam_data->F0 = entry->unk1C;
        cam_data->F4 = pos_out[2];
        cam_data->E0 += car->obj->x;
        cam_data->E4 += car->obj->y;
        cam_data->E8 += car->obj->z;
        cam_data->EC += car->obj->x;
        cam_data->F0 += car->obj->y;
        cam_data->F4 += car->obj->z;
        cam_data->F8 = 0.0f;
        cam_data->FC = 1.0f;
        cam_data->F100 = 0.0f;
        cam_data->D0 = 0.0f;
        g_camera->flags &= 0xFF77;
        cam->unk68 &= 0xFFFD;
        break;
    }
    if (D_8009BA30 == 0) {
        updatePlayerPauseInput(cam, car);
    }
}
