void mat3x3MulQ12();

/* Builds a 3x3 rotation matrix (Q12 fixed point) from three Euler angles
   (angles[0..2] for X, Y, Z): multiplies the X and Y rotations, then the Z
   rotation, and writes the result to out. */
s16 *mat3x3_from_euler(s16 *angles, s16 *out) {
 s16 rot_y[16], rot_x[16], rot_z[16], tmp[16];
 s16 x_cos, x_sin, y_cos, y_sin, z_cos, z_sin;
 x_cos = cos_q12(angles[0]);
 x_sin = sin_q12(angles[0]);
 y_cos = cos_q12(angles[1]);
 y_sin = sin_q12(angles[1]);
 z_cos = cos_q12(angles[2]);
 z_sin = sin_q12(angles[2]);
 rot_x[0]=0x1000;rot_x[1]=0;rot_x[2]=0;rot_x[3]=0;rot_x[4]=x_cos;rot_x[5]=-x_sin;rot_x[6]=0;rot_x[7]=x_sin;rot_x[8]=x_cos;
 rot_y[0]=y_cos;rot_y[1]=0;rot_y[2]=y_sin;rot_y[3]=0;rot_y[4]=0x1000;rot_y[5]=0;rot_y[6]=-y_sin;rot_y[7]=0;rot_y[8]=y_cos;
 rot_z[0]=z_cos;rot_z[1]=-z_sin;rot_z[2]=0;rot_z[3]=z_sin;rot_z[4]=z_cos;rot_z[5]=0;rot_z[6]=0;rot_z[7]=0;rot_z[8]=0x1000;
 mat3x3MulQ12(rot_x,rot_y,tmp);mat3x3MulQ12(tmp,rot_z,out);return out;
}
