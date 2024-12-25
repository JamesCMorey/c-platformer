#pragma once

#define TICKS_PER_SEC 60
#define TICK_DUR 1.0 / TICKS_PER_SEC * 1000

unsigned int get_time_ms();
void sleep_ms(int ms);
