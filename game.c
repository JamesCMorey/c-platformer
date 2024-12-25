#include "game.h"
#include "player.h"
#include <stdlib.h>
#include <stdbool.h>

struct GameState *gs_init() {
    struct GameState *gs = malloc(sizeof(struct GameState));
    gs->player = pl_init();
    gs->running = true;
    gs->game_over = false;
    gs->tick_num = 0;

    return gs;
};

void gs_teardown(struct GameState *gs) {
    //save to file or smth

    //free
    gs_free(gs);
}

bool gs_running(struct GameState *gs) {
    return gs->running;
}

void gs_update(struct GameState *gs) {
    if (!gs->running)
        return;

    //pl_change_dy_by(GRAVITY);
}

void gs_add_tick(struct GameState *gs) {
    gs->tick_num++;
}

void gs_quit(struct GameState *gs) {
    gs->running = false;
}

void gs_free(struct GameState *gs) {
    pl_free(gs->player);
    free(gs);
}
