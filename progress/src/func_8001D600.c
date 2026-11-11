typedef struct {
    u8 pad00[0x90];
    s32 value90;
    u8 flag94;
    u8 pad95[0x47];
    s32 valueDC;
    u8 flagE0;
} VRSrcRecord;

typedef struct {
    u8 pad00[0x70];
    s16 field70;
    s16 field72;
} VRDstRecord;

extern char gOrderState[];

/* If the record at gOrderState+0x8A28 exists and both flags of src (0x94 and 0xE0) are set,
   copies src->value90 into dst->field70, and src->valueDC into dst->field72 when flag 0xE0 is set. */
void func_8001D600(void *src) {
    VRDstRecord *dst;

    if ((*(void **)(gOrderState + 0x8A28) != NULL) && (((VRSrcRecord *)src)->flag94 != 0) && (((VRSrcRecord *)src)->flagE0 != 0)) {
        dst = *(VRDstRecord **)(gOrderState + 0x8A28);
        dst->field70 = (s16) ((VRSrcRecord *)src)->value90;
        if (((VRSrcRecord *)src)->flagE0 != 0) {
            dst->field72 = (s16) ((VRSrcRecord *)src)->valueDC;
        }
    }
}
