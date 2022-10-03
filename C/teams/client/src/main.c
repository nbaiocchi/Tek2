/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** main.c
*/

#include "../include/client.h"

void print_usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport  is the port number on which ");
    printf("the server socket listens\n");
    printf("\tpath  is the path to the home ");
    printf("directory for the Anonymous user\n");
}

void init_struct(int socket, t_client *s)
{
    s->login = false;
    s->sokfd = socket;
    s->uuid = NULL;
    s->user_name = NULL;
}

int main(int ac, char **av)
{
    if (ac != 3) {
        printf("wrong arguents\n");
        return (0);
    }
    if (ac == 2 && ((!strcmp(av[1], "--help")) || !(strcmp(av[1], "-h")))) {
        print_usage();
        return (0);
    }
    int socket_client = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrClient;
    t_client *s = malloc(sizeof(t_client));
    init_struct(socket_client, s);
    addrClient.sin_addr.s_addr = inet_addr(av[1]);
    addrClient.sin_family = AF_INET;
    addrClient.sin_port = htons(atoi(av[2]));
    connect(s->sokfd, (const struct sockaddr *)&addrClient,
    sizeof(addrClient));
    loop(s);
    close(s->sokfd);
    return (0);
}
