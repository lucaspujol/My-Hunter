/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

char *bis(int num, char *str, int is_negative, int rem)
{
    int i = 0;

    if (num < 0) {
        is_negative = 1;
        num = ~num + 1;
    }
    while (num != 0) {
        rem = num % 10;
        str[i] = rem + '0';
        i++;
        num = num / 10;
    }
    if (is_negative) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}

// ptdrrrrr nb = ~nb + 1 c'est goofy de ouf
char *my_itoa(int num)
{
    int i = 0;
    int is_negative = 0;
    char *str = malloc(sizeof(char) * 12);
    int rem = 0;

    if (!str)
        return NULL;
    if (num == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
    return bis(num, str, is_negative, rem);
}
