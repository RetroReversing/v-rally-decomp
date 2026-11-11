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

void func_8002D2C8(s32, s32);

/* Writes the world position of the grid point at (row arg3, column arg2) to out, then steps
 * to the next row and passes the x/z offset between the two points to func_8002D2C8. */
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
    out[0] = ((Vec3s *)(off + (int)base))->x + x;
    out[1] = ((Vec3s *)(off + (int)track->points))->y + track->originY;
    out[2] = ((Vec3s *)(off + (int)track->points))->z + track->originZ;
    i += track->rowWidth;
    w = (Vec3s *)(i * 6 + (int)track->points);
    func_8002D2C8(w->x - ((Vec3s *)(off + (int)track->points))->x, w->z - ((Vec3s *)(off + (int)track->points))->z);
}
