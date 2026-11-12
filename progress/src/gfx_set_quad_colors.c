#ifdef PORT
#define VTX_PTR(obj, off) ((s8 *)(*(s8 **)((s8 *)(obj) + 0x70)) + (off))
#else
#define VTX_PTR(obj, off) ((s8 *)((off) + *(s32 *)((s8 *)(obj) + 0x70)))
#endif

/* Writes the colour bytes of the four vertices of quad `index` (16-byte Vtx entries, array at obj+0x70). Each vertex gets two signed and two unsigned colour bytes. */
void gfx_set_quad_colors(void *obj, s32 index, s8 v0a, s8 v0b, u8 v0c, u8 v0d, u8 v1a, u8 v1b, u8 v1c, u8 v1d, u8 v2a, u8 v2b, u8 v2c, u8 v2d, u8 v3a, u8 v3b, u8 v3c, u8 v3d) {
    s32 off;

    off = (index & 0xFFFF) * 0x10;
    *(s8 *)(VTX_PTR(obj, off) + 0xC) = v0a;
    *(s8 *)(VTX_PTR(obj, off) + 0xD) = v0b;
    *(u8 *)(VTX_PTR(obj, off) + 0xE) = v0c;
    *(u8 *)(VTX_PTR(obj, off) + 0xF) = v0d;
    *(u8 *)(VTX_PTR(obj, off) + 0x1C) = v1a;
    *(u8 *)(VTX_PTR(obj, off) + 0x1D) = v1b;
    *(u8 *)(VTX_PTR(obj, off) + 0x1E) = v1c;
    *(u8 *)(VTX_PTR(obj, off) + 0x1F) = v1d;
    *(u8 *)(VTX_PTR(obj, off) + 0x2C) = v2a;
    *(u8 *)(VTX_PTR(obj, off) + 0x2D) = v2b;
    *(u8 *)(VTX_PTR(obj, off) + 0x2E) = v2c;
    *(u8 *)(VTX_PTR(obj, off) + 0x2F) = v2d;
    *(u8 *)(VTX_PTR(obj, off) + 0x3C) = v3a;
    *(u8 *)(VTX_PTR(obj, off) + 0x3D) = v3b;
    *(u8 *)(VTX_PTR(obj, off) + 0x3E) = v3c;
    *(u8 *)(VTX_PTR(obj, off) + 0x3F) = v3d;
}
