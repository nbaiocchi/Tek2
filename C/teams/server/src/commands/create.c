/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** pwd
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/teams.h"

int create(char **commands, t_client *cli, t_server *serv, int nb_args)
{
    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (cli->context.state == THREAD && nb_args != 2)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (cli->context.state != THREAD && nb_args != 3)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (cli->context.state == UNDEFINED)
        return team_create(serv, cli, commands[1], commands[2]);
    if (cli->context.state == TEAM)
        return channel_create(serv, cli, commands[1], commands[2]);
    if (cli->context.state == CHANNEL)
        return thread_create(serv, cli, commands[1], commands[2]);
    if (cli->context.state == THREAD)
        return reply_create(serv, cli, commands[1]);
    return EXIT_SUCCESS;
}
