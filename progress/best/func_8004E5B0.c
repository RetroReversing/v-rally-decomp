#define U(p,o) (*(u16*)((char*)(p)+(o)))
#define B(p,o) (*(u8*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(s16*)((char*)(p)+(o)))
typedef struct { u16 v0, v1, v2, v3; } BS;
extern int D_8009EB80;
u8 func_800308EC(void *, int);
void func_8004E554(void *);
int func_8004E5B0(char *a, BS *b)
{
  u8 changed = 0;
  int high = 800;
  int low = 200;
  u8 special;
  int f;
  b->v1 = 0;
  special = 0;
  if (((U(a, 0x8c) != 15) & (U(a, 0x8c) != 22)) && (U(a, 0x8c) != 28))
  {
    f = U(a, 10);
    if (f & 8) { special = 1; b->v1 = 1; b->v0 = 2; }
    else if (f & 4) { special = 1; b->v0 = (b->v1 = 2); }
    else if (f & 16) { special = 1; b->v0 = (b->v1 = 6); }
    else if (f & 64) { b->v0 = (b->v1 = 6); }
    else if (f & 32) { special = 1; b->v0 = 6; b->v1 = 9; }
  }
  if (!b->v1)
  {
    switch (U(a, 0x8c))
    {
      case 9: b->v1 = 1; b->v0 = 1; b->v3 = 0; break;
      case 10:
        b->v1 = 1; b->v0 = 0; b->v3 = 1;
        if (((D_8009EB80 == 2) || (D_8009EB80 == 7)) || (D_8009EB80 == 5)) b->v0 = 1;
        break;
      case 11:
        b->v1 = 1; b->v0 = 1; b->v3 = 1;
        if (D_8009EB80 == 1) low = 460;
        break;
      case 12: b->v1 = 1; b->v0 = 1; b->v3 = 1; break;
      case 13:
        b->v1 = 1; b->v0 = 1; b->v3 = 0;
        if (D_8009EB80 == 0) low = 280;
        break;
      case 14: b->v1 = 1; b->v0 = 1; b->v3 = 1; break;
      case 15: b->v1 = 1; b->v0 = 2; b->v3 = 0; break;
      case 16: b->v1 = 1; b->v0 = 1; b->v3 = 0; break;
      case 17:
        b->v1 = 2; b->v0 = 1;
        if ((D_8009EB80 == 5) || (D_8009EB80 == 1)) b->v0 = 0;
        if (D_8009EB80 == 6) low = 140;
        b->v3 = 1;
        break;
      case 18:
        b->v1 = 1; b->v0 = 0;
        if (D_8009EB80 == 5) high = 650;
        if (D_8009EB80 == 0) high = 600;
        if (D_8009EB80 == 6) high = 650;
        b->v3 = 1;
        break;
      case 19:
        b->v1 = 1; b->v0 = 0; b->v3 = 2;
        if (D_8009EB80 == 5) { b->v1 = 0; b->v0 = 0; b->v3 = 0; }
        if (((D_8009EB80 == 6) || (D_8009EB80 == 4)) || (D_8009EB80 == 7)) { b->v1 = 4; b->v0 = 4; b->v3 = 2; }
        break;
      case 20: b->v1 = 1; b->v0 = 1; b->v3 = 1; break;
      case 21: b->v1 = 1; b->v0 = 2; b->v3 = 2; break;
      case 22:
        b->v1 = 2; b->v0 = 0; b->v3 = 0;
        if (D_8009EB80 == 1) b->v0 = 1;
        if (D_8009EB80 == 6) high = 1100;
        if (D_8009EB80 == 7) { b->v0 = 1; low = 190; }
        break;
      case 23:
        b->v1 = 1; b->v0 = 0; b->v3 = 0;
        if (D_8009EB80 == 6) high = 1100;
        if (D_8009EB80 == 1) high = 1230;
        if (D_8009EB80 == 7) b->v0 = 1;
        if (D_8009EB80 == 5) high = 609;
        break;
      case 24: b->v1 = 1; b->v0 = 0; b->v3 = 2; break;
      case 25: b->v1 = 4; b->v0 = 4; b->v3 = 2; break;
      case 26:
      case 27: b->v1 = 1; b->v0 = 0; b->v3 = 0; break;
      case 30: b->v1 = 1; b->v0 = 0; b->v3 = 0; break;
      default:
        if (!b->v1) { b->v1 = 0; b->v0 = 0; b->v3 = 0; }
        break;
    }
  }
  if (B(a, 0x92) == 77)
  {
    b->v1 = 6; b->v0 = 6; b->v3 = 1;
    if (func_800308EC(a, 0) == 2) { b->v1 = 3; b->v0 = 3; }
    special = func_800308EC(a, 9);
    if (special == 2) { b->v1 = 8; b->v0 = 6; }
    if ((D_8009EB80 == 1) && (U(a, 0x8c) == 1)) { b->v1 = 0; b->v0 = 0; b->v3 = 0; }
    if ((D_8009EB80 == 5) && ((U(a, 0x8c) == 17) || (U(a, 0x8c) == 1))) { b->v1 = 0; b->v0 = 0; b->v3 = 0; }
    if ((D_8009EB80 == 6) && (U(a, 0x8c) == 20)) { b->v1 = 0; b->v0 = 0; b->v3 = 0; }
  }
  if ((b->v1 != 0) & (!special))
  {
    if (U(a, 10) & 0x100) func_8004E554(b);
    if (b->v0 == 0)
    {
      if (b->v3 == 0)
      {
        if ((H(P(a, 0x78), 0) > high) && (b->v1 == 2)) { b->v0++; changed = 1; }
        else if ((H(P(a, 0x78), 2) > high) && (b->v1 == 1)) { b->v0++; changed = 1; }
      }
      else if ((b->v3 == 1) && P(a, 0x58))
      {
        if ((H(P(P(a, 0x58), 0x78), 0) > high) && (b->v1 == 2)) { b->v0++; changed = 1; }
        else if ((H(P(P(a, 0x58), 0x78), 2) > high) && (b->v1 == 1)) { b->v0++; changed = 1; }
      }
    }
    if ((b->v0 == 1) & (!changed))
    {
      if (b->v3 == 0)
      {
        if ((H(P(a, 0x78), 2) > low) && (b->v1 == 2)) b->v0--;
        else if ((H(P(a, 0x78), 0) > low) && (b->v1 == 1)) b->v0--;
      }
      else if ((b->v3 == 1) && P(a, 0x58))
      {
        if ((H(P(P(a, 0x58), 0x78), 2) > low) && (b->v1 == 2)) b->v0--;
        else if ((H(P(P(a, 0x58), 0x78), 0) > low) && (b->v1 == 1)) b->v0--;
      }
    }
  }
  return special;
}
