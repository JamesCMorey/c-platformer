#pragma once

#define TICKS_PER_SEC 20
#define TICK_DUR 1.0 / TICKS_PER_SEC * 1000

unsigned int t_ms_get();
void t_sleep(int ms);
