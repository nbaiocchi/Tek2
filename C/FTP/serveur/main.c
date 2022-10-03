/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** main
*/

#include "../include/include.h"

int main(int ac, char **av)
{
    t_server *s = malloc(sizeof(t_server));
    if (check_arg(ac, av) == 1)
        return (0);
    if (init(s, av) == 1) {
        printf("init error");
        return (0);
    }
    loop(s);
    return (0);
}