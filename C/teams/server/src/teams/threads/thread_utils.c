/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** thread_utils.c
*/

#include <stdio.h>
#include "../../../include/utils.h"
#include "../../../include/teams.h"
#include "../../../include/users.h"
#include "../../../include/status_codes.h"
#include "../../../../libs/myteams/logging_server.h"

char *print_thread(char *thread_uuid)
{
    return msprintf("\"%s\" \"%s\" \"%s\" \"%s\" \"%s\"#",
    thread_uuid, get_thread_author(thread_uuid),
    get_thread_timestamp(thread_uuid), get_thread_title(thread_uuid),
    get_thread_message(thread_uuid));
}

char *thread_concat_print(char *name, char *print)
{
    char *str = print_thread(name);
    char *concat_str = msprintf("%s%s", print, str);

    free(print);
    free(str);
    return concat_str;
}

void print_thread_created(t_server *serv, t_client *cli, char *uuid)
{
    char *author = get_thread_author(uuid);
    char *timestamp = get_thread_timestamp(uuid);
    char *title = get_thread_title(uuid);
    char *message = get_thread_message(uuid);

    server_event_thread_created(cli->context.channel_uuid,
    uuid, author, title, message);
    for (int i = 0; i < serv->max_clients; i++) {
        if (user_subscribed_to_team(serv->all_clients[i].uuid,
        cli->context.team_uuid) == 1)
            continue;
        if (cli->socket == serv->all_clients[i].socket)
            print_thread_created_users(serv, cli, uuid);
        else
            print_thread_created_user(serv, &serv->all_clients[i], uuid);
    }
    free(author);
    free(timestamp);
    free(title);
    free(message);
}

void print_thread_created_users(t_server *serv, t_client *cli, char *uuid)
{
    char *author = get_thread_author(uuid);
    char *timestamp = get_thread_timestamp(uuid);
    char *title = get_thread_title(uuid);
    char *message = get_thread_message(uuid);

    print_message_to_cli(serv, cli,
    "%sprint_thread_created \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
    STATUS200, uuid, author, timestamp, title, message);
    free(author);
    free(timestamp);
    free(title);
    free(message);
}

void print_thread_created_user(t_server *serv, t_client *cli, char *uuid)
{
    char *author = get_thread_author(uuid);
    char *timestamp = get_thread_timestamp(uuid);
    char *title = get_thread_title(uuid);
    char *message = get_thread_message(uuid);

    print_message_to_cli(serv, cli,
    "%sthread_created \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
    STATUS200, uuid, author, timestamp, title, message);
    free(author);
    free(timestamp);
    free(title);
    free(message);
}
