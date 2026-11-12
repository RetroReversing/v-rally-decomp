typedef struct {
    u8 pad[0x10];
    s32 unk10;
} WaveInfo;

typedef struct {
    u8 pad[0x28];
    f32 *pitch;
    void **wave;
} InstInfo;

typedef struct Chan {
    u8 *pdata;          /* 0x00 */
    void *wave;         /* 0x04 */
    s32 unk08;          /* 0x08 */
    u8 pad0C[0x28 - 0x0C];
    f32 pitch;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    s32 time;           /* 0x38 */
    s32 last_time;      /* 0x3C */
    u8 pad40[0x48 - 0x40];
    f32 unk48;          /* 0x48 */
    f32 unk4C;          /* 0x4C */
    s32 unk50;          /* 0x50 */
    u8 pad54[0x70 - 0x54];
    WaveInfo *unk70;    /* 0x70 */
    InstInfo *inst;     /* 0x74 */
    u8 pad78[0x7C - 0x78];
    u8 *drum;           /* 0x7C */
    u8 pad80[0x92 - 0x80];
    u16 length;         /* 0x92 */
    u8 pad94[0x98 - 0x94];
    u16 unk98;          /* 0x98 */
    u8 pad9A[0xA2 - 0x9A];
    u16 unkA2;          /* 0xA2 */
    u16 fixed_length;   /* 0xA4 */
    u16 wave_idx;       /* 0xA6 */
    u8 padA8[0xAF - 0xA8];
    u8 ignore_fixed;    /* 0xAF */
    u8 padB0[0xB3 - 0xB0];
    u8 velocity;        /* 0xB3 */
    u8 padB4;
    u8 unkB5;           /* 0xB5 */
    u8 padB6[0xBB - 0xB6];
    u8 unkBB;
    u8 unkBC;
    u8 unkBD;
    u8 padBE[0xC1 - 0xBE];
    u8 playing;         /* 0xC1 */
    u8 unkC2;
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 padC6;
    u8 unkC7;
    u8 unkC8;
    u8 unkC9;
    u8 vel_on;          /* 0xCA */
    u8 default_vel;     /* 0xCB */
    u8 unkCC;
    u8 padCD;
    u8 unkCE;
    u8 unkCF;
} Chan;

typedef u8 *(*CmdFunc)(Chan *, u8 *);
extern CmdFunc D_800A1BC0[];
extern u8 gOrderState[];
extern u8 stream_state[];
extern u8 *read_rate_params(Chan *, s32);
extern void voice_slot_restart(Chan *, s32);
extern void func_80089298(Chan *);
extern void obj_reset_flags(Chan *);
extern void alSynSetFXMix(void *, void *, s32);
extern void alSynSetVol(void *, void *, s32, s32);
extern void alSynStopVoice(void *, void *);

#define SYNTH ((void *)(gOrderState + 0x2304))
#define VOICE(n) ((void *)(*(u8 **)(stream_state + 0x7576) + (n) * 28))

/* Runs the channel's sequence script up to its next note, then starts that note
   on the voice: pitch, drum/wave mapping, length, velocity and FX mix. A script
   end stops the channel and its voice. */
void func_8008871C(Chan *ch, s32 n)
{
    u8 *p;
    s32 note;
    u8 v;
    u8 mix;
    InstInfo *inst;
    s32 idx;

    p = ch->pdata;
    if (p != NULL) {
    loop:
        v = *p;
        if (v >= 0x80) {
            if (v >= 0xAA) {
                goto end_seq;
            }
            p = D_800A1BC0[v & 0x7F](ch, p + 1);
            if (p != NULL) {
                goto loop;
            }
        }
    }
    ch->pdata = p;
    if (p == NULL) {
        goto stop;
    }
    ch->unk48 = ch->unk4C;
    note = *ch->pdata++;
    if (ch->vel_on) {
        ch->velocity = *ch->pdata++;
    } else {
        ch->velocity = ch->default_vel;
    }
    if (ch->fixed_length) {
        if (ch->ignore_fixed) {
            ch->ignore_fixed = 0;
            v = *ch->pdata++;
            if (v < 0x80) {
                ch->length = v;
            } else {
                ch->length = *ch->pdata++ + ((v & 0x7F) << 8);
            }
        } else {
            ch->length = ch->fixed_length;
        }
    } else {
        v = *ch->pdata++;
        if (v < 0x80) {
            ch->length = v;
        } else {
            ch->length = *ch->pdata++ + ((v & 0x7F) << 8);
        }
    }
    ch->last_time = ch->time;
    ch->time += ch->length << 8;
    ch->unkA2 = 0;
    ch->unkC9 = 0;
    ch->unkC8 = ch->unkC7;
    if (note != 0x60) {
        inst = ch->inst;
        if (ch->drum != NULL) {
            ch->wave_idx = ch->drum[note * 4];
            ch->unkB5 = ch->drum[note * 4 + 2] >> 1;
            read_rate_params(ch, ch->unk70->unk10 + ch->drum[note * 4 + 1] * 7);
            note = ch->drum[note * 4 + 3];
        }
        if (!ch->unkCE) {
            func_80089298(ch);
        }
        if (ch->unkCC) {
            obj_reset_flags(ch);
        }
        idx = ch->wave_idx;
        if (!ch->unkCF) {
            ch->wave = inst->wave[idx];
            if (ch->playing && ch->unk98) {
                ch->unk98 = 0;
                alSynSetVol(SYNTH, VOICE(n), 0, *(s32 *)(gOrderState + 0x7420));
            } else {
                voice_slot_restart(ch, n);
            }
        }
        ch->pitch = (f32)note + inst->pitch[idx];
        mix = ch->unkC2;
        if (mix != ch->unkC4) {
            s32 fx = ch->unkC3;
            s32 val = (0x80 - fx) * mix;
            ch->unkC4 = mix;
            alSynSetFXMix(SYNTH, VOICE(n), (fx + (val >> 7)) & 0xFF);
        }
    } else if (ch->unkBB < 4) {
        ch->unkBB = 4;
        ch->unkBD = 1;
        ch->unk50 = ch->unk08;
        ch->unkC5 = ch->unkBC;
    }
    return;
end_seq:
    ch->pdata = NULL;
    return;
stop:
    if (ch->playing) {
        ch->playing = 0;
        alSynStopVoice(SYNTH, VOICE(n));
    }
}
