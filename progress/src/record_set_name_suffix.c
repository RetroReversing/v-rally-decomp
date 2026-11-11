s32 dispatch_name_handler(void *obj, void *record);
s32 str_len(void *s);
void *str_ncat(void *dst, void *src, s32 n);
extern u8 sNameSuffix[];
extern u8 gOrderState[];

/* Appends the suffix string sNameSuffix to the record's name (at +0x4C), then
 * stores the result of dispatch_name_handler for this record in gOrderState. */
void record_set_name_suffix(s32 record)
{
    s32 name;

    name = record + 0x4C;
    str_ncat(name, sNameSuffix, str_len(name));
    *(s32 *)(gOrderState + 0x8A28) = dispatch_name_handler(*(void **)(gOrderState + 0x252C), (void *)record);
}
