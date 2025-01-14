#pragma once

#include <stdbool.h>

struct Player {
    int y, x;
    int dy, dx;
    bool grounded;
    bool airjumped;
};

struct Player *pl_init();
void pl_free(struct Player *p);

int pl_dx(struct Player *p);
int pl_dy(struct Player *p);
int pl_x(struct Player *p);
int pl_y(struct Player *p);

void pl_dx_set(struct Player *p, int dx);
void pl_dy_set(struct Player *p, int dy);
void pl_dx_add(struct Player *p, int dx);
void pl_dy_add(struct Player *p, int dy);

void pl_x_set(struct Player *p, int x);
void pl_y_set(struct Player *p, int y);
void pl_x_add(struct Player *p, int x);
void pl_y_add(struct Player *p, int y);

void pl_grounded_set(struct Player *p, bool grounded);
void pl_airjumped_set(struct Player *p, bool airjumped);

bool pl_grounded(struct Player *p);
bool pl_airjumped(struct Player *p);
