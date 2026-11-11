s32 draw_screen_line();

/* Draws both diagonals of the box with corners (x0,y0) and (x1,y1): the line between them and the line between (x0,y1) and (x1,y0). */
void drawScreenCross(s32 x0, s32 y0, s32 x1, s32 y1, s32 color)
{
  draw_screen_line(x0, y0, x1, y1, color);
  draw_screen_line(x0, y1, x1, y0, color);
}
