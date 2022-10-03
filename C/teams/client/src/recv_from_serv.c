/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** recv_from_serv
*/

#include "../include/client.h"

void handle_recv_cmd(char *msg)
{
    bool is_multiple_args;

    if (msg == NULL || msg[0] == '\0')
        return;
    is_multiple_args = check_multiple_args(msg);

    if (is_multiple_args == false) {
        single_args(msg);
    } else {
        multiple_args(msg);
    }
}

void recv_from_serv(t_client *s, char *buffer)
{
    read(s->sokfd, buffer, 10000);
    handle_recv_cmd(buffer);
}
