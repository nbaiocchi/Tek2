/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** channel_info.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../../include/structs.h"
#include "../../../include/teams.h"
#include "../../../include/users.h"
#include "../../../include/status_codes.h"
#include "../../../include/utils.h"

int channel_info(t_server *serv, t_client *cli)
{
    char *uuid = cli->context.channel_uuid;
    char *team_uuid = cli->context.team_uuid;

    if (user_subscribed_to_team(cli->uuid, team_uuid) == EXIT_SUCCESS) {
        print_message_to_cli(serv, cli,
        "%sprint_channel \"%s\" \"%s\" \"%s\"\n",
        STATUS250, uuid, get_channel_name(uuid),
        get_channel_description(uuid));
        return EXIT_SUCCESS;
    } else {
        print_message_to_cli(serv, cli, "%serr_unauthorized\n", STATUS401);
        return EXIT_FAILURE;
    }
}
