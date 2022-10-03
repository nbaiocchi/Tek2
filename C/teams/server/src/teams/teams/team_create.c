/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** team_create.c
*/

#include <dirent.h>
#include <sys/stat.h>
#include "../../../include/teams.h"
#include "../../../include/utils.h"
#include "../../../include/status_codes.h"
#include "../../../include/users.h"

int team_create(t_server *serv, t_client *cli, char *name, char *desc)
{
    char *uuid = generate_uuid();

    if (strlen(name) > MAX_NAME_LENGTH || strlen(desc) > MAX_DESC_LENGTH)
        return send_message(EXIT_FAILURE, STATUS414, cli->socket);
    if (generate_team_folder(uuid) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (generate_team_file_name(uuid, name) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (generate_team_file_description(uuid, desc) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    print_team_created(serv, cli, uuid);
    free(uuid);
    return EXIT_SUCCESS;
}

int generate_team_folder(char *uuid)
{
    DIR *dir = opendir(".teams");
    int dfd = dirfd(dir);
    int ret = mkdirat(dfd, uuid, S_IRWXU);

    errno = 0;
    if (ret == -1) {
        perror("mkdir");
        return EXIT_FAILURE;
    }
    closedir(dir);
    return EXIT_SUCCESS;
}

int generate_team_file_name(char *uuid, char *name)
{
    char *folder_path = my_strcat(".teams/", uuid, 1);
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

int generate_team_file_description(char *uuid, char *desc)
{
    char *folder_path = my_strcat(".teams/", uuid, 1);
    char *file_path = my_strcat(folder_path, "description.txt", 0);
    FILE *file = fopen(file_path, "w");

    if (file == NULL) {
        perror("fopen");
        free(folder_path);
        free(file_path);
        return EXIT_FAILURE;
    }
    fprintf(file, "%s", desc);
    free(folder_path);
    free(file_path);
    fclose(file);
    return EXIT_SUCCESS;
}
