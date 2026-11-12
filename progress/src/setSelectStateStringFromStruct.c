s32 strCpy(s32, s32);
extern s32 gSelectState;

/* Copies the name string from a select-state info struct (offset 0x4C)
 * into the select-state buffer at +0x204. */
void setSelectStateStringFromStruct(s32 info) {
    strCpy(gSelectState + 0x204, info + 0x4C);
}
