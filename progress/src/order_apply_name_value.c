s32 nameTableLookup();
extern char gOrderState[];
/* Looks up the object's name (+0x4C) in the name table; if the current order entry exists and the value is nonzero, stores the value at entry +0x6E. */ /* Looks up the object's name at +0x4C in the name table; if the current order entry exists and the value is nonzero, stores it at entry +0x6E. */ void order_apply_name_value(s32 order_obj)
{
  s32 name_value;
  u8 name_byte;
  s16 *cur_entry;

  name_value = nameTableLookup(order_obj + 0x4C);
  cur_entry = *((s16 **) (gOrderState + 0x8A28));
  if (cur_entry != NULL)
  {
    name_byte = name_value;
    if (name_byte != 0)
    {
      cur_entry[0x6E / 2] = name_byte;
    }
  }
}
