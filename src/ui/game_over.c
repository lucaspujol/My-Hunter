/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void display_score_gameover(my_hunter_t *hunter)
{
    char base_msg[50] = "Your score: ";
    char *score_str = my_itoa(hunter->score);

    my_strcat(base_msg, score_str);
    sfText_setString(hunter->score_text, base_msg);
    sfText_setPosition(hunter->score_text, (sfVector2f){
        sfRenderWindow_getSize(hunter->window).x / 2 -
        sfText_getGlobalBounds(hunter->score_text).width / 2, 440});
    sfRenderWindow_drawText(hunter->window, hunter->score_text, NULL);
    sfText_setPosition(hunter->score_text, (sfVector2f){sfRenderWindow_getSize
        (hunter->window).x / 2 - 50 +
        sfText_getGlobalBounds(hunter->score_text).width / 2, 150});
}

void display_high_score_gameover(my_hunter_t *hunter)
{
    char base_msg[50] = "High score: ";
    char *score_str = my_itoa(hunter->high_score);

    my_strcat(base_msg, score_str);
    sfText_setCharacterSize(hunter->score_text, 35);
    sfText_setString(hunter->score_text, base_msg);
    sfText_setPosition(hunter->score_text, (sfVector2f){
        sfRenderWindow_getSize(hunter->window).x / 2 -
        sfText_getGlobalBounds(hunter->score_text).width / 2, 500});
    sfRenderWindow_drawText(hunter->window, hunter->score_text, NULL);
    sfText_setPosition(hunter->score_text, (sfVector2f){sfRenderWindow_getSize
        (hunter->window).x / 2 - 50, 150});
    sfText_setCharacterSize(hunter->score_text, 50);
}

void display_gameover(my_hunter_t *hunter)
{
    sfRenderWindow_drawSprite(hunter->window, hunter->boutons[8]->sprite,
    NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->boutons[7]->sprite,
    NULL);
    sfSprite_setPosition(hunter->boutons[2]->sprite, (sfVector2f){960, 850});
    sfRenderWindow_drawSprite(hunter->window, hunter->boutons[2]->sprite,
    NULL);
    display_score_gameover(hunter);
    display_high_score_gameover(hunter);
    save_high_score(hunter);
}
