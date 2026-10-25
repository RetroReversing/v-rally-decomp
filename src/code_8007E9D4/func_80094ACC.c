#include "common.h"

typedef void (*CbFn)(void *, s32, s32);

typedef struct Node {
    struct Node *child;
    s32 unk4;
    CbFn cb;
} Node;

typedef struct S0 {
    Node *child;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
} S0;

s32 func_80094ACC(S0 *arg0, s32 arg1, s32 arg2) {
    S0 *self = arg0;
    Node *node;

    switch (arg1) {
    case 1:
        arg0->child = (Node *)arg2;
        return 0;
    case 2:
        self->unk20 = 0;
        self->unk24 = 1;
        self->unk30 = 0;
        self->unk1C = 0;
        node = arg0->child;
        if (node != NULL) {
            node->cb(node, 4, 0);
        }
        return 0;
    case 3:
        self->unk30 = 1;
        node = arg0->child;
        if (node != NULL) {
            node->cb(node, 9, 0);
        }
        return 0;
    case 4:
        self->unk18 = arg2;
        return 0;
    case 5:
        self->unk1C = 1;
        return 0;
    case 6:
    case 7:
    case 8:
    case 9:
        return 0;
    default:
        break;
    }
    node = arg0->child;
    if (node != NULL) {
        node->cb(node, arg1, arg2);
    }
    return 0;
}
