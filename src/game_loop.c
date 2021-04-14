/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** read_print.c
*/

#include "../include/matchstick.h"

int print_updated_board(board_t *board, char *player, int line, int nb_matches)
{
    int matches = nb_matches;
    char **map = board->map;

    if (nb_matches <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (player_turn(board));
    }
    for (int i = my_strlen(map[line]); i > 0 && nb_matches > 0; i--)
        if (map[line][i] == '|') {
            map[line][i] = ' ';
            nb_matches--;
        }
    my_printf("%s removed %d match(es) from line %d\n", player, matches, line);
    for (int i = 0; map[i]; i++)
        my_printf("%s\n", map[i]);
    return (0);
}

int print_error(char *msg, board_t *board)
{
    my_printf("%s\n", msg);
    return (player_turn(board));
}

int player_turn_matches(board_t *board, char *error, int line)
{
    char *read_matches = my_read_getline("Matches: ");
    int nb_matches = 0;

    if (read_matches == NULL)
        return (-1);
    nb_matches = get_nb(read_matches);
    free(read_matches);
    if (nb_matches == -1)
        return (print_error(error, board));
    if (nb_char(board->map[line], '|') < nb_matches) {
        my_printf("Error: not enough matches on this line\n");
        return (player_turn(board));
    }
    if (nb_matches > board->max_matches) {
        my_printf("Error: you cannot remove more ");
        my_printf("than %d matches per turn\n", board->max_matches);
        return (player_turn(board));
    }
    return (print_updated_board(board, "Player", line, nb_matches));
}

int player_turn(board_t *board)
{
    int line = 0;
    char *error = "Error: invalid input (positive number expected)";
    char *read_line = my_read_getline("Line: ");

    if (read_line == NULL)
        return (-1);
    line = get_nb(read_line);
    free(read_line);
    if (line == -1)
        return (print_error(error, board));
    if (line >= my_strlen_array(board->map) || line <= 0)
        return (print_error("Error: this line is out of range", board));
    return (player_turn_matches(board, error, line));
}

int game_loop(board_t *board)
{
    my_printf("\nYour turn:\n");
    if (player_turn(board) == -1)
        return (0);
    if (count_char_in_array(board->map, '|') == 0)
        return (2);
    play_ai(board);
    if (count_char_in_array(board->map, '|') == 0)
        return (1);
    return (game_loop(board));
}