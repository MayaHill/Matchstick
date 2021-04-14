/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** play_ai.c
*/

#include "../include/matchstick.h"

int get_biggest_line(board_t *board)
{
    int max_line = 0;
    int line = 0;
    int len = 0;

    for (int i = 1; board->map[i]; i++) {
        len = nb_char(board->map[i], '|');
        if (len >= max_line) {
            max_line = len;
            line = i;
        }
    }
    return (line);
}

int play_rand_game(char **map, int max_matches)
{
    int line = 0;
    int matches = 0;
    int player = 0;

    while (count_char_in_array(map, '|')) {
        if (player == 1)
            player = 0;
        else
            player = 1;
        line = get_rand_line(map);
        matches = get_rand_matches(map, line, max_matches);
        update_board(map, line, matches);
    }
    return (player);
}

void try_action(board_t *board, int *max_gain, action_t *max, action_t *turn)
{
    int gain = 0;
    int turns = 500;
    char **dup_map = NULL;

    for (int n = 0; n < turns; n++) {
        dup_map = duplicate_map(board->map);
        update_board(dup_map, turn->line, turn->matches);
        gain += play_rand_game(dup_map, board->max_matches);
        free_array(dup_map);
    }
    if (gain > (*max_gain)) {
        (*max_gain) = gain;
        max->line = turn->line;
        max->matches = turn->matches;
    }
}

void monte_carlo(board_t *board)
{
    action_t max;
    action_t turn;
    int max_gain = 0;
    int nb_matches = 0;
    int nb_lines = my_strlen_array(board->map) - 1;

    max.line = 0;
    max.matches = 0;
    for (turn.line = 1; turn.line < nb_lines; turn.line++) {
        nb_matches = nb_char(board->map[turn.line], '|');
        if (board->max_matches < nb_matches)
            nb_matches = board->max_matches;
        for (turn.matches = 1; turn.matches <= nb_matches; turn.matches++)
            try_action(board, &max_gain, &max, &turn);
    }
    if (max.matches == 0) {
        max.line = get_biggest_line(board);
        max.matches = 1;
    }
    print_updated_board(board, "AI", max.line, max.matches);
}

void play_ai(board_t *board)
{
    int line = 0;
    int matches = 0;

    my_printf("\nAI's turn...\n");
    if (count_char_in_array(board->map, '|') >= 100) {
        line = get_rand_line(board->map);
        matches = get_rand_matches(board->map, line, board->max_matches);
        print_updated_board(board, "AI", line, matches);
    } else
        monte_carlo(board);
}