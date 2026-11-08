typedef struct Car40 { u8 pad0[0x10]; u16 flags; u8 pad12[2]; u16 cls; u8 pad16[0x2C4 - 0x16]; } Car40;
typedef struct Pl40 { u8 name[4]; u8 pad[6]; u16 car; u8 pad2[0x28 - 0xC]; } Pl40;
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

/* Chooses the car for each player in the race. Players without a name get a
 * default one. When the race uses class rules, each remaining car slot is
 * filled by a random car of the required class that no earlier slot has
 * taken and that is not flagged in the car database. The chosen car
 * indices are then copied back into the player records. */
void func_800407D0(void)
{
  s32 classes[4];
  s32 name_buf[2];
  u32 ncars;
  u32 nplayers;
  u16 i;
  u32 k;
  u32 slot;
  u16 *car_ids;
  Db40 *db_root;
  Car40 *cars_db;
  s32 *cls_next;
  s32 *cls_cur;
  s32 picked;
  u32 car;
  s32 unique;

  ncars = D_800D0630;
  nplayers = D_800C35A0->nplayers;
  car_ids = D_800C35A0->car;
  db_root = &D_800D05E0;
  func_800980C4(osGetTime());
  if (ncars == 0)
    return;
  for (i = 0; i < nplayers; i++)
  {
    car_ids[i] = D_800C35A0->pl[D_800C35A0->slot[i]].car;
    if (D_800C35A0->pl[D_800C35A0->slot[i]].name[0] == 0)
    {
      func_80099DF8(name_buf, D_800A4C20, D_800A4C28, i + 1);
      *(s32 *) D_800C35A0->pl[D_800C35A0->slot[i]].name = name_buf[0];
    }
  }
  if (D_800C35A0->flag == 0)
    return;
  cars_db = db_root->cars;
  for (i = 0; i < nplayers; i++)
    classes[i] = cars_db[D_800C35A0->pl[D_800C35A0->slot[i]].car].cls;
  i = nplayers;
  if (i < 4)
  {
    cls_next = classes;
    do
    {
      switch (D_800C35A0->nplayers)
      {
        case 1:
          if (classes[0] == 2)
            classes[0] = 0;
          picked = 0;
          cls_cur = cls_next;
          slot = i;
          do
          {
            car = func_80098090() % ncars;
            unique = 1;
            if (cars_db[car].cls == *cls_cur)
            {
              u32 lim = slot;
              for (k = 0; k < lim; k++)
                unique &= -(car_ids[k] != car);
              if (unique && !(cars_db[car].flags & 8))
              {
                car_ids[slot] = car;
                picked = 1;
                func_80053C28(D_800C35A0->slot[slot], car & 0xFF);
              }
            }
          }
          while (!picked);
          break;
        case 2:
          if (classes[0] == 2)
            classes[0] = 0;
          if (classes[1] == 2)
            classes[1] = 0;
          picked = 0;
          slot = i;
          do
          {
            car = func_80098090() % ncars;
            unique = 1;
            if (cars_db[car].cls == *cls_next)
            {
              u32 lim = slot;
              for (k = 0; k < lim; k++)
                unique &= -(car_ids[k] != car);
              if (unique && !(cars_db[car].flags & 8))
              {
                picked = 1;
                car_ids[slot] = car;
                func_80053C28(D_800C35A0->slot[slot], car & 0xFF);
                cls_next++;
              }
            }
          }
          while (!picked);
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
