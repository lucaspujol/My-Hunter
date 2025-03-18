/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void init_boutons_of_menus(my_hunter_t *hunter)
{
    hunter->boutons[9] = create_bouton("assets/images/easy_active.png",
        (sfVector2f){sfRenderWindow_getSize(hunter->window).x / 2,
        sfRenderWindow_getSize(hunter->window).y / 2 - 385},
        (sfVector2f){12.0, 12.0});
    hunter->boutons[10] = create_bouton("assets/images/mid.png",
        (sfVector2f){sfRenderWindow_getSize(hunter->window).x / 2,
        sfRenderWindow_getSize(hunter->window).y / 2 - 215},
        (sfVector2f){12.0, 12.0});
    hunter->boutons[11] = create_bouton("assets/images/hard.png",
        (sfVector2f){sfRenderWindow_getSize(hunter->window).x / 2,
        sfRenderWindow_getSize(hunter->window).y / 2 - 50},
        (sfVector2f){12.0, 12.0});
    hunter->easy_active = sfTexture_createFromFile
    ("assets/images/easy_active.png", NULL);
    hunter->mid_active = sfTexture_createFromFile
    ("assets/images/mid_active.png", NULL);
    hunter->hard_active = sfTexture_createFromFile
    ("assets/images/hard_active.png", NULL);
}

void init_buttons_bis(my_hunter_t *hunter)
{
    hunter->boutons[4] = create_bouton("assets/images/arrow.png",
        (sfVector2f){150, 830}, (sfVector2f){5, 5});
    hunter->boutons[5] = create_bouton("assets/images/pause.png",
        (sfVector2f){1770, 150}, (sfVector2f){5, 5});
    hunter->boutons[6] = create_bouton("assets/images/settings.png",
        (sfVector2f){150, 150}, (sfVector2f){0.4, 0.4});
    hunter->boutons[7] = create_bouton("assets/images/restart.png",
        (sfVector2f){960, 750}, (sfVector2f){7, 7});
    hunter->boutons[8] = create_bouton("assets/images/game_over.png",
        (sfVector2f){960, 270}, (sfVector2f){0.4, 0.4});
    init_boutons_of_menus(hunter);
}

void init_buttons(my_hunter_t *hunter)
{
    hunter->boutons = malloc(sizeof(image_t *) * 12);
    hunter->boutons[0] = create_bouton("assets/images/logo.png", (sfVector2f)
        {sfRenderWindow_getSize(hunter->window).x / 2,
        (sfRenderWindow_getSize(hunter->window).y / 2 - 250)},
        (sfVector2f){12.0, 12.0});
    hunter->boutons[1] = create_bouton("assets/images/play_button.png",
        (sfVector2f){960, 600}, (sfVector2f){7, 7});
    hunter->boutons[2] = create_bouton("assets/images/menu_button.png",
        (sfVector2f){960, 700}, (sfVector2f){7, 7});
    hunter->boutons[3] = create_bouton("assets/images/exit_button.png",
        (sfVector2f){960, 800}, (sfVector2f){7, 7});
    init_buttons_bis(hunter);
}
