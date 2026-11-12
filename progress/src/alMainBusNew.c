s32 alFilterNew(void *a0, void *fn2, void *fn3, s32 n4);
extern void *alMainBusPull;
extern void *func_80094580;

/* Initialises a main bus: registers the pull and cleanup handlers with the base
 * object (type 7), then stores the bus's two parameters at +0x18 and +0x1C. */
void alMainBusNew(void *bus, s32 param1, s32 param2) {
    alFilterNew(bus, &alMainBusPull, &func_80094580, 7);
    *(s32 *)((s8 *)bus + 0x14) = 0;
    *(s32 *)((s8 *)bus + 0x18) = param2;
    *(s32 *)((s8 *)bus + 0x1C) = param1;
}
