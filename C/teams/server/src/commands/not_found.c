/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** user
*/

#include "../../include/my.h"
#include "../../include/status_codes.h"

void not_found_case(t_client *cli)
{
    dprintf(cli->socket, STATUS500);
}
