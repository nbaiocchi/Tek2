/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** channel_list.c
*/

#include <dirent.h>
#include "../../../include/structs.h"
#include "../../../include/utils.h"
#include "../../../include/teams.h"
#include "../../../include/status_codes.h"

int channel_list(t_server *serv, t_client *cli)
{
    char *team_path = my_strcat(".teams/", cli->context.team_uuid, 1);
    DIR *d = opendir(team_path);
    struct dirent *dir = NULL;
    char *print = malloc(sizeof(char) * 1);

    free(team_path);
    print[0] = '\0';
    if (d == NULL)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    while ((dir = readdir(d)) != NULL) {
        if (check_channel_folder(dir->d_name) == EXIT_SUCCESS)
            print = channel_concat_print(dir->d_name, print);
    }
    print_message_to_cli(serv, cli, "%sprint_channels %s\n", STATUS200, print);
    free(print);
    closedir(d);
    return EXIT_SUCCESS;
}

int check_channel_folder(char *name)
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
