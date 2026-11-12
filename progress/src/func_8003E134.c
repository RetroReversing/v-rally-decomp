extern char gOrderState[];

/* Sets the object's 16-bit field at +0xE from its owner's config (offset +6 or +0x10
 * depending on the entry's kind), then finds the list node whose id matches and
 * stores that id at +0x7A. */
void func_8003E134(void *object) {
    char *obj = object;
    char *owner;
    char *sub;
    char *node;
    char *cfg;
    u32 kind;
    s32 delta;
    s32 val;
    s32 id;

    owner = *((char **) (obj + 0xA8));
    sub = *((char **) (owner + 0x24));
    if (sub != 0) {
        node = *((char **) (sub + 0x6C));
        kind = *((u32 *) (node + 8));
        if (kind >= 2) {
            cfg = *((char **) (owner + 0x178));
            delta = -1;
            val = (*((u16 *) (cfg + 0xA))) + 6;
        } else {
            cfg = *((char **) (owner + 0x178));
            delta = 1;
            val = (*((u16 *) (cfg + 0xA))) + 0x10;
        }
        *((s16 *) (obj + 0xE)) = (s16) val;
        node = *((char **) (gOrderState + 0x73F0));
        sub = *((char **) node);
        if (sub != 0) {
            do {
                id = *((s32 *) ((*((char **) (sub + 0x6C))) + 8));
                if (id == (s32) (kind + ((u32) delta))) {
                    *((s16 *) (obj + 0x7A)) = (s16) id;
                    return;
                }
                sub = *((char **) (sub + 4));
            } while (sub != 0);
        }
    }
}
