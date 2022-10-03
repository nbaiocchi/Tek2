/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** cmd_log
*/

#include "../../include/client.h"
#include "../../../libs/myteams/logging_client.h"

void print_team_created(char **cmd)
{
    client_print_team_created(cmd[2], cmd[3], cmd[4]);
}

void print_channel_created(char **cmd)
{
    client_print_channel_created(cmd[2], cmd[3], cmd[4]);
}

void print_thread_created(char **cmd)
{
    client_print_thread_created(cmd[2], cmd[3],
    strtol(cmd[4], NULL, 10), cmd[5], cmd[6]);
}

void print_reply_created(char **cmd)
{
    client_print_reply_created(cmd[2], cmd[3],
    strtol(cmd[4], NULL, 10), cmd[5]);
}

void print_subscribed(char **cmd)
{
    client_print_subscribed(cmd[2], cmd[3]);
}
