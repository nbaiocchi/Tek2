/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** quit
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/commands.h"
#include "../../../libs/myteams/logging_server.h"

int quit(char **commands, t_client *cli, t_server *serv, int nb_args)
{
    (void)commands;

    if (nb_args != 1)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    for (int i = 0; i < serv->actual_size; i++) {
        if (cli->socket == serv->all_clients[i].socket) {
            print_user_logged_out(serv, cli);
            server_event_user_logged_out(cli->uuid);
            close(serv->all_clients[i].socket);
            remove_client(serv->all_clients, i, &serv->actual_size);
        }
    }
    return EXIT_SUCCESS;
}

void print_user_logged_out(t_server *serv, t_client *cli)
{
    for (int i = 0; i < serv->actual_size; i++) {
        print_message_to_cli(serv, &serv->all_clients[i],
        "%slogout \"%s\" \"%s\"\n", STATUS221, cli->uuid, cli->name);
    }
}
