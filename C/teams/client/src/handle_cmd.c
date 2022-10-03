/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** send_msg
*/

#include "../include/client.h"

void send_to_serv(t_client *s, char **cmd, char *msg)
{
    char *message = clear_first_word(msg);

    static const char *CMDS[] =
    {"/login", "/logout", "/users", "/user", "/send", "/messages",
        "/subscribe", "/subscribed", "/unsubscribe", "/use", "/create",
        "/list", "/info"};
    bool is_cmd = false;
    for (int i = 0; CMDS[i] != NULL; i++) {
        if (strcmp(cmd[0], CMDS[i]) == 0) {
            is_cmd = true;
        }
    }
    if (is_cmd == false) {
        dprintf(s->sokfd, "%s\r\n", msg);
        return;
    }
    if (cmd[1] == NULL)
        one_args_cmd(s, cmd);
    else
        more_args_cmd(s, cmd, message);
}

void send_cmd(t_client *s, char **cmd, char *msg)
{
    if (strcmp(msg, "/help") == 0) {
        printf("%s", STATUS214);
        return;
    }
    send_to_serv(s, cmd, msg);
}
