/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** extract
*/

#include "../../include/my.h"

char **revert_ascii(char **cmds, int nb_args)
{
    for (int i = 0; i != nb_args || cmds[i] != NULL; i += 1) {
        replace_non_ascii(cmds[i]);
        if (cmds[i][0] == '"') {
            memmove(cmds[i], cmds[i] + 1, strlen(cmds[i]));
            cmds[i][strlen(cmds[i]) - 1] = '\0';
        }
    }
    return (cmds);
}

void replace_non_ascii(char *cmds)
{
    for (int j = 0; cmds[j] != '\0'; j += 1) {
        if (cmds[j] < 0) {
            cmds[j] = ' ';
        }
    }
}

char *replace_ascii(char *str, int *i)
{
    while (str[*i] != '\0' && str[*i] != '"') {
        if (str[*i] == ' ') {
            str[*i] = 130;
        }
        *i += 1;
    }
    return (str);
}

char *remove_quotes(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == 34)
            str[i] = ' ';
    }
    return (str);
}

char *specify_quotes(char *str)
{
    int nb_quotes = 0;

    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '"')
            nb_quotes += 1;
    }
    if (nb_quotes % 2 != 0)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '"') {
            i += 1;
            str = replace_ascii(str, &i);
        }
    }
    str = removing_spaces(str);
    str = removing_spaces_middle(str);
    return (str);
}
