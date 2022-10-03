/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** port
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/users.h"
#include "../../include/commands.h"

int use(char **cmds, t_client *cli, t_server *serv, int nb_args)
{
    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (nb_args > 4)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (nb_args == 1) {
        cli->context.state = UNDEFINED;
        return send_message(EXIT_SUCCESS, STATUS200, cli->socket);
    }
    if (!check_folder(".teams/", cmds[1])) {
        print_message_to_cli(serv, cli, "%serr_unknown_team %s\n",
        STATUS404, cmds[1]);
        return EXIT_FAILURE;
    }
    return check_use_args(serv, cli, nb_args, cmds);
}

int check_use_args(t_server *serv, t_client *cli, int nb_args, char **cmds)
{
    if (user_subscribed_to_team(cli->uuid, cmds[1]) == EXIT_SUCCESS) {
        if (nb_args == 2)
            return use_team_handler(cli, cmds[1]);
        if (nb_args == 3)
            return use_channel_handler(serv, cli, cmds[1], cmds[2]);
        if (nb_args == 4)
            return use_thread_handler(serv, cli, cmds);
    }
    return send_message(EXIT_SUCCESS, STATUS401, cli->socket);
}

int use_team_handler(t_client *cli, char *t_uuid)
{
    cli->context.state = TEAM;
    strcpy(cli->context.team_uuid, t_uuid);
    return send_message(EXIT_SUCCESS, STATUS200, cli->socket);
}

int use_channel_handler(t_server *sv, t_client *cli, char *t_id, char *c_id)
{
    char *team_path = my_strcat(".teams/", t_id, 1);

    if (!check_folder(team_path, c_id)) {
        print_message_to_cli(sv, cli, "%serr_unknown_team %s\n",
        STATUS404, t_id);
        return EXIT_FAILURE;
    }
    cli->context.state = CHANNEL;
    strcpy(cli->context.team_uuid, t_id);
    strcpy(cli->context.channel_uuid, c_id);
    return send_message(EXIT_SUCCESS, STATUS200, cli->socket);
}

int use_thread_handler(t_server *serv, t_client *cli, char **cmds)
{
    char *team_path = my_strcat(".teams/", cmds[1], 1);
    char *channel_path = my_strcat(team_path, cmds[2], 1);

    if (!check_folder(channel_path, cmds[3])) {
        print_message_to_cli(serv, cli, "%serr_unknown_team %s\n",
        STATUS404, cmds[1]);
        return EXIT_FAILURE;
    }
    cli->context.state = THREAD;
    strcpy(cli->context.team_uuid, cmds[1]);
    strcpy(cli->context.channel_uuid, cmds[2]);
    strcpy(cli->context.thread_uuid, cmds[3]);
    return send_message(EXIT_SUCCESS, STATUS200, cli->socket);
}
