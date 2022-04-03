/*
** SYSNAV PROJECT, 2022
** SYSNAV
** File description:
** movements
*/

#include "../include/my.h"

static void add_letter(global_t *go, char c)
{
    go->path = realloc(go->path, sizeof(char) * go->nb + 1);
    go->path[go->nb - 1] = c;
    go->path[go->nb] = '\0';
    go->nb++;
}

int up(global_t *go, int i, int j)
{
    if (go->grid[i - 1][j] == '.' || go->grid[i - 1][j] == 'E') {
        go->grid[i - 1][j] = 'S';
        go->player[0] = i - 1;
        add_letter(go, 'U');
    }
    else
        return 84;
}

int down(global_t *go, int i, int j)
{
    if (go->grid[i + 1][j] == '.' || go->grid[i + 1][j] == 'E') {
        go->grid[i + 1][j] = 'S';
        go->player[0] = i + 1;
        add_letter(go, 'D');
    }
    else
        return 84;
}

int right(global_t *go, int i, int j)
{
    if (go->grid[i][j + 1] == '.' || go->grid[i][j + 1] == 'E') {
        go->grid[i][j + 1] = 'S';
        go->player[1] = j + 1;
        add_letter(go, 'R');
    }
    else
        return 84;
}

int left(global_t *go, int i, int j)
{
    if (go->grid[i][j - 1] == '.' || go->grid[i][j - 1] == 'E') {
        go->grid[i][j - 1] = 'S';
        go->player[1] = j - 1;
        add_letter(go, 'L');
    }
    else
        return 84;
}
