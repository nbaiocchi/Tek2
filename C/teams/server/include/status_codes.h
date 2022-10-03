/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** my
*/

#pragma once

#define STATUS200 "200 Command okay.\r\n"
#define STATUS214 "214 Help message.\nOn how to use the server or the meaning \
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
#define STATUS220 "220 Service ready for new user.\r\n"
#define STATUS221 "221 Service closing control connection. \
Logged out if appropriate.\r\n"
#define STATUS230 "230 User logged in, proceed.\r\n"
#define STATUS250 "250 Requested file action okay, completed.\r\n"
#define STATUS332 "332 Need account for login.\r\n"
#define STATUS401 "401 Unauthorized.\r\n"
#define STATUS404 "404 Not found.\r\n"
#define STATUS414 "414 Parameters too long.\r\n"
#define STATUS425 "425 Can't open data connection.\r\n"
#define STATUS500 "500 Unknown command.\r\n"
#define STATUS501 "501 Syntax error in parameters or arguments.\r\n"
#define STATUS504 "504 Command not implemented.\r\n"
#define STATUS530 "530 Not logged in.\r\n"
#define STATUS550 "550 Requested action not taken.\r\n"
