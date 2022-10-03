/*
** EPITECH PROJECT, 2020
** main
** File description:
** bsq
*/

#include "../include/my.h"
#include "../include/users.h"

// TODO: update print message to client

int main(int ac, char **av)
{
    t_server main_server;

    if (ac != 2 || ((!strcmp(av[1], "--help")) || !(strcmp(av[1], "-h")))) {
        print_usage();
        return (0);
    }
    if (init(&main_server, av[1], "") == false)
        return (84);
    print_all_loaded_users();
    main_loop(&main_server);
    return (0);
}
