void car_init_from_stream_record(void *rec);
extern void **gCarList;

/* Walks the car list (gCarList points at the head record; each record's next pointer is at +4)
 * and initialises each car from its record. */
void func_8001FF80(void) {
    void *rec;

    rec = *gCarList;
    if (rec != NULL) {
        do {
            car_init_from_stream_record(rec);
            rec = *(void **)((char *)rec + 4);
        } while (rec != NULL);
    }
}
