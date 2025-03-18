/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void animate_logo(my_hunter_t *hunter)
{
    float amplitude = 20.0f;
    float speed = 3.0f;
    float offset = 0.0f;

    hunter->time = sfClock_getElapsedTime(hunter->clock);
    hunter->seconds = sfTime_asSeconds(hunter->time);
    offset = amplitude * sinf(speed * hunter->seconds);
    hunter->boutons[0]->position.y += offset;
    sfSprite_setPosition(hunter->boutons[0]->sprite,
    hunter->boutons[0]->position);
    hunter->boutons[0]->position.y -= offset;
}
