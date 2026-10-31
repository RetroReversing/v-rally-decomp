extern s8 D_800AE850[];
extern s8 D_800C02AE[];
void func_80086A34(s32 arg0);
s32 func_80088008(u8 *arg0, u8 *arg1);
typedef struct Q
{
  struct Q *next;
  s32 priority;
  struct Q *queue;
} Q;
void func_8008B5DC(Q *head, Q *item)
{
  Q *prev = head;
  Q *new_var2;
  s32 new_var;
  Q *cur = head->next;
  s32 key = item->priority;
  new_var = cur->priority;
  if (new_var >= key)
  {
    new_var = cur->priority;
    new_var2 = cur;
    do
    {
      prev = new_var2;
      cur = prev->next;
    }
    while (new_var >= key);
  }
  item->next = prev->next;
  cur->next = item;
  item->queue = head;
}

u8 *func_80087DE4(u8 *arg0, u8 *arg1);
