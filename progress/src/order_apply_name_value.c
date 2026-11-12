s32 nameTableLookup();
extern char gOrderState[];
/* Looks up the object's name at +0x4C in the name table; if the current order entry exists and the value is nonzero, stores it at entry +0x6E. */ void order_apply_name_value(s32 obj)
{
  s32 nameValue;
  u8 nameByte;
  s16 *orderEntry;

  nameValue = nameTableLookup(obj + 0x4C);
  orderEntry = *((s16 **) (gOrderState + 0x8A28));
  if (orderEntry != NULL)
  {
    nameByte = nameValue;
    if (nameByte != 0)
    {
      orderEntry[0x6E / 2] = nameByte;
    }
  }
}
