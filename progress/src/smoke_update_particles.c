typedef struct {
    s16 x, y, z;
    s16 px, py, pz;
    u8 decay;
    u8 pad[7];
} Particle;

typedef struct {
    f32 x, y, z;
} Pos12;

typedef struct {
    u8 pad0[8];
    s32 count;
    u8 pad1[0xC];
    Pos12 pos[1];
} SmokeTable;

typedef struct {
    u8 pad[0xD8];
    f32 vx;
    f32 pad2;
    f32 vz;
    u8 pad3[0x34];
    f32 x;
    f32 y;
    f32 z;
} Car;

extern s32 func_8002D2C8(s32, s32);
extern void mat3x3_from_euler(s16 *, s32 *);
void *mtx3_transform_vec3(void *, void *, void *);
extern s32 func_80098090(void);
extern SmokeTable *g_ent_list;
extern Car *g_camera;

/* Moves one smoke/dust particle per emitter position. Each particle drifts with
 * the car (the offset from the car to the emitter, clamped if far off) and rises;
 * a particle at the spawn marker (y == 1001) is re-seeded at a random angle
 * around the car's heading. */
void smoke_update_particles(Particle *part, u8 idx)
{
s32 __repair_call_arithmetic;
    s16 vec[4];
    s16 rot[4];
    s32 mtx[8];
    f32 relX, relZ;
    s32 heading;
    s32 left;
    s32 r;

    relX = (s16)(s32)(g_ent_list->pos[idx].x - g_camera->x);
    relZ = (s16)(s32)(g_ent_list->pos[idx].z - g_camera->z);
    if (abs((s32)relX) > 1000 || abs((s32)relZ) > 1000) {
        relX = relZ = 0.0f;
    }
    relX += 4.0f;
    relZ += 2.0f;
    heading = -func_8002D2C8((s32)(g_camera->vz * 4096.0f), (s32)(g_camera->vx * -4096.0f));
    rot[0] = 0;
    rot[2] = 0;
    vec[2] = 0;
    left = g_ent_list->count;
    while (left-- != 0) {
        if (part->y == 1001) {
            vec[0] = func_80098090() % 4095 + 0x200;
            vec[1] = -(func_80098090() % 511);
__repair_call_arithmetic = heading - 0x200;

            rot[1] = __repair_call_arithmetic + func_80098090() % 1023;
            mat3x3_from_euler(rot, mtx);
            mtx3_transform_vec3(mtx, vec, part);
        }
        part->px = part->x;
        part->pz = part->z;
        part->x = part->x + relX;
        part->y += 0x41;
        part->z = part->z + relZ;
        part->py = part->y - part->decay;
        part++;
    }
}
