#pragma once
#include "game.h"
#include <stdbool.h>

enum BLOCK_TYPE {
    GROUND, ENEMY
};

struct Stage {
    char **grid;
};

struct Stage *stage_load(struct GameState *gs, char *filename);
bool stage_collision_get(struct GameState *gs);
void stage_set_row(struct Stage *s, int row, int start, int end, char c);
char **stage_grid(struct Stage *s);
