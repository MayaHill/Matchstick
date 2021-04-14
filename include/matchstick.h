/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** matchstick.h
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

typedef struct board_s {
    char **map;
    int max_matches;
} board_t;

typedef struct action_s {
    int line;
    int matches;
} action_t;

int print_updated_board(board_t *board, char *player, int line, int nb_match);

char *my_read_getline(char *str);

int game_loop(board_t *board);

int my_strlen_array(char **array);

int nb_char(char *str, char c);

char **create_board(int lines);

int get_nb(char *str);

void play_ai(board_t *board);

int player_turn(board_t *board);

int count_char_in_array(char **board, char c);

void fill_str(char *str, char c, int len);

char **duplicate_map(char **map);

void free_array(char **array);

int get_rand_line(char **map);

int get_rand_matches(char **map, int line, int max);

void update_board(char **map, int line, int matches);