#include "ui.h"
#include "game.h"
#include "player.h"
#include <ncurses.h>

void ui_stage_draw();

void ui_render(struct GameState *gs) {
    erase();
    ui_stage_draw();
    mvprintw(pl_y(gs_player(gs)), pl_x(gs_player(gs)), "@");
}

void ui_stage_draw() {
    mvhline(20, 0, '-', 200);
}
