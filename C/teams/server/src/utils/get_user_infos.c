/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** get_user_infos.c
*/

#include <stdbool.h>
#include "../../include/my.h"
#include "../../include/utils.h"
#include "../../include/users.h"

bool get_user_status(t_server *serv, char *uuid)
{
    for (int i = 0; i < serv->max_clients; i++) {
        if (strcmp(serv->all_clients[i].uuid, uuid) == 0)
            return serv->all_clients[i].is_connected;
    }
    return false;
}

char *get_user_name(char *uuid)
{
    char *folder_path = my_strcat(".users/", uuid, 1);
    char *file_path = my_strcat(folder_path, "name.txt", 0);
    char *name;
    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        perror("fopen");
        free(folder_path);
        free(file_path);
        return NULL;
    }
    fscanf(file, "%ms", &name);
    free(folder_path);
    free(file_path);
    fclose(file);
    return name;
}

char *get_user_uuid(char *username)
{
    DIR *d = opendir(".users");
    char *file_path = NULL;
    char *folder_path = NULL;
    struct dirent *dir = NULL;

    if (d == NULL)
        return false;
    while ((dir = readdir(d)) != NULL) {
        folder_path = my_strcat(".users/", dir->d_name, 1);
        file_path = my_strcat(folder_path, "name.txt", 0);
        free(folder_path);
        if (check_user_file_exists(file_path, username) == EXIT_SUCCESS) {
            free(file_path);
            closedir(d);
            return dir->d_name;
        }
        free(file_path);
    }
    closedir(d);
    return NULL;
}
