/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** send_msg
*/

#include "../include/client.h"

char *clean_line(char *line)
{
    char *res = malloc(sizeof(char) * strlen(line));

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n') {
            res[i] = '\0';
            return (res);
        }
        res[i] = line[i];
    }
    return (NULL);
}

void handle_line(t_client *s, char *line)
{
    char *message = clean_line(line);
    char **cmd = NULL;

    if (message == NULL)
        return;
    cmd = to_word_array(message);
    send_cmd(s, cmd, message);
}
