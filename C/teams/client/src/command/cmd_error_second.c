/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** cmd_log
*/

#include "../../include/client.h"
#include "../../../libs/myteams/logging_client.h"

void err_unauthorized(char **cmds)
{
    (void)cmds;
    client_error_unauthorized();
}

void err_already_exist(char **cmds)
{
    (void)cmds;
    client_error_already_exist();
}
