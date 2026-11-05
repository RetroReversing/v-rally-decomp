#include "decompdecomp_snapshot_80021064.h"
#line 1 "func.c"
typedef struct VR210Manager
{
  char *contacts;
  u16 threshold;
  u8 flags[4];
  u8 pad0a[10];
  u16 capacity;
  u8 pad16[2];
  u16 head;
} VR210Manager;
extern u8 D_8009D6A8[];
extern s32 D_8009EB80;
extern s32 D_800AFA6C;
extern char *D_800C35A0;
extern char *D_800C811C;
void func_8002FD68(void);
u64 osGetTime(void);
void func_800980C4(u32);
int func_80098090(void);
void *func_8002EB34(void *, int, void *);
void *func_8002E514(void *, void *, void *);
void func_8002D3AC(void *, void *, int, int, void *);
int func_8001FEE8(void *);
void func_8002FBD4(void *, int, int);
void func_8002E778(void *, void *);
void func_8002EC5C(void *, void *, void *);
void func_80021064(void *list)
{
  s16 a[3];
  int new_var;
  int new_var2;
  s16 b[3];
  s16 c[3];
  char *obj;
  int new_var3;
  VR210Manager *manager;
  char *snapshot;
  char *particle;
  char *contact;
  char *flags;
  unsigned i;
  unsigned n;
  int effect = 0;
  int type;
  int x;
  int z;
  int y;
  int j;
  long v;
  int extra;
  int trigger;
  int wx;
  int wy;
  int wz;
  int world[3];
  func_8002FD68();
  obj = *((char **) (((char *) list) + 0));
  if ((*((u16 *) (((char *) D_800C35A0) + 0xe))) < 3)
  {
    do
    {
      for (; obj; obj = *((char **) (((char *) obj) + 4)))
      {
        int velocity;
        extra = (int)*((char **)(((char *)obj)+0x38)); snapshot = (char *)extra + 12; manager = *(VR210Manager **)extra;
        velocity = *((int *) (((char *) (*((char **) (((char *) obj) + 0x58)))) + 0));
        for (i = D_800AFA6C & 1; i < 4; i += 2)
        {
          if ((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x310 + (i * 4))))) >= 0)
          {
            continue;
          }
          v = *((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + (0x1dc + (i * 4))));
          x = *((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x100 + (i * 20))));
          type = *((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x320 + (i * 4))));
          z = *((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x108 + (i * 20))));
          y = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + 4))) + 30;
          switch (type)
          {
            case 7:
              effect = 3;
              break;

            case 6:
              effect = (D_8009EB80 == 7) ? (1) : (4);
              break;

            case 4:

            case 8:
              effect = (D_8009EB80 == 3) ? (4) : (1);
              break;

            case 9:
              effect = 2;
              break;

            case 5:

            case 10:

            case 11:

            default:
              goto special;

          }

          if ((velocity > 1000) && (D_800AFA6C & 2))
          {
            func_800980C4(osGetTime());
            b[0] = 0;
            b[1] = 0;
            b[2] = 0;
            particle = func_8002EB34(manager, effect, b);
            new_var2 = func_80098090();
            *((s16 *) (((char *) particle) + 6)) = y;
            *((s16 *) (((char *) particle) + 4)) = (x + (new_var2 % 31)) - 15;
            *((s16 *) (((char *) particle) + 8)) = (z + (func_80098090() % 31)) - 15;
          }
          special:
          if (((((*((u16 *) (((char *) D_800C35A0) + 0x1e))) == 0) && ((*((u16 *) (((char *) D_800C35A0) + 0xe))) == 1)) && (((*((u16 *) (((char *) D_800C811C) + 4))) == 3) & (type == 2))) && (((u32) (v + 100)) > 200))
          {
            b[0] = 0;
            b[1] = 0;
            b[2] = 0;
            particle = func_8002EB34(manager, effect, b);
            if (effect) { *((s16 *) (((char *) particle) + 4)) = x; } else { *((s16 *) (((char *) particle) + 4)) = x; }
            *((s16 *) (((char *) particle) + 6)) = y;
            *((s16 *) (((char *) particle) + 8)) = z;
            continue;
          }

          if (((u32) (v + 2000)) <= 4000)
          {
            continue;
          }
          switch (type)
          {
            case 6:
              effect = (D_8009EB80 == 7) ? (1) : (4);
              a[0] = 0;
              a[1] = 0;
              a[2] = -256;
              func_8002E514((*((char **) (((char *) obj) + 0x5c))) + 0x40, a, a);
              goto velocity_scale;

            case 4:
              effect = (D_8009EB80 == 3) ? (4) : (1);
              break;

            case 5:

            case 8:
              effect = 1;
              break;

            case 7:
              effect = 3;
              break;

            case 9:
              effect = 2;
              break;

            case 10:
              effect = 1;
              continue;

            case 2:

            case 3:

            case 11:
              effect = 0;
              break;

            default:
              continue;

          }

          goto zero_velocity;
          velocity_scale:
          if (v > 0)
          {
            func_8002D3AC(a, a, 0, v, b);
            goto emit_particle;
          }

          zero_velocity:
          b[0] = 0;

          b[1] = 0;
          b[2] = 0;
          emit_particle:
          particle = func_8002EB34(manager, effect, b);

          *((s16 *) (((char *) particle) + 4)) = x;
          *((s16 *) (((char *) particle) + 6)) = y;
          *((s16 *) (((char *) particle) + 8)) = z;
        }

        {
          int five;
          for (i = 0; i < 4; i++)
          {
            if ((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x310 + (i * 4))))) >= 0)
            {
              if (manager->flags[i]) { manager->flags[i] = 0; } goto next_flag;
            }
            v = *((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + (0x1dc + (i * 4))));
            if ((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x320 + (i * 4))))) == 2)
            {
              extra = (v < 0) ? (-v) : (v);
              *((int *) (((char *) (*((char **) (((char *) obj) + 0x68)))) + (8 + (i * 4)))) = extra;
            }
            else
            {
              *((int *) (((char *) (*((char **) (((char *) obj) + 0x68)))) + (8 + (i * 4)))) = 0;
            }
            if ((((!(((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x320 + (i * 4))))) == D_8009D6A8[D_8009EB80]) || ((D_8009EB80 == 1) && ((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x320 + (i * 4))))) == 4)))) && ((*((int *) (((char *) (*((char **) (((char *) obj) + 0x48)))) + 0))) < 4)) && (func_8001FEE8(obj) >= 76)) && ((D_8009EB80 != 3) & (D_8009EB80 != 7)))
            {
              func_8002FBD4(obj, 65, 2);
            }
            if (((u32) (v + 2000)) > 4000)
            {
              if (!(((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x320 + (i * 4))))) == D_8009D6A8[D_8009EB80]) || ((D_8009EB80 == 1) && ((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x320 + (i * 4))))) == 4))))
              {
                goto clear_flag;
              }
              five = i * 5; new_var3 = five; new_var3 += five;
              contact = manager->contacts;
              contact += manager->head * 36;
              {
                a[0] = *((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + ((0x8c + (i * 40)) + (0 * 4))));
                a[1] = *((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + ((0x8c + (i * 40)) + (1 * 4))));
                a[2] = *((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + ((0x8c + (i * 40)) + (2 * 4))));
              }
              func_8002E514((*((char **) (((char *) obj) + 0x5c))) + 0x40, a, b);
              {
                wx = (*((int *) (((char *) contact) + (0 * 4))) = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x5c)))) + (0x54 + (0 * 4))))) + b[0]);
                wy = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x5c)))) + (0x54 + (1 * 4))))) + b[1];
                *((int *) (((char *) contact) + (1 * 4))) = wy;
                wz = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x5c)))) + (0x54 + (2 * 4))))) + b[2];
                *((int *) (((char *) contact) + (2 * 4))) = wz;
              }
              *((s16 *) (((char *) contact) + 0x12)) = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + (0x12c + (i * 40))))) - wx;
              *((s16 *) (((char *) contact) + 0x14)) = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + (0x130 + (i * 40))))) - wy;
              *((s16 *) (((char *) contact) + 0x16)) = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + (0x134 + (i * 40))))) - wz;
              new_var3 += 5;
              new_var3 *= 4;
              {
                a[0] = *((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + ((0x8c + new_var3) + (0 * 4))));
                a[1] = *((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + ((0x8c + new_var3) + (1 * 4))));
                a[2] = *((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + ((0x8c + new_var3) + (2 * 4))));
              }
              func_8002E514((*((char **) (((char *) obj) + 0x5c))) + 0x40, a, c);
              {
                new_var = (u16)(c[0]); extra = (u16)(b[0]); *((s16 *) (((char *) contact) + (12 + (0 * 2)))) = new_var - extra;
                new_var = (u16)(c[1]); extra = (u16)(b[1]); *((s16 *) (((char *) contact) + (12 + (1 * 2)))) = new_var - extra;
                new_var = (u16)(c[2]); extra = (u16)(b[2]); *((s16 *) (((char *) contact) + (12 + (2 * 2)))) = new_var - extra;
                *((s16 *) (((char *) contact) + (24 + (0 * 2)))) = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + ((0x12c + new_var3) + (0 * 4))))) - wx;
                *((s16 *) (((char *) contact) + (24 + (1 * 2)))) = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + ((0x12c + new_var3) + (1 * 4))))) - wy;
                *((s16 *) (((char *) contact) + (24 + (2 * 2)))) = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + ((0x12c + new_var3) + (2 * 4))))) - wz;
              }
              *((int *) (((char *) contact) + 32)) |= 1;
              manager->flags[i] = 1;
              new_var = (*((s16 *) (((char *) contact) + 24))); extra = (*((s16 *) (((char *) contact) + 12))); world[0] = new_var - extra;
              new_var = (*((s16 *) (((char *) contact) + 26))); extra = (*((s16 *) (((char *) contact) + 14))); world[1] = new_var - extra;
              new_var = (*((s16 *) (((char *) contact) + 28))); extra = (*((s16 *) (((char *) contact) + 16))); world[2] = new_var - extra;
              func_8002E778(world, world);
              world[0] = world[0] + (world[1] + world[2]);
              trigger = manager->threshold < world[0];
              if (trigger)
              {
                manager->flags[i] = 0;
                manager->head++;
                if (manager->head == manager->capacity)
                {
                  manager->head = 0;
                }
              }
            }
            else
            {
              trigger = manager->flags[i];
              if (trigger)
              {
                manager->flags[i] = 0;
                manager->head++;
                if (manager->head == manager->capacity)
                {
                  manager->head = 0;
                }
              }
            }
            goto next_flag;
            clear_flag:
            if (manager->flags[i])
            {
              manager->flags[i] = 0;
            }

            next_flag:
            ;

            ;
          }

        }
        for (i = 0; i < 4; i++)
        {
          if (!manager->flags[i])
          {
            for (n = 0; n < 2; n++)
            {
              {
                a[0] = ((s32 *) (*((char **) (((char *) obj) + 0x64))))[((0x23 + (i * 10)) + (n * 5)) + 0];
                a[1] = ((s32 *) (*((char **) (((char *) obj) + 0x64))))[((0x23 + (i * 10)) + (n * 5)) + 1];
                a[2] = ((s32 *) (*((char **) (((char *) obj) + 0x64))))[((0x23 + (i * 10)) + (n * 5)) + 2];
              }
              func_8002E514((*((char **) (((char *) obj) + 0x5c))) + 0x40, a, b);
              {
                ((s32 *) (*((char **) (((char *) obj) + 0x64))))[((0x4b + (i * 10)) + (n * 5)) + 0] = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x5c)))) + (0x54 + (0 * 4))))) + b[0];
                ((s32 *) (*((char **) (((char *) obj) + 0x64))))[((0x4b + (i * 10)) + (n * 5)) + 1] = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x5c)))) + (0x54 + (1 * 4))))) + b[1];
                ((s32 *) (*((char **) (((char *) obj) + 0x64))))[((0x4b + (i * 10)) + (n * 5)) + 2] = (*((int *) (((char *) (*((char **) (((char *) obj) + 0x5c)))) + (0x54 + (2 * 4))))) + b[2];
              }
            }

          }
        }

        func_8002EC5C(obj, manager, snapshot);
        *((int *) (((char *) snapshot) + 0x14)) = *((int *) (((char *) (*((char **) (((char *) obj) + 0x5c)))) + 0x54));
        *((int *) (((char *) snapshot) + 0x18)) = *((int *) (((char *) (*((char **) (((char *) obj) + 0x5c)))) + 0x58));
        *((int *) (((char *) snapshot) + 0x1c)) = *((int *) (((char *) (*((char **) (((char *) obj) + 0x5c)))) + 0x5c));
      }

    }
    while (0);
  }
  else
  {
    for (; obj; obj = *((char **) (((char *) obj) + 4)))
    {
      for (i = 0; i < 4; i++)
      {
        if ((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x310 + (i * 4))))) < 0)
        {
          v = *((int *) (((char *) (*((char **) (((char *) obj) + 0x64)))) + (0x1dc + (i * 4))));
          if ((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x320 + (i * 4))))) == 2)
          {
            extra = (v < 0) ? (-v) : (v);
            *((int *) (((char *) (*((char **) (((char *) obj) + 0x68)))) + (8 + (i * 4)))) = extra;
          }
          else
          {
            *((int *) (((char *) (*((char **) (((char *) obj) + 0x68)))) + (8 + (i * 4)))) = 0;
          }
          if ((((u32) (v + 2000)) > 4000) && ((*((int *) (((char *) (*((char **) (((char *) obj) + 0x80)))) + (0x320 + (i * 4))))) == 2))
          {
            func_8002FBD4(obj, 130, 2);
          }
        }
      }

    }

  }
}


