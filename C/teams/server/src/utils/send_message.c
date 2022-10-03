/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** send_message.c
*/

#include <stdio.h>

int send_message(int return_value, char *message, int fd)
{
    dprintf(fd, "%s", message);
    return return_value;
}
