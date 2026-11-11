static __inline__ s32 __repair_inline(s32 a) { return a; }
typedef struct { s32 x, y, z, w; } V4;
typedef struct { s16 x, y, z; } P3;
typedef struct {
    u8 pad0[0x24];
    s32 x;
    s32 y;
    s32 z;
    u8 pad30[0x4C - 0x30];
    s32 base;
    u8 pad50[4];
    P3 *pts;
    u8 pad58[0x8A - 0x58];
    u16 n;
} Track;
extern void vec3_square(V4 *, V4 *);

/* Works out how far a car has moved along the track segment it is on, as a
   percentage (0-100ish) between the points either side of it. Writes the result
   to the car's progress field at +0x17C of the object pointed to by car+0x60. */
void func_8002B7D4(u8 *car)
{
    V4 pos;
    V4 dir;
    V4 rel;
    Track *track;
    u8 *pos_src;
    s32 seg;
    s32 next_seg;
    s32 prev_seg;
    s32 dot;
    s32 len_sq;

    track = **(Track ***)(car + 0x8C);
    pos_src = *(u8 **)(car + 0x58);
    seg = __repair_inline(**(s32 **)(car + 0x60));
    seg = seg * track->n + track->base;
    pos.x = *(s32 *)(pos_src + 0xC);
    pos.z = *(s32 *)(*(u8 **)(car + 0x58) + 0x14);
    pos.x -= track->x;
    pos.z -= track->z;
    prev_seg = seg - 2;
    next_seg = seg + 2;
    dir.x = track->pts[next_seg].x - track->pts[prev_seg].x;
    dir.z = track->pts[next_seg].z - track->pts[prev_seg].z;
    rel.x = pos.x - track->pts[prev_seg].x;
    rel.z = pos.z - track->pts[prev_seg].z;
    dot = dir.x * rel.x + dir.z * rel.z;
    vec3_square(&dir, &dir);
    len_sq = dir.x + dir.z;
    dot = dot * 100 / len_sq;
    *(s32 *)(*(u8 **)(car + 0x60) + 0x17C) = dot;
}
