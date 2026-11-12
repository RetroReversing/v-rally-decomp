#define U(p,o) (*(u16*)((char*)(p)+(o)))
#define B(p,o) (*(u8*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(s16*)((char*)(p)+(o)))
typedef struct 
{
  u16 v0;
  u16 v1;
  u16 v2;
  u16 v3;
} BS;
extern int gSnapIndex;
u8 func_800308EC(void *, int);
void func_8004E554(void *);
/* Chooses the four-halfword state in 'out' for an object from its type code (offset 0x8c), flags (offset 10) and the current snap index, then nudges v0 up or down by comparing the neighbouring speeds. */ int func_8004E5B0(char *obj, BS *out)
{
  u8 adjusted = 0;
  int high_limit = 800;
  int low_limit = 200;
  u8 special_case;
  int flags;
  out->v1 = 0;
  special_case = 0;
  if (((U(obj, 0x8c) != 15) & (U(obj, 0x8c) != 22)) && (U(obj, 0x8c) != 28))
  {
    flags = U(obj, 10);
    if (flags & 8)
    {
      special_case = 1;
      out->v1 = 1;
      out->v0 = 2;
    }
    else
      if (flags & 4)
    {
      special_case = 1;
      out->v0 = (out->v1 = 2);
    }
    else
      if (flags & 16)
    {
 do { special_case = 1; } while (0);
      out->v0 = (out->v1 = 6);
    }
    else
      if (flags & 64)
    {
      out->v0 = (out->v1 = 6);
    }
    else
      if (flags & 32)
    {
      special_case = 1;
      out->v0 = 6;
      out->v1 = 9;
    }
  }
  if (!out->v1)
  {
    switch (U(obj, 0x8c))
    {
      case 9:
        out->v1 = 1;
        out->v0 = 1;
        out->v3 = 0;
        break;

      case 10:
        out->v1 = 1;
        out->v0 = 0;
        out->v3 = 1;
        if (((gSnapIndex == 2) || (gSnapIndex == 7)) || (gSnapIndex == 5))
      {
        out->v0 = 1;
      }
        break;

      case 11:
        out->v1 = 1;
        out->v0 = 1;
        out->v3 = 1;
        if (gSnapIndex == 1)
      {
        low_limit = 460;
      }
        break;

      case 12:
        out->v1 = 1;
        out->v0 = 1;
        out->v3 = 1;
        break;

      case 13:
        out->v1 = 1;
        out->v0 = 1;
        out->v3 = 0;
        if (gSnapIndex == 0)
      {
        low_limit = 280;
      }
        break;

      case 14:
        out->v1 = 1;
        out->v0 = 1;
        out->v3 = 1;
        break;

      case 15:
        out->v1 = 1;
        out->v0 = 2;
        out->v3 = 0;
        break;

      case 16:
        out->v1 = 1;
        out->v0 = 1;
        out->v3 = 0;
        break;

      case 17:
        out->v1 = 2;
        out->v0 = 1;
        if ((gSnapIndex == 5) || (gSnapIndex == 1))
      {
        out->v0 = 0;
      }
        if (gSnapIndex == 6)
      {
        low_limit = 140;
      }
        out->v3 = 1;
        break;

      case 18:
        out->v1 = 1;
        out->v0 = 0;
        if (gSnapIndex == 5)
      {
        high_limit = 650;
      }
        if (gSnapIndex == 0)
      {
        high_limit = 600;
      }
        if (gSnapIndex == 6)
      {
        high_limit = 650;
      }
        out->v3 = 1;
        break;

      case 19:
        out->v1 = 1;
        out->v0 = 0;
        out->v3 = 2;
        if (gSnapIndex == 5)
      {
        out->v1 = 0;
        out->v0 = 0;
        out->v3 = 0;
      }
        if (((gSnapIndex == 6) || (gSnapIndex == 4)) || (gSnapIndex == 7))
      {
        out->v1 = 4;
        out->v0 = 4;
        out->v3 = 2;
      }
        break;

      case 20:
        out->v1 = 1;
        out->v0 = 1;
        out->v3 = 1;
        break;

      case 21:
        out->v1 = 1;
        out->v0 = 2;
        out->v3 = 2;
        break;

      case 22:
        out->v1 = 2;
        out->v0 = 0;
        out->v3 = 0;
        if (gSnapIndex == 1)
      {
        out->v0 = 1;
      }
        if (gSnapIndex == 6)
      {
        high_limit = 1100;
      }
        if (gSnapIndex == 7)
      {
        out->v0 = 1;
        low_limit = 190;
      }
        break;

      case 23:
        out->v1 = 1;
        out->v0 = 0;
        out->v3 = 0;
        if (gSnapIndex == 6)
      {
        high_limit = 1100;
      }
        if (gSnapIndex == 1)
      {
        high_limit = 1230;
      }
        if (gSnapIndex == 7)
      {
        out->v0 = 1;
      }
        if (gSnapIndex == 5)
      {
        high_limit = 609;
      }
        break;

      case 24:
        out->v1 = 1;
        out->v0 = 0;
        out->v3 = 2;
        break;

      case 25:
        out->v1 = 4;
        out->v0 = 4;
        out->v3 = 2;
        break;

      case 26:

      case 27:
        out->v1 = 1;
        out->v0 = 0;
        out->v3 = 0;
        break;

      case 30:
        out->v1 = 1;
        out->v0 = 0;
        out->v3 = 0;
        break;

      default:
        if (!out->v1)
      {
        out->v1 = 0;
        out->v0 = 0;
        out->v3 = 0;
      }
        break;

    }

  }
  if (B(obj, 0x92) == 77)
  {
    out->v1 = 6;
    out->v0 = 6;
    out->v3 = 1;
    if (func_800308EC(obj, 0) == 2)
    {
      out->v1 = 3;
      out->v0 = 3;
    }
    special_case = func_800308EC(obj, 9);
    if (special_case == 2)
    {
      out->v1 = 8;
      out->v0 = 6;
    }
    if ((gSnapIndex == 1) && (U(obj, 0x8c) == 1))
    {
      out->v1 = 0;
      out->v0 = 0;
      out->v3 = 0;
    }
    if ((gSnapIndex == 5) && ((U(obj, 0x8c) == 17) || (U(obj, 0x8c) == 1)))
    {
      out->v1 = 0;
      out->v0 = 0;
      out->v3 = 0;
    }
    if ((gSnapIndex == 6) && (U(obj, 0x8c) == 20))
    {
      out->v1 = 0;
      out->v0 = 0;
      out->v3 = 0;
    }
  }
  if ((out->v1 != 0) & (!special_case))
  {
    if (U(obj, 10) & 0x100)
    {
      func_8004E554(out);
    }
    if (out->v0 == 0)
    {
      if (out->v3 == 0)
      {
        if ((H(P(obj, 0x78), 0) > high_limit) && (out->v1 == 2))
        {
          out->v0++;
          adjusted = 1;
        }
        else
          if ((H(P(obj, 0x78), 2) > high_limit) && (out->v1 == 1))
        {
          out->v0++;
          adjusted = 1;
        }
      }
      else
        if ((out->v3 == 1) && P(obj, 0x58))
      {
        if ((H(P(P(obj, 0x58), 0x78), 0) > high_limit) && (out->v1 == 2))
        {
          out->v0++;
          adjusted = 1;
        }
        else
          if ((H(P(P(obj, 0x58), 0x78), 2) > high_limit) && (out->v1 == 1))
        {
          out->v0++;
          adjusted = 1;
        }
      }
    }
    if ((out->v0 == 1) & (!adjusted))
    {
      if (out->v3 == 0)
      {
        if ((H(P(obj, 0x78), 2) > low_limit) && (out->v1 == 2))
        {
          out->v0--;
        }
        else
          if ((H(P(obj, 0x78), 0) > low_limit) && (out->v1 == 1))
        {
          out->v0--;
        }
      }
      else
        if ((out->v3 == 1) && P(obj, 0x58))
      {
        if ((H(P(P(obj, 0x58), 0x78), 2) > low_limit) && (out->v1 == 2))
        {
          out->v0--;
        }
        else
          if ((H(P(P(obj, 0x58), 0x78), 0) > low_limit) && (out->v1 == 1))
        {
          out->v0--;
        }
      }
    }
  }
  return special_case;
}
