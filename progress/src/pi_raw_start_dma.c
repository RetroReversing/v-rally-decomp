extern s32 osRomBase;
extern s32 osVirtualToPhysical(void *);

#define PI_DRAM_ADDR_REG (*(vu32 *)0xA4600000)
#define PI_CART_ADDR_REG (*(vu32 *)0xA4600004)
#define PI_RD_LEN_REG    0xA4600008
#define PI_WR_LEN_REG    0xA460000C
#define PI_STATUS_REG    (*(vu32 *)0xA4600010)

/* Starts a raw cartridge DMA on the PI: waits until the PI is idle, sets the
 * RAM address (physical) and the cart address (ROM base | cartAddr, 28 bits),
 * then the length minus one. direction 0 writes to the cart, 1 reads from it;
 * any other value returns -1. */
s32 pi_raw_start_dma(s32 direction, s32 cartAddr, void *ramAddr, s32 length)
{
    vu32 *lenReg;

    while (PI_STATUS_REG & 3) {}
    PI_DRAM_ADDR_REG = osVirtualToPhysical(ramAddr);
    PI_CART_ADDR_REG = (osRomBase | cartAddr) & 0x1fffffff;
    switch (direction) {
    case 0:
        lenReg = (vu32 *)PI_WR_LEN_REG;
        break;
    case 1:
        lenReg = (vu32 *)PI_RD_LEN_REG;
        break;
    default:
        return -1;
    }
    *lenReg = length - 1;
    return 0;
}
