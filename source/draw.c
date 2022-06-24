#include "draw.h"
#include <SDL2/SDL_image.h>

void prepareCanvas(Win *app)
{
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);

    SDL_RenderClear(app->renderer);
}

void presentCanvas(Win *app)
{
    SDL_RenderPresent(app->renderer);
}

SDL_Texture *loadTexture(Win *app, char *img_path)
{

    SDL_Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading: %s", img_path);
    texture = IMG_LoadTexture(app->renderer, img_path);
    if (texture == NULL)
    {
        printf("Failed to load texture %s\n", IMG_GetError());
    }
    return texture;
}

int Colision(SDL_Rect *player, SDL_Rect *en)
{
    int left_player, left_en;
    int right_player, right_en;
    int top_player, top_en;
    int bottom_player, bottom_en;

    left_player = player->x;
    right_player = player->x + player->w;
    top_player = player->y;
    bottom_player = player->y + player->h;

    left_en = en->x;
    right_en = en->x + en->w;
    top_en = en->y;
    bottom_en = en->y + en->h;

    if (bottom_player <= top_en)
    {
        return 0;
    }

    if (top_player >= bottom_en)
    {
        return 0;
    }

    if (right_player <= left_en)
    {
        return 0;
    }

    if (left_player >= right_en)
    {
        return 0;
    }

    return -1;
}


int drawEntity(Win *app, Entity *entity, Entity *enemy)

{
    SDL_Rect dest = {entity->pos_x, entity->pos_y, entity->width, entity->height};
    SDL_Rect en = {enemy->pos_x, enemy->pos_y, enemy->width, enemy->height};

    SDL_RenderCopy(app->renderer, entity->texture, NULL, &dest);
    SDL_RenderCopy(app->renderer, enemy->texture, NULL, &en);

    if (Colision(&dest, &en))
    {
        printf("You lose");
        return -1;
    }

    return 0;
}
