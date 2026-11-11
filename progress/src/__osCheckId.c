s32 __osPfsSelectBank(void *, s32);
s32 __osContRamRead(s32, s32, s32, s32 *);
s32 func_80097620(void *, s32 *, s32);

/* Checks the memory pak ID block: selects bank 0 if needed, reads the ID page
 * (retrying once on a bank error), then compares it with the stored ID.
 * Returns 0 if it matches, 2 if it does not, or the read error code. */
s32 __osCheckId(void *pfs)
{
    s32 idBuf[8];
    s32 err;

    if (*(u8 *)((char *) pfs + 0x65) != 0) {
        err = __osPfsSelectBank(pfs, 0);
        if (err == 2) {
            err = __osPfsSelectBank(pfs, 0);
        }
        if (err != 0) {
            return err;
        }
    }
    err = __osContRamRead(*(s32 *)((char *) pfs + 4), *(s32 *)((char *) pfs + 8), 1, idBuf);
    if (err != 0) {
        if (err != 2) {
            return err;
        }
        err = __osContRamRead(*(s32 *)((char *) pfs + 4), *(s32 *)((char *) pfs + 8), 1, idBuf);
        if (err != 0) {
            return err;
        }
    }
    return (func_80097620((char *) pfs + 0xC, idBuf, 0x20) != 0) * 2;
}
