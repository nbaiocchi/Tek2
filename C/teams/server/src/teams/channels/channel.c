/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** channel.c
*/

#include "../../../include/utils.h"
#include "../../../include/teams.h"

char *get_channel_name(char *channel_uuid)
{
    char *thread_path = find_path_by_uuid(channel_uuid);
    char *file_path = NULL;
    char *name = NULL;

    if (thread_path == NULL)
        return NULL;
    file_path = my_strcat(thread_path, "name.txt", 0);
    name = get_file_content(file_path);
    free(thread_path);
    free(file_path);
    return name;
}

char *get_channel_uuid(char *team_uuid, char *channel_name)
{
    DIR *d = opendir(".teams");
    char *uuid = NULL;
    struct dirent *dir = NULL;

    if (d == NULL)
        return false;
    while ((dir = readdir(d)) != NULL) {
        uuid = check_channel_file(dir->d_name, team_uuid, channel_name);
        if (uuid != NULL) {
            closedir(d);
            return uuid;
        }
    }
    closedir(d);
    return NULL;
}

char *get_channel_description(char *channel_uuid)
{
    char *thread_path = find_path_by_uuid(channel_uuid);
    char *file_path = NULL;
    char *description = NULL;

    if (thread_path == NULL)
        return NULL;
    file_path = my_strcat(thread_path, "description.txt", 0);
    description = get_file_content(file_path);
    free(thread_path);
    free(file_path);
    return description;
}
