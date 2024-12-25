#pragma once

struct Player {
    int y, x;
    int dy, dx;
};

struct Player *pl_init();
void pl_set_dx(struct Player *p, int dx);
void pl_set_dy(struct Player *p, int dy);
void pl_free(struct Player *p);
