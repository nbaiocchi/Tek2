/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** loop
*/

#include "../include/include.h"

void loop_one(t_server *s)
{
    FD_ZERO(&s->readfds);
    FD_SET(STDIN_FILENO, &s->readfds);
    FD_SET(s->master_socket, &s->readfds);
    s->max_sd = s->master_socket;
    for (int i = 0; i < s->max_clients; i++) {
        s->sd = s->client_socket[i];
        if (s->sd > 0)
            FD_SET(s->sd, &s->readfds);
        if (s->sd > s->max_sd)
            s->max_sd = s->sd;
    }
    s->activity = select(s->max_sd + 1, &s->readfds, NULL, NULL, NULL);
}

void loop_two(t_server *s, char *buffer)
{
    s->new_socket = accept(s->master_socket,
    (struct sockaddr *)&s->address, (socklen_t *)&s->addrlen);
    dprintf(s->new_socket, "220 new connection\r\n");
    for (int i = 0; i < s->actual_size; i++) {
        if (FD_ISSET(s->client_socket[i], &s->readfds)) {
            read(s->client_socket[i], buffer, 42);
            s->i = i;
            handle_cmd(buffer, s);
        }
    }
    for (int i = 0; i < s->max_clients; i++) {
        if (s->client_socket[i] == 0) {
            s->client_socket[i] = s->new_socket;
            break;
        }
    }
    s->actual_size += 1;+++
}

void loop_three(t_server *s, char *buffer)
{
    for (int i = 0; i < s->actual_size; i++) {
        if (FD_ISSET(s->client_socket[i], &s->readfds)) {
            read(s->client_socket[i], buffer, 42);
            s->i = i;
            handle_cmd(buffer, s);
        }
    }
}

void loop(t_server *s)
{
    char buffer[42];
    s->max_sd = s->master_socket;
    while (true) {
        memset(buffer, '\0', 42);
        loop_one(s);
        if (FD_ISSET(s->master_socket, &s->readfds)) {
            loop_two(s, buffer);
        } else {
            loop_three(s, buffer);
        }
    }
}