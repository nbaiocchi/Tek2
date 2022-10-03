/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** cmd_log
*/

#include "../../include/client.h"
#include "../../../libs/myteams/logging_client.h"

void message_received(char **cmd)
{
    client_event_private_message_received(cmd[2], cmd[3]);
}

void thread_reply(char **cmd)
{
    client_event_thread_reply_received(cmd[2], cmd[3], cmd[4], cmd[5]);
}

void team_created(char **cmd)
{
    client_event_team_created(cmd[2], cmd[3], cmd[4]);
}

void channel_created(char **cmd)
{
    client_event_channel_created(cmd[2], cmd[3], cmd[4]);
}

void thread_created(char **cmd)
{
    client_event_thread_created(cmd[2], cmd[3],
    strtol(cmd[4], NULL, 10), cmd[5], cmd[6]);
}
