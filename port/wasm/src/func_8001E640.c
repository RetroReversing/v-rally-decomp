/* Port-only C (WebAssembly build): written from the assembly so it behaves as the game does, not matching C.
 * The project still has this function open for agents to match. */
#include "common.h"
#include "gap.h"
/* port: prototypes follow the real callees, not m2c's guesses (a wasm call must match the callee's type):
 * 0x80098290 is strCpy(dst, src), 0x80098370 str_ncat(dst, src, n), 0x8008E118 str_len(s). The asm loads
 * $a1/$a2 before the str_len call, but str_len reads only $a0: they are leftovers, not arguments. */
u8 *strCpy(u8 *dst, u8 *src);
void *str_ncat(void *dst, void *src, s32 n);
s32 str_len(void *s);
extern s32 D_8009D540;
extern u8 D_800A16F0;
extern M2C_UNK D_800A47BC;
extern f64 D_800A4888;
extern f64 D_800A4890;
extern f64 D_800A4898;
extern f64 D_800A48A0;
extern f64 D_800A48A8;
extern f64 D_800A48B0;
extern f64 D_800A48B8;
extern M2C_UNK D_800A73E0;
extern M2C_UNK D_800C02AE;

/* The handler gets func_8002ABC0's token array (0x4C bytes each: text[68], number at +0x44):
 * +0x4C tokens[1].text (the command word), +0xDC tokens[2].number, then three groups of 0x130 bytes
 * (four tokens) from tokens[3]: +0xE4 text, +0x174 number, +0x1C0 number; +0x474 tokens[15].text,
 * +0x504 tokens[16].number, +0x59C tokens[18].number. */

/* port: trunc.w.s. In range it is C's conversion; a NaN or out-of-range value raises the R4300's
 * unimplemented-operation exception on the console (it can't be masked). C leaves that undefined and wasm
 * traps, so the port returns the MIPS "invalid" result 0x7FFFFFFF instead. */
static s32 port_trunc_w_s(f32 x) {
    if (!(x >= -2147483648.0f && x < 2147483648.0f)) {
        return 0x7FFFFFFF;
    }
    return (s32) x;
}

/* The asm's u32 -> f64 conversion: cvt.d.w, plus the 2^32 constant (bias) when the word is negative. */
static f64 port_u32_to_f64(s32 v, f64 bias) {
    f64 d = (f64) v;
    if (v < 0) {
        d += bias;
    }
    return d;
}

/* One 16-byte row: +0 s32 time, +4 byte, +6 name, +0xA speed byte, +0xB byte, +0xC byte cleared.
 * speed = (mul * D_8009D540) * 3.6 / time, as unsigned, then truncated to a byte (sb). */
static void port_fill_row(u8 *row, u8 *tok, u8 *cmd, s32 *mulp, f64 bias) {
    s32 t;
    f32 den;
    f32 q;
    s32 v;
    s32 lo;

    strCpy(row + 6, tok + 0xE4);
    M2C_FIELD(row, s32 *, 0) = M2C_FIELD(tok, s32 *, 0x174);
    t = M2C_FIELD(row, s32 *, 0);
    M2C_FIELD(row, u8 *, 4) = (u8) M2C_FIELD(tok, s32 *, 0x1C0);
    den = (f32) port_u32_to_f64(t, bias);
    lo = (s32) ((u32) *mulp * (u32) D_8009D540);
    q = ((f32) port_u32_to_f64(lo, bias) * 3.6f) / den;
    if (q >= 2147483648.0f) {
        v = port_trunc_w_s(q - 2147483648.0f) | 0x80000000;
    } else {
        v = port_trunc_w_s(q);
    }
    M2C_FIELD(row, u8 *, 0xA) = (u8) v;
    M2C_FIELD(row, u8 *, 0xC) = 0;
    M2C_FIELD(row, u8 *, 0xB) = (u8) M2C_FIELD(cmd, s32 *, 0xDC);
}

