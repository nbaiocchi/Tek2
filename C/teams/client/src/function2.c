/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** function2
*/

#include "../include/client.h"

char *get_string_cote(char *str, int *i)
{
    char *res = malloc(sizeof(char) * strlen(str));
    int y = 0;

    *i += 1;
    for (; str[*i] != '"'; *i += 1) {
        res[y] = str[*i];
        y += 1;
    }
    res[y] = '\0';
    return (res);
}

char **tab_for_args2(char *msg, char **res, int i, int y)
{
    int z = 2;

    for (; msg[i] != ' '; i += 1) {
        res[1][y] = msg[i];
        y += 1;
    }
    res[1][y] = '\0';
    for (; msg[i] != '\0'; i += 1) {
        if (msg[i] == '"' && (msg[i - 1] == ' ' || msg[i - 1] == '#')) {
            res[z] = get_string_cote(msg, &i);
            z += 1;
        }
    }
    res[z] = NULL;
    return (res);
}

char **tab_for_args(char *msg)
{
    char **res = malloc(sizeof(char *) * 20);
    res[0] = malloc(sizeof(char) * 500);
    res[1] = malloc(sizeof(char) * 500);
    int i = 0;
    int y = 0;

    for (; msg[i] != '\n'; i += 1) {
        res[0][i] = msg[i];
    }
    res[0][i] = '\n';
    i += 1;
    res[0][i] = '\0';
    if (msg[i] == '\0') {
        res[1] = NULL;
        return (res);
    }
    return (tab_for_args2(msg, res, i, y));
}

int cout_iter(char *msg)
{
    int res = 0;

    for (int i = 0; msg[i] != '\0'; i += 1) {
        if (msg[i] == '#' && msg[i - 1] == '"')
            res += 1;
    }
    return (res);
}
