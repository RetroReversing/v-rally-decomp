typedef s32 M2C_UNK;

M2C_UNK func_80048B38(s32);
s32 str_len(s32);
M2C_UNK str_ncat(s32, M2C_UNK *, s32);
extern M2C_UNK sNameSuffix;

/* Appends sNameSuffix to the name stored at +0x98 of obj, then runs func_80048B38 on obj. */
void appendNameSuffix(s32 obj) {
    s32 name;

    name = obj + 0x98;
    str_ncat(name, &sNameSuffix, str_len(name));
    func_80048B38(obj);
}
