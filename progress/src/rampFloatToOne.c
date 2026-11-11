extern f64 D_800A54D8;
extern f64 gRampStep;

/* Ramps *value up by gRampStep while it is below the limit D_800A54D8; once it reaches the limit, sets it to 1.0. arg0 is unused. */
void rampFloatToOne(s32 arg0, f32 *arg1)
{
    f32 var_fv1;
    var_fv1 = (f64)(*arg1);
    if (var_fv1 < D_800A54D8) {
        var_fv1 = (f32)(var_fv1 + gRampStep);
    } else {
        var_fv1 = 1.0f;
    }
    *arg1 = var_fv1;
}
