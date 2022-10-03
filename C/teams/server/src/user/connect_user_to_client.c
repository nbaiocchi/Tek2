/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** connect_user_to_client.c
*/

#include <uuid/uuid.h>
#include "../../include/my.h"
#include "../../include/utils.h"
#include "../../../libs/myteams/logging_server.h"

int connect_new_user_to_client(t_server *server, t_client *cli, char *name)
{
    char *uuid = generate_uuid();

    (void)server;
    strcpy(cli->uuid, uuid);
    strcpy(cli->name, name);
    free(uuid);
    return EXIT_SUCCESS;
}

int connect_user_to_cli(t_server *srv, t_client *cli, char *name, char *uuid)
{
    (void)srv;
    strcpy(cli->uuid, uuid);
    strcpy(cli->name, name);
    return EXIT_SUCCESS;
}
