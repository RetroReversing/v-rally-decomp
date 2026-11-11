typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct S1 {
    u8 pad0[0x24];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x4C - 0x30];
    s32 unk4C;
    u8 pad50[0x54 - 0x50];
    Vec3s *unk54;
    u8 pad58[0x88 - 0x58];
    u16 unk88;
    u16 unk8A;
} S1;

void func_8002D2C8(s32, s32, s16, Vec3s *);

/* Advances a position by the current path entry's offset and steps the object's
   path index: pos gets the entry's x/y/z plus the object's base offsets, then the
   step to the next entry (unk8A entries on) is passed to func_8002D2C8. */
void func_8001C444(s32 *pos, S1 *obj) {
    s32 idx;
    s32 byteOff;
    Vec3s *next;
    s32 dx, baseX;
    Vec3s *verts;

    idx = obj->unk88 >> 1;
    idx *= obj->unk8A;
    idx += obj->unk4C;

    baseX = obj->unk24;
    verts = obj->unk54;
    byteOff = idx * 6;
    dx = ((Vec3s *)(byteOff + (int)verts))->x;
    dx += baseX;
    pos[0] += dx;
    pos[1] = (((Vec3s *)(byteOff + (int)obj->unk54))->y + obj->unk28) - 0x96;
    pos[2] += ((Vec3s *)(byteOff + (int)obj->unk54))->z + obj->unk2C;
    idx += obj->unk8A;
    next = (Vec3s *)(idx * 6 + (int)obj->unk54);
    func_8002D2C8(next->x - ((Vec3s *)(byteOff + (int)obj->unk54))->x, next->z - ((Vec3s *)(byteOff + (int)obj->unk54))->z, next->x, (Vec3s *)(byteOff + (int)obj->unk54));
}
