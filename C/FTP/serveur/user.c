/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** loop
*/

#include "../include/include.h"

void user_cmd(char **cmd, t_server *s)
{
    if (s->client[s->i].is_co == 1) {
        printf("530: bad login\r\n");
        dprintf(s->client_socket[s->i], "530 bad login\r\n");
        return;
    }
    printf("331: User name okay, need password.\r\n");
    dprintf(s->client_socket[s->i], "331 User name okay\r\n");
    s->client[s->i].is_user = 1;
    strcpy(s->client[s->i].user[0], cmd[1]);
    if (cmd[2] == NULL) {
        s->client[s->i].user[1] = NULL;
    } else
        strcpy(s->client[s->i].user[1], cmd[2]);
}

void pass_two(t_server *s)
{
    if (s->client[s->i].user[1] == NULL) {
        printf("230 User logged in, proceed\r\n");
        dprintf(s->client_socket[s->i], "230 User logged in, proceed\r\n");
        s->client[s->i].is_pass = 1;
    } else {
        dprintf(s->client_socket[s->i], "530 Invalide password\r\n");
    }
}

void pass_cmd(t_server *s)
{
    if (s->client[s->i].is_user == 0) {
        printf("503 Please, specify a user first\r\n");
        dprintf(s->client_socket[s->i],
        "503 Please, specify a user first\r\n");
        return;
    } else if (s->client[s->i].is_pass == 1) {
        printf("230 Already logged in\r\n");
        dprintf(s->client_socket[s->i],
        "230 Already logged in\r\n");
        return;
    }
    if (strcmp(s->client[s->i].user[0], "Anonymous") != 0
    || s->client[s->i].user[1] != NULL) {
        dprintf(s->client_socket[s->i], "530 Invalide user\r\n");
        return;
    }
    pass_two(s);
}