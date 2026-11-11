/* Writes the 4x4 identity matrix into mtx (row-major, 16 words): 1.0f on the diagonal, 0 elsewhere. */
void guMtxIdentF(s32 *mtx)
{
  s32 row;
  s32 col;
  s32 *cell;
  s32 *diag;
  f32 one;

  row = 0;
  one = 1.0f;
  diag = mtx;
  do {
    col = 0;
    cell = mtx;
    do {
      if (row == col) {
        *(f32 *)diag = one;
      } else {
        *cell = 0;
      }
      col++;
      cell++;
    } while (col < 4);
    diag += 5;
    row++;
    mtx += 4;
  } while (row < 4);
}
