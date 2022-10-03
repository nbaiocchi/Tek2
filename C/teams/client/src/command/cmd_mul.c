/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** recv_from_serv
*/

#include "../../include/client.h"
#include "../../../libs/myteams/logging_client.h"

void m_print_teams(char **cmd, int count)
{
    int y = 2;

    for (int i = 0; i != count; i += 1) {
        client_print_teams(cmd[y], cmd[y + 1], cmd[y + 2]);
        y += 3;
    }
}

void m_print_channels(char **cmd, int count)
{
    int y = 2;

    for (int i = 0; i != count; i += 1) {
        client_team_print_channels(cmd[y], cmd[y + 1], cmd[y + 2]);
        y += 3;
    }
}

void m_print_threads(char **cmd, int count)
{
    int y = 2;

    for (int i = 0; i != count; i += 1) {
        client_channel_print_threads
        (cmd[y], cmd[y + 1], strtol(cmd[y + 2], NULL, 10),
        cmd[y + 3], cmd[y + 4]);
        y += 5;
    }
}

void m_print_replies(char **cmd, int count)
{
    int y = 2;

    for (int i = 0; i != count; i += 1) {
        client_thread_print_replies
        (cmd[y], cmd[y + 1], strtol(cmd[y + 2], NULL, 10), cmd[y + 3]);
        y += 4;
    }
}

void m_print_message(char **cmd, int count)
{
    int y = 2;

    for (int i = 0; i != count; i += 1) {
        client_private_message_print_messages
        (cmd[y], strtol(cmd[y + 1], NULL, 10), cmd[y + 2]);
        y += 3;
    }
}
