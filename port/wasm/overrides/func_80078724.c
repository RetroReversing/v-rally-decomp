/* port (WebAssembly build): the graphics context its callees read from $a0 is passed on explicitly; the matched C leaves it in the register. */
#include "common.h"
void func_80078760(s32 ctx);
void results_screen_draw(s32 ctx);
extern char stream_state[];

/* Draws the results panel while the stream state byte at +0x7F4F is 5; otherwise runs the results-screen draw.
 * port: the graphics context arrives in $a0 and both callees read it there; the matched C leaves it implicit. */
void func_80078724(s32 ctx) {
    if (*(u8 *)(stream_state + 0x7F4F) != 5) {
        results_screen_draw(ctx);
        return;
    }
    func_80078760(ctx);
}
