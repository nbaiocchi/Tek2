/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** find_path_by_uuid.c
*/

#include "../../include/utils.h"
#include "../../include/teams.h"

char *find_path_by_uuid(char *uuid)
{
    char *current_path = NULL;
    char *path = NULL;
    DIR *d = opendir(".teams");
    struct dirent *dir = NULL;

    if (d == NULL)
        return NULL;
    while ((dir = readdir(d)) != NULL && path == NULL) {
        if (strcmp(dir->d_name, uuid) == 0)
            path = my_strcat(".teams/", dir->d_name, 1);
        if (check_team_folder(dir->d_name) == EXIT_SUCCESS && path == NULL) {
            current_path = my_strcat(".teams/", dir->d_name, 1);
            path = find_path_by_uuid_in_team(current_path, uuid);
            free(current_path);
        }
    }
    closedir(d);
    return path;
}

char *find_path_by_uuid_in_team(char *team_path, char *uuid)
{
    char *current_path = NULL;
    char *path = NULL;
    DIR *d = opendir(team_path);
    struct dirent *dir = NULL;

    if (d == NULL)
        return NULL;
    while ((dir = readdir(d)) != NULL && path == NULL) {
        if (strcmp(dir->d_name, uuid) == 0)
            path = my_strcat(team_path, dir->d_name, 1);
        if (check_channel_folder(dir->d_name) == 0 && path == NULL) {
            current_path = my_strcat(team_path, dir->d_name, 1);
            path = find_path_by_uuid_in_channel(current_path, uuid);
            free(current_path);
        }
    }
    closedir(d);
    return path;
}

char *find_path_by_uuid_in_channel(char *channel_path, char *uuid)
{
    char *current_path = NULL;
    char *path = NULL;
    DIR *d = opendir(channel_path);
    struct dirent *dir = NULL;

    if (d == NULL)
        return NULL;
    while ((dir = readdir(d)) != NULL && path == NULL) {
        if (strcmp(dir->d_name, uuid) == 0)
            path = my_strcat(channel_path, dir->d_name, 1);
        if (check_thread_folder(dir->d_name) == EXIT_SUCCESS && path == NULL) {
            current_path = my_strcat(channel_path, dir->d_name, 1);
            path = find_path_by_uuid_in_thread(current_path, uuid);
            free(current_path);
        }
    }
    closedir(d);
    return path;
}

char *find_path_by_uuid_in_thread(char *thread_path, char *uuid)
{
    char *path = NULL;
    DIR *d = opendir(thread_path);
    struct dirent *dir = NULL;

    if (d == NULL)
        return NULL;
    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, uuid) == 0) {
            path = my_strcat(thread_path, dir->d_name, 1);
            closedir(d);
            return path;
        }
    }
    closedir(d);
    return NULL;
}
