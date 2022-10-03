/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** cwd
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/teams.h"

int list(char **commands, t_client *cli, t_server *sv, int nb_args)
{
    (void)commands;
    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (nb_args != 1)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (cli->context.state == UNDEFINED)
        return team_list(sv, cli);
    if (cli->context.state == TEAM)
        return channel_list(sv, cli);
    if (cli->context.state == CHANNEL)
        return thread_list(sv, cli);
    if (cli->context.state == THREAD)
        return reply_list(sv, cli);
    return EXIT_SUCCESS;
}
