/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** my
*/

#pragma once

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
#include <limits.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include "structs.h"

void replace_non_ascii(char *cmds);
char *specify_quotes(char *str);
char **revert_ascii(char **cmds, int nb_args);
void print_usage(void);
bool init(t_server *main_server, char *port, char *folderpath);
bool init_b(t_server *main_server, char *folderpath);
int setup_folder(void);
bool main_loop(t_server *serv);
int read_client(int sock, char *buffer);
void remove_client(t_client *clients, int to_remove, int *actual);
void add_new_client(t_server *serv);
void connected_client(t_server *serv, char *buffer);
bool check_end_string(char *str, int index);
char *removing_spaces(char *src);
char *removing_spaces_middle(char *str);
char **malloc_res(char **res, int nb_arg, int lg);
char **fill_res(char **res, char *str, char divisor);
char **str_to_tab(char *str, int *nb);
int handle_commands(char **, t_client *, int nb_args, t_server *serv);
void get_commands(char *buffer, t_client *client, t_server *serv);
void setup_client(t_server *serv);
char **check_if_double_quotes_is_good(char **input, char *buffer, int nb_args);
