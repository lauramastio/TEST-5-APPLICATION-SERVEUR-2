/*
** SYSNAV PROJECT, 2022
** SYSNAV
** File description:
** get_positions
*/

#include "../include/my.h"

static int find_nb_exits(char **grid, int lines)
{
    int nb_of_exits = 0;
    int nb_of_players = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < strlen(grid[i]); j++) {
            if (grid[i][j] == 'E')
                nb_of_exits++;
            if (grid[i][j] == 'S')
                nb_of_players++;
        }
    }
    if (nb_of_players != 1) // minor error handling -> only one player is allowed
        exit (84);
    return nb_of_exits;
}

void get_all_positions(global_t *go)
{
    go->nbexits = find_nb_exits(go->grid, go->nblines);
    int x = 0; //counter for exits

    go->exits = malloc(sizeof(int) * (go->nbexits * 2));
    go->player = malloc(sizeof(int) * 2);
    go->fire = malloc(sizeof(int) * 2);

    for (int i = 0; i < go->nblines; i++) {
        for (int j = 0; j < strlen(go->grid[i]); j++) {
            if (go->grid[i][j] == 'S') {
                go->player[0] = i;
                go->player[1] = j;
            }
            if (go->grid[i][j] == 'F') {
                go->fire[0] = i;
                go->fire[1] = j;
            }
            if (go->grid[i][j] == 'E') {
                go->exits[x] = i;
                go->exits[x + 1] = j;
                x += 2;
            }
        }
    }
}
