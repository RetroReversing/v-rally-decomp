f64 _ldexpf(f64 value, s32 exp) {
    f64 result;

    result = value;
    if (exp != 0) {
        result *= (f64) (1 << exp);
    }
    return result;
}
