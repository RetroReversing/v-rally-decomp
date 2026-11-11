void *textObjGet(u32);

/* Gets the text object with the given id and sets its three colour bytes (at +0xB, +0xC, +0xD). */
void textSetColor(s32 id, s8 red, s8 green, s8 blue) {
    void *obj;

    obj = textObjGet(id);
    *(s8 *)((char *)obj + 0xB) = red;
    *(s8 *)((char *)obj + 0xC) = green;
    *(s8 *)((char *)obj + 0xD) = blue;
}
