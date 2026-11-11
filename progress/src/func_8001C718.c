s32 func_8001B834();
s32 func_8001B854();
s32 resolve_path();
s32 func_80081664();
s32 copyStringAligned();
extern u8 gStreamReady;
extern char D_800A476C[];
extern char gOrderState[];
extern char gStreamState[];

/* Copies the two name strings from the job record (+0x98 into the order state,
   +0xE4 into the stream state). If no stream is ready, opens the stream from +0x4C
   and resolves the path at +0x130 before starting it; otherwise calls func_8001B834. */
void func_8001C718(s32 job)
{
    s32 stream;

    copyStringAligned(gOrderState + 0x23D8, job + 0x98);
    copyStringAligned(gStreamState + 0x5B82, job + 0xE4);
    if (gStreamReady == 0) {
        stream = func_80081664(1, job + 0x4C);
        resolve_path(job + 0x130);
        func_8001B854(stream, D_800A476C);
    } else {
        func_8001B834();
    }
}
