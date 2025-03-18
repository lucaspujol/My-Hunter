/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void free_ducks(my_hunter_t *hunter)
{
    for (int i = 0; i < 7; i++) {
        sfSprite_destroy(hunter->ducks[i]->sprite);
        sfTexture_destroy(hunter->ducks[i]->texture);
        free(hunter->ducks[i]);
    }
    free(hunter->ducks);
}
