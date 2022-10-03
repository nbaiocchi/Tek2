/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** include
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

    #include <sys/socket.h>
    #include <sys/types.h>
    #include <stdio.h>
    #include <ctype.h>
    #include <netdb.h>
    #include <stdlib.h>
    #include <netinet/in.h>
    #include <unistd.h>
    #include <string.h>
    #include <arpa/inet.h>
    #include <sys/wait.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/select.h>
    #include <stdbool.h>
    #include <dirent.h>

typedef struct s_client {
    char **user;
    int is_user;
    int is_pass;
    int is_co;
} t_client;

typedef struct s_server {
    int opt;
    int master_socket;
    int addrlen;
    int new_socket;
    int client_socket[42];
    int max_clients;
    int activity;
    int i;
    int valread;
    int sd;
    int max_sd;
    struct sockaddr_in address;
    fd_set readfds;
    int actual_size;
    t_client *client;
} t_server;

int check_arg(int ac, char **av);
void loop(t_server *s);
int init(t_server *s, char **av);
void handle_cmd(char *buffer, t_server *s);
char **to_word_array(char *str);
void user_cmd(char **cmd, t_server *s);
void pass_cmd(t_server *s);
void quit(t_server *s);
void help_cmd(char **cmd, t_server *s);

#endif /* !INCLUDE_H_ */