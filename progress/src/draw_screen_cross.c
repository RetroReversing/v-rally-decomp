s32 draw_screen_line();

/* Draws a cross through the middle of the box (x0,y0)-(x1,y1): a vertical line at the mid x and a horizontal line at the mid y, both in colour `color`. */
void draw_screen_cross(u32 x0, u32 y0, u32 x1, u32 y1, u32 color) {
    u32 midX;
    u32 midY;

    midX = (x0 + x1) >> 1;
    midY = (y0 + y1) >> 1;
    draw_screen_line(midX, y0, midX, y1, color);
    draw_screen_line(x0, midY, x1, midY, color);
}
