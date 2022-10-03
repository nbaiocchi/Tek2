/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** reply_list.c
*/

#include "../../../include/structs.h"
#include "../../../include/utils.h"
#include "../../../include/status_codes.h"
#include "../../../include/teams.h"

int reply_list(t_server *serv, t_client *cli)
{
    char *thread_path = msprintf(".teams/%s/%s/%s/", cli->context.team_uuid,
    cli->context.channel_uuid, cli->context.thread_uuid);
    DIR *d = opendir(thread_path);
    struct dirent *dir = NULL;
    char *print = malloc(sizeof(char) * 1);

    free(thread_path);
    print[0] = '\0';
    if (d == NULL)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    while ((dir = readdir(d)) != NULL) {
        if (check_reply_folder(dir->d_name) == EXIT_SUCCESS)
            print = reply_concat_print(dir->d_name, print);
    }
    print_message_to_cli(serv, cli, "%sprint_replies %s\n", STATUS200, print);
    free(print);
    closedir(d);
    return EXIT_SUCCESS;
}

int check_reply_folder(char *name)
{
    if (strcmp(name, ".") == 0)
        return EXIT_FAILURE;
    if (strcmp(name, "..") == 0)
        return EXIT_FAILURE;
    if (strcmp(name, "title.txt") == 0)
        return EXIT_FAILURE;
    if (strcmp(name, "message.txt") == 0)
        return EXIT_FAILURE;
    if (strcmp(name, "author.txt") == 0)
        return EXIT_FAILURE;
    if (strcmp(name, "timestamp.txt") == 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
