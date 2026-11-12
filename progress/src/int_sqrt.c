/* Integer square root through the float sqrt; negative input gives 0. */
s32 int_sqrt(s32 value) { if (value < 0) return 0; return (s32)__builtin_sqrtf((f32)value); }
