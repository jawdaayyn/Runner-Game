#ifndef INPUT
#define INPUT

#include "draw.h"
#include <SDL2/SDL.h>

enum Direction
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    LEFT_ENEMY
};
int imput_handler(Entity *entity);
int move(Entity *entity, enum Direction);
int Colision(Entity *entity);
int checkLeftCollision();

#endif