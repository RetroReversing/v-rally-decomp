typedef struct RaceRecords {
    u8 pad0[0xE];
    u16 slotCount;
    u8 pad10[0xE];
    u16 mode;
} RaceRecords;

typedef struct CarState {
    u8 pad0[0x20];
    s32 phase;
} CarState;

typedef struct CarNode {
    u8 pad0[4];
    struct CarNode *next;
    u8 pad8[0x40];
    CarState *state;
} CarNode;

extern const int gRaceState;
extern CarNode **gCarList;
extern RaceRecords *gRecords;
extern s32 gPadFlags;
extern char D_800A4DF4[];
extern void *g_camera;

s32 view_gfx_setup();
void *named_entry_lookup(void **, u8 *);
s32 func_8002FE78();
void *find_object_by_id();
s32 func_80042DE0();
s32 func_800528A4();
s32 func_80073708();
s32 results_table_fill();
s32 func_80076E7C();

/* Resets the race at start: sets up the camera and its tables for the current
 * record set, runs the mode-specific setup, then moves every car's state to the
 * start-of-race phase (4 when the race state is 2, otherwise 8). */
void race_reset(void)
{
    s32 temp_v1;
    s32 mode;
    s32 temp_a0;
    RaceRecords *config;
    void *node;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    CarNode *var_v1;
    CarState *temp_a1;

    func_8002FE78();
    temp_a0 = gRecords->slotCount;
    gPadFlags |= 1;
    temp_v0 = find_object_by_id((temp_a0 * 2) | 1);
    g_camera = temp_v0;
    node = *(void **)((char *) named_entry_lookup((void **)((char *) temp_v0 + 0x28), (u8 *) D_800A4DF4) + 0x10);
    config = gRecords;
    *(s32 *)((char *) node + 8) = 1;
    temp_v0_2 = find_object_by_id((config->slotCount * 2) + 2);
    temp_a0 = *(s32 *)((char *) temp_v0_2 + 0x178);
    g_camera = temp_v0_2;
    view_gfx_setup(temp_a0);
    temp_v1 = gRecords->mode;
    switch (temp_v1) {
    case 0: results_table_fill(); break;
    case 1: case 2: case 3: case 4: func_80042DE0(); goto mode_join;
    case 5: func_80042DE0(); func_800528A4();
mode_join: func_80073708(); break;
    }
    temp_v0_3 = find_object_by_id((gRecords->slotCount * 2) + 2);
    g_camera = temp_v0_3;
    func_80076E7C(temp_v0_3);
    var_v1 = *gCarList;
    gPadFlags |= 0xA00;
    if (var_v1 != NULL) {
        mode = gRaceState;
        do {
            temp_a1 = var_v1->state;
            temp_a0 = temp_a1->phase;
            switch (temp_a0) {
            case 6:
                temp_a1->phase = 4;
                break;
            case 10:
                temp_a1->phase = 8;
                break;
            case 7:
                temp_a1->phase = 8;
                break;
            default:
                var_v1->state->phase = 8;
                break;
            }
            if (gRaceState == 2) {
                var_v1->state->phase = 4;
            }
            var_v1 = var_v1->next;
        } while (var_v1 != NULL);
    }
}
