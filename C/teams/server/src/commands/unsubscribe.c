/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** retr
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/users.h"
#include "../../include/commands.h"
#include "../../../libs/myteams/logging_server.h"

int unsubscribe(char **cmd, t_client *cli, t_server *serv, int nb_args)
{
    (void)serv;

    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (nb_args != 2)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (check_folder(".users/", cli->uuid) && check_folder(".teams/", cmd[1])
    && check_if_user_subscribed(cli->uuid, cmd[1]) == EXIT_SUCCESS) {
        if (remove_user_from_team(cli->uuid, cmd[1]))
            return send_message(EXIT_FAILURE, STATUS550, cli->socket);
        print_message_to_cli(serv, cli, "%sprint_unsubscribed \"%s\" \"%s\"\n",
        STATUS200, cli->uuid, cmd[1]);
        server_event_user_unsubscribed(cmd[1], cli->uuid);
        return EXIT_SUCCESS;
    }
    print_message_to_cli(serv, cli, "%serr_unknown_user %s\n",
    STATUS404, cmd[1]);
    return EXIT_FAILURE;
}

int remove_user_from_team(char *uuid, char *team_uuid)
{
    char *folder_path = my_strcat(".users/", uuid, 1);
    char *teams_path = my_strcat(folder_path, "teams", 1);
    char *team_folder = my_strcat(teams_path, team_uuid, 0);

    errno = 0;
    if (rmdir(team_folder) == -1) {
        perror("rmdir");
        free(folder_path);
        free(teams_path);
        free(team_folder);
        return EXIT_FAILURE;
    }
    free(folder_path);
    free(teams_path);
    free(team_folder);
    return EXIT_SUCCESS;
}
