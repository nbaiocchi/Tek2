/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** dele
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"
#include "../../include/utils.h"
#include "../../include/commands.h"
#include "../../include/users.h"
#include "../../../libs/myteams/logging_server.h"
#include "../../include/teams.h"

int mysend(char **cd, t_client *cli, t_server *serv, int nb_args)
{
    char *user_path = NULL;
    char *dest_path = NULL;

    if (!cli->is_connected)
        return send_message(EXIT_FAILURE, STATUS530, cli->socket);
    if (nb_args != 3)
        return send_message(EXIT_FAILURE, STATUS501, cli->socket);
    if (check_folder(".users/", cli->uuid) && check_folder(".users/", cd[1])) {
        user_path = my_strcat(".users/", cli->uuid, 1);
        dest_path = my_strcat(".users/", cd[1], 1);
        init_folders(user_path, dest_path, cd[1], cli->uuid);
        if (send_message_dest(serv, cli, cd) == EXIT_FAILURE)
            return EXIT_FAILURE;
        if (put_msg_client(cli, cd) == EXIT_FAILURE)
            return EXIT_FAILURE;
        return send_message(EXIT_SUCCESS, STATUS250, cli->socket);
    }
    print_message_to_cli(serv, cli, "%serr_unknown_user %s\n",
    STATUS404, cd[1]);
    return EXIT_FAILURE;
}

int create_dest_folder(char *user_path, char *name)
{
    DIR *dir = opendir(user_path);
    int dfd = dirfd(dir);
    int ret = mkdirat(dfd, name, S_IRWXU);

    errno = 0;
    if (ret == -1) {
        perror("mkdir");
        return EXIT_FAILURE;
    }
    closedir(dir);
    return EXIT_SUCCESS;
}

void init_folders(char *user_path, char *dest_path, char *command, char *name)
{
    if (!check_folder(user_path, command))
        create_dest_folder(user_path, command);
    if (!check_folder(dest_path, name))
        create_dest_folder(dest_path, name);
}

int send_message_dest(t_server *serv, t_client *cli, char **cmds)
{
    char *uuid = generate_uuid();
    char *user_path = msprintf(".users/%s/%s/", cmds[1], cli->uuid);

    if (create_folder(user_path, uuid) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (reply_create_files(cli, user_path, uuid, cmds[2]) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    free(uuid);
    free(user_path);
    if (get_user_status(serv, cmds[1]))
        send_event_dest(serv, cli, cmds);
    server_event_private_message_sended(cli->uuid, cmds[1], cmds[2]);
    return EXIT_SUCCESS;
}

int put_msg_client(t_client *cli, char **cmds)
{
    char *uuid = generate_uuid();
    char *user_path = msprintf(".users/%s/%s/", cli->uuid, cmds[1]);

    if (create_folder(user_path, uuid) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    if (reply_create_files(cli, user_path, uuid, cmds[2]) == EXIT_FAILURE)
        return send_message(EXIT_FAILURE, STATUS425, cli->socket);
    free(uuid);
    free(user_path);
    return EXIT_SUCCESS;
}
