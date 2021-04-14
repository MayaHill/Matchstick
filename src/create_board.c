/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** create_board.c
*/

#include "../include/matchstick.h"

void fill_str(char *str, char c, int len)
{
    for (int i = 0; i < len - 1; i++)
        str[i] = c;
}

void print_array(char **array)
{
    for (int i = 0; array[i]; i++)
        my_printf("%s\n", array[i]);
}

void add_matches(char *line, int nb_spaces)
{
    int len = my_strlen(line) - 1;

    for (int i = 1 + nb_spaces; i < len - nb_spaces; i++)
        line[i] = '|';
}

char **create_board(int lines)
{
    char **board = malloc(sizeof(char *) * (lines + 3));
    int len = (lines * 2) + 2;
    int nb_spaces = 0;

    board[lines + 2] = NULL;
    for (int i = 0; i <= lines + 1; i++) {
        board[i] = malloc(sizeof(char) * len);
        board[i][len - 1] = 0;
    }
    fill_str(board[0], '*', len);
    for (int i = lines; i >= 1; i--, nb_spaces += 1) {
        fill_str(board[i], ' ', len);
        board[i][0] = '*';
        board[i][len - 2] = '*';
        add_matches(board[i], nb_spaces);
    }
    fill_str(board[lines + 1], '*', len);
    print_array(board);
    return (board);
}