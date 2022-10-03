/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-noe.baiocchi
** File description:
** loop
*/

#include "../include/include.h"

void quit(t_server *s)
{
    dprintf(s->client_socket[s->i], "221 quit\r\n");
}