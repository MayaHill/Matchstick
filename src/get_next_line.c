/*
** EPITECH PROJECT, 2020
** Minishell1
** File description:
** main.c
*/

#include "../include/matchstick.h"

char *my_read_getline(char *str)
{
    char *line = NULL;
    size_t len = 0;

    my_printf("%s", str);
    while (getline(&line, &len, stdin) != -1) {
        if (line != NULL) {
            line[my_strlen(line)] = 0;
            return (line);
        }
    }
    return (NULL);
}