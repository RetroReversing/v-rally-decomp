#define W(p,o) (*(int *)((char *)(p)+(o)))
#define P(p,o) (*(char **)((char *)(p)+(o)))
#define H(p,o) (*(s16 *)((char *)(p)+(o)))
#define U(p,o) (*(u16 *)((char *)(p)+(o)))
#define B(p,o) (*(u8 *)((char *)(p)+(o)))
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
void func_8002E514(void *, void *, void *);
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
  int sq[3];
  char *obj;
  int new_var3;
  char *manager;
  char *snapshot;
  char *particle;
  char *contact;
  char *flags;
  unsigned i;
  unsigned n;
  int effect = 0;
  int velocity;
  int type;
  int x;
  int z;
  int y;
  int j;
  long v;
  int extra;
  volatile int trigger;
  int world[3];
  func_8002FD68();
  obj = P(list, 0);
  if (U(D_800C35A0, 0xe) < 3)
  {
    do
    {
      for (; obj; obj = P(obj, 4))
      {
        snapshot = P(obj, 0x38) + 12;
        manager = P(P(obj, 0x38), 0);
        velocity = W(P(obj, 0x58), 0);
        for (i = D_800AFA6C & 1; i < 4; i += 2)
        {
          if (W(P(obj, 0x80), 0x310 + (i * 4)) >= 0)
          {
            continue;
          }
          type = W(P(obj, 0x80), 0x320 + (i * 4));
          v = W(P(obj, 0x64), 0x1dc + (i * 4));
          x = W(P(obj, 0x80), 0x100 + (i * 20));
          z = W(P(obj, 0x80), 0x108 + (i * 20));
          y = W(P(obj, 0x80), 4) + 30;
          switch (type)
          {
            case 4:
              effect = 3;
              break;

            case 5:
              effect = (D_8009EB80 == 7) ? (1) : (4);
              break;

            case 6:
              effect = (D_8009EB80 == 3) ? (4) : (1);
              break;

            case 7:

            case 8:

            case 9:

            case 10:

            case 11:
              effect = 2;
              break;

            default:
              goto special;

          }

          if ((velocity > 1000) && (D_800AFA6C & 2))
          {
            func_800980C4(osGetTime());
            a[0] = (a[1] = (a[2] = 0));
            particle = func_8002EB34(manager, effect, a);
            new_var2 = func_80098090();
            H(particle, 6) = y;
            H(particle, 4) = (x + (new_var2 % 31)) - 15;
            H(particle, 8) = (z + (func_80098090() % 31)) - 15;
          }
          special:
          if ((((U(D_800C35A0, 0x1e) == 0) && (U(D_800C35A0, 0xe) == 1)) && ((U(D_800C811C, 4) == 3) & (type == 2))) && (((u32) (v + 100)) > 200))
          {
            a[0] = (a[1] = (a[2] = 0));
            particle = func_8002EB34(manager, effect, a);
            H(particle, 4) = x;
            H(particle, 6) = y;
            H(particle, 8) = z;
            continue;
          }

          if (((u32) (v + 2000)) <= 4000)
          {
            continue;
          }
          trigger = 0;
          switch (type)
          {
            case 2:
              effect = (D_8009EB80 == 7) ? (1) : (4);
              a[0] = (a[1] = 0);
              a[2] = -256;
              func_8002E514(P(obj, 0x5c) + 0x40, a, a);
              trigger = 1;
              break;

            case 3:
              effect = (D_8009EB80 == 3) ? (4) : (1);
              break;

            case 4:
              effect = 1;
              break;

            case 5:
              effect = 3;
              break;

            case 6:
              effect = 2;
              break;

            case 7:
              effect = 1;
              continue;

            case 8:
              effect = 0;
              break;

            default:
              continue;

          }

          if (trigger && (v > 0))
          {
            func_8002D3AC(a, a, 0, v, b);
          }
          else
          {
            b[0] = (b[1] = (b[2] = 0));
          }
          particle = func_8002EB34(manager, effect, b);
          H(particle, 4) = x;
          H(particle, 6) = y;
          H(particle, 8) = z;
        }

        flags = manager;
        for (i = 0; i < 4; i++, flags++)
        {
          if (W(P(obj, 0x80), 0x310 + (i * 4)) >= 0)
          {
            if (B(flags, 6))
            {
              B(flags, 6) = 0;
            }
            continue;
          }
          type = W(P(obj, 0x80), 0x320 + (i * 4));
          v = W(P(obj, 0x64), 0x1dc + (i * 4));
          W(P(obj, 0x68), 8 + (i * 4)) = (type == 2) ? ((v < 0) ? (-v) : (v)) : (0);
          trigger = type == 4;
          trigger = (type == D_8009D6A8[D_8009EB80]) || ((D_8009EB80 == 1) && trigger);
          if ((((!trigger) && (W(P(obj, 0x48), 0) < 4)) && ((func_8001FEE8(obj) + 1) > 76)) && ((D_8009EB80 != 3) & (D_8009EB80 != 7)))
          {
            func_8002FBD4(obj, 65, 2);
          }
          if (((u32) (v + 2000)) > 4000)
          {
            if (!trigger)
            {
              if (B(flags, 6))
              {
                B(flags, 6) = 0;
              }
              continue;
            }
            contact = P(manager, 0) + (U(manager, 0x18) * 36);
            new_var3 = (0x12c + (i * 40)) + 20;
            {
              a[0] = W(P(obj, 0x64), (0x8c + (i * 40)) + (0 * 4));
              a[1] = W(P(obj, 0x64), (0x8c + (i * 40)) + (1 * 4));
              a[2] = W(P(obj, 0x64), (0x8c + (i * 40)) + (2 * 4));
            }
            func_8002E514(P(obj, 0x5c) + 0x40, a, b);
            {
              world[0] = W(P(obj, 0x5c), 0x54 + (0 * 4)) + b[0];
              W(contact, 0 * 4) = world[0];
              world[1] = W(P(obj, 0x5c), 0x54 + (1 * 4)) + b[1];
              W(contact, 1 * 4) = world[1];
              world[2] = W(P(obj, 0x5c), 0x54 + (2 * 4)) + b[2];
            }
            H(contact, 0x12) = W(P(obj, 0x64), 0x12c + (i * 40)) - world[0];
            H(contact, 0x14) = W(P(obj, 0x64), 0x130 + (i * 40)) - world[1];
            H(contact, 0x16) = W(P(obj, 0x64), 0x134 + (i * 40)) - world[2];
            {
              a[0] = W(P(obj, 0x64), ((0x8c + (i * 40)) + 20) + (0 * 4));
              a[1] = W(P(obj, 0x64), ((0x8c + (i * 40)) + 20) + (1 * 4));
              a[2] = W(P(obj, 0x64), ((0x8c + (i * 40)) + 20) + (2 * 4));
            }
            W(contact, 2 * 4) = world[2];
            func_8002E514(P(obj, 0x5c) + 0x40, a, c);
            {
              H(contact, 12 + (0 * 2)) = c[0] - b[0];
              H(contact, 24 + (0 * 2)) = W(P(obj, 0x64), new_var3 + (0 * 4)) - world[0];
              H(contact, 12 + (1 * 2)) = c[1] - b[1];
              H(contact, 12 + (2 * 2)) = c[2] - b[2];
              H(contact, 24 + (1 * 2)) = W(P(obj, 0x64), new_var3 + (1 * 4)) - world[1];
              H(contact, 24 + (2 * 2)) = W(P(obj, 0x64), new_var3 + (2 * 4)) - world[2];
            }
            W(contact, 32) |= 1;
            B(flags, 6) = 1;
            new_var = 1 * 2;
            {
              sq[2] = H(contact, 24 + (2 * 2)) - H(contact, 12 + (2 * 2));
              sq[0] = H(contact, 24 + (0 * 2)) - H(contact, 12 + (0 * 2));
              sq[1] = H(contact, 24 + new_var) - H(contact, 12 + new_var);
            }
            func_8002E778(sq, sq);
            sq[0] += sq[1] + sq[2];
            trigger = U(manager, 4) < sq[0];
          }
          else
          {
            trigger = B(flags, 6);
          }
          if (trigger)
          {
            B(flags, 6) = 0;
            U(manager, 0x18)++;
            if (U(manager, 0x18) == U(manager, 0x14))
            {
              U(manager, 0x18) = 0;
            }
          }
        }

        for (i = 0; i < 4; i++)
        {
          if (!B(manager, 6 + i))
          {
            for (n = 0; n < 2; n++)
            {
              {
                a[0] = W(P(obj, 0x64), ((0x8c + (i * 40)) + (n * 20)) + (0 * 4));
                a[1] = W(P(obj, 0x64), ((0x8c + (i * 40)) + (n * 20)) + (1 * 4));
                a[2] = W(P(obj, 0x64), ((0x8c + (i * 40)) + (n * 20)) + (2 * 4));
              }
              func_8002E514(P(obj, 0x5c) + 0x40, a, b);
              {
                W(P(obj, 0x64), ((0x12c + (i * 40)) + (n * 20)) + (0 * 4)) = W(P(obj, 0x5c), 0x54 + (0 * 4)) + b[0];
                W(P(obj, 0x64), ((0x12c + (i * 40)) + (n * 20)) + (1 * 4)) = W(P(obj, 0x5c), 0x54 + (1 * 4)) + b[1];
                W(P(obj, 0x64), ((0x12c + (i * 40)) + (n * 20)) + (2 * 4)) = W(P(obj, 0x5c), 0x54 + (2 * 4)) + b[2];
              }
            }

          }
        }

        func_8002EC5C(obj, manager, snapshot);
        W(snapshot, 0x14) = W(P(obj, 0x5c), 0x54);
        W(snapshot, 0x18) = W(P(obj, 0x5c), 0x58);
        W(snapshot, 0x1c) = W(P(obj, 0x5c), 0x5c);
      }

    }
    while (0);
  }
  else
  {
    for (; obj; obj = P(obj, 4))
    {
      for (i = 0; i < 4; i++)
      {
        if (W(P(obj, 0x80), 0x310 + (i * 4)) < 0)
        {
          v = W(P(obj, 0x64), 0x1dc + (i * 4));
          type = W(P(obj, 0x80), 0x320 + (i * 4));
          W(P(obj, 0x68), 8 + (i * 4)) = (type == 2) ? ((v < 0) ? (-v) : (v)) : (0);
          if ((((u32) (v + 2000)) > 4000) && (type == 2))
          {
            func_8002FBD4(obj, 130, 2);
          }
        }
      }

    }

  }
}
