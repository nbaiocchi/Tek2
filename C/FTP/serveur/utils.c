/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** utils
*/

#include "../include/include.h"

int count_word(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ')
            count += 1;
    }
    return (count);
}

char **to_word_array(char *str)
{
    char **res = malloc(sizeof(char *) * (count_word(str) + 1));
    int j = 0;
    int y = 0;

    for (int i = 0; i != count_word(str) + 1; i++)
        res[i] = malloc(sizeof(char) * (100));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            res[y][j] = str[i];
            j += 1;
        }
        if (str[i] == ' ' && str[i + 1] != ' ') {
            res[y][j] = '\0';
            j = 0;
            y += 1;
        }
    }
    res[y][j] = '\0';
    res[y + 1] = NULL;
    return (res);
}