/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** remove_spaces
*/

#include "../../include/my.h"

bool check_end_string(char *str, int index)
{
    for (int i = index; str[i] != '\0'; i += 1) {
        if (str[i] != ' ' && str[i] != '\t') {
            return (false);
        }
    }
    return (true);
}

char *removing_spaces(char *str)
{
    while ((str[0] == ' ' || str[0] == '\t')) {
        str += 1;
    }
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] == ' ' || str[i] == '\t') &&
        check_end_string(str, i) == true) {
            str[i] = '\0';
            return (str);
        }
    }
    return (str);
}

char *removing_spaces_middle(char *str)
{
    char *copy = malloc(sizeof(char) * (strlen(str) + 2));
    int c = 0;
    int i = 0;

    for (; str[i] != '\0'; i += 1) {
        if (str[i] == ' ' || str[i] == '\t') {
            copy[c] = ' ';
            c += 1;
        }
        while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
            i += 1;
        copy[c] = str[i];
        c += 1;
    }
    copy[c] = str[i];
    copy[c + 1] = '\0';
    return (copy);
}
