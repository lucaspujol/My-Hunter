/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void toggle_pause_menu(my_hunter_t *hunter)
{
    if ((hunter->where_am_i == GAME || hunter->where_am_i == PAUSE)
    && is_in_global_bounds(hunter, 5)) {
        if (hunter->where_am_i == GAME) {
            sfMusic_play(hunter->button_sound);
            hunter->where_was_i = hunter->where_am_i;
            hunter->where_am_i = PAUSE;
        } else {
            sfMusic_play(hunter->button_sound);
            hunter->where_was_i = hunter->where_am_i;
            hunter->where_am_i = GAME;
        }
    }
}

void toggle_settings_menu(my_hunter_t *hunter)
{
    if (hunter->where_am_i != GAME && is_in_global_bounds(hunter, 6)) {
        sfMusic_play(hunter->button_sound);
        hunter->where_am_i = SETTINGS;
    }
}

void handle_settings_menu(my_hunter_t *hunter)
{
    if (is_in_global_bounds(hunter, 6)) {
        sfMusic_play(hunter->button_sound);
        hunter->where_am_i = hunter->where_was_i;
    }
}

void handle_menus(my_hunter_t *hunter)
{
    if (hunter->event.mouseButton.button == sfMouseLeft) {
        toggle_pause_menu(hunter);
        toggle_settings_menu(hunter);
        if (hunter->where_am_i == START)
            handle_start_menu(hunter);
        if (hunter->where_am_i == GAME)
            handle_game_menu(hunter);
        if (hunter->where_am_i == MENU)
            handle_menu_menu(hunter);
        if (hunter->where_am_i == PAUSE)
            handle_pause_menu(hunter);
        if (hunter->where_am_i == SETTINGS)
            handle_settings_menu(hunter);
        if (hunter->where_am_i == GAMEOVER)
            handle_gameover_menu(hunter);
    }
}
