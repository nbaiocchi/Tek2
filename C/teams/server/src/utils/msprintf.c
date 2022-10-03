/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myteams-noe.baiocchi
** File description:
** my_strcat_mul.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "../../include/utils.h"

char *msprintf(const char *format, ...)
{
    va_list ap;
    size_t needed;
    char *str;

    va_start(ap, format);
    needed = vsnprintf(NULL, 0, format, ap) + 1;
    va_end(ap);
    va_start(ap, format);
    str = malloc(sizeof(char) * needed);
    vsprintf(str, format, ap);
    va_end(ap);
    return str;
}
