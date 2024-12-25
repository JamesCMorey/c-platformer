#include "input.h"
#include "game.h"
#include <ncurses.h>

void in_handle(struct GameState *gs) {
    char c = getch();

    switch(c) {
        case 'w':
            break;
        case 'a':
            break;
        case 's':
            break;
        case 'd':
            break;
        case 'q':
            gs_quit(gs);
            break;
    }
}
