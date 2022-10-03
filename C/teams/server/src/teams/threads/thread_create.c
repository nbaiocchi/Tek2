/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** thread_create.c
*/

#include "../../../include/utils.h"
#include "../../../include/teams.h"
#include "../../../include/status_codes.h"

int thread_create(t_server *serv, t_client *cli, char *name, char *desc)
{
    char *uuid = generate_uuid();

    if (strlen(name) > MAX_NAME_LENGTH || strlen(desc) > MAX_BODY_LENGTH)
        return send_message(EXIT_FAILURE, STATUS414, cli->socket);
    if (generate_thread_folder(cli, uuid) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (generate_thread_file_title(cli, uuid, name) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (generate_thread_file_message(cli, uuid, desc) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (generate_thread_file_timestamp(cli, uuid) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (generate_thread_file_author(cli, uuid) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    print_thread_created(serv, cli, uuid);
    free(uuid);
    return EXIT_SUCCESS;
}

int generate_thread_folder(t_client *cli, char *uuid)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(folder_path, cli->context.channel_uuid, 0);
    DIR *dir = opendir(channel_path);
    int dfd = dirfd(dir);
    int ret = mkdirat(dfd, uuid, S_IRWXU);

    errno = 0;
    free(folder_path);
    free(channel_path);
    if (ret == -1) {
        perror("mkdir");
        return EXIT_FAILURE;
    }
    closedir(dir);
    return EXIT_SUCCESS;
}
