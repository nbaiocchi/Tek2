/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** check_user_exists.c
*/

#include "../../include/my.h"
#include "../../include/utils.h"
#include "../../include/users.h"

bool check_user_exists(char *path, char *username)
{
    DIR *d = opendir(path);
    char *file_path = NULL;
    char *folder_path = NULL;
    struct dirent *dir;

    if (d == NULL)
        return false;
    while ((dir = readdir(d)) != NULL) {
        folder_path = my_strcat(path, dir->d_name, 1);
        file_path = my_strcat(folder_path, "name.txt", 0);
        free(folder_path);
        if (check_user_file_exists(file_path, username) == EXIT_SUCCESS) {
            free(file_path);
            closedir(d);
            return true;
        }
        free(file_path);
    }
    closedir(d);
    return false;
}

int check_user_file_exists(char *file_path, char *username)
{
    char *name = NULL;
    FILE *file = fopen(file_path, "r");

    if (file == NULL)
        return EXIT_FAILURE;
    fscanf(file, "%ms", &name);
    fclose(file);
    if (strcmp(name, username) == 0) {
        free(name);
        return EXIT_SUCCESS;
    }
    free(name);
    return EXIT_FAILURE;
}

bool check_folder(char *path, char *uuid)
{
    struct stat st = {0};
    char *folder_path = my_strcat(path, uuid, 0);

    if (stat(folder_path, &st) == -1) {
        free(folder_path);
        return false;
    }
    free(folder_path);
    return true;
}
