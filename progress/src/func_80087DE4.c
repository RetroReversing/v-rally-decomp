typedef struct Trk {
    u8 pad00[0x30];
    s32 x30;
    s32 x34;
    u8 pad38[0x6C - 0x38];
    f32 f6C;
    u8 pad70[0x78 - 0x70];
    s32 x78;
    u8 pad7C[4];
    s32 x80;
    s32 x84;
    u8 pad88[0x9A - 0x88];
    u16 h9A;
    u16 h9C;
    u8 pad9E[0xB4 - 0x9E];
    u8 bB4;
    u8 padB5[0xD3 - 0xB5];
    u8 depth;
    u8 *ret[5];
    s32 e8[5];
    s32 fc[5];
    u16 h110[5];
    u16 h11A[5];
    u8 b124[5];
    u8 b129[5];
    u8 b12E[5];
} Trk;

/* Pushes the current track state onto the track's save stack (one slot per
 * depth level), then returns the read position advanced by one byte. */
u8 *func_80087DE4(Trk *track, u8 *pos)
{
    s32 level = track->depth;

    track->b124[level] = *pos++;
    track->ret[level] = pos;
    track->e8[level] = track->x34;
    track->fc[level] = track->x30;
    track->b129[level] = track->bB4;
    track->b12E[level] = track->f6C;
    track->h110[level] = track->h9A;
    track->h11A[level] = track->h9C;
    track->depth++;
    return pos;
}
