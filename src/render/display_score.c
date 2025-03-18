/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void display_score(my_hunter_t *hunter)
{
    hunter->score_str = my_itoa(hunter->score);
    sfText_setString(hunter->score_text, hunter->score_str);
    sfRenderWindow_drawText(hunter->window, hunter->score_text, NULL);
}
