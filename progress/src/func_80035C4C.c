typedef struct Part { s16 x; s16 t; s16 z; s16 w; } Part;
typedef struct Ent { f32 x; f32 y; f32 z; } Ent;
typedef struct EntList { char pad0[8]; s32 count; char padC[0x18 - 0xC]; Ent ents[1]; } EntList;
typedef struct Cam { char pad0[0xD8]; f32 dirx; char padDC[4]; f32 dirz; char padE4[0x118 - 0xE4]; f32 x; f32 y; f32 z; } Cam;

extern s32 func_8002D2C8(s32, s32);
extern void func_8002E148(s16 *, s32 *);
void *mtx3_transform_vec3(void *, void *, void *);
extern u64 osGetTime(void);
extern s32 func_80098090(void);
extern void func_800980C4(u32);
extern Cam *D_800C7F84;
extern EntList *D_800C811C;

void func_80035C4C(Part *p, u8 idx) {
    s16 vec[4];
    s16 rot[4];
    s32 mtx[8];
    f32 fdx;
    f32 fdz;
    s32 ang;
    s32 n;
    s32 r;
    Ent *e;
    Cam *cam;

    fdx = (s16)(D_800C811C->ents[idx].x - D_800C7F84->x);
    fdz = (s16)(D_800C811C->ents[idx].z - D_800C7F84->z);
    cam = D_800C7F84;
    if ((fdx > 1000.0f) & (fdz > 1000.0f)) {
        fdx = fdz = 0.0f;
    }
    ang = -func_8002D2C8(cam->dirz * 4096.0f, cam->dirx * -4096.0f);
    rot[0] = 0;
    rot[2] = 0;
    vec[2] = 0;
    n = D_800C811C->count;
    func_800980C4(osGetTime());
    while (n-- != 0) {
        if (p->t == 1001) {
            vec[0] = func_80098090() % 4095 + 0x200;
            vec[1] = -(func_80098090() % 511);
            r = ang - 0x200;
            rot[1] = r + func_80098090() % 1023;
            func_8002E148(rot, mtx);
            mtx3_transform_vec3(mtx, vec, p);
        }
        p->x = p->x + fdx;
        p->t += 20;
        p->z = p->z + fdz;
        p++;
    }
}
