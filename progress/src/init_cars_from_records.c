extern int gRecords;
void init_car_from_record(void *car, u8 *record);
extern void *gRaceCtx;
extern char gOrderState[];
extern char gStreamState[];

/* Walks the linked list of cars (head at gOrderState+0x73F0). For each car whose
 * id matches the race context's byte at +0x382, initialises it from its record. */
void init_cars_from_records(void)
{
    s32 temp_a0;
    void *car;

    car = **(void ***)(gOrderState + 0x73F0);
    if (car != NULL) {
        do {
            ;
            if (*(*(s32 **)((char *)car + 0x48)) == *((u8 *)((char *)gRaceCtx + 0x382))) {
                temp_a0 = (*((u8 *)((char *)(gRecords + *(*(s32 **)((char *)car + 0x48)))) + 0x32)) * 0x28 + 0x44;
                init_car_from_record(car, (u8 *)(gRecords + temp_a0));
            }
            car = *((void **)((char *)car + 4));
        } while (car != NULL);
    }
}
