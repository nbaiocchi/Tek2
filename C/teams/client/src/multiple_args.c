/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** recv_from_serv
*/

#include "../include/client.h"
#include "../../libs/myteams/logging_client.h"

static command_mul_t _commandm[6] = {&m_print_users, &m_print_teams,
&m_print_channels, &m_print_threads, &m_print_replies, &m_print_message};

void m_print_users(char **cmd, int count)
{
    int y = 2;

    for (int i = 0; i != count; i += 1) {
        if (!strcmp(cmd[y + 2], "true"))
            client_print_users(cmd[y], cmd[y + 1], 1);
        if (!strcmp(cmd[y + 2], "false"))
            client_print_users(cmd[y], cmd[y + 1], 0);
        y += 3;
    }
}

// cmd[0] = rfc message
// cmd[1] = command name
// cmd[x] = args
void multiple_args(char *msg)
{
    char **cmd = tab_for_args(msg);
    int count = cout_iter(msg);
    char *cmd_name[] =
    {"print_users", "print_teams", "print_channels",
    "print_threads", "print_replies", "print_message"};

    printf("%s", cmd[0]);
    if (cmd[1] == NULL)
        return;
    for (int i = 0; i != 29; i++) {
        if (!strcmp(cmd[1], cmd_name[i])) {
            _commandm[i](cmd, count);
            return;
        }
    }
}
