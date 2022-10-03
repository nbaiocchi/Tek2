/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** print_thread.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../../include/structs.h"
#include "../../../include/teams.h"
#include "../../../include/status_codes.h"
#include "../../../include/utils.h"

int thread_info(t_server *serv, t_client *cli)
{
    char *thread_uuid = cli->context.thread_uuid;

    print_message_to_cli(serv, cli,
    "%sprint_thread \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
    STATUS250, thread_uuid, get_thread_author(thread_uuid),
    get_thread_timestamp(thread_uuid), get_thread_title(thread_uuid),
    get_thread_message(thread_uuid));
    return EXIT_SUCCESS;
}
