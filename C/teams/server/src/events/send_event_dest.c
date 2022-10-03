/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** send_event_dest.c
*/

#include <string.h>
#include <stdio.h>
#include "../../include/structs.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/teams.h"

void send_event_dest(t_server *serv, t_client *cli, char **commands)
{
    for (int i = 0; i < serv->max_clients; i++) {
        if (strcmp(serv->all_clients[i].uuid, commands[1]) == 0) {
            print_message_to_cli(serv, &serv->all_clients[i],
            "%smessage_received \"%s\" \"%s\"\n", STATUS200,
            cli->uuid, commands[2]);
        }
    }
}

void send_event_reply_received(t_server *serv, t_client *cli, char *body)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(folder_path, cli->context.channel_uuid, 1);
    char *thread_path = my_strcat(channel_path, cli->context.thread_uuid, 1);
    char *file_path = my_strcat(thread_path, "author.txt", 0);
    char *author = get_file_content(file_path);

    print_message_to_cli(serv, cli,
    "%sprint_reply_created \"%s\" \"%s\" \"%s\" \"%s\"\n", STATUS200,
    cli->context.team_uuid, cli->context.thread_uuid, cli->uuid, body);
    free(folder_path);
    free(channel_path);
    free(thread_path);
    free(file_path);
    free(author);
}
