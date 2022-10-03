/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** user.h
*/

#pragma once

#include <stdbool.h>
#include "my.h"

/*** USER CHECKERS ***/
bool check_user_exists(char *path, char *username);
bool check_folder(char *path, char *username);
int check_user_file_exists(char *file_path, char *username);
int user_subscribed_to_team(char *user_uuid, char *team_uuid);

/*** USER GETTERS ***/
bool get_user_status(t_server *serv, char *uuid);
char *get_user_name(char *uuid);
char *get_user_uuid(char *username);

int user_info(t_server *serv, t_client *cli);

void print_all_loaded_users(void);
