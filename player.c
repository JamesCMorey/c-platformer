#include "player.h"
#include <stdlib.h>

/* Accessors */
int pl_dx(struct Player *p) { return p->dx; }
int pl_dy(struct Player *p) { return p->dy; }
int pl_x(struct Player *p) { return p->x; }
int pl_y(struct Player *p) { return p->y; }

/* Mutators */
void pl_dx_set(struct Player *p, int dx) { p->dx = dx; }
void pl_dy_set(struct Player *p, int dy) { p->dy = dy; }
void pl_dx_add(struct Player *p, int dx) { p->dx += dx; }
void pl_dy_add(struct Player *p, int dy) { p->dy += dy; }

void pl_x_set(struct Player *p, int x) { p->x = x; }
void pl_y_set(struct Player *p, int y) { p->y = y; }
void pl_x_add(struct Player *p, int x) { p->x += x; }
void pl_y_add(struct Player *p, int y) { p->y += y; }

/* Init and Teardown */
struct Player *pl_init() {
    struct Player *p = malloc(sizeof(struct Player));
    p->x = 0;
    p->y = 0;

    return p;
}

void pl_free(struct Player *p) { free(p); }
