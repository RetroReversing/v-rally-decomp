s32 alFilterNew(void *a0, void *fn2, void *fn3, s32 n4);
extern void *alAuxBusPull;
extern void *func_800915CC;

/* Initialises an aux bus: registers the pull and cleanup handlers with the base
 * object (type 6), then stores the bus's two parameters at +0x18 and +0x1C. */
void alAuxBusNew(void *bus, s32 param1, s32 param2) {
    alFilterNew(bus, &alAuxBusPull, &func_800915CC, 6);
    *(s32 *)((s8 *)bus + 0x14) = 0;
    *(s32 *)((s8 *)bus + 0x18) = param2;
    *(s32 *)((s8 *)bus + 0x1C) = param1;
}
