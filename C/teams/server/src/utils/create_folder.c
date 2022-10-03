/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** create_folder.c
*/

#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int create_folder(char *path, char *name)
{
    DIR *dir = opendir(path);
    int dfd = dirfd(dir);
    int ret = mkdirat(dfd, name, S_IRWXU);

    errno = 0;
    if (ret == -1) {
        perror("mkdir");
        return EXIT_FAILURE;
    }
    closedir(dir);
    return EXIT_SUCCESS;
}
