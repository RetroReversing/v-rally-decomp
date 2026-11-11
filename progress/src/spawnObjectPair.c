extern s32 gOrderState[];
s32 func_80005CB8(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 streamFreeObject(s32 a);
s32 func_80005EB0(void);

/* Allocates two objects of the given type from the pools. If both succeed, they are stored
 * in the two slots at gOrderState+0x7400 and +0x12EC and the slots are swapped; if the second
 * allocation fails, the first is freed. Returns 1 on success, 0 otherwise. */
s32 spawnObjectPair(s32 unused0, s32 unused1, s32 nItems, s32 nExtra, u16 typeId)
{
    s32 first;
    s32 second;
    s32 result = 0;
    s32 v;
    u16 s1 = typeId;

    first = func_80005CB8(s1, nItems, nExtra, 1, 6);
    second = first;
    if (first != 0) {
        v = func_80005CB8(s1, nItems, nExtra, 1, 6);
        if (v != 0) {
            *(s32 *)((u8 *)gOrderState + 0x7400) = first;
            *(s32 *)((u8 *)gOrderState + 0x12EC) = v;
            result = 1;
            func_80005EB0();
        } else {
            streamFreeObject(second);
        }
    }
    return result;
}
