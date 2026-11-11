typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

s32 view_get_ctx_id(s32);
void *gfx_get_dl(s32);
s32 gfx_set_dl(s32, void *);
void *find_object_by_id(u32);
s32 guMtxIdent(void *);
extern u8 *gRecords;
extern u8 D_800C8380[];

/* For each object in the record table, emits a G_MOVEWORD, a matrix load of the identity matrix, and a
 * pipe sync into that object's view display list. */
void func_80010AF4(void) {
    u8 *obj;
    Gfx *dl;
    Gfx *cmd;
    Gfx *cmd2;
    u8 *identityMtx;
    s32 ctxId;
    u8 objCount;
    u32 objId;

    objCount = (*(u16 *)(gRecords + 0xE) * 2) & 0xFF;
    objId = 1;
    if (objCount != 0) {
        identityMtx = D_800C8380;
        do {
            obj = find_object_by_id(objId);
            objId += 1;
            ctxId = view_get_ctx_id(*(s32 *)(obj + 0x178));
            dl = gfx_get_dl(ctxId);
            guMtxIdent(identityMtx);
            cmd = dl++;
            cmd->w0 = 0xDB0E0000;
            cmd->w1 = *(u16 *)(obj + 0x104);
            cmd2 = dl++;
            cmd2->w0 = 0xDA380003;
            cmd2->w1 = (u32)identityMtx;
            dl->w0 = 0xE7000000;
            dl->w1 = 0;
            gfx_set_dl(ctxId, dl + 1);
        } while (objCount >= objId);
    }
}
