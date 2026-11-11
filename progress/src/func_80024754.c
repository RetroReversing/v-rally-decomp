/* Per-frame update over the linked list of cars at *head: each car's target
 * value (target) is recomputed, its rank (rank) is adjusted from the control
 * state and the lap data, and the control timer at +8 is counted down. */
void func_80024754(void **head) {
    s32 delta, half, ctrlState, ctrlStateB, target, i, sum, rank, ev, pos;
    u8 bits;
    void *ai, *car, *ctrl, *ctrl2, *ctrl3, *ctrl4, *ctrl5, *ctrl6, *hist, *info, *lapTimes;
    s32 flags, timer;

    car = *head;
    if (car != NULL) {
        do {
            ctrl = *(void **)((u8 *)car + 0x50);
            ai = *(void **)((u8 *)car + 0x48);
            hist = *(void **)((u8 *)car + 0x4C);
            pos = *(s32 *)*(s32 **)((u8 *)car + 0x58);
            rank = *(s32 *)ctrl;
            info = (u8 *)ai + 4;
            if ((pos < 0x7D0) & (rank < 3)) {
                if ((*((u8 *)ai + 8) != 0) || ((target = 0, (*(s32 *)((u8 *)ctrl + 4) & 2) != 0) && *((u8 *)ai + 9) != 0)) {
                    delta = (*(s32 *)(*(void **)((u8 *)car + 0x78) + 4) - *(s32 *)((u8 *)hist + 4) + 0x3E8) >> 4;
                    if (delta >= 0x65) delta = 0x64;
                    half = pos >> 4;
                    if (pos >= 0) target = delta - half;
                    else target = delta + half;
                }
            } else target = 0;
            if (target < 0) {
                *(s32 *)((u8 *)*(void **)((u8 *)car + 0x48) + 0x18) = 0;
            } else {
                *(s32 *)((u8 *)*(void **)((u8 *)car + 0x48) + 0x18) = target;
            }

            ev = *((u8 *)info + 3) & 0xEF;
            switch (ev) {
            case 0x20:
                if ((rank < *(s32 *)(*(void **)((u8 *)car + 0x7C) + 0x20)) &&
                    ((ctrlState = *(s32 *)((u8 *)*(void **)((u8 *)car + 0x50) + 4), ctrlState == 0) ||
                     ((ctrlState != 0) & (rank < 2)))) rank += 1;
                bits = *((u8 *)info + 2) & 0xDF;
                *((u8 *)info + 2) = bits;
                break;
            case 0x40:
                if ((rank > 0) &&
                    ((ctrlStateB = *(s32 *)((u8 *)*(void **)((u8 *)car + 0x50) + 4), ctrlStateB == 0) ||
                     ((ctrlStateB != 0) & (rank < 3)))) rank -= 1;
                bits = *((u8 *)info + 2) & 0xBF;
                *((u8 *)info + 2) = bits;
                break;
            }
            ctrl2 = *(void **)((u8 *)car + 0x50);
            if (*(s32 *)((u8 *)ctrl2 + 4) != 0) {
                if (*(s32 *)((u8 *)ctrl2 + 8) == 0) {
                    delta = 0;
                    i = 0;
                    lapTimes = *(void **)((u8 *)car + 0x54);
                    for (; i < 4; i++)
                        delta += *(s32 *)((u8 *)lapTimes + 0x10 + i * 4);
                    sum = delta;
                    if (((u32)(sum + 0xAFF) < 0x15FFU) &&
                        ((*(s32 *)(*(void **)((u8 *)car + 0x78) + 4) - 0x5DC) < *(s32 *)((u8 *)hist + 4)) &&
                        ((rank < *(s32 *)(*(void **)((u8 *)car + 0x7C) + 0x20)) & (rank > 0)) &&
                        (*(s32 *)((u8 *)*(void **)((u8 *)car + 0x48) + 0x18) == 0)) rank += *((u8 *)info + 4) != 0;
                    delta = *(s32 *)((u8 *)hist + 4);
                    if (delta >= 0)
                        rank -= (delta < (*(s32 *)(*(void **)((u8 *)car + 0x78) + 4) - 0xFA0)) & (rank >= 3);
                    if ((*((u8 *)info + 5) != 0) && (*(s32 *)*(void **)((u8 *)car + 0x48) != 5)) {
                        if ((u32)(pos + 0x12B) < 0x257U) {
                            ctrl3 = *(void **)((u8 *)car + 0x50);
                            rank = 0;
                            *(s32 *)((u8 *)ctrl3 + 4) |= 2;
                        }
                    } else {
                        ctrl4 = *(void **)((u8 *)car + 0x50);
                        flags = *(s32 *)((u8 *)ctrl4 + 4);
                        if (flags & 2) rank = 2;
                        *(s32 *)((u8 *)ctrl4 + 4) = flags & ~2;
                    }
                }
            }
            if (*((u8 *)info + 3) & 0x10)
                *(s32 *)((u8 *)*(void **)((u8 *)car + 0x7C) + 0x2C) = 0xFF;
            else
                *(s32 *)((u8 *)*(void **)((u8 *)car + 0x7C) + 0x2C) = 0;
            ctrl5 = *(void **)((u8 *)car + 0x50);
            if (((rank != *(s32 *)ctrl5) & (rank >= 3)) && (*(s32 *)*(void **)((u8 *)car + 0x4C) == 2))
                *(s32 *)((u8 *)ctrl5 + 8) = 0xA;
            *(s32 *)*(void **)((u8 *)car + 0x50) = rank;
            ctrl6 = *(void **)((u8 *)car + 0x50);
            timer = *(s32 *)((u8 *)ctrl6 + 8);
            if (timer != 0) *(s32 *)((u8 *)ctrl6 + 8) = timer - 1;
            car = *(void **)((u8 *)car + 4);
        } while (car != NULL);
    }
}
