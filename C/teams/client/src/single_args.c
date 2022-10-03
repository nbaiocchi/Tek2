/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** recv_from_serv
*/

#include "../include/client.h"
#include "../../libs/myteams/logging_client.h"

static command_t _command[29] = {&login, &logout, &message_received,
&thread_reply, &team_created, &channel_created, &thread_created,
&print_users, &print_teams, &print_channels, &print_threads, &print_replies,
&print_message, &print_user, &print_team, &print_channel, &print_thread,
&print_team_created, &print_channel_created, &print_thread_created,
&print_reply_created, &print_subscribed, &print_unsubscribed,
&err_unknown_team, &err_unknown_channel, &err_unknown_thread,
&err_unknown_thread, &err_unauthorized, &err_already_exist};

// cmd[0] = rfc message
// cmd[1] = command name
// cmd[x] = args
void single_args(char *msg)
{
    char **cmd = tab_for_args(msg);
    char *cmd_name[] = {"login", "logout", "message_received", "thread_reply",
    "team_created", "channel_created", "thread_created", "print_users",
    "print_teams", "print_channels", "print_threads", "print_replies",
    "print_message", "print_user", "print_team", "print_channel",
    "print_thread", "print_team_created", "print_channel_created",
    "print_thread_created", "print_reply_created", "print_subscribed",
    "print_unsubscribed", "err_unknown_team", "err_unknown_channel",
    "err_unknown_thread", "err_unknown_thread", "err_unauthorized",
    "err_already_exist"};

    printf("%s", cmd[0]);
    if (cmd[1] == NULL)
        return;
    for (int i = 0; i != 29; i++) {
        if (!strcmp(cmd[1], cmd_name[i])) {
            _command[i](cmd);
            return;
        }
    }
}
