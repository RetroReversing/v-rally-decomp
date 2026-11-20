typedef struct {
    char name[0x90];
    u32 time;
    u8 pad94[0x48];
    s32 rank;
    u8 padE0[0x50];
} VRSplitResult;

typedef struct {
    u8 pad00[0x4C];
    char code[0x90];
    s32 flags;
    u8 padE0[4];
    VRSplitResult split[3];
    char name[0x90];
    s32 category;
    u8 pad508[0x94];
    u32 distance;
} VRRaceResult;

typedef struct {
    volatile u32 time;
    u8 rank;
    u8 pad05;
    char name[4];
    u8 speed;
    u8 flags;
    volatile u8 unused;
    u8 padding[3];
} VRRecord;

typedef struct {
    u8 pad00[0x2C];
    VRRecord split[8][4];
    u32 distance[8];
    char name[8][14];
    u8 category[8];
} VRTrackRecords;

extern char gStreamState[];
extern char gGameState[];
extern char sNameSuffix[];
extern s32 gRecordTimeScale;
extern u8 D_800A16F0;

extern VRRecord D_800C3650[4][4];
extern VRRecord g_split_times[12][4];
extern VRRecord D_800C3A50[1][4];
extern VRRecord D_800C3A90[1][4];
extern VRRecord D_800C3AD0[1][4];
extern VRRecord D_800C3B50[1][4];
extern VRRecord D_800C3B10[1][4];

void strCpy(char *dst, const char *src);
void str_ncat(char *dst, const char *src, s32 length);
s32 str_len(const char *src);

#define RECORD_GROUP ((VRTrackRecords **) (gStreamState + 0x10386))
#define TIME_LOG ((u16 *) (gStreamState + 0x5A8A))
#define GAME_TIMES ((u32 *) (gGameState + 0x6B50))
#define RECORDS(offset) ((VRRecord (*)[4]) (gStreamState + (offset)))
#define SPEED(distance, time) ((u32) ((f32)((distance) * gRecordTimeScale) * 3.6f / (f32)(time)))

#define SPLIT(race, index) (((VRSplitResult *)((u32)((index) * sizeof(VRSplitResult)) + (u32)(race) + 0xE4))[0])

