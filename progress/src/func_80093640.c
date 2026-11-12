#define PI_STATUS_REG      (*(volatile u32 *)0xA4600010)
#define PI_DOM1_LAT        (*(volatile u32 *)0xA4600014)
#define PI_DOM1_PWD        (*(volatile u32 *)0xA460001C)
#define PI_DOM1_PGS        (*(volatile u32 *)0xA4600020)
#define PI_DOM1_RLS        (*(volatile u32 *)0xA4600018)
#define PI_DOM2_LAT        (*(volatile u32 *)0xA4600024)
#define PI_DOM2_PWD        (*(volatile u32 *)0xA460002C)
#define PI_DOM2_PGS        (*(volatile u32 *)0xA4600030)
#define PI_DOM2_RLS        (*(volatile u32 *)0xA4600028)

typedef struct { u8 pad0[5]; u8 latency,pulse_width,page_size,release,domain; u8 padA[2]; s32 base_addr; } PiDevCfg;
extern PiDevCfg *gPiCurrentDev[4];
extern volatile u8 D_A0000000[];

/* Starts a PI access on the device described by dev: waits for the PI to go
   idle, reprograms the timing registers that differ from the device last used
   on that domain (domain 0 = DOM1, otherwise DOM2), records dev as current,
   then writes arg2 to base|arg1 in uncached space. */
s32 func_80093640(PiDevCfg *dev, s32 arg1, s32 arg2) {
    s32 domain;
    PiDevCfg *cur;
    while (PI_STATUS_REG & 3) {}
    domain = dev->domain;
    cur = gPiCurrentDev[domain];
    if (cur != dev) {
        if (domain == 0) {
            if (cur->latency != dev->latency) PI_DOM1_LAT = dev->latency;
            if (cur->pulse_width != dev->pulse_width) PI_DOM1_PWD = dev->pulse_width;
            if (cur->page_size != dev->page_size) PI_DOM1_PGS = dev->page_size;
            if (cur->release != dev->release) PI_DOM1_RLS = dev->release;
        } else {
            if (cur->latency != dev->latency) PI_DOM2_LAT = dev->latency;
            if (cur->pulse_width != dev->pulse_width) PI_DOM2_PWD = dev->pulse_width;
            if (cur->page_size != dev->page_size) PI_DOM2_PGS = dev->page_size;
            if (cur->release != dev->release) PI_DOM2_RLS = dev->release;
        }
        gPiCurrentDev[domain] = dev;
    }
#ifdef PORT
    *(volatile u32 *)(unsigned long)(u32)((dev->base_addr | arg1 | 0xA0000000) ) = arg2;
#else
    *(volatile u32 *)((dev->base_addr | arg1 | 0xA0000000) ) = arg2;
#endif
    return 0;
}
