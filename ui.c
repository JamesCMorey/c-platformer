#include "ui.h"
#include "game.h"
#include "player.h"
#include "stage.h"
#include <ncurses.h>

void ui_stage_draw();

void ui_render(struct GameState *gs) {
    erase();
    ui_stage_draw(gs);
    mvprintw(pl_y(gs_player(gs)), pl_x(gs_player(gs)), "@");
}

void ui_stage_draw(struct GameState *gs) {
    for(int row = 0; row < getmaxy(stdscr); row++) {
        for(int col = 0; col < getmaxx(stdscr); col++) {
            // TODO: Fix interface violation
            mvprintw(row, col, "%c", gs->stage->grid[row][col]);
        }
    }
}
