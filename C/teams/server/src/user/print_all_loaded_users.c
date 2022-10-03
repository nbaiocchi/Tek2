/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** print_all_loaded_users.c
*/

#include "../../include/utils.h"
#include "../../../libs/myteams/logging_server.h"
#include "../../include/users.h"

void print_all_loaded_users(void)
{
    DIR *d = opendir(".users");
    struct dirent *dir = NULL;

    if (d == NULL)
        return;
    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)
            server_event_user_loaded(dir->d_name, get_user_name(dir->d_name));
    }
    closedir(d);
}
