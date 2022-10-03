/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** utils.h
*/

#pragma once

#include <stdbool.h>
#include "my.h"

#define MAX_NAME_LENGTH 32
#define MAX_DESC_LENGTH 255
#define MAX_BODY_LENGTH 512

char *my_strcat(char *str1, char *str2, int slash);
int send_message(int return_value, char *message, int fd);

char *generate_uuid(void);

int create_folder(char *path, char *name);

char *get_file_content(char *file_path);

char *find_path_by_uuid(char *uuid);
char *find_path_by_uuid_in_team(char *team_path, char *uuid);
char *find_path_by_uuid_in_channel(char *channel_path, char *uuid);
char *find_path_by_uuid_in_thread(char *thread_path, char *uuid);

char *msprintf(const char *format, ...);

void print_message_to_cli(t_server *serv, t_client *cli, char *format, ...);
void pending_message_handler(t_server *serv);
