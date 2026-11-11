/* Layouts used by alSynStartVoice (audio synth, libaudio). */
#define AL_EVT_START_VOICE 0xE
#define AL_EVT_TYPE_ADD    3

typedef struct AlEvent { struct AlEvent *next; s32 time; s16 type; s16 vel; s32 param; } AlEvent;
typedef s32 (*AlHandler)(void *self, s32 type, AlEvent *evt);
typedef struct AlOwner { u8 pad00[8]; AlHandler handler; } AlOwner;
typedef struct AlUnit { u8 pad00[0xC]; AlOwner *owner; u8 pad10[0xC8]; s32 timeOffset; } AlUnit;
typedef struct AlVoice { u8 pad00[8]; AlUnit *unit; u8 pad0C[0xE]; s16 vel; } AlVoice;
typedef struct AlSynth { u8 pad00[0x1C]; s32 now; } AlSynth;

void *__allocParam();

/* Queues a start event for a voice on the synth. The event is stamped with the
 * current synth time plus the unit's time offset and handed to the unit's owner. */
void alSynStartVoice(AlSynth *synth, AlVoice *voice, s32 param) {
    AlEvent *evt;
    AlOwner *owner;
    s32 time;

    if (voice->unit != NULL) {
        evt = __allocParam();
        if (evt != NULL) {
            time = synth->now + voice->unit->timeOffset;
            evt->type = AL_EVT_START_VOICE;
            evt->param = param;
            evt->next = NULL;
            evt->time = time;
            evt->vel = voice->vel;
            owner = voice->unit->owner;
            owner->handler(owner, AL_EVT_TYPE_ADD, evt);
        }
    }
}
