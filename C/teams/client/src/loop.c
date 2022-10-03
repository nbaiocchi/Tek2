/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** loop
*/

#include "../include/client.h"

void core_loop(fd_set fds, size_t len, t_client *s, char *line)
{
    char buffer[10000];

    bzero(buffer, 10000);
    while (1) {
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(s->sokfd, &fds);
        if (select(s->sokfd + 1, &fds, NULL, NULL, NULL) == -1) {
            printf("select failed\n");
            return;
        }
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            getline(&line, &len, stdin);
            handle_line(s, line);
        }
        if (FD_ISSET(s->sokfd, &fds)) {
            recv_from_serv(s, buffer);
            bzero(buffer, 10000);
        }
    }
}

void loop(t_client *s)
{
    char *line = NULL;
    size_t len = 0;
    fd_set fds;

    core_loop(fds, len, s, line);
    close(s->sokfd);
    free(s);
}
