/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"


void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

void make_ducks_move_bis(my_hunter_t *hunter, int i, int rand_pos_y)
{
    hunter->ducks[i]->position.x += 10;
    if (hunter->ducks[i]->position.x >= 1920 + 220) {
        hunter->ducks[i]->position.x = -rand() % 1920;
        rand_pos_y = rand() % 1080;
        if (rand_pos_y < 110)
            hunter->ducks[i]->position.y = 110;
        if (rand_pos_y > 1080 - 110)
            hunter->ducks[i]->position.y = 1080 - 110;
        if (rand_pos_y >= 800 && rand_pos_y <= 1080 - 110)
            hunter->ducks[i]->position.y = rand_pos_y;
        hunter->life -= 1;
    }
    sfSprite_setPosition(hunter->ducks[i]->sprite,
    hunter->ducks[i]->position);
}

void make_ducks_move(my_hunter_t *hunter, int i)
{
    int rand_pos_y = 0;

    if (hunter->move_seconds > hunter->game_speed) {
        make_ducks_move_bis(hunter, i, rand_pos_y);
    }
}

void animate_ducks(my_hunter_t *hunter)
{
    hunter->time = sfClock_getElapsedTime(hunter->clock);
    hunter->seconds = hunter->time.microseconds / 1000000.0;
    hunter->move_time = sfClock_getElapsedTime(hunter->move_clock);
    hunter->move_seconds = hunter->move_time.microseconds / 1000000.0;
    for (int i = 0; i < 7; i++) {
        if (hunter->seconds > 0.1) {
            move_rect(&hunter->ducks[i]->rect, 110, 330);
            sfSprite_setTextureRect(hunter->ducks[i]->sprite,
            hunter->ducks[i]->rect);
        }
        make_ducks_move(hunter, i);
    }
    if (hunter->seconds > 0.1)
        sfClock_restart(hunter->clock);
    if (hunter->move_seconds > hunter->game_speed)
        sfClock_restart(hunter->move_clock);
}
