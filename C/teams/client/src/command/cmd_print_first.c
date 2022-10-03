/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** cmd_log
*/

#include "../../include/client.h"
#include "../../../libs/myteams/logging_client.h"

void print_users(char **cmd)
{
    if (!strcmp(cmd[4], "true"))
        client_print_users(cmd[2], cmd[3], 1);
    if (!strcmp(cmd[4], "false"))
        client_print_users(cmd[2], cmd[3], 0);
}

void print_teams(char **cmd)
{
    client_print_teams(cmd[2], cmd[3], cmd[4]);
}

void print_channels(char **cmd)
{
    client_team_print_channels(cmd[2], cmd[3], cmd[4]);
}

void print_threads(char **cmd)
{
    client_channel_print_threads(cmd[2], cmd[3],
    strtol(cmd[4], NULL, 10), cmd[5], cmd[6]);
}

void print_replies(char **cmd)
{
    client_thread_print_replies(cmd[2], cmd[3],
    strtol(cmd[4], NULL, 10), cmd[5]);
}
