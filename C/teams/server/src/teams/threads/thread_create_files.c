/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** thread_create_files.c
*/

#include <time.h>
#include "../../../include/structs.h"
#include "../../../include/utils.h"

int generate_thread_file_title(t_client *cli, char *uuid, char *name)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(folder_path, cli->context.channel_uuid, 1);
    char *thread_path = my_strcat(channel_path, uuid, 1);
    char *file_path = my_strcat(thread_path, "title.txt", 0);
    FILE *file = fopen(file_path, "w");

    free(folder_path);
    free(channel_path);
    free(thread_path);
    free(file_path);
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fprintf(file, "%s", name);
    fclose(file);
    return EXIT_SUCCESS;
}

int generate_thread_file_message(t_client *cli, char *uuid, char *desc)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(folder_path, cli->context.channel_uuid, 1);
    char *thread_path = my_strcat(channel_path, uuid, 1);
    char *file_path = my_strcat(thread_path, "message.txt", 0);
    FILE *file = fopen(file_path, "w");

    free(folder_path);
    free(channel_path);
    free(thread_path);
    free(file_path);
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fprintf(file, "%s", desc);
    fclose(file);
    return EXIT_SUCCESS;
}

int generate_thread_file_timestamp(t_client *cli, char *uuid)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(folder_path, cli->context.channel_uuid, 1);
    char *thread_path = my_strcat(channel_path, uuid, 1);
    char *file_path = my_strcat(thread_path, "timestamp.txt", 0);
    FILE *file = fopen(file_path, "w");

    free(folder_path);
    free(channel_path);
    free(thread_path);
    free(file_path);
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fprintf(file, "%ld", time(NULL));
    fclose(file);
    return EXIT_SUCCESS;
}

int generate_thread_file_author(t_client *cli, char *uuid)
{
    char *folder_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(folder_path, cli->context.channel_uuid, 1);
    char *thread_path = my_strcat(channel_path, uuid, 1);
    char *file_path = my_strcat(thread_path, "author.txt", 0);
    FILE *file = fopen(file_path, "w");

    free(folder_path);
    free(channel_path);
    free(thread_path);
    free(file_path);
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fprintf(file, "%s", cli->uuid);
    fclose(file);
    return EXIT_SUCCESS;
}
