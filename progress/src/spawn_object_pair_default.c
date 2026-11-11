s32 spawnObjectPair(void *, void *, s32, s32, s32);

/* Spawns an object pair for id, using 0x400 for a zero width and 0x20 for a zero height.
 * Returns the low byte of the spawn result. */
s32 spawn_object_pair_default(s32 id, s32 width, s32 height) {
    s32 w;
    s32 h;

    w = width;
    h = height;
    if (w == 0) {
        w = 0x400;
    }
    if (h == 0) {
        h = 0x20;
    }
    return spawnObjectPair(0, 0, w, h, id & 0xFFFF) & 0xFF;
}
