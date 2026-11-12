void *findRecordByRange(s32, s32);

/* Sets the byte at offset 0xE of the record whose range covers key to value (low byte). */
void func_8008A14C(s32 key, s32 value)
{
    ((s8 *)findRecordByRange(key, value & 0xFFFF))[0xE] = (s8)value;
}
