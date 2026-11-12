typedef struct { u16 button; s8 stick_x; s8 stick_y; u8 errno; } OSContPad;
typedef struct { u8 dummy; u8 txsize; u8 rxsize; u8 cmd; u16 button; s8 stick_x; s8 stick_y; } __OSContReadFormat;
typedef struct { u32 ramarray[15]; u32 pifstatus; } OSPifRam;
extern OSPifRam __osContPifRam;
extern u8 __osMaxControllers;

/* Copies the button and stick state of each controller out of the PIF RAM read buffer.
 * Channels whose status nibble reports an error are skipped and keep their old values. */
void osContGetReadData(OSContPad *pad) {
    u8 *ptr = (u8 *)__osContPifRam.ramarray;
    __OSContReadFormat readformat;
    int i;

    for (i = 0; i < __osMaxControllers; i++, ptr += sizeof(__OSContReadFormat), pad++) {
        readformat = *(__OSContReadFormat *)ptr;
        pad->errno = ((readformat.rxsize & 0xC0) >> 4);

        if (pad->errno != 0) {
            continue;
        }

        pad->button = readformat.button;
        pad->stick_x = readformat.stick_x;
        pad->stick_y = readformat.stick_y;
    }
}
