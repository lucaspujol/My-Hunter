/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void init_game_values(my_hunter_t *hunter)
{
    int fd = open(".high_score.txt", O_RDONLY);
    char *high_score = malloc(sizeof(char) * 10);

    for (int i = 0; i < 10; i++)
        high_score[i] = '\0';
    read(fd, high_score, 10);
    hunter->high_score = my_getnbr(high_score);
    hunter->difficulty = 2;
    hunter->score = 0;
    hunter->life = 3;
}

void init_text(my_hunter_t *hunter)
{
    init_game_values(hunter);
    hunter->move_clock = sfClock_create();
    hunter->move_time = sfClock_getElapsedTime(hunter->move_clock);
    hunter->move_seconds = hunter->move_time.microseconds / 1000000.0;
    hunter->game_speed = 0.04 / hunter->difficulty;
    hunter->score_str = malloc(sizeof(char) * 10);
    hunter->score_font = sfFont_createFromFile("assets/font/ARCADE_N.TTF");
    hunter->score_text = sfText_create();
    sfText_setFont(hunter->score_text, hunter->score_font);
    sfText_setCharacterSize(hunter->score_text, 50);
    sfText_setPosition(hunter->score_text, (sfVector2f){sfRenderWindow_getSize
        (hunter->window).x / 2 - 50 +
        sfText_getGlobalBounds(hunter->score_text).width / 2, 150});
    sfText_setFillColor(hunter->score_text, sfColor_fromRGB(0, 128, 0));
}

void init_cursor(my_hunter_t *hunter)
{
    hunter->mouse_texture = sfTexture_createFromFile
    ("assets/images/cursor.png", NULL);
    hunter->mouse_cursor = sfSprite_create();
    sfSprite_setTexture(hunter->mouse_cursor, hunter->mouse_texture, sfTrue);
    sfRenderWindow_setMouseCursorVisible(hunter->window, sfFalse);
    sfSprite_setOrigin(hunter->mouse_cursor, (sfVector2f)
        {sfSprite_getGlobalBounds(hunter->mouse_cursor).width / 2,
        sfSprite_getGlobalBounds(hunter->mouse_cursor).height / 2});
    sfSprite_setScale(hunter->mouse_cursor, (sfVector2f){0.1, 0.1});
}

void init_life_sprites(my_hunter_t *hunter)
{
    sfTexture *life_texture = sfTexture_createFromFile
    ("assets/images/heart.png", NULL);

    hunter->life_sprites = malloc(sizeof(sfSprite *) * 3);
    for (int i = 0; i < 3; i++) {
        hunter->life_sprites[i] = sfSprite_create();
        sfSprite_setTexture(hunter->life_sprites[i], life_texture, sfTrue);
        sfSprite_setScale(hunter->life_sprites[i], (sfVector2f){0.1, 0.1});
        sfSprite_setPosition(hunter->life_sprites[i], (sfVector2f)
            {sfRenderWindow_getSize(hunter->window).x - 1500 - i * 150, 50});
    }
}

void init_game(my_hunter_t *hunter)
{
    hunter->where_am_i = 0;
    hunter->where_was_i = 0;
    hunter->mode = (sfVideoMode){1920, 1080, 32};
    hunter->window = sfRenderWindow_create(hunter->mode, "My Hunter",
        sfClose, NULL);
    hunter->background_texture =
        sfTexture_createFromFile("assets/images/background.png", NULL);
    hunter->background = sfSprite_create();
    sfSprite_setTexture(hunter->background, hunter->background_texture,
        sfTrue);
    sfSprite_setScale(hunter->background, (sfVector2f){1.07, 1.05});
    init_buttons(hunter);
    hunter->clock = sfClock_create();
    init_ducks(hunter);
    init_text(hunter);
    init_cursor(hunter);
    init_sounds(hunter);
    init_life_sprites(hunter);
}
