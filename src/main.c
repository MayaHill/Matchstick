/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main.c
*/

#include "../include/matchstick.h"
#include <time.h>

void print_end_message(int winner)
{
    if (winner == 2)
        my_printf("You lost, too bad...\n");
    else if (winner == 1)
        my_printf("I lost... snif... but I'll get you next time!!\n");
}

int main(int argc, char **argv)
{
    int nb_lines = 0;
    int nb_matches = 0;
    int winner = 0;
    board_t board;

    srand(time(0));
    if (argc != 3)
        return (84);
    nb_lines = get_nb(argv[1]);
    nb_matches = get_nb(argv[2]);
    if (nb_lines <= 0 || nb_matches <= 0 || nb_lines >= 100)
        return (84);
    board.map = create_board(my_getnbr(argv[1]));
    board.max_matches = nb_matches;
    winner = game_loop(&board);
    free_array(board.map);
    print_end_message(winner);
    return (winner);
}