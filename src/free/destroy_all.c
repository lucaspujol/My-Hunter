/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void destroy_game(my_hunter_t *hunter)
{
    sfRenderWindow_destroy(hunter->window);
    sfClock_destroy(hunter->clock);
    sfClock_destroy(hunter->move_clock);
    sfFont_destroy(hunter->score_font);
    sfText_destroy(hunter->score_text);
    sfSprite_destroy(hunter->background);
    sfTexture_destroy(hunter->background_texture);
    sfSprite_destroy(hunter->mouse_cursor);
    sfTexture_destroy(hunter->mouse_texture);
    sfMusic_destroy(hunter->button_sound);
    sfMusic_destroy(hunter->shot_sound);
}
