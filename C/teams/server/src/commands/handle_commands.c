/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** get_commands
*/

#include "../../include/my.h"
#include "../../include/commands.h"

int handle_commands(char **cmds, t_client *cli, int nb_args, t_server *sv)
{
    char *teams_commands[14] = {"HELP", "USER", "QUIT", "LUSERS", "LUSER",
    "SEND", "MESSAGES", "SUBSCRIBE", "SUBSCRIBED", "UNSUBSCRIBE", "USE",
    "CREATE", "LIST", "INFO"};
    int (*teams_functions[14])(char **, t_client *, t_server *, int) = {
    &help, &user, &quit, &lusers, &luser, &mysend, &messages, &subscribe,
    &subscribed, &unsubscribe, &use, &create, &list, &info};

    if (cmds == NULL) {
        not_found_case(cli);
        return -1;
    }
    for (int i = 0; i != 14; i += 1) {
        if (!strcmp(cmds[0], teams_commands[i]))
            return (teams_functions[i](cmds, cli, sv, nb_args));
    }
    not_found_case(cli);
    return 0;
}

void get_commands(char *buffer, t_client *client, t_server *sv)
{
    int nb_args = 0;
    char **input;

    input = str_to_tab(buffer, &nb_args);
    input = check_if_double_quotes_is_good(input, buffer, nb_args);
    handle_commands(input, client, nb_args, sv);
    if (input != NULL) {
        for (int i = 0; i != nb_args; i += 1)
            free(input[i]);
    }
    free(input);
}

char **check_if_double_quotes_is_good(char **input, char *buffer, int nb_args)
{
    int nb = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '"')
            nb++;
    }
    if ((nb_args - 1) * 2 == nb)
        return input;
    return NULL;
}
