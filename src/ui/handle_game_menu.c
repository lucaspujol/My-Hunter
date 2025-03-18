/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

int hande_game_menu_bis(my_hunter_t *hunter, int i)
{
    if (hunter->event.mouseButton.x >= sfSprite_getGlobalBounds(
        hunter->ducks[i]->sprite).left && hunter->event.mouseButton.x
        <= sfSprite_getGlobalBounds(hunter->ducks[i]->sprite).left
        + sfSprite_getGlobalBounds(hunter->ducks[i]->sprite).width &&
        hunter->event.mouseButton.y >= sfSprite_getGlobalBounds
        (hunter->ducks[i]->sprite).top && hunter->event.mouseButton.y
        <= sfSprite_getGlobalBounds(hunter->ducks[i]->sprite).top
        + sfSprite_getGlobalBounds(hunter->ducks[i]->sprite).height) {
        hunter->ducks[i]->position.x = -rand() % 1920;
        hunter->ducks[i]->position.y = rand() % 1080;
        if (hunter->ducks[i]->position.y < 220)
            hunter->ducks[i]->position.y += 220;
        if (hunter->ducks[i]->position.y > 1080 - 220)
            hunter->ducks[i]->position.y -= 220;
        sfSprite_setPosition(hunter->ducks[i]->sprite,
            hunter->ducks[i]->position);
        hunter->score += 1;
        return 1;
    }
    return 0;
}

void handle_game_menu(my_hunter_t *hunter)
{
    sfMusic_play(hunter->shot_sound);
    for (int i = 0; i < 7; i++) {
        if (hande_game_menu_bis(hunter, i) == 1) {
            break;
        }
    }
}
