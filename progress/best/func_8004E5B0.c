#define U(p,o) (*(u16*)((char*)(p)+(o)))
#define B(p,o) (*(u8*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(s16*)((char*)(p)+(o)))
extern int D_8009EB80;
u8 func_800308EC(void *, int);
void func_8004E554(void *);
int func_8004E5B0(char *a, u16 *b)
{
  u8 changed = 0;
  int dummy_changed_unused = 0;
  int high = 800;
  int low = 200;
  u8 special = 0;
  int t;
  int f;
  b[1] = 0;
  t = U(a, 0x8c);
  if (((t != 15) & (t != 22)) && (t != 28))
  {
    f = U(a, 10);
    if (f & 8)
    {
      special = 1;
      b[1] = 1;
      b[0] = 2;
    }
    else
      if (f & 4)
    {
      special = 1;
      b[0] = (b[1] = 2);
    }
    else
      if (f & 16)
    {
      special = 1;
      goto six;
    }
    else
      if (f & 64)
    {
      six:
      b[0] = (b[1] = 6);

    }
    else
    {
      if (f & 32)
      {
        special = 1;
        b[0] = 6;
        b[1] = 9;
      }
      if (1)
      {
      }
    }
  }
  if (!b[1])
  {
    switch (U(a, 0x8c))
    {
      case 9:
        b[1] = (b[0] = 1);
        b[3] = 0;
        break;

      case 10:
        b[1] = 1;
        b[0] = 0;
        b[3] = 1;
        if (((D_8009EB80 == 2) || (D_8009EB80 == 7)) || (D_8009EB80 == 5))
      {
        b[0] = 1;
      }
        break;

      case 11:
        b[3] = (b[0] = (b[1] = 1));
        if (D_8009EB80 == 1)
      {
        low = 460;
      }
        break;

      case 12:
        b[0] = (b[1] = (b[3] = 1));
        break;

      case 13:
        b[1] = (b[0] = 1);
        b[3] = 0;
        if (D_8009EB80 == 0)
      {
        low = 280;
      }
        break;

      case 14:
        b[1] = (b[0] = (b[3] = 1));
        break;

      case 15:
        b[1] = 1;
        b[0] = 2;
        b[3] = 0;
        break;

      case 16:
        b[1] = (b[0] = 1);
        b[3] = 0;
        break;

      case 17:
        b[1] = 2;
        if ((D_8009EB80 == 5) || (D_8009EB80 == 1))
      {
        b[0] = 0;
        b[0] = 1;
      }
        if (D_8009EB80 == 6)
      {
        low = 140;
      }
        b[3] = 1;
        break;

      case 18:
        b[1] = 1;
        b[0] = 0;
        if (D_8009EB80 == 5)
      {
        high = 650;
      }
        if (D_8009EB80 == 0)
      {
        high = 600;
      }
        if (D_8009EB80 == 6)
      {
        high = 650;
      }
        b[3] = 1;
        break;

      case 19:
        b[1] = 1;
        high = 0;
        b[0] = high;
        b[3] = 2;
        if (D_8009EB80 == 5)
      {
        b[1] = (b[0] = (b[3] = 0));
      }
        if (((D_8009EB80 == 6) || (D_8009EB80 == 4)) || (D_8009EB80 == 7))
      {
        b[1] = (b[0] = 4);
        b[3] = 2;
      }
        break;

      case 20:
        b[1] = (b[0] = (b[3] = 1));
        break;

      case 21:
        b[1] = 1;
        b[0] = (b[3] = 2);
        break;

      case 22:
        b[1] = 2;
        b[0] = 0;
        b[3] = 0;
        if (D_8009EB80 == 1)
      {
        b[0] = 1;
      }
        if (D_8009EB80 == 6)
      {
        high = 1100;
      }
        if (D_8009EB80 == 7)
      {
        b[0] = 1;
        low = 190;
      }
        break;

      case 23:
        b[1] = 1;
        b[0] = 0;
        b[3] = 0;
        if (D_8009EB80 == 6)
      {
        high = 1100;
      }
        if (D_8009EB80 == 1)
      {
        high = 1230;
      }
        if (D_8009EB80 == 7)
      {
        b[0] = 1;
      }
        if (D_8009EB80 == 5)
      {
        high = 609;
      }
        break;

      case 24:
        b[1] = 1;
        b[0] = 0;
        b[3] = 2;
        break;

      case 25:
        b[0] = (b[1] = 4);
        b[3] = 2;
        break;

      case 26:

      case 27:
        b[1] = 1;
        b[0] = (b[3] = 0);
        break;

      case 30:
        b[1] = (b[0] = 1);
        break;

      default:
        b[0] = (b[1] = (b[3] = 0));
        break;

    }

  }
  if (B(a, 0x92) == 77)
  {
    b[0] = (b[1] = 6);
    b[3] = 1;
    if (func_800308EC(a, 0) == 2)
    {
      b[0] = (b[1] = 3);
    }
    special = func_800308EC(a, 9);
    if (special == 2)
    {
      b[1] = 8;
      b[0] = 6;
    }
    if ((D_8009EB80 == 1) && (U(a, 0x8c) == 1))
    {
      if (low)
      {
        b[1] = (b[0] = (b[3] = 0));
      }
      else
      {
        b[1] = (b[0] = (b[3] = 0));
      }
    }
    if ((D_8009EB80 == 5) && ((U(a, 0x8c) == 17) || (U(a, 0x8c) == 1)))
    {
      b[1] = (b[0] = (b[3] = 0));
    }
    if ((D_8009EB80 == 6) && (U(a, 0x8c) == 20))
    {
      b[1] = (b[0] = (b[3] = 0));
    }
  }
  if (b[1] && (!special))
  {
    if (U(a, 10) & 256)
    {
      func_8004E554(b);
    }
    if (b[0] == 0)
    {
      if (b[3] == 0)
      {
        if ((H(P(a, 0x78), 0) > high) && (b[1] == 2))
        {
          b[0]++;
          changed = 1;
        }
        else
          if ((H(P(a, 0x78), 2) > high) && (b[1] == 1))
        {
          b[0]++;
          changed = 1;
        }
      }
      else
        if ((b[3] == 1) && P(a, 0x58))
      {
        if ((H(P(P(a, 0x58), 0x78), 0) > high) && (b[1] == 2))
        {
          b[0]++;
          changed = 1;
        }
        else
          if ((H(P(P(a, 0x58), 0x78), 2) > high) && (b[1] == 1))
        {
          b[0]++;
          changed = 1;
        }
      }
    }
    if ((b[0] == 1) & (!changed))
    {
      if (b[3] == 0)
      {
        if ((H(P(a, 0x78), 2) > low) && (b[1] == 2))
        {
          b[0]--;
        }
        else
          if ((H(P(a, 0x78), 0) > low) && (b[1] == 1))
        {
          b[0]--;
        }
      }
      else
        if ((b[3] == 1) && P(a, 0x58))
      {
        if ((H(P(P(a, 0x58), 0x78), 2) > low) && (b[1] == 2))
        {
          b[0]--;
        }
        else
          if ((H(P(P(a, 0x58), 0x78), 0) > low) && (b[1] == 1))
        {
          b[0]--;
        }
      }
    }
  }
  return special;
}

