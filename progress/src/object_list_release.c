extern s32 gStreamState;

/* Walks the object list from *list_head. Objects with flags bit 1 run their destructor
 * (at +0x54) if one is set. Unless flags bit 2 is also set, they are then passed to the
 * release callback (at +0x50) together with the context at gStreamState + 0x7CD6 -> 0x178. */
void object_list_release(void **list_head) {
    void (*destroy)(void *);
    void *next;
    void *ctx;
    void *obj;

    obj = *list_head;
    ctx = *(void **) (((char *) &gStreamState) + 0x7CD6);
    if (obj != NULL) {
        do {
            next = *(void **) ((char *) obj + 4);
            if (*(s32 *) ((char *) obj + 0xC) & 1) {
                destroy = *(void (**)(void *)) ((char *) obj + 0x54);
                if (destroy != NULL) {
                    destroy(obj);
                }
                if (!(*(s32 *) ((char *) obj + 0xC) & 2)) {
                    (*(void (**)(s32, void *)) ((char *) obj + 0x50))(*(s32 *) ((char *) ctx + 0x178), obj);
                }
            }
            obj = next;
        } while (obj != NULL);
    }
}
