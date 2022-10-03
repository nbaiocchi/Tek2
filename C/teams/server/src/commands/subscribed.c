/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** pasv
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/commands.h"
#include "../../include/users.h"
#include "../../include/teams.h"

int subscribed(char **commands, t_client *cli, t_server *serv, int nb_args)
{
    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (!check_folder(".users/", cli->uuid))
        return send_message(EXIT_SUCCESS, STATUS404, cli->socket);
    if (nb_args == 1)
        return list_all_subscribed_teams(serv, cli);
    else if (nb_args == 2)
        return list_all_users_of_team(cli, serv, commands[1]);
    else
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
}

int list_all_subscribed_teams(t_server *serv, t_client *cli)
{
    char *folder_path = msprintf(".users/%s/teams/", cli->uuid);
    DIR *d = opendir(folder_path);
    struct dirent *dir = NULL;
    char *print = malloc(sizeof(char) * 1);

    print[0] = '\0';
    if (d == NULL)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)
            print = team_concat_print(dir->d_name, print);
    }
    print_message_to_cli(serv, cli, "%sprint_teams %s\n", STATUS200, print);
    free(print);
    free(folder_path);
    closedir(d);
    return EXIT_SUCCESS;
}

int list_all_users_of_team(t_client *cli, t_server *serv, char *team_uuid)
{
    DIR *dir = opendir(".users/");
    struct dirent *d = NULL;
    char *print = malloc(sizeof(char) * 1);
    char *user_path = NULL;

    print[0] = '\0';
    if (dir == NULL)
        return EXIT_FAILURE;
    while ((d = readdir(dir)) != NULL) {
        user_path = msprintf(".users/%s/teams/", d->d_name);
        if (check_folder(user_path, team_uuid))
            print = user_concat_print(serv, d->d_name, print);
        free(user_path);
    }
    print_message_to_cli(serv, cli, "%sprint_users %s\n", STATUS200, print);
    free(print);
    closedir(dir);
    return EXIT_SUCCESS;
}

char *user_concat_print(t_server *serv, char *uuid, char *print)
{
    char *str = print_user(get_user_name(uuid), uuid,
    get_user_status(serv, uuid));
    char *concat_str = msprintf("%s%s#", print, str);

    free(print);
    free(str);
    return concat_str;
}
