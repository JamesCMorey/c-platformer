#include "tick.h"
#include <time.h>
#include <unistd.h>

unsigned int get_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    //     1000ms == 1s       1ms == 1,000,000ns
    return ts.tv_sec * 1000 + ts.tv_nsec/1000000;
}

void sleep_ms(int ms) {
    usleep(ms * 1000);
}
