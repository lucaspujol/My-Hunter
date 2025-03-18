/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void animate_menu_buttons_bis(my_hunter_t *hunter)
{
    for (int i = 9; i < 12; i++) {
        if (check_hovering(hunter, i)) {
            sfSprite_setScale(hunter->boutons[i]->sprite,
            (sfVector2f){13, 13});
            sfSprite_setColor(hunter->boutons[i]->sprite,
            sfColor_fromRGB(200, 200, 200));
        } else {
            sfSprite_setScale(hunter->boutons[i]->sprite,
            (sfVector2f){12, 12});
            sfSprite_setColor(hunter->boutons[i]->sprite,
            sfColor_fromRGB(255, 255, 255));
        }
    }
}

void animate_menu_buttons(my_hunter_t *hunter)
{
    if (check_hovering(hunter, 4)) {
        sfSprite_setScale(hunter->boutons[4]->sprite, (sfVector2f){6, 6});
        sfSprite_setColor(hunter->boutons[4]->sprite,
        sfColor_fromRGB(200, 200, 200));
    } else {
        sfSprite_setScale(hunter->boutons[4]->sprite, (sfVector2f){5, 5});
        sfSprite_setColor(hunter->boutons[4]->sprite,
        sfColor_fromRGB(255, 255, 255));
    }
    animate_menu_buttons_bis(hunter);
}
