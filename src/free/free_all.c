/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void free_all(my_hunter_t *hunter)
{
    for (int i = 0; i < 12; i++) {
        sfTexture_destroy(hunter->boutons[i]->texture);
        sfSprite_destroy(hunter->boutons[i]->sprite);
        free(hunter->boutons[i]);
    }
    free(hunter->ducks);
    free(hunter->boutons);
    free(hunter);
}
