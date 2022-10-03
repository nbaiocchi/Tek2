/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** reply.c
*/

#include "../../../include/utils.h"
#include "../../../include/teams.h"

char *get_reply_timestamp(char *reply_uuid)
{
    char *thread_path = find_path_by_uuid(reply_uuid);
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

char *get_reply_author(char *reply_uuid)
{
    char *thread_path = find_path_by_uuid(reply_uuid);
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

char *get_reply_body(char *reply_uuid)
{
    char *thread_path = find_path_by_uuid(reply_uuid);
    char *file_path = NULL;
    char *body = NULL;

    if (thread_path == NULL)
        return NULL;
    file_path = my_strcat(thread_path, "body.txt", 0);
    body = get_file_content(file_path);
    free(thread_path);
    free(file_path);
    return body;
}
