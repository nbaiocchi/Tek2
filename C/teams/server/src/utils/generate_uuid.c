/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** generate_uuid.c
*/

#include <uuid/uuid.h>
#include <stdlib.h>

char *generate_uuid(void)
{
    uuid_t binuuid;
    char *uuid;

    uuid = malloc(sizeof(char *) * 37);
    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
    return uuid;
}
