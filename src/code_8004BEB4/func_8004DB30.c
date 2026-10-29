#include "snapshot29_0433f7af8f6d.h"

typedef struct DB30Rec
{
  void *ptr;
  s16 pad4;
  s16 pad6;
} DB30Rec;
typedef struct DB30Block
{
  u8 pad0[0x18];
  u16 count;
} DB30Block;
typedef struct DB30Ent
{
  u16 type;
  u16 pad2;
  u32 step;
  s16 value;
} DB30Ent;
s32 func_8004D4D8(void *, void *);
s32 func_8004DB30(void *arg0, s16 arg1)
{
  u32 count;
  int new_var;
  DB30Rec *table;
  s16 n;
  unsigned short found;
  u16 i;
  u16 j;
  DB30Rec *rec;
  DB30Block *block;
  DB30Ent *ent;
  s16 key;
  count = *((u32 *) (((u8 *) arg0) + 0x50));
  table = *((DB30Rec ***) (((u8 *) arg0) + 0x68));
  n = arg1;
  found = 0;
  if (count != 0)
  {
    i = 0;
    while ((((u32) i) < (*((u32 *) (((u8 *) arg0) + 0x50)))) && (found != 1))
    {
      rec = (DB30Rec *) ((((u32) i) * 8) + ((u32) table));
      new_var = 0;
      key = rec->pad4;
      if (key == new_var)
      {
        block = (DB30Block *) rec->ptr;
        j = new_var;
        ent = (DB30Ent *) (((u8 *) block) + 0x1c);
        if ((((u32) key) < block->count) && (found != 1))
        {
          do
          {
            if (ent->type == 1)
            {
              func_8004D4D8(arg0, block);
 do { ent->value = n; n++; } while (0);
              found = 1;
            }
            ent = (DB30Ent *) (((u8 *) ent) + (ent->step + 8));
            j++;
          }
          while ((((u32) j) < block->count) && (found != 1));
        }
      }
      i++;
    }

  }
  return found;
}
