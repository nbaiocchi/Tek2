/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** loop
*/

#include "../include/include.h"

void cmd_two(char **cmd, t_server *s)
{
    if (strcmp(cmd[0], "HELP") == 0 && s->client[s->i].is_co == 1) {
        help_cmd(cmd, s);
    } else if (strcmp(cmd[0], "HELP") == 0 && s->client[s->i].is_co == 0)
        dprintf(s->client_socket[s->i], "530 not logged\r\n");
    if (strcmp(cmd[0], "NOOP") == 0 && s->client[s->i].is_co == 1) {
        dprintf(s->client_socket[s->i], "200 noop\r\n");
    } else if (strcmp(cmd[0], "NOOP") == 0 && s->client[s->i].is_co == 0)
        dprintf(s->client_socket[s->i], "530 not logged\r\n");
    if ((strcmp(cmd[0], "CWD") == 0 || strcmp(cmd[0], "CDUP") == 0)
    && s->client[s->i].is_co == 1) {
        dprintf(s->client_socket[s->i], "550 forbiden path\r\n");
    } else if ((strcmp(cmd[0], "CWD") == 0 || strcmp(cmd[0], "CDUP") == 0)
    && s->client[s->i].is_co == 0)
        dprintf(s->client_socket[s->i], "530 not logged\r\n");
}

void wich_cmd(char **cmd, t_server *s)
{
    if (s->client[s->i].is_pass == 1 && s->client[s->i].is_user == 1)
        s->client[s->i].is_co = 1;
    if (strcmp(cmd[0], "USER") == 0)
        user_cmd(cmd, s);
    if (strcmp(cmd[0], "PASS") == 0)
        pass_cmd(s);
    if (strcmp(cmd[0], "QUIT") == 0)
        quit(s);
    cmd_two(cmd, s);
}

int check_cmd(char **cmd)
{
    static const char *CMDS[] = {
        "USER", "PASS", "CWD", "CDUP", "QUIT", "DELE", "PWD",
        "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"
    };

    for (int i = 0; CMDS[i] != NULL; i++) {
        if (strcmp(cmd[0], CMDS[i]) == 0) {
            return (1);
        }
    }
    return (0);
}

void handle_cmd(char *buffer, t_server *s)
{
    char **cmd;
    static const char *CMDS[] = {
        "USER", "PASS", "CWD", "CDUP", "QUIT", "DELE", "PWD",
        "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"
    };

    if (buffer[strlen(buffer) - 2] == '\r')
        buffer[strlen(buffer) - 2] = '\0';
    else if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';
    cmd = to_word_array(buffer);
    if (check_cmd(cmd) == 0) {
        dprintf(s->client_socket[s->i], "500 Unknown command\r\n");
        return;
    }
    for (int i = 0; CMDS[i] != NULL; i++) {
        if (strcmp(cmd[0], CMDS[i]) == 0) {
            wich_cmd(cmd, s);
        }
    }
}