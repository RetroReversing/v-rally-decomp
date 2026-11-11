s32 find_object_by_id(s32);
s32 func_800480B0(s32, s32);
s32 func_80048878(s32, s32);

/* Looks up the object for 1-based slot number (slot & 0xFF) with id ((slot-1)*2)|1, then passes it and value to func_800480B0 and func_80048878. */
void func_80047F3C(s32 value, s32 slot)
{
    s32 object;

    object = find_object_by_id((((slot & 0xFF) - 1) * 2) | 1);
    func_800480B0(object, value);
    func_80048878(object, value);
}
