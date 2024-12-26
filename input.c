#include "input.h"
#include "game.h"
#include "player.h"
#include <ncurses.h>

void in_handle(struct GameState *gs) {
    char c = getch();

    switch(c) {
        case 'w':
            pl_dy_set(gs_player(gs), -3);
            break;
        case 'a':
            pl_dx_set(gs_player(gs), -3);
            break;
        case 's': /* No point in platformer */
            break;
        case 'd':
            pl_dx_set(gs_player(gs), 3);
            break;
        case 'q':
            gs_quit(gs);
            break;
    }
}
