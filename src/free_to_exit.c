/*
** SYSNAV PROJECT, 2022
** SYSNAV
** File description:
** free_to_exit
*/

#include "../include/my.h"

static void free_array(char **array, int lines)
{
    for (int i = 0; i < lines; i++)
        free(array[i]);
    free(array);
}

void free_to_exit(global_t *go, int status)
{
    (go->grid != NULL) ? free_array(go->grid, go->nblines) : 0;
    (go->txt != NULL) ? free(go->txt) : 0;
    (go->exits != NULL) ? free(go->exits) : 0;
    (go->player != NULL) ? free(go->player) : 0;
    (go->fire != NULL) ? free(go->fire) : 0;
    (go->farexit != NULL) ? free(go->farexit) : 0;
    (go->path != NULL) ? free(go->path) : 0;
    (go != NULL) ? free(go) : 0;
    exit(status);
}