/* Writes the four corners of a quad into the vertex buffer at obj->verts + vtxIndex * 16.
 * Each corner is x, y, z; the z/x/y arguments are packed 32-bit words, and only the low 16 bits are stored. */
void gfx_set_quad_pos(u8 *obj, s32 vtxIndex, u16 x0, u16 y0, u32 z0, u32 x1, u32 y1, u32 z1, u32 x2, u32 y2, u32 z2, u32 x3, u32 y3, u32 z3) {
    s32 byteOff = (vtxIndex & 0xFFFF) << 4;

    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70)) = x0;
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 2) = y0;
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 4) = *(u16 *)((u8 *)&z0 + 2);
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 0x10) = *(u16 *)((u8 *)&x1 + 2);
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 0x12) = *(u16 *)((u8 *)&y1 + 2);
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 0x14) = *(u16 *)((u8 *)&z1 + 2);
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 0x20) = *(u16 *)((u8 *)&x2 + 2);
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 0x22) = *(u16 *)((u8 *)&y2 + 2);
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 0x24) = *(u16 *)((u8 *)&z2 + 2);
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 0x30) = *(u16 *)((u8 *)&x3 + 2);
    *(u16 *)(byteOff + (s32)*(u8 **)(obj + 0x70) + 0x32) = *(u16 *)((u8 *)&y3 + 2);
    byteOff = byteOff + (s32)*(u8 **)(obj + 0x70);
    *(u16 *)(byteOff + 0x34) = *(u16 *)((u8 *)&z3 + 2);
}
