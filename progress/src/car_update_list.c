s32 car_set_sfx_params(void *);
void car_fix_path_ends(void *);
void func_80032FE8(void *);
void func_8003310C(void *);
void func_800324B4(void *);
void UpdateRecordTimers(void);
void func_80033238(void *);
void func_80033298(void *);
void func_80033348(void *);
void statBarsUpdate(void *);

/* Runs the per-car update over the circular car list starting at head, choosing a
 * handler by the car's path point (x and y past 0xFB mean an edge), then the list-wide steps. */
void car_update_list(void *head) {
    void *car;
    s16 x;
    s16 y;
    u8 *p;

    car = head;
    do {
        if (car_set_sfx_params(car) == 0) {
            p = *(u8 **)((u8 *)car + 0x78);
            x = *(s16 *)(p + 4);
            y = *(s16 *)(p + 6);
            if (x >= 0xFB && y >= 0xFB) {
                func_80033298(car);
            } else if (x >= 0xFB) {
                statBarsUpdate(car);
            } else if (y >= 0xFB) {
                func_80033238(car);
            } else {
                func_80033348(car);
            }
        }
        car = *(void **)((u8 *)car + 0x5C);
    } while (car != head && car != NULL);
    func_80032FE8(head);
    func_8003310C(head);
    car_fix_path_ends(head);
    func_800324B4(head);
    UpdateRecordTimers();
}