void func_8001E640(VRRaceResult *race) {
    char code[8];
    s8 raw;
    u16 group;
    u16 track;
    u16 slot;
    u16 i;
    u32 offset;
    u8 flags;
    u8 rank;
    VRTrackRecords *records;
    f32 splitTime;
    u32 logTime;
    u16 newIndex;
    u8 logIndex;
    u32 stored;

    group = 0;
    track = 0;
    slot = 0;
    strCpy(code, race->code);
    switch ((s8)(code[0] - 'A')) {
    case 'T' - 'A':
        group = 0;
        raw = code[1];
        track = raw - '0';
        raw = code[2];
        slot = raw - '1';
        break;
    case 'A' - 'A':
        track = 0;
        group = (s8)code[3] - '0';
        slot = (s8)code[6] - '1';
        break;
    case 'W' - 'A':
    case 'X' - 'A':
        slot = (s8)code[2] - '1';
        group = 5;
        if (code[5] == 'D') {
            track = 8 * (code[0] == 'X');
        } else if (code[5] == 'C') {
            track = 1;
        } else if (code[5] == 'T') {
            track = 2;
        } else if (code[5] == 'F') {
            track = 3;
            if (code[0] == 'X') {
                track = 9;
            }
        } else if (code[5] == 'R') {
            track = 4;
        } else if (code[5] == 'L') {
            track = 5;
            if (code[0] == 'X') {
                track = 10;
            }
        } else if (code[5] == 'N') {
            track = 6;
            if (code[0] == 'X') {
                track = 11;
            }
        } else if (code[5] == 'E') {
            track = 7;
        }
        break;
    case 'H' - 'A':
        switch (code[1]) {
        case 'A':
            group = 0;
            track = (s8)code[2] - '1';
            break;
        case 'C':
            group = 4;
            track = (code[2] - '0') * 10 + ((s8)code[3] - '1');
            break;
        case 'T':
            switch (code[2]) {
            case '1':
                group = 16;
                track = 0;
                break;
            case '2':
                group = 17;
                track = 0;
                break;
            case '3':
                group = 18;
                track = 0;
                break;
            case '4':
                group = 19;
                track = 0;
                break;
            }
            break;
        }
        break;
    }
    if (code[0] != 'H') {
        records = &RECORD_GROUP[group][track];
        stored = slot;
        logIndex = D_800A16F0;
        records->distance[slot] = race->distance;
        logTime = race->split[0].time;
        newIndex = logIndex + 1;
        D_800A16F0 = newIndex;
        TIME_LOG[logIndex] = logTime;
        str_ncat(race->name, sNameSuffix, str_len(race->name));
        strCpy(records->name[slot], race->name);
        records->category[slot] = race->category;
        for (i = 0; i < 3; i++) {
            strCpy(records->split[slot][i].name, race->split[i].name);
            records->split[slot][i].time = SPLIT(race, i).time;
            records->split[slot][i].rank = SPLIT(race, i).rank;
            splitTime = records->split[slot][i].time;
            records->split[slot][i].speed = SPEED(records->distance[stored], splitTime);
            records->split[slot][i].flags = race->flags;
            records->split[slot][i].unused = 0;
        }
    } else {
        GAME_TIMES[group + track] = race->split[0].time;
        if (group < 4) {
            for (i = 0; i < 3; i++) {
                strCpy(D_800C3650[track][i].name, race->split[i].name);
                D_800C3650[track][i].time = SPLIT(race, i).time;
                D_800C3650[track][i].rank = SPLIT(race, i).rank;
                splitTime = D_800C3650[track][i].time;
                D_800C3650[track][i].speed = SPEED(race->distance, splitTime);
                flags = *(volatile s32 *)&race->flags;
                D_800C3650[track][i].unused = 0;
                D_800C3650[track][i].flags = flags;
            }
        } else if (group < 16) {
            for (i = 0; i < 3; i++) {
                strCpy(g_split_times[track][i].name, race->split[i].name);
                g_split_times[track][i].time = SPLIT(race, i).time;
                g_split_times[track][i].rank = SPLIT(race, i).rank;
                splitTime = g_split_times[track][i].time;
                g_split_times[track][i].speed = SPEED(race->distance, splitTime);
                flags = *(volatile s32 *)&race->flags;
                g_split_times[track][i].unused = 0;
                g_split_times[track][i].flags = flags;
            }
        } else if (group < 17) {
            for (i = 0; (u16)i < 3; i++) {
                strCpy(D_800C3A50[0][i].name, race->split[i].name);
                D_800C3A50[0][i].time = SPLIT(race, i).time;
                D_800C3A50[0][i].rank = SPLIT(race, i).rank;
                splitTime = D_800C3A50[0][i].time;
                D_800C3A50[0][i].speed = SPEED(race->distance, splitTime);
                offset = i;
                flags = *(volatile s32 *)&race->flags;
                D_800C3A50[0][offset].unused = 0;
                D_800C3A50[0][offset].flags = flags;
            }
        } else if (group < 18) {
            for (i = 0; i < 3; i++) {
                strCpy(D_800C3A90[0][i].name, race->split[i].name);
                D_800C3A90[0][i].time = SPLIT(race, i).time;
                D_800C3A90[0][i].rank = SPLIT(race, i).rank;
                splitTime = D_800C3A90[0][i].time;
                D_800C3A90[0][i].speed = SPEED(race->distance, splitTime);
                D_800C3A90[0][i].unused = 0;
                D_800C3A90[0][i].flags = race->flags;
                strCpy(D_800C3B10[0][i].name, race->split[i].name);
                D_800C3B10[0][i].time = SPLIT(race, i).time;
                rank = *(volatile s32 *)&SPLIT(race, i).rank;
                D_800C3B10[0][i].unused = 0;
                D_800C3B10[0][i].rank = rank;
            }
        } else if (group < 19) {
            for (i = 0; i < 3; i++) {
                strCpy(D_800C3AD0[0][i].name, race->split[i].name);
                D_800C3AD0[0][i].time = SPLIT(race, i).time;
                D_800C3AD0[0][i].rank = SPLIT(race, i).rank;
                splitTime = D_800C3AD0[0][i].time;
                D_800C3AD0[0][i].speed = SPEED(race->distance, splitTime);
                flags = *(volatile s32 *)&race->flags;
                D_800C3AD0[0][i].unused = 0;
                D_800C3AD0[0][i].flags = flags;
                D_800C3B10[0][i].time += SPLIT(race, i).time;
                rank = *(volatile s32 *)&SPLIT(race, i).rank;
                D_800C3B10[0][i].unused = 0;
                D_800C3B10[0][i].rank = rank;
            }
        } else if (group < 20) {
            for (i = 0; (u16)i < 3; i++) {
                strCpy(D_800C3B50[0][i].name, race->split[i].name);
                D_800C3B50[0][i].time = SPLIT(race, i).time;
                D_800C3B50[0][i].rank = SPLIT(race, i).rank;
                splitTime = D_800C3B50[0][i].time;
                D_800C3B50[0][i].speed = SPEED(race->distance, splitTime);
                offset = i;
                flags = *(volatile s32 *)&race->flags;
                D_800C3B50[0][offset].unused = 0;
                D_800C3B50[0][offset].flags = flags;
            }
        }
    }
}
