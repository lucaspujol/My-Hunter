/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void init_ducks_bis(my_hunter_t *hunter, int i)
{
    hunter->ducks[i]->scale = (sfVector2f){2, 2};
    hunter->ducks[i]->rect = (sfIntRect){0, 0, 110, 110};
    sfSprite_setTexture(hunter->ducks[i]->sprite,
        hunter->ducks[i]->texture, sfTrue);
    sfSprite_setTextureRect(hunter->ducks[i]->sprite,
        hunter->ducks[i]->rect);
    sfSprite_setPosition(hunter->ducks[i]->sprite,
        hunter->ducks[i]->position);
    sfSprite_setScale(hunter->ducks[i]->sprite, hunter->ducks[i]->scale);
    sfSprite_setOrigin(hunter->ducks[i]->sprite, (sfVector2f)
        {sfSprite_getGlobalBounds(hunter->ducks[i]->sprite).width / 2,
        sfSprite_getGlobalBounds(hunter->ducks[i]->sprite).height / 2});
}

void init_ducks(my_hunter_t *hunter)
{
    srand(time(NULL));
    hunter->ducks = malloc(sizeof(duck_t *) * 7);
    for (int i = 0; i < 7; i++) {
        hunter->ducks[i] = malloc(sizeof(duck_t));
        hunter->ducks[i]->texture = sfTexture_createFromFile
        ("assets/images/duck.png", NULL);
        hunter->ducks[i]->sprite = sfSprite_create();
        sfSprite_setTexture(hunter->ducks[i]->sprite,
            hunter->ducks[i]->texture, sfTrue);
        hunter->ducks[i]->position = (sfVector2f)
        {rand() % 1920 - 1920, rand() % 1080};
        init_ducks_bis(hunter, i);
    }
}
