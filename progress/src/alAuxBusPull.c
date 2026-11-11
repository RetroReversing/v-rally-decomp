typedef struct { unsigned int w0; unsigned int w1; } Awords;
typedef union { Awords words; long long int force_union_align; } Acmd;
typedef Acmd *(*ALCmdHandler)(void *, s16 *, s32, s32, Acmd *);

typedef struct ALFilter_s {
    struct ALFilter_s *source;
    ALCmdHandler handler;
    void *setParam;
    s16 inp;
    s16 outp;
    s32 type;
} ALFilter;

typedef struct ALAuxBus_s {
    ALFilter filter;
    s32 sourceCount;
    s32 maxSources;
    ALFilter **sources;
} ALAuxBus;

/* Emits the two DMEM setup commands for an aux bus pull, then appends the
 * command output of each source filter in the bus. */
Acmd *alAuxBusPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    ALAuxBus *bus = (ALAuxBus *)filter;
    ALFilter **sources = bus->sources;
    s32 i;

    {
        Acmd *cmd = (Acmd *)ptr++;
        cmd->words.w0 = (2u << 24) | 1728;
        cmd->words.w1 = (unsigned int)(outCount << 1);
    }
    {
        Acmd *cmd = (Acmd *)ptr++;
        cmd->words.w0 = (2u << 24) | 2048;
        cmd->words.w1 = (unsigned int)(outCount << 1);
    }

    for (i = 0; i < bus->sourceCount; i++) {
        ptr = (sources[i]->handler)(sources[i], outp, outCount, sampleOffset, ptr);
    }

    return ptr;
}
