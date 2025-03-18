/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void handle_gameover_menu(my_hunter_t *hunter)
{
    if (is_in_global_bounds(hunter, 7)) {
        sfMusic_play(hunter->button_sound);
        hunter->where_am_i = GAME;
        hunter->life = 3;
        hunter->score = 0;
        free_ducks(hunter);
        init_ducks(hunter);
    }
    if (is_in_global_bounds(hunter, 2)) {
        sfMusic_play(hunter->button_sound);
        sfSprite_setPosition(hunter->boutons[2]->sprite,
        (sfVector2f){960, 700});
        hunter->where_am_i = START;
        hunter->life = 3;
        hunter->score = 0;
    }
}
