extern char *D_800AFA64;
extern char *gLeague;

/* If the current menu's sub-object at +0x5C has its flag at +0x5C set, makes that
 * sub-object current and sets field +0x10 of the league's item at index `count` to 100. */
void league_set_item_100(void) {
    char *obj;
    char *tbl;
    s32 idx;

    obj = *((char **) (D_800AFA64 + 0x5C));
    if (*((s32 *) (obj + 0x5C)) != 0) {
        tbl = gLeague;
        idx = *((s16 *) (tbl + 2));
        D_800AFA64 = obj;
        *((s32 *) (((*((char **) (tbl + 0x10))) - (-(idx * 20))) + 0x10)) = 100;
    }
}
