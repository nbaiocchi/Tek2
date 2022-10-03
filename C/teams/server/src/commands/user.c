/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** user
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/commands.h"
#include "../../include/utils.h"
#include "../../../libs/myteams/logging_server.h"
#include "../../include/users.h"

int create_user_folder(char *name, char *uuid)
{
    DIR *dir = opendir(".users");
    int dfd = dirfd(dir);
    int ret = mkdirat(dfd, uuid, S_IRWXU);

    errno = 0;
    if (ret == -1) {
        perror("mkdir");
        return EXIT_FAILURE;
    }
    create_user_name_file(name, uuid);
    create_user_teams_folder(uuid);
    server_event_user_created(uuid, name);
    closedir(dir);
    return EXIT_SUCCESS;
}

int create_user_name_file(char *name, char *uuid)
{
    char *folder_path = my_strcat(".users/", uuid, 1);
    char *file_path = my_strcat(folder_path, "name.txt", 0);
    FILE *file = fopen(file_path, "w");

    if (file == NULL) {
        perror("fopen");
        free(folder_path);
        free(file_path);
        return EXIT_FAILURE;
    }
    fprintf(file, "%s", name);
    free(folder_path);
    free(file_path);
    fclose(file);
    return EXIT_SUCCESS;
}

int create_user_teams_folder(char *uuid)
{
    char *folder_path = my_strcat(".users/", uuid, 1);
    DIR *dir = opendir(folder_path);
    int dfd = dirfd(dir);
    int ret = mkdirat(dfd, "teams", S_IRWXU);

    errno = 0;
    if (ret == -1) {
        perror("mkdir");
        free(folder_path);
        return EXIT_FAILURE;
    }
    free(folder_path);
    return EXIT_SUCCESS;
}

int user(char **cmds, t_client *cli, t_server *serv, int nb_args)
{
    char *uuid;

    if (nb_args != 2)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    uuid = get_user_uuid(cmds[1]);
    if (uuid == NULL) {
        if (connect_new_user_to_client(serv, cli, cmds[1]) == EXIT_FAILURE)
            return send_message(EXIT_FAILURE, STATUS401, cli->socket);
    } else {
        if (connect_user_to_cli(serv, cli, cmds[1], uuid) == EXIT_FAILURE)
            return send_message(EXIT_FAILURE, STATUS401, cli->socket);
    }
    if (!check_user_exists(".users/", cmds[1]))
        create_user_folder(cmds[1], cli->uuid);
    cli->is_connected = true;
    server_event_user_logged_in(cli->uuid);
    print_user_logged_in(serv, cli);
    return EXIT_SUCCESS;
}

void print_user_logged_in(t_server *serv, t_client *cli)
{
    for (int i = 0; i < serv->max_clients; i++) {
        serv->sd = serv->all_clients[i].socket;
        if (serv->all_clients[i].is_connected)
            print_message_to_cli(serv, &serv->all_clients[i],
            "%slogin \"%s\" \"%s\"\n", STATUS230, cli->uuid, cli->name);
    }
}
