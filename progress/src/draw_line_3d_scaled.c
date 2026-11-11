typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

s32 draw_line_3d(s32, Vec3i *, Vec3i *);

/* Draws a line between two points given in world units. The points are
 * scaled down (from is >> 5, to is >> 2) before being passed to draw_line_3d. */
void draw_line_3d_scaled(s32 color, Vec3i *from, Vec3i *to) {
    Vec3i end;
    Vec3i start;

    end = *to;
    end.x >>= 2;
    end.y >>= 2;
    end.z >>= 2;
    start = *from;
    start.x >>= 5;
    start.y >>= 5;
    start.z >>= 5;
    draw_line_3d(color, &start, &end);
}
