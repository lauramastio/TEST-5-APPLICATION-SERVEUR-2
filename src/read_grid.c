/*
** SYSNAV PROJECT, 2022
** SYSNAV
** File description:
** read_grid
*/

#include "../include/my.h"

//return value of 84 is a Epitech norm for errors

void read_map(char *file, global_t *go)
{
    int fd = open(file, O_RDONLY);
    struct stat buf;
    int size;

    stat(file, &buf);
    size = buf.st_size;
    if (fd == -1)
        exit(84);
    go->txt = malloc(sizeof(char) * size + 1);
    read(fd, go->txt, size);
    close(fd);
    go->txt[size] = '\0';
    return;
}
