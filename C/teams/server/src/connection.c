/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-abdelkarim.bengrine
** File description:
** connection
*/

#include "../include/my.h"

int read_client(int sock, char *buffer)
{
    int n = 0;

    memset(buffer, 0, 1000);
    if ((n = read(sock, buffer, 1000 - 1)) < 0) {
        printf("Cannot read client message.\n");
        n = 1;
    }
    for (int i = 0; buffer[i] != '\0'; i += 1) {
        if (buffer[i] == '\r' || buffer[i] == '\n') {
            buffer[i] = '\0';
            return (n);
        }
    }
    return n;
}

void remove_client(t_client *clients, int to_remove, int *actual)
{
    clients[to_remove].is_connected = false;
    memset(clients[to_remove].name, 0, strlen(clients[to_remove].name));
    memmove(clients + to_remove, clients + to_remove + 1,
    (*actual - to_remove - 1) * sizeof(t_client));
    (*actual)--;
}
