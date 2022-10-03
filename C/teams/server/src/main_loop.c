/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** main_loop
*/

#include "../include/my.h"
#include "../include/status_codes.h"
#include "../include/utils.h"

void add_new_client(t_server *serv)
{
    if ((serv->new_socket = accept(serv->master_socket,
    (struct sockaddr *)&serv->addr, (socklen_t *)&serv->addrlen)) < 0) {
        printf("accept failure\n");
        exit(84);
    }
    dprintf(serv->new_socket, STATUS220);
    t_context context = {UNDEFINED, "", "", ""};
    t_client c = {serv->new_socket, "", false, "./", NULL, "", context};
    serv->all_clients[serv->actual_size] = c;
    serv->actual_size++;
}

void handle_connected_client(t_server *sv, char *buffer, int i)
{
    int c = 0;
    t_client *client = &sv->all_clients[i];

    c = read_client(client->socket, buffer);
    if (c == 0) {
        close(sv->all_clients[i].socket);
        remove_client(sv->all_clients, i, &sv->actual_size);
    } else {
        if (strlen(buffer) > 1)
            get_commands(buffer, client, sv);
    }
}

void connected_client(t_server *sv, char *buffer)
{
    for (int i = 0; i < sv->actual_size; i++) {
        sv->sd = sv->all_clients[i].socket;
        if (FD_ISSET(sv->sd, &sv->readfds)) {
            handle_connected_client(sv, buffer, i);
            break;
        }
    }
}

void set_fdset(int i, t_server *sv)
{
    for (i = 0; i < sv->actual_size; i++) {
        sv->sd = sv->all_clients[i].socket;
        if (sv->sd > 0) {
            FD_SET(sv->sd, &sv->readfds);
            FD_SET(sv->sd, &sv->writefds);
        }
        if (sv->sd > sv->max_sd)
            sv->max_sd = sv->sd;
    }
}

bool main_loop(t_server *sv)
{
    char buffer[1000];
    sv->max_sd = sv->master_socket;

    while (1) {
        memset(buffer, 0, 1000);
        FD_ZERO(&sv->readfds);
        FD_ZERO(&sv->writefds);
        FD_SET(sv->master_socket, &sv->readfds);
        FD_SET(sv->master_socket, &sv->writefds);
        sv->max_sd = sv->master_socket;
        set_fdset(0, sv);
        sv->acti = select(sv->max_sd + 1, &sv->readfds,
        &sv->writefds, NULL, NULL);
        if (FD_ISSET(sv->master_socket, &sv->readfds)) {
            add_new_client(sv);
        }
        connected_client(sv, buffer);
        pending_message_handler(sv);
    }
}
