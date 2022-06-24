#include <stdio.h>
#include "window.h"
#include "input.h"
#include "draw.h"
#include "init.h"
#include <stdlib.h>

// gcc -Wall -Wextra -Werror src/*.c -o main -L./lib -I./include -lSDL2-2.0 -lSDL2_image

void initEntity(Entity *entity, Win *app, int pos_x, int pos_y, char *texture)
{
    entity->pos_x = pos_x;
    entity->pos_y = pos_y;
    entity->width = 50;
    entity->height = 50;
    entity->texture = loadTexture(app, texture);
}

int main()
{
     int num = (rand() % (480 - 0 + 1)) + 0;
    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));
    Entity *enemy = malloc(sizeof(Entity));

    if (initSDL(app) < 0)
    {
        return -1;
    }

    initEntity(player, app, 0, 100, "./img/issou.png");
    initEntity(enemy, app, 400, num, "./img/test.svg");

    
    while (imput_handler(player) == 0)
    {
        move(enemy, LEFT_ENEMY);
        prepareCanvas(app);
        if (drawEntity(app, player, enemy) == -1)
        {
            return 0;
        }
        presentCanvas(app);
        SDL_Delay(16);
    }

    free(app);
    free(player);
    free(enemy);

    return 0;
}