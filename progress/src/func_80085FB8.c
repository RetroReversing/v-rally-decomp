s32 func_80084DD4();
s32 cont_port_is_connected(s32, s32);
s32 __osMotorAccess();
s32 osMotorInit();
extern s32 gContCtx;
extern s32 (*D_800A1B80)();
extern char gOrderState[];

/* For each of the four controller channels that has a pak of type 2 (rumble),
 * initialise its motor pack and send the stop command three times. */
void func_80085FB8(void)
{
    s32 channel;
    s32 pfs_off;
    void *queue;

    channel = 0;
    queue = gOrderState + 0x5A38;
    (*D_800A1B80)();
    pfs_off = 0x18C;
    do
    {
        if ((func_80084DD4(channel) != 0) && (cont_port_is_connected(channel, 2) != 0))
        {
            osMotorInit(queue, gContCtx + pfs_off, channel);
            __osMotorAccess(gContCtx + pfs_off, 0);
            osMotorInit(queue, gContCtx + pfs_off, channel);
            __osMotorAccess(gContCtx + pfs_off, 0);
            osMotorInit(queue, gContCtx + pfs_off, channel);
            __osMotorAccess(gContCtx + pfs_off, 0);
        }
        channel += 1;
        pfs_off += 0x68;
    }
    while (channel < 4);
}
