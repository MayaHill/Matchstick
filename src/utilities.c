/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** utilities.c
*/

#include "../include/matchstick.h"

int my_strlen_array(char **array)
{
    int len = 0;

    for (; array[len]; len++);
    return (len);
}

int nb_char(char *str, char c)
{
    int nb = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            nb++;
    return (nb);
}

int count_char_in_array(char **board, char c)
{
    int nb = 0;

    for (int i = 0; board[i]; i++)
        nb += nb_char(board[i], c);
    return (nb);
}

int get_nb(char *str)
{
    if (str == NULL)
        return (-1);
    for (int i = 0; str[i]; i++)
        if (str[i] != '\n' && (str[i] < '0' || str[i] > '9'))
            return (-1);
    return (my_getnbr(str));
}