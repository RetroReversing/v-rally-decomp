extern void *D_8009D6B0;
extern char gOrderState[];
extern char stream_state[];

void car_dispatch_cmd(void *, s32, void *, s32);
s32 packBytes4(u8, u8, u8, s8);
void func_80050048(s32);
void func_8004F3C4(void);
s32 func_8001FFC4(void *, void *, s32, s32);
void func_80023134(void *, void *, void *);
void func_80024B28(void *);

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Quad20B04;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Tri20B04;

/* Walks the linked list of active nodes from the list head (or from the node
 * saved in D_8009D6B0 when a previous pass stopped early), runs each node's
 * update, and feeds the node's state byte pattern to the sound/effects code.
 * Stops early and saves the current node if the global check flag is set. */
void func_80020B04(void **list_head) {
    void *node;
    s32 hi_mask;
    void *payload;
    u8 *data;
    s32 hi;
    void *state;
    Quad20B04 rect;
    Tri20B04 tri;
    s32 kind;
    u16 flag;

    node = *list_head;
    if (D_8009D6B0 != NULL) {
        node = D_8009D6B0;
    }
    if (node != NULL) {
        hi_mask = 0xFFFF0000;
        do {
            payload = *(void **)((char *)node + 0x48);
            D_8009D6B0 = NULL;
            data = (u8 *)payload + 4;
            car_dispatch_cmd(node, *(s32 *)payload, data, *(s32 *)((char *)payload + 0x20));
            if ((*(s32 *)((char *)*(void **)(gOrderState + 0x73F0) + 8) & 1) != 0) {
                D_8009D6B0 = node;
                return;
            }
            kind = *(s32 *)((char *)*(void **)((char *)node + 0x48) + 0x20);
            if ((kind == 0) || (kind == 9)) {
                flag = *(u16 *)((char *)*(void **)(stream_state + 0x32F2) + 0x1E);
                if (flag != 0) {
                    u8 byte8 = data[4];
                    u8 byte9 = data[5];
                    s32 fl = *(s32 *)((char *)node + 0x14);
                    s8 sbyte0 = (s8)data[0];
                    u8 byte1 = data[1];
                    if ((fl & 0x10) == 0) {
                        func_80050048(packBytes4(byte1, byte8, byte9, sbyte0));
                    }
                } else {
                    func_80050048(packBytes4(data[1], data[4], data[5], (s8)data[0]));
                }
            }
            state = *(void **)((char *)node + 0x54);
            {
                s32 w = *(s32 *)((char *)state + 0x20);
                hi = w >> 16;
                if (hi != 0) {
                    *(s32 *)((char *)state + 0x20) = w + hi_mask;
                }
            }
            if (hi == 1) {
                func_8004F3C4();
            }
            if ((data[1] & 0x80) != 0) {
                {
                    void *p = *(void **)((char *)node + 0x54);
                    s32 w = *(s32 *)((char *)p + 0x20);
                    if ((w & 0xFFFF) != 0) {
                        *(s32 *)((char *)p + 0x20) = w - 1;
                    if (*(u16 *)((char *)*(void **)((char *)node + 0x54) + 0x22) != 0) {
                            goto join20;
                        }
                        if (hi != 0) {
                            goto join20;
                        }
                        if (1) {
                        {
                            void *p8c = *(void **)((char *)node + 0x8C);
                            void *p60 = *(void **)((char *)node + 0x60);
                            void *a1v = *(void **)((char *)p8c + 0x28);
                            s32 a3v = *(s32 *)((char *)p60 + 0x28);
                            tri.a = 0;
                            tri.b = func_8001FFC4(&rect, a1v, 0, (s16)a3v);
                        }
                        tri.c = 0;
                        rect.b -= 0x5A;
                        func_80023134(node, &rect, &tri);
                        func_80024B28(node);
                        *(s32 *)((char *)*(void **)((char *)node + 0x54) + 0x20) = 0x320000;
                        *(s32 *)((char *)node + 0x14) |= 0x40;
                    }
                }
            }
            } else {
                state = *(void **)((char *)node + 0x54);
                *(s32 *)((char *)state + 0x20) &= hi_mask;
                state = *(void **)((char *)node + 0x54);
                *(s32 *)((char *)state + 0x20) |= 0x14;
            }
            join20:
            *(s32 *)((char *)*(void **)((char *)node + 0x48) + 0x14) = (s8)data[0];
            *(s32 *)((char *)*(void **)((char *)node + 0x48) + 0x1C) = data[3];
            *(s32 *)((char *)*(void **)((char *)node + 0x48) + 0xC) = data[4];
            *(s32 *)((char *)*(void **)((char *)node + 0x48) + 0x10) = data[5];
            *(s32 *)((char *)*(void **)((char *)node + 0x48) + 0x18) = 0;
            node = *(void **)((char *)node + 4);
        } while (node != NULL);
    }
}
