/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void handle_pause_menu(my_hunter_t *hunter)
{
    if (is_in_global_bounds(hunter, 2)) {
        sfMusic_play(hunter->button_sound);
        hunter->where_am_i = START;
        hunter->score = 0;
        hunter->life = 3;
    }
}
