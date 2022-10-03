/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** structs.h
*/

#pragma once

#include <netinet/in.h>
#include <stdbool.h>

enum context_state {
    UNDEFINED,
    TEAM,
    CHANNEL,
    THREAD
};

typedef struct s_context {
    enum context_state state;
    char team_uuid[1000];
    char channel_uuid[1000];
    char thread_uuid[1000];
} t_context;

typedef struct s_client {
    int socket;
    char name[1000];
    bool is_connected;
    char folderpath[1000];
    char *pending_commands;
    char uuid[100];
    t_context context;
} t_client;

typedef struct s_server {
    int opt;
    int master_socket;
    int addrlen;
    int new_socket;
    int max_clients;
    int acti;
    int i;
    int valread;
    int sd;
    int max_sd;
    struct sockaddr_in addr;
    fd_set readfds;
    fd_set writefds;
    int actual_size;
    t_client ac_client;
    t_client all_clients[1000];
    char folderpath[400];
} t_server;
