/* Copies the 4x4 float matrix `src` into `dst` transposed: dst[col][row] = src[row][col].
 * dst rows are 0x10 bytes apart. */
void transposeMatrix4x4(f32 *src, s32 dst) {
    f32 *elem;
    f32 *srcPtr;
    f32 value;
    s32 col;
    s32 row;
    s32 rowOffset;
    s32 dstPtr;
    f32 *srcRow;

    row = 0;
    srcRow = src;
    do {
        col = 0;
        rowOffset = row * 4;
        srcPtr = srcRow;
        dstPtr = dst;
loop_2:
        value = *srcPtr;
        srcPtr += 1;
        elem = (f32 *) (rowOffset + dstPtr);
        *elem = value;
        dstPtr += 0x10;
        if (++col < 4) {
            goto loop_2;
        }
        row += 1;
        srcRow = srcRow + 4;
    } while (row < 4);
}
