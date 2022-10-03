/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** get_file_content.c
*/

#include "../../include/utils.h"

char *get_file_content(char *file_path)
{
    FILE *file = fopen(file_path, "r");
    char *content = malloc(sizeof(char) * 1096);

    if (file == NULL) {
        perror("fopen");
        return NULL;
    }
    fgets(content, 1096, file);
    fclose(file);
    return content;
}