void func_8001E640(void *arg0) {
    /* port: the asm copies tokens[1].text into an 8-byte slot at 0x10($sp) (saved registers follow at
     * 0x18); a word longer than 7 characters overruns them on the console. The port gives the copy the
     * token's full 68 bytes, so only well-formed input behaves the same. */
    u8 sp10[68];
    u8 *cmd = (u8 *) arg0;
    u8 *base = (u8 *) &D_800C02AE;
    s32 var_s0; /* $s0: index within the table */
    s32 var_s4; /* $s4: which table */
    s32 var_s5; /* $s5: slot */
    u32 tbl;
    u32 idx;
    u32 i;

    var_s4 = 0;
    strCpy(sp10, cmd + 0x4C);
    var_s0 = 0;
    var_s5 = 0;
    /* lbu 0x10($sp) - 'A', sign-extended from a byte, then sltiu 0x18: jtbl_800A4828. */
    switch ((s8) (sp10[0] - 0x41)) {
    case 19: /* 'T' -> .L8001E6C0 */
        var_s4 = 0;
        var_s0 = (s8) sp10[1] - 0x30;
        var_s5 = (s8) sp10[2] - 0x31;
        break;
    case 0: /* 'A' -> .L8001E6E8 */
        var_s0 = 0;
        var_s4 = (s8) sp10[3] - 0x30;
        var_s5 = (s8) sp10[6] - 0x31;
        break;
    case 22: /* 'W' -> .L8001E710 */
    case 23: /* 'X' -> .L8001E710 */
        var_s5 = (s8) sp10[2] - 0x31;
        var_s4 = 5;
        switch ((s8) sp10[5]) {
        case 0x44: /* 'D' */
            var_s0 = ((s8) sp10[0] == 0x58) << 3;
            break;
        case 0x43: /* 'C' */
            var_s0 = 1;
            break;
        case 0x54: /* 'T' */
            var_s0 = 2;
            break;
        case 0x46: /* 'F' */
            var_s0 = ((s8) sp10[0] == 0x58) ? 9 : 3;
            break;
        case 0x52: /* 'R' */
            var_s0 = 4;
            break;
        case 0x4C: /* 'L' */
            var_s0 = ((s8) sp10[0] == 0x58) ? 0xA : 5;
            break;
        case 0x4E: /* 'N' */
            var_s0 = ((s8) sp10[0] == 0x58) ? 0xB : 6;
            break;
        case 0x45: /* 'E' */
            var_s0 = 7;
            break;
        }
        break;
    case 7: /* 'H' -> .L8001E7E8 */
        switch ((s8) sp10[1]) {
        case 0x41: /* 'A' */
            var_s4 = 0;
            var_s0 = (s8) sp10[2] - 0x31;
            break;
        case 0x43: /* 'C' */
            var_s4 = 4;
            var_s0 = (((s8) sp10[2] - 0x30) * 10) + ((s8) sp10[3] - 0x31);
            break;
        case 0x54: /* 'T' */
            switch ((s8) sp10[2]) {
            case 0x31:
                var_s4 = 0x10;
                var_s0 = 0;
                break;
            case 0x32:
                var_s4 = 0x11;
                var_s0 = 0;
                break;
            case 0x33:
                var_s4 = 0x12;
                var_s0 = 0;
                break;
            case 0x34:
                var_s4 = 0x13;
                var_s0 = 0;
                break;
            }
            break;
        }
        break;
    default: /* .L8001E8B8 */
        break;
    }

    if ((s8) sp10[0] != 0x48) {
        u8 *name = cmd + 0x474;
        u8 *rec;
        u32 slot;
        u8 old;
        s32 num;
        s32 *mulp;

        tbl = var_s4 & 0xFFFF;
        idx = var_s0 & 0xFFFF;
        /* lw (D_800C02AE + 0x10386)[tbl]: a table of record pointers, each record 0x2C4 bytes. */
        rec = M2C_FIELD(base, u8 **, 0x10386 + tbl * 4) + idx * 0x2C4;
        slot = var_s5 & 0xFFFF;
        old = D_800A16F0;
        mulp = &M2C_FIELD(rec + slot * 4, s32 *, 0x22C);
        *mulp = M2C_FIELD(cmd, s32 *, 0x59C);
        num = M2C_FIELD(cmd, s32 *, 0x174);
        D_800A16F0 = old + 1;
        M2C_FIELD(base, s16 *, 0x5A8A + old * 2) = (s16) num;
        str_ncat(name, &D_800A47BC, str_len(name));
        strCpy(rec + slot * 0xE + 0x24C, name);
        M2C_FIELD(rec + slot, u8 *, 0x2BC) = (u8) M2C_FIELD(cmd, s32 *, 0x504);
        /* port: lw 0x22C($s7) is re-read every row, so the multiplier comes through mulp. */
        for (i = 0; i < 3; i++) {
            port_fill_row(rec + (slot << 6) + 0x2C + i * 0x10, cmd + i * 0x130, cmd, mulp, D_800A4888);
        }
        return;
    }

    tbl = var_s4 & 0xFFFF;
    idx = var_s0 & 0xFFFF;
    M2C_FIELD((u8 *) &D_800A73E0, s32 *, 0x6B50 + (tbl + idx) * 4) = M2C_FIELD(cmd, s32 *, 0x174);
    if (tbl < 4) {
        for (i = 0; i < 3; i++) {
            port_fill_row(base + 0x33A2 + (idx << 6) + i * 0x10, cmd + i * 0x130, cmd,
                          &M2C_FIELD(cmd, s32 *, 0x59C), D_800A4890);
        }
    } else if (tbl < 0x10) {
        for (i = 0; i < 3; i++) {
            port_fill_row(base + 0x34A2 + (idx << 6) + i * 0x10, cmd + i * 0x130, cmd,
                          &M2C_FIELD(cmd, s32 *, 0x59C), D_800A4898);
        }
    } else if (tbl < 0x11) {
        for (i = 0; i < 3; i++) {
            port_fill_row(base + 0x37A2 + i * 0x10, cmd + i * 0x130, cmd, &M2C_FIELD(cmd, s32 *, 0x59C),
                          D_800A48A0);
        }
    } else if (tbl < 0x12) {
        for (i = 0; i < 3; i++) {
            u8 *tok = cmd + i * 0x130;
            u8 *row = base + 0x3862 + i * 0x10;

            port_fill_row(base + 0x37E2 + i * 0x10, tok, cmd, &M2C_FIELD(cmd, s32 *, 0x59C), D_800A48A8);
            /* The same entry is copied into the rows at +0x3862 (no speed byte there). */
            strCpy(row + 6, tok + 0xE4);
            M2C_FIELD(row, s32 *, 0) = M2C_FIELD(tok, s32 *, 0x174);
            M2C_FIELD(row, u8 *, 0xC) = 0;
            M2C_FIELD(row, u8 *, 4) = (u8) M2C_FIELD(tok, s32 *, 0x1C0);
        }
    } else if (tbl < 0x13) {
        for (i = 0; i < 3; i++) {
            u8 *tok = cmd + i * 0x130;
            u8 *row = base + 0x3862 + i * 0x10;

            port_fill_row(base + 0x3822 + i * 0x10, tok, cmd, &M2C_FIELD(cmd, s32 *, 0x59C), D_800A48B0);
            /* Adds this entry's time to the +0x3862 rows (no name copy here). */
            M2C_FIELD(row, s32 *, 0) = M2C_FIELD(row, s32 *, 0) + M2C_FIELD(tok, s32 *, 0x174);
            M2C_FIELD(row, u8 *, 0xC) = 0;
            M2C_FIELD(row, u8 *, 4) = (u8) M2C_FIELD(tok, s32 *, 0x1C0);
        }
    } else if (tbl < 0x14) {
        for (i = 0; i < 3; i++) {
            port_fill_row(base + 0x38A2 + i * 0x10, cmd + i * 0x130, cmd, &M2C_FIELD(cmd, s32 *, 0x59C),
                          D_800A48B8);
        }
    }
}
