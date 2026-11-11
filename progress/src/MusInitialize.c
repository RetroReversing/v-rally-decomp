typedef struct {
    s32 control_flag;
    s32 channels;
    s32 thread_priority;
    u8 *heap;
    s32 heap_length;
    s32 ptr;
    s32 wbk;
    s32 default_fxbank;
    s32 fifo_length;
    s32 syn_updates;
    s32 syn_output_rate;
    s32 syn_rsp_cmds;
    s32 syn_retraceCount;
    s32 syn_num_dma_bufs;
    s32 syn_dma_buf_size;
    u8 fxtype;
    u8 rate;
} MusConfig;

typedef struct { s16 priority; s16 fxBus; u8 unityPitch; } VoiceConfig;
typedef struct {
    s32 maxVVoices;
    s32 maxPVoices;
    s32 maxUpdates;
    s32 maxFXbusses;
    void *dmaproc;
    void *heap;
    s32 outputRate;
    u8 fxType;
    s32 *params;
} SynConfig;
typedef struct { s32 a; s32 b; s32 c; } SB;
typedef struct { u8 *base; u8 *cur; s32 len; s32 count; } Heap;
typedef struct { void *next; void *clientData; void *handler; } Player;
typedef struct { u8 pad[0xC1]; u8 playing; u8 pad2[0x134 - 0xC2]; } Chan;
typedef struct { u8 pad[0x1C]; } Voice;

extern s32 D_800C3648;
extern s32 gVoiceCount;
extern s32 D_800B6160;
extern s32 gDmaThreadStack;
extern s32 D_800B68EC;
extern s32 D_800B5C70;
extern Voice *D_800C7824;
extern Chan *gVoices;
extern u8 D_800C3580;
extern s32 D_800C34D4;
extern s32 D_800A9934;
extern s32 D_800B0100;
extern s32 gRandomState;
extern Player D_800B4130;
extern Heap D_800C3538;
extern char D_800B0B54[];
extern s32 D_800C80C0;
extern s32 D_800A1B90;
void MusSetMasterVolume(s32, s32);
void *alHeapDBAlloc(s32, s32, void *, s32, s32);
void alHeapInit(void *, void *, s32);
void alSynAddPlayer(void *, void *);
s32 alSynAllocVoice(void *, void *, VoiceConfig *);
void audio_driver_setup(SynConfig *, s32, SB *, s32, s32, s32);
void voice_reset(Chan *);
void func_800896DC(void *, s32, s32);
void ptrbank_relocate(s32, s32);
void func_800864C0(void);
void update_voices(void);

/* Initialises the music driver from config: sets up the heap, the voice and
 * channel pools, the synth (audio_driver_setup) and the master volume, adds the
 * sequencer player, allocates a voice for each channel, and registers the
 * per-frame callback func_800864C0. Returns the heap bytes used. */
s32 MusInitialize(MusConfig *config)
{
    VoiceConfig voiceCfg;
    SynConfig synCfg;
    SB synBuf;
    s32 i;

    D_800C3648 = config->control_flag;
    gVoiceCount = config->channels;
    D_800B6160 = config->default_fxbank;
    gDmaThreadStack = config->fifo_length;
    D_800B68EC = config->rate;
    D_800B5C70 = 1000000 / D_800B68EC;

    func_800896DC(config->heap, 0, config->heap_length);
    alHeapInit(&D_800C3538, config->heap, config->heap_length);
    D_800C7824 = alHeapDBAlloc(0, 0, &D_800C3538, 1, gVoiceCount * sizeof(Voice));
    gVoices = alHeapDBAlloc(0, 0, &D_800C3538, 1, gVoiceCount * sizeof(Chan));
    func_800896DC(D_800C7824, 0, gVoiceCount * sizeof(Voice));
    func_800896DC(gVoices, 0, gVoiceCount * sizeof(Chan));

    D_800C3580 = config->fxtype;
    ptrbank_relocate(config->ptr, config->wbk);
    D_800A9934 = D_800C34D4 = config->ptr;

    synCfg.maxPVoices = synCfg.maxVVoices = gVoiceCount;
    synCfg.maxUpdates = config->syn_updates;
    synCfg.dmaproc = 0;
    synCfg.fxType = 2;
    synCfg.outputRate = 0;
    synCfg.heap = &D_800C3538;
    synBuf.a = config->syn_output_rate;
    synBuf.b = config->syn_retraceCount;
    synBuf.c = config->syn_rsp_cmds;
    audio_driver_setup(&synCfg, config->thread_priority, &synBuf, config->syn_num_dma_bufs, config->syn_dma_buf_size, D_800B68EC);
    MusSetMasterVolume(3, 0x7FFF);

    D_800B0100 = 1;
    gRandomState = 0x12345678;
    D_800B4130.next = 0;
    D_800B4130.handler = update_voices;
    D_800B4130.clientData = &D_800B4130;
    alSynAddPlayer(D_800B0B54, &D_800B4130);

    for (i = 0; i < gVoiceCount; i++) {
        gVoices[i].playing = 0;
        voice_reset(&gVoices[i]);
        voiceCfg.unityPitch = 0;
        voiceCfg.priority = config->thread_priority;
        voiceCfg.fxBus = 0;
        alSynAllocVoice(D_800B0B54, &D_800C7824[i], &voiceCfg);
    }
    D_800A1B90 = D_800C80C0;
    D_800C80C0 = (s32)func_800864C0;
    return D_800C3538.cur - D_800C3538.base;
}
