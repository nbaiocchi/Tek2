/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** cmd_log
*/

#include "../../include/client.h"
#include "../../../libs/myteams/logging_client.h"

void print_message(char **cmd)
{
    client_private_message_print_messages(cmd[2],
    strtol(cmd[3], NULL, 10), cmd[4]);
}

void print_user(char **cmd)
{
    if (!strcmp(cmd[4], "true"))
        client_print_user(cmd[2], cmd[3], 1);
    if (!strcmp(cmd[4], "false"))
        client_print_user(cmd[2], cmd[3], 0);
}

void print_team(char **cmd)
{
    client_print_team(cmd[2], cmd[3], cmd[4]);
}

void print_channel(char **cmd)
{
    client_print_channel(cmd[2], cmd[3], cmd[4]);
}

void print_thread(char **cmd)
{
    client_print_thread(cmd[2], cmd[3],
    strtol(cmd[4], NULL, 10), cmd[5], cmd[6]);
}
