/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"


void init_sounds(my_hunter_t *hunter)
{
    hunter->button_sound = sfMusic_createFromFile
    ("assets/music/button_click.wav");
    hunter->shot_sound = sfMusic_createFromFile("assets/music/shot_sound.mp3");
    hunter->gameover_sound = sfMusic_createFromFile
    ("assets/music/gameover_sound.wav");
    sfMusic_setVolume(hunter->gameover_sound, 50);
    hunter->power_up_sound = sfMusic_createFromFile
    ("assets/music/power_up_sound.wav");
    hunter->main_theme_1 = sfMusic_createFromFile
    ("assets/music/Desert Theme - New Super Mario Bros. Wii.mp3");
    sfMusic_setLoop(hunter->main_theme_1, sfTrue);
    sfMusic_play(hunter->main_theme_1);
}
