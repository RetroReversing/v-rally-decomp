s32 select_copy_entry_label();
void func_80069648();
void func_80069690();
extern char *gSelectState;
extern char *gRecords;

/* Stores the selected record index in the select state, installs the two
 * select handlers, and copies the record's byte at +0x32 into the state. */
s32 func_800695D0(s32 record_index)
{
    char *p;
    char *tbl;
    select_copy_entry_label();
    p = gSelectState;
    *(u8 *)(p + 0x228) = record_index;
    tbl = gRecords;
    *(void (**)())(p + 0x288) = func_80069648;
    *(void (**)())(p + 0x28C) = func_80069690;
    *(u8 *)(gSelectState + 0x22A) = *(u8 *)(tbl + record_index + 0x32);
    *(u8 *)(gSelectState + 0x22B) = *(u8 *)(gSelectState + 0x228);
    return 0;
}
