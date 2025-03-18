/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void handle_start_menu(my_hunter_t *hunter)
{
    if (is_in_global_bounds(hunter, 1)) {
        sfMusic_play(hunter->button_sound);
        hunter->where_was_i = hunter->where_am_i;
        hunter->where_am_i = GAME;
    }
    if (is_in_global_bounds(hunter, 2)) {
        sfMusic_play(hunter->button_sound);
        hunter->where_was_i = hunter->where_am_i;
        hunter->where_am_i = MENU;
    }
    if (is_in_global_bounds(hunter, 3)) {
        sfMusic_play(hunter->button_sound);
        hunter->where_was_i = hunter->where_am_i;
        sfRenderWindow_close(hunter->window);
    }
}
