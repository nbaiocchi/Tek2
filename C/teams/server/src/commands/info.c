/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** stor
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/teams.h"
#include "../../include/users.h"

int info(char **commands, t_client *cli, t_server *serv, int nb_args)
{
    (void)commands;

    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (nb_args != 1)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (cli->context.state == UNDEFINED)
        return user_info(serv, cli);
    if (cli->context.state == TEAM)
        return team_info(serv, cli);
    if (cli->context.state == CHANNEL)
        return channel_info(serv, cli);
    if (cli->context.state == THREAD)
        return thread_info(serv, cli);
    return EXIT_SUCCESS;
}
