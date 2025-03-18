/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void handle_difficulty_bis(my_hunter_t *hunter)
{
    if (is_in_global_bounds(hunter, 11)) {
        sfMusic_play(hunter->button_sound);
        hunter->difficulty = 4;
        hunter->game_speed = 0.04 / hunter->difficulty;
        sfSprite_setTexture(hunter->boutons[11]->sprite, hunter->hard_active,
        sfTrue);
        sfSprite_setTexture(hunter->boutons[9]->sprite,
        sfTexture_createFromFile("assets/images/easy.png", NULL), sfTrue);
        sfSprite_setTexture(hunter->boutons[10]->sprite,
        sfTexture_createFromFile("assets/images/mid.png", NULL), sfTrue);
    }
}

void handle_difficulty(my_hunter_t *hunter)
{
    if (is_in_global_bounds(hunter, 10)) {
        sfMusic_play(hunter->button_sound);
        hunter->difficulty = 3;
        hunter->game_speed = 0.04 / hunter->difficulty;
        sfSprite_setTexture(hunter->boutons[10]->sprite, hunter->mid_active,
        sfTrue);
        sfSprite_setTexture(hunter->boutons[9]->sprite,
        sfTexture_createFromFile("assets/images/easy.png", NULL), sfTrue);
        sfSprite_setTexture(hunter->boutons[11]->sprite,
        sfTexture_createFromFile("assets/images/hard.png", NULL), sfTrue);
    }
    handle_difficulty_bis(hunter);
}

void reset_ducks_after_menu(my_hunter_t *hunter)
{
    for (int i = 0; i < 7; i++) {
        hunter->ducks[i]->position = (sfVector2f){-(rand() % 1920),
        rand() % 1080};
        sfSprite_setPosition(hunter->ducks[i]->sprite,
        hunter->ducks[i]->position);
    }
}

void handle_menu_menu(my_hunter_t *hunter)
{
    if (is_in_global_bounds(hunter, 4)) {
        sfMusic_play(hunter->button_sound);
        hunter->where_was_i = hunter->where_am_i;
        hunter->where_am_i = START;
        reset_ducks_after_menu(hunter);
    }
    if (is_in_global_bounds(hunter, 9)) {
        sfMusic_play(hunter->button_sound);
        hunter->difficulty = 2;
        hunter->game_speed = 0.04 / hunter->difficulty;
        sfSprite_setTexture(hunter->boutons[9]->sprite, hunter->easy_active,
        sfTrue);
        sfSprite_setTexture(hunter->boutons[10]->sprite,
        sfTexture_createFromFile("assets/images/mid.png", NULL), sfTrue);
        sfSprite_setTexture(hunter->boutons[11]->sprite,
        sfTexture_createFromFile("assets/images/hard.png", NULL), sfTrue);
    }
    handle_difficulty(hunter);
}
