#include "input.h"
#include "game.h"
#include "player.h"
#include <stdbool.h>
#include <ncurses.h>

void in_handle(struct GameState *gs) {
    char c = getch();

    switch(c) {
        case 'w':
            if (pl_grounded(gs_player(gs))) {
                pl_grounded_set(gs_player(gs), false);
                pl_dy_set(gs_player(gs), JUMP_VELO);
            }
            else if (!pl_airjumped(gs_player(gs))) {
                pl_grounded_set(gs_player(gs), false);
                pl_dy_set(gs_player(gs), JUMP_VELO);
                pl_airjumped_set(gs_player(gs), true);
            }
            break;
        case 'a':
            pl_dx_set(gs_player(gs), -SIDEWAYS_VELO);
            break;
        case 'd':
            pl_dx_set(gs_player(gs), SIDEWAYS_VELO);
            break;
        case 'q':
            gs_quit(gs);
            break;
        default:
            break;
    }
}
