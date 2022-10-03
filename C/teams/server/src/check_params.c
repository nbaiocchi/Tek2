/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** check_params
*/

#include "../include/my.h"

bool check_params(char **av)
{
    DIR *pDir;

    pDir = opendir(av[2]);
    if (pDir == NULL) {
        printf("Cannot open directory '%s'\n", av[2]);
        return (false);
    }
    return (true);
}
