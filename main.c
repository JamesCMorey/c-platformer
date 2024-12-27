#include <ncurses.h>
#include <stdbool.h>
#include "player.h"
#include "tick.h"
#include "game.h"
#include "input.h"
#include "ui.h"

int main(int argc, char *argv[]) {
    initscr(); cbreak(); noecho(); nodelay(stdscr, TRUE);

    struct GameState *gs = gs_init();

    unsigned int t_accum = 0;
    unsigned int t_now, t_prev = t_ms_get();
    while(gs_running(gs)) {
        t_now = t_ms_get();
        t_accum += t_now - t_prev;
        t_prev = t_now;

        if (t_accum > TICK_DUR) {
            mvprintw(0, 0, "Tick %d\n", gs->tick_num);

            in_handle(gs);
            gs_update(gs);
            ui_render(gs);

            gs_tick_add(gs);
            t_accum -= TICK_DUR;
        }
    }

    gs_teardown(gs);
    endwin();
    return 0;
}
