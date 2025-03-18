/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

image_t *create_bouton(char *path, sfVector2f position, sfVector2f scale)
{
    image_t *bouton = malloc(sizeof(image_t));

    bouton->texture = sfTexture_createFromFile(path, NULL);
    bouton->sprite = sfSprite_create();
    sfSprite_setTexture(bouton->sprite, bouton->texture, sfTrue);
    bouton->position = position;
    sfSprite_setPosition(bouton->sprite, position);
    sfSprite_setOrigin(bouton->sprite, (sfVector2f)
        {sfSprite_getGlobalBounds(bouton->sprite).width / 2,
        sfSprite_getGlobalBounds(bouton->sprite).height / 2});
    sfSprite_setScale(bouton->sprite, scale);
    return bouton;
}
