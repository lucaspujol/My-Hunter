/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../include/my_hunter.h"

void my_hunter(void)
{
    my_hunter_t *hunter = malloc(sizeof(my_hunter_t));

    init_game(hunter);
    while (sfRenderWindow_isOpen(hunter->window))
        run_game(hunter);
    free_all(hunter);
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_putstr("Welcome to My Hunter!\n\n");
        my_putstr("This is a Duck Hunt-like game.\n");
        my_putstr("You have to shoot the ducks to get points.\n");
        my_putstr("You have 3 lives. ");
        my_putstr("If you miss a duck, you lose a life. (duh)\n");
        my_putstr("You can change the difficulty in the menus.\n");
        my_putstr("You can pause the game by pressing the Escape key.\n");
        my_putstr("Good luck and have fun!\n");
        return 0;
    }
    my_hunter();
}
