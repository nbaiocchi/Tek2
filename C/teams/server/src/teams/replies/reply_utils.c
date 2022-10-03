/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** reply_utils.c
*/

#include <stdio.h>
#include "../../../include/utils.h"
#include "../../../include/teams.h"

char *print_reply(char *reply_uuid)
{
    char *thread_uuid = get_thread_uuid_from_reply_uuid(reply_uuid);
    char *author = get_reply_author(reply_uuid);
    char *timestamp = get_reply_timestamp(reply_uuid);
    char *body = get_reply_body(reply_uuid);
    char *str = msprintf("\"%s\" \"%s\" \"%s\" \"%s\"#",
    thread_uuid, author, timestamp, body);

    free(thread_uuid);
    free(author);
    free(timestamp);
    free(body);
    return str;
}

char *get_thread_uuid_from_reply_uuid(char *uuid)
{
    return get_last_path(remove_last_path(find_path_by_uuid(uuid)));
}

char *remove_last_path(char *str)
{
    size_t len;

    if (str == NULL)
        return str;
    len = strlen(str);
    while (str[len - 2] != '/')
        len--;
    str[len - 1] = '\0';
    return str;
}

char *get_last_path(char *str)
{
    size_t len = strlen(str);
    char *path = NULL;

    while (str[len - 2] != '/')
        len--;
    path = strndup(str + len - 1, strlen(str) - len);
    return path;
}

char *reply_concat_print(char *name, char *print)
{
    char *str = print_reply(name);
    char *concat_str = msprintf("%s%s", print, str);

    free(print);
    free(str);
    return concat_str;
}
