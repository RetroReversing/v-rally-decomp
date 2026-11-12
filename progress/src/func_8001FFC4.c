typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

/* Track data: the grid of points (points), the grid origin and the grid's row width (rowWidth). */
typedef struct Track {
    u8 pad0[0x24];
    s32 originX;
    s32 originY;
    s32 originZ;
    u8 pad30[0x4C - 0x30];
    s32 baseIndex;
    u8 pad50[0x54 - 0x50];
    Vec3s *points;
    u8 pad58[0x88 - 0x58];
    u16 unk88;
    u16 rowWidth;
} Track;

void angle_atan2_thunk(s32, s32);

#ifdef PORT
#define VEC_AT(p, o) ((Vec3s *)((u8 *)(p) + (o)))
#else
#define VEC_AT(p, o) ((Vec3s *)((o) + (int)(p)))
#endif

/* Writes the world position of the grid point at (row arg3, column arg2) to out, then steps
 * to the next row and passes the x/z offset between the two points to angle_atan2_thunk. */
void func_8001FFC4(s32 *out, Track *track, s32 col, s32 row) {
    s32 i;
    s32 off;
    s32 t;
    s32 x;
    Vec3s *base;
    Vec3s *w;

    i = (s16)row;
    i *= track->rowWidth; t = (s16)col;
    i += track->baseIndex; i += t;
    x = track->originX;
    base = track->points;
    off = i * 6;
    out[0] = VEC_AT(base, off)->x + x;
    out[1] = VEC_AT(track->points, off)->y + track->originY;
    out[2] = VEC_AT(track->points, off)->z + track->originZ;
    i += track->rowWidth;
    w = VEC_AT(track->points, i * 6);
    angle_atan2_thunk(w->x - VEC_AT(track->points, off)->x, w->z - VEC_AT(track->points, off)->z);
}
