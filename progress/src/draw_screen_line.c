s32 obj_get_owner(s32);
void draw_screen_pixel(s32,s32,s32,s32);
extern s32 gSceneSlot1;

/* Draws a line from (x0,y0) to (x1,y1) with Bresenham's algorithm, one pixel at a
 * time through draw_screen_pixel. The color comes from obj_get_owner(gSceneSlot1). The
 * endpoints are swapped so the loop always steps along the major axis. */
void draw_screen_line(s32 x0, s32 y0, s32 x1, s32 y1)
{
    s32 pattern = 0xFFC1FFC1;
    s32 color;
    s32 dx;
    s32 dy;
    s32 err;
    s32 errStepB;
    s32 errStepA;
    s32 stepDir;
    s32 t;
    s32 temp;

    temp = obj_get_owner(gSceneSlot1);
    dx = x1 - x0;
    dy = y1 - y0;
    dx = __builtin_abs(dx);
    if (dy < 0) dy = -dy;
    color = temp;
    if (dx >= dy) {
        if (x1 < x0) { t = x1; x1 = x0; x0 = t; t = y1; y1 = y0; y0 = t; }
        stepDir = y0 >= y1 ? -1 : 1;
        err = dy * 2 - dx;
        errStepA = dy * 2;
        errStepB = (dy - dx) * 2;
        draw_screen_pixel(x0, y0, 0xFFC1FFC1, color);
        x0++;
        while (x1 >= x0) {
            if (err < 0) err += errStepA;
            else { err += errStepB; y0 += stepDir; }
            draw_screen_pixel(x0, y0, pattern, color);
            x0++;
        }
    } else {
        if (y1 < y0) { t = x1; x1 = x0; x0 = t; t = y1; y1 = y0; y0 = t; }
        stepDir = x0 >= x1 ? -1 : 1;
        err = dx * 2 - dy;
        errStepA = dx * 2;
        errStepB = (dx - dy) * 2;
        draw_screen_pixel(x0, y0, 0xFFC1FFC1, color);
        y0++;
        while (y1 >= y0) {
            if (err < 0) err += errStepA;
            else { err += errStepB; x0 += stepDir; }
            draw_screen_pixel(x0, y0, pattern, color);
            y0++;
        }
    }
}
