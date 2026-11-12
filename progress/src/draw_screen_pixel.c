/* Writes color to pixel (x, y) of the 320x240 screen buffer, if it is on screen. */
void draw_screen_pixel(int x, int y, short color, short *screen) {
    unsigned int offset = x + y * 320;
    if (offset <= 0x12BFF) {
        screen[offset] = color;
    }
}
