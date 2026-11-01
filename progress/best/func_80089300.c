extern f64 D_800A6D48;
extern f64 D_800A6D50;
extern f64 D_800A6D58;
extern f64 D_800A6D60;
extern f64 D_800A6D68;
extern f64 D_800A6D70;
extern f64 D_800A6D78;
extern f64 D_800A6D80;
extern f64 D_800A6D88;
extern f64 D_800A6D90;
extern f64 D_800A6D98;
extern f64 D_800A6DA0;
extern f64 D_800A6DA8;
extern f64 D_800A6DB0;
f32 func_80089300(f32 x)
{
  double new_var;
  f32 c;
  f32 d;
  float new_var2;
  f64 r;
  if (x == 0.0f)
  {
    return 1.0f;
  }
  if (!(x > 0.0f))
  {
    f32 y = -x; c = y * y;
    d = c * c;
    new_var = ((f64) (d * y)) * D_800A6D70;
    {
      f64 one = D_800A6D68;
      f64 sum;
      new_var2 = d * c;
      sum = (((f64) new_var2) * D_800A6D78) + ((((((((f64) y) * D_800A6D48) + one) + (((f64) c) * D_800A6D50)) + (((f64) (c * y)) * D_800A6D58)) + (((f64) d) * D_800A6D60)) + new_var);
      r = one / sum;
    }
  }
  else
  {
 do { c = x * x; d = c * c; new_var = (f64) c; r = ((((((((f64) x) * D_800A6D80) + D_800A6DA0) + (new_var * D_800A6D88)) + (((f64) (c * x)) * D_800A6D90)) + (((f64) d) * D_800A6D98)) + (((f64) (d * x)) * D_800A6DA8)) + (((f64) (d * c)) * D_800A6DB0); } while (0);
  }
  return (f32) r;
}
