/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** user_subscribed_to_team.c
*/

#include "../../include/utils.h"

int user_subscribed_to_team(char *user_uuid, char *team_uuid)
{
    char *user_folder = my_strcat(".users/", user_uuid, 1);
    char *teams_folder = my_strcat(user_folder, "teams", 1);
    char *team_folder = my_strcat(teams_folder, team_uuid, 0);
    struct stat st = {0};

    free(user_folder);
    free(teams_folder);
    if (strcmp(team_uuid, "") == 0 || stat(team_folder, &st) == -1) {
        free(team_folder);
        return EXIT_FAILURE;
    }
    free(team_folder);
    return EXIT_SUCCESS;
}
