/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

int check_hovering(my_hunter_t *hunter, int i)
{
    if (hunter->event.mouseMove.x >= sfSprite_getGlobalBounds(
        hunter->boutons[i]->sprite).left &&
        hunter->event.mouseMove.x <= sfSprite_getGlobalBounds(
        hunter->boutons[i]->sprite).left + sfSprite_getGlobalBounds(
        hunter->boutons[i]->sprite).width &&
        hunter->event.mouseMove.y >= sfSprite_getGlobalBounds(
        hunter->boutons[i]->sprite).top &&
        hunter->event.mouseMove.y <= sfSprite_getGlobalBounds(
        hunter->boutons[i]->sprite).top + sfSprite_getGlobalBounds(
        hunter->boutons[i]->sprite).height)
        return 1;
    return 0;
}

void animate_start_menu_buttons(my_hunter_t *hunter)
{
    for (int i = 1; i < 4; i++) {
        if (check_hovering(hunter, i)) {
            sfSprite_setScale(hunter->boutons[i]->sprite, (sfVector2f){8, 8});
            sfSprite_setColor(hunter->boutons[i]->sprite,
            sfColor_fromRGB(200, 200, 200));
        } else {
            sfSprite_setScale(hunter->boutons[i]->sprite, (sfVector2f){7, 7});
            sfSprite_setColor(hunter->boutons[i]->sprite,
            sfColor_fromRGB(255, 255, 255));
        }
    }
}

void animate_game_buttons(my_hunter_t *hunter)
{
    if (check_hovering(hunter, 5)) {
        sfSprite_setScale(hunter->boutons[5]->sprite, (sfVector2f){6, 6});
        sfSprite_setColor(hunter->boutons[5]->sprite,
        sfColor_fromRGB(200, 200, 200));
    } else {
        sfSprite_setScale(hunter->boutons[5]->sprite, (sfVector2f){5, 5});
        sfSprite_setColor(hunter->boutons[5]->sprite,
        sfColor_fromRGB(255, 255, 255));
    }
}

void is_hovering_buttons(my_hunter_t *hunter)
{
    if (hunter->where_am_i == START || hunter->where_am_i == PAUSE)
        animate_start_menu_buttons(hunter);
    if (hunter->where_am_i == MENU)
        animate_menu_buttons(hunter);
    if (hunter->where_am_i == GAME)
        animate_game_buttons(hunter);
    if (hunter->where_am_i == GAMEOVER) {
        animate_start_menu_buttons(hunter);
        if (check_hovering(hunter, 7)) {
            sfSprite_setScale(hunter->boutons[7]->sprite, (sfVector2f){8, 8});
            sfSprite_setColor(hunter->boutons[7]->sprite,
            sfColor_fromRGB(200, 200, 200));
        } else {
            sfSprite_setScale(hunter->boutons[7]->sprite, (sfVector2f){7, 7});
            sfSprite_setColor(hunter->boutons[7]->sprite,
            sfColor_fromRGB(255, 255, 255));
        }
    }
}
