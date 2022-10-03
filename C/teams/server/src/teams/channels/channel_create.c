/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** channel_create.c
*/

#include "../../../include/utils.h"
#include "../../../include/teams.h"
#include "../../../include/status_codes.h"

int channel_create(t_server *serv, t_client *cli, char *name, char *desc)
{
    char *uuid = generate_uuid();

    if (strlen(name) > MAX_NAME_LENGTH || strlen(desc) > MAX_DESC_LENGTH)
        return send_message(EXIT_FAILURE, STATUS414, cli->socket);
    if (generate_channel_folder(cli, uuid) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (generate_channel_file_name(cli, uuid, name) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (generate_channel_file_description(cli, uuid, desc) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    print_channel_created(serv, cli, uuid, cli->context.team_uuid);
    free(uuid);
    return EXIT_SUCCESS;
}

int generate_channel_folder(t_client *cli, char *uuid)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 0);
    DIR *dir = opendir(folder_path);
    int dfd = dirfd(dir);
    int ret = mkdirat(dfd, uuid, S_IRWXU);

    errno = 0;
    if (ret == -1) {
        perror("mkdir");
        free(folder_path);
        return EXIT_FAILURE;
    }
    free(folder_path);
    closedir(dir);
    return EXIT_SUCCESS;
}

int generate_channel_file_name(t_client *cli, char *uuid, char *name)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(folder_path, uuid, 1);
    char *file_path = my_strcat(channel_path, "name.txt", 0);
    FILE *file = fopen(file_path, "w");

    if (file == NULL) {
        perror("fopen");
        free(folder_path);
        free(channel_path);
        free(file_path);
        return EXIT_FAILURE;
    }
    fprintf(file, "%s", name);
    free(folder_path);
    free(channel_path);
    free(file_path);
    fclose(file);
    return EXIT_SUCCESS;
}

int generate_channel_file_description(t_client *cli, char *uuid, char *desc)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(folder_path, uuid, 1);
    char *file_path = my_strcat(channel_path, "description.txt", 0);
    FILE *file = fopen(file_path, "w");

    if (file == NULL) {
        perror("fopen");
        free(folder_path);
        free(channel_path);
        free(file_path);
        return EXIT_FAILURE;
    }
    fprintf(file, "%s", desc);
    free(folder_path);
    free(channel_path);
    free(file_path);
    fclose(file);
    return EXIT_SUCCESS;
}
