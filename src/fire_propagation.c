/*
** EPITECH PROJECT, 2022
** SYSNAV
** File description:
** fire_propagation
*/

#include "../include/my.h"

static void replace_with_fire(global_t *go)
{
    for (int i = 0; i < go->nblines; i++) {
        for (int j = 0; j < strlen(go->grid[i]); j++) {
            if (go->grid[i][j] == 'O')
                go->grid[i][j] = 'F';
        }
    }
}

void spread_fire(global_t *go)
{
    for (int i = 0; i < go->nblines; i++) {
        for (int j = 0; j < strlen(go->grid[i]); j++) {
            if (go->grid[i][j] == 'F') {
                (i + 1 <= go->nblines) ? go->grid[i + 1][j] = 'O' : 0;
                (i - 1 >= 0) ? go->grid[i - 1][j] = 'O' : 0;
                (j + 1 <= strlen(go->grid[i])) ? go->grid[i][j + 1] = 'O' : 0;
                (j - 1 >= 0) ? go->grid[i][j - 1] = 'O' : 0;
            }
        }
    }
    replace_with_fire(go);
}
