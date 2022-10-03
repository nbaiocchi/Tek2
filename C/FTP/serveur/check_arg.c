/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** check_arg
*/

#include "../include/include.h"

void usage(void)
{
    printf("USAGE TODO");
}

int check_arg(int ac, char **av)
{
    DIR *dir;

    if (ac == 2 && ((!strcmp(av[1], "--help")) || !(strcmp(av[1], "-h")))) {
        usage();
        return (1);
    }
    if (ac != 3) {
        printf("3 arguments in my_ftp\n See usage `-h`\n");
        return (1);
    }
    dir = opendir(av[2]);
    if (dir == NULL) {
        printf("Cannot open directory '%s'\n", av[2]);
        return (1);
    }
    if (atoi(av[1]) <= 0)
        return (1);
    return (0);
}