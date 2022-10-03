/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** thread.c
*/

#include "../../../include/utils.h"
#include "../../../include/teams.h"

char *get_thread_title(char *thread_uuid)
{
    char *thread_path = find_path_by_uuid(thread_uuid);
    char *file_path = NULL;
    char *title = NULL;

    if (thread_path == NULL)
        return NULL;
    file_path = my_strcat(thread_path, "title.txt", 0);
    title = get_file_content(file_path);
    free(thread_path);
    free(file_path);
    return title;
}

char *get_thread_author(char *thread_uuid)
{
    char *thread_path = find_path_by_uuid(thread_uuid);
    char *file_path = NULL;
    char *author = NULL;

    if (thread_path == NULL)
        return NULL;
    file_path = my_strcat(thread_path, "author.txt", 0);
    author = get_file_content(file_path);
    free(thread_path);
    free(file_path);
    return author;
}

char *get_thread_message(char *thread_uuid)
{
    char *thread_path = find_path_by_uuid(thread_uuid);
    char *file_path = NULL;
    char *message = NULL;

    if (thread_path == NULL)
        return NULL;
    file_path = my_strcat(thread_path, "message.txt", 0);
    message = get_file_content(file_path);
    free(thread_path);
    free(file_path);
    return message;
}

char *get_thread_timestamp(char *thread_uuid)
{
    char *thread_path = find_path_by_uuid(thread_uuid);
    char *file_path = NULL;
    char *timestamp = NULL;

    if (thread_path == NULL)
        return NULL;
    file_path = my_strcat(thread_path, "timestamp.txt", 0);
    timestamp = get_file_content(file_path);
    free(thread_path);
    free(file_path);
    return timestamp;
}
