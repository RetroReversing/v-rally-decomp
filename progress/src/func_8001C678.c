extern unsigned char g_dark_mode;
extern char D_800A4748[];
extern char D_800A4754[];
extern char D_800A4760[];

s32 func_8001B854();
s32 resolve_path();
s32 *func_80081664();
s32 format_to_buffer();

/* Builds a file name from the format string picked by g_dark_mode and the name at +0x4C,
   fetches the entry for slot 6, resolves the path at +0x98 and loads it into that entry. */
void func_8001C678(s32 *obj) {
    s32 name[4];
    s32 mode;
    s32 *entry;
    s32 *path;

    mode = g_dark_mode;
    path = obj;
    if (mode == 0) {
        format_to_buffer(name, D_800A4748, (u8 *)path + 0x4C);
    } else {
        if (mode < 0) {
            format_to_buffer(name, D_800A4760, (u8 *)path + 0x4C);
        } else if (mode < 3) {
            format_to_buffer(name, D_800A4754, (u8 *)path + 0x4C);
        } else {
            format_to_buffer(name, D_800A4760, (u8 *)path + 0x4C);
        }
    }
    entry = func_80081664(6, name);
    path = (s32 *)((u8 *)path + 0x98);
    resolve_path(path);
    func_8001B854(entry, path);
}
