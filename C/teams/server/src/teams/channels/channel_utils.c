/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** channel_utils.c
*/

#include "../../../include/utils.h"
#include "../../../include/teams.h"
#include "../../../include/users.h"
#include "../../../include/status_codes.h"
#include "../../../../libs/myteams/logging_server.h"

char *check_channel_file(char *dir_name, char *team_uuid, char *channel_name)
{
    char *folder_path = my_strcat(".teams/", team_uuid, 1);
    char *channel_path = my_strcat(folder_path, dir_name, 1);
    char *file_path = my_strcat(channel_path, "name.txt", 0);

    free(folder_path);
    free(channel_path);
    if (check_team_file_exists(file_path, channel_name) == EXIT_SUCCESS) {
        free(file_path);
        return dir_name;
    }
    free(file_path);
    return NULL;
}

char *print_channel(char *channel_uuid)
{
    return msprintf("\"%s\" \"%s\" \"%s\"#",
    channel_uuid, get_channel_name(channel_uuid),
    get_channel_description(channel_uuid));
}

char *channel_concat_print(char *name, char *print)
{
    char *str = print_channel(name);
    char *concat_str = msprintf("%s%s", print, str);

    free(print);
    free(str);
    return concat_str;
}

void print_channel_created(t_server *srv, t_client *cli, char *id, char *t_id)
{
    char *channel_name = get_channel_name(id);
    char *channel_desc = get_channel_description(id);

    server_event_channel_created(t_id, id, channel_name);
    for (int i = 0; i < srv->max_clients; i++) {
        if (user_subscribed_to_team(srv->all_clients[i].uuid, t_id) == 1)
            continue;
        if (cli->socket == srv->all_clients[i].socket)
            print_message_to_cli(srv, &srv->all_clients[i],
            "%sprint_channel_created \"%s\" \"%s\" \"%s\"\n", STATUS200, id,
            channel_name, channel_desc);
        print_message_to_cli(srv, &srv->all_clients[i],
        "%schannel_created \"%s\" \"%s\" \"%s\"\n", STATUS200, id,
        channel_name, channel_desc);
    }
    free(channel_name);
    free(channel_desc);
}
