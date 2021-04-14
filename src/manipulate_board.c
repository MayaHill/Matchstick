/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** manipulate_board.c
*/

#include "../include/matchstick.h"

void update_board(char **map, int line, int matches)
{
    for (int i = my_strlen(map[line]); i > 0 && matches > 0; i--)
        if (map[line][i] == '|') {
            map[line][i] = ' ';
            matches--;
        }
}

char **duplicate_map(char **map)
{
    int len = my_strlen_array(map);
    char **dup_map = malloc(sizeof(char *) * (len + 1));

    dup_map[len] = NULL;
    for (int i = 0; map[i]; i++)
        dup_map[i] = my_strdup(map[i]);
    return (dup_map);
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

int get_rand_line(char **map)
{
    int len = my_strlen_array(map);
    int nbr = 0;

    while (nb_char(map[nbr], '|') == 0)
        nbr = (rand() % len - 1) + 1;
    return (nbr);
}

int get_rand_matches(char **map, int line, int max)
{
    int max_matches = nb_char(map[line], '|');
    int nbr = 0;

    if (max < max_matches)
        max_matches = max;
    if (max_matches == 1)
        return (1);
    nbr = (rand() % max_matches) + 1;
    return (nbr);
}