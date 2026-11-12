/* port (WebAssembly build): its callback is the function func_8000A840, not data at its address. */
#include "common.h"
void func_8000A840(void *, s32, s32, u8 *, s32, u8 *);
void *poolAllocListNode(void *, s32);
typedef void (*SpriteHook)(void *);
typedef struct { u8 r; u8 g; u8 b; u8 a; } Color4;

/* Allocates a 0xB0-byte sprite under parent and sets its defaults: active, position
 * (x, y), layer, unit scale (0x400), a half-alpha white tint and the per-frame hook. */
void *sprite_create(void *parent, s16 x, s16 y, s32 layerFlags, SpriteHook hook, s32 unused_mode) {
    s16 layer = layerFlags;
    Color4 tint;
    u8 *sprite;

    sprite = poolAllocListNode(parent, 0xB0);
    tint.r = 0xFF;
    tint.g = 0xFF;
    tint.b = 0xFF;
    tint.a = 0x80;
    *(s32 *)(sprite + 0x80) = 1;
    *(s16 *)(sprite + 0x7E) = -1;
    *(s16 *)(sprite + 0x7C) = -1;
    *(s16 *)(sprite + 0x7A) = 0;
    *(s16 *)(sprite + 0x74) = layer;
    *(s16 *)(sprite + 0xC) = x;
    *(s16 *)(sprite + 0xE) = y;
    *(s32 *)(sprite + 0x8C) = 0;
    *(s16 *)(sprite + 0x78) = 0;
    *(s16 *)(sprite + 0x70) = 0;
    *(s16 *)(sprite + 0x72) = 0;
    *(s16 *)(sprite + 0x98) = 0x400;
    *(s16 *)(sprite + 0x9A) = 0x400;
    *(SpriteHook *)(sprite + 0x84) = hook;
    *(Color4 *)(sprite + 0x90) = tint;
    *(s32 *)(sprite + 0xA0) = 1;
    *(u32 **)(sprite + 0x88) = (u32 *)func_8000A840;
    return sprite;
}
