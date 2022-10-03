/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** function
*/

#include "../include/client.h"

char *get_message(char *buffer)
{
    int c = 0;

    buffer = malloc(sizeof(char) * 1000);

    if ((c = read(0, buffer, 100)) == -1) {
        printf("Cannot read message.\n");
        return NULL;
    }
    buffer[c] = '\0';
    if (!buffer[0])
        return (NULL);
    if (buffer[strlen(buffer) - 2] == '\r')
        buffer[strlen(buffer) - 2] = '\0';
    else if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';
    return (buffer);
}

int count_word(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ')
            count += 1;
    }
    return (count);
}

char **to_word_array(char *str)
{
    char **res = malloc(sizeof(char *) * (count_word(str) + 2));
    int j = 0;
    int y = 0;

    for (int i = 0; i != count_word(str) + 1; i++)
        res[i] = malloc(sizeof(char) * (100));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            res[y][j] = str[i];
            j += 1;
        }
        if (str[i] == ' ' && str[i + 1] != ' ') {
            res[y][j] = '\0';
            j = 0;
            y += 1;
        }
    }
    res[y][j] = '\0';
    res[y + 1] = NULL;
    return (res);
}

char *clear_first_word(char *msg)
{
    char *tmp = strchr(msg, ' ');

    if (tmp != NULL)
        msg = tmp + 1;
    return (msg);
}

bool check_multiple_args(char *msg)
{
    for (int i = 0; msg[i] != '\0'; i += 1) {
        if (msg[i] == '#' && msg[i - 1] == '"')
            return (true);
    }
    return (false);
}
