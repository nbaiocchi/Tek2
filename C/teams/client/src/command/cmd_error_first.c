/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** cmd_log
*/

#include "../../include/client.h"
#include "../../../libs/myteams/logging_client.h"

void print_unsubscribed(char **cmd)
{
    client_print_unsubscribed(cmd[2], cmd[3]);
}

void err_unknown_team(char **cmd)
{
    client_error_unknown_team(cmd[2]);
}

void err_unknown_channel(char **cmd)
{
    client_error_unknown_channel(cmd[2]);
}

void err_unknown_thread(char **cmd)
{
    client_error_unknown_thread(cmd[2]);
}

void err_unknown_user(char **cmd)
{
    client_error_unknown_user(cmd[2]);
}
