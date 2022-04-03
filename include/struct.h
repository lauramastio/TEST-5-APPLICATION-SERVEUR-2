/*
** SYSNAV PROJECT, 2022
** SYSNAV
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct global_s {
        char **grid;
        char *txt;
        int *player;
        int *fire;
        int *exits;
        int *farexit;
        char *path;
        int steps;
        int nbexits;
        int nblines;
        int nb;
    } global_t;

#endif /* !STRUCT_H_ */
