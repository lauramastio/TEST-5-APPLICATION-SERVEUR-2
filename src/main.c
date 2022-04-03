/*
** SYSNAV PROJECT, 2022
** SYSNAV
** File description:
** main
*/

#include "../include/my.h"

static void initialize_map(global_t *go, char *filename)
{
    read_map(filename, go);
    go->nblines = count_words(go->txt, '\n');
    go->grid = str_to_array(go->txt, '\n');
    get_all_positions(go);
}

int main(int ac, char **av)
{
    global_t *go = malloc(sizeof(global_t));

    if (ac != 2)
        return 1;
    initialize_map(go, av[1]);
    find_path(go);
    printf("Solution possible:\n%s\n", go->path);
    free_to_exit(go, 0);
}
