/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** loop
*/

#include "../include/include.h"

void init_client(t_server *s)
{
    s->client = malloc(sizeof(t_client) * 42);
    for (int i = 0; i != 42; i++) {
        s->client[i].user = malloc(sizeof(char *) * 3);
        s->client[i].user[0] = malloc(sizeof(char) * 50);
        s->client[i].user[1] = malloc(sizeof(char) * 50);
        s->client[i].is_co = 0;
        s->client[i].is_pass = 0;
        s->client[i].is_user = 0;
    }
}

int init(t_server *s, char **av)
{
    init_client(s);
    for (int i = 0; i < s->max_clients; i++)
        s->client_socket[i] = 0;
    if ((s->master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        return (1);
    if (setsockopt(s->master_socket, SOL_SOCKET, SO_REUSEADDR,
    (char *)&s->opt, sizeof(s->opt)) < 0)
        return (1);
    s->address.sin_family = AF_INET;
    s->address.sin_addr.s_addr = INADDR_ANY;
    s->address.sin_port = htons(atoi(av[1]));
    if (bind(s->master_socket, (struct sockaddr *)&s->address,
    sizeof(s->address)) < 0)
        return (1);
    if (listen(s->master_socket, 3) < 0)
        return (1);
    s->addrlen = sizeof(s->address);
    s->max_clients = 42;
    s->actual_size = 0;
    return (0);
}