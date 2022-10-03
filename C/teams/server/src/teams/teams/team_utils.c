/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** team_util.c
*/

#include "../../../include/teams.h"
#include "../../../include/utils.h"
#include "../../../include/users.h"
#include "../../../include/status_codes.h"
#include "../../../../libs/myteams/logging_server.h"

int check_team_file_exists(char *file_path, char *team_name)
{
    char *name = NULL;
    FILE *file = fopen(file_path, "r");

    if (file == NULL)
        return EXIT_FAILURE;
    fscanf(file, "%ms", &name);
    fclose(file);
    if (strcmp(name, team_name) == 0) {
        free(name);
        return EXIT_SUCCESS;
    }
    free(name);
    return EXIT_FAILURE;
}

char *print_team(char *team_uuid)
{
    return msprintf("\"%s\" \"%s\" \"%s\"#", team_uuid,
    get_channel_name(team_uuid), get_channel_description(team_uuid));
}

char *team_concat_print(char *name, char *print)
{
    char *str = print_team(name);
    char *concat_str = msprintf("%s%s", print, str);

    free(print);
    free(str);
    return concat_str;
}

void print_team_created(t_server *serv, t_client *cli, char *uuid)
{
    char *team_name = get_team_name(uuid);
    char *team_desc = get_team_description(uuid);

    server_event_team_created(uuid, team_name, cli->uuid);
    for (int i = 0; i < serv->max_clients; i++) {
        if (!serv->all_clients[i].is_connected)
            continue;
        if (cli->socket == serv->all_clients[i].socket)
            print_message_to_cli(serv, &serv->all_clients[i],
            "%sprint_team_created \"%s\" \"%s\" \"%s\"\n", STATUS200, uuid,
            team_name, team_desc);
        print_message_to_cli(serv, &serv->all_clients[i],
        "%steam_created \"%s\" \"%s\" \"%s\"\n", STATUS200, uuid,
        team_name, team_desc);

    }
    free(team_name);
    free(team_desc);
}
