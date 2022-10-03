/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** help
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"

int help(char **commands, t_client *cli, t_server *serv, int nb_args)
{
    (void)serv;
    if (cli->is_connected == true) {
        if (nb_args == 1 || (nb_args == 2 && strlen(commands[1]) == 0)) {
            print_message_to_cli(serv, cli, STATUS214);
            return EXIT_SUCCESS;
        }
        print_message_to_cli(serv, cli, STATUS504);
        return EXIT_FAILURE;
    }
    print_message_to_cli(serv, cli, STATUS530);
    return EXIT_FAILURE;
}
