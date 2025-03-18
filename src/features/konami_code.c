/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

sfKeyCode const konami_sequence[10] = {
    sfKeyUp, sfKeyUp, sfKeyDown, sfKeyDown,
    sfKeyLeft, sfKeyRight, sfKeyLeft, sfKeyRight,
    sfKeyB, sfKeyA
};

int is_konami_code(int *input_index)
{
    if (*input_index == 10) {
        *input_index = 0;
        return 1;
    }
    return 0;
}

int konami_code(my_hunter_t *hunter)
{
    static sfKeyCode user_input[10] = {0};
    static int input_index = 0;
    int return_value = 0;

    if (hunter->event.type == sfEvtKeyPressed) {
        user_input[input_index] = hunter->event.key.code;
        if (user_input[input_index] == konami_sequence[input_index]) {
            input_index++;
            return_value = is_konami_code(&input_index);
        } else {
            input_index = 0;
        }
    }
    return return_value;
}
