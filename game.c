#include "game.h"
#include "player.h"
#include "stage.h"
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

struct GameState *gs_init() {
    struct GameState *gs = malloc(sizeof(struct GameState));
    gs->player = pl_init();
    gs->stage = stage_load("1st.st");
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

    int dy = pl_dy(player);
    int dx = pl_dx(player);
    while (dy != 0 || dx != 0) {

        if (pl_x(player) < 0) {
            pl_x_set(player, pl_x(player) + 1);
            pl_dx_set(player, 0);
        }
        else if (pl_x(player) >= getmaxx(stdscr)) {
            pl_x_set(player, pl_x(player) - 1);
            pl_dx_set(player, 0);
        }
        else if (dx < 0) {
            pl_x_add(player, -1);
            dx++;
        }
        else if (dx > 0){
            pl_x_add(player, 1);
            dx--;
        }

        if (dy < 0) {
            pl_y_add(player, -1);
            dy++;
        }
        else if (dy > 0){
            pl_y_add(player, 1);
            dy--;
        }

        if (pl_y(player) >= getmaxy(stdscr)) {
            pl_y_set(player, pl_y(player) - 1);
            pl_dy_set(player, 0);
        }
        else if (pl_y(player) <= 0) {
            pl_y_set(player, pl_y(player) + 1);
            pl_dy_set(player, 0);
        }
        /* On ground */
        else if (stage_grid(gs->stage)[pl_y(player)][pl_x(player)] == '#') {
            pl_y_set(player, pl_y(player) - 1);
            pl_dy_set(player, 0);
        }
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
struct Stage *gs_stage(struct GameState *gs) { return gs->stage; }
