/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** reply_create_files.c
*/

#include <time.h>
#include "../../../include/utils.h"
#include "../../../include/teams.h"
#include "../../../include/commands.h"

int reply_create_files(t_client *cli, char *trd_path, char *uuid, char *body)
{
    if (create_reply_file_timestamp(trd_path, uuid) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (create_reply_file_body(trd_path, uuid, body) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (create_reply_file_author(trd_path, uuid, cli->uuid) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int create_reply_file_timestamp(char *path, char *uuid)
{
    char *folder_path = my_strcat(path, uuid, 1);
    char *file_path = my_strcat(folder_path, "timestamp.txt", 0);
    FILE *file = fopen(file_path, "w");

    free(folder_path);
    free(file_path);
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fprintf(file, "%ld", time(NULL));
    fclose(file);
    return EXIT_SUCCESS;
}

int create_reply_file_body(char *path, char *uuid, char *body)
{
    char *folder_path = my_strcat(path, uuid, 1);
    char *file_path = my_strcat(folder_path, "body.txt", 0);
    FILE *file = fopen(file_path, "w");

    free(folder_path);
    free(file_path);
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fprintf(file, "%s", body);
    fclose(file);
    return EXIT_SUCCESS;
}

int create_reply_file_author(char *path, char *uuid, char *author)
{
    char *folder_path = my_strcat(path, uuid, 1);
    char *file_path = my_strcat(folder_path, "author.txt", 0);
    FILE *file = fopen(file_path, "w");

    free(folder_path);
    free(file_path);
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fprintf(file, "%s", author);
    fclose(file);
    return EXIT_SUCCESS;
}
