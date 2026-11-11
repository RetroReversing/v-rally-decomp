typedef struct { u8 pad[4]; u32 *buf; u16 flags, status, count, len; } CarEntry;
typedef struct { u8 pad[0x110]; u16 entry_count, sample_limit; u8 cursor; } CarEntries;
typedef struct { u8 pad[0x0E]; u16 mode; u8 pad2[0x0A]; u16 a; u8 pad3[2]; u16 b; } RaceEvent;
extern CarEntries *gCarEntries;
extern char gStreamState[];
extern void car_entries_refresh(void *);
#define CUR_EVENT (*(RaceEvent **)(gStreamState + 0x32F2))
#define CAR_AT(s, n) ((CarEntry *)((u8 *)(s) + (n) * 0x44))

/* Records one sample (arg0) into the car entry under the cursor and advances
 * the cursor. Entries that are not in status 1 only get the event side effects.
 * When an entry fills its sample buffer, it is marked for a status-3 rearm. */
s32 func_80050048(s32 sample)
{
    char *__repair_addr;
    CarEntries *s = gCarEntries;
    u8 cursor = s->cursor;
    CarEntry *entry = CAR_AT(s, cursor);
    u8 i;

    if (entry->status != 1) {
        if (CUR_EVENT->b == 0 && CUR_EVENT->a != 0 && CUR_EVENT->mode == 2) {
            s->cursor = cursor + 1;
            if (s->cursor == s->entry_count) s->cursor = 0;
        }
        return 0;
    }
    if (entry->flags & 8) {
        if (CUR_EVENT->b == 0 && CUR_EVENT->a == 0) {
            for (i = 0; i < s->entry_count; i++) {
                CarEntry *p = CAR_AT(s, i);
                p->status = 1;
                p->flags &= ~8;
            }
        } else {
            for (i = 0; i < 4; i++) {
                CarEntry *p = CAR_AT(s, i);
                p->status = 1;
                p->flags &= ~8;
            }
        }
    }
    if (entry->count == 0 && !(entry->flags & 0x200)) car_entries_refresh(s);
    {
        u32 *b = entry->buf;
        u16 c = entry->count;
        __repair_addr = (char *)((u8 *)b + c * 4);
        *(u32 *)(__repair_addr) = sample;
    }
    entry->count++;
    if (entry->len < entry->count) entry->len++;
    if (s->sample_limit - 1 < entry->count) {
        if (entry->flags & 0x10) {
            if (CUR_EVENT->b == 0) entry->flags |= 0x80;
        }
        if (CUR_EVENT->b) {
            for (i = 0; i < 4; i++) {
                entry = CAR_AT(s, i);
                entry->status = 3;
            }
        } else {
            entry = CAR_AT(s, s->cursor);
            entry->status = 3;
        }
    }
    s->cursor++;
    if (s->cursor == s->entry_count) s->cursor = 0;
    return 1;
}
