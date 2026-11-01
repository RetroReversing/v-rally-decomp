typedef struct Car40 { u8 pad0[0x10]; u16 flags; u8 pad12[2]; u16 cls; u8 pad16[0x2C4 - 0x16]; } Car40;
typedef struct Pl40 { s32 name; u8 pad[6]; u16 car; u8 pad2[0x28 - 0xC]; } Pl40;
typedef struct Race40 {
  u8 pad0[0xE]; u16 nplayers; u8 pad10[0xE]; u16 flag; u8 pad20[0x12];
  u8 slot[4]; u8 pad36[4]; u16 car[4]; u8 pad42[2]; Pl40 pl[4];
} Race40;
typedef struct Db40 { u8 pad[0x78]; Car40 *cars; } Db40;
extern Race40 *D_800C35A0;
extern u16 D_800D0630;
extern Db40 D_800D05E0;
extern char D_800A4C20[];
extern char D_800A4C28[];
u64 osGetTime(void);
void func_80053C28(s32, s32);
u32 func_80098090(void);
void func_800980C4(u32);
void func_80099DF8(s32 *, char *, char *, s32);
void func_800407D0(void)
{
  s32 cls[4];
  s32 name[2];
  u32 count;
  u32 n;
  u16 i;
  u32 k;
  u32 j;
  u16 *cars;
  u16 *c;
  Db40 *dbs;
  Car40 *db;
  s32 *p;
  s32 *q;
  s32 done;
  u32 r;
  s32 ok;

  count = D_800D0630;
  n = D_800C35A0->nplayers;
  cars = D_800C35A0->car;
  dbs = &D_800D05E0;
  func_800980C4(osGetTime());
  if (count == 0)
    return;
  for (i = 0; i < n; i++)
  {
    cars[i] = D_800C35A0->pl[D_800C35A0->slot[i]].car;
    if (*(u8 *) &D_800C35A0->pl[D_800C35A0->slot[i]].name == 0)
    {
      func_80099DF8(name, D_800A4C20, D_800A4C28, i + 1);
      *(s32 *) &D_800C35A0->pl[D_800C35A0->slot[i]] = name[0];
    }
  }
  if (D_800C35A0->flag == 0)
    return;
  db = dbs->cars;
  for (i = 0; i < n; i++)
    cls[i] = db[D_800C35A0->pl[D_800C35A0->slot[i]].car].cls;
  i = n;
  if (i < 4)
  {
    p = cls;
    do
    {
      switch (D_800C35A0->nplayers)
      {
        case 1:
          if (cls[0] == 2)
            cls[0] = 0;
          done = 0;
          q = p;
          j = i;
          do
          {
            r = func_80098090() % count;
            ok = 1;
            if (db[r].cls == *q)
            {
              u32 lim = j;
              for (k = 0; k < lim; k++)
                ok &= -(cars[k] != r);
              if (ok && !(db[r].flags & 8))
              {
                cars[j] = r;
                done = 1;
                func_80053C28(D_800C35A0->slot[j], r & 0xFF);
              }
            }
          }
          while (!done);
          break;
        case 2:
          if (cls[0] == 2)
            cls[0] = 0;
          if (cls[1] == 2)
            cls[1] = 0;
          done = 0;
          j = i;
          do
          {
            r = func_80098090() % count;
            ok = 1;
            if (db[r].cls == *p)
            {
              u32 lim = j;
              for (k = 0; k < lim; k++)
                ok &= -(cars[k] != r);
              if (ok && !(db[r].flags & 8))
              {
                done = 1;
                cars[j] = r;
                func_80053C28(D_800C35A0->slot[j], r & 0xFF);
                p++;
              }
            }
          }
          while (!done);
          break;
        case 3:
          break;
      }
      i++;
    }
    while (i < 4);
  }
  for (i = 0; i < 4; i++)
    D_800C35A0->pl[D_800C35A0->slot[i]].car = D_800C35A0->car[i];
}
