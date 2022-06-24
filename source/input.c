#include "input.h"
#include "draw.h"
#include <stdio.h>




int move(Entity *entity, enum Direction dir)
{
    switch (dir)
    {
    case UP:
        if (entity->pos_y - 4 >= 0)
            entity->pos_y -= 4;
        break;
    case DOWN:
        if ((entity->pos_y + 50) + 4 <= WINDOW_HEIGHT)
            entity->pos_y += 4;
        break;
    case RIGHT:
        if ((entity->pos_x + 50) + 4 <= WINDOW_WIDTH)
            entity->pos_x += 4;
        break;
    case LEFT:
        if (entity->pos_x - 4 >= 0)
            entity->pos_x -= 4;
        break;


    case LEFT_ENEMY:
        if (entity->pos_x - 4 >= 0)
            entity->pos_x -= 4;
        
        
        if (entity->pos_x == 0)
        {
            entity->pos_x = 500;
            entity->pos_y =rand() % (310 + 1 - 50) + 50;
            return 0;   
        }
        
        break;
    }
    return 0;
}
int imput_handler(Entity *entity)
{

    SDL_Event event;

    SDL_Delay(10);
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        return -1;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) 
        {
        case SDLK_UP:
            move(entity, UP);
            printf("key is up\n ");
            break;
        case SDLK_DOWN:
            move(entity, DOWN);
            printf("key is down\n ");
            break;
        case SDLK_RIGHT:
            move(entity, RIGHT);
            printf("key is right\n ");
            break;
        case SDLK_LEFT:
            move(entity, LEFT);
            printf("key is left\n ");
            break;
        }
        break;
    default:
        break;
    }
    return 0;
}
