/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** loop
*/

#include "../include/include.h"

void print_cmd(t_server *s)
{
    dprintf(s->client_socket[s->i],
    "USER\tPASS\tCWD\tCDUP\tQUIT\tDELE\tPORT\t");
    dprintf(s->client_socket[s->i],
    "PWD\tPASV\tHELP\tNOOP\tRETR\tSTOR\tLIST\r\n");
}

void help_cmd(char **cmd, t_server *s)
{
    static const char *CMDS[] = {
        "USER", "PASS", "CWD", "CDUP", "QUIT", "DELE", "PWD",
        "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"
    };

    dprintf(s->client_socket[s->i], "214 some help\r\n");
    if (cmd[1] == NULL) {
        print_cmd(s);
        return;
    }
    for (int i = 0; CMDS[i] != NULL; i++) {
        if (strcmp(cmd[1], CMDS[i]) == 0) {
            dprintf(s->client_socket[s->i], "%s\r\n", cmd[1]);
            return;
        }
    }
    dprintf(s->client_socket[s->i], "No command %s found\r\n", cmd[1]);
}