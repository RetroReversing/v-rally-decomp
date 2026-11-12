s32 osCreateThread();
s32 func_8008BB80();
s32 osStartThread();
extern char gGameState[];
extern char gOrderState[];
extern s32 func_8007FF9C;

/* Boot-time start-up: runs the hardware setup in func_8008BB80, then creates
 * and starts the boot thread (priority 1, entry func_8007FF9C, stack in
 * gOrderState at +0x7D50). The thread control block is at gGameState+0x38. */
void boot_start(void)
{
    void *boot_thread;

    func_8008BB80();
    boot_thread = gGameState + 0x38;
    osCreateThread(boot_thread, 1, &func_8007FF9C, 0, gOrderState + 0x7D50, 1);
    osStartThread(boot_thread);
}
