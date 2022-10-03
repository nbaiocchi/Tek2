/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** cdup
*/

#include "../../include/commands.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/users.h"

char *print_user(char *name, char *uuid, bool status)
{
    if (name == NULL || uuid == NULL)
        return NULL;
    if (strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
        if (status)
            return msprintf("\"%s\" \"%s\" \"true\"", uuid, name);
        else
            return msprintf("\"%s\" \"%s\" \"false\"", uuid, name);
    }
    return NULL;
}

char *print_users(t_server *serv)
{
    DIR *d = opendir(".users");
    char *print = malloc(sizeof(char) * 1);
    struct dirent *dir = NULL;

    print[0] = '\0';
    if (d == NULL)
        return NULL;
    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)
            print = lusers_concat_print(serv, dir->d_name, print);
    }
    closedir(d);
    return print;
}

char *lusers_concat_print(t_server *serv, char *uuid, char *print)
{
    char *str = print_user(get_user_name(uuid),
    uuid, get_user_status(serv, uuid));
    char *concat_str = msprintf("%s%s#", print, str);

    free(print);
    free(str);
    return concat_str;
}

int lusers(char **commands, t_client *cli, t_server *serv, int nb_args)
{
    char *print = NULL;

    (void)commands;
    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (nb_args != 1)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    print = print_users(serv);
    print_message_to_cli(serv, cli, "%sprint_users %s\n", STATUS200, print);
    free(print);
    return EXIT_SUCCESS;
}
