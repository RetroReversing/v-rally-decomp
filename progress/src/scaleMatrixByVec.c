/* Scales each of the three rows of the 3x3 s16 part of a matrix element-wise by the s32 vector
 * `scale` (16.12 fixed point): each product is shifted right by 12 and stored back in the cell.
 * Returns the matrix. */
void *scaleMatrixByVec(void *matrix, void *scale) {
 s32 row=0; s16 *cell=(s16*)matrix; s32 *factor=(s32*)scale; s32 v;
loop:
 v=cell[0]; v=v*factor[0]; cell[0]=(s16)((u32)v>>12);
 v=cell[1]; v=v*factor[1]; cell[1]=(s16)((u32)v>>12);
 row++;
 v=cell[2]; v=v*factor[2]; cell[2]=(s16)((u32)v>>12);
 cell+=3; if(row<3)goto loop;
 return matrix;
}
