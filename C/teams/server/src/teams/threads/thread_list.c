/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** thread_list.c
*/

#include "../../../include/structs.h"
#include "../../../include/utils.h"
#include "../../../include/status_codes.h"
#include "../../../include/teams.h"

int thread_list(t_server *serv, t_client *cli)
{
    char *team_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    char *channel_path = my_strcat(team_path, cli->context.channel_uuid, 1);
    DIR *d = opendir(channel_path);
    struct dirent *dir = NULL;
    char *print = malloc(sizeof(char) * 1);

    free(team_path);
    free(channel_path);
    print[0] = '\0';
    if (d == NULL)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    while ((dir = readdir(d)) != NULL) {
        if (check_thread_folder(dir->d_name) == 0)
            print = thread_concat_print(dir->d_name, print);
    }
    print_message_to_cli(serv, cli, "%sprint_threads %s\n", STATUS200, print);
    free(print);
    closedir(d);
    return EXIT_SUCCESS;
}

int check_thread_folder(char *name)
{
    if (strcmp(name, ".") == 0)
        return EXIT_FAILURE;
    if (strcmp(name, "..") == 0)
        return EXIT_FAILURE;
    if (strcmp(name, "name.txt") == 0)
        return EXIT_FAILURE;
    if (strcmp(name, "description.txt") == 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
