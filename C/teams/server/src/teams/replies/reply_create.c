/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** reply_create.c
*/

#include "../../../include/structs.h"
#include "../../../include/utils.h"
#include "../../../include/teams.h"
#include "../../../include/status_codes.h"
#include "../../../include/commands.h"
#include "../../../include/users.h"
#include "../../../../libs/myteams/logging_server.h"

int reply_create(t_server *serv, t_client *cli, char *body)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(folder_path, cli->context.channel_uuid, 1);
    char *thread_path = my_strcat(channel_path, cli->context.thread_uuid, 1);
    char *uuid = generate_uuid();

    free(folder_path);
    free(channel_path);
    if (strlen(body) > MAX_BODY_LENGTH)
        return send_message(EXIT_FAILURE, STATUS414, cli->socket);
    if (create_folder(thread_path, uuid) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (reply_create_files(cli, thread_path, uuid, body) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    print_reply_created(serv, uuid, cli->context.team_uuid);
    send_event_reply_received(serv, cli, body);
    free(uuid);
    free(thread_path);
    return EXIT_SUCCESS;
}

void print_reply_created(t_server *serv, char *uuid, char *t_uuid)
{
    char *thread_uuid = get_thread_uuid_from_reply_uuid(uuid);
    char *reply_author = get_reply_author(uuid);
    char *reply_timestamp = get_reply_timestamp(uuid);
    char *reply_body = get_reply_body(uuid);

    server_event_reply_created(thread_uuid, reply_author, reply_body);
    for (int i = 0; i < serv->max_clients; i++) {
        if (user_subscribed_to_team(serv->all_clients[i].uuid, t_uuid) == 0) {
            print_message_to_cli(serv, &serv->all_clients[i],
            "%sthread_reply \"%s\" \"%s\" \"%s\" \"%s\"\n", STATUS200,
            thread_uuid, reply_author, reply_timestamp, reply_body);
        }
    }
    free(thread_uuid);
    free(reply_author);
    free(reply_timestamp);
    free(reply_body);
}
