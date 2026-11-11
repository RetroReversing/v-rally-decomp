typedef struct { u8 b[8]; } Buf8;
typedef struct { s32 w[4]; } Quad;

extern int D_800B5B4C;
extern char gOrderState[];
extern char D_8009FFF0[];

s32 func_800051B4();
s32 flag_test_bit0();
s32 streamOrderInit();
void *poolAllocNode();

/* Allocates a 0x198-byte object record and fills it in: copies the 0x140-byte template at D_8009FFF0 into it, stores the id, kind and param, and zeroes the trailing words. When active is zero, only the 0x178 word is cleared. */
void *func_80042078(void *pos, u16 id, s32 active, s32 kind, u16 param) {
    u16 p16;
    char *src;
    char *obj;
    char *dst;
    char *src_end;

    p16 = param;
    if (flag_test_bit0(gOrderState + 0x7338) != 0) {
        goto block_2;
    }
    streamOrderInit();
block_2:
    obj = poolAllocNode(D_800B5B4C, 0x198);
    if (active == 0) {
        goto block_6;
    }
    *(s32 *)(obj + 0x178) = func_800051B4(pos, id & 0xFFFF, 0, 0, p16);
    *(Buf8 *)(obj + 0x17C) = *(Buf8 *)pos;
    dst = obj + 0x38;
    src = D_8009FFF0;
    src_end = src + 0x140;
    *(s16 *)(obj + 0x184) = id;
    *(s16 *)(obj + 0x186) = active;
    *(s16 *)(obj + 0x188) = kind;
    *(u16 *)(obj + 0x18A) = p16;
    *(s32 *)(obj + 0x18C) = 0;
    *(s32 *)(obj + 0x190) = 0;
    do {
        *(Quad *)dst = *(Quad *)src;
        src += 0x10;
        dst += 0x10;
    } while (src != src_end);
    return obj;
block_6:
    *(s32 *)(obj + 0x178) = 0;
    return obj;
}
