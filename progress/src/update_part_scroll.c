typedef struct Part { s16 x; s16 t; s16 z; s16 w; } Part;
typedef struct Ent { f32 x; f32 y; f32 z; } Ent;
typedef struct EntList { char pad0[8]; s32 count; char padC[0x18 - 0xC]; Ent ents[1]; } EntList;
typedef struct Cam { char pad0[0xD8]; f32 dirx; char padDC[4]; f32 dirz; char padE4[0x118 - 0xE4]; f32 x; f32 y; f32 z; } Cam;

extern s32 func_8002D2C8(s32, s32);
extern void mat3x3_from_euler(s16 *, s32 *);
void *mtx3_transform_vec3(void *, void *, void *);
extern u64 osGetTime(void);
extern s32 func_80098090(void);
extern void func_800980C4(u32);
extern Cam *g_camera;
extern EntList *g_ent_list;

/* Scrolls every track part by the camera-relative offset of entity ent_idx.
 * Parts with t == 1001 are respawned at random positions in front of the camera
 * (position and yaw from the random generator). Every part ages by 20 each call. */
void update_part_scroll(Part *part, u8 ent_idx) {
    s16 pos[4];
    s16 angles[4];
    s32 mtx[8];
    f32 dx;
    f32 dz;
    s32 cam_yaw;
    s32 count;
    s32 base_angle;
    Cam *cam;

    dx = (s16)(g_ent_list->ents[ent_idx].x - g_camera->x);
    dz = (s16)(g_ent_list->ents[ent_idx].z - g_camera->z);
    cam = g_camera;
    if ((dx > 1000.0f) & (dz > 1000.0f)) {
        dx = dz = 0.0f;
    }
    cam_yaw = -func_8002D2C8(cam->dirz * 4096.0f, cam->dirx * -4096.0f);
    angles[0] = 0;
    angles[2] = 0;
    pos[2] = 0;
    count = g_ent_list->count;
    func_800980C4(osGetTime());
    while (count-- != 0) {
        if (part->t == 1001) {
            pos[0] = func_80098090() % 4095 + 0x200;
            pos[1] = -(func_80098090() % 511);
            base_angle = cam_yaw - 0x200;
            angles[1] = base_angle + func_80098090() % 1023;
            mat3x3_from_euler(angles, mtx);
            mtx3_transform_vec3(mtx, pos, part);
        }
        part->x = part->x + dx;
        part->t += 20;
        part->z = part->z + dz;
        part++;
    }
}
