/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void render_game(my_hunter_t *hunter)
{
    if (hunter->where_am_i == GAME)
        animate_ducks(hunter);
    if (hunter->where_am_i != GAMEOVER)
        display_score(hunter);
    for (int i = 2; i >= 3 - hunter->life &&
    hunter->where_am_i != GAMEOVER; i--) {
        sfRenderWindow_drawSprite(hunter->window, hunter->life_sprites[i],
        NULL);
    }
    if (hunter->life == 0) {
        sfMusic_play(hunter->gameover_sound);
        hunter->life = 3;
        hunter->where_am_i = GAMEOVER;
    }
    for (int i = 0; i < 7; i++) {
        sfRenderWindow_drawSprite(hunter->window, hunter->ducks[i]->sprite,
            NULL);
    }
    sfRenderWindow_drawSprite(hunter->window, hunter->boutons[5]->sprite,
        NULL);
}
