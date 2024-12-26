#pragma once

#include <stdbool.h>

#define GRAVITY 1

struct GameState {
    struct Player *player;
    struct Stage *stage;
    bool running;
    bool game_over;
    unsigned long tick_num;
};

struct GameState *gs_init();
void gs_tick_add(struct GameState *gs);
void gs_quit(struct GameState *gs);
void gs_update(struct GameState *gs);
bool gs_running(struct GameState *gs);
void gs_teardown(struct GameState *gs);
void gs_free(struct GameState *gs);
struct Player *gs_player(struct GameState *gs);
struct Stage *gs_stage(struct GameState *gs);
