/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** send_msg
*/

#include "../include/client.h"

void one_args_cmd2(t_client *s, char **cmd)
{
    if (strcmp(cmd[0], "/subscribed") == 0)
        dprintf(s->sokfd, "SUBSCRIBED\r\n");
    if (strcmp(cmd[0], "/unsubscribe") == 0)
        dprintf(s->sokfd, "UNSUBSCRIBE\r\n");
    if (strcmp(cmd[0], "/use") == 0)
        dprintf(s->sokfd, "USE\r\n");
    if (strcmp(cmd[0], "/create") == 0)
        dprintf(s->sokfd, "CREATE\r\n");
    if (strcmp(cmd[0], "/list") == 0)
        dprintf(s->sokfd, "LIST\r\n");
    if (strcmp(cmd[0], "/info") == 0)
        dprintf(s->sokfd, "INFO\r\n");
}

void one_args_cmd(t_client *s, char **cmd)
{
    if (strcmp(cmd[0], "/login") == 0)
        dprintf(s->sokfd, "USER\r\n");
    if (strcmp(cmd[0], "/logout") == 0)
        dprintf(s->sokfd, "QUIT\r\n");
    if (strcmp(cmd[0], "/users") == 0)
        dprintf(s->sokfd, "LUSERS\r\n");
    if (strcmp(cmd[0], "/user") == 0)
        dprintf(s->sokfd, "LUSER\r\n");
    if (strcmp(cmd[0], "/send") == 0)
        dprintf(s->sokfd, "SEND\r\n");
    if (strcmp(cmd[0], "/messages") == 0)
        dprintf(s->sokfd, "MESSAGES\r\n");
    if (strcmp(cmd[0], "/subscribe") == 0)
        dprintf(s->sokfd, "SUBSCRIBE\r\n");
    one_args_cmd2(s, cmd);
}

void more_args_cmd2(t_client *s, char **cmd, char *msg)
{
    if (strcmp(cmd[0], "/subscribed") == 0)
        dprintf(s->sokfd, "SUBSCRIBED %s\r\n", msg);
    if (strcmp(cmd[0], "/unsubscribe") == 0)
        dprintf(s->sokfd, "UNSUBSCRIBE %s\r\n", msg);
    if (strcmp(cmd[0], "/use") == 0)
        dprintf(s->sokfd, "USE %s\r\n", msg);
    if (strcmp(cmd[0], "/create") == 0)
        dprintf(s->sokfd, "CREATE %s\r\n", msg);
    if (strcmp(cmd[0], "/list") == 0)
        dprintf(s->sokfd, "LIST %s\r\n", msg);
    if (strcmp(cmd[0], "/info") == 0)
        dprintf(s->sokfd, "INFO %s\r\n", msg);
}

void more_args_cmd(t_client *s, char **cmd, char *msg)
{
    if (strcmp(cmd[0], "/login") == 0)
        dprintf(s->sokfd, "USER %s\r\n", msg);
    if (strcmp(cmd[0], "/logout") == 0)
        dprintf(s->sokfd, "QUIT %s\r\n", msg);
    if (strcmp(cmd[0], "/users") == 0)
        dprintf(s->sokfd, "LUSERS %s\r\n", msg);
    if (strcmp(cmd[0], "/user") == 0)
        dprintf(s->sokfd, "LUSER %s\r\n", msg);
    if (strcmp(cmd[0], "/send") == 0)
        dprintf(s->sokfd, "SEND %s\r\n", msg);
    if (strcmp(cmd[0], "/messages") == 0)
        dprintf(s->sokfd, "MESSAGES %s\r\n", msg);
    if (strcmp(cmd[0], "/subscribe") == 0)
        dprintf(s->sokfd, "SUBSCRIBE %s\r\n", msg);
    more_args_cmd2(s, cmd, msg);
}
