/*
** SYSNAV PROJECT, 2022
** B-PSU-101-STG-1-1-minishell1-laura.mastio
** File description:
** my_str_to_word_array
*/

#include "../include/my.h"

//return value of 84 is a Epitech norm for errors

int count_words(char *str, char delim)
{
    int nb = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == delim)
            nb++;
    }
    nb++;
    return nb;
}

static int *lengths_tab(char *str, char delim, int nb)
{
    int *lens = malloc(sizeof(int) * nb);
    int y = 0;

    (lens == NULL) ? exit(84) : 0;
    for (int x = 0; x < nb; lens[x] = 0, x++);
    for (int i = 0; str[i] != '\0'; i++)
        (str[i] == delim) ? y++ : lens[y]++;
    return lens;
}

char **str_to_array(char *str, char delim)
{
    char **tab;
    int nb = count_words(str, delim);
    int *lens = lengths_tab(str, delim, nb);

    tab = malloc(sizeof(char *) * nb + 1);
    (tab == NULL) ? exit(84) : 0;
    for (int i = 0; i < nb; i++) {
        tab[i] = malloc(sizeof(char) * lens[i] + 1);
        (tab[i] == NULL) ? exit(84) : 0;
        for (int j = 0; j < lens[i]; tab[i][j] = str[j], j++ );
        tab[i][lens[i]] = '\0';
        str = &str[lens[i] + 1];
    }
    free(lens);
    return tab;
}
