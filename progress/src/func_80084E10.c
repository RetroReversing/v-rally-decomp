extern char *gContCtx;

unsigned char func_80084E10(void)
{
    u8 cnt;
    s32 i;

    cnt = 0;
    i = 0;
    do {
        if ((gContCtx[i * 4 + 0xF] & 8) == 0) {
            cnt++;
        }
        i++;
    } while (i < 4);
    return cnt;
}
