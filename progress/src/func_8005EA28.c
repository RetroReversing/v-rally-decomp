/* Copies two name templates into a local frame, clears the padding, resolves the path, then
 * stamps the digits 1..8 into each template in turn and passes it to func_8004C7F0. */
typedef struct {
    u8 b[13];
} Buf13;

typedef struct {
    u8 b[14];
} Buf14;

typedef struct {
    Buf13 a;
    u8 c[3];
    Buf14 d;
    u8 e[2];
} Frame;

extern Buf13 D_800A54B4;
extern Buf14 D_800A54C4;
extern char aTexPackDir[];
void memset(void *, s32, s32);
void func_8004C7F0(void *);
void resolve_path(void *);

void func_8005EA28(void) {
    Frame frame;
    s32 digit;

    frame.a = D_800A54B4;
    memset(frame.c, 0, 3);
    frame.d = D_800A54C4;
    memset(frame.e, 0, 2);
    resolve_path(aTexPackDir);
    digit = 1;
    do {
        frame.a.b[7] = digit + 0x30;
        func_8004C7F0(&frame.a);
        digit++;
    } while ((u8)digit < 9);
    digit = 1;
    do {
        frame.d.b[8] = digit + 0x30;
        func_8004C7F0(&frame.d);
        digit++;
    } while ((u8)digit < 9);
}
