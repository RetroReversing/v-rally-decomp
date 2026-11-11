extern char gStreamState[];

/* Sound name table: 0x800 buckets of HashEnt pointers. */
typedef struct {
    u16 key;
    u8 pad[2];
    s32 val;
    s8 tag;
} HashEnt;

s32 soundNameHash(u8 *, u16);

/* Looks up a sound by name (name_len bytes) in the hash table. Tries the bucket
   for the hash first, then scans every bucket for a matching key and tag. Returns
   the sound's value, or 0 when the name is not in the table. */
s32 func_800555A0(u8 *name, s32 name_len)
{
    u8 found;
    u16 i;
    u16 h;
    u16 k;
    s32 c;
    HashEnt *e;

    found = 0;
    k = name_len & 0xFFFF;
    h = soundNameHash(name, k) & 0xFFFF;
    e = ((HashEnt **) (gStreamState + 0x3902))[h];
    if (e == NULL) {
        return 0;
    }
    c = *name;
    if (e->key == k + h + c && e->tag == c) {
        return e->val;
    }
    i = 0;
    while (i < 0x800) {
        e = ((HashEnt **) (gStreamState + 0x3902))[i];
        if (e != NULL && e->key == k + h + *name) {
            if (e->tag == *name) {
                found = 1;
                break;
            }
        }
        i++;
    }
    if (!found) {
        return 0;
    }
    return ((HashEnt **) (gStreamState + 0x3902))[i]->val;
}
