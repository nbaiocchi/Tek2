/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** cmd_log
*/

#include "../../include/client.h"
#include "../../../libs/myteams/logging_client.h"

void login(char **cmd)
{
    client_event_logged_in(cmd[2], cmd[3]);
}

void logout(char **cmd)
{
    client_event_logged_out(cmd[2], cmd[3]);
}
