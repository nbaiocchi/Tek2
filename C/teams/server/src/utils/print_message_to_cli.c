/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** print_message.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../include/structs.h"
#include "../../include/utils.h"

void print_message_to_cli(t_server *serv, t_client *cli, char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    if (cli->is_connected && !FD_ISSET(cli->socket, &serv->writefds)) {
        if (cli->pending_commands != NULL)
            free(cli->pending_commands);
        cli->pending_commands = msprintf(format, ap);
    } else
        vdprintf(cli->socket, format, ap);
    va_end(ap);
}
