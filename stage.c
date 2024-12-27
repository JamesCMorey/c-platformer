#include "stage.h"
#include "game.h"
#include "player.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>

struct Stage *stage_new() {
    struct Stage *s = malloc(sizeof(struct Stage));

    s->grid = (char**)calloc(getmaxy(stdscr), sizeof(char*)); // rows
    for (int i = 0; i < getmaxy(stdscr); i++) {
        s->grid[i] = (char*)calloc(getmaxx(stdscr), sizeof(char)); // columns
    }

    return s;
}

struct Stage *stage_load(struct GameState *gs, char *filename) {
    struct Stage *s = stage_new();

    char buf[100];
    FILE *stage_file = fopen(filename, "r");

    int row, start, end;
    while (fgets(buf, sizeof(buf), stage_file)) {
        if (strncmp(buf, "GROUND", sizeof("GROUND") - 1) == 0) {
            sscanf(buf + sizeof("GROUND"), "%d, %d-%d", &row, &start, &end);
            stage_set_row(s, row, start, end, '#');
        }
        else if (strncmp(buf, "ENEMIES", sizeof("ENEMIES") - 1) == 0) {
        } else if(strncmp(buf, "PLAYER", sizeof("PLAYER") - 1) == 0) {
            sscanf(buf + sizeof("PLAYER"), "%d, %d", &start, &end);
            pl_x_set(gs_player(gs), start);
            pl_y_set(gs_player(gs), end);
        }
    }

    return s;
}

bool stage_collision_get(struct GameState *gs) {
    return false;
}

void stage_set_row(struct Stage *s, int row, int start, int end, char c) {
    if (row > getmaxy(stdscr)) {
        fprintf(stderr, "stage_set_row: trying to fill row off screen\n");
        return;
    }


    int i;
    for (i = 0; i < end - start; i++) {
        if (start + i >= getmaxx(stdscr))
            break;

        s->grid[row][start + i] = c;
    }
}

char **stage_grid(struct Stage *s) { return s->grid; }
