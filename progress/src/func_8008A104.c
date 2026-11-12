char *getRecordValueFromRange(int a, int b);
/* Looks up the record for recordKey/rangeKey and stores two status bytes at offsets 9 and 0xA. */
void func_8008A104(int recordKey, int rangeKey, char status, char flags) { char *rec = getRecordValueFromRange(recordKey, rangeKey & 0xFFFF); rec[9] = status; rec[0xA] = flags; }
