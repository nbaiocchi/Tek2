/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** str_array
*/

#include "../../include/my.h"

char **malloc_res(char **res, int nb_arg, int lg)
{
    res = malloc(sizeof(char *) * (nb_arg + 1));

    for (int i = 0; i != nb_arg; i += 1)
        res[i] = malloc(sizeof(char) * (lg + 2));
    res[nb_arg - 1] = NULL;
    return (res);
}

char **fill_res(char **res, char *str, char divisor)
{
    int i = 0;
    int a = 0;
    int b = 0;

    while (str[i + 1] != '\0') {
        if (str[i] == divisor && str[i + 1] != divisor) {
            res[a][b] = '\0';
            a += 1;
            b = 0;
        } else {
            res[a][b] = str[i];
            b += 1;
        }
        i += 1;
    }
    res[a][b] = str[i];
    res[a][b + 1] = '\0';
    return (res);
}

bool contains_space(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == ' ')
            return (true);
    }
    return (false);
}

char **str_to_tab(char *str, int *nb)
{
    char **res = NULL;

    *nb = 1;
    if (contains_space(str) == false) {
        res = malloc(sizeof(char *) * 2);
        res[0] = strdup(str);
        res[1] = NULL;
        return (res);
    }
    str = specify_quotes(str);
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == ' ')
            *nb += 1;
    }
    res = malloc_res(res, *nb + 1, strlen(str));
    res = fill_res(res, str, ' ');
    res = revert_ascii(res, *nb);
    return (res);
}
