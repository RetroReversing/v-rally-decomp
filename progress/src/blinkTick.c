typedef struct { u8 pad00[0xC6]; u8 onTicks, offTicks, countdown; s8 state; u8 pad_CA[6]; u8 onLevel; } VRBlink;

/* Advances a blink timer: counts down, and on zero flips state, reloading countdown from the on or off period. Returns the state as f32. */
f32 blinkTick(void *arg0) {
    u8 temp_v0;
    VRBlink *blink;

    blink = (VRBlink *)arg0;
    temp_v0 = blink->countdown - 1;
    blink->countdown = temp_v0;
    if (!(temp_v0 & 0xFF)) {
        if (blink->state == 0) {
            blink->state = (s8) blink->onLevel;
            blink->countdown = (u8) blink->onTicks;
        } else {
            blink->state = 0;
            blink->countdown = (u8) blink->offTicks;
        }
    }
    return (f32) blink->state;
}
