typedef struct Obj53 {
    u8 pad0[0xE];
    u16 e;
    u8 pad10[0xE];
    u16 state;
    u16 prevStep;
    u16 step;
    u8 pad24[6];
    u16 flags;
} Obj53;
extern u8 gOrderState[];
extern u8 stream_state[];
extern Obj53 *gRecords;
extern u8 D_800C365C[];
extern u8 D_800C7FA1;
extern u8 D_800C81FC;
extern u8 D_800C81FD;
extern u8 D_800C81FF;
extern u16 D_800B5B52;
extern void update_records(void);
extern void update_split_deltas(void);
extern void pack_tile_rows(void);
extern void func_8006ECB4(void);
extern void save_race_to_pak(void);
extern void func_80078018(void);

/* Ends the current stage state: stores result m, sets the end-of-stage flags from
 * the record time, moves the record to state 8, and saves its step as prevStep. */
#define FINISH_STAGE(m)                                   \
    q = gRecords;                                 \
    stream_state[0x7F4F] = (m);                       \
    stream_state[0x7F51] = q->e;                      \
    if (stream_state[0x7CF3] < q->e) {                \
        stream_state[0x7F4E] = 1;                     \
    } else {                                        \
        stream_state[0x7F4E] = 0;                     \
    }                                               \
    q = gRecords;                                 \
    old = q->prevStep;                                 \
    *(s32 *)(gOrderState + 0x8030) = 6;              \
    q->state = 8;                                   \
    q->prevStep = 0;                                   \
    q->step = old;

/* Per-frame update of the stage state machine. Each state waits for a set step
 * count, then runs its finish routines, sets its record flag and stage counter,
 * and calls FINISH_STAGE with the result code. */
void func_80053784(void)
{
    Obj53 *p;
    Obj53 *q;
    u16 step;
    u16 old;
    u8 i;
    u8 ok;

    pack_tile_rows();
    save_race_to_pak();
    p = gRecords;
    step = p->step + 1;
    p->step = step;
    switch (p->state) {
    case 1:
        if (step == 4) {
            p->flags |= 0x1000;
            update_records();
            func_80078018();
            update_split_deltas();
            func_8006ECB4();
            save_race_to_pak();
            if (D_800B5B52 == 0) {
                D_800B5B52++;
            }
            FINISH_STAGE(2);
        }
        break;
    case 2:
        if (step == 5) {
            p->flags |= 0x2000;
            update_records();
            func_80078018();
            update_split_deltas();
            func_8006ECB4();
            save_race_to_pak();
            if (D_800B5B52 == 1) {
                D_800B5B52++;
            }
            FINISH_STAGE(3);
        }
        break;
    case 3:
        if (step == 6) {
            update_records();
            ok = 1;
            i = 0;
            do {
                if (D_800C365C[i << 6] != 1) {
                    ok = 0;
                }
                i++;
            } while (i < 3 && ok);
            if (ok) {
                gRecords->flags |= 0x4000;
            }
            if (D_800B5B52 == 2) {
                D_800B5B52++;
            }
            func_80078018();
            update_split_deltas();
            func_8006ECB4();
            save_race_to_pak();
            FINISH_STAGE(4);
        }
        break;
    case 4:
        if (step == 3) {
            update_records();
            func_80078018();
            update_split_deltas();
            func_8006ECB4();
            save_race_to_pak();
            FINISH_STAGE(8);
        }
        break;
    }
}
