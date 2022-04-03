/*
** SYSNAV PROJECT, 2022
** SYSNAV
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include "struct.h"
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>

    char **str_to_array(char *str, char delim);
    void free_to_exit(global_t *go, int status);
    void read_map(char *file, global_t *go);
    int count_words(char *str, char delim);
    void get_all_positions(global_t *go);
    int find_path(global_t *go);
    int left(global_t *go, int i, int j);
    int right(global_t *go, int i, int j);
    int down(global_t *go, int i, int j);
    int up(global_t *go, int i, int j);
    void spread_fire(global_t *go);
#endif /* !MY_H_ */
