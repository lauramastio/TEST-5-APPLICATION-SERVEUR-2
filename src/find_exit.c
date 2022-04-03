/*
** SYSNAV PROJECT, 2022
** SYSNAV
** File description:
** find_exit
*/

#include "../include/my.h"

static void check_burned(global_t *go)
{
    if (go->grid[go->player[0]][go->player[1]] == 'F')
        free_to_exit (go, 1);
}

static void find_farthest(global_t *go)
{
    go->farexit = malloc(sizeof(int) * 2);
    go->farexit[0] = 0;
    go->farexit[1] = 0;

    for (int a = 0; a < (go->nbexits * 2); a += 2) {
        if (abs(go->exits[a] - go->fire[0]) >= go->farexit[0] ||
        abs(go->exits[a + 1] - go->fire[1]) >= go->farexit[1]) {
            go->farexit[0] = go->exits[a];
            go->farexit[1] = go->exits[a + 1];
        }
    }
}

static void go_to_farthest(global_t *go)
{
    int steps;

    for (steps = 0; go->grid[go->farexit[0]][go->farexit[1]] != 'S'; steps++) {
        if (go->player[0] > go->farexit[0])
            up(go, go->player[0], go->player[1]);
        else if (go->player[0] < go->farexit[0])
            down(go, go->player[0], go->player[1]);
        else if (go->player[1] > go->farexit[1])
            left(go, go->player[0], go->player[1]);
        else if (go->player[1] < go->farexit[1])
            right(go, go->player[0], go->player[1]);
        spread_fire(go);
        check_burned(go);
    }
    go->steps = steps;
}

int find_path(global_t *go)
{
    find_farthest(go);
    go->nb = 1;
    go->path = malloc(sizeof(char) * go->nb);
    go_to_farthest(go);
}

