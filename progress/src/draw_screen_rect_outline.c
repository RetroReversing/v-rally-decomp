s32 draw_screen_line();

/* Draws the outline of the rectangle (left, top)-(right, bottom) in the given colour. */
void draw_screen_rect_outline(s32 left, s32 top, s32 right, s32 bottom, s32 color) {
    draw_screen_line(left, top, left, bottom, color);
    draw_screen_line(left, bottom, right, bottom, color);
    draw_screen_line(right, bottom, right, top, color);
    draw_screen_line(right, top, left, top, color);
}
