/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** teams.c
*/

#include "../../../include/teams.h"
#include "../../../include/utils.h"

char *get_team_name(char *team_uuid)
{
    char *thread_path = find_path_by_uuid(team_uuid);
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

char *get_team_uuid(char *team_name)
{
    DIR *d = opendir(".teams");
    char *file_path = NULL;
    char *folder_path = NULL;
    struct dirent *dir = NULL;

    if (d == NULL)
        return false;
    while ((dir = readdir(d)) != NULL) {
        folder_path = my_strcat(".teams/", dir->d_name, 1);
        file_path = my_strcat(folder_path, "name.txt", 0);
        free(folder_path);
        if (check_team_file_exists(file_path, team_name) == EXIT_SUCCESS) {
            free(file_path);
            closedir(d);
            return dir->d_name;
        }
        free(file_path);
    }
    closedir(d);
    return NULL;
}

char *get_team_description(char *team_uuid)
{
    char *thread_path = find_path_by_uuid(team_uuid);
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
