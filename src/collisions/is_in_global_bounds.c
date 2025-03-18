/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

int is_in_global_bounds(my_hunter_t *hunter, int i)
{
    if (hunter->event.mouseButton.x >= sfSprite_getGlobalBounds(
        hunter->boutons[i]->sprite).left &&
        hunter->event.mouseButton.x <= sfSprite_getGlobalBounds
        (hunter->boutons[i]->sprite).left + sfSprite_getGlobalBounds
        (hunter->boutons[i]->sprite).width &&
        hunter->event.mouseButton.y >= sfSprite_getGlobalBounds
        (hunter->boutons[i]->sprite).top &&
        hunter->event.mouseButton.y <= sfSprite_getGlobalBounds
        (hunter->boutons[i]->sprite).top + sfSprite_getGlobalBounds
        (hunter->boutons[i]->sprite).height)
        return 1;
    return 0;
}
