/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** subscribe
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/users.h"
#include "../../include/commands.h"
#include "../../../libs/myteams/logging_server.h"

int subscribe(char **commands, t_client *cli, t_server *serv, int nb_args)
{
    (void)serv;

    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (nb_args != 2)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (check_folder(".users/", cli->uuid)
    && check_folder(".teams/", commands[1])
    && check_if_user_subscribed(cli->uuid, commands[1]) == EXIT_FAILURE) {
        if (add_user_to_team(cli->uuid, commands[1]))
            return send_message(EXIT_FAILURE, STATUS550, cli->socket);
        print_message_to_cli(serv, cli, "%sprint_subscribed \"%s\" \"%s\"\n",
        STATUS200, cli->uuid, commands[1]);
        server_event_user_subscribed(commands[1], cli->uuid);
        return EXIT_SUCCESS;
    }
    print_message_to_cli(serv, cli, "%serr_unknown_user %s\n",
    STATUS404, commands[1]);
    return EXIT_FAILURE;
}

int add_user_to_team(char *uuid, char *team_uuid)
{
    char *folder_path = my_strcat(".users/", uuid, 1);
    char *teams_path = my_strcat(folder_path, "teams", 1);
    DIR *dir = opendir(teams_path);
    int dfd = dirfd(dir);
    int ret = mkdirat(dfd, team_uuid, 0777);

    errno = 0;
    if (ret == -1) {
        perror("mkdir");
        free(folder_path);
        free(teams_path);
        return EXIT_FAILURE;
    }
    free(folder_path);
    free(teams_path);
    return EXIT_SUCCESS;
}

int check_if_user_subscribed(char *uuid, char *team_uuid)
{
    char *path = msprintf(".users/%s/teams/", uuid);

    if (check_folder(path, team_uuid)) {
        free(path);
        return EXIT_SUCCESS;
    }
    free(path);
    return EXIT_FAILURE;
}
