/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** pending_message_handler.c
*/

#include "../../include/structs.h"
#include "../../include/utils.h"

void pending_message_handler(t_server *serv)
{
    for (int i = 0; i < serv->actual_size; i++) {
        if (serv->all_clients[i].is_connected &&
        serv->all_clients[i].pending_commands != NULL)
            print_message_to_cli(serv, &serv->all_clients[i],
            serv->all_clients[i].pending_commands);
    }
}
