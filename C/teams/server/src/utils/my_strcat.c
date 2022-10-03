/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** my_strcat.c
*/

#include <string.h>
#include <stdlib.h>

char *my_strcat(char *str1, char *str2, int slash)
{
    char *str;
    int i;
    int j;

    if (slash == 1)
        str = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 2));
    else
        str = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    for (i = 0; str1[i] != '\0'; i++)
        str[i] = str1[i];
    for (j = 0; str2[j] != '\0'; j++)
        str[i + j] = str2[j];
    if (slash == 1) {
        str[i + j] = '/';
        j++;
    }
    str[i + j] = '\0';
    return (str);
}
