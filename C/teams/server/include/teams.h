/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** team.h
*/

#pragma once

#include "structs.h"

/*** TEAM GETTERS ***/
char *get_team_name(char *channel_uuid);
char *get_team_uuid(char *team_name);
char *get_team_description(char *channel_uuid);

/*** TEAM GENERATORS ***/
int team_create(t_server *serv, t_client *cli, char *name, char *desc);
int generate_team_folder(char *uuid);
int generate_team_file_name(char *uuid, char *name);
int generate_team_file_description(char *uuid, char *desc);

/*** TEAM LISTS ***/
int team_list(t_server *serv, t_client *cli);
int check_team_folder(char *name);

/** TEAM INFOS ***/
int team_info(t_server *serv, t_client *cli);

/*** TEAM UTILS ***/
int check_team_file_exists(char *file_path, char *team_name);
char *print_team(char *team_uuid);
char *team_concat_print(char *name, char *print);
void print_team_created(t_server *serv, t_client *cli, char *uuid);

/*****************************************************************************/

/*** CHANNEL GETTERS ***/
char *get_channel_name(char *channel_uuid);
char *get_channel_uuid(char *team_uuid, char *channel_name);
char *get_channel_description(char *channel_uuid);

/*** CHANNEL GENERATORS ***/
int channel_create(t_server *serv, t_client *cli, char *name, char *desc);
int generate_channel_folder(t_client *cli, char *uuid);
int generate_channel_file_name(t_client *cli, char *uuid, char *name);
int generate_channel_file_description(t_client *cli, char *uuid, char *desc);

/*** CHANNEL LISTS ***/
int channel_list(t_server *serv, t_client *cli);
void channel_list_handler(t_client *cli, char *name);
int check_channel_folder(char *name);

/** CHANNEL INFOS ***/
int channel_info(t_server *serv, t_client *cli);

/*** CHANNEL UTILS ***/
char *check_channel_file(char *dir_name, char *team_uuid, char *channel_name);
char *print_channel(char *channel_uuid);
char *channel_concat_print(char *name, char *print);
void print_channel_created(t_server *srv, t_client *cli, char *id, char *t_id);

/*****************************************************************************/

/*** THREAD GETTERS ***/
char *get_thread_title(char *thread_uuid);
char *get_thread_message(char *thread_uuid);
char *get_thread_timestamp(char *thread_uuid);
char *get_thread_author(char *thread_uuid);

/*** THREAD GENERATORS ***/
int thread_create(t_server *serv, t_client *cli, char *name, char *desc);
int generate_thread_folder(t_client *cli, char *uuid);
int generate_thread_file_title(t_client *cli, char *uuid, char *name);
int generate_thread_file_message(t_client *cli, char *uuid, char *desc);
int generate_thread_file_timestamp(t_client *cli, char *uuid);
int generate_thread_file_author(t_client *cli, char *uuid);

/*** THREAD LISTS ***/
int thread_list(t_server *serv, t_client *cli);
void thread_list_handler(t_client *cli, char *name);
int check_thread_folder(char *name);

/** THREAD INFOS ***/
int thread_info(t_server *serv, t_client *cli);

/*** THREAD UTILS ***/
char *print_thread(char *thread_uuid);
char *thread_concat_print(char *name, char *print);
void print_thread_created(t_server *serv, t_client *cli, char *uuid);
void print_thread_created_users(t_server *serv, t_client *cli, char *uuid);
void print_thread_created_user(t_server *serv, t_client *cli, char *uuid);

/*****************************************************************************/

/*** REPLY GETTERS ***/
char *get_reply_timestamp(char *reply_uuid);
char *get_reply_author(char *reply_uuid);
char *get_reply_body(char *reply_uuid);

/*** REPLY GENERATORS ***/
int reply_create(t_server *serv, t_client *cli, char *body);
int reply_create_files(t_client *cli, char *trd_path, char *uuid, char *body);
int create_reply_file_timestamp(char *path, char *uuid);
int create_reply_file_body(char *path, char *uuid, char *body);
int create_reply_file_author(char *path, char *uuid, char *author);

/*** REPLY LISTS ***/
int reply_list(t_server *serv, t_client *cli);
void reply_list_handler(t_client *cli, char *name);
int check_reply_folder(char *name);

/*** REPLY UTILS **/
char *print_reply(char *reply_uuid);
char *reply_concat_print(char *name, char *print);
char *get_thread_uuid_from_reply_uuid(char *uuid);
char *remove_last_path(char *str);
char *get_last_path(char *str);
void print_reply_created(t_server *serv, char *uuid, char *t_uuid);
