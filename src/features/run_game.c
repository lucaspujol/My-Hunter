/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void pause_with_escape(my_hunter_t *hunter)
{
    if ((hunter->where_am_i == GAME || hunter->where_am_i == PAUSE)) {
        if (hunter->where_am_i == GAME) {
            hunter->where_was_i = hunter->where_am_i;
            sfMusic_play(hunter->button_sound);
            hunter->where_am_i = PAUSE;
        } else {
            sfMusic_play(hunter->button_sound);
            hunter->where_was_i = hunter->where_am_i;
            hunter->where_am_i = GAME;
        }
    }
}

void analyse_event(my_hunter_t *hunter)
{
    while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
        hunter->mouse_pos = sfMouse_getPositionRenderWindow(hunter->window);
        sfSprite_setPosition(hunter->mouse_cursor, (sfVector2f)
            {hunter->mouse_pos.x, hunter->mouse_pos.y});
        if (hunter->event.type == sfEvtClosed)
            sfRenderWindow_close(hunter->window);
        if (hunter->event.type == sfEvtMouseMoved)
            is_hovering_buttons(hunter);
        if (hunter->event.type == sfEvtMouseButtonPressed)
            handle_menus(hunter);
        if (hunter->event.type == sfEvtKeyPressed &&
        hunter->event.key.code == sfKeyEscape)
            pause_with_escape(hunter);
        if (konami_code(hunter) == 1) {
            sfMusic_play(hunter->power_up_sound);
            hunter->score += 1000;
            hunter->life = 3;
        }
    }
}

void run_game(my_hunter_t *hunter)
{
    analyse_event(hunter);
    display_game(hunter);
}
