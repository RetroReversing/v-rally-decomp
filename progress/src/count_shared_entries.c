typedef struct 
{
  u16 *pa;
  u16 na;
  u16 pad0;
  u16 *pb;
  u16 nb;
  u16 pad1;
} Lists;
void objGetTypedBlock(void *, u16 **, u16 *);
static inline int greater_than(u16 a, int b)
{
  return a > b;
}

/* Counts how many entries of list A (pa, na) also appear in list B (pb, nb).
   Both lists are fetched from their objects by objGetTypedBlock. */
#ifdef PORT
s32 count_shared_entries(void *objA, void *objB)
{
  Lists l;
  s32 pad[2];
  u16 *nbPtr;
  s32 i;
  s32 j;
  u16 na;
  u16 *listA;
  u16 cur;
  u16 nbr;
  s32 count;
  nbPtr = &l.nb;
  (void) (&pad);
  objGetTypedBlock(objA, &l.pa, &l.na);
  objGetTypedBlock(objB, &l.pb, nbPtr);
  na = l.na;
  i = 0;
  count = 0;
  if (greater_than(na, 0))
  {
    do
    {
      j = 0;
      if (l.nb & 0xFFFF)
      {
        cur = (listA = l.pa)[i];
        nbr = l.nb;
        do
        {
          count += cur == l.pb[j];
          j++;
        }
        while (j < nbr);
      }
      i++;
    }
    while (i < na);
  }
  return count;
}
#else
s32 count_shared_entries(void *objA, s32 objB)
{
  Lists l;
  s32 pad[2];
  u16 *nbPtr;
  s32 i;
  s32 j;
  u16 na;
  u16 *listA;
  u16 cur;
  u16 nbr;
  nbPtr = &l.nb;
  (void) (&pad);
  objGetTypedBlock(objA, &l.pa, &l.na);
  objGetTypedBlock((void *) objB, &l.pb, nbPtr);
  na = l.na;
  i = 0;
  objB = 0;
  if (greater_than(na, 0))
  {
    do
    {
      j = 0;
      if (l.nb & 0xFFFF)
      {
        cur = (listA = l.pa)[i];
        nbr = l.nb;
        do
        {
          objB += cur == l.pb[j];
          j++;
        }
        while (j < nbr);
      }
      i++;
    }
    while (i < na);
  }
  return objB;
}
#endif
