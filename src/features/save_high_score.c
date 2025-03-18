/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "../../include/my_hunter.h"

void save_high_score(my_hunter_t *hunter)
{
    int fd = open(".high_score.txt", O_WRONLY | O_CREAT, 0644);
    char *high_score = my_itoa(hunter->score);

    if (fd == -1)
        return;
    if (hunter->score > hunter->high_score) {
        hunter->high_score = hunter->score;
        write(fd, high_score, my_strlen(high_score));
    }
    close(fd);
}
