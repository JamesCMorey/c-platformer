#include "player.h"
#include <stdlib.h>

struct Player *pl_init() {
    struct Player *p = malloc(sizeof(struct Player));
    p->x = 0;
    p->y = 0;

    return p;
}

void pl_set_dx(struct Player *p, int dx) {
    p->dx = dx;
}

void pl_set_dy(struct Player *p, int dy) {
    p->dy = dy;
}

void pl_free(struct Player *p) {
    free(p);
}
