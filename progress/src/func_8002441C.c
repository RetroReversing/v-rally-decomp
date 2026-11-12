extern void obj_clear_sub_0x74();

/* Resets the per-car state block at obj+0x58 and the two sub-blocks at obj+0x2C, then copies
 * the car's start-position values from obj+0x30 into the block, scaled by 0x10 or 4. */
void func_8002441C(void *arg0) {
    void *state;
    void *state_b;
    void *state_c;
    void *state_d;
    void *state_e;
    void *state_f;

    obj_clear_sub_0x74();
    state = *(void **)((char *)arg0 + 0x58);
    *(s32 *)((char *)state + 0x5C) = 0;
    *(s32 *)((char *)state + 0x60) = 0;
    *(s32 *)((char *)state + 0x64) = 0;
    state_b = *(void **)((char *)arg0 + 0x58);
    *(s32 *)((char *)state_b + 0x70) = 0;
    *(s32 *)((char *)state_b + 0x74) = 0;
    *(s32 *)((char *)state_b + 0x78) = 0;
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xC) = (s32) *(s32 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x54);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0x10) = (s32) *(s32 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x58);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0x14) = (s32) *(s32 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x5C);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xE8) = (s32) (*(s32 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x54) * 0x10);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xEC) = (s32) (*(s32 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x58) * 0x10);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xF0) = (s32) (*(s32 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x5C) * 0x10);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xC0) = (s32) (*(s16 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x40) * 4);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xC4) = (s32) (*(s16 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x46) * 4);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xC8) = (s32) (*(s16 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x4C) * 4);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xD4) = (s32) (*(s16 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x42) * 4);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xD8) = (s32) (*(s16 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x48) * 4);
    *(s32 *)((char *)*(void **)((char *)arg0 + 0x58) + 0xDC) = (s32) (*(s16 *)((char *)*(void **)((char *)arg0 + 0x30) + 0x4E) * 4);
    state_c = *(void **)((char *)arg0 + 0x2C);
    *(s32 *)((char *)state_c + 0x20) = 0;
    *(s32 *)((char *)state_c + 0x24) = 0;
    *(s32 *)((char *)state_c + 0x28) = 0;
    state_d = *(void **)((char *)arg0 + 0x2C);
    *(s32 *)((char *)state_d + 0x34) = 0;
    *(s32 *)((char *)state_d + 0x38) = 0;
    *(s32 *)((char *)state_d + 0x3C) = 0;
    state_e = *(void **)((char *)arg0 + 0x2C);
    *(s32 *)((char *)state_e + 0x98) = 0;
    *(s32 *)((char *)state_e + 0x9C) = 0;
    *(s32 *)((char *)state_e + 0xA0) = 0;
    state_f = *(void **)((char *)arg0 + 0x2C);
    *(s32 *)((char *)state_f + 0xAC) = 0;
    *(s32 *)((char *)state_f + 0xB0) = 0;
    *(s32 *)((char *)state_f + 0xB4) = 0;
}
