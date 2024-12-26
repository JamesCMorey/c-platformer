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

    struct Player *player = gs->player;

    pl_dy_add(player, GRAVITY);
    pl_y_add(player, pl_dy(player));
    pl_x_add(player, pl_dx(player));

    if (pl_y(player) > 20) {
        pl_y_set(player, 19);
    }
}

void gs_tick_add(struct GameState *gs) {
    gs->tick_num++;
}

void gs_quit(struct GameState *gs) {
    gs->running = false;
}

void gs_free(struct GameState *gs) {
    pl_free(gs->player);
    free(gs);
}

struct Player *gs_player(struct GameState *gs) { return gs->player; }
