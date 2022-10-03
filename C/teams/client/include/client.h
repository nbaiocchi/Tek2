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

    #define STATUS214 "214 Help message.\nOn how \
to use the server or the meaning \
of a particular non-standard command.\nThis reply is useful \
only to the human user.\n\
Command available:\n\
/help : show help\n\n\
/login [“user_name”] : set the user_name used by client\n\
/logout : disconnect the client from the server\n\n\
/users : get the list of all users that exist on the domain\n\
/user [“user_uuid”] : get information about a user\n\n\
/send [“user_uuid”] [“message_body”] : send a message to a user\n\
/messages [“user_uuid”] : list all messages exchange with an user\n\n\
/subscribe [“team_uuid”] : subscribe to the event of a team and its sub \
directories (enable reception of all events from a team)\n\
/subscribed ?[“team_uuid”] : list all subscribed teams or list all users \
subscribed to a team\n\
/unsubscribe [“team_uuid”] : unsubscribe from a team\n\n\
/use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : use specify a \
context team/channel/thread\n\n\
When the context is not defined (/use):\n\
• /create [“team_name”] [“team_description”] : create a new team\n\
When team_uuid is defined (/use “team_uuid”):\n\
• /create [“channel_name”] [“channel_description”] : create a new channel\n\
When team_uuid and channel_uuid are defined (/use “team_uuid” \
“channel_uuid”):\n\
• /create [“thread_title”] [“thread_message”] : create a new thread\n\
When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” \
“channel_uuid” “thread_uuid”):\n\
• /create [“comment_body”] : create a new reply\n\n\
When the context is not defined (/use):\n\
• /list : list all existing teams\n\
When team_uuid is defined (/use “team_uuid”):\n\
• /list : list all existing channels\n\
When team_uuid and channel_uuid are defined (/use “team_uuid” \
“channel_uuid”):\n\
• /list : list all existing threads\n\
When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” \
“channel_uuid” “thread_uuid”):\n\
• /list : list all existing replies\n\n\
When the context is not defined (/use):\n\
• /info : display currently logged user infos\n\
When team_uuid is defined (/use “team_uuid”):\n\
• /info : display currently selected team infos\n\
When team_uuid and channel_uuid are defined (/use “team_uuid” \
“channel_uuid”):\n\
• /info : display currently selected channel infos\n\
When team_uuid, channel_uuid and thread_uuid are defined (/use “team_uuid” \
“channel_uuid” “thread_uuid”):\n\
• /info : display currently selected thread infos\n\r\n"

typedef struct s_client {
    bool login;
    int sokfd;
    char *uuid;
    char *user_name;
} t_client;

typedef void (*command_t)(char **cmd);
typedef void (*command_mul_t)(char **cmd, int count);

void loop(t_client *s);
char **to_word_array(char *str);
char *get_message(char *buffer);

void handle_line(t_client *s, char *line);
void send_cmd(t_client *s, char **cmd, char *msg);
void recv_from_serv(t_client *s, char *buffer);
char *clear_first_word(char *msg);
bool check_multiple_args(char *msg);
void single_args(char *msg);
char **tab_for_args(char *msg);
int cout_iter(char *msg);
void multiple_args(char *msg);
void more_args_cmd(t_client *s, char **cmd, char *msg);
void one_args_cmd(t_client *s, char **cmd);

//cmd_log
void login(char **cmd);
void logout(char **cmd);

//cmd_event
void message_received(char **cmd);
void thread_reply(char **cmd);
void team_created(char **cmd);
void channel_created(char **cmd);
void thread_created(char **cmd);

//cmd_print_first
void print_users(char **cmd);
void print_teams(char **cmd);
void print_channels(char **cmd);
void print_threads(char **cmd);
void print_replies(char **cmd);

//cmd_print_second
void print_message(char **cmd);
void print_user(char **cmd);
void print_team(char **cmd);
void print_channel(char **cmd);
void print_thread(char **cmd);

//cmd_print_third
void print_team_created(char **cmd);
void print_channel_created(char **cmd);
void print_thread_created(char **cmd);
void print_reply_created(char **cmd);
void print_subscribed(char **cmd);

//cmd_error_first
void print_unsubscribed(char **cmd);
void err_unknown_team(char **cmd);
void err_unknown_channel(char **cmd);
void err_unknown_thread(char **cmd);
void err_unknown_user(char **cmd);

//cmd_error_second
void err_unauthorized(char **cmd);
void err_already_exist(char **cmd);

//cmd_mul
void m_print_users(char **cmd, int count);
void m_print_teams(char **cmd, int count);
void m_print_channels(char **cmd, int count);
void m_print_threads(char **cmd, int count);
void m_print_replies(char **cmd, int count);
void m_print_message(char **cmd, int count);
