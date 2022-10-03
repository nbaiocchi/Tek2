/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** user_info.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/structs.h"
#include "../../include/commands.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"

int user_info(t_server *serv, t_client *cli)
{
    char *print = NULL;

    print = print_user(cli->name, cli->uuid, cli->is_connected);
    print_message_to_cli(serv, cli, "%sprint_user %s\n", STATUS250, print);
    free(print);
    return EXIT_SUCCESS;
}
