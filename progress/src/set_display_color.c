extern s32 gPadFlags;

/* Copies the four colour bytes of src into obj (+0x90..+0x93) and counts obj's hold
 * timer (+0x94) down unless gPadFlags bit 2 is set. With no timer left, the colour is set to 0xFF. */
void set_display_color(void *obj, void *src) {
    if (*((u8 *)obj + 0x94) != 0) {
        *((u8 *)obj + 0x90) = (u8) *((u8 *)src + 0);
        *((u8 *)obj + 0x91) = (u8) *((u8 *)src + 1);
        *((u8 *)obj + 0x92) = (u8) *((u8 *)src + 2);
        *((u8 *)obj + 0x93) = (u8) *((u8 *)src + 3);
        if (!(gPadFlags & 2)) {
            *((u8 *)obj + 0x94) = (u8) (*((u8 *)obj + 0x94) - 1);
        }
    } else {
        *((u8 *)obj + 0x90) = 0xFFU;
        *((u8 *)obj + 0x91) = 0xFFU;
        *((u8 *)obj + 0x92) = 0xFFU;
        *((u8 *)obj + 0x93) = 0xFFU;
    }
}
