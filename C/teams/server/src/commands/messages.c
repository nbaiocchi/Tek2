/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** noob
*/

#include "../../include/my.h"
#include "../../include/commands.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/users.h"

int messages(char **commands, t_client *cli, t_server *serv, int nb_args)
{
    char *user_path = NULL;

    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (nb_args != 2)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    user_path = my_strcat(".users/", cli->uuid, 1);
    if (check_folder(".users/", cli->uuid)
    && check_folder(user_path, commands[1]))
        print_discussion(serv, cli, commands[1]);
    free(user_path);
    return EXIT_SUCCESS;
}

int print_discussion(t_server *serv, t_client *cli, char *dest_uuid)
{
    char *path = msprintf(".users/%s/%s/", cli->uuid, dest_uuid);
    DIR *d = opendir(path);
    struct dirent *dir;
    char *print = malloc(sizeof(char) * 1);

    print[0] = '\0';
    if (d == NULL)
        return EXIT_FAILURE;
    while ((dir = readdir(d)) != NULL) {
        if (check_discussion_folder(dir->d_name) == EXIT_SUCCESS)
            print = discusion_concat_print(path, dir->d_name, print);
    }
    print_message_to_cli(serv, cli, "%sprint_message %s\n", STATUS200, print);
    free(print);
    free(path);
    closedir(d);
    return EXIT_SUCCESS;
}

int check_discussion_folder(char *name)
{
    if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

char *discusion_concat_print(char *path, char *uuid, char *print)
{
    char *file_path = msprintf("%s%s/", path, uuid);
    char *str = print_message(file_path);
    char *concat_str = msprintf("%s%s", print, str);

    free(print);
    free(file_path);
    free(str);
    return concat_str;
}

char *print_message(char *path)
{
    char *author_path = msprintf("%sauthor.txt", path);
    char *author = get_file_content(author_path);
    char *timestamp_path = msprintf("%stimestamp.txt", path);
    char *timestamp = get_file_content(timestamp_path);
    char *body_path = msprintf("%sbody.txt", path);
    char *body = get_file_content(body_path);
    char *str = msprintf("\"%s\" \"%s\" \"%s\"#", author, timestamp, body);

    free(author_path);
    free(timestamp_path);
    free(body_path);
    free(author);
    free(timestamp);
    free(body);
    return str;
}
