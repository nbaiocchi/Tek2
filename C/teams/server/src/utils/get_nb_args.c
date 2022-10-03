/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** get_nb_args
*/

#include "../../include/my.h"

int get_nb_args(char **tmp)
{
    int nb = 0;

    for (int i = 0; tmp[i] != NULL; i += 1)
        nb += 1;
    return (nb);
}
