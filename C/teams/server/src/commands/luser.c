/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** cwd
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/users.h"
#include "../../include/commands.h"

int luser(char **cmds, t_client *cli, t_server *serv, int nb_args)
{
    char *user = NULL;

    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (nb_args != 2)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (!check_folder(".users/", cmds[1])) {
        print_message_to_cli(serv, cli, "%serr_unknown_user %s\n",
        STATUS404, cmds[1]);
        return EXIT_FAILURE;
    }
    user = print_user(get_user_name(cmds[1]), cmds[1],
    get_user_status(serv, cmds[1]));
    print_message_to_cli(serv, cli, "%sprint_user %s\n", STATUS200, user);
    free(user);
    return EXIT_SUCCESS;
}
