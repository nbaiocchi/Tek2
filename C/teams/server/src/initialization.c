/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** initialization
*/

#include "../include/my.h"

bool init(t_server *main_server, char *port, char *folderpath)
{
    main_server->opt = true;
    main_server->master_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (main_server->master_socket == 0) {
        printf("main_server initialization failed\n");
        return (false);
    }
    if (setsockopt(main_server->master_socket, SOL_SOCKET, SO_REUSEADDR,
    (char *)&main_server->opt, sizeof(main_server->opt)) < 0) {
        printf("setsockopt initialization failed\n");
        return (false);
    }
    main_server->addr.sin_family = AF_INET;
    main_server->addr.sin_addr.s_addr = INADDR_ANY;
    main_server->addr.sin_port = htons(atoi(port));
    return (init_b(main_server, folderpath));
}

bool init_b(t_server *main_server, char *folderpath)
{
    if (bind(main_server->master_socket, (struct sockaddr *)&main_server->addr,
        sizeof(main_server->addr)) < 0) {
        printf("Bind failed\n");
        return (false);
    }
    if (listen(main_server->master_socket, 42) < 0) {
        printf("Listen failed\n");
        return (false);
    }
    main_server->addrlen = sizeof(main_server->addr);
    main_server->actual_size = 0;
    realpath(folderpath, main_server->folderpath);
    main_server->max_clients = 42;
    if (setup_folder() == -1) {
        printf("Setup folder failed\n");
        return (false);
    }
    setup_client(main_server);
    return (true);
}

int setup_folder(void)
{
    struct stat st = {0};

    if (stat(".users", &st) == -1) {
        if (mkdir(".users", 0700) == -1)
            return -1;
    }
    if (stat(".teams", &st) == -1) {
        if (mkdir(".teams", 0700) == -1)
            return -1;
    }
    return 0;
}

void setup_client(t_server *serv)
{
    for (int i = 0; i < serv->max_clients; i++) {
        serv->all_clients[i].is_connected = false;
        serv->all_clients[i].socket = -1;
    }
}
