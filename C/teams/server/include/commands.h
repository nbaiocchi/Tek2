/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** my
*/

#pragma once

/*
** Types
*/

#include "my.h"

/*** INFO COMMAND FUNCTIONS ***/
int help(char **commands, t_client *cli, t_server *serv, int nb_args);

/*** USER COMMAND FUNCTIONS ***/
int user(char **commands, t_client *cli, t_server *serv, int nb_args);
int connect_user_to_cli(t_server *srv, t_client *cli, char *name, char *uuid);
int connect_new_user_to_client(t_server *server, t_client *cli, char *name);
int create_user_folder(char *name, char *uuid);
int create_user_name_file(char *name, char *uuid);
int create_user_teams_folder(char *uuid);
void print_user_logged_in(t_server *serv, t_client *cli);

/*** QUIT COMMAND FUNCTIONS ***/
int quit(char **commands, t_client *cli, t_server *serv, int nb_args);
void print_user_logged_out(t_server *serv, t_client *cli);

/*** LUSERS COMMAND FUNCTIONS ***/
int lusers(char **commands, t_client *cli, t_server *serv, int nb_args);
char *print_users(t_server *serv);
char *print_user(char *name, char *uuid, bool status);
char *lusers_concat_print(t_server *serv, char *uuid, char *print);

/*** LUSER COMMAND FUNCTIONS ***/
int luser(char **cmds, t_client *cli, t_server *serv, int nb_args);

/*** SEND COMMAND FUNCTIONS ***/
int mysend(char **commands, t_client *cli, t_server *serv, int nb_args);
int create_dest_folder(char *user_path, char *name);
void init_folders(char *user_path, char *dest_path, char *command, char *name);
int send_message_dest(t_server *serv, t_client *cli, char **cmds);
int put_msg_client(t_client *cli, char **cmds);
void send_event_dest(t_server *serv, t_client *cli, char **commands);

/*** MESSAGES COMMAND FUNCTIONS ***/
int messages(char **commands, t_client *cli, t_server *serv, int nb_args);
int print_discussion(t_server *serv, t_client *cli, char *user_uuid);
int check_discussion_folder(char *name);
char *discusion_concat_print(char *path, char *uuid, char *print);
char *print_message(char *path);

/*** SUBSCRIBE COMMAND FUNCTIONS ***/
int subscribe(char **commands, t_client *cli, t_server *serv, int nb_args);
int add_user_to_team(char *uuid, char *team_uuid);
int check_if_user_subscribed(char *uuid, char *team_uuid);

/*** SUBSCRIBED COMMAND FUNCTIONS ***/
int subscribed(char **commands, t_client *cli, t_server *serv, int nb_args);
int list_all_subscribed_teams(t_server *serv, t_client *cli);
int list_all_users_of_team(t_client *cli, t_server *serv, char *team_uuid);
int read_user_teams_folders(t_client *c, t_server *s, char *u_id, char *t_id);
char *user_concat_print(t_server *serv, char *uuid, char *print);

/*** UNSUBSCRIBE COMMAND FUNCTIONS ***/
int unsubscribe(char **commands, t_client *cli, t_server *serv, int nb_args);
int remove_user_from_team(char *uuid, char *team_uuid);

/*** USE COMMAND FUNCTIONS ***/
int use(char **cmds, t_client *cli, t_server *serv, int nb_args);
int use_team_handler(t_client *cli, char *t_uuid);
int check_use_args(t_server *serv, t_client *cli, int nb_args, char **cmds);
int use_channel_handler(t_server *sv, t_client *cli, char *t_id, char *c_id);
int use_thread_handler(t_server *serv, t_client *cli, char **cmds);

/*** CREATE COMMAND FUNCTIONS ***/
int create(char **commands, t_client *cli, t_server *serv, int nb_args);
void send_event_reply_received(t_server *serv, t_client *cli, char *body);

/*** LIST COMMAND FUNCTIONS ***/
int list(char **commands, t_client *cli, t_server *serv, int nb_args);

/*** INFO COMMAND FUNCTIONS ***/
int info(char **commands, t_client *cli, t_server *serv, int nb_args);

void not_found_case(t_client *cli);
