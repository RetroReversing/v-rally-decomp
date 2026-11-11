typedef struct Obj
{
  s32 unk_00;
  s32 unk_04;
} Obj;
typedef struct Entry
{
  char *key;
  void (*handler)(Obj *, u8 *, s32);
  s32 value;
} Entry;
extern Entry gNameHandlers[];
extern s32 strCmp(u8 *, char *);
extern s32 func_80040084(Obj *, u8 *, s32);

/* Looks up the record's name (at +0x4C) in gNameHandlers. On a match it runs that
 * handler and returns the object's second word if the handler changed it, else 0.
 * With no match it falls back to func_80040084 to create the sprite. */
s32 dispatch_name_handler(Obj *obj, u8 *record)
{
  Entry *entry;
  s32 result;
  u8 handled;

  result = (handled = 0);
  entry = gNameHandlers;
  loop:
  {
    if (entry->handler == NULL)
    {
      goto end;
    }
    do
    {
      if (strCmp(record + 0x4C, entry->key) == 0)
      {
        result = obj->unk_04;
        entry->handler(obj, record, entry->value);
        if (obj->unk_04 != result)
        {
          result = obj->unk_04;
        }
        else
        {
          result = 0;
        }
        handled = 1;
      }
      entry++;
      if (!handled)
      {
        goto loop;
      }
    }
    while (0);
  }

  end:
  if (!handled)
  {
    if (entry)
    {
      result = func_80040084(obj, record, 0);
    }
    else
    {
      result = func_80040084(obj, record, 0);
    }
  }

  return result;
}
