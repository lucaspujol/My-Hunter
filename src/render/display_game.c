/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void draw_start(my_hunter_t *hunter)
{
    animate_logo(hunter);
    sfSprite_setPosition(hunter->boutons[2]->sprite, (sfVector2f){960, 700});
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(hunter->window,
            hunter->boutons[i]->sprite, NULL);
}

void draw_menu(my_hunter_t *hunter)
{
    sfRenderWindow_drawSprite(hunter->window, hunter->boutons[4]->sprite,
        NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->boutons[9]->sprite,
        NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->boutons[10]->sprite,
        NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->boutons[11]->sprite,
        NULL);
}

void draw_pause(my_hunter_t *hunter)
{
    sfRenderWindow_drawSprite(hunter->window, hunter->boutons[2]->sprite,
        NULL);
}

void draw_settings(my_hunter_t *hunter)
{
    hunter->background_texture = sfTexture_createFromFile
    ("assets/images/settings_background.png", NULL);
    sfSprite_setTexture(hunter->background, hunter->background_texture,
    sfTrue);
    sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
}

void display_game(my_hunter_t *hunter)
{
    sfRenderWindow_clear(hunter->window, sfBlack);
    sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
    if (hunter->where_am_i == GAME || hunter->where_am_i == PAUSE
    || hunter->where_am_i == GAMEOVER)
        render_game(hunter);
    if (hunter->where_am_i == START)
        draw_start(hunter);
    if (hunter->where_am_i == MENU)
        draw_menu(hunter);
    if (hunter->where_am_i == PAUSE)
        draw_pause(hunter);
    if (hunter->where_am_i == GAMEOVER)
        display_gameover(hunter);
    sfRenderWindow_drawSprite(hunter->window, hunter->mouse_cursor, NULL);
    sfRenderWindow_display(hunter->window);
}
